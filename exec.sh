#!/bin/bash
cmake .
make
make test
cp sw/edifym/libtest.a ../Edifym/EdifymRunner
