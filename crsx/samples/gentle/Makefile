# Makefile for HACS Gentle Introduction Examples.

# HACS configuration.
HACS = $(abspath hacs)
include $(HACS)/Makefile-hx

# Sample target.
all:: first.run
first.run: first.hx

clean::; $(MAKE) -C $(HACS) clean

# Distribution.
TOPFILES = 00README-hacs Makefile-hacs-template first.hx doc/hacs-gently.pdf
HACSSOURCES = Makefile Makefile-hx crsx.jar Cookmain.c run-hacs.sh
HACSGENERATED = Cook.h Cook_sorts.c Cook_rules.c Cook_symbols.c

hacs.zip: $(TOPFILES)
	@rm -fr hacs.zip tmp
	$(MAKE) -C $(HACS) clean $(HACSSOURCES) $(HACSGENERATED)
	mkdir -p tmp/hacs
	cp -vp $(TOPFILES) tmp/
	d="`pwd`" && cd $(HACS) && cp -vp $(HACSSOURCES) $(HACSGENERATED) $$d/tmp/hacs/
	d="`pwd`" && cd tmp && zip -r $$d/hacs.zip .
	rm -fr tmp
