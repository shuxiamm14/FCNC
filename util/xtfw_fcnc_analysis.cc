#include "histSaver.h"
#include "TH1D.h"

int main(int argc, char const *argv[])
{
	bool doPlots = 1;

	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	tau_plots->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV, 140 fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
	tau_plots->inputfilename = "hists";
	tau_plots->debug = 0;
	tau_plots->sensitivevariable = "BDTG";
	tau_plots->add("BDT discriminant","BDTG","",5);
  	//tau_plots->add("p_{T,lead-#tau}","tau_0_pt","GeV",5);
  	//tau_plots->add("p_{T,sublead-#tau}","tau_1_pt","GeV",5);
  	//tau_plots->add("E^{T}_{miss}","etmiss","GeV",2);
  	//tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",5);
  	//tau_plots->add("m_{#tau#tau,vis}","ttvismass","",5);
  	//tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",5);
  	//tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  	//tau_plots->add("E^{T}_{miss} centrality","phicent","",5);
  	//tau_plots->add("m_{t,SM}","t1mass","GeV",20);
  	//tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  	//tau_plots->add("m_{W}","wmass","GeV",5);
  	//tau_plots->add("m_{t,FCNC}","t2mass","GeV",20);
  	//tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",1);
  	//tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",1);

  	tau_plots->blinding = 0;
	vector<TString> regions;
	//regions.push_back("reg2mtau1b2jss");
	//regions.push_back("reg1mtau1ltau1b2jss");
	//regions.push_back("reg2ltau1b2jss");
	regions.push_back("reg2mtau1b3jss");
	//regions.push_back("reg1mtau1ltau1b3jss");
	//regions.push_back("reg2ltau1b3jss");
	//regions.push_back("reg2mtau1b2jos");
	//regions.push_back("reg1mtau1ltau1b2jos");
	//regions.push_back("reg2ltau1b2jos");
	regions.push_back("reg2mtau1b3jos");
	//regions.push_back("reg1mtau1ltau1b3jos");
	//regions.push_back("reg2ltau1b3jos");
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
	TString samples[] = {"smhiggs", "wjet", "diboson", "zll", "ztautau", "top","fcnc_ch"};
	double norm[] = {1,1,1,1,1,1,1};
	TString sampletitle[] = {"SM Higgs", "W+jets", "Diboson", "Z#rightarrowll", "Z#rightarrow#tau#tau", "Top production(real tau)", "#bar{t}t#rightarrow bWqH"};
	stringstream ss;
	ss<<"(BR=" << norm[6] << "%)";
	TString tmp;
	ss>>tmp;
	sampletitle[6]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed};

	tau_plots->read_sample("data","data","data",kBlack, 1);
//============================ merge_sample============================
	if(plot_option == 1){
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], origintitle[i], (enum EColor)colors[i], norm[j]);
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
  		tau_plots->overlay(samples[6]);
		for (int j = 0; j < 7; ++j)
			for (int i = 6; i < 7; i += 1)
				if (origin[i] != "real")
				{
					tau_plots->read_sample( "fakeMC", samples[j] + "_" + origin[i] + "_NP0", "FakeMC", kPink, norm[j]);
				}else
					tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP0", sampletitle[j], (enum EColor)colors[j], norm[j]);

	}
	for (int j = 0; j < nregions; ++j){
		for (int k = 0; k < 2; ++k)
			for (int i = 1; i < 2; i+=2){
			  tau_plots->merge_regions(regions[j] + "_" + nprong[k] + "_above35_vetobtagwp70",regions[j] + "_" + nprong[k] + "_below35_vetobtagwp70",regions[j] + "_" + nprong[k]);
			}
		tau_plots->merge_regions(regions[j] + "_" + nprong[0],regions[j] + "_" + nprong[1],regions[j]);
	}
	if(plot_option == 2){
  		tau_plots->templatesample("reg2mtau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  		//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
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

  		vector<TString> stacks;

  		//tau_plots->overlay("fake");
  		stacks.push_back("ztautau");
  		stacks.push_back("top");
  		stacks.push_back("smhiggs");
  		stacks.push_back("wjet");
  		stacks.push_back("zll");
  		stacks.push_back("diboson");
  		//stacks.push_back("fakeMC");
  		stacks.push_back("fake");
  		stacks.push_back("fcnc_ch");
  		tau_plots->stackorder = stacks;
  	}

	if(doPlots){
		tau_plots  ->plot_stack(outputdir[plot_option]);
	}
	return 0;
}