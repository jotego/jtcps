#!/usr/bin/python

import sys

bank_size = [int(sys.argv[1],16),
             int(sys.argv[2],16),
             int(sys.argv[3],16),
             int(sys.argv[4],16) ]

offset=0
mask=0

aux=bank_size[0]>>13
offset = aux<<4
mask = aux-1

aux+=(bank_size[1]>>13)
offset |= aux<<8
mask |= ( (bank_size[1]>>12)-1)<<4

aux+=(bank_size[2]>>13)
offset |= aux<<12
mask   |= ((bank_size[2]>>12)-1)<<8

mask   |= ( (bank_size[3]>>12)-1)<<12



print '{:02X} {:02X} {:02X} {:02X}'.format( offset &0xff, (offset>>8)&0xff, mask &0xff, (mask>>8)&0xff)