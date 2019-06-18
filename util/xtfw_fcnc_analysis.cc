#include "histSaver.h"
#include "TH1D.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <sys/ioctl.h>
#include "observable.h"
TString NPnames[] = {
	"NOMINAL",
	"fakeSF",
	"fakeSFNP1",
	"fakeSFNP2",
	"fakeSFNP3",
	"fakeSFNP4",
	"fakeSFNP5",
	"fakeSFNP6",
	"PRW_DATASF_1up_pileup_combined_weight",
	"PRW_DATASF_1down_pileup_combined_weight",
	"jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10",
	"jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10",
	"jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10",
	"jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT",
	"jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT",
	"jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT",
	"jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT",
	"jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT",
	"jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT",
	"jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT",
	"jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM"
};

void plot(int iNP)
{
	bool doPlots = 0;
	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	tau_plots->doROC = 1;
	tau_plots->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV, 140 fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
	tau_plots->inputfilename = "hists"+to_string(iNP);
	tau_plots->debug = 0;
	bool calibfake = 1;
	bool fakeMC = 0;
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
	samples.push_back("fcnc_ch");
	samples.push_back("fcnc_prod_ch");
	samples.push_back("tcH");
	samples.push_back("fcnc_uh");
	samples.push_back("fcnc_prod_uh");
	samples.push_back("tuH");
	double norm[] = {1,1,1,1,1,1,0.2,0.2,0.2,0.2,0.2,0.2};
	vector<TString> sampletitle;
	sampletitle.push_back("SM Higgs");
	sampletitle.push_back("W+jets");
	sampletitle.push_back("Diboson");
	sampletitle.push_back("Z#rightarrowll");
	sampletitle.push_back("Z#rightarrow#tau#tau");
	sampletitle.push_back("Top production");
	sampletitle.push_back("#bar{t}t#rightarrowbWcH");
	sampletitle.push_back("ctH Prod Mode");
	sampletitle.push_back("tcH merged signal");
	sampletitle.push_back("#bar{t}t#rightarrowbWuH");
	sampletitle.push_back("utH Prod Mode");
	sampletitle.push_back("tuH merged signal");

	stringstream ss;
	ss<<"(BR=" << norm[6] << "%)";
	TString tmp;
	ss>>tmp;
	sampletitle[6]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data","doublefake"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kRed, kRed, kRed, kRed, kRed, kMagenta, kSpring, kTeal, kAzure};
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
				if (fakeMC && origin[i] != "real")
				{
					tau_plots->read_sample( "fake1truth", samples[j] + "_" + origin[i] + "_NP" + to_string(iNP), "Fake MC, 1 truth #tau", kMagenta, norm[j]);
				}
				if(origin[i] == "real"){
					if(j == samples.size()-4){
						tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_qq_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
						tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_lv_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
						tau_plots->read_sample( samples[j], TString("fcnc_prod_ch") + "_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					}else if(j == samples.size()-1){
						tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_qq_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
						tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_lv_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
						tau_plots->read_sample( samples[j], TString("fcnc_prod_uh") + "_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					}else if(j == samples.size()-3){
						tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_qq_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
						tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_lv_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					}else if(j == samples.size()-6){
						tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_qq_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
						tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_lv_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					}else{
						tau_plots->read_sample( samples[j], samples[j] + "_" + origin[i] + "_NP" + to_string(iNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					}
				}
				else if(!fakeMC && calibfake){
					tau_plots->read_sample( "fake", samples[j] + "_" + origin[i] + "_NP" + to_string(iNP), "MC Fake #tau", kTeal, norm[j]);
				}
				
			}
			if(fakeMC && j != samples.size()-1) tau_plots->read_sample( "fake0truth", samples[j] + "_" + origin[8] + "_NP" + to_string(iNP), "fake, 0 truth #tau", kTeal, norm[j]);
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
  		vector<TString> stacks;
  		//tau_plots->overlay("fake");
  		stacks.push_back("ztautau");
  		stacks.push_back("top");
  		if(!fakeMC && calibfake) stacks.push_back("fake");
  		stacks.push_back("smhiggs");
  		stacks.push_back("wjet");
  		stacks.push_back("zll");
  		stacks.push_back("diboson");
  		if(!fakeMC) {
  			stacks.push_back("fakeSS");
  		}
  		else{
  			stacks.push_back("fake1truth");
  			stacks.push_back("fake0truth");
  		}
  		tau_plots->stackorder = stacks;
  		//double integralerr = 0;
  		//observable int1b3jssdata(integral(tau_plots->grabdatahist("reg2mtau1b3jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b3josdata(integral(tau_plots->grabdatahist("reg2mtau1b3jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2jssdata(integral(tau_plots->grabdatahist("reg2mtau1b2jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2josdata(integral(tau_plots->grabdatahist("reg2mtau1b2jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b3jssbkg(integral(tau_plots-> grabbkghist("reg2mtau1b3jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b3josbkg(integral(tau_plots-> grabbkghist("reg2mtau1b3jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2jssbkg(integral(tau_plots-> grabbkghist("reg2mtau1b2jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2josbkg(integral(tau_plots-> grabbkghist("reg2mtau1b2jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int2b3jssdata(integral(tau_plots->grabdatahist("reg2mtau2b3jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b3josdata(integral(tau_plots->grabdatahist("reg2mtau2b3jos",0),-1,1,&integralerr),integralerr);
  		//observable int2b2jssdata(integral(tau_plots->grabdatahist("reg2mtau2b2jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b2josdata(integral(tau_plots->grabdatahist("reg2mtau2b2jos",0),-1,1,&integralerr),integralerr);
  		//observable int2b3jssbkg (integral(tau_plots-> grabbkghist("reg2mtau2b3jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b3josbkg (integral(tau_plots-> grabbkghist("reg2mtau2b3jos",0),-1,1,&integralerr),integralerr);
  		//observable int2b2jssbkg (integral(tau_plots-> grabbkghist("reg2mtau2b2jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b2josbkg (integral(tau_plots-> grabbkghist("reg2mtau2b2jos",0),-1,1,&integralerr),integralerr);
  		//observable SF1b = ((int1b2josdata - int1b2josbkg + int1b3josdata - int1b3josbkg) / (int1b2jssdata - int1b2jssbkg + int1b3jssdata - int1b3jssbkg));
  		//observable SF2b = ((int2b2josdata - int2b2josbkg + int2b3josdata - int2b3josbkg) / (int2b2jssdata - int2b2jssbkg + int2b3jssdata - int2b3jssbkg));
  		//observable SF = ((int1b2josdata - int1b2josbkg + int1b3josdata - int1b3josbkg + int2b2josdata - int2b2josbkg + int2b3josdata - int2b3josbkg) 
  		//	/ (int1b2jssdata - int1b2jssbkg + int1b3jssdata - int1b3jssbkg + int2b2jssdata - int2b2jssbkg + int2b3jssdata - int2b3jssbkg));
  		//SF1b.print();
  		//SF2b.print();
  		//SF.print();

		if(!fakeMC){
  			tau_plots->templatesample("reg2mtau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau1b3jos","fakeSS","Fake",kYellow,0);
  			tau_plots->templatesample("reg2mtau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau1b2jos","fakeSS","Fake",kYellow,0);
  			tau_plots->templatesample("reg2mtau2b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b3jos","fakeSS","Fake",kYellow,1);
  			tau_plots->templatesample("reg2mtau2b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b2jos","fakeSS","Fake",kYellow,1);
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
  	}
	tau_plots->write_trexinput(NPnames[iNP],"update");
	if(doPlots){
		for (int i = samples.size()-6; i < samples.size(); ++i)
		{
  			tau_plots->overlay(samples[i]);
			tau_plots  ->plot_stack("output/" + samples[i]);
		}
		
	}
	deletepointer(tau_plots);
}

int main(int argc, char const *argv[])
{
	int from = atoi(argv[1]);
	int to = atoi(argv[2]);
	for (int i = from; i <= to; ++i)
	{
//	struct winsize w; 
//	ioctl(0, TIOCGWINSZ, &w);
//	auto start = chrono::steady_clock::now();
//
//	for (int i = 0; i < 168; ++i)
//	{
//		if (i == 1)
//		{
//			continue;
//		}
//		auto end = chrono::steady_clock::now();
//		stringstream ss;
//		ss<<"Elapsed time in seconds : "<< chrono::duration_cast<chrono::seconds>(end - start).count()
//		<< " sec";
//	
//		printf("%*s\n" , w.ws_col, ss.str().c_str());
		printf("=============================generating NP %d : %s=============================\n", i, NPnames[i].Data());
		plot(i);
	}
	return 0;
}
