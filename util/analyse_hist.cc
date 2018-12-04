#include "histSaver.h"
#include "TH1D.h"

TMinuit* gM = 0;

void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {
	f = 0;
	TH1D* histforfit = (TH1D*) gM->GetObjectFit();
	if (!histforfit)
	{
	   printf("hist isn't found\n");
	   exit(1);
	}
	int nfitHbin = 0;
	int nregion = 7;
	int norigin = 7;
	for (int i = 1; i < nregion+1; ++i)
	{
		double mctot = 0;
		double error = 0;
		for (int iorigin = 0; iorigin < norigin; ++iorigin)
		{
			mctot += histforfit->GetBinContent(nregion*iorigin+i) * (iorigin < 4?par[iorigin] : 1);
			if(histforfit->GetBinContent(nregion*iorigin+i)) error += pow(histforfit->GetBinError(nregion*iorigin+i) * (iorigin < 4?par[iorigin] : 1),2);
			nfitHbin += 1;
		}
		error = sqrt(error);
		if(histforfit->GetBinContent(norigin*nregion+i) && mctot) f += pow(histforfit->GetBinContent(norigin*nregion+i) - mctot,2)/error;
	}
}

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
	TH1D *fitpreparehist = new TH1D("fitpreparehist","fitpreparehist",100,0,100);

	int plot_option = *argv[1] - '0';
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver();
	tau_plots->debug = 0;
	histSaver *notau_plots = new histSaver();
	notau_plots->debug = 0;
	TString bwps[] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
	tau_plots->add("p_{T,#tau}","taupt","GeV");
	//tau_plots->add("p_{T,b}","bpt","GeV");
	tau_plots->add("m_{#tau,light-jet}","taulmass","GeV");
  	//tau_plots->add("E_{miss}^{T}","met","GeV");
  	tau_plots->irebin = 1;
	//tau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	notau_plots->add("p_{T,b}","bpt","GeV");
	notau_plots->add("p_{T,light-jet}","ljetpt","GeV");
	TString regions[] = {"reg1e1mu1tau2b","reg1l1tau2b1j_ss","reg1e1mu1tau1b","reg1e1mu2bnj","reg1l2b2j","reg1e1mu2b"};

	TString nprong[] = {"1prong","3prong"};
	for (int j = 0; j < 6; ++j)
	  if(j>2) notau_plots->add_region(regions[j]);
	  else for (int i = 1; i < 4; i+=2)
	  	for (int k = 0; k < 2; ++k){
			printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
			tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
			tau_plots->add_region(regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
	    }

	TString samples[] = {"Other", "Vjets", "diboson", "ttH", "ttV", "ttbar"};
	TString sampletitle[] = {"Other", "V+jets", "Diboson", "#bar{t}tH", "#bar{t}tV", "#bar{t}t"};

	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed};

	tau_plots->read_sample("data","data","data",kBlack,1);
	notau_plots->read_sample("data","data_notau","data",kBlack,1);

//============================ merge_other ============================
	if (plot_option == 0)
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i)
			{
				if (samples[j] != "ttbar")
				{
					if(origin[i] == "real") tau_plots->read_sample("other_real",samples[j] + "_" + origin[i],"Other samples with real tau",kYellow,1);
					else tau_plots->read_sample("other_fake",samples[j] + "_" + origin[i],"Other samples with fake tau",kMagenta,1);
				}else
					tau_plots->read_sample( samples[j] + "_" + origin[i], samples[j] + "_" + origin[i], sampletitle[j] + origintitle[i], (enum EColor)colors[j],1);
			}
//============================ merge_sample============================
	else if(plot_option == 1){
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], origintitle[i], (enum EColor)colors[i],1);
	}
//============================ merge_origin ============================
	else if(plot_option == 2)
		for (int j = 0; j < 6; ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i], sampletitle[j], (enum EColor)colors[j],1);

	if(doPlots){
	//	for (int i = 0; i < 6; ++i)
	//	{
	//		notau_plots->read_sample(samples[i] ,samples[i] + "_notau", sampletitle[i], (enum EColor)colors[i],1);
	//	}
	//
	//	notau_plots->plot_stack(outputdir[plot_option]);
		tau_plots  ->plot_stack(outputdir[plot_option]);
	}

	if (dofit && plot_option == 1)
	{
		TH1D *target;
		gM = new TMinuit(5);
		gM->SetFCN(fcn);
		gM->SetPrintLevel(-1);
		Double_t arglist[10];
		Int_t ierflg = 0;

		for (int iprong = 0 ; iprong < 2 ; ++iprong){
			for (int ptbin = 0; ptbin < binning; ++ptbin){
					int nfitHbin = 0;
				for (int iorigin = 0; iorigin < 8; ++iorigin)
				{
					for (int ifveto = 0; ifveto < 2; ++ifveto){
						for (int i = 0; i < 4; ++i)
						{
							if (i == 3)
							{
								if(ifveto == 1) continue;
								nfitHbin += 1;
								target = tau_plots->plot_lib[origin[iorigin]][regions[1] + "_" + nprong[iprong] + (ifveto?"_veto":"_") + bwps[3]][0];
							}else{
								nfitHbin += 1;
								target = tau_plots->plot_lib[origin[iorigin]][regions[i] + "_" + nprong[iprong] + (ifveto?"_veto":"_") + bwps[1]][0];
							}
							fitpreparehist->SetBinContent(nfitHbin, ptbin < binning-1? target->GetBinContent(ptbin+1): target->Integral(binning,10));
							if (ptbin<binning-1)
								fitpreparehist->SetBinError(nfitHbin, target->GetBinError(ptbin+1));
							else {
								double error = 0;
								for (int ib = 4; ib < target->GetNbinsX()+1; ++ib)
								{
									if (target->GetBinContent(ib))
										error += pow(target->GetBinError(ib),2);
								}
								error = sqrt(error);
								fitpreparehist->SetBinError(nfitHbin,error);
							}
						}
					}
				}

				TFile debugfile("debug.root","recreate");
				fitpreparehist->Write();
				debugfile.Close();
//============================ do fit here============================

				gM->mnparm(0, "sf_b", 1, 0.1, 0.,2.,ierflg);
				gM->mnparm(1, "sf_c", 1, 0.1, 0.,2.,ierflg);
				gM->mnparm(2, "sf_g", 2, 0.1, 0.,10.,ierflg);
				gM->mnparm(3, "sf_j", 1, 0.1, 0.,2.,ierflg);
				gM->SetObjectFit(fitpreparehist);
				arglist[0] = 1000;
				arglist[1] = 0;
				Double_t val[4],err[4];
				gM->mnexcm("MIGRADE", arglist ,2,ierflg);
				for (int i = 0; i < 4; ++i) gM->GetParameter(i,val[i],err[i]);

				printf("scale factors for %s, ptbin %d: b: %f+/-%f, c: %f+/-%f, g: %f+/-%f, j: %f+/-%f\n", nprong[iprong].Data(), ptbin, val[0],err[0], val[1],err[1], val[2],err[2], val[3],err[3]);

//============================post-fit plots============================
				for (int iorigin = 0; iorigin < 4; ++iorigin)
				{
					for (int ifveto = 0; ifveto < 2; ++ifveto){						
						for (int i = 0; i < 4; ++i){

							if (i == 3)
							{
								if(ifveto == 1) continue;
								target = tau_plots->plot_lib[origin[iorigin]][regions[1] + "_" + nprong[iprong] + (ifveto?"_veto":"_") + bwps[3]][0];
							}else{
								target = tau_plots->plot_lib[origin[iorigin]][regions[i] + "_" + nprong[iprong] + (ifveto?"_veto":"_") + bwps[1]][0];
							}

							if (ptbin<binning-1){
								target->SetBinContent(ptbin+1, val[iorigin]*target->GetBinContent(ptbin+1));
								target->SetBinError(ptbin+1, val[iorigin]*target->GetBinError(ptbin+1));
							}else{
								for (int ib = 4; ib < target->GetNbinsX()+1; ++ib){
									target->SetBinContent(ib, val[iorigin]*target->GetBinContent(ib));
									target->SetBinError(ib, val[iorigin]*target->GetBinError(ib));
								}
							}
						}
					}
				}
			}
		}
		tau_plots  ->plot_stack("postfit");
	}
	return 0;
}