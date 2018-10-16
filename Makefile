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

CPPFLAGS  += -Wno-long-long -fPIC -w -g

MAKESHARED = clang++ -shared -fPIC -dynamiclib -single_module -O2 -mmacosx-version-min=10.10 -m64 -Wl,-install_name,@rpath/$(patsubst lib/%,%,$@)

TARGETS 		= $(patsubst util/%.cc,bin/%_run,$(wildcard util/*.cc))

all: makebin lib/libnominal.so $(TARGETS)

makebin:
	@echo using compiler: $(CXX)
	@mkdir -p ./bin ./lib
	@echo current directory: $(PWD)

bin/.%.o: src/%.cc include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: src/%.C include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: util/%.C include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: util/%.cc include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: util/%.cc
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/%_run: bin/.%.o
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) $(EXTRALIBS)  -Llib -lnominal -o $@ $<

lib/lib%.so: bin/.%.o
	@echo Linking $@ with $^
	@$(MAKESHARED) $(CPPFLAGS) $(EXTRALIBS) $< -o $@

.PHONY:clean

clean:
	@rm bin/*
