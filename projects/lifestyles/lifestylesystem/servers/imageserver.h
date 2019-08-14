/**  imageserver.h  ************************************************************

    Image Server Object.


changes log
when       who     what
12.7.99    Dan     Creation. 

*******************************************************************************/


#ifndef IMAGESERVEROBJECT_API
#define IMAGESERVEROBJECT_API

#include "../../../library/lib/string/string.h"
#include "../../../library/lib/thread/mutex.h"
#include "../../../library/pserver/carapace/carapace.h"


#include "../../containers/serverManifest.h"
#include "../../dynamicContainers/lifestyleSession.h"


#define IMAGESERVER_DEFAULT_PORT 5111


class imageserver_o  {
  private:
    serverManifest_o ServerManifest;
    mutex_o       mutex;
    unsigned long NumberProcessed;

  protected:
    string_o    Id;
    int         State;


  public:   
    imageserver_o();                                    // Default constructor.
    imageserver_o(const imageserver_o&);                // Copy constructor.
   ~imageserver_o();                                    // Default destructor.
    imageserver_o&  operator =  (const imageserver_o&); // Assignment operator.

          int       process(input_o&,output_o&);
          int       state()                     const;
    const char*     id()                        const;
    unsigned long   numberProcessed()           const;

};


/******************************************************************************/

inline int imageserver_o::state() const  {
    return  State;
}

inline unsigned long imageserver_o::numberProcessed() const  {
    return NumberProcessed;
}

inline const char* imageserver_o::id() const  {
    return  Id.string();
}


#endif

/******************************************************************************/
