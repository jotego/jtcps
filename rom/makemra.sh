#!/bin/bash
pushd .
cd $JTFRAME/cc
make || exit $?
popd

mkdir -p mra/_alt/"Warriors of Fate"
mame2dip wof.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Warriors of Fate" \
    -frac 2 gfx 4 -qsound \
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
    -header-data 5 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 76 54 32 10 24 60 13 57 43 43 43 \
    -buttons Attack Jump None None None None

mkdir -p mra/_alt/"The Punisher"
mame2dip punisher.xml -rbf jtcps15 -outdir mra -altfolder _alt/"The Punisher" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data 0e c0 \
    -header-data FF FF FF FF \
    -header-data 12 14 16 08 0a 0c 04 02 20 00 \
    -header-data 17 \
    -header-data $(mapper_offset.py 8000 8000 0 0) \
    -header-pointer 48 \
    -header-data 67 45 21 03 75 31 60 24 22 22 22 \
    -buttons Attack Jump None None None None

mkdir -p mra/_alt/"Saturday Night Slam Masters"
mame2dip slammast.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Saturday Night Slam Masters" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data 2e c1 \
    -header-data FF FF FF FF \
    -header-data 16 00 02 28 2a 2c 04 08 10 00 \
    -header-data 10 \
    -header-data $(mapper_offset.py 8000 8000 8000 0) \
    -header-pointer 48 \
    -header-data 54 32 10 76 65 43 21 07 31 31 19 \
    -buttons Attack Jump None None None None

mkdir -p mra/_alt/"Muscle Bomber Duo"
mame2dip mbombrd.xml -rbf jtcps15 -outdir mra -altfolder _alt/"Muscle Bomber Duo" \
    -frac 2 gfx 4 -qsound \
    -swapbytes maincpu \
    -ignore aboardplds bboardplds cboardplds dboardplds \
    -order maincpu audiocpu qsound gfx \
    -header 64 0xff \
    -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
    -header-pointer 16 \
    -header-data 2e c1 \
    -header-data FF FF FF FF \
    -header-data 16 00 02 28 2a 2c 04 08 10 00 \
    -header-data 10 \
    -header-data $(mapper_offset.py 8000 8000 8000 0) \
    -header-pointer 48 \
    -header-data 54 32 10 76 65 43 21 07 31 31 19 \
    -buttons Attack Jump None None None None

# CPS2 Titles
function cps2_mra {
if [ ! -e $1.xml ]; then
    mamefilter $1 > $1.xml
fi

mkdir -p mra/_alt/"$2"
mame2dip $1.xml -rbf jtcps2 -outdir mra -altfolder _alt/"$2" \
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
}

cps2_mra ddtod "DnD Tower of Doom"
cps2_mra ssf2       "Super Street Fighter II: The New Challengers (World 931005)"
cps2_mra ssf2t      "Super Street Fighter II Turbo (World 940223)"
cps2_mra ecofghtr   "Eco Fighters (World 931203)"
cps2_mra avsp       "Alien vs. Predator (Euro 940520)"
cps2_mra dstlk      "Darkstalkers: The Night Warriors (Euro 940705)"
cps2_mra ringdest   "Ring of Destruction: Slammasters II (Euro 940902)"
cps2_mra armwar     "Armored Warriors (Euro 941024)"
cps2_mra xmcota     "X-Men: Children of the Atom (Euro 950331)"
cps2_mra nwarr      "Night Warriors: Darkstalkers' Revenge (Euro 950316)"
cps2_mra cybots     "Cyberbots: Fullmetal Madness (Euro 950424)"
cps2_mra sfa        "Street Fighter Alpha: Warriors' Dreams (Euro 950727)"
cps2_mra mmancp2u   "Mega Man: The Power Battle (CPS2, USA 951006, SAMPLE Version)"
cps2_mra mmancp2ur1 "Mega Man: The Power Battle (CPS2, USA 950926, SAMPLE Version)"
cps2_mra rmancp2j   "Rockman: The Power Battle (CPS2, Japan 950922)"
cps2_mra msh        "Marvel Super Heroes (Euro 951024)"
cps2_mra 19xx       "19XX: The War Against Destiny (Euro 960104)"
cps2_mra ddsom      "Dungeons & Dragons: Shadow over Mystara (Euro 960619)"
cps2_mra sfa2       "Street Fighter Alpha 2 (Euro 960229)"
cps2_mra sfz2al     "Street Fighter Zero 2 Alpha (Asia 960826)"
cps2_mra spf2t      "Super Puzzle Fighter II Turbo (Euro 960529)"
cps2_mra megaman2   "Mega Man 2: The Power Fighters (USA 960708)"
cps2_mra qndream    "Quiz Nanairo Dreams: Nijiirochou no Kiseki (Japan 960826)"
cps2_mra xmvsf      "X-Men Vs. Street Fighter (Euro 961004)"
cps2_mra batcir     "Battle Circuit (Euro 970319)"
cps2_mra vsav       "Vampire Savior: The Lord of Vampire (Euro 970519)"
cps2_mra mshvsf     "Marvel Super Heroes Vs. Street Fighter (Euro 970625)"
cps2_mra csclub     "Capcom Sports Club (Euro 971017)"
cps2_mra sgemf      "Super Gem Fighter Mini Mix (USA 970904)"
cps2_mra vhunt2     "Vampire Hunter 2: Darkstalkers Revenge (Japan 970929)"
cps2_mra vsav2      "Vampire Savior 2: The Lord of Vampire (Japan 970913)"
cps2_mra mvsc       "Marvel Vs. Capcom: Clash of Super Heroes (Euro 980123)"
cps2_mra sfa3       "Street Fighter Alpha 3 (Euro 980904)"
cps2_mra jyangoku   "Jyangokushi: Haoh no Saihai (Japan 990527)"
cps2_mra hsf2       "Hyper Street Fighter II: The Anniversary Edition (USA 040202)"

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
