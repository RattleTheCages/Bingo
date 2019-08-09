/**  bingoSession.cc  **********************************************************




changes log
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/


#include "../../library/lib/parse/parse.h"
#include "../containers/bingoSession.h"


extern log_o  log;

bingoSession_o::bingoSession_o()  {
    (void)init();
}

bingoSession_o::~bingoSession_o()  {}

void bingoSession_o::init()  {
    Id = -1;
    Transactions = 1000;
    JoinedGameId = "";
}

void bingoSession_o::clear()  {
    (void)init();
}


void bingoSession_o::operator >> (string_o& s) const  {
    s << "\nbingoSession_o:";
    s << '\n' << BINGOSESSION_ID << '=' << Id;
    s << '\n' << BINGOSESSION_STATE << '=' << State;
    s << '\n';
}

void bingoSession_o::operator << (const char* bs)  {
    parse_o  parse(bs);

    (void)parse.it(BINGOSESSION_ID,   Id);
    (void)parse.it(BINGOSESSION_STATE,State);
}

string_o& operator << (string_o& s,const bingoSession_o& bs)  {
    bs >> s;
    return s;
}


/******************************************************************************/
