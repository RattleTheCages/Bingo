/**  hdmlWeatherContainerDisplay.h  ********************************************


    HDML Weather Container Display Object.

    This object creates an hdml display of a weather_o container object.


changes log
when       who      what
10.6.99   Dan      Creation.

*******************************************************************************/

#ifndef HDMLWEATHERCONTAINERDISPLAYOBJECT_API
#define HDMLWEATHERCONTAINERDISPLAYOBJECT_API

#include "../../../library/lib/string/string.h"

#include "../../containers/weather.h"


class hdmlWeatherContainerDisplay_o  {
  private:
    void          init();

  public:
    hdmlWeatherContainerDisplay_o();                    // Default constructor.
    hdmlWeatherContainerDisplay_o(const hdmlWeatherContainerDisplay_o&);
                                                        // Copy constructor.
   ~hdmlWeatherContainerDisplay_o();                    // Default destructor.
    hdmlWeatherContainerDisplay_o& operator = (const hdmlWeatherContainerDisplay_o&);                                                   // Assignment operator.

    void page(const weather_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
