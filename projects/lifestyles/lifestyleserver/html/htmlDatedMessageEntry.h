/**  htmlDatedMessageEntry.h  **************************************************


    HTML Dated Message Entry Object.


changes log
when       who      what
11.24.99   Dan      Creation.

*******************************************************************************/

#ifndef HTMLDATEDMESSAGEENTRYOBJECT_API
#define HTMLDATEDMESSAGEENTRYOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../containers/datedMessage.h"


class htmlDatedMessageEntry_o  {
  private:
    void          init();

  public:
    htmlDatedMessageEntry_o();                                    // Default constructor.
    htmlDatedMessageEntry_o(const htmlDatedMessageEntry_o&);                    // Copy constructor.
   ~htmlDatedMessageEntry_o();                                    // Default destructor.
    htmlDatedMessageEntry_o& operator = (const htmlDatedMessageEntry_o&);       // Asignment operator.

    void page(const datedMessage_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
