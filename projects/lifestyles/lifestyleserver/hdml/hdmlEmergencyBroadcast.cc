/**  hdmlEmergencyBroadcast.cc  **((********************************************



changes log
when       who      what
10.8.99    Dan      Creation.


*******************************************************************************/

#include "../hdml/hdmlEmergencyBroadcast.h"
#include "../hdml/hdmlInterface.h"

#include "../servers/lifestyleserver.h"


extern hdmlInterface_o* hdmlInterface;

extern lifestyleserver_o* lifestyleserver;

hdmlEmergencyBroadcast_o::hdmlEmergencyBroadcast_o()  {
    (void)init();
}

hdmlEmergencyBroadcast_o::~hdmlEmergencyBroadcast_o()  {}

void hdmlEmergencyBroadcast_o::init()  {}

void hdmlEmergencyBroadcast_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {


::hdmlInterface->hdmlServerHeader.page(s);


s<< "<HDML VERSION=2.0 PUBLIC=TRUE TTL=0>\n";
s<< "<DISPLAY>\n";
s<< "<ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<< "<ACTION TYPE=ACCEPT LABEL=\"DONE\" GO=\"?lifestylemenu" << lifestyleSession.transactions() << "\">\n";
s<<"<CENTER>Emergency Broadcast:\n";
s<<"<WRAP>"<<::lifestyleserver->emergencyBroadcast()<<"\n";
s<<"</DISPLAY>\n";
s<<"\n";
s<<"</HDML>";

}

/******************************************************************************/
