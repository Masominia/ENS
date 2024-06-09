#   Makefile for compiling the Electonical Neuron Simulator Project
#
#   Written by Ehsan Nedaaee Oskoee
#
#   Using svn 


include ../elecnerunsimu_config.mk

default: lib install

BASE = $(shell pwd )

# library directory

LIBS = $(BASE)/lib

#sources directory

SRC = $(BASE)/src

# include directory

INCLDS = -I../include/ 

LIB_FILE = $(LIBS)/lib_LinSolver.$(VERSION).a

Sources = $(shell ls $(SRC))

OBJS = $(Sources:.cpp=.o)

SRC_CMP = $(Sources:%.cpp=$(SRC)/%.cpp)


lib:write libclean libmake clean

write:
	@echo
	@echo
	@echo "--------------------------------------------"
	@echo "--------------------------------------------"
	@echo "-   making the Linear solver files library -"
	@echo "--------------------------------------------"
	@echo "--------------------------------------------"
	@echo
	@echo

libclean:
	@echo "Removing the old library file......."
	rm -f $(LIB_FILE)

libmake: makelib
	@echo "Making radom access to the library files ....."
	ranlib $(LIB_FILE)
makelib:compile $(OBJS)
	@echo "Making library file ....."
	ar  $(LIBFLAGS) $(LIB_FILE) $(OBJS)
compile:
	@echo "Compiling files for making library....."
	$(CC) $(CFLAGS) $(INCLDS) -c $(SRC_CMP)

clean:
	@echo "Cleaning ......"
	@rm -f $(OBJS)
install:
	@echo "Copying lib files ............................."
	$(CP) $(LIB_FILE) $(INSTALL_LIB)	

