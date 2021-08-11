#!/bin/bash

cd $JTUTIL/src
make || exit $?
cd -
echo "------------"
OUTDIR=mra

rm -rf "${OUTDIR}"
rm -rf baddir
mkdir baddir

AUXTMP=/tmp/$RANDOM
jtcfgstr -target=mist -output=bash -def $DEF|grep _START > $AUXTMP
source $AUXTMP

if [ ! -d xml ]; then
    mkdir xml
fi

mkdir -p "${OUTDIR}"
mkdir -p "${OUTDIR}/_alt"

function ord { 
    printf -v ordr "%d" "'$1"
}

function hexize() {
    mra="${1}"
    nvm="${2}"
    tmp="${3}"
    
    hexstr=""
    
    while IFS= read -r -n 1 -d '' char; do
        ord "$char"
        hb=`printf '%02x\n' "$ordr"`
        if [ ! -z "${hexstr}" ] ; then
            hexstr="${hexstr} ${hb}"
        else
            hexstr="${hb}"
        fi
    done < "${nvm}"

    inln=`grep -n "nvram index=\"2\"" "${mra}" | cut -d ':' -f 1`
    headln=$[ ${inln} - 1 ]
    head -${headln} "${mra}" > "${tmp}"
    echo "    <rom index=\"2\">" >> "${tmp}"
    echo "        <part>${hexstr}</part>" >> "${tmp}"
    echo "    </rom>" >> "${tmp}"
    tail -n +${inln} "${mra}" >> "${tmp}"
    
    mv -f "${tmp}" "${mra}"
}

function add_nvram() {
    mra="${1}"
    bname=`basename "${mra}"`
    dname=`dirname "${mra}"`
    base="${bname%%mra}"
    nvm="nvram/${base}nvm"
    tmp="${base}tmp"
    
    if [ ! -f "${nvm}" ]; then
        echo "Missing nvram: ${nvm}"
        mv "${mra}" baddir/
    else
#        echo "MRA base: ${bname}  MRA dir: ${dname}  basename: ${base}  NVM: ${nvm}  tmp: ${tmp}"
        hexize "${mra}" "${nvm}" "${tmp}"
    fi
}

function cps2_mra {
    local GAME=$1
    local BUT=$2
    local BUTSTR="$3"
    local ALT=${4//[:]/}
    local CATEGORY="$5"
    local CATVER="${SUBCATEGORY}"
    local BUTCFG=
    
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
    
    case $BUT in
        6) BUTCFG="-header-pointer 050 -header-data FC";;
        *) BUTCFG="";;
    esac
    
    ALTD=_alt/_"$ALT"
    mkdir -p $OUTDIR/"$ALTD"
    AUTHOR="jotego,atrac17"
    if [[ $GAME = choko || $GAME = jyangoku ]]; then
        AUTHOR="$AUTHOR,MJY71"
    fi
    
    echo -----------------------------------------------
    echo Dumping $GAME
#    echo "Dumping $GAME   outdir: ${OUTDIR}   altfolder: ${ALTD}"
    mame2dip xml/$GAME.xml -rbf jtcps2 -outdir $OUTDIR -altfolder "$ALTD" \
        -skip_desc 'Giga Man 2' \
        -setword gfx 64 -qsound \
        -setword maincpu 16 reverse \
        -setword qsound 16 \
        -corebuttons 6 \
        -ignore aboardplds bboardplds cboardplds dboardplds \
        -order key maincpu audiocpu qsound gfx \
        -header 44 0xff \
        -header-offset 0 audiocpu qsound gfx -header-offset-bits 10 -header-offset-reverse \
        -header-pointer 16 \
        -header-data 32 FF 00 \
        -header-data 02 04 06 \
        -header-data 26 28 2A 2C 2E 00 00 30 02 04 08 30 \
        -info platform CPS-2 \
        -info category "$CATEGORY" \
        -info catver "$CATVER" \
        -info mraauthor $AUTHOR \
        $BUTCFG \
        -buttons $BUTSTR \
        -nvram 128 -ddr
}

function update_mras() {
    find . -type f -name "*.mra" | while read l; do
#    	echo "Working with MRA: ${l}"
        add_nvram "${l}"
#        echo "Processed MRA: ${l}"
    done
}


#$BUTSTR W/ Kick Harness except ringdest
FIGHTBTN="Light Punch,Middle Punch,Heavy Punch,Light Kick,Middle Kick,Heavy Kick"

#Games released on CPS-2 hardware in chronological order by Capcom Co., Ltd.
cps2_mra ssf2           6 "$FIGHTBTN"                                                  "Super Street Fighter II: The New Challengers" "Fighting"
cps2_mra ecofghtr       3 "Rotate CCW,Shoot,Rotate CW"                                 "Eco Fighters" "Shoot'em up"
cps2_mra ddtod          4 "Attack,Jump,Item,Select"                                    "Dungeons & Dragons: Tower of Doom" "Beat'em up"
cps2_mra ssf2t          6 "$FIGHTBTN"                                                  "Super Street Fighter II Turbo" "Fighting"
cps2_mra avsp           3 "Shoot,Attack,Jump/Dash"                                     "Alien vs. Predator" "Beat'em up"
cps2_mra dstlk          6 "$FIGHTBTN"                                                  "Darkstalkers: The Night Warriors" "Fighting"
cps2_mra ringdest       6 "Grab,Light Punch,Heavy Punch,Unused,Light Kick,Heavy Kick"  "Ring of Destruction: Slam Masters II" "Fighting"
cps2_mra armwar         3 "Attack,Jump,Sub Weapons"                                    "Armored Warriors" "Beat'em up"
cps2_mra xmcota         6 "$FIGHTBTN"                                                  "X-Men: Children of the Atom" "Fighting"
cps2_mra nwarr          6 "$FIGHTBTN"                                                  "Night Warriors: Darkstalkers' Revenge" "Fighting"
cps2_mra cybots         4 "Attack 1,Attack 2,Boost,Weapon"                             "Cyberbots: Fullmetal Madness" "Fighting"
cps2_mra sfa            6 "$FIGHTBTN"                                                  "Street Fighter Alpha: Warriors' Dreams" "Fighting"
cps2_mra msh            6 "$FIGHTBTN"                                                  "Marvel Super Heroes" "Fighting"
cps2_mra 19xx           2 "Shot,Bomb"                                                  "19XX: The War Against Destiny" "Shoot'em up"
cps2_mra ddsom          4 "Attack,Jump,Select,Magic"                                   "Dungeons & Dragons: Shadow over Mystara" "Beat'em up"
cps2_mra sfa2           6 "$FIGHTBTN"                                                  "Street Fighter Alpha 2" "Fighting"
cps2_mra spf2t          2 "Rotate Left,Rotate Right"                                   "Super Puzzle Fighter II Turbo" "Puzzle"
cps2_mra megaman2       3 "Attack,Jump,Weapon Change"                                  "Mega Man 2: The Power Fighters" "Platformer"
cps2_mra sfz2al         6 "$FIGHTBTN"                                                  "Street Fighter Zero 2 Alpha" "Fighting"
cps2_mra qndream        4 "Button 1,Button 2,Button 3,Button 4"                        "Quiz Nanairo Dreams: Nijiirochou no Kiseki" "Quiz"
cps2_mra xmvsf          6 "$FIGHTBTN"                                                  "X-Men Vs. Street Fighter" "Fighting"
cps2_mra batcir         2 "Attack,Jump"                                                "Battle Circuit" "Beat'em up"
cps2_mra vsav           6 "$FIGHTBTN"                                                  "Vampire Savior: The Lord of Vampire" "Fighting"
cps2_mra mshvsf         6 "$FIGHTBTN"                                                  "Marvel Super Heroes Vs. Street Fighter" "Fighting"
cps2_mra csclub         3 "Shoot/Weak Shot,Pass/Strong Shot,Dash/Lob/Jump"             "Capcom Sports Club" "MultiGame"
cps2_mra sgemf          3 "Punch,Kick,Special"                                         "Super Gem Fighter Mini Mix" "Fighting"
cps2_mra vhunt2         6 "$FIGHTBTN"                                                  "Vampire Hunter 2 Darkstalkers Revenge" "Fighting"
cps2_mra vsav2          6 "$FIGHTBTN"                                                  "Vampire Savior 2: The Lord of Vampire" "Fighting"
cps2_mra mvsc           6 "$FIGHTBTN"                                                  "Marvel Vs. Capcom: Clash of Super Heroes" "Fighting"
cps2_mra sfa3           6 "$FIGHTBTN"                                                  "Street Fighter Alpha 3" "Fighting"
cps2_mra jyangoku       2 "Tsumo,Open Menu"                                            "Jyangokushi: Haoh no Saihai" "Puzzle"
cps2_mra hsf2           6 "$FIGHTBTN"                                                  "Hyper Street Fighter II: The Anniversary Edition" "Fighting"

#Released on CPS-1/CPS-2 hardware by Capcom Co., Ltd.
cps2_mra mmancp2u       3 "Attack,Jump,Weapon Change"                                  "Mega Man: The Power Battle" "Platformer"
cps2_mra mmancp2ur1     3 "Attack,Jump,Weapon Change"                                  "Mega Man: The Power Battle" "Platformer"
cps2_mra mmancp2ur2     3 "Attack,Jump,Weapon Change"                                  "Mega Man: The Power Battle" "Platformer"
cps2_mra rmancp2j       3 "Attack,Jump,Weapon Change"                                  "Mega Man: The Power Battle" "Platformer"

#Games released on CPS-2 hardware by Cave Co., Ltd.
cps2_mra progear        3 "Shot,Bomb,Rapid Shot"                                       "Progear" "Shoot'em up"

#Games released on CPS-2 hardware by Eighting/Raizing
cps2_mra dimahoo        3 "Main Shot,Bomb,Rapid Main Shot"                             "Dimahoo" "Shoot'em up"
cps2_mra 1944           2 "Shot,Bomb"                                                  "1944: The Loop Master" "Shoot'em up"

#Games released on CPS-2 hardware by Mitchell Corp.
cps2_mra mpang          1 "Shot"                                                       "Mighty! Pang" "Platformer"
cps2_mra pzloop2        1 "Shot"                                                       "Puzz Loop 2" "Puzzle"
cps2_mra choko          3 "Select,Cancel,Help"                                         "Janpai Puzzle Choukou" "Puzzle"

#Games released on CPS-2 hardware by Takumi Corporation
cps2_mra gigawing       2 "Shot,Force Bomb"                                            "Giga Wing" "Shoot'em up"
cps2_mra mmatrix        1 "Shot"                                                       "Mars Matrix: Hyper Solid Shooting" "Shoot'em up"

update_mras

# echo "Enter MiSTer's root password"
# scp -r "mra/* root@MiSTer.home:/media/fat/_CPS 2"

exit 0
