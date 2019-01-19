# --------------------------------------------------------------
# GNUmakefile
# --------------------------------------------------------------

ROOTCFLAGS      := $(shell root-config --cflags)
ROOTLIBS        := $(shell root-config --libs)
ROOTGLIBS       := $(shell root-config --glibs) -lMinuit -lTMVA -lTMVAGui

DELPHES_DIR := /Users/Liby/Desktop/software/delphes/Delphes-3.4.0
DELPHESLIBS := -L$(DELPHES_DIR) -lDelphes
DELPHESINCS := -I$(DELPHES_DIR)

FCNC_DIR := /Users/Liby/work/tau_analysis/FCNC/plotTools
FCNCLIBS := -L$(FCNC_DIR)/lib -lAtlasStyle -lPlotTool
FCNCINCS := -I$(FCNC_DIR)/include/fcnc -I$(FCNC_DIR)/include/atlasstyle 

EXTRALIBS +=$(ROOTLIBS) $(ROOTGLIBS) $(FCNCLIBS)

CPPFLAGS += $(ROOTCFLAGS) $(FCNCINCS) -Iinclude
CPPFLAGS += -D PACKAGE_DIR=\"$(PWD)\"

CPPFLAGS  += -Wno-long-long -fPIC -w -g

CXX=/Applications/Xcode.app/Contents/Developer/usr/bin/g++

MAKESHARED = clang++ -shared -fPIC -dynamiclib -single_module -O2 -mmacosx-version-min=10.10 -m64 -Wl,-install_name,@rpath/$(patsubst lib/%,%,$@)

TARGETS 		= $(patsubst util/%.cc,bin/%_run,$(wildcard util/*.cc))

all: makebin lib/libskim.so lib/libfake_analysis.so $(TARGETS) bin/plot_fake_run

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

bin/.dict.cxx: include/LinkDef.h
	@echo Linking LinkDef.h for $@
	@rootcint -f $@ -c $<

bin/.dict.o: bin/.dict.cxx
	@$(CXX) $(CPPFLAGS) -c $< -o $@
	@mv bin/.dict_rdict.pcm lib/.
bin/.%.o: util/%.cc include/%.h
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/.%.o: util/%.cc
	@echo Compiling $@ with $^
	@$(CXX) $(CPPFLAGS) -c $< -o $@

bin/reduce%_run: bin/.reduce%.o bin/.dict.o
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) -D $(EXTRALIBS)  -Llib -lskim -o $@ $^

bin/plot_fake_run: bin/.reduce1.o lib/libfake_analysis.so
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) -D $(EXTRALIBS)  -Llib -lfake_analysis -o $@ $^

bin/%_run: bin/.%.o bin/.dict.o
	@echo Linking $@ with $^
	@$(CXX) $(CPPFLAGS) $(EXTRALIBS) -o $@ $^

lib/lib%.so: bin/.%.o
	@echo Linking $@ with $^
	@$(MAKESHARED) $(CPPFLAGS) $(EXTRALIBS) $< -o $@

.PRECIOUS: bin/.%.o

.PHONY:clean

clean:
	@rm -r bin lib
