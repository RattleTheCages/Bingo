/**  epi.h  ********************************************************************


    Executable Programmer Interface Object.



changes log
when      who       what
11.11.99  Dan       Creation 


*******************************************************************************/


#ifndef EPITHREADOBJECT_EPI
#define EPITHREADOBJECT_EPI

#include "../../../library/lib/thread/thread.h"


#define EPI_EPISERVER_DEFAULT_IP   "204.131.41.3"
#define EPI_EPISERVER_DEFAULT_PORT 8194


class epi_o: public thread_o  {
  private:
    unsigned long int   NumberAdvanced;

    string_o            EPIServerIp;
    int                 EPIServerPort;

    
  public:
    epi_o();                                            // Default constructor.
    epi_o(const epi_o&);                                // Copy contructor.
    epi_o(const thread_o&);
   ~epi_o();                                            // Default destructor.
    epi_o& operator = (const epi_o&);                   // Assignment operator.

    void            process();

    unsigned long int   numberAdvanced()    const;
    const char*         epiServerIp()       const;
    int                 epiServerPort()     const;
};
void* startepi(void*);//!!



/******************************************************************************/


inline unsigned long int epi_o::numberAdvanced() const  {
    return NumberAdvanced;
}

inline int epi_o::epiServerPort() const  {
    return EPIServerPort;
}

inline const char* epi_o::epiServerIp() const  {
    return EPIServerIp.string();
}


#endif

/******************************************************************************/
