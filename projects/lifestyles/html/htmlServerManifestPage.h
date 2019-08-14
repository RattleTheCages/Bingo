/**  htmlServerManifestPage.h  *************************************************


    HTML Server Manifest Page Object.


changes log
when       who      what
12.4.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLSERVERMANIFESTPAGEOBJECT_API
#define HTMLSERVERMANIFESTPAGEOBJECT_API

#include "../../library/lib/string/string.h"


class htmlServerManifestPage_o  {
  private:
    void          init();

  public:
    htmlServerManifestPage_o();                         // Default constructor.
    htmlServerManifestPage_o(const htmlServerManifestPage_o&);
                                                        // Copy constructor.
   ~htmlServerManifestPage_o();                         // Default destructor.
    htmlServerManifestPage_o& operator = (const htmlServerManifestPage_o&);
                                                        // Assignment operator.

    void page(const serverManifest_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
