/**  passcode.cc  **************************************************************




changes log
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/


#include "../../library/lib/parse/parse.h"
#include "../containers/passcode.h"


passcode_o::passcode_o()  {}

passcode_o::~passcode_o()  {}

void passcode_o::clear()  {
    Userid    = "";
    Password  = "";
    Valid     = 0;
}

int passcode_o::blank() const  {
    if( Userid.length()  < 1 &&
        Password.length() < 1)  return 1;
    return 0;
}

passcode_o& passcode_o::operator = (const passcode_o& a)  {
    Userid    = a.Userid;
    Password  = a.Password;
    Valid     = a.Valid;
    return *this;
}

int passcode_o::operator == (const passcode_o& a) const  {
    if(Userid == a.Userid  &&  Password == a.Password)  return 1;
    return 0;
}

void passcode_o::operator >> (string_o& s) const  {
    s << "\n" << PASSCODE_OBJECT;
    s << '\n' << PASSCODE_USERID << '=' << Userid;
    s << '\n' << PASSCODE_PASSWORD << '=' << Password;
    s << '\n' << PASSCODE_VALID << '=' << Valid;
    s << '\n';
}

void passcode_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(PASSCODE_USERID,   Userid);
    (void)parse.it(PASSCODE_PASSWORD, Password);
    (void)parse.it(PASSCODE_VALID,    Valid);
}


/******************************************************************************/
