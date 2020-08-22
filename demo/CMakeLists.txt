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
set ( PROJECT_NAME "mem-demo" )

# Project Version
set ( PROJECT_VERSION 0.0.0 )

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

set( PROJECT_HEADERS
    "" )

# =================================================================================
# SOURCES
# =================================================================================

set( PROJECT_SOURCES
    "${CMAKE_SOURCE_DIR}/demo/main.cpp" )

# =================================================================================
# RESOURCES
# =================================================================================

if ( BUILD_DEMO )
    if ( WIN32 OR WIN64 OR MINGW OR MINGW64 OR MINGW32 OR MSVC )
        set( RESOURCES "${CMAKE_SOURCE_DIR}/res/win_res.rc" )
    endif ( WIN32 OR WIN64 OR MINGW OR MINGW64 OR MINGW32 OR MSVC )
endif ( BUILD_DEMO )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable-Object
add_executable ( mem_demo ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${RESOURCES} )

# Configure Executable-Object
set_target_properties ( mem_demo PROPERTIES
    VERSION ${PROJECT_VERSION}
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" )

# Link
include_directories ( "../core/public" )
target_link_libraries ( mem_demo libmem )