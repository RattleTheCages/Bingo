/**  hdmlViewAccount.h  ***********************************************************


    HDML New Cards Object.


changes log
when       who      what
9.19.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLNEWCARDSOBJECT_API
#define HDMLNEWCARDSOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlViewAccount_o  {
  private:
    void            init();

  public:
    hdmlViewAccount_o();                                   // Default constructor.
    hdmlViewAccount_o(const hdmlViewAccount_o&);              // Copy constructor.
   ~hdmlViewAccount_o();                                   // Default destructor.
    hdmlViewAccount_o& operator = (const hdmlViewAccount_o&); // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
