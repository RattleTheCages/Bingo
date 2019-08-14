/**  archiver.cc  **************************************************************




changes log
when      who       what
9.22.99   Dan       Creation

*******************************************************************************/


#include <unistd.h>
#include <stdlib.h>

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/log/log.h"
#include "../../../library/sserver/telenet/client.h"

#include "../../dynamicContainers/lifestyleSession.h"

#include "../threads/archiver.h"
#include "../managers/lifestyleQueueManager.h"


extern log_o log;
extern lifestyleQueueManager_o* lifestyleQueueManager;

void* startarchiver(void* v)  {
    archiver_o* b = (archiver_o*)v;
    b->process();
    return v;
}


archiver_o::archiver_o(const thread_o& thread): thread_o(thread)  {
    NumberAdvanced    = 0;
    ArchiveServerIp   = ARCHIVER_ARCHIVESERVER_IP;
    ArchiveServerPort = ARCHIVER_ARCHIVESERVER_PORT;
}

archiver_o::~archiver_o()  {}

void archiver_o::process()  {
    string_o message;

    client_o  client;
    int       nbytes;
    string_o  ss;
    string_o  rs;

    lifestyleSession_o* lifestyleSession;


    if(::log.debug(123))  {
        (message = "") << *this << "starting process.";
        ::log << message;
    }


    while(1)  {

        lifestyleSession = ::lifestyleQueueManager->ArchiveSessionsQueue.get();


        if(::log.debug(123))  {
            (message = "") << *this << "received lifestyleSession id ";
            message << lifestyleSession->id() << " from queue.";
            ::log << message;
        }


        if(::log.debug(124))  {
            (message = "") << *this << "attempting connect for id ";
            message << lifestyleSession->id() << ".";
            ::log << message;
        }

        (void)client.connect(ArchiveServerIp.string(),ArchiveServerPort);
        if(client.error() != ERROR_OK)  {
            (message = "") << *this << "client connect error.";
            ::log.error(message);
        }
        else  {

            ss = "";
            *lifestyleSession >> ss;

            if(::log.debug(125))  {
                (message = "") << *this << "attempting send for id ";
                message << lifestyleSession->id() << ".";
                ::log << message;
            }

            nbytes = client.send(ss);
            if(client.error() != ERROR_OK)  {
                (message = "") << *this << "client send error.";
                ::log.error(message);
            }
            if(::log.debug(125))  {
                (message = "") << *this << "sent " << nbytes << " for id ";
                message << lifestyleSession->id() << ".";
                ::log << message;
            }


            (void)::usleep(222);


            if(client.error() == ERROR_OK)  {
                if(::log.debug(126))  {
                    (message = "") << *this << "attempting recv for id ";
                    message << lifestyleSession->id() << ".";
                    ::log << message;
                }

                rs = "";
                nbytes = client.recv(rs);    
                if(client.error() != ERROR_OK)  {
                    (message = "") << *this << "client recv error.";
                    ::log.error(message);
                }

                if(::log.debug(126))  {
                    (message = "") << *this << "recv " << nbytes << " for id ";
                    message << lifestyleSession->id() << ".";
                    ::log << message;
                }

            }
        }

        (void)client.disconnect();


        if(::log.debug(123))  {
            (message = "") << *this << "completed lifestyleSession id ";
            message << lifestyleSession->id() << ".";
            ::log << message;
        }

    }
}


/******************************************************************************/
