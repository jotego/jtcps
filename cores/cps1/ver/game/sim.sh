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
SCENE=

while [ $# -gt 0 ]; do
    case $1 in
        -g|-game)
            shift
            GAME=$1
            if [ ! -e $ROM/$GAME.rom ]; then
                echo Cannot find $ROM/$GAME.rom
                exit 1;
            fi
            touch rom.bin;;
        -s|-scene)
            shift
            SCENE=$1;;
        -p|-patch) shift; PATCH=$1;;
        -h|-help)
            echo "CPS simulation specific commands"
            echo "   -g|-game   selects game. Use MAME names"
            echo "   -s|-scene  selects simulation scene. Turns off MAIN/SOUND simulation"
            echo "   ---------------------- "
            $JTFRAME/bin/sim.sh -sysname cps1 -help
            exit 0;;
        *) OTHER="$OTHER $1";;
    esac
    shift
done

# Check that the scene exists
if [ -n "$SCENE" ]; then
    if [[ ! -e $GAME/vram${SCENE}.bin || ! -e $GAME/regs${SCENE}.hex ]]; then
        echo "Error: cannot find scene $SCENE files in $GAME folder"
        exit 1
    fi
    MMR_FILE="-d MMR_FILE=\"$GAME/regs${SCENE}.hex\""
    OTHER="$OTHER -d NOMAIN -d NOSOUND -video 3"
    SCENE="-game $GAME -scene $SCENE"
    rm sdram_bank?.hex
else
    MMR_FILE=
fi

ln -sf $ROM/$GAME.rom rom.bin
ln -sf $JTFRAME/hdl/sound/uprate2.hex
touch sdram_bank1.hex
make SCENE="$SCENE" || exit $?

CFG_FILE=../video/cfg/${GAME}_cfg.hex
if [[ ! -e $CFG_FILE ]]; then
    echo "ERROR: could not find the required snapshot files"
    ls $CFG_FILE
    exit 1
fi

CPSB_CONFIG=$(cat $CFG_FILE)

export MEM_CHECK_TIME=310_000_000
# 280ms to load the ROM ~17 frames
export CONVERT_OPTIONS="-resize 300%x300%"
export YM2151=1
export MSM6295=1

# Generic simulation script from JTFRAME
jtsim -mist \
    -sysname cps1  \
    -def ../../hdl/jtcps1.def \
    -d SCAN2X_TYPE=5 -d SKIP_RAMCLR\
    -videow 384 -videoh 224 $MMR_FILE -d JTFRAME_SIM_ROMRQ_NOCHECK \
    -d VIDEO_START=2 $OTHER
    #-d JTCPS_TURBO \
    #-d CPSB_CONFIG="$CPSB_CONFIG" \
