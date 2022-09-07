include_directories (include)

FILE(GLOB_RECURSE SOURCES src/*.cpp)

if (WIN32)
    ENABLE_LANGUAGE(RC)
    set(SOURCES win_stuff/resource.rc ${SOURCES})
endif()

add_executable(DeltaPatcher WIN32 ${SOURCES})
target_link_libraries(DeltaPatcher wx::core wx::base xdelta3)