#!/bin/bash

if [ ! -e mame.xml ]; then
    echo Creating mame.xml
    mame -listxml > mame.xml || ( echo "Error creating mame.xml"; exit 1 )
fi

pushd . > /dev/null
cd $JTFRAME/cc
make > /dev/null || ( echo "Error while compiling JTFRAME/cc files"; exit $? )
popd > /dev/null

MAKEROM=0
CPS15=0
CPS2=0
OUTDIR=mra

while [ $# -gt 0 ]; do
    case $1 in
        -rom)
            MAKEROM=1;;
        -cps15)
            CPS15=1;;
        -cps2)
            CPS2=1;;
        -outdir)
            shift
            OUTDIR=$1;;
        -h|-help)
            cat <<EOF
makemra.sh creates MRA files for some cores. Optional arguments:
    -rom        create .rom files too using the mra tool
                * not implemented yet *
    -cps1.5     enable CPS1.5 MRA creation
    -cps2       enable CPS2   MRA creation
    -outdir     output directory
    -h | -help  shows this message
EOF
            exit 1;;
        *)
            echo "ERROR: unknown argument " $1
            exit 1;;
    esac
    shift
done

if [[ $CPS15 = 0 && $CPS2 = 0 ]]; then
    echo You must specify at least -cps15 or -cps2
    exit 1
fi

if [ ! -d $OUTDIR ]; then
    echo mkdir -p $OUTDIR
fi

if [ $CPS15 = 1 ]; then

    ALTFOLDER=_alt/"_Warriors of Fate"
    mkdir -p $OUTDIR/"$ALTFOLDER"
    mame2dip wof.xml -rbf jtcps15 -outdir $OUTDIR -altfolder "$ALTFOLDER" \
        -setword gfx 64 -qsound \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order maincpu audiocpu qsound gfx \
        -header 64 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data FF FF \
        -header-data FF FF FF FF \
        -header-data 22 24 26 28 2a 00 00 2c 10 08 04 00 \
        -header-data 25 \
        -header-data $(mapper_offset.py 8000 8000 0 0) \
        -header-data 20 \
        -header-pointer 48 \
        -header-data 01 23 45 67 54 16 30 72 51 51 51 \
        -corebuttons 6 \
        -buttons Attack,Jump \
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_Cadillacs and Dinosaurs"
    mkdir -p $OUTDIR/"$ALTFOLDER"
    mame2dip dino.xml -rbf jtcps15 -outdir $OUTDIR -altfolder "$ALTFOLDER" \
        -setword gfx 64 -setword maincpu 16 -qsound \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order maincpu audiocpu qsound gfx \
        -header 64 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data FF FF \
        -header-data FF FF FF FF \
        -header-data 0a 0c 0e 00 02 00 00 04 16 16 16 00 \
        -header-data 5 \
        -header-data $(mapper_offset.py 8000 8000 0 0) \
        -header-data 20 \
        -header-pointer 48 \
        -header-data 76 54 32 10 24 60 13 57 43 43 43 \
        -corebuttons 6 \
        -buttons Attack,Jump\
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_The Punisher"
    mkdir -p $OUTDIR/"$ALTFOLDER"
    mame2dip punisher.xml -rbf jtcps15 -outdir $OUTDIR -altfolder "$ALTFOLDER" \
        -setword gfx 64 -setword maincpu 16 reverse -qsound \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order maincpu audiocpu qsound gfx \
        -header 64 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data 0e c0 \
        -header-data FF FF FF FF \
        -header-data 12 14 16 08 0a 00 00 0c 04 02 20 00 \
        -header-data 17 \
        -header-data $(mapper_offset.py 8000 8000 0 0) \
        -header-data 20 \
        -header-pointer 48 \
        -header-data 67 45 21 03 75 31 60 24 22 22 22 \
        -corebuttons 6 \
        -buttons Attack,Jump \
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_Saturday Night Slam Masters"
    mkdir -p $OUTDIR/"$ALTFOLDER"
    mame2dip slammast.xml -rbf jtcps15 -outdir $OUTDIR -altfolder "$ALTFOLDER" \
        -setword gfx 64 -setword maincpu 16 reverse -qsound \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order maincpu audiocpu qsound gfx \
        -header 64 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data 2e c1 \
        -header-data FF FF FF FF \
        -header-data 16 00 02 28 2a 00 00 2c 04 08 10 00 \
        -header-data 10 \
        -header-data $(mapper_offset.py 8000 8000 8000 0) \
        -header-data 20 \
        -header-pointer 48 \
        -header-data 54 32 10 76 65 43 21 07 31 31 19 \
        -corebuttons 6 \
        -buttons Punch,Jump,Action \
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_Muscle Bomber Duo"
    mkdir -p $OUTDIR/"$ALTFOLDER"
    mame2dip mbombrd.xml -rbf jtcps15 -outdir $OUTDIR -altfolder "$ALTFOLDER" \
        -setword gfx 64 -setword maincpu 16 reverse -qsound \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order maincpu audiocpu qsound gfx \
        -header 64 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data 1e c2 \
        -header-data FF FF FF FF \
        -header-data 2a 2c 2e 30 32 00 00 1c 04 08 10 00 \
        -header-data 10 \
        -header-data $(mapper_offset.py 8000 8000 8000 0) \
        -header-data 20 \
        -header-pointer 48 \
        -header-data 54 32 10 76 65 43 21 07 31 31 19 \
        -corebuttons 6 \
        -buttons Punch,Attack,Jump \
        -rmdipsw Freeze -nvram 128
fi

if [ $CPS2 = 0 ]; then
    exit 0
fi

# CPS2 Titles
function cps2_mra {
    local GAME=$1
    local BUT=$2
    local BUTSTR="$3"
    local ALT=${4//[:]/}
    local BUTCFG=

    if [ ! -e $GAME.xml ]; then
        mamefilter $GAME > $GAME.xml
    fi

    case $BUT in
        6) BUTCFG="-header-pointer 050 -header-data FC";;
        *) BUTCFG="";;
    esac

    ALT=_alt/_"$ALT"
    mkdir -p $OUTDIR/"$ALT"
    AUTHOR="jotego,atrac17"
    if [[ $GAME = choko || $GAME = jyangoku ]]; then
        AUTHOR="$AUTHOR,MJY71"
    fi
    echo -----------------------------------------------
    echo Dumping $GAME
    mame2dip $GAME.xml -rbf jtcps2 -outdir $OUTDIR -altfolder "$ALT" \
        -setword gfx 64 -qsound \
        -setword qsound 16 \
        -swapbytes maincpu \
        -corebuttons 6 \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order key maincpu audiocpu qsound gfx \
        -header 44 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data 32 FF 00 \
        -header-data 02 04 06 \
        -header-data 26 28 2A 2C 2E 00 00 30 02 04 08 30 \
        -info mraauthor $AUTHOR \
        -info mameversion 0229 \
        -info mratimestamp $(date +"%Y%m%d") \
        -info platform CPS-2 \
        $BUTCFG \
        -buttons $BUTSTR \
        -nvram 128 -ddr
}


#$BUTSTR W/ Kick Harness except ringdest
FIGHTBTN="Light Punch,Middle Punch,Heavy Punch,Light Kick,Middle Kick,Heavy Kick"

#Games released on CPS-2 hardware in chronological order by Capcom Co., Ltd.
cps2_mra ssf2           6 "$FIGHTBTN" "Super Street Fighter II: The New Challengers"
cps2_mra ecofghtr       3 "Rotate CCW,Shoot,Rotate CW" "Eco Fighters"
cps2_mra ddtod          4 "Attack,Jump,Item,Select" "Dungeons & Dragons: Tower of Doom"
cps2_mra ssf2t          6 "$FIGHTBTN" "Super Street Fighter II Turbo"
cps2_mra avsp           3 "Shoot,Attack,Jump/Dash" "Alien vs. Predator"
cps2_mra dstlk          6 "$FIGHTBTN" "Darkstalkers: The Night Warriors"
cps2_mra ringdest       5 "Grab,Light Punch,Heavy Punch,Light Kick,Heavy Kick,Unused" "Ring of Destruction Slammasters II"
cps2_mra armwar         3 "Attack,Jump,Sub Weapons" "Armored Warriors"
cps2_mra xmcota         6 "$FIGHTBTN" "X-Men: Children of the Atom"
cps2_mra nwarr          6 "$FIGHTBTN" "Night Warriors: Darkstalkers' Revenge"
cps2_mra cybots         4 "Attack 1,Attack 2,Boost,Weapon" "Cyberbots: Fullmetal Madness"
cps2_mra sfa            6 "$FIGHTBTN" "Street Fighter Alpha: Warriors' Dreams"
cps2_mra mmancp2u       3 "Attack,Jump,Weapon Change" "Mega Man: The Power Battle"
cps2_mra rmancp2j       3 "Attack,Jump,Weapon Change" "Rockman: The Power Battle"
cps2_mra msh            6 "$FIGHTBTN" "Marvel Super Heroes"
cps2_mra 19xx           2 "Shot,Bomb" "19XX: The War Against Destiny"
cps2_mra ddsom          4 "Attack,Jump,Select,Magic" "Dungeons & Dragons: Shadow over Mystara"
cps2_mra sfa2           6 "$FIGHTBTN" "Street Fighter Alpha 2"
cps2_mra spf2t          2 "Rotate Left,Rotate Right" "Super Puzzle Fighter II Turbo"
cps2_mra megaman2       3 "Attack,Jump,Weapon Change" "Mega Man 2: The Power Fighters"
cps2_mra sfz2al         6 "$FIGHTBTN" "Street Fighter Zero 2 Alpha"
cps2_mra qndream        4 "Button 1,Button 2,Button 3,Button 4" "Quiz Nanairo Dreams: Nijiirochou no Kiseki"
cps2_mra xmvsf          6 "$FIGHTBTN" "X-Men Vs. Street Fighter"
cps2_mra batcir         2 "Attack,Jump" "Battle Circuit"
cps2_mra vsav           6 "$FIGHTBTN" "Vampire Savior: The Lord of Vampire"
cps2_mra mshvsf         6 "$FIGHTBTN" "Marvel Super Heroes Vs. Street Fighter"
cps2_mra csclub         3 "Shoot/Weak Shot,Pass/Strong Shot,Dash/Lob/Jump" "Capcom Sports Club"
cps2_mra sgemf          3 "Punch,Kick,Special" "Super Gem Fighter Mini Mix"
cps2_mra vhunt2         6 "$FIGHTBTN" "Vampire Hunter 2 Darkstalkers Revenge"
cps2_mra vsav2          6 "$FIGHTBTN" "Vampire Savior 2: The Lord of Vampire"
cps2_mra mvsc           6 "$FIGHTBTN" "Marvel Vs. Capcom: Clash of Super Heroes"
cps2_mra sfa3           6 "$FIGHTBTN" "Street Fighter Alpha 3"
cps2_mra jyangoku       2 "Tsumo,Open Menu" "Jyangokushi: Haoh no Saihai"
cps2_mra hsf2           6 "$FIGHTBTN" "Hyper Street Fighter II: The Anniversary Edition"

#Games released on CPS-2 hardware by Cave Co., Ltd.
cps2_mra progear        3 "Shot,Bomb,Unknown" "Progear"

#Games released on CPS-2 hardware by Eighting/Raizing
cps2_mra dimahoo        3 "Main Shot,Bomb,Rapid Main Shot (OPT)" "Dimahoo"
cps2_mra 1944           2 "Shot,Bomb" "1944: The Loop Master"

#Games released on CPS-2 hardware by Mitchell Corp.
cps2_mra mpang          1 "Shot" "Mighty! Pang"
cps2_mra pzloop2        1 "Shot" "Puzz Loop 2"
cps2_mra choko          3 "Select,Cancel,Help" "Janpai Puzzle Choukou"

#Games released on CPS-2 hardware by Takumi Corporation
cps2_mra gigawing       2 "Shot,Force Bomb" "Giga Wing"
cps2_mra mmatrix        1 "Shot" "Mars Matrix: Hyper Solid Shooting"
