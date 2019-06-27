#include "histSaver.h"
#include "TH1D.h"

void plot()
{
	bool doPlots = 1;

	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	tau_plots->inputfilename = "hists";
	tau_plots->debug = 0;
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
	int fakeMC = 2; // 0 use DD, 1 include fake in each bkg, 2 show fakes in the plots
	tau_plots->sensitivevariable = "BDTG_test";
	tau_plots->add("BDT discriminant","BDTG_test","",10);

  	//tau_plots->add("p_{T,SS#tau}","tauptss","GeV",1);
  	//tau_plots->add("p_{T,OS#tau}","tauptos","GeV",1);
    tau_plots->add("#DeltaR(l,b-jet)","drlb","",3);
    tau_plots->add("#DeltaR(l,b-jet)","drtaub","",3);
    tau_plots->add("M(light-jet,light-jet,min)","mjjmin","GeV",5);
  	tau_plots->add("p_{T,lead-#tau}","taupt_0","GeV",1);
  	tau_plots->add("p_{T,sublead-#tau}","taupt_1","GeV",1);
  	tau_plots->add("m_{t,SM}","t1mass","GeV",5);
  	tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  	tau_plots->add("m_{W}","wmass","GeV",5);
  	tau_plots->add("m_{t,FCNC}","t2mass","GeV",5);
  	tau_plots->add("m_{#tau#tau,vis}","tautauvismass","GeV",10);
  	tau_plots->add("m_{t,FCNC,vis}","t2vismass","GeV",10);
  	tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",1);
  	tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",1);
  	tau_plots->add("P_{t,#tau#tau,vis}","tautauvispt","GeV",10);
  	tau_plots->add("m^{T}_{W}","mtw","GeV",10);
  	tau_plots->add("m_{t,SM,vis}","t1vismass","GeV",15);
  	tau_plots->add("#DeltaR(l+b-jet,#tau+#tau)","drlbditau","",5);
  	tau_plots->add("#eta_{#tau,max}","etamax","",10);
  	tau_plots->add("#DeltaR(l,#tau)","drltau","",8);
  	tau_plots->add("#DeltaR(#tau,fcnc-j)","drtauj","",10);
  	tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",4);
  	tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  	tau_plots->add("M(#tau#tau#light-jet,min)","mtaujmin","",5);
  	tau_plots->add("E^{T}_{miss}","etmiss","GeV",10);
    tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",6);
    tau_plots->add("E^{T}_{miss} centrality","phicent","",3);

    gErrorIgnoreLevel = kWarning;
  	tau_plots->blinding = 2;
	TString regions[] = {"reg1l2tau1bnj_ss","reg1l2tau1bnj_os","reg1l1tau1b2j_ss","reg1l1tau1b2j_os","reg1l1tau1b3j_ss","reg1l1tau1b3j_os",
						"reg1l2tau2bnj_ss","reg1l2tau2bnj_os","reg1l1tau2b2j_ss","reg1l1tau2b2j_os","reg1l1tau2b3j_ss","reg1l1tau2b3j_os"};
//	TString regions[] = {"reg1l2tau1bnj_os"};
	int nregions = sizeof(regions)/sizeof(TString);
	TString nprong[] = {"1prong","3prong"};
	for (int j = 0; j < nregions; ++j)
	  for (int k = 0; k < 2; ++k)
	    for (int i = 1; i < 2; i+=2){
	    	//TString addedregion = regions[j] + "_" + nprong[k] + "_veto" + bwps[i];
	      	//printf("adding region: %s\n", addedregion.Data());
	      	//tau_plots->add_region(addedregion);
//	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_above35_veto" + bwps[i]);
	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_below35_veto" + bwps[i]);
	    }
	tau_plots->muteregion("35_veto");
	tau_plots->muteregion("prong");
	vector<TString> samples;
	samples.push_back("Other");
	samples.push_back("Vjets");
	samples.push_back("diboson");
	samples.push_back("ttH");
	samples.push_back("ttV");
	samples.push_back("ttbar");
	samples.push_back("fcnc_uh");
	samples.push_back("fcnc_prod_uh");
	samples.push_back("tuH");
	samples.push_back("fcnc_ch");
	samples.push_back("fcnc_prod_ch");
	samples.push_back("tcH");
	double norm[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector<TString> sampletitle;
	sampletitle.push_back("Other");
	sampletitle.push_back("V+jets");
	sampletitle.push_back("Diboson");
	sampletitle.push_back("#bar{t}tH");
	sampletitle.push_back("#bar{t}tV");
	sampletitle.push_back("#bar{t}t");
	sampletitle.push_back("#bar{t}t#rightarrowbWuH");
	sampletitle.push_back("utH Prod Mode");
	sampletitle.push_back("tuH merged signal");
	sampletitle.push_back("#bar{t}t#rightarrowbWcH");
	sampletitle.push_back("ctH Prod Mode");
	sampletitle.push_back("tcH merged signal");

	stringstream ss;
	ss<<"(BR=" << 0.2*norm[6] << "%)";
	TString tmp;
	ss>>tmp;
	for(int i = 6; i<12 ; ++i) sampletitle[i]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kRed, kRed, kRed, kRed, kRed};

	tau_plots->read_sample("data","data","data",kBlack, 1);
//============================ merge_sample============================
	if(plot_option == 1){
		for (int i = 0; i < 7; ++i){
			tau_plots->stackorder.push_back(origin[i]);
			for (int j = 0; j < 6; ++j)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], origintitle[i], (enum EColor)colors[i], norm[j]);
		}
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
		for (int j = 0; j < samples.size(); ++j){
			if(j < 6) tau_plots->stackorder.push_back(samples[j]);
			if(j == samples.size()-4){
					tau_plots->read_sample( samples[j], "fcnc_uh_" + origin[6] + "_NP2", sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], "fcnc_prod_uh_" + origin[6] + "_NP2", sampletitle[j], (enum EColor)colors[j], norm[j]);
			}else if(j == samples.size()-1){
					tau_plots->read_sample( samples[j], "fcnc_ch_" + origin[6] + "_NP2", sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], "fcnc_prod_ch_" + origin[6] + "_NP2", sampletitle[j], (enum EColor)colors[j], norm[j]);
			}else{
				for (int i = 0; i < 6; ++i)
				{
					if(fakeMC == 1) tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP2", sampletitle[j], (enum EColor)colors[j], norm[j]);
					else if(fakeMC == 2) tau_plots->read_sample( "fake", samples[j] + "_" + origin[i] + "_NP2", "Fake MC", kYellow, norm[j]);
				}
				tau_plots->read_sample( samples[j], samples[j] + "_" + origin[6] + "_NP2", sampletitle[j], (enum EColor)colors[j], norm[j]);
			}
		}
		if(fakeMC) tau_plots->stackorder.push_back("fake");
	}
	for (int j = 0; j < nregions; ++j){
		for (int i = 1; i < 2; i+=2){
			for (int k = 0; k < 2; ++k)
			  tau_plots->merge_regions(regions[j] + "_" + nprong[k] + "_above35_veto" + bwps[i],regions[j] + "_" + nprong[k] + "_below35_veto" + bwps[i],regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
			  //tau_plots->merge_regions(regions[j] + "_" + nprong[k] + "_above35_" + bwps[i],regions[j] + "_" + nprong[k] + "_below35_" + bwps[i],regions[j] + "_" + nprong[k] + "_" + bwps[i]);
			  //tau_plots->add_region(regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
			tau_plots->merge_regions(regions[j] + "_" + nprong[0] + "_veto" + bwps[i], regions[j] + "_" + nprong[1] + "_veto" + bwps[i],regions[j] + "_veto" + bwps[i]);
		}
	}

	if(plot_option == 2){
		if(!fakeMC){
  			//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
			tau_plots->templatesample("reg1l2tau1bnj_ss_vetobtagwp70","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l2tau1bnj_os_vetobtagwp70","fake","Fake",kYellow,1);
			tau_plots->templatesample("reg1l1tau1b2j_ss_vetobtagwp70","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau1b2j_os_vetobtagwp70","fake","Fake",kYellow,1);
			tau_plots->templatesample("reg1l1tau1b3j_ss_vetobtagwp70","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau1b3j_os_vetobtagwp70","fake","Fake",kYellow,1);

			tau_plots->templatesample("reg1l2tau2bnj_ss_vetobtagwp70","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l2tau2bnj_os_vetobtagwp70","fake","Fake",kYellow,1);
			tau_plots->templatesample("reg1l1tau2b2j_ss_vetobtagwp70","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau2b2j_os_vetobtagwp70","fake","Fake",kYellow,1);
			tau_plots->templatesample("reg1l1tau2b3j_ss_vetobtagwp70","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau2b3j_os_vetobtagwp70","fake","Fake",kYellow,1);
			tau_plots->stackorder.push_back("fake");
  		}
  	}

	if(doPlots){
		for (int i = 6; i < 12; ++i)
		//for (int i = 8; i < 9; ++i)
		{
			printf("plot signal: %s\n", samples[i].Data());
  			tau_plots->overlay(samples[i]);
			tau_plots->plot_stack("output/" + samples[i]);
		}
	}
}
int main(int argc, char const *argv[])
{
	plot();
	return 0;
}