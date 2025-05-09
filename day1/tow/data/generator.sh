#!/usr/bin/env bash
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution ../empty.py

samplegroup
limits nl=3 nh=9 k=100 k100=100
sample 1

group group1 6
limits nl=3 nh=9 k=8000 k100=8000
tg_manual ../manual_tests/group1

group group2 7
limits nl=40 nh=50 k=4500 k100=4500
tg_manual ../manual_tests/group2

group group3 9
limits nl=90 nh=100 k=3000 k100=3000
tg_manual ../manual_tests/group3

group group4 22
limits nl=400 nh=400 k=4500 k100=4500 is_halfset=1
tg_manual ../manual_tests/group4

group group5 56
limits nl=500 nh=500 k=12000 k100=4200
tg_manual ../manual_tests/group5
