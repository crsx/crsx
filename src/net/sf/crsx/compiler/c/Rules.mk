# Makefile for Generating CRSX rule C files.
CRSXHOME = $(abspath ../../../../../..)

ifndef MAKEFILE_CC
MAKEFILE_CC=$(CRSXHOME)/Env.mk
endif

include $(MAKEFILE_CC)

ICU4CLIB=-licui18n -licuuc -licudata

CCFLAGS+=-I$(ICU4CDIR)/../include
LDFLAGS+=-L$(ICU4CDIR)
CRSXCBUILD=build

#Keep the intermediate files in cache.
.SECONDARY:

all: prereq rules
	
.PHONY: prereq  
prereq:
	mkdir -p $(CRSXCBUILD)

clean::
	rm -rf $(CRSXCBUILD)
	rm -f rules


#===================================================================================================
# .crs files compilation
# 

TARGETS=CRSXC

# CRSX rule families
CRSXCFAMILIES=EVAL-E1 EVAL-E2 RULE TERM HEADER SORTS SYMBOLS D CD Reified Text SRULE STERM SHEADER

# Same as FAMILIES but as CRSX list format
CRSXCMODULES=( $(patsubst %,'%';,$(CRSXCFAMILIES)) )

# The crsxc rules files.
CRSXCRULESFILES =  ../crsxc.crs rules.crs srules.crs sterm.crs evaluators.crs term.crs sterm.crs header.crs sorts.crs symbols.crs ../defs.crs ../reify.crs cdefs.crs 

# We need a second expansion: the first expansion generates target rules and the second expansion processes automatic variables	    
.SECONDEXPANSION:
define TARGETDR
  $(CRSXCBUILD)/$(1).dr: $($(1)RULESFILES)
	$(RUNCRSXRC) 'grammar=("net.sf.crsx.text.Text";)' "modules=$($(1)MODULES)" rules="$$<" simple-terms sortify dispatchify reify="$$@"
	@[ -s $$@ ] || rm -f $$@ || false

endef
$(foreach tgt, $(TARGETS), $(eval $(call TARGETDR,$(tgt))))

#===================================================================================================
# C SOURCE FILES GENERATION USING CRSX INTEPRETER

define TARGETGEN

# - header fragment for TARGET.h with all declarations.
$(CRSXCBUILD)/$(1)_%.h: $(CRSXCBUILD)/$(1)_%_header.dr
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=header.crs wrapper="ComputeHeader" "MODULE=$$*" sink=net.sf.crsx.text.TextSink omit-linear-variables input="$$<" output="$$@.tmp"
	@mv $$@.tmp $$@

# - sort data structures and step function definitions.

$(CRSXCBUILD)/$(1)_%_fun.c: $(CRSXCBUILD)/$(1)_%.dr
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=rules.crs  wrapper="ComputeRules" "HEADERS=$(1).h" "MODULE=$$*" sink=net.sf.crsx.text.TextSink omit-linear-variables input="$$<" canonical-variables output="$$@.tmp"
	@mv $$@.tmp $$@
 
 # - symbol list for crsx_scan.
 $(CRSXCBUILD)/$(1)_%.symlist: $(CRSXCBUILD)/$(1)_%_header.dr
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=symbols.crs wrapper="ComputeSymbols" sink=net.sf.crsx.text.TextSink omit-linear-variables input="$$<" output="$$@.tmp"
	@sed -e 's/ {/\'$$$$'\n{/g' -e 's/ //g' $$@.tmp | awk '/^$$$$/{next}{print}' | LC_ALL=C sort -bu > $$@
	@rm -f $$@.tmp

 # specific targets for data symbols.
 $(CRSXCBUILD)/$(1)_data.dr: $(CRSXCBUILD)/$(1).dr

 $(CRSXCBUILD)/$(1)_data.h: $(CRSXCBUILD)/$(1)_data.dr  
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=header.crs wrapper="ComputeHeader" MODULE=DATA sink=net.sf.crsx.text.TextSink omit-linear-variables input="$(CRSXCBUILD)/$(1)_data.dr" output="$(CRSXCBUILD)/$(1)_data.h.tmp"
	@mv $(CRSXCBUILD)/$(1)_data.h.tmp $(CRSXCBUILD)/$(1)_data.h

 $(CRSXCBUILD)/$(1)_data.c: $(CRSXCBUILD)/$(1)_data.dr 
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=sorts.crs wrapper="ComputeSorts" "HEADERS=$(1).h" sink=net.sf.crsx.text.TextSink omit-linear-variables input="$(CRSXCBUILD)/$(1)_data.dr" output="$(CRSXCBUILD)/$(1)_data.c.tmp"
	@mv $(CRSXCBUILD)/$(1)_data.c.tmp $(CRSXCBUILD)/$(1)_data.c

$(1)C_FILES+=$(CRSXCBUILD)/$(1)_data.c

 $(CRSXCBUILD)/$(1)_data.symlist: $(CRSXCBUILD)/$(1)_data.dr  
	$(RUNCRSXRC) "grammar=('net.sf.crsx.text.Text';)" rules=symbols.crs wrapper="ComputeSymbols" sink=net.sf.crsx.text.TextSink input="$(CRSXCBUILD)/$(1)_data.dr" omit-linear-variables output="$(CRSXCBUILD)/$(1)_data.symlist.tmp"
	sed -e 's/ {/\'$$$$'\n{/g' -e 's/ //g' $(CRSXCBUILD)/$(1)_data.symlist.tmp | awk '/^$$$$/{next}{print}' | LC_ALL=C sort -bu > $(CRSXCBUILD)/$(1)_data.symlist
	@rm $(CRSXCBUILD)/$(1)_data.symlist.tmp

 $(1)DR_FILES += $(CRSXCBUILD)/$(1)_data.dr
 $(1)H_FILES += $(CRSXCBUILD)/$(1)_data.h 
 $(1)SYMLIST_FILES += $(CRSXCBUILD)/$(1)_data.symlist
 
 $(CRSXCBUILD)/%_fun.o : $(CRSXCBUILD)/%_fun.c $(CRSXCBUILD)/$(1).h 
	$(CC) $(CCFLAGS) -I$(CRSXCBUILD) -I. -c $$< -o $$@
 
endef
$(foreach tgt, $(TARGETS), $(eval $(call TARGETGEN,$(tgt))))

# Non-.c targets for all sort data structures, step functions, and function symbol lists.
define FAMILY_DEPENDENCIES
 $(CRSXCBUILD)/$(1)_$(2).dr:		$(CRSXCBUILD)/$(1).dr 
 $(CRSXCBUILD)/$(1)_$(2)_header.dr:	$(CRSXCBUILD)/$(1).dr 
 $(CRSXCBUILD)/$(1)_$(2)_fun.c:		$(CRSXCBUILD)/$(1)_$(2).dr 
 $(CRSXCBUILD)/$(1)_$(2).h:		$(CRSXCBUILD)/$(1)_$(2)_header.dr 
 $(CRSXCBUILD)/$(1)_$(2).symlist:	$(CRSXCBUILD)/$(1)_$(2)_header.dr 
 $(1)DR_FILES += $(CRSXCBUILD)/$(1)_$(2).dr
 $(1)H_FILES += $(CRSXCBUILD)/$(1)_$(2).h
 $(1)SYMLIST_FILES += $(CRSXCBUILD)/$(1)_$(2).symlist
 $(1)C_FILES += $(CRSXCBUILD)/$(1)_$(2)_fun.c

#$(CRSXCBUILD)/$(1)_$(2)_fun.o:	$(CRSXCBUILD)/$(1)_$(2)_fun.c $(H_FILES) $(CRSXCBUILD)/$(1).h
#$(1)O_FILES += $(CRSXCBUILD)/$(1)_$(2)_fun.o


endef

define TARGETED_FAMILY_DEPENDENCIES
# Top header file included from all components.
$(CRSXCBUILD)/$(1).h: $$($(1)H_FILES)
	@(echo '/* C HEADER FOR CRSX $(1).h */'; \
	  echo '#ifndef CRSX__M_$(1)_H'; \
	  echo '#define CRSX__M_$(1)_H'; \
	  echo '#include "crsx.h"'; \
	  echo '#include "$(1)_data.h"'; \
	  for line in $($(1)FAMILIES); do \
	     echo "#include \"$(1)_$$$$line.h\""; \
	  done; \
	  echo '#endif') > $(CRSXCBUILD)/$(1).h

$(1)H_FILES += $(CRSXCBUILD)/$(1).h

# All symbols list.
$(CRSXCBUILD)/$(1)symbols.c: $$($(1)SYMLIST_FILES)  
	LC_ALL=C sort -bu $$($(1)SYMLIST_FILES) > $$@.tmp
	@(echo '/* Generated table of all $(1) symbols. */'; \
	  echo '#include "$(1).h"'; \
	  echo "size_t symbolDescriptorCount = $$$$(wc -l <$$@.tmp);"; \
	  echo 'struct _SymbolDescriptor symbolDescriptorTable[] = {';\
	  cat $$@.tmp;\
	  echo '{NULL, NULL}};') > $$@

$(CRSXCBUILD)/$(1)symbols.o: $(CRSXCBUILD)/$(1)symbols.c crsx.h $(CRSXCBUILD)/$(1)_data.h $(CRSXCBUILD)/$(1).h
	$(CC) $(CCFLAGS) -I$(CRSXCBUILD) -I. -c $$< -o $$@

# OBJECT FILES.
#$(CRSXCBUILD)/$(1)_data.o: $(CRSXCBUILD)/$(1)_data.c $($(1)H_FILES) $(CRSXCBUILD)/$(1).h $(CRSX_FILES) 

#$(1)O_FILES += $(CRSXCBUILD)/$(1)_data.o
#$(1)O_FILES += $(CRSXCBUILD)/$(1)symbols.o

$(foreach family,$($(1)FAMILIES),$(eval $(call FAMILY_DEPENDENCIES,$(1),$(family))))
endef
$(foreach tgt, $(TARGETS), $(eval $(call TARGETED_FAMILY_DEPENDENCIES,$(tgt))))


rules: $(CRSXCC_FILES) $(CRSXCH_FILES) $(CRSXCBUILD)/CRSXCsymbols.c 
	touch rules