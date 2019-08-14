/**  weather.h  ****************************************************************

    Weather Container Object.


changes log:
when       who     what
9.9.99     Dan     Creation. 
10.6.99    Dan     Added:    Data member forc for forcast.

*******************************************************************************/


#ifndef WEATHEROBJECT_CONTAINER
#define WEATHEROBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define WEATHER_TEMP    "weather_o.temp"
#define WEATHER_HUMD    "weather_o.humd"
#define WEATHER_COND    "weather_o.cond"
#define WEATHER_FORC    "weather_o.forc"

#define WEATHER_TEMP_MAX      6
#define WEATHER_HUMD_MAX      6
#define WEATHER_COND_MAX     16
#define WEATHER_FORC_MAX    512


class weather_o  {
  protected:
    string_o Temp;
    string_o Humd;
    string_o Cond;
    string_o Forc;

  public:   
    weather_o();                                    // Default constructor.
    weather_o(const weather_o&);                    // Copy constructor.
   ~weather_o();                                    // Default destructor.
    weather_o&      operator =  (const weather_o&); // Assignment operator.
    void            operator >> (string_o&) const;  // Node-Value.
    void            operator << (const char*);      // Reconstruct.
    void            clear();

    int             blank()                 const;

    const char*     temp()                  const;
    const char*     humd()                  const;
    const char*     cond()                  const;
    const char*     forc()                  const;

    void            setTemp(const char*);
    void            setHumd(const char*);
    void            setCond(const char*);
    void            setForc(const char*);

};
string_o& operator << (string_o&,const weather_o&);


/**  Inline methods need to be in the header file.  ***************************/

inline const char* weather_o::temp() const  {
    return  Temp.string();
}

inline const char* weather_o::humd() const  {
    return  Humd.string();
}

inline const char* weather_o::cond() const  {
    return  Cond.string();
}

inline const char* weather_o::forc() const  {
    return  Forc.string();
}


inline void weather_o::setTemp(const char* t)  {
    Temp = t;
    Temp.cut(WEATHER_TEMP_MAX);
}

inline void weather_o::setHumd(const char* hu)  {
    Humd = hu;
    Humd.cut(WEATHER_TEMP_MAX);
}

inline void weather_o::setCond(const char* cd)  {
    Cond = cd;
    Cond.cut(WEATHER_COND_MAX);
}

inline void weather_o::setForc(const char* fo)  {
    Forc = fo;
    Forc.cut(WEATHER_FORC_MAX);
}


#endif

/******************************************************************************/
