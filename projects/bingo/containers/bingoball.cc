/**  bingoball.cc  *************************************************************

changes log:
when       who     what
9.19.99    Dan     Creation. 


*******************************************************************************/


#include "../containers/bingoball.h"
#include "../../library/lib/parse/parse.h"

bingoball_o::bingoball_o()  {}

bingoball_o::~bingoball_o()  {}

bingoball_o& bingoball_o::operator = (const bingoball_o& b)  {
    Id      = b.Id;
    Value   = b.Value;
    Order   = b.Order;
    return *this;
}

void bingoball_o::operator >> (string_o& s) const  {
    s << "\nbingoball_o:";
    s << '\n' << BINGOBALL_ID << '=' << Id;
    s << '\n' << BINGOBALL_VALUE << '=' << Value;
    s << '\n' << BINGOBALL_ORDER << '=' << Order;
    s << '\n';
}

void bingoball_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(BINGOBALL_ID,   Id);
    (void)parse.it(BINGOBALL_VALUE,Value);
    (void)parse.it(BINGOBALL_ORDER,Order);
}

string_o& operator << (string_o& s,const bingoball_o& b)  {
    b >> s;
    return s;
}


/******************************************************************************/
