#define nominal_cxx
#include "nominal.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <stdlib.h>
TMinuit* gM = 0;
nominal::nominal(){
  TLorentzVector v1;
  for(int i = 0 ; i < 2 ; ++i){
    taus_v.push_back(v1);
  }
  forFit.Add(&(taus_v[0]));
  forFit.Add(&(taus_v[1]));
  forFit.Add(&bjet_v);
  forFit.Add(&cjet_v);
  forFit.Add(&lep_v);
  forFit.Add(&mets);

  neutrino_pt  = new vector<float>();
  neutrino_eta = new vector<float>();
  neutrino_phi = new vector<float>();
  neutrino_m   = new vector<float>();
}
void nominal::init_hist(){
  //init histSaver here:
  dohist = 1;
  tau_plots = new histSaver();
  tau_plots->set_weight(&weight);
  tau_plots->debug = 0;
  if (dofcnc){
    tau_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
    tau_plots->add(100,50.,250.,"m_{t,SM}","t1mass",&t1mass,true,"GeV");
    tau_plots->add(100,50.,250.,"m_{#tau,#tau}","tautaumass",&tautaumass,true,"GeV");
    tau_plots->add(100,50.,250.,"m_{W}","wmass",&wmass,true,"GeV");
    tau_plots->add(100,50.,250.,"m_{t,FCNC}","t2mass",&t2mass,true,"GeV");
    tau_plots->add(100,50.,250.,"m_{#tau#tau,vis}","tautauvismass",&ttvismass,true,"GeV");
    tau_plots->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,true,"GeV");
    tau_plots->add(100,0.,1.,"E_{#nu,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
    tau_plots->add(100,0.,1.,"E_{#nu,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
    
    TString _regions[] = {"reg1l2tau1bnj","reg1l1tau1b2j","reg1l1tau1b3j"};

    nregions = sizeof(_regions)/sizeof(TString);
    regions = (TString**)malloc(nregions*sizeof(TString*));
    for (int i = 0; i < nregions; ++i)
    {
      regions[i] = new TString(_regions[i]);
    }

    TString nprong[] = {"1prong","3prong"};
  
    for (int j = 0; j < 3; ++j){
      for (int k = 0; k < 2; ++k)
      {
        for (int i = 0; i < 4; ++i)
        {
          if(doseppt)
            for (int iptbin = 0; iptbin < 2; ++iptbin)
            {
              if(debug) printf("adding region: %s\n", (*regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
              tau_plots->add_region(*regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
              tau_plots->add_region(*regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
            }
          tau_plots->add_region(*regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
          tau_plots->add_region(*regions[j] + "_" + nprong[k] + "_" + bwps[i]);
        }
      }
    }
  }else{
    notau_plots = new histSaver();
    notau_plots->set_weight(&weight);
    notau_plots->debug = 0;
    tau_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
    tau_plots->add(10,25.,125.,"p_{T,b}","bpt",&pt_b,true,"GeV");
    tau_plots->add(10,25.,125.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
    tau_plots->add(20,20.,120.,"m_{#tau,light-jet}","taulmass",&taulmass,true,"GeV");
    tau_plots->add(100,0.,100.,"E_{miss}^{T}","met",&MET_RefFinal_et,true,"GeV");
    notau_plots->add(10,0.,200.,"p_{T,b}","bpt",&pt_b,true,"GeV");
    notau_plots->add(10,0.,200.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  
    TString _regions[] = {"reg1e1mu1tau2b","reg1l1tau2b1j_os","reg1l1tau2b1j_ss_ptbin1","reg1l1tau2b1j_ss_ptbin2","reg1l1tau2b1j_ss_ptbin2","reg1e1mu1tau1b"};
  
    nregions = sizeof(_regions)/sizeof(TString);
    regions = (TString**)malloc(nregions*sizeof(TString*));
    for (int i = 0; i < nregions; ++i)
    {
      regions[i] = new TString(_regions[i]);
    }
    TString regions_notau[] = {"reg1e1mu2bnj","reg1l2b2j","reg1e1mu2b"};
    TString nprong[] = {"1prong","3prong"};
  
    for (int j = 0; j < nregions; ++j)
      for (int k = 0; k < 2; ++k){
        for (int i = 1; i < 4; i+=2){
          printf("adding region: %s\n", (*regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
          tau_plots->add_region(*regions[j] + "_" + nprong[k] + "_" + bwps[i]);
          tau_plots->add_region(*regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
        }
      }
    for (int j = 0; j < sizeof(regions_notau)/sizeof(TString); ++j)
      notau_plots->add_region(regions_notau[j]);
  }
}
nominal::~nominal(){
  deletepointer(tau_plots);
  deletepointer(gM);
  deletepointer(neutrino_pt  );
  deletepointer(neutrino_eta );
  deletepointer(neutrino_phi );
  deletepointer(neutrino_m   );
}

void nominal::fill_tau(TString region, int nprong, TString sample, int iptbin){
  for (int i = 0; i < 4; ++i){
    if(tau_MV2c10_0>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[i]).Data(), sample.Data());
      if(doseppt) tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[i]);
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + bwps[i]);
    }else{
      if(doseppt) tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[i]);
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + "veto" + bwps[i]);
    }
  }
}

void nominal::initgM(){

  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);

}
void nominal::init_sample(TString sample, TString sampletitle){
  if(dohist) tau_plots->histfilename = sample;
//==========================init output n-tuple==========================
  if(writetree){
    outputtreefile = new TFile(sample + "_tree.root","update");
    map<TString, TTree*>::iterator iter;
    for (int i = 0; i < nregions; ++i)
    {
      if (outputtreefile->Get(*regions[i])) {
        outputtree[*regions[i]] = (TTree*)(outputtreefile->Get(*regions[i]));
        Init(outputtree[*regions[i]]);
      }else{
        outputtree[*regions[i]] = new TTree(*regions[i],*regions[i]);
        definetree(outputtree[*regions[i]]);
      }
      if(reduce >= 1 || reduce == 0 && dofcnc){
        outputtree[*regions[i]]->Branch("t1mass",&t1mass);
        outputtree[*regions[i]]->Branch("tautaumass",&tautaumass);
        outputtree[*regions[i]]->Branch("wmass",&wmass);
        outputtree[*regions[i]]->Branch("t2mass",&t2mass);
      }
      if(reduce==2 || reduce == 0 && dofcnc){
        outputtree[*regions[i]]->Branch("neutrino_pt" , &neutrino_pt );
        outputtree[*regions[i]]->Branch("neutrino_eta", &neutrino_eta);
        outputtree[*regions[i]]->Branch("neutrino_phi", &neutrino_phi);
        outputtree[*regions[i]]->Branch("neutrino_m"  , &neutrino_m  );
        outputtree[*regions[i]]->Branch("weight",&weight);
        outputtree[*regions[i]]->Branch("fakeSF",&fakeSF);
        outputtree[*regions[i]]->Branch("cjet_index", &cjet_index );
        outputtree[*regions[i]]->Branch("wjet1_index", &wjet1_index);
        outputtree[*regions[i]]->Branch("wjet2_index", &wjet2_index);
        outputtree[*regions[i]]->Branch("x1fit", &x1fit);
        outputtree[*regions[i]]->Branch("x2fit", &x2fit);
        outputtree[*regions[i]]->Branch("t1vismass",&t1vismass);
        outputtree[*regions[i]]->Branch("t2vismass",&t2vismass);
        outputtree[*regions[i]]->Branch("ttvismass",&ttvismass);
      }
    }
  }
//  for (iter = outputtree.begin(); iter!=outputtree.end(); ++iter)
//    iter->second->SetDirectory(outputtreefile);

//==========================init output histogram==========================
  if(dohist){
    if (sample.Contains("data"))
    {
      tau_plots->init_sample("data","data","data",kBlack);
      initdata = 1;
    }else{
      if(sample.Contains("ttbar")) sample = "ttbar";
      else sample.Remove(sample.Sizeof()-2);
      tau_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      tau_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
      tau_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
      tau_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
      tau_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
      tau_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
      tau_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
    }
  }
}

void nominal::Loop(TTree *inputtree, TString samplename)
{
  reduce -= 1;
  Init(inputtree);
  reduce += 1;
  printf("reduce scheme: %d\n", reduce);
  if(reduce > 1) {
    ifregions[inputtree->GetName()] = 1;
  }
  if (inputtree == 0) return;
  Long64_t nentries = inputtree->GetEntriesFast();
  TString sample = samplename;
  if(samplename.Contains("ttbar")) sample = "ttbar";
  else sample.Remove(sample.Sizeof()-2);
  if(dofcnc) initgM();

  if(dumptruth){
    if(TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) filetruth[0].open("lephad2j.txt");
    else
      for (int i = 0; i < 3; ++i)
      {
        if(TString(inputtree->GetName()).Contains("reg1l1tau1b3j")) filetruth[i].open(CharAppend("lephad",i+2) + "j.txt");
        else filetruth[i].open(CharAppend("lep2tau",i+1) + "j.txt");
      }
  }
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    inputtree->GetEntry(jentry);
    if((jentry%100000==0))
      std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;
//===============================pre-selections===============================

    if(selected_jets_T->size() == 0 && nJets_OR_T !=0 ) {
      printf("error: read vector failed entry: %d\n",jentry);
      continue;
    }

    map<TString, bool>::iterator iter;
    if(reduce == 1 || reduce == 0){
      bool basic_selection = passEventCleaning;
  
      if(samplename.Contains("ttbargamma")) { basic_selection &=m_hasMEphoton_DRgt02_nonhad;}
      if(samplename.Contains("ttbarnohad")) { basic_selection &=!m_hasMEphoton_DRgt02_nonhad;}
  
      basic_selection &= 
        (RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
        (RunYear==2015 && (HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1))||
        (RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 ))||
        (RunYear>=2016 && (HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1));

      if(dofcnc)  basic_selection = basic_selection&&(tau_numTrack_0 == 1 || tau_numTrack_0 == 3); // assuming triggers for 2017 is same for 2016 
  
      if (!basic_selection) continue;
  
      bool trig_match = (lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
      bool SLtrig_match = 
        ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
      	(RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 )))&&lep_isTrigMatch_0;

//===============================define regions===============================
      if(dofcnc){
        ifregions["reg1l1tau1b2j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T==3 && nTaus_OR_Pt25==1;
        ifregions["reg1l1tau1b3j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T>4 && nTaus_OR_Pt25==1;
        ifregions["reg1l2tau1bnj"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T>=2 && nTaus_OR_Pt25>=2;
      }else{
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
      }

      bool triggered = 0;
      
      for(iter=ifregions.begin(); iter!=ifregions.end(); iter++)
        if(iter->second) {
          triggered = 1;
        }

      if(!triggered) continue;
    }
    if(reduce <= 2) weight = mc_channel_number>0?mc_norm*mcWeightOrg*pileupEventWeight_090*(version == 7?bTagSF_weight_MV2c10_FixedCutBEff_70:bTagSF_weight_MV2c10_Continuous)*JVT_EventWeight*SherpaNJetWeight*((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0;
    if(debug==2) printf("event weight: %f\n", weight);
    if(debug == 2){
      for(iter = ifregions.begin(); iter!= ifregions.end(); iter++){
        if (iter->second)
          printf("region: %s\n", iter->first.Data());
      }
    }
//===============================find leading b,non b jets===============================
    if(reduce <= 2){
      leading_b = -1;
      leading_ljet = -1;
      pt_b = 0;
      pt_ljet = 0;
      bool reloop = 1;
      if(nJets_OR_T != selected_jets_T->size()){
        printf("ERROR: nJets_OR_T,%d != selected_jets_T->size(),%d; Entry: %d\n", nJets_OR_T,selected_jets_T->size(),jentry);
        continue;
      }
      for (int i = 0; i < nJets_OR_T; ++i)
      {
        if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] > btag70wt && leading_b == -1) {
          leading_b = selected_jets_T->at(i);
          pt_b = (*m_jet_pt)[selected_jets_T->at(i)];
        }else if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] < btag70wt && reloop == 1){
          leading_ljet = selected_jets_T->at(i);
          cjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_ljet],(*m_jet_eta)[leading_ljet],(*m_jet_phi)[leading_ljet],(*m_jet_E)[leading_ljet]);
          if((cjet_v + taus_v[0] + taus_v[1]).M() < 175) reloop = 0;
          pt_ljet = (*m_jet_pt)[selected_jets_T->at(i)];
          cjet_index = selected_jets_T->at(i);
        }
        if(reloop == 0 && leading_b != -1) break;
      }
      if(dofcnc){
        if(ifregions["reg1l2tau1bnj"]){
          for (int i = 0; i < 2; ++i) taus_v[i].SetPtEtaPhiE((*m_tau_pt)[i],(*m_tau_eta)[i],(*m_tau_phi)[i],(*m_tau_E)[i]);
          if (fabs(lep_ID_0)==11) lep_v.SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
          else lep_v.SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
          bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
        }
        else{
          if (fabs(lep_ID_0)==11) taus_v[0].SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
          else taus_v[0].SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
          taus_v[1].SetPtEtaPhiE((*m_tau_pt)[0],(*m_tau_eta)[0],(*m_tau_phi)[0],(*m_tau_E)[0]);
          lep_v.SetPtEtaPhiE(0,0,0,0);
          bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
          cjet_index = findcjet();
          if(debug) {
            printf("wmass: %f, t1mass: %f, cjet %d, wjet1 %d\n", wmass, t1mass, cjet_index, wjet1_index);
          }
          cjet_v.SetPtEtaPhiE((*m_jet_pt)[cjet_index],(*m_jet_eta)[cjet_index],(*m_jet_phi)[cjet_index],(*m_jet_E)[cjet_index]);
        }
        if(cjet_index == wjet1_index && !ifregions["reg1l2tau1bnj"]) printf("bug: cjet=w1jet %d\n",cjet_index);
        mets.SetXYZ(met_met*cos(met_phi), met_met*sin(met_phi), MET_RefFinal_sumet);
//==    =============================fit neutrino===============================
        gM->mnparm(0, "rpt1", 0.4, 0.01, 0.,2.,ierflg);
        gM->mnparm(1, "rpt2", 0.4, 0.01, 0.,2.,ierflg);
    
        if(nTaus_OR_Pt25>=2){
          gM->mnparm(2, "pt3", 10000, 10000, 0.,1000000.,ierflg);
          gM->mnparm(3, "eta3",0, 0.1, -5,5,ierflg);
          gM->mnparm(4, "phi3",0, 0.1, -PI,PI,ierflg);
          arglist[0] = 5;
        }else{
          gM->mnparm(2, "v1mass", 1000, 1, 0.,1776,ierflg);
          arglist[0] = 3;
        }
        gM->SetObjectFit(&forFit);
    
        arglist[1] = 60.;
        Double_t val[5] = {0,0,0,0,0};
        Double_t err[5] = {0,0,0,0,0};
      
        gM->mnexcm("SCAN", arglist ,2,ierflg);
        for (int i = 0; i < 5; ++i) gM->GetParameter(i,val[i],err[i]);
        gM->mnparm(0, "rpt1", val[0], 0.01, 0.,2.,ierflg);
        gM->mnparm(1, "rpt2", val[1], 0.01, 0.,2.,ierflg);
        if(nTaus_OR_Pt25>=2){
          gM->mnparm(2, "pt3",  val[2], 10, 0.,1000.,ierflg);
          gM->mnparm(3, "eta3", val[3], 0.1, -5,5,ierflg);
          gM->mnparm(4, "phi3", val[4], 0.1, -PI,PI,ierflg);
        }else{
          gM->mnparm(2, "v1mass", val[2], 1, 0.,1776,ierflg);
        }
      
        arglist[0] = 1000;
        arglist[1] = 0;
      
        gM->mnexcm("MIGRADE", arglist ,2,ierflg);
        for (int i = 0; i < (nTaus_OR_Pt25>=2?5:3); ++i) gM->GetParameter(i,val[i],err[i]);
      
      
        Double_t fmin, fedm, errdef;
        Int_t npari, nparx, istat;
        gM->mnstat(fmin, fedm, errdef,npari, nparx, istat);
        TLorentzVector tauv1_v; tauv1_v.SetPtEtaPhiM(val[0]*(*m_tau_pt)[0],(*m_tau_eta)[0],(*m_tau_phi)[0],nJets_OR_T>=2?0:val[2]);
        TLorentzVector tauv2_v; tauv2_v.SetPtEtaPhiM(val[1]*(*m_tau_pt)[1],(*m_tau_eta)[1],(*m_tau_phi)[1],0);
        x1fit = val[0];
        x2fit = val[1];
        neutrino_pt  ->push_back (tauv1_v.Pt ()); neutrino_pt  ->push_back (tauv2_v.Pt ());
        neutrino_eta ->push_back (tauv1_v.Eta()); neutrino_eta ->push_back (tauv2_v.Eta());
        neutrino_phi ->push_back (tauv1_v.Phi()); neutrino_phi ->push_back (tauv2_v.Phi());
        neutrino_m   ->push_back (tauv1_v.M  ()); neutrino_m   ->push_back (tauv2_v.M  ());
        if (nTaus_OR_Pt25>=2)
        {
          TLorentzVector wv_v   ; wv_v   .SetPtEtaPhiM(val[2],val[3],val[4],0);
          neutrino_pt  ->push_back (wv_v.Pt ());
          neutrino_eta ->push_back (wv_v.Eta());
          neutrino_phi ->push_back (wv_v.Phi());
          neutrino_m   ->push_back (wv_v.M  ());
          t1mass     = ( lep_v + wv_v + bjet_v ) .M();
          t1vismass = ( lep_v + bjet_v ) .M();
          wmass      = ( lep_v + wv_v ).M();
        }else{
          t1vismass = t1mass;
        }
        tau_leadpt = taus_v[0].Pt();
        tau_subpt  = taus_v[1].Pt();
        t2mass     = ( tauv2_v + taus_v[0] + tauv1_v + taus_v[1] + cjet_v) .M();
        tautaumass  = ( tauv2_v + taus_v[0] + tauv1_v + taus_v[1] ) .M();
        ttvismass  = ( taus_v[0] + taus_v[1] ) .M();
        t2vismass = ( taus_v[0] + taus_v[1] + cjet_v ) .M();
      }else if(ifregions["reg1l1tau2b1j_os"] || ifregions["reg1l1tau2b1j_ss"]||ifregions["reg1e1mu2bnj"]||ifregions["reg1l2b2j"]){
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
        } else taulmass = 0;
      }
    }else{
      if(dofcnc){
        x1fit = 1./(x1fit+1);
        x2fit = 1./(x2fit+1);
      }
    }

//===============================fill histograms, fill tree===============================
    TString tauorigin;
    int SFbin = (tau_pt_0/GeV > 35)+(tau_numTrack_0)-1;
    fakeSF = 1;
    if(sample == "data"){
      tauorigin = "data";
    }else if(nTaus_OR_Pt25>=1){
      if(tau_truthType_0 == 10) tauorigin = sample + "_real";
      else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)) tauorigin = sample + "_lep";
      else
        switch (tau_truthJetFlavour_0){
          case 5:
            tauorigin = sample + "_b";
            fakeSF = fakeSFs[SFbin][0];
            break;
          case 4:
            tauorigin = sample + "_c";
            fakeSF = fakeSFs[SFbin][1];
            break;
          case 21:
            tauorigin = sample + "_g";
            fakeSF = fakeSFs[SFbin][2];
            break;
          default:
            tauorigin = sample + "_j";
            fakeSF = fakeSFs[SFbin][3];
        }
    }

    if(dumptruth) dumpTruth();

    for(iter=ifregions.begin(); iter!=ifregions.end(); iter++)
    {
      if(iter->second == 1) {
        if(writetree) outputtree[iter->first]->Fill();
        if(dohist) {
          //weight *= fakeSF;
          if(iter->first.Contains("tau")) fill_tau(iter->first,tau_numTrack_0,tauorigin,tau_pt_0/GeV > 35);
            else fill_notau(iter->first,sample);
        }
//      outputtree[iter->first]->AutoSave();
      }
    }
    neutrino_pt  -> clear();
    neutrino_eta -> clear();
    neutrino_phi -> clear();
    neutrino_m   -> clear();
  }

  if(dumptruth){
    if(TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) filetruth[0].close();
    else
      for (int i = 0; i < 6; ++i)
      {
        if(TString(inputtree->GetName()).Contains("reg1l1tau1b3j")) filetruth[i].close();
        else filetruth[i].close();
      }
  }
  if(writetree) {
    outputtreefile->cd();
    map<TString, TTree*>::iterator iter;
    for (iter = outputtree.begin(); iter!=outputtree.end(); ++iter)
      iter->second->Write(iter->first,TObject::kWriteDelete);
  }

}

void nominal::plot(){
  tau_plots->write();
  tau_plots->clearhist();
}

void nominal::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {
    TList *listforfit = (TList*) gM->GetObjectFit();
    if (!listforfit)
    {
      printf("list isnt found\n");
      exit(1);
    }
    enum lorentzv{tau1,tau2,bj,cj,lep};
  
    TLorentzVector vectors[5];
    TLorentzVector neutrino[3];
    for( int i = 0; i<5 ; ++i) {
      if (listforfit->At(i))
      {
        vectors[i] = *((TLorentzVector*)listforfit->At(i));
      }else{
        printf("i-th parameter is not found\n");
        exit(1);
      }
    }
    double met[3];
    if (listforfit->At(5)) {
      met[0] = ((TVector3*)listforfit->At(5))->x();
      met[1] = ((TVector3*)listforfit->At(5))->y();
      met[2] = ((TVector3*)listforfit->At(5))->z();
    }
    else { printf("met parameter is not found\n"); exit(1); }

    neutrino[0].SetPtEtaPhiM(par[0]*vectors[tau1].Pt(),vectors[tau1].Eta(),vectors[tau1].Phi(),vectors[lep].Pt()==0?par[2]:0);
    neutrino[1].SetPtEtaPhiM(par[1]*vectors[tau2].Pt(),vectors[tau2].Eta(),vectors[tau2].Phi(),0);
    Float_t Hmass = (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]).M();
    Float_t met_resol = 13100+0.50*sqrt(met[2]*1000);
    Double_t chisq = 1e10;

    if(vectors[lep].Pt()!=0){
      neutrino[2].SetPtEtaPhiM(par[2],par[3],par[4],0);
  
      TLorentzVector t1 = neutrino[2]+vectors[lep]+vectors[bj];
  
      Float_t t2mass= (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]+vectors[cj]).M();
      Float_t wmass = (vectors[lep] + neutrino[2]).M();
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
      Float_t pConstrain = (vectors[bj].Dot(vectors[lep])/100) + (vectors[bj].Dot(neutrino[2])/100);
      chisq =  pow((wmass-81000)/10000,2) + pow((t1.M()-172500)/25000,2) +pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2) + pow((Hmass-125000)/10000,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
    }else{
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
      chisq = pow((Hmass-125000)/10000,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
    }
    f = chisq;
}

void nominal::dumpTruth(){
  TLorentzVector wchild[2],fcncjet;
  ofstream *truthfile = &(filetruth[min(nJets_OR_T-(nTaus_OR_Pt25==1?3:2),2)]);
  if(debug) printf("truth particles: %d\n", m_truth_pdgId->size());
  bool foundcjet = 0;
  bool foundw = 0;
  for (int itruth = 0; itruth < m_truth_pdgId->size(); ++itruth)
  {
    if(debug) printf("pdg: %d,\tbarcode: %d\n", m_truth_pdgId->at(itruth), m_truth_barcode->at(itruth));
    if(abs(m_truth_pdgId->at(itruth)) == 24 && m_truth_m->at(itruth)/GeV > 70 && m_truth_m->at(itruth)/GeV < 90 ){
      if (m_truth_children->at(itruth).size()!=2) continue;
      for (int ichild = 0; ichild < 2; ++ichild)
      {
        int childbarcode = m_truth_children->at(itruth)[ichild];
        if(debug) printf("child barcode %d\n", childbarcode);
        int childid = 0;
        for (int i = 0; i < m_truth_barcode->size(); ++i)
        {
          if(m_truth_barcode->at(i) == childbarcode) {
            childid = i;
            break;
          }
        }
        if(debug) printf("child pdg: %d\n",m_truth_pdgId->at(childid));
        if(abs(m_truth_pdgId->at(childid))>4 || abs(m_truth_pdgId->at(childid))<1) {
        }
        if(debug) printf("childid: %d\n", childid);
        foundw = 1;
        wchild[ichild].SetPtEtaPhiM(m_truth_pt->at(childid),m_truth_eta->at(childid),m_truth_phi->at(childid),m_truth_m->at(childid));
      }
    }else if((abs(m_truth_pdgId->at(itruth))==2 || abs(m_truth_pdgId->at(itruth))==4)){
        foundcjet = 1;
        fcncjet.SetPtEtaPhiM(m_truth_pt->at(itruth),m_truth_eta->at(itruth),m_truth_phi->at(itruth),m_truth_m->at(itruth));
    }
  }
  if(debug && !foundw) printf("coundn't find truth w jets\n");
  if(debug && !foundcjet) printf("coundn't find truth fcnc jets\n");
  if(foundw&&foundcjet){
    int loopmax = min(nJets_OR_T,(nTaus_OR_Pt25==1?3:2)+2)-1;
    for (int i = 0; i < loopmax; ++i)
    {
      if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] < btag70wt) {
        TLorentzVector tmpv;
        tmpv.SetPtEtaPhiE((*m_jet_pt)[selected_jets_T->at(i)],(*m_jet_eta)[selected_jets_T->at(i)],(*m_jet_phi)[selected_jets_T->at(i)],(*m_jet_E)[selected_jets_T->at(i)]);
        (*truthfile)<<tmpv.Pt()<<" "<<tmpv.Eta()<<" "<<tmpv.Phi()<<" "<<tmpv.E();
        bool wmatched = 0;
        if(tmpv.DeltaR(fcncjet)<0.4) {
          (*truthfile)<<" 1 0\n";
          continue;
        }
        else{
          for (int ichild = 0; ichild < 2; ++ichild)
          {
            if(tmpv.DeltaR(wchild[ichild])<0.4) {
              (*truthfile)<<" 0 1\n";
              wmatched = 1;
            }
            break;
          }
        }
        if(!wmatched) (*truthfile)<<" 0 0\n";
      }else{
        loopmax++;
      }
    }
    for (int i = 0; i < nJets_OR_T; ++i)
    {
      if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] > btag70wt) {
        (*truthfile)<<"pool:\t"<<(*m_jet_pt)[selected_jets_T->at(i)]<<" "<<(*m_jet_eta)[selected_jets_T->at(i)]<<" "<<(*m_jet_phi)[selected_jets_T->at(i)]<<" "<<(*m_jet_E)[selected_jets_T->at(i)]<<" 0 0\n";
      }
    }
    if(nTaus_OR_Pt25 >= 2){
      for (int i = 0; i < 2; ++i) taus_v[i].SetPtEtaPhiE((*m_tau_pt)[i],(*m_tau_eta)[i],(*m_tau_phi)[i],(*m_tau_E)[i]);
      if (fabs(lep_ID_0)==11) lep_v.SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
      else lep_v.SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
      bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
    }
    else{
      if (fabs(lep_ID_0)==11) taus_v[0].SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
      else taus_v[0].SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
      taus_v[1].SetPtEtaPhiE((*m_tau_pt)[0],(*m_tau_eta)[0],(*m_tau_phi)[0],(*m_tau_E)[0]);
    }
    for (int i = 0; i < 2; ++i)
    {
      (*truthfile)<<"taus:\t"<<taus_v[i].Pt()<<" "<<taus_v[i].Eta()<<" "<<taus_v[i].Phi()<<" "<<taus_v[i].E()<<" 0 0\n";
    }
    if (nTaus_OR_Pt25>=2)
    {
      (*truthfile)<<"leptons:\t"<<lep_v.Pt()<<" "<<lep_v.Eta()<<" "<<lep_v.Phi()<<" "<<lep_v.E()<<" 0 0\n";
    }
    (*truthfile)<<endl;
  }
}
