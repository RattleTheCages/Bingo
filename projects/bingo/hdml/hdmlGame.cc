/**  hdmlGame.cc  **((**********************************************************




*******************************************************************************/

#include "../hdml/hdmlGame.h"
#include "../hdml/hdmlInterface.h"
#include "../servers/bingodealer.h"


extern hdmlInterface_o* hdmlInterface;

extern bingodealer_o bingodealer;

hdmlGame_o::hdmlGame_o()  {
    (void)init();
}

hdmlGame_o::~hdmlGame_o()  {}

void hdmlGame_o::init()  {}

void hdmlGame_o::page(const bingoSession_o& bingoSession,string_o& s)  {
int x;


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlViewCards_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO!</B><BR>\n";
s<<"Playing Game " << ::bingodealer.currentGameId() << ".<BR>\n";
s<<"Game Attendance " << ::bingodealer.numberOfPlayers() << ".<BR>\n";
s<<"Game Jack Pot " << "xx" << ".<BR>\n";
s<<"_B__I__N__G__O<BR>\n";

for(x=0;x<5;x++)  {
if(bingoSession.bingocard().Bx[x] == 1)  s << " XX";
else  s<<" " << bingoSession.bingocard().B[x];
if(bingoSession.bingocard().Ix[x] == 1)  s << " XX";
else  s<<" " << bingoSession.bingocard().I[x];
if(bingoSession.bingocard().Nx[x] == 1)  s << " XX";
else  s<<" " << bingoSession.bingocard().N[x];
if(bingoSession.bingocard().Gx[x] == 1)  s << " XX";
else  s<<" " << bingoSession.bingocard().G[x];
if(bingoSession.bingocard().Ox[x] == 1)  s << " XX";
else  s<<" " << bingoSession.bingocard().O[x];
if(x<4)  s<<"<BR>\n";
}


s<<"            <CE VALUE=\"~~input_o:~command=game" << bingoSession.transactions() << "\"> Check Game\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
