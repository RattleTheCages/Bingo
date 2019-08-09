/**  pitbossui.h  **************************************************************

    Pit Boss User Interface Container Object.


changes log:
when       who     what
9.22.99    Dan     Creation. 

*******************************************************************************/


#ifndef PITBOSSUIOBJECT_CONTAINER
#define PITBOSSUIOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define PITBOSSUI_ID          "pitbossui_o.id"
#define PITBOSSUI_GAMESERVER  "pitbossui_o.gameserver"
#define PITBOSSUI_GAME        "pitbossui_o.game"
#define PITBOSSUI_GAME_ID     "pitbossui_o.gameid"

#define PITBOSSUI_ID_MAX          24
#define PITBOSSUI_GAMESERVER_MAX  48
#define PITBOSSUI_GAME_MAX        24
#define PITBOSSUI_GAME_ID_MAX     24

class pitbossui_o  {
  private:
    string_o Id;

  protected:
    string_o GameServer;
    string_o Game;
    string_o GameId;

  public:   
    pitbossui_o();                                      // Default constructor.
    pitbossui_o(const pitbossui_o&);                    // Copy constructor.
   ~pitbossui_o();                                      // Default destructor.
    pitbossui_o&    operator =  (const pitbossui_o&);   // Assignment operator.
    void            operator >> (string_o&) const;      // Node-Value.
    void            operator << (const char*);          // Reconstruct.
    void            clear();
    int             blank()                 const;

    const char*     id()                    const;
    const char*     gameServer()            const;
    const char*     game()                  const;
    const char*     gameid()                const;

    void            setId(const char*);
    void            setGameServer(const char*);
    void            setGame(const char*);
    void            setGameId(const char*);
};
string_o& operator << (string_o&,const pitbossui_o&);


/******************************************************************************/

inline const char* pitbossui_o::id() const  {
    return  Id.string();
}

inline const char* pitbossui_o::gameServer() const  {
    return  GameServer.string();
}

inline const char* pitbossui_o::game() const  {
    return  Game.string();
}

inline const char* pitbossui_o::gameid() const  {
    return  GameId.string();
}

inline void pitbossui_o::setId(const char* id)  {
    Id = id;
    Id.cut(PITBOSSUI_ID_MAX);
}

inline void pitbossui_o::setGameServer(const char* gs)  {
    GameServer = gs;
    GameServer.cut(PITBOSSUI_GAMESERVER_MAX);
}

inline void pitbossui_o::setGame(const char* sg)  {
    Game = sg;
    Game.cut(PITBOSSUI_GAME_MAX);
}

inline void pitbossui_o::setGameId(const char* gid)  {
    GameId = gid;
    GameId.cut(PITBOSSUI_GAME_ID_MAX);
}


#endif

/******************************************************************************/
