/**  hdmlDisplayMessages.h  ****************************************************


    HDML Display Messages Object.


changes log
when       who      what
11.25.99   Dan      Creation.


*******************************************************************************/

#ifndef HDMLDISPLAYMESSAGESOBJECT_API
#define HDMLDISPLAYMESSAGESOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlDisplayMessages_o  {
  private:
    void            init();

  public:
    hdmlDisplayMessages_o();                            // Default constructor.
    hdmlDisplayMessages_o(const hdmlDisplayMessages_o&);// Copy constructor.
   ~hdmlDisplayMessages_o();                            // Default destructor.
    hdmlDisplayMessages_o& operator = (const hdmlDisplayMessages_o&);
                                                        // Assignment operator.

    void page(lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
