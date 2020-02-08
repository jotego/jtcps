#!/bin/bash

for i in 1 2 3 4 5 6 7 8 9 a b c d e f;do
for j in 4 5 6 7 8 9 10 11 12 13 14 15 16;do
        OFFSET=${i}_${j}
        echo "$OFFSET"
        go.sh -s 2 -d NOSCROLL -d OFFSET=\(23\'h${i}\<\<${j}\)
        mv video.png offset_$OFFSET.png
    done
done