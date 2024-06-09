#   Makefile for compiling the Electonical Neuron Simulator Project
#
#   Written by Ehsan Nedaaee Oskoee
#
#   Using svn 

include elecnerunsimu_config.mk

default: main clean

# macro for home dir

BASE = $(shell pwd )

# include directory

INCLDS = -I$(BASE)/include -I/usr/local/include -I$(BASE)/SuiteSparse/Include

# library directory

LIBS = $(BASE)/lib

# source directory 
SRC = $(BASE)/src

HDRS_BASE = $(BASE)/include

# Exectutable file name

EXEFILE = $(BASE)/bin/ENS

#HDRS_FILES = $(shell ls include)

# -----------------<Lib files definition>---------------------------------

LIB_FILE = $(shell ls $(LIBS))

LIB_FILES= $(LIB_FILE:%=$(LIBS)/%)
#------------------<External Lib files definition>-------------------------

LIB_EXT_PATH = $(BASE)/SuiteSparse/Lib

LIB_EXT_FILES = $(shell ls $(BASE)/SuiteSparse/Lib/*.a)

LIB_EXT = $(LIB_EXT_FILES:%=$(LIB_EXT_PATH)/%)
#------------------------------------------------------------------------

MAIN_SRC = $(SRC)/main.cpp

OBJS = main.o

MAIN_CMP = $(SRC)/main.cpp

#-----------------<Making main >---------------------------------------------------------------
main: $(OBJS) 
	@echo
	@echo "Linking ...."
	@echo
	$(CC) $(LNK_FLAGS)  $(OBJS)  lib/*.a $(LIB_FILES)  lib/*.a  $(LIB_EXT_FILES) $(BASE)/SuiteSparse/Lib/*.a -o $(EXEFILE) 
$(OBJS): 
	$(CC) $(CFLAGS) $(INCLDS) -c $(MAIN_CMP)
#----------------------------------------------------------------------------------------------
#-----------------<Making Read >---------------------------------------------------------------
read:
	@echo
	@echo "Compiling Reading data Program ...."
	@echo
	$(CC) $(SRC)/read.cpp -o $(BASE)/bin/read_file

#-----------------<Cleaning >---------------------------------------------------------------
clean:
	@echo "Cleaning ......"
	@rm -f $(OBJS)

#----------------------------<compiling and making libraries>--------------------------------------

lib: linsolver nonlinsolver random simulation

linsolver:
	@echo
	@echo "Compiling and making the Linear Solver library .........."
	@echo
	- ( cd LinSolver && $(MAKE) )
mna:
	@echo
	@echo "Compiling and making the MNA Matrix library .........."
	@echo
	- ( cd MNA && $(MAKE) )
nonlinsolver:
	@echo
	@echo "Compiling and making the non-linear solver library .........."
	@echo
	- ( cd NonLinSolver && $(MAKE) )
random:
	@echo
	@echo "Compiling and making the Random library .........."
	@echo
	- ( cd Random && $(MAKE) )
simulation:
	@echo
	@echo "Compiling and making the Simulation library .........."
	@echo
	- ( cd Simulation && $(MAKE) )

