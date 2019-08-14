/**  hdmlViewWeather.cc  *******************************************************



changes log
when       who      what
3.23.99    Dan      Creation.

*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../hdml/hdmlViewWeather.h"
#include "../hdml/hdmlInterface.h"


extern hdmlInterface_o*     hdmlInterface;

hdmlViewWeather_o::hdmlViewWeather_o()  {
    (void)init();
}

hdmlViewWeather_o::~hdmlViewWeather_o()  {}

void hdmlViewWeather_o::init()  {
}

void hdmlViewWeather_o::page(const address_o& address,const weather_o& weather,string_o& s)  {

string_o place;
place = address.city();
if(place.length() < 2)  place = address.zip();


::hdmlInterface->hdmlServerHeader.page(s);

s<< "<HDML VERSION=2.0 PUBLIC=TRUE TTL=0>\n";
s<< "<DISPLAY>\n";
s<< "<ACTION TYPE=PREV LABEL=\"BACK\" GO=\"" << ::hdmlInterface->transactionServerPath() << "\">\n";
s<< "<ACTION TYPE=ACCEPT LABEL=\"DONE\" GO=\"" << ::hdmlInterface->transactionServerPath() << "/lifestylemenu\">\n";
s<< "<LINE>Location: "<<place<<"\n";
::hdmlInterface->hdmlWeatherContainerDisplay.page(weather,s);
s<< "</DISPLAY>\n";
s<< "\n";
s<< "</HDML>\n";


}



/******************************************************************************/
