/**  address.cc  ***************************************************************




changes log
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/


#include "../../library/lib/parse/parse.h"
#include "../containers/address.h"


address_o::address_o()  {}

address_o::~address_o()  {}

void address_o::clear()  {
    Type    = "";
    Name    = "";
    Street  = "";
    City    = "";
    State   = "";
    Zip     = "";
    Country = "";
}

int address_o::blank() const  {
    if( Street.length()  < 1  &&
        City.length()    < 1  &&
        State.length()   < 1  &&
        Zip.length()     < 1  &&
        Country.length() < 1  )  return 1;
    return 0;
}

address_o& address_o::operator = (const address_o& a)  {
    Name    = a.Name;
    Type    = a.Type;
    Street  = a.Street;
    City    = a.City;
    State   = a.State;
    Zip     = a.Zip;
    Country = a.Country;
    return *this;
}

void address_o::operator >> (string_o& s) const  {
    s << '\n' << ADDRESS_OBJECT;
    s << '\n' << ADDRESS_TYPE << '=' << Type;
    s << '\n' << ADDRESS_NAME << '=' << Name;
    s << '\n' << ADDRESS_STREET << '=' << Street;
    s << '\n' << ADDRESS_CITY << '=' << City;
    s << '\n' << ADDRESS_STATE << '=' << State;
    s << '\n' << ADDRESS_ZIP << '=' << Zip;
    s << '\n' << ADDRESS_COUNTRY << '=' << Country;
    s << '\n';
}

void address_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(ADDRESS_TYPE,   Type);
    (void)parse.it(ADDRESS_NAME,   Name);
    (void)parse.it(ADDRESS_STREET, Street);
    (void)parse.it(ADDRESS_CITY,   City);
    (void)parse.it(ADDRESS_STATE,  State);
    (void)parse.it(ADDRESS_ZIP,    Zip);
    (void)parse.it(ADDRESS_COUNTRY,Country);
}

string_o& operator << (string_o& s,const address_o& a)  {
    a >> s;
    return s;
}


/******************************************************************************/
