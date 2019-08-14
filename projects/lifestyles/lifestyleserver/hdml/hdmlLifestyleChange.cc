/**  hdmlLifestyleChange.cc  **((***********************************************


changes log
when       who      what
9.9.99     Dan      Creation.

*******************************************************************************/

#include "../hdml/hdmlLifestyleChange.h"
#include "../hdml/hdmlInterface.h"

#include "../servers/lifestyleserver.h"


extern hdmlInterface_o* hdmlInterface;
extern lifestyleserver_o* lifestyleserver;

hdmlLifestyleChange_o::hdmlLifestyleChange_o()  {
    (void)init();
}

hdmlLifestyleChange_o::~hdmlLifestyleChange_o()  {}

void hdmlLifestyleChange_o::init()  {}

void hdmlLifestyleChange_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x;

::hdmlInterface->hdmlServerHeader.page(s);

s<< "<HDML VERSION=2.0 PUBLIC=TRUE TTL=0>\n";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << ::hdmlInterface->transactionServerPath() << "\">\n";
s<< "<CHOICE NAME=\"LifestyleChangeMenu\">\n";
s<< "<ACTION TYPE=ACCEPT>\n";
s<< "<LINE>Choose Lifestyle:\n";
for(x=0;x<lifestyleSession.numberOfLifestyles();x++)  {
 s<< "<CE TASK=\"GO\" DEST=\"/lifestyleState" << ::lifestyleserver->LifestyleItems[x].Name;
 s<< "\"><LINE>" << ::lifestyleserver->LifestyleItems[x].Name<< "\n";
}

s<< "<CE TASK=\"GO\" DEST=\"/passcode" << lifestyleSession.transactions() << "\"><LINE>View Pass Code\n";
s<< "</CHOICE>\n";
s<< "\n";
s<< "</HDML>\n";

}

/******************************************************************************/
