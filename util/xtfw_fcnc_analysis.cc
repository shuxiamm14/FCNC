#include "histSaver.h"
#include "TH1D.h"

void plot(int signalmode, TString fcncquark)
{
	bool doPlots = 1;
	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	if(signalmode == 3 && fcncquark == "u") tau_plots->doROC = 1;
	tau_plots->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV, 140 fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
	tau_plots->inputfilename = "hists";
	tau_plots->debug = 0;
	bool calibttberfake = 1;
	bool fakeMC = 1;
	tau_plots->sensitivevariable = "BDTG_test";
	tau_plots->add("BDT discriminant","BDTG_test","",5);
	tau_plots->add("BDT discriminant","BDTG_train","",5);
  	tau_plots->add("p_{T,lead-#tau}","tau_0_pt","GeV",5);
  	tau_plots->add("p_{T,sublead-#tau}","tau_1_pt","GeV",5);
  	tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",5);
  	tau_plots->add("m_{#tau#tau,vis}","ttvismass","",5);
  	tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",5);
  	tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  	tau_plots->add("E^{T}_{miss} centrality","phicent","",5);
  	tau_plots->add("m_{t,SM}","t1mass","GeV",20);
  	tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  	tau_plots->add("m_{W}","wmass","GeV",5);
  	tau_plots->add("m_{t,FCNC}","t2mass","GeV",20);
  	tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",1);
  	tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",1);
  	tau_plots->add("E^{T}_{miss}","etmiss","GeV",5);
  	gErrorIgnoreLevel = kWarning;
  	tau_plots->blinding = 3;
	vector<TString> regions;
	regions.push_back("reg2mtau1b2jss");
	regions.push_back("reg2mtau1b2jos");
	regions.push_back("reg2mtau1b3jss");
	regions.push_back("reg2mtau1b3jos");

	regions.push_back("reg2mtau2b2jss");
	regions.push_back("reg2mtau2b2jos");
	regions.push_back("reg2mtau2b3jss");
	regions.push_back("reg2mtau2b3jos");
	//regions.push_back("reg1mtau1ltau1b2jss");
	//regions.push_back("reg2ltau1b2jss");
	//regions.push_back("reg1mtau1ltau1b3jss");
	//regions.push_back("reg2ltau1b3jss");
	//regions.push_back("reg1mtau1ltau1b2jos");
	//regions.push_back("reg2ltau1b2jos");
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
	vector<TString> samples;
	samples.push_back("smhiggs");
	samples.push_back("wjet");
	samples.push_back("diboson");
	samples.push_back("zll");
	samples.push_back("ztautau");
	samples.push_back("top");
	if(signalmode == 1) samples.push_back("fcnc_" + fcncquark + "h");
	if(signalmode == 2) samples.push_back("fcnc_prod_" + fcncquark + "h");
	if(signalmode == 3) samples.push_back("t" + fcncquark + "H");
	double norm[] = {1,1,1,1,1,1,0.2};
	vector<TString> sampletitle;
	sampletitle.push_back("SM Higgs");
	sampletitle.push_back("W+jets");
	sampletitle.push_back("Diboson");
	sampletitle.push_back("Z#rightarrowll");
	sampletitle.push_back("Z#rightarrow#tau#tau");
	sampletitle.push_back("Top production");
	if(signalmode == 1) sampletitle.push_back("#bar{t}t#rightarrowbW" + fcncquark + "H");
	if(signalmode == 2) sampletitle.push_back(fcncquark + "tH Prod Mode");
	if(signalmode == 3) sampletitle.push_back("t" + fcncquark + "H merged signal");

	stringstream ss;
	ss<<"(BR=" << norm[6] << "%)";
	TString tmp;
	ss>>tmp;
	sampletitle[6]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data","doublefake"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kMagenta, kSpring, kTeal, kAzure};
	tau_plots->read_sample("data","data","data",kBlack, 1);
//============================ merge_sample============================
	if(plot_option == 1){
		for (int j = 0; j < samples.size(); ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], origintitle[i], (enum EColor)colors[i], norm[j]);
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
  		tau_plots->overlay(samples[samples.size()-1]);
		for (int j = 0; j < samples.size(); ++j){
			for (int i = 0; i < 7; i++){
				if (fakeMC && origin[i] != "real" && j != samples.size()-1 && samples[j] == "top")
				{
					tau_plots->read_sample( "fake1truth", samples[j] + "_" + origin[i] + "_NP1", "Fake MC, 1 truth #tau", kMagenta, norm[j]);
				}
				if(origin[i] == "real"){
					if(j == samples.size()-1){
						if(signalmode != 2){
							tau_plots->read_sample( samples[j], "fcnc_" + fcncquark + "h" + "_qq_" + origin[i] + "_NP1", sampletitle[j], (enum EColor)colors[j], norm[j]);
							tau_plots->read_sample( samples[j], "fcnc_" + fcncquark + "h" + "_lv_" + origin[i] + "_NP1", sampletitle[j], (enum EColor)colors[j], norm[j]);
						}
						if(signalmode != 1)
							tau_plots->read_sample( samples[j], "fcnc_prod_" + fcncquark + "h" + "_" + origin[i] + "_NP1", sampletitle[j], (enum EColor)colors[j], norm[j]);
					}else
						tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP1", sampletitle[j], (enum EColor)colors[j], norm[j]);
				}
				else if(!fakeMC && calibttberfake && samples[j] == "top" && origin[i] != "doublefake"){
					tau_plots->read_sample( "top", samples[j] + "_" + origin[i] + "_NP1", sampletitle[j] + "(Fake #tau)", kTeal, norm[j]);
				}
				
			}
			if(fakeMC && j != samples.size()-1) tau_plots->read_sample( "fake0truth", samples[j] + "_" + origin[8] + "_NP1", "Fake MC, 0 truth #tau", kTeal, norm[j]);
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
		if(!fakeMC){
  			tau_plots->templatesample("reg2mtau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 top_fake","reg2mtau1b3jos","fake","Fake",kYellow,1);
  			tau_plots->templatesample("reg2mtau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 top_fake","reg2mtau1b2jos","fake","Fake",kYellow,1);
  			tau_plots->templatesample("reg2mtau2b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 top_fake","reg2mtau2b3jos","fake","Fake",kYellow,1);
  			tau_plots->templatesample("reg2mtau2b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 top_fake","reg2mtau2b2jos","fake","Fake",kYellow,1);
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
  		vector<TString> stacks;

  		//tau_plots->overlay("fake");
  		stacks.push_back("ztautau");
  		stacks.push_back("top");
  		stacks.push_back("smhiggs");
  		stacks.push_back("wjet");
  		stacks.push_back("zll");
  		stacks.push_back("diboson");
  		if(!fakeMC) {
  			stacks.push_back("fake");
  			//if(calibttberfake) stacks.push_back("top_fake");
  		}
  		else{
  			stacks.push_back("fake1truth");
  			stacks.push_back("fake0truth");
  		}
  		if(signalmode == 2) stacks.push_back("fcnc_prod_" + fcncquark + "h");
  		if(signalmode == 1) stacks.push_back("fcnc_" + fcncquark + "h");
  		if(signalmode == 3) stacks.push_back("t" + fcncquark + "H");
  		tau_plots->stackorder = stacks;
  	}

	if(doPlots){
		TString outputname = signalmode == 3 ? "merged" : (signalmode == 1 ? "decay" : "prod");
		outputname += fcncquark;
		outputname += "H";
		tau_plots  ->plot_stack("output/" + outputname);
	}
	deletepointer(tau_plots);
}

int main(int argc, char const *argv[])
{
	
	int signalmode = 1; //1 decay, 2 prod, 3 both
	TString fcncquark = "u";
	//plot(1,"u");
	//plot(1,"c");
	//plot(2,"u");
	//plot(2,"c");
	plot(3,"c");
	//plot(3,"u");
	return 0;
}