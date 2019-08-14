/**  epi.cc  *******************************************************************

    Executable Programmer Interface Object.



changes log
when      who       what
11.11.99  Dan       Creation

*******************************************************************************/


#include <unistd.h>//!!
#include <stdlib.h>

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/log/log.h"
#include "../../../library/sserver/telenet/client.h"
#include "../threads/epi.h"


extern log_o log;



epi_o::epi_o(const thread_o& thread): thread_o(thread)  {
    NumberAdvanced = 0;
    EPIServerIp    = EPI_EPISERVER_DEFAULT_IP;
    EPIServerPort  = EPI_EPISERVER_DEFAULT_PORT;
}

epi_o::~epi_o()  {}


void epi_o::process()  {
    string_o message;

    client_o  client;
    string_o  ss;
    string_o  rs;

    ::sleep(30);//!!

    if(::log.debug(123))  {
        (message = "") << *this << "Starting process.";
        ::log << message;
    }



    client.connect(EPIServerIp.string(),EPIServerPort);
    if(client.error() != ERROR_OK)  {
        (message = "") << *this << "Client connect error.";
        ::log.error(message);
    }


    ss = "serverManifest_o:\nserverManifest_o.name=\"lifestyleserver-1\"\n\n";


    if(client.error() != ERROR_OK)  {
        (message = "") << *this << "Client send error.";
        ::log.error(message);
    }
    if(::log.debug(114))  {
        (message = "") << "Send to archiveserver: " << ss;
        ::log << message;
    }

    this->usleep(55555);

    rs = "";
    client.recv(rs);    

    if(client.error() != ERROR_OK)  {
        (message = "") << *this << "Client recv error.";
        ::log.error(message);
    }

    client.disconnect();


    if(::log.debug(116))  {
        (message = "") << *this << "Recv from " << EPIServerIp << ": " << rs;
        ::log << message;
    }

}

void* startepi(void* v)  {
    epi_o* b = (epi_o*)v;
    b->process();
    return v;
}



/******************************************************************************/
