../../hdl/jtcps1_video.v
../../hdl/jtcps1_scroll.v
../../hdl/jtcps1_timing.v
../../hdl/jtcps1_tilemap.v
../../hdl/jtcps1_colmix.v
../../hdl/jtcps1_pal.v
../../hdl/jtcps1_obj.v
../../hdl/jtcps1_mmr.v
../../hdl/jtcps1_obj_line_table.v
../../hdl/jtcps1_obj_tile_match.v
../../hdl/jtcps1_obj_draw.v
../../hdl/jtcps1_obj_line.v
../../hdl/jtcps1_sdram.v
../../hdl/jtcps1_prom_we.v
../../hdl/jtcps1_main.v
../../hdl/jtcps1_dtack.v
../../hdl/jtcps1_game.v
../../hdl/jtcps1_sound.v
../../hdl/jtcps1_stars.v
../../hdl/jtcps1_cpucen.v
../../hdl/jtcps1_gfx_mappers.v
../../hdl/jtcps1_dma.v
../../hdl/jtcps1_sdram.v
# ../../hdl/jtcps1_ram.v
# SDRAM
-F $JTFRAME/hdl/sdram/jtframe_sdram64.f

#$JTFRAME/hdl/ram/jtframe_dual_ram.v
$JTFRAME/hdl/ram/jtframe_ram.v
# Z80
$JTFRAME/hdl/cpu/jtframe_z80.v
$JTFRAME/hdl/cpu/jtframe_z80wait.v

# 68000
$JTFRAME/hdl/cpu/jtframe_68kdma.v
$JTFRAME/hdl/cpu/jtframe_m68k.v
$JTFRAME/hdl/cpu/jtframe_68kdtack.v
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
$JTFRAME/hdl/jtframe_sh.v
$JTFRAME/hdl/keyboard/jt4701.v
# $JTFRAME/hdl/keyboard/jtframe_4wayjoy.v
$JTFRAME/hdl/sound/jtframe_mixer.v

# Filters
$JTFRAME/hdl/sound/jtframe_uprate2_fir.v
$JTFRAME/hdl/sound/jtframe_fir_mono.v
$JTFRAME/hdl/sound/jtframe_fir.v
$JTFRAME/hdl/sound/jtframe_pole.v
