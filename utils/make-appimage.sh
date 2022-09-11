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

declare -a SYSLIBS=(
"libpthread.so.0"
"libdl.so.2"
"libgtk-3.so.0"
"libgdk-3.so.0"
"libpangocairo-1.0.so.0"
"libpango-1.0.so.0"
"libcairo.so.2"
"libgdk_pixbuf-2.0.so.0"
"libgio-2.0.so.0"
"libgobject-2.0.so.0"
"libglib-2.0.so.0"
"libX11.so.6"
"libm.so.6"
"libgmodule-2.0.so.0"
"libXi.so.6"
"libXfixes.so.3"
"libcairo-gobject.so.2"
"libatk-1.0.so.0"
"libatk-bridge-2.0.so.0"
"libepoxy.so.0"
"libfribidi.so.0"
"libpangoft2-1.0.so.0"
"libharfbuzz.so.0"
"libfontconfig.so.1"
"libfreetype.so.6"
"libXinerama.so.1"
"libXrandr.so.2"
"libXcursor.so.1"
"libXcomposite.so.1"
"libXdamage.so.1"
"libxkbcommon.so.0"
"libwayland-cursor.so.0"
"libwayland-egl.so.1"
"libwayland-client.so.0"
"libXext.so.6"
"librt.so.1"
"libthai.so.0"
"libpixman-1.so.0"
"libpng16.so.16"
"libxcb-shm.so.0"
"libxcb.so.1"
"libxcb-render.so.0"
"libXrender.so.1"
"libz.so.1"
"libmount.so.1"
"libselinux.so.1"
"libresolv.so.2"
"libffi.so.7"
"libpcre.so.3"
"libdbus-1.so.3"
"libatspi.so.0"
"libgraphite2.so.3"
"libexpat.so.1"
"libuuid.so.1"
"libdatrie.so.1"
"libXau.so.6"
"libXdmcp.so.6"
"libblkid.so.1"
"libpcre2-8.so.0"
"libsystemd.so.0"
"libbsd.so.0"
"liblzma.so.5"
"liblz4.so.1"
"libgcrypt.so.20"
"libgpg-error.so.0"
)

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
#patchelf --set-interpreter '/usr/lib/ld-linux-x86-64.so.2' "$OUTDIR/usr/bin/$BINARY"

# Patching hardcoded paths in loader
#sed -i -e 's|/lib|/xib|g' "$OUTDIR/usr/lib/ld-linux-x86-64.so.2"
#sed -i -e 's|/etc|/xtc|g' "$OUTDIR/usr/lib/ld-linux-x86-64.so.2"

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
