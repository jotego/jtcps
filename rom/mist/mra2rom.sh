#!/bin/bash
parallel mra {} -z ../zip -A ::: *.mra

DEST=/media/$USER/MIST

if [ -d $DEST ]; then
    mkdir -p $DEST/JTCPS1
    cp *.arc $DEST/JTCPS1
fi
