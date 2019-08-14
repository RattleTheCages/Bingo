/**  serverManifest.cc  ********************************************************



changes log
when       who     what
10.22.99   Dan     Creation. 


*******************************************************************************/


#include "../containers/serverManifest.h"
#include "../../library/lib/parse/parse.h"

serverManifest_o::serverManifest_o()  {}

serverManifest_o::~serverManifest_o()  {}

void serverManifest_o::clear()  {
    Id = "";
    ParentId = "";
    State = "";
    Type = "";
    Name = "";
    Location = "";
    NumberProcessed = "";
    Ip = "";
    Port = "";
}

int serverManifest_o::blank() const  {
    if( Id.length()       < 1  &&
        ParentId.length() < 1  &&
        State.length()    < 1  )  return 1;
    return 0;
}

serverManifest_o& serverManifest_o::operator = (const serverManifest_o& a)  {
    Id       = a.Id;
    ParentId = a.ParentId;
    State    = a.State;
    Type     = a.Type;
    Name     = a.Name;
    Location = a.Location;
    NumberProcessed = a.NumberProcessed;
    Ip       = a.Ip;
    Port     = a.Port;
    return *this;
}

void serverManifest_o::operator >> (string_o& s) const  {
    s << "\nserverManifest_o:";
    s << '\n' << SERVERMANIFEST_ID << '=' << Id;
    s << '\n' << SERVERMANIFEST_PARENTID << '=' << ParentId;
    s << '\n' << SERVERMANIFEST_STATE << '=' << State;
    s << '\n' << SERVERMANIFEST_TYPE << '=' << Type;
    s << '\n' << SERVERMANIFEST_NAME << '=' << Name;
    s << '\n' << SERVERMANIFEST_LOCATION << '=' << Location;
    s << '\n' << SERVERMANIFEST_NUMBERPROCESSED << '=' << NumberProcessed;
    s << '\n' << SERVERMANIFEST_IP << '=' << Ip;
    s << '\n' << SERVERMANIFEST_PORT << '=' << Port;
    s << '\n';
}

void serverManifest_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(SERVERMANIFEST_ID,Id);
    (void)parse.it(SERVERMANIFEST_PARENTID,ParentId);
    (void)parse.it(SERVERMANIFEST_STATE,State);
    (void)parse.it(SERVERMANIFEST_TYPE,Type);
    (void)parse.it(SERVERMANIFEST_NAME,Name);
    (void)parse.it(SERVERMANIFEST_LOCATION,Location);
    (void)parse.it(SERVERMANIFEST_NUMBERPROCESSED,NumberProcessed);
    (void)parse.it(SERVERMANIFEST_IP,Ip);
    (void)parse.it(SERVERMANIFEST_PORT,Port);
}

string_o& operator << (string_o& s,const serverManifest_o& a)  {
    a >> s;
    return s;
}


/******************************************************************************/
