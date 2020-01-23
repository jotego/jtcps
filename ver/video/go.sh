#!/bin/bash

if which ncverilog; then
    ncverilog test.v -f test.f  +access+r +define+SIMULATION +define+NCVERILOG $*
else
    iverilog test.v -f test.f -DSIMULATION $* -o sim || exit 1
    sim -lxt
fi

rm video*.png
convert -size 384x240 -depth 8 RGBA:video.raw -resize 200% video.png
# right aspect ratio:
# convert video.png -resize 598x448 x.png