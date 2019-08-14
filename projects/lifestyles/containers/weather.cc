/**  weather.cc  ***************************************************************



changes log
when       who     what
9.9.99     Dan     Creation. 
10.6.99    Dan     Added:    Data member forc for forcast.


*******************************************************************************/


#include "../containers/weather.h"
#include "../../library/lib/parse/parse.h"

weather_o::weather_o()  {}

weather_o::~weather_o()  {}

void weather_o::clear()  {
    Temp = "";
    Humd = "";
    Cond = "";
    Forc = "";
}

int weather_o::blank() const  {
    if( Temp.length()  < 1  &&
        Humd.length() < 1  )  return 1;
    return 0;
}

weather_o& weather_o::operator = (const weather_o& w)  {
    Temp    = w.Temp;
    Humd    = w.Humd;
    Cond    = w.Cond;
    Forc    = w.Forc;
    return *this;
}

void weather_o::operator >> (string_o& s) const  {
    s << "\nweather_o:";
    s << '\n' << WEATHER_TEMP << '=' << Temp;
    s << '\n' << WEATHER_HUMD << '=' << Humd;
    s << '\n' << WEATHER_COND << '=' << Cond;
    s << '\n' << WEATHER_FORC << '=' << Forc;
    s << '\n';
}

void weather_o::operator << (const char* cc)  {
    parse_o parse(cc);
    (void)parse.it(WEATHER_TEMP,   Temp);
    (void)parse.it(WEATHER_HUMD,   Humd);
    (void)parse.it(WEATHER_COND,   Cond);
    (void)parse.it(WEATHER_FORC,   Forc);
}

string_o& operator << (string_o& s,const weather_o& w)  {
    w >> s;
    return s;
}


/******************************************************************************/
