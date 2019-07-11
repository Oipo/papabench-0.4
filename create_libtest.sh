#!/bin/bash
rm sw/libtest.a
cd sw/airborne/autopilot
aarch64-linux-gnu-ar -x libautopilot.a 
cd -
cd sw/airborne/fly_by_wire
aarch64-linux-gnu-ar -x libfly_by_wire.a 
cd -
cd sw/edifym
aarch64-linux-gnu-ar -x libedifym_wrapper.a 
cd ..
aarch64-linux-gnu-ar -qc libtest.a airborne/fly_by_wire/*.o airborne/autopilot/*.o edifym/*.o
cd ..
