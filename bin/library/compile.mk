# Makefile for compiling crsx files.
# Arguments are
# CRSXFILE : name of the file to compile


CRSXHOME = $(abspath ../../)
makefile_cc=$(CRSXHOME)/Env.mk

include $(makefile_cc)

crsabs = $(abspath $(CRSFILE))
crspath = $(dir $(crsabs))
crsbasename = $(patsubst %.crs,%,$(CRSFILE))

crsdrfile = $(crsbasename).dr
crsbinfile = $(crsbasename)

all: $(crsbinfile)
clean:
	rm -r $(crsdrfile) $(crsbinfile)

$(crsbasename) : $(crsbasename).dr

$(crsbasename).dr: $(CRSFILE)
	$(RUNCRSXRC) 'grammar=("net.sf.crsx.text.Text";)' rules="$<" simple-terms sortify dispatchify reify="$@" 
	
