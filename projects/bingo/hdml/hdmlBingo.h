/**  hdmlBingo.h  ***********************************************************


    HDML New Cards Object.


changes log
when       who      what
9.19.99    Dan      Creation.


*******************************************************************************/

#ifndef HDMLBINGOOBJECT_API
#define HDMLBINGOOBJECT_API

#include "../../library/lib/string/string.h"
#include "../containers/bingoSession.h"

class hdmlBingo_o  {
  private:
    void            init();

  public:
    hdmlBingo_o();                                   // Default constructor.
    hdmlBingo_o(const hdmlBingo_o&);              // Copy constructor.
   ~hdmlBingo_o();                                   // Default destructor.
    hdmlBingo_o& operator = (const hdmlBingo_o&); // Assignment operator.

    void page(const bingoSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
