CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: let2
	@echo "compilation done."
	@echo "try ./let2 term=\"Compile[Let[x, Literal[2], Let[y, Variable[x], Variable[y]]]]\""

clean:
	@rm -rf let2
	@$(CRSX) compile --clean --nocompile let2.crs

let2: let2.crs
	@$(CRSX) compile --clean --opt -d $<
