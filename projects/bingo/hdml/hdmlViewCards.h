/**  hdmlViewCards.h  ***********************************************************


    HDML View Cards Object.


changes log
when       who      what
9.19.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLVIEWCARDSOBJECT_API
#define HDMLVIEWCARDSOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlViewCards_o  {
  private:
    void            init();

  public:
    hdmlViewCards_o();                                  // Default constructor.
    hdmlViewCards_o(const hdmlViewCards_o&);            // Copy constructor.
   ~hdmlViewCards_o();                                  // Default destructor.
    hdmlViewCards_o& operator = (const hdmlViewCards_o&);
                                                        // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
