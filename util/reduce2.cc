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
	//regions.push_back("reg1l2tau1bnj");
	//regions.push_back("reg1l1tau1b2j");
	//regions.push_back("reg1l1tau1b3j");

	//regions.push_back("reg1e1mu1tau1b");
	//regions.push_back("reg1e1mu1tau2b");
	//regions.push_back("reg1e1mu2b");
	regions.push_back("reg1e1mu2bnj");
	//regions.push_back("reg1l1tau2b1j_os");
	//regions.push_back("reg1l1tau2b1j_ss_ptbin1");
	//regions.push_back("reg1l1tau2b1j_ss_ptbin2");
	//regions.push_back("reg1l2b2j");

	nominal *analysis = new nominal();
	analysis->debug = 0;
	analysis->writetree = 0;
	analysis->fcnc = 0;
	analysis->reduce = 2;
	analysis->dumptruth = 0;
	analysis->readTFmeanstd("meanstddevs.txt");
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
		printf("reading Root file: %s\n", (prefix + "/data/reduce1/" + cate + "_tree.root").Data());
		TFile inputfile(prefix + "/data/reduce1/" + cate + "_tree.root");
		for (std::vector<TString>::iterator i = regions.begin(); i != regions.end(); ++i)
		{
			printf("region: %s\n", i->Data());
			analysis->Loop( (TTree*)inputfile.Get(i->Data()), cate);
			printf("finish loop on region: %s\n", i->Data());
		}
		inputfile.Close();
		TFile *output = new TFile(CharAppend(cate,".root"),"recreate");
		if(doplot) analysis->plot(output);
		output->Close();
		deletepointer(output);
		analysis->finalise_sample();
	}
	return 0;
}