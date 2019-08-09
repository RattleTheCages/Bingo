/**  bingoball.h  **************************************************************

    Bingo Ball Container Object.


changes log:
when       who     what
9.19.99    Dan     Creation. 

*******************************************************************************/


#ifndef BINGOBALLOBJECT_CONTAINER
#define BINGOBALLOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define BINGOBALL_ID    "bingoball_o.id"
#define BINGOBALL_VALUE "bingoball_o.value"
#define BINGOBALL_ORDER "bingoball_o.order"


class bingoball_o  {
  protected:
    string_o Id;
    int      Value;
    int      Order;

  public:   
    bingoball_o();                                      // Default constructor.
    bingoball_o(const bingoball_o&);                    // Copy constructor.
   ~bingoball_o();                                      // Default destructor.
    bingoball_o&      operator =  (const bingoball_o&); // Assignment operator.
    void              operator >> (string_o&) const;    // Node-Value.
    void              operator << (const char*);        // Reconstruct.
    void              clear();

    const char*       id()                  const;
          int         value()               const;
          int         order()               const;

    const char*       setValue(int);
          int         setOrder(int);
};
string_o& operator << (string_o&,const bingoball_o&);


/******************************************************************************/

inline const char* bingoball_o::id() const  {
    return  Id.string();
}

inline int bingoball_o::order() const  {
    return  Order;
}

inline int bingoball_o::value() const  {
    return  Value;
}

inline const char* bingoball_o::setValue(int v)  {
    if(v > 0 && v < 76)  {
        Value = v;
        if(v == 1)  Id = "B1";
        else if(v == 2)   Id = "B2";
        else if(v == 3)   Id = "B3";
        else if(v == 4)   Id = "B4";
        else if(v == 5)   Id = "B5";
        else if(v == 6)   Id = "B6";
        else if(v == 7)   Id = "B7";
        else if(v == 8)   Id = "B8";
        else if(v == 9)   Id = "B9";
        else if(v == 10)  Id = "B10";
        else if(v == 11)  Id = "B11";
        else if(v == 12)  Id = "B12";
        else if(v == 13)  Id = "B13";
        else if(v == 14)  Id = "B14";
        else if(v == 15)  Id = "B15";
        else if(v == 16)  Id = "I16";
        else if(v == 17)  Id = "I17";
        else if(v == 18)  Id = "I18";
        else if(v == 19)  Id = "I19";
        else if(v == 20)  Id = "I20";
        else if(v == 21)  Id = "I21";
        else if(v == 22)  Id = "I22";
        else if(v == 23)  Id = "I23";
        else if(v == 24)  Id = "I24";
        else if(v == 25)  Id = "I25";
        else if(v == 26)  Id = "I26";
        else if(v == 27)  Id = "I27";
        else if(v == 28)  Id = "I28";
        else if(v == 29)  Id = "I29";
        else if(v == 30)  Id = "I30";
        else if(v == 31)  Id = "N31";
        else if(v == 32)  Id = "N32";
        else if(v == 33)  Id = "N33";
        else if(v == 34)  Id = "N34";
        else if(v == 35)  Id = "N35";
        else if(v == 36)  Id = "N36";
        else if(v == 37)  Id = "N37";
        else if(v == 38)  Id = "N38";
        else if(v == 39)  Id = "N39";
        else if(v == 40)  Id = "N40";
        else if(v == 41)  Id = "N41";
        else if(v == 42)  Id = "N42";
        else if(v == 43)  Id = "N43";
        else if(v == 44)  Id = "N44";
        else if(v == 45)  Id = "N45";
        else if(v == 46)  Id = "G46";
        else if(v == 47)  Id = "G47";
        else if(v == 48)  Id = "G48";
        else if(v == 49)  Id = "G49";
        else if(v == 50)  Id = "G50";
        else if(v == 51)  Id = "G51";
        else if(v == 52)  Id = "G52";
        else if(v == 53)  Id = "G53";
        else if(v == 54)  Id = "G54";
        else if(v == 55)  Id = "G55";
        else if(v == 56)  Id = "G56";
        else if(v == 57)  Id = "G57";
        else if(v == 58)  Id = "G58";
        else if(v == 59)  Id = "G59";
        else if(v == 60)  Id = "G60";
        else if(v == 61)  Id = "O61";
        else if(v == 62)  Id = "O62";
        else if(v == 63)  Id = "O63";
        else if(v == 64)  Id = "O64";
        else if(v == 65)  Id = "O65";
        else if(v == 66)  Id = "O66";
        else if(v == 67)  Id = "O67";
        else if(v == 68)  Id = "O68";
        else if(v == 69)  Id = "O69";
        else if(v == 70)  Id = "O70";
        else if(v == 71)  Id = "O71";
        else if(v == 72)  Id = "O72";
        else if(v == 73)  Id = "O73";
        else if(v == 74)  Id = "O74";
        else if(v == 75)  Id = "O75";
    }
    else  {
        Value = 0;
        Id = "VOID";
    }
    return Id.string();
}

inline int bingoball_o::setOrder(int o)  {
    if(o > 0)  {
        Order = o;
    }
    return Order;
}


#endif

/*****************************************************************************/
