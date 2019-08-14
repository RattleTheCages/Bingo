/**  datedMessage.h  ***********************************************************

    Dated Message Container Object.


changes log
when       who     what
11.24.99   Dan     Creation. 

*******************************************************************************/


#ifndef DATEDMESSAGEOBJECT_CONTAINER
#define DATEDMESSAGEOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define DATEDMESSAGE_MESSAGE "datedMessage_o.message"
#define DATEDMESSAGE_DELIVERTIME "datedMessage_o.deliver"
#define DATEDMESSAGE_EXPIRETIME "datedMessage_o.expire"
#define DATEDMESSAGE_SENTTIME "datedMessage_o.sent"
#define DATEDMESSAGE_ID "datedMessage_o.id"
#define DATEDMESSAGE_VALID "datedMessage_o.valid"
#define DATEDMESSAGE_HOUR "datedMessage_o.hour"
#define DATEDMESSAGE_MINUTE "datedMessage_o.minute"
#define DATEDMESSAGE_MONTH "datedMessage_o.month"
#define DATEDMESSAGE_DAY "datedMessage_o.day"

#define DATEDMESSAGE_MAX_MESSAGE_LENGTH 4096


class datedMessage_o  {
  protected:
    string_o    Id;
    short int   Valid;
    int         DeliverTime;
    int         ExpireTime;
    int         SentTime;
    string_o    Message;

  public:   
    datedMessage_o();                               // Default constructor.
    datedMessage_o(const datedMessage_o&);          // Copy constructor.
   ~datedMessage_o();                               // Default destructor.
    datedMessage_o& operator =  (const datedMessage_o&);
                                                    // Assignment operator.
    void            operator >> (string_o&) const;  // OLP.
    void            operator << (const char*);      // Reconstruct from OLP.
    void            clear();
    int             blank()                 const;

    const char*     id()                    const;
    int             valid()                 const;
    const char*     message()               const;
    int             deliverTime()           const;
    int             expireTime()            const;
    int             sentTime()              const;


    void            setId(const char*);
    void            setValid(int);
    void            setMessage(const char*);
    void            setDeliverTime(int);
    void            setExpireTime(int);
    void            setSentTime(int);

};
string_o& operator << (string_o&,const datedMessage_o&);


/******************************************************************************/

inline const char* datedMessage_o::id() const  {
    return  Id.string();
}

inline int datedMessage_o::valid() const  {
    return  (int)Valid;
}

inline const char* datedMessage_o::message() const  {
    return  Message.string();
}

inline int datedMessage_o::deliverTime() const  {
    return DeliverTime;
}

inline int datedMessage_o::expireTime() const  {
    return ExpireTime;
}

inline int datedMessage_o::sentTime() const  {
    return SentTime;
}


inline void datedMessage_o::setMessage(const char* mesg)  {
    Message = mesg;
    Message.cut(DATEDMESSAGE_MAX_MESSAGE_LENGTH);
}

inline void datedMessage_o::setValid(int v)  {
    Valid = (short int)v;
}

inline void datedMessage_o::setDeliverTime(int dt)  {
    DeliverTime = dt;
}

inline void datedMessage_o::setExpireTime(int et)  {
    ExpireTime = et;
}

inline void datedMessage_o::setSentTime(int st)  {
    SentTime = st;
}


#endif

/******************************************************************************/

