/**  htmlDisplayServerManifest.h  *************************************************


    HTML Display Server Manifest Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLDISPLAYSERVERMANIFESTOBJECT_API
#define HTMLDISPLAYSERVERMANIFESTOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/serverManifest.h"


class htmlDisplayServerManifest_o  {
  private:
    void          init();

  public:
    htmlDisplayServerManifest_o();                         // Default constructor.
    htmlDisplayServerManifest_o(const htmlDisplayServerManifest_o&);
                                                        // Copy constructor.
   ~htmlDisplayServerManifest_o();                         // Default destructor.
    htmlDisplayServerManifest_o& operator = (const htmlDisplayServerManifest_o&);
                                                        // Assignment operator.

    void page(const serverManifest_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
