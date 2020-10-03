#include "histSaver.h"
#include "TH1D.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <sys/ioctl.h>
#include "fcnc_include.h"
#include "weightsys_list.h"
#include "LatexChart.h"
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

int plot(int iNP, TString framework, TString method, int ipart = 0) //method = fitss / fitos / plot / trex
{
	TString dirname;
	TString NPname = findNPname(dirname,iNP,framework);
	TString nominalname = "NOMINAL";
	TString histmiddlename =  (dirname==NPname || NPname.Contains("fake_mismodelling"))? nominalname:NPname;
	TString figuredir = method.Contains("test")?"." : FIGURE_DIR;
	TString chartdir = method.Contains("test")?"." : TABLE_DIR;
	observable fakeFactor;
	bool prefit = 1;
	float BRbenchmark = 0.2;
	bool calculate_fake_calibration = 1;
	bool wfake = 0;
	bool mergeFake = 1;// template: mergeFake=0,showfake=0
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
	int perpart = 5;
	int varcount = 0;
	int plotvar = 0;
	bool doFakeFactor = 0;
	bool realOnly = 0;
	bool mergeDiletype = 1;
	if(method.Contains("nofake")){
		showFake = 0;
	}
	if(method.Contains("plot")){
		doTrex = 0;
		doPlots = 1;
		if(method.Contains("fake")) calculate_fake_calibration = 1;
		else calculate_fake_calibration = 0;
	}
	if(method.Contains("IFF")){
		calculate_fake_calibration = 1;
		doFakeFactor = 1;
		plotFakeLep = 1;
		wfake = 0;
		realOnly = 1;
	}
	if(method.Contains("postfit")){
		prefit = 0;
	}else if(method.Contains("fit")){
		doTrex = 0;
		doPlots = 1;
		calculate_fake_calibration = 1;
		wfake = 1;
		fittodata = 1;
		fitcharge = method.Contains("os")?"os":"ss";
	}
	if(method.Contains("lep")){
		plotFakeLep = 1;
		wfake = 0;
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
	vector<fcncSample> samples = getBkgSamples(framework);
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kMagenta, kSpring, kTeal, kAzure};
	vector<fcncSample> sigsamples = getSigSamples(framework, BRbenchmark);
	//if(!calculate_fake_calibration){
		samples.insert(samples.begin(),sigsamples.begin(),sigsamples.end());
	//}
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
	auto vars = getVariables(framework);
	if(framework == "tthML"){
		if(calculate_fake_calibration){
			if(!fittodata && !(fakeFactor.nominal == 0 && doFakeFactor)){
				tau_plots->sensitivevariable = "BDTG_test";
				for(auto var : vars){
					
//					if(   var.first!="tau_pt_0"
//						&&var.first!="tau_pt_1"
//						&&var.first!="etmiss"
//						&&var.first!="ttvismass"
//						&&var.first!="lep_pt_0"
//						&&var.first!="BDTG_test"
//					) continue;
					if(varcount / perpart == ipart){
						tau_plots->add(var.second);
						plotvar++;
					}else if(varcount / perpart == ipart+1) break;
					varcount++;
				}
				//tau_plots->add(vars["taulmass"]);
				//tau_plots->add(vars["bpt"]);
				//tau_plots->add(vars["etmiss"]);
				//tau_plots->add(vars["ljetpt"]);
			}else{
				tau_plots->add(vars["tau_pt_0"]);
				tau_plots->add(vars["lep_pt_0"]);
				if(doFakeFactor) tau_plots->add(vars["lep_pt_1"]);
			}
			//tau_plots->add("p_{T,b}","bpt","GeV");
			//tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
		}
		else if(plotnj){
			tau_plots->add(vars["njet"]);
			tau_plots->muteregion("3j");
			tau_plots->muteregion("2j");
		}else{
			tau_plots->sensitivevariable = "BDTG_test";
			for(auto var : vars){
				
//				if(   var.first!="tau_pt_0"
//					&&var.first!="tau_pt_1"
//					&&var.first!="etmiss"
//					&&var.first!="ttvismass"
//					&&var.first!="lep_pt_0"
//					&&var.first!="BDTG_test"
//				) continue;
				if(varcount / perpart == ipart){
					tau_plots->add(var.second);
					plotvar++;
				}else if(varcount / perpart == ipart+1) break;
				varcount++;
			}
			if(plotvar == 0) { printf("No variable to plot\n"); return 0; }
		}
	}else{
		tau_plots->sensitivevariable = "BDTG_test";
		for(auto var : vars){
         //       std::cout<<"---------------"<<std::endl;
		//	if(var.first!="tautauvispt"&&var.first!="t2vismass"&&var.first!="drttj" && var.first!="tau_pt_0"&&var.first!="tau_pt_1"&&var.first!="etmiss" &&var.first!="ttvismass" &&var.first!="BDTG_test"&&var.first!="dphitauetmiss"&&var.first!="BDTG_train"&&var.first!="x1fit"&&var.first!="x2fit"&&var.first!="phicent") continue;
			tau_plots->add(var.second);
		}
	}
	gErrorIgnoreLevel = kWarning;
	tau_plots->blinding = 2;
	vector<TString> regions_xTFW = {
		//"reg1mtau1ltau1b2jss",
		"reg2ltau1b2jss",
		//"reg1mtau1ltau1b3jss",
		"reg2ltau1b3jss",
		//"reg1mtau1ltau1b2jos",
		"reg2ltau1b2jos",
		//"reg1mtau1ltau1b3jos",
		"reg2ltau1b3jos",
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
		"reg2lSS1taunj_os",
		"reg2lSS1taunj_os_antiiso",
		"reg2lSS1taunj_os_antiisolead",
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
	vector<TString> dileptype = {"ee","emu","mue","mumu"};
	for (int j = 0; j < nregions; ++j){
		if(plotFakeLep){
			tau_plots->add_region(regions[j]+"_ee");
			tau_plots->add_region(regions[j]+"_emu");
			tau_plots->add_region(regions[j]+"_mue");
			tau_plots->add_region(regions[j]+"_mumu");
		}else{
			for (int k = 0; k < 2; ++k){
				for (int i = 1; i < 2; i+=2){
					tau_plots->add_region(regions[j] + nprong[k] + "_vetobtagwp70");
				}
			}
		}
	}

	vector<TString> origin = {"b", "c", "g", "j", "lep", "wjet-fake","nomatch","doublefake", "real", "data"};
	vector<TString> origintitle = {"b-jets fake #tau", "c-jets fake #tau", "gluon-jets fake #tau", "light-jets fake #tau", "lepton fake #tau", "#tau_{W}", "non-matched", "double fake #tau", "real #tau", "data"};
	if(plotFakeLep){
		vector<TString> tmp1 = {"chargeFlip","converge","nonPrompt","otherFakeLep","unknownFakeLep","doubleFakeLep","realLep","data"};
		vector<TString> tmp2 = {"charge flip","converge","non prompt","other fake lep","unknown fake lep","double fake","realLep","data"};
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
				datafile[i] = new TFile(framework== "tthML"? "nominal/" + datafilesname[i] + "_NOMINAL.root" : "NOMINAL/" + datafilesname[i] + "_NOMINAL.root");
				tau_plots->read_sample("data","data","NOMINAL","data",kBlack, 1, datafile[i]);
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
							inputfile = getFile(mc_campaign + "_" + signalsamp, dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
							double norm = samples[j].norm;
							//if(origin[i] == "wjet-fake") tau_plots->read_sample( origin[i], signalsamp + "_wjet", histmiddlename, origintitle[i], (enum EColor)colors[i], norm,inputfile);
							//else
							tau_plots->read_sample( origin[i], signalsamp + "_" + origin[i], histmiddlename, origintitle[i], (enum EColor)colors[i], norm,inputfile);
							deletepointer(inputfile);
						}
					}
					TString samplename = (samplesys==samples[j].name ? NPname : samples[j].name);
					//inputfile = getFile(mc_campaign + "_" + samplename + (framework == "tthML"? (calculate_fake_calibration ? "_fake" : "_fcnc") : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					inputfile = getFile(mc_campaign + "_" + samplename + (framework == "tthML"? "_fcnc" : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					double norm = samples[j].norm;
					if(origin[i] == "wjet-fake") tau_plots->read_sample( origin[i], samples[j].name + "_wjet", histmiddlename, origintitle[i], (enum EColor)colors[i], norm,inputfile);
					else tau_plots->read_sample( origin[i], samples[j].name + "_" + origin[i], histmiddlename, origintitle[i], (enum EColor)colors[i], norm,inputfile);
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
				if(signalmap.find(samples[j].name) != signalmap.end()){
					for(auto signalsamp : signalmap.at(samples[j].name)){
						inputfile = getFile(mc_campaign + "_" + signalsamp, dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
						for (int i = 0; i < origin.size()-1; i++) {
							//if(origin[i] == "wjet-fake") tau_plots->read_sample( samples[j].name, signalsamp + "_wjet", histmiddlename, samples[j].title, samples[j].color, samples[j].norm, inputfile);
							//else 
							tau_plots->read_sample( samples[j].name, signalsamp + "_" + origin[i], histmiddlename, samples[j].title, samples[j].color, samples[j].norm, inputfile);
						}
						deletepointer(inputfile);
					}
				}else{
					TString samplename = (samplesys==samples[j].name ? NPname : samples[j].name);
					inputfile = getFile(mc_campaign + "_" + samplename, dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					double norm = samples[j].norm;
					if(plotFakeLep) tau_plots->read_sample( samples[j].name, samplename + "_realLep", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					else tau_plots->read_sample( samples[j].name, samplename + "_real", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
		//		std::cout<<"samplename:"<<samples[j].name<<std::endl;	//tau_plots->read_sample( samples[j].name, samplename + "_lep", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					if(!realOnly){//0
						if(showFake){//1
							if (mergeFake) { //1
								for (int i = 0; i < origin.size() - 3; i++) {
                                                                       // if(origin[i] == "wjet-fake") tau_plots->read_sample( "fake1truth", samplename + "_wjet", histmiddlename, "Fake MC, 1 truth #tau", kMagenta, norm, inputfile);
									  if(origin[i] !="wjet-fake") tau_plots->read_sample( "fake1truth", samplename + "_" + origin[i], histmiddlename, "Fake MC, 1 truth #tau", kMagenta, norm, inputfile);
								}
						//		tau_plots->read_sample( "fake0truth", samplename + "_" + origin[origin.size() - 3], histmiddlename, "fake, 0 truth #tau", kTeal, norm,inputfile);
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
							for (int i = 0; i < origin.size()-2; i++){ //-2
								if(origin[i] == "wjet-fake")
									tau_plots->read_sample( samples[j].name, samplename + "_wjet", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
								else tau_plots->read_sample( samples[j].name, samplename + "_" + origin[i], histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
							}
						}
					}
					deletepointer(inputfile);
				}
			}
		}

	}
	if(!plotFakeLep){
		if(mergeprong){
			for (int j = 0; j < nregions; ++j){
				tau_plots->merge_regions(regions[j] + nprong[0] + "_vetobtagwp70",regions[j] + nprong[1] + "_vetobtagwp70",regions[j]);
			}
		}
	}else if(mergeDiletype){
		for (int j = 0; j < nregions; ++j){
			vector<TString> mergeregions;
			for(auto type : dileptype) mergeregions.push_back(regions[j] + "_" + type);
			tau_plots->merge_regions(mergeregions,regions[j]);
		}
	}
	if(plot_option == 2){
		for(auto samp: samples){
			if(signalmap.find(samp.name) == signalmap.end()) tau_plots->stackorder.push_back(samp.name);
		}
		if(plotFakeLep){
			for (int i = 0; i < origin.size() - 2; i++) tau_plots->stackorder.push_back(origin[i]);
			if(doFakeFactor && framework == "tthML") {
				tau_plots->stackorder.push_back("non-prompt_lead");
				tau_plots->stackorder.push_back("non-prompt_sub-lead");
				string fakeFormular="1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 ttbar -1 ttV -1 others";
				if(fakeFactor.nominal == 0)
					fakeFactor=tau_plots->calculateYield("reg2lSS1taunj_os",fakeFormular,NPname)/(tau_plots->calculateYield("reg2lSS1taunj_os_antiisolead",fakeFormular,NPname)+tau_plots->calculateYield("reg2lSS1taunj_os_antiiso",fakeFormular,NPname));
				printf("Calculated Lepton Fake Factor: %f+/-%f",fakeFactor.nominal,fakeFactor.error);
				tau_plots->templatesample("reg2lSS1tau1bnj_os_antiisolead",histmiddlename,fakeFormular,"reg2lSS1tau1bnj_os","non-prompt_lead","non-prompt lead",(enum EColor)40,0,fakeFactor.nominal);
				tau_plots->templatesample("reg2lSS1tau1bnj_os_antiiso",histmiddlename,fakeFormular,"reg2lSS1tau1bnj_os","non-prompt_sub-lead","non-prompt sub-lead",(enum EColor)41,0,fakeFactor.nominal);
			}
		}else{
			if(showFake){
				if(mergeFake){
                                        std::cout<<"stackorder"<<std::endl;
					tau_plots->stackorder.push_back("fake1truth");
				//	tau_plots->stackorder.push_back("fake0truth");
				}
				else if(wfake) {
					tau_plots->stackorder.push_back("lep-fake");
					tau_plots->stackorder.push_back("doublefake");
					tau_plots->stackorder.push_back("other-fake");
					tau_plots->stackorder.push_back("bjet-fake");
					tau_plots->stackorder.push_back("wjet-fake");
				}else
					for (int i = 0; i < origin.size() - 2; i++) tau_plots->stackorder.push_back(origin[i]);
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
					if(NPname == "NOMINAL") {
						chart = new LatexChart("scale_factor");
					}

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
					TString varname = "tau_pt_0";
					map<TString,vector<observable>> *SFs = tau_plots->fit_scale_factor(&fit_regions, &varname, &scalesamples, &fakePtSlices, &histmiddlename, &postfit_regions);

					TH1D* SFhist;
					for (int i = 0; i < fakePtSlices.size(); ++i)	//3 pt bins
					{
						for (auto SF : *SFs) //parameters
						{
							if(chart) {
								string rowname = SF.first.Contains("wjet")? "$\\tau_{W}$" : (SF.first.Contains("bjet") ? "$\\tau_{b}$" : "$\\tau_{other}$");
								string columnname = "$" + to_string(int(fakePtSlices[i])) + "-" + to_string(int(fakePtSlices[i+1])) + "$~GeV";
								if(i == fakePtSlices.size()-2) columnname = to_string(int(fakePtSlices[i])) + "GeV$-$";
								chart->set(rowname,columnname,SF.second[i]);
							}
					
							TString histname = SF.first + "_pt" + (to_string(int(fakePtSlices[i])) + to_string(int(fakePtSlices[i+1]))).c_str();
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
					SFfile.Close();
					if(chart){
						gSystem->mkdir((chartdir + "/fakeTauFit/").Data());
						chart->print((chartdir + "/fakeTauFit/").Data() + chart->label + "_statonly");
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
						tau_plots->scale_to_data("reg1l1tau2b1j_os" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b1j_ss" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b_os" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b_ss" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
					}else{
						tau_plots->scale_to_data("reg1l1tau2b2j_os" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b3j_os" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b2j_ss" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b3j_ss" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b2j_os" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b3j_os" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b2j_ss" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b3j_ss" + nprong[i],"1 fake","tau_pt_0",fakePtSlices);
					}
				}
			}
			if(/*!mergeFake &&*/ framework == "xTFW") {
				std::cout<<"starting template!"<<std::endl;
				tau_plots->stackorder.push_back("fakeSS");
				tau_plots->templatesample("reg2mtau1b3jss",histmiddlename,"1 data -1 smhiggs -1 wjet -1 diboson -1 ztautau -1 top -1 other -1 fake1truth","reg2mtau1b3jos","fakeSS","Fake",kYellow,1,1.31597);
				tau_plots->templatesample("reg2mtau1b2jss",histmiddlename,"1 data -1 smhiggs -1 wjet -1 diboson -1 ztautau -1 top -1 other -1 fake1truth","reg2mtau1b2jos","fakeSS","Fake",kYellow,1,1.31597);

//				tau_plots->templatesample("reg2ltau1b3jss",histmiddlename,"1 data -1 smhiggs -1 wjet -1 diboson -1 ztt -1 top","reg2ltau1b3jos","fakeSS","Fake",kYellow,1,1.31597);
//				tau_plots->templatesample("reg2ltau1b2jss",histmiddlename,"1 data -1 smhiggs -1 wjet -1 diboson -1 ztt -1 top","reg2ltau1b2jos","fakeSS","Fake",kYellow,1,1.31597);				



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

		//if(!calculate_fake_calibration)
			for (auto samp : sigsamples)
			{
				tau_plots->overlay(samp.name);
			}
		if(fittodata) tau_plots->plot_stack(histmiddlename, "plots_" + NPname, "charts_" + NPname);
		else{
		//	if(figuredir == "") figuredir = ".";
		//	if(chartdir == "") chartdir = ".";
		        figuredir ="/publicfs/atlas/atlasnew/higgs/tautau/xiammfcnc/FCNC_analysis/FCNCAnalysis/";
                 	chartdir="/publicfs/atlas/atlasnew/higgs/tautau/xiammfcnc/FCNC_analysis/FCNCAnalysis/";
                        TString savename = framework;
			gSystem->mkdir(figuredir + "/" + savename);
			gSystem->mkdir(chartdir + "/" + savename);
			savename += showFake? "/showFake" : "/raw";
			gSystem->mkdir(figuredir + "/" + savename);
			gSystem->mkdir(chartdir + "/" + savename);
			if(framework == "tthML"){
				if(plotFakeLep) {
					savename += "/fakelep";
				} else{
					savename += "/faketau";
				}
					gSystem->mkdir(figuredir + "/" + savename);
					gSystem->mkdir(chartdir + "/" + savename);
					if(prefit) savename += "/prefit";
					else savename += "/postfit";
					gSystem->mkdir(figuredir + "/" + savename);
					gSystem->mkdir(chartdir + "/" + savename);
			}
			savename += "/" + NPname;
			tau_plots->plot_stack(histmiddlename, figuredir + "/" + savename,chartdir + "/" + savename);
		}
		
	}
	deletepointer(tau_plots);
	for (int i = 0; i < 3; ++i)
	{
		deletepointer(datafile[i]);
		deletepointer(datafile_fake[i]);
	}
	if(plotvar < perpart) {
		printf("finished %d variables. %d variables in this batch with batch size %d.\n", varcount, plotvar, perpart);
		return 0;
	}
	return 1;
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
		for(int ipart = 0;1;ipart++)
			if(!plot(i,framework,method,ipart) || method.Contains("IFF") || method.Contains("fit")) break;
	}
	return 0;
}
