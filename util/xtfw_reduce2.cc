#include "hadhadtree.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: xtfw_reduce_run dataconfigfile (mc16a_wjet.txt)\n");
		exit(1);
	}
	bool debug = 0;
	bool doplot = 1;
	TString prefix = PACKAGE_DIR;
	prefix += "/data/hadhadreduce1/";
	vector<TString> regions;
	regions.push_back("reg2mtau1b2jss");
	//regions.push_back("reg1mtau1ltau1b2jss");
	//regions.push_back("reg2ltau1b2jss");
	//regions.push_back("reg2ttau1b2jss");
	//regions.push_back("reg1ttau1mtau1b2jss");
	regions.push_back("reg2mtau1b3jss");
	//regions.push_back("reg1mtau1ltau1b3jss");
	//regions.push_back("reg2ltau1b3jss");
	//regions.push_back("reg2ttau1b3jss");
	//regions.push_back("reg1ttau1mtau1b3jss");
	regions.push_back("reg2mtau1b2jos");
	//regions.push_back("reg1mtau1ltau1b2jos");
	//regions.push_back("reg2ltau1b2jos");
	regions.push_back("reg2mtau1b3jos");
	//regions.push_back("reg1mtau1ltau1b3jos");
	//regions.push_back("reg2ltau1b3jos");
	//regions.push_back("reg2ttau1b2jos");
	//regions.push_back("reg1ttau1mtau1b2jos");
	//regions.push_back("reg2ttau1b3jos");
	//regions.push_back("reg1ttau1mtau1b3jos");

	ifstream fn(argv[1]);
	if(!debug) gErrorIgnoreLevel=kError;
	hadhadtree *analysis = new hadhadtree();
	analysis->dofcnc = 1;
	analysis->reduce = 2;
	analysis->debug = debug;
	analysis->writetree = 1;
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
			analysis->Loop( (TTree*)inputfile.Get(reg), filename, 1);
		}
		inputfile.Close();
		analysis->finalise_sample();
	}
	return 0;
}
