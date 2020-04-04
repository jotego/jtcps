#!/bin/bash

echo -mist -mister | parallel jtcore cps -d JTFRAME_OSD_NOLOAD -z 
jtcore cps -sidi -d JTFRAME_OSD_NOLOAD -z 