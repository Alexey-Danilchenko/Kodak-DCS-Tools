#=============================================================================
# This is derived from Sam Hanes implementation:
#      https://github.com/Elemecca/cmake-ida/blob/master/FindIDA.cmake
# and distributed under the same license (see the link above)
#=============================================================================
find_path(IDA_ROOT_DIR
    NAMES "include/ida.hpp"
    DOC "Location of the extracted IDA SDK"
)

if(IDA_ROOT_DIR)
    file(STRINGS
        "${IDA_ROOT_DIR}/include/pro.h"
        _ida_version_define
        REGEX "IDA_SDK_VERSION"
        LIMIT_COUNT 1
    )

    if(_ida_version_define MATCHES "define +IDA_SDK_VERSION +([0-9])([0-9]+)")
        set(IDA_VERSION_MAJOR ${CMAKE_MATCH_1})
        set(IDA_VERSION_MINOR ${CMAKE_MATCH_2})
        set(IDA_VERSION "${IDA_VERSION_MAJOR}.${IDA_VERSION_MINOR}")
    endif()

    unset(_ida_version_define)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(IDA
    REQUIRED_VARS IDA_ROOT_DIR
    VERSION_VAR IDA_VERSION
)

if(IDA_FOUND)
    set(IDA_EA64 ON CACHE BOOL
        "Whether addresses are 64-bit (sizeof(ea_t)==8)"
    )

    if(IDA_EA64)
        set(_ida_ea 64)
        set(_ida_module_suffix 64)
        list(APPEND IDA_DEFINITIONS __EA64__)
    else()
        set(_ida_ea 32)
        set(_ida_module_suffix)
    endif()

    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^AMD64|x86_64$")
        list(APPEND IDA_DEFINITIONS __X64__)
        set(_ida_arch x64)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^X86|i686$")
        set(_ida_arch x86)
    else()
        message(FATAL_ERROR
            "Unsupported processor ${CMAKE_SYSTEM_PROCESSOR}"
        )
    endif()

    if(WIN32)
        list(APPEND IDA_DEFINITIONS __NT__)
        set(_ida_target win_vc)
        set(_ida_lib ida.lib)
    elseif(APPLE)
        list(APPEND IDA_DEFINITIONS __MAC__)
        set(_ida_target mac_gcc)
        if(IDA_EA64)
            set(_ida_lib libida64.dylib)
        else()
            set(_ida_lib libida.dylib)
        endif()
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        list(APPEND IDA_DEFINITIONS __LINUX__)
        set(_ida_target linux_gcc)
        if(IDA_EA64)
            set(_ida_lib libida64.so)
        else()
            set(_ida_lib libida.so)
        endif()
    else()
        message(FATAL_ERROR
            "Unsupported target system ${CMAKE_SYSTEM_NAME}"
        )
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        # remove /EHsc and /GR from default CXX flags
        string(REGEX REPLACE
               " */EH[a-z]+ *" " "
               CMAKE_CXX_FLAGS
               ${CMAKE_CXX_FLAGS}
        )
        string(REGEX REPLACE
               " */GR.? *" " "
               CMAKE_CXX_FLAGS
               ${CMAKE_CXX_FLAGS}
        )
    endif()

    set(IDA_LIBRARY_DIR
        ${IDA_ROOT_DIR}/lib/${_ida_arch}_${_ida_target}_${_ida_ea}
    )

    set(IDA_LIBRARY_DIRS ${IDA_LIBRARY_DIR})
    set(IDA_LIBRARIES ${IDA_LIBRARY_DIR}/${_ida_lib})

    set(IDA_INCLUDE_DIRS ${IDA_ROOT_DIR}/include ${IDA_ROOT_DIR}/module)

    add_library(IDA INTERFACE)
    set_target_properties(IDA PROPERTIES
        INTERFACE_LINK_LIBRARIES "${IDA_LIBRARIES}"
        INTERFACE_INCLUDE_DIRECTORIES "${IDA_INCLUDE_DIRS}"
        INTERFACE_COMPILE_DEFINITIONS "${IDA_DEFINITIONS}"
        INTERFACE_POSITION_INDEPENDENT_CODE ON
    )
endif()



function(add_ida_module module_name)
    set(options PLUGIN LOADER PROCESSOR)
    set(oneValue)
    set(multiValue SOURCES)
    cmake_parse_arguments(PARSE_ARGV 1 module
        "${options}" "${oneValue}" "${multiValue}"
    )

    add_library(${module_name} SHARED ${module_SOURCES})
    target_link_libraries(${module_name} PUBLIC IDA)

    set_target_properties(${module_name} PROPERTIES
        PREFIX "" # suppress lib prefix
        OUTPUT_NAME "${module_name}${_ida_module_suffix}"
    )


    if((module_PLUGIN AND (module_LOADER OR module_PROCESSOR))
            OR (module_LOADER AND module_PROCESSOR))
        message(FATAL_ERROR
            "Only one module type (PLUGIN, LOADER, or PROCESSOR)"
            " is permitted."
        )
    endif()

    if(module_PLUGIN)
        set(_ida_export  "PLUGIN")
        set(_ida_vscript "${IDA_ROOT_DIR}/plugins/plugin.script")
    elseif(module_LOADER)
        set(_ida_export  "LDSC")
        set(_ida_vscript "${IDA_ROOT_DIR}/ldr/ldr.script")
    elseif(module_PROCESSOR)
        target_compile_definitions(${module_name} PUBLIC __IDP__)
        set(_ida_export  "LPH")
        set(_ida_vscript "${IDA_ROOT_DIR}/module/idp.script")
    else()
        message(FATAL_ERROR
            "The module type (PLUGIN, LOADER, or PROCESSOR)"
            " is required."
        )
    endif()


    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_definitions(${module_name} PUBLIC __VC__)

        # extract warnings flags from SDK makefile
        file(STRINGS
            "${IDA_ROOT_DIR}/makeenv_vc.mak"
            _ida_compile_warnings
            REGEX "^/w[de][0-9]+"
        )

        list(APPEND _ida_compile_flags
            # flags taken from makeenv_vc.mak in the SDK
            "/GF"   # merge duplicate strings
            "/EHs"  # no SEH; "extern C" may throw
            "/Gy"   # separate functions for linker
            "/Gw"   # separate data for linker
            "/Wall" # all warnings on
            "/GR-"  # no RTTI
            "/wd5204" # remove lost of IDA virtual destructor missing warnings
            ${_ida_compile_warnings}
        )

        list(APPEND _ida_link_flags
            "/EXPORT:${_ida_export},@1,,DATA")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        # when building Windows DLLs with mingw-w64, statically link
        # the GCC runtime libraries so only the output DLL is needed
        if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
            list(APPEND _ida_link_flags
                "-static-libgcc"
                "-static-libstdc++"
            )
        else()
            list(APPEND _ida_compile_flags
                 "-fvisibility=hidden"
                 "-fvisibility-inlines-hidden"
            )
        endif()

        list(APPEND _ida_link_flags
            "-Wl,--version-script=${_ida_vscript}"
        )
    elseif(APPLE)
        list(APPEND _ida_compile_flags
             "-fvisibility=hidden"
             "-fvisibility-inlines-hidden"
        )
    else()
        message(FATAL_ERROR
                "Compiler '${CMAKE_CXX_COMPILER_ID}' is not supported on platform '${CMAKE_SYSTEM_NAME}'."
        )
    endif()

    # convert flag lists to space-delimited strings and set on target
    string(REPLACE ";" " " _ida_compile_flags "${_ida_compile_flags}")
    string(REPLACE ";" " " _ida_link_flags "${_ida_link_flags}")
    set_target_properties(${module_name} PROPERTIES
        COMPILE_FLAGS "${_ida_compile_flags}"
        LINK_FLAGS "${_ida_link_flags}"
    )
endfunction()
