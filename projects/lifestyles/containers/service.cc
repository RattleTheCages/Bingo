/**  service.cc  ***************************************************************

changes log:
when       who     what
10.7.99    Dan     Creation. 
10.22.99   Dan     Added:    Data member class.


*******************************************************************************/


#include "../containers/service.h"
#include "../../library/lib/parse/parse.h"

service_o::service_o()  {}

service_o::~service_o()  {}

void service_o::clear()  {
    Type = "";
    Lifestyle = "";
    Class = "";
    Name = "";
    Url = "";
    Description = "";
}


service_o& service_o::operator = (const service_o& s)  {
    Type =        s.Type;
    Lifestyle =   s.Lifestyle;
    Class =       s.Class;
    Name =        s.Name;
    Url =         s.Url;
    Description = s.Description;

    return *this;
}

void service_o::operator >> (string_o& s) const  {
    s << "\nservice_o:";
    s << '\n' << SERVICE_TYPE << '=' << Type;
    s << '\n' << SERVICE_LIFESTYLE << '=' << Lifestyle;
    s << '\n' << SERVICE_CLASS << '=' << Class;
    s << '\n' << SERVICE_NAME << '=' << Name;
    s << '\n' << SERVICE_URL << '=' << Url;
    s << '\n' << SERVICE_DESCRIPTION << '=' << Description;
    s << '\n';
}

void service_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(SERVICE_TYPE,        Type);
    (void)parse.it(SERVICE_LIFESTYLE,   Lifestyle);
    (void)parse.it(SERVICE_CLASS,       Class);
    (void)parse.it(SERVICE_NAME,        Name);
    (void)parse.it(SERVICE_URL,         Url);
    (void)parse.it(SERVICE_DESCRIPTION, Description);
}

string_o& operator << (string_o& s,const service_o& a)  {
    a >> s;
    return s;
}


/******************************************************************************/
