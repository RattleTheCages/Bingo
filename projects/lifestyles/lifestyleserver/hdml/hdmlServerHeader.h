/**  hdmlServerHeader.h  ******************************************************


    HDML Server Header Object.


changes log
when       who      what
10.22.99   Dan      Creation.


*******************************************************************************/

#ifndef HDMLSERVERHEADEROBJECT_API
#define HDMLSERVERHEADEROBJECT_API

#include "../../../library/lib/string/string.h"

class hdmlServerHeader_o  {
  private:
    void            init();

  public:
    hdmlServerHeader_o();                               // Default constructor.
    hdmlServerHeader_o(const hdmlServerHeader_o&);      // Copy constructor.
   ~hdmlServerHeader_o();                               // Default destructor.
    hdmlServerHeader_o& operator = (const hdmlServerHeader_o&);
                                                        // Assignment operator.

    void page(string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
