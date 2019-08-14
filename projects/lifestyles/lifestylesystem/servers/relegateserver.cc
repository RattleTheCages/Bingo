/**  relegateserver.cc  ********************************************************


    relegateserver 0.024 server.


changes log
when       who    when
10.22.99   Dan    Creation.
10.29.99   Dan    Added:    Reporting of server manifest to a browser.
12.4.99    Dan    Changed:  Using htmlServerManifestPage_o now. 


*******************************************************************************/

#define RELEGATESERVER_DEFAULT_PORT  8196

#include <unistd.h>
#include <time.h>
#include <signal.h>

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/memory/cache.h"
#include "../../../library/lib/log/log.h"
#include "../../../library/lib/other/sysinfo.h"
#include "../../../library/pserver/pserver.h"

#include "../servers/relegateserver.h"
#include "../../html/htmlTelluric.h"



/**  **************************************************************************/

log_o                 log;
sysinfo_o             sysinfo;
carapace_o            carapace;
pserver_o*            pserver;
relegateserver_o*     relegateserver;
htmlTelluric_o*      htmlTelluric;


/**  **************************************************************************/


relegateserver_o::relegateserver_o()  {

    NumberProcessed = 0;
    State = 0;

    ServerManifest.setId("relegateserver-1");
    ServerManifest.setParentId(" ");
    ServerManifest.setName("Relegate Server v0.024");
    ServerManifest.setState("listen");
    ServerManifest.setNumberProcessed(0UL);
    ServerManifest.setType("relegateserver");
    ServerManifest.setLocation("USA.Denver");
    ServerManifest.setIp("204.131.41.3");
    ServerManifest.setPort(RELEGATESERVER_DEFAULT_PORT);


    LifestyleItems[0].setType("");
    LifestyleItems[0].setName("Home");
    LifestyleItems[0].setDescription("Home Lifestyle Menu");

}

relegateserver_o::~relegateserver_o()  {}


int relegateserver_o::process(input_o& input,output_o& output)  {
    string_o    message;
    string_o    archs;

    output_o* output2;

    Mutex.lock();
        NumberProcessed++;
    Mutex.unlock();


    if(input.message().contains("HTTP"))  {
        return htmlinput(input,output);
    }
    else if(input.message().contains("serverManifest_o:"))  {
        if(::log.debug(70))  {
            (message = "") << "Received relegate request: ";
            message << input.message();
            ::log << message;
        }

    if(State != 0)  {
    }
else  {



//  fstream fout;


    if(::log.debug(70))  {
        (message = "") << "Received relegate request: ";
        message << input.message();
        ::log << message;
    }



//  lifestyleSession << input.message().string();
//  lifestyleSession >> archs;

//  fout.open(lifestyleSession.id(),ios::out);
//  if(!fout)  {
//      (message = "") << "Failed to open file " << lifestyleSession.id();
//      ::log << message;
//  }

//  archs.boxears();
//  if(archs.charat(0) == '\n')  archs.upcut(1);
//  fout << archs << endl << endl;

//  fout.close();


//    output.setMessage(archs.string());

    output2 = new output_o(&input);
    output2->setMessage(input.message());
    pserver->outputQueue(output2);
    output.setInvalidCode(1);


::sleep(10);

    ::system("../loaders/lifestyleItems");
::sleep(2);
    ::system("../loaders/services");
::sleep(2);
    ::system("../loaders/loadsessions");

    if(::log.debug(70))  {
        (message = "") << "Finshed relegate request.";
        ::log << message;
    }

}
State = 1;
State = 0;//!!??
}
    return ERROR_OK;
}

int relegateserver_o::htmlinput(input_o& input,output_o& output)  {
    string_o page;

    ::htmlTelluric->htmlServerManifestPage.page(serverManifest(),page);


::usleep(500000);

    output.setMessage(page);

    return ERROR_OK;
}

int carapace_o::process(input_o& input,output_o& output)  {
    return relegateserver->process(input,output);
}


int main(int argc,char* argv[])  {
    int x;
    int rcode;
    string_o message;

    ::log.registerName(argv[0]);

    for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<200;x++)  ::log.setDebugLevel(x);


    ::pserver = new pserver_o(8);

    ::htmlTelluric = new htmlTelluric_o;

    ::relegateserver = new relegateserver_o;


    rcode = ::pserver->serveport(RELEGATESERVER_DEFAULT_PORT);
    if(rcode != ERROR_OK)  return rcode;


    (void)::pserver->persist();
    return ERROR_OK;
}


/******************************************************************************/

