# Makefile for compiling crsx file.

CRSXHOME = $(abspath ../../)
MAKEFILE_CC=$(CRSXHOME)/Env.mk

include $(MAKEFILE_CC)

BASENAME = $(patsubst %.crs,%,$(CRSFILE))

all: $(BASENAME)

$(BASENAME) : $(BASENAME).dr

$(BASENAME).dr: $(CRSFILE)
	$(RUNCRSXRC) 'grammar=("net.sf.crsx.text.Text";)' rules="$<" simple-terms sortify dispatchify reify="$@" 
	

