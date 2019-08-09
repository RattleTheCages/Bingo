/**  hdmlInProgress.cc  **((**********************************************************




*******************************************************************************/

#include "../hdml/hdmlInProgress.h"
#include "../hdml/hdmlInterface.h"
#include "../servers/bingodealer.h"


extern bingodealer_o bingodealer;
extern hdmlInterface_o* hdmlInterface;

hdmlInProgress_o::hdmlInProgress_o()  {
    (void)init();
}

hdmlInProgress_o::~hdmlInProgress_o()  {}

void hdmlInProgress_o::init()  {}

void hdmlInProgress_o::page(const bingoSession_o& bingoSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"GameWait\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO! Waiting</B><BR>\n";
s<<"You have anteed for game " << ::bingodealer.nextGameId() << ".<BR>\n";
s<<"Game " << ::bingodealer.nextGameId() << " Will start in xx seconds.\n ";
s<<"            <CE VALUE=\"~~input_o:~command=game" << bingoSession.transactions() << "\"> Check Game\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
