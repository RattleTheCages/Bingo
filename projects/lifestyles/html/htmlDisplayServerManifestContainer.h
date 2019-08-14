/**  htmlDisplayServerManifestContainer.h  *************************************


    HTML Display Server Manifest Container Object.

    This object creates an html display of a serverManifest_o container object.


changes log
when       who      what
10.28.99   Dan      Creation.

*******************************************************************************/

#ifndef HTMLDISPLAYSERVERMANIFESTCONTAINEROBJECT_API
#define HTMLDISPLAYSERVERMANIFESTCONTAINEROBJECT_API


#include "../../library/lib/string/string.h"
#include "../containers/serverManifest.h"


class htmlDisplayServerManifestContainer_o  {
  private:
    void          init();

  public:
    htmlDisplayServerManifestContainer_o();             // Default constructor.
    htmlDisplayServerManifestContainer_o(const htmlDisplayServerManifestContainer_o&);                                                 // Copy constructor.
   ~htmlDisplayServerManifestContainer_o();            // Default destructor.
    htmlDisplayServerManifestContainer_o& operator = (const htmlDisplayServerManifestContainer_o&);                                    // Assignment operator.

    void page(const serverManifest_o&,string_o&);
};


/******************************************************************************/


#endif

/******************************************************************************/
