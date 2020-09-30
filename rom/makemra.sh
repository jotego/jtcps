#!/bin/bash
pushd .
cd $JTFRAME/cc
make || exit $?
popd

mkdir -p mra/_alt/"Warriors of Fate"
mame2dip wof.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Warriors of Fate" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data FF FF \
    -header-data FF FF FF FF \
    -header-data 22 24 26 28 2a 2c 10 08 04 00 \
    -header-data 25 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 01 23 45 67 54 16 30 72 51 51 51 \
    -buttons Attack Jump None None None None

# CPSB data is a place holder
mkdir -p mra/_alt/"Cadillacs and Dinosaurs"
mame2dip dino.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Cadillacs and Dinosaurs" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data FF FF \
    -header-data FF FF FF FF \
    -header-data 22 24 26 28 2a 2c 10 08 04 00 \
    -header-data 25 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 01 23 45 67 54 16 30 72 51 51 51 \
    -buttons Attack Jump None None None None

# CPSB data is a place holder
mkdir -p mra/_alt/"The Punisher"
mame2dip punisher.xml -rbf jtcps15 -outdir mra -altfolder _alt/"The Punisher" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data FF FF \
    -header-data FF FF FF FF \
    -header-data 22 24 26 28 2a 2c 10 08 04 00 \
    -header-data 25 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 01 23 45 67 54 16 30 72 51 51 51 \
    -buttons Attack Jump None None None None

# CPSB data is a place holder
mkdir -p mra/_alt/"Saturday Night Slam Masters"
mame2dip slammast.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Saturday Night Slam Masters" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data FF FF \
    -header-data FF FF FF FF \
    -header-data 22 24 26 28 2a 2c 10 08 04 00 \
    -header-data 25 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 01 23 45 67 54 16 30 72 51 51 51 \
    -buttons Attack Jump None None None None

# CPSB data is a place holder
mkdir -p mra/_alt/"Muscle Bomber Duo"
mame2dip mbombrd.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Muscle Bomber Duo" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data FF FF \
    -header-data FF FF FF FF \
    -header-data 22 24 26 28 2a 2c 10 08 04 00 \
    -header-data 25 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 01 23 45 67 54 16 30 72 51 51 51 \
    -buttons Attack Jump None None None None