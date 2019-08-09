/**  htmlInterface.h  **********************************************************

    HTML Interface Object.


changes log
when       who      what
3.20.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLINTERFACEOBJECT_API
#define HTMLINTERFACEOBJECT_API

#include "../html/htmlMenu.h"

#include "../../library/sserver/containers/input.h"
#include "../../library/lib/string/string.h"


class htmlInterface_o  {
  private:
    htmlInterface_o* wi;

  public:
    string_o      transactionServerPath;
    string_o      staticServerPath;

    string_o      colorText;
    string_o      colorHighlight;

    string_o      fontText;
    string_o      fontInput;
    string_o      fontEmph;
    string_o      fontC;
    string_o      fontSmall;
    string_o      fontSt;
    string_o      fontId;

    void          init();


  public:
    htmlInterface_o();
    htmlInterface_o(const htmlInterface_o&);
   ~htmlInterface_o();
    htmlInterface_o& operator = (const htmlInterface_o&);

    htmlMenu_o     htmlMenu;

    int parse(input_o*);

    void unnet(string_o&);
};


/******************************************************************************/


#endif

/******************************************************************************/
