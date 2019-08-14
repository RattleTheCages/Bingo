/**  lifestyleSession.cc  ******************************************************




changes log
when       who     what
10.7.99    Dan     Creation. 

*******************************************************************************/


#include "../../library/lib/parse/parse.h"
#include "../dynamicContainers/lifestyleSession.h"



extern log_o  log;

lifestyleSession_o::lifestyleSession_o()  {
    (void)init();
}

lifestyleSession_o::~lifestyleSession_o()  {}

void lifestyleSession_o::init()  {
    int       x,y;

    State               = 0;
    MessagePending      = 0;
    EmergencyBroadcastPending = 0;

    Transactions        = 0;
    RegisteredUser      = 0;
    NumberOfLifestyles  = LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;

    Passcode.clear();


    for(y=0;y<LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;y++)  {
        for(x=0;x<LIFESTYLESESSION_SERVICES_MAX;x++)  {
            ServicesMap[y][x] = 0;
        }
    }
}

int lifestyleSession_o::setMap(service_o* services,lifestyleItem_o* lifestyleItems)  {
    int       x,y;
    string_o  a;

    for(y=0;y<LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;y++)  {
        for(x=0;x<LIFESTYLESESSION_SERVICES_MAX;x++)  {
            a = services[x].lifestyle();
            if(a.length() > 1 && (a == "All" || a == lifestyleItems[y].name())) {
                ServicesMap[y][x] = 1;
            }
        }
    }

    return ERROR_OK;
}

lifestyleSession_o& lifestyleSession_o::operator =(const lifestyleSession_o& ls)  {
    int x,y;

    State               = ls.State;
    MessagePending      = ls.MessagePending;
    EmergencyBroadcastPending = ls.EmergencyBroadcastPending;

    Transactions        = ls.Transactions;
    Id                  = ls.Id;
    RegisteredUser      = ls.RegisteredUser;
    Passcode            = ls.Passcode;
    NumberOfLifestyles  = ls.NumberOfLifestyles;


    for(y=0;y<LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;y++)  {
        for(x=0;x<LIFESTYLESESSION_SERVICES_MAX;x++)  {
            ServicesMap[y][x] = ls.ServicesMap[y][x];
        }
    }

    for(y=0;y<LIFESTYLESESSION_ADDRESS_OBJECT_MAX;y++)  {
            Address[y] = ls.Address[y];
    }

    for(y=0;y<LIFESTYLESESSION_ACTDATE_OBJECT_MAX;y++)  {
            Actdate[y] = ls.Actdate[y];
    }

    return *this;
}

void lifestyleSession_o::clear()  {
    int y;

    (void)init();

    for(y=0;y<LIFESTYLESESSION_ADDRESS_OBJECT_MAX;y++)  {
            Address[y].clear();
    }

    for(y=0;y<LIFESTYLESESSION_ACTDATE_OBJECT_MAX;y++)  {
            Actdate[y].clear();
    }

}

void lifestyleSession_o::operator >> (string_o& s) const  {
    int x,y;
    string_o t;

    s << "\nlifestyleSession_o:";
    s << '\n' << LIFESTYLESESSION_TRANSACTIONS << '=' << Transactions;
    s << '\n' << LIFESTYLESESSION_ID << '=' << Id;
    s << '\n' << LIFESTYLESESSION_REGISTEREDUSER << '=' << RegisteredUser;
    s << '\n' << LIFESTYLESESSION_NUMBEROFLIFESTYLES << '=' << NumberOfLifestyles;
    Passcode >> t;
    s << '\n' << LIFESTYLESESSION_PASSCODE << '=' << t;


    for(x=0;x<LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;x++)  {
        for(y=0;y<LIFESTYLESESSION_SERVICES_MAX;y++)  {
            s << '\n' << LIFESTYLESESSION_SERVICEMAP << "[" << x << "][" << y << "]=" << ServicesMap[x][y];
        }
    }

    for(x=0;x<LIFESTYLESESSION_ADDRESS_OBJECT_MAX;x++)  {
        t = "";
        Address[x] >> t;
        s << '\n' << LIFESTYLESESSION_ADDRESS << "[" << x << "]=" << t;
    }

    for(x=0;x<LIFESTYLESESSION_ACTDATE_OBJECT_MAX;x++)  {
        t = "";
        Actdate[x] >> t;
        s << '\n' << LIFESTYLESESSION_ACTDATE << "[" << x << "]=" << t;
    }

    s << '\n';
}

void lifestyleSession_o::operator << (const char* bs)  {
    int x,y;
    string_o a,b;
    string_o message;
    parse_o  parse(bs);

    (void)parse.it(LIFESTYLESESSION_TRANSACTIONS,Transactions);
    (void)parse.it(LIFESTYLESESSION_ID,Id);
    (void)parse.it(LIFESTYLESESSION_REGISTEREDUSER,RegisteredUser);

    a = LIFESTYLESESSION_PASSCODE;
    b = bs;
    b.upcut(a.string());
    b.cut("\n\n");
    Passcode << b.string();

    (void)parse.it(LIFESTYLESESSION_NUMBEROFLIFESTYLES,NumberOfLifestyles);

    for(x=0;x<LIFESTYLESESSION_LIFESTYLE_ITEM_MAX;x++)  {
        for(y=0;y<LIFESTYLESESSION_SERVICES_MAX;y++)  {
            a = LIFESTYLESESSION_SERVICEMAP;
            a << "[" << x << "][" << y << "]";
            (void)parse.it(a.string(),ServicesMap[x][y]);
        }
    }

    for(x=0;x<LIFESTYLESESSION_ADDRESS_OBJECT_MAX;x++)  {
        a = LIFESTYLESESSION_ADDRESS;
        a << "[" << x << "]";
        b = bs;
        b.upcut(a.string());
        b.cut("\n\n");
        Address[x] << b.string();
    }

    for(x=0;x<LIFESTYLESESSION_ACTDATE_OBJECT_MAX;x++)  {
        a = LIFESTYLESESSION_ACTDATE;
        a << "[" << x << "]";
        b = bs;
        b.upcut(a.string());
        b.cut("\n\n");
        Actdate[x] << b.string();
    }

}

string_o& operator << (string_o& s,const lifestyleSession_o& bs)  {
    bs >> s;
    return s;
}


/******************************************************************************/
