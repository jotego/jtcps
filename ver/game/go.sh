#!/bin/bash
if [[ -N rom.bin || ! -s sdram.hex ]]; then
    #bin2hex is a JTFRAME file
    bin2hex < rom.bin > sdram.hex
fi

export GAME_ROM_PATH=rom.bin
export MEM_CHECK_TIME=310_000_000
# 280ms to load the ROM ~17 frames
export BIN2PNG_OPTIONS="--scale"
export CONVERT_OPTIONS="-resize 300%x300%"
GAME_ROM_LEN=$(stat -c%s $GAME_ROM_PATH)
GAME_ROM_LEN=$((GAME_ROM_LEN/8))
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
    -d COLORW=8 -d STEREO_GAME=1 -d JTFRAME_WRITEBACK=1\
    -video $*
