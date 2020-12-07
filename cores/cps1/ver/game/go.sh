#!/bin/bash

# Ghouls'n Ghosts
# Game starts at address $400. It can be set to reset from it
# ROM check starts at PC=$61adc
# ROM OK written just before PC=$61bd6
# Game execution starts at PC=$400
# First character display around frame 170
# Boot up fails around frame 3220


GAME=ghouls
PATCH=
OTHER=

while [ $# -gt 0 ]; do
    case $1 in
        -g|-game)  shift; GAME=$1; touch rom.bin;;
        -p|-patch) shift; PATCH=$1;;
        *) OTHER="$OTHER $1";;
    esac
    shift
done


ln -sf $ROM/$GAME.rom rom.bin
make || exit $?

CFG_FILE=../video/cfg/${GAME}_cfg.hex
if [[ ! -e $CFG_FILE ]]; then
    echo "ERROR: could not find the required snapshot files"
    ls $CFG_FILE
    exit 1
fi

CPSB_CONFIG=$(cat $CFG_FILE)


export GAME_ROM_PATH=rom.bin
export MEM_CHECK_TIME=310_000_000
# 280ms to load the ROM ~17 frames
export BIN2PNG_OPTIONS="--scale"
export CONVERT_OPTIONS="-resize 300%x300%"
export YM2151=1
export MSM6295=1

if [ ! -e $GAME_ROM_PATH ]; then
    echo Missing file $GAME_ROM_PATH
    exit 1
fi

# Generic simulation script from JTFRAME
$JTFRAME/bin/sim.sh -mist -d GAME_ROM_LEN=$GAME_ROM_LEN \
    -sysname cps1  \
    -def ../../hdl/jtcps1.def \
    -d SCAN2X_TYPE=5 -d JT51_NODEBUG -d CPSB_CONFIG="$CPSB_CONFIG" \
    -d JTCPS_TURBO \
    -videow 384 -videoh 224 \
    $OTHER
