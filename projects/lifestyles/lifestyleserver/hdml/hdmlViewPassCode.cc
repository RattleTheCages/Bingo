/**  hdmlViewPassCode.cc  **((**************************************************




*******************************************************************************/

#include "../hdml/hdmlViewPassCode.h"
#include "../hdml/hdmlInterface.h"

#include "../servers/lifestyleserver.h"


extern hdmlInterface_o* hdmlInterface;
extern lifestyleserver_o* lifestyleserver;

hdmlViewPassCode_o::hdmlViewPassCode_o()  {
    (void)init();
}

hdmlViewPassCode_o::~hdmlViewPassCode_o()  {}

void hdmlViewPassCode_o::init()  {}

void hdmlViewPassCode_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {


::hdmlInterface->hdmlServerHeader.page(s);

s<< "<HDML VERSION=2.0 PUBLIC=TRUE MARKABLE=TRUE TTL=0>\n";
s<< "<DISPLAY>";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << ::hdmlInterface->transactionServerPath() << "\">\n";
s<< "<ACTION TYPE=ACCEPT LABEL=\"DONE\" GO=\"" << ::hdmlInterface->transactionServerPath() << "?lifestylemenu" << lifestyleSession.transactions() << "\">\n";
s<< "<LINE>Userid:<LINE>";
s<< lifestyleSession.passcode().userid()<<"\n";
s<< "<LINE>Password:<LINE>";
s<< lifestyleSession.passcode().password()<<"\n";
s<<"</DISPLAY>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
