/**  lifestyleItem.h  **********************************************************

    Service Container Object.


changes log
when       who     what
10.22.99   Dan     Creation. 

*******************************************************************************/


#ifndef LIFESTYLEITEMOBJECT_CONTAINER
#define LIFESTYLEITEMOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define LIFESTYLEITEM_OBJECT    "lifestyleItem_o:"
#define LIFESTYLEITEM_TYPE    "lifestyleItem_o.type"
#define LIFESTYLEITEM_NAME    "lifestyleItem_o.name"
#define LIFESTYLEITEM_DESCRIPTION   "lifestyleItem_o.desc"

#define LIFESTYLEITEM_TYPE_MAX     12
#define LIFESTYLEITEM_NAME_MAX     60
#define LIFESTYLEITEM_DESCRIPTION_MAX  160


class lifestyleItem_o  {
  protected:
public://!!
    string_o Type;
    string_o Name;
    string_o Description;

  public:   
    lifestyleItem_o();                                    // Default constructor.
    lifestyleItem_o(const lifestyleItem_o&);                    // Copy constructor.
   ~lifestyleItem_o();                                    // Default destructor.
    lifestyleItem_o&      operator =  (const lifestyleItem_o&); // Assignment operator.
    void            operator >> (string_o&) const;  // Node-Value.
    void            operator << (const char*);      // Reconstruct.
    void            clear();

    int             blank()                 const;
    int             operator == (const lifestyleItem_o&) const;

    const char*     type()                  const;
    const char*     name()                  const;
    const char*     description()           const;

    void            setType(const char*);
    void            setName(const char*);
    void            setDescription(const char*);

};
string_o& operator << (string_o&,const lifestyleItem_o&);


/**  Inline methods need to be in the header file.  ***************************/

inline const char* lifestyleItem_o::type() const  {
    return  Type.string();
}

inline const char* lifestyleItem_o::name() const  {
    return  Name.string();
}

inline const char* lifestyleItem_o::description() const  {
    return  Description.string();
}

inline void lifestyleItem_o::setType(const char* ty)  {
    Type = ty;
    Type.cut(LIFESTYLEITEM_TYPE_MAX);
}

inline void lifestyleItem_o::setName(const char* na)  {
    Name = na;
    Name.cut(LIFESTYLEITEM_NAME_MAX);
}

inline void lifestyleItem_o::setDescription(const char* na)  {
    Description = na;
    Description.cut(LIFESTYLEITEM_DESCRIPTION_MAX);
}



#endif

/*****************************************************************************/
