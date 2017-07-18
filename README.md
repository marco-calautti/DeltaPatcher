DeltaPatcher [![Codacy Badge](https://api.codacy.com/project/badge/Grade/524960d735d24d49931e906444cf9267)](https://www.codacy.com/app/marco-calautti/DeltaPatcher?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=marco-calautti/DeltaPatcher&amp;utm_campaign=Badge_Grade)
============

Delta Patcher is yet another frontend to the
xdelta3 decoder/encoder created by Joshua
McDonald. Delta patcher is able to make and
apply patches. But... why making another frontend?
All the frontends I've seen don't support some
options of the encoder/decoder at all, like
compression level for encoding and checksum
checking for decoding/encoding. Also, they are
all written in .NET (0_0). So, this tool was
designed to be selfcontained (as of now, only
for Windows). It's written in C++ using
wxWidgets for the GUI components and all the
needed libraries are static linked to the EXE.
All you need is to place the xdelta.exe file
in the same directory of this tool (no more
.NET Framework required).
Last, but not the least, Delta Patcher is
GPL2'd and cross-platform: it runs fine on
Windows and Linux and should compile on MacOS
too.

-------------------------
Full and Lite versions
-------------------------

This package comes with two versions of the
frontend. The Lite version is simply the
patching GUI, this is intended to be shipped
along with your patch. This way, the final
user doesn't need to mess with other options
like patch creation (simplicity comes first!).
The Full version is mainly for romhackers,
it supports both creation and application
of xdelta patches.
