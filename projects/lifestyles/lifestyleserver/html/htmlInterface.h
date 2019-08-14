/**  htmlInterface.h  **********************************************************

    HTML Interface Object.


changes log
when       who      what
3.20.99    Dan      Creation.
12.23.99   Dan      Added:    Rotating Banners and background.

*******************************************************************************/

#ifndef HTMLINTERFACEOBJECT_API
#define HTMLINTERFACEOBJECT_API


#include "../../../library/lib/string/string.h"
#include "../../../library/lib/thread/mutex.h"

#include "../../containers/rotatingBanner.h"

#include "../html/htmlLogin.h"
#include "../html/htmlNewSettings.h"
#include "../html/htmlThankYou.h"
#include "../html/htmlEmergencyBroadcastEntry.h"
#include "../html/htmlLifestyleUserMenu.h"
#include "../html/htmlSendMessage.h"
#include "../html/htmlExamineService.h"
#include "../html/htmlDatedMessageEntry.h"
#include "../html/htmlStencil.h"
#include "../html/htmlSideMenu.h"
#include "../html/htmlSideMenuLoggedin.h"
#include "../html/htmlChangeDynamicMenu.h"
#include "../html/htmlPleaseRegister.h"



class htmlInterface_o  {
  private:
    mutex_o Mutex;
  protected:
    void          init();

  public:
    htmlInterface_o();
    htmlInterface_o(const htmlInterface_o&);
   ~htmlInterface_o();
    htmlInterface_o& operator = (const htmlInterface_o&);

    rotatingBanner_o rotatingBanner;
    int              rotatingBannerIndex;

    htmlLogin_o  htmlLogin;
    htmlNewSettings_o  htmlNewSettings;
    htmlThankYou_o  htmlThankYou;
    htmlStencil_o  htmlStencil;
    htmlSideMenu_o  htmlSideMenu;
    htmlSideMenuLoggedin_o  htmlSideMenuLoggedin;
    htmlEmergencyBroadcastEntry_o  htmlEmergencyBroadcastEntry;
    htmlLifestyleUserMenu_o  htmlLifestyleUserMenu;
    htmlSendMessage_o  htmlSendMessage;
    htmlExamineService_o htmlExamineService;
    htmlDatedMessageEntry_o htmlDatedMessageEntry;
    htmlChangeDynamicMenu_o htmlChangeDynamicMenu;
    htmlPleaseRegister_o htmlPleaseRegister;


    int setRotatingBanner(const rotatingBanner_o&);
    const char* rotatingBannerURL();
    const char* rotatingBackgroundURL();
    const char* logoURL();
};


/******************************************************************************/



#endif

/******************************************************************************/
