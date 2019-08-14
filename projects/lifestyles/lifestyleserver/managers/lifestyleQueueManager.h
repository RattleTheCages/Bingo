/**  lifestyleQueueManager.h  **************************************************

    Lifestylesession Queue Manager Object.


changes log
when       who      what
10.22.99   Dan      Creation.

*******************************************************************************/


#ifndef LIFESTYLEQUEUEMANAGEROBJECT_API
#define LIFESTYLEQUEUEMANAGEROBJECT_API


#include "../../../library/lib/thread/queue.h"

#include "../../dynamicContainers/lifestyleSession.h"


class lifestyleQueueManager_o  {
  friend class lifestyleserver_o;
  private:
public://!!
    queue_o<lifestyleSession_o> ArchiveSessionsQueue;

    void        init();

  public:
    lifestyleQueueManager_o();                          // Default constructor.
    lifestyleQueueManager_o(const lifestyleQueueManager_o&);// Copy constuctor.
   ~lifestyleQueueManager_o();                          // Default desructor.
    lifestyleQueueManager_o& operator = (const lifestyleQueueManager_o&);


};


/******************************************************************************/


#endif

/******************************************************************************/
