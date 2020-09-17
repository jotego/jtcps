#!/usr/bin/python

import sys

bank_size[0]=int(sys.argv[1],16)
bank_size[1]=int(sys.argv[2],16)
bank_size[2]=int(sys.argv[3],16)
bank_size[3]=int(sys.argv[4],16)

offset=0
mask=0


aux=bank_size[0]>>13
offset = offset | (aux<<4)
mask = mask | (aux-1)

print hex(offset &0xff) hex(offset>>8) hex(mask &0xff) hex(mask>>8)