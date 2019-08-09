/**  bingogame.cc  *************************************************************

changes log:
when       who     what
9.19.99    Dan     Creation. 


*******************************************************************************/


#include "../containers/bingogame.h"
#include "../../library/lib/parse/parse.h"

bingogame_o::bingogame_o()  {
    int x;
    NumberOfPlayers = 0;
    for(x=0;x<75;x++)  {
        Ball[x] = 0;
    }
    State = BINGOGAME_STATE_JOIN_NOW;
}

bingogame_o::~bingogame_o()  {}

bingogame_o& bingogame_o::operator = (const bingogame_o& b)  {
    int x;
    Id = b.Id;
    NumberOfPlayers = b.NumberOfPlayers;
    LastBall = b.LastBall;
    for(x=0;x<75;x++)  {
        Ball[x] = b.Ball[x];
    }
    State = b.State;
    
    return *this;
}

void bingogame_o::clear()  {
    int x;
    Id = "";
    NumberOfPlayers = 0;
    LastBall = 0;
    State = BINGOGAME_STATE_JOIN_NOW;
    for(x=0;x<75;x++)  {
        Ball[x] = 0;
    }
}


int bingogame_o::complete() const  {
    int x;
    if(State == BINGOGAME_STATE_COMPLETE)  return 1;
    for(x=0;x<75;x++)  {
        if(Ball[x] == 0)  return 0;
    }
    return 1;
}

int bingogame_o::addPlayer(const char* player)  {
    NumberOfPlayers = NumberOfPlayers + 1;
    return NumberOfPlayers;
}

void bingogame_o::operator >> (string_o& s) const  {
    int x;
    string_o t(BINGOGAME_BALL_NNN);
    t.cut(t.length()-3);
    s << "\nbingogame_o:";
    s << '\n' << BINGOGAME_ID << '=' << Id;
    s << '\n' << BINGOGAME_STATE << '=' << State;
    s << '\n' << BINGOGAME_LASTBALL << '=' << LastBall;
    for(x=0;x<75;x++)  {
        s << '\n' << t << x << '=' << Ball[x];
    }
    s << '\n';
}

void bingogame_o::operator << (const char* cc)  {
    int x;
    string_o t;
    parse_o parse(cc);
    (void)parse.it(BINGOGAME_ID,   Id);
    (void)parse.it(BINGOGAME_STATE,State);
    (void)parse.it(BINGOGAME_LASTBALL,LastBall);
    for(x=0;x<75;x++)  {
        t = BINGOGAME_BALL_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),Ball[x]);
    }
}

string_o& operator << (string_o& s,const bingogame_o& b)  {
    b >> s;
    return s;
}


/******************************************************************************/
