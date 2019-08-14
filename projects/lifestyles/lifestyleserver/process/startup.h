/**  startup.h  ****************************************************************

    HTML Input Object.



log_o::debug levels


changes log
when      who       what
10.22.99  Dan       Creation 


*******************************************************************************/


#ifndef STARTUPPROCESSOBJECT_API
#define STARTUPPROCESSOBJECT_API

#include "../../../library/sserver/containers/input.h"
#include "../../../library/sserver/containers/output.h"

#include "../../containers/serverManifest.h"


#define STARTUPPROCESSOBJECT_DEFAULT_RELEGATE_SERVER_IP   "204.131.41.3"
#define STARTUPPROCESSOBJECT_DEFAULT_RELEGATE_SERVER_PORT 8196


class startup_o  {
  private:
    string_o RelegateServerIp;
    int      RelegateServerPort;
    
  public:
    startup_o();                                        // Default constructor.
    startup_o(const startup_o&);                        // Copy contructor.
   ~startup_o();                                        // Default destructor.
    startup_o& operator = (const startup_o&);           // Assignment operator.

    int getAccountsFromRelegateServer(const serverManifest_o&);

};


/******************************************************************************/



#endif

/******************************************************************************/
