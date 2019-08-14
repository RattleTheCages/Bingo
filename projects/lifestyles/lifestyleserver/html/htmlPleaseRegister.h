/**  htmlPleaseRegister.h  *****************************************************


    HTML Please Register Object.


changes log
when       who      what
12.12.99   Dan      Creation.

*******************************************************************************/

#ifndef HTMLPLEASEREGISTEROBJECT_API
#define HTMLPLEASEREGISTEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../containers/serverManifest.h"
#include "../../containers/passcode.h"


class htmlPleaseRegister_o  {
  private:
    void          init();

  public:
    htmlPleaseRegister_o();                             // Default constructor.
    htmlPleaseRegister_o(const htmlPleaseRegister_o&);  // Copy constructor.
   ~htmlPleaseRegister_o();                             // Default destructor.
    htmlPleaseRegister_o& operator = (const htmlPleaseRegister_o&);
                                                        // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
