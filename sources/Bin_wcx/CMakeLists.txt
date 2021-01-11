cmake_minimum_required(VERSION 3.17)

project(BIN_WCX)

# Default build type release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

# static linking for MSVC
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Add common include
include_directories(common)

# 64bit plugin
add_library(kodakbinfw SHARED
    kodakbinfw.cpp
    common/dcs_firm.cpp
    common/dcs_firm.h
    common/dcs_common.cpp
    common/dcs_common.h
)

set_target_properties(kodakbinfw PROPERTIES PREFIX "")
set_target_properties(kodakbinfw PROPERTIES SUFFIX ".wcx64")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(kodakbinfw PUBLIC
        "/GF"   # merge duplicate strings
        "/EHs"  # no SEH; "extern C" may throw
        "/Gy"   # separate functions for linker
        "/Gw"   # separate data for linker
        "/GR-"  # no RTTI
    )
elseif(NOT WIN32)
    target_compile_options(kodakbinfw PUBLIC
        "-fvisibility=hidden"
        "-fvisibility-inlines-hidden"
    )
endif()

# install built plugins to bin directory
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/kodakbinfw64)
if(WIN32)
    install(TARGETS kodakbinfw RUNTIME DESTINATION .)
else()
    install(TARGETS kodakbinfw DESTINATION .)
endif()
install(FILES pluginst.inf DESTINATION .)

