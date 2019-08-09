/**  hdmlViewCards.cc  **********************************************************




*******************************************************************************/

#include "../hdml/hdmlViewCards.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlViewCards_o::hdmlViewCards_o()  {
    (void)init();
}

hdmlViewCards_o::~hdmlViewCards_o()  {}

void hdmlViewCards_o::init()  {}

void hdmlViewCards_o::page(const bingoSession_o& bingoSession,string_o& s)  {
int x;


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlViewCards_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO! View Cards</B><BR>\n";
s<<"            B__I__N__G__O<BR>\n";
for(x=0;x<5;x++)  {
if(bingoSession.bingocard().Bx[x] == 1)  s << " X";
else  s<<" B" << bingoSession.bingocard().B[x];
if(bingoSession.bingocard().Ix[x] == 1)  s << " X";
else  s<<" I" << bingoSession.bingocard().I[x];
if(bingoSession.bingocard().Nx[x] == 1)  s << " X";
else  s<<" N" << bingoSession.bingocard().N[x];
if(bingoSession.bingocard().Gx[x] == 1)  s << " X";
else  s<<" G" << bingoSession.bingocard().G[x];
if(bingoSession.bingocard().Ox[x] == 1)  s << " X";
else  s<<" O" << bingoSession.bingocard().O[x];
if(x<4)  s<<"<BR>\n";
}
s<<"            <CE VALUE=\"~~input_o:~command=joinGame\"> Join Game\n";
s<<"            <CE VALUE=\"~~input_o:~command=newCards" << bingoSession.transactions() << "\"> New Cards\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
