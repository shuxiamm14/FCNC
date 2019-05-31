#include "histSaver.h"
#include "TH1D.h"

void plot(int signalmode, TString fcncquark)
{
	bool doPlots = 1;

	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	tau_plots->inputfilename = "hists";
	tau_plots->debug = 0;
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
	bool fakeMC = 0;
	tau_plots->sensitivevariable = "BDTG_test";
	tau_plots->add("BDT discriminant","BDTG_test","",10);

  	//tau_plots->add("p_{T,SS#tau}","tauptss","GeV",1);
  	//tau_plots->add("p_{T,OS#tau}","tauptos","GeV",1);
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
//
  	tau_plots->add("E^{T}_{miss}","etmiss","GeV",10);
    tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",6);
    tau_plots->add("E^{T}_{miss} centrality","phicent","",3);
    gErrorIgnoreLevel = kWarning;
  	tau_plots->blinding = 2;
	TString regions[] = {"reg1l2tau1bnj_ss","reg1l2tau1bnj_os","reg1l1tau1b2j_os","reg1l1tau1b3j_os"};
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
	if(signalmode == 1) samples.push_back("fcnc_" + fcncquark + "h");
	if(signalmode == 2) samples.push_back("fcnc_prod_" + fcncquark + "h");
	if(signalmode == 3) samples.push_back("t" + fcncquark + "H");
	double norm[] = {1,1,1,1,1,1,1};
	vector<TString> sampletitle;
	sampletitle.push_back("Other");
	sampletitle.push_back("V+jets");
	sampletitle.push_back("Diboson");
	sampletitle.push_back("#bar{t}tH");
	sampletitle.push_back("#bar{t}tV");
	sampletitle.push_back("#bar{t}t");

	if(signalmode == 1) sampletitle.push_back("#bar{t}t#rightarrowbW" + fcncquark + "H");
	if(signalmode == 2) sampletitle.push_back(fcncquark + "tH Prod Mode");
	if(signalmode == 3) sampletitle.push_back("t" + fcncquark + "H merged signal");

	stringstream ss;
	ss<<"(BR=" << 0.2*norm[6] << "%)";
	TString tmp;
	ss>>tmp;
	sampletitle[6]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed};

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
  		tau_plots->overlay(samples[6]);

		for (int j = 0; j < 7; ++j){
			tau_plots->stackorder.push_back(samples[j]);
			for (int i = fakeMC? 0:6; i < 7; ++i){
				if(j == samples.size()-1){
					if(signalmode != 2)
						tau_plots->read_sample( samples[j], "fcnc_" + fcncquark + "h_" + origin[i] + "_NP0", sampletitle[j], (enum EColor)colors[j], norm[j]);
					if(signalmode != 1)
						tau_plots->read_sample( samples[j], "fcnc_prod_" + fcncquark + "h_" + origin[i] + "_NP0", sampletitle[j], (enum EColor)colors[j], norm[j]);
				}else
					tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP0", sampletitle[j], (enum EColor)colors[j], norm[j]);
			}
		}
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
			tau_plots->templatesample("reg1l2tau1bnj_ss","1 data -1 Other -1 Vjets -1 diboson -1 ttH -1 ttV -1 ttbar","reg1l2tau1bnj_os","fake","Fake",kYellow,1);
  		}
  	}

	if(doPlots){
		TString outputname = signalmode == 3 ? "merged" : (signalmode == 1 ? "decay" : "prod");
		outputname += fcncquark;
		outputname += "H";
		tau_plots  ->plot_stack("output/" + outputname);
	}
}
int main(int argc, char const *argv[])
{
	
	int signalmode = 1; //1 decay, 2 prod, 3 both
	TString fcncquark = "u";
	plot(1,"u");
	//plot(1,"c");
	//plot(2,"u");
	//plot(2,"c");
	//plot(3,"u");
	//plot(3,"c");
	return 0;
}