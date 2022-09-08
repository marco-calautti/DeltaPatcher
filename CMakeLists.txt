cmake_minimum_required (VERSION 3.8)

project ("deltapatcher")

if(MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif()

# Subprojects
add_subdirectory (libs)
add_subdirectory (app)
