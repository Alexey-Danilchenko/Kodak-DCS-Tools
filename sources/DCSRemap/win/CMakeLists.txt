# Windows specific parts of DCSRemap project
set_target_properties(DCSRemap PROPERTIES WIN32_EXECUTABLE TRUE)

set (CMAKE_CXX_FLAGS "/MD")

target_sources(DCSRemap PRIVATE
    DCSRemap.rc
)

qt5_import_plugins(DCSRemap
    INCLUDE Qt::QWindowsIntegrationPlugin
)

# Frameworks
macro(copy_imported_shared_lib _target _shared_target)
    get_target_property(_shared_target_imported "${_shared_target}" IMPORTED)
    if(_shared_target_imported)
        get_target_property(_shared_target_type "${_shared_target}" TYPE)
        if (_shared_target_type STREQUAL "SHARED_LIBRARY")
            get_target_property(_shared_framework_location "${_shared_target}" LOCATION)
            if(EXISTS "${_shared_framework_location}")
                add_custom_command(TARGET ${_target} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${_shared_target}>  $<TARGET_FILE_DIR:${_target}>
                )
            else()
                message(FATAL_ERROR "Imported framework ${_shared_target} not found at: ${_shared_framework_location}")
            endif()
        endif()
    else()
        message(FATAL_ERROR "Framework ${_shared_target} is not an IMPORTED CMake target")
    endif()
endmacro()

function(copy_libraries _target)
    foreach(_lib ${ARGN})
        copy_imported_shared_lib(${_target} ${_lib})
    endforeach()
endfunction()

# Qt5 plugins
# based on code from CMake's QtDialog/CMakeLists.txt
macro(copy_qt5_plugin _target _qt_plugin_name)
    get_target_property(_qt_plugin_path "${_qt_plugin_name}" LOCATION)
    if(EXISTS "${_qt_plugin_path}")
        get_filename_component(_qt_plugin_file "${_qt_plugin_path}" NAME)
        get_filename_component(_qt_plugin_type "${_qt_plugin_path}" PATH)
        get_filename_component(_qt_plugin_type "${_qt_plugin_type}" NAME)
        # Copy plugin to bundle *now* (don't wait for CMake install)
        add_custom_command(TARGET ${_target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${_target}>/${_qt_plugin_type}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${_qt_plugin_name}>  $<TARGET_FILE_DIR:${_target}>/${_qt_plugin_type}
        )
    else()
        message(FATAL_ERROR "QT plugin ${_qt_plugin_name} not found at: ${_qt_plugin_path}")
    endif()
endmacro()

function(copy_qt_plugins _target)
    copy_qt5_plugin(${_target} "Qt5::QWindowsIntegrationPlugin")
endfunction()

# Extras
function(copy_extras _target)
    foreach(_extraDir ${ARGN})
        # Copy plugin to bundle *now* (don't wait for CMake install)
        get_filename_component(dirName "${_extraDir}" NAME)
        add_custom_command(TARGET ${_target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${_target}>/${dirName}
            COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/${_extraDir} $<TARGET_FILE_DIR:${_target}>/${dirName}
        )
    endforeach()
endfunction()

