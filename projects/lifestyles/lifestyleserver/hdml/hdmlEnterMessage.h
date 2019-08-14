/**  hdmlEnterMessage.h  ******************************************************


    HDML Lifestyle Menu Object.


changes log
when       who      what
12.3.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLENTERMESSAGEOBJECT_API
#define HDMLENTERMESSAGEOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlEnterMessage_o  {
  private:
    void            init();

  public:
    hdmlEnterMessage_o();                              // Default constructor.
    hdmlEnterMessage_o(const hdmlEnterMessage_o&);    // Copy constructor.
   ~hdmlEnterMessage_o();                              // Default destructor.
    hdmlEnterMessage_o& operator = (const hdmlEnterMessage_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
