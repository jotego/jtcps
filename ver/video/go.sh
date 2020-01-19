#!/bin/bash

if which ncverilog; then
    ncverilog test.v -f test.f  +access+r +define+SIMULATION +define+NCVERILOG
else
    iverilog test.v -f test.f -DSIMULATION -o sim || exit 1
    sim -lxt
fi

convert -size 512x256 -depth 8 RGBA:video.raw video.png
