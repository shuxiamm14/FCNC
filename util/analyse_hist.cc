#include "nominal.h"

int main(int argc, char const *argv[])
{

	histSaver *tau_plots = new histSaver();
	tau_plots->debug = 1;
	histSaver *notau_plots = new histSaver();
	notau_plots->debug = 1;
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
	tau_plots->add("p_{T,#tau}","taupt","GeV");
	tau_plots->add("p_{T,b}","bpt","GeV");
	tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	notau_plots->add("p_{T,b}","bpt","GeV");
	notau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	TString regions[] = {"reg1e1mu1tau2b","reg1l1tau2b1j","reg1e1mu1tau1b","reg1e1mu2bnj","reg1l2b2j","reg1e1mu2b"};
	TString nprong[] = {"1prong","3prong"};
	for (int j = 0; j < 6; ++j)
	  if(j>2) notau_plots->add_region(regions[j]);
	  else for (int k = 0; k < 2; ++k)
	    for (int i = 0; i < 4; ++i){
	      printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
	      tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
	    }
	tau_plots->read_sample("data","data","data",kBlack);
	printf("data\n");
	tau_plots->read_sample("other","other","Other samples",kYellow);
	printf("other\n");
	tau_plots->read_sample("ttbar_g","ttbar_g","t#bar{t}(gluon fake #tau)",(enum EColor)7);
	printf("gluon\n");
	tau_plots->read_sample("ttbar_j","ttbar_j","t#bar{t}(light-jet fake #tau)",kBlue);
	tau_plots->read_sample("ttbar_b","ttbar_b","t#bar{t}(b-jets fake #tau)",kViolet);
	tau_plots->read_sample("ttbar_lep","ttbar_lep","t#bar{t}(lepton fake #tau)",kGreen);
	tau_plots->read_sample("ttbar_real","ttbar_real","t#bar{t}(real #tau)",kRed);
	tau_plots->read_sample("ttbar_c","ttbar_c","t#bar{t}(c-jets fake #tau)",kOrange);
	tau_plots->read_sample("ttbar_nomatch","ttbar_nomatch","t#bar{t}(no truth matched fake #tau)",kGray);

	//notau_plots->read_sample("data","data_notau","data",kBlack);
	//notau_plots->read_sample("other","other_notau","Other samples",kYellow);
	//notau_plots->read_sample("ttbar","ttbar_notau","t#bar{t}",kRed);

	return 0;
}