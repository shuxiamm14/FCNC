#include "histSaver.h"
#include "TH1D.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <sys/ioctl.h>
#include "fcnc_include.h"
#include "weightsys_list.h"
#include "makechart.h"
#include "common.h"
using namespace std;

TFile *getFile(TString sample, TString NPdir, TString NPname, TString nominaldir, TString nominalname){
	TFile *inputfile = new TFile(NPdir + "/" + sample + "_" + (NPdir==nominaldir? NPname : nominalname) + ".root");
	if(inputfile->IsZombie()) {
		deletepointer(inputfile);
		inputfile = new TFile(nominaldir + "/" + sample + "_" + nominalname + ".root");
	}
	return inputfile;
}







void plot(int iNP, TString framework, TString method) //method = fitss / fitos / plot / trex
{
	TString dirname;
	TString NPname = findNPname(dirname,iNP,framework);
	TString nominalname = "NOMINAL";
	TString histmiddlename =  (dirname==NPname || NPname.Contains("fake_mismodelling"))? nominalname:NPname;
	float BRbenchmark = 0.2;
	bool calculate_fake_calibration = 1;
	bool wfake = 0;
	bool mergeFake = 0;
	bool doTrex = 1;
	bool plotnj = 0;
	bool doPlots = 1;
	bool scaletodata = 0;
	bool mergeprong = 1;
	int plot_option = 2;
	bool fittodata = 0;
	bool plotFakeLep = 0;
	bool showFake = 1;
	TString fitcharge = "os";
	int campaignfrom = 0;
	int campaignto = 3;
	if(method.Contains("plot")){
		doTrex = 0;
		doPlots = 1;
		if(method.Contains("fake")) calculate_fake_calibration = 1;
		else calculate_fake_calibration = 0;
	}
	if(method.Contains("fit")){
		doTrex = 0;
		doPlots = 1;
		calculate_fake_calibration = 1;
		wfake = 1;
		fittodata = 1;
		fitcharge = method.Contains("os")?"os":"ss";
	}
	if(fittodata == 1 && NPname.Contains("Xsec")) {
		histmiddlename = nominalname;
	}
	if(framework == "xTFW") calculate_fake_calibration = 0;
	histSaver *tau_plots = new histSaver("dummy");
	tau_plots->doROC = 0;
	TString lumitag = "#it{#sqrt{s}} = 13TeV, ";
	lumitag += campaignto == 3 ? "140 fb^{-1}" : (campaignto==2?"80 fb^{-1}":"36.1 fb^{-1}");
	tau_plots->SetLumiAnaWorkflow(lumitag,"FCNC tqH H#rightarrow tautau","Internal");
	tau_plots->debug = 0;
/*
	tau_plots->checkread = 1;
	tau_plots->checkread_sample = "fake";
	tau_plots->checkread_region = "reg1l1tau1b2j_os_1prong_above35_vetobtagwp70";
	tau_plots->checkread_variation = "NOMINAL";
	tau_plots->checkread_variable = 0;
	tau_plots->checkread_ibin = 2;
*/
	vector<sample> samples = getBkgSamples(framework);
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kMagenta, kSpring, kTeal, kAzure};
	vector<sample> sigsamples = getSigSamples(framework, BRbenchmark);
	if(!calculate_fake_calibration){
		samples.insert(samples.begin(),sigsamples.begin(),sigsamples.end());
	}
	TString samplesys = "";
	if(NPname.Contains("ttbarsys")){
		samplesys = "ttbar";
	}
	if(NPname.Contains("Xsec")){
		bool applied = 0;
		for(auto &samp : samples){
			if(NPname.Contains(samp.name)){
				if(NPname.Contains("_up")) samp.norm *= 1+XsecErr.at(samp.name)[0];
				else samp.norm *= 1+XsecErr.at(samp.name)[1];
				applied = 1;
				break;
			}
		}
		if(applied == 0) {
			printf("Error: Xsec uncertainty %s is not applied\n", NPname.Data());
			exit(0);
		}
	}
	if(framework == "tthML"){
		if(calculate_fake_calibration){
			tau_plots->add("p_{T,#tau}","taupt_0","GeV");
			if(!fittodata){
				tau_plots->add("m_{#tau,light-jet}","taulmass","GeV");
				tau_plots->add("p_{T,b}","bpt","GeV");
  				tau_plots->add("E_{miss}^{T}","etmiss","GeV",10);
				tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
			}
			//tau_plots->add("p_{T,b}","bpt","GeV");
			//tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
		}
		else if(plotnj){
  			tau_plots->add("N_{l-jet}","njet","",1);
			tau_plots->muteregion("3j");
			tau_plots->muteregion("2j");
		}else{
			tau_plots->sensitivevariable = "BDTG_test";
			tau_plots->add("BDT discriminant","BDTG_test","",10);
  			tau_plots->add("p_{T,lead-#tau}","taupt_0","GeV",1);
  			tau_plots->add("p_{T,lead-l}","lep_pt_0","GeV",1);
			tau_plots->add("m_{#tau,light-jet}","taulmass","GeV");
  			tau_plots->add("E^{T}_{miss}","etmiss","GeV",10);
			tau_plots->add("#DeltaR(l,b-jet)","drlb","",3);
			tau_plots->add("#chi^{2}","chi2","",5);
			tau_plots->add("M_{all}","allmass","GeV",25);
			tau_plots->add("p_{Z,all}","allpz","GeV",25);
			tau_plots->add("M(light-jet,light-jet,min)","mjjmin","GeV",5);
  			tau_plots->add("m_{t,SM}","t1mass","GeV",5);
  			tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  			tau_plots->add("m_{W}","wmass","GeV",5);
  			tau_plots->add("m_{t,FCNC}","t2mass","GeV",5);
  			tau_plots->add("m_{#tau#tau,vis}","tautauvismass","GeV",10);
  			tau_plots->add("m_{t,FCNC,vis}","t2vismass","GeV",10);
  			tau_plots->add("P_{t,#tau#tau,vis}","tautauvispt","GeV",10);
  			tau_plots->add("m^{T}_{W}","mtw","GeV",10);
  			tau_plots->add("m_{t,SM,vis}","t1vismass","GeV",15);
  			tau_plots->add("#DeltaR(l+b-jet,#tau+#tau)","drlbditau","",5);
  			tau_plots->add("#eta_{#tau,max}","etamax","",10);
  			tau_plots->add("#DeltaR(l,#tau)","drltau","",8);
  			tau_plots->add("#DeltaR(#tau,fcnc-j)","drtauj","",10);
  			tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",4);
  			tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  			tau_plots->add("M(#tau#tau light-jet,min)","mtaujmin","",5);
			tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",6);
			tau_plots->add("E^{T}_{miss} centrality","phicent","",3);
  			tau_plots->add("p_{T,sublead-#tau}","taupt_1","GeV",1);
  			tau_plots->add("p_{T,sublead-l}","lep_pt_1","GeV",1);
  			tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",5);
  			tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",5);
  		}
  	}else{
		tau_plots->sensitivevariable = "BDTG_test";
		tau_plots->add("BDT discriminant","BDTG_test","",5);
		//tau_plots->add("BDT discriminant","BDTG_train","",5);
  		//tau_plots->add("p_{T,lead-#tau}","taupt_0","GeV",5);
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
	vector<TString> regions_tthML_faketau = {"reg1l2tau1bnj_ss",
		"reg2l1tau1bnj",
		"reg2l1tau2bnj",
		"reg1l2tau1bnj_os",
		"reg1l1tau1b2j_ss",
		"reg1l1tau1b2j_os",
		"reg1l1tau1b3j_ss",
		"reg1l1tau1b3j_os",
		"reg1l2tau2bnj_ss",
		"reg1l2tau2bnj_os",
		"reg1l1tau2b2j_ss",
		"reg1l1tau2b2j_os",
		"reg1l1tau2b3j_ss",
		"reg1l1tau2b3j_os"
	};
	vector<TString> regions_tthML_fakelep = {
		"reg2lSS1tau1bnj_os",
		"reg2lSS1tau1bnj_os_antiiso",
		"reg2lSS1tau1bnj_os_antiisolead",
	};
	vector<TString> regions_tthML = plotFakeLep? regions_tthML_fakelep : regions_tthML_faketau;
	//vector<TString> regions_calc_fake = {"reg2l1tau2b","reg1l1tau2b1j_ss","reg1l1tau2b1j_os","reg2l1tau1b","reg1l1tau2b_os","reg1l1tau2b_ss"};//,"reg2l2bnj","reg1l2b2j","reg2l2b"};
	vector<TString> regions = framework == "xTFW" ? regions_xTFW : regions_tthML;
	//if(calculate_fake_calibration) {
	//	regions = regions_calc_fake;
	//	if(fittodata) regions.insert(regions.end(), regions_tthML.begin(), regions_tthML.end());
	//}
	int nregions = regions.size();
	TString nprong[] = {"_1prong","_3prong",""};
	for (int j = 0; j < nregions; ++j){
		if(plotFakeLep){
			tau_plots->add_region(regions[j]);
		}else{
			for (int k = 0; k < 2; ++k){
				for (int i = 1; i < 2; i+=2){
					//TString addedregion = regions[j] + nprong[k] + "_veto";
				  	//printf("adding region: %s\n", addedregion.Data());
				  	//tau_plots->add_region(addedregion);
					//tau_plots->add_region(regions[j] + nprong[k] + "_");
					tau_plots->add_region(regions[j] + nprong[k] + "_above35_vetobtagwp70");
					tau_plots->add_region(regions[j] + nprong[k] + "_below35_vetobtagwp70");
				}
			}
		}
	}

	vector<TString> origin = {"b", "c", "g", "j", "lep", "wjet-fake","nomatch","doublefake", "real", "data"};
	vector<TString> origintitle = {"b-jets fake #tau", "c-jets fake #tau", "gluon-jets fake #tau", "light-jets fake #tau", "lepton fake #tau", "#tau_{W}", "non-matched", "double fake #tau", "real #tau", "data"};
	if(plotFakeLep){
		vector<TString> tmp1 = {"chargeflip","misid","non_prompt","fakelep","real","data"};
		vector<TString> tmp2 = {"charge flip","mis-id","non prompt","fake lep","real lep","data"};
		origin = tmp1;
		origintitle = tmp2;
	}else{
		if(mergeprong) tau_plots->muteregion("prong");
		if(!mergeprong) tau_plots->muteregion("35");
	}

	TFile *datafile[3] = {0,0,0};
	TFile *datafile_fake[3] = {0,0,0};
	TString datafilesname[3] = {"data1516","data17","data18"};
	for (int i = campaignfrom; i < campaignto; ++i)
	{
		if(!calculate_fake_calibration || fittodata || framework!= "tthML") {
				datafile[i] = new TFile(framework== "tthML"? "nominal/" + datafilesname[i] + "_fcnc_NOMINAL.root" : "NOMINAL/" + datafilesname[i] + "_NOMINAL.root");
				tau_plots->read_sample("data","data","NOMINAL","data",kBlack, 1, datafile[i]);
		}
//		if(calculate_fake_calibration && framework== "tthML") {
//			datafile_fake[i] = new TFile("nominal/" + datafilesname[i] + "_fake_NOMINAL.root");
//			tau_plots->read_sample("data","data","NOMINAL","data",kBlack, 1, datafile_fake[i]);
//		}
	}
	TFile *inputfile;
//============================ merge_sample============================
	if(plot_option == 1){
		for (int j = 0; j < samples.size(); ++j){
			for (int i = 0; i < origin.size(); ++i){
				for (int icamp = campaignfrom; icamp < campaignto; ++icamp)
				{
					TString mc_campaign = mc_campaigns[icamp];
					if(signalmap.find(samples[j].name) != signalmap.end()){
						for(auto signalsamp : signalmap.at(samples[j].name)){
							inputfile = getFile(mc_campaign + "_" + signalsamp + (framework == "tthML"? (calculate_fake_calibration ? "_fake" : "_fcnc") : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
							double norm = samples[j].norm;
							tau_plots->read_sample( origin[i], signalsamp + "_" + origin[i], histmiddlename, origintitle[i], (enum EColor)colors[i], norm,inputfile);
							deletepointer(inputfile);
						}
					}
					TString samplename = (samplesys==samples[j].name ? NPname : samples[j].name);
					//inputfile = getFile(mc_campaign + "_" + samplename + (framework == "tthML"? (calculate_fake_calibration ? "_fake" : "_fcnc") : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					inputfile = getFile(mc_campaign + "_" + samplename + (framework == "tthML"? "_fcnc" : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					double norm = samples[j].norm;
					tau_plots->read_sample( origin[i], samples[j].name + "_" + origin[i], histmiddlename, origintitle[i], (enum EColor)colors[i], norm,inputfile);
					deletepointer(inputfile);
				}
			}
		}
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
		for (int j = 0; j < samples.size(); ++j){
			for (int icamp = campaignfrom; icamp < campaignto; ++icamp)
			{
				TString mc_campaign = mc_campaigns[icamp];
				if(!calculate_fake_calibration && signalmap.find(samples[j].name) != signalmap.end()){
					for(auto signalsamp : signalmap.at(samples[j].name)){
						inputfile = getFile(mc_campaign + "_" + signalsamp + (framework == "tthML"? "_fcnc" : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
						for (int i = 0; i < origin.size(); i++) tau_plots->read_sample( samples[j].name, signalsamp + "_" + origin[i], histmiddlename, samples[j].title, samples[j].color, samples[j].norm, inputfile);
						deletepointer(inputfile);
					}
				}else{
					TString samplename = (samplesys==samples[j].name ? NPname : samples[j].name);
					inputfile = getFile(mc_campaign + "_" + samplename + (framework == "tthML"? "_fcnc" : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					double norm = samples[j].norm;
					if(plotFakeLep) tau_plots->read_sample( samples[j].name, samplename + "_real", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					else tau_plots->read_sample( samples[j].name, samplename + "_real", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					//tau_plots->read_sample( samples[j].name, samplename + "_lep", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					if(showFake){
						if (mergeFake) {
							for (int i = 0; i < origin.size() - 3; i++) tau_plots->read_sample( "fake1truth", samplename + "_" + origin[i], histmiddlename, "Fake MC, 1 truth #tau", kMagenta, norm, inputfile);
							tau_plots->read_sample( "fake0truth", samplename + "_" + origin[origin.size() - 3], histmiddlename, "fake, 0 truth #tau", kTeal, norm,inputfile);
						}else if(wfake){
							for (int i = 0; i < origin.size() - 2; i++) {
								if(origin[i] == "wjet-fake")
									tau_plots->read_sample( "wjet-fake", samplename + "_wjet", histmiddlename, "W-jet Fake #tau", kRed, norm, inputfile);
								else if(origin[i] == "lep")
									tau_plots->read_sample( "lep-fake", samplename + "_" + origin[i], histmiddlename, "Lep Fake #tau", (enum EColor)(40), norm, inputfile);
								else if(origin[i] == "doublefake")
									tau_plots->read_sample( "doublefake", samplename + "_" + origin[i], histmiddlename, "Double Fake #tau", (enum EColor)(41), norm, inputfile);
								else if(origin[i] == "b")
									tau_plots->read_sample( "bjet-fake", samplename + "_" + origin[i], histmiddlename, "b-jet Fake #tau", (enum EColor)(43), norm, inputfile);
								else
									tau_plots->read_sample( "other-fake", samplename + "_" + origin[i], histmiddlename, "Other Fake #tau", (enum EColor)(42), norm, inputfile);
							}
						}else{
							for (int i = 0; i < origin.size() - 2; i++){
								if(origin[i] == "wjet-fake")
									tau_plots->read_sample( origin[i], samplename + "_wjet", histmiddlename, origintitle[i], (enum EColor)(i+40), norm, inputfile);
								else tau_plots->read_sample( origin[i], samplename + "_" + origin[i], histmiddlename, origintitle[i], (enum EColor)(i+40), norm, inputfile);
							}
						}
					}else{
						for (int i = 0; i < origin.size()-2; i++)
							tau_plots->read_sample( samples[j].name, samplename + "_" + origin[i], histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					}
					deletepointer(inputfile);
				}
			}
		}

	}
	if(!plotFakeLep){
		for (int j = 0; j < nregions; ++j){
			for (int k = 0; k < 2; ++k)
				for (int i = 1; i < 2; i+=2){
				  tau_plots->merge_regions(regions[j] + nprong[k] + "_above35_vetobtagwp70",regions[j] + nprong[k] + "_below35_vetobtagwp70",regions[j] + nprong[k]);
				}
			if(mergeprong) tau_plots->merge_regions(regions[j] + nprong[0],regions[j] + nprong[1],regions[j]);
		}
	}
	if(plot_option == 2){
  		for(auto samp: samples){
  			if(signalmap.find(samp.name) == signalmap.end()) tau_plots->stackorder.push_back(samp.name);
  		}
  		if(plotFakeLep){
  			for (int i = 0; i < origin.size() - 2; i++) tau_plots->stackorder.push_back(origin[i]);
  		}else{
  			if(showFake){
  				if(mergeFake){
					tau_plots->stackorder.push_back("fake1truth");
					tau_plots->stackorder.push_back("fake0truth");
  				}
  				else if(wfake) {
					tau_plots->stackorder.push_back("lep-fake");
					tau_plots->stackorder.push_back("doublefake");
					tau_plots->stackorder.push_back("other-fake");
					tau_plots->stackorder.push_back("bjet-fake");
					tau_plots->stackorder.push_back("wjet-fake");
				}else
					for (int i = 0; i < origin.size() - 2; i++) tau_plots->stackorder.push_back(origin[i]);
			}else{
				for (int j = 0; j < samples.size(); ++j)
					tau_plots->stackorder.push_back(samples[j].name);
			}
			if(fittodata){
				for(int i = 0; i < 3; i++){
					if(mergeprong) { if(i != 2) continue; }
					else { if(i == 2) continue; }

					TString prefix = PACKAGE_DIR;
					prefix += "/data/";

					LatexChart *chart = 0;

					vector<TString> fit_regions = {
						"reg1l1tau1b2j_ss" + nprong[i], "reg1l1tau1b3j_ss" + nprong[i],
						"reg1l1tau2b2j_os" + nprong[i], "reg1l1tau2b3j_os" + nprong[i],
						"reg1l1tau2b2j_ss" + nprong[i], "reg1l1tau2b3j_ss" + nprong[i],
						"reg2l1tau1bnj" + nprong[i],"reg2l1tau2bnj" + nprong[i]
					};
					//map<TString,map<TString,vector<TString>>> scalesamples;
					//scalesamples["other-fake"];
					//scalesamples["wjet-fake"];
					//scalesamples["wjet-fake"] = {
					//	{"ss", {"reg1l1tau2b2j_ss" + nprong[i], "reg1l1tau2b3j_ss" + nprong[i], "reg1l1tau2b1j_ss" + nprong[i]}},
					//	{"os", {"reg1l1tau2b2j_os" + nprong[i], "reg1l1tau2b3j_os" + nprong[i], "reg1l1tau2b1j_os" + nprong[i], "reg2l1tau1bnj" + nprong[i], "reg2l1tau2bnj" + nprong[i]}},
					//};
					//scalesamples["bjet-fake"];
					//map<TString,map<TString,vector<TString>>> postfit_regions = scalesamples;
					//postfit_regions["wjet-fake"]["ss"].push_back("reg1l1tau1b3j_ss");
					//postfit_regions["wjet-fake"]["ss"].push_back("reg1l1tau1b2j_ss");
					//postfit_regions["wjet-fake"]["os"].push_back("reg1l1tau1b3j_os");
					//postfit_regions["wjet-fake"]["os"].push_back("reg1l1tau1b2j_os");
					TFile SFfile(prefix + "scale_factors.root","update");
					//if(NPname == "NOMINAL") {
					//	chart = new LatexChart("scale_factor");
					//}

					vector<TString> postfit_regions = fit_regions;
					postfit_regions.push_back("reg1l1tau1b2j_os" + nprong[i]);
					postfit_regions.push_back("reg1l1tau1b3j_os" + nprong[i]);

//					vector<TString> fit_regions = {"reg1l1tau2b2j_" + fitcharge + nprong[i], "reg1l1tau2b3j_" + fitcharge + nprong[i], "reg1l1tau2b1j_" + fitcharge + nprong[i],"reg2l1tau1b" + nprong[i],"reg2l1tau2b" + nprong[i]};
//					vector<TString> fit_regions = {"reg1l1tau2b2j_" + fitcharge + nprong[i], "reg1l1tau2b3j_" + fitcharge + nprong[i],"reg2l1tau1b" + nprong[i],"reg2l1tau2b" + nprong[i]};
//					vector<TString> fit_regions = {"reg1l1tau2b2j_" + fitcharge + nprong[i], "reg1l1tau2b1j_" + fitcharge + nprong[i],"reg2l1tau1b" + nprong[i],"reg2l1tau2b" + nprong[i]};
//					vector<TString> postfit_regions = fit_regions;
//					postfit_regions.push_back("reg1l1tau1b2j_" + fitcharge + nprong[i]);
//					postfit_regions.push_back("reg1l1tau1b3j_" + fitcharge + nprong[i]);
//					TFile SFfile(prefix + "scale_factors_" + fitcharge + ".root","update");
//					if(NPname == "NOMINAL") {
//						chart = new LatexChart(("scale_factor_" + fitcharge).Data());
//					}
					vector<TString> scalesamples = {"wjet-fake","other-fake","bjet-fake"};
					TString varname = "taupt_0";
					map<TString,vector<observable>> *SFs = tau_plots->fit_scale_factor(&fit_regions, &varname, &scalesamples, &fakePtSlices, &histmiddlename, &postfit_regions);

					TH1D* SFhist;
					for (int i = 0; i < 3; ++i)	//3 pt bins
					{
						for (auto SF : *SFs) //parameters
						{
							if(chart) {
								string rowname = SF.first.Contains("wjet")? "$\tau_{W}$" : (SF.first.Contains("bjet") ? "$\tau_{b}$" : "$\tau_{other}$");
								string columnname = "$" + to_string(int(fakePtSlices[i])) + "-" + to_string(int(fakePtSlices[i+1])) + "$~GeV";
								if(i == fakePtSlices.size()-2) columnname = to_string(int(fakePtSlices[i])) + "GeV$-$";
								chart->set(rowname,columnname,SF.second[i]);
							}
					
							TString histname = prefix + SF.first + "_pt" + (to_string(int(fakePtSlices[i])) + to_string(int(fakePtSlices[i+1]))).c_str();
							SFhist = (TH1D*)SFfile.Get(histname);
							if(!SFhist) {
								SFhist = new TH1D(histname,histname,300,0,300);
							}
							SFhist -> SetBinContent(iNP+1,SF.second[i].nominal);
							SFhist -> SetBinError(iNP+1,SF.second[i].error);
							SFhist -> GetXaxis() -> SetBinLabel(iNP+1,NPname);
							SFhist -> Write(histname, TObject::kWriteDelete);
						}
					}
					if(chart){
						chart->print(chart->label + "_statonly");
					}
				}
			}


  			if(NPname == "fake_mismodelling"){
				for(int i = 0; i < 3; i++){
					if(mergeprong) { if(i != 2) continue; }
					else { if(i == 2) continue; }
					vector<double> BDTslice = {-1,-0.4,0.1,0.3,0.5,0.65,0.75,0.85,1};
					vector<observable> mismodel2j = tau_plots->scale_to_data("reg1l1tau1b2j_ss" + nprong[i],"1 wjet-fake","BDTG_test",BDTslice);
					vector<observable> mismodel3j = tau_plots->scale_to_data("reg1l1tau1b3j_ss" + nprong[i],"1 wjet-fake","BDTG_test",BDTslice);
					tau_plots->scale_sample("reg1l1tau1b2j_os" + nprong[i],"1 wjet-fake","BDTG_test",mismodel2j,BDTslice);
					tau_plots->scale_sample("reg1l1tau1b3j_os" + nprong[i],"1 wjet-fake","BDTG_test",mismodel3j,BDTslice);
				}
  			}

  			if(scaletodata){
				for(int i = 0; i < 3; i++){
					if(mergeprong) { if(i != 2) continue; }
					else { if(i == 2) continue; }
					if(calculate_fake_calibration){
						tau_plots->scale_to_data("reg1l1tau2b1j_os" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b1j_ss" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b_os" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b_ss" + nprong[i],"1 fake","taupt_0",fakePtSlices);
					}else{
						tau_plots->scale_to_data("reg1l1tau2b2j_os" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b3j_os" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b2j_ss" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b3j_ss" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b2j_os" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b3j_os" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b2j_ss" + nprong[i],"1 fake","taupt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b3j_ss" + nprong[i],"1 fake","taupt_0",fakePtSlices);
					}
				}
  			}
  			if(!mergeFake && framework == "xTFW") {
  				tau_plots->stackorder.push_back("fakeSS");
  				tau_plots->templatesample("reg2mtau1b3jss",histmiddlename,"1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 ttbar -1 othertop -1 fake","reg2mtau1b3jos","fakeSS","Fake",kYellow,0,1.31597);
  				tau_plots->templatesample("reg2mtau1b2jss",histmiddlename,"1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 ttbar -1 othertop -1 fake","reg2mtau1b2jos","fakeSS","Fake",kYellow,0,1.31597);
  				//tau_plots->templatesample("reg2mtau2b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b3jos","fakeSS","Fake",kYellow,1);
  				//tau_plots->templatesample("reg2mtau2b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b2jos","fakeSS","Fake",kYellow,1);
	
  				//tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  				//tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
		
  				//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  				//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
  				////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  				////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
		
  				//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 mergeFake -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  				//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 mergeFake -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
  				////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 mergeFake -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  				////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 mergeFake -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
  			}
  		}
  	}
  	//tau_plots->printyield("reg1l1tau1b3j_os");
  	//tau_plots->printyield("reg1l1tau1b2j_os");
	if(doTrex){
  		std::string nptmp = NPname.Data();
  		findAndReplaceAll(nptmp,"__1down","_down");
  		findAndReplaceAll(nptmp,"__1up","_up");
  		findAndReplaceAll(nptmp,"JET_EffectiveNP","JES");
		findAndReplaceAll(nptmp,"JET_CategoryReduction_","JES");
  		findAndReplaceAll(nptmp,"JET_JER_EffectiveNP","JER");
  		findAndReplaceAll(nptmp,"JET_EtaIntercalibration","JET_EtaInt");
		findAndReplaceAll(nptmp,"TAUS_TRUEHADTAU_SME_TES","TES");
		NPname = nptmp;
		if(NPname.Contains("PDF")) tau_plots->trexdir = "PDF_trexinputs";
		else if(NPname.Contains("muR")) tau_plots->trexdir = "scale_trexinputs";
		else tau_plots->trexdir = "trexinputs";
		tau_plots->write_trexinput(histmiddlename,NPname);
	}
	if(doPlots){
		for (int j = 0; j < nregions; ++j){
			if(!mergeprong && !plotFakeLep) tau_plots->merge_regions(regions[j] + nprong[0],regions[j] + nprong[1],regions[j]);
		}

		if(!calculate_fake_calibration)
			for (auto samp : sigsamples)
			{
  				tau_plots->overlay(samp.name);
			}
		TString savename = NPname;
		if(fittodata) savename += "_" + method;
		tau_plots->plot_stack(histmiddlename, savename);
		
	}
	deletepointer(tau_plots);
	for (int i = 0; i < 3; ++i)
	{
		deletepointer(datafile[i]);
		deletepointer(datafile_fake[i]);
	}
}

int main(int argc, char const *argv[])
{
	TString framework = argv[1];
	int from = atoi(argv[2]);
	int to = atoi(argv[3]);
	TString dirname;
	TString method = argv[4];
	for (int i = from; i <= to; ++i)
	{
		printf("=============================generating NP %d : %s=============================\n", i, findNPname(dirname,i,framework).Data());
		plot(i,framework,method);
	}
	return 0;
}
