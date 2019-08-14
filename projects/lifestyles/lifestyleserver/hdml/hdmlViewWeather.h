/**  htmlViewWeather.h  ********************************************************


    HDML View Weather Object.


changes log
when       who      what
3.23.99    Dan      Creation.

*******************************************************************************/

#ifndef HTMLVIEWWEATHEROBJECT_API
#define HTMLVIEWWEATHEROBJECT_API

#include "../../../library/lib/string/string.h"

#include "../../containers/weather.h"
#include "../../containers/address.h"


class hdmlViewWeather_o  {
  private:

  protected:
    void          init();

  public:
    hdmlViewWeather_o();                                    // Default constructor.
    hdmlViewWeather_o(const hdmlViewWeather_o&);                    // Copy constructor.
   ~hdmlViewWeather_o();                                    // Default destructor.
    hdmlViewWeather_o& operator = (const hdmlViewWeather_o&);       // Asignment operator.

    void page(const address_o&,const weather_o&,string_o&);

};


/******************************************************************************/


#endif

/******************************************************************************/
