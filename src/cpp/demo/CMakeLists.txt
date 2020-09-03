# ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR ) # QT & Android

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "memLib.Demo" )

# Project Version
set ( PROJECT_VERSION 0.1.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# =================================================================================
# HEADERS
# =================================================================================

set ( PROJECT_HEADERS "main.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( PROJECT_SOURCES "main.cpp" )

set ( WIN_RESOURCES "${CMAKE_SOURCE_DIR}/res/win_res.rc" )

# =================================================================================
# BUILD
# =================================================================================

# Build STATIC Library
add_executable ( demo ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${WIN_RESOURCES} )

# Configure Executable-Object
set_target_properties ( demo PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" )

# Link with memLib
target_link_libraries ( demo memLib )
target_include_directories ( demo PUBLIC "${CMAKE_SOURCE_DIR}/src/cpp/mem/public" )

# ------------------------------------------------------------------------------
