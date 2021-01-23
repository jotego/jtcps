# Buffer Architecture

## CPS1

### Original Design

There is a frame buffer only for objects. Data is read from it at the pixel rate,
while data for the next frame is written in any location.

1. At VBLANK: CPU triggers the DMA and starts writing on a new VRAM page
2. During HBLANK, a few table entries are read
3. Sprites from read entries are rendered in the frame buffer

### JTCPS1

There is no frame buffer but only a line buffer.

1. At VBLANK: CPU triggers the DMA and starts writing on a new VRAM page
2. During HBLANK, a few table entries are copied to an internal table in BRAM
3. The internal table is read and a selection of sprites that will be visible
   is copied to a second table (double buffered)
4. The second table is used to render sprites in the line buffer

The advantage of this architecture is that it uses less memory. However, the
maximum number of sprites that can be drawn is less than what was allegedly
possible in the original hardware.

## CPS2

### Original design

There is no DMA involved. There is an 8kBx2 page buffer. While the CPU writes to one
of them, the engine renders the contents of the other one. The CPU flags which half
is being accessed with a latch.

A frame buffer is also used in CPS2.

### JTCPS2

Memory bits available without OBJ logic: 249'117 (MiST) => 27 9MK blocks free

The SDRAM does not limit the number of elements:
    -SDRAM limit: 96MHz / 8 * 4 bytes = 48 MByte
    -GFX data 4bpp, 16 pixels => 1 pixel = 8 bytes
    -SDRAM limit in pixels = 48Mbyte/8 = 6MByte => >12k horizontal lines
