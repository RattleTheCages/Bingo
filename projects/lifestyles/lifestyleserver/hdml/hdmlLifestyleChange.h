/**  hdmlLifestyleChange.h  ****************************************************


    HDML Lifestyle Change Menu Object.


changes log
when       who      what
10.7.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLLIFESTYLECHANGEOBJECT_API
#define HDMLLIFESTYLECHANGEOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlLifestyleChange_o  {
  private:
    void            init();

  public:
    hdmlLifestyleChange_o();                                   // Default constructor.
    hdmlLifestyleChange_o(const hdmlLifestyleChange_o&);                  // Copy constructor.
   ~hdmlLifestyleChange_o();                                   // Default destructor.
    hdmlLifestyleChange_o& operator = (const hdmlLifestyleChange_o&);     // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
