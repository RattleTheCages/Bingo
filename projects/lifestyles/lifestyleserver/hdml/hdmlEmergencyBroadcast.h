/**  hdmlEmergencyBroadcast.h  *************************************************


    HDML Emergancy Broadcast Object.


changes log
when       who      what
10.8.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLEMERGENCYBROADCASTOBJECT_API
#define HDMLEMERGENCYBROADCASTOBJECT_API


#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlEmergencyBroadcast_o  {
  private:
    void            init();

  public:
    hdmlEmergencyBroadcast_o();                         // Default constructor.
    hdmlEmergencyBroadcast_o(const hdmlEmergencyBroadcast_o&);
                                                        // Copy constructor.
   ~hdmlEmergencyBroadcast_o();                         // Default destructor.
    hdmlEmergencyBroadcast_o& operator = (const hdmlEmergencyBroadcast_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
