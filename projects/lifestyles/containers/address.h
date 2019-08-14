/**  address.h  ****************************************************************

    Address Container Object.


changes log
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/


#ifndef ADDRESSOBJECT_CONTAINER
#define ADDRESSOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define ADDRESS_OBJECT  "address_o:"
#define ADDRESS_TYPE    "address_o.type"
#define ADDRESS_NAME    "address_o.name"
#define ADDRESS_STREET  "address_o.street"
#define ADDRESS_CITY    "address_o.city"
#define ADDRESS_STATE   "address_o.state"
#define ADDRESS_ZIP     "address_o.zip"
#define ADDRESS_COUNTRY "address_o.country"

#define ADDRESS_TYPE_MAX     12
#define ADDRESS_NAME_MAX     64
#define ADDRESS_STREET_MAX  160
#define ADDRESS_CITY_MAX     64
#define ADDRESS_STATE_MAX    42
#define ADDRESS_ZIP_MAX      14
#define ADDRESS_COUNTRY_MAX  14


class address_o  {
  protected:
    string_o Type;
    string_o Name;
    string_o Street;
    string_o City;
    string_o State;
    string_o Zip;
    string_o Country;

  public:   
    address_o();                                        // Default constructor.
    address_o(const address_o&);                        // Copy constructor.
   ~address_o();                                        // Default destructor.
    address_o&      operator =  (const address_o&);     // Assignment operator.
    void            operator >> (string_o&) const;      // OLP representation.
    void            operator << (const char*);          // Reconstruct.
    void            clear();

    int             blank()                     const;

    const char*     type()                      const;
    const char*     name()                      const;
    const char*     street()                    const;
    const char*     city()                      const;
    const char*     state()                     const;
    const char*     zip()                       const;
    const char*     country()                   const;

    void            setType(const char*);
    void            setName(const char*);
    void            setStreet(const char*);
    void            setCity(const char*);
    void            setState(const char*);
    void            setZip(const char*);
    void            setCountry(const char*);

};
string_o& operator << (string_o&,const address_o&);


/******************************************************************************/

inline const char* address_o::type() const  {
    return Type.string();
}

inline const char* address_o::name() const  {
    return Name.string();
}

inline const char* address_o::street() const  {
    return Street.string();
}

inline const char* address_o::city() const  {
    return City.string();
}

inline const char* address_o::state() const  {
    return State.string();
}

inline const char* address_o::zip() const  {
    return Zip.string();
}

inline const char* address_o::country() const  {
    return Country.string();
}


inline void address_o::setType(const char* ty)  {
    Type = ty;
    Type.cut(ADDRESS_TYPE_MAX);
}

inline void address_o::setName(const char* na)  {
    Name = na;
    Name.cut(ADDRESS_NAME_MAX);
}

inline void address_o::setStreet(const char* st)  {
    Street = st;
    Street.cut(ADDRESS_STREET_MAX);
}

inline void address_o::setCity(const char* ct)  {
    City = ct;
    City.cut(ADDRESS_CITY_MAX);
}

inline void address_o::setState(const char* st)  {
    State = st;
    State.cut(ADDRESS_STATE_MAX);
}

inline void address_o::setZip(const char* z)  {
    Zip = z;
    Zip.cut(ADDRESS_ZIP_MAX);
}

inline void address_o::setCountry(const char* cu)  {
    Country = cu;
    Country.cut(ADDRESS_COUNTRY_MAX);
}


#endif

/******************************************************************************/
