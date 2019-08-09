/**  hdmlTakingBets.h  *************************************************************


    HDML TakingBets Object.


changes log
when       who      what
9.22.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLTAKINGBETSOBJECT_API
#define HDMLTAKINGBETSOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlTakingBets_o  {
  private:
    void            init();

  public:
    hdmlTakingBets_o();                                   // Default constructor.
    hdmlTakingBets_o(const hdmlTakingBets_o&);              // Copy constructor.
   ~hdmlTakingBets_o();                                   // Default destructor.
    hdmlTakingBets_o& operator = (const hdmlTakingBets_o&); // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
