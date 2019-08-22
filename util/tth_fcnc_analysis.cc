#include "histSaver.h"
#include "TH1D.h"
#include "fcnc_include.h"

TString NPnames[] = {
	"NOMINAL",
	"fakeSFOrig",
	"fakeSF",
	"fakeSFNP1",
	"fakeSFNP2",
	"fakeSFNP3",
	"fakeSFNP4",
	"fakeSFNP5",
	"fakeSFNP6"
};

void plot(int iNP)
{
	bool doPlots = 1;
	bool deriveSSOSSF = 0;
	bool doTrex = 0;
	bool plotnj = 0;
	int plot_option = 2; // 1 plot tau origin, 2 standard plots
	int fakeMC = 1; // 0 use DD, 1 include fake in each bkg, 2 show fakes in the plots
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	//tau_plots->inputfilename = "hists"+to_string(iNP);
	tau_plots->inputfilename = "hists";
	tau_plots->debug = 0;
  	tau_plots->blinding = 2;
	tau_plots->muteregion("35_veto");
	tau_plots->muteregion("prong");
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
	if(plotnj){
  		tau_plots->add("N_{l-jet}","njet","",1);
		tau_plots->muteregion("3j");
		tau_plots->muteregion("2j");
	}else{
		//tau_plots->sensitivevariable = "BDTG_test";
		//tau_plots->add("BDT discriminant","BDTG_test","",10);
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
  		tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",5);
  		tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",5);
  	}
    gErrorIgnoreLevel = kWarning;
	TString regions[] = {"reg1l2tau1bnj_ss","reg1l2tau1bnj_os","reg1l1tau1b2j_ss","reg1l1tau1b2j_os","reg1l1tau1b3j_ss","reg1l1tau1b3j_os"};
	//					"reg1l2tau2bnj_ss","reg1l2tau2bnj_os","reg1l1tau2b2j_ss","reg1l1tau2b2j_os","reg1l1tau2b3j_ss","reg1l1tau2b3j_os"};
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
	vector<TString> samples;
	samples.push_back("other");
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
	sampletitle.push_back("other");
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
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i] + "_NP" + to_string(iNP), origintitle[i], (enum EColor)colors[i], norm[j]);
		}
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
		for (int j = 0; j < samples.size(); ++j){
			if(j < 6) tau_plots->stackorder.push_back(samples[j]);
			if(j == samples.size()-4){
					tau_plots->read_sample( samples[j], "fcnc_uh_" + origin[6] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], "fcnc_prod_uh_" + origin[6] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
			}else if(j == samples.size()-1){
					tau_plots->read_sample( samples[j], "fcnc_ch_" + origin[6] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], "fcnc_prod_ch_" + origin[6] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
			}else{
				for (int i = 0; i < 6; ++i)
				{
					if(fakeMC == 1) tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					else if(fakeMC == 2) tau_plots->read_sample( "fake", samples[j] + "_" + origin[i] + "_NP" + to_string(iNP), "Fake MC", kYellow, norm[j]);
				}
				tau_plots->read_sample( samples[j], samples[j] + "_" + origin[6] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
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
	if(plotnj)
		for (int i = 1; i < 2; i+=2){
			tau_plots->merge_regions("reg1l1tau1b2j_ss_veto" + bwps[i], "reg1l1tau1b3j_ss_veto" + bwps[i], "reg1l1tau1b_ss_veto" + bwps[i]);
			tau_plots->merge_regions("reg1l1tau1b2j_os_veto" + bwps[i], "reg1l1tau1b3j_os_veto" + bwps[i], "reg1l1tau1b_os_veto" + bwps[i]);
			tau_plots->merge_regions("reg1l1tau2b2j_ss_veto" + bwps[i], "reg1l1tau2b3j_ss_veto" + bwps[i], "reg1l1tau2b_ss_veto" + bwps[i]);
			tau_plots->merge_regions("reg1l1tau2b2j_os_veto" + bwps[i], "reg1l1tau2b3j_os_veto" + bwps[i], "reg1l1tau2b_os_veto" + bwps[i]);
		}
	if(plot_option == 2){
		if(!fakeMC){
			//tau_plots->templatesample("reg1l2tau1bnj_ss_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l2tau1bnj_os_vetobtagwp70","fake","Fake",kYellow,1);
			//tau_plots->templatesample("reg1l1tau1b2j_ss_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau1b2j_os_vetobtagwp70","fake","Fake",kYellow,1);
			//tau_plots->templatesample("reg1l1tau1b3j_ss_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau1b3j_os_vetobtagwp70","fake","Fake",kYellow,1);
			//tau_plots->templatesample("reg1l2tau2bnj_ss_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l2tau2bnj_os_vetobtagwp70","fake","Fake",kYellow,1);
			//tau_plots->templatesample("reg1l1tau2b2j_ss_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau2b2j_os_vetobtagwp70","fake","Fake",kYellow,1);
			//tau_plots->templatesample("reg1l1tau2b3j_ss_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau2b3j_os_vetobtagwp70","fake","Fake",kYellow,1);

			//tau_plots->templatesample("reg1l1tau2b2j_os_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau1b2j_os_vetobtagwp70","fake","Fake",kYellow,1); //di-b fake estimate
			//tau_plots->templatesample("reg1l1tau2b3j_os_vetobtagwp70","1 data -1 other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l1tau1b3j_os_vetobtagwp70","fake","Fake",kYellow,1);
			tau_plots->stackorder.push_back("fake");
  		}
  	}

  	//tau_plots->printyield("reg1l2tau1bnj_os_vetobtagwp70");
  	//tau_plots->printyield("reg1l1tau1b2j_os_vetobtagwp70");
  	//tau_plots->printyield("reg1l1tau1b3j_os_vetobtagwp70");

	if(doTrex){
		if(NPnames[iNP].Contains("PDF")) tau_plots->trexdir = "PDF_trexinputs";
		else if(NPnames[iNP].Contains("muR")) tau_plots->trexdir = "scale_trexinputs";
		else tau_plots->trexdir = "trexinputs";
		tau_plots->write_trexinput(NPnames[iNP],"update");
	}

	if(doPlots){
		if(plot_option == 2){
			gSystem->mkdir(("output_"+to_string(iNP)).c_str());
			for (int i = 6; i < 12; ++i)
			{
  				tau_plots->overlay(samples[i]);
			}
			tau_plots->plot_stack(("output_"+to_string(iNP)).c_str());
		}
		if(plot_option == 1)
			tau_plots->plot_stack("fake_plots");
	}
}
int main(int argc, char const *argv[])
{
	if(argc == 1){
		plot(0);
		return 0;
	}
	for (int i = *argv[1]-'0'; i <= *argv[2]-'0'; ++i)
	{
		plot(i);
	}
	return 0;
}