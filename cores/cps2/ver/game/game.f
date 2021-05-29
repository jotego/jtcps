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
../../../cps1/hdl/jtcps1_stars.v
../../../cps1/hdl/jtcps1_cpucen.v
../../../cps1/hdl/jtcps1_gfx_mappers.v
../../../cps1/hdl/jtcps1_dma.v
../../../cps1/hdl/jtcps1_sdram.v
#../../../cps1/hdl/jtcps1_ram.v
../../../cps1/hdl/jtcps1_dtack.v
# CPS15
../../../cps15/hdl/jtcps15_sound.v
# CPS2
../../hdl/jtcps2_game.v
../../hdl/jtcps2_main.v
../../hdl/jtcps2_obj.v
../../hdl/jtcps2_obj_frame.v
../../hdl/jtcps2_objram.v
../../hdl/jtcps2_obj_scan.v
../../hdl/jtcps2_colmix.v
../../hdl/jtcps2_raster.v
../../hdl/jtcps2_dtack.v
# Keys
../../hdl/jtcps2_decrypt.v
../../hdl/jtcps2_keyload.v
../../hdl/jtcps2_fn1.v
../../hdl/jtcps2_fn2.v
../../hdl/jtcps2_fn_sbox.v
../../hdl/jtcps2_sbox.v
../../hdl/jtcps2_dec_ctrl.v

# DSP16
$MODULES/jtdsp16/hdl/jtdsp16_ctrl.v
$MODULES/jtdsp16/hdl/jtdsp16_dau.v
$MODULES/jtdsp16/hdl/jtdsp16_div.v
$MODULES/jtdsp16/hdl/jtdsp16_pio.v
$MODULES/jtdsp16/hdl/jtdsp16_ram_aau.v
$MODULES/jtdsp16/hdl/jtdsp16_ram.v
$MODULES/jtdsp16/hdl/jtdsp16_rom_aau.v
$MODULES/jtdsp16/hdl/jtdsp16_rom.v
$MODULES/jtdsp16/hdl/jtdsp16_rsel.v
$MODULES/jtdsp16/hdl/jtdsp16_sio.v
$MODULES/jtdsp16/hdl/jtdsp16.v

# Filter
$JTFRAME/hdl/sound/jtframe_fir.v
$JTFRAME/hdl/sound/jtframe_uprate2_fir.v
# SDRAM
-F $JTFRAME/hdl/sdram/jtframe_sdram64.f

$JTFRAME/hdl/ram/jtframe_dual_ram.v
$JTFRAME/hdl/ram/jtframe_dual_ram16.v
$JTFRAME/hdl/ram/jtframe_ram.v
# Z80
$JTFRAME/hdl/cpu/jtframe_kabuki.v
$JTFRAME/hdl/cpu/jtframe_z80.v
$JTFRAME/hdl/jtframe_z80wait.v
$JTFRAME/hdl/jtframe_z80wait.v
# 68000
$JTFRAME/hdl/cpu/jtframe_68kdma.v
$MODULES/fx68k/fx68kAlu.sv
$MODULES/fx68k/fx68k.sv
$MODULES/fx68k/uaddrPla.sv
# Serial EEPROM
$MODULES/jteeprom/hdl/jt9346.v
# Clocking
$JTFRAME/hdl/clocking/jtframe_cen96.v
$JTFRAME/hdl/clocking/jtframe_cen48.v
$JTFRAME/hdl/clocking/jtframe_frac_cen.v
# Other
$JTFRAME/hdl/cpu/jtframe_virq.v
$JTFRAME/hdl/jtframe_sh.v
$JTFRAME/hdl/keyboard/jt4701.v
$JTFRAME/hdl/sound/jtframe_mixer.v
