/**  bingo.h  ******************************************************************

    Bingo Caller Object.



log_o::debug levels


changes log
when      who       what
9.19.99   Dan       Creation 


*******************************************************************************/


#ifndef BINGOCALLEROBJECT_API
#define BINGOCALLEROBJECT_API

#include "../../library/lib/thread/thread.h"



class bingo_o: public thread_o  {
  private:
    unsigned long       NumberAdvanced;
    
  public:
    bingo_o();                                          // Default constructor.
    bingo_o(const bingo_o&);                            // Copy contructor.
    bingo_o(const thread_o&);
   ~bingo_o();                                          // Default destructor.
    bingo_o& operator = (const bingo_o&);               // Assignment operator.

    void            callbingo();
};
void* callbingo(void*);



/******************************************************************************/



#endif

/******************************************************************************/
