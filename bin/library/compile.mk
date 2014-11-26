# Makefile for compiling crsx files.
# Arguments are
# CRSXHOME  : crsx root directory
# CRSXFILE  : name of the file to compile
# OUTPUTDIR : where to put generated files
# MODE      : crsx compilation mode. STRICT or empty  

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

crsdrfile = $(OUTPUTDIR)/$(crsbasename).dr
crsbinfile = $(OUTPUTDIR)/$(crsbasename)

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
	@rm -f $(crsdrfile) $(crsbinfile) $(header) $(data) $(function) $(symbols)

prereq:
	mkdir -p $(OUTPUTDIR)

# Generate C files

$(OUTPUTDIR)/$(crsbasename) : $(crsbasename).dr

$(crsdrfile): $(CRSFILE) prereq
	@$(RUNCRSXRC) 'grammar=("net.sf.crsx.text.Text";)' rules="$<" simple-terms sortify dispatchify reify="$@" 

$(data): $(crsdrfile) prereq
	@export HEADERS="$(crsbasename).h" && $(CRSXC) compile sorts "$<" > "$@"

$(header): $(crsdrfile) prereq
	@$(CRSXC) HEADERS=crsx.h $(MODE) wrapper=ComputeHeader input="$<" > "$@"

$(function): $(crsdrfile) prereq
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

$(OUTPUTDIR)/%.o: $(COMPILERSRC)/c/%.c prereq 
	$(CC) $(CCFLAGS) -c "$<" -o "$@"

$(OUTPUTDIR)/%.o: $(OUTPUTDIR)/%.c $(header) prereq  
	$(CC) $(CCFLAGS) -c "$<" -o "$@"

$(OUTPUTDIR)/$(crsbasename): $(objs) 
	$(CXX) $(objs) $(ICU4CLIB) $(RTLIB) $(LDFLAGS) -o "$@"
		
