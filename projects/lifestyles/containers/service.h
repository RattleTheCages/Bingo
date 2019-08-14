/**  service.h  ***************************************************************

    Service Container Object.


changes log:
when       who     what
10.7.99    Dan     Creation. 
10.22.99   Dan     Added:    Data member class.

*******************************************************************************/


#ifndef SERVICEOBJECT_CONTAINER
#define SERVICEOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define SERVICE_LIFESTYLE       "service_o.life"
#define SERVICE_TYPE            "service_o.type"
#define SERVICE_CLASS           "service_o.class"
#define SERVICE_NAME            "service_o.name"
#define SERVICE_URL             "service_o.url"
#define SERVICE_DESCRIPTION     "service_o.desc"

#define SERVICE_LIFESTYLE_MAX    60
#define SERVICE_TYPE_MAX         12
#define SERVICE_CLASS_MAX        32
#define SERVICE_NAME_MAX         60
#define SERVICE_URL_MAX         512
#define SERVICE_DESCRIPTION_MAX 160


class service_o  {
  protected:
    string_o Lifestyle;
    string_o Type;
    string_o Class;
    string_o Name;
    string_o Url;
    string_o Description;

  public:   
    service_o();                                    // Default constructor.
    service_o(const service_o&);                    // Copy constructor.
   ~service_o();                                    // Default destructor.
    service_o&      operator =  (const service_o&); // Assignment operator.
    void            operator >> (string_o&) const;  // Node-Value.
    void            operator << (const char*);      // Reconstruct.
    void            clear();

    int             blank()                 const;

    const char*     type()                  const;
    const char*     lifestyle()             const;
    const char*     class_()                const;
    const char*     name()                  const;
    const char*     url()                   const;
    const char*     description()           const;

    void            setType(const char*);
    void            setLifestyle(const char*);
    void            setClass(const char*);
    void            setName(const char*);
    void            setUrl(const char*);
    void            setDescription(const char*);

};
string_o& operator << (string_o&,const service_o&);


/**  Inline methods need to be in the header file.  ***************************/

inline const char* service_o::type() const  {
    return  Type.string();
}

inline const char* service_o::lifestyle() const  {
    return  Lifestyle.string();
}

inline const char* service_o::class_() const  {
    return  Class.string();
}

inline const char* service_o::name() const  {
    return  Name.string();
}

inline const char* service_o::url() const  {
    return  Url.string();
}

inline const char* service_o::description() const  {
    return  Description.string();
}



inline void service_o::setType(const char* ty)  {
    Type = ty;
    Type.cut(SERVICE_TYPE_MAX);
}

inline void service_o::setLifestyle(const char* ct)  {
    Lifestyle = ct;
    Lifestyle.cut(SERVICE_LIFESTYLE_MAX);
}

inline void service_o::setClass(const char* st)  {
    Class = st;
    Class.cut(SERVICE_CLASS_MAX);
}

inline void service_o::setName(const char* na)  {
    Name = na;
    Name.cut(SERVICE_NAME_MAX);
}

inline void service_o::setUrl(const char* st)  {
    Url = st;
    Url.cut(SERVICE_URL_MAX);
}

inline void service_o::setDescription(const char* st)  {
    Description = st;
    Description.cut(SERVICE_DESCRIPTION_MAX);
}


#endif

/*****************************************************************************/
