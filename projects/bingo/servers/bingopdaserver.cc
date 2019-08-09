/**  bingoserver.cc  ***********************************************************


    bingoserver 0.001 server.


changes log
when        who    when
9.18.99     Dan    Creation.


*******************************************************************************/

#define BINGOSERVER_DEFAULT_PORT  8844

#define UIPORT 13145

#include <unistd.h>
#include <time.h>


#include "../../library/lib/string/string.h"
#include "../../library/lib/log/log.h"
#include "../../library/lib/other/sysinfo.h"
#include "../../library/pserver/pserver.h"
#include "../../library/sserver/telenet/client.h"
#include "../managers/pdaSessionManager.h"
#include "../hdml/hdmlInterface.h"
#include "../containers/pdaInput.h"
#include "../containers/bingogame.h"
#include "../process/bingo.h"


/**  **************************************************************************/

log_o                 log;
sysinfo_o             sysinfo;
carapace_o            carapace;
pserver_o*            pserver;
hdmlInterface_o*      hdmlInterface;
pdaSessionManager_o*  pdaSessionManager;


bingogame_o bingogame;

/**  **************************************************************************/


int carapace_o::process(input_o& input,output_o& output)  {
    string_o ss;
    string_o rr;
    client_o client;

    string_o    s;
    string_o    message;

    pdaSession_o*  pdaSession;
    pdaInput_o*    pdaInput;
    output_o*      output2;




    if(input.message() == "RequestGame")  {
        bingogame >> s;
        output.setMessage(s.string());
        
        return ERROR_OK;
    }
    else if(input.message().contains("bingogame_o:"))  {
        bingogame << input.message().string();
        bingogame >> s;
        output.setMessage(s.string());
    }
    else  {

    pdaInput = new pdaInput_o(input);


    ::hdmlInterface->parse(*pdaInput);


    pdaSession = ::pdaSessionManager->findSession(pdaInput->phone());
    if(!pdaSession)  {
        pdaSession = ::pdaSessionManager->newSession(pdaInput->phone());
        ::pdaSessionManager->saveSession(pdaSession);
        if(::log.debug(051))  {
            (message = "") << ": new session: " << pdaSession->id();
            ::log << message;
        }
    }
    else  {
        if(::log.debug(051))  {
            (message = "") << ": found session: " << pdaSession->id();
            ::log << message;
        }
    }


message = "";

           (void)::hdmlInterface->hdmlMenu.page(*pdaSession,message);


    output2 = new output_o(&input);
    output2->setMessage(message);
    pserver->outputQueue(output2);
    output.setInvalidCode(1);



    }


    return ERROR_OK;
}


int main(int argc,char* argv[])  {
int x;
int rcode;
string_o message;

thread_o* bthread = new thread_o(888,"Bingo Caller Thread");
bingo_o* bingo;

bingo = new bingo_o(*bthread);



    ::log.registerName(argv[0]);



//  for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<100;x++)  ::log.setDebugLevel(x);

::pserver = new pserver_o;

/**  Instanciate the HDML Interface Object.  ***********************************/

    if(0)
        ::log << "Instanciate HDML Interface Object attempt.";
    ::hdmlInterface = new hdmlInterface_o();
    if(!::hdmlInterface)  {
        //(void)::log.lerror("main: new hdmlInterface_o returned null.");
        return -1;
    }
    if(0)  ::log << "Instanciated the HDML Interface Object.";


/**  Instanciate the sessionManager_o Object.  ********************************/

    if(0)
        ::log << "Instanciate pdaSessionManager_o Object attempt.";
    ::pdaSessionManager = new pdaSessionManager_o();
    if(!::pdaSessionManager)  {
        //(void)::log.lerror("main: new pdaSessionManager_o returned null.");
        return -1;
    }
    if(0)  ::log << "Instanciated the pdaSessionManager_o Object.";




    rcode = ::pserver->serveport(BINGOSERVER_DEFAULT_PORT);
    if(rcode != ERROR_OK)  return rcode;


bingo->start((::callbingo),bingo);

    ::pserver->persist();

    ::pthread_exit(NULL);
}


/******************************************************************************/

