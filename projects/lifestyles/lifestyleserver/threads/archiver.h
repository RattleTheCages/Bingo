/**  archiver.h  ***************************************************************

    Archiver Object.



log_o::debug levels


changes log
when      who       what
10.22.99  Dan       Creation 


*******************************************************************************/


#ifndef ARCHIVERTHREADOBJECT_API
#define ARCHIVERTHREADOBJECT_API

#include "../../../library/lib/thread/thread.h"


#define ARCHIVER_ARCHIVESERVER_IP   "204.131.41.3"
#define ARCHIVER_ARCHIVESERVER_PORT 8194


class archiver_o: public thread_o  {
  private:
    unsigned long       NumberAdvanced;

    string_o            ArchiveServerIp;
    int                 ArchiveServerPort;

    
  public:
    archiver_o();                                       // Default constructor.
    archiver_o(const archiver_o&);                      // Copy contructor.
    archiver_o(const thread_o&);
   ~archiver_o();                                       // Default destructor.
    archiver_o& operator = (const archiver_o&);         // Assignment operator.

    void            process();

    int             numberAdvanced()      const;
    const char*     archiveServerIp()     const;
    int             archiveServerPort()   const;
};
void* startarchiver(void*);



/******************************************************************************/


inline int archiver_o::numberAdvanced() const  {
    return NumberAdvanced;
}

inline int archiver_o::archiveServerPort() const  {
    return ArchiveServerPort;
}

inline const char* archiver_o::archiveServerIp() const  {
    return ArchiveServerIp.string();
}


#endif

/******************************************************************************/
