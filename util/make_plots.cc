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

#define TESTFIT 0
using namespace std;

map<TString,observable> fakeFactor_mu;
map<TString,observable> fakeFactor_e;
TFile *getFile(TString sample, TString NPdir, TString NPname, TString nominaldir, TString nominalname){
	TFile *inputfile = new TFile(NPdir + "/" + sample + "_" + (NPdir==nominaldir? NPname : nominalname) + ".root");
	if(inputfile->IsZombie()) {
		deletepointer(inputfile);
		TString filename = nominaldir + "/" + sample + "_" + nominalname + ".root";
		printf("read from instread: %s\n",filename.Data());
		inputfile = new TFile(filename);
	}
	return inputfile;
}

int plot(int iNP, TString framework, TString method, int ipart = 0) //method = fitss / fitos / plot / trex
{
	TString dirname;
	TString NPname = findNPname(dirname,iNP,framework);
	TString nominalname = "NOMINAL";
	TString histmiddlename =  (dirname==NPname || NPname.Contains("ABCD"))? nominalname:NPname;
	TString figuredir = method.Contains("test")?"." : FIGURE_DIR;
	TString chartdir = method.Contains("test")?"." : TABLE_DIR;
	observable fakeFactorl;
	int debug = 0;
	bool prefit = 1;
	float BRbenchmark = 0.2;
	bool calculate_fake_calibration = 1;
	bool mergeFake = 0;// template: mergeFake=0,showfake=0
	bool mergeOrigin = 0;
	bool doTrex = 1;
	bool plotnj = 0;
	bool doPlots = 0;
	bool scaletodata = 0;
	bool mergeprong = 1;
	bool mergemet = 0;
	int plot_option = 2;
	bool fittodata = 0;
	bool plotFakeLep = 0;
	bool plot2lttbar = 0;
	bool showFake = 1;
	TString fitcharge = "os";
	int campaignfrom = 0;
	int campaignto = 3;
	int perpart = 1;
	int varcount = 0;
	int plotvar = 0;
	bool doFakeFactor = 0;
	bool realOnly = 1;
	bool mergeleptype = 1;
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
		realOnly = 1;
	}
	if(method.Contains("QCDFF")){
		mergeOrigin = 1;
		plotFakeLep = 0;
		doFakeFactor = 1;
		prefit = 0;
	}
	if(method.Contains("postfit")){
		prefit = 0;
	}else if(method.Contains("fit")){
		mergeOrigin = 1;
		doTrex = 0;
		doPlots = 1;
		calculate_fake_calibration = 1;
		fittodata = 1;
		fitcharge = method.Contains("os")?"os":"ss";
	}
	if(method.Contains("lep")){
		plotFakeLep = 1;
	}
	//if(fittodata == 1 && NPname.Contains("Xsec")) {
	//	histmiddlename = nominalname;
	//}
	if(framework == "xTFW") calculate_fake_calibration = 0;
	histSaver *tau_plots = new histSaver("dummy");
	tau_plots->doROC = 0;
	TString lumitag = "#it{#sqrt{s}} = 13TeV, ";
	lumitag += campaignto == 3 ? "140 fb^{-1}" : (campaignto==2?"80 fb^{-1}":"36.1 fb^{-1}");
	tau_plots->SetLumiAnaWorkflow(lumitag,"FCNC tqH H#rightarrow tautau","Work in progress");
	tau_plots->debug = debug;
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
	vector<TString> mergedOrigins = {"c_fake","g_fake","j_fake","nomatch"};
	//if(!calculate_fake_calibration){
		samples.insert(samples.begin(),sigsamples.begin(),sigsamples.end());
	//}
	TString samplesys = "";
	if(NPname.Contains("ttbarsys")){
		samplesys = "ttbar";
	}
	//if(NPname.Contains("Xsec")){
	//	bool applied = 0;
	//	for(auto &samp : samples){
	//		if(NPname.Contains(samp.name)){
	//			if(NPname.Contains("_up")) samp.norm *= 1+XsecErr.at(samp.name)[0];
	//			else samp.norm *= 1+XsecErr.at(samp.name)[1];
	//			applied = 1;
	//			break;
	//		}
	//	}
	//	if(applied == 0) {
	//		printf("Error: Xsec uncertainty %s is not applied\n", NPname.Data());
	//		exit(0);
	//	}
	//}
	auto vars = getVariables(framework);
	if(framework == "tthML"){
		if(plot2lttbar){
			tau_plots->add(vars.at("nljet"));
			tau_plots->add(vars.at("lep_pt_0"));
		}
		else if(fittodata){
			tau_plots->add(vars["tau_pt_0"]);
		}else if(doFakeFactor){
			tau_plots->sensitivevariable = "BDTG_test";
			for(auto var : vars){
				
				if(   //var.first!="tau_pt_0"
//					&&var.first!="tau_pt_1"
//					var.first!="drlbditau"
//					&&var.first!="etmiss"
//					&&var.first!="ttvismass"
//					&&var.first!="lep_pt_0"
					var.first!="chi2"
					//&&var.first!="BDTG_test"
					&&var.first!="drlb"
					&&var.first!="x1fit"
					&&var.first!="x2fit"
					&&var.first!="ttvismass"
				) continue;
				if(varcount / perpart == ipart){
					printf("registered variable: %s\n",var.first.Data());
					tau_plots->add(var.second);
					plotvar++;
				}else if(varcount / perpart == ipart+1) break;
				varcount++;
			}
			if(plotvar == 0) { printf("No variable to plot\n"); return 0; }
		}
		else if(plotnj){
			tau_plots->add(vars["njet"]);
			tau_plots->muteregion("3j");
			tau_plots->muteregion("2j");
		}else{
			tau_plots->sensitivevariable = "tau_pt_0";
			for(auto var : vars){
				
				if(   var.first!="tau_pt_0"
//					&&var.first!="tau_pt_1"
//					&&var.first!="etmiss"
//					&&var.first!="ttvismass"
//					&&var.first!="lep_pt_0"
//					&&var.first!="BDTG_test"
				) continue;
				if(varcount / perpart == ipart){
					tau_plots->add(var.second);
					plotvar++;
				}else if(varcount / perpart == ipart+1) break;
				varcount++;
			}
			if(plotvar == 0) { printf("No variable to plot\n"); return 0; }
		}
	}else{//xtfw
		tau_plots->sensitivevariable = "BDTG_test";
		if(method.Contains("trex")){
            for(auto var : vars){
                if(var.first=="BDTG_test"){
                    tau_plots->add(var.second);
                }
            }
        }else{
            for(auto var : vars){
		        if(var.first!="leading_index_bin" && var.first!="subleading_index_bin") tau_plots->add(var.second);
		    }
        }
	}




	gErrorIgnoreLevel = kWarning;
	tau_plots->blinding = 1;
	vector<TString> regions_xTFW = {
		/*//"reg1mtau1ltau1b2jss",
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
		"reg2mtau2b3jos",*/
		"reg2mtau1b2jss",
        "reg2mtau1b2jos",
        "reg2mtau1b3jos",
        "reg2mtau1b3jss",
        "reg1mtau1ltau1b2jos",
        "reg1ltau1mtau1b2jos",
        "reg1mtau1ltau1b3jos",
        "reg1ltau1mtau1b3jos",
        "reg1ltau1ntau1b2jos",
        "reg1ltau1ntau1b3jos",
        "reg1ntau1ltau1b2jos",
        "reg1ntau1ltau1b3jos",
        "reg2ltau1b2jos",
        "reg2ltau1b3jos",
        "reg1mtau1ltau1b2jss",
        "reg1ltau1mtau1b2jss",
        "reg1mtau1ltau1b3jss",
        "reg1ltau1mtau1b3jss",
        "reg1ltau1ntau1b2jss",
        "reg1ltau1ntau1b3jss",
        "reg1ntau1ltau1b2jss",
        "reg1ntau1ltau1b3jss",
        "reg2ltau1b2jss",
        "reg2ltau1b3jss",
        //"reg2mtau1b5jos",
        //"reg2mtau1b5jss",
        //"reg1mtau1ltau1b5jos",
        //"reg1ltau1mtau1b5jos",
        //"reg1mtau1ltau1b5jos",
        //"reg1ltau1mtau1b5jos",
        //"reg1ltau1ntau1b5jos",
        //"reg1ltau1ntau1b5jos",
        //"reg1ntau1ltau1b5jos",
        //"reg1ntau1ltau1b5jos",
        //"reg2ltau1b5jos",
        //"reg2ltau1b5jos"
	};
	vector<TString> regions_tthML_faketau = {
//		"reg1l1tau2b_os",
//		"reg1l1tau2b_ss",
//		"reg1l1tau2b1j_os",
//		"reg1l1tau2b1j_ss",
//		"reg1l1tau2b2j_os",
//		"reg1l1tau2b2j_ss",
//		"reg1l1tau2b3j_os",
//		"reg1l1tau2b3j_ss",
		"reg1l2tau1bnj_os",
//		"reg1l2tau1bnj_ss",
//		"reg1l2tau2bnj_os",
//		"reg1l2tau2bnj_ss",
//		"reg1l1tau1b_os",
//		"reg1l1tau1b_ss",
//		"reg1l1tau1b1j_os",
		"reg1l1tau1b1j_ss",
		"reg1l1tau1b2j_os",
		"reg1l1tau1b2j_ss",
		"reg1l1tau1b3j_os",
//		"reg1l1tau1b3j_ss",
//		"reg1l1tau1b_os_antiiso",
//		"reg1l1tau1b_ss_antiiso",
//		"reg1l1tau1b1j_os_antiiso",
		"reg1l1tau1b1j_ss_antiiso",
		"reg1l1tau1b2j_os_antiiso",
		"reg1l1tau1b2j_ss_antiiso",
		"reg1l1tau1b3j_os_antiiso",
//		"reg1l1tau1b3j_ss_antiiso",
//		"reg2l1tau1bnj",
//		"reg2l1tau2bnj",
	};
	vector<TString> regions_tthML_fakelep = {
		"reg2l1bnj",
		"reg2l2bnj",
		"reg2lSSnj",
		"reg2lSS1bnj",
		"reg2lSS2bnj"
	//	"reg2lSS1tau1bnj_os",
	//	"reg2lSS1tau1bnj_os_antiiso",
	//	"reg2lSS1tau1bnj_os_antiisolead",
	//	"reg2lSS1taunj_os",
	//	"reg2lSS1taunj_os_antiiso",
	//	"reg2lSS1taunj_os_antiisolead",
	};
	vector<TString> regions_tthML_fit = {
		"reg1l1tau2b2j_os",
		"reg1l1tau2b2j_ss",
		"reg1l1tau2b3j_os",
		"reg1l1tau2b3j_ss",
		"reg2l1tau1bnj",
		"reg2l1tau2bnj",
#if TESTFIT==1
		"reg1l1tau2b1j_os",
		"reg1l1tau2b1j_ss",
		"reg1l1tau2b_os",
		"reg1l1tau2b_ss",
		"reg1l2tau1bnj_os",
		"reg1l2tau1bnj_ss",
		"reg1l2tau2bnj_os",
		"reg1l2tau2bnj_ss",
		"reg1l1tau1b_os",
		"reg1l1tau1b_ss",
		"reg1l1tau1b1j_os",
		"reg1l1tau1b1j_ss",
		"reg1l1tau1b2j_os",
		"reg1l1tau1b2j_ss",
		"reg1l1tau1b3j_os",
		"reg1l1tau1b3j_ss",
#endif
	};
	vector<TString> regions_tthML = plotFakeLep? regions_tthML_fakelep : (fittodata?regions_tthML_fit:regions_tthML_faketau);
	if(!plotFakeLep && !fittodata && !doFakeFactor) regions_tthML.insert(regions_tthML.end(),regions_tthML_fit.begin(),regions_tthML_fit.end());
	//vector<TString> regions_calc_fake = {"reg2l1tau2b","reg1l1tau2b1j_ss","reg1l1tau2b1j_os","reg2l1tau1b","reg1l1tau2b_os","reg1l1tau2b_ss"};//,"reg2l2bnj","reg1l2b2j","reg2l2b"};
	vector<TString> regions = framework == "xTFW" ? regions_xTFW : regions_tthML;
	//if(calculate_fake_calibration) {
	//	regions = regions_calc_fake;
	//	if(fittodata) regions.insert(regions.end(), regions_tthML.begin(), regions_tthML.end());
	//}
	int nregions = regions.size();
	TString nprong[] = {"_1prong","_3prong",""};
	vector<vector<TString>> merge_suffix = {
		{"e","mu"},
		{"ee","emu","mue","mumu"},
		{"1prong","3prong"},
		{"vetobtagwp70_lowmet","vetobtagwp70_highmet"}
	};
	if(!doFakeFactor) {
		merge_suffix[3].erase(merge_suffix[3].begin());
	}
	vector<int> primensuffix;
	for(auto x: merge_suffix) primensuffix.push_back(x.size());
	if(doFakeFactor) primensuffix[2] = 0;
	else{
		primensuffix[0] = 0;
		primensuffix[1] = 0;
	}
	auto mergeregion = [&](int imerge, map<TString,vector<TString>> &ret){
		  //[other suffix][merged suffix]
		for (int j = 0; j < nregions; ++j){
			vector<int> nsuffix = primensuffix;
			int isuffix[4] = {0,0,0,0};
			TString fillname = regions[j].Data();
			bool condition = 1;
			int i = 0;
			if(framework == "tthML"){
				if(regions[j].Contains("2l")) nsuffix[0] = 0;
				if(!regions[j].Contains("2l")) nsuffix[1] = 0;
			}else{
				nsuffix[0] = nsuffix[1] = 0;
			}
			while(1){
				vector<TString> tmp;
				TString tmp1 = regions[j];
				if(imerge >= 0){
					for (isuffix[imerge] = 0; isuffix[imerge] < nsuffix[imerge]; isuffix[imerge]++)
					{
						for(int iloop = 0; iloop < merge_suffix.size(); iloop++){
							if(nsuffix[iloop] == 0) continue;
							fillname = fillname + "_" + merge_suffix[iloop][isuffix[iloop]];
							if(isuffix[imerge] == 0 && iloop != imerge)  tmp1  = tmp1 + "_" + merge_suffix[iloop][isuffix[iloop]];
						}
						tmp.push_back(fillname);
						fillname = regions[j].Data();
					}
					ret[tmp1] = tmp;
				}else{
					for(int iloop = 0; iloop < merge_suffix.size(); iloop++){
						if(nsuffix[iloop] == 0) continue;
						fillname = fillname + "_" + merge_suffix[iloop][isuffix[iloop]];
					}
					ret["all"].push_back(fillname);
					fillname = regions[j].Data();
				}
				while(isuffix[i] + 1 == nsuffix[i] || i == imerge || nsuffix[i] == 0){
					i++;
				}
				if(i>= merge_suffix.size()) break;
				isuffix[i] ++;
				for(int x = 0; x<i ; x++) isuffix[x] = 0;
				i = 0;
			}
		}
		if(imerge >= 0) primensuffix[imerge] = 0;
		return ret;
	};
	map<TString,vector<TString>> ret;
	mergeregion(-1,ret);
	for(auto reg : ret["all"]) tau_plots->add_region(reg);
     tau_plots->show();
	auto origin = plotFakeLep?getFakeLepOrigin() : getFakeTauOrigin();

	if(!plotFakeLep){
		if(mergeprong) tau_plots->muteregion("prong");
	}
	tau_plots->muteregion("_e_");
	tau_plots->muteregion("_mu_");
	tau_plots->muteregion("_ee_");
	tau_plots->muteregion("_mumu_");
	tau_plots->muteregion("_emu_");
	tau_plots->muteregion("_mue_");
	bool dopt = 0;
	for( auto &var : tau_plots->v) if(var->name == "lep_pt_0"){
		dopt = 1;
		break;
	}
	if(!dopt) {
		tau_plots->muteregion("lowmet");
		tau_plots->muteregion("antiiso");
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
							tau_plots->read_sample( origin.at(i).name, signalsamp + "_" + origin.at(i).name, histmiddlename, origin.at(i).title, (enum EColor)colors[i], norm,inputfile);
							deletepointer(inputfile);
						}
					}
					TString samplename = (samplesys==samples[j].name ? NPname : samples[j].name);
					//inputfile = getFile(mc_campaign + "_" + samplename + (framework == "tthML"? (calculate_fake_calibration ? "_fake" : "_fcnc") : ""), dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					inputfile = getFile(mc_campaign + "_" + samplename , dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					double norm = samples[j].norm;
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
						for (int i = 0; i < origin.size(); i++) {
							tau_plots->read_sample( samples[j].name, signalsamp + "_" + origin.at(i).name, histmiddlename, samples[j].title, samples[j].color, samples[j].norm, inputfile);
						}
						deletepointer(inputfile);
					}
				}else{
					TString samplename = (samplesys==samples[j].name ? NPname : samples[j].name);
					inputfile = getFile(mc_campaign + "_" + samplename, dirname, NPname, (framework == "tthML"? "nominal" : "NOMINAL"), nominalname);
					double norm = samples[j].norm;
					if(plotFakeLep) tau_plots->read_sample( samples[j].name, samplename + "_realLep", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					else tau_plots->read_sample( samples[j].name, samplename + "_real", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					//tau_plots->read_sample( samples[j].name, samplename + "_lep", histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
					if(!realOnly){
						if(showFake){
							if (mergeFake) {
								for (int i = 1; i < origin.size() - 1; i++) {
									tau_plots->read_sample( "fake1truth", samplename + origin.at(i).name, histmiddlename, "Fake MC, 1 truth #tau", kMagenta, norm, inputfile);
								}
								tau_plots->read_sample( "fake0truth", samplename + "_doublefake", histmiddlename, "fake, 0 truth #tau", kTeal, norm,inputfile);
							}else 
								for (int i = 1; i < origin.size() - (framework=="xTFW"); i++){  //no double fake for hadhad channel
									if(mergeOrigin && find(mergedOrigins.begin(),mergedOrigins.end(),origin.at(i).name) != mergedOrigins.end())
										tau_plots->read_sample( "other_fake", samplename + "_" + origin.at(i).name, histmiddlename, "Other Fake #tau", (enum EColor)(i+40), norm, inputfile);
									else
										tau_plots->read_sample( origin.at(i).name, samplename + "_" + origin.at(i).name, histmiddlename, origin.at(i).title, (enum EColor)(i+40), norm, inputfile);
								}
						}else{
							for (int i = 1; i < origin.size(); i++){
								tau_plots->read_sample( samples[j].name, samplename + "_" + origin.at(i).name, histmiddlename, samples[j].title, samples[j].color, norm, inputfile);
							}
						}
					}
					deletepointer(inputfile);
				}
			}
		}

	}
	if(mergeprong){
		map<TString,vector<TString>> ret;
		mergeregion(2,ret);
		for(auto i : ret){
			if(i.second.size()>1) tau_plots->merge_regions(i.second, i.first);
		}
	} tau_plots->show();
	if(plot_option == 2){
		for(auto samp: samples){
			if(signalmap.find(samp.name) == signalmap.end()) tau_plots->stackorder.push_back(samp.name);
		}
		if(plotFakeLep){
			for (int i = 0; i < origin.size() - 2; i++) tau_plots->stackorder.push_back(origin.at(i).name);
			if(doFakeFactor && framework == "tthML") {
				tau_plots->stackorder.push_back("non-prompt_lead");
				tau_plots->stackorder.push_back("non-prompt_sub-lead");
				string fakeFormular="1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 ttbar -1 ttV -1 others";
				if(fakeFactorl.nominal == 0)
					fakeFactorl=tau_plots->calculateYield("reg2lSS1taunj_os",fakeFormular,histmiddlename)/(tau_plots->calculateYield("reg2lSS1taunj_os_antiisolead",fakeFormular,histmiddlename)+tau_plots->calculateYield("reg2lSS1taunj_os_antiiso",fakeFormular,histmiddlename));
				printf("Calculated Lepton Fake Factor: %f+/-%f",fakeFactorl.nominal,fakeFactorl.error);
				tau_plots->templatesample("reg2lSS1tau1bnj_os_antiisolead",histmiddlename,fakeFormular,"reg2lSS1tau1bnj_os","non-prompt_lead","non-prompt lead",(enum EColor)40,0,fakeFactorl.nominal);
				tau_plots->templatesample("reg2lSS1tau1bnj_os_antiiso",histmiddlename,fakeFormular,"reg2lSS1tau1bnj_os","non-prompt_sub-lead","non-prompt sub-lead",(enum EColor)41,0,fakeFactorl.nominal);
			}
		}else{
			if(showFake){
				if(mergeFake){
					tau_plots->stackorder.push_back("fake1truth");
					tau_plots->stackorder.push_back("fake0truth");
				}
				else
					for (int i = 1; i < origin.size(); i++) {
						if(mergeOrigin && find(mergedOrigins.begin(),mergedOrigins.end(),origin.at(i).name) != mergedOrigins.end()) continue;
						tau_plots->stackorder.push_back(origin.at(i).name);
					}
					if(mergeOrigin) tau_plots->stackorder.push_back("other_fake");
			}
			if(doFakeFactor && framework == "tthML") {
				LatexChart *FFchart = 0;
				if(ipart==0) if(iNP == 0) FFchart = new LatexChart("FF");
				tau_plots->stackorder.push_back("FF_QCD_mu");
				tau_plots->stackorder.push_back("FF_QCD_e");
				string fakeFormular="1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 ttbar -1 ttV -1 others -1 lep_fake -1 other_fake -1 b_fake -1 w_jet_fake";
				vector<TString> FFregions = {
					//"reg1l1tau1b1j_os",
					"reg1l1tau1b1j_ss",
//					"reg1l1tau1b_ss",
					//"reg1l1tau1b_os",
					"reg1l1tau1b2j_os",
					"reg1l1tau1b2j_ss",
					"reg1l1tau1b3j_os",
					//"reg1l1tau1b3j_ss"
				};
				for(auto FFreg: FFregions){
					if(ipart == 0){
						fakeFactor_e[FFreg]=tau_plots->calculateYield(FFreg + "_e_vetobtagwp70_lowmet",fakeFormular,histmiddlename);
						fakeFactor_e[FFreg].error = rms(fakeFactor_e[FFreg].error,tau_plots->calculateYield(FFreg + "_e_vetobtagwp70_lowmet","1 tuH",histmiddlename).nominal);
						fakeFactor_e[FFreg]=fakeFactor_e[FFreg]/(tau_plots->calculateYield(FFreg + "_antiiso_e_vetobtagwp70_lowmet",fakeFormular,histmiddlename));
						if(FFchart) FFchart->set(translateRegion(FFreg).Data(),"Electron",fakeFactor_e[FFreg]);
					}
					//tau_plots->templatesample(FFreg + "_antiiso_e_vetobtagwp70_highmet",histmiddlename,fakeFormular,FFreg + "_e_vetobtagwp70_highmet","FF_QCD_e","#muFF(QCD)",(enum EColor)45,0,fakeFactor_e[FFreg].nominal);
					if(ipart == 0){
						fakeFactor_mu[FFreg]=tau_plots->calculateYield(FFreg + "_mu_vetobtagwp70_lowmet",fakeFormular,histmiddlename);
						fakeFactor_mu[FFreg].error = rms(fakeFactor_mu[FFreg].error,tau_plots->calculateYield(FFreg + "_mu_vetobtagwp70_lowmet","1 tuH",histmiddlename).nominal);
						fakeFactor_mu[FFreg]=fakeFactor_mu[FFreg]/(tau_plots->calculateYield(FFreg + "_antiiso_mu_vetobtagwp70_lowmet",fakeFormular,histmiddlename));
						if(FFchart) FFchart->set(translateRegion(FFreg).Data(),"Muon",fakeFactor_mu[FFreg]);
					}
					//tau_plots->templatesample(FFreg + "_antiiso_mu_vetobtagwp70_highmet",histmiddlename,fakeFormular,FFreg + "_mu_vetobtagwp70_highmet","FF_QCD_mu","eFF(QCD)",(enum EColor)46,0,fakeFactor_mu[FFreg].nominal);
				}
				if(ipart==0) {
					if(iNP == 0) gSystem->mkdir((chartdir + "/FF/").Data());
					auto getvec = [&](auto map){
						std::vector<observable> ret;
						for(auto x : map){
							ret.push_back(x.second);
						}
						return ret;
					};
					auto combFF_e = getvec(fakeFactor_e);
					auto combFF_mu = getvec(fakeFactor_mu);
					fakeFactor_e["combine"] = measure(combFF_e);
					fakeFactor_mu["combine"] = measure(combFF_mu);
					if(FFchart) {
						FFchart->set("Combined","Electron",fakeFactor_e["combine"]);
						FFchart->set("Combined","Muon",fakeFactor_mu["combine"]);
						FFchart->print((chartdir + "/FF/fakeFactor").Data());
						deletepointer(FFchart);
					}
				}
				for(auto FFreg: FFregions){
					tau_plots->templatesample(FFreg + "_antiiso_e_vetobtagwp70_highmet",histmiddlename,fakeFormular,FFreg + "_e_vetobtagwp70_highmet","FF_QCD_e","eFF(QCD)",(enum EColor)51,0,fakeFactor_e["combine"].nominal);
					tau_plots->templatesample(FFreg + "_antiiso_mu_vetobtagwp70_highmet",histmiddlename,fakeFormular,FFreg + "_mu_vetobtagwp70_highmet","FF_QCD_mu","#muFF(QCD)",(enum EColor)52,0,fakeFactor_mu["combine"].nominal);
				}
			}
			if(fittodata){
			//	map<TString,vector<TString>> ret;
			//	mergeregion(0,ret);
			//	mergeregion(1,ret);
			//	for(auto i : ret){
			//		if(i.second.size()>1) tau_plots->merge_regions(i.second, i.first);
			//	}
				for(int i = 0; i < 3; i++){
					if(mergeprong) { if(i != 2) continue; }
					else { if(i == 2) continue; }

					TString prefix = PACKAGE_DIR;
					prefix += "/data/";
					TString suffix = nprong[i] + "_vetobtagwp70_highmet";
					LatexChart *chart = 0;
#if FITSTRATEGY != 3
					vector<TString> fit_regions = {
//						"reg1l1tau1b2j_ss" + suffix, "reg1l1tau1b3j_ss" + suffix,
						"reg1l1tau2b2j_os" + suffix, "reg1l1tau2b3j_os" + suffix,
						"reg1l1tau2b2j_ss" + suffix, "reg1l1tau2b3j_ss" + suffix,
						"reg2l1tau1bnj" + suffix,"reg2l1tau2bnj" + suffix
					};
					TFile SFfile(prefix + "scale_factors" + nprong[i] + ".root","update");
					if(iNP == 0) {
						chart = new LatexChart(("scale_factor" + nprong[i]).Data());
					}
#else
					vector<TString> fit_regions = {"reg1l1tau2b2j_" + fitcharge + suffix, "reg1l1tau2b3j_" + fitcharge + suffix, "reg1l1tau2b1j_" + fitcharge + suffix,"reg2l1tau1b" + suffix,"reg2l1tau2b" + suffix};
					vector<TString> fit_regions = {"reg1l1tau2b2j_" + fitcharge + suffix, "reg1l1tau2b3j_" + fitcharge + suffix,"reg2l1tau1b" + suffix,"reg2l1tau2b" + suffix};
					vector<TString> fit_regions = {"reg1l1tau2b2j_" + fitcharge + suffix, "reg1l1tau2b1j_" + fitcharge + suffix,"reg2l1tau1b" + suffix,"reg2l1tau2b" + suffix};
					vector<TString> postfit_regions = fit_regions;
					postfit_regions.push_back("reg1l1tau1b2j_" + fitcharge + suffix);
					postfit_regions.push_back("reg1l1tau1b3j_" + fitcharge + suffix);
					TFile SFfile(prefix + "scale_factors_" + fitcharge + nprong[i] + ".root","update");
					if(iNP == 0) {
						chart = new LatexChart(("scale_factor_" + fitcharge + nprong[i]).Data());
					}
#endif
#if FITSTRATEGY != 2
					vector<TString> postfit_regions = fit_regions;
					postfit_regions.push_back("reg1l1tau1b2j_os" + suffix);
					postfit_regions.push_back("reg1l1tau1b3j_os" + suffix);
					vector<TString> scalesamples = {"w_jet_fake","other_fake","b_fake"};
#else
					map<TString,map<TString,vector<TString>>> scalesamples;
					scalesamples["other_fake"];
					scalesamples["w_jet_fake"];
					scalesamples["w_jet_fake"] = {
						{"ss", {"reg1l1tau2b2j_ss" + suffix, "reg1l1tau2b3j_ss" + suffix}},
						{"os", {"reg1l1tau2b2j_os" + suffix, "reg1l1tau2b3j_os" + suffix, "reg2l1tau1bnj" + suffix, "reg2l1tau2bnj" + suffix}},
					};
					scalesamples["b_fake"];
					map<TString,map<TString,vector<TString>>> postfit_regions = scalesamples;
					postfit_regions["w_jet_fake"]["ss"].push_back("reg1l1tau1b3j_ss" + suffix);
					postfit_regions["w_jet_fake"]["ss"].push_back("reg1l1tau1b2j_ss" + suffix);
					postfit_regions["w_jet_fake"]["os"].push_back("reg1l1tau1b3j_os" + suffix);
					postfit_regions["w_jet_fake"]["os"].push_back("reg1l1tau1b2j_os" + suffix);
#endif
					TString varname = "tau_pt_0";

					map<TString,vector<observable>> *SFs = tau_plots->fit_scale_factor(&fit_regions, &varname, &scalesamples, &fakePtSlices, &histmiddlename, &postfit_regions);

					TH1D* SFhist;
					for (int i = 0; i < fakePtSlices.size()-1; ++i)	//3 pt bins
					{
						for (auto SF : *SFs) //parameters
						{
							if(chart) {
								string rowname;
								if(SF.first.Contains("w_jet_fake")){
									rowname = "$\\tau_{W}$";
									if(SF.first.Contains("os")) rowname += "~os";
									if(SF.first.Contains("ss")) rowname += "~ss";
								}else
									rowname = SF.first.Contains("b_fake") ? "$\\tau_{b~fake}$" : "$\\tau_{other}$";
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
					TString suffix = nprong[i] + "_vetobtagwp70_highmet";
					vector<double> BDTslice = {-1,-0.4,0.1,0.3,0.5,0.65,0.75,0.85,1};
					vector<observable> mismodel2j = tau_plots->scale_to_data("reg1l1tau1b2j_ss" + suffix,"1 w_jet_fake","BDTG_test",BDTslice);
					vector<observable> mismodel3j = tau_plots->scale_to_data("reg1l1tau1b3j_ss" + suffix,"1 w_jet_fake","BDTG_test",BDTslice);
					tau_plots->scale_sample("reg1l1tau1b2j_os" + suffix,"1 w_jet_fake","BDTG_test",mismodel2j,BDTslice);
					tau_plots->scale_sample("reg1l1tau1b3j_os" + suffix,"1 w_jet_fake","BDTG_test",mismodel3j,BDTslice);
				}
			}

			if(scaletodata){
				for(int i = 0; i < 3; i++){
					if(mergeprong) { if(i != 2) continue; }
					else { if(i == 2) continue; }
					TString suffix = nprong[i] + "_vetobtagwp70_highmet";
					if(calculate_fake_calibration){
						tau_plots->scale_to_data("reg1l1tau2b1j_os" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b1j_ss" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b_os" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b_ss" + suffix,"1 fake","tau_pt_0",fakePtSlices);
					}else{
						tau_plots->scale_to_data("reg1l1tau2b2j_os" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b3j_os" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b2j_ss" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau2b3j_ss" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b2j_os" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b3j_os" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b2j_ss" + suffix,"1 fake","tau_pt_0",fakePtSlices);
						tau_plots->scale_to_data("reg1l1tau1b3j_ss" + suffix,"1 fake","tau_pt_0",fakePtSlices);
					}
				}
			}
			if(/*!mergeFake &&*/ framework == "xTFW") {
				std::cout<<"starting template!"<<std::endl;
				tau_plots->stackorder.push_back("Fake");
                std::vector<TString> tmp_regions_={"data","smhiggs","wjet","diboson","ztautau","top","other"};
				if(showFake){
                    if(mergeprong==1){
                        tau_plots->FakeFactorMethod("reg2mtau1b2jos","reg1mtau1ltau1b2jos","reg1ltau1mtau1b2jos","reg1ltau1ntau1b2jos","reg1ntau1ltau1b2jos","reg2ltau1b2jos",histmiddlename,"Fake","Fake",tmp_regions_,(enum EColor)42);
                        tau_plots->FakeFactorMethod("reg2mtau1b3jos","reg1mtau1ltau1b3jos","reg1ltau1mtau1b3jos","reg1ltau1ntau1b3jos","reg1ntau1ltau1b3jos","reg2ltau1b3jos",histmiddlename,"Fake","Fake",tmp_regions_,(enum EColor)42);
                        tau_plots->FakeFactorMethod("reg2mtau1b3jss","reg1mtau1ltau1b3jss","reg1ltau1mtau1b3jss","reg1ltau1ntau1b3jss","reg1ntau1ltau1b3jss","reg2ltau1b3jss",histmiddlename,"Fake","Fake",tmp_regions_,(enum EColor)42);
                        tau_plots->FakeFactorMethod("reg2mtau1b2jss","reg1mtau1ltau1b2jss","reg1ltau1mtau1b2jss","reg1ltau1ntau1b2jss","reg1ntau1ltau1b2jss","reg2ltau1b2jss",histmiddlename,"Fake","Fake",tmp_regions_,(enum EColor)42);
                        //tau_plots->FakeFactorMethod("reg2mtau1b5jos","reg1mtau1ltau1b5jos","reg1ltau1mtau1b5jos","reg1ltau1ntau1b5jos","reg1ntau1ltau1b5jos","reg2ltau1b5jos",histmiddlename,"Fake","Fake",tmp_regions_,(enum EColor)42);
                    }else{
	                    tau_plots->FakeFactorMethod("reg2mtau1b2jos_3prong_vetobtagwp70","reg1mtau1ltau1b2jos_3prong_vetobtagwp70","reg1ltau1mtau1b2jos_3prong_vetobtagwp70","reg1ltau1ntau1b2jos_3prong_vetobtagwp70","reg1ntau1ltau1b2jos_3prong_vetobtagwp70","reg2ltau1b2jos_3prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b3jos_3prong_vetobtagwp70","reg1mtau1ltau1b3jos_3prong_vetobtagwp70","reg1ltau1mtau1b3jos_3prong_vetobtagwp70","reg1ltau1ntau1b3jos_3prong_vetobtagwp70","reg1ntau1ltau1b3jos_3prong_vetobtagwp70","reg2ltau1b3jos_3prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b3jss_3prong_vetobtagwp70","reg1mtau1ltau1b3jss_3prong_vetobtagwp70","reg1ltau1mtau1b3jss_3prong_vetobtagwp70","reg1ltau1ntau1b3jss_3prong_vetobtagwp70","reg1ntau1ltau1b3jss_3prong_vetobtagwp70","reg2ltau1b3jss_3prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b2jss_3prong_vetobtagwp70","reg1mtau1ltau1b2jss_3prong_vetobtagwp70","reg1ltau1mtau1b2jss_3prong_vetobtagwp70","reg1ltau1ntau1b2jss_3prong_vetobtagwp70","reg1ntau1ltau1b2jss_3prong_vetobtagwp70","reg2ltau1b2jss_3prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b5jos_3prong_vetobtagwp70","reg1mtau1ltau1b5jos_3prong_vetobtagwp70","reg1ltau1mtau1b5jos_3prong_vetobtagwp70","reg1ltau1ntau1b5jos_3prong_vetobtagwp70","reg1ntau1ltau1b5jos_3prong_vetobtagwp70","reg2ltau1b5jos_3prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);

                        tau_plots->FakeFactorMethod("reg2mtau1b2jos_1prong_vetobtagwp70","reg1mtau1ltau1b2jos_1prong_vetobtagwp70","reg1ltau1mtau1b2jos_1prong_vetobtagwp70","reg1ltau1ntau1b2jos_1prong_vetobtagwp70","reg1ntau1ltau1b2jos_1prong_vetobtagwp70","reg2ltau1b2jos_1prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b3jos_1prong_vetobtagwp70","reg1mtau1ltau1b3jos_1prong_vetobtagwp70","reg1ltau1mtau1b3jos_1prong_vetobtagwp70","reg1ltau1ntau1b3jos_1prong_vetobtagwp70","reg1ntau1ltau1b3jos_1prong_vetobtagwp70","reg2ltau1b3jos_1prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b3jss_1prong_vetobtagwp70","reg1mtau1ltau1b3jss_1prong_vetobtagwp70","reg1ltau1mtau1b3jss_1prong_vetobtagwp70","reg1ltau1ntau1b3jss_1prong_vetobtagwp70","reg1ntau1ltau1b3jss_1prong_vetobtagwp70","reg2ltau1b3jss_1prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b2jss_1prong_vetobtagwp70","reg1mtau1ltau1b2jss_1prong_vetobtagwp70","reg1ltau1mtau1b2jss_1prong_vetobtagwp70","reg1ltau1ntau1b2jss_1prong_vetobtagwp70","reg1ntau1ltau1b2jss_1prong_vetobtagwp70","reg2ltau1b2jss_1prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                        tau_plots->FakeFactorMethod("reg2mtau1b5jos_1prong_vetobtagwp70","reg1mtau1ltau1b5jos_1prong_vetobtagwp70","reg1ltau1mtau1b5jos_1prong_vetobtagwp70","reg1ltau1ntau1b5jos_1prong_vetobtagwp70","reg1ntau1ltau1b5jos_1prong_vetobtagwp70","reg2ltau1b5jos_1prong_vetobtagwp70",histmiddlename,"Fake","Fake",tmp_regions_,kYellow);
                    }
                }


//tau_plots->templatesample("reg2mtau2b3jss","1 data -1 smhiggs -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b3jos","fakeSS","Fake",kYellow,1);
				//tau_plots->templatesample("reg2mtau2b2jss","1 data -1 smhiggs -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b2jos","fakeSS","Fake",kYellow,1);
	
				//tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 smhiggs -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
				//tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 smhiggs -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
		
				//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
				//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
				////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
				////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
		
				//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 mergeFake -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
				//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 mergeFake -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
				////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 mergeFake -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
				////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 mergeFake -1 w_jet_fake -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
			}
		}
	}
	if(!mergeprong){
		map<TString,vector<TString>> ret;
		mergeregion(2,ret);
		for(auto i : ret){
			if(i.second.size()>1) tau_plots->merge_regions(i.second, i.first);
		}
	}
	if(mergeleptype && !fittodata){
		map<TString,vector<TString>> ret;
		mergeregion(0,ret);
		mergeregion(1,ret);
		for(auto i : ret){
			if(i.second.size()>1) tau_plots->merge_regions(i.second, i.first);
		}
	}
	if(mergemet){
		map<TString,vector<TString>> ret;
		mergeregion(3,ret);
		for(auto i : ret){
			if(i.second.size()>1) tau_plots->merge_regions(i.second, i.first);
		}
	}else{
		tau_plots->merge_regions("reg1l2tau1bnj_os_vetobtagwp70_highmet","reg1l2tau1bnj_os_vetobtagwp70_lowmet", "reg1l2tau1bnj_os");
		tau_plots->muteregion("reg1l2tau1bnj_os_vetobtagwp70_highmet");
	}
	tau_plots->show();
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

		//if(!calculate_fake_calibration)
			for (auto samp : sigsamples)
			{
				tau_plots->overlay(samp.name);
			}
		if(figuredir == "") figuredir = ".";
		if(chartdir == "") chartdir = ".";
		TString savename = framework;
		gSystem->mkdir(figuredir + "/" + savename);
		gSystem->mkdir(chartdir + "/" + savename);
		if(fittodata) {
			gSystem->mkdir(chartdir + "/" + savename + "/originFit");
			tau_plots->plot_stack(histmiddlename, figuredir + "/" + savename + "/originFit", "charts_Fit");
		}
		else{
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
			if(!plot(i,framework,method,ipart) || method.Contains("IFF") || (method.Contains("fit")&&!method.Contains("postfit"))) break;
	}
	return 0;
}
