/**  startup.cc  ***************************************************************




changes log
when      who       what
9.22.99   Dan       Creation

*******************************************************************************/


#include <unistd.h>
#include <stdlib.h>

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/log/log.h"
#include "../../../library/sserver/telenet/client.h"

#include "../process/startup.h"

extern log_o log;


startup_o::startup_o()  {
    RelegateServerIp = STARTUPPROCESSOBJECT_DEFAULT_RELEGATE_SERVER_IP;
    RelegateServerPort = STARTUPPROCESSOBJECT_DEFAULT_RELEGATE_SERVER_PORT;
}

startup_o::~startup_o()  {}

int startup_o::getAccountsFromRelegateServer(const serverManifest_o& serverManifest)  {
    string_o message;

    client_o  client;
    string_o  ss;
    string_o  rs;

    if(::log.debug(123))  {
        (message = "") << "Getting accounts from relegateserver.";
        ::log << message;
    }


    client.connect(RelegateServerIp.string(),RelegateServerPort);

    if(client.error() != ERROR_OK)  {
        (message = "") << "Client connect error.";
        ::log.error(message);
    }

    ss = "";
    serverManifest >> ss;

    client.send(ss);
    if(client.error() != ERROR_OK)  {
        (message = "") << "Client send error.";
        ::log.error(message);
    }
    if(::log.debug(114))  {
        (message = "") << "Send to archiveserver: " << ss;
        ::log << message;
    }

    ::usleep(55555);

    rs = "";
    client.recv(rs);

    if(client.error() != ERROR_OK)  {
        (message = "") << "Client recv error.";
        ::log.error(message);
    }

    client.disconnect();


    if(::log.debug(116))  {
        (message = "") << "Recv from archiveserver: " << rs;
        ::log << message;
    } 



    return ERROR_OK;
}


/******************************************************************************/
