# Makefile for compiling crsx files.
# Arguments are
# CRSXFILE  : name of the file to compile
# OUTPUTDIR : where to put generated files
# MODE      : crsx compilation mode. STRICT or empty  

CRSXHOME = $(abspath ../../)

ifndef MAKEFILE_CC
MAKEFILE_CC=$(CRSXHOME)/Env.mk
endif

include $(MAKEFILE_CC)
include $(COMPILERSRC)/c/Files.mk

crsabs = $(abspath $(CRSFILE))
crspath = $(dir $(crsabs))
crsbasename = $(patsubst %.crs,%,$(CRSFILE))

ifndef OUTPUTDIR
OUTPUTDIR=$(crspath)
endif

crsdrfile = $(crsbasename).dr
crsbinfile = $(crsbasename)

objs=

header=$(OUTPUTDIR)/$(crsbasename).h

data=$(OUTPUTDIR)/$(crsbasename)_data.c
objs+=$(OUTPUTDIR)/$(crsbasename)_data.o

function=$(OUTPUTDIR)/$(crsbasename)_fun.c
objs+=$(OUTPUTDIR)/$(crsbasename)_fun.o

symbols=$(OUTPUTDIR)/$(crsbasename)_symbols.c
objs+=$(OUTPUTDIR)/$(crsbasename)_symbols.o

CCFLAGS+=-I$(ICU4CDIR)/../include -I$(COMPILERSRC)/c
LDFLAGS+=-L$(ICU4CDIR)

all: $(crsbinfile)
clean::
	@rm -f $(crsdrfile) $(crsbinfile)

# Generate C files

$(crsbasename) : $(crsbasename).dr

$(crsdrfile): $(CRSFILE)
	@$(RUNCRSXRC) 'grammar=("net.sf.crsx.text.Text";)' rules="$<" simple-terms sortify dispatchify reify="$@" 

$(data): $(crsdrfile)
	@export HEADERS="$(crsbasename).h" && $(CRSXC) compile sorts "$<" > "$@"

$(header): $(crsdrfile)
	@$(CRSXC) HEADERS=crsx.h $(MODE) wrapper=ComputeHeader input="$<" > "$@"

$(function): $(crsdrfile)
	@$(CRSXC) HEADERS="$(crsbasename).h" $(MODE) CANONICAL_VARIABLES=1 wrapper=ComputeRules input="$<" > "$@"
		
# Compile C files

CCFLAGS+=-I. -DCRSX_ENABLE_PROFILING -O3  
ifdef ICU4CDIR
LDFLAGS+=-L$(ICU4CDIR)
CCFLAGS+=-I$(ICU4CDIR)/../include
endif 

ifneq ($(UNAME_S),Darwin)
RTLIB=-lrt
endif

ifdef RTDIR
LDFLAGS+=-L$(RTDIR)
CCFLAGS+=-I$(RTDIR)/../include
endif

objs+=$(OUTPUTDIR)/crsx.o $(OUTPUTDIR)/crsx_scan.o $(OUTPUTDIR)/main.o \
			 $(OUTPUTDIR)/linter.o $(OUTPUTDIR)/invariant.o $(OUTPUTDIR)/prof.o
			 
clean::
	@rm -f $(objs)
#
$(OUTPUTDIR)/crsx.o: $(COMPILERSRC)/c/crsx.c $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/crsx_scan.o: $(COMPILERSRC)/c/crsx_scan.c $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/linter.o: $(COMPILERSRC)/c/linter.c $(COMPILERSRC)/c/linter.h $(COMPILERSRC)/c/crsx.h 
$(OUTPUTDIR)/main.o: $(COMPILERSRC)/c/main.c $(COMPILERSRC)/c/linter.h $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/invariant.o: $(COMPILERSRC)/c/invariant.c $(COMPILERSRC)/c/invariant.h $(COMPILERSRC)/c/crsx.h
$(OUTPUTDIR)/prof.o: $(COMPILERSRC)/c/prof.c $(COMPILERSRC)/c/prof.h $(COMPILERSRC)/c/crsx.h

$(OUTPUTDIR)/%.o: $(COMPILERSRC)/c/%.c   
	$(CC) $(CCFLAGS) -c "$<" -o "$@"

$(OUTPUTDIR)/%.o: $(OUTPUTDIR)/%.c   
	$(CC) $(CCFLAGS) -c "$<" -o "$@"

$(crsbasename): $(objs) 
	$(CXX) $(objs) $(ICU4CLIB) $(RTLIB) $(LDFLAGS) -o "$@"
		
