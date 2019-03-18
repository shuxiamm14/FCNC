#include "hadhadtree.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: xtfw_reduce_run dataconfigfile (mc16a_wjet.txt)\n");
		exit(1);
	}
	bool doplot = 1;
	TString prefix1;
	TString prefix = PACKAGE_DIR;
	ifstream fn(prefix + "/datafiles/xTFW/run/" + argv[1]);
	if(!fn) {
	  fprintf(stderr,"Error: can't open file: %s\n",(prefix + "/datafiles/xTFW/run/" + argv[1]).Data());
	  return 1;
	}
	TString inputconfig = argv[1];
	inputconfig.Remove(inputconfig.Sizeof()-5,4); //remove ".txt"
	float luminosity;
	if(inputconfig.Contains("mc16a")) luminosity = 4.21*0.921 + 38.5*0.924;
	else if(inputconfig.Contains("mc16d")) luminosity = 46.9;
	else if(inputconfig.Contains("mc16e")) luminosity = 62.2;
	else {
		printf("Wrong config file name: %s\n", inputconfig.Data());
		exit(0);
	}
	char inputline[500];

	hadhadtree *analysis = new hadhadtree();
    analysis->dofcnc = 1;
	analysis->reduce = 1;
	analysis->debug = 0;
	analysis->init_hist();
	analysis->init_sample(inputconfig,inputconfig);
	ifstream xsecfile(prefix + "/config/Xsecs.txt");
	map<int, float> xsecs;
	printf("reading cross section file: %s\n", (prefix + "/config/Xsecs.txt").Data());
	while(!xsecfile.eof()){
		xsecfile.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		int dsid;
		float filtereff, xsec, kfactor;
		sscanf(inputline,"%d %f %f %f", &dsid, &filtereff, &xsec, &kfactor);
		xsecs[dsid] = filtereff*xsec*kfactor;
	}
	while(!fn.eof()){
		fn.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char filename[500];
		int dsid;
		sscanf(inputline,"%d %s",&dsid,filename);
		printf("reading file: DSID: %d name %s\n", dsid, filename);
		TFile inputfile(filename);
		if(!inputfile.Get("h_metadata")) {
			printf("h_metadata not found, exit.\n");
			exit(1);
		}
		analysis->Loop( (TTree*)inputfile.Get("NOMINAL"), inputconfig, xsecs[dsid]*luminosity/((TH1*)inputfile.Get("h_metadata"))->GetBinContent(8));
		inputfile.Close();
	}
	analysis->finalise_sample();
	TFile *output = new TFile(CharAppend(inputconfig,".root"),"recreate");
	if(doplot) analysis->plot(output);
	output->Close();
	deletepointer(output);
	return 0;
}
