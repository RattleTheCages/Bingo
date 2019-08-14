/**  htmlDisplayServerManifest.cc  *********************************************


changes log
when       who      what
10.29.99   Dan      Creation.


*******************************************************************************/


#include "../../library/lib/string/string.h"
#include "../html/htmlTelluric.h"
#include "../html/htmlDisplayServerManifest.h"

extern htmlTelluric_o* htmlTelluric;

htmlDisplayServerManifest_o::htmlDisplayServerManifest_o()  {}

htmlDisplayServerManifest_o::~htmlDisplayServerManifest_o()  {}


void htmlDisplayServerManifest_o::page(const serverManifest_o& serverManifest,string_o& s)  {


s<< "\n<!--  htmlDisplayServerManifest_o::page()  -->\n";

(void)::htmlTelluric->htmlDisplayServerManifestContainer.page(serverManifest,s);

s<< "<br>";

}



/******************************************************************************/
