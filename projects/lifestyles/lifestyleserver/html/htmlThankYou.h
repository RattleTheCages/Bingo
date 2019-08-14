/**  htmlThankYou.h  ***********************************************************


    HTML Thank You Object.


changes log
when       who      what
10.7.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLTHANKYOUOBJECT_API
#define HTMLTHANKYOUOBJECT_API


#include "../../../library/lib/string/string.h"



class htmlThankYou_o  {
  private:
    void          init();

  public:
    htmlThankYou_o();                                   // Default constructor.
    htmlThankYou_o(const htmlThankYou_o&);              // Copy constructor.
   ~htmlThankYou_o();                                   // Default destructor.
    htmlThankYou_o& operator = (const htmlThankYou_o&); // Assignment operator.

    void page(string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
