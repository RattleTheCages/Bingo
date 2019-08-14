/**  htmlChangeDynamicMenu.cc  *************************************************



changes log
when       who      what
12.4.99    Dan      Creation.
12.11.99   Dan      Added:    Action Times.

*******************************************************************************/


#include "../../containers/actdate.h"

#include "../servers/lifestyleserver.h"

#include "../../../library/lib/string/string.h"
#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlChangeDynamicMenu.h"


extern htmlTelluric_o*   htmlTelluric;
extern htmlInterface_o*  htmlInterface;
extern lifestyleserver_o*  lifestyleserver;

htmlChangeDynamicMenu_o::htmlChangeDynamicMenu_o()  {
    (void)init();
}

htmlChangeDynamicMenu_o::~htmlChangeDynamicMenu_o()  {}

void htmlChangeDynamicMenu_o::init()  {}

void htmlChangeDynamicMenu_o::page(const lifestyleItem_o& lifestyleItem, const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x,y;
int offset1;
string_o a,b,t;
actdate_o actdate;


t = lifestyleItem.name();
for(y=0;y<lifestyleserver->numberOfLifestyleItems();y++)  {
if(t.contains(lifestyleserver->LifestyleItems[y].name()))  break;
}


s<< "<!--  htmlChangeDynamicMenu_o::page()  -->";


t = "Change Lifestyle ";
t << lifestyleItem.name();
t << " Menu Settings.";
(void)::htmlInterface->htmlStencil.pageIn(lifestyleSession,t.string(),s);


s<< ::htmlTelluric->fontEmph() << t << "</font><br>\n";
s<< "pda id: " << lifestyleSession.id() << "<br>\n";
s<< "<br>";
s<< "Please choose your lifestyle settings.<br>\n";
s<< "<br>";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "/SaveLifestyleDynamicMenuChanges?" <<"' method='POST'>";

s<< "<input type='hidden' name='" << PASSCODE_OBJECT << "' value='";
t="";
lifestyleSession.passcode() >> t;
(void)::htmlTelluric->ennet(t);
t << "\n";
lifestyleItem >> t;
s << t << "'>\n";

s<< ::htmlTelluric->fontGreen() << "Lifestyle: " << lifestyleItem.name() << "</font><br>\n";


s<< "Please enter your service selections for your ";
s<< lifestyleItem.name();
s<< " lifestyle:<br>";

s<< "<table border=1 cellspacing=1 cellpadding=1>";

s<< "<tr>";
for(x=0;x<lifestyleserver->numberOfServices();x++)  {

t = "";
t<< "<td><input type='checkbox'";
if(lifestyleSession.servicesMap(y,x))  t<< " CHECKED"; 
t<< " NAME='cb'";
t<< " VALUE='" << lifestyleserver->Services[x].name() << "'>";
if(lifestyleSession.registeredUser())  {
t<< "<a href='" << ::htmlTelluric->transactionServerURL();
t<< "/ExamineService?" << lifestyleItem.name();
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

t << "</td>\n";

if((x % 5) == 4)  {
    t<< "</tr><tr>\n";
}


s<< t;

}

s<< "</tr></table>\n";



if(y<LIFESTYLESESSION_ADDRESS_OBJECT_MAX)  {
s<< "<br>";
s<< "<br>";
s<< "If there is an address associated with lifestyle ";
s<< lifestyleItem.name();
s<< ", please enter it.<br>\n";
s<< " zipcode:";
s<< "<input type='text' size='20' name='address_o.zip' value='";
s<< lifestyleSession.address(y).zip();
s<< "'><br>\n";
}


offset1 = LIFESTYLESESSION_ACTDATE_OBJECT_MAX/LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;



if(y<LIFESTYLESESSION_ACTDATE_OBJECT_MAX)  {
s<< "Please enter the time you leave ";
s<< lifestyleItem.name();
s<< ".  Please format  23:59:59<br>";
s<< "<input type='text' size='10' name='" << ACTDATE_OBJECT << "' value='";
lifestyleSession.actdate(y).time(s);
s<< "'><br>\n";
}
if(y+(offset1*1)<LIFESTYLESESSION_ACTDATE_OBJECT_MAX)  {
s<< "Please enter the time you return to ";
s<< lifestyleItem.name();
s<< ".  Please format  23:59:59<br>";
s<< "<input type='text' size='10' name='" << ACTDATE_OBJECT << "' value='";
lifestyleSession.actdate(y+offset1*1).time(s);
s<< "'><br>\n";
}
if(y+(offset1*2)<LIFESTYLESESSION_ACTDATE_OBJECT_MAX)  {
s<< "Please enter the time you leave to ";
s<< lifestyleItem.name();
s<< ".  Please format  23:59:59<br>";
s<< "<input type='text' size='10' name='" << ACTDATE_OBJECT << "' value='";
lifestyleSession.actdate(y+offset1*2).time(s);
s<< "'><br>\n";
}
if(y+(offset1*3)<LIFESTYLESESSION_ACTDATE_OBJECT_MAX)  {
s<< "Please enter the time you return to ";
s<< lifestyleItem.name();
s<< ".  Please format  23:59:59<br>";
s<< "<input type='text' size='10' name='" << ACTDATE_OBJECT << "' value='";
lifestyleSession.actdate(y+offset1*3).time(s);
s<< "'><br>\n";
}


s<< "<br>";
s<< "<input type='submit' size='40' name='cldm_submit' value='Save Lifestyle " << lifestyleItem.name() << " Menu Changes'>\n";
s<< "</form>\n";

(void)::htmlInterface->htmlStencil.pageOut(s);

}



/******************************************************************************/
