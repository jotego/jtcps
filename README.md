# jtcps1
Capcom System 1 compatible verilog core for FPGA by Jose Tejada (jotego).

# Usage

## MiSTer

Copy the RBF file to `_Arcade/cores` and the MRA files to `_Arcade`. Copy zipped MAME romsets to `_Arcade/mame`. Enjoy.

## MiST

You need to generate the .rom file using this (tool)[https://github.com/sebdel/mra-tools-c/tree/master/release]. Basically call it like this:

`mra ghouls.mra -z rompath`

And that will produce the .rom file.

Copy the RBF and .rom files to MiST and enjoy!

# Issues

This is a beta version and as such not everything is implemented here. Known issues:

-Sprites may flicker
-Sprites/background may show blank horizontal lines
-ADPCM sound may sound as the same instrument all the time
-Top line of background is either missing or wrong
-Palette during Ghouls'n Ghosts boot up is wrong or absent. Ghouls n' Ghosts has a very long boot up test and if the palette is wrong you may not see something for a while. That's a known problem
-No DIP settings yet, except for test.

Things you may not notice but that are wrong

-CPU bus timing is still not exact, particularly bus sharing is not fully implemented yet

Please report issues (here)[https://github.com/jotego/jtbin/issues].

# PAL Dumps
PAL dumps cam be obtained from MAME rom sets directly. Use the tool jedutil in order to extract the equations from them. The device is usually a gal16v8. For instance:

```
jedutil -view wl24b.1a gal16v8
```

In order to see the equations for Willow's PAL.

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

# Support

You can show your appreciation through
    * Patreon: https://patreon.com/topapate
    * Paypal: https://paypal.me/topapate