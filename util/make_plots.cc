#include "histSaver.h"
#include "TH1D.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <sys/ioctl.h>
#include "observable.h"
#include "fcnc_include.h"
#include "weightsys_list.h"
using namespace std;

TFile *getFile(TString sample, TString NPdir, TString NPname, TString nominaldir, TString nominalname){
	TFile *inputfile = new TFile(NPdir + "/" + sample + "_" + (NPdir==nominaldir? NPname : nominalname) + ".root");
	if(inputfile->IsZombie()) {
		deletepointer(inputfile);
		inputfile = new TFile(nominaldir + "/" + sample + "_" + nominalname + ".root");
	}
	return inputfile;
}

void plot(int iNP, TString framework)
{
	TString dirname;
	TString NPname = findNPname(dirname,iNP,framework);
	TString nominalname = "fakeSF_tthML";
	float BRbenchmark = 0.2;
	bool calibfake = 1;
	bool fakeMC = 0;
	bool doTrex = 0;
	bool plotnj = 0;
	bool doPlots = 1;
	int plot_option = 2;
	histSaver *tau_plots = new histSaver("dummy");
	tau_plots->doROC = 0;
	tau_plots->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV, 140 fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
	tau_plots->debug = 1;
	vector<TString> samples;
	samples.push_back("smhiggs");
	samples.push_back("wjet");
	samples.push_back("diboson");
	samples.push_back("zll");
	samples.push_back("ztautau");
	samples.push_back("top");
	samples.push_back("fcnc_ch");
	samples.push_back("fcnc_prod_ch");
	samples.push_back("tcH");
	samples.push_back("fcnc_uh");
	samples.push_back("fcnc_prod_uh");
	samples.push_back("tuH");
 	double norm[] = {1,1,1,1,1,1,BRbenchmark*(framework == "xTFW"? 1:5),BRbenchmark*(framework == "xTFW"? 1:5),BRbenchmark*(framework == "xTFW"? 1:5),BRbenchmark*(framework == "xTFW"? 1:5),BRbenchmark*(framework == "xTFW"? 1:5),BRbenchmark*(framework == "xTFW"? 1:5)};
	vector<TString> sampletitle;
	sampletitle.push_back("SM Higgs");
	sampletitle.push_back("W+jets");
	sampletitle.push_back("Diboson");
	sampletitle.push_back("Z#rightarrowll");
	sampletitle.push_back("Z#rightarrow#tau#tau");
	sampletitle.push_back("Top production");
	sampletitle.push_back("#bar{t}t#rightarrowbWcH");
	sampletitle.push_back("ctH Prod Mode");
	sampletitle.push_back("tcH merged signal");
	sampletitle.push_back("#bar{t}t#rightarrowbWuH");
	sampletitle.push_back("utH Prod Mode");
	sampletitle.push_back("tuH merged signal");

	map<TString,vector<TString>> signalmap = {
		{"tcH",{"fcnc_ch_lv","fcnc_ch_qq","fcnc_prod_ch"}},
		{"tuH",{"fcnc_uh_lv","fcnc_uh_qq","fcnc_prod_uh"}},
		{"fcnc_ch",{"fcnc_ch_lv","fcnc_ch_qq"}},
		{"fcnc_uh",{"fcnc_uh_lv","fcnc_uh_qq"}},
	};
	TString samplesys = "";
	if(NPname.Contains("ttbar")){
		samplesys = "top";
	}

	tau_plots->sensitivevariable = "BDTG_test";
	if(framework == "tthML"){
		if(plotnj){
  			tau_plots->add("N_{l-jet}","njet","",1);
			tau_plots->muteregion("3j");
			tau_plots->muteregion("2j");
		}else{
			tau_plots->sensitivevariable = "BDTG_test";
			tau_plots->add("BDT discriminant","BDTG_test","",10);
    		//tau_plots->add("#DeltaR(l,b-jet)","drlb","",3);
    		//tau_plots->add("#chi^{2}","chi2","",5);
    		//tau_plots->add("M_{all}","allmass","",5);
    		//tau_plots->add("p_{Z,all}","allpz","",5);
    		//tau_plots->add("M(light-jet,light-jet,min)","mjjmin","GeV",5);
  			//tau_plots->add("m_{t,SM}","t1mass","GeV",5);
  			//tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  			//tau_plots->add("m_{W}","wmass","GeV",5);
  			//tau_plots->add("m_{t,FCNC}","t2mass","GeV",5);
  			//tau_plots->add("m_{#tau#tau,vis}","tautauvismass","GeV",10);
  			//tau_plots->add("m_{t,FCNC,vis}","t2vismass","GeV",10);
  			//tau_plots->add("P_{t,#tau#tau,vis}","tautauvispt","GeV",10);
  			//tau_plots->add("m^{T}_{W}","mtw","GeV",10);
  			//tau_plots->add("m_{t,SM,vis}","t1vismass","GeV",15);
  			//tau_plots->add("#DeltaR(l+b-jet,#tau+#tau)","drlbditau","",5);
  			//tau_plots->add("#eta_{#tau,max}","etamax","",10);
  			//tau_plots->add("#DeltaR(l,#tau)","drltau","",8);
  			//tau_plots->add("#DeltaR(#tau,fcnc-j)","drtauj","",10);
  			//tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",4);
  			//tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  			//tau_plots->add("M(#tau#tau#light-jet,min)","mtaujmin","",5);
  			//tau_plots->add("E^{T}_{miss}","etmiss","GeV",10);
    		//tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",6);
    		//tau_plots->add("E^{T}_{miss} centrality","phicent","",3);
  			//tau_plots->add("p_{T,lead-#tau}","taupt_0","GeV",1);
  			//tau_plots->add("p_{T,sublead-#tau}","taupt_1","GeV",1);
  			//tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",5);
  			//tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",5);
  		}
  	}else{
		tau_plots->add("BDT discriminant","BDTG_test","",5);
		//tau_plots->add("BDT discriminant","BDTG_train","",5);
  		//tau_plots->add("p_{T,lead-#tau}","tau_0_pt","GeV",5);
  		//tau_plots->add("p_{T,sublead-#tau}","tau_1_pt","GeV",5);
  		//tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",5);
  		//tau_plots->add("m_{#tau#tau,vis}","ttvismass","",5);
  		//tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",5);
  		//tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  		//tau_plots->add("E^{T}_{miss} centrality","phicent","",5);
  		//tau_plots->add("m_{t,SM}","t1mass","GeV",20);
  		//tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  		//tau_plots->add("m_{W}","wmass","GeV",5);
  		//tau_plots->add("m_{t,FCNC}","t2mass","GeV",20);
  		//tau_plots->add("E^{T}_{miss}","etmiss","GeV",5);
  		//tau_plots->add("#chi^2","chi2","",5);
  		//tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",5);
  		//tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",5);
	}
  	gErrorIgnoreLevel = kWarning;
  	tau_plots->blinding = 1;
	vector<TString> regions_xTFW = {
		//"reg1mtau1ltau1b2jss",
		//"reg2ltau1b2jss",
		//"reg1mtau1ltau1b3jss",
		//"reg2ltau1b3jss",
		//"reg1mtau1ltau1b2jos",
		//"reg2ltau1b2jos",
		//"reg1mtau1ltau1b3jos",
		//"reg2ltau1b3jos",
		"reg2mtau1b2jss",
		"reg2mtau1b2jos",
		"reg2mtau1b3jss",
		"reg2mtau1b3jos",
		"reg2mtau2b2jss",
		"reg2mtau2b2jos",
		"reg2mtau2b3jss",
		"reg2mtau2b3jos",
	};
	vector<TString> regions_tthML = {"reg1l2tau1bnj_ss","reg1l2tau1bnj_os","reg1l1tau1b2j_ss","reg1l1tau1b2j_os","reg1l1tau1b3j_ss","reg1l1tau1b3j_os"};
	// "reg1l2tau2bnj_ss","reg1l2tau2bnj_os","reg1l1tau2b2j_ss","reg1l1tau2b2j_os","reg1l1tau2b3j_ss","reg1l1tau2b3j_os"};
	vector<TString> regions = framework == "xTFW" ? regions_xTFW : regions_tthML;
	int nregions = regions.size();
	TString nprong[] = {"1prong","3prong"};
	for (int j = 0; j < nregions; ++j)
	  for (int k = 0; k < 2; ++k)
	    for (int i = 1; i < 2; i+=2){
	    	//TString addedregion = regions[j] + "_" + nprong[k] + "_veto";
	      	//printf("adding region: %s\n", addedregion.Data());
	      	//tau_plots->add_region(addedregion);
//	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_");
	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_above35_vetobtagwp70");
	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_below35_vetobtagwp70");
	    }
	tau_plots->muteregion("prong");
	stringstream ss;
	ss<<"(BR=" << BRbenchmark << "%)";
	TString tmp;
	ss>>tmp;
	for(int i = 6; i<12 ; ++i) sampletitle[i]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data","doublefake"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kRed, kRed, kRed, kRed, kRed, kMagenta, kSpring, kTeal, kAzure};

	TFile *datafile1516 = new TFile(framework== "tthML"? "nominal/data1516_fcnc_NOMINAL.root" : "NOMINAL/data1516_NOMINAL.root");
	TFile *datafile17 = new TFile(framework== "tthML"? "nominal/data17_fcnc_NOMINAL.root" : "NOMINAL/data17_NOMINAL.root");
	TFile *datafile18 = 0;
	if(framework == "xTFW") datafile18 = new TFile(framework== "tthML"? "nominal/data18_fcnc_NOMINAL.root" : "NOMINAL/data18_NOMINAL.root");

	tau_plots->read_sample("data","data","NOMINAL","data",kBlack, 1, datafile1516);
	tau_plots->read_sample("data","data","NOMINAL","data",kBlack, 1, datafile17);
	tau_plots->read_sample("data","data","NOMINAL","data",kBlack, 1, datafile18);
	TString campains[] = {"mc16a_","mc16d_","mc16e_"};
//============================ merge_sample============================
	if(plot_option == 1){
		for (int j = 0; j < samples.size(); ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], NPname, origintitle[i], (enum EColor)colors[i], norm[j]);
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
		for (int j = 0; j < samples.size(); ++j){
			for (int i = 0; i < 3; ++i)
			{
				TString mc_campaign = campains[i];
				TFile *inputfile;
				if(signalmap.find(samples[j]) != signalmap.end()){
					for(auto signalsamp : signalmap[samples[j]]){
						inputfile = getFile(mc_campaign + signalsamp + (framework == "tthML"? "_fcnc" : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
						for (int i = 0; i < 7; i++) tau_plots->read_sample( samples[j], signalsamp + "_" + origin[i], dirname==NPname? nominalname:NPname, sampletitle[j], (enum EColor)colors[j], norm[j], inputfile);
						deletepointer(inputfile);
					}
				}else{
					TString samplename = (samplesys==samples[j] ? NPname : samples[j]);
					inputfile = getFile(mc_campaign + samplename + (framework == "tthML"? "_fcnc" : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					tau_plots->read_sample( samples[j], samplename + "_real", dirname==NPname? nominalname:NPname, sampletitle[j], (enum EColor)colors[j], norm[j], inputfile);
					if (fakeMC) {
						for (int i = 0; i < 7; i++) tau_plots->read_sample( "fake1truth", samplename + "_" + origin[i], dirname==NPname? nominalname:NPname, "Fake MC, 1 truth #tau", kMagenta, norm[j], inputfile);
						tau_plots->read_sample( "fake0truth", samplename + "_" + origin[8], dirname==NPname? nominalname:NPname, "fake, 0 truth #tau", kTeal, norm[j],inputfile);
					}else if(calibfake){
						for (int i = 0; i < 7; i++) tau_plots->read_sample( "fake", samplename + "_" + origin[i], dirname==NPname? nominalname:NPname, "MC Fake #tau", kTeal, norm[j], inputfile);
					}
					deletepointer(inputfile);
				}
			}
		}

	}
	for (int j = 0; j < nregions; ++j){
		for (int k = 0; k < 2; ++k)
			for (int i = 1; i < 2; i+=2){
			  tau_plots->merge_regions(regions[j] + "_" + nprong[k] + "_above35_vetobtagwp70",regions[j] + "_" + nprong[k] + "_below35_vetobtagwp70",regions[j] + "_" + nprong[k]);
			}
		tau_plots->merge_regions(regions[j] + "_" + nprong[0],regions[j] + "_" + nprong[1],regions[j]);
	}
	if(plot_option == 2){
  		vector<TString> stacks;
  		//tau_plots->overlay("fake");
  		stacks.push_back("ztautau");
  		stacks.push_back("top");
  		if(!fakeMC && calibfake) stacks.push_back("fake");
  		stacks.push_back("smhiggs");
  		stacks.push_back("wjet");
  		stacks.push_back("zll");
  		stacks.push_back("diboson");
  		if(!fakeMC && framework == "xTFW") {
  			stacks.push_back("fakeSS");
  			tau_plots->templatesample("reg2mtau1b3jss",NPname,"1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau1b3jos","fakeSS","Fake",kYellow,0,1.31597);
  			tau_plots->templatesample("reg2mtau1b2jss",NPname,"1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau1b2jos","fakeSS","Fake",kYellow,0,1.31597);
  			//tau_plots->templatesample("reg2mtau2b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b3jos","fakeSS","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau2b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b2jos","fakeSS","Fake",kYellow,1);

  			//tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
	
  			//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
	
  			//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
  		}
  		else{
  			stacks.push_back("fake1truth");
  			stacks.push_back("fake0truth");
  		}
  		tau_plots->stackorder = stacks;

  	}
  	//tau_plots->printyield("reg2mtau1b3jos");
  	//tau_plots->printyield("reg2mtau1b2jos");
  	std::string nptmp = NPname.Data();
  	findAndReplaceAll(nptmp,"_1down","_down");
  	findAndReplaceAll(nptmp,"_1up","_up");
  	findAndReplaceAll(nptmp,"JET_EffectiveNP","JET_EFF");
  	findAndReplaceAll(nptmp,"JET_JER_EffectiveNP","JER");
  	findAndReplaceAll(nptmp,"JET_EtaIntercalibration","JET_EtaInt");
	findAndReplaceAll(nptmp,"TAUS_TRUEHADTAU_SME_TES","TES");
	NPname = nptmp;
	if(doTrex){
		if(NPname.Contains("PDF")) tau_plots->trexdir = "PDF_trexinputs";
		else if(NPname.Contains("muR")) tau_plots->trexdir = "scale_trexinputs";
		else tau_plots->trexdir = "trexinputs";
		tau_plots->write_trexinput(NPname,"update");
	}
	if(doPlots){
		gSystem->mkdir(("output_"+to_string(iNP)).c_str());
		for (int i = samples.size()-6; i < samples.size(); ++i)
		{
  			tau_plots->overlay(samples[i]);
		}
		tau_plots->plot_stack(("output_"+to_string(iNP)).c_str());
		
	}
	deletepointer(tau_plots);
	deletepointer(datafile1516);
	deletepointer(datafile17);
	deletepointer(datafile18);
}

int main(int argc, char const *argv[])
{
	TString framework = argv[1];
	int from = atoi(argv[2]);
	int to = atoi(argv[3]);
	TString dirname;
	for (int i = from; i <= to; ++i)
	{
		printf("=============================generating NP %d : %s=============================\n", i, findNPname(dirname,i,framework).Data());
		plot(i,framework);
	}
	return 0;
}
