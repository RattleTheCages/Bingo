/**  bingocard.h  **************************************************************

    Bingo Card Container Object.


changes log:
when       who     what
9.19.99    Dan     Creation. 

*******************************************************************************/


#ifndef BINGOCARDOBJECT_CONTAINER
#define BINGOCARDOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define BINGOCARD_ID     "bingocard_o.id"
#define BINGOCARD_B_NNN  "bingocard_o.B_NNN"
#define BINGOCARD_I_NNN  "bingocard_o.I_NNN"
#define BINGOCARD_N_NNN  "bingocard_o.N_NNN"
#define BINGOCARD_G_NNN  "bingocard_o.G_NNN"
#define BINGOCARD_O_NNN  "bingocard_o.O_NNN"
#define BINGOCARD_BX_NNN "bingocard_o.BX_NNN"
#define BINGOCARD_IX_NNN "bingocard_o.IX_NNN"
#define BINGOCARD_NX_NNN "bingocard_o.NX_NNN"
#define BINGOCARD_GX_NNN "bingocard_o.GX_NNN"
#define BINGOCARD_OX_NNN "bingocard_o.OX_NNN"


class bingocard_o  {
  friend class bingocardserver_o;
  friend class bingodealer_o;
  friend class hdmlViewCards_o;
  friend class hdmlGame_o;
  protected:
    string_o Id;
    short    B[5];
    short    I[5];
    short    N[5];
    short    G[5];
    short    O[5];

    short    Bx[5];
    short    Ix[5];
    short    Nx[5];
    short    Gx[5];
    short    Ox[5];

  public:   
    bingocard_o();                                      // Default constructor.
    bingocard_o(const bingocard_o&);                    // Copy constructor.
   ~bingocard_o();                                      // Default destructor.
    bingocard_o&      operator =  (const bingocard_o&); // Assignment operator.
    void              operator >> (string_o&) const;    // Node-Value.
    void              operator << (const char*);        // Reconstruct.
    void              clear();
    int               blank()               const;

    const char*       id()                  const;

    const char*       setId(const char*);
};
string_o& operator << (string_o&,const bingocard_o&);


/******************************************************************************/

inline const char* bingocard_o::id() const  {
    return  Id.string();
}

inline const char* bingocard_o::setId(const char* id)  {
    Id = id;
    return Id.string();
}

inline int bingocard_o::blank() const  {
    if(B[0] == 0)  return 1;
    return 0;
}




#endif

/*****************************************************************************/
