#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <mamegame.hpp>

#include "config.h"
#include "dips.h"

using namespace std;

bool verbose=false;

void xml_element( stringstream& of, const char *name, const string &content, int tab) {
    while( tab-- ) of << "    ";
    of << "<" << name << ">" << content << "</" << name << ">\n";
}

struct size_map{
    int cpu, sound, oki, gfx, qsound;
};

void dump_region( stringstream& of, const tiny_rom_entry *entry, const string& region, int bits, int swap, int min_length=0 ) {
    int length=0;
    while( !(entry->flags&ROMENTRYTYPE_END) ) {
        //if( entry->name != nullptr ) cout << "region=" << entry->name << '\n';
        if( entry->flags & ROMENTRYTYPE_REGION ) {
            if( region == entry->name ) {
                const char *indent="        ";
                of << indent << "<!-- " << region << " -->\n";
                if( entry->flags&ROMREGION_ERASEMASK ) {
                    of << indent << "<part repeat=\"0x";
                    of << hex << entry->length << "\">" << dec;
                    int erase = entry->flags&ROMREGION_ERASEVALMASK;
                    erase >>= 16;
                    erase &=0xff;
                    of << hex << uppercase << erase << "</part>\n";
                    of << dec;
                    return;
                }
                ++entry;
                int done=0;
                while( !(entry->flags&ROMENTRYTYPE_REGION) && !(entry->flags&ROMENTRYTYPE_END)) {
                    if( entry->name ) { // avoid the ROM_CONTINUE case
                        int file_width = (entry->flags & ROM_GROUPMASK) >> 7;
                        if(file_width==0) file_width=1;
                        of << indent;
                        if(verbose) cout << entry->name << ' ';
                        if( bits==8 ) {
                            of << "<part name=\"" << entry->name << "\" ";
                            of << "crc=\"" << entry->hashdata << "\"/>\n";
                        }
                        if( bits==16 ) {
                            if( file_width==1 ) {
                                const tiny_rom_entry* cur= entry;
                                // For swapped ROMs the map content (01 or 10)
                                // does not match the file order. That is
                                // ok with MiSTer but not with the MiST mra tool
                                // thus the little pointer arithmetic needed.
                                if( swap ) {
                                    if( done==0 )
                                        cur++;
                                    else
                                        cur--;
                                }
                                if( done==0 ) {
                                    of << "<interleave output=\""<<bits<<"\">\n";
                                    of << indent;
                                }
                                of << "    ";
                                of << "<part name=\"" << cur->name << "\" ";
                                of << "crc=\"" << cur->hashdata << "\" map=\"";
                                if(done==0) {
                                    of << "01\"";
                                }
                                else {
                                    of << "10\"";
                                }
                                of << "/>\n";
                                done+=file_width;
                                if( done==(bits>>3) ) {
                                    of << indent << "</interleave>\n";
                                    done=0;
                                }
                            }
                            if( file_width==2 ) {
                                of << "<interleave output=\"16\">\n";
                                of << indent << "    <part name=\"" << entry->name << "\" ";
                                of << "crc=\"" << entry->hashdata << "\"";
                                int file_swap = (entry->flags & ROM_REVERSE)!=0;
                                if( swap != file_swap )
                                    of << " map=\"12\"/>\n";
                                else
                                    of << " map=\"21\"/>\n";
                                of << indent << "</interleave>\n";
                            }
                        }
                        if( bits==64 ) {
                            if( done==0 ) {
                                of << "<interleave output=\""<<bits<<"\">\n";
                                of << indent;
                            }
                            of << "    ";
                            of << "<part name=\"" << entry->name << "\" ";
                            of << "crc=\"" << entry->hashdata << "\" ";
                            of << " map=\"";
                            if( file_width==2 ) {
                                for( int k=done;k<6;k++ ) of << '0';
                                of << "21";
                                for( int k=done;k>0;k--) of << '0';
                            }
                            else {
                                for( int k=done;k<7;k++ ) of << '0';
                                of << '1';
                                for( int k=done;k>0;k--) of << '0';
                            }
                            of << '\"';
                            of << "/>\n";
                            done+=file_width;
                            if( done==(bits>>3) ) {
                                of << indent << "</interleave>\n";
                                done=0;
                            }
                        }
                    }
                    length += entry->length;
                    entry++;
                }
                if(verbose) cout <<  " - " << length << " - " << min_length << '\n';
                if( length < min_length ) {
                    // used to ensure that each ROM section falls where it should
                    of << "       <part repeat=\"0x" << hex << (min_length-length) << "\">FF</part>\n" << dec;
                }
                return;
            }
        }
        entry++;
    }
    throw region;
}

int size_region( const tiny_rom_entry *entry, const string& region, int min_length=0 ) {
    int length=0;
    while( !(entry->flags&ROMENTRYTYPE_END) ) {
        //if( entry->name != nullptr ) cout << "region=" << entry->name << '\n';
        if( entry->flags & ROMENTRYTYPE_REGION ) {
            if( region == entry->name ) {
                ++entry;
                int done=0;
                while( !(entry->flags&ROMENTRYTYPE_REGION) && !(entry->flags&ROMENTRYTYPE_END)) {
                    length += entry->length;
                    entry++;
                }
                if( length < min_length ) length = min_length;
                return length;
            }
        }
        entry++;
    }
    return 0;   // the region was not found
}

#define DUMP(a) of << hex << uppercase << setw(2) << setfill('0') << ((a)&0xff) << ' '; \
    sim_cfg[dumpcnt] = a; dumpcnt++;

int find_cfg( const string& name, stringstream *of=nullptr ) {
    int k=0;
    while( cps1_config_table[k].name != nullptr ) {
        if( name == cps1_config_table[k].name ) return k;
        k++;
    }
    if( of ) (*of) << "ERROR: cannot find game " << name << '\n';
    cout << "ERROR: cannot find game " << name << '\n';
    return -1;
}

int generate_cpsb(stringstream& of, int *sim_cfg, const CPS1config* x) {
    of << "        <!-- CPS-B config for " << x->name << " --> \n";
    of << "        <part> ";
    int dumpcnt=0;
    DUMP( x->cpsb_addr );
    DUMP( (x->cpsb_value>>4) | (x->cpsb_value&0xf) );
    DUMP( x->mult_factor1    );
    DUMP( x->mult_factor2    );
    DUMP( x->mult_result_lo  );
    DUMP( x->mult_result_hi  );
    DUMP( x->layer_control   );
    DUMP( x->priority[0]     );
    DUMP( x->priority[1]     );
    DUMP( x->priority[2]     );
    DUMP( x->priority[3]     );
    DUMP( x->in2_addr        );
    DUMP( x->in3_addr        );
    DUMP( x->palette_control );
    DUMP( x->layer_enable_mask[0] );
    DUMP( x->layer_enable_mask[1] );
    DUMP( x->layer_enable_mask[2] );
    DUMP( x->layer_enable_mask[3] );
    of << "</part>\n";
    return dumpcnt;
}

// SCR1      1'b0, code[15:...]
// SCR2/OBJ  code[15:...]
// SCR3      code[13:..]

void output_range( stringstream& ss, const char *layer, const char *layer_bits,
    int min, int max, const gfx_range *r, bool& addor, const char *extra="" ) {
        if(addor) ss << "\n        || ";
        ss << " ( layer==" << layer << " ";
        if( min!=0 ) {
            ss << " &&";
            ss << " code[" << layer_bits << "]>=7'h" << hex << min;
        }
        if( max != 31 ) {
            ss << " &&";
            ss << " code[" << layer_bits << "]<=7'h"  << hex << max;
        }
        if( extra[0] ) ss << extra;
        ss << ") /* " << hex << r->start << " - " << r->end << " */ ";
        addor= true;
}

void parse_range( string& s, const gfx_range *r ) {
    stringstream ss;
    bool addor=false;
    int min=r->start>>10;
    int max=(r->end>>10);

    if( r->type & GFXTYPE_SPRITES ) {
        output_range( ss, "OBJ ",  "15:9", min, max, r, addor );
    }
    if( r->type & GFXTYPE_SCROLL2 ) {
        output_range( ss, "SCR2", "15:9", min, max, r, addor );
    }
    if( r->type & GFXTYPE_SCROLL1 ) {
        output_range( ss, "SCR1", "15:10", min, max, r, addor );
    }
    if( r->type & GFXTYPE_SCROLL3 ) {
        output_range( ss, "SCR3", "13:7", min, max, r, addor, " && code[15:14]==2'b00 " );
    }
    // ss << " 1'b0 /* STARS ommitted*/ ";
    /*
    if( r->type & GFXTYPE_STARS   ) {
        output_range( ss, "STARS", "15:10", min, max, r, addor );
    }
    */
    s = ss.str();
}

string parent_name( game_entry* game ) {
    if( game->parent!="0" ) return game->parent;
    return game->name;
}

int add_verilog_mapper( stringstream& mappers, const CPS1config* x ) {
    int id;

    for(id=0;all_mappers[id]!=nullptr && all_mappers[id]!=x->ranges;id++);

    const gfx_range *r = x->ranges;
    const int set_used = id&1; // half of the games will use b outputs, and the other
    const string mux_set = set_used ? "_b" : "_a";
    while( r->type != 0 ) {
        stringstream aux;
        int b=-1;
        int done=0;
        do {
            bool nl=false;
            if ( b != r->bank ) {
                b = r->bank;
                aux << "        // Bank " << b << " size 0x" << hex << setw(5) << setfill('0') << x->bank_size[b] << '\n';
                aux << "        bank" << mux_set << "["<<b<<"] <= ";
                done |= (1<<b);
            }
            string s;
            parse_range(s,r);
            if( r[1].type!=0 ) {
                if ( r[1].bank == b && s.size()>0 ) {
                    aux << s << " ||\n        ";
                    nl = true;
                }
            }
            if(!nl && s.size()>0 ) aux << s << ";\n";
            r++;
        } while(r->type);
        for( b=0; b<4; b++) {
            if( (done & (1<<b)) == 0)
                aux << "        bank" << mux_set << "["<<b<<"] <= 1'b0;\n";
        }
        aux << "        set_used  <= 1'b" << set_used << ";\n";
        mappers << "6'h" << hex << id << ": begin\n" << aux.str() << "    end\n";
    }
    return id;
}

int generate_mapper(stringstream& of, int *sim_cfg, stringstream& mappers,
    game_entry* game, const CPS1config* x) {
    static set<int>done;
    int mask=0xABCD, offset=0x1234;
    int id=0;
    bool found=false;
    bool dump_inc;  // Avoid dumping more than once to the verilog include file
    string name; // = game->parent=="0" ? game->name : game->parent;
    // find game code. First look by the game name as some game variations have different
    // mappers to the parent game, like area88/unsquad
    for(id=0;all_mappers[id]!=nullptr && all_mappers[id]!=x->ranges;id++);
    // cout << hex << all_mappers[id] << '\n';
    // cout << hex << x->ranges << '\n';
    // cout << "Found: " << id << '\n';
    if(all_mappers[id]==nullptr) {
        of << "ERROR: game mapper not found\n";
        cout << "ERROR: game mapper not found (" << game->name << ") \n";
    }
    dump_inc = done.count(id)==0;
    done.insert(id);
    of << "        <!-- Mapper for " << name << " --> \n";
    of << "        <part> ";
    int aux=0, aux_mask;
    offset=0;
    mask=0;
    if( game->name == "sfzch" || game->parent == "sfzch" || game->name == "ganbare" ) {
        mask = 0xffff;
    } else {
        // bank 1. Bank size is always a multiple of 2^13
        aux = x->bank_size[0]>>13;
        if( (aux&~0xf) ) throw 11;
        offset |= aux<<4;
        mask   |= (aux-1);
        // bank 2
        aux += x->bank_size[1]>>13;
        if( (aux&~0xf) ) throw 12;
        offset |= aux<<8;
        mask   |= ((x->bank_size[1]>>12)-1)<<4;
        // bank 3
        aux += x->bank_size[2]>>13;
        if( (aux&~0xf) ) throw 13;
        offset |= aux<<12;
        mask   |= ((x->bank_size[2]>>12)-1)<<8;
        // bank 4
        mask   |= ((x->bank_size[3]>>12)-1)<<12;
    }
    int dumpcnt=0;
    DUMP( id        );
    DUMP( offset    );
    DUMP( offset>>8 );
    DUMP( mask      );
    DUMP( mask>>8   );
    of << "</part>\n";
    // Mapper ranges for verilog include file
    if( dump_inc ) {
        add_verilog_mapper( mappers, x );
    }
    return dumpcnt;
}

void fill( stringstream& of, int& cnt, int lim ) {
    if( cnt>lim ) throw 2;
    of << "        <part repeat=\"" << dec << (lim-cnt) << "\">FF</part>\n";
    cnt=lim;
}

string int2part( int x ) {
    char xz[32];
    sprintf( xz,"%04x",x&0xffff );
    string aux(xz);
    string s;
    //s=aux;
    s = aux.substr(2,2);
    s += " ";
    s += aux.substr(0,2);
    s += " ";
    return s;
}

#define LUT_DUMP(a,b) \
    of << "        <!-- " << a << " size " << dec << (b/1024) << " kB -->\n"; \
    of << "        <part>" << hex << int2part( cnt ) << "</part>\n"; \
    cnt+=(b>>10); dumpcnt+=2;

int generate_lut( stringstream& of, size_map& sizes ) {
    of << "        <!-- relative position of each ROM section in the file, discounting the header, in kilobytes -->\n";
    int cnt=0, dumpcnt=0;
    cnt = sizes.cpu>>10;
    of << "        <!-- Size of M68000 code " << dec << (sizes.cpu>>10) << " kB -->\n";
    LUT_DUMP( "Sound CPU", sizes.sound );
    if( sizes.oki ) {
        LUT_DUMP( "OKI samples", sizes.oki );
    }
    else {
        LUT_DUMP( "QSound samples", sizes.qsound );
    }
    LUT_DUMP( "Graphics", sizes.gfx );
    fill( of, dumpcnt, 16 );
    return dumpcnt;
}

void dump_orientation( stringstream& mra, game_entry* game, int buttons ) {
    mra << "    <rom index=\"1\"><part> ";
    int core_mod = 0x7f;
    if( game->orientation==ROT0 ) core_mod &= ~1;
    if( buttons !=0 ) {
        core_mod &= ~0xe;
        core_mod |= (buttons-2)<<1;
    }
    mra << hex << setfill('0') << setw(2) << core_mod;
    mra << " </part></rom>\n";
}

game_entry *get_parent( game_entry *game ) {
    string ref = game->parent;
    if( ref == "0" ) {
        ref = game->zipfile;
        //cout << "* using zipfile name (" << ref << " ) as parent was null\n";
    }
    for( game_entry* g : gl ) {
        if( g->name == ref ) return g;
    }
    return nullptr;
}

port_entry* find_ports( game_entry *game ) {
    port_entry*ports = nullptr;
    if( game == nullptr ) {
        //cout << "ERROR: find_ports called with nullprt\n";
        return nullptr;
    }
    //cout << "Looking for ports of " << game->name << '\n';
    for( port_entry* p : all_ports ) {
        if( p->name == game->name ) {
            ports = p;
            break;
        }
    }
    bool search_parent = ports==nullptr;
    if( ports != nullptr ) search_parent = search_parent || ports->ports_type==parent;
    if( search_parent ) {
        game_entry *p = get_parent( game );
        return find_ports( p );
    }
    return ports;
}

port_entry* dump_buttons( stringstream& mra, game_entry* game ) {
    port_entry* ports = find_ports( game );
    if( ports==nullptr ) {
        cout << "Warning: no ports for game " << game->name << '\n';
        return nullptr;
    }
//        <buttons names="Gear Up,Gear Down,-,-,Start,Coin" default="X,B,Start,R"/>
    int buttons;
    mra << "    <buttons names=\"";
    switch( ports->ports_type ) {
        case cps1_2b: mra << "B0,B1,-,-,-,-,Start,Coin,Pause\" \n        default=\"A,B,R,L,Start"; buttons=2; break;
        case cps1_2b_4way: mra << "B0,B1,-,-,-,-,Start,Coin,Pause\" \n        default=\"A,B,R,L,Start"; buttons=2; break;
        case cps1_3b: mra << "B0,B1,B2,-,-,-,Start,Coin,Pause\" \n        default=\"A,B,X,R,L,Start"; buttons=3; break;
        case cps1_quiz:
        case cps1_3players:
        case ports_ganbare:
        case cps1_4players: mra << "B0,B1,B2,B3,-,-,Start,Coin,Pause\" \n        default=\"A,B,X,Y,R,L,Start"; buttons=4; break;
        case sf2hack:
        case ports_sfzch:
        case cps1_6b: mra << "B0,B1,B2,B3,B4,B5,Start,Coin,Pause\" \n        default=\"A,B,X,Y,R,L,Select,Select,Start"; buttons=6; break;
        default: cout << "ERROR: cannot process buttons of game " << game->name;
            cout << " ports_type = " << ports->ports_type << '\n'; buttons=0; break;
    }
    mra << "\"/>\n";
    return ports;
}

#undef LUT_DUMP

void replace( string& aux, const char *f, const char *r ) {
    int x;
    while( (x = aux.find(f)) != string::npos  )
        aux.replace( x, strlen(f), r );
} 


void parse_dips( stringstream& mras, Game* dip_info, bool skip_coins ) {
    map<string, int> bases;
    bases["DSWA"] = 0;
    bases["DSWB"] = 8;
    bases["DSWC"] = 16;
    mras << "    <switches default=\"FF,FF,FF,FF\" base=\"8\">\n";
    for( DIPsw* d : dip_info->getDIPs() ) {
        if( d->name == "Unused" ) continue;
        if( skip_coins ) {
            //if( d->name.find("Coin") != string::npos ) continue;
            int dump=0;
            if( d->name.find("Flip") != string::npos ) dump++;
            if( d->name.find("Game") != string::npos ) dump++;
            if( d->name.find("Demo") != string::npos ) dump++;
            if( d->name.find("Freeze") != string::npos ) dump++;
            if( d->name.find("Difficulty") != string::npos ) dump++;
            if( !dump ) continue;
        }
        auto b = bases.find(d->tag);
        if( b != bases.end() ) {
            stringstream pre_mras;
            pre_mras << "        ";
            int base = b->second;
            int bit0 = base;
            int bit1 = base;
            int m    = d->mask;
            int k;
            for( k=0; k<8; k++ ) {
                if( (m&1) == 0 ) {
                    m>>=1;
                    bit0++;
                }
                else
                    break;
            }
            for( bit1=bit0; k<8;k++ ) {
                if( (m&1) == 1 ) {
                    m>>=1;
                    bit1++;
                }
                else
                    break;
            }
            pre_mras << "<dip bits=\"";
            --bit1;
            if( bit1==bit0 )
                pre_mras << dec << bit0;
            else
                pre_mras << dec << bit0 << "," << bit1;
            pre_mras << "\"\t name=\"" << d->name << "\" ids=\"";
            stringstream ids;
            for( DIPvalue& dval : d->values ) {
                string aux = dval.name;
                if( skip_coins ) {
                    while(1) {
                        int x = aux.find_first_of('(');
                        if( x!=string::npos) {
                            int y = aux.find_first_of(')');
                            if( y!=string::npos) {
                                aux = aux.substr(0,x)+aux.substr(y+1);
                            } else break;
                        } else break;
                    }
                }
                if( aux[aux.length()-1]==' ' ) {
                    aux.erase( aux.end()-1 );
                }
                ids << aux << ',';
            }
            string ids_str = ids.str();
            ids_str.erase( ids_str.length()-1, 1 );
            int total_length = ids_str.length() + d->name.length() + 4;
            if( total_length >255 ) {
                cout << "WARNING: DIP ids string too long by " << (total_length-255) << " chars.\n";
                cout << "Game: " << dip_info->name << '\n';
                cout << ids_str << '\n';
            }
            pre_mras << ids_str;
            pre_mras << "\"/>\n";
            string aux = pre_mras.str();
            if( !(aux.length()>63 && skip_coins) ) {
                mras << aux;
            }
        }
    }
    mras << "    </switches>\n";
}

void generate_mra( game_entry* game, Game* dip_info, bool skip_include, bool skip_coins,
    bool skip_cfg ) {
    bool skip_gfx = false;
    switch( game->board_type ) {
        //case cps1_10MHz:
        //case cps1_12MHz:
        //case sf2m3:
        //case sf2m10:
        //case sf2cems6:
        case forgottn:
        case qsound:
        //case ganbare:
            return;
        case pang3:
            skip_gfx = true;
            break;
    }
    static bool first=true;
    //ofstream simf( game->name+".hex");
    stringstream mras, simf, mappers, ss_ports;
    mras << "<misterromdescription>\n";
    xml_element(mras,"name", game->full_name,1 );
    xml_element(mras,"setname", game->name,1 );
    xml_element(mras,"year", game->year,1 );
    xml_element(mras,"manufacturer", game->mfg,1 );
    xml_element(mras,"rbf", "jtcps1",1 );
    // ROMs
    if(verbose) cout << '\n' << game->name << '\n';
    mras << "    <rom index=\"0\" zip=\"";
    if( game->zipfile != game->name ) mras << game->zipfile <<".zip|";
    if( game->parent!="0" && game->zipfile != get_parent(game)->zipfile ) {
        mras << get_parent(game)->zipfile<<".zip|";
        mras << get_parent(game)->name<<".zip|";
    }
    mras << game->name << ".zip\" md5=\"none\">\n";
    const tiny_rom_entry *entry = game->roms;
    port_entry *ports = dump_buttons(ss_ports, game);
    try{
        int cfg_id = find_cfg( game->name, &mras );
        const CPS1config* x = &cps1_config_table[cfg_id];

        int cnt=0;
        size_map sizes;
        sizes.cpu   = size_region(entry,"maincpu",1024*1024);
        sizes.sound = size_region(entry,"audiocpu",64*1024);
        sizes.oki   = size_region(entry,"oki",256*1024);
        sizes.qsound= size_region(entry,"qsound",256*1024);
        sizes.gfx   = size_region(entry,"gfx");

        cnt+=generate_lut( mras, sizes );
        // CPS-B information
        int sim_cfg[64];
        int lut_size = cnt;
        cnt+=generate_cpsb( mras, sim_cfg+cnt, x );
        // Mappers
        cnt+=generate_mapper( mras, sim_cfg+cnt, mappers, game, x );
        // Set 12MHz bit
        char cpu12=0;
        switch( game->board_type ) {
            case cps1_12MHz: cpu12=1; break;
            case sf2m3:      cpu12=1; break;
            case sf2m10:     cpu12=1; break;
            case qsound:     cpu12=1; break;
            case wofhfh:     cpu12=1; break;
            case pang3:      cpu12=1; break;
        }
        if( game->name!="pang3b" && game->board_type == pang3 )
            cpu12 |= 0x80; // enable decryption
        if( ports!= nullptr )
            cpu12 |= ports->cpsb_extra_inputs()<<1;
        // charger game ?
        if( game->name == "sfzch" || game->parent == string("sfzch") ) cpu12 |= 1 << 4;
        mras << "        <part> " << hex << uppercase << setw(2) << setfill('0') << (int)cpu12 << " </part>\n";
        sim_cfg[cnt] = cpu12;
        cnt++;
        for( int k=cnt-1; k>=lut_size; k-- ) {
            simf << "8'h" << hex << (sim_cfg[k]&0xff);
            if( k!=lut_size) simf << ',';
        }
        fill( mras, cnt, 64 ); // fill rest of header
        // Header done
        dump_region(mras, entry,"maincpu",16,1,1024*1024);
        dump_region(mras, entry,"audiocpu",8,0,64*1024);
        if( sizes.oki!=0 )
            dump_region(mras, entry,"oki",8,0,256*1024);
        else
            dump_region(mras, entry,"qsound",8,0,2*1024*1024);
        if( !skip_gfx ) dump_region(mras, entry,"gfx",64,0);
    } catch( const string& reg ) {
        cout << "ERROR: cannot process region " << reg << " of game " << game->name << '\n';
        return;
    }
    catch( int x ) {
        switch (x)  {
            case 2: cout << "ERROR: MRA header does not fit\n"; break;
            default:
                cout << "ERROR: bank offset does not fit in 4 bits " << game->name << " error code " << x << '\n'; break;
        }
        return;
    }
    mras << "    </rom>\n";
    // Game orientation
    int buttons = ports == nullptr ? 4 : ports->buttons();
    dump_orientation(mras, game, buttons);
    mras << ss_ports.str();
    // DIPs
    parse_dips( mras, dip_info, skip_coins );
    // Close MRA file
    mras << "</misterromdescription>\n";    // End of MRA file
    // Config file for MiST
    if( !skip_cfg ) {
        string fname = game->name+".cfg";
        transform(fname.begin(), fname.end(), fname.begin(), ::toupper);
        ofstream ofcfg( fname, ios_base::binary );
        unsigned char buf[4] = { 0, 0, 0xff, 0xff };
        ofcfg.write((char*)buf,4);
    }
    // hex file for simulation
    string s = simf.str();
    s = s.substr(0,s.length()-1);
    // dump files
    ofstream ofhex( "../ver/video/cfg/"+game->name+"_cfg.hex");
    ofhex << s;
    ofhex.close();

    string mra_name=game->full_name;
    replace(mra_name.begin(),mra_name.end(),'(','-');
    replace(mra_name.begin(),mra_name.end(),')','-');
    replace(mra_name.begin(),mra_name.end(),':',' ');
    replace(mra_name.begin(),mra_name.end(),'?',' ');
    ofhex.open( mra_name+".mra" );
    ofhex << mras.str();
    ofhex.close();

    if( !skip_include ) {
        ofhex.open( "../ver/video/mappers.inc", first ? ios_base::trunc : (ios_base::app | ios_base::ate) );
        ofhex << mappers.str();
        ofhex.close();
    }
    first=false;
}

int main(int argc, char *argv[]) {
    bool game_list=false, dump_parents=true, skip_include=true, skip_coins=false, mapper=false;
    bool dump_alt=false;
    bool skip_cfg =true;
    string game_name;
    for( int k=1; k<argc; k++ ) {
        if( string(argv[k])=="-list" )  { game_list=true; continue; }
        if( string(argv[k])=="-parent" ) { dump_parents=true; continue; }
        if( string(argv[k])=="-alt" ) { dump_alt=true; continue; }
        if( string(argv[k])=="-v" )   { verbose=true; continue; }
        if( string(argv[k])=="-inc" )   { skip_include=false; continue; }
        if( string(argv[k])=="-nocoin" )   { skip_coins=true; continue; }
        if( string(argv[k])=="-cfg" )   { skip_cfg=false; continue; }
        if( string(argv[k])=="-mapper" )   { mapper=true; continue; }
        if( string(argv[k])=="-h" ) {
            cout << "-list      to produce only the game list\n";
            cout << "-parent    to produce output for parent games (default)\n";
            cout << "-alt       to produce output for alternative games\n";
            cout << "-v         verbose\n";
            cout << "-inc       generates the include file for verilog\n";
            cout << "-nocoin    skips coin/credit DIP switches (useful for MiST)\n";
            cout << "-h         shows this message\n";
            return 0;
        }
        if( argv[k][0] == '-' ) {
            cout << "ERROR: unknown argument " << argv[k] << '\n';
            return 1;
        }
        game_name = argv[k];
    }
    int cnt=0;
    // Parse XML file
    GameMap game_dips;
    parse_MAME_xml( game_dips, "cps1.xml" );

    if( mapper ) {
        string all_mappers;
        set<int> done;
        vector<string> mapper_str(100);
        for( auto game : gl ) {
            int cfg_id = find_cfg( game->name );
            const CPS1config* x = &cps1_config_table[cfg_id];
            stringstream new_mapper;
            int new_id = add_verilog_mapper( new_mapper, x );
            if( done.count(new_id)==0 ) {
                done.insert(new_id);
                mapper_str[new_id] = new_mapper.str();
            }
        }
        ofstream fout("../ver/video/mappers.inc");
        for( int k=0; k < done.size(); k++ ) {
            fout << mapper_str[k];
        }
        cout << done.size() << " mappers\n";
    }
    else {
        int mra_count=0;
        for( auto game : gl ) {
            if( game_list ) {
                    cout << game->name << '\n';
            } else {
                // process game if it matches the name in arguments or
                // if there was not name then process all
                if( (!game_name.length() && (
                        ( dump_parents && game->parent=="0" ) ||
                        ( dump_alt     && game->parent!="0" )
                    ))
                    || game->name == game_name  ) {
                    Game* dip_info;
                    for( auto& g : game_dips ) {
                        if( g.second->name == game->name ) {
                            dip_info = g.second;
                            // cout << "Found " << dip_info->name << '\n';
                            break;
                        }
                    }
                    generate_mra( game, dip_info, skip_include, skip_coins, skip_cfg );
                    mra_count++;
                }
                cnt++;
            }
        }
        cout << "Created " << mra_count << " MRA files.\n";
    }
    cout << cnt << " games.\n";
}
