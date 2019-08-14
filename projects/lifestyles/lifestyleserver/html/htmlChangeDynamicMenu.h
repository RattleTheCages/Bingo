/**  htmlChangeDynamicMenu.h  **************************************************


    HTML Change Dynamic Menu Settings Object.


changes log
when       who      what
12.4.99    Dan      Creation.

*******************************************************************************/


#ifndef HTMLCHANGEDYNAMICMENUOBJECT_API
#define HTMLCHANGEDYNAMICMENUOBJECT_API


#include "../../../library/lib/string/string.h"

#include "../../containers/lifestyleItem.h"
#include "../../dynamicContainers/lifestyleSession.h"


class htmlChangeDynamicMenu_o  {
  private:
    void          init();

  public:
    htmlChangeDynamicMenu_o();                                    // Default constructor.
    htmlChangeDynamicMenu_o(const htmlChangeDynamicMenu_o&);                    // Copy constructor.
   ~htmlChangeDynamicMenu_o();                                    // Default destructor.
    htmlChangeDynamicMenu_o& operator = (const htmlChangeDynamicMenu_o&);       // Asignment operator.

    void page(const lifestyleItem_o&,const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
