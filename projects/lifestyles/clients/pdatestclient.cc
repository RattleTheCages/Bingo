/**  pdaclient.cc  *************************************************************


    PDA simulated client.



changes log
when        who    when
9.9.99      Dan    Creation.


*******************************************************************************/


#include "../../library/lib/string/string.h"
#include "../../library/lib/log/log.h"
#include "../../library/sserver/telenet/client.h"

log_o   log;

int main(int argc,char* argv[])  {
    string_o  s;
    int       rcode;
    string_o  rstring;
    string_o  sstring;
    string_o  phoneID;
    client_o  client;

    string_o serverIP;
    int      serverPort;

    if(argc < 5)  {
        cerr << " usage:" << argv[0] << " serverIP serverPort phoneID message" << endl;
        return ERROR_FAIL;
    }


    serverIP = argv[1];
    s = argv[2];
    serverPort = s.stoi();
    phoneID = argv[3];



    sstring << "GET /" << argv[4] << " HTTP 1.0";

    sstring << "\n";
    sstring << "Accept: text/x-hdml, application/x-hdmlc, application/x-up-alert, application/x-up-cacheop, application/x-up-device, application/x-up-digestentry, image/bmp, image/x-up-bmp\n";
    sstring << "x-up-uplink: pn.mobile.att.net\n";
    sstring << "x-up-fax-accepts: text/plain, application/postscript\n";
    sstring << "x-up-fax-limit: 3000000\n";
    sstring << "User-Agent: UP.Browser/2.00-PC01 UP.Link/2.0\n";
    sstring << "x-up-subno: ";
    sstring << phoneID << "\n";
    sstring << "Accept-Charset: US-ASCII\n";
    sstring << "Accept-Language: en\n";
    sstring << "\n";

    if(1)  {
        cerr << argv[0] << ": serverIP: " << serverIP;
        cerr << ", serverPort: " << serverPort << ", phoneID:";
        cerr << phoneID << endl;
    }


    rcode = client.connect(serverIP.string(),serverPort);

    if(rcode != ERROR_OK)  {
        cerr << argv[0] << ": error:" << rcode << endl;
        return rcode;
    }

    client.send(sstring);
    cout << argv[0] << ": sent: " << sstring << endl;


    client.recv(rstring);
    client.recv(rstring);
    cout << endl << endl;
    cout << argv[0] << ": recv: " << rstring << endl;


    client.disconnect();
    return 0;
}

/******************************************************************************/
