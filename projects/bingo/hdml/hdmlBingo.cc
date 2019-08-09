/**  hdmlBingo.cc  **********************************************************




*******************************************************************************/

#include "../hdml/hdmlBingo.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlBingo_o::hdmlBingo_o()  {
    (void)init();
}

hdmlBingo_o::~hdmlBingo_o()  {}

void hdmlBingo_o::init()  {}

void hdmlBingo_o::page(const bingoSession_o& bingoSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlBingo_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO!</B><BR>\n";
s<<" Someone has BINGO!!<BR>\n";
s<<"            <CE VALUE=\"~~input_o:~command=menu\"> Menu\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
