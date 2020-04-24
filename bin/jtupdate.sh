#!/bin/bash

parallel jtcore cps1 {} -d JTFRAME_OSD_NOLOAD -d JTFRAME_RELEASE -ftp-folder CPS $* ::: -mist -mister -sidi
