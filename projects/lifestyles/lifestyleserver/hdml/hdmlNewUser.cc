/**  hdmlNewUser.cc  **((*******************************************************



changes log
when       who      what
9.9.99     Dan      Creation.

*******************************************************************************/

#include "../hdml/hdmlNewUser.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlNewUser_o::hdmlNewUser_o()  {
    (void)init();
}

hdmlNewUser_o::~hdmlNewUser_o()  {}

void hdmlNewUser_o::init()  {}

void hdmlNewUser_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {


::hdmlInterface->hdmlServerHeader.page(s);

s<< "<HDML VERSION=2.0 PUBLIC=TRUE TTL=0>\n";
s<< "<DISPLAY>\n";
s<< "\n";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << ::hdmlInterface->transactionServerPath() << "\">\n";
s<< "<ACTION TYPE=ACCEPT LABEL=\"DONE\" GO=\"" << ::hdmlInterface->transactionServerPath() << "/lifestylemenu?" << lifestyleSession.transactions() << "\">\n";
s<< "<CENTER>Welcome New \n";
s<< "<CENTER>Lifestyles User!\n";
s<< "<LINE>Userid: " << lifestyleSession.passcode().userid() << "\n";
s<< "<LINE>Password: " << lifestyleSession.passcode().password() << "\n";
s<< "<WRAP>Please point your full-sized computer browser at:\n";
s<< "<WRAP>" << ::hdmlInterface->transactionServerPath() << "\n";
s<< "<WRAP>Enter the above information where instructed.\n";
s<< "</DISPLAY>\n";
s<< "\n";
s<< "</HDML>";

}

/******************************************************************************/
