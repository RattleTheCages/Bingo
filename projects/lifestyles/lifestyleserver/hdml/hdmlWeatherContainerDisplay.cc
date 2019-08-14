/**  hdmlWeatherContainerDisplay.h  ********************************************


changes log
when       who      what
10.6.99    Dan      Creation.


*******************************************************************************/

#include "../hdml/hdmlWeatherContainerDisplay.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o*     hdmlInterface;

hdmlWeatherContainerDisplay_o::hdmlWeatherContainerDisplay_o()  {
    (void)init();
}

hdmlWeatherContainerDisplay_o::~hdmlWeatherContainerDisplay_o()  {}

void hdmlWeatherContainerDisplay_o::init()  {
}

void hdmlWeatherContainerDisplay_o::page(const weather_o& weather,string_o& s)  {

s<< "<LINE>Temperature: " << weather.temp() << "F\n";
s<< "<LINE>Humdity    : " << weather.humd() << "\n";
s<< "<LINE>Condition  : " << weather.cond() << "\n";
s<< "<WRAP>Forcast    : " << weather.forc() << "\n";

}



/******************************************************************************/
