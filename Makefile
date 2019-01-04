# --------------------------------------------------------------
# GNUmakefile
# --------------------------------------------------------------

ROOTCFLAGS      := $(shell root-config --cflags)
ROOTLIBS        := $(shell root-config --libs)
ROOTGLIBS       := $(shell root-config --glibs) -lMinuit -lTMVA -lHistFactory -lRooStats -lRooFit -lRooFitCore

DELPHES_DIR := /Users/Liby/Desktop/software/delphes/Delphes-3.4.0
DELPHESLIBS := -L$(DELPHES_DIR) -lDelphes
DELPHESINCS := -I$(DELPHES_DIR)

FCNC_DIR := /Users/Liby/work/tau_analysis/FCNC/plotTools
FCNCLIBS := -L$(FCNC_DIR)/lib -lAtlasStyle -lPlotTool
FCNCINCS := -I$(FCNC_DIR)/include/fcnc -I$(FCNC_DIR)/include/atlasstyle 

EXTRALIBS +=$(ROOTLIBS) $(ROOTGLIBS) $(FCNCLIBS) $(DELPHESLIBS)

CPPFLAGS += $(ROOTCFLAGS) $(DELPHESINCS) $(FCNCINCS) -Iinclude
CPPFLAGS += -D PACKAGE_DIR=\"$(PWD)\"

CPPFLAGS  += -Wno-long-long -fPIC -w -g

MAKESHARED = clang++ -shared -fPIC -dynamiclib -single_module -O2 -mmacosx-version-min=10.10 -m64 -Wl,-install_name,@rpath/$(patsubst lib/%,%,$@)

TARGETS 		= $(patsubst util/%.cc,bin/%_run,$(wildcard util/*.cc))

all: makebin lib/libskim.so lib/libfake_analysis.so $(TARGETS)

makebin:
	@echo using compiler: $(CXX)
	@mkdir -p ./bin ./lib
	@echo current directory: $(PWD)

bin/.%.o: src/%.cc include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.skim.o: src/skim.C include/nominal.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -D V7NTUP=1 -c $< -o $@

bin/.fake_analysis.o: src/fake_analysis.C include/nominal.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -D V7NTUP=0 -c $< -o $@

bin/.%.o: util/.C include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

src/LinkDef.cxx: include/LinkDef.h
	@echo Linking LinkDef.h for $@
	@rootcint -f $@ -c $<

bin/.LinkDef.o: src/LinkDef.cxx
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: util/%.cc include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: util/%.cc
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/plot_fake_run: bin/.reduce1.o bin/.LinkDef.o
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) -D V7NTUP=0 $(EXTRALIBS)  -Llib -lfake_analysis -o $@ $^

bin/reduce%_run: bin/.reduce%.o bin/.LinkDef.o
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) -D V7NTUP=1 $(EXTRALIBS)  -Llib -lskim -o $@ $^

bin/%_run: bin/.%.o bin/.LinkDef.o
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) $(EXTRALIBS) -o $@ $^

lib/lib%.so: bin/.%.o
	@echo Linking $@ with $^
	@$(MAKESHARED) $(CPPFLAGS) $(EXTRALIBS) $< -o $@

.PHONY:clean

clean:
	@rm bin/*
