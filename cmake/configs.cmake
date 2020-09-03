# ------------------------------------------------------------------------------

# DEBUG
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    add_definitions ( -DDEBUG=1 )
    set ( DEBUG ON )

    #memLib
    set ( MEM_DEBUG ON )
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )

# ------------------------------------------------------------------------------
