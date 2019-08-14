/**  htmlLifestyleUserMenu.h  **************************************************


    HTML LifestyleUserMenu Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLLIFESTYLEUSERMENUOBJECT_API
#define HTMLLIFESTYLEUSERMENUOBJECT_API


#include "../../../library/lib/string/string.h"

#include "../../dynamicContainers/lifestyleSession.h"


class htmlLifestyleUserMenu_o  {
  private:
    void          init();

  public:
    htmlLifestyleUserMenu_o();                          // Default constructor.
    htmlLifestyleUserMenu_o(const htmlLifestyleUserMenu_o&);
                                                        // Copy constructor.
   ~htmlLifestyleUserMenu_o();                          // Default destructor.
    htmlLifestyleUserMenu_o& operator = (const htmlLifestyleUserMenu_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
