cmake_minimum_required(VERSION 3.17)

project(DCSRemap)

# Search path for cmake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

# Default build type release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Usage of TBB clashes with QT internal emit keyword
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

message("Looking for Qt...")
# Qt modules (https://doc.qt.io/qt-5/qtmodules.html) you're using in your application
find_package(Qt5 REQUIRED ThemeSupport Core Gui Widgets Network Xml XmlPatterns)
if (${Qt5_FOUND})
    message("Found Qt " ${Qt5_VERSION})
else()
    message("Couldn't find Qt")
endif()

# LibRaw
find_package(LibRaw REQUIRED)
if (${LibRaw_FOUND})
    message("Found LibRaw " ${LibRaw_VERSION})
else()
    message("Couldn't find LibRaw")
endif()

# TBB - until QT/TBB is sorted
find_package(TBB REQUIRED tbb)
if (${TBB_FOUND})
    message("Found TBB " ${TBB_VERSION})
else()
    message("Couldn't find TBB")
endif()

# Main executable and version
add_executable(DCSRemap)
set_target_properties(DCSRemap PROPERTIES
    VERSION 1.2
)

# Add common include
include_directories(common)

target_link_libraries(DCSRemap
                      Qt5::ThemeSupport
                      Qt5::Core
                      Qt5::Gui
                      Qt5::Widgets
                      Qt5::Network
                      Qt5::Xml
                      Qt5::XmlPatterns
                      TBB::tbb
                      LibRaw::LibRaw)

add_subdirectory(common)

if (APPLE)
    add_subdirectory(mac)
elseif(WIN32)
    add_subdirectory(win)
else()
    message("Platform not supported!")
endif()

# Post build steps - copy libraries and other dependencies
copy_libraries(DCSRemap
               Qt5::Core
               Qt5::Gui
               Qt5::Widgets
               Qt5::Network
               Qt5::Xml
               Qt5::XmlPatterns
               TBB::tbb
               LibRaw::LibRaw)

copy_qt_plugins(DCSRemap)

copy_extras(DCSRemap
            common/firmware
            common/help)
