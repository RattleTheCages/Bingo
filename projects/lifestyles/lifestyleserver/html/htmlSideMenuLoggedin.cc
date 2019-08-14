/**  htmlSideMenuLoggedin.cc  **************************************************


changes log
when       who      what
12.4.99    Dan      Creation.


*******************************************************************************/


#include "../../html/htmlTelluric.h"
#include "../html/htmlSideMenuLoggedin.h"
#include "../servers/lifestyleserver.h"



extern htmlTelluric_o* htmlTelluric;
extern lifestyleserver_o* lifestyleserver;


htmlSideMenuLoggedin_o::htmlSideMenuLoggedin_o()  {
    (void)init();
}

htmlSideMenuLoggedin_o::~htmlSideMenuLoggedin_o()  {}

void htmlSideMenuLoggedin_o::init()  {}


void htmlSideMenuLoggedin_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x,y;
string_o t;


s<< "<!--  htmlSideMenuLoggedin_o::page()  -->\n\n";

s<< ::htmlTelluric->fontData() << "Lifestyle Menu<br><br>\n";

for(y=0;y<lifestyleserver->NumberOfLifestyleItems;y++)  {
s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "/";
s<< lifestyleserver->LifestyleItems[y].Name << "?";

t="";
lifestyleSession.passcode() >> t;
(void)::htmlTelluric->ennet(t);
s << t;

s<< "'>";
s<< lifestyleserver->LifestyleItems[y].Name << "</a><br>\n";
}


s<< "<br>";


s<< "<a href='" << ::htmlTelluric->transactionServerURL();
s<< "/EnterMessage'>";
s<< "Send Message</a>\n";

s<< "<br>";

s<< "<a href='" << ::htmlTelluric->transactionServerURL();
s<< "/EnterUrgentMessage?";
t="";
lifestyleSession.passcode() >> t;
(void)::htmlTelluric->ennet(t);
s << t;
s << "'>Urgent Message</a>\n";

s<< "<br>";

s<< "<a href='" << ::htmlTelluric->transactionServerURL();
s<< "/ServerManifest'>";
s<< "Server Manifest</a>\n";


s<< "<br>";


}


/******************************************************************************/
