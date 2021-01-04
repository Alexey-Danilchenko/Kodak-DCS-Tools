cmake_minimum_required(VERSION 3.17)

project(DCS_IDA)

# If building the patched version of TMS320C6 CPU module is required, uncomment this
set(BUILD_TMS320C6 TRUE)

# Search path for cmake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

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

# By default build 32 bit address space version of plugins
# these will work with hexrays PPC decompiler
set(IDA_EA64 OFF
    CACHE BOOL "Whether addresses are 64-bit (sizeof(ea_t)==8)" FORCE)

# IDA SDK module
find_package(IDA 7.0 REQUIRED)
if (${IDA_FOUND})
    message("Found IDA SDK " ${IDA_VERSION})
else()
    message("Couldn't find IDA SDK")
endif()

# Add common include
include_directories(common DSP/coff)

# BIN loader
add_ida_module(dcs-bin LOADER SOURCES
    BIN_loader/binloader.cpp
    BIN_loader/immr.h
    common/dcs_common.cpp
    common/dcs_common.h
    common/dcs_firm.cpp
    common/dcs_firm.h
    common/dcs_tiff_tags.cpp
    common/dcs_tiff_tags.h
)

# PPC helper plugins
add_ida_module(ppc2c PLUGIN SOURCES
    PPC/ppc2c.cpp
)
add_ida_module(ppchelper PLUGIN SOURCES
    PPC/ppchelper.cpp
)

# TI DSP
# TI COFF loader
add_ida_module(dcs-dsp LOADER SOURCES
    DSP/coff/dsp_coff.h
    DSP/loader/dsploader.cpp
    common/dcs_tiff_tags.cpp
    common/dcs_tiff_tags.h
)

# TI offset plugin
add_ida_module(offset-finder PLUGIN SOURCES
    DSP/offset_finder/offset_finder.cpp
)

# TI patched CPU module
if (BUILD_TMS320C6)
    add_ida_module(tms320c6 PROCESSOR SOURCES
        DSP/processor/ana.cpp
        DSP/processor/emu.cpp
        DSP/processor/ins.cpp
        DSP/processor/ins.hpp
        DSP/processor/out.cpp
        DSP/processor/reg.cpp
        DSP/processor/tms6.hpp
    )
endif()

# dump TI COFF
add_executable(dump_coff
    DSP/coff/dsp_coff.h
    DSP/coff/dump_coff.cpp
)

# install built plugins to bin directory
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME})
if(WIN32)
    install(TARGETS dcs-bin dcs-dsp
            RUNTIME
            DESTINATION loaders
    )
    install(TARGETS ppc2c ppchelper offset-finder
            RUNTIME
            DESTINATION plugins
    )
    if (BUILD_TMS320C6)
        install(TARGETS tms320c6 RUNTIME DESTINATION procs)
    endif()
else()
    install(TARGETS dcs-bin dcs-dsp
            DESTINATION loaders
    )
    install(TARGETS ppc2c ppchelper offset-finder
            DESTINATION plugins
    )
    if (BUILD_TMS320C6)
        install(TARGETS tms320c6 DESTINATION procs)
    endif()
endif()

install(TARGETS dump_coff
        DESTINATION .
)
