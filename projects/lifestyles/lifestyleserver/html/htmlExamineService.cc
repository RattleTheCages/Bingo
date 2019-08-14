/**  htmlExamineService.cc  ***********************************************************


changes log
when       who      what
11.11.99   Dan      Creation.


*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../servers/lifestyleserver.h"

#include "../../html/htmlTelluric.h"
#include "../html/htmlInterface.h"
#include "../html/htmlExamineService.h"


extern htmlTelluric_o*  htmlTelluric;
extern htmlInterface_o*  htmlInterface;
extern lifestyleserver_o*  lifestyleserver;

htmlExamineService_o::htmlExamineService_o()  {
    (void)init();
}

htmlExamineService_o::~htmlExamineService_o()  {}

void htmlExamineService_o::init()  {
}

void htmlExamineService_o::page(int service,const lifestyleSession_o& lifestyleSession,string_o& s)  {
int x;

s<< "<html><head>";
s<< "<title>Examine Service</title>";

s<< "</head>\n<body background=\"" << ::htmlInterface->rotatingBackgroundURL() << "\">";


s<< ::htmlTelluric->fontEmph() << "Examine Service.</font><br>\n";
s<< "pda id: " << lifestyleSession.id() << "<br>\n";
s<< "<br>\n";
s<< "<br>";

s<< "<table cellspacing='1' border='1' cellpadding='4'><tr>\n";
s<< "<td>name</td><td>type</td><td>class</td><td>description</td><td>url</td></tr><tr>\n";
s<< "<td>" << ::htmlTelluric->fontEmph() << lifestyleserver->Services[service].name() << "</font></td>\n";
s<< "<td>" << ::htmlTelluric->fontEmph() << lifestyleserver->Services[service].type() << "</font></td>\n";
s<< "<td>" << ::htmlTelluric->fontEmph() << lifestyleserver->Services[service].class_() << "</font></td>\n";
s<< "<td>" << ::htmlTelluric->fontEmph() << lifestyleserver->Services[service].description() << "</font></td>\n";
s<< "<td>" << ::htmlTelluric->fontEmph() << lifestyleserver->Services[service].url() << "</font></td>\n";

s<< "</tr></table>";

s<< "<br>";
s<< "<br>";
s<< "<br>\n";


s<< "<br>";
s<< "<br>";
s<< "<br>";


s<<"</body>\n</html>\n\n";

}



/******************************************************************************/
