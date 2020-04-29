#!/bin/bash
make || exit $?

rm -f *mra
mmr -parent
mv *.mra $JTROOT/rom/mra
mmr -alt
mv *.mra $JTROOT/rom/mra/_alt
