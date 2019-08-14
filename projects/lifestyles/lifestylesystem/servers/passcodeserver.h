/**  passcodeserver.h  *********************************************************

    Pass Code Server Object.

    This object is to maintain the unique information on each PDA
    device.  Information such as the device's Pass Code is retained
    by this server.  This server provides a global place accross the
    lifestyle and other systems for PDA aggreate data.


changes log
when       who     what
10.28.99   Dan     Creation. 
12.4.99    Dan     Changed:  Using new passcode_o object.

*******************************************************************************/


#ifndef PASSCODESERVEROBJECT_API
#define PASSCODESERVEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/thread/mutex.h"
#include "../../../library/sserver/containers/input.h"
#include "../../../library/sserver/containers/output.h"

#include "../../containers/passcode.h"
#include "../../containers/serverManifest.h"
#include "../../containers/pdaInput.h"

#define PASSCODESERVER_DEFAULT_IP   "204.131.41.3"
#define PASSCODESERVER_DEFAULT_PORT 9047
#define PASSCODESERVER_DEFAULT_HTML_DELAY 500000

#define PASSCODESERVER_MAX_NUMBER_OF_SOMETHING   32


class passcodeserver_o  {
  private:
    mutex_o           Mutex;
    serverManifest_o  ServerManifest;
    int               State;
    unsigned long     NumberProcessed;

    string_o          PassCodes[30000];  //!!!!!
    int               CurrentPassCode;

    passcode_o        Passcodes[6666];  //!!!!!


  public:   
    passcodeserver_o();                                 // Default constructor.
    passcodeserver_o(const passcodeserver_o&);          // Copy constructor.
   ~passcodeserver_o();                                 // Default destructor.
    passcodeserver_o&   operator = (const passcodeserver_o&);
                                                        // Assignment operator.

          int       process(input_o&,output_o&);
          int       htmlinput(input_o&,output_o&);
          int       pdainput(pdaInput_o&,output_o&);
          int       newPassCodeRequest(input_o&,output_o&);
          int       updatePassCodeRequest(input_o&,output_o&);

          int       checkPassCodeExist(string_o&);
          int       generateNewPassCode(string_o&);

    const serverManifest_o& serverManifest();               // Server Manifest.
          int       state()                         const;  // Server state.
    const char*     id()                            const;
    unsigned long   numberProcessed()               const;
};


/******************************************************************************/

inline int passcodeserver_o::state() const  {
    return State;
}

inline unsigned long passcodeserver_o::numberProcessed() const  {
    return NumberProcessed;
}

inline const serverManifest_o& passcodeserver_o::serverManifest()  {
    ServerManifest.setState(State);
    ServerManifest.setNumberProcessed(NumberProcessed);
    return ServerManifest;
}


#endif

/******************************************************************************/
