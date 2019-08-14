/**  htmlLogin.h  ************************************************************


    HTML login Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLLOGINOBJECT_API
#define HTMLLOGINOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../containers/passcode.h"


class htmlLogin_o  {
  private:
    void          init();

  public:
    htmlLogin_o();                                    // Default constructor.
    htmlLogin_o(const htmlLogin_o&);                    // Copy constructor.
   ~htmlLogin_o();                                    // Default destructor.
    htmlLogin_o& operator = (const htmlLogin_o&);       // Asignment operator.

    void page(passcode_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
