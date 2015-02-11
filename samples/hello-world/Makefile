CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: hello-world
	@echo "compilation done."
	@echo "try ./hello-world term=Go"

clean:
	@rm -rf hello-world
	@$(CRSX) compile --clean --nocompile hello-world.crs

hello-world: hello-world.crs
	@$(CRSX) compile --clean --opt -d $<
