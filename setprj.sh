#!/bin/bash

source modules/jtframe/bin/setprj.sh --quiet
alias jtcore="$JTFRAME/bin/jtcore cps1 -ftp-folder CPS"
# derived variables
VER=$JTROOT/ver
GAME=$VER/game
VIDEO=$VER/video
HDL=$JTROOT/hdl
OKI=$MODULES/jt6295
