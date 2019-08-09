/**  bingo.cc  *****************************************************************




changes log
when      who       what
9.19.99   Dan       Creation

*******************************************************************************/


#include <stdlib.h>

#include "../../library/lib/string/string.h"
#include "../../library/lib/log/log.h"
#include "../../library/lib/other/rand.h"

#include "../process/bingo.h"
#include "../containers/bingoball.h"
#include "../containers/bingogame.h"
#include "../containers/bingocard.h"


extern log_o log;
extern bingogame_o bingogame;


void* callbingo(void* v)  {
    bingo_o* b = (bingo_o*)v;
    b->callbingo();
    return v;
}


bingo_o::bingo_o(const thread_o& thread): thread_o(thread)  {
    NumberAdvanced  = 0;
}

bingo_o::~bingo_o()  {}

void bingo_o::callbingo()  {
while(1)  {
//    ::system("./bingocaller 204.131.41.107 8844");
//sleep(10);
}
}


/******************************************************************************/
