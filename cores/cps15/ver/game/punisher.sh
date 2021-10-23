#!/bin/bash
# Tests punisher music
# Sound starts at frame 508
cp punisher.inputs sim_inputs.hex
go.sh -g punisher -d DIP_TEST -inputs -w -video 1000 -d DUMP_START=505
