#!/bin/bash
if (echo $PATH | grep modules/jtframe/bin -q); then
    echo ERROR: path variable already points to a modules/jtframe/bin folder
    echo source setprj.sh with a clean PATH
else
    export JTROOT=$(pwd)
    export JTFRAME=$JTROOT/modules/jtframe

    PATH=$PATH:$JTFRAME/bin
    #unalias jtcore
    alias jtcore="$JTFRAME/bin/jtcore cps1 -ftp-folder CPS"

    # derived variables
    VER=$JTROOT/ver
    GAME=$VER/game
    VIDEO=$VER/video
    HDL=$JTROOT/hdl
    CC=$JTROOT/cc
    ROM=$JTROOT/rom
    MRA=$ROM/mra
    MODULES=$JTROOT/modules
    JT51=$MODULES/jt51
    OKI=$MODULES/jt6295
fi
