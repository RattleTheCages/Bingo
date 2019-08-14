/**  sortedDatedMessageQueue.cc  ***********************************************

changes log
when       who     what
11.25.99   Dan     Creation. 


*******************************************************************************/


#include "../../library/lib/error/error.h"
#include "../dynamicContainers/sortedDatedMessageQueue.h"

#ifndef NULL
#define NULL 0
#endif 

sortedDatedMessageQueueContainer_o::sortedDatedMessageQueueContainer_o()  {
    DatedMessage = NULL;
    Next         = NULL;
}

sortedDatedMessageQueueContainer_o::~sortedDatedMessageQueueContainer_o()  {
//!!!!!!!!  Delete Stuff!!!!
}


sortedDatedMessageQueue_o::sortedDatedMessageQueue_o()  {
    NumberOfDatedMessages = 0;

    DatedMessageQueue = NULL;
}

sortedDatedMessageQueue_o::~sortedDatedMessageQueue_o()  {
//!!!!!!!!  Delete all remaining datedMessage_o* objects!!!!!!
}


int sortedDatedMessageQueue_o::addToQueue(datedMessage_o* dedm)  {
    sortedDatedMessageQueueContainer_o* sdedmqc;
    sortedDatedMessageQueueContainer_o* newsdedmqc;
    if(!dedm)  return ERROR_NULL_PASSED;

    newsdedmqc = new sortedDatedMessageQueueContainer_o;
    if(!newsdedmqc)  {
        return ERROR_OUT_OF_MEMORY;
    }
    newsdedmqc->DatedMessage = dedm;

    if(!DatedMessageQueue)  {
        DatedMessageQueue = newsdedmqc;
    }
    else  {

        sdedmqc = DatedMessageQueue;

        while(sdedmqc)  {
            if(sdedmqc->Next == NULL)  {
                sdedmqc->Next = newsdedmqc;

                break;
            }
            if(dedm->deliverTime() < sdedmqc->Next->DatedMessage->deliverTime())  {
                newsdedmqc->Next = sdedmqc->Next;
                sdedmqc->Next = newsdedmqc;

                break;
            }

            sdedmqc = sdedmqc->Next;
        }

    }


    NumberOfDatedMessages++;

    return ERROR_OK;
}

datedMessage_o* sortedDatedMessageQueue_o::removeHeadOfQueue()  {
    datedMessage_o* dmp;
    sortedDatedMessageQueueContainer_o* sdedmqc;

    sdedmqc = DatedMessageQueue;
    DatedMessageQueue = DatedMessageQueue->Next;

    NumberOfDatedMessages--;

    dmp = sdedmqc->DatedMessage;
    delete sdedmqc;
    return dmp;
}

datedMessage_o* sortedDatedMessageQueue_o::removeFromQueue(int index)  {
    int x;
    datedMessage_o* dmp;
    sortedDatedMessageQueueContainer_o* sdedmqc;
    sortedDatedMessageQueueContainer_o* sdedmqcret;
    if(NumberOfDatedMessages < index)  return NULL;

    sdedmqc = DatedMessageQueue;

    for(x=0;x<index-1;x++)  {
        sdedmqc = sdedmqc->Next;
    }

    sdedmqcret = sdedmqc->Next;
    sdedmqc->Next = sdedmqcret->Next;

    NumberOfDatedMessages--;

    dmp = sdedmqcret->DatedMessage;
    delete sdedmqcret;
    return dmp;
}

datedMessage_o* sortedDatedMessageQueue_o::operator[] (int index)  {
    int x;
    sortedDatedMessageQueueContainer_o* sdedmqc;
    if(NumberOfDatedMessages < index)  return NULL;

    sdedmqc = DatedMessageQueue;

    for(x=0;x<index;x++)  {
        sdedmqc = sdedmqc->Next;
    }

    return sdedmqc->DatedMessage;
}




/******************************************************************************/
