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

include_directories(/usr/include/libusb-1.0)

#linux only libudev is required for libusb
MESSAGE("Looking for libudev")
find_library(LIBUDEV_LIBRARY NAMES udev PATHS /usr/lib)

if(LIBUDEV_LIBRARY)
        MESSAGE("Found in ${LIBUDEV_LIBRARY}")
else(LIBUDEV_LIBRARY)
        MESSAGE( FATAL_ERROR "Could not find libudev")
endif(LIBUDEV_LIBRARY)

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



