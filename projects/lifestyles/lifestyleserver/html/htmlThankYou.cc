/**  htmlThankYou.cc  **********************************************************


changes log
when       who      what
10.7.99    Dan      Creation.


*******************************************************************************/


#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlThankYou.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o*  htmlInterface;


htmlThankYou_o::htmlThankYou_o()  {
    (void)init();
}

htmlThankYou_o::~htmlThankYou_o()  {}

void htmlThankYou_o::init()  {}


void htmlThankYou_o::page(string_o& s)  {
string_o t;

(void)::htmlInterface->htmlStencil.pageIn("Thank You.",s);


s<< "<!--  htmlThankYou_o::page()  -->\n\n";


s<< ::htmlTelluric->fontEmph() << "Thank You for using Lifestyles.</font><br>\n";
s<< "<br>";
s<< "<br>";
s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "'>Back<\a>\n";


(void)::htmlInterface->htmlStencil.pageOut(s);


}



/******************************************************************************/
