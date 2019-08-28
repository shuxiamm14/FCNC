#include "hadhadtree.h"
#include "tthmltree.h"
#include "TROOT.h"
#include "TSystem.h"
using namespace std;
int main(int argc, char const *argv[])
{
	if (argc < 5)
	{
		printf("Usage: reduce_run framework(xTFW/tthML) reduce(1/2/3) dataconfigfile(eg. mc16a_wjet.txt) systname(eg. NOMINAL) [optional: 1 for saveweightslist]\n");
		exit(1);
	}
	bool debug = 0;
	bool doplot = 0;
	bool dofake = 0;
	TString prefix1;
	TString prefix = PACKAGE_DIR;
	TString framework = argv[1];
	int reduce = *argv[2]-'0';
	doplot = reduce == 3 ? 1 : 0;
	TString samplefile = argv[3];
	TString systname = argv[4];
	TString samplefilefullname = prefix + "/datafiles/" + framework + "/v2/run/" + samplefile;
	ifstream fn(samplefilefullname);
	if(!fn) {
	  fprintf(stderr,"can't open file: %s, try %s\n",samplefilefullname.Data(),samplefile.Data());
	  fn.open(argv[1]);
	  if(!fn){
	  	fprintf(stderr,"can't open file: %s\n",argv[1]);
	  	return 1;
	  }
	}
	if(samplefile.Contains("sys") && systname != "NOMINAL") {
		printf("sys sample doesnt have the systematic trees\n");
		return 0;
	}
	vector<TString> regions, regions_fake, regions_notau;
	if(framework == "xTFW"){
		regions.push_back("reg2mtau1b2jss");
		regions.push_back("reg2mtau1b3jss");
		regions.push_back("reg2mtau1b3jos");
		regions.push_back("reg2mtau1b2jos");
		regions.push_back("reg2mtau2b2jss");
		regions.push_back("reg2mtau2b3jss");
		regions.push_back("reg2mtau2b3jos");
		regions.push_back("reg2mtau2b2jos");
		regions.push_back("reg1mtau1ltau1b2jss");
		regions.push_back("reg2ltau1b2jss");
		regions.push_back("reg2ttau1b2jss");
		regions.push_back("reg1ttau1mtau1b2jss");
		regions.push_back("reg1mtau1ltau1b3jss");
		regions.push_back("reg2ltau1b3jss");
		regions.push_back("reg2ttau1b3jss");
		regions.push_back("reg1ttau1mtau1b3jss");
		regions.push_back("reg1mtau1ltau1b2jos");
		regions.push_back("reg2ltau1b2jos");
		regions.push_back("reg1mtau1ltau1b3jos");
		regions.push_back("reg2ltau1b3jos");
		regions.push_back("reg2ttau1b2jos");
		regions.push_back("reg1ttau1mtau1b2jos");
		regions.push_back("reg2ttau1b3jos");
		regions.push_back("reg1ttau1mtau1b3jos");
	}else{
		regions.push_back("reg1l1tau1b2j_os");
		regions.push_back("reg1l1tau1b3j_os");
		regions.push_back("reg1l1tau2b2j_os");
		regions.push_back("reg1l1tau2b3j_os");
		regions.push_back("reg1l1tau1b2j_ss");
		regions.push_back("reg1l1tau1b3j_ss");
		regions.push_back("reg1l1tau2b2j_ss");
		regions.push_back("reg1l1tau2b3j_ss");
		regions.push_back("reg1l2tau1bnj_os");
		regions.push_back("reg1l2tau1bnj_ss");
		regions.push_back("reg1l2tau2bnj_os");
		regions.push_back("reg1l2tau2bnj_ss");
		regions_fake.push_back("reg1e1mu1tau2b");
		regions_fake.push_back("reg1l1tau2b1j_os");
		regions_fake.push_back("reg1l1tau2b1j_ss");
		regions_fake.push_back("reg1l1tau2b_os");
		regions_fake.push_back("reg1l1tau2b_ss");
		regions_fake.push_back("reg1e1mu1tau1b");
		regions_notau.push_back("reg1e1mu2bnj");
		regions_notau.push_back("reg1l2b2j");
		regions_notau.push_back("reg1e1mu2b");

	}
	
	TString inputconfig = samplefile;
	inputconfig.Remove(inputconfig.Sizeof()-5,4); //remove ".txt"
	gSystem->mkdir(prefix+"/data");
	if(!debug) gErrorIgnoreLevel=kError;
	nominal *analysis;
	if(framework == "xTFW") analysis = new hadhadtree();
	else if(framework == "tthML") {
		analysis = new tthmltree();
		analysis->version = 7;
	}
	analysis->SystematicsName = systname;
	analysis->dumptruth = 0;
	analysis->reduce = reduce;
	analysis->debug = debug;
	analysis->fcnc_regions = regions;
	analysis->nominaltree = inputconfig.Contains("sys")? 0 : (analysis->SystematicsName == "NOMINAL" || analysis->SystematicsName == "nominal");
	analysis->writetree = reduce <= 2 ? 1:0;
	if(framework == "xTFW") {
		if(reduce == 1) analysis->init_reduce1();
		else analysis->init_reduce2();
	}
	if(framework == "tthML" && reduce <= 2) {
		analysis->fake_regions = regions_fake;
		analysis->fake_regions_notau = regions_notau;
	}
	char inputline[500];

	if(reduce > 1){
		if(framework == "tthML"){
			if(!dofake) {
				doplot = 1;
				analysis->writetree = 0;
				analysis->dovetobwp["btagwp70"] = 1;
				analysis->fcnc_regions = regions;
			}
			else {
				analysis->dovetobwp["btagwp70"] = 1;
				analysis->dobwp["btagwp70"] = 1;
				analysis->dobwp["btagwp85"] = 1;
			}
			analysis->dumpeventnumber = 1;
			regions.insert(regions.end(),regions_fake.begin(),regions_fake.end());
			regions.insert(regions.end(),regions_notau.begin(),regions_notau.end());
		}
		if(doplot) {
			if(!inputconfig.Contains("data")){
				if(analysis->nominaltree == 1 )
					for(int i = 0; i < 124; ++i) {
						analysis->plotNPs.push_back(i);
					}
				else analysis->plotNPs.push_back(1);
			}else  analysis->plotNPs.push_back(0);
		}
		analysis->init_hist(inputconfig);
		analysis->init_sample(inputconfig,inputconfig);
		TString inputfilename = prefix + "/data/" + framework + "reduce" + to_string(reduce-1) + "/" + analysis->SystematicsName + "/" + inputconfig + "_tree.root";
		printf("reading file: %s\n", inputfilename.Data());
		TFile inputfile(inputfilename);
		for(auto reg : regions){
			printf("Loop region: %s\n", reg.Data());
			analysis->Loop( (TTree*)inputfile.Get(reg), inputconfig, 1);
		}
		inputfile.Close();
		analysis->finalise_sample();
		return 0;
	}
	analysis->init_sample(inputconfig,inputconfig);

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
	map<int, float> xsecs;
	if(!isData && framework == "xTFW"){
		printf("reading cross section file: %s\n", (prefix + "/config/Xsecs.txt").Data());
		ifstream xsecfile(prefix + "/config/Xsecs.txt");
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

	map<int,double> totgenweighted;
	map<int,double> totgenraw;
	map<int,long> nDAODraw;
	map<int,TH1D*> theoryweightsum;
	double totgenWeighted = 0;
	long totgenRaw = 0;
	double totDAODWeighted = 0;
	long totDAODRaw = 0;

	double totgenWeightederr = 0;
	double totDAODWeightederr = 0;
	TH1D *cutflowweighted = 0;
	TH1D *cutflowraw = 0;

	printf("Reading bin 8 and theory weight sum\n");
	if(framework == "xTFW"){
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
				TH1D *theoryhisttmp = ((TH1D*)inputfile.Get("h_metadata_theory_weights"));
				if(totgenweighted.find(dsid) == totgenweighted.end()) {
					totgenweighted[dsid] = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(8);
					if(analysis->nominaltree) {
						theoryweightsum[dsid] = (TH1D*)theoryhisttmp->Clone(("theory_" + to_string(dsid)).c_str());
						theoryweightsum[dsid]->SetDirectory(gROOT);
					}
				}
				else{
					totgenweighted[dsid] += ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(8);
					if(analysis->nominaltree) theoryweightsum[dsid]->Add(theoryhisttmp);
				}
	
				if(totgenraw.find(dsid) == totgenraw.end()) totgenraw[dsid] = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
				else totgenraw[dsid] += ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
				if(nDAODraw.find(dsid) == nDAODraw.end()) nDAODraw[dsid] = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
				else nDAODraw[dsid] += ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
				inputfile.Close();
			}else{
				totgenWeighted = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
				totgenRaw = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(7);
				totDAODWeighted = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
				totDAODRaw = ((TH1*)inputfile.Get("h_metadata"))->GetBinContent(10);
				totgenWeightederr = ((TH1*)inputfile.Get("h_metadata"))->GetBinError(7);
				totDAODWeightederr = ((TH1*)inputfile.Get("h_metadata"))->GetBinError(10);
			}
		}
		if(!isData){
			for (auto pair : totgenraw)
			{
				totgenWeighted += xsecs[pair.first]*luminosity;
				totgenWeightederr += pair.second/pow(pair.second*xsecs[pair.first]*luminosity,2);
				totgenRaw += pair.second;
				totDAODRaw += nDAODraw[pair.first];
				totDAODWeighted += nDAODraw[pair.first]/pair.second*xsecs[pair.first]*luminosity;
				totDAODWeightederr += nDAODraw[pair.first]/pow(pair.second*xsecs[pair.first]*luminosity,2);
			}
			totgenWeightederr = sqrt(totgenWeightederr);
			totDAODWeightederr = sqrt(totDAODWeightederr);
		}
	
		fn.clear();
		fn.seekg(0, fn.beg);
		cutflowweighted = new TH1D("cutflow_HSM_common_weighted","cutflow_HSM_common_weighted",23,0,23);
		cutflowraw = new TH1D("cutflow_HSM_common_raw","cutflow_HSM_common_raw",23,0,23);
		cutflowweighted->Sumw2();
		cutflowraw->Sumw2();
		cutflowweighted->SetBinContent(1,totgenWeighted);
		cutflowweighted->SetBinContent(2,totDAODWeighted);
		cutflowraw->SetBinContent(1,totgenRaw);
		cutflowraw->SetBinContent(2,totDAODRaw);
		cutflowweighted->SetBinError(1,totgenWeightederr);
		cutflowweighted->SetBinError(2,totDAODWeightederr);
		cutflowraw->SetBinError(1,sqrt((double)totgenRaw));
		cutflowraw->SetBinError(2,sqrt((double)totDAODRaw));
		cutflowweighted->GetXaxis()->SetBinLabel(1,"Total Events");
		cutflowweighted->GetXaxis()->SetBinLabel(2,"DAOD");
		cutflowraw->GetXaxis()->SetBinLabel(1,"Total Events");
		cutflowraw->GetXaxis()->SetBinLabel(2,"DAOD");
	}else if(analysis->nominaltree && !isData){
		TString weightfilename = prefix + "/datafiles/" + framework + "/v2/run/weightsum_" + samplefile;
		printf("Read weightSum file: %s\n", weightfilename.Data());
		ifstream wtfn(weightfilename);
		while(!wtfn.eof()){
			wtfn.getline(inputline,500);
			if(strlen(inputline)==0) continue;
			if(inputline[0]=='#') continue;
			char filename[500];
			int dsid;
			if(!isData) sscanf(inputline,"%d %s",&dsid,filename);
			else sscanf(inputline,"%s",filename);
			printf("reading file: DSID: %d name %s\n", dsid, filename);
			TFile inputfile(filename);
			TTree *weighttree = (TTree*)inputfile.Get("sumWeights");
			if(!weighttree) {
				printf("sumWeights not found, exit.\n");
				exit(1);
			}
			vector<float>* weightsum = new vector<float>();
			vector<string>* weightname = new vector<string>();
			weighttree->SetBranchAddress("names_mc_generator_weights",&weightname);
			weighttree->SetBranchAddress("totalEventsWeighted_mc_generator_weights", &weightsum);
			int nentries = weighttree->GetEntries();
			printf("Loop over %d entries for weight sum\n", nentries);
			for (int i = 0; i < nentries; ++i)
			{
				weighttree->GetEntry(i);
				if(theoryweightsum.find(dsid) == theoryweightsum.end()) {
					theoryweightsum[dsid] = new TH1D(("theory_"+to_string(dsid)).c_str(), ("theory_"+to_string(dsid)).c_str(), weightname->size(), 0, weightname->size());
					theoryweightsum[dsid]->SetDirectory(gROOT);
					for(int j = 0; j<weightname->size(); j++) theoryweightsum[dsid]->GetXaxis()->SetBinLabel(j+1,weightname->at(j).c_str());
				}
				for(int j = 0; j<weightname->size(); j++) theoryweightsum[dsid]->Fill(j,weightsum->at(j));
			}
		}
	}
	int lastdsid = -1;
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
		if(framework == "xTFW"){
			if(!isData && xsecs.find(dsid) == xsecs.end())
				printf("xsec for DSID %d not found, please update your Xsec file\n", dsid);
			TH1D *inputcutflow = (TH1D*)inputfile.Get("cutflow_HSM_common");
			for (int i = 1; i <= inputcutflow->GetNbinsX(); ++i)
			{
				if(TString(cutflowweighted->GetXaxis()->GetBinLabel(i+2)) == "") {
					cutflowweighted->GetXaxis()->SetBinLabel(i+2,inputcutflow->GetXaxis()->GetBinLabel(i));
					cutflowraw->GetXaxis()->SetBinLabel(i+2,inputcutflow->GetXaxis()->GetBinLabel(i));
				}
				double error = cutflowweighted->GetBinContent(i+2) ? cutflowweighted->GetBinError(i+2) : 0;
				error = sqrt(pow(error,2) + pow(inputcutflow->GetBinError(i)*(isData?1:xsecs[dsid]*luminosity/totgenraw[dsid]),2));
				cutflowweighted->Fill(i+1,inputcutflow->GetBinContent(i)*(isData?1:xsecs[dsid]*luminosity/totgenraw[dsid]));
				cutflowweighted->SetBinError(i+2, error);
				error = cutflowraw->GetBinContent(i+2) ? cutflowraw->GetBinError(i+2) : 0;
				cutflowraw->Fill(i+1,inputcutflow->GetBinContent(i));
				cutflowraw->SetBinError(i+2, sqrt(pow(error,2) + pow(inputcutflow->GetBinError(i),2)));
			}
		}
		if(isData) analysis->Loop( (TTree*)inputfile.Get(systname), inputconfig, 1.);
		else {
			if(analysis->nominaltree) {
				analysis->theoryweightsum=theoryweightsum[dsid];
			}
			analysis->Loop( (TTree*)inputfile.Get(systname), inputconfig, framework == "xTFW"? xsecs[dsid]*luminosity/totgenweighted[dsid] : 1);
		}
		printf("xsecs[%d] = %f\nluminosity=%f\ntotal weight generated:%f\n",dsid,xsecs[dsid],luminosity,totgenweighted[dsid]);
		inputfile.Close();
		gSystem->mkdir(prefix + "/config/theoryweightlist");
		if(dsid != lastdsid && inputconfig.Contains("mc16a")) analysis->saveweightslist(prefix + "/config/theoryweightlist/" + framework + "_" + to_string(dsid) + ".txt");
		lastdsid = dsid;
	}
	if(framework == "xTFW"){
		analysis->outputtreefile->cd();
		cutflowweighted->Write();
		cutflowraw->Write();
	}
	analysis->finalise_sample();
	return 0;
}
