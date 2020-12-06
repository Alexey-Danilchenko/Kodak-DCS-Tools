# MacOS X specific parts of DCSRemap project
get_target_property(DCSRemap_VERSION DCSRemap VERSION)

set_target_properties(DCSRemap PROPERTIES
    MACOSX_BUNDLE                      TRUE
    MACOSX_BUNDLE_BUNDLE_NAME          DCSRemap
    MACOSX_BUNDLE_BUNDLE_VERSION       "${DCSRemap_VERSION}"
    MACOSX_BUNDLE_COPYRIGHT            "© 2013-2020 Alexey Danilchenko"
    MACOSX_BUNDLE_GUI_IDENTIFIER       com.DCSRemap
    MACOSX_BUNDLE_ICON_FILE            DCSRemap.icns
    MACOSX_BUNDLE_INFO_STRING          "Sensor defect remap application for Kodak DCS Cameras"
    MACOSX_BUNDLE_LONG_VERSION_STRING  "${DCSRemap_VERSION}"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${DCSRemap_VERSION}"
    MACOSX_BUNDLE_INFO_PLIST           ${CMAKE_SOURCE_DIR}/mac/Info.plist
    # Since the dependencies are bundled as part of the build stages (and not at install-time), build with the install rpath
    BUILD_WITH_INSTALL_RPATH           TRUE
    INSTALL_RPATH                       "@executable_path/../Frameworks"
)

set_source_files_properties(
    DCSRemap.icns
    TARGET_DIRECTORY DCSRemap
    PROPERTIES MACOSX_PACKAGE_LOCATION Resources
)

target_sources(DCSRemap PRIVATE
    DCSRemap.icns
)

# For static QT builds - import plugins
qt5_import_plugins(DCSRemap
    INCLUDE Qt::QCocoaIntegrationPlugin
)

# Shared libs
macro(copy_imported_shared_lib _target _shared_target)
    get_target_property(_framework_target_imported "${_shared_target}" IMPORTED)
    if(_framework_target_imported)
        get_target_property(_framework_target_type "${_shared_target}" TYPE)
        if (_framework_target_type STREQUAL "SHARED_LIBRARY")
            if(CMAKE_BUILD_TYPE STREQUAL "Debug")
                get_target_property(_shared_target_location "${_shared_target}" LOCATION_DEBUG)
            else()
                get_target_property(_shared_target_location "${_shared_target}" LOCATION_RELEASE)
            endif()
            if(EXISTS "${_shared_target_location}")
                # Copy plugin to bundle *now* (don't wait for CMake install)
                set_source_files_properties(
                    ${_shared_target_location} PROPERTIES
                        MACOSX_PACKAGE_LOCATION "Frameworks"
                )
                target_sources(${_target} PRIVATE ${_shared_target_location})
                # create symlink if needed
                if(CMAKE_BUILD_TYPE STREQUAL "Debug")
                    get_target_property(_shared_imp_soname "${_shared_target}" IMPORTED_SONAME_DEBUG)
                else()
                    get_target_property(_shared_imp_soname "${_shared_target}" IMPORTED_SONAME_RELEASE)
                endif()
                get_filename_component(_shared_soname "${_shared_imp_soname}" NAME)
                get_filename_component(_shared_file "${_shared_target_location}" NAME)
                if(NOT ${_shared_soname} STREQUAL ${_shared_file})
                    add_custom_command(TARGET ${_target} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E create_symlink
                            ${_shared_file}
                            $<TARGET_FILE_DIR:${_target}>/../Frameworks/${_shared_soname}
                    )
                endif()
            else()
                message(FATAL_ERROR "Imported framework ${_shared_target} not found at: ${_shared_target_location}")
            endif()
        endif()
    else()
        message(FATAL_ERROR "Framework ${_shared_target} is not an IMPORTED CMake target")
    endif()
endmacro()

function(copy_libraries _target)
    # Handling non QT5
    foreach(_lib ${ARGN})
        if(NOT ${_lib} MATCHES "^Qt5")
            copy_imported_shared_lib(${_target} ${_lib})
        endif()
    endforeach()

    # Retrieve the absolute path to uic and then use that path to find
    # the binaries
    get_target_property(_qmake_executable Qt5::uic IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(_macdeployqt macdeployqt HINTS "${_qt_bin_dir}")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_custom_command(TARGET ${_target} POST_BUILD
            COMMAND "${_macdeployqt}"
                "$<TARGET_FILE_DIR:${_target}>/../.."
                -always-overwrite -no-plugins -no-strip
                COMMENT "Running macdeployqt..."
        )
    else()
        add_custom_command(TARGET ${_target} POST_BUILD
            COMMAND "${_macdeployqt}"
                "$<TARGET_FILE_DIR:${_target}>/../.."
                -always-overwrite -no-plugins
                COMMENT "Running macdeployqt..."
        )
    endif()
endfunction()

# Qt5 plugins
# based on code from CMake's QtDialog/CMakeLists.txt
macro(copy_qt5_plugin _target _qt_plugin_name)
    get_target_property(_qt_plugin_path "${_qt_plugin_name}" LOCATION)
    if(EXISTS "${_qt_plugin_path}")
        get_filename_component(_qt_plugin_file "${_qt_plugin_path}" NAME)
        get_filename_component(_qt_plugin_type "${_qt_plugin_path}" PATH)
        get_filename_component(_qt_plugin_type "${_qt_plugin_type}" NAME)
        set(_qt_plugin_dest "PlugIns/${_qt_plugin_type}")
        # Copy plugin to bundle *now* (don't wait for CMake install)
        set_source_files_properties(
            ${_qt_plugin_path} PROPERTIES
                MACOSX_PACKAGE_LOCATION "${_qt_plugin_dest}"
        )
        target_sources(${_target} PRIVATE ${_qt_plugin_path})
    else()
        message(FATAL_ERROR "QT plugin ${_qt_plugin_name} not found at: ${_qt_plugin_path}")
    endif()
endmacro()

function(copy_qt_plugins _target)
    copy_qt5_plugin(${_target} "Qt5::QCocoaIntegrationPlugin")
endfunction()

# Extras
function(copy_extras _target)
    foreach(_extraDir ${ARGN})
        # Copy plugin to bundle *now* (don't wait for CMake install)
        get_filename_component(dirName "${_extraDir}" NAME)
        add_custom_command(TARGET ${_target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${_target}>/../${dirName}
            COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/${_extraDir} $<TARGET_FILE_DIR:${_target}>/../${dirName}
        )
    endforeach()
endfunction()
