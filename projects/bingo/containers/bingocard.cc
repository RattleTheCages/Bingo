/**  bingocard.cc  *************************************************************

changes log:
when       who     what
9.19.99    Dan     Creation. 


*******************************************************************************/


#include "../containers/bingocard.h"
#include "../../library/lib/parse/parse.h"

bingocard_o::bingocard_o()  {
    int x;
    for(x=0;x<5;x++)  {
        B[x] = 0;
        I[x] = 0;
        N[x] = 0;
        G[x] = 0;
        O[x] = 0;

        Bx[x] = 0;
        Ix[x] = 0;
        Nx[x] = 0;
        Gx[x] = 0;
        Ox[x] = 0;
    }
    Nx[2] = 1;  // Free!!
}

bingocard_o::~bingocard_o()  {}

bingocard_o& bingocard_o::operator = (const bingocard_o& c)  {
    int x;

    Id = c.Id;
    for(x=0;x<5;x++)  {
        B[x] =  c.B[x];
        I[x] =  c.I[x];
        N[x] =  c.N[x];
        G[x] =  c.G[x];
        O[x] =  c.O[x];

        Bx[x] = c.Bx[x];
        Ix[x] = c.Ix[x];
        Nx[x] = c.Nx[x];
        Gx[x] = c.Gx[x];
        Ox[x] = c.Ox[x];
    }
    Nx[2] = 1;  // Free!!

    return *this;
}

void bingocard_o::clear()  {
    int x;
    for(x=0;x<5;x++)  {
        B[x] = 0;
        I[x] = 0;
        N[x] = 0;
        G[x] = 0;
        O[x] = 0;

        Bx[x] = 0;
        Ix[x] = 0;
        Nx[x] = 0;
        Gx[x] = 0;
        Ox[x] = 0;
    }
    Nx[2] = 1;  // Free!!
}

void bingocard_o::operator >> (string_o& s) const  {
    int x;
    string_o t;
    s << "\nbingocard_o:";
    s << '\n' << BINGOCARD_ID << '=' << Id;
    for(x=0;x<5;x++)  {
        t = BINGOCARD_B_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << B[x];
        t = BINGOCARD_I_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << I[x];
        t = BINGOCARD_N_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << N[x];
        t = BINGOCARD_G_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << G[x];
        t = BINGOCARD_O_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << O[x];
        t = BINGOCARD_BX_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << Bx[x];
        t = BINGOCARD_IX_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << Ix[x];
        t = BINGOCARD_NX_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << Nx[x];
        t = BINGOCARD_GX_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << Gx[x];
        t = BINGOCARD_OX_NNN;
        t.cut(t.length()-3);
        s << '\n' << t << x << '=' << Ox[x];
    }
    s << '\n';
}

void bingocard_o::operator << (const char* cc)  {
    int x;
    string_o t;
    parse_o parse(cc);
    (void)parse.it(BINGOCARD_ID,Id);
    for(x=0;x<5;x++)  {
        t = BINGOCARD_B_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),B[x]);
        t = BINGOCARD_I_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),I[x]);
        t = BINGOCARD_N_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),N[x]);
        t = BINGOCARD_G_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),G[x]);
        t = BINGOCARD_O_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),O[x]);
        t = BINGOCARD_BX_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),Bx[x]);
        t = BINGOCARD_IX_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),Ix[x]);
        t = BINGOCARD_NX_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),Nx[x]);
        t = BINGOCARD_GX_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),Gx[x]);
        t = BINGOCARD_OX_NNN;
        t.cut(t.length()-3);
        t << x;
        (void)parse.it(t.string(),Ox[x]);
    }
}

string_o& operator << (string_o& s,const bingocard_o& c)  {
    c >> s;
    return s;
}


/******************************************************************************/
