
add_library(edifym_wrapper STATIC libtest.c)

add_custom_target(test  COMMAND rm -f *.o libautopilot/*.o libfly_by_wire/*.o libtest.a
			COMMAND mkdir -p libautopilot libfly_by_wire
			COMMAND ar x ../airborne/autopilot/libautopilot.a
			COMMAND mv *.o libautopilot
			COMMAND ar x ../airborne/fly_by_wire/libfly_by_wire.a
			COMMAND mv *.o libfly_by_wire
			COMMAND ar x libedifym_wrapper.a
			COMMAND ar qc libtest.a *.o libautopilot/*.o libfly_by_wire/*.o
			DEPENDS edifym_wrapper)
