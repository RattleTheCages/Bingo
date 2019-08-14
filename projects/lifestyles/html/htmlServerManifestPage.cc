/**  htmlServerManifestPage.cc  ************************************************


changes log
when       who      what
12.4.99    Dan      Creation.


*******************************************************************************/


#include "../../library/lib/string/string.h"
#include "../html/htmlTelluric.h"
#include "../html/htmlServerManifestPage.h"

extern htmlTelluric_o* htmlTelluric;

htmlServerManifestPage_o::htmlServerManifestPage_o()  {
    (void)init();
}

htmlServerManifestPage_o::~htmlServerManifestPage_o()  {}

void htmlServerManifestPage_o::init()  {}

void htmlServerManifestPage_o::page(const serverManifest_o& serverManifest,string_o& s)  {


s<< "<!--  htmlServerManifestPage_o::page()  -->\n\n";

s<< "<html><head><title>Server Manifest</title></head>\n\n";

s<< "<body background=\"" << ::htmlTelluric->staticServerURL();
s<< "/site/images/bkg.binary.white.gif\">\n\n";


(void)::htmlTelluric->htmlDisplayServerManifest.page(serverManifest,s);

s<< "<br>";

s<< "</body>\n";
s<< "</html>\n\n";

s<< "<!--  Thank you.  -->\n\n";


}



/******************************************************************************/
