/**  hdmlDisplayUrgentMessage.h  *************************************************


    HDML Emergancy Broadcast Object.


changes log
when       who      what
10.8.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLMESSAGEOBJECT_API
#define HDMLMESSAGEOBJECT_API


#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlDisplayUrgentMessage_o  {
  private:
    void            init();

  public:
    hdmlDisplayUrgentMessage_o();                         // Default constructor.
    hdmlDisplayUrgentMessage_o(const hdmlDisplayUrgentMessage_o&);
                                                        // Copy constructor.
   ~hdmlDisplayUrgentMessage_o();                         // Default destructor.
    hdmlDisplayUrgentMessage_o& operator = (const hdmlDisplayUrgentMessage_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
