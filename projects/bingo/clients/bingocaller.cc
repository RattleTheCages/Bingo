/**  bingocaller.cc  ***********************************************************


    bingocaller 0.004 client.


changes log
when        who    when
9.19.99     Dan    Creation.



*******************************************************************************/

#include <unistd.h>

#include "../../library/lib/log/log.h"
#include "../../library/sserver/telenet/client.h"

#include "../clients/bingocaller.h"

log_o   log;


bingocaller_o::bingocaller_o()  {}
bingocaller_o::~bingocaller_o()  {}


int bingocaller_o::getGame()  {
    int retry;
    string_o message;
    client_o    client;
    int         nbyte;
    string_o rs;
    string_o ss;

    ss << "BingoCaller_";
    Bingogame >> ss;

cout<<ss<<endl;


(void)client.connect(Bingoserver.string(),BingoserverPort);
if(client.error())  {
    (message = "") << "connect: " << client.error();
    ::log.error(message);
    return client.error();
}
else  {
    if(::log.debug(21))  {
        (message = "") << "Connected to: " << Bingoserver;
        message << ", Port: " << BingoserverPort;
        ::log << message;
   }

    nbyte = client.send(ss.string());
    if(client.error())  {
        (message = "") << "send: " << client.error();
        ::log.error(message);
    }
    if(::log.debug(22))  {
        (message = "") << "Sent " << nbyte << " bytes.";
        ::log << message;
    }

    ::usleep(2222);
    nbyte = client.recv(rs);
    retry = 0;
    //if(!rs.contains("\n\n") && retry++ < 2250)  {
    //    ::usleep(2222);
    //    nbyte += client.recv(rs);
   // }

    if(::log.debug(23))  {
        (message = "") << "Recv " << nbyte << " bytes.\n";
      //message << "Recv " << rs;
        ::log << message;
    }
}

client.disconnect();
if(::log.debug(24))  {
    (message = "") << "Disconnected.";
    ::log << message;
}

Bingogame << rs.string();

return ERROR_OK;
}


int bingocaller_o::process()  {
    int         x;
    string_o    s;
    string_o    message; 
    int         ball;

    if(::log.debug(2))  {
        (message = "") << "bingo server IP " << Bingoserver;
        message << " port " << BingoserverPort << ".";
        ::log << message;
    }


    getGame();

    if(::log.debug(11))  {
        (message = "") << "Starting game id " << Bingogame.id() << ".";
        ::log << message;
    }

    Bingogame.setState(BINGOGAME_STATE_IN_PROGRESS);
    while(!Bingogame.complete())  {
        Bingogame.setState(BINGOGAME_STATE_IN_PROGRESS);
        ::sleep(1);

        ball = Rand.i(100)-10;
        while(Bingogame[ball])  ball = Rand.i(100)-10;
        Bingogame.setBallPick(ball);

        if(::log.debug(12))  {
            (message = "") << "Ball " << ball << "  Game ";
            message << Bingogame.id() << ".";
            ::log << message;
        }


        getGame();

        if(::log.debug(49))  {
            (message = "") << "Ball " << ball << " call complete.";
            ::log << message;
        }

    }



    if(::log.debug(51))  {
        (message = "") << "Game " << Bingogame.id() << " complete.";
        ::log << message;
    }

    return ERROR_OK;
}


void bingocaller_o::setBingoserver(const char* cc)  {
    Bingoserver = cc;
}

void bingocaller_o::setBingoserverPort(const char* p)  {
    string_o s;
    s << p;
    BingoserverPort = s.stoi();
}


int main(int argc,char* argv[])  {
    int           x;
    string_o      message;
    bingocaller_o bingocaller;

    if(argc < 2)  {
        message = "usage: bingoserverIP bingoserverport\n";
        ::log.error(message);
        return -1;
    }

    bingocaller.setBingoserver(argv[1]);
    bingocaller.setBingoserverPort(argv[2]);

    ::log.registerName(argv[0]);
//  for(x=250;x<260;x++)  ::log.setDebugLevel(x);
    for(x=0;x<100;x++)    ::log.setDebugLevel(x);

    if(::log.debug(1))  {
        (message = "") << "bingo caller start.";
        ::log << message;
    }
    ::sleep(2);
    return bingocaller.process();
}

/******************************************************************************/
