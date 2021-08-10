#!/bin/bash

cd $JTUTIL/src
make || exit $?
cd -
echo "------------"

OUTDIR=mra

mkdir -p "$OUTDIR"
mkdir -p "${OUTDIR}/$ALTD"

AUXTMP=/tmp/$RANDOM$RANDOM
jtcfgstr -target=mist -output=bash -def $DEF|grep _START > $AUXTMP
source $AUXTMP

if [ ! -d xml ]; then
  mkdir xml
fi

function maincpu {
case $1 in
  01) echo maincpu 16;;
  02) echo maincpu 16 reverse;;
esac
}

function cps_header_a {
case $1 in
  01) echo ;;
  02) echo ;;
esac
}

function cps_header_b {
case $1 in
  01)  echo 32 ff 00 02 04 06 26 28 2a 2c 2e 36 30 30 02 04 08 30;; #B_21_DEF
  02)  echo ff ff ff ff ff ff 22 24 26 28 2a 00 00 2c 10 08 04 00;; #B_21_QS1
  03)  echo ff ff ff ff ff ff 0a 0c 0e 00 02 00 00 04 16 16 16 00;; #B_21_QS2
  04)  echo 0e c0 ff ff ff ff 12 14 16 08 0a 00 00 0c 04 02 20 00;; #B_21_QS3
  05)  echo 2e c1 ff ff ff ff 16 00 02 28 2a 00 00 2c 04 08 10 00;; #B_21_QS4
  06)  echo 1e c2 ff ff ff ff 2a 2c 2e 30 32 00 00 1c 04 08 10 00;; #B_21_QS5
esac
}

function cps_header_c {
case $1 in
  90) echo 25 $(mapper_offset.py 8000 8000 0 0) 20;; #wof
  91) echo 05 $(mapper_offset.py 8000 8000 0 0) 20;; #dino
  92) echo 17 $(mapper_offset.py 8000 8000 0 0) 20;; #punisher
  93) echo 10 $(mapper_offset.py 8000 8000 8000 0) 20;; #slammast
  94) echo 10 $(mapper_offset.py 8000 8000 8000 0) 20;; #mbombrd
esac
}

function cps_header_d {
case $1 in
  01) echo 01 23 45 67 54 16 30 72 51 51 51;; #wof
  02) echo 76 54 32 10 24 60 13 57 43 43 43;; #dino
  03) echo 67 45 21 03 75 31 60 24 22 22 22;; #punisher
  04) echo 54 32 10 76 65 43 21 07 31 31 19;; #slammast
  05) echo 54 32 10 76 65 43 21 07 31 31 19;; #mbombrd
esac
}

function cps15_mra {
    local GAME=$1
    local ALT=${2//[:]/}
    local BUTSTR="$3"
    local CPU="$4"
    local CFG_A="$5"
    local CFG_B="$6"
    local CFG_C="$7"
    local CFG_D="$8"
    local CATEGORY="$9"
    local CATVER="${SUBCATEGORY}"

    CATVER=`egrep "^${GAME}=" catver.ini | head -1 | cut -d '=' -f 2- | tr -d '\r' | tr -d '\n'`
    if [ -z "${CATVER}" ]; then
        CATVER="${SUBCATEGORY}"
    fi

    if [ ! -e xml/$GAME.xml ]; then
        if [ ! -f $GAME.xml ]; then
            mamefilter $GAME
        fi
        mv $GAME.xml xml/
    fi

    ALTD=_alt/_"$ALT"
    mkdir -p $OUTDIR/"$ALTD"

    AUTHOR="jotego,atrac17"

    echo -----------------------------------------------
    echo "Dumping $GAME"
    mame2dip xml/$GAME.xml -rbf jtcps15 -outdir $OUTDIR -altfolder "$ALTD" \
        -skip_desc hack \
        -skip_desc bootleg \
        -nobootlegs \
        -order maincpu audiocpu qsound gfx \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -setword $CPU \
        -setword gfx 64 \
        -qsound \
        -header 64 0xff \
        -header-offset 0 audiocpu qsound gfx \
        -header-offset-bits 10 -header-offset-reverse \
        -header-data $CFG_A \
        -header-pointer 15 \
        -header-data ff \
        -header-data $CFG_B \
        -header-data $CFG_C \
        -header-pointer 48 \
        -header-data $CFG_D \
        -info platform CPS-1.5 \
        -info category "$CATEGORY" \
        -info catver "$CATVER" \
        -info mraauthor $AUTHOR \
        -rmdipsw 'Unused' 'Unknown' 'Service Mode' 'Freeze' \
        -nvram 128 \
        -corebuttons 6 -buttons $BUTSTR
}

#Title
cps15_mra  wof         "Warriors of Fate"                           "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 90)" "$(cps_header_d 01)" "Beat 'em Up"
cps15_mra  wofr1       "Warriors of Fate"                           "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 90)" "$(cps_header_d 01)" "Beat 'em Up"
cps15_mra  wofa        "Warriors of Fate"                           "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 90)" "$(cps_header_d 01)" "Beat 'em Up"
cps15_mra  wofu        "Warriors of Fate"                           "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 90)" "$(cps_header_d 01)" "Beat 'em Up"
cps15_mra  wofj        "Warriors of Fate"                           "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 90)" "$(cps_header_d 01)" "Beat 'em Up"
cps15_mra  dino        "Cadillacs and Dinosaurs"                    "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 03)" "$(cps_header_c 91)" "$(cps_header_d 02)" "Beat 'em Up"
cps15_mra  punisher    "The Punisher"                               "Attack,Jump"      "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 92)" "$(cps_header_d 03)" "Beat 'em Up"
cps15_mra  punisherj   "The Punisher"                               "Attack,Jump"      "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 92)" "$(cps_header_d 03)" "Beat 'em Up"
cps15_mra  slammast    "Saturday Night Slam Masters"                "Attack,Jump,Pin"  "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 93)" "$(cps_header_d 04)" "Sports"
cps15_mra  mbomberj    "Saturday Night Slam Masters"                "Attack,Jump,Pin"  "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 93)" "$(cps_header_d 04)" "Sports"
cps15_mra  mbombrd     "Muscle Bomber Duo Ultimate Team Battle"     "Grab,Attack,Jump" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 06)" "$(cps_header_c 94)" "$(cps_header_d 05)" "Sports"

# echo "Enter MiSTer's root password"
# scp -r "mra/* root@MiSTer.home:/media/fat/_CPS 1.5"

exit 0
