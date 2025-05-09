#!/usr/bin/env bash
. ../../../testdata_tools/gen.sh

use_solution model_solution.cpp

samplegroup
limits n=8 q=4 a_max=5
sample 1

group group1 6
limits n=8 q=10 a_max=1000000
tc 1
tg_manual ../manual_tests/group1

group group2 8
limits n=200 q=300000 a_max=1000000
include_group group1
tg_manual ../manual_tests/group2

group group3 23
limits n=2000 q=2000 a_max=1000000
include_group group1
tg_manual ../manual_tests/group3

group group4 22
limits n=300000 q=300000 a_max=20
tg_manual ../manual_tests/group4

group group5 41
limits n=300000 q=300000 a_max=1000000
include_group group2 # group1
include_group group3
include_group group4
tg_manual ../manual_tests/group5
