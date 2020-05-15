# jtcps1

Capcom System 1 compatible verilog core for FPGA by Jose Tejada (jotego).

# Control

MiSTer allows for gamepad redifinition. However, the keyboard can be used with more or less the same layout as MAME for MiST(er) platforms. Some important keys:

-F12 OSD menu
-P   Pause. Press 1P during pause to toggle the credits on and off
-5,6 1P coin, 2P coin
-1,2 1P, 2P

# MiSTer

Copy the RBF file to `_Arcade/cores` and the MRA files to `_Arcade`. Copy zipped MAME romsets to `_Arcade/mame`. Enjoy.

It is also possible to keep the MAME romsets in `_Arcade/mame` but have the MRA files in `_CPS` and the RBF files in `_CPS/cores`

## Notes

The _rotate screen_ OSD option is ignored for horizontal games.

# MiST

## Setup

You need to generate the .rom file using this (tool)[https://github.com/sebdel/mra-tools-c/tree/master/release]. Basically call it like this:

`mra ghouls.mra -z rompath -A`

And that will produce the .rom file and a .arc file. The .arc file can be used to start the core and directly load the game rom file. Note that the RBF name must be JTCPS1.RBF for it to work. The three files must be in the root folder.

*Important*: make sure to have the latest firmware and latest version of the mra tool.

Copy the RBF, .arc and .rom files to MiST and enjoy!

## Notes

Note that there is no screen rotation in MiST. Vertical games require you to turn your screen around. You can however flip the image through the OSD.

# Issues

Known issues:

-Fuel hoses in Carrier Airwing appear on top of the airplane
-12MHz games may run slightly slower than the original

Please report issues (here)[https://github.com/jotego/jtbin/issues].

# PAL Dumps
PAL dumps cam be obtained from MAME rom sets directly. Use the tool jedutil in order to extract the equations from them. The device is usually a gal16v8. For instance:

```
jedutil -view wl24b.1a gal16v8
```

In order to see the equations for Willow's PAL.

# Compilation
The core is compiled using jtcore from **JTFRAME** but the first time you need to compile and run the utility **mmr** in the *cc* folder:

```
cd cc
make
mmr -inc
```

This generates an include file needed by the verilog code.

# Simulation

## Game
1. Generate a rom file using the MRA tool
2. Update the symbolic link rom.bin in ver/game to point to it
3. If all goes well, `go.sh` should update the sdram.hex file
   But if sdram.hex is a symbolic link to something else it might
   fail. You can delete sdram.hex first so it gets recreated

   `go.sh` will fill up sdram.hex with zeros in order to avoid x's in
   simulation.

4. Apply patches if appropiate. The script `apply_patches.sh` can generate
   some alternative hex files which skip some of the test code of the game
   so it boots up more quickly

5. While simulation is running, it is possible to update the output video
   files by running `raw2jpg.sh`

Some Verilog macros:

1. FORCE_GRAY ignore palette and use a 4-bit gray scale for everything
2. REPORT_DELAY will print the average CPU delay at the end of each frame
   in system ticks (number of 48MHz clocks)

## Video

Video only simulations can be done using mame dumps. Use the tool *cfg2mame* in the *ver/video* folder
to create two *.mame* files that can invoked from mame to dump the simulation data. Run the game in debug
mode but source from MAME the register file that *cfg2mame* creates. Then at the point of interest souce *vram.mame*. That creates the file vram.bin. Copy that file to a directory with the mame name of the game. Add a numerical index (see the other folders for examples). Create a hex file following the examples in
the other files too. Now you run go.sh like this:

```
go.sh -g game -s number -frame 2
```

This will run the simulation for the folder *game* and looking for files with the *number* index. If you
 need to look at the sprites too, you need to run more than one frame as the object DMA needs a frame to
 fill in the data.

# Support

You can show your appreciation through
* Patreon: https://patreon.com/topapate
* Paypal: https://paypal.me/topapate

# Licensing

Contact the author for special licensing needs. Otherwise follow the GPLv3 license attached.