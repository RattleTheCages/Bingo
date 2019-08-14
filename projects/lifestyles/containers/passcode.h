/**  passcode.h  ***************************************************************

    PassCode Container Object.


changes log
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/


#ifndef PASSCODEOBJECT_CONTAINER
#define PASSCODEOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define PASSCODE_OBJECT   "passcode_o:"
#define PASSCODE_USERID   "passcode_o.userid"
#define PASSCODE_PASSWORD "passcode_o.password"
#define PASSCODE_VALID    "passcode_o.valid"


#define PASSCODE_USERID_MAX   12
#define PASSCODE_PASSWORD_MAX 12


class passcode_o  {
  protected:
    string_o    Userid;
    string_o    Password;
    int         Valid;

  public:   
    passcode_o();                                       // Default constructor.
    passcode_o(const passcode_o&);                      // Copy constructor.
   ~passcode_o();                                       // Default destructor.
    passcode_o&     operator =  (const passcode_o&);    // Assignment operator.
    void            operator >> (string_o&) const;      // OLP representation.
    void            operator << (const char*);          // Reconstruct.
    void            clear();

    int             operator == (const passcode_o&) const;
    int             blank()                         const;

    const char*     userid()                        const;
    const char*     password()                      const;
          int       valid()                         const;

    void            setUserid(const char*);
    void            setPassword(const char*);
    void            setValid(int);

};


/******************************************************************************/

inline const char* passcode_o::userid() const  {
    return Userid.string();
}

inline const char* passcode_o::password() const  {
    return Password.string();
}

inline int passcode_o::valid() const  {
    return Valid;
}


inline void passcode_o::setUserid(const char* ui)  {
    Userid = ui;
    Userid.cut(PASSCODE_USERID_MAX);
}

inline void passcode_o::setPassword(const char* pw)  {
    Password = pw;
    Password.cut(PASSCODE_PASSWORD_MAX);
}

inline void passcode_o::setValid(int v)  {
    Valid = v;
}


#endif

/******************************************************************************/
