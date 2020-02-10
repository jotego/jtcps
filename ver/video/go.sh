#!/bin/bash

# The simulation can work loading a local .hex file
# for SDRAM, but it has to be provided in a 8-bit per line format
# use macro SDRAM_HEXFILE or argument -hex to enable this
# The SDRAM file can be obtained from top level simulation in ver/game
# but you need to convert it from 16-bit per line to 8-bit. You can
# use the hex16to8.cc file in this folder to accomplish exactly that.

MACROPREFIX=-D
EXTRA=
MMR=regs.hex

if which ncverilog; then
    MACROPREFIX=+define+
fi

GAME=ghouls
SAVE=1

while [ $# -gt 0 ]; do
    case $1 in
        -g|-game) shift; GAME=$1; shift;;
        -s|-save) shift; SAVE=$1; shift;;
        -hex) EXTRA="$EXTRA ${MACROPREFIX}SDRAM_HEXFILE";;
        -mmr) shift; MMR=$1; shift;;
        -f|-frame) shift; EXTRA="$EXTRA ${MACROPREFIX}FRAMES=$1"; shift;;
        -d) shift; EXTRA="$EXTRA ${MACROPREFIX}$1"; shift;;
        *) echo "ERROR: unknown argument $1"; exit 1;;
    esac
done

# Does the game/snapshot exist?
VRAM_FILE=$GAME/vram$SAVE.bin
REGS_FILE=$GAME/regs$SAVE.hex
ROM_FILE=$GAME/rom
if [[ ! -e $REGS_FILE || ! -e $VRAM_FILE || ! -e $ROM_FILE  ]]; then
    echo "ERROR: could not find the required snapshot files"
    echo $VRAM_FILE
    echo $REGS_FILE
    echo $ROM_FILE
    exit 1
fi

# Link to simulation files
rm -f vram.bin regs.hex rom
ln -s $VRAM_FILE vram.bin
ln -s $REGS_FILE regs.hex
ln -s $ROM_FILE rom

# Prepare bin files
dd if=vram.bin of=vram_sw.bin conv=swab
# Palette
dd if=vram.bin of=pal.bin count=$((8*1024/512)) skip=$((256*256/512)) # iflag=count_bytes,skip_bytes
# Objects
dd if=vram.bin of=obj.bin count=$((256*4*2/512)) skip=$((2*256*256/512)) #iflag=count_bytes,skip_bytes

if which ncverilog; then
    ncverilog test.v -f test.f  +access+r +define+SIMULATION +define+NCVERILOG $EXTRA \
    +define+MMR_FILE=\"$MMR\" $*
else
    iverilog test.v -f test.f -DSIMULATION $EXTRA -DMMR_FILE=\"$MMR\" $* -o sim || exit 1
    sim -lxt
fi

rm -f video*.png
#dd if=video.raw of=x.raw count=$((384*240*4)) iflag=count_bytes
#convert -size 384x240 -depth 8 RGBA:x.raw -resize 200% video.png
convert -size 384x240 -depth 8 RGBA:video.raw -resize 200% video.png
#convert -size 384x240 -depth 8 RGBA:video.raw -resize 800x600 video.png
#convert -size 384x240 -depth 8 RGBA:video.raw video.png
# right aspect ratio:
# convert video.png -resize 598x448 x.png