/**  lifestyleSession.h  *******************************************************


changes log
when       who     what
10.7.99    Dan     Creation. 
10.22.99   Dan     Added:    A mutex.
11.24.99   Dan     Added:    Data members to faslitate changing the current
                             lifestyle because of the time of day.
12.4.99    Dan     Added:    New object passcode_o.
12.11.99   Dan     Added:    New object actdate_o.

*******************************************************************************/


#ifndef LIFESTYLESESSIONOBJECT_API
#define LIFESTYLESESSIONOBJECT_API

#include "../../library/lib/log/log.h"
#include "../../library/lib/cron/time.h"
#include "../../library/lib/string/string.h"
#include "../../library/lib/other/list.h"
#include "../../library/lib/thread/mutex.h"

#include "../containers/address.h"
#include "../containers/passcode.h"
#include "../containers/actdate.h"
#include "../containers/service.h"
#include "../containers/lifestyleItem.h"
#include "../dynamicContainers/sortedDatedMessageQueue.h"


#define LIFESTYLESESSION_TRANSACTIONS       "lifestylesession_o.transactions"
#define LIFESTYLESESSION_ID                 "lifestylesession_o.id"
#define LIFESTYLESESSION_REGISTEREDUSER     "lifestylesession_o.registereduser"
#define LIFESTYLESESSION_PASSCODE           "lifestylesession_o.passcode"
#define LIFESTYLESESSION_NUMBEROFLIFESTYLES "lifestylesession_o.numberoflifestyles"
#define LIFESTYLESESSION_SERVICEMAP         "lss_o.sm"
#define LIFESTYLESESSION_ADDRESS            "lifestylesession_o.address"
#define LIFESTYLESESSION_ACTDATE            "lifestylesession_o.actdate"


#define LIFESTYLESESSION_LIFESTYLE_ITEM_MAX  6
#define LIFESTYLESESSION_ADDRESS_OBJECT_MAX  6
#define LIFESTYLESESSION_ACTDATE_OBJECT_MAX  LIFESTYLESESSION_LIFESTYLE_ITEM_MAX*4
#define LIFESTYLESESSION_SERVICES_MAX       72


class lifestyleSession_o  {
  friend class lifestyleserver_o;
  protected:
    unsigned long int   Transactions;
    string_o            Id;
    short int           RegisteredUser;
    short int           NumberOfLifestyles;
    short int           ServicesMap[LIFESTYLESESSION_LIFESTYLE_ITEM_MAX][LIFESTYLESESSION_SERVICES_MAX];
    address_o           Address[LIFESTYLESESSION_ADDRESS_OBJECT_MAX];
    actdate_o           Actdate[LIFESTYLESESSION_ACTDATE_OBJECT_MAX];
    passcode_o          Passcode;

  private:
    mutex_o             Mutex;
    int                 State;
    int                 MessagePending;
    string_o            Message;
    int                 EmergencyBroadcastPending;

public://!!
    sortedDatedMessageQueue_o SortedDatedMessageQueue;


  public:   
    lifestyleSession_o();                               // Default constructor.
    lifestyleSession_o(const lifestyleSession_o&);      // Copy constructor.
   ~lifestyleSession_o();                               // Default destructor.
    lifestyleSession_o& operator = (const lifestyleSession_o&);
                                                        // Assignment operator.
    void            operator >> (string_o&) const;      // Node-Value.
    void            operator << (const char*);          // Reconstruct.
    void            init();
    void            clear();                            // Clear data members.

          int       setMap(service_o*,lifestyleItem_o*);

          int       transactions()             const;
          int       incrementTransactions();

    const char*     id()                       const;   // Session id.
          int       state()                    const;
          int       registeredUser()           const;
    const passcode_o&   passcode()             const;
    const char*     stateText(int)             const;
          int       numberOfLifestyles()       const;
          int       emergencyBroadcastPending()   const;
    const char*     message()                  const;
          int       messagePending()           const;
          int       servicesMap(int,int)       const;
    const address_o& address(int) const;
    const actdate_o& actdate(int) const;
          int       numberOfDatedMessages()    const;

          void      setId(const char*);
          void      setState(int);
          void      setRegisteredUser();
//          void      setPassCode(const char*);
          void      setEmergencyBroadcastPending();
          void      resetEmergencyBroadcastPending();
          void      setMessage(const char*);
          void      setMessagePending();
          void      resetMessagePending();
};


/******************************************************************************/

inline const char* lifestyleSession_o::id() const  {
    return Id.string();
}

inline const passcode_o& lifestyleSession_o::passcode() const  {
    return Passcode;
}

inline const char* lifestyleSession_o::message() const  {
    return Message.string();
}

inline int lifestyleSession_o::transactions() const  {
    return Transactions;
}

inline int lifestyleSession_o::numberOfLifestyles() const  {
    return NumberOfLifestyles;
}

inline int lifestyleSession_o::servicesMap(int x,int y) const  {
    if(x < 0 || x > LIFESTYLESESSION_LIFESTYLE_ITEM_MAX || y < 0 || y > LIFESTYLESESSION_SERVICES_MAX)  return 0;
    return ServicesMap[x][y];
}

inline int lifestyleSession_o::state() const  {
    return State;
}

inline int lifestyleSession_o::emergencyBroadcastPending() const  {
    return EmergencyBroadcastPending;
}

inline int lifestyleSession_o::messagePending() const  {
    return MessagePending;
}

inline int lifestyleSession_o::registeredUser() const  {
    return RegisteredUser;
}

inline int lifestyleSession_o::numberOfDatedMessages() const  {
    return SortedDatedMessageQueue.numberOfDatedMessages();
}

inline const address_o& lifestyleSession_o::address(int a) const  {
    if(a > 0 && a < LIFESTYLESESSION_ADDRESS_OBJECT_MAX)  {
        return  Address[a];
    }
    return  Address[0];
}

inline const actdate_o& lifestyleSession_o::actdate(int a) const  {
    if(a > 0 && a < LIFESTYLESESSION_ACTDATE_OBJECT_MAX)  {
        return  Actdate[a];
    }
    return  Actdate[0];
}

inline void lifestyleSession_o::setId(const char* i)  {
    Id = i;
}

/*
inline void lifestyleSession_o::setPassCode(const char* pc)  {
    PassCode = pc;
}
*/

inline void lifestyleSession_o::setMessage(const char* pc)  {
    Message = pc;
}

inline void lifestyleSession_o::setState(int s)  {
    if(s < 0 || s >= LIFESTYLESESSION_LIFESTYLE_ITEM_MAX)  return;
    State = s;
}

inline int lifestyleSession_o::incrementTransactions()  {
    return  (Transactions++);
}

inline void lifestyleSession_o::setRegisteredUser()  {
    RegisteredUser = 1;
}

inline void lifestyleSession_o::setEmergencyBroadcastPending()  {
    EmergencyBroadcastPending = 1;
}

inline void lifestyleSession_o::resetEmergencyBroadcastPending()  {
    EmergencyBroadcastPending = 0;
}

inline void lifestyleSession_o::setMessagePending()  {
    MessagePending = 1;
}

inline void lifestyleSession_o::resetMessagePending()  {
    MessagePending = 0;
}


#endif

/******************************************************************************/
