CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: butterfly
	@echo "compilation done."
	@echo "try ./butterfly term=\"Metamorphosis[Egg]\""

clean:
	@rm -rf butterfly
	@$(CRSX) compile --clean --nocompile butterfly.crs

butterfly: butterfly.crs
	@$(CRSX) compile --clean --opt -d $<
