/**  hdmlMenu.cc  **((**********************************************************




*******************************************************************************/

#include "../hdml/hdmlMenu.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlMenu_o::hdmlMenu_o()  {
    (void)init();
}

hdmlMenu_o::~hdmlMenu_o()  {}

void hdmlMenu_o::init()  {}

void hdmlMenu_o::page(const bingoSession_o& bingoSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"EntranceMenu\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO! Start Here</B>\n";
s<<"            <CE VALUE=\"~~input_o:~command=joinGame\"> Join Game\n";
s<<"            <CE VALUE=\"~~input_o:~command=viewCards\"> View Cards\n";
s<<"            <CE VALUE=\"~~input_o:~command=newCards\"> New Cards\n";
s<<"            <CE VALUE=\"~~input_o:~command=viewAccount\"> View Account\n";
s<<"            <CE VALUE=\"~~input_o:~command=exitBingo\"> Exit Bingo\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
