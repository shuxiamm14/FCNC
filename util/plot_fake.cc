#include "nominal.h"

int main(int argc, char const *argv[])
{
	TString prefix1 = "/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimV6/MytthAnaSkim_";
	TString prefix = PACKAGE_DIR;
	ifstream fn(argv[1]);
	if(!fn) {
	  fprintf(stderr,"Error: can't open file: %s\n",argv[1]);
	  return 1;
	}
	char inputline[100];
	nominal *analysis = new nominal();
	while(!fn.eof()){
		fn.getline(inputline,200);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char filename[100];
		char cate[100];
		sscanf(inputline,"%s %s",&filename,&cate);
		printf("reading list: %s as %s\n", (prefix + "/datafiles/" + filename + ".txt").Data(), cate);
		ifstream list(prefix + "/datafiles/" + filename + ".txt");
		while(!list.eof()){
			list.getline(inputline,200);
			if(strlen(inputline)==0) continue;
			if(inputline[0]=='#') continue;
			printf("reading Root file: %s\n", (prefix1 + inputline).Data());
			TFile inputfile(prefix1 + inputline);
			analysis->Loop( (TTree*)inputfile.Get("nominal"), cate);
			inputfile.Close();
		}
	}
	analysis->plot();
	return 0;
}