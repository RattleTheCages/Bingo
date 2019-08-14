/**  htmlSendMessage.h  ********************************************************


    HTML Send Message Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLSENDMESSAGEOBJECT_API
#define HTMLSENDMESSAGEOBJECT_API

#include "../../../library/lib/string/string.h"

#include "../../dynamicContainers/lifestyleSession.h"



class htmlSendMessage_o  {
  private:
    void          init();

  public:
    htmlSendMessage_o();                                    // Default constructor.
    htmlSendMessage_o(const htmlSendMessage_o&);                    // Copy constructor.
   ~htmlSendMessage_o();                                    // Default destructor.
    htmlSendMessage_o& operator = (const htmlSendMessage_o&);       // Asignment operator.

    void page(const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
