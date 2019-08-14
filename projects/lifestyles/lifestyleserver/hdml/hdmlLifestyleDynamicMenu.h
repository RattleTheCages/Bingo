/**  hdmlLifestyleDynamicMenu.h  ******************************************************


    HDML Lifestyle Menu Object.


changes log
when       who      what
10.8.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLLIFESTYLEMENUOBJECT_API
#define HDMLLIFESTYLEMENUOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlLifestyleDynamicMenu_o  {
  private:
    void            init();

  public:
    hdmlLifestyleDynamicMenu_o();                              // Default constructor.
    hdmlLifestyleDynamicMenu_o(const hdmlLifestyleDynamicMenu_o&);    // Copy constructor.
   ~hdmlLifestyleDynamicMenu_o();                              // Default destructor.
    hdmlLifestyleDynamicMenu_o& operator = (const hdmlLifestyleDynamicMenu_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
