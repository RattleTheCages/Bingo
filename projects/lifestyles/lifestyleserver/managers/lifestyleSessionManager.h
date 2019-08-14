/**  lifestyleSessionManager.h  ************************************************

    PDA Session Manager Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/


#ifndef LIFESTYLESESSIONMANAGEROBJECT_API
#define LIFESTYLESESSIONMANAGEROBJECT_API


#include "../../../library/lib/memory/cache.h"
#include "../../dynamicContainers/lifestyleSession.h"


class lifestyleSessionManager_o  {
  friend class lifestyleserver_o;
  private:
    cache_o<lifestyleSession_o> lifestyleSessions;

    void        init();

  public:
    lifestyleSessionManager_o();                      // Default constructor.
    lifestyleSessionManager_o(const lifestyleSessionManager_o&);// Copy constuctor.
   ~lifestyleSessionManager_o();                          // Default desructor.
    lifestyleSessionManager_o& operator = (const lifestyleSessionManager_o&);
                                                    // Assignment operator.

    lifestyleSession_o* newSession(const char*);
    lifestyleSession_o* findSession(string_o&);
    lifestyleSession_o* saveSession(lifestyleSession_o*);
};


/******************************************************************************/


#endif

/******************************************************************************/
