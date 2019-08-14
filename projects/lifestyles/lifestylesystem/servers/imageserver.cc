/**  imageserver.cc  *********************************************************


    imageserver 0.024 server.


changes log
when        who    when
12.7.99     Dan    Creation.


*******************************************************************************/


#include <unistd.h>
#include <time.h>
#include <signal.h>

#include <iostream.h>
#include <fstream.h>


#include "../servers/imageserver.h"


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
imageserver_o*        imageserver;


/**  **************************************************************************/


imageserver_o::imageserver_o()  {

    NumberProcessed = 0;
    State = 0;


    ServerManifest.setId("imageserver-1");
    ServerManifest.setParentId(" ");
    ServerManifest.setName("Image Server v0.024");
    ServerManifest.setState("listen");
    ServerManifest.setNumberProcessed(0UL);
    ServerManifest.setType("imageserver");
    ServerManifest.setLocation("USA.Denver");
    ServerManifest.setIp("204.131.41.107");
    ServerManifest.setPort(IMAGESERVER_DEFAULT_PORT);


}

imageserver_o::~imageserver_o()  {}


int imageserver_o::process(input_o& input,output_o& output)  {
    string_o    message;
    string_o    archs;

    fstream fout;


    if(::log.debug(70))  {
        (message = "") << "Received image request: ";
        message << input.message();
        ::log << message;
    }


    //fout.open(lifestyleSession.id(),ios::out);
    if(!fout)  {
        (message = "") << "Failed to open file " << lifestyleSession.id();
        ::log << message;
    }

    fout.close();


    output.setMessage(archs.string());


    return ERROR_OK;
}

int carapace_o::process(input_o& input,output_o& output)  {
    return imageserver->process(input,output);
}


int main(int argc,char* argv[])  {
    int x;
    int rcode;
    string_o message;

    ::log.registerName(argv[0]);

    for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<200;x++)  ::log.setDebugLevel(x);


    ::pserver = new pserver_o(8);

    ::imageserver = new imageserver_o();


    rcode = ::pserver->serveport(IMAGESERVER_DEFAULT_PORT);
    if(rcode != ERROR_OK)  return rcode;


    (void)::pserver->persist();
    return ERROR_OK;
}


/******************************************************************************/

