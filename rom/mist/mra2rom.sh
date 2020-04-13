#!/bin/bash
parallel mra {} -z ../zip -A ::: *.mra

DEST=/media/$USER/MIST

if [ -d $DEST ]; then
    cp *.CFG $DEST
    mkdir -p $DEST/JTCPS1
    cp *.arc $DEST/JTCPS1
fi
