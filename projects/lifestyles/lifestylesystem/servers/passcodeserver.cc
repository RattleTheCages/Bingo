/**  passcodeserver.cc  ********************************************************


    passcodeserver 0.024 server.


changes log
when       who     when
10.28.99   Dan     Creation.
12.4.99    Dan     Changed:  Using new passcode_o object.



*******************************************************************************/


#include <unistd.h>
#include <time.h>
#include <signal.h>


#include "../servers/passcodeserver.h"


#include "../../../library/lib/log/log.h"
#include "../../../library/lib/other/sysinfo.h"
#include "../../../library/lib/memory/cache.h"
#include "../../../library/pserver/pserver.h"
#include "../../html/htmlTelluric.h"


/**  **************************************************************************/

log_o               log;
sysinfo_o           sysinfo;
carapace_o          carapace;
pserver_o*          pserver;
htmlTelluric_o*     htmlTelluric;
passcodeserver_o*   passcodeserver;


/**  **************************************************************************/


passcodeserver_o::passcodeserver_o()  {
int x,y,z;
string_o k;
    NumberProcessed = 0;
    State = 0;

    ServerManifest.setId("passcodeserver-1");
    ServerManifest.setParentId("");
    ServerManifest.setName("Passcode Server v0.024");
    ServerManifest.setType("passcodeserver");
    ServerManifest.setLocation("USA-Denver");
    ServerManifest.setState(0);
    ServerManifest.setNumberProcessed(0UL);
    ServerManifest.setIp(PASSCODESERVER_DEFAULT_IP);
    ServerManifest.setPort(PASSCODESERVER_DEFAULT_PORT);


    for(y=0;y<99;y++)  {
        k = "";
        k << y;
        while(k.length() < 2)  {
            k.reverse();
            k << "0";
            k.reverse();
        }
        (PassCodes[0+(y*100)] = "tophat") << k;
        (PassCodes[1+(y*100)] = "blackcat") << k;
        (PassCodes[2+(y*100)] = "green") << k;
        (PassCodes[3+(y*100)] = "brown") << k;
        (PassCodes[4+(y*100)] = "yellow") << k;
        (PassCodes[5+(y*100)] = "orange") << k;
        (PassCodes[6+(y*100)] = "red") << k;
        (PassCodes[7+(y*100)] = "blue") << k;
        (PassCodes[8+(y*100)] = "white") << k;
        (PassCodes[9+(y*100)] = "tie") << k;
        (PassCodes[10+(y*100)] = "shoe") << k;
        (PassCodes[11+(y*100)] = "coat") << k;
        (PassCodes[12+(y*100)] = "mitten") << k;
        (PassCodes[13+(y*100)] = "fan") << k;
        (PassCodes[14+(y*100)] = "cold") << k;
        (PassCodes[15+(y*100)] = "hot") << k;
        (PassCodes[16+(y*100)] = "round") << k;
        (PassCodes[17+(y*100)] = "box") << k;
        (PassCodes[18+(y*100)] = "board") << k;
        (PassCodes[19+(y*100)] = "redball") << k;
        (PassCodes[20+(y*100)] = "abdicate") << k;
        (PassCodes[21+(y*100)] = "abdomen") << k;
        (PassCodes[22+(y*100)] = "abeyant") << k;
        (PassCodes[23+(y*100)] = "ablaze") << k;
        (PassCodes[24+(y*100)] = "able") << k;
        (PassCodes[25+(y*100)] = "abort") << k;
        (PassCodes[26+(y*100)] = "about") << k;
        (PassCodes[27+(y*100)] = "above") << k;
        (PassCodes[28+(y*100)] = "abscess") << k;
        (PassCodes[29+(y*100)] = "absorb") << k;
        (PassCodes[30+(y*100)] = "absurd") << k;
        (PassCodes[31+(y*100)] = "abut") << k;
        (PassCodes[32+(y*100)] = "abyss") << k;
        (PassCodes[33+(y*100)] = "accent") << k;
        (PassCodes[34+(y*100)] = "acclaim") << k;
        (PassCodes[35+(y*100)] = "ace") << k;
        (PassCodes[36+(y*100)] = "accrue") << k;
        (PassCodes[37+(y*100)] = "acme") << k;
        (PassCodes[38+(y*100)] = "acidic") << k;
        (PassCodes[39+(y*100)] = "acolyte") << k;
        (PassCodes[40+(y*100)] = "adverb") << k;
        (PassCodes[41+(y*100)] = "advise") << k;
        (PassCodes[42+(y*100)] = "afoul") << k;
        (PassCodes[43+(y*100)] = "afoot") << k;
        (PassCodes[44+(y*100)] = "age") << k;
        (PassCodes[45+(y*100)] = "bluff") << k;
        (PassCodes[46+(y*100)] = "bluegrass") << k;
        (PassCodes[47+(y*100)] = "bluish") << k;
        (PassCodes[48+(y*100)] = "blurt") << k;
        (PassCodes[49+(y*100)] = "blush") << k;
        (PassCodes[50+(y*100)] = "brave") << k;
        (PassCodes[51+(y*100)] = "bray") << k;
        (PassCodes[52+(y*100)] = "bream") << k;
        (PassCodes[53+(y*100)] = "broil") << k;
        (PassCodes[54+(y*100)] = "brow") << k;
        (PassCodes[55+(y*100)] = "broom") << k;
        (PassCodes[56+(y*100)] = "brouhaha") << k;
        (PassCodes[57+(y*100)] = "cart") << k;
        (PassCodes[58+(y*100)] = "carve") << k;
        (PassCodes[59+(y*100)] = "cent") << k;
        (PassCodes[60+(y*100)] = "diet") << k;
        (PassCodes[61+(y*100)] = "dig") << k;
        (PassCodes[62+(y*100)] = "digram") << k;
        (PassCodes[63+(y*100)] = "digest") << k;
        (PassCodes[64+(y*100)] = "dilate") << k;
        (PassCodes[65+(y*100)] = "dim") << k;
        (PassCodes[66+(y*100)] = "dime") << k;
        (PassCodes[67+(y*100)] = "diode") << k;
        (PassCodes[68+(y*100)] = "dip") << k;
        (PassCodes[69+(y*100)] = "dire") << k;
        (PassCodes[70+(y*100)] = "dish") << k;
        (PassCodes[71+(y*100)] = "ditch") << k;
        (PassCodes[72+(y*100)] = "ditto") << k;
        (PassCodes[73+(y*100)] = "ditty") << k;
        (PassCodes[74+(y*100)] = "diva") << k;
        (PassCodes[75+(y*100)] = "dome") << k;
        (PassCodes[76+(y*100)] = "dolly") << k;
        (PassCodes[77+(y*100)] = "dot") << k;
        (PassCodes[78+(y*100)] = "dove") << k;
        (PassCodes[79+(y*100)] = "down") << k;
        (PassCodes[80+(y*100)] = "draw") << k;
        (PassCodes[81+(y*100)] = "drape") << k;
        (PassCodes[82+(y*100)] = "drew") << k;
        (PassCodes[83+(y*100)] = "droll") << k;
        (PassCodes[84+(y*100)] = "drink") << k;
        (PassCodes[85+(y*100)] = "drip") << k;
        (PassCodes[86+(y*100)] = "dry") << k;
        (PassCodes[87+(y*100)] = "echo") << k;
        (PassCodes[88+(y*100)] = "elect") << k;
        (PassCodes[89+(y*100)] = "girth") << k;
        (PassCodes[90+(y*100)] = "gist") << k;
        (PassCodes[91+(y*100)] = "give") << k;
        (PassCodes[92+(y*100)] = "gland") << k;
        (PassCodes[93+(y*100)] = "heckle") << k;
        (PassCodes[94+(y*100)] = "helium") << k;
        (PassCodes[95+(y*100)] = "hem") << k;
        (PassCodes[96+(y*100)] = "hence") << k;
        (PassCodes[97+(y*100)] = "herd") << k;
        (PassCodes[98+(y*100)] = "hex") << k;
        (PassCodes[99+(y*100)] = "friday") << k;

    }
    CurrentPassCode = 5;


    for(x=0;x<6666;x++)  {
        Passcodes[x].setUserid(PassCodes[x].string());
        Passcodes[x].setPassword(PassCodes[x+6666].string());
        Passcodes[x].setValid(1);
    }

}

passcodeserver_o::~passcodeserver_o()  {}


int passcodeserver_o::htmlinput(input_o& input,output_o& output)  {
    string_o message;
    string_o page;
    string_o s;


    if(::log.debug(70))  {
        (message = "") << "htmlinput(input_o&,output_o&) Start.";
        ::log << message;
    }
    if(::log.debug(71))  {
        (message = "") << "htmlinput message:\n" << input.message();
        ::log << message;
    }

    (void)::htmlTelluric->htmlDisplayServerManifest.page(serverManifest(),page);

    output.setMessage(page.string());


    ::usleep(PASSCODESERVER_DEFAULT_HTML_DELAY);

    return ERROR_OK;
}


int passcodeserver_o::newPassCodeRequest(input_o& input,output_o& output)  {
    string_o message;
    string_o send;

    if(::log.debug(62))  {
        (message = "") << "New Pass Code Requested.";
        ::log << message;
    }

    send = "";
    Passcodes[CurrentPassCode] >> send;
    send << "\n\n";

    output.setMessage(send.string());

    if(::log.debug(62))  {
        (message = "") << "New Pass Code assigned:\n" << send;
        ::log << message;
    }


    CurrentPassCode++;

    return ERROR_OK;
}

int passcodeserver_o::updatePassCodeRequest(input_o& input,output_o& output)  {
    string_o message;

    if(::log.debug(62))  {
        (message = "") << "Update Pass Code Requested.";
        ::log << message;
    }

    return ERROR_OK;
}

int passcodeserver_o::process(input_o& input,output_o& output)  {
    string_o    s;
    string_o    message;
    int         ret;


    if(input.message().contains("passcode_o:"))  {
        (void)Mutex.lock();
            ret = newPassCodeRequest(input,output);
        (void)Mutex.unlock();
    }
    else if(input.message().contains("input%%%%updatePassCodeRequest"))  {
        ret = updatePassCodeRequest(input,output);
    }
    else  {
        ret = htmlinput(input,output);
    }


    (void)Mutex.lock();
        NumberProcessed++;
    (void)Mutex.unlock();

    return ret;
}


int carapace_o::process(input_o& input,output_o& output)  {
    return passcodeserver->process(input,output);
}


int main(int argc,char* argv[])  {
    int      x;
    string_o message;

    int rcode;


/******************************************************************************/



    ::log.registerName(argv[0]);

    for(x=0;x<1024;x++)   ::log.setDebugLevel(x);
    for(x=0;x<200;x++)  ::log.setDebugLevel(x);


/******************************************************************************/



    ::pserver = new pserver_o(6);

    ::passcodeserver = new passcodeserver_o();


/**  Instanciate the HTML Interface Object.  **********************************/



    if(::log.debug(5))
        ::log << "Instanciate HTML Telluric Object attempt.";
    ::htmlTelluric = new htmlTelluric_o();
    if(!::htmlTelluric)  {
        (void)::log.error("main: new htmlTelluric_o() returned null.");
        return -1;
    }
    if(::log.debug(5))  ::log << "Instanciated the HTML Telluric Object.";


/******************************************************************************/



    rcode = ::pserver->serveport(PASSCODESERVER_DEFAULT_PORT);
    if(rcode != ERROR_OK)  {
        (message = "") << "Error " << rcode << " returned from pserver_o.";
        ::log.error(message);

        return rcode;
    }

    if(::log.debug(9))  {
        (message = "") << "Server started.";
        ::log << message;
    }


/******************************************************************************/



    (void)::pserver->persist();
    return ERROR_OK;
}


/******************************************************************************/

