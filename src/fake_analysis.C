#define nominal_cxx
#include "nominal.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <stdlib.h>
void init_hist(){  

  //init histSaver here:
  dohist = 1;
  tau_plots = new histSaver();
  tau_plots->set_weight(&weight);
  tau_plots->debug = 0;
  notau_plots = new histSaver();
  notau_plots->set_weight(&weight);
  notau_plots->debug = 0;
  writetree = 0;

  tau_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
  tau_plots->add(10,25.,125.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  tau_plots->add(10,25.,125.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  tau_plots->add(20,20.,120.,"m_{#tau,light-jet}","taulmass",&taulmass,true,"GeV");
  tau_plots->add(100,0.,100.,"E_{miss}^{T}","met",&MET_RefFinal_et,true,"GeV");
  notau_plots->add(10,0.,200.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  notau_plots->add(10,0.,200.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");

  TString _regions[] = {"reg1e1mu1tau2b","reg1l1tau2b1j_os","reg1l1tau2b1j_ss_ptbin1","reg1l1tau2b1j_ss_ptbin2","reg1l1tau2b1j_ss_ptbin2","reg1e1mu1tau1b"};

  regions = _regions;
  nregions = sizeof(_regions)/sizeof(TString);

  TString regions_notau[] = {"reg1e1mu2bnj","reg1l2b2j","reg1e1mu2b"};
  TString nprong[] = {"1prong","3prong"};

  for (int j = 0; j < nregions; ++j)
    for (int k = 0; k < 2; ++k){
      for (int i = 1; i < 4; i+=2){
        printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
        tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
        tau_plots->add_region(regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
      }
    }
  for (int j = 0; j < sizeof(regions_notau)/sizeof(TString); ++j)
    notau_plots->add_region(regions_notau[j]);}
nominal::nominal(){
}

nominal::~nominal(){
  deletepointer(tau_plots);
  deletepointer(notau_plots);
}

void nominal::fill_tau(TString region, int nprong, TString sample, int iptbin){
  for (int i = 1; i < 4; i+=2){
    if(tau_MV2c10_0>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[i]).Data(), sample.Data());
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_"+bwps[i]);
    }else{
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_veto"+bwps[i]);
    }
  }
}

void nominal::fill_notau(TString region, TString sample){
  if(debug) printf("fill region: %s sample: %s\n", (region).Data(), (sample).Data());
  notau_plots->fill_hist(sample, region);
}

void nominal::init_sample(TString sample, TString sampletitle){

  if(sample.Contains("ttbar")) sample = "ttbar";
  if(dohist)
    if (sample.Contains("data"))
    {
      tau_plots->init_sample("data","data","data",kBlack);
      notau_plots->init_sample("data","data_notau","data",kBlack);
      initdata = 1;
    }else{
      tau_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      tau_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
      tau_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
      tau_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
      tau_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
      tau_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
      tau_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
      notau_plots->init_sample(sample,sample + "_notau",sampletitle + "",kRed);
    }
}

void nominal::Loop(TTree *inputtree, TString samplename)
{
  Init(inputtree);
  TFile outputfile(samplename+".root","update");
  TTree *outputtree;
  if(outputfile.Get("tree")) {
    outputtree = (TTree*) outputfile.Get("tree");
    reduce = 1;
    Init(outputtree);
    reduce = 0;
  }else{
    outputtree = new TTree("tree","tree");
    definetree(outputtree);
  }
  if (inputtree == 0) return;
  Long64_t nentries = inputtree->GetEntriesFast();
  TString sample = samplename;
  if(samplename.Contains("ttbar")) sample = "ttbar";
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
  //for (Long64_t jentry=0; jentry<6000;jentry++) {
    inputtree->GetEntry(jentry);
    if((jentry%100000==0))
      std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;
//===============================pre-selections===============================

      if(selected_jets_T->size() == 0 && nJets_OR_T !=0 ) {
        printf("error: read vector failed entry: %d\n",jentry);
        continue;
      }
    bool basic_selection = passEventCleaning;

    if (!basic_selection) continue;

    if(samplename.Contains("ttbargamma")) { basic_selection =m_hasMEphoton_DRgt02_nonhad;}
    if(samplename.Contains("ttbarnohad")) { basic_selection =!m_hasMEphoton_DRgt02_nonhad;}

    if (!basic_selection) continue;

    basic_selection = 
      (RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
      (RunYear==2015 && (HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1))||
      (RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 ))||
      (RunYear>=2016 && (HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1)); // assuming triggers for 2017 is same for 2016 

    if (!basic_selection) continue;

    bool trig_match = (lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
    bool SLtrig_match = 
      ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
    	(RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 )))&&lep_isTrigMatch_0;

    weight = mc_channel_number>0?mc_norm*mcWeightOrg*pileupEventWeight_090*(V7NTUP?bTagSF_weight_MV2c10_FixedCutBEff_70:bTagSF_weight_MV2c10_Continuous)*JVT_EventWeight*SherpaNJetWeight*((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0; 
//===============================define regions===============================
    map<TString, bool> ifregions;
    if(trig_match&&dilep_type&&total_charge==0&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&
      ((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&SelectTLepid(0)&&
      ((abs(lep_ID_1)==11&&lep_promptLeptonVeto_TagWeight_1<-0.7)||(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5))&&SelectTLepid(1)&&
      (nTaus_OR_Pt25==0||(tau_passEleBDT_0&&tau_passMuonOLR_0))
      &&(dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&total_charge==0){ //met>30 GeV ? ttbar vs z+bb:
      ifregions["reg1e1mu1tau2b"] = nJets_OR_T_MV2c10_70==2&&nJets_OR_T==2&&nTaus_OR_Pt25==1;
      ifregions["reg1e1mu2bnj"]   = nJets_OR_T_MV2c10_70==2&&nJets_OR_T>=3&&nTaus_OR_Pt25==0;
      ifregions["reg1e1mu1tau1b"] = nJets_OR_T_MV2c10_70==1&&nJets_OR_T==1&&nTaus_OR_Pt25==1;
      ifregions["reg1e1mu2b"]     = nJets_OR_T_MV2c10_70==2&&nJets_OR_T==2&&nTaus_OR_Pt25==0;
    }else{
      ifregions["reg1e1mu1tau2b"] = 0;
      ifregions["reg1e1mu2bnj"]   = 0;
      ifregions["reg1e1mu1tau1b"] = 0;
      ifregions["reg1e1mu2b"]     = 0;
    }
    ifregions["reg1l2b2j"]      = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==2 && nJets_OR_T>=4 && nTaus_OR_Pt25==0;
    ifregions["reg1l1tau2b1j_os"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==2 && nJets_OR_T>=3 && nTaus_OR_Pt25>=1 && (lep_ID_0>0?-1:1)*tau_charge_0<0;
    TString reg1l1tau2b1j_ss = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==2 && nJets_OR_T>=3 && nTaus_OR_Pt25>=1 && (lep_ID_0>0?-1:1)*tau_charge_0>0;
    ifregions["reg1l1tau2b1j_ss_ptbin1"] = reg1l1tau2b1j_ss && tau_pt_0/GeV <= 35;
    ifregions["reg1l1tau2b1j_ss_ptbin2"] = reg1l1tau2b1j_ss && tau_pt_0/GeV > 35;

    if(ifregions["reg1l1tau2b1j_os"] || ifregions["reg1l1tau2b1j_ss"]||ifregions["reg1e1mu2bnj"]||ifregions["reg1l2b2j"]){
//===============================find leading b,non b jets===============================
      leading_b = -1;
      leading_ljet = -1;
      pt_b = 0;
      pt_ljet = 0;
      for (int i = 0; i < nJets_OR_T; ++i)
      {
        if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] > btag70wt && leading_b == -1) {
          leading_b = selected_jets_T->at(i);
          pt_b = (*m_jet_pt)[selected_jets_T->at(i)];
        }else if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] < btag70wt && leading_ljet == -1){
          leading_ljet = selected_jets_T->at(i);
          pt_ljet = (*m_jet_pt)[selected_jets_T->at(i)];
        }
      }
      TLorentzVector lp, taup;
      if(leading_ljet>=0) lp.SetPtEtaPhiE((*m_jet_pt)[leading_ljet],(*m_jet_eta)[leading_ljet],(*m_jet_phi)[leading_ljet],(*m_jet_E)[leading_ljet]);
      else {
        printf("ERROR: no light jet found\n");
        printf("nJets_OR_T_MV2c10_70: %d, nJets_OR_T: %d\n",nJets_OR_T_MV2c10_70,nJets_OR_T);
        for(int i = 0; i < nJets_OR_T; ++i) printf("btag: %f\n",(*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)]);
      }
      if(ifregions["reg1l1tau2b1j_os"] || ifregions["reg1l1tau2b1j_ss"]){
        taup.SetPtEtaPhiE((*m_tau_pt)[0],(*m_tau_eta)[0],(*m_tau_phi)[0],(*m_tau_E)[0]);
        taulmass = (taup+lp).M();
      }else
        taulmass = 0;
    }else if(ifregions["reg1e1mu1tau2b"]||ifregions["reg1e1mu1tau1b"]||ifregions["reg1e1mu2b"]){
      taulmass = 0;
    }else continue;
    outputtree->Fill();
//===============================fill histograms===============================
    if(dohist){
      map<TString, bool>::iterator iter;
      TString tauorigin;
      if(sample == "data"){
        tauorigin = "data";
      }else if(nTaus_OR_Pt25>=1){
        if(tau_truthType_0 == 10) tauorigin = sample + "_real";
        else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)) tauorigin = sample + "_lep";
        else
          switch (tau_truthJetFlavour_0){
            case 5:
              tauorigin = sample + "_b";
              break;
            case 21:
              tauorigin = sample + "_g";
              break;
            case 4:
              tauorigin = sample + "_c";
              break;
            default:
              tauorigin = sample + "_j";
          }
      }
  
      for(iter=ifregions.begin(); iter!=ifregions.end(); iter++)
      {
        if(iter->second == 1 & iter->first.Contains("tau")  & ( tau_numTrack_0 == 1 | tau_numTrack_0 == 3 ) ) { fill_tau(iter->first,tau_numTrack_0,tauorigin,0); }
        if(iter->second == 1 & !iter->first.Contains("tau") ) { fill_notau(iter->first,sample); }
      }
    }
  }
  outputfile.cd();
  outputtree->Write("tree",TObject::kWriteDelete);
  outputfile.Close();
  deletepointer(outputtree);
}

void nominal::plot(){
  tau_plots->write();
  notau_plots->write();
}
