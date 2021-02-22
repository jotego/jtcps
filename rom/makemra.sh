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
    mkdir -p mra/$OUTDIR"$ALTFOLDER"
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
        -buttons Attack Jump None None None None \
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_Cadillacs and Dinosaurs"
    mkdir -p mra/$OUTDIR"$ALTFOLDER"
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
        -buttons Attack Jump None None None None\
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_The Punisher"
    mkdir -p mra/$OUTDIR"$ALTFOLDER"
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
        -buttons Attack Jump None None None None \
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_Saturday Night Slam Masters"
    mkdir -p mra/$OUTDIR"$ALTFOLDER"
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
        -buttons Punch Jump Action None None None \
        -rmdipsw Freeze -nvram 128

    ALTFOLDER=_alt/"_Muscle Bomber Duo"
    mkdir -p mra/$OUTDIR"$ALTFOLDER"
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
        -buttons Punch Attack Jump None None None \
        -rmdipsw Freeze -nvram 128
fi

if [ $CPS2 = 0 ]; then
    exit 0
fi

# CPS2 Titles
function cps2_mra {
    local GAME=$1
    local BUT=$2
    local ALT=$3
    local BUTCFG=

    if [ ! -e $GAME.xml ]; then
        mamefilter $GAME > $GAME.xml
    fi

    case $BUT in
        6) BUTCFG="-header-pointer 30 -header-data 0"
           BUTSTR="Punch0 Punch1 Punch2 Kick0 Kick1 Kick2";;
        *) BUTCFG=""
           BUTSTR="Attack Jump None None None None";;
    esac

    ALT=_alt/_"$ALT"
    mkdir -p $OUTDIR/"$ALT"
    mame2dip $GAME.xml -rbf jtcps2 -outdir $OUTDIR -altfolder "$ALT" \
        -frac 2 gfx 4 -qsound \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order key maincpu audiocpu qsound gfx \
        -header 44 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data 32 FF 00 \
        -header-data 02 04 06 \
        -header-data 26 28 2A 2C 2E 00 00 30 02 04 08 30 \
        $BUTCFG \
        -buttons $BUTSTR \
        -nvram 128
}

# cps2_mra dstlk      2 "Darkstalkers: The Night Warriors (Euro 940705)"
# exit 0

cps2_mra ddtod      2 "DnD Tower of Doom"
cps2_mra ssf2       2 "Super Street Fighter II: The New Challengers (World 931005)"
cps2_mra ssf2t      2 "Super Street Fighter II Turbo (World 940223)"
cps2_mra ecofghtr   2 "Eco Fighters (World 931203)"
cps2_mra avsp       2 "Alien vs. Predator (Euro 940520)"
cps2_mra dstlk      2 "Darkstalkers: The Night Warriors (Euro 940705)"
cps2_mra ringdest   2 "Ring of Destruction: Slammasters II (Euro 940902)"
cps2_mra armwar     2 "Armored Warriors (Euro 941024)"
cps2_mra xmcota     2 "X-Men: Children of the Atom (Euro 950331)"
cps2_mra nwarr      2 "Night Warriors: Darkstalkers' Revenge (Euro 950316)"
cps2_mra cybots     2 "Cyberbots: Fullmetal Madness (Euro 950424)"
cps2_mra sfa        2 "Street Fighter Alpha: Warriors' Dreams (Euro 950727)"
cps2_mra mmancp2u   2 "Mega Man: The Power Battle (CPS2, USA 951006, SAMPLE Version)"
cps2_mra mmancp2ur1 2 "Mega Man: The Power Battle (CPS2, USA 950926, SAMPLE Version)"
cps2_mra rmancp2j   2 "Rockman: The Power Battle (CPS2, Japan 950922)"
cps2_mra msh        2 "Marvel Super Heroes (Euro 951024)"
cps2_mra 19xx       2 "19XX: The War Against Destiny (Euro 960104)"
cps2_mra ddsom      2 "Dungeons & Dragons: Shadow over Mystara (Euro 960619)"
cps2_mra sfa2       2 "Street Fighter Alpha 2 (Euro 960229)"
cps2_mra sfz2al     2 "Street Fighter Zero 2 Alpha (Asia 960826)"
cps2_mra spf2t      2 "Super Puzzle Fighter II Turbo (Euro 960529)"
cps2_mra megaman2   2 "Mega Man 2: The Power Fighters (USA 960708)"
cps2_mra qndream    2 "Quiz Nanairo Dreams: Nijiirochou no Kiseki (Japan 960826)"
cps2_mra xmvsf      2 "X-Men Vs. Street Fighter (Euro 961004)"
cps2_mra batcir     2 "Battle Circuit (Euro 970319)"
cps2_mra vsav       2 "Vampire Savior: The Lord of Vampire (Euro 970519)"
cps2_mra mshvsf     2 "Marvel Super Heroes Vs. Street Fighter (Euro 970625)"
cps2_mra csclub     2 "Capcom Sports Club (Euro 971017)"
cps2_mra sgemf      2 "Super Gem Fighter Mini Mix (USA 970904)"
cps2_mra vhunt2     2 "Vampire Hunter 2: Darkstalkers Revenge (Japan 970929)"
cps2_mra vsav2      2 "Vampire Savior 2: The Lord of Vampire (Japan 970913)"
cps2_mra mvsc       2 "Marvel Vs. Capcom: Clash of Super Heroes (Euro 980123)"
cps2_mra sfa3       2 "Street Fighter Alpha 3 (Euro 980904)"
cps2_mra jyangoku   2 "Jyangokushi: Haoh no Saihai (Japan 990527)"
cps2_mra hsf2       2 "Hyper Street Fighter II: The Anniversary Edition (USA 040202)"

# Games released on CPS-2 hardware by Takumi
cps2_mra gigawing   "Giga Wing (USA 990222)"
cps2_mra mmatrix    "Mars Matrix: Hyper Solid Shooting (USA 000412)"

# Games released on CPS-2 hardware by Mitchell
cps2_mra mpang      "Mighty! Pang (Euro 001010)"
cps2_mra pzloop2    "Puzz Loop 2 (Euro 010302)"
cps2_mra choko      "Janpai Puzzle Choukou (Japan 010820)"

# Games released on CPS-2 hardware by Eighting/Raizing
cps2_mra dimahoo    "Dimahoo (Euro 000121)"
cps2_mra 1944       "1944: The Loop Master (USA 000620)"

# Games released on CPS-2 hardware by Cave
cps2_mra progear    "Progear (USA 010117)"
