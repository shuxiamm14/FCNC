#define nominal_cxx
#include "nominal.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <stdlib.h>

nominal::nominal(){
  //init histSaver here:
  tau_plots = new histSaver();
  tau_plots->set_weight(&weight);

  notau_plots = new histSaver();
  notau_plots->set_weight(&weight);

  tau_plots->init_sample("data","data",kBlack);
  tau_plots->init_sample("other","Other samples",kYellow);
  tau_plots->init_sample("ttbar_g","t#bar{t}(gluon fake #tau)",kPink);
  tau_plots->init_sample("ttbar_j","t#bar{t}(light-jet fake #tau)",kBlue);
  tau_plots->init_sample("ttbar_b","t#bar{t}(b-jets fake #tau)",kViolet);
  tau_plots->init_sample("ttbar_lep","t#bar{t}(lepton fake #tau)",kGreen);
  tau_plots->init_sample("ttbar_real","t#bar{t}(real #tau)",kRed);
  tau_plots->init_sample("ttbar_nomatch","t#bar{t}(no truth matched fake #tau)",kGray);

  notau_plots->init_sample("data","data",kBlack);
  notau_plots->init_sample("other","Other samples",kYellow);
  notau_plots->init_sample("ttbar","t#bar{t}",kRed);

  TString regions[] = {"reg1e1mu1tau2b","reg1e1mu2bnj","reg1l1tau2b1j","reg1l2b2j","reg1e1mu1tau1b","reg1e1mu2b"};
  TString nprong[] = {"1prong","3prong"};

  for (int k = 0; k < 2; ++k)
    for (int j = 0; j < 6; ++j)
      for (int i = 0; i < 4; ++i){
        printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
        tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
      }
  tau_plots->add(30,25.,115.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
}

nominal::~nominal(){
  deletepointer(tau_plots);
  deletepointer(notau_plots);
}

void nominal::fill_tau(TString region, int nprong, TString sample){
  for (int i = 0; i < 4; ++i)
    if(tau_MV2c10_0>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong)+"_"+bwps[i]).Data(), sample.Data());
      tau_plots->fill_hist(region+"_"+char('0'+nprong)+"_"+bwps[i],sample);
    }
}

void nominal::fill_notau(TString region, TString sample){
  if(debug) printf("fill region: %s sample: %s\n", (region).Data(), sample.Data());
  notau_plots->fill_hist(region,sample);
}

void nominal::Loop(TTree *inputtree, TString sample)
{
  Init(inputtree);
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    nb = fChain->GetEntry(jentry);
    if(debug||(jentry%10000==0))
      std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;

//===============================pre-selections===============================

    bool basic_selection = passEventCleaning;

    if(sample.Contains("ttbargamma")) { basic_selection &=m_hasMEphoton_DRgt02_nonhad; sample = "ttbar"; }
    if(sample.Contains("ttbarnohad")) { basic_selection &=!m_hasMEphoton_DRgt02_nonhad; sample = "ttbar"; }

    basic_selection &= 
      (RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
      (RunYear==2015 && (HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1))||
      (RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 ))||
      (RunYear>=2016 && (HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1)); // assuming triggers for 2017 is same for 2016 

    if (!basic_selection) continue;

    bool trig_match = (lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
    bool SLtrig_match = 
      ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
    	(RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 )))&&lep_isTrigMatch_0;

    weight = mc_channel_number>0?_lum/43.814*mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*JVT_EventWeight*SherpaNJetWeight*((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0; 
    map<TString, bool> ifregions;
//===============================define regions===============================
    if(trig_match&&dilep_type&&total_charge==0&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&
      ((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&SelectTLepid(0)&&
      ((abs(lep_ID_1)==11&&lep_promptLeptonVeto_TagWeight_1<-0.7)||(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5))&&SelectTLepid(1)){ //met>30 GeV ? ttbar vs z+bb:
      ifregions["reg1e1mu1tau2b"] = (dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&total_charge==0&&nJets_OR_T_MV2c10_70==2&&nJets_OR_T==1&&nTaus_OR_Pt25==1;
      ifregions["reg1e1mu2bnj"]   = (dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&total_charge==0&&nJets_OR_T_MV2c10_70==2&&nJets_OR_T>=1&&nTaus_OR_Pt25==0;
      ifregions["reg1e1mu1tau1b"] = (dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&total_charge==0&&nJets_OR_T_MV2c10_70==1&&nJets_OR_T==1&&nTaus_OR_Pt25==1;
      ifregions["reg1e1mu2b"]     = (dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&total_charge==0&&nJets_OR_T_MV2c10_70==2&&nJets_OR_T==0&&nTaus_OR_Pt25==0;
    }else{
      ifregions["reg1e1mu1tau2b"] = 0;
      ifregions["reg1e1mu2bnj"]   = 0;
      ifregions["reg1e1mu1tau1b"] = 0;
      ifregions["reg1e1mu2b"]     = 0;
    }
    ifregions["reg1l2b2j"]      = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==2 && nJets_OR_T==2 && nTaus_OR_Pt25==0;
    ifregions["reg1l1tau2b1j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==2 && nJets_OR_T==2 && nTaus_OR_Pt25==1;
//===============================fill histograms===============================
    map<TString, bool>::iterator iter;
    TString tauorigin;
    if(sample == "ttbar" && nTaus_OR_Pt25==1){
      if(tau_truthType_0 == 10) tauorigin == "ttbar_real";
      else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)) tauorigin == "ttbar_lep";
      else
        switch (tau_truthJetFlavour_0){
          case 5:
            tauorigin == "ttbar_b";
            break;
          case 21:
            tauorigin == "ttbar_g";
            break;
          case 4:
            tauorigin == "ttbar_c";
            break;
          default:
            tauorigin == "ttbar_j";
        }
    }else if(sample == "data"){
      tauorigin == "data";
    }else{
      tauorigin == "other";
    }
    for(iter=ifregions.begin(); iter!=ifregions.end(); iter++)
    {
      if(iter->second == 1 & iter->first.Contains("tau")  & ( tau_numTrack_0 == 1 | tau_numTrack_0 == 3 ) ) fill_tau(iter->first,tau_numTrack_0,tauorigin);
      if(iter->second == 1 & !iter->first.Contains("tau") ) fill_notau(iter->first,sample);
    }
  }
}

void nominal::plot(){
  tau_plots->plot_stack();
  notau_plots->plot_stack();
}

bool nominal::SelectTLepid(int id){
  bool pass(false);
  //lep_ambiguityType_0==0 for electron
  if(id==0){
    pass = lep_isolationFixedCutLoose_0&&(abs(lep_ID_0)==13||((abs(lep_ID_0)==11)&&lep_isTightLH_0));
  }
  else if(id==1){
    pass = lep_isolationFixedCutLoose_1&&(abs(lep_ID_1)==13||((abs(lep_ID_1)==11)&&lep_isTightLH_1));
  }
  else if(id==2){
    pass = lep_isolationFixedCutLoose_2&&(abs(lep_ID_2)==13||((abs(lep_ID_2)==11)&&lep_isTightLH_2));
  }
  else if(id==3){
    pass = lep_isolationFixedCutLoose_3&&(abs(lep_ID_3)==13||((abs(lep_ID_3)==11)&&lep_isTightLH_3));
  }
  else if(id==4){
    pass = lep_isolationFixedCutLoose_4&&(abs(lep_ID_4)==13||((abs(lep_ID_4)==11)&&lep_isTightLH_4));
  }
  return pass;
}
