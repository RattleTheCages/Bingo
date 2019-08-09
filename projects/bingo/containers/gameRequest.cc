/**  gameRequest.cc  ******************************************************



changes log
when       who     what
9.22.99    Dan     Creation. 

*******************************************************************************/


#include "../containers/gameRequest.h"
#include "../../library/lib/parse/parse.h"


gameRequest_o::gameRequest_o()  {}

gameRequest_o::~gameRequest_o()  {}

void gameRequest_o::clear()  {
    Id         = "";
    State      = GAMEREQUEST_STATE_REQUESTING;
    GameServer = "";
    Game       = "";
    GameId     = "";
}

int gameRequest_o::blank() const  {
    if( Id.length()  < 1  &&
        GameServer.length()    < 1  &&
        Game.length()   < 1  &&
        GameId.length() < 1  )  return 1;
    return 0;
}

gameRequest_o& gameRequest_o::operator = (const gameRequest_o& p)  {
    Id         = p.Id;
    State      = p.State;
    GameServer = p.GameServer;
    Game       = p.Game;
    GameId     = p.GameId;
    return *this;
}

void gameRequest_o::operator >> (string_o& s) const  {
    s << "\ngameRequest_o:";
    s << '\n' << GAMEREQUEST_ID << '=' << Id;
    s << '\n' << GAMEREQUEST_STATE << '=' << State;
    s << '\n' << GAMEREQUEST_GAMESERVER << '=' << GameServer;
    s << '\n' << GAMEREQUEST_GAME << '=' << Game;
    s << '\n' << GAMEREQUEST_GAME_ID << '=' << Id;
    s << '\n';
}

void gameRequest_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(GAMEREQUEST_ID,        Id);
    (void)parse.it(GAMEREQUEST_STATE,     State);
    (void)parse.it(GAMEREQUEST_GAMESERVER,GameServer);
    (void)parse.it(GAMEREQUEST_GAME,      Game);
    (void)parse.it(GAMEREQUEST_GAME_ID,   GameId);
}

string_o& operator << (string_o& s,const gameRequest_o& p)  {
    p >> s;
    return s;
}


/******************************************************************************/
