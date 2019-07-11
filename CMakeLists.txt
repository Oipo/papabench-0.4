# add sub-directories
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER   aarch64-linux-gnu-gcc)
SET(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -s -fno-stack-protector ")

add_subdirectory(sw/airborne/autopilot)
add_subdirectory(sw/airborne/fly_by_wire)
add_subdirectory(sw/edifym)