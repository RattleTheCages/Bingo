/**  lifestyleItem.cc  *********************************************************



changes log:
when       who     what
10.22.99    Dan     Creation. 

*******************************************************************************/


#include "../containers/lifestyleItem.h"
#include "../../library/lib/parse/parse.h"

lifestyleItem_o::lifestyleItem_o()  {}

lifestyleItem_o::~lifestyleItem_o()  {}

void lifestyleItem_o::clear()  {
    Type = "";
    Name = "";
    Description = "";
}


lifestyleItem_o& lifestyleItem_o::operator = (const lifestyleItem_o& a)  {
    Name    = a.Name;
    Type    = a.Type;
    Description    = a.Description;

    return *this;
}

int lifestyleItem_o::operator == (const lifestyleItem_o& li)  const  {
    if(Type == li.Type  &&  Name == li.Name)  return 1;
    return 0;
}

void lifestyleItem_o::operator >> (string_o& s) const  {
    s << "\nlifestyleItem_o:";
    s << '\n' << LIFESTYLEITEM_TYPE << '=' << Type;
    s << '\n' << LIFESTYLEITEM_NAME << '=' << Name;
    s << '\n' << LIFESTYLEITEM_DESCRIPTION << '=' << Description;
    s << '\n';
}

void lifestyleItem_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(LIFESTYLEITEM_TYPE,   Type);
    (void)parse.it(LIFESTYLEITEM_NAME,   Name);
    (void)parse.it(LIFESTYLEITEM_DESCRIPTION,   Description);
}

string_o& operator << (string_o& s,const lifestyleItem_o& a)  {
    a >> s;
    return s;
}


/******************************************************************************/
