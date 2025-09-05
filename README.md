# Delta Patcher [![Build](https://github.com/marco-calautti/DeltaPatcher/actions/workflows/release.yml/badge.svg)](https://github.com/marco-calautti/DeltaPatcher/actions/workflows/release.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/bdfed52f118c4199ad0d828520f29b61)](https://www.codacy.com/gh/marco-calautti/DeltaPatcher/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=marco-calautti/DeltaPatcher&amp;utm_campaign=Badge_Grade) 

![ScreenShot](https://i.imgur.com/qRM3PB8.png)

<p align='center'>
<a href='https://github.com/marco-calautti/DeltaPatcher/releases'><img height='40' src='https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white'/></a>
<a href='https://github.com/marco-calautti/DeltaPatcher/releases'><img height='40' src='https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0'/></a>
<a href='https://flathub.org/apps/io.github.marco_calautti.DeltaPatcher'><img height='40' alt='Download on Flathub' src='https://flathub.org/api/badge?locale=en'/></a>
</p>

Delta Patcher is a GUI software that is able to create and apply xdelta patches as the ones supported by the xdelta tool developed by Joshua McDonald. 

Delta patcher is fully self-contained and does not depend on the xdelta3 tool at all. This sets Delta Patcher apart from all other tools out there that are just frontends to the xdelta3 binary. Moreover, such frontends do not support some options of the encoder/decoder at all, like main and secondary compression level for encoding and checksum checking for decoding/encoding. Also, they are all written in .NET (0_0).

So, this tool was designed to be self-contained (for Windows, MacOS and GTK-based Linux systems). It's written in C++ using wxWidgets for the GUI components and all the needed libraries are statically linked to the executable (except for GTK for linux builds). Last, but not the least, Delta Patcher is GPL2'd and cross-platform: it runs fine on Windows, Linux and MacOS.


## How to build
Delta Patcher has been successfully built on Windows 10, Ubuntu 22.04, Fedora 36 and MacOS 10.14+.

### Windows and MacOS

-   On Windows, install CMake, git and Visual Studio with the Desktop C++ Development tools (including the WindowsSDK package).
-   On MacOS install the Xcode command line tools (or Xcode itself), CMake and git.
-   git clone --recurse-submodules https://github.com/marco-calautti/DeltaPatcher.git
-   cd DeltaPatcher
-   cmake -B build -DCMAKE_BUILD_TYPE=Release -DwxBUILD_SHARED=OFF -DwxBUILD_USE_STATIC_RUNTIME=ON
-   cmake --build build --config Release 

For an x86 (32bit) build on Windows do:
- cmake -B build -A Win32 -DCMAKE_BUILD_TYPE=Release -DwxBUILD_SHARED=OFF -DwxBUILD_USE_STATIC_RUNTIME=ON

The executable should be found in build/app/Release/ on Windows and in build/app on MacOS

### Linux

-   First install dependencies:
    -   Ubuntu: sudo apt install build-essential cmake git libgtk-3-dev
    -   Fedora: sudo dnf install g++ make cmake git gtk3-devel

-   git clone --recurse-submodules https://github.com/marco-calautti/DeltaPatcher.git
-   cd DeltaPatcher
-   cmake -B build -DCMAKE_BUILD_TYPE=Release -DwxBUILD_SHARED=OFF
-   cmake --build build --config Release

The final binary should be found in build/app/
