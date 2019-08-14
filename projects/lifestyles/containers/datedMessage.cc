/**  datedMessage.cc  **********************************************************

changes log
when       who     what
11.24.99   Dan     Creation. 


*******************************************************************************/


#include "../containers/datedMessage.h"
#include "../../library/lib/parse/parse.h"

datedMessage_o::datedMessage_o()  {
    clear();
}

datedMessage_o::datedMessage_o(const datedMessage_o& dm)  {
    Id = dm.Id;
    Valid = dm.Valid;
    Message = dm.Message;
    DeliverTime = dm.DeliverTime;
    ExpireTime  = dm.ExpireTime;
    SentTime    = dm.SentTime;
}

datedMessage_o::~datedMessage_o()  {}

void datedMessage_o::clear()  {
    Id = "";
    Valid = 1;
    Message = "";
    DeliverTime = -1;
    ExpireTime  = -1;
    SentTime    = -1;
}

int datedMessage_o::blank() const  {
    if(Message.length() < 2)  return 1;
    return 0;
}

datedMessage_o& datedMessage_o::operator = (const datedMessage_o& dm)  {
    Id          = dm.Id;
    Valid       = dm.Valid;
    Message     = dm.Message;
    DeliverTime = dm.DeliverTime;
    ExpireTime  = dm.ExpireTime;
    SentTime    = dm.SentTime;
    return *this;
}

void datedMessage_o::operator >> (string_o& s) const  {
    s << "\ndatedMessage_o:";
    s << '\n' << DATEDMESSAGE_ID << '=' << Id;
    s << '\n' << DATEDMESSAGE_VALID << '=' << Valid;
    s << '\n' << DATEDMESSAGE_MESSAGE << '=' << Message;
    s << '\n' << DATEDMESSAGE_DELIVERTIME << '=' << DeliverTime;
    s << '\n' << DATEDMESSAGE_EXPIRETIME << '=' << ExpireTime;
    s << '\n' << DATEDMESSAGE_SENTTIME << '=' << SentTime;
    s << '\n';
}

void datedMessage_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(DATEDMESSAGE_ID,Id);
    (void)parse.it(DATEDMESSAGE_VALID,Valid);
    (void)parse.it(DATEDMESSAGE_MESSAGE,Message);
    (void)parse.it(DATEDMESSAGE_DELIVERTIME,DeliverTime);
    (void)parse.it(DATEDMESSAGE_EXPIRETIME,ExpireTime);
    (void)parse.it(DATEDMESSAGE_SENTTIME,SentTime);
}

string_o& operator << (string_o& s,const datedMessage_o& dm)  {
    dm >> s;
    return s;
}


/******************************************************************************/
