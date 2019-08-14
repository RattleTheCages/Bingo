/**  htmlSideMenuLoggedin.h  ***************************************************


    HTML Side MenuLoggedin Object.


changes log
when       who      what
12.4.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLSIDEMENULOGGEDINOBJECT_API
#define HTMLSIDEMENULOGGEDINOBJECT_API


#include "../../../library/lib/string/string.h"

#include "../../dynamicContainers/lifestyleSession.h"


class htmlSideMenuLoggedin_o  {
  private:
    void          init();

  public:
    htmlSideMenuLoggedin_o();                                   // Default constructor.
    htmlSideMenuLoggedin_o(const htmlSideMenuLoggedin_o&);              // Copy constructor.
   ~htmlSideMenuLoggedin_o();                                   // Default destructor.
    htmlSideMenuLoggedin_o& operator = (const htmlSideMenuLoggedin_o&); // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
