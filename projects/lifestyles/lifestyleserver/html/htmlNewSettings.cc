/**  htmlNewSettings.cc  *******************************************************


changes log
when       who      what
10.7.99    Dan      Creation.


*******************************************************************************/


#include "../../../library/lib/string/string.h"
#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlNewSettings.h"
#include "../servers/lifestyleserver.h"


extern htmlTelluric_o*   htmlTelluric;
extern htmlInterface_o*  htmlInterface;
extern lifestyleserver_o* lifestyleserver;

htmlNewSettings_o::htmlNewSettings_o()  {
    (void)init();
}

htmlNewSettings_o::~htmlNewSettings_o()  {}

void htmlNewSettings_o::init()  {
}

void htmlNewSettings_o::page(const lifestyleItem_o& lifestyleItem, const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x,y;
string_o a,b,t;


(void)::htmlInterface->htmlStencil.pageIn("Change Lifestyle Dynamic Menu Items",s);


s<< ::htmlTelluric->fontEmph() << "Change Lifestyle Dynamic Menu Item Settings.</font><br>\n";
s<< "pda id: " << lifestyleSession.id() << "<br>\n";
s<< "<br>";
s<< "Please choose your lifestyle settings.<br>\n";
s<< "<br>";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "/NewLifestyleDynamicMenuSettings?" <<"' method='POST'>";

s<< "<input type='hidden' name='" << PASSCODE_OBJECT << "' value='";
t="";
lifestyleSession.passcode() >> t;
(void)::htmlTelluric->ennet(t);
s << t << "'>\n";

for(y=0;y<lifestyleserver->NumberOfLifestyleItems && y<4;y++)  {
s<< ::htmlTelluric->fontGreen() << "Lifestyle: " << lifestyleserver->LifestyleItems[y].Name << "</font><br>\n";

if(y<2)  {
s<< "Please enter your ";
s<< lifestyleserver->LifestyleItems[y].Name;
s<< " zipcode:";
s<< "<input type='text' size='20' name='" << y << "address_o.zip' value='";
s<< lifestyleSession.address(y).zip();
s<< "'><br>\n";
}

s<< "Please enter your service selections for your ";
s<< lifestyleserver->LifestyleItems[y].Name;
s<< " lifestyle:<br>";

s<< "<table border=1 cellspacing=1 cellpadding=1>";

s<< "<tr>";
for(x=0;x<lifestyleserver->numberOfServices();x++)  {

t = "";
t<< "<td><input type='checkbox'";
if(lifestyleSession.servicesMap(y,x))  t<< " CHECKED"; 
t<< " NAME='" << y << "checkbox'";
t<< " VALUE='" << lifestyleserver->Services[x].name() << "'>";
if(lifestyleSession.registeredUser())  {
t<< "<a href='" << ::htmlTelluric->transactionServerURL();
t<< "/EXAMINE_SERVICE?" << lifestyleserver->LifestyleItems[y].Name;
t<< "::" << lifestyleserver->Services[x].name() << "::" << x;
t<< "'>";
t<< ::htmlTelluric->fontFix() << "";
t<< lifestyleserver->Services[x].name();
t<< "</font></a>";
}
else  {
t<< ::htmlTelluric->fontFix() << "";
t<< lifestyleserver->Services[x].name();
t<< "</font>";
}

if((x % 5) == 4)  {
    t<< "</tr><tr>";
}
t<< "\n";


s<< t;

}


s<< "</tr></table>";
s<< "<br>";
s<< "<br>";
s<< "<br>";

}

s<< "<input type='submit' size='40' name='newsettings_o.submit' value='Okay'>\n";
s<< "</form>\n";

(void)::htmlInterface->htmlStencil.pageOut(s);

}



/******************************************************************************/
