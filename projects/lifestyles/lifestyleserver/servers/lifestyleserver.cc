/**  lifestyleserver.cc  *******************************************************


    lifestyleserver 0.032 server.


changes log
when        who    when
10.7.99     Dan    Creation.
11.25.99    Dan    Added:    Scheduled messageing system.
12.4.99     Dan    Changed:  Passcode system.
12.23.99    Dan    Added:    Rotating Banners.


*******************************************************************************/


#include <unistd.h>
#include <time.h>
#include <signal.h>


#include "../servers/lifestyleserver.h"


#include "../../../library/lib/string/string.h"
#include "../../../library/lib/memory/cache.h"
#include "../../../library/lib/log/log.h"
#include "../../../library/lib/other/sysinfo.h"
#include "../../../library/lib/other/rand.h"
#include "../../../library/pserver/pserver.h"
#include "../../../library/sserver/telenet/client.h"
#include "../hdml/hdmlInterface.h"
#include "../html/htmlInterface.h"
#include "../../html/htmlTelluric.h"
#include "../../containers/pdaInput.h"
#include "../../containers/datedMessage.h"
#include "../threads/archiver.h"
#include "../threads/epi.h"


/**  **************************************************************************/

log_o                       log;
sysinfo_o                   sysinfo;
rand_o                      rndm;
carapace_o                  carapace;

pserver_o*                  pserver;
lifestyleserver_o*          lifestyleserver;
hdmlInterface_o*            hdmlInterface;
htmlInterface_o*            htmlInterface;
htmlTelluric_o*             htmlTelluric;
lifestyleSessionManager_o*  lifestyleSessionManager;
lifestyleQueueManager_o*    lifestyleQueueManager;


/**  **************************************************************************/


lifestyleserver_o::lifestyleserver_o()  {
    rotatingBanner_o rb;

    NumberProcessed = 0;
    State = 0;
    ServerManifest.setId("lifestyleserver-1");
    ServerManifest.setParentId("relegateserver-1");
    ServerManifest.setType("lifestyleserver");
    ServerManifest.setName("Lifestyle Server v0.2000");
    ServerManifest.setState(0);
    ServerManifest.setNumberProcessed(0UL);
    ServerManifest.setLocation("USA-Denver");
    ServerManifest.setIp("204.131.41.3");
    ServerManifest.setPort(4111);

    NumberOfServices = 0;
    NumberOfLifestyleItems = 0;

    rb.setId("Rotating Banner");
    rb.setNumberOfBanners(4);
    rb.setLogoURL("http://www.infomechanics.com/~dhuffman/images/lifestyles/logo1.jpg");
    rb.setBannerURL(0,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellscape1.jpg");
    rb.setBannerURL(1,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellscape2.jpg");
    rb.setBannerURL(2,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellscape3.jpg");
    rb.setBannerURL(3,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellscape4.jpg");
    rb.setBackgroundURL(0,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellbackground1.jpg");
    rb.setBackgroundURL(1,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellbackground1.jpg");
    rb.setBackgroundURL(2,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellbackground1.jpg");
    rb.setBackgroundURL(3,"http://www.infomechanics.com/~dhuffman/images/lifestyles/cellbackground1.jpg");


    ::htmlInterface->setRotatingBanner(rb);
}

lifestyleserver_o::~lifestyleserver_o()  {}


int lifestyleserver_o::generatePassCode(passcode_o& passcode)  {
    int ret;
    string_o message;

    string_o send;
    string_o recv;

    client_o client;


    passcode >> send;

    mutex.lock();
        ret = client.connect(LIFESTYLESERVER_DEFAULT_PASSCODE_SERVER_IP,
                             LIFESTYLESERVER_DEFAULT_PASSCODE_SERVER_PORT);

        if(ret != ERROR_OK)  {
            if(::log.debug(73))  {
                (message = "client.connect() error ") << ret << ".";
                ::log << message;
            }
        }


        ret = client.send(send);

        if(ret != ERROR_OK)  {
            if(::log.debug(73))  {
                (message = "client.send() error ") << ret << ".";
                ::log << message;
            }
        }


        ret = client.recv(recv);

        if(ret != ERROR_OK)  {
            if(::log.debug(73))  {
                (message = "client.recv() error ") << ret << ".";
                ::log << message;
            }
        }

    mutex.unlock();


    ret = client.disconnect();


    if(recv.length() > 6)  {
        passcode.clear();
        passcode << recv.string();
        passcode.setValid(1);
    }
    else  {
        passcode.setValid(0);
    }


    return ERROR_OK;
}

lifestyleSession_o* lifestyleserver_o::findLifestyleSessionByPasscode(const passcode_o& passcode)  {

    string_o                            message;
    cacheSearch_o<lifestyleSession_o>*  cs;
    lifestyleSession_o*                 lifestyleSession;


    if(::log.debug(71))  {
        (message = "") << "searching for `";
        message << passcode.userid() << "'";
        ::log << message;
    }


    lifestyleSession = NULL;

    cs = new cacheSearch_o<lifestyleSession_o>(&::lifestyleSessionManager->lifestyleSessions);
    if(cs)  {
        lifestyleSession = cs->listhead();
        while(lifestyleSession)  {
            if(passcode == lifestyleSession->passcode())  {

                if(::log.debug(73))  {
                    (message = "") << "found lifestyleSession: ";
                    message << lifestyleSession->id();
                    ::log << message;
                }

                break;
            }
            lifestyleSession = cs->listnext();
        }

        delete cs;
    }


    return lifestyleSession;
}

lifestyleSession_o* lifestyleserver_o::findLifestyleSessionByUserid(const char* uid)  {

    string_o                            message;
    string_o                            userid;
    cacheSearch_o<lifestyleSession_o>*  cs;
    lifestyleSession_o*                 lifestyleSession;


    userid = uid;
    lifestyleSession = NULL;

    cs = new cacheSearch_o<lifestyleSession_o>(&::lifestyleSessionManager->lifestyleSessions);
    if(cs)  {
        lifestyleSession = cs->listhead();
        while(lifestyleSession)  {
            if(userid == lifestyleSession->passcode().userid())  {

                if(::log.debug(73))  {
                    (message = "") << "found lifestyleSession: ";
                    message << lifestyleSession->id();
                    ::log << message;
                }

                break;
            }
            lifestyleSession = cs->listnext();
        }

        delete cs;
    }


    return lifestyleSession;
}

int lifestyleserver_o::changeLifestyleSettings(lifestyleSession_o* lifestyleSession,input_o& input,string_o& page)  {
    int x,y;
string_o s,t;
    string_o message;
    string_o add;
            string_o p1;
    lifestyleItem_o lifestyleItem;
actdate_o actdate;


        if(::log.debug(76))  {
            (message = "") << "changeLifestyleSettings()";
            ::log << message;
        }


        if(input.message().contains("actdate_o"))  {
/*
            s = input.message();

            (void)::htmlTelluric->unnet(s);
 
            s.upcut(ACTDATE_OBJECT);
            s.transpose("&","\n");
            t << (char)13;
            s.transpose(t.string(),"\n");

            actdate << s.string();
cout<<"XYXYXYXYXYXYXYXYXYXYXYXYXYXYXY"<<endl;
cout<<s<<endl;
cout<<"XYXYXYXYXYXYXYXYXYXYXYXYXYXYXY"<<endl;
            lifestyleSession->Actdate[0] = actdate;
*/
        }


        if(input.message().contains("lifestyleItem_o"))  {
            s = input.message();

            (void)::htmlTelluric->unnet(s);
 
            s.upcut(LIFESTYLEITEM_OBJECT);
            s.transpose("&","\n");
            t << (char)13;
            s.transpose(t.string(),"\n");

            lifestyleItem << s.string();

        }

for(y=0;y<NumberOfLifestyleItems;y++)  {
    if(lifestyleItem == LifestyleItems[y])  break;
}


        if(input.message().contains("address_o"))  {
            add = input.message();
            add.upcut("address_o");
            add.upcut('=');
            add.cut('&');
            add.boxears();

            if(add.length() > 4)  {
                lifestyleSession->Address[y].setZip(add.string());
            }
        }

for(x=0;x<NumberOfServices;x++)  {

        p1 = "cb=";
        p1 << Services[x].name();
        if(input.message().contains(p1.string()))  {
            lifestyleSession->ServicesMap[y][x] = 1;
        }
        else  {
            lifestyleSession->ServicesMap[y][x] = 0;
        }

}

        ::lifestyleQueueManager->ArchiveSessionsQueue.put(lifestyleSession);


        if(::log.debug(51))  {
            (message = "") << "updated session: " << lifestyleSession->id();
            ::log << message;
        }

        ::htmlInterface->htmlLifestyleUserMenu.page(*lifestyleSession,page);


    return ERROR_OK;
}


int lifestyleserver_o::htmlinputLoggedinUser(lifestyleSession_o* lifestyleSession,input_o& input,output_o& output)  {
    int x,y;
    string_o message;
    string_o s;
    string_o command;
    string_o page;
    lifestyleItem_o     lifestyleItem;
    int ser;
passcode_o passcode;

    if(::log.debug(71))  {
        (message = "") << "html input loggedin user: " << lifestyleSession->passcode().userid();
        ::log << message;
    }

    command = input.message();
    command.cut("HTTP");

    if(::log.debug(72))  {
        (message = "") << "command `" << command << "'";
        ::log << message;
    }

    for(x=0;x<NumberOfLifestyleItems;x++)  {
        if(command.contains(LifestyleItems[x].name()))  {

            s = command;
            s.upcut('/');
            s.cut('?');
            if(s.contains(LifestyleItems[x].name()))  {
                (void)::htmlInterface->htmlChangeDynamicMenu.page(LifestyleItems[x],*lifestyleSession,page);
                lifestyleSession->setState(x);
                break;
            }
        }
    }


    if(x != NumberOfLifestyleItems)  {}



    else  if(command.contains("ExamineService"))  {
        if(::log.debug(76))  {
            (message = "") << "ExamineService";
            ::log << message;
        }

        s = command;

        s.upcut("::");
        s.upcut("::");
        ser = s.stoi();

        (void)::htmlInterface->htmlExamineService.page(ser,*lifestyleSession,page);
    }


    else  if(command.contains("LifestyleUserMenu"))  {
        if(::log.debug(76))  {
            (message = "") << "LifestyleUserMenu";
            ::log << message;
        }

        (void)::htmlInterface->htmlLifestyleUserMenu.page(*lifestyleSession,page);
    }


    else  if(command.contains("EnterUrgentMessage"))  {
        if(::log.debug(76))  {
            (message = "") << "EnterUrgentMessage";
            ::log << message;
        }

        if(input.message().contains("sendmessage_o.message"))  {
            s = input.message();
            s.upcut("sendmessage_o.message=");
            s.cut('&');
            ::htmlTelluric->unnet(s);
            lifestyleSession->setMessage(s.string());
            lifestyleSession->setMessagePending();

            if(::log.debug(77))  {
                (message = "") << "setting message to: " << s;
                ::log << message;
            }

            ::htmlInterface->htmlThankYou.page(page);
        }
        else  {
            ::htmlInterface->htmlSendMessage.page(*lifestyleSession,page);
        }
    }


    else if(command.contains("SaveLifestyleDynamicMenuChanges"))  {
        changeLifestyleSettings(lifestyleSession,input,page);
    }


    else if(!lifestyleSession->registeredUser())  {


        if(::log.debug(77))  {
            (message = "") << "user is not registered." << s;
            ::log << message;
        }


        if(command.contains("UserLogin"))  {
            (void)::htmlInterface->htmlPleaseRegister.page(*lifestyleSession,page);
        }
        else  if(command.contains("PleaseRegister"))  {
            lifestyleSession->setRegisteredUser();
            (void)::htmlInterface->htmlLifestyleUserMenu.page(*lifestyleSession,page);
        }
        else  {
            (void)::htmlInterface->htmlPleaseRegister.page(*lifestyleSession,page);
        }
    }


    else if(lifestyleSession->registeredUser())  {
        (void)::htmlInterface->htmlLifestyleUserMenu.page(*lifestyleSession,page);
    }


    else  {
        (void)::htmlInterface->htmlChangeDynamicMenu.page(lifestyleItem,*lifestyleSession,page);
    }


    output.setMessage(page);


    return ERROR_OK;
}

int lifestyleserver_o::htmlinput(input_o& input,output_o& output)  {
    int x;
    string_o s,t;
    string_o message;
    string_o page;
    int ser;

    string_o im;
    lifestyleSession_o* lifestyleSession = NULL;
    lifestyleSession_o  lss;
    cacheSearch_o<lifestyleSession_o>* cs;
    passcode_o      passcode;
    datedMessage_o  datedMessage;
    datedMessage_o* datedMessagePointer;


    if(::log.debug(70))  {
        (message = "") << "htmlinput(input_o&,output_o&) Start.";
        ::log << message;
    }
    if(::log.debug(71))  {
        (message = "") << "html input message:\n" << input.message();
        ::log << message;
    }

    im = input.message();
    (void)::htmlTelluric->unnet(im);

    s = PASSCODE_OBJECT;
    s.cut(s.length()-1);

    if(im.contains(s.string()))  {
        s = input.message();

        (void)::htmlTelluric->unnet(s);

        s.upcut(PASSCODE_OBJECT);
        s.transpose("&","\n");
        t << (char)13;
        s.transpose(t.string(),"\n");

        passcode << s.string();

        if(::log.debug(72))  {
            (message = "") << "found pc `" << s << "'";
            ::log << message;
        }

        lifestyleSession = findLifestyleSessionByPasscode(passcode);

    }


    if(lifestyleSession)  {
        return  htmlinputLoggedinUser(lifestyleSession,input,output);
    }



    im = input.message();
    im.cut("HTTP");


    if(im.contains("UserLogin"))  {

        if(::log.debug(76))  {
            (message = "") << "UserLogin, lifestyleSession not found.";
            ::log << message;
        }

        ::htmlInterface->htmlLogin.page(passcode,page);
    }
    else if(im.contains("EmergencyBroadcastingService"))  {
        if(::log.debug(76))  {
            (message = "") << "EmergencyBroadcastingService";
            ::log << message;
        }
        if(input.message().contains("emergencybroadcast.message"))  {
cs = new cacheSearch_o<lifestyleSession_o>(&::lifestyleSessionManager->lifestyleSessions);
if(cs)  {
    lifestyleSession = cs->listhead();
    while(lifestyleSession)  {
        lifestyleSession->setEmergencyBroadcastPending();
        lifestyleSession = cs->listnext();
    }
}
delete cs;
            s = input.message();
            s.upcut("emergencybroadcast.message");
            s.cut('\n');
            ::htmlTelluric->unnet(s);
            s.cut('&');
            if(::log.debug(88))  {
                (message = "") << "Setting Emergency Broadcast to: " << s;
                ::log << message;
            }
            setEmergencyBroadcast(s.string());
            (void)::htmlInterface->htmlLogin.page(passcode,page);
        }
        else  {
            (void)::htmlInterface->htmlEmergencyBroadcastEntry.page(page);
        }
    }

    else if(im.contains("ServerManifest"))  {
        (void)::htmlTelluric->htmlServerManifestPage.page(serverManifest(),page);
    }

    else  if(im.contains("EnterMessage"))  {
        datedMessage.clear();
        datedMessage.setValid(1);
        (void)::htmlInterface->htmlDatedMessageEntry.page(datedMessage,page);
    }

    else  if(im.contains("DatedMessageEntry"))  {
        if(::log.debug(76))  {
            (message = "") << "DatedMessageEntry";
            ::log << message;
        }

        if(input.message().contains("datedMessage_o"))  {

            s = input.message();
            s.upcut("datedMessage_o");
            s.cut('\n');
            ::htmlTelluric->unnet(s);
            s.transpose("&","\n");
            s.reverse();
            s << "o_egasseMdetad\n:o_egasseMdetad";
            s.reverse();

            datedMessage << s.string();

            if(::log.debug(77))  {
                (message = "recv: ");
                datedMessage >> message;
                ::log << message;
            }

            lifestyleSession = findLifestyleSessionByUserid(datedMessage.id());

            if(!lifestyleSession)  {
                if(::log.debug(76))  {
                    (message = "User ") << datedMessage.id() << " not found.";
                    ::log << message;
                }

                datedMessage.setValid(0);
                (void)::htmlInterface->htmlDatedMessageEntry.page(datedMessage,page);
            }
            else  {

                if(::log.debug(78))  {
                    (message = "") << "Dated Message Object sent to " << lifestyleSession->id();
                    ::log << message;
                }

                datedMessagePointer = new datedMessage_o(datedMessage);
                lifestyleSession->SortedDatedMessageQueue.addToQueue(datedMessagePointer);


                (void)::htmlInterface->htmlThankYou.page(page);
            }

        }
        else  {
            (void)::htmlInterface->htmlDatedMessageEntry.page(datedMessage,page);
        }

    }
    else  {
        if(::log.debug(76))  {
            (message = "") << "No command found.";
            ::log << message;
        }

        (void)::htmlInterface->htmlLogin.page(passcode,page);
    }


    (void)output.setMessage(page.string());


    return ERROR_OK;
}

int lifestyleserver_o::messages(lifestyleSession_o& lifestyleSession,string_o& page)  {
    string_o message;


        if(::log.debug(82))  {
            (message = "") << "PDA user " << lifestyleSession.id() << " checking messages.";
            ::log << message;
        }

    (void)::hdmlInterface->hdmlDisplayMessages.page(lifestyleSession,page);


    return ERROR_OK;
}

int lifestyleserver_o::weather(const lifestyleSession_o& lifestyleSession,string_o& page)  {

    string_o message;

    weather_o weather;
    address_o address;

    client_o  client;
    string_o  ss;
    string_o  rs;


    if(lifestyleSession.state() == 0)  {
        address = lifestyleSession.address(0);
    }
    else if(lifestyleSession.state() == 1)  {
        address = lifestyleSession.address(1);
    }
    else  {
        address = lifestyleSession.address(2);
    }


    client.connect("204.131.41.3",13333);
    if(client.error() != ERROR_OK)  {
        (message = "") << "Client connect error.";
        ::log.error(message);
    }

    address >> ss;
    client.send(ss);
    if(client.error() != ERROR_OK)  {
        (message = "") << "Client send error.";
        ::log.error(message);
    }
    if(::log.debug(114))  {
        (message = "") << "Send to weatherserver: " << ss;
        ::log << message;
    }

    ::usleep(2555);

    client.recv(rs);

    if(client.error() != ERROR_OK)  {
        (message = "") << "Client recv error.";
        ::log.error(message);
    }

    client.disconnect();


    if(::log.debug(116))  {
        (message = "") << "Recv from weatherserver: " << rs;
        ::log << message;
    }

    weather << rs.string();



    ::hdmlInterface->hdmlViewWeather.page(address,weather,page);


    return ERROR_OK;
}


int lifestyleserver_o::pdainput(input_o& input,output_o& output)  {
    int            x;
    string_o       s,t;
    string_o       message;
    string_o       page;

    lifestyleSession_o*  lifestyleSession;
    pdaInput_o*    pdaInput;
    output_o*      output2;


    pdaInput = new pdaInput_o(input);
    ::hdmlInterface->parse(*pdaInput);


    lifestyleSession = ::lifestyleSessionManager->findSession(pdaInput->phone());
    if(!lifestyleSession)  {
        lifestyleSession = ::lifestyleSessionManager->newSession(pdaInput->phone());

        lifestyleSession->setMap(Services,LifestyleItems);



        if(::log.debug(88))  {
            (message = "") << "calling method generatePassCode().";
            ::log << message;
        }

        s = "";
        generatePassCode(lifestyleSession->passcode());


        if(::log.debug(82))  {
            (message = "") << "Saving session ";
            message << lifestyleSession->id() << " in Lifestyle Manager.";
            ::log << message;
        }

        ::lifestyleSessionManager->saveSession(lifestyleSession);


        if(::log.debug(83))  {
            (message = "") << "Sending session ";
            message << lifestyleSession->id() << " to Archiver Thread.";
            ::log << message;
        }

        ::lifestyleQueueManager->ArchiveSessionsQueue.put(lifestyleSession);




        if(::log.debug(84))  {
            (message = "") << "Complte new session ";
            message << lifestyleSession->id() << ".";
            ::log << message;
        }

    }
    else  {

        lifestyleSession->incrementTransactions();
        if(::log.debug(51))  {
            (message = "") << ": found session: " << lifestyleSession->id();
            ::log << message;
        }
    }


    if(!lifestyleSession->registeredUser())  {
        (void)::hdmlInterface->hdmlNewUser.page(*lifestyleSession,page);
    }
    else if(lifestyleSession->emergencyBroadcastPending())  {
        lifestyleSession->resetEmergencyBroadcastPending();
        (void)::hdmlInterface->hdmlEmergencyBroadcast.page(*lifestyleSession,page);
    }
    else if(lifestyleSession->messagePending())  {
        lifestyleSession->resetMessagePending();
        (void)::hdmlInterface->hdmlDisplayUrgentMessage.page(*lifestyleSession,page);
    }
    else if(lifestyleSession->registeredUser())  {

        if(0)  {}
        else if(input.message().contains("lifestyleState"))  {
            for(x=0;x<lifestyleSession->numberOfLifestyles();x++)  {
                if(input.message().contains(::lifestyleserver->LifestyleItems[x].Name.string()))  {
                    lifestyleSession->setState(x);
                }
            }
            (void)::hdmlInterface->hdmlLifestyleDynamicMenu.page(*lifestyleSession,page);
        }
        else if(input.message().contains("LifestyleChange"))  {
            (void)::hdmlInterface->hdmlLifestyleChange.page(*lifestyleSession,page);
        }
        else if(input.message().contains("passcode"))  {
            (void)::hdmlInterface->hdmlViewPassCode.page(*lifestyleSession,page);
        }
        else if(input.message().contains("ENTER_MESSAGE"))  {
            (void)::hdmlInterface->hdmlEnterMessage.page(*lifestyleSession,page);
        }
        else if(input.message().contains("ENTERED_MESSAGE"))  {
            (void)::hdmlInterface->hdmlEnterMessage.page(*lifestyleSession,page);
        }
        else if(input.message().contains("ServerManifest"))  {
//            (void)::hdmlTelluric->hdmlServerManifest.page(serverManifest(),page);
        }
        else  {
            s = input.message();
            s.cut("HTTP");
            if(::log.debug(81))  {
                (message = "") << "s: " << lifestyleSession->id();
                message << ": `" << s << "'";
                ::log << message;
            }
            for(x=0;x<NumberOfServices;x++)  {
                if(s.contains(Services[x].name()))  {

                    if(::log.debug(81))  {
                        (message = "") << "session: " << lifestyleSession->id();
                        message << ": " << Services[x].name();
                        ::log << message;
                    }

                    t = Services[x].name();

                    if(s.contains("eather"))  {   //!!!
                        weather(*lifestyleSession,page);
                    }
                    else if(t == "Messages")  {  ///!!!
                        messages(*lifestyleSession,page);
                    }


                    break;

                }
            }
            if(x == NumberOfServices)  {
                (void)::hdmlInterface->hdmlLifestyleDynamicMenu.page(*lifestyleSession,page);
            }
            else if(x != 0)  {
                (void)::hdmlInterface->hdmlLifestyleDynamicMenu.page(*lifestyleSession,page);
            }
        }
    }


    (void)::usleep(4040);


    output2 = new output_o(&input);
    output2->setMessage(page);
    pserver->outputQueue(output2);
    output.setInvalidCode(1); 


    delete pdaInput;


    return ERROR_OK;
}

int lifestyleserver_o::lifestyleIteminput(input_o& input,output_o& output)  {
    string_o message;
    string_o ps(input.message().string());

    if(NumberOfLifestyleItems < LIFESTYLESERVER_MAX_NUMBER_OF_ITEMS)  {

        ps.upcut("lifestyleItem_o:");
        output.setMessage(ps);

        mutex.lock();
            LifestyleItems[NumberOfLifestyleItems] << ps.string();
            NumberOfLifestyleItems++;
        mutex.unlock();

        if(::log.debug(62))  {
            LifestyleItems[NumberOfLifestyleItems-1] >> ps;
            (message = "") << "Added lifestyleItem_o: " << ps;
            ::log << message;
        }
    }


    return ERROR_OK;
}

int lifestyleserver_o::serviceinput(input_o& input,output_o& output)  {
    string_o message;
    string_o ps(input.message().string());

    if(NumberOfServices < LIFESTYLESERVER_MAX_NUMBER_OF_SERVICES)  {

        ps.upcut("service_o:");
        output.setMessage(ps);

        mutex.lock();
            Services[NumberOfServices] << ps.string();
            NumberOfServices++;
        mutex.unlock();

        if(::log.debug(63))  {
            Services[NumberOfServices-1] >> ps;
            (message = "") << "Added service_o: " << ps;
            ::log << message;
        }
    }


    return ERROR_OK;
}

int lifestyleserver_o::rotatingBannerInput(input_o& input,output_o& output)  {
    string_o message;
    string_o ps(input.message().string());
    rotatingBanner_o rotatingBanner;

    ps.upcut("rotatingBanner_o:");
    ps.reverse();
    ps << ":o_rennaBgnitator";
    ps.reverse();
    output.setMessage(ps);

    rotatingBanner << ps.string();

ps = "";
rotatingBanner >> ps;
::log<<ps;

    (void)::htmlInterface->setRotatingBanner(rotatingBanner);
    

    return ERROR_OK;
}

int lifestyleserver_o::entityInput(input_o& input,output_o& output)  {
    string_o message;
    string_o ps(input.message().string());
    entity_o* entity;

    ps.upcut("entity_o:");
    ps.reverse();
    ps << ":o_ytitne";
    ps.reverse();
    output.setMessage(ps);

    entity = new entity_o(ps.string());

    (void)::pserver->setEntity(*entity);

    delete entity;


    return ERROR_OK;
}


int lifestyleserver_o::sessioninput(input_o& input,output_o& output)  {
    string_o message;
    string_o ps(input.message().string());
    lifestyleSession_o* lsp;
    lifestyleSession_o  lifestyleSession;

    if(NumberOfServices < LIFESTYLESERVER_MAX_NUMBER_OF_PATRIONS)  {

        ps.upcut("lifestylesession_o:");
        output.setMessage(ps);

        lifestyleSession << ps.string();

        lsp = ::lifestyleSessionManager->findSession(lifestyleSession.id());
        if(!lsp)  {
            lsp = ::lifestyleSessionManager->newSession(lifestyleSession.id());
            *lsp = lifestyleSession;
            ::lifestyleSessionManager->saveSession(lsp);


            if(::log.debug(51))  {
                (message = "") << ": new session to session manager: ";
                *lsp >> message;
                ::log << message;
            }
        }
        else  {
            mutex.lock();
                *lsp = lifestyleSession;
            mutex.unlock();

            if(::log.debug(51))  {
                (message = "") << ": found session: " << lsp->id();
                ::log << message;
            }
        }

    }



    return ERROR_OK;
}

int lifestyleserver_o::process(input_o& input,output_o& output)  {
    string_o    s;
    string_o    message;


    if(::log.debug(99))  {
        (message = "") << "msg `" << input.message() << "'";
        ::log << message;
    }


    if(input.message().contains("lifestyleItem_o:"))  {
        lifestyleIteminput(input,output);
    }
    else if(input.message().contains("service_o:"))  {
        serviceinput(input,output);
    }
    else if(input.message().contains("lifestyleSession_o:"))  {
        sessioninput(input,output);
    }
    else if(input.message().contains("rotatingBanner_o:"))  {
        rotatingBannerInput(input,output);
    }
    else if(input.message().contains("entity_o:"))  {
        entityInput(input,output);
    }
    else if(input.message().contains("x-up-sub") || input.message().contains("x-UP-SubNo"))  { //!!!!!!!!!!!!
        pdainput(input,output);
    }
    else  {
        htmlinput(input,output);
    }


    mutex.lock();
        NumberProcessed++;
    mutex.unlock();


    return ERROR_OK;
}

int lifestyleserver_o::startup()  {
    return Startup.getAccountsFromRelegateServer(serverManifest());
}

int carapace_o::process(input_o& input,output_o& output)  {
    return lifestyleserver->process(input,output);
}

void sighand(int sig)  {
    string_o message;
    message << "signal: " << sig << " thrown.";
    ::log.error(message);
}

int main(int argc,char* argv[])  {
    int x,y;
    string_o message;
    int rcode;
    int clientport;
    thread_o* athread;
    archiver_o* archiver;
    epi_o* epi;


/**  **************************************************************************/
/******************************************************************************/


    (void)::signal(SIGALRM,sighand);
    (void)::signal(SIGPIPE,sighand);


/**  **************************************************************************/


    ::log.registerName(argv[0]);

    for(x=0;x<1024;x++) ::log.setDebugLevel(x);
    for(x=0;x<200;x++)  ::log.setDebugLevel(x);
    for(x=0;x<100;x++)  ::log.setDebugLevel(x);


/**  **************************************************************************/


    clientport = LIFESTYLESERVER_DEFAULT_USER_PORT;

/**  **************************************************************************/


    x = 1;
    while(x<argc)  {
        if(*argv[x] == '-' && *(argv[x]+1) == 'p')  {
            x++;
            y = atoi(argv[x]);
            if(y > 1 && y < 65534)  clientport = y;
            else  {
                (message = "") << "Unable to use '" << argv[x];
                message << "' as port.";
                ::log.error(message);
            }
        }
    }



/**  **************************************************************************/
/******************************************************************************/


    athread = new thread_o(888,"Archiver Thread");
    if(!athread)  {
        (void)::log.error("new thread_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(2))  ::log << "Instanciated Archiver Thread.";

    archiver = new archiver_o(*athread);
    if(!archiver)  {
        (void)::log.error("new archiver_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(2))  ::log << "Instanciated Archiver Object.";



    athread = new thread_o(889,"EPI Thread");
    if(!athread)  {
        (void)::log.error("new thread_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(3))  ::log << "Instanciated EPI Thread.";

    epi = new epi_o(*athread);
    if(!epi)  {
        (void)::log.error("new epi_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(3))  ::log << "Instanciated EPI Object.";



/**  **************************************************************************/


    ::htmlTelluric = new htmlTelluric_o();
    if(!::htmlTelluric)  {
        (void)::log.error("new htmlTelluric_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(4))  ::log << "Instanciated the HTML Telluric Object.";


    ::htmlInterface = new htmlInterface_o();
    if(!::htmlInterface)  {
        (void)::log.error("new htmlInterface_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(4))  ::log << "Instanciated the HTML Interface Object.";


    ::hdmlInterface = new hdmlInterface_o();
    if(!::hdmlInterface)  {
        (void)::log.error("new hdmlInterface_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(4))  ::log << "Instanciated the HDML Interface Object.";




/**  **************************************************************************/


    ::lifestyleSessionManager = new lifestyleSessionManager_o;
    if(!::lifestyleSessionManager)  {
        (void)::log.error("new lifestyleSessionManager_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(6))  ::log << "Instanciated the lifestyleSessionManager_o Object.";


    ::lifestyleQueueManager = new lifestyleQueueManager_o;
    if(!::lifestyleQueueManager)  {
        (void)::log.error("new lifestyleQueueManager_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(6))  ::log << "Instanciated the lifestyleQueueManager_o Object.";



/**  **************************************************************************/


    ::lifestyleserver = new lifestyleserver_o();
    if(!::lifestyleserver)  {
        (void)::log.error("new lifestyleserver_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(7))  ::log << "Instanciated the lifestyleserver_o Object.";



    ::pserver = new pserver_o();
    if(!::pserver)  {
        (void)::log.error("new pserver_o returned null.");
        return ERROR_NULL_PASSED;
    }
    if(::log.debug(8))  ::log << "Instanciated the pserver_o Object.";


/**  **************************************************************************/
/******************************************************************************/


    (void)::lifestyleserver->startup();


/**  **************************************************************************/
/******************************************************************************/


 
    archiver->start((::startarchiver),archiver);


/**  **************************************************************************/
/******************************************************************************/

    rcode = ::pserver->serveport(clientport);
//  while(rcode != ERROR_OK)  {
//      ::sleep(10);
//      rcode = ::pserver->serveport(clientport);
//  }


/**  **************************************************************************/
/******************************************************************************/
    (void)::pserver->persist();

/**  **************************************************************************/
/******************************************************************************/

    return ERROR_OK;
}


/******************************************************************************/

