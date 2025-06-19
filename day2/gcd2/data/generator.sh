#!/usr/bin/env bash
. ../../../testdata_tools/gen.sh

use_solution model_solution.cpp

samplegroup
limits n=3
sample 1

group group1 17
limits n=2
tg_manual ../manual_tests/group1

group group2 34
limits n=10
include_group group1
tc 1
tg_manual ../manual_tests/group2

group group3 11
limits n=1000
include_group group2 # group1
tg_manual ../manual_tests/group3

group group4 38
limits n=1000000
include_group group3 # group3 group2 group1
tg_manual ../manual_tests/group4
