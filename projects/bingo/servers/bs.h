/**  bingoserver.h  ************************************************************

    Bingo Server Object.


changes log:
when       who     what
9.19.99    Dan     Creation. 

*******************************************************************************/


#ifndef BINGOSERVEROBJECT_API
#define BINGOSERVEROBJECT_API

#include "../../library/lib/string/string.h"
#include "../../library/pserver/carapace/carapace.h"

#include "../containers/bingogame.h"
#include "../containers/bingocard.h"


class bingoserver_o  {
  protected:

    bingogame_o Bingogame;

  public:   
    bingoserver_o();                                    // Default constructor.
    bingoserver_o(const bingoserver_o&);                    // Copy constructor.
   ~bingoserver_o();                                    // Default destructor.
    bingoserver_o&      operator =  (const bingoserver_o&); // Assignment operator.

    int process(input_o&,output_o&);
    int pdainput(input_o&,output_o&);

    int markPlayersCards();
    int checkCard(bingocard_o&);
};


/******************************************************************************/


#endif

/*****************************************************************************/
