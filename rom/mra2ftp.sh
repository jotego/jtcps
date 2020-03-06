#/bin/bash
HOST=mr

#for i in *.mra; do mra $i; done
#bspatch ghouls.rom ghouls_notest.rom ghouls_notest.bspatch

ftp -inv $HOST <<EOF
user root 1
cd /media/fat/games/JTCPS1
mput *.rom
rename ffight.rom JTCPS1.rom
mput ffight.rom
bye
EOF

