CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: family
	@echo "compilation done."
	@echo "try ./family term=\"Relationship[Brother[Friend[Sister[Me]]]]\""

clean:
	@rm -rf family
	@$(CRSX) compile --clean --nocompile family.crs

family: family.crs
	@$(CRSX) compile --clean --opt -d $<
