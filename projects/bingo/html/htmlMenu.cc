/**  htmlMenu.cc  **************************************************************


changes log
when       who      what
3.23.99    Dan      Creation.


*******************************************************************************/

#include "../html/htmlMenu.h"
#include "../html/htmlInterface.h"
#include "../../library/lib/string/string.h"
#include "../servers/bingodealer.h"


extern htmlInterface_o*     htmlInterface;
extern bingodealer_o bingodealer;

htmlMenu_o::htmlMenu_o()  {
    (void)init();
}

htmlMenu_o::~htmlMenu_o()  {}

void htmlMenu_o::init()  {
}

void htmlMenu_o::page(const bingogame_o& bingogame,string_o& s)  {
int x;

s<< "<html><head>";
s<< "<meta http-equiv='refresh' content='4;url=";
s<< htmlInterface->transactionServerPath << "'>";
s<< "</head>\n<body>";

s<< htmlInterface->fontEmph << "<p>Dealer Id: </font>\n";
s<< ::bingodealer.id() << ".<br>\n";

s<< htmlInterface->fontEmph << "<p>State: </font>\n";
 if(::bingodealer.state() == BINGODEALER_STATE_CLOSED)  s<<"Closed";
 if(::bingodealer.state() == BINGODEALER_STATE_TAKING_BETS)  s<<"Taking Bets";
 if(::bingodealer.state() == BINGODEALER_STATE_PLAYING)  s<<"Playing";
 if(::bingodealer.state() == BINGODEALER_STATE_VOID)  s<<"Void";
 if(::bingodealer.state() == BINGODEALER_STATE_CLEARING)  s<<"Clearing";
 if(::bingodealer.state() == BINGODEALER_STATE_BINGO)  s<<"Bingo";
s<< ".<br>\n";

s<< htmlInterface->fontEmph << "<p>Game Id: </font>\n";
s<< ::bingodealer.currentGameId() << ".<br>\n";

s<< "</p><p>\n";
s<< htmlInterface->fontEmph << "Number Of Players: </font>\n";

   s<< ::bingodealer.numberOfPlayers() << ".<br>\n";


s<<"<TABLE cellspacing='4' cellpadding='4' border='4'>";

s<<"<TR>";
s<<"<TD>"<<htmlInterface->fontEmph << "B</FONT></TD>";
s<<"<TD>"<<htmlInterface->fontEmph << "I</FONT></TD>";
s<<"<TD>"<<htmlInterface->fontEmph << "N</FONT></TD>";
s<<"<TD>"<<htmlInterface->fontEmph << "G</FONT></TD>";
s<<"<TD>"<<htmlInterface->fontEmph << "O</FONT></TD>";
s<<"</TR>";

for(x=0;x<15;x++)  {
    s<<"<TR>";

    s<<"<TD>";
    s<< htmlInterface->fontEmph;
    if(bingogame[x+1])  s<< x+1;
    else s<<"..";
    s<<"</FONT></TD>\n";

    s<<"<TD>";
    s<< htmlInterface->fontEmph;
    if(bingogame[x+1+15])  s<< x+15+1;
    else s<<"..";
    s<<"</FONT></TD>\n";

    s<<"<TD>";
    s<< htmlInterface->fontEmph;
    if(bingogame[x+1+30])  s<< x+30+1;
    else s<<"..";
    s<<"</FONT></TD>\n";

    s<<"<TD>";
    s<< htmlInterface->fontEmph;
    if(bingogame[x+1+45])  s<< x+45+1;
    else s<<"..";
    s<<"</FONT></TD>\n";

    s<<"<TD>";
    s<< htmlInterface->fontEmph;
    if(bingogame[x+1+60])  s<< x+60+1;
    else s<<"..";
    s<<"</FONT></TD>\n";

    s<<"</TR>\n";
}
s<<"</TR>\n";
s<<"</TABLE><BR>\n";


s<< "</p>\n";


s<<"</body>\n</HTML>\n\n";

}



/******************************************************************************/
