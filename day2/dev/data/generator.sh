#!/usr/bin/env bash
. ../../../testdata_tools/gen.sh

use_solution model_solution.cpp

samplegroup
limits n=11 a_max=10
sample 1

group group1 4
limits n=5 a_max=10
tg_manual ../manual_tests/group1

group group2 13
limits n=2000 a_max=1000000000
include_group group1
tc 1
tg_manual ../manual_tests/group2

group group3 8
limits n=200000 a_max=10
include_group group1
tg_manual ../manual_tests/group3

group group4 19
limits n=200000 a_max=1000000000 is_inc=1
tg_manual ../manual_tests/group4

group group5 29
limits n=20000 a_max=1000000000
include_group group2 # group1
tg_manual ../manual_tests/group5

group group6 27
limits n=200000 a_max=1000000000
include_group group3
include_group group4
include_group group5 # group2 group1
tg_manual ../manual_tests/group6
