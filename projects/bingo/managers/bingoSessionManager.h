/**  bingoSessionManager.h  ****************************************************

    PDA Session Manager Object.


changes log
when       who      what
9.9.99     Dan      Creation.

*******************************************************************************/


#ifndef BINGOSESSIONMANAGEROBJECT_API
#define BINGOSESSIONMANAGEROBJECT_API


#include "../containers/bingoSession.h"
#include "../../library/lib/memory/cache.h"


//#define BINGOSESSIONMANAGER_MAX_OPEN_SESSIONS 1024

class bingoSessionManager_o  {
  friend class bingodealer_o;
  private:
    cache_o<bingoSession_o> bingoSessions;

    void        init();

  public:
    bingoSessionManager_o();                          // Default constructor.
    bingoSessionManager_o(const bingoSessionManager_o&);// Copy constuctor.
   ~bingoSessionManager_o();                          // Default desructor.
    bingoSessionManager_o& operator = (const bingoSessionManager_o&);
                                                    // Assignment operator.

    bingoSession_o* newSession(const char*);
    bingoSession_o* findSession(string_o&);
    bingoSession_o* saveSession(bingoSession_o*);
};


/******************************************************************************/


#endif

/******************************************************************************/
