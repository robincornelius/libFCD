project(FCDControl)
set(FCDControl_sources main.c)

MESSAGE("Looking for argtable2")
find_library(ARGTABLE2_LIBRARY NAMES argtable2 PATHS /usr/lib)

if(ARGTABLE2_LIBRARY)
        MESSAGE("Found in ${ARGTABLE2_LIBRARY}")
else(ARGTABLE2_LIBRARY)
        MESSAGE( FATAL_ERROR "Could not find argtable2")
endif(ARGTABLE2_LIBRARY)

find_path(ARGTABLE2_INCLUDE_DIR argtable2.h)

if(ARGTABLE2_INCLUDE_DIR)
	MESSAGE( "Found argtable2.h" )
else(ARGTABLE2_INCLUDE_DIR)
       MESSAGE( FATAL_ERROR "Could not find argtable2.h")
endif(ARGTABLE2_INCLUDE_DIR)

include_directories(../FCDlib/)
include_directories(ARGTABLE2_INCLUDE_DIR)

add_executable(FCDControl main.c)
target_link_libraries(FCDControl FCD hidapi argtable2)

install(TARGETS FCDControl RUNTIME DESTINATION bin COMPONENT runtime)

