include_directories (include)

FILE(GLOB_RECURSE SOURCES src/*.cpp)

if (WIN32)
    ENABLE_LANGUAGE(RC)
    set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/win_stuff/resource.rc ${SOURCES})
endif()

add_executable(DeltaPatcher WIN32 ${SOURCES})
target_link_libraries(DeltaPatcher wx::core wx::base xdelta3)

if (APPLE)
    set(bundle_icon ${CMAKE_CURRENT_SOURCE_DIR}/mac_stuff/icon.icns)
    target_sources(DeltaPatcher PRIVATE ${bundle_icon})
    set_source_files_properties(${bundle_icon} PROPERTIES MACOSX_PACKAGE_LOCATION Resources/)
    set_target_properties(DeltaPatcher PROPERTIES MACOSX_BUNDLE TRUE MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/mac_stuff/Info.plist)
endif()

install(TARGETS DeltaPatcher DESTINATION bin)
install(FILES linux_stuff/io.github.marco_calautti.DeltaPatcher.desktop DESTINATION share/applications)
install(FILES linux_stuff/io.github.marco_calautti.DeltaPatcher.metainfo.xml DESTINATION share/metainfo)

foreach(SIZE "16" "24" "32" "48" "64" "128" "256")
    install(FILES ../graphics/icon${SIZE}.png DESTINATION share/icons/hicolor/${SIZE}x${SIZE}/apps RENAME  io.github.marco_calautti.DeltaPatcher.png)
endforeach()
