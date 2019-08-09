/**  bingocardserver.cc  *******************************************************


    bingocardserver 0.002 server.


changes log
when        who    when
9.19.99     Dan    Creation.


*******************************************************************************/

#define BINGOCARDSERVER_DEFAULT_PORT  8845


#include <unistd.h>
#include <time.h>


#include "../../library/lib/string/string.h"
#include "../../library/lib/log/log.h"
#include "../../library/lib/other/sysinfo.h"
#include "../../library/lib/other/rand.h"
#include "../../library/pserver/pserver.h"
#include "../../library/sserver/telenet/client.h"

#include "../servers/bingocardserver.h"


/**  **************************************************************************/

log_o                 log;
sysinfo_o             sysinfo;
carapace_o            carapace;
pserver_o*            pserver;


bingocardserver_o bingocardserver;

/**  **************************************************************************/



bingocardserver_o::bingocardserver_o()  {
}

bingocardserver_o::~bingocardserver_o()  {}


void bingocardserver_o::getCard(bingocard_o& bingocard)  {
    int x;
    int zz;
    int x0,x1,x2,x3,x4;
    int b;
    int B[5];
    int I[5];
    int N[5];
    int G[5];
    int O[5];

    for(x=0;x<5;x++)  {
        B[x] = x+1;
        I[x] = x+1;
        N[x] = x+1;
        G[x] = x+1;
        O[x] = x+1;
    }


    b = rand.i(3003);

    for(x0=1;x0<12;x0++)  {
        for(x1=x0+1;x1<13;x1++)  {
            for(x2=x1+1;x2<14;x2++)  {
                for(x3=x2+1;x3<15;x3++)  {
                    for(x4=x3+1;x4<16;x4++)  {
                        b = b - 1;
                        if(b < 0)  break;
                    }
                    if(b < 0)  break;
                }
                if(b < 0)  break;
            }
            if(b < 0)  break;
        }
        if(b < 0)  break;
    }

    B[0] = x0;
    B[1] = x1;
    B[2] = x2;
    B[3] = x3;
    B[4] = x4;



    b = rand.i(3003);

    for(x0=1;x0<12;x0++)  {
        for(x1=x0+1;x1<13;x1++)  {
            for(x2=x1+1;x2<14;x2++)  {
                for(x3=x2+1;x3<15;x3++)  {
                    for(x4=x3+1;x4<16;x4++)  {
                        b = b - 1;
                        if(b < 0)  break;
                    }
                    if(b < 0)  break;
                }
                if(b < 0)  break;
            }
            if(b < 0)  break;
        }
        if(b < 0)  break;
    }

    I[0] = x0+15;
    I[1] = x1+15;
    I[2] = x2+15;
    I[3] = x3+15;
    I[4] = x4+15;



    b = rand.i(3003);

    for(x0=1;x0<12;x0++)  {
        for(x1=x0+1;x1<13;x1++)  {
            for(x2=x1+1;x2<14;x2++)  {
                for(x3=x2+1;x3<15;x3++)  {
                    for(x4=x3+1;x4<16;x4++)  {
                        b = b - 1;
                        if(b < 0)  break;
                    }
                    if(b < 0)  break;
                }
                if(b < 0)  break;
            }
            if(b < 0)  break;
        }
        if(b < 0)  break;
    }

    N[0] = x0+30;
    N[1] = x1+30;
    N[2] = x2+30;
    N[3] = x3+30;
    N[4] = x4+30;



    b = rand.i(3003);

    for(x0=1;x0<12;x0++)  {
        for(x1=x0+1;x1<13;x1++)  {
            for(x2=x1+1;x2<14;x2++)  {
                for(x3=x2+1;x3<15;x3++)  {
                    for(x4=x3+1;x4<16;x4++)  {
                        b = b - 1;
                        if(b < 0)  break;
                    }
                    if(b < 0)  break;
                }
                if(b < 0)  break;
            }
            if(b < 0)  break;
        }
        if(b < 0)  break;
    }

    G[0] = x0+45;
    G[1] = x1+45;
    G[2] = x2+45;
    G[3] = x3+45;
    G[4] = x4+45;


    
    b = rand.i(3003);

    for(x0=1;x0<12;x0++)  {
        for(x1=x0+1;x1<13;x1++)  {
            for(x2=x1+1;x2<14;x2++)  {
                for(x3=x2+1;x3<15;x3++)  {
                    for(x4=x3+1;x4<16;x4++)  {
                        b = b - 1;
                        if(b < 0)  break;
                    }
                    if(b < 0)  break;
                }
                if(b < 0)  break;
            }
            if(b < 0)  break;
        }
        if(b < 0)  break;
    }

    O[0] = x0+60;
    O[1] = x1+60;
    O[2] = x2+60;
    O[3] = x3+60;
    O[4] = x4+60;



cout<<B[0]<<"-"<<I[0]<<"-"<<N[0]<<"-"<<G[0]<<"-"<<O[0]<<endl;
cout<<B[1]<<"-"<<I[1]<<"-"<<N[1]<<"-"<<G[1]<<"-"<<O[1]<<endl;
cout<<B[2]<<"-"<<I[2]<<"-"<<N[2]<<"-"<<G[2]<<"-"<<O[2]<<endl;
cout<<B[3]<<"-"<<I[3]<<"-"<<N[3]<<"-"<<G[3]<<"-"<<O[3]<<endl;
cout<<B[4]<<"-"<<I[4]<<"-"<<N[4]<<"-"<<G[4]<<"-"<<O[4]<<endl;
cout<<endl;

    for(x=0;x<5;x++)  {
        bingocard.B[x] = B[x];
        bingocard.I[x] = I[x];
        bingocard.N[x] = N[x];
        bingocard.G[x] = G[x];
        bingocard.O[x] = O[x];
    }

}


int carapace_o::process(input_o& input,output_o& output)  {
    string_o s;
    string_o message;
    string_o ss;
    string_o rr;
    bingocard_o bingocard;


    bingocardserver.getCard(bingocard);


       
        bingocard >> ss; 
        output.setMessage(ss.string());
        return ERROR_OK;


    return ERROR_OK;
}


int main(int argc,char* argv[])  {
int x;
int rcode;
string_o message;



    ::log.registerName(argv[0]);



//  for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<100;x++)  ::log.setDebugLevel(x);

::pserver = new pserver_o;


    rcode = ::pserver->serveport(BINGOCARDSERVER_DEFAULT_PORT);
    if(rcode != ERROR_OK)  return rcode;


    ::pserver->persist();

    ::pthread_exit(NULL);
}


/******************************************************************************/

