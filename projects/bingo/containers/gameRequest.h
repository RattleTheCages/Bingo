/**  gameRequest.h  *******************************************************


    Begin Game Request Container Object.



changes log:
when       who     what
9.22.99    Dan     Creation. 

*******************************************************************************/


#ifndef GAMEREQUESTOBJECT_CONTAINER
#define GAMEREQUESTOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define GAMEREQUEST_STATE_REQUESTING  8882
#define GAMEREQUEST_STATE_CLOSE       8883
#define GAMEREQUEST_STATE_TAKE_BETS   8884
#define GAMEREQUEST_STATE_START       8885
#define GAMEREQUEST_STATE_VOID        8889


#define GAMEREQUEST_ID          "gameRequest_o.id"
#define GAMEREQUEST_STATE       "gameRequest_o.state"
#define GAMEREQUEST_GAMESERVER  "gameRequest_o.gameserver"
#define GAMEREQUEST_GAME        "gameRequest_o.game"
#define GAMEREQUEST_GAME_ID     "gameRequest_o.gameid"

#define GAMEREQUEST_ID_MAX          24
#define GAMEREQUEST_GAMESERVER_MAX  48
#define GAMEREQUEST_GAME_MAX        24
#define GAMEREQUEST_GAME_ID_MAX     24

class gameRequest_o  {
  private:
    int      State;
    string_o Id;

  protected:
    string_o GameServer;
    string_o Game;
    string_o GameId;

  public:   
    gameRequest_o();                               // Default constructor.
    gameRequest_o(const gameRequest_o&);      // Copy constructor.
   ~gameRequest_o();                               // Default destructor.
    gameRequest_o&    operator =  (const gameRequest_o&);
                                                        // Assignment operator.
    void            operator >> (string_o&) const;      // Node-Value.
    void            operator << (const char*);          // Reconstruct.
    void            clear();
    int             blank()                 const;

    const char*     id()                    const;
          int       state()                 const;
    const char*     gameServer()            const;
    const char*     game()                  const;
    const char*     gameid()                const;

    void            setId(const char*);
    void            setState(int);
    void            setGameServer(const char*);
    void            setGame(const char*);
    void            setGameId(const char*);
};
string_o& operator << (string_o&,const gameRequest_o&);


/******************************************************************************/

inline const char* gameRequest_o::id() const  {
    return  Id.string();
}

inline int gameRequest_o::state() const  {
    return  State;
}

inline const char* gameRequest_o::gameServer() const  {
    return  GameServer.string();
}

inline const char* gameRequest_o::game() const  {
    return  Game.string();
}

inline const char* gameRequest_o::gameid() const  {
    return  GameId.string();
}

inline void gameRequest_o::setId(const char* id)  {
    Id = id;
    Id.cut(GAMEREQUEST_ID_MAX);
}

inline void gameRequest_o::setState(int st)  {
    State = st;
}

inline void gameRequest_o::setGameServer(const char* gs)  {
    GameServer = gs;
    GameServer.cut(GAMEREQUEST_GAMESERVER_MAX);
}

inline void gameRequest_o::setGame(const char* sg)  {
    Game = sg;
    Game.cut(GAMEREQUEST_GAME_MAX);
}

inline void gameRequest_o::setGameId(const char* gid)  {
    GameId = gid;
    GameId.cut(GAMEREQUEST_GAME_ID_MAX);
}


#endif

/******************************************************************************/
