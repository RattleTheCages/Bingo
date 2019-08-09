/**  pdaInput.h  ***************************************************************

    PDA Input Container Object.


changes log:
when       who     what
9.9.99     Dan     Creation. 

*******************************************************************************/


#ifndef PDAINPUTOBJECT_CONTAINER
#define PDAINPUTOBJECT_CONTAINER

#include "../../library/lib/string/string.h"
#include "../../library/sserver/containers/input.h"


#define PDAINPUT_PHONE  "pdaInput_o.phone"
#define PDAINPUT_INPUT  "pdaInput_o.input"

#define PDAINPUT_PHONE_MAX      160
#define PDAINPUT_COMMAND_MAX     20
#define PDAINPUT_NODEVALUE_MAX 8096


class pdaInput_o: public input_o  {
  protected:
    string_o Phone;
    string_o Command;
    string_o NodeValue;

  public:   
    pdaInput_o();                                   // Default constructor.
    pdaInput_o(const pdaInput_o&);                  // Copy constructor.
    pdaInput_o(const input_o&);
   ~pdaInput_o();                                   // Default destructor.
    pdaInput_o&     operator =  (const pdaInput_o&);// Assignment operator.
    void            operator >> (string_o&) const;  // Node-Value.
    void            operator << (const char*);      // Reconstruct.
    void            clear();

    int             blank()                 const;

    const char*     phone()                 const;
    const string_o&       command()               const;
    const char*     nodeValue()             const;

    void            setPhone(const char*);
    void            setCommand(const char*);
    void            setNodeValue(const char*);

};
string_o& operator << (string_o&,const pdaInput_o&);


/**  Inline methods need to be in the header file.  ***************************/

inline const char* pdaInput_o::phone() const  {
    return  Phone.string();
}

inline const string_o& pdaInput_o::command() const  {
    return Command;
}

inline const char* pdaInput_o::nodeValue() const  {
    return NodeValue.string();
}

inline void pdaInput_o::setPhone(const char* ph)  {
    Phone = ph;
    Phone.cut(PDAINPUT_PHONE_MAX);
}

inline void pdaInput_o::setCommand(const char* c)  {
    Command = c;
    Command.cut(PDAINPUT_COMMAND_MAX);
}

inline void pdaInput_o::setNodeValue(const char* nv)  {
    NodeValue = nv;
    NodeValue.cut(PDAINPUT_NODEVALUE_MAX);
}


#endif

/******************************************************************************/
