/**  pitboss.cc  ***************************************************************


    pitboss 0.004 server.


changes log
when        who    when
9.22.99     Dan    Creation.


*******************************************************************************/

#define PITBOSS_DEFAULT_PORT 14996

#include <unistd.h>
#include <time.h>


#include "../../library/lib/string/string.h"
#include "../../library/lib/memory/cache.h"
#include "../../library/lib/log/log.h"
#include "../../library/lib/other/sysinfo.h"
#include "../../library/pserver/pserver.h"
#include "../../library/sserver/telenet/client.h"

#include "../servers/pitboss.h"


/**  **************************************************************************/

log_o                 log;
sysinfo_o             sysinfo;
carapace_o            carapace;
pserver_o*            pserver;
pitboss_o             pitboss;


/**  **************************************************************************/


pitboss_o::pitboss_o()  {
}

pitboss_o::~pitboss_o()  {}


int pitboss_o::process(input_o& input,output_o& output)  {
    string_o    s;
    string_o    message;

    if(input.message() == "RequestGame")  {
        s = "pitbossui_o";
        output.setMessage(s.string());
    }
    else if(input.message().contains("pitbossui_o:"))  {
        s = "pitbossui_o";
        output.setMessage(s.string());
    }
    else  {
        s = "pitbossui_o";
        output.setMessage(s.string());
    }


    return ERROR_OK;
}


int carapace_o::process(input_o& input,output_o& output)  {
    return pitboss.process(input,output);
}

int main(int argc,char* argv[])  {
int x;
int rcode;
string_o message;

    ::log.registerName(argv[0]);



    for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<100;x++)  ::log.setDebugLevel(x);

    ::pserver = new pserver_o;

    rcode = ::pserver->serveport(PITBOSS_DEFAULT_PORT);
    if(rcode != ERROR_OK)  return rcode;

    ::pserver->persist();

    ::pthread_exit(NULL);
}


/******************************************************************************/

