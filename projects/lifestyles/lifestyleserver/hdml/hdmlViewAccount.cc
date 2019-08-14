/**  hdmlViewAccount.cc  **********************************************************




*******************************************************************************/

#include "../hdml/hdmlViewAccount.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlViewAccount_o::hdmlViewAccount_o()  {
    (void)init();
}

hdmlViewAccount_o::~hdmlViewAccount_o()  {}

void hdmlViewAccount_o::init()  {}

void hdmlViewAccount_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlViewAccount_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER>BINGO! Player Account<BR>\n";
s<<"Assets:\n";
s<<"            <CE VALUE=\"~~input_o:~command=menu\"> Back To Bingo\n";
s<<"            <CE VALUE=\"~~input_o:~command=addFunds\"> Add Funds\n";
s<<"            <CE VALUE=\"~~input_o:~command=removeFunds\"> Remove Funds\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
