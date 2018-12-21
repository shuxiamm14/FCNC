#include "histSaver.h"
#include "TH1D.h"

int main(int argc, char const *argv[])
{
	bool doPlots = 1;

	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver();
	tau_plots->debug = 0;
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
//	tau_plots->add("p_{T,#tau}","taupt","GeV");
//	tau_plots->add("p_{T,b}","bpt","GeV");
//	tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	tau_plots->add("m_{t,SM}","t1mass","GeV");
	tau_plots->add("m_{#tau,#tau}","tautaumass","GeV");
	tau_plots->add("m_{#tau#tau,vis}","tautauvismass","GeV");
	tau_plots->add("m_{W}","wmass","GeV");
	tau_plots->add("m_{t,FCNC}","t2mass","GeV");
	tau_plots->add("m_{t,FCNC,vis}","t2vismass","GeV");
  	tau_plots->irebin = 6;
	TString regions[] = {"reg1l2tau1bnj","reg1l1tau1b2j","reg1l1tau1b3j"};
	TString nprong[] = {"1prong","3prong"};
	for (int j = 0; j < 3; ++j)
	  for (int k = 0; k < 2; ++k)
	    for (int i = 1; i < 4; i+=2){
	      printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
//	      tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
	      tau_plots->add_region(regions[j] + "_" + nprong[k] + "_above35_veto" + bwps[i]);
	      tau_plots->add_region(regions[j] + "_" + nprong[k] + "_below35_veto" + bwps[i]);
	    }
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
		for (int j = 0; j < 7; ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], origintitle[i], (enum EColor)colors[i], norm[j]);
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
  		tau_plots->overlay = samples[6];
		for (int j = 0; j < 7; ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i], sampletitle[j], (enum EColor)colors[j], norm[j]);
	}
	if(doPlots){
		tau_plots  ->plot_stack(outputdir[plot_option]);
	}
	return 0;
}