/**  htmlMenu.h  ***************************************************************


    HTML Menu Object.


changes log
when       who      what
3.23.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLMENUOBJECT_API
#define HTMLMENUOBJECT_API

#include "../../library/lib/string/string.h"

#include "../containers/bingogame.h"


class htmlMenu_o  {
  private:
    void          init();

  public:
    htmlMenu_o();                                    // Default constructor.
    htmlMenu_o(const htmlMenu_o&);                    // Copy constructor.
   ~htmlMenu_o();                                    // Default destructor.
    htmlMenu_o& operator = (const htmlMenu_o&);       // Asignment operator.

    void page(const bingogame_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
