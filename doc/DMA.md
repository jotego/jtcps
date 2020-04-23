# DMA

## Measurements

DMA events occur once per line. All events except the palette DMA will finish before the line finishes.

Once VB starts DMA events are stopped until
1. A palette or OBJ request occurs
2. We need to prepare the SCR buffers before VB ends

VB lasts for 38 lines.

### Palette DMA

It spreads over many lines. Lasts for 780.4us, it can be shorter if not all pages are copied. It can start outside VB, particularly during system bootup sequence.

Palette DMA stops for OBJ processing at the regular pace. It probably stops also for tile processing but that cannot be seen VB because tile proc. is stopped for most of the VB period.

### OBJ DMA

I measured the line DMA header and found these values: 604ns, 1.64us, 2.06us

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

