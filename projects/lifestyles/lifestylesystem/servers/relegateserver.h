/**  relegateserver.h  *********************************************************

    Relegate Server Object.

    This server is contacted by the lifestyle servers opon start up
    to receive accounts assigned to the lifestyle server.
    The accounts are assigned by this server to one or many
    lifestyle servers.


changes log
when       who     what
10.22.99   Dan     Creation. 
10.29.99   Dan     Added:    Reporting of server manifest to a browser.

*******************************************************************************/


#ifndef RELEGATESERVEROBJECT_API
#define RELEGATESERVEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/thread/mutex.h"
#include "../../../library/pserver/carapace/carapace.h"

#include "../../containers/serverManifest.h"
#include "../../containers/lifestyleItem.h"


class relegateserver_o  {
  private:
    serverManifest_o    ServerManifest;
    mutex_o             Mutex;
    int                 State;
    unsigned long       NumberProcessed;

    lifestyleItem_o     LifestyleItems[6];

  protected:


  public:   
    relegateserver_o();                                 // Default constructor.
    relegateserver_o(const relegateserver_o&);          // Copy constructor.
   ~relegateserver_o();                                 // Default destructor.
    relegateserver_o&  operator =  (const relegateserver_o&);
                                                        // Assignment operator.

          int       process(input_o&,output_o&);
          int       htmlinput(input_o&,output_o&);

          int       state()                     const;
    const char*     id()                        const;
    unsigned long   numberProcessed()           const;
    const serverManifest_o& serverManifest();

};


/******************************************************************************/

inline int relegateserver_o::state() const  {
    return State;
}

inline unsigned long relegateserver_o::numberProcessed() const  {
    return NumberProcessed;
}

inline const char* relegateserver_o::id() const  {
    return ServerManifest.id();
}

inline const serverManifest_o& relegateserver_o::serverManifest()  {
    ServerManifest.setNumberProcessed(NumberProcessed);
    ServerManifest.setState(State);
    return ServerManifest;
}


#endif

/******************************************************************************/
