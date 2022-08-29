# DeltaPatcher [![Codacy Badge](https://app.codacy.com/project/badge/Grade/bdfed52f118c4199ad0d828520f29b61)](https://www.codacy.com/gh/marco-calautti/DeltaPatcher/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=marco-calautti/DeltaPatcher&amp;utm_campaign=Badge_Grade)

Delta Patcher is a hybrid frontend to the xdelta3 decoder/encoder. Delta patcher is able to make and apply xdelta patches. But... why making another frontend? All the frontends I've seen don't support some options of the encoder/decoder at all, like compression level for encoding and checksum
checking for decoding/encoding. Also, they are all written in .NET (0_0). So, this tool was designed to be selfcontained (as of now, only
for Windows). It's written in C++ using wxWidgets for the GUI components and all the needed libraries are statically linked to the EXE, including the xdelta3 decoder/encoder itself.
Last, but not the least, Delta Patcher is GPL2'd and cross-platform: it runs fine on Windows and Linux and should compile on MacOS too.

## How to build
Delta Patcher has been successfully built on Windows 10, Ubuntu 22.04 and Fedora 36.

### Windows

-   Install CMake and Visual Studio Community 2022 with the Desktop C++ Development tools (including the WindowsSDK package).
-   git clone --recurse-submodules https://github.com/marco-calautti/DeltaPatcher.git
-   mkdir build
-   cd build
-   cmake -G "Visual Studio 17 2022" -DwxBUILD_SHARED=OFF -DwxBUILD_USE_STATIC_RUNTIME=ON -DwxBUILD_STRIPPED_RELEASE=ON -DCMAKE_BUILD_TYPE=Release ..
-   Open the solution file created in the build directory.
-   Select Release as the build configuration (or MinSizeRel if you prefer a smaller executable rather than a fast one).
-   Right click on the Delta Patcher project and click build.

Executable should be found in build/app/Release/ or build/app/MinSizeRel, depending on your choice.

### Linux

-   First install dependencies:
    -   Ubuntu: sudo apt install build-essential cmake git libgtk-3-dev xdelta3
    -   Fedora: sudo dnf install g++ make cmake git gtk3-devel xdelta3

-   git clone --recurse-submodules https://github.com/marco-calautti/DeltaPatcher.git
-   mkdir build && cd build
-   cmake -DwxBUILD_SHARED=OFF -DCMAKE_BUILD_TYPE=Release ..
-   make (use -j flag to speed up compilation)

The final binary should be found in build/app/
