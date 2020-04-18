#!/bin/bash

parallel jtcore cps1 {} -d JTFRAME_OSD_NOLOAD -z -ftp-folder CPS $* ::: -mist -mister
jtcore cps1 -sidi -d JTFRAME_OSD_NOLOAD -z 
