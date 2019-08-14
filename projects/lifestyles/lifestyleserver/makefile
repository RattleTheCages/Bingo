################################################################################
################################################################################
##                                                                            ##
##  Lifestyle Server v0.2000             12.31.99    Daniel Huffman           ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##    Please note.  The header file dependences are not complete in this      ##
##    makefile.  If any changes are made to header files, please `make clean' ##
##    before executing `make all'.                                            ##
##                                                                            ##
################################################################################
################################################################################


# Use the complier that is POSIX threads enabled.
CC          = /opt/SUNWspro/bin/CC

OBJFLAGS    = -g -D_REENTRANT
LINKFLAGS   = -lpthread -lthread -lsocket -D_REENTRANT


LF_BASE_DIR             = /home/dhuffman/del/projects/
LF_LIB_DIR              = $(LF_BASE_DIR)/library/
LF_CONTAINER_DIR        = $(LF_BASE_DIR)/lifestyles/containers/
LF_DYNAMICCONTAINER_DIR = $(LF_BASE_DIR)/lifestyles/dynamicContainers/
LF_MANAGER_DIR          = $(LF_BASE_DIR)/lifestyles/lifestyleserver/managers/
LF_HDML_DIR             = $(LF_BASE_DIR)/lifestyles/lifestyleserver/hdml/
LF_HTML_DIR             = $(LF_BASE_DIR)/lifestyles/lifestyleserver/html/
LF_TELL_HTML_DIR        = $(LF_BASE_DIR)/lifestyles/html/
LF_SERVERS_DIR          = $(LF_BASE_DIR)/lifestyles/lifestyleserver/servers/
LF_PROCESS_DIR          = $(LF_BASE_DIR)/lifestyles/lifestyleserver/process/
LF_THREADS_DIR          = $(LF_BASE_DIR)/lifestyles/lifestyleserver/threads/


LF_CONTAINER_OBJS       = pdaInput.o  address.o  weather.o  service.o          \
                          lifestyleItem.o  serverManifest.o  datedMessage.o    \
                          passcode.o actdate.o rotatingBanner.o
LF_DYNAMICCONTAINER_OBJS= sortedDatedMessageQueue.o  lifestyleSession.o
LF_THREAD_OBJS          = mutex.o  thread.o
LF_MANAGER_OBJS         = lifestyleSessionManager.o  lifestyleQueueManager.o
LF_PROCESS_OBJS         = startup.o  htmlinput.o
LF_THREADS_OBJS         = archiver.o  epi.o
LF_HDML_OBJS            = hdmlInterface.o  hdmlServerHeader.o  hdmlNewUser.o   \
                          hdmlViewWeather.o  hdmlWeatherContainerDisplay.o     \
                          hdmlLifestyleChange.o  hdmlLifestyleDynamicMenu.o    \
                          hdmlEmergencyBroadcast.o  hdmlViewPassCode.o         \
                          hdmlDisplayUrgentMessage.o  hdmlDisplayMessages.o    \
                          hdmlEnterMessage.o
LF_HTML_OBJS            = htmlInterface.o  htmlLogin.o  htmlNewSettings.o      \
                          htmlThankYou.o  htmlEmergencyBroadcastEntry.o        \
                          htmlLifestyleUserMenu.o  htmlSendMessage.o           \
                          htmlExamineService.o  htmlDatedMessageEntry.o        \
                          htmlSideMenu.o  htmlSideMenuLoggedin.o               \
                          htmlStencil.o htmlChangeDynamicMenu.o                \
                          htmlPleaseRegister.o
LF_TELL_HTML_OBJS       = htmlTelluric.o  htmlServerManifestPage.o             \
                          htmlDisplayServerManifest.o                          \
                          htmlDisplayServerManifestContainer.o


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Building Lifestyle Server v0.2000"
	@echo `date`
	@make allsub

allsub: lifestyleserver
	@echo "Lifestyle Server v0.2000 Build Complete."
	@echo `date`


################################################################################
## Container Objects.                                                         ##
################################################################################
pdaInput.o: $(LF_CONTAINER_DIR)pdaInput.h $(LF_CONTAINER_DIR)pdaInput.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)pdaInput.cc

passcode.o: $(LF_CONTAINER_DIR)passcode.h $(LF_CONTAINER_DIR)passcode.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)passcode.cc

lifestyleItem.o: $(LF_CONTAINER_DIR)lifestyleItem.h \
                $(LF_CONTAINER_DIR)lifestyleItem.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)lifestyleItem.cc

address.o: $(LF_CONTAINER_DIR)address.h \
                $(LF_CONTAINER_DIR)address.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)address.cc

weather.o: $(LF_CONTAINER_DIR)weather.h \
                $(LF_CONTAINER_DIR)weather.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)weather.cc

service.o: $(LF_CONTAINER_DIR)service.h \
                $(LF_CONTAINER_DIR)service.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)service.cc

serverManifest.o: $(LF_CONTAINER_DIR)serverManifest.h \
                $(LF_CONTAINER_DIR)serverManifest.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)serverManifest.cc

datedMessage.o: $(LF_CONTAINER_DIR)datedMessage.h \
                $(LF_CONTAINER_DIR)datedMessage.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)datedMessage.cc

actdate.o: $(LF_CONTAINER_DIR)actdate.h \
                $(LF_CONTAINER_DIR)actdate.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)actdate.cc

rotatingBanner.o: $(LF_CONTAINER_DIR)rotatingBanner.h \
                $(LF_CONTAINER_DIR)rotatingBanner.cc
	$(CC) $(OBJFLAGS) -c $(LF_CONTAINER_DIR)rotatingBanner.cc


################################################################################
## Dynamic Container Objects.                                                 ##
################################################################################
sortedDatedMessageQueue.o: $(LF_DYNAMICCONTAINER_DIR)sortedDatedMessageQueue.h \
                           $(LF_DYNAMICCONTAINER_DIR)sortedDatedMessageQueue.cc
	$(CC) $(OBJFLAGS) -c $(LF_DYNAMICCONTAINER_DIR)sortedDatedMessageQueue.cc

lifestyleSession.o: $(LF_DYNAMICCONTAINER_DIR)lifestyleSession.h               \
                    $(LF_DYNAMICCONTAINER_DIR)lifestyleSession.cc
	$(CC) $(OBJFLAGS) -c $(LF_DYNAMICCONTAINER_DIR)lifestyleSession.cc



################################################################################
## Thread Objects.                                                            ##
################################################################################
archiver.o: $(LF_THREADS_DIR)archiver.h $(LF_THREADS_DIR)archiver.cc
	$(CC) $(OBJFLAGS) -c $(LF_THREADS_DIR)archiver.cc

epi.o: $(LF_THREADS_DIR)epi.h $(LF_THREADS_DIR)epi.cc
	$(CC) $(OBJFLAGS) -c $(LF_THREADS_DIR)epi.cc


################################################################################
## Process Objects.                                                           ##
################################################################################
startup.o: $(LF_PROCESS_DIR)startup.h $(LF_PROCESS_DIR)startup.cc
	$(CC) $(OBJFLAGS) -c $(LF_PROCESS_DIR)startup.cc

htmlinput.o: $(LF_PROCESS_DIR)htmlinput.h $(LF_PROCESS_DIR)htmlinput.cc
	$(CC) $(OBJFLAGS) -c $(LF_PROCESS_DIR)htmlinput.cc


################################################################################
## Manager Objects.                                                           ##
################################################################################
lifestyleSessionManager.o: $(LF_MANAGER_DIR)lifestyleSessionManager.h \
                $(LF_MANAGER_DIR)lifestyleSessionManager.cc
	$(CC) $(OBJFLAGS) -c $(LF_MANAGER_DIR)lifestyleSessionManager.cc

lifestyleQueueManager.o: $(LF_MANAGER_DIR)lifestyleQueueManager.h \
                $(LF_MANAGER_DIR)lifestyleQueueManager.cc
	$(CC) $(OBJFLAGS) -c $(LF_MANAGER_DIR)lifestyleQueueManager.cc


################################################################################
## HTML Objects.                                                              ##
################################################################################
htmlInterface.o: $(LF_HTML_DIR)htmlInterface.h \
                 $(LF_HTML_DIR)htmlInterface.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlInterface.cc

htmlLogin.o: $(LF_HTML_DIR)htmlLogin.h \
                 $(LF_HTML_DIR)htmlLogin.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlLogin.cc

htmlNewSettings.o: $(LF_HTML_DIR)htmlNewSettings.h \
                 $(LF_HTML_DIR)htmlNewSettings.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlNewSettings.cc

htmlServerHeader.o: $(LF_HTML_DIR)htmlServerHeader.h \
                 $(LF_HTML_DIR)htmlServerHeader.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlServerHeader.cc

htmlThankYou.o: $(LF_HTML_DIR)htmlThankYou.h \
                 $(LF_HTML_DIR)htmlThankYou.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlThankYou.cc

htmlStencil.o: $(LF_HTML_DIR)htmlStencil.h \
                 $(LF_HTML_DIR)htmlStencil.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlStencil.cc

htmlSideMenu.o: $(LF_HTML_DIR)htmlSideMenu.h \
                 $(LF_HTML_DIR)htmlSideMenu.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlSideMenu.cc

htmlSideMenuLoggedin.o: $(LF_HTML_DIR)htmlSideMenuLoggedin.h \
                 $(LF_HTML_DIR)htmlSideMenuLoggedin.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlSideMenuLoggedin.cc

htmlEmergencyBroadcastEntry.o: $(LF_HTML_DIR)htmlEmergencyBroadcastEntry.h \
                 $(LF_HTML_DIR)htmlEmergencyBroadcastEntry.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlEmergencyBroadcastEntry.cc

htmlLifestyleUserMenu.o: $(LF_HTML_DIR)htmlLifestyleUserMenu.h $(LF_HTML_DIR)htmlLifestyleUserMenu.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlLifestyleUserMenu.cc

htmlSendMessage.o: $(LF_HTML_DIR)htmlSendMessage.h $(LF_HTML_DIR)htmlSendMessage.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlSendMessage.cc

htmlExamineService.o:  $(LF_HTML_DIR)htmlExamineService.h \
 $(LF_HTML_DIR)htmlExamineService.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlExamineService.cc

htmlDatedMessageEntry.o:  $(LF_HTML_DIR)htmlDatedMessageEntry.h \
 $(LF_HTML_DIR)htmlDatedMessageEntry.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlDatedMessageEntry.cc

htmlChangeDynamicMenu.o:  $(LF_HTML_DIR)htmlChangeDynamicMenu.h \
 $(LF_HTML_DIR)htmlChangeDynamicMenu.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlChangeDynamicMenu.cc

htmlPleaseRegister.o:  $(LF_HTML_DIR)htmlPleaseRegister.h \
 $(LF_HTML_DIR)htmlPleaseRegister.cc
	$(CC) $(OBJFLAGS) -c $(LF_HTML_DIR)htmlPleaseRegister.cc


################################################################################
## Telluric HTML Objects.                                                     ##
################################################################################
htmlTelluric.o: $(LF_TELL_HTML_DIR)htmlTelluric.h \
 $(LF_TELL_HTML_DIR)htmlTelluric.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlTelluric.cc

htmlServerManifestPage.o: $(LF_TELL_HTML_DIR)htmlServerManifestPage.h \
 $(LF_TELL_HTML_DIR)htmlServerManifestPage.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlServerManifestPage.cc

htmlDisplayServerManifestContainer.o:  $(LF_TELL_HTML_DIR)htmlDisplayServerManifestContainer.h \
 $(LF_TELL_HTML_DIR)htmlDisplayServerManifestContainer.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlDisplayServerManifestContainer.cc

htmlDisplayServerManifest.o:  $(LF_TELL_HTML_DIR)htmlDisplayServerManifest.h \
 $(LF_TELL_HTML_DIR)htmlDisplayServerManifest.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlDisplayServerManifest.cc



################################################################################
## HDML Objects.                                                              ##
################################################################################
hdmlInterface.o: $(LF_HDML_DIR)hdmlInterface.h \
                 $(LF_HDML_DIR)hdmlInterface.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlInterface.cc

hdmlViewAccount.o: $(LF_HDML_DIR)hdmlViewAccount.h \
                   $(LF_HDML_DIR)hdmlViewAccount.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlViewAccount.cc

hdmlClosed.o: $(LF_HDML_DIR)hdmlClosed.h $(LF_HDML_DIR)hdmlClosed.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlClosed.cc

hdmlNewUser.o: $(LF_HDML_DIR)hdmlNewUser.h $(LF_HDML_DIR)hdmlNewUser.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlNewUser.cc

hdmlViewWeather.o: $(LF_HDML_DIR)hdmlViewWeather.h $(LF_HDML_DIR)hdmlViewWeather.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlViewWeather.cc

hdmlWeatherContainerDisplay.o: $(LF_HDML_DIR)hdmlWeatherContainerDisplay.h $(LF_HDML_DIR)hdmlWeatherContainerDisplay.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlWeatherContainerDisplay.cc

hdmlLifestyleChange.o: $(LF_HDML_DIR)hdmlLifestyleChange.h       \
                       $(LF_HDML_DIR)hdmlLifestyleChange.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlLifestyleChange.cc

hdmlWork.o: $(LF_HDML_DIR)hdmlWork.h $(LF_HDML_DIR)hdmlWork.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlWork.cc

hdmlLifestyleDynamicMenu.o: $(LF_HDML_DIR)hdmlLifestyleDynamicMenu.h $(LF_HDML_DIR)hdmlLifestyleDynamicMenu.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlLifestyleDynamicMenu.cc

hdmlEmergencyBroadcast.o: $(LF_HDML_DIR)hdmlEmergencyBroadcast.h   \
                          $(LF_HDML_DIR)hdmlEmergencyBroadcast.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlEmergencyBroadcast.cc

hdmlViewPassCode.o: $(LF_HDML_DIR)hdmlViewPassCode.h $(LF_HDML_DIR)hdmlViewPassCode.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlViewPassCode.cc

hdmlDisplayUrgentMessage.o: $(LF_HDML_DIR)hdmlDisplayUrgentMessage.h  \
                            $(LF_HDML_DIR)hdmlDisplayUrgentMessage.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlDisplayUrgentMessage.cc

hdmlServerHeader.o: $(LF_HDML_DIR)hdmlServerHeader.h \
                    $(LF_HDML_DIR)hdmlServerHeader.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlServerHeader.cc

hdmlDisplayMessages.o: $(LF_HDML_DIR)hdmlDisplayMessages.h \
                    $(LF_HDML_DIR)hdmlDisplayMessages.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlDisplayMessages.cc

hdmlEnterMessage.o: $(LF_HDML_DIR)hdmlEnterMessage.h \
                    $(LF_HDML_DIR)hdmlEnterMessage.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlEnterMessage.cc


################################################################################
## Server Objects.                                                            ##
################################################################################
lifestyleserver.o: $(LF_SERVERS_DIR)lifestyleserver.cc \
                   $(LF_SERVERS_DIR)lifestyleserver.h
	$(CC) $(OBJFLAGS) -c $(LF_SERVERS_DIR)lifestyleserver.cc


################################################################################
## Build the Lifestyle Server v0.2000 executable                              ##
################################################################################
lifestyleserver:                                                               \
               $(LF_CONTAINER_OBJS)                                            \
               $(LF_DYNAMICCONTAINER_OBJS)                                     \
               lifestyleserver.o                                               \
               $(LF_HTML_OBJS)                                                 \
               $(LF_TELL_HTML_OBJS)                                            \
               $(LF_HDML_OBJS)                                                 \
               $(LF_THREADS_OBJS)                                              \
               $(LF_PROCESS_OBJS)                                              \
               $(LF_MANAGER_OBJS)
	$(CC) $(LINKFLAGS)                                                     \
               $(LF_CONTAINER_OBJS)                                            \
               $(LF_DYNAMICCONTAINER_OBJS)                                     \
               lifestyleserver.o                                               \
               $(LF_HTML_OBJS)                                                 \
               $(LF_TELL_HTML_OBJS)                                            \
               $(LF_HDML_OBJS)                                                 \
               $(LF_THREADS_OBJS)                                              \
               $(LF_PROCESS_OBJS)                                              \
               $(LF_MANAGER_OBJS)                                              \
               $(LF_LIB_DIR)/lib/*.o                                           \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                              \
               $(LF_LIB_DIR)/pserver/*.o                                       \
               $(LF_LIB_DIR)/pserver/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/sserver/server.o                                  \
               $(LF_LIB_DIR)/sserver/sendrecv.o                                \
               $(LF_LIB_DIR)/sserver/input.o                                   \
               $(LF_LIB_DIR)/sserver/output.o                                  \
               $(LF_LIB_DIR)/sserver/client.o                                  \
               $(LF_LIB_DIR)/genetic/*.o                                       \
	       -o ../executables/lifestyleserver


################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	@echo "Cleaning Lifestyle Servers v0.2000 build."
	rm -f core *.core
	rm -f del log d
	rm -f *.o
	rm -f -r ./Templates.DB
	rm -f ../executables/lifestyleserver
	@echo "Done cleaning Lifestyle Servers build."


################################################################################
################################################################################
