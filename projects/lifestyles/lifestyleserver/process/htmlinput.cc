/**  htmlinput.cc  *************************************************************




changes log
when      who       what
9.22.99   Dan       Creation

*******************************************************************************/


#include <unistd.h>
#include <stdlib.h>

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/log/log.h"

#include "../process/htmlinput.h"

extern log_o log;


htmlinput_o::htmlinput_o()  {
    NumberAdvanced = 0;
}

htmlinput_o::~htmlinput_o()  {}

int htmlinput_o::input(input_o& input,output_o& output)  {
    string_o message;

    return ERROR_OK;
}


/******************************************************************************/
