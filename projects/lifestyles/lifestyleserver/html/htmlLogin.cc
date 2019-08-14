/**  htmlLogin.cc  *************************************************************


changes log
when       who      what
10.7.99    Dan      Creation.
12.4.99    Dan      Added:    Use of the htmlStencil_o object.
12.23.99   Dan      Removed:  Server Manifest Display.


*******************************************************************************/


#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlLogin.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o* htmlInterface;


htmlLogin_o::htmlLogin_o()  {
    (void)init();
}

htmlLogin_o::~htmlLogin_o()  {}

void htmlLogin_o::init()  {}

void htmlLogin_o::page(passcode_o& passcode,string_o& s)  {


s<< "<!--  htmlLogin_o::page()  -->\n\n";


(void)::htmlInterface->htmlStencil.pageIn("CellScape Login.",s);



s<< ::htmlTelluric->fontEmph() << "Welcome.  Please login.</font><br>\n";
s<< "<br>";
s<< "<br>";
s<< ::htmlTelluric->fontText() << "If you are a new user, please point your Pager or PDA device to:<br></font>\n";
s<< ::htmlTelluric->fontEmph() << "http://204.131.41.3:4111<br></font>\n";
s<< ::htmlTelluric->fontText() << "Enter below the Userid and Password displayed in your Pager or PDA unit, to access activities.<br></font>\n";
s<< "<br>";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "UserLogin?" << "' method='POST'>";
s<< "<input type='hidden' name='passcode_o:'>\n";
if(!passcode.blank() && passcode.valid() != 1)  {
s<< ::htmlTelluric->fontRed() << "Userid not found, or Password invalid, please check your hand-held device and try again.<br></font>\n";
s<< ::htmlTelluric->fontSmall() << "For instructions on how to obtain your Userid and Password from your Hand-Held device, ";
s<< "<a href='" << ::htmlTelluric->staticServerURL() << "/XXXinstructionsXXX'>";
s<< "click here</a>.</font><br><br>\n";
}
s<< "Userid shown in your hand-held device:<br>\n";
s<< "<input type='text' size='12' name='" << PASSCODE_USERID << "' value='";
s<< passcode.userid() << "'><br>\n";
s<< "Password shown in your hand-held device:<br>\n";
s<< "<input type='text' size='12' name='" << PASSCODE_PASSWORD << "' value='";
s<< passcode.password() << "'><br>\n";
s<< "<input type='submit' name='passcode_o.submit' value='Login'>\n";
s<< "</form>";
s<< "<br>";
s<< "<br>";
s<< "<br>";


(void)::htmlInterface->htmlStencil.pageOut(s);


}


/******************************************************************************/
