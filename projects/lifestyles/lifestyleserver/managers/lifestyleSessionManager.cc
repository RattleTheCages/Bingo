/**  lifestyleSessionManager.cc  ***********************************************



changes log
when       who      what
10.7.99     Dan      Creation.


*******************************************************************************/


#include "../managers/lifestyleSessionManager.h"


extern log_o               log;

lifestyleSessionManager_o::lifestyleSessionManager_o()  {
    (void)init();
}

lifestyleSessionManager_o::~lifestyleSessionManager_o()  {}

void lifestyleSessionManager_o::init()  {}

lifestyleSession_o* lifestyleSessionManager_o::newSession(const char* id)  {
    lifestyleSession_o* lifestyleSession = new lifestyleSession_o();
    if(lifestyleSession && id)  {
        lifestyleSession->setId(id);
        return lifestyleSession;
    }
    return NULL;
}

lifestyleSession_o* lifestyleSessionManager_o::saveSession(lifestyleSession_o* lifestyleSession)  {
    string_o s;
    s << lifestyleSession->id();
    lifestyleSessions.insert(s,lifestyleSession);
    return lifestyleSession;
}

lifestyleSession_o* lifestyleSessionManager_o::findSession(string_o& s)  {
    lifestyleSession_o* lifestyleSession;
    cacheSearch_o<lifestyleSession_o>* cs;
    cs = new cacheSearch_o<lifestyleSession_o>(&lifestyleSessions);

    lifestyleSession = cs->find(s.string());
    delete cs;
    if(lifestyleSession)  lifestyleSession->incrementTransactions();
    return lifestyleSession;
}


/******************************************************************************/
