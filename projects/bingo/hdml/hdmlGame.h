/**  hdmlGame.h  ***************************************************************


    HDML Main Game Object.


changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/

#ifndef HDMLGAMEOBJECT_API
#define HDMLGAMEOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlGame_o  {
  private:
    void            init();

  public:
    hdmlGame_o();                                   // Default constructor.
    hdmlGame_o(const hdmlGame_o&);                  // Copy constructor.
   ~hdmlGame_o();                                   // Default destructor.
    hdmlGame_o& operator = (const hdmlGame_o&);     // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/**  Inline methods need to be in the header.  ********************************/


#endif

/******************************************************************************/
