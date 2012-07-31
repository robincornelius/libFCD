project(FCD)
set(FCD_Sources FCDlib.c HID.c)

add_definitions(-DFCDLIB_EXPORTS)
ADD_LIBRARY(FCD SHARED ${FCD_Sources})

install(TARGETS FCD LIBRARY DESTINATION lib COMPONENT runtime)

