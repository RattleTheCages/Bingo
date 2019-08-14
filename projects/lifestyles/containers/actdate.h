/**  actdate.h  ****************************************************************

    Action Date Container Object.


changes log
when       who     what
12.11.99   Dan     Creation. 

*******************************************************************************/


#ifndef ACTIONDATEOBJECT_CONTAINER
#define ACTIONDATEOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define ACTDATE_OBJECT  "actdate_o:"
#define ACTDATE_SECOND  "actdate_o.second"
#define ACTDATE_MINUTE  "actdate_o.minute"
#define ACTDATE_HOUR    "actdate_o.hour"
#define ACTDATE_DAY     "actdate_o.day"
#define ACTDATE_MONTH   "actdate_o.month"
#define ACTDATE_YEAR    "actdate_o.year"
#define ACTDATE_EPOCH   "actdate_o.epoch"
#define ACTDATE_ACTION  "actdate_o.action"


class actdate_o  {
  private:

  protected:
    short int   Second;
    short int   Minute;
    short int   Hour;
    short int   Day;
    short int   Month;
    short int   Year;
    long  int   Epoch;
    string_o    Action;

  public:   
    actdate_o();                                        // Default constructor.
    actdate_o(const actdate_o&);                        // Copy constructor.
   ~actdate_o();                                        // Default destructor.
    actdate_o&      operator =  (const actdate_o&);     // Assignment operator.
    void            operator >> (string_o&) const;      // OLP representation.
    void            operator << (const char*);          // Reconstruct.
    void            clear();

    int             blank()                     const;

    int             second()                    const;
    int             minute()                    const;
    int             hour()                      const;
    int             day()                       const;
    int             month()                     const;
    int             year()                      const;
    long int        epoch()                     const;
    const char*     action()                    const;

    void  time(string_o& s) const;

    void            setSecond(int);
    void            setMinute(int);
    void            setHour(int);
    void            setDay(int);
    void            setMonth(int);
    void            setYear(int);
    void            setEpoch(long int);
    void            setAction(const char*);

};


/******************************************************************************/

inline int actdate_o::second() const  {
    return (int)Second;
}

inline int actdate_o::minute() const  {
    return (int)Minute;
}

inline int actdate_o::hour() const  {
    return (int)Hour;
}

inline int actdate_o::day() const  {
    return (int)Day;
}

inline int actdate_o::month() const  {
    return (int)Month;
}

inline int actdate_o::year() const  {
    return (int)Year;
}

inline long int actdate_o::epoch() const  {
    return Epoch;
}


#endif

/******************************************************************************/
