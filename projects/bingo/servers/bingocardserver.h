/**  bingocardserver.h  ********************************************************

    Address Container Object.


changes log:
when       who     what
9.19.99    Dan     Creation. 

*******************************************************************************/


#ifndef BINGOCARDSERVEROBJECT_API
#define BINGOCARDSERVEROBJECT_API

#include "../../library/lib/other/rand.h"
#include "../../library/lib/string/string.h"
#include "../../library/lib/memory/cache.h"

#include "../containers/bingocard.h"



class bingocardserver_o  {
  private:
    rand_o rand;
  protected:
    short int             BingoCardsCheckedOut[100000];
    cache_o<bingocard_o>  BingoCards;
    bingocard_o           BlankBingoCard;

  public:   
    bingocardserver_o();                            // Default constructor.
    bingocardserver_o(const bingocardserver_o&);    // Copy constructor.
   ~bingocardserver_o();                            // Default destructor.
    bingocardserver_o&  operator =  (const bingocardserver_o&);
                                                    // Assignment operator.
    void            operator >> (string_o&) const;  // Node-Value.
    void            operator << (const char*);      // Reconstruct.

    void getCard(bingocard_o&);

          void         returnCard(const bingocard_o&);

};


/******************************************************************************/



#endif

/*****************************************************************************/
