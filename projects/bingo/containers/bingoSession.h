/**  bingoSession.h  *************************************************************


changes log
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/

#ifndef PDASESSIONOBJECT_API
#define PDASESSIONOBJECT_API

#include "../../library/lib/log/log.h"
#include "../../library/lib/cron/time.h"
#include "../../library/lib/string/string.h"
#include "../../library/lib/other/list.h"

#include "../containers/bingocard.h"


#define BINGOSESSION_ID    "bingoSession_o.id"
#define BINGOSESSION_STATE "bingoSession_o.state"


#define BINGOSESSION_STATE_PLAYING                4355
#define BINGOSESSION_STATE_WAITING_FOR_NEXT_GAME  4356
#define BINGOSESSION_STATE_NOT_PLAYING            4357


class bingoSession_o  {
  private:
    int                 Transactions;

    string_o            Id;
    int                 State;
    string_o            JoinedGameId;
    bingocard_o         Bingocard;

  protected:
    void                init();

  public:   
    bingoSession_o();                                   // Default constructor.
    bingoSession_o(const bingoSession_o&);              // Copy constructor.
   ~bingoSession_o();                                   // Default destructor.
    bingoSession_o& operator = (const bingoSession_o&); // Assignment operator.
    void            operator >> (string_o&) const;      // Node-Value.
    void            operator << (const char*);          // Reconstruct.
    void            clear();                            // Clear data members.

          int       transactions()             const;
          int       incrementTransactions();

    const char*     id()                       const;   // Session id.
          int       state()                    const;

          void      setId(const char*);
          void      setState(int);


    const bingocard_o&    bingocard() const;
    const char*     joinedGameId()             const;
          void      setJoinedGameId(const char*);
};
string_o& operator << (string_o&,const bingoSession_o&);


/******************************************************************************/

inline const char* bingoSession_o::id() const  {
    return Id.string();
}

inline int bingoSession_o::transactions() const  {
    return Transactions;
}

inline int bingoSession_o::state() const  {
    return State;
}

inline void bingoSession_o::setId(const char* i)  {
    Id = i;
}

inline void bingoSession_o::setState(int s)  {
    State = s;
}

inline int bingoSession_o::incrementTransactions()  {
    return (Transactions++);
}

inline const bingocard_o& bingoSession_o::bingocard() const  {
    return  Bingocard;
}

inline const char* bingoSession_o::joinedGameId() const  {
    return  JoinedGameId.string();
}

inline void bingoSession_o::setJoinedGameId(const char* id)  {
    JoinedGameId = id;
}


#endif

/******************************************************************************/
