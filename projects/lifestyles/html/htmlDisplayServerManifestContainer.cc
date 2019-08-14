/**  htmlDisplayServerManifestContainer.h  *************************************


changes log
when       who      what
10.28.99   Dan      Creation.


*******************************************************************************/


#include "../html/htmlTelluric.h"
#include "../html/htmlDisplayServerManifestContainer.h"


extern htmlTelluric_o* htmlTelluric;


htmlDisplayServerManifestContainer_o::htmlDisplayServerManifestContainer_o()  {}

htmlDisplayServerManifestContainer_o::~htmlDisplayServerManifestContainer_o() {}


void htmlDisplayServerManifestContainer_o::page(const serverManifest_o& serverManifest,string_o& s)  {



s<< "<table cellspacing='2' border='1'><tr>";
s<< "<td colspan='4'>" << htmlTelluric->fontExSmall() << "Server Manifest</font></td>\n";
s<< "</tr>";

s<< "<tr>\n";
s<< "<td>";
s<< htmlTelluric->fontSmall() << serverManifest.name() << "</font></td><td>\n";
s<< htmlTelluric->fontExSmall() << "Name</font></td>";

s<< "<td align=right>" << htmlTelluric->fontExSmall() << "Id</font></td><td>";
s<< htmlTelluric->fontSmall() << serverManifest.id() << "</font></td>\n";
s<< "</tr>\n";

s<< "<tr>\n";
s<< "<td>" << htmlTelluric->fontSmall() << serverManifest.state() << "</font></td>\n";
s<< "<td>" << htmlTelluric->fontExSmall() << "State</font></td>";

s<< "<td>" << htmlTelluric->fontExSmall() << "ParentId</font></td><td align=right>";
s<< htmlTelluric->fontSmall() << serverManifest.parentid() << "</font></td>\n";
s<< "</tr>\n";

s<< "<tr>\n";
s<< "<td>" << htmlTelluric->fontSmall() << serverManifest.type() << "</font></td>\n";
s<< "<td>" << htmlTelluric->fontExSmall() << "Type</font></td>";

s<< "<td align=right>" << htmlTelluric->fontExSmall() << "Location</font></td><td>";
s<< htmlTelluric->fontSmall() << serverManifest.location() << "</font></td>\n";
s<< "</tr>\n";

s<< "<tr>\n";
s<< "<td>" << htmlTelluric->fontSmall() << serverManifest.numberProcessed() << "</font></td>\n";
s<< "<td>" << htmlTelluric->fontExSmall() << "Processed</font></td>";

s<< "<td align=right>" << htmlTelluric->fontExSmall() << "Ip</font></td><td>";
s<< htmlTelluric->fontSmall() << serverManifest.ip() << "</font></td>\n";
s<< "</tr>\n";

s<< "<tr>\n";
s<< "<td></td>\n";
s<< "<td>" << htmlTelluric->fontExSmall() << "UpTime</font></td>";

s<< "<td align=right>" << htmlTelluric->fontExSmall() << "Port</font></td><td>";
s<< htmlTelluric->fontSmall() << serverManifest.port() << "</font></td>\n";
s<< "</tr>\n";

s<< "</table>\n\n";

s<< "\n\n";

}


/******************************************************************************/
