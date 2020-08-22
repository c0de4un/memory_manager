# // ------------------------------------------------------------------------------
#
# Tutorial Project for memory-managment methods.
#
# License: see "LICENSE" file.
#
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR ) # QT & Android

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "mem.core" )

# Project Version
set ( PROJECT_VERSION 0.1.0 )

# Project Description
set ( PROJECT_DESCRIPTION "Simple & lightweight memory-managment library, designed, primary, for mobile platforms." )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# =================================================================================
# HEADERS
# =================================================================================

set( PROJECT_HEADERS ${PROJECT_HEADERS}
    "public/mem.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set( PROJECT_SOURCES ${PROJECT_SOURCES}
    "private/mem.cpp" )

# =================================================================================
# BUILD
# =================================================================================

if ( BUILD_STATIC )

    # Add Library-Object
    add_library ( libmem STATIC ${PROJECT_HEADERS} ${PROJECT_SOURCES} )
elseif ( BUILD_SHARED )

    # Add Library-Object
    add_library ( libmem SHARED ${PROJECT_SOURCES} )

    # Configure Library-Object
    set_target_properties ( libmem PROPERTIES
        PUBLIC_HEADER ${PROJECT_HEADERS}
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        SOVERSION 1
        VERSION PROJECT_VERSION )

else ( BUILD_STATIC )
    message ( STATUS "${PROJECT_NAME} - headers & sources will exported to <MEM_HEADERS> & <MEM_SOURCES>" )
    set ( MEM_HEADERS ${PROJECT_HEADERS} ${MEM_HEADERS} PARENT_SCOPE )
    set ( MEM_SOURCES ${PROJECT_SOURCES} ${MEM_SOURCES} PARENT_SCOPE )
endif ( BUILD_STATIC )
