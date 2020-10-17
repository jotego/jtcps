#!/bin/bash

source modules/jtframe/bin/setprj.sh --quiet
alias jtcore="$JTFRAME/bin/jtcore -ftp-folder CPS"
# derived variables
#VER=$JTROOT/cores/$CORE/ver
#GAME=$VER/cores/$CORE/game
#VIDEO=$VER/cores/$CORE/video
#HDL=$JTROOT/cores/$CORE/hdl
OKI=$MODULES/jt6295