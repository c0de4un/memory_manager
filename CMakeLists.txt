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
set ( PROJECT_NAME "mem" )

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
# OPTIONS
# =================================================================================

option ( BUILD_STATIC "Build as STATIC library" OFF )
option ( BUILD_SHARED "Build as SHARED (dynamic) library" ON )
option ( BUILD_DEMO "Build executable demo." ON )

# =================================================================================
# CONFIGS
# =================================================================================

# DEBUG
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
	add_definitions ( -DDEBUG=1 )
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )

# API
if ( BUILD_SHARED )
    add_definitions ( -DMEM_SHARED=1 )
endif ( BUILD_SHARED )

if ( BUILD_STATIC )
    add_definitions ( -DMEM_STATIC=1 )
endif ( BUILD_STATIC )

# =================================================================================
# HEADERS
# =================================================================================

set( PROJECT_HEADERS
    "" )

# =================================================================================
# SOURCES
# =================================================================================

set( PROJECT_SOURCES
    "" )


# =================================================================================
# MODULES
# =================================================================================

# CORE
add_subdirectory ( "core" )

# =================================================================================
# DEMO
# =================================================================================

#if ( BUILD_DEMO )
    add_subdirectory ( "demo" )
#endif ( BUILD_DEMO )

# =================================================================================
# INSTALL
# =================================================================================

if ( BUILD_STATIC )

    # Install STATIC Library
    install( TARGETS libmem LIBRARY
        DESTINATION "lib/static"
        PUBLIC_HEADER DESTINATION "include" )

elseif ( BUILD_SHARED )

    # Install SHARED Library
    install( TARGETS libmem LIBRARY
        DESTINATION "lib/shared"
        PUBLIC_HEADER DESTINATION "include" )

endif ( BUILD_STATIC )

if ( BUILD_DEMO )
    install( TARGETS mem_demo DESTINATION "bin" )
endif ( BUILD_DEMO )
