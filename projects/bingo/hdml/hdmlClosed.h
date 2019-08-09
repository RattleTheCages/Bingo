/**  hdmlClosed.h  *************************************************************


    HDML Closed Object.


changes log
when       who      what
9.19.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLCLOSEDOBJECT_API
#define HDMLCLOSEDOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlClosed_o  {
  private:
    void            init();

  public:
    hdmlClosed_o();                                   // Default constructor.
    hdmlClosed_o(const hdmlClosed_o&);              // Copy constructor.
   ~hdmlClosed_o();                                   // Default destructor.
    hdmlClosed_o& operator = (const hdmlClosed_o&); // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
