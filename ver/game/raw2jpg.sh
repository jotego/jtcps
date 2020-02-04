#!/bin/bash
rm -f video*.jpg
convert -size 384x240 -depth 8 RGBA:video.raw -resize 200% video.jpg
