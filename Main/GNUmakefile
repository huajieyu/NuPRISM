#
# This is an example GNUmakefile for my packages

#
NAME = Main

# specific names for this package
SOURCES = $(wildcard *.cxx)
FMWK_HEADERS = LinkDef.h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))

# include options for this package
INCFLAGS  = -I.                       #Include itself
NCFLAGS += -I$(MYSW_INCDIR)

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

LDFLAGS += -L$(MYSW_LIBDIR) -lLiteFMWK_Base 


# call kernel specific compiler setup
include $(MYSW_DIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(MYSW_DIR)/Makefile/GNUmakefile.CORE
