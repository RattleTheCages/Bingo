/**  hdmlJoinGame.h  ***********************************************************


    HDML Join Game Object.


changes log
when       who      what
9.19.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLJOINGAMEOBJECT_API
#define HDMLJOINGAMEOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlJoinGame_o  {
  private:
    void            init();

  public:
    hdmlJoinGame_o();                                   // Default constructor.
    hdmlJoinGame_o(const hdmlJoinGame_o&);              // Copy constructor.
   ~hdmlJoinGame_o();                                   // Default destructor.
    hdmlJoinGame_o& operator = (const hdmlJoinGame_o&); // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
