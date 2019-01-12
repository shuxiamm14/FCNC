#include "nominal.h"

int main(int argc, char const *argv[])
{
	TString prefix = PACKAGE_DIR;
	ifstream fn(argv[1]);
	if(!fn) {
	  fprintf(stderr,"Error: can't open file: %s\n",argv[1]);
	  return 1;
	}
	char inputline[100];
	vector<TString> regions;
	regions.push_back("reg1l2tau1bnj");
	regions.push_back("reg1l1tau1b2j");
	regions.push_back("reg1l1tau1b3j");

	nominal *analysis = new nominal();
	analysis->reduce = 2;
	analysis->debug = 0;
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
		printf("reading Root file: %s\n", (prefix + "/data/" + cate + ".root").Data());
		TFile inputfile(prefix + "/data/" + cate + ".root");
		for (std::vector<TString>::iterator i = regions.begin(); i != regions.end(); ++i)
		{
			printf("region: %s\n", i->Data());
			analysis->Loop( (TTree*)inputfile.Get(i->Data()), cate);
			printf("finish loop on region: %s\n", i->Data());
		}
		inputfile.Close();
		analysis->finalise_sample();
	}
	analysis->plot();
	return 0;
}