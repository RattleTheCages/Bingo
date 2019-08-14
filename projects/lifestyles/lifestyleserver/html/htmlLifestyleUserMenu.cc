/**  htmlLifestyleUserMenu.cc  *************************************************


changes log
when       who      what
10.7.99    Dan      Creation.


*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../servers/lifestyleserver.h"

#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlLifestyleUserMenu.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o*  htmlInterface;
extern lifestyleserver_o*  lifestyleserver;

htmlLifestyleUserMenu_o::htmlLifestyleUserMenu_o()  {
    (void)init();
}

htmlLifestyleUserMenu_o::~htmlLifestyleUserMenu_o()  {}

void htmlLifestyleUserMenu_o::init()  {
}

void htmlLifestyleUserMenu_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x;
string_o t;


(void)::htmlInterface->htmlStencil.pageIn(lifestyleSession,"Lifestyle User Menu",s);
  

s<< ::htmlTelluric->fontEmph() << "Lifestyle LifestyleUserMenu.</font><br>\n";
s<< "pda id: " << lifestyleSession.id() << "<br>\n";
s<< "lifestyle: " << lifestyleserver->LifestyleItems[lifestyleSession.state()].Name;
s<< "<br>\n";
s<< "<br>";

s<< "Current Lifestyle Services Selected:<br>";
for(x=0;x<LIFESTYLESERVER_MAX_NUMBER_OF_SERVICES;x++)  {
if(lifestyleSession.servicesMap(lifestyleSession.state(),x))
    s<< lifestyleserver->Services[x].name() << "<br>\n";
}
s<< "<br>";
s<< "<br>";
s<< "<br>\n";


s<< "<br>";
s<< "<br>";


(void)::htmlInterface->htmlStencil.pageOut(s);

}



/******************************************************************************/
