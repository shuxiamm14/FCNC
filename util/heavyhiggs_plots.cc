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
#include "TColor.h"
using namespace std;

std::map<TString,variable*> getVariablesHH(){
	std::map<TString,variable*> ret;
	ret["Meff"]=new variable("Meff","M_{eff}^{2l}",30,0,3000,"GeV",1e-3, 1);
	ret["met"]=new variable("met","E_{T}^{miss}",200,0,1000,"GeV",1e-3, 1);
	ret["Reg3lMhh"]=new variable("Reg3lMhh", "M_{H}", 9, 150, 1050,"GeV", 1e-3, 1);
	return ret;
}

int plot(int iNP, TString method, int ipart = 0) //method = fitss / fitos / plot / trex
{
	TString NPname = "NOMINAL";
	bool doTrex = 1;
	bool doPlots = 0;
	int perpart = 5;
	int varcount = 0;
	int plotvar = 0;
	bool mergeDiletype = 1;

	if(method.Contains("plot")){
		doTrex = 0;
		doPlots = 1;
	}
	histSaver *tau_plots = new histSaver("dummy");
	tau_plots->doROC = 0;
	TString lumitag = "#it{#sqrt{s}} = 13TeV, ";
	lumitag += "140 fb^{-1}";
	tau_plots->SetLumiAnaWorkflow(lumitag,"Heavy Higgs","Internal");
	tau_plots->debug = 0;
/*
	tau_plots->checkread = 1;
	tau_plots->checkread_sample = "fake";
	tau_plots->checkread_region = "reg1l1tau1b2j_os_1prong_above35_vetobtagwp70";
	tau_plots->checkread_variation = "NOMINAL";
	tau_plots->checkread_variable = 0;
	tau_plots->checkread_ibin = 2;
*/


	map<TString, enum EColor> ColorMap;
	TColor tcolor;
	ColorMap["Red"] = (enum EColor)tcolor.GetColor((int)228, 26, 28);
	ColorMap["LightRed"] = (enum EColor)tcolor.GetColor((int)255, 47, 42);
	ColorMap["DarkRed"] = (enum EColor)tcolor.GetColor((int)156, 18, 19);
	ColorMap["Blue"] = (enum EColor)tcolor.GetColor((int)55, 126, 184);
	ColorMap["LightBlue"] = (enum EColor)tcolor.GetColor((int)92, 182, 245);
	ColorMap["DarkBlue"] = (enum EColor)tcolor.GetColor((int)43, 100, 145);
	ColorMap["Green"] = (enum EColor)tcolor.GetColor((int)77, 175, 74);
	ColorMap["LightGreen"] = (enum EColor)tcolor.GetColor((int)116, 238, 127);
	ColorMap["DarkGreen"] = (enum EColor)tcolor.GetColor((int)28, 135, 47);
	ColorMap["Purple"] = (enum EColor)tcolor.GetColor((int)152, 78, 163);
	ColorMap["LightPurple"] = (enum EColor)tcolor.GetColor((int)219, 130, 227);
	ColorMap["DarkPurple"] = (enum EColor)tcolor.GetColor((int)128, 66, 138);
	ColorMap["Orange"] = (enum EColor)tcolor.GetColor((int)255, 127, 0);
	ColorMap["DarkOrange"] = (enum EColor)tcolor.GetColor((int)178, 89, 0);
	ColorMap["Yellow"] = (enum EColor)tcolor.GetColor((int)255, 255, 51);
	ColorMap["DarkYellow"] = (enum EColor)tcolor.GetColor((int)166, 166, 33);
	ColorMap["Brown"] = (enum EColor)tcolor.GetColor((int)128, 98, 16);
	ColorMap["DarkBrown"] = (enum EColor)tcolor.GetColor((int)102, 78, 11);
	ColorMap["Grey"] = (enum EColor)tcolor.GetColor((int)190, 174, 212);
	ColorMap["DarkGrey"] = (enum EColor)tcolor.GetColor((int)190, 174, 200);
	ColorMap["Pink"] = (enum EColor)tcolor.GetColor((int)244, 202, 172);
	ColorMap["DarkPink"] = (enum EColor)tcolor.GetColor((int)244, 202, 160);
	ColorMap["Skin"] = (enum EColor)tcolor.GetColor((int)253, 191, 111);
	ColorMap["DarkSkin"] = (enum EColor)tcolor.GetColor((int)253, 191, 100);
	ColorMap["Wjets1"] = (enum EColor)tcolor.GetColor((int)140, 150, 198);
	ColorMap["Wjets2"] = (enum EColor)tcolor.GetColor((int)136, 86, 167);
	ColorMap["Wjets3"] = (enum EColor)tcolor.GetColor((int)129, 15, 124);
	ColorMap["DarkWjets1"] = (enum EColor)tcolor.GetColor((int)140, 150, 198);
	ColorMap["DarkWjets2"] = (enum EColor)tcolor.GetColor((int)136, 86, 167);
	ColorMap["DarkWjets3"] = (enum EColor)tcolor.GetColor((int)129, 15, 124);

	// SampleColorMap["WWW"] = "Yellow"
	// SampleColorMap["WZ"] = "Orange"
	// SampleColorMap["V#gamma"] = "Green"
	// SampleColorMap["Fake"] = "Purple"
	// SampleColorMap["Charge Flip"] = "Blue"
	// SampleColorMap["OtherSS"] = "Red"

	vector<fcncSample> sigsamples;
	int signorm = 1;
	TString tmp = "";
 	sigsamples.emplace_back("GHH300X","VH#rightarrow VVV,300X"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH300Y","VH#rightarrow VVV,300Y"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3f600f0","VH#rightarrow VVV,3f600f0"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3fm600f0","VH#rightarrow VVV,3fm600f0"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3f350f2100","VH#rightarrow VVV,3f350f2100"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3fm350f2100","VH#rightarrow VVV,3fm350f2100"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3fm350fm2100","VH#rightarrow VVV,3fm350fm2100"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3f350fm2100","VH#rightarrow VVV,3f350fm2100"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3f0f3000","VH#rightarrow VVV,3f0f3000"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH3f0fm3000","VH#rightarrow VVV,3f0fm3000"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH600X","VH#rightarrow VVV,600X"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH600Y","VH#rightarrow VVV,600Y"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6f650f0","VH#rightarrow VVV,6f650f0"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6fm650f0","VH#rightarrow VVV,6fm650f0"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6f400f2400","VH#rightarrow VVV,6f400f2400"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6fm400f2400","VH#rightarrow VVV,6fm400f2400"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6fm400fm2400","VH#rightarrow VVV,6fm400fm2400"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6f400fm2400","VH#rightarrow VVV,6f400fm2400"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6f0f3500","VH#rightarrow VVV,6f0f3500"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH6f0fm3500","VH#rightarrow VVV,6f0fm3500"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH900X","VH#rightarrow VVV,900X"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9f800f0","VH#rightarrow VVV,9f800f0"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9fm800f0","VH#rightarrow VVV,9fm800f0"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9f600f3600","VH#rightarrow VVV,9f600f3600"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9fm600f3600","VH#rightarrow VVV,9fm600f3600"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9fm600fm3600","VH#rightarrow VVV,9fm600fm3600"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9f600fm3600","VH#rightarrow VVV,9f600fm3600"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9f0f5000","VH#rightarrow VVV,9f0f5000"+tmp,kRed,signorm);
 	sigsamples.emplace_back("GHH9f0fm5000","VH#rightarrow VVV,9f0fm5000"+tmp,kRed,signorm);
	vector<fcncSample> bkgsamples;
	bkgsamples.emplace_back("WWW","WWW",ColorMap["Yellow"]);
	bkgsamples.emplace_back("ssWW","ssWW",ColorMap["Brown"]);
	bkgsamples.emplace_back("VVV","VVV",ColorMap["Pink"]);
	bkgsamples.emplace_back("DiBoson","Diboson",ColorMap["LightPurple"]); // ZZ + WZ
//	bkgsamples.emplace_back("ZZ","ZZ",ColorMap["Grey"]);
//	bkgsamples.emplace_back("WZ","WZ",ColorMap["LightPurple"]);
	bkgsamples.emplace_back("TopX","top + X",ColorMap["Wjets1"]); // tZ + ttW + ttZ
//	bkgsamples.emplace_back("tZ","tZ",ColorMap["Wjets3"]);
//	bkgsamples.emplace_back("ttW","ttW",ColorMap["Wjets1"]);
//	bkgsamples.emplace_back("ttZ","ttZ",ColorMap["Wjets2"]);
	bkgsamples.emplace_back("Others","Others",ColorMap["LightBlue"]); // SingleTop + Wjets + Zjets + ttbar + Vgamma
//	bkgsamples.emplace_back("SingleTop","SingleTop",ColorMap["Skin"]);
//	bkgsamples.emplace_back("Wjets","Wjets",ColorMap["Blue"]);
//	bkgsamples.emplace_back("Zjets","Zjets",ColorMap["Green"]);
//	bkgsamples.emplace_back("ttbar","ttbar",ColorMap["LightBlue"]);
//	bkgsamples.emplace_back("Vgamma","Vgamma",ColorMap["Orange"]);
 	vector<fcncSample> samples = bkgsamples;
	map<TString, std::vector<TString>> merge = {
		{"Others",{"SingleTop", "Wjets", "Zjets", "ttbar", "Vgamma"}},
		{"TopX",{"tZ","ttW","ttZ"}},
		{"DiBoson",{"ZZ","WZ"}}
	};

	//if(!calculate_fake_calibration){
		samples.insert(samples.begin(),sigsamples.begin(),sigsamples.end());
	//}
	//TString samplesys = "";
	//if(NPname.Contains("ttbarsys")){
	//	samplesys = "ttbar";
	//}
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
	auto vars = getVariablesHH();
	tau_plots->sensitivevariable = "Meff";
	for(auto var : vars){
			if(varcount / perpart == ipart){
			tau_plots->add(var.second);
			plotvar++;
		}else if(varcount / perpart == ipart+1) break;
		varcount++;
	}

	gErrorIgnoreLevel = kWarning;
	tau_plots->blinding = 2;
	vector<TString> regions = {"Resolved_ss2l_SR","Boosted_ss2l_SR","Resolved_3l_SR","Boosted_3l_SR"};

	int nregions = regions.size();
	vector<TString> dileptype = {"ee","emu","mue","mumu"};
	for (int j = 0; j < nregions; ++j){
		tau_plots->add_region(regions[j]+"_ee");
		tau_plots->add_region(regions[j]+"_emu");
		tau_plots->add_region(regions[j]+"_mue");
		tau_plots->add_region(regions[j]+"_mumu");
	}

	TFile *inputfile = new TFile("GHH_v1.root");
	//tau_plots->read_sample("data","Data","NOMINAL","data",kBlack, 1, inputfile);
	TString histmiddlename = "NOMINAL";
	for (int j = 0; j < samples.size(); ++j){
		if(merge.find(samples[j].name) == merge.end()) tau_plots->read_sample( samples[j].name, samples[j].name, histmiddlename, samples[j].title, samples[j].color, samples[j].norm, inputfile);
		else{
			for(auto subsamples : merge[samples[j].name]){
				tau_plots->read_sample( samples[j].name, subsamples, histmiddlename, samples[j].title, samples[j].color, samples[j].norm, inputfile);
			}
		}
	}
//============================ merge_origin ============================
	if(mergeDiletype){
		for (int j = 0; j < nregions; ++j){
			vector<TString> mergeregions;
			for(auto type : dileptype) mergeregions.push_back(regions[j] + "_" + type);
			tau_plots->merge_regions(mergeregions,regions[j]);
		}
	}
	for(auto samp: bkgsamples){
		tau_plots->stackorder.push_back(samp.name);
	}

	if(doTrex){
		std::string nptmp = NPname.Data();
//		findAndReplaceAll(nptmp,"__1down","_down");
//		findAndReplaceAll(nptmp,"__1up","_up");
//		findAndReplaceAll(nptmp,"JET_EffectiveNP","JES");
//		findAndReplaceAll(nptmp,"JET_CategoryReduction_","JES");
//		findAndReplaceAll(nptmp,"JET_JER_EffectiveNP","JER");
//		findAndReplaceAll(nptmp,"JET_EtaIntercalibration","JET_EtaInt");
//		findAndReplaceAll(nptmp,"TAUS_TRUEHADTAU_SME_TES","TES");
		NPname = nptmp;
		if(NPname.Contains("PDF")) tau_plots->trexdir = "PDF_trexinputs";
		else if(NPname.Contains("muR")) tau_plots->trexdir = "scale_trexinputs";
		else tau_plots->trexdir = "trexinputs";
		tau_plots->write_trexinput(histmiddlename,NPname);
	}
	if(doPlots){
		for (auto samp : sigsamples)
		{
			tau_plots->overlay(samp.name);
		}
		tau_plots->plot_stack(histmiddlename, "plots/"+ NPname,"charts/"+ NPname);
	}
	deletepointer(tau_plots);
	deletepointer(inputfile);
	if(plotvar < perpart) {
		printf("finished %d variables. %d variables in this batch with batch size %d.\n", varcount, plotvar, perpart);
		return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int from = atoi(argv[2]);
	int to = atoi(argv[3]);
	TString dirname;
	TString method = argv[4];
	for (int i = from; i <= to; ++i)
	{
		//printf("=============================generating NP %d : %s=============================\n", i, findNPname(dirname,i,framework).Data());
		for(int ipart = 0;1;ipart++)
			if(!plot(i,method,ipart) || method.Contains("IFF") || method.Contains("fit")) break;
	}
	return 0;
}
