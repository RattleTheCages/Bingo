/**  serverManifest.h  *********************************************************

    Server Manifest Container Object.


changes log
when       who     what
10.22.99   Dan     Creation. 

*******************************************************************************/


#ifndef SERVERMANIFESTOBJECT_CONTAINER
#define SERVERMANIFESTOBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define SERVERMANIFEST_ID        "serverManifest_o.id"
#define SERVERMANIFEST_PARENTID  "serverManifest_o.parentid"
#define SERVERMANIFEST_STATE     "serverManifest_o.state"
#define SERVERMANIFEST_TYPE      "serverManifest_o.type"
#define SERVERMANIFEST_NAME      "serverManifest_o.name"
#define SERVERMANIFEST_LOCATION  "serverManifest_o.location"
#define SERVERMANIFEST_NUMBERPROCESSED "serverManifest_o.processed"
#define SERVERMANIFEST_IP        "serverManifest_o.ip"
#define SERVERMANIFEST_PORT      "serverManifest_o.port"

#define SERVERMANIFEST_ID_MAX         64
#define SERVERMANIFEST_PARENTID_MAX   64
#define SERVERMANIFEST_TYPE_MAX       32
#define SERVERMANIFEST_NAME_MAX       32
#define SERVERMANIFEST_LOCATION_MAX   64
#define SERVERMANIFEST_IP_MAX         64


class serverManifest_o  {
  protected:
    string_o Id;
    string_o ParentId;
    string_o State;
    string_o Type;
    string_o Name;
    string_o Location;
    string_o NumberProcessed;
    string_o Ip;
    string_o Port;

  public:   
    serverManifest_o();                                 // Default constructor.
    serverManifest_o(const serverManifest_o&);          // Copy constructor.
   ~serverManifest_o();                                 // Default destructor.
    serverManifest_o&      operator =  (const serverManifest_o&);
                                                        // Assignment operator.
    void            operator >> (string_o&) const;      // Object Lang Protocol.
    void            operator << (const char*);          // Reconstruct.
    void            clear();

    int             blank()                 const;
    const char*     id()                    const;
    const char*     parentid()              const;
    const char*     state()                 const;
    const char*     type()                  const;
    const char*     name()                  const;
    const char*     location()              const;
    const char*     numberProcessed()       const;
    const char*     ip()                    const;
    const char*     port()                  const;

    void            setId(const char*);
    void            setParentId(const char*);
    void            setState(const char*);
    void            setState(int);
    void            setType(const char*);
    void            setName(const char*);
    void            setLocation(const char*);
    void            setNumberProcessed(const char*);
    void            setNumberProcessed(unsigned long int);
    void            setIp(const char*);
    void            setPort(const char*);
    void            setPort(int);

};


/******************************************************************************/

inline const char* serverManifest_o::id() const  {
    return  Id.string();
}

inline const char* serverManifest_o::parentid() const  {
    return  ParentId.string();
}

inline const char* serverManifest_o::state() const  {
    return  State.string();
}

inline const char* serverManifest_o::type() const  {
    return  Type.string();
}

inline const char* serverManifest_o::name() const  {
    return  Name.string();
}

inline const char* serverManifest_o::location() const  {
    return  Location.string();
}

inline const char* serverManifest_o::numberProcessed() const  {
    return  NumberProcessed.string();
}

inline const char* serverManifest_o::ip() const  {
    return  Ip.string();
}

inline const char* serverManifest_o::port() const  {
    return  Port.string();
}


inline void serverManifest_o::setId(const char* id)  {
    Id = id;
    Id.cut(SERVERMANIFEST_ID_MAX);
}

inline void serverManifest_o::setParentId(const char* id)  {
    ParentId = id;
    ParentId.cut(SERVERMANIFEST_PARENTID_MAX);
}

inline void serverManifest_o::setType(const char* ty)  {
    Type = ty;
    Type.cut(SERVERMANIFEST_TYPE_MAX);
}

inline void serverManifest_o::setName(const char* na)  {
    Name = na;
    Name.cut(SERVERMANIFEST_NAME_MAX);
}

inline void serverManifest_o::setLocation(const char* st)  {
    Location = st;
    Location.cut(SERVERMANIFEST_LOCATION_MAX);
}

inline void serverManifest_o::setNumberProcessed(const char* ts)  {
    NumberProcessed = ts;
}

inline void serverManifest_o::setNumberProcessed(unsigned long int uli)  {
    (NumberProcessed = "") << uli;
}

inline void serverManifest_o::setState(const char* ts)  {
    State = ts;
}

inline void serverManifest_o::setState(int s)  {
    (State = "") << s;
}

inline void serverManifest_o::setIp(const char* ip)  {
    Ip = ip;
    Ip.cut(SERVERMANIFEST_IP_MAX);
}

inline void serverManifest_o::setPort(const char* pr)  {
    Port = pr;
}

inline void serverManifest_o::setPort(int pr)  {
    (Port = "") << pr;
}


#endif

/******************************************************************************/
