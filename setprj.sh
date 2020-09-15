#!/bin/bash

source modules/jtframe/bin/setprj.sh --quiet
alias jtcore="$JTFRAME/bin/jtcore cps1 -ftp-folder CPS"
# derived variables
CORE=cps1
VER=$JTROOT/cores/$CORE/ver
GAME=$VER/cores/$CORE/game
VIDEO=$VER/cores/$CORE/video
HDL=$JTROOT/cores/$CORE/hdl
OKI=$MODULES/jt6295
