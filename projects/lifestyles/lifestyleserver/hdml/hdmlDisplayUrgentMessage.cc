/**  hdmlDisplayUrgentMessage.cc  **((*******************************************************



changes log
when       who      what
10.8.99    Dan      Creation.


*******************************************************************************/

#include "../hdml/hdmlDisplayUrgentMessage.h"
#include "../hdml/hdmlInterface.h"



extern hdmlInterface_o* hdmlInterface;


hdmlDisplayUrgentMessage_o::hdmlDisplayUrgentMessage_o()  {
    (void)init();
}

hdmlDisplayUrgentMessage_o::~hdmlDisplayUrgentMessage_o()  {}

void hdmlDisplayUrgentMessage_o::init()  {}

void hdmlDisplayUrgentMessage_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {

::hdmlInterface->hdmlServerHeader.page(s);

s<< "<HDML VERSION=2.0 PUBLIC=TRUE TTL=0>\n";
s<< "<DISPLAY>\n";
s<< "\n";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << hdmlInterface->transactionServerPath() << ">\n";
s<< "<ACTION TYPE=ACCEPT LABEL=\"DONE\" GO=\"/lifestylemenu" << lifestyleSession.transactions() << "\">\n";
s<< "<CENTER>Urgent Message:\n";
s<< "<WRAP>"<<lifestyleSession.message()<<"\n";
s<< "</DISPLAY>\n";
s<< "\n";
s<< "</HDML>\n";

}

/******************************************************************************/
