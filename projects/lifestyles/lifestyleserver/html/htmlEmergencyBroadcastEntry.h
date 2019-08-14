/**  htmlEmergencyBroadcastEntry.h  ********************************************


    HTML Emergency Broadcast Entry Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLEMERGENCYBROADCASTENTRYOBJECT_API
#define HTMLEMERGENCYBROADCASTENTRYOBJECT_API

#include "../../../library/lib/string/string.h"



class htmlEmergencyBroadcastEntry_o  {
  private:
    void          init();

  public:
    htmlEmergencyBroadcastEntry_o();                                    // Default constructor.
    htmlEmergencyBroadcastEntry_o(const htmlEmergencyBroadcastEntry_o&);                    // Copy constructor.
   ~htmlEmergencyBroadcastEntry_o();                                    // Default destructor.
    htmlEmergencyBroadcastEntry_o& operator = (const htmlEmergencyBroadcastEntry_o&);       // Asignment operator.

    void page(string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
