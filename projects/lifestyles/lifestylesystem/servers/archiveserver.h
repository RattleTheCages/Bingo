/**  archiveserver.h  **********************************************************

    Archive Server Object.


changes log
when       who     what
10.22.99   Dan     Creation. 

*******************************************************************************/


#ifndef ARCHIVESERVEROBJECT_API
#define ARCHIVESERVEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/thread/mutex.h"
#include "../../../library/pserver/carapace/carapace.h"


#include "../../dynamicContainers/lifestyleSession.h"


class archiveserver_o  {
  private:
    mutex_o       mutex;
    unsigned long NumberProcessed;

  protected:
    string_o    Id;
    int         State;


  public:   
    archiveserver_o();                                  // Default constructor.
    archiveserver_o(const archiveserver_o&);            // Copy constructor.
   ~archiveserver_o();                                  // Default destructor.
    archiveserver_o&  operator =  (const archiveserver_o&);
                                                        // Assignment operator.

          int       process(input_o&,output_o&);
          int       state()                     const;
    const char*     id()                        const;
    unsigned long   numberProcessed()           const;

};


/******************************************************************************/

inline int archiveserver_o::state() const  {
    return  State;
}

inline unsigned long archiveserver_o::numberProcessed() const  {
    return NumberProcessed;
}

inline const char* archiveserver_o::id() const  {
    return  Id.string();
}


#endif

/******************************************************************************/
