/**  htmlEmergencyBroadcastEntry.cc  *******************************************


changes log
when       who      what
10.7.99    Dan      Creation.


*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlEmergencyBroadcastEntry.h"


extern htmlTelluric_o*     htmlTelluric;
extern htmlInterface_o*     htmlInterface;


htmlEmergencyBroadcastEntry_o::htmlEmergencyBroadcastEntry_o()  {
    (void)init();
}

htmlEmergencyBroadcastEntry_o::~htmlEmergencyBroadcastEntry_o()  {}

void htmlEmergencyBroadcastEntry_o::init()  {
}

void htmlEmergencyBroadcastEntry_o::page(string_o& s)  {
s<< "<html><head>";
s<< "</head>\n<body>";



s<< ::htmlTelluric->fontEmph() << "Emergency Broadcast Entry.</font><br>\n";
s<< "<br>";
s<< "<br>";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "EmergencyBroadcastingService?" << "' method='POST'>";
s<< "<input type='hidden' name='PassCode' value='2202'>\n";
s<< "Enter the emergency broadcast below.  The message must be less than 256 characters.<br>";
s<< "<input type='text' size='80' name='emergencybroadcast.message'><br>\n";
s<< "<br>Enter the zipcode or zipcodes for which this message applies.<br>";
s<< "<input type='text' size='10' name='emergencybroadcast.zipcode'><br>\n";
s<< "<input type='submit' name='passcode_o.submit' value='Send Emergency Message'>\n";
s<< "</form>";
s<< "<br>";
s<< "<br>";
s<< "<br>";



s<<"</body>\n</html>\n\n";

}



/******************************************************************************/
