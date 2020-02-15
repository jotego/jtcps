struct gfx_range
{
    // start and end are as passed by the game (shift adjusted to be all
    // in the same scale a 8x8 tiles): they don't necessarily match the
    // position in ROM.
    int type;
    int start;
    int end;
    int bank;
};

#define GFXTYPE_SPRITES   (1<<0)
#define GFXTYPE_SCROLL1   (1<<1)
#define GFXTYPE_SCROLL2   (1<<2)
#define GFXTYPE_SCROLL3   (1<<3)
#define GFXTYPE_STARS     (1<<4)

#define mapper_LWCHR    { 0x8000, 0x8000, 0, 0 }, mapper_LWCHR_table
static const struct gfx_range mapper_LWCHR_table[] =
{
    // verified from PAL dump (PAL16P8B @ 3A):
    // bank 0 = pin 19 (ROMs 1,5,8,12)
    // bank 1 = pin 16 (ROMs 2,6,9,13)
    // pin 12 and pin 14 are always enabled (except for stars)
    // note that allowed codes go up to 0x1ffff but physical ROM is half that size

    /* type            start    end      bank */
    { GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },
    { GFXTYPE_SCROLL1, 0x00000, 0x1ffff, 0 },

    { GFXTYPE_STARS,   0x00000, 0x1ffff, 1 },
    { GFXTYPE_SCROLL2, 0x00000, 0x1ffff, 1 },
    { GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },
    { 0 }
};

#define mapper_LW621    { 0x8000, 0x8000, 0, 0 }, mapper_LW621_table
static const struct gfx_range mapper_LW621_table[] =
{
    // verified from PAL dump (PAL @ 1A):
    // bank 0 = pin 18
    // bank 1 = pin 14
    // pins 19, 16, 17, and 12 give an alternate half-size mapping which would
    // allow to use smaller ROMs:
    // pin 19
    // 0 00000-03fff
    // pin 16
    // 0 04000-07fff
    // 1 00000-1ffff
    // pin 17
    // 2 00000-1ffff
    // 3 00000-1ffff
    // 4 00000-1ffff
    // pin 12
    // 3 00000-1ffff
    //
    // note that allowed codes go up to 0x1ffff but physical ROM is half that size

    /* type            start    end      bank */
    { GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },
    { GFXTYPE_SCROLL1, 0x00000, 0x1ffff, 0 },

    { GFXTYPE_STARS,   0x00000, 0x1ffff, 1 },
    { GFXTYPE_SCROLL2, 0x00000, 0x1ffff, 1 },
    { GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },
    { 0 }
};


// DM620, DM22A and DAM63B are equivalent as far as the game is concerned, though
// the equations are quite different

#define mapper_DM620    { 0x8000, 0x2000, 0x2000, 0 }, mapper_DM620_table
static const struct gfx_range mapper_DM620_table[] =
{
    // verified from PAL dump (PAL16P8B @ 2A):
    // bank 0 = pin 19 (ROMs  5,6,7,8)
    // bank 1 = pin 16 (ROMs  9,11,13,15,18,20,22,24)
    // bank 2 = pin 14 (ROMs 10,12,14,16,19,21,23,25)
    // pin 12 is never enabled
    // note that bank 0 is enabled whenever banks 1 or 2 are not enabled,
    // which would make it highly redundant, so I'm relying on the table
    // to be scanned top to bottom and using a catch-all clause at the end.

    /* type            start   end     bank */
    { GFXTYPE_SCROLL3, 0x8000, 0xbfff, 1 },

    { GFXTYPE_SPRITES, 0x2000, 0x3fff, 2 },

    { GFXTYPE_STARS | GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 0 },
    { 0 }
};

#define mapper_DM22A    { 0x4000, 0x4000, 0x2000, 0x2000 }, mapper_DM22A_table
static const struct gfx_range mapper_DM22A_table[] =
{
    // verified from PAL dump
    // bank 0 = pin 19
    // bank 1 = pin 16
    // bank 2 = pin 14
    // bank 3 = pin 12

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x00000, 0x01fff, 0 },
    { GFXTYPE_SCROLL1, 0x02000, 0x03fff, 0 },

    { GFXTYPE_SCROLL2, 0x04000, 0x07fff, 1 },

    { GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 2 },

    { GFXTYPE_SPRITES, 0x02000, 0x03fff, 3 },
    { 0 }
};

#define mapper_DAM63B   { 0x8000, 0x8000, 0, 0 }, mapper_DAM63B_table
static const struct gfx_range mapper_DAM63B_table[] =
{
    // verified from PAL dump:
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
    // pins 12,13,14,15 are always enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x00000, 0x01fff, 0 },
    { GFXTYPE_SCROLL1, 0x02000, 0x02fff, 0 },
    { GFXTYPE_SCROLL2, 0x04000, 0x07fff, 0 },

    { GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },
    { GFXTYPE_SPRITES, 0x02000, 0x03fff, 1 },
    { 0 }
};


// ST24M1 and ST22B are equivalent except for the stars range which is
// different. This has no practical effect.

#define mapper_ST24M1   { 0x8000, 0x8000, 0, 0 }, mapper_ST24M1_table
static const struct gfx_range mapper_ST24M1_table[] =
{
    // verified from PAL dump
    // bank 0 = pin 19 (ROMs 2,4,6,8)
    // bank 1 = pin 16 (ROMs 1,3,5,7)
    // pin 12 and pin 14 are never enabled

    /* type            start    end      bank */
    { GFXTYPE_STARS,   0x00000, 0x003ff, 0 },
    { GFXTYPE_SPRITES, 0x00000, 0x04fff, 0 },
    { GFXTYPE_SCROLL2, 0x04000, 0x07fff, 0 },

    { GFXTYPE_SCROLL3, 0x00000, 0x07fff, 1 },
    { GFXTYPE_SCROLL1, 0x07000, 0x07fff, 1 },
    { 0 }
};

#define mapper_ST22B    { 0x4000, 0x4000, 0x4000, 0x4000 }, mapper_ST22B_table
static const struct gfx_range mapper_ST22B_table[] =
{
    // verified from PAL dump
    // bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
    // bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
    // bank 2 = pin 14 (ROMs 3,7,11,15,19,21,26,28)
    // bank 3 = pin 12 (ROMS 4,8,12,16,20,22,27,29)

    /* type            start    end      bank */
    { GFXTYPE_STARS,   0x00000, 0x1ffff, 0 },
    { GFXTYPE_SPRITES, 0x00000, 0x03fff, 0 },

    { GFXTYPE_SPRITES, 0x04000, 0x04fff, 1 },
    { GFXTYPE_SCROLL2, 0x04000, 0x07fff, 1 },

    { GFXTYPE_SCROLL3, 0x00000, 0x03fff, 2 },

    { GFXTYPE_SCROLL3, 0x04000, 0x07fff, 3 },
    { GFXTYPE_SCROLL1, 0x07000, 0x07fff, 3 },
    { 0 }
};


#define mapper_TK22B    { 0x4000, 0x4000, 0x4000, 0x4000 }, mapper_TK22B_table
static const struct gfx_range mapper_TK22B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
    // bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
    // bank 2 = pin 14 (ROMs 3,7,11,15,19,21,26,28)
    // bank 3 = pin 12 (ROMS 4,8,12,16,20,22,27,29)

    /* type            start  end      bank */
    { GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },

    { GFXTYPE_SPRITES, 0x4000, 0x5fff, 1 },
    { GFXTYPE_SCROLL1, 0x6000, 0x7fff, 1 },

    { GFXTYPE_SCROLL3, 0x0000, 0x3fff, 2 },

    { GFXTYPE_SCROLL2, 0x4000, 0x7fff, 3 },
    { 0 }
};


#define mapper_WL24B    { 0x8000, 0x8000, 0, 0 }, mapper_WL24B_table
static const struct gfx_range mapper_WL24B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // bank 1 = pin 12 (ROMs 10,12,14,16,20,22,24,26)
    // pin 14 and pin 19 are never enabled

    /* type            start  end      bank */
    { GFXTYPE_SPRITES, 0x0000, 0x4fff, 0 },
    { GFXTYPE_SCROLL3, 0x5000, 0x6fff, 0 },
    { GFXTYPE_SCROLL1, 0x7000, 0x7fff, 0 },

    { GFXTYPE_SCROLL2, 0x0000, 0x3fff, 1 },
    { 0 }
};


#define mapper_S224B    { 0x8000, 0, 0, 0 }, mapper_S224B_table
static const struct gfx_range mapper_S224B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // pin 12 & pin 14 give an alternate half-size mapping which would allow to
    // populate the 8-bit ROM sockets instead of the 16-bit ones:
    // pin 12
    // 0 00000 - 03fff
    // pin 14
    // 0 04000 - 043ff
    // 1 04400 - 04bff
    // 2 06000 - 07fff
    // 3 04c00 - 05fff
    // pin 19 is never enabled

    /* type            start  end      bank */
    { GFXTYPE_SPRITES, 0x0000, 0x43ff, 0 },
    { GFXTYPE_SCROLL1, 0x4400, 0x4bff, 0 },
    { GFXTYPE_SCROLL3, 0x4c00, 0x5fff, 0 },
    { GFXTYPE_SCROLL2, 0x6000, 0x7fff, 0 },
    { 0 }
};


#define mapper_YI24B    { 0x8000, 0, 0, 0 }, mapper_YI24B_table
static const struct gfx_range mapper_YI24B_table[] =
{
    // verified from JED:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // pin 12 & pin 14 give an alternate half-size mapping which would allow to
    // populate the 8-bit ROM sockets instead of the 16-bit ones:
    // pin 12
    // 0 0000-1fff
    // 3 2000-3fff
    // pin 14
    // 1 4000-47ff
    // 2 4800-7fff
    // pin 19 is never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x1fff, 0 },
    { GFXTYPE_SCROLL3, 0x2000, 0x3fff, 0 },
    { GFXTYPE_SCROLL1, 0x4000, 0x47ff, 0 },
    { GFXTYPE_SCROLL2, 0x4800, 0x7fff, 0 },
    { 0 }
};


// AR24B and AR22B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_AR24B    { 0x8000, 0, 0, 0 }, mapper_AR24B_table
static const struct gfx_range mapper_AR24B_table[] =
{
    // verified from JED:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // pin 12 & pin 14 give an alternate half-size mapping which would allow to
    // populate the 8-bit ROM sockets instead of the 16-bit ones:
    // pin 12
    // 0 0000-2fff
    // 1 3000-3fff
    // pin 14
    // 2 4000-5fff
    // 3 6000-7fff
    // pin 19 is never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL1, 0x3000, 0x3fff, 0 },
    { GFXTYPE_SCROLL2, 0x4000, 0x5fff, 0 },
    { GFXTYPE_SCROLL3, 0x6000, 0x7fff, 0 },
    { 0 }
};

#define mapper_AR22B    { 0x4000, 0x4000, 0, 0 }, mapper_AR22B_table
static const struct gfx_range mapper_AR22B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
    // bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
    // pins 12 and 14 are tristated

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL1, 0x3000, 0x3fff, 0 },

    { GFXTYPE_SCROLL2, 0x4000, 0x5fff, 1 },
    { GFXTYPE_SCROLL3, 0x6000, 0x7fff, 1 },
    { 0 }
};


#define mapper_O224B    { 0x8000, 0x4000, 0, 0 }, mapper_O224B_table
static const struct gfx_range mapper_O224B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 2,4,6,8)
    // bank 1 = pin 12 (ROMs 10,12,14,16,20,22,24,26)
    // pin 16 & pin 14 appear to be an alternate half-size mapping for bank 0
    // but scroll1 is missing:
    // pin 16
    // 2 00c00 - 03bff
    // 3 03c00 - 03fff
    // pin 14
    // 3 04000 - 04bff
    // 0 04c00 - 07fff

    /* type            start   end     bank */
    { GFXTYPE_SCROLL1, 0x0000, 0x0bff, 0 },
    { GFXTYPE_SCROLL2, 0x0c00, 0x3bff, 0 },
    { GFXTYPE_SCROLL3, 0x3c00, 0x4bff, 0 },
    { GFXTYPE_SPRITES, 0x4c00, 0x7fff, 0 },

    { GFXTYPE_SPRITES, 0x8000, 0xa7ff, 1 },
    { GFXTYPE_SCROLL2, 0xa800, 0xb7ff, 1 },
    { GFXTYPE_SCROLL3, 0xb800, 0xbfff, 1 },
    { 0 }
};


#define mapper_MS24B    { 0x8000, 0, 0, 0 }, mapper_MS24B_table
static const struct gfx_range mapper_MS24B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // pin 14 duplicates pin 16 allowing to populate the 8-bit ROM sockets
    // instead of the 16-bit ones.
    // pin 12 is enabled only for sprites:
    // 0 0000-3fff
    // pin 19 is never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },
    { GFXTYPE_SCROLL1, 0x4000, 0x4fff, 0 },
    { GFXTYPE_SCROLL2, 0x5000, 0x6fff, 0 },
    { GFXTYPE_SCROLL3, 0x7000, 0x7fff, 0 },
    { 0 }
};


#define mapper_CK24B    { 0x8000, 0, 0, 0 }, mapper_CK24B_table
static const struct gfx_range mapper_CK24B_table[] =
{
    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL1, 0x3000, 0x3fff, 0 },
    { GFXTYPE_SCROLL2, 0x4000, 0x6fff, 0 },
    { GFXTYPE_SCROLL3, 0x7000, 0x7fff, 0 },
    { 0 }
};


#define mapper_NM24B    { 0x8000, 0, 0, 0 }, mapper_NM24B_table
static const struct gfx_range mapper_NM24B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // pin 12 & pin 14 give an alternate half-size mapping which would allow to
    // populate the 8-bit ROM sockets instead of the 16-bit ones:
    // pin 12
    // 0 00000 - 03fff
    // 2 00000 - 03fff
    // pin 14
    // 1 04000 - 047ff
    // 0 04800 - 067ff
    // 2 04800 - 067ff
    // 3 06800 - 07fff
    // pin 19 is never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },
    { GFXTYPE_SCROLL2, 0x0000, 0x3fff, 0 },
    { GFXTYPE_SCROLL1, 0x4000, 0x47ff, 0 },
    { GFXTYPE_SPRITES, 0x4800, 0x67ff, 0 },
    { GFXTYPE_SCROLL2, 0x4800, 0x67ff, 0 },
    { GFXTYPE_SCROLL3, 0x6800, 0x7fff, 0 },
    { 0 }
};


// CA24B and CA22B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_CA24B    { 0x8000, 0, 0, 0 }, mapper_CA24B_table
static const struct gfx_range mapper_CA24B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // pin 12 & pin 14 give an alternate half-size mapping which would allow to
    // populate the 8-bit ROM sockets instead of the 16-bit ones:
    // pin 12
    // 0 0000-2fff
    // 2 0000-2fff
    // 3 3000-3fff
    // pin 14
    // 3 4000-4fff
    // 1 5000-57ff
    // 0 5800-7fff
    // 2 5800-7fff
    // pin 19 is never enabled (actually it is always enabled when PAL pin 1 is 1, purpose unknown)

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL2, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL3, 0x3000, 0x4fff, 0 },
    { GFXTYPE_SCROLL1, 0x5000, 0x57ff, 0 },
    { GFXTYPE_SPRITES, 0x5800, 0x7fff, 0 },
    { GFXTYPE_SCROLL2, 0x5800, 0x7fff, 0 },
    { 0 }
};

#define mapper_CA22B    { 0x4000, 0x4000, 0, 0 }, mapper_CA22B_table
static const struct gfx_range mapper_CA22B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
    // bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
    // pin 12 and pin 14 are never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL2, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL3, 0x3000, 0x3fff, 0 },

    { GFXTYPE_SCROLL3, 0x4000, 0x4fff, 1 },
    { GFXTYPE_SCROLL1, 0x5000, 0x57ff, 1 },
    { GFXTYPE_SPRITES, 0x5800, 0x7fff, 1 },
    { GFXTYPE_SCROLL2, 0x5800, 0x7fff, 1 },
    { 0 }
};


#define mapper_STF29    { 0x8000, 0x8000, 0x8000, 0 }, mapper_STF29_table
static const struct gfx_range mapper_STF29_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 5,6,7,8)
    // bank 1 = pin 14 (ROMs 14,15,16,17)
    // bank 2 = pin 12 (ROMS 24,25,26,27)

    /* type            start    end      bank */
    { GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },

    { GFXTYPE_SPRITES, 0x08000, 0x0ffff, 1 },

    { GFXTYPE_SPRITES, 0x10000, 0x11fff, 2 },
    { GFXTYPE_SCROLL3, 0x02000, 0x03fff, 2 },
    { GFXTYPE_SCROLL1, 0x04000, 0x04fff, 2 },
    { GFXTYPE_SCROLL2, 0x05000, 0x07fff, 2 },
    { 0 }
};


// RT24B and RT22B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_RT24B    { 0x8000, 0x8000, 0, 0 }, mapper_RT24B_table
static const struct gfx_range mapper_RT24B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 16 (ROMs 1,3,5,7)
    // bank 1 = pin 19 (ROMs 2,4,6,8)
    // pin 12 & pin 14 are never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x53ff, 0 },
    { GFXTYPE_SCROLL1, 0x5400, 0x6fff, 0 },
    { GFXTYPE_SCROLL3, 0x7000, 0x7fff, 0 },

    { GFXTYPE_SCROLL3, 0x0000, 0x3fff, 1 },
    { GFXTYPE_SCROLL2, 0x2800, 0x7fff, 1 },
    { GFXTYPE_SPRITES, 0x5400, 0x7fff, 1 },
    { 0 }
};

#define mapper_RT22B    { 0x4000, 0x4000, 0x4000, 0x4000 }, mapper_RT22B_table
static const struct gfx_range mapper_RT22B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
    // bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
    // bank 2 = pin 14 (ROMs 3,7,11,15,19,21,26,28)
    // bank 3 = pin 12 (ROMS 4,8,12,16,20,22,27,29)

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },

    { GFXTYPE_SPRITES, 0x4000, 0x53ff, 1 },
    { GFXTYPE_SCROLL1, 0x5400, 0x6fff, 1 },
    { GFXTYPE_SCROLL3, 0x7000, 0x7fff, 1 },

    { GFXTYPE_SCROLL3, 0x0000, 0x3fff, 2 },
    { GFXTYPE_SCROLL2, 0x2800, 0x3fff, 2 },

    { GFXTYPE_SCROLL2, 0x4000, 0x7fff, 3 },
    { GFXTYPE_SPRITES, 0x5400, 0x7fff, 3 },
    { 0 }
};


#define mapper_KD29B    { 0x8000, 0x8000, 0, 0 }, mapper_KD29B_table
static const struct gfx_range mapper_KD29B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 1,2,3,4)
    // bank 1 = pin 14 (ROMs 10,11,12,13)
    // pin 12 is never enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x7fff, 0 },

    { GFXTYPE_SPRITES, 0x8000, 0x8fff, 1 },
    { GFXTYPE_SCROLL2, 0x9000, 0xbfff, 1 },
    { GFXTYPE_SCROLL1, 0xc000, 0xd7ff, 1 },
    { GFXTYPE_SCROLL3, 0xd800, 0xffff, 1 },
    { 0 }
};


#define mapper_CC63B    { 0x8000, 0x8000, 0, 0 }, mapper_CC63B_table
static const struct gfx_range mapper_CC63B_table[] =
{
    // verified from PAL dump:
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
    // pins 12,13,14,15 are always enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x7fff, 0 },
    { GFXTYPE_SCROLL2, 0x0000, 0x7fff, 0 },

    { GFXTYPE_SPRITES, 0x8000, 0xffff, 1 },
    { GFXTYPE_SCROLL1, 0x8000, 0xffff, 1 },
    { GFXTYPE_SCROLL2, 0x8000, 0xffff, 1 },
    { GFXTYPE_SCROLL3, 0x8000, 0xffff, 1 },
    { 0 }
};


#define mapper_KR63B    { 0x8000, 0x8000, 0, 0 }, mapper_KR63B_table
static const struct gfx_range mapper_KR63B_table[] =
{
    // verified from PAL dump:
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
    // pins 12,13,14,15 are always enabled

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x7fff, 0 },
    { GFXTYPE_SCROLL2, 0x0000, 0x7fff, 0 },

    { GFXTYPE_SCROLL1, 0x8000, 0x9fff, 1 },
    { GFXTYPE_SPRITES, 0x8000, 0xcfff, 1 },
    { GFXTYPE_SCROLL2, 0x8000, 0xcfff, 1 },
    { GFXTYPE_SCROLL3, 0xd000, 0xffff, 1 },
    { 0 }
};


#define mapper_S9263B   { 0x8000, 0x8000, 0x8000, 0 }, mapper_S9263B_table
static const struct gfx_range mapper_S9263B_table[] =
{
    // verified from PAL dump:
    // FIXME there is some problem with this dump since pin 14 is never enabled
    // instead of being the same as pin 15 as expected
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
    // bank2 = pin 15 (ROMs 10,12) & pin 14 (ROMs 11,13)
    // pins 12 and 13 are the same as 14 and 15

    /* type            start    end      bank */
    { GFXTYPE_SPRITES, 0x00000, 0x07fff, 0 },

    { GFXTYPE_SPRITES, 0x08000, 0x0ffff, 1 },

    { GFXTYPE_SPRITES, 0x10000, 0x11fff, 2 },
    { GFXTYPE_SCROLL3, 0x02000, 0x03fff, 2 },
    { GFXTYPE_SCROLL1, 0x04000, 0x04fff, 2 },
    { GFXTYPE_SCROLL2, 0x05000, 0x07fff, 2 },
    { 0 }
};


// VA22B and VA63B are equivalent, but since we could dump both PALs we are
// documenting both.

#define mapper_VA22B    { 0x4000, 0x4000, 0, 0 }, mapper_VA22B_table
static const struct gfx_range mapper_VA22B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19 (ROMs 1,5, 9,13,17,24,32,38)
    // bank 1 = pin 16 (ROMs 2,6,10,14,18,25,33,39)
    // pin 12 and pin 14 are never enabled

    /* type                                                                  start    end      bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x03fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x04000, 0x07fff, 1 },
    { 0 }
};

#define mapper_VA63B    { 0x8000, 0, 0, 0 }, mapper_VA63B_table
static const struct gfx_range mapper_VA63B_table[] =
{
    // verified from PAL dump (PAL # uncertain):
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // pins 12,13,14,15,16,17 are never enabled

    /* type                                                                  start    end      bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x07fff, 0 },
    { 0 }
};


#define mapper_Q522B    { 0x8000, 0, 0, 0 }, mapper_Q522B_table
static const struct gfx_range mapper_Q522B_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x0000, 0x6fff, 0 },
    { GFXTYPE_SCROLL3,                   0x7000, 0x77ff, 0 },
    { GFXTYPE_SCROLL1,                   0x7800, 0x7fff, 0 },
    { 0 }
};


#define mapper_TK263B   { 0x8000, 0x8000, 0, 0 }, mapper_TK263B_table
static const struct gfx_range mapper_TK263B_table[] =
{
    // verified from PAL dump:
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
    // pins 12,13,14,15 are always enabled

    /* type                                                                  start    end      bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x07fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x08000, 0x0ffff, 1 },
    { 0 }
};


#define mapper_CD63B    { 0x8000, 0x8000, 0, 0 }, mapper_CD63B_table
static const struct gfx_range mapper_CD63B_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
    { GFXTYPE_SPRITES,                   0x1000, 0x7fff, 0 },

    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0xdfff, 1 },
    { GFXTYPE_SCROLL3,                   0xe000, 0xffff, 1 },
    { 0 }
};


#define mapper_PS63B    { 0x8000, 0x8000, 0, 0 }, mapper_PS63B_table
static const struct gfx_range mapper_PS63B_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
    { GFXTYPE_SPRITES,                   0x1000, 0x7fff, 0 },

    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0xdbff, 1 },
    { GFXTYPE_SCROLL3,                   0xdc00, 0xffff, 1 },
    { 0 }
};


#define mapper_MB63B    { 0x8000, 0x8000, 0x8000, 0 }, mapper_MB63B_table
static const struct gfx_range mapper_MB63B_table[] =
{
    /* type                              start    end      bank */
    { GFXTYPE_SCROLL1,                   0x00000, 0x00fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x01000, 0x07fff, 0 },

    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x08000, 0x0ffff, 1 },

    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x10000, 0x167ff, 2 },
    { GFXTYPE_SCROLL3,                   0x16800, 0x17fff, 2 },
    { 0 }
};


#define mapper_QD22B    { 0x4000, 0, 0, 0 }, mapper_QD22B_table
static const struct gfx_range mapper_QD22B_table[] =
{
    // verified from PAL dump:
    // bank 0 = pin 19

    /* type            start   end     bank */
    { GFXTYPE_SPRITES, 0x0000, 0x3fff, 0 },
    { GFXTYPE_SCROLL1, 0x0000, 0x3fff, 0 },
    { GFXTYPE_SCROLL2, 0x0000, 0x3fff, 0 },
    { GFXTYPE_SCROLL3, 0x0000, 0x3fff, 0 },
    { 0 }
};


#define mapper_QAD63B   { 0x8000, 0, 0, 0 }, mapper_QAD63B_table
static const struct gfx_range mapper_QAD63B_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SCROLL1,                   0x0000, 0x07ff, 0 },
    { GFXTYPE_SCROLL3,                   0x0800, 0x1fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x2000, 0x7fff, 0 },
    { 0 }
};


#define mapper_TN2292   { 0x8000, 0x8000, 0, 0 }, mapper_TN2292_table
static const struct gfx_range mapper_TN2292_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
    { GFXTYPE_SCROLL3,                   0x1000, 0x3fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x4000, 0x7fff, 0 },

    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0xffff, 1 },
    { 0 }
};


#define mapper_RCM63B   { 0x8000, 0x8000, 0x8000, 0x8000 }, mapper_RCM63B_table
static const struct gfx_range mapper_RCM63B_table[] =
{
    // verified from PAL dump:
    // bank0 = pin 19 (ROMs 1,3) & pin 18 (ROMs 2,4)
    // bank1 = pin 17 (ROMs 5,7) & pin 16 (ROMs 6,8)
    // bank0 = pin 15 (ROMs 10,12) & pin 14 (ROMs 11,13)
    // bank1 = pin 13 (ROMs 14,16) & pin 12 (ROMs 15,17)

    /* type                                                                  start    end      bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x07fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x08000, 0x0ffff, 1 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x10000, 0x17fff, 2 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x18000, 0x1ffff, 3 },
    { 0 }
};


#define mapper_PKB10B   { 0x8000, 0, 0, 0 }, mapper_PKB10B_table
static const struct gfx_range mapper_PKB10B_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SCROLL1,                   0x0000, 0x0fff, 0 },
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x1000, 0x5fff, 0 },
    { GFXTYPE_SCROLL3,                   0x6000, 0x7fff, 0 },
    { 0 }
};


#define mapper_pang3    { 0x8000, 0x8000, 0, 0 }, mapper_pang3_table
static const struct gfx_range mapper_pang3_table[] =
{
    /* type                              start   end     bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x0000, 0x7fff, 0 },

    { GFXTYPE_SPRITES | GFXTYPE_SCROLL2, 0x8000, 0x9fff, 1 },
    { GFXTYPE_SCROLL1,                   0xa000, 0xbfff, 1 },
    { GFXTYPE_SCROLL3,                   0xc000, 0xffff, 1 },
    { 0 }
};


#define mapper_sfzch    { 0x20000, 0, 0, 0 }, mapper_sfzch_table
static const struct gfx_range mapper_sfzch_table[] =
{
    /* type                                                                  start    end      bank */
    { GFXTYPE_SPRITES | GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 0 },
    { 0 }
};


/*
  I don't know if CPS2 ROM boards use PALs as well; since all games seem to be
  well behaved, I'll just assume that there is no strong checking of gfx type.
  (sprites are not listed here because they are addressed linearly by the CPS2
  sprite code)
 */
#define mapper_cps2 { 0x20000, 0x20000, 0, 0 }, mapper_cps2_table
static const struct gfx_range mapper_cps2_table[] =
{
    /* type                                                start    end      bank */
    { GFXTYPE_SCROLL1 | GFXTYPE_SCROLL2 | GFXTYPE_SCROLL3, 0x00000, 0x1ffff, 1 },   // 20000-3ffff physical
    { 0 }
};



/*
Name     knm10b;
PartNo   ;
Date     ;
Revision ;
Designer ;
Company  ;
Assembly ;
Location ;
Device   g16v8;

 Dedicated input pins

pin 1   = I0;  Input
pin 2   = I1;  Input
pin 3   = I2;  Input
pin 4   = I3;  Input
pin 5   = I4;  Input
pin 6   = I5;  Input
pin 7   = I6;  Input
pin 8   = I7;  Input
pin 9   = I8;  Input
pin 11  = I9;  Input

 Programmable output pins

pin 12  = B0;  Combinatorial output
pin 13  = B1;  Combinatorial output
pin 14  = B2;  Combinatorial output
pin 15  = B3;  Combinatorial output
pin 16  = B4;  Combinatorial output
pin 17  = B5;  Combinatorial output
pin 18  = B6;  Combinatorial output
pin 19  = B7;  Combinatorial output

 Output equations

!B7 = !I0 & !I1 & !I2 & !I3 & !I4 & !I5 & !I9
    #  I0 & !I1 & !I2 & !I3 & !I4 & !I5 &  I9;
!B6 = !I0 & !I1 & !I2 & !I3 & !I4 & !I5 & !I9
    #  I0 & !I1 & !I2 & !I3 & !I4 & !I5 &  I9;
!B5 = !I0 & !I1 & !I2 & !I3 & !I4 &  I5 & !I9
    #  I0 & !I1 & !I2 & !I3 & !I4 &  I5 &  I9;
!B4 = !I0 & !I1 & !I2 & !I3 & !I4 &  I5 & !I9
    #  I0 & !I1 & !I2 & !I3 & !I4 &  I5 &  I9;
!B3 = !I0 & !I1 & !I2 & !I3 &  I4 & !I5 & !I6 & !I7 & !I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 & !I8 & !I9
    # !I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 & !I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 & !I8 & !I9
    # !I0 & !I1 & !I2 &  I3 & !I4 & !I5 & !I6 & !I7 &  I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 &  I8 & !I9
    # !I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 &  I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 &  I8 & !I9
    #  I0 & !I1 & !I2 & !I3 &  I4 & !I5 & !I6 & !I7 & !I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 & !I8 &  I9
    #  I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 & !I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 & !I8 &  I9
    #  I0 & !I1 & !I2 &  I3 & !I4 & !I5 & !I6 & !I7 &  I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 &  I8 &  I9
    #  I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 &  I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 &  I8 &  I9;
!B2 = !I0 & !I1 & !I2 & !I3 &  I4 & !I5 & !I6 & !I7 & !I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 & !I8 & !I9
    # !I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 & !I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 & !I8 & !I9
    # !I0 & !I1 & !I2 &  I3 & !I4 & !I5 & !I6 & !I7 &  I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 &  I8 & !I9
    # !I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 &  I8 & !I9
    # !I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 &  I8 & !I9
    #  I0 & !I1 & !I2 & !I3 &  I4 & !I5 & !I6 & !I7 & !I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 & !I8 &  I9
    #  I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 & !I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 & !I8 &  I9
    #  I0 & !I1 & !I2 &  I3 & !I4 & !I5 & !I6 & !I7 &  I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 &  I8 &  I9
    #  I0 & !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 &  I8 &  I9
    #  I0 & !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 &  I8 &  I9;
!B1 = !I1 & !I2 & !I3 &  I4 & !I5 & !I6 & !I7 & !I8
    # !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 & !I8
    # !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 & !I8
    # !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 & !I8
    # !I1 & !I2 &  I3 & !I4 & !I5 & !I6 & !I7 &  I8
    # !I1 &  I2 & !I3 & !I4 & !I5 &  I6 & !I7 &  I8
    # !I1 &  I2 &  I3 & !I4 & !I5 & !I6 &  I7 &  I8
    # !I1 &  I2 & !I3 & !I4 & !I5 &  I6 &  I7 &  I8;
!B0 =  I0 &  I9;

*/
// wrong, need to figure this out from the PAL

#define mapper_KNM10B    { 0x8000, 0x8000, 0x8000, 0 }, mapper_KNM10B_table
static const struct gfx_range mapper_KNM10B_table[] =
{
    /* type             start    end      bank */

    { GFXTYPE_SPRITES , 0x00000, 0x07fff, 0 },
    { GFXTYPE_SPRITES , 0x08000, 0x0ffff, 1 },
    { GFXTYPE_SPRITES , 0x10000, 0x17fff, 2 },
    { GFXTYPE_SCROLL2 , 0x04000, 0x07fff, 2 },
    { GFXTYPE_SCROLL1,  0x01000, 0x01fff, 2 },
    { GFXTYPE_SCROLL3 , 0x02000, 0x03fff, 2 },
    { 0 }
};

// unknown part number, this is just based on where the gfx are in the ROM
#define mapper_pokonyan   { 0x8000, 0x8000, 0x8000, 0 }, mapper_pokonyan_table
static const struct gfx_range mapper_pokonyan_table[] =
{
    /* type            start    end      bank */
    { GFXTYPE_SPRITES, 0x0000, 0x2fff, 0 },
    { GFXTYPE_SCROLL1, 0x7000, 0x7fff, 0 },
    { GFXTYPE_SCROLL3, 0x3000, 0x3fff, 0 },
    { GFXTYPE_SCROLL2, 0x4000, 0x6fff, 0 },
    { 0 }
};
