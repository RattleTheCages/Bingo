/**  hdmlJoinGame.cc  **********************************************************




*******************************************************************************/

#include "../hdml/hdmlJoinGame.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlJoinGame_o::hdmlJoinGame_o()  {
    (void)init();
}

hdmlJoinGame_o::~hdmlJoinGame_o()  {}

void hdmlJoinGame_o::init()  {}

void hdmlJoinGame_o::page(const bingoSession_o& bingoSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlJoinGame_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO! Join Game</B>\n";
s<<"            <CE VALUE=\"~~input_o:~command=game\"> Ante and Join Game\n";
s<<"            <CE VALUE=\"~~input_o:~command=viewCards\"> View Cards\n";
s<<"            <CE VALUE=\"~~input_o:~command=newCards\"> New Cards\n";
s<<"            <CE VALUE=\"~~input_o:~command=viewAccount\"> View Account\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
