/**  archiveserver.cc  *********************************************************


    archiveserver 0.022 server.


changes log
when        who    when
10.22.99    Dan    Creation.


*******************************************************************************/

#define ARCHIVESERVER_DEFAULT_PORT  8194

#include <unistd.h>
#include <time.h>
#include <signal.h>

#include <iostream.h>
#include <fstream.h>


#include "../servers/archiveserver.h"


#include "../../../library/lib/string/string.h"
#include "../../../library/lib/memory/cache.h"
#include "../../../library/lib/log/log.h"
#include "../../../library/lib/other/sysinfo.h"
#include "../../../library/pserver/pserver.h"

#include "../../html/htmlTelluric.h"


/**  **************************************************************************/

log_o                 log;
sysinfo_o             sysinfo;
carapace_o            carapace;
pserver_o*            pserver;
archiveserver_o*      archiveserver;

htmlTelluric_o* htmlTelluric;


/**  **************************************************************************/


archiveserver_o::archiveserver_o()  {
    int y;

    NumberProcessed = 0;
    State = 0;
    Id = "Archive Server v0.022";
}

archiveserver_o::~archiveserver_o()  {}


int archiveserver_o::process(input_o& input,output_o& output)  {
    string_o    message;
    string_o    archs;
    lifestyleSession_o lifestyleSession;

    fstream fout;


    if(::log.debug(70))  {
        (message = "") << "Received archive request: ";
        message << input.message();
        ::log << message;
    }

    lifestyleSession << input.message().string();
    lifestyleSession >> archs;

    fout.open(lifestyleSession.id(),ios::out);
    if(!fout)  {
        (message = "") << "Failed to open file " << lifestyleSession.id();
        ::log << message;
    }

    archs.boxears();
    if(archs.charat(0) == '\n')  archs.upcut(1);
    fout << archs << endl << endl;

    fout.close();


    output.setMessage(archs.string());


    return ERROR_OK;
}

int carapace_o::process(input_o& input,output_o& output)  {
    return archiveserver->process(input,output);
}


int main(int argc,char* argv[])  {
    int x;
    int rcode;
    string_o message;

    ::log.registerName(argv[0]);

    for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<200;x++)  ::log.setDebugLevel(x);

htmlTelluric = new htmlTelluric_o;

    ::pserver = new pserver_o(8);

    ::archiveserver = new archiveserver_o();


    rcode = ::pserver->serveport(ARCHIVESERVER_DEFAULT_PORT);
    if(rcode != ERROR_OK)  return rcode;


    (void)::pserver->persist();
    return ERROR_OK;
}


/******************************************************************************/

