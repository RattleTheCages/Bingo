/**  hdmlTakingBets.cc  **********************************************************




*******************************************************************************/

#include "../hdml/hdmlTakingBets.h"
#include "../hdml/hdmlInterface.h"
#include "../servers/bingodealer.h"

extern hdmlInterface_o* hdmlInterface;
extern bingodealer_o bingodealer;

hdmlTakingBets_o::hdmlTakingBets_o()  {
    (void)init();
}

hdmlTakingBets_o::~hdmlTakingBets_o()  {}

void hdmlTakingBets_o::init()  {}

void hdmlTakingBets_o::page(const bingoSession_o& bingoSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlTakingBets_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>Air Ball BINGO!</B><BR>\n";
s<<"Players are entering game " << ::bingodealer.currentGameId() << ".<BR>\n";
s<<"There are currently " << ::bingodealer.numberOfPlayers() << " players.<BR>\n";
s<<"            <CE VALUE=\"~~input_o:~command=game" << bingoSession.transactions() << "\"> Check Game\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
