#!/bin/bash
ROM=$JTROOT/rom
cd $JTROOT/cc || exit $?

make || exit $?

rm -f *.mra

# MiST
mmr -nocoin || exit $?
mv *mra $ROM/mist

mmr -nocoin -alt || exit $?
mv *mra $ROM/mist/alt

# MiSTer
mmr -nocoin || exit $?
mv *mra $ROM/mister

mmr -nocoin -alt || exit $?
mv *mra $ROM/mist/alt

# Make ARC files
echo Preparing MiST ARC files
cd $ROM/mist
mra2rom.sh

# Copy file to MiSTer
echo Copying files to MiSTer
SSHPASS="sshpass -p 1 "
if ! which sshpass>/dev/null; then
    SSHPASS=
fi
cd $ROM/mister
$SSHPASS scp *.mra root@mr:/media/fat/_CPS
cd alt
$SSHPASS scp *.mra root@mr:/media/fat/_CPS/_alt