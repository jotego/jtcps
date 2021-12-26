#include "mamegame.hpp"
#include <xercesc/sax2/XMLReaderFactory.hpp>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <list>
// Other include files, declarations, and non-Xerces-C++ initializations.

using namespace xercesc;
using namespace std;

string get_str_attr( const Attributes & attrs, const char* name ) {
    const char *blank="";
    const XMLCh* v = attrs.getValue( (const XMLCh*)XMLStr(name) );
    if( v != NULL ) {
        string aux( (const char*)StdStr(v) );
        return aux;
    }
    else return blank;
}

#define TOSTR(a,b) string a( (const char*)StdStr(b) )
//#define GET_STR_ATTR( a ) string a( (const char*)StdStr( attrs.getValue(XMLStr(#a)) ) );
#define GET_STR_ATTR( a ) string a( get_str_attr(attrs, #a) );

void MameParser::startElement( const XMLCh *const uri,
        const XMLCh *const localname, const XMLCh *const qname, const Attributes & attrs ) 
{
    TOSTR( _localname, localname );
    if( _localname == "machine" ) {
        GET_STR_ATTR( name );
        string cloneof;
        const XMLCh* aux = attrs.getValue( XMLStr("cloneof"));
        if( aux ) cloneof = (const char*)StdStr(aux);
        current = new Game(name);
        current->cloneof = cloneof;
        games[name] = current;
    }
    if( _localname == "dipswitch" ) {
        GET_STR_ATTR( name );
        GET_STR_ATTR( tag  );
        GET_STR_ATTR( mask );
        current_dip = new DIPsw( name, tag, toint(mask));
        current->addDIP( current_dip );
    }
    if( _localname == "dipvalue" ) {
        GET_STR_ATTR( name );
        GET_STR_ATTR( value );
        current_dip->values.push_back( { name, toint(value)} );
    }
    if( _localname == "diplocation" ) {
        GET_STR_ATTR( name );
        current_dip->location=name;
    }
    if( _localname == "rom" ) {
        parse_rom( attrs );
    }
}

void MameParser::endElement( const XMLCh *const uri,
        const XMLCh *const localname, const XMLCh *const qname ) {
    TOSTR( _localname, localname );
    if( _localname == "dipswitch" ) {
        current_dip->values.sort();
        current_dip = nullptr;
    }
}

void MameParser::parse_rom( const Attributes & attrs ) {
    GET_STR_ATTR( name   );
    GET_STR_ATTR( crc    );
    GET_STR_ATTR( region );
    GET_STR_ATTR( size   );
    GET_STR_ATTR( offset );
    ROMRegion* r = current->getRegion( region );
    r->roms.push_back(
        new ROM( {name, crc, toint(size,10), toint(offset,16)} )
    );
}

ROMRegion* Game::getRegion( std::string _name ) {
    static ROMRegion *last = nullptr;
    if( last != nullptr ) {
        if( last->name == _name ) return last;
    }
    for( ROMRegion *r : regions ) {
        if( r->name == _name ) {
            last = r;
            return last;
        }
    }
    last = new ROMRegion( {_name} );
    regions.push_back(last);
    return last;
}

void Game::addDIP( DIPsw* d ) {
    dips.push_back(d);   
}

void Game::dump() {
    cout << name << '\n';
    for( auto k : dips ) {
        cout << '\t' << k->name << '\t' << k->tag << '\t' << hex << k->mask << '\n';
    }
}

Game::~Game() {
    for( auto k : dips ) {
        delete k;
    }
}

int toint(string s, int base) {    
    return strtol( s.c_str(), NULL, base);
}

GameMap::~GameMap() {
    for( auto& g : *this ) {
        delete g.second;
        g.second=nullptr;
    }
    clear();
}

ROMRegion::~ROMRegion() {
    for( ROM* r : roms ) {
        delete r;
    }
    roms.clear();
}

int parse_MAME_xml( GameMap& games, const char *xmlFile ) {
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        // Do your failure processing here
        return 1;
    }

    SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

    MameParser mame(games);
    parser->setErrorHandler(&mame);
    parser->setContentHandler( (ContentHandler*) &mame);

    try {
        parser->parse(xmlFile);
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "ERROR (XML): \n"
             << message << "\n";
        XMLString::release(&message);
        return -1;
    }
    catch (const SAXParseException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "ERROR (XML): \n"
             << message << "\n";
        XMLString::release(&message);
        return -1;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        return -1;
    }

    delete parser;
    XMLPlatformUtils::Terminate();
    return 0;
}