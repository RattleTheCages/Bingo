/**  pdaInput.cc  **************************************************************

changes log:
when       who     what
9.9.99     Dan     Creation. 


*******************************************************************************/


#include "../containers/pdaInput.h"
#include "../../library/lib/parse/parse.h"

pdaInput_o::pdaInput_o()  {}

pdaInput_o::pdaInput_o(const input_o& input)  {
    (*(input_o*)this) = input;
}

pdaInput_o::~pdaInput_o()  {}

void pdaInput_o::clear()  {
    Phone = "";
}

pdaInput_o& pdaInput_o::operator = (const pdaInput_o& p)  {
    Phone = p.Phone;
    return *this;
}

void pdaInput_o::operator >> (string_o& s) const  {
    s << "~pdaInput_o:";
    s << '~' << PDAINPUT_PHONE << '=' << Phone;
    s << '~' << PDAINPUT_INPUT << '=' << *((input_o*)this);
    s << '~';
}

void pdaInput_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(PDAINPUT_PHONE, Phone);
    //((input_o*)this) << cc;  !!!!!!
}

string_o& operator << (string_o& s,const pdaInput_o& p)  {
    p >> s;
    return s;
}


/******************************************************************************/
