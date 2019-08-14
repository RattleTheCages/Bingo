/**  hdmlEnterMessage.cc  **((*************************************************




changes log
when       who      what
12.3.99    Dan      Creation.


*******************************************************************************/

#include "../hdml/hdmlEnterMessage.h"
#include "../hdml/hdmlInterface.h"

#include "../servers/lifestyleserver.h"


extern hdmlInterface_o* hdmlInterface;
extern lifestyleserver_o* lifestyleserver;

hdmlEnterMessage_o::hdmlEnterMessage_o()  {
    (void)init();
}

hdmlEnterMessage_o::~hdmlEnterMessage_o()  {}

void hdmlEnterMessage_o::init()  {}

void hdmlEnterMessage_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {

::hdmlInterface->hdmlServerHeader.page(s);


s<< "<HDML VERSION=2.0 PUBLIC=TRUE MARKABLE=TRUE TTL=0>\n";
s<< "<ENTRY NAME=\"datedMessageEntery\" FORMAT=\"\\t\\o\\(MMMMMMMM\\)\">";
s<< "<ACTION TYPE=ACCEPT LABEL=\"SEND\"  GO=\"" << hdmlInterface->transactionServerPath() << "/EnterMessage\">\n";
s<< "Send Message:";
s<< "</ENTRY>\n";
s<< "\n";
s<< "</HDML>";

}

/******************************************************************************/
