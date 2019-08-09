/**  hdmlInProgress.h  ***************************************************************


    HDML Main InProgress Object.


changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/

#ifndef HDMLINPROGRESSOBJECT_API
#define HDMLINPROGRESSOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlInProgress_o  {
  private:
    void            init();

  public:
    hdmlInProgress_o();                                   // Default constructor.
    hdmlInProgress_o(const hdmlInProgress_o&);                  // Copy constructor.
   ~hdmlInProgress_o();                                   // Default destructor.
    hdmlInProgress_o& operator = (const hdmlInProgress_o&);     // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/**  Inline methods need to be in the header.  ********************************/


#endif

/******************************************************************************/
