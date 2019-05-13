#include "histSaver.h"
#include "TH1D.h"

int main(int argc, char const *argv[])
{
	bool doPlots = 1;

	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	tau_plots->inputfilename = "hists";
	tau_plots->debug = 0;
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};

	tau_plots->sensitivevariable = "BDTG_test";
	tau_plots->add("BDT discriminant","BDTG_test","",10);

  	//tau_plots->add("p_{T,SS#tau}","tauptss","GeV",1);
  	//tau_plots->add("p_{T,OS#tau}","tauptos","GeV",1);
  	tau_plots->add("p_{T,lead-#tau}","taupt_0","GeV",1);
  	tau_plots->add("p_{T,sublead-#tau}","taupt_1","GeV",1);
  	tau_plots->add("m_{t,SM}","t1mass","GeV",10);
  	tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",10);
  	tau_plots->add("m_{W}","wmass","GeV",10);
  	tau_plots->add("m_{t,FCNC}","t2mass","GeV",10);
  	tau_plots->add("m_{#tau#tau,vis}","tautauvismass","GeV",10);
  	tau_plots->add("m_{t,FCNC,vis}","t2vismass","GeV",10);
  	tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",5);
  	tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",5);
  	tau_plots->add("P_{t,#tau#tau,vis}","tautauvispt","GeV",10);
  	tau_plots->add("m^{T}_{W}","mtw","GeV",10);
  	tau_plots->add("m_{t,SM,vis}","t1vismass","GeV",10);
  	tau_plots->add("#DeltaR(l+b-jet,#tau+#tau)","drlbditau","",10);
  	tau_plots->add("#eta_{#tau,max}","etamax","",10);
  	tau_plots->add("#DeltaR(l,#tau)","drltau","",8);
  	tau_plots->add("#DeltaR(#tau,fcnc-j)","drtauj","",10);
  	tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",4);
  	tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",10);
//
  	tau_plots->add("E^{T}_{miss}","etmiss","GeV",20);
    tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",12);
    tau_plots->add("E^{T}_{miss} centrality","phicent","",6);
    gErrorIgnoreLevel = kWarning;
  	tau_plots->blinding = 3;
	TString regions[] = {"reg1l2tau1bnj_ss","reg1l2tau1bnj_os","reg1l1tau1b2j","reg1l1tau1b3j"};
	int nregions = 4;
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
	TString samples[] = {"Other", "Vjets", "diboson", "ttH", "ttV", "ttbar","fcnc_ch"};
	double norm[] = {1,1,1,1,1,1,5};
	TString sampletitle[] = {"Other", "V+jets", "Diboson", "#bar{t}tH", "#bar{t}tV", "#bar{t}t", "#bar{t}t#rightarrow bWqH"};
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
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP0", sampletitle[j], (enum EColor)colors[j], norm[j]);
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
	if(doPlots){
		tau_plots  ->plot_stack(outputdir[plot_option]);
	}
	return 0;
}