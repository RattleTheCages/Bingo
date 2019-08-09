/**  hdmlClosed.cc  **********************************************************




*******************************************************************************/

#include "../hdml/hdmlClosed.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o* hdmlInterface;

hdmlClosed_o::hdmlClosed_o()  {
    (void)init();
}

hdmlClosed_o::~hdmlClosed_o()  {}

void hdmlClosed_o::init()  {}

void hdmlClosed_o::page(const bingoSession_o& bingoSession,string_o& s)  {


s<< "HTTP/1.0 200 OK\n";
s<< "Content-Type: text/x-hdml\n\n";
s<<"<HDML VERSION=2.0 TTL=0 PUBLIC=TRUE>\n";
s<<"    <ACTION TYPE=PREV LABEL=BACK GO=\"" << hdmlInterface->transactionServerPath() << "\">\n";
s<<"        <CHOICE name=\"hdmlClosed_o\" KEY=\"v\" IDEFAULT=1>\n";
s<<"            <ACTION type=ACCEPT GO=\"?$v\">\n";
s<<"            <CENTER><B>BINGO! Closed.</B><BR>\n";
s<<"            You have entered a closed game.";
s<<"            <CE VALUE=\"~~input_o:~command=menu\"> Back To Bingo\n";
s<<"        </CHOICE>\n";
s<<"\n";
s<<"</HDML>\n";

}

/******************************************************************************/
