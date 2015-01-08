CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: fact fact2
	@echo "compilation done."
	@echo "try ./Fact wrapper=Fact term=5"
	
clean:
	@rm -f fact fact2
	@$(CRSX) compile --clean --nocompile fact.crs
	@$(CRSX) compile --clean --nocompile fact2.crs
	
	
fact: fact.crs
	@$(CRSX) compile --clean --opt -d --strict $<
	
fact2: fact2.crs
	@$(CRSX) compile --clean --opt -d --strict $<