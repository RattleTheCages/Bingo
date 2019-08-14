################################################################################
################################################################################
##                                                                            ##
##  Makefile for lifestyle clients 0.022                           12.4.99    ##
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
LF_LIB_DIR              = /home/dhuffman/del/projects/library/
LF_CLIENTS_DIR          = /home/dhuffman/del/projects/lifestyles/clients/


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Building Lifestyle Clients 0.022"
	@echo `date`
	@make allsub

allsub: client pdatestclient
	@echo "Lifestyle Clients 0.022 Build Completed."
	@echo `date`


################################################################################
## Client Objects.                                                            ##
################################################################################
client.o: $(LF_CLIENTS_DIR)client.cc 
	$(CC) $(OBJFLAGS) -c $(LF_CLIENTS_DIR)client.cc


################################################################################
## Build the Lifestyle Clients 0.022!                                         ##
################################################################################
client: client.o 
	$(CC)  -lsocket                                        \
               $(LF_LIB_DIR)/lib/*.o                                       \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/sserver/sendrecv.o                            \
               $(LF_LIB_DIR)/sserver/input.o                               \
               $(LF_LIB_DIR)/sserver/output.o                              \
               $(LF_LIB_DIR)/sserver/client.o                              \
               client.o                                         \
	       -o ../executables/client


pdatestclient: pdatestclient.o 
	$(CC)  -lsocket                                        \
               $(LF_LIB_DIR)/lib/*.o                                       \
               $(LF_LIB_DIR)/lib/Templates.DB/*.o                          \
               $(LF_LIB_DIR)/sserver/sendrecv.o                            \
               $(LF_LIB_DIR)/sserver/input.o                               \
               $(LF_LIB_DIR)/sserver/output.o                              \
               $(LF_LIB_DIR)/sserver/client.o                              \
               pdatestclient.o                                         \
	       -o ../executables/pdatestclient


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
	rm -f ../executables/client ../executables/pdaclient


################################################################################
################################################################################
