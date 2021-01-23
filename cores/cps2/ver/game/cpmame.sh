#!/bin/bash
if [ $# != 2 ]; then
    echo "Usage: cpmame.sh game scene"
    exit 1
fi

cp -v vram.bin $1/vram$2.bin || exit 1
cp -v obj.bin $1/obj$2.bin   || exit 1

git add --force $1/{vram$2.bin,obj$2.bin}