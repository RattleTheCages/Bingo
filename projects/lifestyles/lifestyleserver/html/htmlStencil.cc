/**  htmlStencil.cc  ***********************************************************


changes log
when       who      what
12.4.99    Dan      Creation.

*******************************************************************************/


#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlStencil.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o* htmlInterface;


htmlStencil_o::htmlStencil_o()  {
    (void)init();
}

htmlStencil_o::~htmlStencil_o()  {}

void htmlStencil_o::init()  {}


void htmlStencil_o::pageIn(const lifestyleSession_o& lifestyleSession,const char* title,string_o& s)  {


s<< "<!--  htmlStencil_o::pageIn(" << title << ")  -->\n\n";


s<< "<html><head><title>" << title << "</title></head>\n\n";

s<< "<body background=\"" << ::htmlInterface->rotatingBackgroundURL() << "\">\n\n";



s<< "<table width=100% height=10% border=0 cellspacing=0 cellpadding=12>\n";
s<< "<tr><td>\n";

s<< "<img src=\"" << ::htmlInterface->logoURL() << "\">";

s<< "</td><td>";

s<< "<img src=\"" << ::htmlInterface->rotatingBannerURL() << "\">";

s<< "</td></tr>\n\n";

s<< "<td align=left nowrap width=10% height=75%>\n";
(void)::htmlInterface->htmlSideMenuLoggedin.page(lifestyleSession,s);
s<< "</td>\n\n";

s<< "<td align=left width=90% height=75%>\n\n";

}


void htmlStencil_o::pageIn(const char* title,string_o& s)  {


s<< "<!--  htmlStencil_o::pageIn(" << title << ")  -->\n\n";


s<< "<html><head><title>" << title << "</title></head>\n\n";

s<< "<body background=\"" << ::htmlInterface->rotatingBackgroundURL() << "\">\n\n";


s<< "<table width=100% height=10% border=0 cellspacing=0 cellpadding=12>\n";
s<< "<tr><td>\n";
s<< "<img src=\"" << ::htmlInterface->logoURL() << "\">";

s<< "</td><td>";

s<< "<img src=\"" << ::htmlInterface->rotatingBannerURL() << "\">";
s<< "</td></tr>\n\n";

s<< "<td align=left nowrap width=10% height=75%>\n";
(void)::htmlInterface->htmlSideMenu.page(s);
s<< "</td>\n\n";

s<< "<td align=left width=90% height=75%>\n\n";

}



void htmlStencil_o::pageOut(string_o& s)  {

s<< "<!-- htmlStencil_o::pageOut() -->\n\n";

s<< "</td></tr></table>\n\n";
s<< "</body>\n";
s<< "</html>\n\n";

s<< "<!--  Thank you.  -->\n\n";

}


/******************************************************************************/
