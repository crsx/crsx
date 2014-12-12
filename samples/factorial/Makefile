CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: fact 
clean:
	@rm -f fact fact2
	@$(CRSX) compile --clean --nocompile fact.crs
	@$(CRSX) compile --clean --nocompile fact2.crs
	
fact: fact.crs
	@$(CRSX) compile --clean --strict $<
	
fact2: fact2.crs
	@$(CRSX) compile --clean --strict $<