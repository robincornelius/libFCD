cmake_minimum_required (VERSION 2.6)
project (hidapi)

include_directories(hidapi)

# on linux we require to link against libusb-1.0 and libudev for the hidapi to work
if(UNIX)

# linux only, libusb is required for hidapi
MESSAGE("Looking for libusb-1.0")
find_library(LIBUSB1_LIBRARY NAMES usb-1.0 PATHS /usr/lib)

if(LIBUSB1_LIBRARY)
        MESSAGE("Found in ${LIBUSB1_LIBRARY}")
else(LIBUSB1_LIBRARY)
        MESSAGE( FATAL_ERROR "Could not find libusb-1.0")
endif(LIBUSB1_LIBRARY)

find_path(LIBUSB_INCLUDE_DIR libusb.h PATH_SUFFIXES libusb-1.0)

if(LIBUSB_INCLUDE_DIR)
        MESSAGE( "Found libusb.h" )
else(LIBUSB_INCLUDE_DIR)
       MESSAGE( FATAL_ERROR "Could not find libusb.h")
endif(LIBUSB_INCLUDE_DIR)

include_directories(${LIBUSB_INCLUDE_DIR})


#linux only libudev is required for libusb
MESSAGE("Looking for libudev")
find_library(LIBUDEV_LIBRARY NAMES udev PATHS /usr/lib)

if(LIBUDEV_LIBRARY)
        MESSAGE("Found in ${LIBUDEV_LIBRARY}")
else(LIBUDEV_LIBRARY)
        MESSAGE( FATAL_ERROR "Could not find libudev")
endif(LIBUDEV_LIBRARY)

find_path(LIBUDEV_INCLUDE_DIR libudev.h)

if(LIBUDEV_INCLUDE_DIR)
        MESSAGE( "Found libudev.h" )
else(LIBUDEV_INCLUDE_DIR)
       MESSAGE( FATAL_ERROR "Could not find libudev.h")
endif(LIBUDEV_INCLUDE_DIR)

include_directories(${LIBUDEV_INCLUDE_DIR})


ADD_LIBRARY(hidapi SHARED linux/hid-libusb.c)
target_link_libraries(hidapi udev usb-1.0)

endif(UNIX)


if(WIN32)
	ADD_LIBRARY(hidapi SHARED windows/hid.c)
endif(WIN32)

if(APPLE)
	ADD_LIBRARY(hidapi SHARED mac/hid.c)
endif(APPLE)

install(TARGETS hidapi LIBRARY DESTINATION lib COMPONENT runtime)



