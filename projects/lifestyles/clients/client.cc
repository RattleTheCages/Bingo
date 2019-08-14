/**  client.cc  ****************************************************************



*******************************************************************************/

#include <unistd.h>
#include <iostream.h>

#include "../../library/lib/string/string.h"
#include "../../library/lib/log/log.h"
#include "../../library/sserver/telenet/client.h"

log_o   log;

int main(int argc,char* argv[])  {
    int       x;
    string_o  s;
    string_o  message; 

    int       rcode;
    int       nbyte;
    string_o  serverName;
    int       serverPort;
    string_o  recvString;
    string_o  sendString;

    client_o  client;


    if(argc < 3)  {
        message = "usage:\n";
        ::log.error(message);
        return -1;
    }

 for(x=0;x<260;x++)  ::log.setDebugLevel(x);
    ::log.registerName(argv[0]);

    serverName = argv[1];
    s          = argv[2];
    serverPort = s.stoi();
    sendString = argv[3];


    if(::log.debug(20))  {
        (message = "") << "Connect to: " << serverName;
        message << ", Port: " << serverPort;
        message << ".  Sending:\n";
        message << sendString;
        ::log << message;
    }


    rcode = client.connect(serverName.string(),serverPort);
    if(::log.debug(20))  {
        (message = "") << "Connected.";
        ::log << message;
    }

  
    nbyte = 0; 
    nbyte = client.send(sendString.string());//!!!

    if(::log.debug(20))  {
        (message = "") << "Sent " << nbyte << " bytes.";
        ::log << message;
    }


    nbyte = client.recv(recvString);//!!!

    if(::log.debug(20))  {
        (message = "") << "Recv " << nbyte << " bytes.\n";
        message << "Recv " << recvString;
        ::log << message;
    }
    cout << recvString.string() << endl;


    client.disconnect();
    if(::log.debug(20))  {
        (message = "") << "Disconnected.";
        ::log << message;
    }



    return ERROR_OK;
}

/******************************************************************************/
