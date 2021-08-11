#!/bin/bash

cd $JTUTIL/src
make || exit $?
cd -
echo "------------"

OUTDIR=mra

mkdir -p "$OUTDIR"
mkdir -p "${OUTDIR}/$ALTD"

AUXTMP=/tmp/$RANDOM
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
  01)  echo ff 00 ff ff ff ff 26 28 2a 2c 2e 00 30 30 02 04 08 30;; #B_01
  02)  echo 20 02 ff ff ff ff 2c 2a 28 26 24 00 00 22 02 04 08 00;; #B_02
  03)  echo 24 03 ff ff ff ff 30 2e 2c 2a 28 00 00 26 20 10 08 00;; #B_03
  04)  echo 20 04 ff ff ff ff 2e 26 30 28 32 00 00 2a 02 04 08 00;; #B_04
  05)  echo 20 05 ff ff ff ff 28 2a 2c 2e 30 00 14 32 02 08 20 14;; #B_05
  11)  echo 32 41 ff ff ff ff 26 28 2a 2c 2e 36 00 30 08 10 20 00;; #B_11
  12)  echo 20 42 ff ff ff ff 2c 2a 28 26 24 36 00 22 02 04 08 00;; #B_12
  13)  echo 2e 43 ff ff ff ff 22 24 26 28 2a 36 00 2c 20 02 04 00;; #B_13
  14)  echo 1e 44 ff ff ff ff 12 14 16 18 1a 36 00 1c 08 20 10 00;; #B_14
  15)  echo 0e 45 ff ff ff ff 02 04 06 80 0a 36 00 0c 04 02 20 00;; #B_15
  16)  echo 00 46 ff ff ff ff 0c 0a 08 06 04 36 00 02 10 0a 0a 00;; #B_16
  17)  echo 08 47 ff ff ff ff 14 12 10 0e 0c 36 00 0a 08 14 02 00;; #B_17
  18)  echo 10 48 ff ff ff ff 1c 1a 18 16 14 3c 00 12 10 08 02 00;; #B_18
  21)  echo 32 ff 00 02 04 06 26 28 2a 2c 2e 36 30 30 02 04 08 30;; #B_21_DEF
  22)  echo 32 80 0e 0c 0a 08 28 26 24 22 20 00 12 30 20 04 08 12;; #B_21_BT1
  23)  echo ff ff 1e 1c 1a 18 20 2e 2c 2a 28 36 00 30 30 08 30 00;; #B_21_BT2
  24)  echo ff ff 06 04 02 00 20 2e 2c 2a 28 36 00 30 20 12 12 00;; #B_21_BT3
  25)  echo ff ff 06 04 02 00 28 26 24 22 20 36 00 30 20 10 02 00;; #B_21_BT4
  26)  echo 32 ff 0e 0c 0a 08 20 2e 2c 2a 28 00 00 30 20 04 02 00;; #B_21_BT5
  27)  echo ff ff ff ff ff ff 20 2e 2c 2a 28 36 00 30 20 14 14 00;; #B_21_BT6
  28)  echo ff ff ff ff ff ff 2c ff ff ff ff 36 00 12 14 02 14 00;; #B_21_BT7
  29)  echo ff ff ff ff ff ff 22 24 26 28 2a 00 00 2c 10 08 04 00;; #B_21_QS1
  30)  echo ff ff ff ff ff ff 0a 0c 0e 00 02 00 00 04 16 16 16 00;; #B_21_QS2
  31)  echo 0e c0 ff ff ff ff 12 14 16 08 0a 00 00 0c 04 02 20 00;; #B_21_QS3
  32)  echo 2e c1 ff ff ff ff 16 00 02 28 2a 00 00 2c 04 08 10 00;; #B_21_QS4
  33)  echo 1e c2 ff ff ff ff 2a 2c 2e 30 32 00 00 1c 04 08 10 00;; #B_21_QS5
  35)  echo ff ff ff ff ff ff 14 12 10 0e 0c    30 0a 0e 0e 0e 30;; #B_HACK_B_1
  36)  echo ff ff 0e 0c 0a 08 28 26 24 22 20    12 22 20 04 08 12;; #B_HACK_B_2
  37)  echo 20 04 ff ff ff ff 30 26 ff 28 32    00 2a 02 04 08 00;; #B_HACK_B_3
esac
}

function cps_header_c {
case $1 in
  01) echo 0e $(mapper_offset.py 8000 8000 0 0) 00;;       #Mapper_LW621 Mapper_LWCHR                    forgottn.xml
  02) echo 0a $(mapper_offset.py 8000 2000 2000 0) 00;;    #Mapper_DM620 Mapper_DM22A Mapper_DAM63B      ghouls.xml
  03) echo 22 $(mapper_offset.py 8000 8000 0 0) 00;;       #Mapper_ST24M1 Mapper_ST22B                   strider.xml
  04) echo 24 $(mapper_offset.py 8000 8000 0 0) 01;;       #Mapper_TK24B1                                dynwar.xml
  05) echo 24 $(mapper_offset.py 4000 4000 4000 4000) 01;; #Mapper_TK22B                                 dynwara.xml / dynwarj.xml / dynwarjr.xml
  06) echo 29 $(mapper_offset.py 8000 4000 0 0) 00;;       #Mapper_WL24B Mapper_WL22B                    willow.xml
  07) echo 1e $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_S224B Mapper_S222B                    ffight.xml
  08) echo 2a $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_YI24B Mapper_YI22B                    1941.xml
  09) echo 01 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_AR24B                                 unsquad.xml
  10) echo 00 $(mapper_offset.py 4000 4000 0 0) 00;;       #Mapper_AR22B                                 area88.xml / area88.xml
  11) echo 13 $(mapper_offset.py 8000 4000 0 0) 02;;       #Mapper_O224B                                 mercs.xml
  12) echo 11 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_MS24B Mapper_MS22B                    msword.xml
  13) echo 06 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_CK24B Mapper_CK22B                    mtwins.xml
  14) echo 12 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_NM24B                                 nemo.xml
  15) echo 03 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_CA24B                                 cawing.xml
  16) echo 02 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_CA22B                                 cawingu.xml
  17) echo 23 $(mapper_offset.py 8000 8000 8000 0) 08;;    #Mapper_STF29                                 sf2.xml
  18) echo 1d $(mapper_offset.py 8000 8000 0 0) 00;;       #Mapper_RT24B Mapper_RT22B                    3wonders.xml
  19) echo 0b $(mapper_offset.py 8000 8000 0 0) 02;;       #Mapper_KD29B Mapper_KD22B                    kod.xml
  20) echo 04 $(mapper_offset.py 8000 8000 0 0) 04;;       #Mapper_CC63B                                 captcomm.xml
  21) echo 0d $(mapper_offset.py 8000 8000 0 0) 02;;       #Mapper_KR63B                                 knights.xml
  22) echo 0d $(mapper_offset.py 4000 4000 4000 4000) 02;; #Mapper_KR22B                                 knightsja.xml
  23) echo 16 $(mapper_offset.py 8000 8000 8000 0) 00;;    #Mapper_pokonyan                              pokonyan.xml
  24) echo 1f $(mapper_offset.py 8000 8000 8000 0) 09;;    #Mapper_S9263B                                sf2ce.xml /sf2hf.xml
  25) echo 28 $(mapper_offset.py 4000 4000 0 0) 01;;       #Mapper_VA24B Mapper_VA24B                    varth.xml
  26) echo 27 $(mapper_offset.py 4000 4000 0 0) 01;;       #Mapper_VA22B                                 varthj.xml
  27) echo 28 $(mapper_offset.py 8000 0 0 0) 01;;          #Mapper_VA63B                                 varthu.xml / varthjr.xml
  28) echo 18 $(mapper_offset.py 8000 0 0 0) 01;;          #Mapper_Q522B                                 cworld2j.xml
  29) echo 1a $(mapper_offset.py 4000 0 0 0) 01;;          #Mapper_QD22B                                 qad.xml
  30) echo 19 $(mapper_offset.py 8000 0 0 0) 01;;          #Mapper_QD22B                                 qadjr.xml
  31) echo 26 $(mapper_offset.py 8000 8000 8000 0) 01;;    #Mapper_TN2292                                qtono2j.xml
  32) echo 1b $(mapper_offset.py 8000 8000 8000 8000) 01;; #Mapper_RCM63B                                megaman.xml
  33) echo 15 $(mapper_offset.py 8000 0 0 0) 01;;          #Mapper_PKB10B                                pnickj.xml
  34) echo 14 40 88 f7 ff c1;;                             #Mapper_CP1B1F                                pang3.xml
  35) echo 20 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_GBPR2                                 ganbare.xml
  36) echo 28 $(mapper_offset.py 8000 0 0 0) 00;;          #Mapper_gulunpa                               gulunpa.xml
  37) echo 20 $(mapper_offset.py 20000 0 0 0) 11;;         #Mapper_sfzch                                 sfzch.xml
esac
}

function cps1_mra {
    local GAME=$1
    local ALT=${2//[:]/}
    local BUTSTR="$3"
    local DIP="$4"
    local CPU="$5"
    local CFG_A="$6"
    local CFG_B="$7"
    local CFG_C="$8"
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
    mame2dip xml/$GAME.xml -rbf jtcps1 -outdir $OUTDIR -altfolder "$ALTD" \
        -skip_desc hack \
        -skip_desc bootleg \
        -skip_desc CPS2 \
        -nobootlegs \
        -order maincpu audiocpu oki gfx \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -setword $CPU \
        -setword gfx 64 \
        -header 64 0xff \
        -header-offset 0 audiocpu oki gfx \
        -header-offset-bits 10 \
        -header-offset-reverse \
        -header-data $CFG_A \
        -header-pointer 15 \
        -header-data ff \
        -header-data $CFG_B \
        -header-data $CFG_C \
        -header-pointer 50 -header-data ff \
        -ghost oki 0x40000 \
        -info platform CPS-1 \
        -info category "$CATEGORY" \
        -info catver "$CATVER" \
        -info mraauthor $AUTHOR \
        -dipbase 8 \
        -dipdef $DIP \
        -rmdipsw 'Unused' 'Unknown' \
        -nvram 128 \
        -corebuttons 6 \
        -buttons $BUTSTR
}

FIGHTBTN="Light Punch,Middle Punch,Heavy Punch,Light Kick,Middle Kick,Heavy Kick"
FIGHTBTN1="Jab,Strong,Fierce,Short,Forward,Roundhouse"

###CP System Titles (Chronological Order)

#Forgotten Worlds
cps1_mra  forgottn         "Forgotten Worlds"                           "Fire,Turn CCW,Turn CW"                      "ff,fc,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 01)" "Run & Gun"
cps1_mra  forgottnu        "Forgotten Worlds"                           "Fire,Turn CCW,Turn CW"                      "ff,fc,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 01)" "Run & Gun"
cps1_mra  forgottnue       "Forgotten Worlds"                           "Fire,Turn CCW,Turn CW"                      "ff,fc,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 01)" "Run & Gun"
cps1_mra  forgottnuc       "Forgotten Worlds"                           "Fire,Turn CCW,Turn CW"                      "ff,fc,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 01)" "Run & Gun"
cps1_mra  forgottnua       "Forgotten Worlds"                           "Fire,Turn CCW,Turn CW"                      "ff,fc,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 01)" "Run & Gun"
cps1_mra  forgottnuaa      "Forgotten Worlds"                           "Fire,Turn CCW,Turn CW"                      "ff,fc,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 01)" "Run & Gun"

#Ghouls'n Ghosts
cps1_mra  ghouls           "Ghouls'n Ghosts"                            "Fire,Jump"                                  "7f,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 02)" "Platformer"
cps1_mra  daimakair        "Ghouls'n Ghosts"                            "Fire,Jump"                                  "7f,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 02)" "Platformer"

#Strider
cps1_mra  strider          "Strider"                                    "Attack,Jump"                                "7f,7f,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 03)" "Hack & Slash"
cps1_mra  striderj         "Strider"                                    "Attack,Jump"                                "7f,7f,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 03)" "Hack & Slash"
cps1_mra  striderjr        "Strider"                                    "Attack,Jump"                                "7f,7f,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 03)" "Hack & Slash"

#Dynasty Wars
cps1_mra  dynwar           "Dynasty Wars"                               "Attack (Left),Attack (Right),Tactics"       "ff,ff,ff" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 05)" "Beat 'em Up"
cps1_mra  dynwara          "Dynasty Wars"                               "Attack (Left),Attack (Right),Tactics"       "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 05)" "Beat 'em Up"
cps1_mra  dynwarj          "Dynasty Wars"                               "Attack (Left),Attack (Right),Tactics"       "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 05)" "Beat 'em Up"
cps1_mra  dynwarjr         "Dynasty Wars"                               "Attack (Left),Attack (Right),Tactics"       "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 05)" "Beat 'em Up"

#Willow
cps1_mra  willow           "Willow"                                     "Magic/Sword,Jump"                           "3f,1f,de" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 03)" "$(cps_header_c 06)" "Platformer"
cps1_mra  willowj          "Willow"                                     "Magic/Sword,Jump"                           "3f,1f,de" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 03)" "$(cps_header_c 06)" "Platformer"

#Final Fight
cps1_mra  ffight           "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffighta          "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightj          "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightj1         "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightj2         "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 02)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightj3         "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 03)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightj4         "Final Fight"                                "Attack,Jump"                                "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightu          "Final Fight"                                "Attack,Jump"                                "bf,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightu1         "Final Fight"                                "Attack,Jump"                                "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightua         "Final Fight"                                "Attack,Jump"                                "bf,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 01)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightub         "Final Fight"                                "Attack,Jump"                                "bf,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 03)" "$(cps_header_c 07)" "Beat 'em Up"
cps1_mra  ffightuc         "Final Fight"                                "Attack,Jump"                                "bf,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 07)" "Beat 'em Up"

#1941 Counter Attack
cps1_mra  1941             "1941 Counter Attack"                        "Attack,Somersault/Mega Crash"               "ff,74,8f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 08)" "Shoot 'em Up"
cps1_mra  1941j            "1941 Counter Attack"                        "Attack,Somersault/Mega Crash"               "ff,74,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 08)" "Shoot 'em Up"
cps1_mra  1941u            "1941 Counter Attack"                        "Attack,Somersault/Mega Crash"               "bf,74,8f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 08)" "Shoot 'em Up"

#U.N. Squadron
cps1_mra  unsquad          "U.N. Squadron"                              "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 11)" "$(cps_header_c 09)" "Shoot 'em Up"
cps1_mra  area88           "U.N. Squadron"                              "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 11)" "$(cps_header_c 10)" "Shoot 'em Up"
cps1_mra  area88r          "U.N. Squadron"                              "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 10)" "Shoot 'em Up"

#Mercs
cps1_mra  mercs            "Mercs"                                      "Attack,Mega Crash"                          "ff,e4,8f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 12)" "$(cps_header_c 11)" "Run & Gun"
cps1_mra  mercsu           "Mercs"                                      "Attack,Mega Crash"                          "bf,e4,8f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 12)" "$(cps_header_c 11)" "Run & Gun"
cps1_mra  mercsur1         "Mercs"                                      "Attack,Mega Crash"                          "bf,e4,8f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 12)" "$(cps_header_c 11)" "Run & Gun"
cps1_mra  mercsj           "Mercs"                                      "Attack,Mega Crash"                          "ff,e4,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 12)" "$(cps_header_c 11)" "Run & Gun"

#Magical Sword Heroic Fantasy
cps1_mra  msword           "Magical Sword Heroic Fantasy"               "Attack,Jump"                                "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 12)" "Hack & Slash"
cps1_mra  mswordr1         "Magical Sword Heroic Fantasy"               "Attack,Jump"                                "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 12)" "Hack & Slash"
cps1_mra  mswordu          "Magical Sword Heroic Fantasy"               "Attack,Jump"                                "bf,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 12)" "Hack & Slash"
cps1_mra  mswordj          "Magical Sword Heroic Fantasy"               "Attack,Jump"                                "ff,fc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 12)" "Hack & Slash"

#Mega Twins
cps1_mra  mtwins           "Mega Twins"                                 "Attack,Jump,Magic Bomb"                     "ff,dc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 14)" "$(cps_header_c 13)" "Platformer"
cps1_mra  chikij           "Mega Twins"                                 "Attack,Jump,Magic Bomb"                     "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 14)" "$(cps_header_c 13)" "Platformer"

#Nemo
cps1_mra  nemo             "Nemo"                                       "Attack,Jump"                                "ff,e4,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 15)" "$(cps_header_c 14)" "Platformer"
cps1_mra  nemor1           "Nemo"                                       "Attack,Jump"                                "ff,e4,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 15)" "$(cps_header_c 14)" "Platformer"
cps1_mra  nemoj            "Nemo"                                       "Attack,Jump"                                "ff,e4,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 15)" "$(cps_header_c 14)" "Platformer"

#Carrier Air Wing
cps1_mra  cawing           "Carrier Air Wing"                           "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 16)" "$(cps_header_c 15)" "Shoot 'em Up"
cps1_mra  cawingr1         "Carrier Air Wing"                           "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 16)" "$(cps_header_c 15)" "Shoot 'em Up"
cps1_mra  cawingu          "Carrier Air Wing"                           "Fire,Special Weapon"                        "bf,fc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 15)" "Shoot 'em Up"
cps1_mra  cawingur1        "Carrier Air Wing"                           "Fire,Special Weapon"                        "bf,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 16)" "$(cps_header_c 15)" "Shoot 'em Up"
cps1_mra  cawingj          "Carrier Air Wing"                           "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 16)" "$(cps_header_c 15)" "Shoot 'em Up"
cps1_mra  cawingbl         "Carrier Air Wing"                           "Fire,Special Weapon"                        "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 16)" "$(cps_header_c 15)" "Shoot 'em Up"

#Street Fighter II The World Warrior
cps1_mra  sf2             "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 11)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ea           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2eb           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ed           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ee           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 18)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ef           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 15)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2em           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2en           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2j            "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2j17          "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ja           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2jc           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 12)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2jf           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 15)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2jh           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2jl           "Street Fighter II The World Warrior"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ua           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ub           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2uc           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 12)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ud           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 05)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ue           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 18)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2uf           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 15)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ug           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 11)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2uh           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 13)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2ui           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 14)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2uk           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"
cps1_mra  sf2um           "Street Fighter II The World Warrior"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 17)" "$(cps_header_c 17)" "Fighting"

#Three Wonders
cps1_mra  3wonders        "Three Wonders"                               "Attack/Shot/P. Block,Jump/T. Shot/P. Block" "ff,9a,99" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 22)" "$(cps_header_c 18)" "MultiGame"
cps1_mra  3wondersr1      "Three Wonders"                               "Attack/Shot/P. Block,Jump/T. Shot/P. Block" "ff,9a,99" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 22)" "$(cps_header_c 18)" "MultiGame"
cps1_mra  3wondersu       "Three Wonders"                               "Attack/Shot/P. Block,Jump/T. Shot/P. Block" "bf,9a,99" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 22)" "$(cps_header_c 18)" "MultiGame"
cps1_mra  wonder3         "Three Wonders"                               "Attack/Shot/P. Block,Jump/T. Shot/P. Block" "ff,9a,99" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 22)" "$(cps_header_c 18)" "MultiGame"

#The King of Dragons
cps1_mra  kod             "The King of Dragons"                         "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 23)" "$(cps_header_c 19)" "Beat 'em Up"
cps1_mra  kodr1           "The King of Dragons"                         "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 23)" "$(cps_header_c 19)" "Beat 'em Up"
cps1_mra  kodr2           "The King of Dragons"                         "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 23)" "$(cps_header_c 19)" "Beat 'em Up"
cps1_mra  kodu            "The King of Dragons"                         "Attack,Jump"                                "bf,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 23)" "$(cps_header_c 19)" "Beat 'em Up"
cps1_mra  kodj            "The King of Dragons"                         "Attack,Jump"                                "ff,3c,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 23)" "$(cps_header_c 19)" "Beat 'em Up"
cps1_mra  kodja           "The King of Dragons"                         "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 23)" "$(cps_header_c 19)" "Beat 'em Up"

#Captain Commando
cps1_mra  captcomm        "Captain Commando"                            "Attack,Jump"                                "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 24)" "$(cps_header_c 20)" "Beat 'em Up"
cps1_mra  captcommr1      "Captain Commando"                            "Attack,Jump"                                "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 24)" "$(cps_header_c 20)" "Beat 'em Up"
cps1_mra  captcommu       "Captain Commando"                            "Attack,Jump"                                "bf,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 24)" "$(cps_header_c 20)" "Beat 'em Up"
cps1_mra  captcommj       "Captain Commando"                            "Attack,Jump"                                "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 24)" "$(cps_header_c 20)" "Beat 'em Up"
cps1_mra  captcommjr1     "Captain Commando"                            "Attack,Jump"                                "ff,fc,9f" "$(maincpu 01)" "$(cps_header_a 01)" "$(cps_header_b 24)" "$(cps_header_c 20)" "Beat 'em Up"

#Knights of the Round
cps1_mra  knights         "Knights of the Round"                        "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 25)" "$(cps_header_c 21)" "Beat 'em Up"
cps1_mra  knightsu        "Knights of the Round"                        "Attack,Jump"                                "bf,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 25)" "$(cps_header_c 21)" "Beat 'em Up"
cps1_mra  knightsj        "Knights of the Round"                        "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 25)" "$(cps_header_c 21)" "Beat 'em Up"
cps1_mra  knightsja       "Knights of the Round"                        "Attack,Jump"                                "ff,3c,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 25)" "$(cps_header_c 21)" "Beat 'em Up"

#Pokonyan! Balloon
cps1_mra  pokonyan        "Pokonyan! Balloon"                           "Rolling,Flower"                             "fe,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 23)" "Redemption"

#Street Fighter II' Champion Edition
cps1_mra  sf2ce           "Street Fighter II' Champion Edition"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2ceea         "Street Fighter II' Champion Edition"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2ceja         "Street Fighter II' Champion Edition"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2cejb         "Street Fighter II' Champion Edition"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2cejc         "Street Fighter II' Champion Edition"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2cet          "Street Fighter II' Champion Edition"         "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2ceua         "Street Fighter II' Champion Edition"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2ceub         "Street Fighter II' Champion Edition"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2ceuc         "Street Fighter II' Champion Edition"         "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"

#Varth: Operation Thunderstorm
cps1_mra  varth           "Varth Operation Thunderstorm"                "Shot,Bomb"                                  "ff,f4,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 27)" "Shoot 'em Up"
cps1_mra  varthr1         "Varth Operation Thunderstorm"                "Shot,Bomb"                                  "ff,f4,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 27)" "Shoot 'em Up"
cps1_mra  varthu          "Varth Operation Thunderstorm"                "Shot,Bomb"                                  "bf,f4,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 04)" "$(cps_header_c 27)" "Shoot 'em Up"
cps1_mra  varthj          "Varth Operation Thunderstorm"                "Shot,Bomb"                                  "ff,f4,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 26)" "$(cps_header_c 26)" "Shoot 'em Up"
cps1_mra  varthjr         "Varth Operation Thunderstorm"                "Shot,Bomb"                                  "ff,f4,8f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 26)" "$(cps_header_c 27)" "Shoot 'em Up"

#Adventure Quiz Capcom World 2
cps1_mra  cworld2j        "Adventure Quiz Capcom World 2"               "Button 1,Button 2,Button 3,Button 4"        "ff,32,df" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 27)" "$(cps_header_c 28)" "Quiz"
cps1_mra  cworld2ja       "Adventure Quiz Capcom World 2"               "Button 1,Button 2,Button 3,Button 4"        "ff,32,df" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 28)" "Quiz"
cps1_mra  cworld2jb       "Adventure Quiz Capcom World 2"               "Button 1,Button 2,Button 3,Button 4"        "ff,32,df" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 27)" "$(cps_header_c 28)" "Quiz"

#Street Fighter II' Hyper Fighting
cps1_mra  sf2hf           "Street Fighter II' Hyper Fighting"           "$FIGHTBTN"                                  "ff,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"
cps1_mra  sf2hfu          "Street Fighter II' Hyper Fighting"           "$FIGHTBTN1"                                 "bf,dc,9f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 24)" "Fighting"

#Quiz & Dragons
cps1_mra  qad             "Quiz & Dragons"                              "Button 1,Button 2,Button 3,Button 4"        "ff,1a,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 28)" "$(cps_header_c 29)" "Quiz"
cps1_mra  qadjr           "Quiz & Dragons"                              "Button 1,Button 2,Button 3,Button 4"        "ff,1a,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 30)" "Quiz"

#Quiz Tonosama no Yabou 2
cps1_mra  qtono2j         "Quiz Tonosama no Yabou 2"                    "Button 1,Button 2,Button 3,Button 4"        "ff,9c,df" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 31)" "Quiz"

#Mega Man The Power Battle
cps1_mra  megaman         "Mega Man The Power Battle"                   "Attack,Jump,Weapon Change"                  "80,b6,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 32)" "Platformer"
cps1_mra  megaman         "Mega Man The Power Battle"                   "Attack,Jump,Weapon Change"                  "80,f6,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 32)" "Platformer"
cps1_mra  megaman         "Mega Man The Power Battle"                   "Attack,Jump,Weapon Change"                  "80,f6,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 32)" "Platformer"

#Pnickies
cps1_mra  pnickj          "Pnickies"                                    "Rotate CCW,Rotate CW"                       "ff,3c,df" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 33)" "Puzzle"

#Pang! 3
cps1_mra  pang3           "Pang! 3"                                     "Wire Shot"                                  "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 34)" "Platformer"
cps1_mra  pang3r1         "Pang! 3"                                     "Wire Shot"                                  "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 34)" "Platformer"
cps1_mra  pang3j          "Pang! 3"                                     "Wire Shot"                                  "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 34)" "Platformer"

#Ganbare! Marine Kun
cps1_mra  ganbare         "Ganbare! Marine Kun"                         "Insert Medal"                               "8b,4c,7f" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 35)" "Redemption"

#Gulun.Pa!
cps1_mra  gulunpa         "Gulun.Pa!"                                   "Rotate CCW,Rotate CW"                       "ff,fc,df" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 36)" "Puzzle"

###CP System Changer Titles

#Street Fighter Alpha Warriors' Dreams
cps1_mra  sfzch           "Street Fighter Alpha Warriors' Dreams"      "$FIGHTBTN"                                   "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 37)" "Fighting"
cps1_mra  sfach           "Street Fighter Alpha Warriors' Dreams"      "$FIGHTBTN1"                                  "ff,ff,ff" "$(maincpu 02)" "$(cps_header_a 01)" "$(cps_header_b 21)" "$(cps_header_c 37)" "Fighting"

###CP System w/ support boards
#cps1_mra  kenseim         ""                                           ""                                            "" "$(maincpu )" "$(cps_header_a )" "$(cps_header_b )" "$(cps_header_c )" ""


# echo "Enter MiSTer's root password"
# scp -r "mra/* root@MiSTer.home:/media/fat/_CPS 1"

exit 0
