/**  lifestyleserver.h  ********************************************************

    Lifestyle Server Object.


changes log
when       who     what
10.7.99    Dan     Creation. 
10.22.99   Dan     Added:    Array of new lifestyleItem objects, queue manager.
11.25.99   Dan     Changed:  Abstracted find lifestyle session by passcode
                             into its own method.

*******************************************************************************/


#ifndef LIFESTYLESERVEROBJECT_API
#define LIFESTYLESERVEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/thread/mutex.h"
#include "../../../library/pserver/carapace/carapace.h"



#include "../../containers/serverManifest.h"
#include "../../containers/service.h"
#include "../../containers/passcode.h"
#include "../../containers/lifestyleItem.h"
#include "../../dynamicContainers/lifestyleSession.h"
#include "../process/htmlinput.h"
#include "../process/startup.h"
#include "../managers/lifestyleSessionManager.h"
#include "../managers/lifestyleQueueManager.h"



#define LIFESTYLESERVER_MAX_NUMBER_OF_SERVICES   72
#define LIFESTYLESERVER_MAX_NUMBER_OF_ITEMS       6
#define LIFESTYLESERVER_MAX_NUMBER_OF_PATRIONS  444

#define LIFESTYLESERVER_DEFAULT_USER_PORT 4111
#define LIFESTYLESERVER_DEFAULT_API_PORT 4211

#define LIFESTYLESERVER_DEFAULT_PASSCODE_SERVER_IP   "204.131.41.3"
#define LIFESTYLESERVER_DEFAULT_PASSCODE_SERVER_PORT 9047

class lifestyleserver_o  {
  private:
    mutex_o       mutex;
    unsigned long NumberProcessed;


public://!!
    int           NumberOfServices;
    service_o     Services[LIFESTYLESERVER_MAX_NUMBER_OF_SERVICES];

    int             NumberOfLifestyleItems;
    lifestyleItem_o LifestyleItems[LIFESTYLESERVER_MAX_NUMBER_OF_ITEMS];


  protected:
    serverManifest_o ServerManifest;
    int         State;

    string_o    EmergencyBroadcast;

  protected:
    startup_o Startup;
    int           pc;
    int           generatePassCode(passcode_o&);

    lifestyleSession_o* findLifestyleSessionByPasscode(const passcode_o&);
    lifestyleSession_o* findLifestyleSessionByUserid(const char*);

          int       pdainput(input_o&,output_o&);
          int       htmlinput(input_o&,output_o&);
          int       htmlinputLoggedinUser(lifestyleSession_o*,input_o&,output_o&);
          int       lifestyleIteminput(input_o&,output_o&);
          int       serviceinput(input_o&,output_o&);
          int       sessioninput(input_o&,output_o&);
          int       rotatingBannerInput(input_o&,output_o&);
          int       entityInput(input_o&,output_o&);
          int       changeLifestyleSettings(lifestyleSession_o*,input_o&,string_o&);


  public:   
    lifestyleserver_o();                                // Default constructor.
    lifestyleserver_o(const lifestyleserver_o&);        // Copy constructor.
   ~lifestyleserver_o();                                // Default destructor.
    lifestyleserver_o&  operator =  (const lifestyleserver_o&);
                                                        // Assignment operator.

          int       startup();

          int       process(input_o&,output_o&);

          int       weather(const lifestyleSession_o&,string_o&);
          int       messages(lifestyleSession_o&,string_o&);

          int       state()                     const;
    const char*     id()                        const;
    unsigned long   numberProcessed()           const;
    const serverManifest_o& serverManifest();
    const char*     emergencyBroadcast()        const;
          int       numberOfServices()          const;
          int       numberOfLifestyleItems()    const;

          void      setEmergencyBroadcast(const char*);

};


/******************************************************************************/

inline int lifestyleserver_o::state() const  {
    return  State;
}

inline int lifestyleserver_o::numberOfLifestyleItems() const  {
    return  NumberOfLifestyleItems;
}

inline int lifestyleserver_o::numberOfServices() const  {
    return  NumberOfServices;
}

inline unsigned long lifestyleserver_o::numberProcessed() const  {
    return NumberProcessed;
}

inline const char* lifestyleserver_o::id() const  {
    return ServerManifest.id();
}

inline const serverManifest_o& lifestyleserver_o::serverManifest()  {
    ServerManifest.setNumberProcessed(NumberProcessed);
    ServerManifest.setState(State);
    return ServerManifest;
}

inline const char* lifestyleserver_o::emergencyBroadcast() const  {
    return  EmergencyBroadcast.string();
}

inline void lifestyleserver_o::setEmergencyBroadcast(const char* eb)  {
    EmergencyBroadcast = eb;
}



#endif

/******************************************************************************/
