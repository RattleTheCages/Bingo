/**  htmlSendMessage.cc  ***********************************************************


changes log
when       who      what
10.7.99    Dan      Creation.


*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlSendMessage.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o*  htmlInterface;

htmlSendMessage_o::htmlSendMessage_o()  {
    (void)init();
}

htmlSendMessage_o::~htmlSendMessage_o()  {}

void htmlSendMessage_o::init()  {
}

void htmlSendMessage_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {
s<< "<html><head>";
s<< "</head>\n<body>";


s<< ::htmlTelluric->fontEmph() << "Send Message.</font><br>\n";
s<< "<br>";
s<< "Phone Id:" << lifestyleSession.id() << "<br>\n";
//!!!!!s<< "Lifestyle:" << ::lifestyleserver->LifestyleItems[lifestyleSession.state()].Name;
s<< "<br>";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "EnterUrgentMessage?" << "' method='POST'>";
s<< "<input type='hidden' name='EnterUrgentMessage' value='2202'>\n";
s<< "Enter your message below.  The message must be less than 256 characters.<br>";
s<< "<input type='text' size='80' name='sendmessage_o.message'><br>\n";
s<< "<input type='submit' size='40' name='sendmessage_o.submit' value='Send Message'>\n";
s<< "</form>";
s<< "<br>";
s<< "<br>";
s<< "<br>";



s<<"</body>\n</html>\n\n";

}



/******************************************************************************/
