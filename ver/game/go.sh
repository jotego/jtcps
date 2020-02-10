#!/bin/bash

# Ghouls'n Ghosts
# Game starts at address $400. It can be set to reset from it
# ROM check starts at PC=$61adc
# ROM OK written just before PC=$61bd6
# Game execution starts at PC=$400
# First character display around frame 170
# Boot up fails around frame 3220

if [ rom.bin -nt ghouls.hex ]; then
    apply_patches.sh
fi

export GAME_ROM_PATH=rom.bin
export MEM_CHECK_TIME=310_000_000
# 280ms to load the ROM ~17 frames
export BIN2PNG_OPTIONS="--scale"
export CONVERT_OPTIONS="-resize 300%x300%"
GAME_ROM_LEN=$(stat --dereference -c%s $GAME_ROM_PATH)
export YM2151=1
export MSM6295=1

if [ ! -e $GAME_ROM_PATH ]; then
    echo Missing file $GAME_ROM_PATH
    exit 1
fi

# Generic simulation script from JTFRAME
echo "Game ROM length: " $GAME_ROM_LEN
../../modules/jtframe/bin/sim.sh -mist -d GAME_ROM_LEN=$GAME_ROM_LEN \
    -sysname cps1 -modules ../../modules -d SCANDOUBLER_DISABLE=1 \
    -d COLORW=8 -d STEREO_GAME=1 -d JTFRAME_WRITEBACK=1 \
    -d SCAN2X_TYPE=5 -d JT51_NODEBUG\
    -videow 384 -videoh 224 \
    -video $*
