#!/bin/bash

function copy {
	DEST=/media/$USER/$1

	if [ -d $DEST ]; then
	    mkdir -p $DEST/JTCPS1
	    cp *.arc $DEST/JTCPS1
	fi
}

parallel mra {} -z ../zip -A ::: *.mra

copy MIST
copy SIDI

