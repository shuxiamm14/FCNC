#include "hadhadtree.h"
#include "fcnc_include.h"
#include <thread>

int main(int argc, char const *argv[])
{

	thread th1(PrintTime, 5);
	th1.detach();
	bool debug = 0;
	TString prefix = PACKAGE_DIR;
	prefix += "/data/hadhadreduce";
	vector<TString> regions;
	regions.push_back("reg2mtau1b2jss");
	regions.push_back("reg2mtau1b2jos");
	regions.push_back("reg2mtau1b3jss");
	regions.push_back("reg2mtau1b3jos");
	regions.push_back("reg2mtau2b2jss");
	regions.push_back("reg2mtau2b2jos");
	regions.push_back("reg2mtau2b3jss");
	regions.push_back("reg2mtau2b3jos");
	//regions.push_back("reg1mtau1ltau1b2jss");
	//regions.push_back("reg2ltau1b2jss");
	//regions.push_back("reg2ttau1b2jss");
	//regions.push_back("reg1ttau1mtau1b2jss");
	//regions.push_back("reg1mtau1ltau1b3jss");
	//regions.push_back("reg2ltau1b3jss");
	//regions.push_back("reg2ttau1b3jss");
	//regions.push_back("reg1ttau1mtau1b3jss");
	//regions.push_back("reg1mtau1ltau1b2jos");
	//regions.push_back("reg2ltau1b2jos");
	//regions.push_back("reg1mtau1ltau1b3jos");
	//regions.push_back("reg2ltau1b3jos");
	//regions.push_back("reg2ttau1b2jos");
	//regions.push_back("reg1ttau1mtau1b2jos");
	//regions.push_back("reg2ttau1b3jos");
	//regions.push_back("reg1ttau1mtau1b3jos");

	ifstream fn(argv[1]);
	if(!debug) gErrorIgnoreLevel=kError;
	hadhadtree *analysis = new hadhadtree();
	analysis->init_reduce2();
	analysis->plotNPs.push_back(0);
	//analysis->plotNPs.push_back(1);
	analysis->dofcnc = 1;
	analysis->reduce = 3;
	analysis->debug = debug;
	analysis->writetree = analysis->reduce == 2 ? 1 : 0;
	bool doplot = analysis->reduce == 2 ? 0 : 1;
	prefix += char('0' + analysis->reduce - 1);
	prefix += "/";
	analysis->fcnc_regions = regions;
	char inputline[500];
	while(!fn.eof()){
		fn.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char filename[500];
		sscanf(inputline,"%s",filename);
		if(doplot) analysis->init_hist(filename);
		analysis->init_sample(filename,filename);
		printf("reading file: %s\n", (prefix + filename + "_tree.root").Data());
		TFile inputfile(prefix + filename + "_tree.root");
		for(auto reg : regions){
			printf("Loop region: %s\n", reg.Data());
			analysis->Loop( (TTree*)inputfile.Get(reg), filename, 1);
		}
		inputfile.Close();
		analysis->finalise_sample();
	}
	return 0;
}
