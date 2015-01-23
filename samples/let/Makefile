CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: let
	@echo "compilation done."
	@echo "try ./let term=\"Compile[Let[x, 2, Variable[x]]]\""

clean:
	@rm -rf let
	@$(CRSX) compile --clean --nocompile let.crs

let: let.crs
	@$(CRSX) compile --clean --opt -d $<
