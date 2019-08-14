/**  htmlNewSettings.h  ********************************************************


    HTML Change Settings Object.


changes log
when       who      what
10.7.99    Dan      Creation.
11.25.99   Dan      Changed:  Only display one lifestyle item at a time.
12.23.99   Dan      Removed:  Server Manifest Display.

*******************************************************************************/


#ifndef HTMLNEWSETTINGSOBJECT_API
#define HTMLNEWSETTINGSOBJECT_API


#include "../../../library/lib/string/string.h"

#include "../../containers/lifestyleItem.h"
#include "../../dynamicContainers/lifestyleSession.h"


class htmlNewSettings_o  {
  private:
    void          init();

  public:
    htmlNewSettings_o();                                // Default constructor.
    htmlNewSettings_o(const htmlNewSettings_o&);        // Copy constructor.
   ~htmlNewSettings_o();                                // Default destructor.
    htmlNewSettings_o& operator = (const htmlNewSettings_o&);
                                                        // Assignment operator.

    void page(const lifestyleItem_o&,const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
