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
set ( PROJECT_NAME "memLib" )

# Project Version
set ( PROJECT_VERSION 0.1.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# =================================================================================
# CONFIGS
# =================================================================================

if ( MEM_DEBUG )
    add_definitions ( -DMEM_DEBUG=1 )
endif ( MEM_DEBUG )

set ( PUBLIC_DIR "" )
set ( PRIVATE_DIR "../../private/mem/" )

# =================================================================================
# HEADERS
# =================================================================================

set ( MEM_HEADERS 
    "${PUBLIC_DIR}allocators/LinearAllocator.hpp"
    "${PUBLIC_DIR}allocators/StackAllocator.hpp"
    "${PUBLIC_DIR}resources/IMemoryResource.hxx"
    "${PUBLIC_DIR}engine/MemoryEngine.hpp"
    "${PUBLIC_DIR}mem.hpp" )

if ( MEM_DEBUG )
    set ( MEM_HEADERS ${MEM_HEADERS}
        "${PUBLIC_DIR}configs/mem_log.hpp"
        "${PUBLIC_DIR}utils/metrics/DummyLogger.hpp" )
endif ( MEM_DEBUG )

# =================================================================================
# SOURCES
# =================================================================================

set ( MEM_SOURCES
    "${PRIVATE_DIR}engine/MemoryEngine.cpp"
    "${PRIVATE_DIR}mem.cpp" )

if ( MEM_DEBUG )
    set ( MEM_SOURCES ${MEM_SOURCES}
        "${PRIVATE_DIR}utils/metrics/DummyLogger.cpp" )
endif ( MEM_DEBUG )

# =================================================================================
# BUILD
# =================================================================================

# Log
message ( STATUS "${PROJECT_NAME} - HEADERS: ${MEM_HEADERS}\nSOURCES: ${MEM_SOURCES}" )

# Build STATIC Library
add_library ( memLib STATIC ${MEM_HEADERS} ${MEM_SOURCES} )

# =================================================================================
# INSTALL
# =================================================================================

# Install STATIC Library
install ( TARGETS memLib LIBRARY
    DESTINATION "lib/static"
    PUBLIC_HEADER DESTINATION "include" )

# ------------------------------------------------------------------------------
