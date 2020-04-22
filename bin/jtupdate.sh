#!/bin/bash

parallel jtcore cps1 {} -d JTFRAME_OSD_NOLOAD -ftp-folder CPS $* ::: -mist -mister -sidi
