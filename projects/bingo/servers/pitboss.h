/**  pitboss.h  ****************************************************************

    Pit Boss Server Object.


changes log
when       who     what
9.22.99    Dan     Creation. 

*******************************************************************************/


#ifndef PITBOSSOBJECT_API
#define PITBOSSOBJECT_API

#include "../../library/lib/string/string.h"
#include "../../library/pserver/carapace/carapace.h"


class pitboss_o  {
  protected:

  public:   
    pitboss_o();                                        // Default constructor.
    pitboss_o(const pitboss_o&);                        // Copy constructor.
   ~pitboss_o();                                        // Default destructor.
    pitboss_o&      operator =  (const pitboss_o&);     // Assignment operator.

    int process(input_o&,output_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
