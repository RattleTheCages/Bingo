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


#include "../hdml/hdmlMenu.h"
#include "../hdml/hdmlJoinGame.h"
#include "../hdml/hdmlViewAccount.h"
#include "../hdml/hdmlViewCards.h"
#include "../hdml/hdmlInProgress.h"
#include "../hdml/hdmlGame.h"
#include "../hdml/hdmlClosed.h"
#include "../hdml/hdmlBingo.h"
#include "../hdml/hdmlTakingBets.h"

#include "../containers/pdaInput.h"

#include "../../library/lib/string/string.h"



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

    hdmlMenu_o          hdmlMenu;
    hdmlJoinGame_o      hdmlJoinGame;
    hdmlViewAccount_o   hdmlViewAccount;
    hdmlViewCards_o     hdmlViewCards;
    hdmlInProgress_o    hdmlInProgress;
    hdmlGame_o          hdmlGame;
    hdmlClosed_o        hdmlClosed;
    hdmlBingo_o         hdmlBingo;
    hdmlTakingBets_o    hdmlTakingBets;


    int parse(pdaInput_o&);

    const char* transactionServerPath() const;
    const char* staticServerPath() const;

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
