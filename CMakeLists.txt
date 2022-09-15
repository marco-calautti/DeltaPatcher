cmake_minimum_required (VERSION 3.8)

project ("deltapatcher")

set(CMAKE_CXX_STANDARD 11)

if(MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static -s")
endif()

# Subprojects
add_subdirectory (libs)
add_subdirectory (app)
