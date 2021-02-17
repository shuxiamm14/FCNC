#define TTHMLVERSION 6
#include "hadhadtree.h"
#if TTHMLVERSION==2
#include "tthmltree_v2.h"
#elif TTHMLVERSION==3
#include "tthmltree_v3.h"
#elif TTHMLVERSION==4
#include "tthmltree_v4.h"
#include "tthmltree_v3.h"
#elif TTHMLVERSION==5
#include "tthmltree_v5.h"
#include "tthmltree_v3.h"
#elif TTHMLVERSION==6
#include "tthmltree_v6.h"
#endif
#include "TROOT.h"
#include "TSystem.h"
#include "weightsys_list.h"
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 5)
	{
		printf("Usage: reduce_run framework(xTFW/tthML) reduce(1/2/3/4/5/6) dataconfigfile(eg. mc16a_wjet.txt) systname(eg. NOMINAL) [optional: 1 for saveweightslist]\n");
		exit(1);
	}
	int debug = 0;
	int reduce = *argv[2]-'0';
	bool doplot = reduce >= 3 ? 1 : 0;
	bool tthdofcnc = 1;
	bool plot_sys = 1;
	bool dofake = 0;
	bool onlyMajorNP = 0; // set to 0 for current xTFW analysis.
	bool applynewSF = 0; //w-jet non-w-jet fake, not available for both hadhad and lephad yet.
	bool nominalOnly = 1;
	TString version = "v3"; //define your n-tuple version
	TString prefix1;
	TString prefix = PACKAGE_DIR;
	TString framework = argv[1];
	if(framework == "tthML") version = TString("v") + char('0'+TTHMLVERSION);
	if(reduce > 4){
		reduce-=2;
		applynewSF = 1;
	}
	if(reduce == 3) {
		dofake = 0;
		tthdofcnc = 1;
	}
	if(reduce == 4){
		dofake = 1;
		tthdofcnc = 0;
		reduce = 2;
	}
	TString samplefile = argv[3];
	TString systname = argv[4];
	if(samplefile.Contains("sys") && systname != "NOMINAL") {
		printf("sys sample doesnt have the systematic trees\n");
		return 0;
	}
	TString samplefilefullname = prefix + "/datafiles/" + framework + "/" + version + "/run/"+ ((systname != "nominal" && framework == "tthML") ? "sys_" : "" ) + samplefile;
	printf("reading list: %s\n",samplefilefullname.Data());
	ifstream fn(samplefilefullname);
	if(!fn) {
	  fprintf(stderr,"can't open file: %s, try %s\n",samplefilefullname.Data(),samplefile.Data());
	  fn.open(argv[1]);
	  if(!fn){
	  	fprintf(stderr,"can't open file: %s\n",argv[1]);
	  	return 1;
	  }
	}
	vector<TString> regions, regions_fake, regions_notau;
	if(framework == "xTFW"){
	        /*regions.push_back("reg2mtau1b2jss");
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
		regions.push_back("reg2mtau1b2jss");
		regions.push_back("reg2ltau1b3jos");*/
		regions.push_back("reg2mtau1b2jss");
        regions.push_back("reg2mtau1b2jos");
        regions.push_back("reg2mtau1b3jos");
        regions.push_back("reg2mtau1b3jss");
        regions.push_back("reg1mtau1ltau1b2jos");
        regions.push_back("reg1ltau1mtau1b2jos");
        regions.push_back("reg1mtau1ltau1b3jos");
        regions.push_back("reg1ltau1mtau1b3jos");
        regions.push_back("reg1ltau1ntau1b2jos");
        regions.push_back("reg1ltau1ntau1b3jos");
        regions.push_back("reg1ntau1ltau1b2jos");
        regions.push_back("reg1ntau1ltau1b3jos");
        regions.push_back("reg2ltau1b2jos");
        regions.push_back("reg2ltau1b3jos");
        regions.push_back("reg1mtau1ltau1b2jss");
        regions.push_back("reg1ltau1mtau1b2jss");
        regions.push_back("reg1mtau1ltau1b3jss");
        regions.push_back("reg1ltau1mtau1b3jss");
        regions.push_back("reg1ltau1ntau1b2jss");
        regions.push_back("reg1ltau1ntau1b3jss");
        regions.push_back("reg1ntau1ltau1b2jss");
        regions.push_back("reg1ntau1ltau1b3jss");
        regions.push_back("reg2ltau1b2jss");
        regions.push_back("reg2ltau1b3jss");
		// new
		regions.push_back("reg1lnmtau1mtau1b2jss");
        regions.push_back("reg1lnmtau1mtau1b2jos");
        regions.push_back("reg1lnmtau1mtau1b3jss");
        regions.push_back("reg1lnmtau1mtau1b3jos");
        regions.push_back("reg1mtau1lnmtau1b2jss");
        regions.push_back("reg1mtau1lnmtau1b2jos");
        regions.push_back("reg1mtau1lnmtau1b3jss");
        regions.push_back("reg1mtau1lnmtau1b3jos");
        //regions.push_back("reg2mtau1b5jos");
        //regions.push_back("reg2mtau1b5jss");
        //regions.push_back("reg1mtau1ltau1b5jos");
        //regions.push_back("reg1ltau1mtau1b5jos");
        //regions.push_back("reg1ltau1ntau1b5jos");
        //regions.push_back("reg1ntau1ltau1b5jos");
        //regions.push_back("reg2ltau1b5jos");
	}else{
		if(tthdofcnc || reduce == 1){
//			regions.push_back("reg1l1tau1b_os");
			regions.push_back("reg1l1tau1b_ss");
//			regions.push_back("reg1l1tau1b1j_os");
			regions.push_back("reg1l1tau1b1j_ss");
			regions.push_back("reg1l1tau1b2j_os");
			regions.push_back("reg1l1tau1b2j_ss");
			regions.push_back("reg1l1tau1b3j_os");
//			regions.push_back("reg1l1tau1b3j_ss");
//			regions.push_back("reg1l1tau1b_os_antiiso");
			regions.push_back("reg1l1tau1b_ss_antiiso");
//			regions.push_back("reg1l1tau1b1j_os_antiiso");
			regions.push_back("reg1l1tau1b1j_ss_antiiso");
			regions.push_back("reg1l1tau1b2j_os_antiiso");
			regions.push_back("reg1l1tau1b2j_ss_antiiso");
			regions.push_back("reg1l1tau1b3j_os_antiiso");
//			regions.push_back("reg1l1tau1b3j_ss_antiiso");
			regions.push_back("reg2l1tau1bnj");
			regions.push_back("reg2l1tau2bnj");
//			regions.push_back("reg1l1tau2b_os");
//			regions.push_back("reg1l1tau2b_ss");
//			regions.push_back("reg1l1tau2b1j_os");
//			regions.push_back("reg1l1tau2b1j_ss");
			regions.push_back("reg1l1tau2b2j_os");
			regions.push_back("reg1l1tau2b2j_ss");
			regions.push_back("reg1l1tau2b3j_os");
			regions.push_back("reg1l1tau2b3j_ss");
			regions.push_back("reg1l2tau1bnj_os");
			regions.push_back("reg1l2tau1bnj_ss");
//			regions.push_back("reg1l2tau2bnj_os");
//			regions.push_back("reg1l2tau2bnj_ss");
//			regions.push_back("reg2lSS1tau1bnj_os");
//			regions.push_back("reg2lSS1tau1bnj_os_antiiso");
//			regions.push_back("reg2lSS1tau1bnj_os_antiisolead");
//			regions.push_back("reg2l1bnj");
//			regions.push_back("reg2l2bnj");
//			regions.push_back("reg2lSSnj");
//			regions.push_back("reg2lSS1bnj");
//			regions.push_back("reg2lSS2bnj");

			//regions.push_back("reg2lSS1tau1bnj_ss");
			//regions.push_back("reg2lSS1tau2bnj_os");
			//regions.push_back("reg2lSS1tau2bnj_ss");
			//regions.push_back("reg2lSS1tau1bnj_ss_antiiso");
			//regions.push_back("reg2lSS1tau2bnj_os_antiiso");
			//regions.push_back("reg2lSS1tau2bnj_ss_antiiso");
		}
		if(dofake || reduce == 1){
			regions_fake.push_back("reg2lSS1taunj_os");
			regions_fake.push_back("reg2lSS1taunj_os_antiiso");
			regions_fake.push_back("reg2lSS1taunj_os_antiisolead");
//			regions_fake.push_back("reg2l1tau2b");
//			regions_fake.push_back("reg1l1tau2b1j_os");
//			regions_fake.push_back("reg1l1tau2b1j_ss");
//			regions_fake.push_back("reg1l1tau2b_os");
//			regions_fake.push_back("reg1l1tau2b_ss");
//			regions_fake.push_back("reg2l1tau1b");
		}

	}
	
	TString inputconfig = samplefile;
	inputconfig.Remove(inputconfig.Sizeof()-5,4); //remove ".txt"
	gSystem->mkdir(prefix+"/data");
	gSystem->mkdir(prefix+"/data/" + version);
	if(!debug) gErrorIgnoreLevel=kError;
	nominal *analysis;
	if(framework == "xTFW") analysis = new hadhadtree();
	else if(framework == "tthML") {
#if TTHMLVERSION==2
		analysis = new tthmltree_v2();
		analysis->version = 7;
		if(inputconfig.Contains("ml"))
		analysis->version = 5;
#elif TTHMLVERSION==3
		analysis = new tthmltree_v3();
#elif TTHMLVERSION==4
		if(inputconfig.Contains("fcnc"))
			analysis = new tthmltree_v3();
		else analysis = new tthmltree_v4();
#elif TTHMLVERSION==5
		if(inputconfig.Contains("fcnc"))
			analysis = new tthmltree_v3();
		else analysis = new tthmltree_v5();
#elif TTHMLVERSION==6
		analysis = new tthmltree_v6();
#endif
	}
	analysis->SystematicsName = systname;
	analysis->dumptruth = 0;
	analysis->dumpeventnumber = 0;
	analysis->dofit = 1;
	analysis->reduce = reduce;
	analysis->debug = debug;
	analysis->plotTauFake = 1;
	analysis->ctagFCNC = 0;
	analysis->mergeProngFF = 0;  //Should be merge prong SF
	if(applynewSF) {
		analysis->plotProng = 0;
		analysis->plotLeptype = 1;
		analysis->doBDT = 1;
	}
	else {
		analysis->plotProng = 1;
		analysis->plotLeptype = 0;
		if(framework=="tthML") analysis->doBDT = 0;
	}
	analysis->fit_collinear = 1;
	analysis->mass_collinear = 0;
	analysis->dataDir = prefix+"/data/" + version;
	analysis->nominaltree = inputconfig.Contains("sys")? 0 : (analysis->SystematicsName == "NOMINAL" || analysis->SystematicsName == "nominal");
	analysis->writetree = (reduce == 1 || (reduce == 2 && !dofake)) ? 1:0;
	analysis->doubleCounting = 1;
  	analysis->belong_regions.enable(regions);
	if(framework == "xTFW") analysis->xTFWfakeNPlist_=xTFWfakeNPlist;
    char inputline[500];
	if(reduce > 1){
        if(framework == "xTFW")analysis->dovetobwp["btagwp70"] = 1;
		if(framework == "tthML"){
			if(!dofake) {
				analysis->dovetobwp["btagwp70"] = 1;
				analysis->fcnc_regions = regions;
			}
			else {
				doplot = 1;
				analysis->writetree = 0;
				analysis->dovetobwp["btagwp70"] = 1;
				//analysis->dobwp["btagwp70"] = 1;
				//analysis->dobwp["btagwp85"] = 1;
				analysis->belong_regions.enable(regions_fake);
				analysis->belong_regions.enable(regions_notau);
				analysis->fake_regions = regions_fake;
				analysis->fake_regions_notau = regions_notau;
				regions = regions_fake;
				regions.insert(regions.end(),regions_notau.begin(),regions_notau.end());
			}
			analysis->dumpeventnumber = 0;
		}
		if(doplot) {
			analysis->plotNPs.push_back("NOMINAL");
			if(!inputconfig.Contains("data")){
				if(analysis->nominaltree == 1 && !nominalOnly){
					//for(auto v: fakeNPlist) analysis->plotNPs.push_back(v);
					if(plot_sys){
						if(onlyMajorNP){
							if(framework == "tthML") for(auto v: tthMLmajorNPlist) analysis->plotNPs.push_back(v);
							else for(auto v: xTFWmajorNPlist) analysis->plotNPs.push_back(v);
						}else{
							//if(framework == "tthML") for(auto v: tthMLNPlist) analysis->plotNPs.push_back(v);
							//else {for(auto v: xTFWNPlist) analysis->plotNPs.push_back(v);
							//for(auto v: theoryNPlist) analysis->plotNPs.push_back(v);
							//for(auto v: commonNPlist) analysis->plotNPs.push_back(v);
                                                        //for(auto v: xsecNPlist) analysis->plotNPs.push_back(v);
							if(framework != "tthML") for(auto v: xTFWfakeNPlist) analysis->plotNPs.push_back(v);
							if(applynewSF)
								for(auto v: tthMLfakeNPlist)
									if(v.Contains("fakeSFNP")) analysis->plotNPs.push_back(v);
						}
					}
				}
			}
			for(auto NPs: analysis->plotNPs) printf("Plotting NPs: %s\n",NPs.Data());
			if(applynewSF) analysis->ConfigNewFakeSF();
			analysis->fcnc_regions = regions;
			analysis->init_hist(inputconfig);
		}
	        analysis->fcnc_regions = regions;
        	analysis->init_sample(inputconfig,inputconfig);
		TString inputfilename = prefix + "/data/" + version + "/" + framework + "reduce" + to_string(reduce-1) + "/" + analysis->SystematicsName + "/" + inputconfig + "_tree.root";
		TString inputfilename_nominal = prefix + "/data/" + version + "/" + framework + "reduce" + to_string(reduce-1) + "/nominal/" + inputconfig + "_tree.root";
		printf("reading file: %s\n", inputfilename.Data());
		TFile inputfile(inputfilename,"read");
		TFile *inputfile_nominal = 0;
		if(!analysis->nominaltree && framework == "tthML" && reduce == 2) {
			printf("reading nominal file to get truth: %s\n", inputfilename_nominal.Data());
			inputfile_nominal = new TFile(inputfilename_nominal,"read");
		}
		for(auto reg : regions){
			printf("Loop region: %s\n", reg.Data());

			if(!analysis->nominaltree && framework == "tthML" && reduce == 2){
				TTree *nominalinputtree;
				inputfile_nominal->GetObject(reg,nominalinputtree);
				analysis->constructwmatchmap(nominalinputtree);
			}
			if(analysis->plotTauFake || reg.Contains("2l") || reduce <=2) analysis->Loop( (TTree*)inputfile.Get(reg), inputconfig, 1);
			else printf("region is disabled in plotting lepton fakes, skip\n");
		}
		analysis->finalise_sample();
		printf("finished reduce\n");
			printf("We need a crash here to terminate the job. Otherwise the destruction of the histograms takes forever. This is on purpose, don't worry.\n");
			std::vector<int> crasher;
			crasher.at(1);
		delete analysis;
		return 0;
	}
	analysis->fcnc_regions = regions;
	if(framework == "tthML"){
		analysis->fake_regions = regions_fake;
		analysis->fake_regions_notau = regions_notau;
		analysis->belong_regions.enable(regions_fake);
		analysis->belong_regions.enable(regions_notau);

	}
	analysis->init_sample(inputconfig,inputconfig);

	float luminosity = 0;
	bool isData = 0;
	if(inputconfig.Contains("data")) isData = 1;
	else if(inputconfig.Contains("mc16a")) luminosity = 3.219555072 + 32.988125184;
	else if(inputconfig.Contains("mc16d")) luminosity = 44.30739456; //No event passed GRL in run 338377 in v3, reason unknown.
	else if(inputconfig.Contains("mc16e")) luminosity = 59.93723904;
	else {
		printf("Wrong config file name, cannot recognise mc campaign: %s\n", inputconfig.Data());
		exit(0);
	}
	analysis->isData = isData;
	map<int, float> xsecs;
	if(!isData){          //Register Xsections
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
		cutflowweighted = new TH1D("cutflow_HSM_common_weighted","cutflow_HSM_common_weighted",24,0,23);
		cutflowraw = new TH1D("cutflow_HSM_common_raw","cutflow_HSM_common_raw",24,0,23);
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
		TString weightfilename = prefix + "/datafiles/" + framework;
		if(version == "v3") weightfilename += "/v3/run/" + samplefile;
		else weightfilename = samplefilefullname;
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
			float totalEventsWeighted = 0;
			weighttree->SetBranchAddress("names_mc_generator_weights",&weightname);
			weighttree->SetBranchAddress("totalEventsWeighted_mc_generator_weights", &weightsum);
			weighttree->SetBranchAddress("totalEventsWeighted", &totalEventsWeighted);
			int nentries = weighttree->GetEntries();
			printf("Loop over %d entries for weight sum\n", nentries);
			for (int i = 0; i < nentries; ++i)
			{
				weighttree->GetEntry(i);
				if(theoryweightsum.find(dsid) == theoryweightsum.end()) {
					theoryweightsum[dsid] = new TH1D(("theory_"+to_string(dsid)).c_str(), ("theory_"+to_string(dsid)).c_str(), weightname->size(), 0, weightname->size());
					theoryweightsum[dsid]->SetDirectory(gROOT);
					for(int j = 0; j<weightname->size(); j++){
						theoryweightsum[dsid]->GetXaxis()->SetBinLabel(j+1,weightname->at(j).c_str());
					//	printf("Weight name : %s;",weightname->at(j).c_str());
					}
				}
				totgenweighted[dsid] += totalEventsWeighted;
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
		if(framework == "xTFW"&&analysis->nominaltree){
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
			if(dsid != lastdsid && lastdsid != -1 && inputconfig.Contains("mc16a")) {
				gSystem->mkdir(prefix + "/config/theoryweightlist");
				if(analysis->nominaltree) analysis->saveweightslist(prefix + "/config/theoryweightlist/" + framework + "_" + to_string(lastdsid) + ".txt");
			}
			if(dsid != lastdsid) analysis->init_dsid();
			//if(framework == "tthML" && inputconfig.Contains("ml") && analysis->TTHMLVERSION == 5) ((tthmltree_v2*)analysis)->mc_norm = xsecs[dsid]*luminosity/totgenweighted[dsid];
			analysis->Loop( (TTree*)inputfile.Get(systname), inputconfig, (framework == "xTFW")? xsecs[dsid]*luminosity/totgenweighted[dsid] : 1);
			if(framework == "xTFW") printf("xsecs[%d] = %f\nluminosity=%f\ntotal weight generated:%f\n",dsid,xsecs[dsid],luminosity,totgenweighted[dsid]);
		}
		inputfile.Close();
		lastdsid = dsid;
	}
	analysis->cut_flow.print();
  	analysis->cut_flow.save(5);
  	analysis->cut_flow.clear();
	if(inputconfig.Contains("mc16a")) {
		gSystem->mkdir(prefix + "/config/theoryweightlist");
		if(analysis->nominaltree) analysis->saveweightslist(prefix + "/config/theoryweightlist/" + framework + "_" + to_string(lastdsid) + ".txt");
	}
	if(framework == "xTFW"){
		analysis->outputtreefile->cd();
		cutflowweighted->Write();
		cutflowraw->Write();
	}
	analysis->finalise_sample();
	return 0;
}
