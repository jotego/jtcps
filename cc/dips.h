#include "dip_base.h"

#define CPS1_COINAGE_1(diploc) \
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) ) PORT_DIPLOCATION(diploc ":1,2,3") \
    PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) ) \
    PORT_DIPSETTING(    0x01, DEF_STR( 3C_1C ) ) \
    PORT_DIPSETTING(    0x02, DEF_STR( 2C_1C ) ) \
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) ) \
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) ) \
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) ) \
    PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) ) \
    PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) ) \
    PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) ) PORT_DIPLOCATION(diploc ":4,5,6") \
    PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) ) \
    PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) ) \
    PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) ) \
    PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) ) \
    PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) ) \
    PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) ) \
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) ) \
    PORT_DIPSETTING(    0x18, DEF_STR( 1C_6C ) )
/*
#define CPS1_COINAGE_2(diploc) \
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coinage ) ) PORT_DIPLOCATION(diploc ":1,2,3") \
    PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) ) \
    PORT_DIPSETTING(    0x01, DEF_STR( 3C_1C ) ) \
    PORT_DIPSETTING(    0x02, DEF_STR( 2C_1C ) ) \
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) ) \
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) ) \
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) ) \
    PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) ) \
    PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) )

#define CPS1_COINAGE_3(diploc) \
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) ) PORT_DIPLOCATION(diploc ":1,2,3") \
    PORT_DIPSETTING(    0x01, DEF_STR( 4C_1C ) ) \
    PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) ) \
    PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) ) \
    PORT_DIPSETTING(    0x00, "2 Coins/1 Credit (1 to continue)" ) \
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) ) \
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) ) \
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) ) \
    PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) ) \
    PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) ) PORT_DIPLOCATION(diploc ":4,5,6") \
    PORT_DIPSETTING(    0x08, DEF_STR( 4C_1C ) ) \
    PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) ) \
    PORT_DIPSETTING(    0x18, DEF_STR( 2C_1C ) ) \
    PORT_DIPSETTING(    0x00, "2 Coins/1 Credit (1 to continue)" ) \
    PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) ) \
    PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) ) \
    PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) ) \
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) )

#define CPS1_DIFFICULTY_1(diploc) \
    PORT_DIPNAME( 0x07, 0x04, DEF_STR( Difficulty ) ) PORT_DIPLOCATION(diploc ":1,2,3") \
    PORT_DIPSETTING(    0x07, "0 (Easiest)" ) \
    PORT_DIPSETTING(    0x06, "1" ) \
    PORT_DIPSETTING(    0x05, "2" ) \
    PORT_DIPSETTING(    0x04, "3 (Normal)" ) \
    PORT_DIPSETTING(    0x03, "4" ) \
    PORT_DIPSETTING(    0x02, "5" ) \
    PORT_DIPSETTING(    0x01, "6" ) \
    PORT_DIPSETTING(    0x00, "7 (Hardest)" )

#define CPS1_DIFFICULTY_2(diploc) \
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Difficulty ) ) PORT_DIPLOCATION(diploc ":1,2,3") \
    PORT_DIPSETTING(    0x04, "1 (Easiest)" ) \
    PORT_DIPSETTING(    0x05, "2" ) \
    PORT_DIPSETTING(    0x06, "3" ) \
    PORT_DIPSETTING(    0x07, "4 (Normal)" ) \
    PORT_DIPSETTING(    0x03, "5" ) \
    PORT_DIPSETTING(    0x02, "6" ) \
    PORT_DIPSETTING(    0x01, "7" ) \
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
*/
static INPUT_PORTS_START( ghouls )
    PORT_INCLUDE( cps1_2b_4way )
    /* Service1 doesn't give any credit */

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )            PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x03, "3" )
    PORT_DIPSETTING(    0x02, "4" )
    PORT_DIPSETTING(    0x01, "5" )
    PORT_DIPSETTING(    0x00, "6" )
    PORT_DIPUNUSED_DIPLOC( 0x04, 0x04, "SW(C):3" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(C):4" )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )      PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unused ) )           PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )              // "Demo Sounds" in manual; doesn't work
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )   PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                  PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

    PORT_START("DSWB") /* Manual states default difficulty "B" (2) which differs from the normal macro */
    PORT_DIPNAME( 0x07, 0x05, DEF_STR( Difficulty ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x04, "1 (Easiest)" )
    PORT_DIPSETTING(    0x05, "2" )
    PORT_DIPSETTING(    0x06, "3" )
    PORT_DIPSETTING(    0x07, "4 (Normal)" )
    PORT_DIPSETTING(    0x03, "5" )
    PORT_DIPSETTING(    0x02, "6" )
    PORT_DIPSETTING(    0x01, "7" )
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(B):4" )
    PORT_DIPNAME( 0x30, 0x30, DEF_STR( Bonus_Life ) )       PORT_DIPLOCATION("SW(B):5,6")
    PORT_DIPSETTING(    0x20, "10K, 30K and every 30K" )
    PORT_DIPSETTING(    0x10, "20K, 50K and every 70K" )
    PORT_DIPSETTING(    0x30, "30K, 60K and every 70K" )
    PORT_DIPSETTING(    0x00, "40K, 70K and every 80K" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Cabinet ) )          PORT_DIPLOCATION("SW(A):7,8")
    PORT_DIPSETTING(    0xc0, "Upright 1 Player" )
    PORT_DIPSETTING(    0x80, "Upright 2 Players" )
//  PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )         // Manual says these are both valid settings
    PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )         // for 2-player cocktail cabinet
INPUT_PORTS_END


/* Same as 'ghouls' but additional "Freeze" Dip Switch, different "Lives" Dip Switch,
   and LOTS of "debug" features (read the notes to know how to activate them) */
static INPUT_PORTS_START( ghoulsu )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) ) PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPSETTING(    0x03, "3" )
    PORT_DIPSETTING(    0x02, "4" )
    PORT_DIPSETTING(    0x01, "5" )

    PORT_MODIFY("DSWB")
    /* Standard Dip Switches */
    PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unused ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x30, 0x00, DEF_STR( Bonus_Life ) )  PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):5,6")
    PORT_DIPSETTING(    0x20, "10K, 30K and every 30K" )
    PORT_DIPSETTING(    0x10, "20K, 50K and every 70K" )
    PORT_DIPSETTING(    0x30, "30K, 60K and every 70K" )
    PORT_DIPSETTING(    0x00, "40K, 70K and every 80K" )
/* Manuals states the following bonus settings
    PORT_DIPSETTING(    0x20, "20K, 50K and every 70K" )
    PORT_DIPSETTING(    0x10, "10K, 30K and every 30K" )
    PORT_DIPSETTING(    0x30, "40K, 70K and every 80K" )
    PORT_DIPSETTING(    0x00, "30K, 60K and every 70K" )
*/
    /* Debug Dip Switches */
    PORT_DIPNAME( 0x07, 0x07, "Starting Weapon" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "Spear" )
    PORT_DIPSETTING(    0x06, "Knife" )
    PORT_DIPSETTING(    0x05, "Torch" )
    PORT_DIPSETTING(    0x04, "Sword" )
    PORT_DIPSETTING(    0x03, "Axe" )
    PORT_DIPSETTING(    0x02, "Shield" )
    PORT_DIPSETTING(    0x01, "Super Weapon" )
//  PORT_DIPSETTING(    0x00, "INVALID !" )
    PORT_DIPNAME( 0x38, 0x30, "Armor on New Life" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(B):4,5,6")
//  PORT_DIPSETTING(    0x38, "Silver Armor" )
    PORT_DIPSETTING(    0x18, "Golden Armor" )
    PORT_DIPSETTING(    0x30, "Silver Armor" )
    PORT_DIPSETTING(    0x28, "None (young man)" )
    PORT_DIPSETTING(    0x20, "None (old man)" )
//  PORT_DIPSETTING(    0x10, "INVALID !" )
//  PORT_DIPSETTING(    0x08, "INVALID !" )
//  PORT_DIPSETTING(    0x00, "INVALID !" )

    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPNAME( 0x80, 0x80, "Freeze" ) PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_MODIFY("DSWA")
    /* Standard Dip Switches */
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(A):1,2,3")
    PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x01, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x02, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )
    PORT_DIPSETTING(    0x03, DEF_STR( 1C_6C ) )
    PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(A):4,5,6")
    PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x08, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) )
    PORT_DIPSETTING(    0x18, DEF_STR( 1C_6C ) )
    /* Debug Dip Switches */
    PORT_DIPNAME( 0x0f, 0x0f, "Starting Level" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):1,2,3,4")
    PORT_DIPSETTING(    0x0f, "Level 1 (1st half)" )
    PORT_DIPSETTING(    0x0e, "Level 1 (2nd half)" )
    PORT_DIPSETTING(    0x0d, "Level 2 (1st half)" )
    PORT_DIPSETTING(    0x0c, "Level 2 (2nd half)" )
    PORT_DIPSETTING(    0x0b, "Level 3 (1st half)" )
    PORT_DIPSETTING(    0x0a, "Level 3 (2nd half)" )
    PORT_DIPSETTING(    0x09, "Level 4 (1st half)" )
    PORT_DIPSETTING(    0x08, "Level 4 (2nd half)" )
    PORT_DIPSETTING(    0x07, "Level 5 (1st half)" )
    PORT_DIPSETTING(    0x06, "Level 5 (2nd half)" )
    PORT_DIPSETTING(    0x05, "Level 6" )
//  PORT_DIPSETTING(    0x04, "INVALID !" )
//  PORT_DIPSETTING(    0x03, "INVALID !" )
//  PORT_DIPSETTING(    0x02, "INVALID !" )
//  PORT_DIPSETTING(    0x01, "INVALID !" )
//  PORT_DIPSETTING(    0x00, "INVALID !" )
    PORT_DIPNAME( 0x10, 0x10, "Invulnerability" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, "Slow Motion" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Cabinet ) ) PORT_DIPLOCATION("SW(A):7,8")
    PORT_DIPSETTING(    0xc0, "Upright 1 Player" )
    PORT_DIPSETTING(    0x80, "Upright 2 Players" )
//  PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )             // Manual says these are both valid settings
    PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )             // for 2-player cocktail cabinet
INPUT_PORTS_END

/* Same as 'ghouls' but additional "Freeze" Dip Switch */
static INPUT_PORTS_START( daimakai )
    PORT_INCLUDE( cps1_2b_4way )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x80, 0x80, "Freeze" )        PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )  // This switch isn't documented in the manual
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

static INPUT_PORTS_START( daimakair )
    PORT_INCLUDE( cps1_2b_4way )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x80, 0x80, "Freeze" )        PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )  // This switch isn't documented in the manual
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

/* "Debug" features to be implemented */
static INPUT_PORTS_START( strider )
    PORT_INCLUDE( cps1_3b )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Cabinet ) )              PORT_DIPLOCATION("SW(A):7,8")
    PORT_DIPSETTING(    0xc0, "Upright 1 Player" )              // These switches are not documented in the manual
    PORT_DIPSETTING(    0x80, "Upright 2 Players" )
//  PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )

    PORT_START("DSWB") /* Like Ghouls, Strider manual states "B" (or 2) as the recommended difficulty level. */
    PORT_DIPNAME( 0x07, 0x05, DEF_STR( Difficulty ) ) PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x04, "1 (Easiest)" )
    PORT_DIPSETTING(    0x05, "2" )
    PORT_DIPSETTING(    0x06, "3" )
    PORT_DIPSETTING(    0x07, "4 (Normal)" )
    PORT_DIPSETTING(    0x03, "5" )
    PORT_DIPSETTING(    0x02, "6" )
    PORT_DIPSETTING(    0x01, "7" )
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
    /* In 'striderj', bit 3 is stored at 0xff8e77 ($e77,A5) via code at 0x000a2a,
       but this address is never checked again.
       In 'strider' and 'stridrjr', this code even doesn't exist ! */
    PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unused ) )               PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )                  // Manual says this is 2c start/1c continue but it
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )                   // doesn't work (see comment above)
    PORT_DIPNAME( 0x30, 0x00, DEF_STR( Bonus_Life ) )           PORT_DIPLOCATION("SW(B):5,6")
/* These show in test mode */
    PORT_DIPSETTING(    0x30, "20K, 40K then every 60K" )
    PORT_DIPSETTING(    0x20, "30K, 50K then every 70K" )
    PORT_DIPSETTING(    0x10, "20K & 60K only" )
    PORT_DIPSETTING(    0x00, "30K & 60K only" )
/* According to manual, these are the proper settings
    PORT_DIPSETTING(    0x30, "40K, 70K then every 80K" )
    PORT_DIPSETTING(    0x20, "20K, 50K then every 70K" )
    PORT_DIPSETTING(    0x10, "10k, 30k then every 30k" )
    PORT_DIPSETTING(    0x00, "30K, 60k then every 70k" )
*/

    PORT_DIPNAME( 0xc0, 0x80, "Internal Diff. on Life Loss" )   PORT_DIPLOCATION("SW(B):7,8")
    PORT_DIPSETTING(    0xc0, "-3" )                            // Check code at 0x00d15a
//  PORT_DIPSETTING(    0x40, "-1" )                            // These switches are not documented in the manual
    PORT_DIPSETTING(    0x00, "-1" )
    PORT_DIPSETTING(    0x80, "Default" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )                PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "2" )                             // "6" in the "test mode" and manual
    PORT_DIPSETTING(    0x03, "3" )
    PORT_DIPSETTING(    0x02, "4" )
    PORT_DIPSETTING(    0x01, "5" )
    PORT_DIPNAME( 0x04, 0x04, "Freeze" )                        PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, DEF_STR( Free_Play ) )            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )          PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ) )          PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x20, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )       PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                      PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )                 // To enable the "debug" features
INPUT_PORTS_END

/* Same as 'strider' but additional "2 Coins to Start, 1 to Continue" Dip Switch */
/* "Debug" features to be implemented */
static INPUT_PORTS_START( stridrua )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWB")
    /* In 'striderj', bit 3 is stored at 0xff8e77 ($e77,A5) via code at 0x000a2a,
       but this address is never checked again.
       In 'strider' and 'stridrjr', this code even doesn't exist ! */
    PORT_DIPNAME( 0x08, 0x08, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )                      // This works in this revision
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

static INPUT_PORTS_START( dynwar )
    PORT_INCLUDE( cps1_3b )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x01, 0x01, "Freeze" )                        PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )                  // Also affects energy cost - read notes
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )                   // This switch is not documented in the manual
    PORT_DIPNAME( 0x02, 0x02, "Turbo Mode" )                    PORT_DIPLOCATION("SW(C):2")
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )                  // Also affects energy cost - read notes
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )                   // This switch is not documented in the manual
    PORT_DIPUNUSED_DIPLOC( 0x04, 0x04, "SW(C):3" )              // This switch is not documented in the manual
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(C):4" )              // This switch is not documented in the manual
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )          PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ) )          PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )                  // "ON"  in the "test mode"
    PORT_DIPSETTING(    0x20, DEF_STR( On ) )                   // "OFF" in the "test mode"
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )       PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )                   // "ON"  in the "test mode"
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )                  // "OFF" in the "test mode"
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                      PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_2( "SW(B)" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(B):4" )              // These five switches are not documented in the
    PORT_DIPUNUSED_DIPLOC( 0x10, 0x10, "SW(B):5" )              // manual
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWA")
    /* According to the manual, ALL switches 1 to 6 must be ON to have
       "2 Coins/1 Credit (1 to continue)" for both coin slots */
    CPS1_COINAGE_3( "SW(A)" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(A):7" )              // This switch is not documented in the manual
    PORT_DIPNAME( 0x80, 0x80, DEF_STR( Free_Play ) )            PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )                  // This switch is not documented in the manual
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END



/* Read the notes to know how to activate the "debug" features */
static INPUT_PORTS_START( willow )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWC")
    /* Standard Dip Switches */
    PORT_DIPNAME( 0x03, 0x02, DEF_STR( Lives ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x02, "1" )
    PORT_DIPSETTING(    0x03, "2" )
    PORT_DIPSETTING(    0x01, "3" )
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPNAME( 0x0c, 0x08, "Vitality" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(C):3,4")
    PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPSETTING(    0x0c, "3" )
    PORT_DIPSETTING(    0x08, "4" )
    PORT_DIPSETTING(    0x04, "5" )
    /* Debug Dip Switches */
    PORT_DIPNAME( 0x01, 0x01, "Turbo Mode" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x02, "Freeze" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(C):2")
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, "Slow Motion" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Invulnerability" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )          PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    /* Standard Dip Switches */
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x20, DEF_STR( On ) )
    /* Debug Dip Switches */
    PORT_DIPNAME( 0x20, 0x20, "Display Debug Infos" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )

    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )       PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                      PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )                 // To enable the "debug" features

    PORT_START("DSWB")
    /* Standard Dip Switches */
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Difficulty ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x04, "1 (Easiest)" )
    PORT_DIPSETTING(    0x05, "2" )
    PORT_DIPSETTING(    0x06, "3" )
    PORT_DIPSETTING(    0x07, "4 (Normal)" )
    PORT_DIPSETTING(    0x03, "5" )
    PORT_DIPSETTING(    0x02, "6" )
    PORT_DIPSETTING(    0x01, "7" )
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
    PORT_DIPNAME( 0x18, 0x18, "Nando Speed" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x10, "Slow" )
    PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x08, "Fast" )
    PORT_DIPSETTING(    0x00, "Very Fast" )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unused ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unused ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, "Stage Magic Continue" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    /* Debug Dip Switches */
    PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unused ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(B):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x1e, 0x1e, "Slow Motion Delay" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(B):2,3,4,5")
    PORT_DIPSETTING(    0x1e, "2 Frames" )
    PORT_DIPSETTING(    0x1c, "3 Frames" )
    PORT_DIPSETTING(    0x1a, "4 Frames" )
    PORT_DIPSETTING(    0x18, "5 Frames" )
    PORT_DIPSETTING(    0x16, "6 Frames" )
    PORT_DIPSETTING(    0x14, "7 Frames" )
    PORT_DIPSETTING(    0x12, "8 Frames" )
    PORT_DIPSETTING(    0x10, "9 Frames" )
    PORT_DIPSETTING(    0x0e, "10 Frames" )
    PORT_DIPSETTING(    0x0c, "11 Frames" )
    PORT_DIPSETTING(    0x0a, "12 Frames" )
    PORT_DIPSETTING(    0x08, "13 Frames" )
    PORT_DIPSETTING(    0x06, "14 Frames" )
    PORT_DIPSETTING(    0x04, "15 Frames" )
    PORT_DIPSETTING(    0x02, "16 Frames" )
    PORT_DIPSETTING(    0x00, "17 Frames" )
    PORT_DIPNAME( 0xe0, 0xe0, "Starting Level" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(B):6,7,8")
    PORT_DIPSETTING(    0xe0, "Level 1" )
    PORT_DIPSETTING(    0xc0, "Level 2" )
    PORT_DIPSETTING(    0xa0, "Level 3" )
    PORT_DIPSETTING(    0x80, "Level 4" )
    PORT_DIPSETTING(    0x60, "Level 5" )
    PORT_DIPSETTING(    0x40, "Level 6" )
//  PORT_DIPSETTING(    0x20, "INVALID !" )
//  PORT_DIPSETTING(    0x00, "INVALID !" )

    PORT_START("DSWA")
    /* Standard Dip Switches */
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Coin_A ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(A):1,2,3")
    PORT_DIPSETTING(    0x01, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x02, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, "2 Coins/1 Credit (1 to continue)" )
    PORT_DIPSETTING(    0x07, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x06, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x05, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x04, DEF_STR( 1C_4C ) )
    PORT_DIPNAME( 0x38, 0x38, DEF_STR( Coin_B ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(A):4,5,6")
    PORT_DIPSETTING(    0x08, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x18, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x00, "2 Coins/1 Credit (1 to continue)" )
    PORT_DIPSETTING(    0x38, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x30, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x28, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 1C_4C ) )
    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Cabinet ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x80) PORT_DIPLOCATION("SW(A):7,8")
    PORT_DIPSETTING(    0xc0, "Upright 1 Player" )
    PORT_DIPSETTING(    0x80, "Upright 2 Players" )
//  PORT_DIPSETTING(    0x40, DEF_STR( Cocktail ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Cocktail ) )
    /* Debug Dip Switches */
    PORT_DIPNAME( 0x3f, 0x3f, DEF_STR( Free_Play ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):1,2,3,4,5,6")
    PORT_DIPSETTING(    0x3f, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x38, DEF_STR( On ) )
    /* Other values don't give free play */
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Cabinet ) ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, "Upright 1 Player" )
    PORT_DIPSETTING(    0x00, "Upright 2 Players" )
    PORT_DIPNAME( 0x80, 0x80, "Maximum magic/sword power" ) PORT_CONDITION("DSWC", 0x80, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

/* To enable extra choices in the "test mode", you must press "Coin 1" ('5') AND "Service Mode" ('F2') */
static INPUT_PORTS_START( unsquad )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_3( "SW(A)" )
    /* According to the manual, ALL bits 0 to 5 must be ON to have
       "2 Coins/1 Credit (1 to continue)" for both coin slots */
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(A):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x18, 0x18, "Damage" )                    PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x10, "Small" )                 // Check code at 0x006f4e
    PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x08, "Big" )
    PORT_DIPSETTING(    0x00, "Biggest" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )        PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                    PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )      PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )      PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )   PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                  PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END



/* To enable other choices in the "test mode", you must press ("P1 Button 1" ('Ctrl')
   or "P1 Button 2" ('Alt')) when "Service Mode" is ON */
static INPUT_PORTS_START( ffight )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN1")
    PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1) PORT_NAME ("P1 Button 3 (Cheat)")
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2) PORT_NAME ("P2 Button 3 (Cheat)")

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x04, "Difficulty Level 1" )                PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, DEF_STR( Easiest ) )      // "01"
    PORT_DIPSETTING(    0x06, DEF_STR( Easier ) )       // "02"
    PORT_DIPSETTING(    0x05, DEF_STR( Easy ) )         // "03"
    PORT_DIPSETTING(    0x04, DEF_STR( Normal ) )       // "04"
    PORT_DIPSETTING(    0x03, DEF_STR( Medium ) )       // "05"
    PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )         // "06"
    PORT_DIPSETTING(    0x01, DEF_STR( Harder ) )       // "07"
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )      // "08"
    PORT_DIPNAME( 0x18, 0x10, "Difficulty Level 2" )                PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )         // "01"
    PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )       // "02"
    PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )         // "03"
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )      // "04"
    PORT_DIPNAME( 0x60, 0x60, DEF_STR( Bonus_Life ) )               PORT_DIPLOCATION("SW(B):6,7")
    PORT_DIPSETTING(    0x60, "100k" )
    PORT_DIPSETTING(    0x40, "200k" )
    PORT_DIPSETTING(    0x20, "100k and every 200k" )
    PORT_DIPSETTING(    0x00, DEF_STR( None ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x03, "2" )
    PORT_DIPSETTING(    0x02, "3" )
    PORT_DIPSETTING(    0x01, "4" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

static INPUT_PORTS_START( 1941 )
    PORT_INCLUDE( cps1_2b )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x18, 0x18, "Level Up Timer" )                    PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, "More Slowly" )
    PORT_DIPSETTING(    0x10, "Slowly" )
    PORT_DIPSETTING(    0x08, "Quickly" )
    PORT_DIPSETTING(    0x00, "More Quickly" )
    PORT_DIPNAME( 0x60, 0x60, "Bullet's Speed" )                    PORT_DIPLOCATION("SW(B):6,7")
    PORT_DIPSETTING(    0x60, "Very Slow" )
    PORT_DIPSETTING(    0x40, "Slow" )
    PORT_DIPSETTING(    0x20, "Fast" )
    PORT_DIPSETTING(    0x00, "Very Fast" )
    PORT_DIPNAME( 0x80, 0x80, "Initial Vitality" )                  PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x80, "3 Bars" )
    PORT_DIPSETTING(    0x00, "4 Bars" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x01, 0x01, "Throttle Game Speed" )               PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )                      // turning this off will break the game
    PORT_DIPSETTING(    0x01, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

static INPUT_PORTS_START( mercs )
    PORT_INCLUDE( cps1_3players )

    PORT_MODIFY("IN0")
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(A):4" )                  // These three switches are not documented in
    PORT_DIPUNUSED_DIPLOC( 0x10, 0x10, "SW(A):5" )                  // the manual
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(A):6" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )                  // This switch is not documented in the manual

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x08, 0x08, "Coin Slots" )                        PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x08, "3" )                                 // This setting can't be used in two-player mode
    PORT_DIPNAME( 0x10, 0x10, "Play Mode" )                         PORT_DIPLOCATION("SW(B):5")
    PORT_DIPSETTING(    0x00, "2 Players" )
    PORT_DIPSETTING(    0x10, "3 Players" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )                  // These three switches are not documented in
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )                  // the manual
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )                  // These three switches are not documented in
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )                  // the manual
    PORT_DIPUNUSED_DIPLOC( 0x04, 0x04, "SW(C):3" )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_SERVICE_DIPLOC( 0x80, IP_ACTIVE_LOW, "SW(C):8" )
INPUT_PORTS_END

/* According to code at 0x001c4e ('mtwins') or ('chikij') , ALL bits 0 to 5 of DSWA
   must be ON to have "2 Coins/1 Credit (1 to continue)" for both coin slots.
   But according to routine starting at 0x06b27c ('mtwins') or 0x06b4fa ('chikij'),
   bit 6 of DSWA is tested to have the same "feature" in the "test mode".

   Bits 3 and 4 of DSWB affect the number of lives AND the level of damage when you get hit.
   When bit 5 of DSWB is ON you ALWAYS have 1 life but more energy (0x38 instead of 0x20).
   Useful addresses to know :
     - 0xff147b.b : lives  (player 1)
     - 0xff153b.b : lives  (player 2)
     - 0xff14ab.w : energy (player 1)
     - 0xff156b.w : energy (player 2)
*/
INPUT_PORTS_START( mtwins )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(A):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x38, 0x18, DEF_STR( Lives ) )            PORT_DIPLOCATION("SW(B):4,5,6")
//  PORT_DIPSETTING(    0x30, "1" )                         // 0x38 energy, smallest damage
//  PORT_DIPSETTING(    0x38, "1" )                         // 0x38 energy, small damage
//  PORT_DIPSETTING(    0x28, "1" )                         // 0x38 energy, big damage
//  PORT_DIPSETTING(    0x20, "1" )                         // 0x38 energy, biggest damage
    PORT_DIPSETTING(    0x10, "1" )                         // 0x20 energy, smallest damage
    PORT_DIPSETTING(    0x18, "2" )                         // 0x20 energy, small damage
    PORT_DIPSETTING(    0x08, "3" )                         // 0x20 energy, big damage
    PORT_DIPSETTING(    0x00, "4" )                         // 0x20 energy, biggest damage
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )        PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                    PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )      PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )      PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )   PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                  PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END



/* I guess that bit 8 of DSWB was used for debug purpose :
     - code at 0x001094 : move players during "attract mode"
     - code at 0x019b62 ('msword' and 'mswordr1'), 0x019bde ('mswordu') or 0x019c26 ('mswordj') : unknown effect
     - code at 0x01c322 ('msword' and 'mswordr1'), 0x01c39e ('mswordu') or 0x01c3e0 ('mswordj') : unknown effect
   These features are not available because of the 'bra' instruction after the test of bit 7. */
static INPUT_PORTS_START( msword )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )       PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x04, "Player's vitality consumption" )         PORT_DIPLOCATION("SW(B):1,2,3") // "Level 1"
    PORT_DIPSETTING(    0x07, "1 (Easiest)" )                   // "Easy 3"             (-1 every 28 frames)
    PORT_DIPSETTING(    0x06, "2" )                             // "Easy 2"             (-1 every 24 frames)
    PORT_DIPSETTING(    0x05, "3" )                             // "Easy 1"             (-1 every 20 frames)
    PORT_DIPSETTING(    0x04, "4 (Normal)" )                    // DEF_STR( Normal )    (-1 every 18 frames)
    PORT_DIPSETTING(    0x03, "5" )                             // "Difficult 1"        (-1 every 16 frames)
    PORT_DIPSETTING(    0x02, "6" )                             // "Difficult 2"        (-1 every 14 frames)
    PORT_DIPSETTING(    0x01, "7" )                             // "Difficult 3"        (-1 every 12 frames)
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )                   // "Difficult 4"        (-1 every 8 frames)
    PORT_DIPNAME( 0x38, 0x38, "Enemy's vitality and attacking power" )  PORT_DIPLOCATION("SW(B):4,5,6") // "Level 2"
    PORT_DIPSETTING(    0x20, "1 (Easiest)" )                   // "Easy 3"
    PORT_DIPSETTING(    0x28, "2" )                             // "Easy 2"
    PORT_DIPSETTING(    0x30, "3" )                             // "Easy 1"
    PORT_DIPSETTING(    0x38, "4 (Normal)" )                    // DEF_STR( Normal )
    PORT_DIPSETTING(    0x18, "5" )                             // "Difficult 1"
    PORT_DIPSETTING(    0x10, "6" )                             // "Difficult 2"
    PORT_DIPSETTING(    0x08, "7" )                             // "Difficult 3"
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )                   // "Difficult 4"
    PORT_DIPNAME( 0x40, 0x00, "Stage Select" )                          PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, "Vitality Packs" )                        PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "1" )                             // 0x0320
    PORT_DIPSETTING(    0x03, "2" )                             // 0x0640
    PORT_DIPSETTING(    0x02, "3 (2 when continue)" )           // 0x0960 (0x0640 when continue)
    PORT_DIPSETTING(    0x01, "4 (3 when continue)" )           // 0x0c80 (0x0960 when continue)
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                    PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                                PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )                  PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )                  PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )               PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                              PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

static INPUT_PORTS_START( cawing )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )       PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )                          // Overrides all other coinage settings
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )                           // according to manual
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )                      // This switch is not documented

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x04, "Difficulty Level (Enemy's Strength)" )   PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "1 (Easiest)" )
    PORT_DIPSETTING(    0x06, "2" )
    PORT_DIPSETTING(    0x05, "3" )
    PORT_DIPSETTING(    0x04, "4 (Normal)" )
    PORT_DIPSETTING(    0x03, "5" )
    PORT_DIPSETTING(    0x02, "6" )
    PORT_DIPSETTING(    0x01, "7" )
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
    PORT_DIPNAME( 0x18, 0x18, "Difficulty Level (Player's Strength)" )  PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x10, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x18, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )                      // This switch is not documented
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )                      // This switch is not documented
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )                      // This switch is not documented

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )                      // This switch is not documented
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )                      // This switch is not documented
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                    PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                                PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )                  PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )                  PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )               PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                              PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

/* "Debug" features to be implemented */
static INPUT_PORTS_START( nemo )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x18, 0x18, "Life Bar" )                          PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x00, "Minimum" )
    PORT_DIPSETTING(    0x18, DEF_STR( Medium ) )
//  PORT_DIPSETTING(    0x10, DEF_STR( Medium ) )
    PORT_DIPSETTING(    0x08, "Maximum" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x02, "1" )
    PORT_DIPSETTING(    0x03, "2" )
    PORT_DIPSETTING(    0x01, "3" )
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )                 // To enable the "debug" features
INPUT_PORTS_END

INPUT_PORTS_START( sf2 )
    PORT_INCLUDE( cps1_6b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(B):4" )
    PORT_DIPUNUSED_DIPLOC( 0x10, 0x10, "SW(B):5" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( sf2j )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x08, 0x00, "2 Players Game" )                    PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, "1 Credit/No Continue" )
    PORT_DIPSETTING(    0x00, "2 Credits/Winner Continue" ) //Winner stays, loser pays, in other words.
INPUT_PORTS_END

static INPUT_PORTS_START( sf2hack )
    PORT_INCLUDE( parent )

    PORT_MODIFY("IN2")      /* Extra buttons */
    PORT_BIT( 0x00ff, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("P1 Short Kick") PORT_PLAYER(1)
    PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("P1 Forward Kick") PORT_PLAYER(1)
    PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("P1 Roundhouse Kick") PORT_PLAYER(1)
    PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON4 ) PORT_NAME("P2 Short Kick") PORT_PLAYER(2)
    PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_NAME("P2 Forward Kick") PORT_PLAYER(2)
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_NAME("P2 Roundhouse Kick") PORT_PLAYER(2)
    PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

static INPUT_PORTS_START( sf2level )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0xf0, 0xf0, "Level" )  PORT_DIPLOCATION("SW(B):5,6,7,8")
    PORT_DIPSETTING(    0xf0, "0" )
    PORT_DIPSETTING(    0xe0, "1" )
    PORT_DIPSETTING(    0xd0, "2" )
    PORT_DIPSETTING(    0xc0, "3" )
    PORT_DIPSETTING(    0xb0, "4" )
    PORT_DIPSETTING(    0xa0, "5" )
    PORT_DIPSETTING(    0x90, "6" )
    PORT_DIPSETTING(    0x80, "7" )
    PORT_DIPSETTING(    0x70, "8" )
    PORT_DIPSETTING(    0x60, "9" )
    PORT_DIPSETTING(    0x50, "10" )
    PORT_DIPSETTING(    0x40, "11" )
    PORT_DIPSETTING(    0x30, "12" )
    PORT_DIPSETTING(    0x20, "13" )
    PORT_DIPSETTING(    0x10, "14" )
    PORT_DIPSETTING(    0x00, "15" )
INPUT_PORTS_END

static INPUT_PORTS_START( sf2m2 )
    PORT_INCLUDE( sf2hack )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x10, 0x00, "It needs to be High" )                       PORT_DIPLOCATION("SW(B):5")
    PORT_DIPSETTING(    0x10, DEF_STR ( Low ) )
    PORT_DIPSETTING(    0x00, DEF_STR ( High ) )
INPUT_PORTS_END

static INPUT_PORTS_START( sf2m4 )
    PORT_INCLUDE( sf2hack )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x08, 0x00, "2 Players Game" )                    PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, "1 Credit/No Continue" )
    PORT_DIPSETTING(    0x00, "2 Credits/Winner Continue" ) //Winner stays, loser pays, in other words.
INPUT_PORTS_END


/* SWB.4, SWB.5 and SWB.6 need to be enabled simultaneously for turbo mode */
static INPUT_PORTS_START( sf2amf )
    PORT_INCLUDE( sf2hack )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x08, 0x08, "Turbo Mode Switch 1 of 3" )   PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, "Turbo Mode Switch 2 of 3" )   PORT_DIPLOCATION("SW(B):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, "Turbo Mode Switch 3 of 3" )   PORT_DIPLOCATION("SW(B):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

/* SWB.6 enables turbo mode, SWB.4 and SWB.5 sets the speed */
static INPUT_PORTS_START( sf2amfx )
    PORT_INCLUDE( sf2hack )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x18, 0x18, "Game Speed" )   PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, "Normal" )
    PORT_DIPSETTING(    0x10, "Fast" )
    PORT_DIPSETTING(    0x08, "Very Fast" )
    PORT_DIPSETTING(    0x00, "Extremely Fast" )
    PORT_DIPNAME( 0x20, 0x20, "Turbo Mode Enable" )   PORT_DIPLOCATION("SW(B):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )  // normal speed
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )   // the speed set by SWB.4 and SWB.5
INPUT_PORTS_END

static INPUT_PORTS_START( sf2accp2 )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWA")
    PORT_DIPNAME( 0x80, 0x00, "Shot Type" )   PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, "Directional shots curve up or down" )
    PORT_DIPSETTING(    0x00, "3D wave shots slow-med-fast" )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x38, 0x20, "Game speed" )   PORT_DIPLOCATION("SW(B):4,5,6") // Manual has some errors here
    PORT_DIPSETTING(    0x38, "Extremely fast" ) // loop counter 30
    PORT_DIPSETTING(    0x30, "Very fast" ) // loop counter 70
    PORT_DIPSETTING(    0x28, "Fast" ) // loop counter 90
    PORT_DIPSETTING(    0x20, "Normal" ) // loop counter 150
    PORT_DIPSETTING(    0x18, "Slow" ) // loop counter 190
    PORT_DIPSETTING(    0x10, "Very slow" ) // loop counter 230
    PORT_DIPSETTING(    0x00, "Slowest" ) // loop counter 310
    PORT_DIPSETTING(    0x08, "Speed test mode" ) // loop counter 1
    // Manual says: we suggest changing the "Special rapid multiple shots feature on a random basis,
    // never turning on more than 1 at any one time, as this feature will prolong the game time.
    PORT_DIPNAME( 0x40, 0x40, "Guile special rapid multiple shots" )   PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, "Blanka special rapid multiple shots" )   PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_MODIFY("DSWC")
    PORT_DIPNAME( 0x01, 0x01, "Ken special rapid multiple shots" )   PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x00, "Ryu special rapid multiple shots" )   PORT_DIPLOCATION("SW(C):2")
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

INPUT_PORTS_START( sf2bhh )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWC")
    PORT_DIPNAME( 0x01, 0x01, "Turbo Mode" )   PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END

static INPUT_PORTS_START( 3wonders )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" ) PORT_CONDITION("DSWA", 0x3f,NOTEQUALS,0x00) PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Free_Play ) ) PORT_CONDITION("DSWA", 0x3f, EQUALS, 0x00) PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    /* Free Play: ALL bits 0 to 7 must be ON ; 4C_1C, 4C_1C, 2 Coins to Start, 1 to Continue ON */
    PORT_DIPNAME( 0x80, 0x80, "Freeze" )                            PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x03, 0x02, "Lives (Midnight Wanderers)" )        PORT_DIPLOCATION("SW(B):1,2")
    PORT_DIPSETTING(    0x03, "1" )
    PORT_DIPSETTING(    0x02, "2" )
    PORT_DIPSETTING(    0x01, "3" )
    PORT_DIPSETTING(    0x00, "5" )
    PORT_DIPNAME( 0x0c, 0x08, "Difficulty (Midnight Wanderers)" )   PORT_DIPLOCATION("SW(B):3,4")
    PORT_DIPSETTING(    0x0c, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x30, 0x10, "Lives (Chariot)" )                   PORT_DIPLOCATION("SW(B):5,6")
    PORT_DIPSETTING(    0x30, "1" )
    PORT_DIPSETTING(    0x20, "2" )
    PORT_DIPSETTING(    0x10, "3" )
    PORT_DIPSETTING(    0x00, "5" )
    PORT_DIPNAME( 0xc0, 0x80, "Difficulty (Chariot)" )              PORT_DIPLOCATION("SW(B):7,8")
    PORT_DIPSETTING(    0xc0, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x80, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x01, "Lives (Don't Pull)" )                PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x03, "1" )
    PORT_DIPSETTING(    0x02, "2" )
    PORT_DIPSETTING(    0x01, "3" )
    PORT_DIPSETTING(    0x00, "5" )
    PORT_DIPNAME( 0x0c, 0x08, "Difficulty (Don't Pull)" )           PORT_DIPLOCATION("SW(C):3,4")
    PORT_DIPSETTING(    0x0c, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

static INPUT_PORTS_START( kod )
    PORT_INCLUDE( cps1_3players )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPNAME( 0x08, 0x08, "Coin Slots" )                        PORT_DIPLOCATION("SW(A):4")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x08, "3" )
    PORT_DIPNAME( 0x10, 0x10, "Play Mode" )                         PORT_DIPLOCATION("SW(A):5")
    PORT_DIPSETTING(    0x00, "2 Players" )
    PORT_DIPSETTING(    0x10, "3 Players" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(A):6" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x38, 0x38, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(B):4,5,6")
    PORT_DIPSETTING(    0x30, "1" )
    PORT_DIPSETTING(    0x38, "2" )
    PORT_DIPSETTING(    0x28, "3" )
    PORT_DIPSETTING(    0x20, "4" )
    PORT_DIPSETTING(    0x18, "5" )
    PORT_DIPSETTING(    0x10, "6" )
    PORT_DIPSETTING(    0x08, "7" )
    PORT_DIPSETTING(    0x00, "8" )
    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Bonus_Life ) )               PORT_DIPLOCATION("SW(B):7,8")
    PORT_DIPSETTING(    0x80, "80k and every 400k" )
    PORT_DIPSETTING(    0x40, "160k and every 450k" )
    PORT_DIPSETTING(    0xc0, "200k and every 450k" )
    PORT_DIPSETTING(    0x00, DEF_STR( None ) )

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

/* Needs further checking
   Same as kod but different "Bonus_life" values */
static INPUT_PORTS_START( kodr1 )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0xc0, 0xc0, DEF_STR( Bonus_Life ) )               PORT_DIPLOCATION("SW(B):7,8")
    PORT_DIPSETTING(    0x80, "80k and every 400k" )
    PORT_DIPSETTING(    0xc0, "100k and every 450k" )
    PORT_DIPSETTING(    0x40, "160k and every 450k" )
    PORT_DIPSETTING(    0x00, DEF_STR( None ) )
INPUT_PORTS_END


INPUT_PORTS_START( captcomm )
    PORT_INCLUDE( cps1_4players )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(A):4" )                  // The manual says to leave these three
    PORT_DIPUNUSED_DIPLOC( 0x10, 0x10, "SW(A):5" )                  // switches off.  Does turning them on cause
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(A):6" )                  // any "undesirable" behaviour?
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )                  // Unused according to manual

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x04, "Difficulty 1" )                      PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "1 (Easiest)" )
    PORT_DIPSETTING(    0x06, "2" )
    PORT_DIPSETTING(    0x05, "3" )
    PORT_DIPSETTING(    0x04, "4 (Normal)" )
    PORT_DIPSETTING(    0x03, "5" )
    PORT_DIPSETTING(    0x02, "6" )
    PORT_DIPSETTING(    0x01, "7" )
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
    PORT_DIPNAME( 0x18, 0x10, "Difficulty 2" )                      PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )                  // Manual says to leave this switch off.
    PORT_DIPNAME( 0xc0, 0xc0, "Play Mode" )                         PORT_DIPLOCATION("SW(B):7,8")
    PORT_DIPSETTING(    0x40, "1 Players" ) // Actual setting is 4 players
    PORT_DIPSETTING(    0xc0, "2 Players" )
    PORT_DIPSETTING(    0x80, "3 Players" )
    PORT_DIPSETTING(    0x00, "4 Players" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x03, "2" )
    PORT_DIPSETTING(    0x02, "3" )
    PORT_DIPSETTING(    0x01, "4" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

INPUT_PORTS_START( knights )
    PORT_INCLUDE( cps1_3players )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPUNUSED_DIPLOC( 0x08, 0x08, "SW(A):4" )
    PORT_DIPUNUSED_DIPLOC( 0x10, 0x10, "SW(A):5" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(A):6" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x04, "Enemy's attack frequency" )          PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "1 (Easiest)" )
    PORT_DIPSETTING(    0x06, "2" )
    PORT_DIPSETTING(    0x05, "3" )
    PORT_DIPSETTING(    0x04, "4 (Normal)" )
    PORT_DIPSETTING(    0x03, "5" )
    PORT_DIPSETTING(    0x02, "6" )
    PORT_DIPSETTING(    0x01, "7" )
    PORT_DIPSETTING(    0x00, "8 (Hardest)" )
    PORT_DIPNAME( 0x38, 0x38, "Enemy's attack power" )              PORT_DIPLOCATION("SW(B):4,5,6")
    PORT_DIPSETTING(    0x00, "1 (Easiest)" )
    PORT_DIPSETTING(    0x08, "2" )
    PORT_DIPSETTING(    0x10, "3" )
    PORT_DIPSETTING(    0x38, "4 (Normal)" )
    PORT_DIPSETTING(    0x30, "5" )
    PORT_DIPSETTING(    0x28, "6" )
    PORT_DIPSETTING(    0x20, "7" )
    PORT_DIPSETTING(    0x18, "8 (Hardest)" )
    PORT_DIPNAME( 0x40, 0x40, "Coin Slots" )                        PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x40, "3" )
    PORT_DIPNAME( 0x80, 0x80, "Play Mode" )                         PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x00, "2 Players" )
    PORT_DIPSETTING(    0x80, "3 Players" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x03, "2" )
    PORT_DIPSETTING(    0x02, "3" )
    PORT_DIPSETTING(    0x01, "4" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

INPUT_PORTS_START( varth )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_1( "SW(A)" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPNAME( 0x18, 0x10, DEF_STR( Bonus_Life ) )               PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, "600k and every 1.400k" )
    PORT_DIPSETTING(    0x10, "600k 2.000k and 4500k" )
    PORT_DIPSETTING(    0x08, "1.200k 3.500k" )
    PORT_DIPSETTING(    0x00, "2000k only" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPUNUSED_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x02, "1" )
    PORT_DIPSETTING(    0x01, "2" )
    PORT_DIPSETTING(    0x03, "3" )
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( cworld2j )
    PORT_INCLUDE( cps1_quiz )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(A):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(A):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(A):6" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, "Extended Test Mode" )                PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x06, DEF_STR( Difficulty ) )               PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x06, "0" )
    PORT_DIPSETTING(    0x05, "1" )
    PORT_DIPSETTING(    0x04, "2" )
    PORT_DIPSETTING(    0x03, "3" )
    PORT_DIPSETTING(    0x02, "4" )
    PORT_DIPNAME( 0x18, 0x18, "Extend" )                            PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, "N" )
    PORT_DIPSETTING(    0x10, "E" )
    PORT_DIPSETTING(    0x00, "D" )
    PORT_DIPNAME( 0xe0, 0xe0, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(B):6,7,8")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x80, "2" )
    PORT_DIPSETTING(    0xe0, "3" )
    PORT_DIPSETTING(    0xa0, "4" )
    PORT_DIPSETTING(    0xc0, "5" )

    PORT_START("DSWC")
    PORT_DIPUNKNOWN_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNKNOWN_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

    PORT_START("IN2")  /* check code at 0x000614, 0x0008ac and 0x000e36 */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( wof )
    PORT_INCLUDE( cps1_3players )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWB")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_BIT( 0xf7, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("IN3")      /* Player 4 - not used */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

    PORT_START( "EEPROMIN" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

    PORT_START( "EEPROMOUT" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END

INPUT_PORTS_START( dino )
    PORT_INCLUDE( cps1_3players )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWB")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_BIT( 0xf7, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("IN3")      /* Player 4 - not used */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

    PORT_START( "EEPROMIN" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

    PORT_START( "EEPROMOUT" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END


static INPUT_PORTS_START( dinoh )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPNAME( 0x08, 0x08, "Coin Slots" )                PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x00, "1" )
    PORT_DIPSETTING(    0x08, "3" )                 // This setting can't be used in two-player mode
    PORT_DIPNAME( 0x10, 0x10, "Play Mode" )                 PORT_DIPLOCATION("SW(B):5")
    PORT_DIPSETTING(    0x00, "2 Players" )
    PORT_DIPSETTING(    0x10, "3 Players" )
    PORT_DIPUNUSED_DIPLOC( 0x20, 0x20, "SW(A):6" )          // This switch is not documented in the manual
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )       PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )          // This switch is not documented in the manual

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x07, 0x04, "Difficulty Level 1" )            PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, DEF_STR( Easiest ) )          // "01"
    PORT_DIPSETTING(    0x06, DEF_STR( Easier ) )           // "02"
    PORT_DIPSETTING(    0x05, DEF_STR( Easy ) )         // "03"
    PORT_DIPSETTING(    0x04, DEF_STR( Normal ) )           // "04"
    PORT_DIPSETTING(    0x03, DEF_STR( Medium ) )           // "05"
    PORT_DIPSETTING(    0x02, DEF_STR( Hard ) )         // "06"
    PORT_DIPSETTING(    0x01, DEF_STR( Harder ) )           // "07"
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )          // "08"
    PORT_DIPNAME( 0x18, 0x10, "Difficulty Level 2" )            PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )         // "01"
    PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )           // "02"
    PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )         // "03"
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )          // "04"
    PORT_DIPNAME( 0x60, 0x40, DEF_STR( Bonus_Life ) )           PORT_DIPLOCATION("SW(B):6,7")
    PORT_DIPSETTING(    0x60, "300k and 700k" )
    PORT_DIPSETTING(    0x40, "500k and 1000k" )
    PORT_DIPSETTING(    0x20, "1000k" )
    PORT_DIPSETTING(    0x00, DEF_STR( None ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_MODIFY("DSWC")
    PORT_DIPNAME( 0x03, 0x02, DEF_STR( Lives ) )                PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPSETTING(    0x01, "3" )
    PORT_DIPSETTING(    0x02, "2" )
    PORT_DIPSETTING(    0x03, "1" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )            PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                    PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )          PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )          PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                  PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

    PORT_MODIFY("IN1")
    PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
    PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
    PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
    PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
    PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
    PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_MODIFY("IN2")      /* Player 3 */
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(3)
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(3)
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN ) PORT_8WAY PORT_PLAYER(3)
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP ) PORT_8WAY PORT_PLAYER(3)
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(3)
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(3)
//  PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 )
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START3 )
INPUT_PORTS_END

INPUT_PORTS_START( punisher )
    PORT_INCLUDE( cps1_2b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWB")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_BIT( 0xf7, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("IN2")      /* Player 3 - not used */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

    PORT_START("IN3")      /* Player 4 - not used */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

    PORT_START( "EEPROMIN" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

    PORT_START( "EEPROMOUT" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END


static INPUT_PORTS_START( punisherbz )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPNAME( 0x08, 0x08, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x30, 0x20, DEF_STR( Lives ) )            PORT_DIPLOCATION("SW(A):5,6")
    PORT_DIPSETTING(    0x30, "1" )
    PORT_DIPSETTING(    0x20, "2" )
    PORT_DIPSETTING(    0x10, "3" )
    PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPNAME( 0x40, 0x40, "Sound" )             PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, "Q Sound" )
    PORT_DIPSETTING(    0x00, "Monaural" )
    PORT_DIPNAME( 0x80, 0x80, DEF_STR( Flip_Screen ) )      PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x07, 0x04, DEF_STR( Difficulty ) )       PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "Extra Easy" )
    PORT_DIPSETTING(    0x06, DEF_STR( Very_Easy) )
    PORT_DIPSETTING(    0x05, DEF_STR( Easy) )
    PORT_DIPSETTING(    0x04, DEF_STR( Normal) )
    PORT_DIPSETTING(    0x03, DEF_STR( Hard) )
    PORT_DIPSETTING(    0x02, DEF_STR( Very_Hard) )
    PORT_DIPSETTING(    0x01, "Extra Hard" )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest) )
    PORT_DIPNAME( 0x18, 0x10, "Extend" )                PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, "800000" )
    PORT_DIPSETTING(    0x10, "1800000" )
    PORT_DIPSETTING(    0x08, "2800000" )
    PORT_DIPSETTING(    0x00, "No Extend" )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Allow_Continue ) )       PORT_DIPLOCATION("SW(B):6")
    PORT_DIPSETTING(    0x20, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Demo_Sounds ) )      PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_MODIFY("DSWC")
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_MODIFY("IN1")
    PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
    PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
    PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
    PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT  ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN  ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP    ) PORT_8WAY PORT_PLAYER(2)
    PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2)
    PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(2)
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
    PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

/* Needs further checking */
INPUT_PORTS_START( slammast )
    PORT_INCLUDE( cps1_4players )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_MODIFY("IN1")
    PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
    PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(3)
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)
    PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(4)

    PORT_START("DSWA")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWB")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_BIT( 0xf7, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START( "EEPROMIN" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

    PORT_START( "EEPROMOUT" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( pnickj )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPNAME( 0x08, 0x08, "Coin Slots" )                PORT_DIPLOCATION("SW(A):4")
    PORT_DIPSETTING(    0x08, "1" )
    PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(A):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(A):6" )
    PORT_DIPUNKNOWN_DIPLOC( 0x40, 0x40, "SW(A):7" )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(B):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(B):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPNAME( 0xc0, 0xc0, "Vs Play Mode" )              PORT_DIPLOCATION("SW(B):7,8")
    PORT_DIPSETTING(    0xc0, "1 Game Match" )
    PORT_DIPSETTING(    0x80, "3 Games Match" )
    PORT_DIPSETTING(    0x40, "5 Games Match" )
    PORT_DIPSETTING(    0x00, "7 Games Match" )

    PORT_START("DSWC")
    PORT_DIPUNKNOWN_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNKNOWN_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPUNKNOWN_DIPLOC( 0x04, 0x04, "SW(C):3" )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                    PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )      PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )      PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x40, 0x40, "SW(C):7" )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                  PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( qad )
    PORT_INCLUDE( cps1_quiz )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(A):4" )                 // Manual says these are for coin 2, but they
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(A):5" )                 // coin to setting, but they clearly don't do
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(A):6" )                 // that.
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x04, DEF_STR( Difficulty ) )               PORT_DIPLOCATION("SW(B):1,2,3")
//  PORT_DIPSETTING(    0x07, DEF_STR( Easiest ) )                  // Controls overall difficulty
    PORT_DIPSETTING(    0x06, DEF_STR( Easiest ) )                  // Manual documents duplicate settings
    PORT_DIPSETTING(    0x05, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x03, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x02, DEF_STR( Hardest ) )
//  PORT_DIPSETTING(    0x01, DEF_STR( Hardest ) )
//  PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x18, 0x10, "Wisdom (questions to win game)" )    PORT_DIPLOCATION("SW(B):4,5")
    PORT_DIPSETTING(    0x18, DEF_STR( Easy ) )                     // Controls number of needed questions to finish
    PORT_DIPSETTING(    0x10, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x08, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0xe0, 0xe0, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(B):6,7,8")
    PORT_DIPSETTING(    0x60, "1" )
    PORT_DIPSETTING(    0x80, "2" )
    PORT_DIPSETTING(    0xa0, "3" )
    PORT_DIPSETTING(    0xc0, "4" )
    PORT_DIPSETTING(    0xe0, "5" )
//  PORT_DIPSETTING(    0x40, "1" )                                 // These three settings are not documented
//  PORT_DIPSETTING(    0x20, "1" )
//  PORT_DIPSETTING(    0x00, "1" )

    PORT_START("DSWC")
    PORT_DIPUNUSED_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPUNUSED_DIPLOC( 0x02, 0x02, "SW(C):2" )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x20, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

    PORT_START("IN2")  /* check code at 0x01d2d2 */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( qadjr )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x07, 0x07, DEF_STR( Difficulty ) )               PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "0" )
    PORT_DIPSETTING(    0x06, "1" )
    PORT_DIPSETTING(    0x05, "2" )
    PORT_DIPSETTING(    0x04, "3" )
    PORT_DIPSETTING(    0x03, "4" )
//  PORT_DIPSETTING(    0x02, "4" )
//  PORT_DIPSETTING(    0x01, "4" )
//  PORT_DIPSETTING(    0x00, "4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(B):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(B):5" )
    PORT_DIPNAME( 0xe0, 0xe0, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(B):6,7,8")
    PORT_DIPSETTING(    0xa0, "1" )
    PORT_DIPSETTING(    0xc0, "2" )
    PORT_DIPSETTING(    0xe0, "3" )
//  PORT_DIPSETTING(    0x00, "1" )
//  PORT_DIPSETTING(    0x20, "1" )
//  PORT_DIPSETTING(    0x80, "1" )
//  PORT_DIPSETTING(    0x40, "2" )
//  PORT_DIPSETTING(    0x60, "3" )

    PORT_MODIFY("IN2")  /* check code at 0x000c48 */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("IN3")  /* check code at 0x000c3e */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( qtono2j )
    PORT_INCLUDE( cps1_quiz )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    CPS1_COINAGE_2( "SW(A)" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(A):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(A):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(A):6" )
    PORT_DIPNAME( 0x40, 0x40, "2 Coins to Start, 1 to Continue" )   PORT_DIPLOCATION("SW(A):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    CPS1_DIFFICULTY_1( "SW(B)" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(B):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(B):5" )
    PORT_DIPNAME( 0xe0, 0xe0, DEF_STR( Lives ) )                    PORT_DIPLOCATION("SW(B):6,7,8")
    PORT_DIPSETTING(    0x60, "1" )
    PORT_DIPSETTING(    0x80, "2" )
    PORT_DIPSETTING(    0xe0, "3" )
    PORT_DIPSETTING(    0xa0, "4" )
    PORT_DIPSETTING(    0xc0, "5" )
//  PORT_DIPSETTING(    0x40, "?" )
//  PORT_DIPSETTING(    0x20, "?" )
//  PORT_DIPSETTING(    0x00, "?" )

    PORT_START("DSWC")
    PORT_DIPUNKNOWN_DIPLOC( 0x01, 0x01, "SW(C):1" )
    PORT_DIPNAME( 0x02, 0x02, "Infinite Lives (Cheat)")             PORT_DIPLOCATION("SW(C):2")
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Free_Play ) )                PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )                            PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x00, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x40, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )

    PORT_START("IN2")  /* check code at 0x000f80 */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("IN3")  /* check code at 0x000f76 */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( pang3 )
    // Though service mode shows diagonal inputs, the flyer and manual both specify 4-way joysticks
    PORT_INCLUDE( cps1_2b_4way )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    // As manual states, "Push 2 is not used," and is not even shown in service mode
    PORT_MODIFY("IN1")
    PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1) PORT_NAME("P1 Shot")
    PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(2) PORT_NAME("P2 Shot")
    PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWA")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWB")      /* (not used, EEPROM) */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWC")
    PORT_DIPUNUSED( 0x01, 0x01 )
    PORT_DIPUNUSED( 0x02, 0x02 )
    PORT_DIPUNUSED( 0x04, 0x04 )
    PORT_DIPUNUSED( 0x08, 0x08 )
    PORT_DIPUNUSED( 0x10, 0x10 )
    PORT_DIPUNUSED( 0x20, 0x20 )
    PORT_DIPUNUSED( 0x40, 0x40 )
    PORT_DIPUNUSED( 0x80, 0x80 ) /* doubles up as an extra service switch */

    PORT_START( "EEPROMIN" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)

    PORT_START( "EEPROMOUT" )
    PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
    PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
    PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( pang3b )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWC")
    PORT_DIPUNUSED( 0x01, 0x01 )
    PORT_DIPUNUSED( 0x02, 0x02 )
    PORT_DIPUNUSED( 0x04, 0x04 )
    PORT_DIPNAME( 0x08, 0x08, "Freeze" )
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPUNUSED( 0x10, 0x10 )
    PORT_DIPUNUSED( 0x20, 0x20 )
    PORT_DIPUNUSED( 0x40, 0x40 )
    PORT_DIPUNUSED( 0x80, 0x80 )
INPUT_PORTS_END

/* Needs further checking */
static INPUT_PORTS_START( megaman )
    PORT_INCLUDE( cps1_3b )

    PORT_MODIFY("IN0")
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )

    PORT_START("DSWA")
    PORT_DIPNAME( 0x1f, 0x1f, DEF_STR( Coinage ) )                  PORT_DIPLOCATION("SW(A):1,2,3,4,5")
    PORT_DIPSETTING(    0x0f, DEF_STR( 9C_1C ) )
    PORT_DIPSETTING(    0x10, DEF_STR( 8C_1C ) )
    PORT_DIPSETTING(    0x11, DEF_STR( 7C_1C ) )
    PORT_DIPSETTING(    0x12, DEF_STR( 6C_1C ) )
    PORT_DIPSETTING(    0x13, DEF_STR( 5C_1C ) )
    PORT_DIPSETTING(    0x14, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x15, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x16, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x0e, "2 Coins to Start, 1 to Continue" )
    PORT_DIPSETTING(    0x1f, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x1e, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x1d, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x1c, DEF_STR( 1C_4C ) )
    PORT_DIPSETTING(    0x1b, DEF_STR( 1C_5C ) )
    PORT_DIPSETTING(    0x1a, DEF_STR( 1C_6C ) )
    PORT_DIPSETTING(    0x19, DEF_STR( 1C_7C ) )
    PORT_DIPSETTING(    0x18, DEF_STR( 1C_8C ) )
    PORT_DIPSETTING(    0x17, DEF_STR( 1C_9C ) )
    PORT_DIPSETTING(    0x0d, DEF_STR( Free_Play ) )
    /* 0x00 to 0x0c 1 Coin/1 Credit */
    PORT_DIPNAME( 0x60, 0x60, "Coin slots" )                        PORT_DIPLOCATION("SW(A):6,7")
//  PORT_DIPSETTING(    0x00, "Invalid" )
    PORT_DIPSETTING(    0x20, "1, Common" )
    PORT_DIPSETTING(    0x60, "2, Common" )
    PORT_DIPSETTING(    0x40, "2, Individual" )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x80, "SW(A):8" )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x03, 0x02, DEF_STR( Difficulty ) )               PORT_DIPLOCATION("SW(B):1,2")
    PORT_DIPSETTING(    0x03, DEF_STR( Easy ) )
    PORT_DIPSETTING(    0x02, DEF_STR( Normal ) )
    PORT_DIPSETTING(    0x01, DEF_STR( Hard ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest ) )
    PORT_DIPNAME( 0x0c, 0x0c, "Time" )                              PORT_DIPLOCATION("SW(B):3,4")
    PORT_DIPSETTING(    0x0c, "100" )
    PORT_DIPSETTING(    0x08, "90" )
    PORT_DIPSETTING(    0x04, "70" )
    PORT_DIPSETTING(    0x00, "60" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(B):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPNAME( 0x40, 0x40, "Voice" )                             PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x40, DEF_STR( On ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x01, 0x01, DEF_STR( Flip_Screen ) )              PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x02, DEF_STR( Demo_Sounds ) )              PORT_DIPLOCATION("SW(C):2")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x02, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Allow_Continue ) )           PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x00, DEF_STR( No ) )
    PORT_DIPSETTING(    0x04, DEF_STR( Yes ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(C):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(C):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(C):6" )
    PORT_DIPUNKNOWN_DIPLOC( 0x40, 0x40, "SW(C):7" )
    PORT_DIPNAME( 0x80, 0x80, "Game Mode")                          PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, "Game" )
    PORT_DIPSETTING(    0x00, DEF_STR( Test ) )
INPUT_PORTS_END

/* Needs further checking */
/* Same as 'megaman' but no "Voice" Dip Switch */
static INPUT_PORTS_START( rockmanj )
    PORT_INCLUDE( parent)

    PORT_MODIFY("DSWB")
    PORT_DIPUNKNOWN_DIPLOC( 0x40, 0x40, "SW(B):7" )
INPUT_PORTS_END

static INPUT_PORTS_START( wofhfh )
    PORT_INCLUDE( parent )

    PORT_MODIFY("DSWA")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Coin_A ) )           PORT_DIPLOCATION("SW(A):1,2")
    PORT_DIPSETTING(    0x03, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x02, DEF_STR( 1C_2C ) )
    PORT_DIPSETTING(    0x01, DEF_STR( 1C_3C ) )
    PORT_DIPSETTING(    0x00, DEF_STR( 1C_4C ) )
    PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_MODIFY("DSWB")
    PORT_DIPNAME( 0x07, 0x04, DEF_STR( Difficulty ) )       PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x07, "Extra Easy" )
    PORT_DIPSETTING(    0x06, DEF_STR( Very_Easy) )
    PORT_DIPSETTING(    0x05, DEF_STR( Easy) )
    PORT_DIPSETTING(    0x04, DEF_STR( Normal) )
    PORT_DIPSETTING(    0x03, DEF_STR( Hard) )
    PORT_DIPSETTING(    0x02, DEF_STR( Very_Hard) )
    PORT_DIPSETTING(    0x01, "Extra Hard" )
    PORT_DIPSETTING(    0x00, DEF_STR( Hardest) )
    PORT_DIPNAME( 0x70, 0x60, DEF_STR( Lives ) )            PORT_DIPLOCATION("SW(B):4,5,6")
    PORT_DIPSETTING(    0x00, "Start 4 Continue 5" )
    PORT_DIPSETTING(    0x10, "Start 3 Continue 4" )
    PORT_DIPSETTING(    0x20, "Start 2 Continue 3" )
    PORT_DIPSETTING(    0x30, "Start 1 Continue 2" )
    PORT_DIPSETTING(    0x40, "Start 4 Continue 4" )
    PORT_DIPSETTING(    0x50, "Start 3 Continue 3" )
    PORT_DIPSETTING(    0x60, "Start 2 Continue 2" )
    PORT_DIPSETTING(    0x70, "Start 1 Continue 1" )
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_MODIFY("DSWC")
    PORT_DIPNAME( 0x03, 0x03, "Coin Slots" )            PORT_DIPLOCATION("SW(C):1,2")
//  PORT_DIPSETTING(    0x00, "2 Players 1 Shooter" )
    PORT_DIPSETTING(    0x01, "2 Players 1 Shooter" )
    PORT_DIPSETTING(    0x02, "3 Players 1 Shooter" )
    PORT_DIPSETTING(    0x03, "3 Players 3 Shooters" )
    PORT_BIT( 0xfc, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_MODIFY("IN1")
    PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(1)
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 ) PORT_PLAYER(2)

    PORT_MODIFY("IN2")      /* Player 3 */
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN3 ) PORT_NAME("Coin 3 (P3 Button 3 in-game)")
INPUT_PORTS_END

static INPUT_PORTS_START( ganbare )
    PORT_INCLUDE( ports_ganbare )
    PORT_START("IN0")
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 ) /* definitely read here in test mode, coin lock prevents it though */
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1 )
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2 )
    PORT_SERVICE_NO_TOGGLE( 0x40, IP_ACTIVE_LOW )
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("IN1")
    PORT_BIT( 0x0001, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0002, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT ) PORT_8WAY PORT_PLAYER(1)
    PORT_BIT( 0x0004, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0008, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0010, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_PLAYER(1)
    PORT_BIT( 0x0020, IP_ACTIVE_LOW, IPT_BUTTON2 ) PORT_PLAYER(1)
    PORT_BIT( 0x0040, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0080, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_UNKNOWN )
    PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_UNKNOWN )

    PORT_START("DSWA")
    PORT_DIPNAME( 0x01, 0x01, "Medal Setup" )                   PORT_DIPLOCATION("SW(A):1")
    PORT_DIPSETTING(    0x01, "1 Medal 1 Credit" )
    PORT_DIPSETTING(    0x00, "Don't use" )
    PORT_DIPNAME( 0x02, 0x02, "Coin Setup" )                    PORT_DIPLOCATION("SW(A):2")
    PORT_DIPSETTING(    0x02, "100 Yen" )
    PORT_DIPSETTING(    0x00, "10 Yen" )
    PORT_DIPNAME( 0x1c, 0x1c, "Change Setup" )                  PORT_DIPLOCATION("SW(A):3,4,5")
    PORT_DIPSETTING(    0x04, "12" )
    PORT_DIPSETTING(    0x00, "11" )
    PORT_DIPSETTING(    0x1c, "10" )
    PORT_DIPSETTING(    0x18, "8" )
    PORT_DIPSETTING(    0x14, "7" )
    PORT_DIPSETTING(    0x10, "6" )
    PORT_DIPSETTING(    0x0c, "5" )
    PORT_DIPSETTING(    0x08, "No change" )
    PORT_DIPNAME( 0x60, 0x60, "10 Yen Setup" )                  PORT_DIPLOCATION("SW(A):6,7")
    PORT_DIPSETTING(    0x60, DEF_STR( 1C_1C ) )
    PORT_DIPSETTING(    0x40, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x20, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x00, "Don't use" )
    PORT_DIPNAME( 0x80, 0x80, "Payout Setup" )                  PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, "Credit Mode" )
    PORT_DIPSETTING(    0x00, "Payout Mode" )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x07, 0x07, "Payout Rate Setup" )             PORT_DIPLOCATION("SW(B):1,2,3")
    PORT_DIPSETTING(    0x01, "90%" )
    PORT_DIPSETTING(    0x00, "85%" )
    PORT_DIPSETTING(    0x07, "80%" )
    PORT_DIPSETTING(    0x06, "75%" )
    PORT_DIPSETTING(    0x05, "70%" )
    PORT_DIPSETTING(    0x04, "65%" )
    PORT_DIPSETTING(    0x03, "60%" )
    PORT_DIPSETTING(    0x02, "55%" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(B):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(B):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(B):6" )
    PORT_DIPUNKNOWN_DIPLOC( 0x40, 0x40, "SW(B):7" )
    PORT_DIPUNKNOWN_DIPLOC( 0x80, 0x80, "SW(B):8" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Demo_Sounds ) )          PORT_DIPLOCATION("SW(C):1,2")
    PORT_DIPSETTING(    0x03, DEF_STR( On ) )
    PORT_DIPSETTING(    0x02, "Every second sound" )
    PORT_DIPSETTING(    0x01, "Every third sound" )
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPUNKNOWN_DIPLOC( 0x04, 0x04, "SW(C):3" )
    PORT_DIPUNKNOWN_DIPLOC( 0x08, 0x08, "SW(C):4" )
    PORT_DIPUNKNOWN_DIPLOC( 0x10, 0x10, "SW(C):5" )
    PORT_DIPUNKNOWN_DIPLOC( 0x20, 0x20, "SW(C):6" )
    PORT_DIPNAME( 0x40, 0x40, "Clear RAM" )                     PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( No ) )
    PORT_DIPSETTING(    0x00, DEF_STR( Yes ) )
    PORT_DIPNAME( 0x80, 0x80, "Tes Mode Display" )              PORT_DIPLOCATION("SW(C):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
INPUT_PORTS_END


static INPUT_PORTS_START( sfzch )
    PORT_INCLUDE( ports_sfzch )
    PORT_START("IN0")     /* IN0 */
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON5) PORT_PLAYER(1)
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5) PORT_PLAYER(2)
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE) PORT_NAME(DEF_STR(Pause)) PORT_CODE(KEYCODE_F1) /* pause */
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE  )   /* pause */
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START1)
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START2)
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6) PORT_PLAYER(1)
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON6) PORT_PLAYER(2)

    PORT_START("DSWA")
    PORT_DIPNAME( 0xff, 0xff, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0xff, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START("DSWB")
    PORT_DIPNAME( 0xff, 0xff, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0xff, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START("DSWC")
    PORT_DIPNAME( 0xff, 0xff, DEF_STR( Unknown ) )
    PORT_DIPSETTING(    0xff, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START("IN1")     /* Player 1 & 2 */
    PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_PLAYER(1) PORT_8WAY
    PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_PLAYER(1) PORT_8WAY
    PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_PLAYER(1) PORT_8WAY
    PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_PLAYER(1) PORT_8WAY
    PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1) PORT_PLAYER(1)
    PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2) PORT_PLAYER(1)
    PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3) PORT_PLAYER(1)
    PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4) PORT_PLAYER(1)
    PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT) PORT_PLAYER(2) PORT_8WAY
    PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT) PORT_PLAYER(2) PORT_8WAY
    PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN) PORT_PLAYER(2) PORT_8WAY
    PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP) PORT_PLAYER(2) PORT_8WAY
    PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1) PORT_PLAYER(2)
    PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2) PORT_PLAYER(2)
    PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3) PORT_PLAYER(2)
    PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON4) PORT_PLAYER(2)

    PORT_START("IN2")      /* Read by wofch */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

    PORT_START("IN3")      /* Player 4 - not used */
    PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

INPUT_PORTS_END

// static INPUT_PORTS_START( wofch )
//     PORT_INCLUDE( sfzch )
// 
//     PORT_START( "EEPROMIN" )
//     PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, do_read)
// 
//     PORT_START( "EEPROMOUT" )
//     PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, di_write)
//     PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, clk_write)
//     PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_93cxx_device, cs_write)
// INPUT_PORTS_END

static INPUT_PORTS_START( pokonyan )
    PORT_INCLUDE( cps1_3b )

    PORT_START("DSWA")
    PORT_DIPNAME( 0x03, 0x02, DEF_STR( Coinage ) ) PORT_DIPLOCATION("SW(A):1,2")
    PORT_DIPSETTING(    0x00, DEF_STR( 4C_1C ) )
    PORT_DIPSETTING(    0x01, DEF_STR( 3C_1C ) )
    PORT_DIPSETTING(    0x03, DEF_STR( 2C_1C ) )
    PORT_DIPSETTING(    0x02, DEF_STR( 1C_1C ) )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(A):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(A):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(A):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(A):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x00, DEF_STR( Unknown ) ) PORT_DIPLOCATION("SW(A):7") // not listed in service mode, but left/right don't seem to work otherwise? maybe tied to some cabinet sensor?
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(A):8")
    PORT_DIPSETTING(    0x80, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )

    PORT_START("DSWB")
    PORT_DIPNAME( 0x03, 0x03, DEF_STR( Demo_Sounds ) ) PORT_DIPLOCATION("SW(B):1,2")
    PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x01, "Every 4" )
    PORT_DIPSETTING(    0x02, "Every 2" )
    PORT_DIPSETTING(    0x03, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x00, "Prize Mode" ) PORT_DIPLOCATION("SW(B):3")
    PORT_DIPSETTING(    0x00, "Not Used" )
    PORT_DIPSETTING(    0x04, "Used" )
    PORT_DIPNAME( 0x08, 0x08, "Credit Mode" ) PORT_DIPLOCATION("SW(B):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, "Max Stage" ) PORT_DIPLOCATION("SW(B):5")
    PORT_DIPSETTING(    0x00, "2" )
    PORT_DIPSETTING(    0x10, "3" )
    PORT_DIPNAME( 0x20, 0x20, "Card Check" ) PORT_DIPLOCATION("SW(B):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(B):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x80, 0x80, DEF_STR( Unused ) ) PORT_DIPLOCATION("SW(B):8")
    PORT_DIPSETTING(    0x00, "1.0 sec" )
    PORT_DIPSETTING(    0x80, "1.2 sec" )

    PORT_START("DSWC")
    PORT_DIPNAME( 0x01, 0x01, DEF_STR( Unknown ) ) PORT_DIPLOCATION("SW(C):1")
    PORT_DIPSETTING(    0x01, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x02, 0x02, "Body Check") PORT_DIPLOCATION("SW(C):2")
    PORT_DIPSETTING(    0x02, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x04, 0x04, DEF_STR( Unknown ) ) PORT_DIPLOCATION("SW(C):3")
    PORT_DIPSETTING(    0x04, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x08, 0x08, "Screen Stop" ) PORT_DIPLOCATION("SW(C):4")
    PORT_DIPSETTING(    0x08, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x10, 0x10, DEF_STR( Flip_Screen ) ) PORT_DIPLOCATION("SW(C):5")
    PORT_DIPSETTING(    0x10, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x20, 0x20, DEF_STR( Unknown ) ) PORT_DIPLOCATION("SW(C):6")
    PORT_DIPSETTING(    0x20, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_DIPNAME( 0x40, 0x40, DEF_STR( Unknown ) ) PORT_DIPLOCATION("SW(C):7")
    PORT_DIPSETTING(    0x40, DEF_STR( Off ) )
    PORT_DIPSETTING(    0x00, DEF_STR( On ) )
    PORT_SERVICE_DIPLOC( 0x80, IP_ACTIVE_LOW, "SW(C):8" )
INPUT_PORTS_END
