/**  htmlSideMenu.h  ***********************************************************


    HTML Side Menu Object.


changes log
when       who      what
12.4.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLSIDEMENUOBJECT_API
#define HTMLSIDEMENUOBJECT_API


#include "../../../library/lib/string/string.h"


class htmlSideMenu_o  {
  private:
    void          init();

  public:
    htmlSideMenu_o();                                   // Default constructor.
    htmlSideMenu_o(const htmlSideMenu_o&);              // Copy constructor.
   ~htmlSideMenu_o();                                   // Default destructor.
    htmlSideMenu_o& operator = (const htmlSideMenu_o&); // Assignment operator.

    void page(string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
