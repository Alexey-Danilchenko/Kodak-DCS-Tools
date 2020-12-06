#
# FindLibRaw
# ----------
#
# Find the LibRaw library <http://www.libraw.org>
#
# Imported Targets
# ----------------
#
# This module provides the following imported targets, if found:
#    LibRaw::LibRaw
#
# Result Variables
# ----------------
#
# This will define the following variables:
#
#   LibRaw_FOUND        - True if the system has the Foo library.
#   LibRaw_VERSION      - The version of the Foo library which was found.
#   LibRaw_INCLUDE_DIRS - Include directories needed to use Foo.
#   LibRaw_LIBRARIES    - Libraries needed to link to Foo.
#
# Cache Variables
# ---------------
#
# The following cache variables may also be set:
#
#   LibRaw_INCLUDE_DIR  - The directory containing libraw.h
#   LibRaw_LIBRARY      - The path to the LibRaw library.
#
# Copyright (c) 2020 Alexey Danilchenko
#
# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.
#

find_path(LibRaw_INCLUDE_DIR libraw.h PATH_SUFFIXES libraw)

find_library(LibRaw_LIBRARY NAMES raw_r libraw)

find_file(_libraw_DLL libraw.dll PATH_SUFFIXES bin)

IF(LibRaw_INCLUDE_DIR)
   FILE(READ ${LibRaw_INCLUDE_DIR}/libraw_version.h _libraw_version_content)

   STRING(REGEX MATCH "#define LIBRAW_MAJOR_VERSION[ \t]*([0-9]*)\n" _version_major_match ${_libraw_version_content})
   SET(_libraw_version_major "${CMAKE_MATCH_1}")

   STRING(REGEX MATCH "#define LIBRAW_MINOR_VERSION[ \t]*([0-9]*)\n" _version_minor_match ${_libraw_version_content})
   SET(_libraw_version_minor "${CMAKE_MATCH_1}")

   STRING(REGEX MATCH "#define LIBRAW_PATCH_VERSION[ \t]*([0-9]*)\n" _version_patch_match ${_libraw_version_content})
   SET(_libraw_version_patch "${CMAKE_MATCH_1}")

   IF(_version_major_match AND _version_minor_match AND _version_patch_match)
      SET(LibRaw_VERSION "${_libraw_version_major}.${_libraw_version_minor}.${_libraw_version_patch}")
   ELSE()
      IF(NOT LibRaw_FIND_QUIETLY)
         MESSAGE(STATUS "Failed to get version information from ${LibRaw_INCLUDE_DIR}/libraw_version.h")
      ENDIF()
   ENDIF()
ENDIF()

# Handle exported variables
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibRaw
                                  FOUND_VAR LibRaw_FOUND
                                  REQUIRED_VARS LibRaw_LIBRARY LibRaw_INCLUDE_DIR
                                  VERSION_VAR LibRaw_VERSION)

# set plural vars and
if(LibRaw_FOUND)
   set(LibRaw_LIBRARIES ${Foo_LIBRARY})
   set(LibRaw_INCLUDE_DIRS ${LibRaw_INCLUDE_DIR})

   mark_as_advanced(LibRaw_VERSION
                    LibRaw_INCLUDE_DIR
                    LibRaw_LIBRARIES)
endif()

# Create imported target LibRaw::LibRaw
if(LibRaw_FOUND AND NOT TARGET LibRaw::LibRaw)
   if(_libraw_DLL)
      add_library(LibRaw::LibRaw SHARED IMPORTED)
      set_target_properties(LibRaw::LibRaw PROPERTIES
                            IMPORTED_IMPLIB "${LibRaw_LIBRARY}"
                            IMPORTED_LOCATION "${_libraw_DLL}"
                            INTERFACE_INCLUDE_DIRECTORIES "${LibRaw_INCLUDE_DIR}"
      )
   else()
      add_library(LibRaw::LibRaw UNKNOWN IMPORTED)
      set_target_properties(LibRaw::LibRaw PROPERTIES
                            IMPORTED_LOCATION "${LibRaw_LIBRARY}"
                            INTERFACE_INCLUDE_DIRECTORIES "${LibRaw_INCLUDE_DIR}"
      )
   endif()
endif()
