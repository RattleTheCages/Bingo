/**  hdmlViewPassCode.h  *******************************************************


    HDML View Pass Code Object.


changes log
when       who      what
10.9.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLVIEWPASSCODEOBJECT_API
#define HDMLVIEWPASSCODEOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlViewPassCode_o  {
  private:
    void            init();

  public:
    hdmlViewPassCode_o();                              // Default constructor.
    hdmlViewPassCode_o(const hdmlViewPassCode_o&);    // Copy constructor.
   ~hdmlViewPassCode_o();                              // Default destructor.
    hdmlViewPassCode_o& operator = (const hdmlViewPassCode_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
