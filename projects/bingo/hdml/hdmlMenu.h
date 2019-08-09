/**  hdmlMenu.h  ***************************************************************


    HDML Main Menu Object.


changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/

#ifndef HDMLMAINMENUOBJECT_API
#define HDMLMAINMENUOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlMenu_o  {
  private:
    void            init();

  public:
    hdmlMenu_o();                                   // Default constructor.
    hdmlMenu_o(const hdmlMenu_o&);                  // Copy constructor.
   ~hdmlMenu_o();                                   // Default destructor.
    hdmlMenu_o& operator = (const hdmlMenu_o&);     // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
