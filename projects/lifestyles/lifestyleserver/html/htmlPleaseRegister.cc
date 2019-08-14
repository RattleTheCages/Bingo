/**  htmlPleaseRegister.cc  ****************************************************



changes log
when       who      what
12.10.99   Dan      Creation.


*******************************************************************************/


#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlPleaseRegister.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o* htmlInterface;


htmlPleaseRegister_o::htmlPleaseRegister_o()  {
    (void)init();
}

htmlPleaseRegister_o::~htmlPleaseRegister_o()  {}

void htmlPleaseRegister_o::init()  {}

void htmlPleaseRegister_o::page(const lifestyleSession_o& lifestyleSession,string_o& s)  {
string_o t;


s<< "<!--  htmlPleaseRegister_o::page()  -->\n\n";


(void)::htmlInterface->htmlStencil.pageIn("Please Register.",s);


s<< ::htmlTelluric->fontEmph() << "Welcome to Lifestyles.  Please Register.</font><br>\n";
s<< "<br>";
s<< "<br>";
s<< ::htmlTelluric->fontText() << "This is the page that will be used to register your PDA to lifestyles.  For now, Please just hit the submit button.<br></font>\n";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "PleaseRegister?" << "' method='POST'>";

s<< "<input type='hidden' name='" << PASSCODE_OBJECT << "' value='";
t="";
lifestyleSession.passcode() >> t;
t << "\n";
lifestyleSession.passcode() >> t;
s << t << "'>\n";
s<< "<input type='submit' name='register_o.submit' value='Please Register'>\n";
s<< "</form>";
s<< "<br>";
s<< "<br>";


(void)::htmlInterface->htmlStencil.pageOut(s);


}


/******************************************************************************/
