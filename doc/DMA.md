# DMA

## Measurements

DMA events occur once per line. All events except the palette DMA will finish before the line finishes.

Once VB starts DMA events are stopped until
1. A palette or OBJ request occurs
2. We need to prepare the SCR buffers before VB ends

VB lasts for 38 lines.

### Palette DMA

It spreads over many lines. Lasts for 780.4us, it is of a fixed duration, regardless of which palettes are updated. It can start outside VB, particularly during system bootup sequence.

Palette DMA stops for OBJ processing at the regular pace. It probably stops also for tile processing but that cannot be seen VB because tile proc. is stopped for most of the VB period.

### OBJ DMA

I measured the line DMA header and found these values: 604ns, 1.64us, 2.06us

ROW SCR | OBJ  | Time (us)
--------|------|----------
  OFF   | OFF  | 0.60
  OFF   |  ON  | 1.64
  ON    | OFF  | Not measured
  ON    |  ON  | 2.06

The first one would correspond to a line update with no OBJ and no row scroll. The second, no row scroll, but OBJ is active. The third, full row scroll and OBJ. It seems that there is a minimum of ~600ns (maybe 9x 16MHz cycles plus some bus arbitrion at the CPU 10MHz) required by the original DMA controller even if no requests are in place.

On each line a whole sprite data is copied: 4 16-bit transfers.

OBJ DMA can be re-started in the middle of the frame.

### Tiles DMA

Tile data for each scroll layer is stored in a buffer. SCR2 buffer is larger because it supports row scrolling.

Layer | Transfers | Time (us, 4MHz clock) | Equivalent tile pixels
------|-----------|-----------------------|------------------------
SCR1  |  98       | 24.5                  | 392
SCR2  |  96       | 24                    | 768
SCR3  |  24       | 6                     | 384

The layers are read in this order: SCR1, SCR2 and finally SCR3. Each layer is read only when it is needed based on the current screen position and the vertical scroll value.

### Loop test

A counter runs during the frame and gets reset at VB. By switching different control registers the following information can be extracted:

-Palette is only copied if the base register is written to. The DMA duration is the same regardless of the palette mask setting
-Scroll 2, 3 and row scroll. The video control register disables DMA for this layer
-Video control register is $4C ($11 in jtcps1_mmr.v = ppu_ctrl)
    -ROW  bit 0
    -SCR2 bit 4
    -SCR3 bit 2

Row scroll
19a9 7,6,3,2
198D 4,5,1,0

Scroll 3
19a8 7,6,3,2
198d 4,5,1,0

Scroll 2
1a31 7,6,3,2
198e 4,5,1,0

Fastest setting
1a67
Slowest setting
1833

## Timing History

Some changes in how the /DTACK signal is handled have affected the core performance over time. This is a collection of the different values recorded using _SF2 DMA no b3.mra_

Version         | commit  | Speed     | JTFRAME
----------------|---------|-----------|-------------------------
Original PCB    |  N/A    |  2C00     |
20210131        |         |  2C04     |
20210604        |         |  2C0A     |
20210828        |         |  2C0B     |
20210921        |         |**357C**   |
20211002        |         |  357C     |
20211024        |         |  357C     |
20220112        |         |  3584     |
20220321        |         |  3584     |
20220417        |         |**2BF9**   |
20220422        |         |  2BF9     |
20220427        |         |  2BF9     |
20220601        |         |  2BF9     |
20220627        |         |  2BF9     |
20220704        |         |  2BF9     |
20220705        | 61626fc |  2BF9     |  bd7cf34
20220819        | b78bdae |**3576**   |  a108a4a
                | f0c96fc |**3576**   |  79e0574

The regression caused by JTFRAME's a108a4a was Fixed in JTFRAME's f697791.

