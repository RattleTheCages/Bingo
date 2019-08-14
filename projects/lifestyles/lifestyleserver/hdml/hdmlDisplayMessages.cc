/**  hdmlDisplayMessages.cc  **((***********************************************


changes log
when       who      what
11.25.99   Dan      Creation.

*******************************************************************************/


#include "../hdml/hdmlDisplayMessages.h"
#include "../hdml/hdmlInterface.h"

#include "../servers/lifestyleserver.h"


extern hdmlInterface_o* hdmlInterface;
extern lifestyleserver_o* lifestyleserver;

hdmlDisplayMessages_o::hdmlDisplayMessages_o()  {
    (void)init();
}

hdmlDisplayMessages_o::~hdmlDisplayMessages_o()  {}

void hdmlDisplayMessages_o::init()  {}

void hdmlDisplayMessages_o::page(lifestyleSession_o& lifestyleSession,string_o& s)  {
int x,y;
string_o t;

::hdmlInterface->hdmlServerHeader.page(s);


s<< "<HDML VERSION=2.0 PUBLIC=TRUE MARKABLE=TRUE TTL=0>\n";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<< "\n";
s<< "<CHOICE NAME=\"DisplayMessages\">\n";
s<< "<ACTION TYPE=ACCEPT>\n";
s<< "<LINE>" << lifestyleSession.numberOfDatedMessages() << " Messages: ";
for(x=0;x<lifestyleSession.numberOfDatedMessages();x++)  {
s<< "<CE TASK=\"GO\" DEST=\"/Message" << x << "\"><LINE>" << lifestyleSession.SortedDatedMessageQueue[x]->message() << "\n";
}

s<< "<CE TASK=\"GO\" DEST=\"/ENTER_MESSAGE\"><LINE>Enter Instant Message\n";
s<< "</CHOICE>\n";
s<< "\n";
s<< "</HDML>";

}

/******************************************************************************/
