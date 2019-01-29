#include "nominal.h"

int main(int argc, char const *argv[])
{
	TString prefix = PACKAGE_DIR;
	ifstream fn(argv[1]);
	if(!fn) {
	  fprintf(stderr,"Error: can't open file: %s\n",argv[1]);
	  return 1;
	}
	bool doplot = 1;
	char inputline[100];
	vector<TString> regions;
	regions.push_back("reg1l2tau1bnj");
	regions.push_back("reg1l1tau1b2j");
	regions.push_back("reg1l1tau1b3j");

	nominal *analysis = new nominal();
	analysis->debug = 0;
	analysis->writetree = 0;
	analysis->reduce = 3;
	analysis->dumptruth = 1;
	if(doplot) analysis->init_hist();
	while(!fn.eof()){
		fn.getline(inputline,200);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char cate[100];
		char title[100];
		int version;
		sscanf(inputline,"%d %s %s",&version,&cate,&title);
		analysis->version = version;
		analysis->init_sample(cate, title);
		printf("reading Root file: %s\n", (prefix + "/data/reduce2/" + cate + "_tree.root").Data());
		TFile inputfile(prefix + "/data/reduce2/" + cate + "_tree.root");
		for (std::vector<TString>::iterator i = regions.begin(); i != regions.end(); ++i)
		{
			printf("region: %s\n", i->Data());
			analysis->Loop( (TTree*)inputfile.Get(i->Data()), cate);
			printf("finish loop on region: %s\n", i->Data());
		}
		inputfile.Close();
		if(doplot) analysis->plot();
		analysis->finalise_sample();
	}
	return 0;
}