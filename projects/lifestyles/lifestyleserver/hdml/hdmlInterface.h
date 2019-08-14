/**  hdmlInterface.h  ********************************************************

    HDML Interface Object.


log_o debug levels:
901 - Transaction and Static server paths.
902 - Parse String Sent.
903 - Parsed Command.
904 - Parsed Phone.
905 - Parsed Node-Value.


changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/

#ifndef HDMLINTERFACEOBJECT_API
#define HDMLINTERFACEOBJECT_API


#include "../../../library/lib/string/string.h"

//#include "../hdml/hdmlViewAccount.h"
#include "../hdml/hdmlNewUser.h"
#include "../hdml/hdmlViewWeather.h"
#include "../hdml/hdmlWeatherContainerDisplay.h"
#include "../hdml/hdmlLifestyleChange.h"
#include "../hdml/hdmlLifestyleDynamicMenu.h"
#include "../hdml/hdmlEmergencyBroadcast.h"
#include "../hdml/hdmlViewPassCode.h"
#include "../hdml/hdmlDisplayUrgentMessage.h"
#include "../hdml/hdmlServerHeader.h"
#include "../hdml/hdmlDisplayMessages.h"
#include "../hdml/hdmlEnterMessage.h"

#include "../../containers/pdaInput.h"




class hdmlInterface_o  {
  private:
    hdmlInterface_o*    hdmlInterface;
    string_o            TransactionServerPath;
    string_o            StaticServerPath;

    void unnet(string_o&);

  public:
    void          init();


  public:
    hdmlInterface_o();
    hdmlInterface_o(const hdmlInterface_o&);
   ~hdmlInterface_o();
    hdmlInterface_o& operator = (const hdmlInterface_o&);

//    hdmlViewAccount_o   hdmlViewAccount;
    hdmlNewUser_o       hdmlNewUser;
    hdmlViewWeather_o       hdmlViewWeather;
    hdmlWeatherContainerDisplay_o hdmlWeatherContainerDisplay;
    hdmlLifestyleChange_o hdmlLifestyleChange;
    hdmlLifestyleDynamicMenu_o hdmlLifestyleDynamicMenu;
    hdmlEmergencyBroadcast_o hdmlEmergencyBroadcast;
    hdmlViewPassCode_o hdmlViewPassCode;
    hdmlDisplayUrgentMessage_o hdmlDisplayUrgentMessage;
    hdmlServerHeader_o hdmlServerHeader;
    hdmlDisplayMessages_o hdmlDisplayMessages;
    hdmlEnterMessage_o hdmlEnterMessage;


    int parse(pdaInput_o&);

    const char* transactionServerPath() const;
    const char* staticServerPath() const;


    string_o fontFix;

};


/**  Inline methods need to be in the header.  ********************************/

inline const char* hdmlInterface_o::transactionServerPath() const  {
    return TransactionServerPath.string();
}

inline const char* hdmlInterface_o::staticServerPath() const  {
    return StaticServerPath.string();
}

#endif

/******************************************************************************/
