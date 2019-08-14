/**  sortedDatedMessageQueue.h  ************************************************

    Sorted Dated Message Queue Object.


changes log
when       who     what
11.25.99   Dan     Creation. 

*******************************************************************************/


#ifndef SORTEDDATEDMESSAGEQUEUEOBJECT_API
#define SORTEDDATEDMESSAGEQUEUEOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/datedMessage.h"

#define SORTEDDATEDMESSAGEQUEUE_MAX_NUMBER_OF_MESSAGES 2048

class sortedDatedMessageQueueContainer_o  {
  friend class sortedDatedMessageQueue_o;
  private:
    datedMessage_o* DatedMessage;
    sortedDatedMessageQueueContainer_o* Next;

  public:   
    sortedDatedMessageQueueContainer_o();               // Default constructor.
    sortedDatedMessageQueueContainer_o(const sortedDatedMessageQueueContainer_o&);                                                      // Copy constructor.
   ~sortedDatedMessageQueueContainer_o();               // Default destructor.
    sortedDatedMessageQueueContainer_o&  operator =  (const sortedDatedMessageQueueContainer_o&);                                       // Assignment operator.
};

class sortedDatedMessageQueue_o  {
  private:
    short int               NumberOfDatedMessages;
    string_o                OwnerId;
    sortedDatedMessageQueueContainer_o* DatedMessageQueue;

  public:   
    sortedDatedMessageQueue_o();                        // Default constructor.
    sortedDatedMessageQueue_o(const sortedDatedMessageQueue_o&);
                                                        // Copy constructor.
   ~sortedDatedMessageQueue_o();                        // Default destructor.
    sortedDatedMessageQueue_o&  operator =  (const sortedDatedMessageQueue_o&);
                                                        // Assignment operator.

    int                 numberOfDatedMessages() const;
    const char*         ownerId()               const;

    void                setOwnerId(const char*);


    int                 addToQueue(datedMessage_o*);
    datedMessage_o*     removeHeadOfQueue();
    datedMessage_o*     checkQueue(int);
    datedMessage_o*     removeFromQueue(int);
    datedMessage_o*     operator[](int);
};


/******************************************************************************/

inline int sortedDatedMessageQueue_o::numberOfDatedMessages() const  {
    return (int)NumberOfDatedMessages;
}

inline const char* sortedDatedMessageQueue_o::ownerId() const  {
    return OwnerId.string();
}


inline void sortedDatedMessageQueue_o::setOwnerId(const char* oid)  {
    OwnerId = oid;
}


#endif

/******************************************************************************/
