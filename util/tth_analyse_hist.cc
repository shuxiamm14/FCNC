#include "histSaver.h"
#include "HISTFITTER.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("please specify merge strategy:\n0 : merge_other; 1: merge_sample ; 2: merge_origin\n");
		return 1;
	}
	bool dofit = 1;
	bool doPlots = 1;
	int binning = 2;
	bool mergeprong = 1;
	HISTFITTER* fitter = new HISTFITTER();

	fitter->setparam("sf_b", 1, 0.1, 0.,2.);
	fitter->setparam("sf_c", 1, 0.1, 0.,2.);
	fitter->setparam("sf_g", 2, 0.1, 0.,10.);
	fitter->setparam("sf_j", 1, 0.1, 0.,2.);
	int plot_option = *argv[1] - '0';
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("tth_ana_output");
	tau_plots -> analysis = "Fake tau study";
	if(mergeprong) tau_plots->muteregion("prong");
	tau_plots->muteregion("35");

	tau_plots->debug = 0;
	//histSaver *notau_plots = new histSaver();
	//notau_plots->debug = 0;

	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
	tau_plots->add("p_{T,#tau}","taupt","GeV");
	tau_plots->add("m_{#tau,light-jet}","taulmass","GeV");
	//tau_plots->add("p_{T,b}","bpt","GeV");
  	//tau_plots->add("E_{miss}^{T}","met","GeV",5);
	//tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	//notau_plots->add("p_{T,b}","bpt","GeV");
	//notau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	TString regions[] = {"reg1e1mu1tau2b","reg1l1tau2b1j_ss","reg1e1mu1tau1b","reg1e1mu2bnj","reg1l2b2j","reg1e1mu2b"};

	TString nprong[] = {"1prong_","3prong_",""};
	TString abvorbl[] = {"below35_","above35_"};
	for (int j = 0; j < 3; ++j)
	  //notau_plots->add_region(regions[j]);
	  for (int i = 1; i < 4; i+=2)
	  	for (int k = 0; k < 2; ++k){
	  		for (int iabvorbl = 0; iabvorbl < 2; ++iabvorbl)
	  		{
				tau_plots->add_region(regions[j] + "_" + nprong[k] + abvorbl[iabvorbl] + bwps[i]);
				if(i == 1) tau_plots->add_region(regions[j] + "_" + nprong[k] + abvorbl[iabvorbl] + "veto" + bwps[i]);
	  		}
	    }

	TString samples[] = {"other", "Vjets", "diboson", "ttH", "ttV", "ttbar"};
	TString sampletitle[] = {"Other", "V+jets", "Diboson", "#bar{t}tH", "#bar{t}tV", "#bar{t}t"};

	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data"};
	TString origintitle[] = {"b-jets fake #tau", "c-jets fake #tau", "gluon-jets fake #tau", "light-jets fake #tau", "lepton fake #tau", "non-truth-matched fake #tau", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed};

	tau_plots->read_sample("data","data","NOMINAL","data",kBlack,1);
	//notau_plots->read_sample("data","data_notau","data",kBlack,1);
//============================ merge_other ============================
	if (plot_option == 0)
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i)
			{
				if (samples[j] != "ttbar")
				{
					if(origin[i] == "real") tau_plots->read_sample("other_real",samples[j] + "_" + origin[i],"NOMINAL","Other samples with real tau",kYellow,1);
					else tau_plots->read_sample("other_fake",samples[j] + "_" + origin[i],"NOMINAL","Other samples with fake tau",kMagenta,1);
				}else
					tau_plots->read_sample( samples[j] + "_" + origin[i], samples[j] + "_" + origin[i],"NOMINAL", sampletitle[j] + "(" + origintitle[i] + ")", (enum EColor)colors[i],1);
			}
//============================ merge_sample============================
	else if(plot_option == 1){
		for (int i = 0; i < 7; ++i)
		{
			(tau_plots->stackorder).push_back(origin[i]);
		}
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i){
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i],"NOMINAL", origintitle[i], (enum EColor)colors[i],1);
				//tau_plots->read_sample("data", samples[j] + "_" + origin[i], "data",kBlack,pseudodataratio[i]);
			}
	}
//============================ merge_origin ============================
	else if(plot_option == 2)
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i){
				tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i],"NOMINAL", sampletitle[j], (enum EColor)colors[j],1);
			}
	if(mergeprong){
		for (int j = 0; j < 3; ++j)
		  for (int i = 1; i < 4; i+=2){
		  	for (int ptbin = 0; ptbin < 2; ++ptbin)
		  	{
		  		tau_plots->merge_regions(regions[j] + "_" + nprong[0] + abvorbl[ptbin] + bwps[i], regions[j] + "_" + nprong[1] + abvorbl[ptbin] + bwps[i],  regions[j] + "_" + abvorbl[ptbin] + bwps[i]);
		  		if(i == 1) tau_plots->merge_regions(regions[j] + "_" + nprong[0] + abvorbl[ptbin] + "veto" + bwps[i], regions[j] + "_" + nprong[1] + abvorbl[ptbin] + "veto" + bwps[i],  regions[j] + "_" + abvorbl[ptbin] + "veto" + bwps[i]);
		  	}
		  }
	}
	if(doPlots){
		//for (int i = 0; i < 6; ++i)
		//{
		//	notau_plots->read_sample(samples[i] ,samples[i] + "_notau", sampletitle[i], (enum EColor)colors[i],1);
		//}
		for (int iprong = (mergeprong?2:0) ; iprong < (mergeprong?3:2) ; ++iprong){
			for (int i = 1; i < 4; i+=2) {
				for (int j = 0; j < 3; ++j)
				{
					tau_plots->merge_regions(regions[j] + "_" + nprong[iprong] + abvorbl[0] + bwps[i],regions[j] + "_" + nprong[iprong] + abvorbl[1] + bwps[i],regions[j] + "_" + nprong[iprong] + bwps[i]);
					if(i == 1) tau_plots->merge_regions(regions[j] + "_" + nprong[iprong] + abvorbl[0] + "veto" + bwps[i],regions[j] + "_" + nprong[iprong] + abvorbl[1]  + "veto" + bwps[i],regions[j] + "_" + nprong[iprong] + "veto" + bwps[i]);
				}
			}
		}
		tau_plots  ->plot_stack(outputdir[plot_option]);
	
		//notau_plots->plot_stack(outputdir[plot_option]);
	}

	if (dofit && plot_option == 1)
	{

		for (int iprong = (mergeprong?2:0) ; iprong < (mergeprong?3:2) ; ++iprong){
			for (int ptbin = 0; ptbin < 2; ++ptbin){
				for (int iorigin = 0; iorigin < 8; ++iorigin)
				{
					TH1D *target[] = {
						tau_plots->grabhist(origin[iorigin],regions[0] + "_" + nprong[iprong] + abvorbl[ptbin] + bwps[1],0),
						tau_plots->grabhist(origin[iorigin],regions[1] + "_" + nprong[iprong] + abvorbl[ptbin] + bwps[1],0),
						tau_plots->grabhist(origin[iorigin],regions[2] + "_" + nprong[iprong] + abvorbl[ptbin] + bwps[1],0),
						tau_plots->grabhist(origin[iorigin],regions[0] + "_" + nprong[iprong] + abvorbl[ptbin] + "veto" + bwps[1],0),
						tau_plots->grabhist(origin[iorigin],regions[1] + "_" + nprong[iprong] + abvorbl[ptbin] + "veto" + bwps[1],0),
						tau_plots->grabhist(origin[iorigin],regions[2] + "_" + nprong[iprong] + abvorbl[ptbin] + "veto" + bwps[1],0),
						tau_plots->grabhist(origin[iorigin],regions[1] + "_" + nprong[iprong] + abvorbl[ptbin] + bwps[3],0),

						tau_plots->grabhist(origin[iorigin],regions[1] + "_" + nprong[iprong] + abvorbl[ptbin] + "veto" + bwps[1],1),
						tau_plots->grabhist(origin[iorigin],regions[1] + "_" + nprong[iprong] + abvorbl[ptbin] + bwps[1],1)
					};
					//TH1D *fithist[4];
					//for (int i = 0; i < 4; ++i)
					//{
					//	fithist[i] = (TH1D*)target[i]->Clone();
					//	fithist[i]->Add(target[i+4]);
					//}

					for (int i = 0; i < 7; ++i)
						fitter->addfithist(origin[iorigin],target[i],1,target[i]->GetNbinsX());

					fitter->addfithist(origin[iorigin],target[7],9,13);

				}
				Double_t val[4],err[4];
				//fitter->debug();
//============================ do fit here============================
				//fitter->asimovfit(100,nprong[iprong]+"ptbin"+char(ptbin+'0')+".root");
				double chi2 = fitter->fit(val,err,0);
				printf("%sptbin: %d, b: %4.2f+/-%4.2f, c: %4.2f+/-%4.2f, g: %4.2f+/-%4.2f, j: %4.2f+/-%4.2f;  Chi2:%f\n",nprong[iprong].Data(), ptbin+1, val[0],err[0], val[1],err[1], val[2],err[2], val[3],err[3], chi2);
				fitter->calculateEigen();
				fitter->clear();
//============================post-fit plots============================
				TH1D *target;
				for (int iorigin = 0; iorigin < 4; ++iorigin)
				{
					for (int ifveto = 0; ifveto < 2; ++ifveto){		
						for (int ibtag = 0; ibtag < 2; ++ibtag){
							for (int i = 0; i < 3; ++i){
								if(ifveto==1 && ibtag==1) continue; 
								target = tau_plots->grabhist(origin[iorigin],regions[i] + "_" + nprong[iprong] + abvorbl[ptbin] + (ifveto?"veto":"") + bwps[ibtag*2+1],0);
								target->Scale(val[iorigin]);
							} // loop region
						} // loop btag wp
					} //loop veto or tag
				} // loop origin
			} // loop ptbin		
			for (int i = 1; i < 4; i+=2) {
				for (int j = 0; j < 3; ++j)
				{
					tau_plots->merge_regions(regions[j] + "_" + nprong[iprong] + abvorbl[0] + bwps[i],regions[j] + "_" + nprong[iprong] + abvorbl[1] + bwps[i],regions[j] + "_" + nprong[iprong] + bwps[i]);
					if(i == 1) tau_plots->merge_regions(regions[j] + "_" + nprong[iprong] + abvorbl[0] + "veto" + bwps[i],regions[j] + "_" + nprong[iprong] + abvorbl[1]  + "veto" + bwps[i],regions[j] + "_" + nprong[iprong] + "veto" + bwps[i]);
				}
			}
		} // loop prong

		if(doPlots) tau_plots->plot_stack("postfit");
		tau_plots->write();
	}
	return 0;
}
