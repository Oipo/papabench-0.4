include_directories(${CMAKE_SOURCE_DIR}/avr/include)
include_directories(${CMAKE_SOURCE_DIR}/sw/include)
include_directories(${CMAKE_SOURCE_DIR}/sw/var/include)

add_definitions(-D__AVR_ATmega8__ -DSTACK=\"0x80000000\" -DPAPABENCH_TEST -DNO_AVR_PLATFORM)

add_executable(fly_by_wire main.c ppm.c servo.c spi.c uart.c adc_fbw.c)

set_target_properties(fly_by_wire PROPERTIES LINK_FLAGS "-static" )
