/**  bingoSessionManager.cc  ***************************************************



changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/


#include "../managers/bingoSessionManager.h"


extern log_o               log;

bingoSessionManager_o::bingoSessionManager_o()  {
    (void)init();
}

bingoSessionManager_o::~bingoSessionManager_o()  {}

void bingoSessionManager_o::init()  {}

bingoSession_o* bingoSessionManager_o::newSession(const char* id)  {
    bingoSession_o* bingoSession = new bingoSession_o();
    if(bingoSession && id)  {
        bingoSession->setId(id);
        return bingoSession;
    }
    return NULL;
}

bingoSession_o* bingoSessionManager_o::saveSession(bingoSession_o* bingoSession)  {
    string_o s;
    s << bingoSession->id();
    bingoSessions.insert(s,bingoSession);
    return bingoSession;
}

bingoSession_o* bingoSessionManager_o::findSession(string_o& s)  {
    bingoSession_o* bingoSession;
    cacheSearch_o<bingoSession_o>* cs;
    cs = new cacheSearch_o<bingoSession_o>(&bingoSessions);

    bingoSession = cs->find(s.string());
    delete cs;
    if(bingoSession)  bingoSession->incrementTransactions();
    return bingoSession;
}


/******************************************************************************/
