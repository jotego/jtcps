#!/bin/bash

MACROPREFIX=-D
EXTRA=
MMR=ghouls_start.hex

if which ncverilog; then
    MACROPREFIX=+define+
fi

while [ $# -gt 0 ]; do
    case $1 in
        -mmr) shift; MMR=$1; shift;;
        -f|-frame) shift; EXTRA="$EXTRA ${MACROPREFIX}FRAMES=$1"; shift;;
        -d) shift; EXTRA="$EXTRA ${MACROPREFIX}$1"; shift;;
        *) echo "ERROR: unknown argument $1"; exit 1;;
    esac
done

if which ncverilog; then
    ncverilog test.v -f test.f  +access+r +define+SIMULATION +define+NCVERILOG $EXTRA \
    +define+MMR_FILE=\"$MMR\" $*
else
    iverilog test.v -f test.f -DSIMULATION $EXTRA -DMMR_FILE=\"$MMR\" $* -o sim || exit 1
    sim -lxt
fi

rm video*.png
convert -size 384x240 -depth 8 RGBA:video.raw -resize 200% video.png
#convert -size 384x240 -depth 8 RGBA:video.raw -resize 800x600 video.png
#convert -size 384x240 -depth 8 RGBA:video.raw video.png
# right aspect ratio:
# convert video.png -resize 598x448 x.png