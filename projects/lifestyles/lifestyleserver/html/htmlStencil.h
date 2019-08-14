/**  htmlStencil.h  ************************************************************


    HTML Stencil Object.


changes log
when       who      what
12.4.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLSTENCILOBJECT_API
#define HTMLSTENCILOBJECT_API


#include "../../../library/lib/string/string.h"

#include "../../dynamicContainers/lifestyleSession.h"


class htmlStencil_o  {
  private:
    void          init();

  public:
    htmlStencil_o();                                    // Default constructor.
    htmlStencil_o(const htmlStencil_o&);                // Copy constructor.
   ~htmlStencil_o();                                    // Default destructor.
    htmlStencil_o& operator = (const htmlStencil_o&);   // Assignment operator.

    void pageIn(const lifestyleSession_o&,const char*,string_o&);
    void pageIn(const char*,string_o&);
    void pageOut(string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
