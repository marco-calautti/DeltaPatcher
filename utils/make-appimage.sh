#!/usr/bin/env bash

# This is free and unencumbered software released into the public domain.
#
# Anyone is free to copy, modify, publish, use, compile, sell, or
# distribute this software, either in source code form or as a compiled
# binary, for any purpose, commercial or non-commercial, and by any
# means.
#
# In jurisdictions that recognize copyright laws, the author or authors
# of this software dedicate any and all copyright interest in the
# software to the public domain. We make this dedication for the benefit
# of the public at large and to the detriment of our heirs and
# successors. We intend this dedication to be an overt act of
# relinquishment in perpetuity of all present and future rights to this
# software under copyright law.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.
#
# For more information, please refer to <http://unlicense.org/>

# This script is based off the one used to build the DuckStation PS1 emulator: https://github.com/stenzek/duckstation

if [ "$#" -ne 3 ]; then
    echo "Syntax: $0 <path to build directory> <path to root directory> <output name>"
    exit 1
fi

BUILDDIR=$1
ROOTDIR=$2
NAME=$3

BINDIR="$DSDIR/bin"

BINARY=DeltaPatcher
APPDIRNAME=DeltaPatcher.AppDir
STRIP=strip

SYSLIBS=(ld-linux-x86-64.so.2 $(ldd "$BUILDDIR/app/$BINARY" | grep -w "=>" | sed 's/^\t//' | sed 's/\s=>.*//'))

set -e

if [ ! -f appimagetool-x86_64.AppImage ]; then
	wget https://github.com/AppImage/AppImageKit/releases/download/continuous/appimagetool-x86_64.AppImage
	chmod +x appimagetool-x86_64.AppImage
fi

OUTDIR=$(realpath "./$APPDIRNAME")
SCRIPTDIR=$(dirname "${BASH_SOURCE[0]}")
rm -fr "$OUTDIR"
mkdir "$OUTDIR"

mkdir -p "$OUTDIR/usr/bin" "$OUTDIR/usr/lib"

echo "Copying binary and resources..."
cp -a "$BUILDDIR/app/$BINARY" "$OUTDIR/usr/bin"



# Libraries we pull in from the system.
echo "Copying system libraries..."
for lib in "${SYSLIBS[@]}"; do
	blib=$(basename "$lib")
	if [ -f "/lib/x86_64-linux-gnu/$lib" ]; then
		cp "/lib/x86_64-linux-gnu/$lib" "$OUTDIR/usr/lib/$blib"
	elif [ -f "/lib64/$lib" ]; then
		cp "/lib64/$lib" "$OUTDIR/usr/lib/$blib"
	elif [ -f "$CHROOT/usr/lib/x86_64-linux-gnu/$lib" ]; then
		cp "$CHROOT/usr/lib/x86_64-linux-gnu/$lib" "$OUTDIR/usr/lib/$blib"
	elif [ -f "$CHROOT/lib/$lib" ]; then
		cp "$CHROOT/lib/$lib" "$OUTDIR/usr/lib/$blib"
	elif [ -f "$CHROOT/usr/lib/$lib" ]; then
		cp "$CHROOT/usr/lib/$lib" "$OUTDIR/usr/lib/$blib"
	else
		echo "*** Failed to find '$blib'"
		exit 1
	fi

	$STRIP "$OUTDIR/usr/lib/$blib"
done

for so in $(find "$OUTDIR/usr/lib" -maxdepth 1); do
	if [ -f "$so" ]; then
		echo "Patching RPATH in ${so}"
		patchelf --set-rpath '$ORIGIN' "$so"
	fi
done

# Patch RPATH so the binary goes hunting for shared libraries in the AppDir instead of system.
echo "Patching RPATH in ${BINARY}..."
patchelf --set-rpath '$ORIGIN/../lib' "$OUTDIR/usr/bin/$BINARY"
patchelf --set-interpreter '$ORIGIN/../lib/ld-linux.so.2' "$OUTDIR/usr/bin/$BINARY"

# Patching hardcoded paths in loader
sed -i -e 's|/lib|/xib|g' "$OUTDIR/usr/lib/ld-linux.so.2"
sed -i -e 's|/etc|/xtc|g' "$OUTDIR/usr/lib/ld-linux.so.2"

# Currently we leave the main binary unstripped, uncomment if this is not desired.
$STRIP "$OUTDIR/usr/bin/$BINARY"

echo "Creating desktop..."
cat > "$OUTDIR/deltapatcher.desktop" << EOF
[Desktop Entry]
Type=Application
Name=Delta Patcher
GenericName=XDelta Patching Utility
Comment=Applies and creates patches in xdelta format
Icon=deltapatcher
TryExec=DeltaPatcher
Exec=DeltaPatcher %f
Categories=Utility
EOF
cp "$ROOTDIR/graphics/icon256.png" "$OUTDIR/deltapatcher.png"

echo "Creating AppRun..."
cat > "$OUTDIR/AppRun" << EOF
#!/bin/sh

APPDIR=\$(dirname "\$0")
exec "\$APPDIR/usr/bin/$BINARY" "\$@"
EOF
chmod +x "$OUTDIR/AppRun"

echo "Generate AppImage"
./appimagetool-x86_64.AppImage -v "$OUTDIR" "$NAME.AppImage"
