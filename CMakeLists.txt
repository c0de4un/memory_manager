# ------------------------------------------------------------------------------

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
# OPTIONS
# =================================================================================

include ( "cmake/options.cmake" )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "memLib.root" )

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
# CONFIGS
# =================================================================================

include ( "cmake/configs.cmake" )

# =================================================================================
# MODULES
# =================================================================================

# memLib
add_subdirectory ( "src/cpp/mem/public/mem" )

# memLib.Demo
add_subdirectory ( "src/cpp/demo" )

# ------------------------------------------------------------------------------
