/**  hdmlNewUser.h  ************************************************************


    HDML New User Object.


changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/

#ifndef HDMLNEWUSEROBJECT_API
#define HDMLNEWUSEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"

class hdmlNewUser_o  {
  private:
    void            init();

  public:
    hdmlNewUser_o();                                   // Default constructor.
    hdmlNewUser_o(const hdmlNewUser_o&);                  // Copy constructor.
   ~hdmlNewUser_o();                                   // Default destructor.
    hdmlNewUser_o& operator = (const hdmlNewUser_o&);     // Assignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
