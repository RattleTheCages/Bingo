/**  htmlSideMenu.cc  **********************************************************


changes log
when       who      what
12.4.99    Dan      Creation.


*******************************************************************************/


#include "../../html/htmlTelluric.h"
#include "../html/htmlSideMenu.h"


extern htmlTelluric_o* htmlTelluric;


htmlSideMenu_o::htmlSideMenu_o()  {
    (void)init();
}

htmlSideMenu_o::~htmlSideMenu_o()  {}

void htmlSideMenu_o::init()  {}


void htmlSideMenu_o::page(string_o& s)  {


s<< "<!--  htmlSideMenu_o::page()  -->\n\n";

s<< ::htmlTelluric->fontData() << "Lifestyle Menu<br><br>\n";

s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "/Item1'>";
s<< "Item 1</a><br>\n";

s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "/Item2'>";
s<< "Item 2</a><br>\n";

s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "/Item3'>";
s<< "Item 3</a><br>\n";


s<< "<br>\n";


s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "/EnterMessage'>";
s<< "Send Message</a><br>\n";

s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "/ServerManifest'>";
s<< "Server Mainfest</a><br>\n";


}


/******************************************************************************/
