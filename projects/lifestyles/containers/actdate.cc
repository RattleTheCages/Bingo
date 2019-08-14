/**  actdate.cc  ***************************************************************




changes log
when       who     what
12.11.99   Dan     Creation. 

*******************************************************************************/


#include "../../library/lib/parse/parse.h"
#include "../containers/actdate.h"


actdate_o::actdate_o()  {
    clear();
}

actdate_o::~actdate_o()  {}

void actdate_o::clear()  {
    Second = 0;
    Minute = 0;
    Hour   = 0;
    Day    = 0;
    Month  = 0;
    Year   = 0;
    Epoch  = 0;
    Action = "";
}

int actdate_o::blank() const  {
    if(Second == 0 &&
       Minute == 0 &&
       Hour   == 0 &&
       Day    == 0 &&
       Month  == 0 &&
       Year   == 0 &&
       Epoch  == 0)  return 1;
    return 0;
}

actdate_o& actdate_o::operator = (const actdate_o& a)  {
    Second  = a.Second;
    Minute  = a.Minute;
    Hour    = a.Hour;
    Day     = a.Day;
    Month   = a.Month;
    Year    = a.Year;
    Epoch   = a.Epoch;
    Action  = a.Action;
    return *this;
}

void actdate_o::time(string_o& s) const  {
    string_o t;

    t << Hour;
    if(t.length() < 2)  {
        t.reverse();
        t << '0';
        t.reverse();
    }
    s << t << ':';


    t = "";
    t << Minute;
    if(t.length() < 2)  {
        t.reverse();
        t << '0';
        t.reverse();
    }
    s << t << ':';


    t = "";
    t << Second;
    if(t.length() < 2)  {
        t.reverse();
        t << '0';
        t.reverse();
    }
    s << t;

}

void actdate_o::operator >> (string_o& s) const  {
    s << "\n" << ACTDATE_OBJECT;
    s << '\n' << ACTDATE_SECOND << '=' << Second;
    s << '\n' << ACTDATE_MINUTE << '=' << Minute;
    s << '\n' << ACTDATE_HOUR << '=' << Hour;
    s << '\n' << ACTDATE_DAY << '=' << Day;
    s << '\n' << ACTDATE_MONTH << '=' << Month;
    s << '\n' << ACTDATE_YEAR << '=' << Year;
    s << '\n' << ACTDATE_EPOCH << '=' << Epoch;
    s << '\n' << ACTDATE_ACTION << '=' << Action;
    s << '\n';
}

void actdate_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(ACTDATE_SECOND, Second);
    (void)parse.it(ACTDATE_MINUTE, Minute);
    (void)parse.it(ACTDATE_HOUR,   Hour);
    (void)parse.it(ACTDATE_DAY,    Day);
    (void)parse.it(ACTDATE_MONTH,  Month);
    (void)parse.it(ACTDATE_YEAR,   Year);
    (void)parse.it(ACTDATE_EPOCH,  Epoch);
    (void)parse.it(ACTDATE_ACTION, Action);
}

string_o& operator << (string_o& s,const actdate_o& a)  {
    a >> s;
    return s;
}


/******************************************************************************/
