/**  bingocaller.h  ************************************************************

    Bingo Caller Container Object.


changes log:
when       who     what
9.19.99    Dan     Creation. 

*******************************************************************************/


#ifndef BINGOCALLEROBJECT_API
#define BINGOCALLEROBJECT_API

#include "../../library/lib/string/string.h"
#include "../../library/lib/other/rand.h"

#include "../containers/bingogame.h"

class bingocaller_o  {
  protected:
    rand_o      Rand;
    bingogame_o Bingogame;
    string_o    Bingoserver;
    int         BingoserverPort;

  public:   
    bingocaller_o();                                    // Default constructor.
    bingocaller_o(const bingocaller_o&);                // Copy constructor.
   ~bingocaller_o();                                    // Default destructor.
    bingocaller_o&  operator =  (const bingocaller_o&); // Assignment operator.


    int process();

    int getGame();


    void setBingoserver(const char*);
    void setBingoserverPort(const char*);
};


/******************************************************************************/



#endif

/******************************************************************************/
