/**  htmlTelluric.h  ***********************************************************

    HTML Telluric Object.


changes log
when       who      what
3.20.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLTELLURICOBJECT_API
#define HTMLTELLURICOBJECT_API


#include "../../library/lib/string/string.h"

#include "../../library/sserver/containers/input.h"
//!!!

#include "../html/htmlDisplayServerManifestContainer.h"
#include "../html/htmlDisplayServerManifest.h"
#include "../html/htmlServerManifestPage.h"


class htmlTelluric_o  {
  private:
    string_o      TransactionServerURL;
    string_o      StaticServerURL;

    string_o      FontText;
    string_o      FontData;
    string_o      FontEmph;
    string_o      FontFix;
    string_o      FontSmall;
    string_o      FontExSmall;
    string_o      FontGreen;
    string_o      FontRed;


  protected:
    void          init();


  public:
    htmlTelluric_o();                                   // Default constructor.
    htmlTelluric_o(const htmlTelluric_o&);              // Copy constructor.
   ~htmlTelluric_o();                                   // Default destructor.
    htmlTelluric_o& operator = (const htmlTelluric_o&); // Assignment operator.



    int parse(input_o*);

    void unnet(string_o&);
    void ennet(string_o&);



    const char* transactionServerURL() const;
    const char* staticServerURL() const;
    const char* fontText() const;
    const char* fontData() const;
    const char* fontEmph() const;
    const char* fontFix() const;
    const char* fontSmall() const;
    const char* fontExSmall() const;
    const char* fontGreen() const;
    const char* fontRed() const;

    int setTransactionServerURL(const char*);
    int setStaticServerURL(const char*);


    htmlDisplayServerManifestContainer_o htmlDisplayServerManifestContainer;
    htmlDisplayServerManifest_o htmlDisplayServerManifest;
    htmlServerManifestPage_o htmlServerManifestPage;
};


/******************************************************************************/


inline const char* htmlTelluric_o::transactionServerURL() const  {
    return TransactionServerURL.string();
}

inline const char* htmlTelluric_o::staticServerURL() const  {
    return StaticServerURL.string();
}

inline const char* htmlTelluric_o::fontText() const  {
    return FontText.string();
}

inline const char* htmlTelluric_o::fontData() const  {
    return FontData.string();
}

inline const char* htmlTelluric_o::fontEmph() const  {
    return FontEmph.string();
}

inline const char* htmlTelluric_o::fontFix() const  {
    return FontFix.string();
}

inline const char* htmlTelluric_o::fontSmall() const  {
    return FontSmall.string();
}

inline const char* htmlTelluric_o::fontExSmall() const  {
    return FontExSmall.string();
}

inline const char* htmlTelluric_o::fontGreen() const  {
    return FontGreen.string();
}

inline const char* htmlTelluric_o::fontRed() const  {
    return FontRed.string();
}


#endif

/******************************************************************************/
