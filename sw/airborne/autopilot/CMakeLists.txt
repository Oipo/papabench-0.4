include_directories(${CMAKE_SOURCE_DIR}/sw/include)
include_directories(${CMAKE_SOURCE_DIR}/avr/include)
include_directories(${CMAKE_SOURCE_DIR}/sw/var/include)
include_directories(${CMAKE_SOURCE_DIR}/sw/airborne/autopilot)
include_directories(${CMAKE_SOURCE_DIR}/sw/airborne/fly_by_wire)

add_definitions(-DUBX -D__AVR_ATmega128__ -DSTACK=\"0x80000000\" -DPAPABENCH_TEST -DNO_AVR_PLATFORM -DUNROLL_FP_LOOPS)

add_library(autopilot STATIC main.c modem.c link_fbw.c spi.c adc.c infrared.c pid.c
                         nav.c uart.c estimator.c if_calib.c mainloop.c
                         gps_ubx.c
                         ${CMAKE_SOURCE_DIR}/sw/lib/c/math.c)

set_target_properties(autopilot PROPERTIES LINK_FLAGS "-static" )
