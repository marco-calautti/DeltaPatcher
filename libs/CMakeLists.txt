# wxWidgets
set(wxUSE_AUI OFF CACHE BOOL "" FORCE)
set(wxUSE_PROPGRID OFF CACHE BOOL "" FORCE)
set(wxUSE_RIBBON OFF CACHE BOOL "" FORCE)
set(wxUSE_MEDIACTRL OFF CACHE BOOL "" FORCE)
set(wxUSE_WEBVIEW OFF CACHE BOOL "" FORCE)
set(wxUSE_RICHTEXT OFF CACHE BOOL "" FORCE)
set(wxUSE_OPENGL OFF CACHE BOOL "" FORCE)
set(wxUSE_DEBUGREPORT OFF CACHE BOOL "" FORCE)
set(wxUSE_HTML OFF CACHE BOOL "" FORCE)
set(wxUSE_STC OFF CACHE BOOL "" FORCE)
set(wxUSE_WXHTML_HELP OFF CACHE BOOL "" FORCE)
set(wxUSE_XRC OFF CACHE BOOL "" FORCE)
set(wxUSE_ZIPSTREAM OFF CACHE BOOL "" FORCE)

set(wxUSE_REGEX OFF CACHE BOOL "" FORCE)
set(wxUSE_ZLIB OFF CACHE STRING "" FORCE)
set(wxUSE_EXPAT OFF CACHE BOOL "" FORCE)
set(wxUSE_LIBJPEG OFF CACHE BOOL "" FORCE)
set(wxUSE_LIBPNG OFF CACHE STRING "" FORCE)
set(wxUSE_LIBTIFF OFF CACHE BOOL "" FORCE)
set(wxUSE_NANOSVG OFF CACHE BOOL "" FORCE)
set(wxUSE_XML OFF CACHE BOOL "" FORCE)
set(wxUSE_SVG OFF CACHE BOOL "" FORCE)
set(wxUSE_ARTPROVIDER_TANGO OFF CACHE BOOL "" FORCE)
set(wxBUILD_STRIPPED_RELEASE ON CACHE BOOL "" FORCE)

add_subdirectory(wxWidgets)

# liblzma
add_subdirectory(xz)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/xz/src/liblzma/api)

#libxdelta3
set(XD3_BUILD_AS_EXE OFF CACHE BOOL "" FORCE)
set(XD3_ENABLE_SECONDARY_COMPRESSION ON CACHE BOOL "" FORCE)
set(XD3_ENABLE_LZMA ON CACHE BOOL "" FORCE)
set(XD3_ENABLE_ENCODER ON CACHE BOOL "" FORCE)
set(XD3_ENABLE_VCDIFF_TOOLS OFF CACHE BOOL "" FORCE)

add_subdirectory(xdelta)



