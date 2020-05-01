#!/bin/bash

jtseed cps1 -d JTFRAME_OSD_NOLOAD \
            -d JTFRAME_RELEASE \
            -d JTFRAME_OSD_NOSND \
            -ftp-folder CPS $* \
