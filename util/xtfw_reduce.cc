#include "hadhadtree.h"
#include <thread>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: xtfw_reduce_run dataconfigfile (mc16a_wjet.txt)\n");
		exit(1);
	}
	thread th1(PrintTime, 5);
	th1.detach();
	bool debug = 0;
	bool doplot = 1;
	TString prefix1;
	TString prefix = PACKAGE_DIR;
	ifstream fn(prefix + "/datafiles/xTFW/run/" + argv[1]);
	if(!fn) {
	  fprintf(stderr,"can't open file: %s, try %s\n",(prefix + "/datafiles/xTFW/run/" + argv[1]).Data(),argv[1]);
	  fn.open(argv[1]);
	  if(!fn){
	  	fprintf(stderr,"can't open file: %s\n",argv[1]);
	  	return 1;
	  }
	}

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

	TString inputconfig = argv[1];
	inputconfig.Remove(inputconfig.Sizeof()-5,4); //remove ".txt"
	float luminosity = 0;
	bool isData = 0;
	if(inputconfig.Contains("data")) isData = 1;
	else if(inputconfig.Contains("mc16a")) luminosity = 3.219555072 + 32.988125184;
	else if(inputconfig.Contains("mc16d")) luminosity = 44.30739456;
	else if(inputconfig.Contains("mc16e")) luminosity = 59.93723904;
	else {
		printf("Wrong config file name, cannot recognise mc campaign: %s\n", inputconfig.Data());
		exit(0);
	}
	char inputline[500];
	map<int, float> xsecs;
	if(!isData){
		ifstream xsecfile(prefix + "/config/Xsecs.txt");
		printf("reading cross section file: %s\n", (prefix + "/config/Xsecs.txt").Data());
		while(!xsecfile.eof()){
			xsecfile.getline(inputline,500);
			if(strlen(inputline)==0) continue;
			if(inputline[0]=='#') continue;
			int dsid;
			float filtereff, xsec, kfactor;
			sscanf(inputline,"%d %f %f %f", &dsid, &filtereff, &xsec, &kfactor);
			xsecs[dsid] = filtereff*xsec*1000000*kfactor;
		}
	}
	if(!debug) gErrorIgnoreLevel=kError;
	hadhadtree *analysis = new hadhadtree();
	analysis->init_reduce1();
	analysis->dofcnc = 1;
	analysis->reduce = 1;
	analysis->debug = debug;
	analysis->writetree = 0;
	analysis->fcnc_regions = regions;
	if(doplot) analysis->init_hist(inputconfig);
	analysis->init_sample(inputconfig,inputconfig);
	map<int,double> totgenweighted;
	map<int,double> totgenraw;
	map<int,long> nDAODraw;
	double totgenWeighted = 0;
	long totgenRaw = 0;
	double totDAODWeighted = 0;
	long totDAODRaw = 0;

	printf("Reading bin 8\n");
	while(!fn.eof()){
		fn.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char filename[500];
		int dsid;
		if(!isData) sscanf(inputline,"%d %s",&dsid,filename);
		else sscanf(inputline,"%s",filename);
		printf("reading file: DSID: %d name %s\n", dsid, filename);
		TFile inputfile(filename);
		if(!inputfile.Get("h_metadata")) {
			printf("h_metadata not found, exit.\n");
			exit(1);
		}
		if(!isData){
			if(totgenweighted.find(dsid) == totgenweighted.end()) totgenweighted[dsid] = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(8);
			else totgenweighted[dsid] += ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(8);
			if(totgenraw.find(dsid) == totgenraw.end()) totgenraw[dsid] = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
			else totgenraw[dsid] += ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
			if(nDAODraw.find(dsid) == nDAODraw.end()) nDAODraw[dsid] = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
			else nDAODraw[dsid] += ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
			inputfile.Close();
			for (auto pair : totgenraw)
			{
				totgenWeighted += xsecs[pair.first]*luminosity;
				totgenRaw += pair.second;
				totDAODRaw += nDAODraw[pair.first];
				totDAODWeighted += nDAODraw[pair.first]/pair.second*xsecs[pair.first]*luminosity;
			}
		}else{
			totgenWeighted = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
			totgenRaw = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
			totDAODWeighted = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
			totDAODRaw = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
		}
	}

	fn.clear();
	fn.seekg(0, fn.beg);
	TH1D *cutflow = 0;
	TH1D *cutflowraw = 0;
	cutflow = new TH1D("cutflow_HSM_common_weighted","cutflow_HSM_common_weighted",23,0,23);
	cutflowraw = new TH1D("cutflow_HSM_common_raw","cutflow_HSM_common_raw",23,0,23);
	cutflow->Sumw2();
	cutflowraw->Sumw2();
	cutflow->SetBinContent(1,totgenWeighted);
	cutflow->SetBinContent(2,totDAODWeighted);
	cutflowraw->SetBinContent(1,totgenRaw);
	cutflowraw->SetBinContent(2,totDAODRaw);
	cutflow->GetXaxis()->SetBinLabel(1,"Total Events");
	cutflow->GetXaxis()->SetBinLabel(2,"DAOD");
	cutflowraw->GetXaxis()->SetBinLabel(1,"Total Events");
	cutflowraw->GetXaxis()->SetBinLabel(2,"DAOD");
	while(!fn.eof()){
		fn.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char filename[500];
		int dsid;
		if(!isData) sscanf(inputline,"%d %s",&dsid,filename);
		else sscanf(inputline,"%s",filename);
		printf("reading file: DSID: %d name %s\n", isData? 0 : dsid, filename);
		TFile inputfile(filename);
		if(!isData && xsecs.find(dsid) == xsecs.end()) printf("xsec for DSID %d not found, please update your Xsec file\n", dsid);
		TH1D *inputcutflow = (TH1D*)inputfile.Get("cutflow_HSM_common");
		for (int i = 1; i <= inputcutflow->GetNbinsX(); ++i)
		{
			if(TString(cutflow->GetXaxis()->GetBinLabel(i+2)) == "") {
				cutflow->GetXaxis()->SetBinLabel(i+2,inputcutflow->GetXaxis()->GetBinLabel(i));
				cutflowraw->GetXaxis()->SetBinLabel(i+2,inputcutflow->GetXaxis()->GetBinLabel(i));
			}
			double error = cutflow->GetBinContent(i+2) ? cutflow->GetBinError(i+2) : 0;
			cutflow->Fill(i+1,inputcutflow->GetBinContent(i)*(isData?1:xsecs[dsid]*luminosity/totgenraw[dsid]/87));
			printf("bin content %f, bin error: %f, bin content now: %f, error now: %f\n",
				inputcutflow->GetBinContent(i)*(isData?1:xsecs[dsid]*luminosity/totgenraw[dsid]/87),
				inputcutflow->GetBinError(i)*(isData?1:xsecs[dsid]*luminosity/totgenraw[dsid]/sqrt(87)),
				cutflow->GetBinContent(i+2),
				error
			);

			cutflow->SetBinError(i+2, sqrt(pow(error,2) + pow(inputcutflow->GetBinError(i)*(isData?1:xsecs[dsid]*luminosity/totgenraw[dsid]/sqrt(87)),2)));
			error = cutflowraw->GetBinContent(i+2) ? cutflowraw->GetBinError(i+2) : 0;
			cutflowraw->Fill(i+1,inputcutflow->GetBinContent(i)/(isData?1:87));
			cutflow->SetBinError(i+2, sqrt(pow(error,2) + pow(inputcutflow->GetBinError(i)/(isData?1:sqrt(87)),2)));
		}
		analysis->Loop( (TTree*)inputfile.Get("NOMINAL"), inputconfig, isData ? 1 : xsecs[dsid]*luminosity/totgenweighted[dsid]);
		printf("xsecs[%d] = %f\nluminosity=%f\ntotal weight generated:%f\n",dsid,xsecs[dsid],luminosity,totgenweighted[dsid]);
		inputfile.Close();
	}
	cutflow->Write();
	cutflowraw->Write();
	analysis->finalise_sample();
	return 0;
}
