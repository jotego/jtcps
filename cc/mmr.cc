#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <algorithm>

#include "config.h"

using namespace std;

bool verbose=false;

void xml_element( stringstream& of, const char *name, const string &content, int tab) {
    while( tab-- ) of << "    ";
    of << "<" << name << ">" << content << "</" << name << ">\n";
}

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
                                const tiny_rom_entry* cur=entry;
                                if( done==0 ) {
                                    of << "<interleave output=\""<<bits<<"\">\n";
                                    of << indent;
                                }
                                of << "    ";
                                of << "<part name=\"" << cur->name << "\" ";
                                of << "crc=\"" << cur->hashdata << "\" map=\"";
                                if(done==0) {
                                    if( swap ) of << "10\""; else of << "01\"";
                                }
                                else {
                                    if( swap ) of << "01\""; else of << "10\"";
                                }
                                of << "/>\n";
                                done+=file_width;
                                if( done==(bits>>3) ) {
                                    of << "       </interleave>\n";
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
                                of << "       </interleave>\n";
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
                if( min_length!=0 && length>min_length ) {
                    cout << "ERROR: unexpected region size!\n";
                }
                return;
            }
        }
        entry++;
    }
    throw region;
}

#define DUMP(a) of << hex << uppercase << setw(2) << setfill('0') << ((a)&0xff) << ' '; \
    simf << "8'h" << hex << ((a)&0xff) << ',';

int find_cfg( stringstream& of, const string& name ) {
    int k=0;
    while( cps1_config_table[k].name != nullptr ) {
        if( name == cps1_config_table[k].name ) return k;
        k++;
    }
    of << "ERROR: cannot find game " << name << '\n';
    cout << "ERROR: cannot find game " << name << '\n';
    return -1;
}

void generate_cpsb(stringstream& of, stringstream& simf, const CPS1config* x) {
    of << "       <!-- CPS-B config for " << x->name << " --> \n";
    of << "       <part> ";            
    DUMP( x->layer_enable_mask[3] );
    DUMP( x->layer_enable_mask[2] );
    DUMP( x->layer_enable_mask[1] );
    DUMP( x->layer_enable_mask[0] );
    DUMP( x->palette_control );
    DUMP( x->priority[3]   );
    DUMP( x->priority[2]   );
    DUMP( x->priority[1]   );
    DUMP( x->priority[0]   );
    DUMP( x->layer_control );
    DUMP( x->mult_result_hi );
    DUMP( x->mult_result_lo );
    DUMP( x->mult_factor2 );
    DUMP( x->mult_factor1 );
    DUMP( (x->cpsb_value>>4) | (x->cpsb_value&0xf) );
    DUMP( x->cpsb_addr );
    of << "</part>\n";
}

// SCR1      1'b0, code[15:...]
// SCR2/OBJ  code[15:...]
// SCR3      code[13:..]

void output_range( stringstream& ss, const char *layer, const char *layer_bits,
    int min, int max, const gfx_range *r, bool& addor ) {
        if(addor) ss << "\n        || "; 
        ss << " ( layer==" << layer << " "; 
        if( min!=0 ) {
            ss << " &&";
            ss << " code[" << layer_bits << "]>=5'h" << hex << min;
        }
        if( max != 31 ) {
            ss << " &&";
            ss << " code[" << layer_bits << "]<=5'h"  << hex << max;
        }
        ss << ") /* " << hex << r->start << " - " << r->end << " */ ";
        addor= true; 
}

void parse_range( string& s, const gfx_range *r ) {
    stringstream ss;
    bool addor=false;
    int min=r->start>>12;
    int max=(r->end>>12);

    if( r->type & GFXTYPE_SPRITES ) {
        output_range( ss, "OBJ ",  "15:11", min, max, r, addor );
    }
    if( r->type & GFXTYPE_SCROLL2 ) { 
        output_range( ss, "SCR2", "15:11", min, max, r, addor );
    }
    if( r->type & GFXTYPE_SCROLL1 ) { 
        output_range( ss, "SCR1", "15:12", min, max, r, addor );
    }
    if( r->type & GFXTYPE_SCROLL3 ) {
        output_range( ss, "SCR3", "13:9", min, max, r, addor );
    }
    if( r->type & GFXTYPE_STARS   ) { 
        output_range( ss, "STARS", "15:11", min, max, r, addor );
    }
    s = ss.str();
}

string parent_name( game_entry* game ) {
    if( game->parent!="0" ) return game->parent;
    return game->name;
}

void generate_mapper(stringstream& of, stringstream& simf, stringstream& mappers,
    game_entry* game, const CPS1config* x) {
    int mask=0xABCD, offset=0x1234;
    int id=0;
    bool found=false;
    const string name = game->parent=="0" ? game->name : game->parent;
    // find game code    
    while( parents[id] ) {
        if( name == parents[id] ) { found=true; break; }
        id++;
    }
    if(!found) {
        of << "ERROR: game parent not found\n";
        cout << "ERROR: game parent not found\n";
    }
    of << "       <!-- Mapper for " << name << " --> \n";
    of << "       <part> ";
    int aux=0, aux_mask;
    offset=0;
    mask=0;
    // bank 1. Bank size is always a multiple of 2^13
    aux = x->bank_size[0]>>13;
    if( (aux&~0xf) ) throw 1;
    offset |= aux<<4;
    mask   |= (aux-1);
    // bank 2
    aux += x->bank_size[1]>>13;
    if( (aux&~0xf) ) throw 1;
    offset |= aux<<8;
    mask   |= ((x->bank_size[1]>>12)-1)<<4;
    // bank 3
    aux += x->bank_size[2]>>13;
    if( (aux&~0xf) ) throw 1;
    offset |= aux<<12;
    mask   |= ((x->bank_size[2]>>12)-1)<<8;
    // bank 4
    mask   |= ((x->bank_size[3]>>12)-1)<<12;

    DUMP( mask>>8   );
    DUMP( mask      );
    DUMP( offset>>8 );
    DUMP( offset    );
    DUMP( id        );
    of << "</part>\n";
    // Work on mapper ranges
    const gfx_range *r = x->ranges;
    while( r->type != 0 ) {
        stringstream aux;
        int b=-1;
        int done=0;
        do {
            bool nl=false;
            if ( b != r->bank ) {
                b = r->bank;
                aux << "        // Bank " << b << " size 0x" << hex << setw(5) << setfill('0') << x->bank_size[b] << '\n';
                aux << "        bank["<<b<<"] <= ";
                done |= (1<<b);
            }
            string s;
            parse_range(s,r);
            if( r[1].type!=0 ) {
                if ( r[1].bank == b ) {
                    aux << s << " ||\n        ";
                    nl = true;
                }
            }
            if(!nl) aux << s << ";\n";
            r++;
        } while(r->type);
        for( b=0; b<4; b++) {
            if( (done & (1<<b)) == 0)
                aux << "        bank["<<b<<"] <= 1'b0;\n";
        }
        mappers << "game_" << parent_name(game) << ": begin\n" << aux.str() << "    end\n";
    }
}

void generate_mra( game_entry* game ) {
    static bool first=true;
    //ofstream simf( game->name+".hex");
    stringstream mras, simf, mappers;
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
    mras << game->name << ".zip\" md5=\"none\">\n";
    const tiny_rom_entry *entry = game->roms;
    try{
        dump_region(mras, entry,"maincpu",16,1,1024*1024);
        dump_region(mras, entry,"audiocpu",8,0,64*1024);
        dump_region(mras, entry,"oki",8,0,256*1024);
        dump_region(mras, entry,"gfx",64,0);
    } catch( const string& reg ) {
        cout << "ERROR: cannot process region " << reg << " of game " << game->name << '\n';
        return;
    }
    int cfg_id = find_cfg( mras, game->name );
    const CPS1config* x = &cps1_config_table[cfg_id];
    try {
        generate_mapper( mras, simf, mappers, game, x );
    } catch( int x ) {
        cout << "ERROR: bank offset does not fit in 4 bits " << game->name << '\n';
        return;
    }
    generate_cpsb( mras, simf, x );
    mras << "    </rom>\n";
    mras << "</misterromdescription>\n";
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

    ofhex.open( "../ver/video/mappers.inc", first ? ios_base::trunc : (ios_base::app | ios_base::ate) );
    ofhex << mappers.str();
    ofhex.close();
    first=false;
}

int main(int argc, char *argv[]) {
    bool game_list=false, parents_only=true;
    string game_name;
    for( int k=1; k<argc; k++ ) {
        if( string(argv[k])=="-list" )  { game_list=true; continue; }
        if( string(argv[k])=="-parent" ) { parents_only=true; continue; }
        if( string(argv[k])=="-alt" ) { parents_only=false; continue; }
        if( string(argv[k])=="-v" )   { verbose=true; continue; }
        if( string(argv[k])=="-h" ) {
            cout << "-list      to produce only the game list\n";
            cout << "-parent    to produce only output for parent games (default)\n";
            cout << "-alt       to produce output for all games\n";
            cout << "-v         verbose\n";
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
    for( auto game : gl ) {
        if( parents_only && game->parent!="0" ) continue;
        if( game_list ) {
                cout << game->name << '\n';
        } else {
            if( !game_name.length() || game->name == game_name )
                generate_mra( game );
                cnt++;
        }
    }
    cout << cnt << " games.\n";
}


