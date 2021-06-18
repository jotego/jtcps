# CPS1
../../../cps1/hdl/jtcps1_video.v
../../../cps1/hdl/jtcps1_scroll.v
../../../cps1/hdl/jtcps1_timing.v
../../../cps1/hdl/jtcps1_tilemap.v
../../../cps1/hdl/jtcps1_colmix.v
../../../cps1/hdl/jtcps1_pal.v
../../../cps1/hdl/jtcps1_obj.v
../../../cps1/hdl/jtcps1_mmr.v
../../../cps1/hdl/jtcps1_obj_line_table.v
../../../cps1/hdl/jtcps1_obj_tile_match.v
../../../cps1/hdl/jtcps1_obj_draw.v
../../../cps1/hdl/jtcps1_obj_line.v
../../../cps1/hdl/jtcps1_prom_we.v
../../../cps1/hdl/jtcps1_main.v
../../../cps1/hdl/jtcps1_dtack.v
../../../cps1/hdl/jtcps1_stars.v
../../../cps1/hdl/jtcps1_cpucen.v
../../../cps1/hdl/jtcps1_gfx_mappers.v
../../../cps1/hdl/jtcps1_dma.v
../../../cps1/hdl/jtcps1_sdram.v
# CPS15
../../hdl/jtcps15_game.v
../../hdl/jtcps15_sound.v
# DSP16
../../modules/jtdsp16/hdl/jtdsp16_ctrl.v
../../modules/jtdsp16/hdl/jtdsp16_dau.v
../../modules/jtdsp16/hdl/jtdsp16_div.v
../../modules/jtdsp16/hdl/jtdsp16_pio.v
../../modules/jtdsp16/hdl/jtdsp16_ram_aau.v
../../modules/jtdsp16/hdl/jtdsp16_ram.v
../../modules/jtdsp16/hdl/jtdsp16_rom_aau.v
../../modules/jtdsp16/hdl/jtdsp16_rom.v
../../modules/jtdsp16/hdl/jtdsp16_rsel.v
../../modules/jtdsp16/hdl/jtdsp16_sio.v
../../modules/jtdsp16/hdl/jtdsp16.v

# Filter
$JTFRAME/hdl/sound/jtframe_fir.v
$JTFRAME/hdl/sound/jtframe_uprate2_fir.v
# SDRAM
-F $JTFRAME/hdl/sdram/jtframe_sdram64.f

$JTFRAME/hdl/ram/jtframe_dual_ram.v
$JTFRAME/hdl/ram/jtframe_ram.v
# Z80
$JTFRAME/hdl/cpu/jtframe_kabuki.v
$JTFRAME/hdl/cpu/jtframe_z80.v
$JTFRAME/hdl/jtframe_z80wait.v
$JTFRAME/hdl/jtframe_z80wait.v

# 68000
$JTFRAME/hdl/cpu/jtframe_68kdma.v
$JTFRAME/hdl/cpu/jtframe_m68k.v
$JTFRAME/hdl/cpu/jtframe_68kdtack.v
../../modules/fx68k/fx68kAlu.sv
../../modules/fx68k/fx68k.sv
../../modules/fx68k/uaddrPla.sv

# Serial EEPROM
../../modules/jteeprom/hdl/jt9346.v
# Clocking
$JTFRAME/hdl/clocking/jtframe_cen96.v
$JTFRAME/hdl/clocking/jtframe_cen48.v
$JTFRAME/hdl/clocking/jtframe_frac_cen.v
# Other
$JTFRAME/hdl/jtframe_sh.v
$JTFRAME/hdl/keyboard/jt4701.v
$JTFRAME/hdl/sound/jtframe_mixer.v
