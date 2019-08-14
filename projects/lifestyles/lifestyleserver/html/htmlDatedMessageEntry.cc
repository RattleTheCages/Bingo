/**  htmlDatedMessageEntry.cc  *************************************************


changes log
when       who      what
11.24.99   Dan      Creation.


*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../../containers/datedMessage.h"

#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlDatedMessageEntry.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o*  htmlInterface;

htmlDatedMessageEntry_o::htmlDatedMessageEntry_o()  {
    (void)init();
}

htmlDatedMessageEntry_o::~htmlDatedMessageEntry_o()  {}

void htmlDatedMessageEntry_o::init()  {
}

void htmlDatedMessageEntry_o::page(const datedMessage_o& datedMessage,string_o& s)  {

s<< "<html><head>";

s<< "<title>Dated Message Entry</title>\n";

s<< "</head>\n<body background=\"" << ::htmlInterface->rotatingBackgroundURL() << "\">";

s<< "<img src=\"" << ::htmlTelluric->staticServerURL() << "/images/infoorbit.gif\">\n";

s<< "<br><br>";




s<< ::htmlTelluric->fontEmph() << "Welcome.  Use this page to send a message to a CellScape user's PDA. ";
s<< "Your message can be delivered instantly, like a page.  ";
s<< "Or you can schedule the time when the message is to be delivered, like a personal dispatch system.</font><br>\n";
s<< "If you would like to see the messages scheduled for your PDA, \n";
s<< "<a href='" << ::htmlTelluric->transactionServerURL() << "'> follow this link, </a> and login with your passcode.<br>\n";
s<< "<br>";
s<< "<br>";
s<< "<br>";
s<< "<form action='" << ::htmlTelluric->transactionServerURL() << "DatedMessageEntry?" << "' method='POST' name='datedMessage_o:'>";

s<< ::htmlTelluric->fontText() << "Please enter the Lifestyles Userid this message is to be delivered.</font><br>\n";
if(datedMessage.valid() != 1)  {
s<< ::htmlTelluric->fontRed() << "Lifestyles Userid not found, please check the Lifestyles Userid and try again.<br></font>\n";
}
s<< "<input type='text' size='10' name='" << DATEDMESSAGE_ID << "' value='" << datedMessage.id() << "'><br><br>\n";

s<< ::htmlTelluric->fontText() << "Please enter your message.<br></font>\n";
s<< "<TEXTAREA NAME='" << DATEDMESSAGE_MESSAGE << "' ROWS=2 COLS=80>" << datedMessage.message() << "</TEXTAREA>\n";

s<< "<br><br>";


s<< ::htmlTelluric->fontText() << "Please enter the time and date this message is to be delivered.<br>\n";

s<< "Hour";
s<< "<SELECT NAME='" << DATEDMESSAGE_HOUR << "' SIZE=1>\n";
s<< "<OPTION SELECTED value='-1'>Instant";
s<< "<OPTION value='0'>12 am";
s<< "<OPTION value='1'>1 am";
s<< "<OPTION value='2'>2 am";
s<< "<OPTION value='3'>3 am";
s<< "<OPTION value='4'>4 am";
s<< "<OPTION value='5'>5 am";
s<< "<OPTION value='6'>6 am";
s<< "<OPTION value='7'>7 am";
s<< "<OPTION value='8'>8 am";
s<< "<OPTION value='9'>9 am";
s<< "<OPTION value='10'>10 am";
s<< "<OPTION value='11'>11 am";
s<< "<OPTION value='12'>12 pm";
s<< "<OPTION value='13'>1 pm";
s<< "<OPTION value='14'>2 pm";
s<< "<OPTION value='15'>3 pm";
s<< "<OPTION value='16'>4 pm";
s<< "<OPTION value='17'>5 pm";
s<< "<OPTION value='18'>6 pm";
s<< "<OPTION value='19'>7 pm";
s<< "<OPTION value='20'>8 pm";
s<< "<OPTION value='21'>9 pm";
s<< "<OPTION value='22'>10 pm";
s<< "<OPTION value='23'>11 pm";
s<< "</select>\n";

s<< "Minute";
s<< "<SELECT NAME='" << DATEDMESSAGE_MINUTE << "' SIZE=1>\n";
s<< "<OPTION SELECTED value='-1'>Now";
s<< "<OPTION value='0'>00";
s<< "<OPTION value='5'>05";
s<< "<OPTION value='10'>10";
s<< "<OPTION value='15'>15";
s<< "<OPTION value='20'>20";
s<< "<OPTION value='25'>25";
s<< "<OPTION value='30'>30";
s<< "<OPTION value='35'>35";
s<< "<OPTION value='40'>40";
s<< "<OPTION value='45'>45";
s<< "<OPTION value='50'>50";
s<< "<OPTION value='55'>55";
s<< "</select>\n";

s<< "Month";
s<< "<SELECT NAME='" << DATEDMESSAGE_MONTH << "' SIZE=1>\n";
s<< "<OPTION SELECTED value='0'> ";
s<< "<OPTION value='1'>Jan";
s<< "<OPTION value='2'>Feb";
s<< "<OPTION value='3'>Mar";
s<< "<OPTION value='4'>Apr";
s<< "<OPTION value='5'>May";
s<< "<OPTION value='6'>Jun";
s<< "<OPTION value='7'>Jul";
s<< "<OPTION value='8'>Aug";
s<< "<OPTION value='9'>Sep";
s<< "<OPTION value='10'>Oct";
s<< "<OPTION value='11'>Nov";
s<< "<OPTION value='12'>Dec";
s<< "</SELECT>\n";
s<< "Day";
s<< "<SELECT NAME='" DATEDMESSAGE_DAY << "' SIZE=1>\n";
s<< "<OPTION SELECTED value='0'> ";
s<< "<OPTION value='1'>1";
s<< "<OPTION value='2'>2";
s<< "<OPTION value='3'>3";
s<< "<OPTION value='4'>4";
s<< "<OPTION value='5'>5";
s<< "<OPTION value='6'>6";
s<< "<OPTION value='7'>7";
s<< "<OPTION value='8'>8";
s<< "<OPTION value='9'>9";
s<< "<OPTION value='10'>10";
s<< "<OPTION value='11'>11";
s<< "<OPTION value='12'>12";
s<< "<OPTION value='13'>13";
s<< "<OPTION value='14'>14";
s<< "<OPTION value='15'>15";
s<< "<OPTION value='16'>16";
s<< "<OPTION value='17'>17";
s<< "<OPTION value='18'>18";
s<< "<OPTION value='19'>19";
s<< "<OPTION value='20'>20";
s<< "<OPTION value='20'>21";
s<< "<OPTION value='20'>22";
s<< "<OPTION value='20'>23";
s<< "<OPTION value='20'>24";
s<< "<OPTION value='20'>25";
s<< "<OPTION value='20'>26";
s<< "<OPTION value='20'>27";
s<< "<OPTION value='20'>28";
s<< "<OPTION value='20'>29";
s<< "<OPTION value='30'>30";
s<< "<OPTION value='31'>31";
s<< "</SELECT>\n";

s<< "<input type='submit' name='datedMessage_o.submit' value='Send Message'>\n";
s<< "</form>";
s<< "<br>";
s<< "<br>";
s<< "<br>";


s<<"</body>\n</html>\n\n";

}



/******************************************************************************/
