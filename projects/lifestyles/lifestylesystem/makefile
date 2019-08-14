################################################################################
################################################################################
##                                                                            ##
##  Makefile for Lifestyle System Servers 0.024                    12.4.99    ##
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
LF_TELL_HTML_DIR        = $(LF_BASE_DIR)/lifestyles/html/
LF_SERVERS_DIR          = $(LF_BASE_DIR)/lifestyles/lifestylesystem/servers/
LF_PROCESS_DIR          = $(LF_BASE_DIR)/lifestyles/lifestylesystem/process/
LF_THREADS_DIR          = $(LF_BASE_DIR)/lifestyles/lifestylesystem/threads/


LF_THREAD_OBJS          = mutex.o thread.o
LF_MANAGER_OBJS         = lifestyleSessionManager.o lifestyleQueueManager.o
LF_PROCESS_OBJS         = startup.o htmlinput.o sortedDatedMessageQueue.o \
                          lifestyleSession.o
LF_THREADS_OBJS         = archiver.o api.o
LF_CONTAINER_OBJS       = pdaInput.o address.o weather.o \
                          service.o lifestyleItem.o serverManifest.o        \
                          datedMessage.o passcode.o actdate.o
LF_DYNAMICCONTAINER_OBJS= lifestyleSession.o sortedDatedMessageQueue.o
LF_HDML_OBJS            = hdmlInterface.o


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Building Lifestyle Systems Servers 0.024"
	@echo `date`
	@make allsub

allsub: archiveserver relegateserver passcodeserver imageserver
	@echo "Lifestyle System Servers 0.024 Build Completed."
	@echo `date`


################################################################################
## Dynamic Container Objects.                                                 ##
################################################################################
lifestyleSession.o: $(LF_DYNAMICCONTAINER_DIR)lifestyleSession.h               \
                    $(LF_DYNAMICCONTAINER_DIR)lifestyleSession.cc
	$(CC) $(OBJFLAGS) -c $(LF_DYNAMICCONTAINER_DIR)lifestyleSession.cc

sortedDatedMessageQueue.o: $(LF_DYNAMICCONTAINER_DIR)sortedDatedMessageQueue.h \
                           $(LF_DYNAMICCONTAINER_DIR)sortedDatedMessageQueue.cc
	$(CC) $(OBJFLAGS) -c $(LF_DYNAMICCONTAINER_DIR)sortedDatedMessageQueue.cc


################################################################################
## Thread Objects.                                                           ##
################################################################################
archiver.o: $(LF_THREADS_DIR)archiver.h $(LF_THREADS_DIR)archiver.cc
	$(CC) $(OBJFLAGS) -c $(LF_THREADS_DIR)archiver.cc

api.o: $(LF_THREADS_DIR)api.h $(LF_THREADS_DIR)api.cc
	$(CC) $(OBJFLAGS) -c $(LF_THREADS_DIR)api.cc


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


################################################################################
## HDML Objects.                                                              ##
################################################################################
hdmlInterface.o: $(LF_HDML_DIR)hdmlInterface.h \
                 $(LF_HDML_DIR)hdmlInterface.cc
	$(CC) $(OBJFLAGS) -c $(LF_HDML_DIR)hdmlInterface.cc


################################################################################
## Telluric HTML Objects.                                                     ##
################################################################################
htmlTelluric.o: $(LF_TELL_HTML_DIR)htmlTelluric.h \
 $(LF_TELL_HTML_DIR)htmlTelluric.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlTelluric.cc

htmlServerManifestPage.o: $(LF_TELL_HTML_DIR)htmlServerManifestPage.h \
 $(LF_TELL_HTML_DIR)htmlServerManifestPage.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlServerManifestPage.cc

htmlDisplayServerManifestContainer.o:  \
    $(LF_TELL_HTML_DIR)htmlDisplayServerManifestContainer.h \
 $(LF_TELL_HTML_DIR)htmlDisplayServerManifestContainer.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlDisplayServerManifestContainer.cc

htmlDisplayServerManifest.o:  $(LF_TELL_HTML_DIR)htmlDisplayServerManifest.h \
 $(LF_TELL_HTML_DIR)htmlDisplayServerManifest.cc
	$(CC) $(OBJFLAGS) -c $(LF_TELL_HTML_DIR)htmlDisplayServerManifest.cc


################################################################################
## Server Objects.                                                            ##
################################################################################
archiveserver.o: $(LF_SERVERS_DIR)archiveserver.cc \
                 $(LF_SERVERS_DIR)archiveserver.h
	$(CC) $(OBJFLAGS) -c $(LF_SERVERS_DIR)archiveserver.cc

relegateserver.o: $(LF_SERVERS_DIR)relegateserver.cc \
                 $(LF_SERVERS_DIR)relegateserver.h
	$(CC) $(OBJFLAGS) -c $(LF_SERVERS_DIR)relegateserver.cc

passcodeserver.o: $(LF_SERVERS_DIR)passcodeserver.cc \
                 $(LF_SERVERS_DIR)passcodeserver.h
	$(CC) $(OBJFLAGS) -c $(LF_SERVERS_DIR)passcodeserver.cc

imageserver.o: $(LF_SERVERS_DIR)imageserver.cc \
                 $(LF_SERVERS_DIR)imageserver.h
	$(CC) $(OBJFLAGS) -c $(LF_SERVERS_DIR)imageserver.cc


################################################################################
## Build the Lifestyle System Server 0.024 servers!                           ##
################################################################################
archiveserver:                                                                 \
               $(LF_CONTAINER_OBJS)                                            \
               $(LF_DYNAMICCONTAINER_OBJS)                                     \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               archiveserver.o
	$(CC) $(LINKFLAGS)                                                     \
               $(LF_CONTAINER_OBJS)                                            \
               $(LF_DYNAMICCONTAINER_OBJS)                                     \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               $(LF_LIB_DIR)/lib/*.o                                           \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                              \
               $(LF_LIB_DIR)/pserver/*.o                                       \
               $(LF_LIB_DIR)/pserver/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/sserver/server.o                                  \
               $(LF_LIB_DIR)/sserver/sendrecv.o                                \
               $(LF_LIB_DIR)/sserver/input.o                                   \
               $(LF_LIB_DIR)/sserver/output.o                                  \
               $(LF_LIB_DIR)/sserver/client.o                                  \
               archiveserver.o                                                 \
	       -o ../executables/archiveserver


relegateserver:                                                            \
               $(LF_CONTAINER_OBJS)                                        \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               relegateserver.o
	$(CC) $(LINKFLAGS)                                                 \
               $(LF_CONTAINER_OBJS)                                        \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               $(LF_LIB_DIR)/lib/*.o                                       \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/pserver/*.o                                   \
               $(LF_LIB_DIR)/pserver/Templates.DB/*.o                      \
               $(LF_LIB_DIR)/sserver/server.o                              \
               $(LF_LIB_DIR)/sserver/sendrecv.o                            \
               $(LF_LIB_DIR)/sserver/input.o                               \
               $(LF_LIB_DIR)/sserver/output.o                              \
               $(LF_LIB_DIR)/sserver/client.o                              \
               relegateserver.o                                         \
	       -o ../executables/relegateserver


passcodeserver:                                                             \
               $(LF_CONTAINER_OBJS)                                        \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               passcodeserver.o
	$(CC) $(LINKFLAGS)                                                 \
               $(LF_CONTAINER_OBJS)                                        \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               $(LF_LIB_DIR)/lib/*.o                                       \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/pserver/*.o                                   \
               $(LF_LIB_DIR)/pserver/Templates.DB/*.o                      \
               $(LF_LIB_DIR)/sserver/server.o                              \
               $(LF_LIB_DIR)/sserver/sendrecv.o                            \
               $(LF_LIB_DIR)/sserver/input.o                               \
               $(LF_LIB_DIR)/sserver/output.o                              \
               $(LF_LIB_DIR)/sserver/client.o                              \
               passcodeserver.o                                         \
	       -o ../executables/passcodeserver


imageserver:                                                             \
               $(LF_CONTAINER_OBJS)                                        \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               imageserver.o
	$(CC) $(LINKFLAGS)                                                 \
               $(LF_CONTAINER_OBJS)                                        \
               htmlTelluric.o \
               htmlDisplayServerManifest.o \
               htmlDisplayServerManifestContainer.o \
               htmlServerManifestPage.o \
               $(LF_LIB_DIR)/lib/*.o                                       \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/pserver/*.o                                   \
               $(LF_LIB_DIR)/pserver/Templates.DB/*.o                      \
               $(LF_LIB_DIR)/sserver/server.o                              \
               $(LF_LIB_DIR)/sserver/sendrecv.o                            \
               $(LF_LIB_DIR)/sserver/input.o                               \
               $(LF_LIB_DIR)/sserver/output.o                              \
               $(LF_LIB_DIR)/sserver/client.o                              \
               imageserver.o                                         \
	       -o ../executables/imageserver


################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	@echo "Cleaning"
	rm -f *.o
	rm -f core *.core
	rm -f del log
	rm -f make.log d
	rm -f -r ./Templates.DB
	rm -f ../executables/archiveserver ../executables/relegateserver
	rm -f ../executables/passcodeserver


################################################################################
################################################################################
