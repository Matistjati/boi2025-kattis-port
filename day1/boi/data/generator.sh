#!/usr/bin/env bash
. ../../../testdata_tools/gen.sh

use_solution model_solution.cpp

samplegroup
limits n=10
sample 1

group group1 11
limits n=10
tc 1
tg_manual ../manual_tests/group1

group group2 12
limits n=2000 is_bo=1
tg_manual ../manual_tests/group2

group group3 10
limits n=2000 is_noeqconsec=1
tg_manual ../manual_tests/group3

group group4 11
limits n=40
include_group group1
tg_manual ../manual_tests/group4

group group5 19
limits n=500
include_group group4
tg_manual ../manual_tests/group5

group group6 37
limits n=2000
include_group group2
include_group group3
include_group group5 # group4 group1
tg_manual ../manual_tests/group6
