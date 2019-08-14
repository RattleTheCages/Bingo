/**  htmlExamineService.h  *****************************************************


    HTML Examine Service Object.


changes log
when       who      what
11.11.99   Dan      Creation.

*******************************************************************************/

#ifndef HTMLEXAMINESERVICEOBJECT_API
#define HTMLEXAMINESERVICEOBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../dynamicContainers/lifestyleSession.h"



class htmlExamineService_o  {
  private:
    void          init();

  public:
    htmlExamineService_o();                                    // Default constructor.
    htmlExamineService_o(const htmlExamineService_o&);                    // Copy constructor.
   ~htmlExamineService_o();                                    // Default destructor.
    htmlExamineService_o& operator = (const htmlExamineService_o&);       // Asignment operator.

    void page(int,const lifestyleSession_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
