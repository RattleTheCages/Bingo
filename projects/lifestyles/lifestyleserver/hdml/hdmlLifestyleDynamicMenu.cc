/**  hdmlLifestyleDynamicMenu.cc  **((*************************************************

changes log
when       who      what
9.9.99     Dan      Creation.




*******************************************************************************/

#include "../hdml/hdmlLifestyleDynamicMenu.h"
#include "../hdml/hdmlInterface.h"

#include "../servers/lifestyleserver.h"


extern hdmlInterface_o* hdmlInterface;
extern lifestyleserver_o* lifestyleserver;

hdmlLifestyleDynamicMenu_o::hdmlLifestyleDynamicMenu_o()  {
    (void)init();
}

hdmlLifestyleDynamicMenu_o::~hdmlLifestyleDynamicMenu_o()  {}

void hdmlLifestyleDynamicMenu_o::init()  {}

void hdmlLifestyleDynamicMenu_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x,y;
string_o t;


::hdmlInterface->hdmlServerHeader.page(s);


s<< "<HDML VERSION=2.0 TTL=0 MARKABLE=TRUE>\n";
s<< "\n";
s<< "<CHOICE NAME=\"LifestyleDynamicMenu\">\n";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<< "<ACTION TYPE=ACCEPT>\n";
s<< "<LINE>Lifestyle: ";
s<< ::lifestyleserver->LifestyleItems[lifestyleSession.state()].Name << "\n";
for(x=0;x<LIFESTYLESERVER_MAX_NUMBER_OF_SERVICES;x++)  {
    t = ::lifestyleserver->Services[x].name();
    if(lifestyleSession.servicesMap(lifestyleSession.state(),x))  {
        if(*::lifestyleserver->Services[x].url() == '\0')  {
s<< "<CE TASK=\"GO\" DEST=\"";
s<< ::hdmlInterface->transactionServerPath() << "/?" << lifestyleSession.transactions();
s<< "\"><LINE>" << ::lifestyleserver->Services[x].name() << "\n";
        }
        else  {
s<< "<CE TASK=\"GOSUB\" DEST=\"" << ::lifestyleserver->Services[x].url() << "\"><LINE>" << ::lifestyleserver->Services[x].name();
if(t == "Messages")  {
s<< "{" << lifestyleSession.numberOfDatedMessages() << "}";
}
s<< "\n";
        }
    }
}

s<< "<CE TASK=\"GO\" DEST=\"";
s<< ::hdmlInterface->transactionServerPath();
s<< "LifestyleChange?";
s<< lifestyleSession.transactions() << "\"><LINE>Lifestyle Menu\n";
s<< "</CHOICE>\n";
s<< "\n";
s<< "</HDML>\n\n";


}

/******************************************************************************/
