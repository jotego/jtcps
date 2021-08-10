#/bin/bash
HOST=mr

#for i in *.mra; do mra $i; done
#bspatch ghouls.rom ghouls_notest.rom ghouls_notest.bspatch

ftp -inv $HOST <<EOF
user root 1
cd /media/fat/_CPS
mput *.mra
bye
EOF

