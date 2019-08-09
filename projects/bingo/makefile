################################################################################
################################################################################
##                                                                            ##
##  Makefile for bingo 0.008                                       9.19.99    ##
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
LINKFLAGS   = -lpthread -lsocket -D_REENTRANT


#BG_LIB_DIR              = /home/dhuffman/projects/library/
#BG_MANAGER_DIR          = /home/dhuffman/projects/bingo/managers/
#BG_CONTAINER_DIR        = /home/dhuffman/projects/bingo/containers/
#BG_HDML_DIR             = /home/dhuffman/projects/bingo/hdml/
#BG_SERVERS_DIR          = /home/dhuffman/projects/bingo/servers/
#BG_PROCESS_DIR          = /home/dhuffman/projects/bingo/process/
#BG_CLIENTS_DIR          = /home/dhuffman/projects/bingo/clients/

BG_LIB_DIR              = /home/dhuffman/del/projects/library/
BG_MANAGER_DIR          = /home/dhuffman/del/projects/bingo/managers/
BG_CONTAINER_DIR        = /home/dhuffman/del/projects/bingo/containers/
BG_HDML_DIR             = /home/dhuffman/del/projects/bingo/hdml/
BG_HTML_DIR             = /home/dhuffman/del/projects/bingo/html/
BG_SERVERS_DIR          = /home/dhuffman/del/projects/bingo/servers/
BG_PROCESS_DIR          = /home/dhuffman/del/projects/bingo/process/
BG_CLIENTS_DIR          = /home/dhuffman/del/projects/bingo/clients/


BG_THREAD_OBJS          = mutex.o thread.o
BG_MANAGER_OBJS         = bingoSessionManager.o
BG_CONTAINER_OBJS       = bingoball.o bingogame.o bingocard.o       \
                          pdaInput.o bingoSession.o pitbossui.o       \
                          gameRequest.o
BG_HDML_OBJS            = hdmlInterface.o hdmlMenu.o hdmlJoinGame.o     \
                          hdmlViewAccount.o hdmlViewCards.o             \
                          hdmlInProgress.o hdmlGame.o hdmlClosed.o   \
                          hdmlBingo.o hdmlTakingBets.o 
BG_HTML_OBJS            = htmlInterface.o htmlMenu.o hdmlJoinGame.o
BG_PROCESS_OBJS         = bingo.o


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Building Bingo 0.008"
	@echo `date`
	@make allsub

allsub: bingodealer bingocaller pitboss pdaclient client bingocardserver
	@echo "Bingo 0.008 Build Completed."
	@echo `date`


################################################################################
## Manager Objects.                                                           ##
################################################################################
bingoSessionManager.o: $(BG_MANAGER_DIR)bingoSessionManager.h \
                $(BG_MANAGER_DIR)bingoSessionManager.cc
	$(CC) $(OBJFLAGS) -c $(BG_MANAGER_DIR)bingoSessionManager.cc


################################################################################
## Container Objects.                                                         ##
################################################################################
bingoball.o: $(BG_CONTAINER_DIR)bingoball.h $(BG_CONTAINER_DIR)bingoball.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)bingoball.cc

bingogame.o: $(BG_CONTAINER_DIR)bingogame.h $(BG_CONTAINER_DIR)bingogame.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)bingogame.cc

bingocard.o: $(BG_CONTAINER_DIR)bingocard.h $(BG_CONTAINER_DIR)bingocard.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)bingocard.cc

pdaInput.o: $(BG_CONTAINER_DIR)pdaInput.h $(BG_CONTAINER_DIR)pdaInput.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)pdaInput.cc

bingoSession.o: $(BG_CONTAINER_DIR)bingoSession.h \
                $(BG_CONTAINER_DIR)bingoSession.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)bingoSession.cc

pitbossui.o: $(BG_CONTAINER_DIR)pitbossui.h $(BG_CONTAINER_DIR)pitbossui.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)pitbossui.cc

gameRequest.o: $(BG_CONTAINER_DIR)gameRequest.h \
               $(BG_CONTAINER_DIR)gameRequest.cc
	$(CC) $(OBJFLAGS) -c $(BG_CONTAINER_DIR)gameRequest.cc


################################################################################
## HTML Objects.                                                              ##
################################################################################
htmlInterface.o: $(BG_HTML_DIR)htmlInterface.h \
                 $(BG_HTML_DIR)htmlInterface.cc
	$(CC) $(OBJFLAGS) -c $(BG_HTML_DIR)htmlInterface.cc


htmlMenu.o: $(BG_HTML_DIR)htmlMenu.h \
                 $(BG_HTML_DIR)htmlMenu.cc
	$(CC) $(OBJFLAGS) -c $(BG_HTML_DIR)htmlMenu.cc


################################################################################
## HDML Objects.                                                              ##
################################################################################
hdmlInterface.o: $(BG_HDML_DIR)hdmlInterface.h \
                 $(BG_HDML_DIR)hdmlInterface.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlInterface.cc

hdmlMenu.o: $(BG_HDML_DIR)hdmlMenu.h $(BG_HDML_DIR)hdmlMenu.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlMenu.cc

hdmlJoinGame.o: $(BG_HDML_DIR)hdmlJoinGame.h $(BG_HDML_DIR)hdmlJoinGame.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlJoinGame.cc

hdmlViewAccount.o: $(BG_HDML_DIR)hdmlViewAccount.h \
                   $(BG_HDML_DIR)hdmlViewAccount.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlViewAccount.cc

hdmlViewCards.o: $(BG_HDML_DIR)hdmlViewCards.h $(BG_HDML_DIR)hdmlViewCards.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlViewCards.cc

hdmlInProgress.o: $(BG_HDML_DIR)hdmlInProgress.h $(BG_HDML_DIR)hdmlInProgress.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlInProgress.cc

hdmlGame.o: $(BG_HDML_DIR)hdmlGame.h $(BG_HDML_DIR)hdmlGame.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlGame.cc

hdmlClosed.o: $(BG_HDML_DIR)hdmlClosed.h $(BG_HDML_DIR)hdmlClosed.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlClosed.cc

hdmlBingo.o: $(BG_HDML_DIR)hdmlBingo.h $(BG_HDML_DIR)hdmlBingo.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlBingo.cc

hdmlTakingBets.o: $(BG_HDML_DIR)hdmlTakingBets.h    \
                  $(BG_HDML_DIR)hdmlTakingBets.cc
	$(CC) $(OBJFLAGS) -c $(BG_HDML_DIR)hdmlTakingBets.cc


################################################################################
## Process Objects.                                                           ##
################################################################################
bingo.o: $(BG_PROCESS_DIR)bingo.cc $(BG_PROCESS_DIR)bingo.h
	$(CC) $(OBJFLAGS) -c $(BG_PROCESS_DIR)bingo.cc


################################################################################
## Server Objects.                                                            ##
################################################################################
bingodealer.o: $(BG_SERVERS_DIR)bingodealer.cc
	$(CC) $(OBJFLAGS) -c $(BG_SERVERS_DIR)bingodealer.cc

bingocardserver.o: $(BG_SERVERS_DIR)bingocardserver.cc   \
                   $(BG_SERVERS_DIR)bingocardserver.h
	$(CC) $(OBJFLAGS) -c $(BG_SERVERS_DIR)bingocardserver.cc

pitboss.o: $(BG_SERVERS_DIR)pitboss.cc
	$(CC) $(OBJFLAGS) -c $(BG_SERVERS_DIR)pitboss.cc


################################################################################
## Client Objects.                                                            ##
################################################################################
bingocaller.o: $(BG_CLIENTS_DIR)bingocaller.cc 
	$(CC) $(OBJFLAGS) -c $(BG_CLIENTS_DIR)bingocaller.cc

client.o: $(BG_CLIENTS_DIR)client.cc 
	$(CC) $(OBJFLAGS) -c $(BG_CLIENTS_DIR)client.cc

pdaclient.o: $(BG_CLIENTS_DIR)pdaclient.cc 
	$(CC) $(OBJFLAGS) -c $(BG_CLIENTS_DIR)pdaclient.cc


################################################################################
## Build the bingo 0.008 servers!                                             ##
################################################################################
bingodealer:                                                                 \
               $(BG_MANAGER_OBJS)                                          \
               $(BG_HDML_OBJS)                                             \
               $(BG_SESSION_OBJS)                                          \
               $(BG_HTML_OBJS)                                             \
               $(BG_CONTAINER_OBJS)                                        \
               $(BG_PROCESS_OBJS)                                        \
               bingodealer.o bingo.o
	$(CC) $(LINKFLAGS)                                                 \
               $(BG_MANAGER_OBJS)                                          \
               $(BG_SESSION_OBJS)                                          \
               $(BG_HDML_OBJS)                                             \
               $(BG_HTML_OBJS)                                             \
               $(BG_CONTAINER_OBJS)                                        \
               $(BG_PROCESS_OBJS)                                        \
               $(BG_LIB_DIR)/lib/*.o                                       \
               $(BG_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(BG_LIB_DIR)/pserver/*.o                                   \
               $(BG_LIB_DIR)/pserver/Templates.DB/*.o                      \
               $(BG_LIB_DIR)/sserver/server.o                              \
               $(BG_LIB_DIR)/sserver/sendrecv.o                            \
               $(BG_LIB_DIR)/sserver/input.o                               \
               $(BG_LIB_DIR)/sserver/output.o                              \
               $(BG_LIB_DIR)/sserver/client.o                              \
               bingodealer.o bingo.o                                         \
	       -o bingodealer

bingocardserver:                                                             \
               $(BG_CONTAINER_OBJS)                                        \
               bingocardserver.o
	$(CC) $(LINKFLAGS)                                                 \
               $(BG_CONTAINER_OBJS)                                        \
               $(BG_LIB_DIR)/lib/*.o                                       \
               $(BG_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(BG_LIB_DIR)/pserver/*.o                                   \
               $(BG_LIB_DIR)/pserver/Templates.DB/*.o                      \
               $(BG_LIB_DIR)/sserver/server.o                              \
               $(BG_LIB_DIR)/sserver/sendrecv.o                            \
               $(BG_LIB_DIR)/sserver/input.o                               \
               $(BG_LIB_DIR)/sserver/output.o                              \
               $(BG_LIB_DIR)/sserver/client.o                              \
               bingocardserver.o                                          \
	       -o bingocardserver


pitboss:                                                             \
               $(BG_CONTAINER_OBJS)                                        \
               pitboss.o
	$(CC) $(LINKFLAGS)                                                 \
               $(BG_CONTAINER_OBJS)                                        \
               $(BG_LIB_DIR)/lib/*.o                                       \
               $(BG_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(BG_LIB_DIR)/pserver/*.o                                   \
               $(BG_LIB_DIR)/pserver/Templates.DB/*.o                      \
               $(BG_LIB_DIR)/sserver/server.o                              \
               $(BG_LIB_DIR)/sserver/sendrecv.o                            \
               $(BG_LIB_DIR)/sserver/input.o                               \
               $(BG_LIB_DIR)/sserver/output.o                              \
               pitboss.o                                          \
	       -o pitboss



################################################################################
## Build the bingo 0.008 clients!                                             ##
################################################################################
bingocaller: bingocaller.o \
               $(BG_CONTAINER_OBJS)                                        
	$(CC)  -lsocket                                        \
               $(BG_LIB_DIR)/lib/*.o                                       \
               $(BG_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(BG_LIB_DIR)/sserver/sendrecv.o                            \
               $(BG_LIB_DIR)/sserver/input.o                               \
               $(BG_LIB_DIR)/sserver/output.o                              \
               $(BG_LIB_DIR)/sserver/client.o                              \
               $(BG_CONTAINER_OBJS)                                         \
               bingocaller.o                                         \
	       -o bingocaller

client: client.o 
	$(CC)  -lsocket                                        \
               $(BG_LIB_DIR)/lib/*.o                                       \
               $(BG_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(BG_LIB_DIR)/sserver/sendrecv.o                            \
               $(BG_LIB_DIR)/sserver/input.o                               \
               $(BG_LIB_DIR)/sserver/output.o                              \
               $(BG_LIB_DIR)/sserver/client.o                              \
               client.o                                         \
	       -o client

pdaclient: pdaclient.o 
	$(CC)  -lsocket                                        \
               $(BG_LIB_DIR)/lib/*.o                                       \
               $(BG_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(BG_LIB_DIR)/sserver/sendrecv.o                            \
               $(BG_LIB_DIR)/sserver/input.o                               \
               $(BG_LIB_DIR)/sserver/output.o                              \
               $(BG_LIB_DIR)/sserver/client.o                              \
               pdaclient.o                                         \
	       -o pdaclient



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
	rm -f bingodealer bingocaller bingocardserver pitboss client pdaclient


################################################################################
################################################################################
