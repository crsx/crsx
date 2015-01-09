CRSXHOME = $(abspath ../..)
include $(CRSXHOME)/Env.mk

all: peano peano-strict
	@echo "compilation done."
	@echo "try ./peano term=\"Multiply[Plus[S[Z],S[Z]],S[S[S[Z]]]]\""

clean:
	@rm -rf peano peano-strict
	@$(CRSX) compile --clean --nocompile peano.crs

peano: peano.crs
	@$(CRSX) compile --clean --opt -d $<

peano-strict: peano.crs
	@$(CRSX) compile --clean --opt -d --strict -o peano-strict $<

