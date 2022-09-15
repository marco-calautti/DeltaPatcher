# DeltaPatcher [![Build](https://github.com/marco-calautti/DeltaPatcher/actions/workflows/build.yml/badge.svg)](https://github.com/marco-calautti/DeltaPatcher/actions/workflows/build.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/bdfed52f118c4199ad0d828520f29b61)](https://www.codacy.com/gh/marco-calautti/DeltaPatcher/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=marco-calautti/DeltaPatcher&amp;utm_campaign=Badge_Grade)

Delta Patcher is a GUI software that is able to create and apply xdelta patches as the ones supported by the xdelta tool developed by Joshua McDonald. 

Delta patcher is fully self-contained and does not depend on the xdelta3 tool at all. This sets Delta Patcher apart from all other tools out there that are just frontends to the xdelta3 binary. Moreover, such frontends do not support some options of the encoder/decoder at all, like main and secondary compression level for encoding and checksum checking for decoding/encoding. Also, they are all written in .NET (0_0).

So, this tool was designed to be self-contained (for Windows, MacOS and GTK-based Linux systems). It's written in C++ using wxWidgets for the GUI components and all the needed libraries are statically linked to the executable (except for GTK for linux builds). Last, but not the least, Delta Patcher is GPL2'd and cross-platform: it runs fine on Windows, Linux and MacOS.

## How to build
Delta Patcher has been successfully built on Windows 10, Ubuntu 22.04, Fedora 36 and MacOS 10.14+.

### Windows

-   Install CMake and Visual Studio with the Desktop C++ Development tools (including the WindowsSDK package).
-   git clone --recurse-submodules https://github.com/marco-calautti/DeltaPatcher.git
-   cd DeltaPatcher
-   mkdir build
-   cd build
-   cmake -DwxBUILD_SHARED=OFF -DwxBUILD_USE_STATIC_RUNTIME=ON -DCMAKE_BUILD_TYPE=Release ..
-   Open the solution file created in the build directory with Visual Studio.
-   Select Release as the build configuration.
-   Press F6 to build.

For an x86 (32bit) build supporting also Windows XP, then you need Visual Studio 2019 and the v141_xp tool set. Then do:
- cmake -G "Visual Studio 16 2019" -A Win32 -T v141_xp -DwxBUILD_SHARED=OFF -DwxBUILD_USE_STATIC_RUNTIME=ON -DCMAKE_BUILD_TYPE=Release ..

The executable should be found in build/app/Release/

### Linux

-   First install dependencies:
    -   Ubuntu: sudo apt install build-essential cmake git libgtk-3-dev
    -   Fedora: sudo dnf install g++ make cmake git gtk3-devel

-   git clone --recurse-submodules https://github.com/marco-calautti/DeltaPatcher.git
-   cd DeltaPatcher
-   mkdir build && cd build
-   cmake -DwxBUILD_SHARED=OFF -DCMAKE_BUILD_TYPE=Release ..
-   make -j$(nproc)

The final binary should be found in build/app/
