#!/bin/bash
#dd if=video.raw of=video1.raw bs=$((384*224*4)) count=1000
rm -rf video
mkdir video
convert -size 384x224 -depth 8 RGBA:video.raw -resize 200% video/video.jpg
