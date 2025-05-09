#!/usr/bin/env bash
ulimit -s unlimited
. ../../../testdata_tools/gen.sh

use_solution model_solution.cpp

samplegroup
limits n=10 m=10 t=5
sample 1

group group1 9
limits n=1000000 m=10 t=100
tc 1
tg_manual ../manual_tests/group1

group group2 23
limits n=1000000 m=1000000 t=500000 N=1000000 M=5000
include_group group1
tg_manual ../manual_tests/group2

group group3 19
limits n=1000000 m=1000000 t=500000 N=1000000 M=50000
include_group group2 # group1
tg_manual ../manual_tests/group3

group group4 25
limits n=1000000 m=1000000 t=500000 N=1000000 M=200000
include_group group3 # group2 group1
tg_manual ../manual_tests/group4

group group5 24
limits n=1000000 m=1000000 t=500000 N=1000000 M=1000000
include_group group4 # group3 group2 group1
tg_manual ../manual_tests/group5
