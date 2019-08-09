/**  pitbossui.cc  *************************************************************


changes log:
when       who     what
9.22.99    Dan     Creation. 


*******************************************************************************/


#include "../containers/pitbossui.h"
#include "../../library/lib/parse/parse.h"

pitbossui_o::pitbossui_o()  {}

pitbossui_o::~pitbossui_o()  {}

void pitbossui_o::clear()  {
    Id = "";
    GameServer = "";
    Game = "";
    GameId = "";
}

int pitbossui_o::blank() const  {
    if( Id.length()  < 1  &&
        GameServer.length()    < 1  &&
        Game.length()   < 1  &&
        GameId.length() < 1  )  return 1;
    return 0;
}

pitbossui_o& pitbossui_o::operator = (const pitbossui_o& p)  {
    Id         = p.Id;
    GameServer = p.GameServer;
    Game       = p.Game;
    GameId     = p.GameId;
    return *this;
}

void pitbossui_o::operator >> (string_o& s) const  {
    s << "\npitbossui_o:";
    s << '\n' << PITBOSSUI_ID << '=' << Id;
    s << '\n' << PITBOSSUI_GAMESERVER << '=' << GameServer;
    s << '\n' << PITBOSSUI_GAME << '=' << Game;
    s << '\n' << PITBOSSUI_GAME_ID << '=' << Id;
    s << '\n';
}

void pitbossui_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(PITBOSSUI_ID,        Id);
    (void)parse.it(PITBOSSUI_GAMESERVER,GameServer);
    (void)parse.it(PITBOSSUI_GAME,      Game);
    (void)parse.it(PITBOSSUI_GAME_ID,   GameId);
}

string_o& operator << (string_o& s,const pitbossui_o& p)  {
    p >> s;
    return s;
}


/******************************************************************************/
