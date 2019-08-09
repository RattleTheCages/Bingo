/**  bingogame.h  **************************************************************

    Bingo Game Container Object.


changes log:
when       who     what
9.19.99    Dan     Creation. 

*******************************************************************************/


#ifndef BINGOGAMEOBJECT_CONTAINER
#define BINGOGAMEOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define BINGOGAME_ID          "bingoball_o.id"
#define BINGOGAME_STATE       "bingoball_o.state"
#define BINGOGAME_LASTBALL    "bingoball_o.lastball"
#define BINGOGAME_BALL_NNN    "bingoball_o.ball_nnn"

#define BINGOGAME_STATE_JOIN_NOW     1
#define BINGOGAME_STATE_IN_PROGRESS  2
#define BINGOGAME_STATE_COMPLETE     3


class bingogame_o  {
  protected:
    string_o Id;
    int      NumberOfPlayers;
    int      LastBall;
    int      Ball[75];
    int      State;

  public:   
    bingogame_o();                                      // Default constructor.
    bingogame_o(const bingogame_o&);                    // Copy constructor.
   ~bingogame_o();                                      // Default destructor.
    bingogame_o&      operator =  (const bingogame_o&); // Assignment operator.
    void              operator >> (string_o&) const;    // Node-Value.
    void              operator << (const char*);        // Reconstruct.
    void              clear();

    const char*       id()                  const;
          int         numberOfPlayers()     const;
          int         operator[] (int)      const;
          int         complete()            const;
          int         state()               const;

          void        setId(const char*);
          int         setBallPick(int);
          void        setState(int);
          int         addPlayer(const char*);
};
string_o& operator << (string_o&,const bingogame_o&);


/******************************************************************************/

inline const char* bingogame_o::id() const  {
    return  Id.string();
}

inline int bingogame_o::numberOfPlayers() const  {
    return  NumberOfPlayers;
}

inline int bingogame_o::state() const  {
    return  State;
}

inline int bingogame_o::operator[] (int p) const  {
    if(p < 1 || p > 75)  {
        return -1;
    }
    return Ball[p-1];
}

inline void bingogame_o::setId(const char* id)  {
    Id = id;
}

inline void bingogame_o::setState(int st)  {
    State = st;
}

inline int bingogame_o::setBallPick(int p)  {
    if(p < 1 || p > 75)  {
        return -1;
    }
    Ball[p-1] = 1;
    return Ball[p-1];
}


#endif

/*****************************************************************************/
