/**  hdmlViewAccount.h  ***********************************************************


    HDML New Cards Object.


changes log
when       who      what
9.19.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLVIEWACCOUNTOBJECT_API
#define HDMLVIEWACCOUNTOBJECT_API

#include "../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlViewAccount_o  {
  private:
    void            init();

  public:
    hdmlViewAccount_o();                                   // Default constructor.
    hdmlViewAccount_o(const hdmlViewAccount_o&);              // Copy constructor.
   ~hdmlViewAccount_o();                                   // Default destructor.
    hdmlViewAccount_o& operator = (const hdmlViewAccount_o&); // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
