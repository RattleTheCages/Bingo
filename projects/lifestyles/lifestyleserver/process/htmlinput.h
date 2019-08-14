/**  htmlinput.h  **************************************************************

    HTML Input Object.



log_o::debug levels


changes log
when      who       what
10.22.99  Dan       Creation 


*******************************************************************************/


#ifndef HTMLINPUTOBJECT_API
#define HTMLINPUTOBJECT_API

#include "../../../library/sserver/containers/input.h"
#include "../../../library/sserver/containers/output.h"


class htmlinput_o  {
  private:
    unsigned long       NumberAdvanced;
    
  public:
    htmlinput_o();                                      // Default constructor.
    htmlinput_o(const htmlinput_o&);                    // Copy contructor.
   ~htmlinput_o();                                      // Default destructor.
    htmlinput_o& operator = (const htmlinput_o&);       // Assignment operator.

    int input(input_o&,output_o&);

};


/******************************************************************************/



#endif

/******************************************************************************/
