#define nominal_cxx
#include "nominal.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdio.h>
#include <stdlib.h>
TMinuit* gM = 0;
nominal::nominal(){
  //init histSaver here:
  tau_plots = new histSaver();
  tau_plots->set_weight(&weight);
  tau_plots->debug = 0;
  debug = 0;
  tau_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
  tau_plots->add(10,25.,125.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  tau_plots->add(10,25.,125.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  tau_plots->add(120,50.,250.,"m_{t,SM}","t1mass",&t1_mass,true,"GeV");
  tau_plots->add(120,50.,250.,"m_{#tau,#tau}","tautaumass",&higgs_mass,true,"GeV");
  tau_plots->add(120,50.,250.,"m_{W}","wmass",&Wmass,true,"GeV");
  tau_plots->add(120,50.,250.,"m_{t,FCNC}","t2mass",&t2_mass,true,"GeV");
  
  TString regions[] = {"reg1l2tau1bnj","reg1l1tau1b2j","reg1l1tau1b3j"};
  TString nprong[] = {"1prong","3prong"};

  for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 2; ++k)
    {
      for (int i = 0; i < 4; ++i)
      {
        for (int iptbin = 0; iptbin < 2; ++iptbin)
        {
          if(debug) printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
          tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
          tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
        }
      }
    }

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
}

nominal::~nominal(){
  deletepointer(tau_plots);
  deletepointer(gM);
}

void nominal::fill_tau(TString region, int nprong, TString sample, int iptbin){
  for (int i = 0; i < 4; ++i){
    if(tau_MV2c10_0>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[i]).Data(), sample.Data());
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[i]);
    }else{
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[i]);
    }
  }
}


void nominal::init_sample(TString sample, TString sampletitle){
  outputtreefile = new TFile(sample + ".root","update");
  if (outputtreefile->Get("reg1l1tau1b2j"))
  {
    outputtree["reg1l1tau1b2j"] = (TTree*)(outputtreefile->Get("reg1l1tau1b2j"));
    outputtree["reg1l1tau1b3j"] = (TTree*)(outputtreefile->Get("reg1l1tau1b3j"));
    outputtree["reg1l2tau1bnj"] = (TTree*)(outputtreefile->Get("reg1l2tau1bnj"));
  }else{
    outputtree["reg1l1tau1b2j"] = 0;
    outputtree["reg1l1tau1b3j"] = 0;
    outputtree["reg1l2tau1bnj"] = 0;
  }

  if(sample.Contains("ttbar")) sample = "ttbar";

  if (sample.Contains("data"))
  {
    tau_plots->init_sample("data","data","data",kBlack);
    
    initdata = 1;
  }else{
    tau_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
    tau_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
    tau_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
    tau_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
    tau_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
    tau_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
    tau_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
  }
}
void nominal::finalise_sample(){
  outputtreefile->cd();
  map<TString, TTree*>::iterator iter;
  for (iter = outputtree.begin(); iter!=outputtree.end(); ++iter)
    iter->second->Write();
  outputtreefile->Close();
  deletepointer(outputtreefile);
}
void nominal::Loop(TTree *inputtree, TString samplename)
{
  Init(inputtree);
  outputtreefile->cd();
  if (!outputtree["reg1l1tau1b2j"])
  {
    outputtree["reg1l1tau1b2j"] = new TTree("reg1l1tau1b2j","reg1l1tau1b2j");
    definetree(outputtree["reg1l1tau1b2j"]);
    outputtree["reg1l1tau1b3j"] = new TTree("reg1l1tau1b3j","reg1l1tau1b3j");
    definetree(outputtree["reg1l1tau1b3j"]);
    outputtree["reg1l2tau1bnj"] = new TTree("reg1l2tau1bnj","reg1l2tau1bnj");
    definetree(outputtree["reg1l2tau1bnj"]);
  }
  map<TString, TTree*>::iterator iter;
  for (iter = outputtree.begin(); iter!=outputtree.end(); ++iter)
  {
    iter->second->Branch("t1mass",&t1_mass);
    iter->second->Branch("tautaumass",&higgs_mass);
    iter->second->Branch("wmass",&Wmass);
    iter->second->Branch("t2mass",&t2_mass);
  }

  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  TString sample = samplename;
  if(samplename.Contains("ttbar")) sample = "ttbar";

  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);


  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    nb = fChain->GetEntry(jentry);
    if((jentry%100000==0))
      std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<RunNumber<<" ismc "<<mc_channel_number<<std::endl;
//===============================pre-selections===============================

    bool basic_selection = passEventCleaning;

    if(samplename.Contains("ttbargamma")) { basic_selection &=m_hasMEphoton_DRgt02_nonhad;}
    if(samplename.Contains("ttbarnohad")) { basic_selection &=!m_hasMEphoton_DRgt02_nonhad;}

    basic_selection &= 
      (RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
      (RunYear==2015 && (HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1))||
      (RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 ))||
      (RunYear>=2016 && (HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))
      &&(tau_numTrack_0 == 1 || tau_numTrack_0 == 3); // assuming triggers for 2017 is same for 2016 

    if (!basic_selection) continue;

    bool trig_match = (lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
    bool SLtrig_match = 
      ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
    	(RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 )))&&lep_isTrigMatch_0;

    weight = mc_channel_number>0?mc_norm*mcWeightOrg*pileupEventWeight_090*(V7NTUP?bTagSF_weight_MV2c10_FixedCutBEff_70:bTagSF_weight_MV2c10_Continuous)*JVT_EventWeight*SherpaNJetWeight*((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0; 
//===============================define regions===============================
    map<TString, bool> ifregions;
    ifregions["reg1l1tau1b2j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T==3 && nTaus_OR_Pt25==1;
    ifregions["reg1l1tau1b3j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T>4 && nTaus_OR_Pt25==1;
    ifregions["reg1l2tau1bnj"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T>=2 && nTaus_OR_Pt25>=2;

    map<TString, bool>::iterator iter;

    bool triggered = 0;
    
    for(iter=ifregions.begin(); iter!=ifregions.end(); iter++)
      if(iter->second) {
        triggered = 1;
      }

    if(!triggered) continue;

//===============================find leading b,non b jets===============================
    leading_b = -1;
    leading_ljet = -1;
    pt_b = 0;
    pt_ljet = 0;
    bool reloop = 1;
    for (int i = 0; i < nJets_OR_T; ++i)
    {
      if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] > 0.83 && leading_b == -1) {
        leading_b = selected_jets_T->at(i);
        pt_b = (*m_jet_pt)[selected_jets_T->at(i)];
      }else if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] < 0.83 && reloop == 1){
        leading_ljet = selected_jets_T->at(i);
        cjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_ljet],(*m_jet_eta)[leading_ljet],(*m_jet_phi)[leading_ljet],(*m_jet_E)[leading_ljet]);
        if((cjet_v + taus_v[0] + taus_v[1]).M() < 175) reloop = 0;
        pt_ljet = (*m_jet_pt)[selected_jets_T->at(i)];
      }
      if(reloop == 0 && leading_b != -1) break;
    }


    if(ifregions["reg1l2tau1bnj"]){
      for (int i = 0; i < 2; ++i) taus_v[i].SetPtEtaPhiE((*m_tau_pt)[i],(*m_tau_eta)[i],(*m_tau_phi)[i],(*m_tau_E)[i]);
      if (abs(lep_ID_0)==11) lep_v.SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
      else lep_v.SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
      bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
    }
    else{
      if (abs(lep_ID_0)==11) taus_v[0].SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
      else taus_v[0].SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
      taus_v[1].SetPtEtaPhiE((*m_tau_pt)[0],(*m_tau_eta)[0],(*m_tau_phi)[0],(*m_tau_E)[0]);
      lep_v.SetPtEtaPhiE(0,0,0,0);
      bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
      int cjetn = findcjet();
      if(debug) {
        printf("Wmass: %f, t1_mass: %f\n", Wmass, t1_mass);
      }
      cjet_v.SetPtEtaPhiE((*m_jet_pt)[cjetn],(*m_jet_eta)[cjetn],(*m_jet_phi)[cjetn],(*m_jet_E)[cjetn]);
    }
    mets.SetXYZ(met_met*cos(met_phi), met_met*sin(met_phi), MET_RefFinal_sumet);

//===============================fit neutrino===============================
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
    if (nTaus_OR_Pt25>=2)
    {
      TLorentzVector wv_v   ; wv_v   .SetPtEtaPhiM(val[2],val[3],val[4],0);
      t1_mass     = ( lep_v + wv_v + bjet_v ) .M();
      Wmass      = ( lep_v + wv_v ).M();
    }
      t2_mass     = ( tauv2_v + taus_v[0] + tauv1_v + taus_v[1] + cjet_v) .M();
      higgs_mass  = ( tauv2_v + taus_v[0] + tauv1_v + taus_v[1] ) .M();


//===============================fill histograms===============================
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
      if(iter->second == 1) {
        fill_tau(iter->first,tau_numTrack_0,tauorigin,tau_pt_0/GeV > 35);
        outputtree[iter->first]->Fill();
      }
    }
  }
}

void nominal::plot(){
  tau_plots->write();
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
      Float_t Wmass = (vectors[lep] + neutrino[2]).M();
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
      Float_t pConstrain = (vectors[bj].Dot(vectors[lep])/100) + (vectors[bj].Dot(neutrino[2])/100);
      chisq =  pow((Wmass-81000)/10000,2) + pow((t1.M()-172500)/25000,2) +pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2) + pow((Hmass-125000)/10000,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
    }else{
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
      chisq = pow((Hmass-125000)/10000,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
    }
    f = chisq;
}


int nominal::findcjet(){
  TLorentzVector ljet[3];
  int nljet[3];
  int j = 0;
  double m_w = 81000;
  int nlightj = nJets_OR_T - nJets_OR_T_MV2c10_70;
  for (int i = 0; i < nJets_OR_T; ++i)
    if ((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] < 0.83){
      nljet[j] = selected_jets_T->at(i);
      ljet[j].SetPtEtaPhiE((*m_jet_pt)[selected_jets_T->at(i)],(*m_jet_eta)[selected_jets_T->at(i)],(*m_jet_phi)[selected_jets_T->at(i)],(*m_jet_E)[selected_jets_T->at(i)]);
      ++j;
    }
  if (nlightj == 2) {
    t1_mass = 0;
    Wmass = 0;
    return ljet[0].DeltaR(taus_v[0] + taus_v[0]) + ljet[1].DeltaR(bjet_v) < ljet[1].DeltaR(taus_v[0] + taus_v[0]) + ljet[0].DeltaR(bjet_v) ? nljet[0]:nljet[1];
  }else{
    if(debug) {
      printv(ljet[0]);
      printv(ljet[1]);
      printv(ljet[2]);
      printf("wm1: %f, wm2: %f, wm3: %f\n", (ljet[0] + ljet[1]).M(), (ljet[0] + ljet[2]).M(), (ljet[2] + ljet[1]).M());
    }
    if( abs((ljet[0] + ljet[1]).M() - m_w) > abs((ljet[0] + ljet[2]).M() - m_w) )
      if(abs((ljet[0] + ljet[2]).M() - m_w) > abs((ljet[1] + ljet[2]).M() - m_w)) 
      {
        t1_mass     = ( ljet[1] + ljet[2] + bjet_v ) .M();
        Wmass      = ( ljet[1] + ljet[2] ).M();
        return nljet[0];
      }
      else{
        t1_mass     = ( ljet[0] + ljet[2] + bjet_v ) .M();
        Wmass      = ( ljet[0] + ljet[2] ).M();
        return nljet[1];
      }
    else if(abs((ljet[0] + ljet[1]).M() - m_w) > abs((ljet[1] + ljet[2]).M() - m_w)) 
      {
        t1_mass     = ( ljet[1] + ljet[2] + bjet_v ) .M();
        Wmass      = ( ljet[1] + ljet[2] ).M();
        return nljet[0];
      }
      else{
        t1_mass     = ( ljet[0] + ljet[1] + bjet_v ) .M();
        Wmass      = ( ljet[0] + ljet[1] ).M();
        return nljet[2];
      }
  }
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

void nominal::printv(TLorentzVector v){
  printf("Pt : %f, Eta: %f, Phi: %f, E: %f, m: %f\n", v.Pt(),v.Eta(),v.Phi(),v.E(),v.M());
}

void nominal::definetree(TTree* tree){
  tree->Branch("eventNumber",&eventNumber,"eventNumber/l");
  tree->Branch("runNumber",&runNumber,"runNumber/i");
  tree->Branch("randomRunNumber",&randomRunNumber,"randomRunNumber/i");
  tree->Branch("mcChannelNumber",&mcChannelNumber,"mcChannelNumber/i");
  tree->Branch("mu",&mu,"mu/F");
  tree->Branch("backgroundFlags",&backgroundFlags,"backgroundFlags/i");
  tree->Branch("hasBadMuon",&hasBadMuon,"hasBadMuon/i");
  tree->Branch("tau_pt",&tau_pt,"vector<float>");
  tree->Branch("tau_eta",&tau_eta,"vector<float>");
  tree->Branch("tau_phi",&tau_phi,"vector<float>");
  tree->Branch("tau_charge",&tau_charge,"vector<float>");
  tree->Branch("met_met",&met_met,"met_met/F");
  tree->Branch("met_phi",&met_phi,"met_phi/F");
  tree->Branch("triggers",&triggers,"triggers/I");
  tree->Branch("loose",&loose,"loose/I");
  tree->Branch("HLT_mu40",&HLT_mu40,"HLT_mu40/B");
  tree->Branch("HLT_mu26_ivarmedium",&HLT_mu26_ivarmedium,"HLT_mu26_ivarmedium/B");
  tree->Branch("HLT_mu26_imedium",&HLT_mu26_imedium,"HLT_mu26_imedium/B");
  tree->Branch("HLT_mu24_ivarmedium",&HLT_mu24_ivarmedium,"HLT_mu24_ivarmedium/B");
  tree->Branch("HLT_mu24_ivarloose",&HLT_mu24_ivarloose,"HLT_mu24_ivarloose/B");
  tree->Branch("HLT_mu24_imedium",&HLT_mu24_imedium,"HLT_mu24_imedium/B");
  tree->Branch("HLT_mu24",&HLT_mu24,"HLT_mu24/B");
  tree->Branch("HLT_mu20_mu8noL1",&HLT_mu20_mu8noL1,"HLT_mu20_mu8noL1/B");
  tree->Branch("HLT_mu20_iloose_L1MU15",&HLT_mu20_iloose_L1MU15,"HLT_mu20_iloose_L1MU15/B");
  tree->Branch("HLT_mu18_mu8noL1",&HLT_mu18_mu8noL1,"HLT_mu18_mu8noL1/B");
  tree->Branch("HLT_mu14_ivarloose_tau25_medium1_tracktwo",&HLT_mu14_ivarloose_tau25_medium1_tracktwo,"HLT_mu14_ivarloose_tau25_medium1_tracktwo/B");
  tree->Branch("HLT_e7_medium_mu24",&HLT_e7_medium_mu24,"HLT_e7_medium_mu24/B");
  tree->Branch("HLT_e17_lhmedium_tau25_medium1_tracktwo",&HLT_e17_lhmedium_tau25_medium1_tracktwo,"HLT_e17_lhmedium_tau25_medium1_tracktwo/B");
  tree->Branch("HLT_e17_lhloose_mu14",&HLT_e17_lhloose_mu14,"HLT_e17_lhloose_mu14/B");
  tree->Branch("HLT_e140_loose",&HLT_e140_loose,"HLT_e140_loose/B");
  tree->Branch("HLT_mu22_mu8noL1",&HLT_mu22_mu8noL1,"HLT_mu22_mu8noL1/B");
  tree->Branch("HLT_2e17_lhvloose_nod0",&HLT_2e17_lhvloose_nod0,"HLT_2e17_lhvloose_nod0/B");
  tree->Branch("HLT_e17_lhloose_2e9_lhloose",&HLT_e17_lhloose_2e9_lhloose,"HLT_e17_lhloose_2e9_lhloose/B");
  tree->Branch("HLT_e17_lhloose_nod0_mu14",&HLT_e17_lhloose_nod0_mu14,"HLT_e17_lhloose_nod0_mu14/B");
  tree->Branch("HLT_mu50",&HLT_mu50,"HLT_mu50/B");
  tree->Branch("HLT_e17_lhloose",&HLT_e17_lhloose,"HLT_e17_lhloose/B");
  tree->Branch("HLT_2e12_lhloose_L12EM10VH",&HLT_2e12_lhloose_L12EM10VH,"HLT_2e12_lhloose_L12EM10VH/B");
  tree->Branch("HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo",&HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo,"HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo/B");
  tree->Branch("HLT_2e12_loose_L12EM10VH",&HLT_2e12_loose_L12EM10VH,"HLT_2e12_loose_L12EM10VH/B");
  tree->Branch("HLT_e140_lhloose_nod0",&HLT_e140_lhloose_nod0,"HLT_e140_lhloose_nod0/B");
  tree->Branch("HLT_e60_medium",&HLT_e60_medium,"HLT_e60_medium/B");
  tree->Branch("HLT_e12_loose",&HLT_e12_loose,"HLT_e12_loose/B");
  tree->Branch("HLT_mu18",&HLT_mu18,"HLT_mu18/B");
  tree->Branch("HLT_e140_lhloose",&HLT_e140_lhloose,"HLT_e140_lhloose/B");
  tree->Branch("HLT_e5_lhloose",&HLT_e5_lhloose,"HLT_e5_lhloose/B");
  tree->Branch("HLT_2e17_lhvloose_nod0_L12EM15VHI",&HLT_2e17_lhvloose_nod0_L12EM15VHI,"HLT_2e17_lhvloose_nod0_L12EM15VHI/B");
  tree->Branch("HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo",&HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo,"HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo/B");
  tree->Branch("HLT_e24_lhmedium_nod0_L1EM20VH",&HLT_e24_lhmedium_nod0_L1EM20VH,"HLT_e24_lhmedium_nod0_L1EM20VH/B");
  tree->Branch("HLT_2e24_lhvloose_nod0",&HLT_2e24_lhvloose_nod0,"HLT_2e24_lhvloose_nod0/B");
  tree->Branch("HLT_e24_tight_iloose",&HLT_e24_tight_iloose,"HLT_e24_tight_iloose/B");
  tree->Branch("HLT_e120_lhloose",&HLT_e120_lhloose,"HLT_e120_lhloose/B");
  tree->Branch("HLT_2e12_lhvloose_nod0_L12EM10VH",&HLT_2e12_lhvloose_nod0_L12EM10VH,"HLT_2e12_lhvloose_nod0_L12EM10VH/B");
  tree->Branch("HLT_2mu10",&HLT_2mu10,"HLT_2mu10/B");
  tree->Branch("HLT_e12_lhloose",&HLT_e12_lhloose,"HLT_e12_lhloose/B");
  tree->Branch("HLT_2mu14",&HLT_2mu14,"HLT_2mu14/B");
  tree->Branch("HLT_e17_loose",&HLT_e17_loose,"HLT_e17_loose/B");
  tree->Branch("HLT_e17_loose_mu14",&HLT_e17_loose_mu14,"HLT_e17_loose_mu14/B");
  tree->Branch("HLT_e24_lhmedium_L1EM20VH",&HLT_e24_lhmedium_L1EM20VH,"HLT_e24_lhmedium_L1EM20VH/B");
  tree->Branch("HLT_mu24_iloose",&HLT_mu24_iloose,"HLT_mu24_iloose/B");
  tree->Branch("HLT_e7_lhmedium_mu24",&HLT_e7_lhmedium_mu24,"HLT_e7_lhmedium_mu24/B");
  tree->Branch("HLT_e60_lhmedium",&HLT_e60_lhmedium,"HLT_e60_lhmedium/B");
  tree->Branch("HLT_e24_lhmedium_iloose_L1EM18VH",&HLT_e24_lhmedium_iloose_L1EM18VH,"HLT_e24_lhmedium_iloose_L1EM18VH/B");
  tree->Branch("HLT_e24_lhmedium_L1EM18VH",&HLT_e24_lhmedium_L1EM18VH,"HLT_e24_lhmedium_L1EM18VH/B");
  tree->Branch("HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1",&HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1,"HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1/B");
  tree->Branch("HLT_e24_lhtight_iloose",&HLT_e24_lhtight_iloose,"HLT_e24_lhtight_iloose/B");
  tree->Branch("HLT_mu14",&HLT_mu14,"HLT_mu14/B");
  tree->Branch("HLT_mu10",&HLT_mu10,"HLT_mu10/B");
  tree->Branch("HLT_e24_lhtight_iloose_L1EM20VH",&HLT_e24_lhtight_iloose_L1EM20VH,"HLT_e24_lhtight_iloose_L1EM20VH/B");
  tree->Branch("HLT_e24_lhtight_ivarloose",&HLT_e24_lhtight_ivarloose,"HLT_e24_lhtight_ivarloose/B");
  tree->Branch("HLT_e60_lhmedium_nod0",&HLT_e60_lhmedium_nod0,"HLT_e60_lhmedium_nod0/B");
  tree->Branch("HLT_e24_lhtight_nod0_ivarloose",&HLT_e24_lhtight_nod0_ivarloose,"HLT_e24_lhtight_nod0_ivarloose/B");
  tree->Branch("HLT_mu14_tau25_medium1_tracktwo",&HLT_mu14_tau25_medium1_tracktwo,"HLT_mu14_tau25_medium1_tracktwo/B");
  tree->Branch("HLT_e24_medium_L1EM20VHI_mu8noL1",&HLT_e24_medium_L1EM20VHI_mu8noL1,"HLT_e24_medium_L1EM20VHI_mu8noL1/B");
  tree->Branch("HLT_e24_tight_iloose_L1EM20VH",&HLT_e24_tight_iloose_L1EM20VH,"HLT_e24_tight_iloose_L1EM20VH/B");
  tree->Branch("HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1",&HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1,"HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1/B");
  tree->Branch("HLT_e26_lhtight_iloose",&HLT_e26_lhtight_iloose,"HLT_e26_lhtight_iloose/B");
  tree->Branch("HLT_e26_lhtight_nod0_ivarloose",&HLT_e26_lhtight_nod0_ivarloose,"HLT_e26_lhtight_nod0_ivarloose/B");
  tree->Branch("HLT_2e15_lhvloose_nod0_L12EM13VH",&HLT_2e15_lhvloose_nod0_L12EM13VH,"HLT_2e15_lhvloose_nod0_L12EM13VH/B");
  tree->Branch("HLT_e26_tight_iloose",&HLT_e26_tight_iloose,"HLT_e26_tight_iloose/B");
  tree->Branch("HLT_e7_lhmedium_nod0_mu24",&HLT_e7_lhmedium_nod0_mu24,"HLT_e7_lhmedium_nod0_mu24/B");
  tree->Branch("HLT_e5_loose",&HLT_e5_loose,"HLT_e5_loose/B");
  tree->Branch("HLT_e300_etcut",&HLT_e300_etcut,"HLT_e300_etcut/B");
  tree->Branch("mcWeightOrg",&mcWeightOrg,"mcWeightOrg/D");
  tree->Branch("mcEventWeights",&mcEventWeights,"vector<float>");
  tree->Branch("pileupEventWeight_090",&pileupEventWeight_090,"pileupEventWeight_090/D");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70",&bTagSF_weight_MV2c10_FixedCutBEff_70,"bTagSF_weight_MV2c10_FixedCutBEff_70/D");
  tree->Branch("MV2c10_60_EventWeight",&MV2c10_60_EventWeight,"MV2c10_60_EventWeight/D");
  tree->Branch("MV2c10_70_EventWeight",&MV2c10_70_EventWeight,"MV2c10_70_EventWeight/D");
  tree->Branch("MV2c10_77_EventWeight",&MV2c10_77_EventWeight,"MV2c10_77_EventWeight/D");
  tree->Branch("MV2c10_85_EventWeight",&MV2c10_85_EventWeight,"MV2c10_85_EventWeight/D");
  tree->Branch("MV2c10_Continuous_EventWeight",&MV2c10_Continuous_EventWeight,"MV2c10_Continuous_EventWeight/D");
  tree->Branch("JVT_EventWeight",&JVT_EventWeight,"JVT_EventWeight/D");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70",&bTagSF_weight_DL1_FixedCutBEff_70,"bTagSF_weight_DL1_FixedCutBEff_70/D");
  tree->Branch("DL1_60_EventWeight",&DL1_60_EventWeight,"DL1_60_EventWeight/D");
  tree->Branch("DL1_70_EventWeight",&DL1_70_EventWeight,"DL1_70_EventWeight/D");
  tree->Branch("DL1_77_EventWeight",&DL1_77_EventWeight,"DL1_77_EventWeight/D");
  tree->Branch("DL1_85_EventWeight",&DL1_85_EventWeight,"DL1_85_EventWeight/D");
  tree->Branch("DL1_Continuous_EventWeight",&DL1_Continuous_EventWeight,"DL1_Continuous_EventWeight/D");
  tree->Branch("pileupEventWeight_UP",&pileupEventWeight_UP,"pileupEventWeight_UP/D");
  tree->Branch("pileupEventWeight_DOWN",&pileupEventWeight_DOWN,"pileupEventWeight_DOWN/D");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up",&bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up,"bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up/F");
  tree->Branch("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down",&bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down,"bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B0_up",&bTagSF_weight_DL1_FixedCutBEff_70_B0_up,"bTagSF_weight_DL1_FixedCutBEff_70_B0_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B0_down",&bTagSF_weight_DL1_FixedCutBEff_70_B0_down,"bTagSF_weight_DL1_FixedCutBEff_70_B0_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B1_up",&bTagSF_weight_DL1_FixedCutBEff_70_B1_up,"bTagSF_weight_DL1_FixedCutBEff_70_B1_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B1_down",&bTagSF_weight_DL1_FixedCutBEff_70_B1_down,"bTagSF_weight_DL1_FixedCutBEff_70_B1_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B2_up",&bTagSF_weight_DL1_FixedCutBEff_70_B2_up,"bTagSF_weight_DL1_FixedCutBEff_70_B2_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B2_down",&bTagSF_weight_DL1_FixedCutBEff_70_B2_down,"bTagSF_weight_DL1_FixedCutBEff_70_B2_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B3_up",&bTagSF_weight_DL1_FixedCutBEff_70_B3_up,"bTagSF_weight_DL1_FixedCutBEff_70_B3_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B3_down",&bTagSF_weight_DL1_FixedCutBEff_70_B3_down,"bTagSF_weight_DL1_FixedCutBEff_70_B3_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B4_up",&bTagSF_weight_DL1_FixedCutBEff_70_B4_up,"bTagSF_weight_DL1_FixedCutBEff_70_B4_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B4_down",&bTagSF_weight_DL1_FixedCutBEff_70_B4_down,"bTagSF_weight_DL1_FixedCutBEff_70_B4_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B5_up",&bTagSF_weight_DL1_FixedCutBEff_70_B5_up,"bTagSF_weight_DL1_FixedCutBEff_70_B5_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B5_down",&bTagSF_weight_DL1_FixedCutBEff_70_B5_down,"bTagSF_weight_DL1_FixedCutBEff_70_B5_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B6_up",&bTagSF_weight_DL1_FixedCutBEff_70_B6_up,"bTagSF_weight_DL1_FixedCutBEff_70_B6_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B6_down",&bTagSF_weight_DL1_FixedCutBEff_70_B6_down,"bTagSF_weight_DL1_FixedCutBEff_70_B6_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B7_up",&bTagSF_weight_DL1_FixedCutBEff_70_B7_up,"bTagSF_weight_DL1_FixedCutBEff_70_B7_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B7_down",&bTagSF_weight_DL1_FixedCutBEff_70_B7_down,"bTagSF_weight_DL1_FixedCutBEff_70_B7_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B8_up",&bTagSF_weight_DL1_FixedCutBEff_70_B8_up,"bTagSF_weight_DL1_FixedCutBEff_70_B8_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_B8_down",&bTagSF_weight_DL1_FixedCutBEff_70_B8_down,"bTagSF_weight_DL1_FixedCutBEff_70_B8_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_C0_up",&bTagSF_weight_DL1_FixedCutBEff_70_C0_up,"bTagSF_weight_DL1_FixedCutBEff_70_C0_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_C0_down",&bTagSF_weight_DL1_FixedCutBEff_70_C0_down,"bTagSF_weight_DL1_FixedCutBEff_70_C0_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_C1_up",&bTagSF_weight_DL1_FixedCutBEff_70_C1_up,"bTagSF_weight_DL1_FixedCutBEff_70_C1_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_C1_down",&bTagSF_weight_DL1_FixedCutBEff_70_C1_down,"bTagSF_weight_DL1_FixedCutBEff_70_C1_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_C2_up",&bTagSF_weight_DL1_FixedCutBEff_70_C2_up,"bTagSF_weight_DL1_FixedCutBEff_70_C2_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_C2_down",&bTagSF_weight_DL1_FixedCutBEff_70_C2_down,"bTagSF_weight_DL1_FixedCutBEff_70_C2_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light0_up",&bTagSF_weight_DL1_FixedCutBEff_70_Light0_up,"bTagSF_weight_DL1_FixedCutBEff_70_Light0_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light0_down",&bTagSF_weight_DL1_FixedCutBEff_70_Light0_down,"bTagSF_weight_DL1_FixedCutBEff_70_Light0_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light1_up",&bTagSF_weight_DL1_FixedCutBEff_70_Light1_up,"bTagSF_weight_DL1_FixedCutBEff_70_Light1_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light1_down",&bTagSF_weight_DL1_FixedCutBEff_70_Light1_down,"bTagSF_weight_DL1_FixedCutBEff_70_Light1_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light2_up",&bTagSF_weight_DL1_FixedCutBEff_70_Light2_up,"bTagSF_weight_DL1_FixedCutBEff_70_Light2_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light2_down",&bTagSF_weight_DL1_FixedCutBEff_70_Light2_down,"bTagSF_weight_DL1_FixedCutBEff_70_Light2_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light3_up",&bTagSF_weight_DL1_FixedCutBEff_70_Light3_up,"bTagSF_weight_DL1_FixedCutBEff_70_Light3_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_Light3_down",&bTagSF_weight_DL1_FixedCutBEff_70_Light3_down,"bTagSF_weight_DL1_FixedCutBEff_70_Light3_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up",&bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up,"bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down",&bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down,"bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up",&bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up,"bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up/F");
  tree->Branch("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down",&bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down,"bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down/F");
  tree->Branch("JVT_EventWeight_UP",&JVT_EventWeight_UP,"JVT_EventWeight_UP/D");
  tree->Branch("JVT_EventWeight_DOWN",&JVT_EventWeight_DOWN,"JVT_EventWeight_DOWN/D");
  tree->Branch("m_truth_m",&m_truth_m,"vector<float>");
  tree->Branch("m_truth_pt",&m_truth_pt,"vector<float>");
  tree->Branch("m_truth_eta",&m_truth_eta,"vector<float>");
  tree->Branch("m_truth_phi",&m_truth_phi,"vector<float>");
  tree->Branch("m_truth_e",&m_truth_e,"vector<float>");
  tree->Branch("m_truth_pdgId",&m_truth_pdgId,"vector<int>");
  tree->Branch("m_truth_status",&m_truth_status,"vector<int>");
  tree->Branch("m_truth_barcode",&m_truth_barcode,"vector<int>");
  tree->Branch("m_truth_parents",&m_truth_parents,"vector<vector<int> >");
  tree->Branch("m_truth_children",&m_truth_children,"vector<vector<int> >");
  tree->Branch("m_mcevt_pdf_X1",&m_mcevt_pdf_X1,"vector<float>");
  tree->Branch("m_mcevt_pdf_X2",&m_mcevt_pdf_X2,"vector<float>");
  tree->Branch("m_mcevt_pdf_PDGID1",&m_mcevt_pdf_PDGID1,"vector<int>");
  tree->Branch("m_mcevt_pdf_PDGID2",&m_mcevt_pdf_PDGID2,"vector<int>");
  tree->Branch("m_mcevt_pdf_Q",&m_mcevt_pdf_Q,"vector<float>");
  tree->Branch("m_mcevt_pdf_XF1",&m_mcevt_pdf_XF1,"vector<float>");
  tree->Branch("m_mcevt_pdf_XF2",&m_mcevt_pdf_XF2,"vector<float>");
  tree->Branch("EventNumber",&EventNumber,"EventNumber/l");
  tree->Branch("RunNumber",&RunNumber,"RunNumber/i");
  tree->Branch("lbn",&lbn,"lbn/i");
  tree->Branch("bcid",&bcid,"bcid/i");
  tree->Branch("passEventCleaning",&passEventCleaning,"passEventCleaning/O");
  tree->Branch("backgroundFlags",&backgroundFlags,"backgroundFlags/i");
  tree->Branch("m_vxp_x",&m_vxp_x,"m_vxp_x/F");
  tree->Branch("m_vxp_y",&m_vxp_y,"m_vxp_y/F");
  tree->Branch("m_vxp_z",&m_vxp_z,"m_vxp_z/F");
  tree->Branch("SherpaNJetWeight",&SherpaNJetWeight,"SherpaNJetWeight/D");
  tree->Branch("nTruthJets_SherpaRwght",&nTruthJets_SherpaRwght,"nTruthJets_SherpaRwght/D");
  tree->Branch("higgs_pt",&higgs_pt,"higgs_pt/D");
  tree->Branch("higgs_eta",&higgs_eta,"higgs_eta/D");
  tree->Branch("higgs_phi",&higgs_phi,"higgs_phi/D");
  tree->Branch("higgs_E",&higgs_E,"higgs_E/D");
  tree->Branch("higgs_rapidity",&higgs_rapidity,"higgs_rapidity/D");
  tree->Branch("top_pt",&top_pt,"top_pt/D");
  tree->Branch("top_eta",&top_eta,"top_eta/D");
  tree->Branch("top_phi",&top_phi,"top_phi/D");
  tree->Branch("top_E",&top_E,"top_E/D");
  tree->Branch("antitop_pt",&antitop_pt,"antitop_pt/D");
  tree->Branch("antitop_eta",&antitop_eta,"antitop_eta/D");
  tree->Branch("antitop_phi",&antitop_phi,"antitop_phi/D");
  tree->Branch("antitop_E",&antitop_E,"antitop_E/D");
  tree->Branch("RunYear",&RunYear,"RunYear/I");
  tree->Branch("higgsDecayMode",&higgsDecayMode,"higgsDecayMode/I");
  tree->Branch("mc_channel_number",&mc_channel_number,"mc_channel_number/i");
  tree->Branch("mc_isAFII",&mc_isAFII,"mc_isAFII/B");
  tree->Branch("mc_xSection",&mc_xSection,"mc_xSection/D");
  tree->Branch("mc_rawXSection",&mc_rawXSection,"mc_rawXSection/D");
  tree->Branch("mc_kFactor",&mc_kFactor,"mc_kFactor/D");
  tree->Branch("mc_showering",&mc_showering,"mc_showering/I");
  tree->Branch("averageIntPerXing_uncorr",&averageIntPerXing_uncorr,"averageIntPerXing_uncorr/F");
  tree->Branch("averageIntPerXing",&averageIntPerXing,"averageIntPerXing/F");
  tree->Branch("actualIntPerXing",&actualIntPerXing,"actualIntPerXing/F");
  tree->Branch("pileupHash",&pileupHash,"pileupHash/l");
  tree->Branch("m_vxp_n",&m_vxp_n,"m_vxp_n/I");
  tree->Branch("m_vxpu_n",&m_vxpu_n,"m_vxpu_n/I");
  tree->Branch("m_vx_density",&m_vx_density,"m_vx_density/F");
  tree->Branch("m_beam_posz",&m_beam_posz,"m_beam_posz/F");
  tree->Branch("m_beam_sigmaz",&m_beam_sigmaz,"m_beam_sigmaz/F");
  tree->Branch("m_hasMEphoton",&m_hasMEphoton,"m_hasMEphoton/B");
  tree->Branch("m_hasMEphoton_DRgt02_nonhad",&m_hasMEphoton_DRgt02_nonhad,"m_hasMEphoton_DRgt02_nonhad/B");
  tree->Branch("m_MEphoton_e",&m_MEphoton_e,"m_MEphoton_e/F");
  tree->Branch("m_MEphoton_pt",&m_MEphoton_pt,"m_MEphoton_pt/F");
  tree->Branch("m_MEphoton_eta",&m_MEphoton_eta,"m_MEphoton_eta/F");
  tree->Branch("m_MEphoton_phi",&m_MEphoton_phi,"m_MEphoton_phi/F");
  tree->Branch("m_MEphoton_mother_pdgId",&m_MEphoton_mother_pdgId,"m_MEphoton_mother_pdgId/I");
  tree->Branch("m_MEphoton_mother_e",&m_MEphoton_mother_e,"m_MEphoton_mother_e/F");
  tree->Branch("m_MEphoton_mother_pt",&m_MEphoton_mother_pt,"m_MEphoton_mother_pt/F");
  tree->Branch("m_MEphoton_mother_eta",&m_MEphoton_mother_eta,"m_MEphoton_mother_eta/F");
  tree->Branch("m_MEphoton_mother_phi",&m_MEphoton_mother_phi,"m_MEphoton_mother_phi/F");
  tree->Branch("MET_RefFinal_et",&MET_RefFinal_et,"MET_RefFinal_et/F");
  tree->Branch("MET_RefFinal_phi",&MET_RefFinal_phi,"MET_RefFinal_phi/F");
  tree->Branch("MET_RefFinal_sumet",&MET_RefFinal_sumet,"MET_RefFinal_sumet/F");
  tree->Branch("MET_RefFinal_softTrk_et",&MET_RefFinal_softTrk_et,"MET_RefFinal_softTrk_et/F");
  tree->Branch("MET_RefFinal_softTrk_phi",&MET_RefFinal_softTrk_phi,"MET_RefFinal_softTrk_phi/F");
  tree->Branch("MET_RefFinal_softClus_et",&MET_RefFinal_softClus_et,"MET_RefFinal_softClus_et/F");
  tree->Branch("MET_RefFinal_softClus_phi",&MET_RefFinal_softClus_phi,"MET_RefFinal_softClus_phi/F");
  tree->Branch("MET_Truth_px",&MET_Truth_px,"MET_Truth_px/F");
  tree->Branch("MET_Truth_py",&MET_Truth_py,"MET_Truth_py/F");
  tree->Branch("MET_Truth_phi",&MET_Truth_phi,"MET_Truth_phi/F");
  tree->Branch("MET_Truth_sumet",&MET_Truth_sumet,"MET_Truth_sumet/F");
  tree->Branch("vtx_x",&vtx_x,"vector<float>");
  tree->Branch("vtx_y",&vtx_y,"vector<float>");
  tree->Branch("vtx_z",&vtx_z,"vector<float>");
  tree->Branch("vtx_type",&vtx_type,"vector<int>");
  tree->Branch("vtx_numTrk",&vtx_numTrk,"vector<int>");
  tree->Branch("electron_isolationLooseTrackOnly",&electron_isolationLooseTrackOnly,"vector<char>");
  tree->Branch("muon_isolationLooseTrackOnly",&muon_isolationLooseTrackOnly,"vector<char>");
  tree->Branch("electron_isolationLoose",&electron_isolationLoose,"vector<char>");
  tree->Branch("muon_isolationLoose",&muon_isolationLoose,"vector<char>");
  tree->Branch("electron_isolationGradient",&electron_isolationGradient,"vector<char>");
  tree->Branch("muon_isolationGradient",&muon_isolationGradient,"vector<char>");
  tree->Branch("electron_isolationGradientLoose",&electron_isolationGradientLoose,"vector<char>");
  tree->Branch("muon_isolationGradientLoose",&muon_isolationGradientLoose,"vector<char>");
  tree->Branch("electron_isolationFixedCutTightTrackOnly",&electron_isolationFixedCutTightTrackOnly,"vector<char>");
  tree->Branch("muon_isolationFixedCutTightTrackOnly",&muon_isolationFixedCutTightTrackOnly,"vector<char>");
  tree->Branch("electron_isolationFixedCutLoose",&electron_isolationFixedCutLoose,"vector<char>");
  tree->Branch("muon_isolationFixedCutLoose",&muon_isolationFixedCutLoose,"vector<char>");
  tree->Branch("electron_isolationFixedCutTight",&electron_isolationFixedCutTight,"vector<char>");
  tree->Branch("electron_pt",&electron_pt,"vector<float>");
  tree->Branch("electron_eta",&electron_eta,"vector<float>");
  tree->Branch("electron_EtaBE2",&electron_EtaBE2,"vector<float>");
  tree->Branch("electron_phi",&electron_phi,"vector<float>");
  tree->Branch("electron_E",&electron_E,"vector<float>");
  tree->Branch("electron_ID",&electron_ID,"vector<int>");
  tree->Branch("electron_sigd0PV",&electron_sigd0PV,"vector<float>");
  tree->Branch("electron_z0SinTheta",&electron_z0SinTheta,"vector<float>");
  tree->Branch("electron_topoetcone20",&electron_topoetcone20,"vector<float>");
  tree->Branch("electron_topoetcone30",&electron_topoetcone30,"vector<float>");
  tree->Branch("electron_topoetcone40",&electron_topoetcone40,"vector<float>");
  tree->Branch("electron_ptvarcone20",&electron_ptvarcone20,"vector<float>");
  tree->Branch("electron_ptvarcone30",&electron_ptvarcone30,"vector<float>");
  tree->Branch("electron_ptvarcone40",&electron_ptvarcone40,"vector<float>");
  tree->Branch("electron_isLooseLH",&electron_isLooseLH,"vector<char>");
  tree->Branch("electron_isMediumLH",&electron_isMediumLH,"vector<char>");
  tree->Branch("electron_isTightLH",&electron_isTightLH,"vector<char>");
  tree->Branch("electron_sharesTrk",&electron_sharesTrk,"vector<char>");
  tree->Branch("electron_passOR",&electron_passOR,"vector<char>");
  tree->Branch("electron_isQMisID",&electron_isQMisID,"vector<char>");
  tree->Branch("electron_ChargeIDBDTLoose",&electron_ChargeIDBDTLoose,"vector<float>");
  tree->Branch("electron_ChargeIDBDTMedium",&electron_ChargeIDBDTMedium,"vector<float>");
  tree->Branch("electron_ChargeIDBDTTight",&electron_ChargeIDBDTTight,"vector<float>");
  tree->Branch("electron_match_HLT_2e12_lhloose_L12EM10VH",&electron_match_HLT_2e12_lhloose_L12EM10VH,"vector<int>");
  tree->Branch("electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH",&electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH,"vector<int>");
  tree->Branch("electron_match_HLT_2e12_loose_L12EM10VH",&electron_match_HLT_2e12_loose_L12EM10VH,"vector<int>");
  tree->Branch("electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH",&electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH,"vector<int>");
  tree->Branch("electron_match_HLT_2e17_lhvloose_nod0",&electron_match_HLT_2e17_lhvloose_nod0,"vector<int>");
  tree->Branch("electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI",&electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI,"vector<int>");
  tree->Branch("electron_match_HLT_2e24_lhvloose_nod0",&electron_match_HLT_2e24_lhvloose_nod0,"vector<int>");
  tree->Branch("electron_match_HLT_e120_lhloose",&electron_match_HLT_e120_lhloose,"vector<int>");
  tree->Branch("electron_match_HLT_e12_lhloose",&electron_match_HLT_e12_lhloose,"vector<int>");
  tree->Branch("electron_match_HLT_e12_loose",&electron_match_HLT_e12_loose,"vector<int>");
  tree->Branch("electron_match_HLT_e140_lhloose",&electron_match_HLT_e140_lhloose,"vector<int>");
  tree->Branch("electron_match_HLT_e140_lhloose_nod0",&electron_match_HLT_e140_lhloose_nod0,"vector<int>");
  tree->Branch("electron_match_HLT_e140_loose",&electron_match_HLT_e140_loose,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhloose",&electron_match_HLT_e17_lhloose,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhloose_2e9_lhloose",&electron_match_HLT_e17_lhloose_2e9_lhloose,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhloose_mu14",&electron_match_HLT_e17_lhloose_mu14,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhloose_nod0_mu14",&electron_match_HLT_e17_lhloose_nod0_mu14,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo",&electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo",&electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo,"vector<int>");
  tree->Branch("electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo",&electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo,"vector<int>");
  tree->Branch("electron_match_HLT_e17_loose",&electron_match_HLT_e17_loose,"vector<int>");
  tree->Branch("electron_match_HLT_e17_loose_mu14",&electron_match_HLT_e17_loose_mu14,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhmedium_L1EM18VH",&electron_match_HLT_e24_lhmedium_L1EM18VH,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhmedium_L1EM20VH",&electron_match_HLT_e24_lhmedium_L1EM20VH,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhmedium_iloose_L1EM18VH",&electron_match_HLT_e24_lhmedium_iloose_L1EM18VH,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhmedium_nod0_L1EM20VH",&electron_match_HLT_e24_lhmedium_nod0_L1EM20VH,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1",&electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhtight_iloose",&electron_match_HLT_e24_lhtight_iloose,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhtight_iloose_L1EM20VH",&electron_match_HLT_e24_lhtight_iloose_L1EM20VH,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhtight_ivarloose",&electron_match_HLT_e24_lhtight_ivarloose,"vector<int>");
  tree->Branch("electron_match_HLT_e24_lhtight_nod0_ivarloose",&electron_match_HLT_e24_lhtight_nod0_ivarloose,"vector<int>");
  tree->Branch("electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1",&electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1,"vector<int>");
  tree->Branch("electron_match_HLT_e24_tight_iloose",&electron_match_HLT_e24_tight_iloose,"vector<int>");
  tree->Branch("electron_match_HLT_e24_tight_iloose_L1EM20VH",&electron_match_HLT_e24_tight_iloose_L1EM20VH,"vector<int>");
  tree->Branch("electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1",&electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1,"vector<int>");
  tree->Branch("electron_match_HLT_e26_lhtight_iloose",&electron_match_HLT_e26_lhtight_iloose,"vector<int>");
  tree->Branch("electron_match_HLT_e26_lhtight_nod0_ivarloose",&electron_match_HLT_e26_lhtight_nod0_ivarloose,"vector<int>");
  tree->Branch("electron_match_HLT_e26_tight_iloose",&electron_match_HLT_e26_tight_iloose,"vector<int>");
  tree->Branch("electron_match_HLT_e300_etcut",&electron_match_HLT_e300_etcut,"vector<int>");
  tree->Branch("electron_match_HLT_e5_lhloose",&electron_match_HLT_e5_lhloose,"vector<int>");
  tree->Branch("electron_match_HLT_e5_loose",&electron_match_HLT_e5_loose,"vector<int>");
  tree->Branch("electron_match_HLT_e60_lhmedium",&electron_match_HLT_e60_lhmedium,"vector<int>");
  tree->Branch("electron_match_HLT_e60_lhmedium_nod0",&electron_match_HLT_e60_lhmedium_nod0,"vector<int>");
  tree->Branch("electron_match_HLT_e60_medium",&electron_match_HLT_e60_medium,"vector<int>");
  tree->Branch("electron_match_HLT_e7_lhmedium_mu24",&electron_match_HLT_e7_lhmedium_mu24,"vector<int>");
  tree->Branch("electron_match_HLT_e7_lhmedium_nod0_mu24",&electron_match_HLT_e7_lhmedium_nod0_mu24,"vector<int>");
  tree->Branch("electron_match_HLT_e7_medium_mu24",&electron_match_HLT_e7_medium_mu24,"vector<int>");
  tree->Branch("electron_nInnerPix",&electron_nInnerPix,"vector<int>");
  tree->Branch("electron_author",&electron_author,"vector<int>");
  tree->Branch("electron_d0",&electron_d0,"vector<float>");
  tree->Branch("electron_z0",&electron_z0,"vector<float>");
  tree->Branch("electron_vz",&electron_vz,"vector<float>");
  tree->Branch("electron_deltaz0",&electron_deltaz0,"vector<float>");
  tree->Branch("electron_truthOrigin",&electron_truthOrigin,"vector<int>");
  tree->Branch("electron_truthType",&electron_truthType,"vector<int>");
  tree->Branch("electron_firstEgMotherPdgId",&electron_firstEgMotherPdgId,"vector<int>");
  tree->Branch("electron_firstEgMotherTruthType",&electron_firstEgMotherTruthType,"vector<int>");
  tree->Branch("electron_firstEgMotherTruthOrigin",&electron_firstEgMotherTruthOrigin,"vector<int>");
  tree->Branch("electron_jetFitterComb",&electron_jetFitterComb,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_sv1_jf_ntrkv",&electron_PromptLeptonInput_sv1_jf_ntrkv,"vector<short>");
  tree->Branch("electron_PromptLeptonInput_TrackJetNTrack",&electron_PromptLeptonInput_TrackJetNTrack,"vector<short>");
  tree->Branch("electron_PromptLeptonInput_DL1mu",&electron_PromptLeptonInput_DL1mu,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_DRlj",&electron_PromptLeptonInput_DRlj,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_LepJetPtFrac",&electron_PromptLeptonInput_LepJetPtFrac,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_PtFrac",&electron_PromptLeptonInput_PtFrac,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_PtRel",&electron_PromptLeptonInput_PtRel,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_ip2",&electron_PromptLeptonInput_ip2,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_ip3",&electron_PromptLeptonInput_ip3,"vector<float>");
  tree->Branch("electron_PromptLeptonInput_rnnip",&electron_PromptLeptonInput_rnnip,"vector<float>");
  tree->Branch("electron_PromptLeptonIso_TagWeight",&electron_PromptLeptonIso_TagWeight,"vector<float>");
  tree->Branch("electron_PromptLeptonVeto_TagWeight",&electron_PromptLeptonVeto_TagWeight,"vector<float>");
  tree->Branch("electron_ambiguityType",&electron_ambiguityType,"vector<unsigned char>");
  tree->Branch("electron_numberOfInnermostPixelLayerHits",&electron_numberOfInnermostPixelLayerHits,"vector<unsigned char>");
  tree->Branch("electron_numberOfInnermostPixelLayerOutliers",&electron_numberOfInnermostPixelLayerOutliers,"vector<unsigned char>");
  tree->Branch("electron_expectInnerPixelLayerHit",&electron_expectInnerPixelLayerHit,"vector<unsigned char>");
  tree->Branch("muon_pt",&muon_pt,"vector<float>");
  tree->Branch("muon_eta",&muon_eta,"vector<float>");
  tree->Branch("muon_phi",&muon_phi,"vector<float>");
  tree->Branch("muon_E",&muon_E,"vector<float>");
  tree->Branch("muon_isLoose",&muon_isLoose,"vector<char>");
  tree->Branch("muon_isMedium",&muon_isMedium,"vector<char>");
  tree->Branch("muon_isTight",&muon_isTight,"vector<char>");
  tree->Branch("muon_ID",&muon_ID,"vector<int>");
  tree->Branch("muon_sigd0PV",&muon_sigd0PV,"vector<float>");
  tree->Branch("muon_z0SinTheta",&muon_z0SinTheta,"vector<float>");
  tree->Branch("muon_momBalSignif",&muon_momBalSignif,"vector<float>");
  tree->Branch("muon_scatCurvSignif",&muon_scatCurvSignif,"vector<float>");
  tree->Branch("muon_scatNeighSignif",&muon_scatNeighSignif,"vector<float>");
  tree->Branch("muon_rho",&muon_rho,"vector<float>");
  tree->Branch("muon_qOverPsigma",&muon_qOverPsigma,"vector<float>");
  tree->Branch("muon_qOverPsignif",&muon_qOverPsignif,"vector<float>");
  tree->Branch("muon_reducedChi2",&muon_reducedChi2,"vector<float>");
  tree->Branch("muon_numPrecLayers",&muon_numPrecLayers,"vector<unsigned char>");
  tree->Branch("muon_topoetcone20",&muon_topoetcone20,"vector<float>");
  tree->Branch("muon_topoetcone30",&muon_topoetcone30,"vector<float>");
  tree->Branch("muon_topoetcone40",&muon_topoetcone40,"vector<float>");
  tree->Branch("muon_ptvarcone20",&muon_ptvarcone20,"vector<float>");
  tree->Branch("muon_ptvarcone30",&muon_ptvarcone30,"vector<float>");
  tree->Branch("muon_ptvarcone40",&muon_ptvarcone40,"vector<float>");
  tree->Branch("muon_sharesTrk",&muon_sharesTrk,"vector<char>");
  tree->Branch("muon_passOR",&muon_passOR,"vector<char>");
  tree->Branch("muon_isQMisID",&muon_isQMisID,"vector<char>");
  tree->Branch("muon_match_HLT_2mu10",&muon_match_HLT_2mu10,"vector<int>");
  tree->Branch("muon_match_HLT_2mu14",&muon_match_HLT_2mu14,"vector<int>");
  tree->Branch("muon_match_HLT_e17_lhloose_mu14",&muon_match_HLT_e17_lhloose_mu14,"vector<int>");
  tree->Branch("muon_match_HLT_e17_lhloose_nod0_mu14",&muon_match_HLT_e17_lhloose_nod0_mu14,"vector<int>");
  tree->Branch("muon_match_HLT_e17_loose_mu14",&muon_match_HLT_e17_loose_mu14,"vector<int>");
  tree->Branch("muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1",&muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1,"vector<int>");
  tree->Branch("muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1",&muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1,"vector<int>");
  tree->Branch("muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1",&muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1,"vector<int>");
  tree->Branch("muon_match_HLT_e7_lhmedium_mu24",&muon_match_HLT_e7_lhmedium_mu24,"vector<int>");
  tree->Branch("muon_match_HLT_e7_lhmedium_nod0_mu24",&muon_match_HLT_e7_lhmedium_nod0_mu24,"vector<int>");
  tree->Branch("muon_match_HLT_e7_medium_mu24",&muon_match_HLT_e7_medium_mu24,"vector<int>");
  tree->Branch("muon_match_HLT_mu10",&muon_match_HLT_mu10,"vector<int>");
  tree->Branch("muon_match_HLT_mu14",&muon_match_HLT_mu14,"vector<int>");
  tree->Branch("muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo",&muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo,"vector<int>");
  tree->Branch("muon_match_HLT_mu14_tau25_medium1_tracktwo",&muon_match_HLT_mu14_tau25_medium1_tracktwo,"vector<int>");
  tree->Branch("muon_match_HLT_mu18",&muon_match_HLT_mu18,"vector<int>");
  tree->Branch("muon_match_HLT_mu18_mu8noL1",&muon_match_HLT_mu18_mu8noL1,"vector<int>");
  tree->Branch("muon_match_HLT_mu20_iloose_L1MU15",&muon_match_HLT_mu20_iloose_L1MU15,"vector<int>");
  tree->Branch("muon_match_HLT_mu20_mu8noL1",&muon_match_HLT_mu20_mu8noL1,"vector<int>");
  tree->Branch("muon_match_HLT_mu22_mu8noL1",&muon_match_HLT_mu22_mu8noL1,"vector<int>");
  tree->Branch("muon_match_HLT_mu24",&muon_match_HLT_mu24,"vector<int>");
  tree->Branch("muon_match_HLT_mu24_iloose",&muon_match_HLT_mu24_iloose,"vector<int>");
  tree->Branch("muon_match_HLT_mu24_imedium",&muon_match_HLT_mu24_imedium,"vector<int>");
  tree->Branch("muon_match_HLT_mu24_ivarloose",&muon_match_HLT_mu24_ivarloose,"vector<int>");
  tree->Branch("muon_match_HLT_mu24_ivarmedium",&muon_match_HLT_mu24_ivarmedium,"vector<int>");
  tree->Branch("muon_match_HLT_mu26_imedium",&muon_match_HLT_mu26_imedium,"vector<int>");
  tree->Branch("muon_match_HLT_mu26_ivarmedium",&muon_match_HLT_mu26_ivarmedium,"vector<int>");
  tree->Branch("muon_match_HLT_mu40",&muon_match_HLT_mu40,"vector<int>");
  tree->Branch("muon_match_HLT_mu50",&muon_match_HLT_mu50,"vector<int>");
  tree->Branch("muon_d0",&muon_d0,"vector<float>");
  tree->Branch("muon_z0",&muon_z0,"vector<float>");
  tree->Branch("muon_vz",&muon_vz,"vector<float>");
  tree->Branch("muon_deltaz0",&muon_deltaz0,"vector<float>");
  tree->Branch("muon_author",&muon_author,"vector<int>");
  tree->Branch("muon_type",&muon_type,"vector<int>");
  tree->Branch("muon_truthType",&muon_truthType,"vector<int>");
  tree->Branch("muon_truthOrigin",&muon_truthOrigin,"vector<int>");
  tree->Branch("muon_trackType",&muon_trackType,"vector<int>");
  tree->Branch("muon_trackOrigin",&muon_trackOrigin,"vector<int>");
  tree->Branch("muon_jetFitterComb",&muon_jetFitterComb,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_sv1_jf_ntrkv",&muon_PromptLeptonInput_sv1_jf_ntrkv,"vector<short>");
  tree->Branch("muon_PromptLeptonInput_TrackJetNTrack",&muon_PromptLeptonInput_TrackJetNTrack,"vector<short>");
  tree->Branch("muon_PromptLeptonInput_DL1mu",&muon_PromptLeptonInput_DL1mu,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_DRlj",&muon_PromptLeptonInput_DRlj,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_LepJetPtFrac",&muon_PromptLeptonInput_LepJetPtFrac,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_PtFrac",&muon_PromptLeptonInput_PtFrac,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_PtRel",&muon_PromptLeptonInput_PtRel,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_ip2",&muon_PromptLeptonInput_ip2,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_ip3",&muon_PromptLeptonInput_ip3,"vector<float>");
  tree->Branch("muon_PromptLeptonInput_rnnip",&muon_PromptLeptonInput_rnnip,"vector<float>");
  tree->Branch("muon_PromptLeptonIso_TagWeight",&muon_PromptLeptonIso_TagWeight,"vector<float>");
  tree->Branch("muon_PromptLeptonVeto_TagWeight",&muon_PromptLeptonVeto_TagWeight,"vector<float>");
  tree->Branch("muon_jet_pt",&muon_jet_pt,"vector<float>");
  tree->Branch("muon_jet_eta",&muon_jet_eta,"vector<float>");
  tree->Branch("muon_jet_phi",&muon_jet_phi,"vector<float>");
  tree->Branch("muon_jet_dr",&muon_jet_dr,"vector<float>");
  tree->Branch("muon_jet_ptRel",&muon_jet_ptRel,"vector<float>");
  tree->Branch("muon_jet_numTrk",&muon_jet_numTrk,"vector<float>");
  tree->Branch("muon_jet_sumPtTrk",&muon_jet_sumPtTrk,"vector<float>");
  tree->Branch("muon_jet_MV2c10_Weight",&muon_jet_MV2c10_Weight,"vector<float>");
  tree->Branch("muon_jet_tagWeightBin",&muon_jet_tagWeightBin,"vector<float>");
  tree->Branch("muon_jet_BDT",&muon_jet_BDT,"vector<float>");
  tree->Branch("m_jet_pt",&m_jet_pt,"vector<float>");
  tree->Branch("m_jet_eta",&m_jet_eta,"vector<float>");
  tree->Branch("m_jet_phi",&m_jet_phi,"vector<float>");
  tree->Branch("m_jet_E",&m_jet_E,"vector<float>");
  tree->Branch("m_jet_etaEM",&m_jet_etaEM,"vector<double>");
  tree->Branch("m_jet_jvt",&m_jet_jvt,"vector<float>");
  tree->Branch("m_jet_passjvt",&m_jet_passjvt,"vector<int>");
  tree->Branch("m_jet_isLooseBad",&m_jet_isLooseBad,"vector<int>");
  tree->Branch("m_jet_flavor_weight_MV2c10",&m_jet_flavor_weight_MV2c10,"vector<float>");
  tree->Branch("m_jet_numTrk",&m_jet_numTrk,"vector<int>");
  tree->Branch("m_jet_passOR",&m_jet_passOR,"vector<char>");
  tree->Branch("m_jet_passTauOR",&m_jet_passTauOR,"vector<char>");
  tree->Branch("m_jet_flavor_truth_label",&m_jet_flavor_truth_label,"vector<int>");
  tree->Branch("m_jet_flavor_truth_label_ghost",&m_jet_flavor_truth_label_ghost,"vector<int>");
  tree->Branch("m_jet_flavor_weight_MV2c00",&m_jet_flavor_weight_MV2c00,"vector<float>");
  tree->Branch("m_jet_flavor_weight_MV2c20",&m_jet_flavor_weight_MV2c20,"vector<float>");
  tree->Branch("m_jet_sumPtTrk",&m_jet_sumPtTrk,"vector<float>");
  tree->Branch("m_jet_emfrac",&m_jet_emfrac,"vector<float>");
  tree->Branch("m_tau_pt",&m_tau_pt,"vector<float>");
  tree->Branch("m_tau_eta",&m_tau_eta,"vector<float>");
  tree->Branch("m_tau_phi",&m_tau_phi,"vector<float>");
  tree->Branch("m_tau_E",&m_tau_E,"vector<float>");
  tree->Branch("m_tau_charge",&m_tau_charge,"vector<float>");
  tree->Branch("m_tau_numTrack",&m_tau_numTrack,"vector<float>");
  tree->Branch("m_tau_BDTJetScore",&m_tau_BDTJetScore,"vector<double>");
  tree->Branch("m_tau_BDTJetScoreSigTrans",&m_tau_BDTJetScoreSigTrans,"vector<double>");
  tree->Branch("m_tau_JetBDTSigLoose",&m_tau_JetBDTSigLoose,"vector<int>");
  tree->Branch("m_tau_JetBDTSigMedium",&m_tau_JetBDTSigMedium,"vector<int>");
  tree->Branch("m_tau_JetBDTSigTight",&m_tau_JetBDTSigTight,"vector<int>");
  tree->Branch("m_tau_MVATESQuality",&m_tau_MVATESQuality,"vector<int>");
  tree->Branch("m_tau_passOR",&m_tau_passOR,"vector<char>");
  tree->Branch("m_tau_passEleOLR",&m_tau_passEleOLR,"vector<int>");
  tree->Branch("m_tau_passEleBDT",&m_tau_passEleBDT,"vector<int>");
  tree->Branch("m_tau_passMuonOLR",&m_tau_passMuonOLR,"vector<int>");
  tree->Branch("m_tau_isHadronicTau",&m_tau_isHadronicTau,"vector<int>");
  tree->Branch("m_tau_MV2c10",&m_tau_MV2c10,"vector<float>");
  tree->Branch("m_tau_tagWeightBin",&m_tau_tagWeightBin,"vector<int>");
  tree->Branch("m_tau_passJVT",&m_tau_passJVT,"vector<char>");
  tree->Branch("m_tau_fromPV",&m_tau_fromPV,"vector<char>");
  tree->Branch("m_tau_BDTEleScoreSigTrans",&m_tau_BDTEleScoreSigTrans,"vector<float>");
  tree->Branch("m_tau_BDTJetScoreSigTrans",&m_tau_BDTJetScoreSigTrans,"vector<double>");
  tree->Branch("m_tau_ptTauEtaCalib",&m_tau_ptTauEtaCalib,"vector<float>");
  tree->Branch("m_tau_etaTauEtaCalib",&m_tau_etaTauEtaCalib,"vector<float>");
  tree->Branch("m_tau_phiTauEtaCalib",&m_tau_phiTauEtaCalib,"vector<float>");
  tree->Branch("m_tau_mTauEtaCalib",&m_tau_mTauEtaCalib,"vector<float>");
  tree->Branch("m_tau_isTruthMatched",&m_tau_isTruthMatched,"vector<int>");
  tree->Branch("m_tau_truthOrigin",&m_tau_truthOrigin,"vector<int>");
  tree->Branch("m_tau_truthType",&m_tau_truthType,"vector<int>");
  tree->Branch("m_tau_truthJetFlavour",&m_tau_truthJetFlavour,"vector<int>");
  tree->Branch("m_tau_ele_match_lhscore",&m_tau_ele_match_lhscore,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_TrackJetNTrack",&m_tau_PromptTauInput_TrackJetNTrack,"vector<short>");
  tree->Branch("m_tau_PromptTauInput_DRlj",&m_tau_PromptTauInput_DRlj,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_JetF",&m_tau_PromptTauInput_JetF,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_LepJetPtFrac",&m_tau_PromptTauInput_LepJetPtFrac,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_MV2c10rnn",&m_tau_PromptTauInput_MV2c10rnn,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_SV1",&m_tau_PromptTauInput_SV1,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_ip2",&m_tau_PromptTauInput_ip2,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_ip3",&m_tau_PromptTauInput_ip3,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_rnnip",&m_tau_PromptTauInput_rnnip,"vector<float>");
  tree->Branch("m_tau_PromptTauInput_MV2c10",&m_tau_PromptTauInput_MV2c10,"vector<float>");
  tree->Branch("m_tau_PromptTauVeto",&m_tau_PromptTauVeto,"vector<float>");
  tree->Branch("m_tau_PromptTauIso",&m_tau_PromptTauIso,"vector<float>");
  tree->Branch("triggers",&triggers,"triggers/I");
  tree->Branch("loose",&loose,"loose/I");
  tree->Branch("lep_ID_0",&lep_ID_0,"lep_ID_0/F");
  tree->Branch("lep_Index_0",&lep_Index_0,"lep_Index_0/I");
  tree->Branch("lep_Pt_0",&lep_Pt_0,"lep_Pt_0/F");
  tree->Branch("lep_E_0",&lep_E_0,"lep_E_0/F");
  tree->Branch("lep_Eta_0",&lep_Eta_0,"lep_Eta_0/F");
  tree->Branch("lep_Phi_0",&lep_Phi_0,"lep_Phi_0/F");
  tree->Branch("lep_EtaBE2_0",&lep_EtaBE2_0,"lep_EtaBE2_0/F");
  tree->Branch("lep_topoEtcone20_0",&lep_topoEtcone20_0,"lep_topoEtcone20_0/F");
  tree->Branch("lep_topoEtcone30_0",&lep_topoEtcone30_0,"lep_topoEtcone30_0/F");
  tree->Branch("lep_topoEtcone40_0",&lep_topoEtcone40_0,"lep_topoEtcone40_0/F");
  tree->Branch("lep_ptVarcone20_0",&lep_ptVarcone20_0,"lep_ptVarcone20_0/F");
  tree->Branch("lep_ptVarcone30_0",&lep_ptVarcone30_0,"lep_ptVarcone30_0/F");
  tree->Branch("lep_ptVarcone40_0",&lep_ptVarcone40_0,"lep_ptVarcone40_0/F");
  tree->Branch("lep_sigd0PV_0",&lep_sigd0PV_0,"lep_sigd0PV_0/F");
  tree->Branch("lep_Z0SinTheta_0",&lep_Z0SinTheta_0,"lep_Z0SinTheta_0/F");
  tree->Branch("lep_d0_0",&lep_d0_0,"lep_d0_0/F");
  tree->Branch("lep_z0_0",&lep_z0_0,"lep_z0_0/F");
  tree->Branch("lep_vz_0",&lep_vz_0,"lep_vz_0/F");
  tree->Branch("lep_deltaz0_0",&lep_deltaz0_0,"lep_deltaz0_0/F");
  tree->Branch("lep_isTightLH_0",&lep_isTightLH_0,"lep_isTightLH_0/B");
  tree->Branch("lep_isMediumLH_0",&lep_isMediumLH_0,"lep_isMediumLH_0/B");
  tree->Branch("lep_isLooseLH_0",&lep_isLooseLH_0,"lep_isLooseLH_0/B");
  tree->Branch("lep_isTight_0",&lep_isTight_0,"lep_isTight_0/B");
  tree->Branch("lep_isMedium_0",&lep_isMedium_0,"lep_isMedium_0/B");
  tree->Branch("lep_isLoose_0",&lep_isLoose_0,"lep_isLoose_0/B");
  tree->Branch("lep_isolationLooseTrackOnly_0",&lep_isolationLooseTrackOnly_0,"lep_isolationLooseTrackOnly_0/I");
  tree->Branch("lep_isolationLoose_0",&lep_isolationLoose_0,"lep_isolationLoose_0/I");
  tree->Branch("lep_isolationGradient_0",&lep_isolationGradient_0,"lep_isolationGradient_0/I");
  tree->Branch("lep_isolationGradientLoose_0",&lep_isolationGradientLoose_0,"lep_isolationGradientLoose_0/I");
  tree->Branch("lep_isolationFixedCutTight_0",&lep_isolationFixedCutTight_0,"lep_isolationFixedCutTight_0/I");
  tree->Branch("lep_isolationFixedCutTightTrackOnly_0",&lep_isolationFixedCutTightTrackOnly_0,"lep_isolationFixedCutTightTrackOnly_0/I");
  tree->Branch("lep_isolationFixedCutLoose_0",&lep_isolationFixedCutLoose_0,"lep_isolationFixedCutLoose_0/I");
  tree->Branch("lep_isTrigMatch_0",&lep_isTrigMatch_0,"lep_isTrigMatch_0/B");
  tree->Branch("lep_isTrigMatchDLT_0",&lep_isTrigMatchDLT_0,"lep_isTrigMatchDLT_0/B");
  tree->Branch("lep_isPrompt_0",&lep_isPrompt_0,"lep_isPrompt_0/B");
  tree->Branch("lep_isFakeLep_0",&lep_isFakeLep_0,"lep_isFakeLep_0/B");
  tree->Branch("lep_isQMisID_0",&lep_isQMisID_0,"lep_isQMisID_0/B");
  tree->Branch("lep_isConvPh_0",&lep_isConvPh_0,"lep_isConvPh_0/B");
  tree->Branch("lep_isExtConvPh_0",&lep_isExtConvPh_0,"lep_isExtConvPh_0/B");
  tree->Branch("lep_isIntConvPh_0",&lep_isIntConvPh_0,"lep_isIntConvPh_0/B");
  tree->Branch("lep_isISR_FSR_Ph_0",&lep_isISR_FSR_Ph_0,"lep_isISR_FSR_Ph_0/B");
  tree->Branch("lep_isBrems_0",&lep_isBrems_0,"lep_isBrems_0/B");
  tree->Branch("lep_chargeIDBDTLoose_0",&lep_chargeIDBDTLoose_0,"lep_chargeIDBDTLoose_0/F");
  tree->Branch("lep_chargeIDBDTMedium_0",&lep_chargeIDBDTMedium_0,"lep_chargeIDBDTMedium_0/F");
  tree->Branch("lep_chargeIDBDTTight_0",&lep_chargeIDBDTTight_0,"lep_chargeIDBDTTight_0/F");
  tree->Branch("lep_promptLeptonInput_sv1_jf_ntrkv_0",&lep_promptLeptonInput_sv1_jf_ntrkv_0,"lep_promptLeptonInput_sv1_jf_ntrkv_0/S");
  tree->Branch("lep_promptLeptonInput_TrackJetNTrack_0",&lep_promptLeptonInput_TrackJetNTrack_0,"lep_promptLeptonInput_TrackJetNTrack_0/S");
  tree->Branch("lep_promptLeptonInput_DL1mu_0",&lep_promptLeptonInput_DL1mu_0,"lep_promptLeptonInput_DL1mu_0/F");
  tree->Branch("lep_promptLeptonInput_DRlj_0",&lep_promptLeptonInput_DRlj_0,"lep_promptLeptonInput_DRlj_0/F");
  tree->Branch("lep_promptLeptonInput_LepJetPtFrac_0",&lep_promptLeptonInput_LepJetPtFrac_0,"lep_promptLeptonInput_LepJetPtFrac_0/F");
  tree->Branch("lep_promptLeptonInput_PtFrac_0",&lep_promptLeptonInput_PtFrac_0,"lep_promptLeptonInput_PtFrac_0/F");
  tree->Branch("lep_promptLeptonInput_PtRel_0",&lep_promptLeptonInput_PtRel_0,"lep_promptLeptonInput_PtRel_0/F");
  tree->Branch("lep_promptLeptonInput_ip2_0",&lep_promptLeptonInput_ip2_0,"lep_promptLeptonInput_ip2_0/F");
  tree->Branch("lep_promptLeptonInput_ip3_0",&lep_promptLeptonInput_ip3_0,"lep_promptLeptonInput_ip3_0/F");
  tree->Branch("lep_promptLeptonInput_rnnip_0",&lep_promptLeptonInput_rnnip_0,"lep_promptLeptonInput_rnnip_0/F");
  tree->Branch("lep_promptLeptonIso_TagWeight_0",&lep_promptLeptonIso_TagWeight_0,"lep_promptLeptonIso_TagWeight_0/F");
  tree->Branch("lep_promptLeptonVeto_TagWeight_0",&lep_promptLeptonVeto_TagWeight_0,"lep_promptLeptonVeto_TagWeight_0/F");
  tree->Branch("lep_jet_Pt_0",&lep_jet_Pt_0,"lep_jet_Pt_0/F");
  tree->Branch("lep_jet_nTrk_0",&lep_jet_nTrk_0,"lep_jet_nTrk_0/F");
  tree->Branch("lep_jet_sumPtTrk_0",&lep_jet_sumPtTrk_0,"lep_jet_sumPtTrk_0/F");
  tree->Branch("lep_jet_mv2c10_0",&lep_jet_mv2c10_0,"lep_jet_mv2c10_0/F");
  tree->Branch("lep_jet_deltaR_0",&lep_jet_deltaR_0,"lep_jet_deltaR_0/F");
  tree->Branch("lep_jet_ptRel_0",&lep_jet_ptRel_0,"lep_jet_ptRel_0/F");
  tree->Branch("lep_jet_ptOverMuPt_0",&lep_jet_ptOverMuPt_0,"lep_jet_ptOverMuPt_0/F");
  tree->Branch("lep_jet_BDT_0",&lep_jet_BDT_0,"lep_jet_BDT_0/F");
  tree->Branch("lep_isTruthMatched_0",&lep_isTruthMatched_0,"lep_isTruthMatched_0/B");
  tree->Branch("lep_truthType_0",&lep_truthType_0,"lep_truthType_0/I");
  tree->Branch("lep_truthOrigin_0",&lep_truthOrigin_0,"lep_truthOrigin_0/I");
  tree->Branch("lep_truthPdgId_0",&lep_truthPdgId_0,"lep_truthPdgId_0/I");
  tree->Branch("lep_truthStatus_0",&lep_truthStatus_0,"lep_truthStatus_0/I");
  tree->Branch("lep_truthParentType_0",&lep_truthParentType_0,"lep_truthParentType_0/I");
  tree->Branch("lep_truthParentOrigin_0",&lep_truthParentOrigin_0,"lep_truthParentOrigin_0/I");
  tree->Branch("lep_truthParentPdgId_0",&lep_truthParentPdgId_0,"lep_truthParentPdgId_0/I");
  tree->Branch("lep_truthParentStatus_0",&lep_truthParentStatus_0,"lep_truthParentStatus_0/I");
  tree->Branch("lep_truthPt_0",&lep_truthPt_0,"lep_truthPt_0/F");
  tree->Branch("lep_truthEta_0",&lep_truthEta_0,"lep_truthEta_0/F");
  tree->Branch("lep_truthPhi_0",&lep_truthPhi_0,"lep_truthPhi_0/F");
  tree->Branch("lep_truthM_0",&lep_truthM_0,"lep_truthM_0/F");
  tree->Branch("lep_truthE_0",&lep_truthE_0,"lep_truthE_0/F");
  tree->Branch("lep_truthRapidity_0",&lep_truthRapidity_0,"lep_truthRapidity_0/F");
  tree->Branch("lep_ambiguityType_0",&lep_ambiguityType_0,"lep_ambiguityType_0/b");
  tree->Branch("lep_SFIDLoose_0",&lep_SFIDLoose_0,"lep_SFIDLoose_0/F");
  tree->Branch("lep_SFIDTight_0",&lep_SFIDTight_0,"lep_SFIDTight_0/F");
  tree->Branch("lep_SFTrigLoose_0",&lep_SFTrigLoose_0,"lep_SFTrigLoose_0/F");
  tree->Branch("lep_SFTrigTight_0",&lep_SFTrigTight_0,"lep_SFTrigTight_0/F");
  tree->Branch("lep_EffTrigLoose_0",&lep_EffTrigLoose_0,"lep_EffTrigLoose_0/F");
  tree->Branch("lep_EffTrigTight_0",&lep_EffTrigTight_0,"lep_EffTrigTight_0/F");
  tree->Branch("lep_SFIsoLoose_0",&lep_SFIsoLoose_0,"lep_SFIsoLoose_0/F");
  tree->Branch("lep_SFIsoTight_0",&lep_SFIsoTight_0,"lep_SFIsoTight_0/F");
  tree->Branch("lep_SFReco_0",&lep_SFReco_0,"lep_SFReco_0/F");
  tree->Branch("lep_SFTTVA_0",&lep_SFTTVA_0,"lep_SFTTVA_0/F");
  tree->Branch("lep_SFObjLoose_0",&lep_SFObjLoose_0,"lep_SFObjLoose_0/F");
  tree->Branch("lep_SFObjTight_0",&lep_SFObjTight_0,"lep_SFObjTight_0/F");
  tree->Branch("lep_nInnerPix_0",&lep_nInnerPix_0,"lep_nInnerPix_0/I");
  tree->Branch("lep_firstEgMotherPdgId_0",&lep_firstEgMotherPdgId_0,"lep_firstEgMotherPdgId_0/I");
  tree->Branch("lep_firstEgMotherTruthType_0",&lep_firstEgMotherTruthType_0,"lep_firstEgMotherTruthType_0/I");
  tree->Branch("lep_firstEgMotherTruthOrigin_0",&lep_firstEgMotherTruthOrigin_0,"lep_firstEgMotherTruthOrigin_0/I");
  tree->Branch("lep_ID_1",&lep_ID_1,"lep_ID_1/F");
  tree->Branch("lep_Index_1",&lep_Index_1,"lep_Index_1/I");
  tree->Branch("lep_Pt_1",&lep_Pt_1,"lep_Pt_1/F");
  tree->Branch("lep_E_1",&lep_E_1,"lep_E_1/F");
  tree->Branch("lep_Eta_1",&lep_Eta_1,"lep_Eta_1/F");
  tree->Branch("lep_Phi_1",&lep_Phi_1,"lep_Phi_1/F");
  tree->Branch("lep_EtaBE2_1",&lep_EtaBE2_1,"lep_EtaBE2_1/F");
  tree->Branch("lep_topoEtcone20_1",&lep_topoEtcone20_1,"lep_topoEtcone20_1/F");
  tree->Branch("lep_topoEtcone30_1",&lep_topoEtcone30_1,"lep_topoEtcone30_1/F");
  tree->Branch("lep_topoEtcone40_1",&lep_topoEtcone40_1,"lep_topoEtcone40_1/F");
  tree->Branch("lep_ptVarcone20_1",&lep_ptVarcone20_1,"lep_ptVarcone20_1/F");
  tree->Branch("lep_ptVarcone30_1",&lep_ptVarcone30_1,"lep_ptVarcone30_1/F");
  tree->Branch("lep_ptVarcone40_1",&lep_ptVarcone40_1,"lep_ptVarcone40_1/F");
  tree->Branch("lep_sigd0PV_1",&lep_sigd0PV_1,"lep_sigd0PV_1/F");
  tree->Branch("lep_Z0SinTheta_1",&lep_Z0SinTheta_1,"lep_Z0SinTheta_1/F");
  tree->Branch("lep_d0_1",&lep_d0_1,"lep_d0_1/F");
  tree->Branch("lep_z0_1",&lep_z0_1,"lep_z0_1/F");
  tree->Branch("lep_vz_1",&lep_vz_1,"lep_vz_1/F");
  tree->Branch("lep_deltaz0_1",&lep_deltaz0_1,"lep_deltaz0_1/F");
  tree->Branch("lep_isTightLH_1",&lep_isTightLH_1,"lep_isTightLH_1/B");
  tree->Branch("lep_isMediumLH_1",&lep_isMediumLH_1,"lep_isMediumLH_1/B");
  tree->Branch("lep_isLooseLH_1",&lep_isLooseLH_1,"lep_isLooseLH_1/B");
  tree->Branch("lep_isTight_1",&lep_isTight_1,"lep_isTight_1/B");
  tree->Branch("lep_isMedium_1",&lep_isMedium_1,"lep_isMedium_1/B");
  tree->Branch("lep_isLoose_1",&lep_isLoose_1,"lep_isLoose_1/B");
  tree->Branch("lep_isolationLooseTrackOnly_1",&lep_isolationLooseTrackOnly_1,"lep_isolationLooseTrackOnly_1/I");
  tree->Branch("lep_isolationLoose_1",&lep_isolationLoose_1,"lep_isolationLoose_1/I");
  tree->Branch("lep_isolationGradient_1",&lep_isolationGradient_1,"lep_isolationGradient_1/I");
  tree->Branch("lep_isolationGradientLoose_1",&lep_isolationGradientLoose_1,"lep_isolationGradientLoose_1/I");
  tree->Branch("lep_isolationFixedCutTight_1",&lep_isolationFixedCutTight_1,"lep_isolationFixedCutTight_1/I");
  tree->Branch("lep_isolationFixedCutTightTrackOnly_1",&lep_isolationFixedCutTightTrackOnly_1,"lep_isolationFixedCutTightTrackOnly_1/I");
  tree->Branch("lep_isolationFixedCutLoose_1",&lep_isolationFixedCutLoose_1,"lep_isolationFixedCutLoose_1/I");
  tree->Branch("lep_isTrigMatch_1",&lep_isTrigMatch_1,"lep_isTrigMatch_1/B");
  tree->Branch("lep_isTrigMatchDLT_1",&lep_isTrigMatchDLT_1,"lep_isTrigMatchDLT_1/B");
  tree->Branch("lep_isPrompt_1",&lep_isPrompt_1,"lep_isPrompt_1/B");
  tree->Branch("lep_isFakeLep_1",&lep_isFakeLep_1,"lep_isFakeLep_1/B");
  tree->Branch("lep_isQMisID_1",&lep_isQMisID_1,"lep_isQMisID_1/B");
  tree->Branch("lep_isConvPh_1",&lep_isConvPh_1,"lep_isConvPh_1/B");
  tree->Branch("lep_isExtConvPh_1",&lep_isExtConvPh_1,"lep_isExtConvPh_1/B");
  tree->Branch("lep_isIntConvPh_1",&lep_isIntConvPh_1,"lep_isIntConvPh_1/B");
  tree->Branch("lep_isISR_FSR_Ph_1",&lep_isISR_FSR_Ph_1,"lep_isISR_FSR_Ph_1/B");
  tree->Branch("lep_isBrems_1",&lep_isBrems_1,"lep_isBrems_1/B");
  tree->Branch("lep_chargeIDBDTLoose_1",&lep_chargeIDBDTLoose_1,"lep_chargeIDBDTLoose_1/F");
  tree->Branch("lep_chargeIDBDTMedium_1",&lep_chargeIDBDTMedium_1,"lep_chargeIDBDTMedium_1/F");
  tree->Branch("lep_chargeIDBDTTight_1",&lep_chargeIDBDTTight_1,"lep_chargeIDBDTTight_1/F");
  tree->Branch("lep_promptLeptonInput_sv1_jf_ntrkv_1",&lep_promptLeptonInput_sv1_jf_ntrkv_1,"lep_promptLeptonInput_sv1_jf_ntrkv_1/S");
  tree->Branch("lep_promptLeptonInput_TrackJetNTrack_1",&lep_promptLeptonInput_TrackJetNTrack_1,"lep_promptLeptonInput_TrackJetNTrack_1/S");
  tree->Branch("lep_promptLeptonInput_DL1mu_1",&lep_promptLeptonInput_DL1mu_1,"lep_promptLeptonInput_DL1mu_1/F");
  tree->Branch("lep_promptLeptonInput_DRlj_1",&lep_promptLeptonInput_DRlj_1,"lep_promptLeptonInput_DRlj_1/F");
  tree->Branch("lep_promptLeptonInput_LepJetPtFrac_1",&lep_promptLeptonInput_LepJetPtFrac_1,"lep_promptLeptonInput_LepJetPtFrac_1/F");
  tree->Branch("lep_promptLeptonInput_PtFrac_1",&lep_promptLeptonInput_PtFrac_1,"lep_promptLeptonInput_PtFrac_1/F");
  tree->Branch("lep_promptLeptonInput_PtRel_1",&lep_promptLeptonInput_PtRel_1,"lep_promptLeptonInput_PtRel_1/F");
  tree->Branch("lep_promptLeptonInput_ip2_1",&lep_promptLeptonInput_ip2_1,"lep_promptLeptonInput_ip2_1/F");
  tree->Branch("lep_promptLeptonInput_ip3_1",&lep_promptLeptonInput_ip3_1,"lep_promptLeptonInput_ip3_1/F");
  tree->Branch("lep_promptLeptonInput_rnnip_1",&lep_promptLeptonInput_rnnip_1,"lep_promptLeptonInput_rnnip_1/F");
  tree->Branch("lep_promptLeptonIso_TagWeight_1",&lep_promptLeptonIso_TagWeight_1,"lep_promptLeptonIso_TagWeight_1/F");
  tree->Branch("lep_promptLeptonVeto_TagWeight_1",&lep_promptLeptonVeto_TagWeight_1,"lep_promptLeptonVeto_TagWeight_1/F");
  tree->Branch("lep_jet_Pt_1",&lep_jet_Pt_1,"lep_jet_Pt_1/F");
  tree->Branch("lep_jet_nTrk_1",&lep_jet_nTrk_1,"lep_jet_nTrk_1/F");
  tree->Branch("lep_jet_sumPtTrk_1",&lep_jet_sumPtTrk_1,"lep_jet_sumPtTrk_1/F");
  tree->Branch("lep_jet_mv2c10_1",&lep_jet_mv2c10_1,"lep_jet_mv2c10_1/F");
  tree->Branch("lep_jet_deltaR_1",&lep_jet_deltaR_1,"lep_jet_deltaR_1/F");
  tree->Branch("lep_jet_ptRel_1",&lep_jet_ptRel_1,"lep_jet_ptRel_1/F");
  tree->Branch("lep_jet_ptOverMuPt_1",&lep_jet_ptOverMuPt_1,"lep_jet_ptOverMuPt_1/F");
  tree->Branch("lep_jet_BDT_1",&lep_jet_BDT_1,"lep_jet_BDT_1/F");
  tree->Branch("lep_isTruthMatched_1",&lep_isTruthMatched_1,"lep_isTruthMatched_1/B");
  tree->Branch("lep_truthType_1",&lep_truthType_1,"lep_truthType_1/I");
  tree->Branch("lep_truthOrigin_1",&lep_truthOrigin_1,"lep_truthOrigin_1/I");
  tree->Branch("lep_truthPdgId_1",&lep_truthPdgId_1,"lep_truthPdgId_1/I");
  tree->Branch("lep_truthStatus_1",&lep_truthStatus_1,"lep_truthStatus_1/I");
  tree->Branch("lep_truthParentType_1",&lep_truthParentType_1,"lep_truthParentType_1/I");
  tree->Branch("lep_truthParentOrigin_1",&lep_truthParentOrigin_1,"lep_truthParentOrigin_1/I");
  tree->Branch("lep_truthParentPdgId_1",&lep_truthParentPdgId_1,"lep_truthParentPdgId_1/I");
  tree->Branch("lep_truthParentStatus_1",&lep_truthParentStatus_1,"lep_truthParentStatus_1/I");
  tree->Branch("lep_truthPt_1",&lep_truthPt_1,"lep_truthPt_1/F");
  tree->Branch("lep_truthEta_1",&lep_truthEta_1,"lep_truthEta_1/F");
  tree->Branch("lep_truthPhi_1",&lep_truthPhi_1,"lep_truthPhi_1/F");
  tree->Branch("lep_truthM_1",&lep_truthM_1,"lep_truthM_1/F");
  tree->Branch("lep_truthE_1",&lep_truthE_1,"lep_truthE_1/F");
  tree->Branch("lep_truthRapidity_1",&lep_truthRapidity_1,"lep_truthRapidity_1/F");
  tree->Branch("lep_ambiguityType_1",&lep_ambiguityType_1,"lep_ambiguityType_1/b");
  tree->Branch("lep_SFIDLoose_1",&lep_SFIDLoose_1,"lep_SFIDLoose_1/F");
  tree->Branch("lep_SFIDTight_1",&lep_SFIDTight_1,"lep_SFIDTight_1/F");
  tree->Branch("lep_SFTrigLoose_1",&lep_SFTrigLoose_1,"lep_SFTrigLoose_1/F");
  tree->Branch("lep_SFTrigTight_1",&lep_SFTrigTight_1,"lep_SFTrigTight_1/F");
  tree->Branch("lep_EffTrigLoose_1",&lep_EffTrigLoose_1,"lep_EffTrigLoose_1/F");
  tree->Branch("lep_EffTrigTight_1",&lep_EffTrigTight_1,"lep_EffTrigTight_1/F");
  tree->Branch("lep_SFIsoLoose_1",&lep_SFIsoLoose_1,"lep_SFIsoLoose_1/F");
  tree->Branch("lep_SFIsoTight_1",&lep_SFIsoTight_1,"lep_SFIsoTight_1/F");
  tree->Branch("lep_SFReco_1",&lep_SFReco_1,"lep_SFReco_1/F");
  tree->Branch("lep_SFTTVA_1",&lep_SFTTVA_1,"lep_SFTTVA_1/F");
  tree->Branch("lep_SFObjLoose_1",&lep_SFObjLoose_1,"lep_SFObjLoose_1/F");
  tree->Branch("lep_SFObjTight_1",&lep_SFObjTight_1,"lep_SFObjTight_1/F");
  tree->Branch("lep_nInnerPix_1",&lep_nInnerPix_1,"lep_nInnerPix_1/I");
  tree->Branch("lep_firstEgMotherPdgId_1",&lep_firstEgMotherPdgId_1,"lep_firstEgMotherPdgId_1/I");
  tree->Branch("lep_firstEgMotherTruthType_1",&lep_firstEgMotherTruthType_1,"lep_firstEgMotherTruthType_1/I");
  tree->Branch("lep_firstEgMotherTruthOrigin_1",&lep_firstEgMotherTruthOrigin_1,"lep_firstEgMotherTruthOrigin_1/I");
  tree->Branch("lep_ID_2",&lep_ID_2,"lep_ID_2/F");
  tree->Branch("lep_Index_2",&lep_Index_2,"lep_Index_2/I");
  tree->Branch("lep_Pt_2",&lep_Pt_2,"lep_Pt_2/F");
  tree->Branch("lep_E_2",&lep_E_2,"lep_E_2/F");
  tree->Branch("lep_Eta_2",&lep_Eta_2,"lep_Eta_2/F");
  tree->Branch("lep_Phi_2",&lep_Phi_2,"lep_Phi_2/F");
  tree->Branch("lep_EtaBE2_2",&lep_EtaBE2_2,"lep_EtaBE2_2/F");
  tree->Branch("lep_topoEtcone20_2",&lep_topoEtcone20_2,"lep_topoEtcone20_2/F");
  tree->Branch("lep_topoEtcone30_2",&lep_topoEtcone30_2,"lep_topoEtcone30_2/F");
  tree->Branch("lep_topoEtcone40_2",&lep_topoEtcone40_2,"lep_topoEtcone40_2/F");
  tree->Branch("lep_ptVarcone20_2",&lep_ptVarcone20_2,"lep_ptVarcone20_2/F");
  tree->Branch("lep_ptVarcone30_2",&lep_ptVarcone30_2,"lep_ptVarcone30_2/F");
  tree->Branch("lep_ptVarcone40_2",&lep_ptVarcone40_2,"lep_ptVarcone40_2/F");
  tree->Branch("lep_sigd0PV_2",&lep_sigd0PV_2,"lep_sigd0PV_2/F");
  tree->Branch("lep_Z0SinTheta_2",&lep_Z0SinTheta_2,"lep_Z0SinTheta_2/F");
  tree->Branch("lep_d0_2",&lep_d0_2,"lep_d0_2/F");
  tree->Branch("lep_z0_2",&lep_z0_2,"lep_z0_2/F");
  tree->Branch("lep_vz_2",&lep_vz_2,"lep_vz_2/F");
  tree->Branch("lep_deltaz0_2",&lep_deltaz0_2,"lep_deltaz0_2/F");
  tree->Branch("lep_isTightLH_2",&lep_isTightLH_2,"lep_isTightLH_2/B");
  tree->Branch("lep_isMediumLH_2",&lep_isMediumLH_2,"lep_isMediumLH_2/B");
  tree->Branch("lep_isLooseLH_2",&lep_isLooseLH_2,"lep_isLooseLH_2/B");
  tree->Branch("lep_isTight_2",&lep_isTight_2,"lep_isTight_2/B");
  tree->Branch("lep_isMedium_2",&lep_isMedium_2,"lep_isMedium_2/B");
  tree->Branch("lep_isLoose_2",&lep_isLoose_2,"lep_isLoose_2/B");
  tree->Branch("lep_isolationLooseTrackOnly_2",&lep_isolationLooseTrackOnly_2,"lep_isolationLooseTrackOnly_2/I");
  tree->Branch("lep_isolationLoose_2",&lep_isolationLoose_2,"lep_isolationLoose_2/I");
  tree->Branch("lep_isolationGradient_2",&lep_isolationGradient_2,"lep_isolationGradient_2/I");
  tree->Branch("lep_isolationGradientLoose_2",&lep_isolationGradientLoose_2,"lep_isolationGradientLoose_2/I");
  tree->Branch("lep_isolationFixedCutTight_2",&lep_isolationFixedCutTight_2,"lep_isolationFixedCutTight_2/I");
  tree->Branch("lep_isolationFixedCutTightTrackOnly_2",&lep_isolationFixedCutTightTrackOnly_2,"lep_isolationFixedCutTightTrackOnly_2/I");
  tree->Branch("lep_isolationFixedCutLoose_2",&lep_isolationFixedCutLoose_2,"lep_isolationFixedCutLoose_2/I");
  tree->Branch("lep_isTrigMatch_2",&lep_isTrigMatch_2,"lep_isTrigMatch_2/B");
  tree->Branch("lep_isTrigMatchDLT_2",&lep_isTrigMatchDLT_2,"lep_isTrigMatchDLT_2/B");
  tree->Branch("lep_isPrompt_2",&lep_isPrompt_2,"lep_isPrompt_2/B");
  tree->Branch("lep_isFakeLep_2",&lep_isFakeLep_2,"lep_isFakeLep_2/B");
  tree->Branch("lep_isQMisID_2",&lep_isQMisID_2,"lep_isQMisID_2/B");
  tree->Branch("lep_isConvPh_2",&lep_isConvPh_2,"lep_isConvPh_2/B");
  tree->Branch("lep_isExtConvPh_2",&lep_isExtConvPh_2,"lep_isExtConvPh_2/B");
  tree->Branch("lep_isIntConvPh_2",&lep_isIntConvPh_2,"lep_isIntConvPh_2/B");
  tree->Branch("lep_isISR_FSR_Ph_2",&lep_isISR_FSR_Ph_2,"lep_isISR_FSR_Ph_2/B");
  tree->Branch("lep_isBrems_2",&lep_isBrems_2,"lep_isBrems_2/B");
  tree->Branch("lep_chargeIDBDTLoose_2",&lep_chargeIDBDTLoose_2,"lep_chargeIDBDTLoose_2/F");
  tree->Branch("lep_chargeIDBDTMedium_2",&lep_chargeIDBDTMedium_2,"lep_chargeIDBDTMedium_2/F");
  tree->Branch("lep_chargeIDBDTTight_2",&lep_chargeIDBDTTight_2,"lep_chargeIDBDTTight_2/F");
  tree->Branch("lep_promptLeptonInput_sv1_jf_ntrkv_2",&lep_promptLeptonInput_sv1_jf_ntrkv_2,"lep_promptLeptonInput_sv1_jf_ntrkv_2/S");
  tree->Branch("lep_promptLeptonInput_TrackJetNTrack_2",&lep_promptLeptonInput_TrackJetNTrack_2,"lep_promptLeptonInput_TrackJetNTrack_2/S");
  tree->Branch("lep_promptLeptonInput_DL1mu_2",&lep_promptLeptonInput_DL1mu_2,"lep_promptLeptonInput_DL1mu_2/F");
  tree->Branch("lep_promptLeptonInput_DRlj_2",&lep_promptLeptonInput_DRlj_2,"lep_promptLeptonInput_DRlj_2/F");
  tree->Branch("lep_promptLeptonInput_LepJetPtFrac_2",&lep_promptLeptonInput_LepJetPtFrac_2,"lep_promptLeptonInput_LepJetPtFrac_2/F");
  tree->Branch("lep_promptLeptonInput_PtFrac_2",&lep_promptLeptonInput_PtFrac_2,"lep_promptLeptonInput_PtFrac_2/F");
  tree->Branch("lep_promptLeptonInput_PtRel_2",&lep_promptLeptonInput_PtRel_2,"lep_promptLeptonInput_PtRel_2/F");
  tree->Branch("lep_promptLeptonInput_ip2_2",&lep_promptLeptonInput_ip2_2,"lep_promptLeptonInput_ip2_2/F");
  tree->Branch("lep_promptLeptonInput_ip3_2",&lep_promptLeptonInput_ip3_2,"lep_promptLeptonInput_ip3_2/F");
  tree->Branch("lep_promptLeptonInput_rnnip_2",&lep_promptLeptonInput_rnnip_2,"lep_promptLeptonInput_rnnip_2/F");
  tree->Branch("lep_promptLeptonIso_TagWeight_2",&lep_promptLeptonIso_TagWeight_2,"lep_promptLeptonIso_TagWeight_2/F");
  tree->Branch("lep_promptLeptonVeto_TagWeight_2",&lep_promptLeptonVeto_TagWeight_2,"lep_promptLeptonVeto_TagWeight_2/F");
  tree->Branch("lep_jet_Pt_2",&lep_jet_Pt_2,"lep_jet_Pt_2/F");
  tree->Branch("lep_jet_nTrk_2",&lep_jet_nTrk_2,"lep_jet_nTrk_2/F");
  tree->Branch("lep_jet_sumPtTrk_2",&lep_jet_sumPtTrk_2,"lep_jet_sumPtTrk_2/F");
  tree->Branch("lep_jet_mv2c10_2",&lep_jet_mv2c10_2,"lep_jet_mv2c10_2/F");
  tree->Branch("lep_jet_deltaR_2",&lep_jet_deltaR_2,"lep_jet_deltaR_2/F");
  tree->Branch("lep_jet_ptRel_2",&lep_jet_ptRel_2,"lep_jet_ptRel_2/F");
  tree->Branch("lep_jet_ptOverMuPt_2",&lep_jet_ptOverMuPt_2,"lep_jet_ptOverMuPt_2/F");
  tree->Branch("lep_jet_BDT_2",&lep_jet_BDT_2,"lep_jet_BDT_2/F");
  tree->Branch("lep_isTruthMatched_2",&lep_isTruthMatched_2,"lep_isTruthMatched_2/B");
  tree->Branch("lep_truthType_2",&lep_truthType_2,"lep_truthType_2/I");
  tree->Branch("lep_truthOrigin_2",&lep_truthOrigin_2,"lep_truthOrigin_2/I");
  tree->Branch("lep_truthPdgId_2",&lep_truthPdgId_2,"lep_truthPdgId_2/I");
  tree->Branch("lep_truthStatus_2",&lep_truthStatus_2,"lep_truthStatus_2/I");
  tree->Branch("lep_truthParentType_2",&lep_truthParentType_2,"lep_truthParentType_2/I");
  tree->Branch("lep_truthParentOrigin_2",&lep_truthParentOrigin_2,"lep_truthParentOrigin_2/I");
  tree->Branch("lep_truthParentPdgId_2",&lep_truthParentPdgId_2,"lep_truthParentPdgId_2/I");
  tree->Branch("lep_truthParentStatus_2",&lep_truthParentStatus_2,"lep_truthParentStatus_2/I");
  tree->Branch("lep_truthPt_2",&lep_truthPt_2,"lep_truthPt_2/F");
  tree->Branch("lep_truthEta_2",&lep_truthEta_2,"lep_truthEta_2/F");
  tree->Branch("lep_truthPhi_2",&lep_truthPhi_2,"lep_truthPhi_2/F");
  tree->Branch("lep_truthM_2",&lep_truthM_2,"lep_truthM_2/F");
  tree->Branch("lep_truthE_2",&lep_truthE_2,"lep_truthE_2/F");
  tree->Branch("lep_truthRapidity_2",&lep_truthRapidity_2,"lep_truthRapidity_2/F");
  tree->Branch("lep_ambiguityType_2",&lep_ambiguityType_2,"lep_ambiguityType_2/b");
  tree->Branch("lep_SFIDLoose_2",&lep_SFIDLoose_2,"lep_SFIDLoose_2/F");
  tree->Branch("lep_SFIDTight_2",&lep_SFIDTight_2,"lep_SFIDTight_2/F");
  tree->Branch("lep_SFTrigLoose_2",&lep_SFTrigLoose_2,"lep_SFTrigLoose_2/F");
  tree->Branch("lep_SFTrigTight_2",&lep_SFTrigTight_2,"lep_SFTrigTight_2/F");
  tree->Branch("lep_EffTrigLoose_2",&lep_EffTrigLoose_2,"lep_EffTrigLoose_2/F");
  tree->Branch("lep_EffTrigTight_2",&lep_EffTrigTight_2,"lep_EffTrigTight_2/F");
  tree->Branch("lep_SFIsoLoose_2",&lep_SFIsoLoose_2,"lep_SFIsoLoose_2/F");
  tree->Branch("lep_SFIsoTight_2",&lep_SFIsoTight_2,"lep_SFIsoTight_2/F");
  tree->Branch("lep_SFReco_2",&lep_SFReco_2,"lep_SFReco_2/F");
  tree->Branch("lep_SFTTVA_2",&lep_SFTTVA_2,"lep_SFTTVA_2/F");
  tree->Branch("lep_SFObjLoose_2",&lep_SFObjLoose_2,"lep_SFObjLoose_2/F");
  tree->Branch("lep_SFObjTight_2",&lep_SFObjTight_2,"lep_SFObjTight_2/F");
  tree->Branch("lep_nInnerPix_2",&lep_nInnerPix_2,"lep_nInnerPix_2/I");
  tree->Branch("lep_firstEgMotherPdgId_2",&lep_firstEgMotherPdgId_2,"lep_firstEgMotherPdgId_2/I");
  tree->Branch("lep_firstEgMotherTruthType_2",&lep_firstEgMotherTruthType_2,"lep_firstEgMotherTruthType_2/I");
  tree->Branch("lep_firstEgMotherTruthOrigin_2",&lep_firstEgMotherTruthOrigin_2,"lep_firstEgMotherTruthOrigin_2/I");
  tree->Branch("lep_ID_3",&lep_ID_3,"lep_ID_3/F");
  tree->Branch("lep_Index_3",&lep_Index_3,"lep_Index_3/I");
  tree->Branch("lep_Pt_3",&lep_Pt_3,"lep_Pt_3/F");
  tree->Branch("lep_E_3",&lep_E_3,"lep_E_3/F");
  tree->Branch("lep_Eta_3",&lep_Eta_3,"lep_Eta_3/F");
  tree->Branch("lep_Phi_3",&lep_Phi_3,"lep_Phi_3/F");
  tree->Branch("lep_EtaBE2_3",&lep_EtaBE2_3,"lep_EtaBE2_3/F");
  tree->Branch("lep_topoEtcone20_3",&lep_topoEtcone20_3,"lep_topoEtcone20_3/F");
  tree->Branch("lep_topoEtcone30_3",&lep_topoEtcone30_3,"lep_topoEtcone30_3/F");
  tree->Branch("lep_topoEtcone40_3",&lep_topoEtcone40_3,"lep_topoEtcone40_3/F");
  tree->Branch("lep_ptVarcone20_3",&lep_ptVarcone20_3,"lep_ptVarcone20_3/F");
  tree->Branch("lep_ptVarcone30_3",&lep_ptVarcone30_3,"lep_ptVarcone30_3/F");
  tree->Branch("lep_ptVarcone40_3",&lep_ptVarcone40_3,"lep_ptVarcone40_3/F");
  tree->Branch("lep_sigd0PV_3",&lep_sigd0PV_3,"lep_sigd0PV_3/F");
  tree->Branch("lep_Z0SinTheta_3",&lep_Z0SinTheta_3,"lep_Z0SinTheta_3/F");
  tree->Branch("lep_d0_3",&lep_d0_3,"lep_d0_3/F");
  tree->Branch("lep_z0_3",&lep_z0_3,"lep_z0_3/F");
  tree->Branch("lep_vz_3",&lep_vz_3,"lep_vz_3/F");
  tree->Branch("lep_deltaz0_3",&lep_deltaz0_3,"lep_deltaz0_3/F");
  tree->Branch("lep_isTightLH_3",&lep_isTightLH_3,"lep_isTightLH_3/B");
  tree->Branch("lep_isMediumLH_3",&lep_isMediumLH_3,"lep_isMediumLH_3/B");
  tree->Branch("lep_isLooseLH_3",&lep_isLooseLH_3,"lep_isLooseLH_3/B");
  tree->Branch("lep_isTight_3",&lep_isTight_3,"lep_isTight_3/B");
  tree->Branch("lep_isMedium_3",&lep_isMedium_3,"lep_isMedium_3/B");
  tree->Branch("lep_isLoose_3",&lep_isLoose_3,"lep_isLoose_3/B");
  tree->Branch("lep_isolationLooseTrackOnly_3",&lep_isolationLooseTrackOnly_3,"lep_isolationLooseTrackOnly_3/I");
  tree->Branch("lep_isolationLoose_3",&lep_isolationLoose_3,"lep_isolationLoose_3/I");
  tree->Branch("lep_isolationGradient_3",&lep_isolationGradient_3,"lep_isolationGradient_3/I");
  tree->Branch("lep_isolationGradientLoose_3",&lep_isolationGradientLoose_3,"lep_isolationGradientLoose_3/I");
  tree->Branch("lep_isolationFixedCutTight_3",&lep_isolationFixedCutTight_3,"lep_isolationFixedCutTight_3/I");
  tree->Branch("lep_isolationFixedCutTightTrackOnly_3",&lep_isolationFixedCutTightTrackOnly_3,"lep_isolationFixedCutTightTrackOnly_3/I");
  tree->Branch("lep_isolationFixedCutLoose_3",&lep_isolationFixedCutLoose_3,"lep_isolationFixedCutLoose_3/I");
  tree->Branch("lep_isTrigMatch_3",&lep_isTrigMatch_3,"lep_isTrigMatch_3/B");
  tree->Branch("lep_isTrigMatchDLT_3",&lep_isTrigMatchDLT_3,"lep_isTrigMatchDLT_3/B");
  tree->Branch("lep_isPrompt_3",&lep_isPrompt_3,"lep_isPrompt_3/B");
  tree->Branch("lep_isFakeLep_3",&lep_isFakeLep_3,"lep_isFakeLep_3/B");
  tree->Branch("lep_isQMisID_3",&lep_isQMisID_3,"lep_isQMisID_3/B");
  tree->Branch("lep_isConvPh_3",&lep_isConvPh_3,"lep_isConvPh_3/B");
  tree->Branch("lep_isExtConvPh_3",&lep_isExtConvPh_3,"lep_isExtConvPh_3/B");
  tree->Branch("lep_isIntConvPh_3",&lep_isIntConvPh_3,"lep_isIntConvPh_3/B");
  tree->Branch("lep_isISR_FSR_Ph_3",&lep_isISR_FSR_Ph_3,"lep_isISR_FSR_Ph_3/B");
  tree->Branch("lep_isBrems_3",&lep_isBrems_3,"lep_isBrems_3/B");
  tree->Branch("lep_chargeIDBDTLoose_3",&lep_chargeIDBDTLoose_3,"lep_chargeIDBDTLoose_3/F");
  tree->Branch("lep_chargeIDBDTMedium_3",&lep_chargeIDBDTMedium_3,"lep_chargeIDBDTMedium_3/F");
  tree->Branch("lep_chargeIDBDTTight_3",&lep_chargeIDBDTTight_3,"lep_chargeIDBDTTight_3/F");
  tree->Branch("lep_promptLeptonInput_sv1_jf_ntrkv_3",&lep_promptLeptonInput_sv1_jf_ntrkv_3,"lep_promptLeptonInput_sv1_jf_ntrkv_3/S");
  tree->Branch("lep_promptLeptonInput_TrackJetNTrack_3",&lep_promptLeptonInput_TrackJetNTrack_3,"lep_promptLeptonInput_TrackJetNTrack_3/S");
  tree->Branch("lep_promptLeptonInput_DL1mu_3",&lep_promptLeptonInput_DL1mu_3,"lep_promptLeptonInput_DL1mu_3/F");
  tree->Branch("lep_promptLeptonInput_DRlj_3",&lep_promptLeptonInput_DRlj_3,"lep_promptLeptonInput_DRlj_3/F");
  tree->Branch("lep_promptLeptonInput_LepJetPtFrac_3",&lep_promptLeptonInput_LepJetPtFrac_3,"lep_promptLeptonInput_LepJetPtFrac_3/F");
  tree->Branch("lep_promptLeptonInput_PtFrac_3",&lep_promptLeptonInput_PtFrac_3,"lep_promptLeptonInput_PtFrac_3/F");
  tree->Branch("lep_promptLeptonInput_PtRel_3",&lep_promptLeptonInput_PtRel_3,"lep_promptLeptonInput_PtRel_3/F");
  tree->Branch("lep_promptLeptonInput_ip2_3",&lep_promptLeptonInput_ip2_3,"lep_promptLeptonInput_ip2_3/F");
  tree->Branch("lep_promptLeptonInput_ip3_3",&lep_promptLeptonInput_ip3_3,"lep_promptLeptonInput_ip3_3/F");
  tree->Branch("lep_promptLeptonInput_rnnip_3",&lep_promptLeptonInput_rnnip_3,"lep_promptLeptonInput_rnnip_3/F");
  tree->Branch("lep_promptLeptonIso_TagWeight_3",&lep_promptLeptonIso_TagWeight_3,"lep_promptLeptonIso_TagWeight_3/F");
  tree->Branch("lep_promptLeptonVeto_TagWeight_3",&lep_promptLeptonVeto_TagWeight_3,"lep_promptLeptonVeto_TagWeight_3/F");
  tree->Branch("lep_jet_Pt_3",&lep_jet_Pt_3,"lep_jet_Pt_3/F");
  tree->Branch("lep_jet_nTrk_3",&lep_jet_nTrk_3,"lep_jet_nTrk_3/F");
  tree->Branch("lep_jet_sumPtTrk_3",&lep_jet_sumPtTrk_3,"lep_jet_sumPtTrk_3/F");
  tree->Branch("lep_jet_mv2c10_3",&lep_jet_mv2c10_3,"lep_jet_mv2c10_3/F");
  tree->Branch("lep_jet_deltaR_3",&lep_jet_deltaR_3,"lep_jet_deltaR_3/F");
  tree->Branch("lep_jet_ptRel_3",&lep_jet_ptRel_3,"lep_jet_ptRel_3/F");
  tree->Branch("lep_jet_ptOverMuPt_3",&lep_jet_ptOverMuPt_3,"lep_jet_ptOverMuPt_3/F");
  tree->Branch("lep_jet_BDT_3",&lep_jet_BDT_3,"lep_jet_BDT_3/F");
  tree->Branch("lep_isTruthMatched_3",&lep_isTruthMatched_3,"lep_isTruthMatched_3/B");
  tree->Branch("lep_truthType_3",&lep_truthType_3,"lep_truthType_3/I");
  tree->Branch("lep_truthOrigin_3",&lep_truthOrigin_3,"lep_truthOrigin_3/I");
  tree->Branch("lep_truthPdgId_3",&lep_truthPdgId_3,"lep_truthPdgId_3/I");
  tree->Branch("lep_truthStatus_3",&lep_truthStatus_3,"lep_truthStatus_3/I");
  tree->Branch("lep_truthParentType_3",&lep_truthParentType_3,"lep_truthParentType_3/I");
  tree->Branch("lep_truthParentOrigin_3",&lep_truthParentOrigin_3,"lep_truthParentOrigin_3/I");
  tree->Branch("lep_truthParentPdgId_3",&lep_truthParentPdgId_3,"lep_truthParentPdgId_3/I");
  tree->Branch("lep_truthParentStatus_3",&lep_truthParentStatus_3,"lep_truthParentStatus_3/I");
  tree->Branch("lep_truthPt_3",&lep_truthPt_3,"lep_truthPt_3/F");
  tree->Branch("lep_truthEta_3",&lep_truthEta_3,"lep_truthEta_3/F");
  tree->Branch("lep_truthPhi_3",&lep_truthPhi_3,"lep_truthPhi_3/F");
  tree->Branch("lep_truthM_3",&lep_truthM_3,"lep_truthM_3/F");
  tree->Branch("lep_truthE_3",&lep_truthE_3,"lep_truthE_3/F");
  tree->Branch("lep_truthRapidity_3",&lep_truthRapidity_3,"lep_truthRapidity_3/F");
  tree->Branch("lep_ambiguityType_3",&lep_ambiguityType_3,"lep_ambiguityType_3/b");
  tree->Branch("lep_SFIDLoose_3",&lep_SFIDLoose_3,"lep_SFIDLoose_3/F");
  tree->Branch("lep_SFIDTight_3",&lep_SFIDTight_3,"lep_SFIDTight_3/F");
  tree->Branch("lep_SFTrigLoose_3",&lep_SFTrigLoose_3,"lep_SFTrigLoose_3/F");
  tree->Branch("lep_SFTrigTight_3",&lep_SFTrigTight_3,"lep_SFTrigTight_3/F");
  tree->Branch("lep_EffTrigLoose_3",&lep_EffTrigLoose_3,"lep_EffTrigLoose_3/F");
  tree->Branch("lep_EffTrigTight_3",&lep_EffTrigTight_3,"lep_EffTrigTight_3/F");
  tree->Branch("lep_SFIsoLoose_3",&lep_SFIsoLoose_3,"lep_SFIsoLoose_3/F");
  tree->Branch("lep_SFIsoTight_3",&lep_SFIsoTight_3,"lep_SFIsoTight_3/F");
  tree->Branch("lep_SFReco_3",&lep_SFReco_3,"lep_SFReco_3/F");
  tree->Branch("lep_SFTTVA_3",&lep_SFTTVA_3,"lep_SFTTVA_3/F");
  tree->Branch("lep_SFObjLoose_3",&lep_SFObjLoose_3,"lep_SFObjLoose_3/F");
  tree->Branch("lep_SFObjTight_3",&lep_SFObjTight_3,"lep_SFObjTight_3/F");
  tree->Branch("lep_nInnerPix_3",&lep_nInnerPix_3,"lep_nInnerPix_3/I");
  tree->Branch("lep_firstEgMotherPdgId_3",&lep_firstEgMotherPdgId_3,"lep_firstEgMotherPdgId_3/I");
  tree->Branch("lep_firstEgMotherTruthType_3",&lep_firstEgMotherTruthType_3,"lep_firstEgMotherTruthType_3/I");
  tree->Branch("lep_firstEgMotherTruthOrigin_3",&lep_firstEgMotherTruthOrigin_3,"lep_firstEgMotherTruthOrigin_3/I");
  tree->Branch("lep_ID_4",&lep_ID_4,"lep_ID_4/F");
  tree->Branch("lep_Index_4",&lep_Index_4,"lep_Index_4/I");
  tree->Branch("lep_Pt_4",&lep_Pt_4,"lep_Pt_4/F");
  tree->Branch("lep_E_4",&lep_E_4,"lep_E_4/F");
  tree->Branch("lep_Eta_4",&lep_Eta_4,"lep_Eta_4/F");
  tree->Branch("lep_Phi_4",&lep_Phi_4,"lep_Phi_4/F");
  tree->Branch("lep_EtaBE2_4",&lep_EtaBE2_4,"lep_EtaBE2_4/F");
  tree->Branch("lep_topoEtcone20_4",&lep_topoEtcone20_4,"lep_topoEtcone20_4/F");
  tree->Branch("lep_topoEtcone30_4",&lep_topoEtcone30_4,"lep_topoEtcone30_4/F");
  tree->Branch("lep_topoEtcone40_4",&lep_topoEtcone40_4,"lep_topoEtcone40_4/F");
  tree->Branch("lep_ptVarcone20_4",&lep_ptVarcone20_4,"lep_ptVarcone20_4/F");
  tree->Branch("lep_ptVarcone30_4",&lep_ptVarcone30_4,"lep_ptVarcone30_4/F");
  tree->Branch("lep_ptVarcone40_4",&lep_ptVarcone40_4,"lep_ptVarcone40_4/F");
  tree->Branch("lep_sigd0PV_4",&lep_sigd0PV_4,"lep_sigd0PV_4/F");
  tree->Branch("lep_Z0SinTheta_4",&lep_Z0SinTheta_4,"lep_Z0SinTheta_4/F");
  tree->Branch("lep_d0_4",&lep_d0_4,"lep_d0_4/F");
  tree->Branch("lep_z0_4",&lep_z0_4,"lep_z0_4/F");
  tree->Branch("lep_vz_4",&lep_vz_4,"lep_vz_4/F");
  tree->Branch("lep_deltaz0_4",&lep_deltaz0_4,"lep_deltaz0_4/F");
  tree->Branch("lep_isTightLH_4",&lep_isTightLH_4,"lep_isTightLH_4/B");
  tree->Branch("lep_isMediumLH_4",&lep_isMediumLH_4,"lep_isMediumLH_4/B");
  tree->Branch("lep_isLooseLH_4",&lep_isLooseLH_4,"lep_isLooseLH_4/B");
  tree->Branch("lep_isTight_4",&lep_isTight_4,"lep_isTight_4/B");
  tree->Branch("lep_isMedium_4",&lep_isMedium_4,"lep_isMedium_4/B");
  tree->Branch("lep_isLoose_4",&lep_isLoose_4,"lep_isLoose_4/B");
  tree->Branch("lep_isolationLooseTrackOnly_4",&lep_isolationLooseTrackOnly_4,"lep_isolationLooseTrackOnly_4/I");
  tree->Branch("lep_isolationLoose_4",&lep_isolationLoose_4,"lep_isolationLoose_4/I");
  tree->Branch("lep_isolationGradient_4",&lep_isolationGradient_4,"lep_isolationGradient_4/I");
  tree->Branch("lep_isolationGradientLoose_4",&lep_isolationGradientLoose_4,"lep_isolationGradientLoose_4/I");
  tree->Branch("lep_isolationFixedCutTight_4",&lep_isolationFixedCutTight_4,"lep_isolationFixedCutTight_4/I");
  tree->Branch("lep_isolationFixedCutTightTrackOnly_4",&lep_isolationFixedCutTightTrackOnly_4,"lep_isolationFixedCutTightTrackOnly_4/I");
  tree->Branch("lep_isolationFixedCutLoose_4",&lep_isolationFixedCutLoose_4,"lep_isolationFixedCutLoose_4/I");
  tree->Branch("lep_isTrigMatch_4",&lep_isTrigMatch_4,"lep_isTrigMatch_4/B");
  tree->Branch("lep_isTrigMatchDLT_4",&lep_isTrigMatchDLT_4,"lep_isTrigMatchDLT_4/B");
  tree->Branch("lep_isPrompt_4",&lep_isPrompt_4,"lep_isPrompt_4/B");
  tree->Branch("lep_isFakeLep_4",&lep_isFakeLep_4,"lep_isFakeLep_4/B");
  tree->Branch("lep_isQMisID_4",&lep_isQMisID_4,"lep_isQMisID_4/B");
  tree->Branch("lep_isConvPh_4",&lep_isConvPh_4,"lep_isConvPh_4/B");
  tree->Branch("lep_isExtConvPh_4",&lep_isExtConvPh_4,"lep_isExtConvPh_4/B");
  tree->Branch("lep_isIntConvPh_4",&lep_isIntConvPh_4,"lep_isIntConvPh_4/B");
  tree->Branch("lep_isISR_FSR_Ph_4",&lep_isISR_FSR_Ph_4,"lep_isISR_FSR_Ph_4/B");
  tree->Branch("lep_isBrems_4",&lep_isBrems_4,"lep_isBrems_4/B");
  tree->Branch("lep_chargeIDBDTLoose_4",&lep_chargeIDBDTLoose_4,"lep_chargeIDBDTLoose_4/F");
  tree->Branch("lep_chargeIDBDTMedium_4",&lep_chargeIDBDTMedium_4,"lep_chargeIDBDTMedium_4/F");
  tree->Branch("lep_chargeIDBDTTight_4",&lep_chargeIDBDTTight_4,"lep_chargeIDBDTTight_4/F");
  tree->Branch("lep_promptLeptonInput_sv1_jf_ntrkv_4",&lep_promptLeptonInput_sv1_jf_ntrkv_4,"lep_promptLeptonInput_sv1_jf_ntrkv_4/S");
  tree->Branch("lep_promptLeptonInput_TrackJetNTrack_4",&lep_promptLeptonInput_TrackJetNTrack_4,"lep_promptLeptonInput_TrackJetNTrack_4/S");
  tree->Branch("lep_promptLeptonInput_DL1mu_4",&lep_promptLeptonInput_DL1mu_4,"lep_promptLeptonInput_DL1mu_4/F");
  tree->Branch("lep_promptLeptonInput_DRlj_4",&lep_promptLeptonInput_DRlj_4,"lep_promptLeptonInput_DRlj_4/F");
  tree->Branch("lep_promptLeptonInput_LepJetPtFrac_4",&lep_promptLeptonInput_LepJetPtFrac_4,"lep_promptLeptonInput_LepJetPtFrac_4/F");
  tree->Branch("lep_promptLeptonInput_PtFrac_4",&lep_promptLeptonInput_PtFrac_4,"lep_promptLeptonInput_PtFrac_4/F");
  tree->Branch("lep_promptLeptonInput_PtRel_4",&lep_promptLeptonInput_PtRel_4,"lep_promptLeptonInput_PtRel_4/F");
  tree->Branch("lep_promptLeptonInput_ip2_4",&lep_promptLeptonInput_ip2_4,"lep_promptLeptonInput_ip2_4/F");
  tree->Branch("lep_promptLeptonInput_ip3_4",&lep_promptLeptonInput_ip3_4,"lep_promptLeptonInput_ip3_4/F");
  tree->Branch("lep_promptLeptonInput_rnnip_4",&lep_promptLeptonInput_rnnip_4,"lep_promptLeptonInput_rnnip_4/F");
  tree->Branch("lep_promptLeptonIso_TagWeight_4",&lep_promptLeptonIso_TagWeight_4,"lep_promptLeptonIso_TagWeight_4/F");
  tree->Branch("lep_promptLeptonVeto_TagWeight_4",&lep_promptLeptonVeto_TagWeight_4,"lep_promptLeptonVeto_TagWeight_4/F");
  tree->Branch("lep_jet_Pt_4",&lep_jet_Pt_4,"lep_jet_Pt_4/F");
  tree->Branch("lep_jet_nTrk_4",&lep_jet_nTrk_4,"lep_jet_nTrk_4/F");
  tree->Branch("lep_jet_sumPtTrk_4",&lep_jet_sumPtTrk_4,"lep_jet_sumPtTrk_4/F");
  tree->Branch("lep_jet_mv2c10_4",&lep_jet_mv2c10_4,"lep_jet_mv2c10_4/F");
  tree->Branch("lep_jet_deltaR_4",&lep_jet_deltaR_4,"lep_jet_deltaR_4/F");
  tree->Branch("lep_jet_ptRel_4",&lep_jet_ptRel_4,"lep_jet_ptRel_4/F");
  tree->Branch("lep_jet_ptOverMuPt_4",&lep_jet_ptOverMuPt_4,"lep_jet_ptOverMuPt_4/F");
  tree->Branch("lep_jet_BDT_4",&lep_jet_BDT_4,"lep_jet_BDT_4/F");
  tree->Branch("lep_isTruthMatched_4",&lep_isTruthMatched_4,"lep_isTruthMatched_4/B");
  tree->Branch("lep_truthType_4",&lep_truthType_4,"lep_truthType_4/I");
  tree->Branch("lep_truthOrigin_4",&lep_truthOrigin_4,"lep_truthOrigin_4/I");
  tree->Branch("lep_truthPdgId_4",&lep_truthPdgId_4,"lep_truthPdgId_4/I");
  tree->Branch("lep_truthStatus_4",&lep_truthStatus_4,"lep_truthStatus_4/I");
  tree->Branch("lep_truthParentType_4",&lep_truthParentType_4,"lep_truthParentType_4/I");
  tree->Branch("lep_truthParentOrigin_4",&lep_truthParentOrigin_4,"lep_truthParentOrigin_4/I");
  tree->Branch("lep_truthParentPdgId_4",&lep_truthParentPdgId_4,"lep_truthParentPdgId_4/I");
  tree->Branch("lep_truthParentStatus_4",&lep_truthParentStatus_4,"lep_truthParentStatus_4/I");
  tree->Branch("lep_truthPt_4",&lep_truthPt_4,"lep_truthPt_4/F");
  tree->Branch("lep_truthEta_4",&lep_truthEta_4,"lep_truthEta_4/F");
  tree->Branch("lep_truthPhi_4",&lep_truthPhi_4,"lep_truthPhi_4/F");
  tree->Branch("lep_truthM_4",&lep_truthM_4,"lep_truthM_4/F");
  tree->Branch("lep_truthE_4",&lep_truthE_4,"lep_truthE_4/F");
  tree->Branch("lep_truthRapidity_4",&lep_truthRapidity_4,"lep_truthRapidity_4/F");
  tree->Branch("lep_ambiguityType_4",&lep_ambiguityType_4,"lep_ambiguityType_4/b");
  tree->Branch("lep_SFIDLoose_4",&lep_SFIDLoose_4,"lep_SFIDLoose_4/F");
  tree->Branch("lep_SFIDTight_4",&lep_SFIDTight_4,"lep_SFIDTight_4/F");
  tree->Branch("lep_SFTrigLoose_4",&lep_SFTrigLoose_4,"lep_SFTrigLoose_4/F");
  tree->Branch("lep_SFTrigTight_4",&lep_SFTrigTight_4,"lep_SFTrigTight_4/F");
  tree->Branch("lep_EffTrigLoose_4",&lep_EffTrigLoose_4,"lep_EffTrigLoose_4/F");
  tree->Branch("lep_EffTrigTight_4",&lep_EffTrigTight_4,"lep_EffTrigTight_4/F");
  tree->Branch("lep_SFIsoLoose_4",&lep_SFIsoLoose_4,"lep_SFIsoLoose_4/F");
  tree->Branch("lep_SFIsoTight_4",&lep_SFIsoTight_4,"lep_SFIsoTight_4/F");
  tree->Branch("lep_SFReco_4",&lep_SFReco_4,"lep_SFReco_4/F");
  tree->Branch("lep_SFTTVA_4",&lep_SFTTVA_4,"lep_SFTTVA_4/F");
  tree->Branch("lep_SFObjLoose_4",&lep_SFObjLoose_4,"lep_SFObjLoose_4/F");
  tree->Branch("lep_SFObjTight_4",&lep_SFObjTight_4,"lep_SFObjTight_4/F");
  tree->Branch("lep_nInnerPix_4",&lep_nInnerPix_4,"lep_nInnerPix_4/I");
  tree->Branch("lep_firstEgMotherPdgId_4",&lep_firstEgMotherPdgId_4,"lep_firstEgMotherPdgId_4/I");
  tree->Branch("lep_firstEgMotherTruthType_4",&lep_firstEgMotherTruthType_4,"lep_firstEgMotherTruthType_4/I");
  tree->Branch("lep_firstEgMotherTruthOrigin_4",&lep_firstEgMotherTruthOrigin_4,"lep_firstEgMotherTruthOrigin_4/I");
  tree->Branch("tau_pt_0",&tau_pt_0,"tau_pt_0/F");
  tree->Branch("tau_eta_0",&tau_eta_0,"tau_eta_0/F");
  tree->Branch("tau_phi_0",&tau_phi_0,"tau_phi_0/F");
  tree->Branch("tau_charge_0",&tau_charge_0,"tau_charge_0/F");
  tree->Branch("tau_E_0",&tau_E_0,"tau_E_0/F");
  tree->Branch("tau_BDTJetScore_0",&tau_BDTJetScore_0,"tau_BDTJetScore_0/D");
  tree->Branch("tau_JetBDTSigLoose_0",&tau_JetBDTSigLoose_0,"tau_JetBDTSigLoose_0/I");
  tree->Branch("tau_JetBDTSigMedium_0",&tau_JetBDTSigMedium_0,"tau_JetBDTSigMedium_0/I");
  tree->Branch("tau_JetBDTSigTight_0",&tau_JetBDTSigTight_0,"tau_JetBDTSigTight_0/I");
  tree->Branch("tau_numTrack_0",&tau_numTrack_0,"tau_numTrack_0/I");
  tree->Branch("tau_isHadronic_0",&tau_isHadronic_0,"tau_isHadronic_0/I");
  tree->Branch("tau_tagWeightBin_0",&tau_tagWeightBin_0,"tau_tagWeightBin_0/I");
  tree->Branch("tau_MV2c10_0",&tau_MV2c10_0,"tau_MV2c10_0/F");
  tree->Branch("tau_fromPV_0",&tau_fromPV_0,"tau_fromPV_0/B");
  tree->Branch("tau_SFTight_0",&tau_SFTight_0,"tau_SFTight_0/F");
  tree->Branch("tau_SFLoose_0",&tau_SFLoose_0,"tau_SFLoose_0/F");
  tree->Branch("tau_passEleOLR_0",&tau_passEleOLR_0,"tau_passEleOLR_0/I");
  tree->Branch("tau_passEleBDT_0",&tau_passEleBDT_0,"tau_passEleBDT_0/I");
  tree->Branch("tau_passMuonOLR_0",&tau_passMuonOLR_0,"tau_passMuonOLR_0/I");
  tree->Branch("tau_BDTEleScoreSigTrans_0",&tau_BDTEleScoreSigTrans_0,"tau_BDTEleScoreSigTrans_0/F");
  tree->Branch("tau_BDTJetScoreSigTrans_0",&tau_BDTJetScoreSigTrans_0,"tau_BDTJetScoreSigTrans_0/F");
  tree->Branch("tau_truthOrigin_0",&tau_truthOrigin_0,"tau_truthOrigin_0/I");
  tree->Branch("tau_truthType_0",&tau_truthType_0,"tau_truthType_0/I");
  tree->Branch("tau_truthJetFlavour_0",&tau_truthJetFlavour_0,"tau_truthJetFlavour_0/I");
  tree->Branch("tau_promptTauInput_TrackJetNTrack_0",&tau_promptTauInput_TrackJetNTrack_0,"tau_promptTauInput_TrackJetNTrack_0/S");
  tree->Branch("tau_promptTauInput_JetF_0",&tau_promptTauInput_JetF_0,"tau_promptTauInput_JetF_0/F");
  tree->Branch("tau_promptTauInput_DRlj_0",&tau_promptTauInput_DRlj_0,"tau_promptTauInput_DRlj_0/F");
  tree->Branch("tau_promptTauInput_LepJetPtFrac_0",&tau_promptTauInput_LepJetPtFrac_0,"tau_promptTauInput_LepJetPtFrac_0/F");
  tree->Branch("tau_promptTauInput_SV1_0",&tau_promptTauInput_SV1_0,"tau_promptTauInput_SV1_0/F");
  tree->Branch("tau_promptTauInput_MV2c10rnn_0",&tau_promptTauInput_MV2c10rnn_0,"tau_promptTauInput_MV2c10rnn_0/F");
  tree->Branch("tau_promptTauInput_ip2_0",&tau_promptTauInput_ip2_0,"tau_promptTauInput_ip2_0/F");
  tree->Branch("tau_promptTauInput_ip3_0",&tau_promptTauInput_ip3_0,"tau_promptTauInput_ip3_0/F");
  tree->Branch("tau_promptTauInput_rnnip_0",&tau_promptTauInput_rnnip_0,"tau_promptTauInput_rnnip_0/F");
  tree->Branch("tau_promptTauInput_MV2c10_0",&tau_promptTauInput_MV2c10_0,"tau_promptTauInput_MV2c10_0/F");
  tree->Branch("tau_promptTauVeto_0",&tau_promptTauVeto_0,"tau_promptTauVeto_0/F");
  tree->Branch("tau_promptTauIso_0",&tau_promptTauIso_0,"tau_promptTauIso_0/F");
  tree->Branch("tau_pt_1",&tau_pt_1,"tau_pt_1/F");
  tree->Branch("tau_eta_1",&tau_eta_1,"tau_eta_1/F");
  tree->Branch("tau_phi_1",&tau_phi_1,"tau_phi_1/F");
  tree->Branch("tau_charge_1",&tau_charge_1,"tau_charge_1/F");
  tree->Branch("tau_E_1",&tau_E_1,"tau_E_1/F");
  tree->Branch("tau_BDTJetScore_1",&tau_BDTJetScore_1,"tau_BDTJetScore_1/D");
  tree->Branch("tau_JetBDTSigLoose_1",&tau_JetBDTSigLoose_1,"tau_JetBDTSigLoose_1/I");
  tree->Branch("tau_JetBDTSigMedium_1",&tau_JetBDTSigMedium_1,"tau_JetBDTSigMedium_1/I");
  tree->Branch("tau_JetBDTSigTight_1",&tau_JetBDTSigTight_1,"tau_JetBDTSigTight_1/I");
  tree->Branch("tau_numTrack_1",&tau_numTrack_1,"tau_numTrack_1/I");
  tree->Branch("tau_isHadronic_1",&tau_isHadronic_1,"tau_isHadronic_1/I");
  tree->Branch("tau_tagWeightBin_1",&tau_tagWeightBin_1,"tau_tagWeightBin_1/I");
  tree->Branch("tau_MV2c10_1",&tau_MV2c10_1,"tau_MV2c10_1/F");
  tree->Branch("tau_fromPV_1",&tau_fromPV_1,"tau_fromPV_1/B");
  tree->Branch("tau_SFTight_1",&tau_SFTight_1,"tau_SFTight_1/F");
  tree->Branch("tau_SFLoose_1",&tau_SFLoose_1,"tau_SFLoose_1/F");
  tree->Branch("tau_passEleOLR_1",&tau_passEleOLR_1,"tau_passEleOLR_1/I");
  tree->Branch("tau_passEleBDT_1",&tau_passEleBDT_1,"tau_passEleBDT_1/I");
  tree->Branch("tau_passMuonOLR_1",&tau_passMuonOLR_1,"tau_passMuonOLR_1/I");
  tree->Branch("tau_BDTEleScoreSigTrans_1",&tau_BDTEleScoreSigTrans_1,"tau_BDTEleScoreSigTrans_1/F");
  tree->Branch("tau_BDTJetScoreSigTrans_1",&tau_BDTJetScoreSigTrans_1,"tau_BDTJetScoreSigTrans_1/F");
  tree->Branch("tau_truthOrigin_1",&tau_truthOrigin_1,"tau_truthOrigin_1/I");
  tree->Branch("tau_truthType_1",&tau_truthType_1,"tau_truthType_1/I");
  tree->Branch("tau_truthJetFlavour_1",&tau_truthJetFlavour_1,"tau_truthJetFlavour_1/I");
  tree->Branch("tau_promptTauInput_TrackJetNTrack_1",&tau_promptTauInput_TrackJetNTrack_1,"tau_promptTauInput_TrackJetNTrack_1/S");
  tree->Branch("tau_promptTauInput_JetF_1",&tau_promptTauInput_JetF_1,"tau_promptTauInput_JetF_1/F");
  tree->Branch("tau_promptTauInput_DRlj_1",&tau_promptTauInput_DRlj_1,"tau_promptTauInput_DRlj_1/F");
  tree->Branch("tau_promptTauInput_LepJetPtFrac_1",&tau_promptTauInput_LepJetPtFrac_1,"tau_promptTauInput_LepJetPtFrac_1/F");
  tree->Branch("tau_promptTauInput_SV1_1",&tau_promptTauInput_SV1_1,"tau_promptTauInput_SV1_1/F");
  tree->Branch("tau_promptTauInput_MV2c10rnn_1",&tau_promptTauInput_MV2c10rnn_1,"tau_promptTauInput_MV2c10rnn_1/F");
  tree->Branch("tau_promptTauInput_ip2_1",&tau_promptTauInput_ip2_1,"tau_promptTauInput_ip2_1/F");
  tree->Branch("tau_promptTauInput_ip3_1",&tau_promptTauInput_ip3_1,"tau_promptTauInput_ip3_1/F");
  tree->Branch("tau_promptTauInput_rnnip_1",&tau_promptTauInput_rnnip_1,"tau_promptTauInput_rnnip_1/F");
  tree->Branch("tau_promptTauInput_MV2c10_1",&tau_promptTauInput_MV2c10_1,"tau_promptTauInput_MV2c10_1/F");
  tree->Branch("tau_promptTauVeto_1",&tau_promptTauVeto_1,"tau_promptTauVeto_1/F");
  tree->Branch("tau_promptTauIso_1",&tau_promptTauIso_1,"tau_promptTauIso_1/F");
  tree->Branch("onelep_type",&onelep_type,"onelep_type/I");
  tree->Branch("dilep_type",&dilep_type,"dilep_type/I");
  tree->Branch("trilep_type",&trilep_type,"trilep_type/I");
  tree->Branch("quadlep_type",&quadlep_type,"quadlep_type/I");
  tree->Branch("total_charge",&total_charge,"total_charge/I");
  tree->Branch("total_leptons",&total_leptons,"total_leptons/I");
  tree->Branch("isQMisIDEvent",&isQMisIDEvent,"isQMisIDEvent/B");
  tree->Branch("isFakeEvent",&isFakeEvent,"isFakeEvent/B");
  tree->Branch("isLepFromPhEvent",&isLepFromPhEvent,"isLepFromPhEvent/B");
  tree->Branch("Mll01",&Mll01,"Mll01/F");
  tree->Branch("Ptll01",&Ptll01,"Ptll01/F");
  tree->Branch("DRll01",&DRll01,"DRll01/F");
  tree->Branch("matchDLTll01",&matchDLTll01,"matchDLTll01/B");
  tree->Branch("Mlll012",&Mlll012,"Mlll012/F");
  tree->Branch("Mllll0123",&Mllll0123,"Mllll0123/F");
  tree->Branch("Mllll0124",&Mllll0124,"Mllll0124/F");
  tree->Branch("Mlll013",&Mlll013,"Mlll013/F");
  tree->Branch("Mllll0134",&Mllll0134,"Mllll0134/F");
  tree->Branch("Mlll014",&Mlll014,"Mlll014/F");
  tree->Branch("Mll02",&Mll02,"Mll02/F");
  tree->Branch("Ptll02",&Ptll02,"Ptll02/F");
  tree->Branch("DRll02",&DRll02,"DRll02/F");
  tree->Branch("matchDLTll02",&matchDLTll02,"matchDLTll02/B");
  tree->Branch("Mlll023",&Mlll023,"Mlll023/F");
  tree->Branch("Mllll0234",&Mllll0234,"Mllll0234/F");
  tree->Branch("Mlll024",&Mlll024,"Mlll024/F");
  tree->Branch("Mll03",&Mll03,"Mll03/F");
  tree->Branch("Ptll03",&Ptll03,"Ptll03/F");
  tree->Branch("DRll03",&DRll03,"DRll03/F");
  tree->Branch("matchDLTll03",&matchDLTll03,"matchDLTll03/B");
  tree->Branch("Mlll034",&Mlll034,"Mlll034/F");
  tree->Branch("Mll04",&Mll04,"Mll04/F");
  tree->Branch("Ptll04",&Ptll04,"Ptll04/F");
  tree->Branch("DRll04",&DRll04,"DRll04/F");
  tree->Branch("matchDLTll04",&matchDLTll04,"matchDLTll04/B");
  tree->Branch("Mll12",&Mll12,"Mll12/F");
  tree->Branch("Ptll12",&Ptll12,"Ptll12/F");
  tree->Branch("DRll12",&DRll12,"DRll12/F");
  tree->Branch("matchDLTll12",&matchDLTll12,"matchDLTll12/B");
  tree->Branch("Mlll123",&Mlll123,"Mlll123/F");
  tree->Branch("Mllll1234",&Mllll1234,"Mllll1234/F");
  tree->Branch("Mlll124",&Mlll124,"Mlll124/F");
  tree->Branch("Mll13",&Mll13,"Mll13/F");
  tree->Branch("Ptll13",&Ptll13,"Ptll13/F");
  tree->Branch("DRll13",&DRll13,"DRll13/F");
  tree->Branch("matchDLTll13",&matchDLTll13,"matchDLTll13/B");
  tree->Branch("Mlll134",&Mlll134,"Mlll134/F");
  tree->Branch("Mll14",&Mll14,"Mll14/F");
  tree->Branch("Ptll14",&Ptll14,"Ptll14/F");
  tree->Branch("DRll14",&DRll14,"DRll14/F");
  tree->Branch("matchDLTll14",&matchDLTll14,"matchDLTll14/B");
  tree->Branch("Mll23",&Mll23,"Mll23/F");
  tree->Branch("Ptll23",&Ptll23,"Ptll23/F");
  tree->Branch("DRll23",&DRll23,"DRll23/F");
  tree->Branch("matchDLTll23",&matchDLTll23,"matchDLTll23/B");
  tree->Branch("Mlll234",&Mlll234,"Mlll234/F");
  tree->Branch("Mll24",&Mll24,"Mll24/F");
  tree->Branch("Ptll24",&Ptll24,"Ptll24/F");
  tree->Branch("DRll24",&DRll24,"DRll24/F");
  tree->Branch("matchDLTll24",&matchDLTll24,"matchDLTll24/B");
  tree->Branch("Mll34",&Mll34,"Mll34/F");
  tree->Branch("Ptll34",&Ptll34,"Ptll34/F");
  tree->Branch("DRll34",&DRll34,"DRll34/F");
  tree->Branch("matchDLTll34",&matchDLTll34,"matchDLTll34/B");
  tree->Branch("best_Z_Mll",&best_Z_Mll,"best_Z_Mll/F");
  tree->Branch("best_Z_other_MtLepMet",&best_Z_other_MtLepMet,"best_Z_other_MtLepMet/F");
  tree->Branch("best_Z_other_Mll",&best_Z_other_Mll,"best_Z_other_Mll/F");
  tree->Branch("minOSSFMll",&minOSSFMll,"minOSSFMll/F");
  tree->Branch("minOSMll",&minOSMll,"minOSMll/F");
  tree->Branch("nJets_OR_T",&nJets_OR_T,"nJets_OR_T/I");
  tree->Branch("nJets_OR",&nJets_OR,"nJets_OR/I");
  tree->Branch("nTruthJets",&nTruthJets,"nTruthJets/I");
  tree->Branch("nTruthJets_OR",&nTruthJets_OR,"nTruthJets_OR/I");
  tree->Branch("nJets_OR_T_MV2c10_60",&nJets_OR_T_MV2c10_60,"nJets_OR_T_MV2c10_60/I");
  tree->Branch("nJets_OR_T_MV2c10_70",&nJets_OR_T_MV2c10_70,"nJets_OR_T_MV2c10_70/I");
  tree->Branch("nJets_OR_T_MV2c10_77",&nJets_OR_T_MV2c10_77,"nJets_OR_T_MV2c10_77/I");
  tree->Branch("nJets_OR_T_MV2c10_85",&nJets_OR_T_MV2c10_85,"nJets_OR_T_MV2c10_85/I");
  tree->Branch("nJets_OR_MV2c10_85",&nJets_OR_MV2c10_85,"nJets_OR_MV2c10_85/I");
  tree->Branch("nJets_OR_MV2c10_60",&nJets_OR_MV2c10_60,"nJets_OR_MV2c10_60/I");
  tree->Branch("nJets_OR_MV2c10_77",&nJets_OR_MV2c10_77,"nJets_OR_MV2c10_77/I");
  tree->Branch("nJets_OR_MV2c10_70",&nJets_OR_MV2c10_70,"nJets_OR_MV2c10_70/I");
  tree->Branch("nJets_OR_T_DL1_60",&nJets_OR_T_DL1_60,"nJets_OR_T_DL1_60/I");
  tree->Branch("nJets_OR_T_DL1_70",&nJets_OR_T_DL1_70,"nJets_OR_T_DL1_70/I");
  tree->Branch("nJets_OR_T_DL1_77",&nJets_OR_T_DL1_77,"nJets_OR_T_DL1_77/I");
  tree->Branch("nJets_OR_T_DL1_85",&nJets_OR_T_DL1_85,"nJets_OR_T_DL1_85/I");
  tree->Branch("nJets_OR_DL1_85",&nJets_OR_DL1_85,"nJets_OR_DL1_85/I");
  tree->Branch("nJets_OR_DL1_60",&nJets_OR_DL1_60,"nJets_OR_DL1_60/I");
  tree->Branch("nJets_OR_DL1_77",&nJets_OR_DL1_77,"nJets_OR_DL1_77/I");
  tree->Branch("nJets_OR_DL1_70",&nJets_OR_DL1_70,"nJets_OR_DL1_70/I");
  tree->Branch("nTaus_OR_Pt25",&nTaus_OR_Pt25,"nTaus_OR_Pt25/I");
  tree->Branch("isBlinded",&isBlinded,"isBlinded/O");
  tree->Branch("HT",&HT,"HT/F");
  tree->Branch("HT_lep",&HT_lep,"HT_lep/F");
  tree->Branch("HT_jets",&HT_jets,"HT_jets/F");
  tree->Branch("lead_jetPt",&lead_jetPt,"lead_jetPt/F");
  tree->Branch("lead_jetEta",&lead_jetEta,"lead_jetEta/F");
  tree->Branch("lead_jetPhi",&lead_jetPhi,"lead_jetPhi/F");
  tree->Branch("lead_jetE",&lead_jetE,"lead_jetE/F");
  tree->Branch("sublead_jetPt",&sublead_jetPt,"sublead_jetPt/F");
  tree->Branch("sublead_jetEta",&sublead_jetEta,"sublead_jetEta/F");
  tree->Branch("sublead_jetPhi",&sublead_jetPhi,"sublead_jetPhi/F");
  tree->Branch("sublead_jetE",&sublead_jetE,"sublead_jetE/F");
  tree->Branch("selected_jets",&selected_jets,"vector<short>");
  tree->Branch("selected_jets_T",&selected_jets_T,"vector<short>");
  tree->Branch("selected_jets_mv2c10_Ordrd",&selected_jets_mv2c10_Ordrd,"vector<short>");
  tree->Branch("selected_jets_T_mv2c10_Ordrd",&selected_jets_T_mv2c10_Ordrd,"vector<short>");
  tree->Branch("lepSFIDLoose",&lepSFIDLoose,"lepSFIDLoose/F");
  tree->Branch("lepSFIDTight",&lepSFIDTight,"lepSFIDTight/F");
  tree->Branch("lepSFIsoLoose",&lepSFIsoLoose,"lepSFIsoLoose/F");
  tree->Branch("lepSFIsoTight",&lepSFIsoTight,"lepSFIsoTight/F");
  tree->Branch("lepSFReco",&lepSFReco,"lepSFReco/F");
  tree->Branch("lepSFTTVA",&lepSFTTVA,"lepSFTTVA/F");
  tree->Branch("lepSFTrigLoose",&lepSFTrigLoose,"lepSFTrigLoose/F");
  tree->Branch("lepSFTrigTight",&lepSFTrigTight,"lepSFTrigTight/F");
  tree->Branch("lepSFTrigTightLoose",&lepSFTrigTightLoose,"lepSFTrigTightLoose/F");
  tree->Branch("lepSFTrigLooseTight",&lepSFTrigLooseTight,"lepSFTrigLooseTight/F");
  tree->Branch("lepEffTrigLoose",&lepEffTrigLoose,"lepEffTrigLoose/F");
  tree->Branch("lepEffTrigTight",&lepEffTrigTight,"lepEffTrigTight/F");
  tree->Branch("lepEffTrigTightLoose",&lepEffTrigTightLoose,"lepEffTrigTightLoose/F");
  tree->Branch("lepEffTrigLooseTight",&lepEffTrigLooseTight,"lepEffTrigLooseTight/F");
  tree->Branch("lepDataEffTrigLoose",&lepDataEffTrigLoose,"lepDataEffTrigLoose/F");
  tree->Branch("lepDataEffTrigTight",&lepDataEffTrigTight,"lepDataEffTrigTight/F");
  tree->Branch("lepDataEffTrigTightLoose",&lepDataEffTrigTightLoose,"lepDataEffTrigTightLoose/F");
  tree->Branch("lepDataEffTrigLooseTight",&lepDataEffTrigLooseTight,"lepDataEffTrigLooseTight/F");
  tree->Branch("lepSFObjLoose",&lepSFObjLoose,"lepSFObjLoose/F");
  tree->Branch("lepSFObjTight",&lepSFObjTight,"lepSFObjTight/F");
  tree->Branch("tauSFTight",&tauSFTight,"tauSFTight/F");
  tree->Branch("tauSFLoose",&tauSFLoose,"tauSFLoose/F");
  tree->Branch("lepSFTrigLoose_EL_SF_Trigger_UP",&lepSFTrigLoose_EL_SF_Trigger_UP,"lepSFTrigLoose_EL_SF_Trigger_UP/F");
  tree->Branch("lepSFTrigTight_EL_SF_Trigger_UP",&lepSFTrigTight_EL_SF_Trigger_UP,"lepSFTrigTight_EL_SF_Trigger_UP/F");
  tree->Branch("lepSFTrigTightLoose_EL_SF_Trigger_UP",&lepSFTrigTightLoose_EL_SF_Trigger_UP,"lepSFTrigTightLoose_EL_SF_Trigger_UP/F");
  tree->Branch("lepSFTrigLooseTight_EL_SF_Trigger_UP",&lepSFTrigLooseTight_EL_SF_Trigger_UP,"lepSFTrigLooseTight_EL_SF_Trigger_UP/F");
  tree->Branch("lepEffTrigLoose_EL_SF_Trigger_UP",&lepEffTrigLoose_EL_SF_Trigger_UP,"lepEffTrigLoose_EL_SF_Trigger_UP/F");
  tree->Branch("lepEffTrigTight_EL_SF_Trigger_UP",&lepEffTrigTight_EL_SF_Trigger_UP,"lepEffTrigTight_EL_SF_Trigger_UP/F");
  tree->Branch("lepEffTrigTightLoose_EL_SF_Trigger_UP",&lepEffTrigTightLoose_EL_SF_Trigger_UP,"lepEffTrigTightLoose_EL_SF_Trigger_UP/F");
  tree->Branch("lepEffTrigLooseTight_EL_SF_Trigger_UP",&lepEffTrigLooseTight_EL_SF_Trigger_UP,"lepEffTrigLooseTight_EL_SF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigLoose_EL_SF_Trigger_UP",&lepDataEffTrigLoose_EL_SF_Trigger_UP,"lepDataEffTrigLoose_EL_SF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigTight_EL_SF_Trigger_UP",&lepDataEffTrigTight_EL_SF_Trigger_UP,"lepDataEffTrigTight_EL_SF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigTightLoose_EL_SF_Trigger_UP",&lepDataEffTrigTightLoose_EL_SF_Trigger_UP,"lepDataEffTrigTightLoose_EL_SF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigLooseTight_EL_SF_Trigger_UP",&lepDataEffTrigLooseTight_EL_SF_Trigger_UP,"lepDataEffTrigLooseTight_EL_SF_Trigger_UP/F");
  tree->Branch("lepSFTrigLoose_EL_SF_Trigger_DOWN",&lepSFTrigLoose_EL_SF_Trigger_DOWN,"lepSFTrigLoose_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigTight_EL_SF_Trigger_DOWN",&lepSFTrigTight_EL_SF_Trigger_DOWN,"lepSFTrigTight_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigTightLoose_EL_SF_Trigger_DOWN",&lepSFTrigTightLoose_EL_SF_Trigger_DOWN,"lepSFTrigTightLoose_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigLooseTight_EL_SF_Trigger_DOWN",&lepSFTrigLooseTight_EL_SF_Trigger_DOWN,"lepSFTrigLooseTight_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigLoose_EL_SF_Trigger_DOWN",&lepEffTrigLoose_EL_SF_Trigger_DOWN,"lepEffTrigLoose_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigTight_EL_SF_Trigger_DOWN",&lepEffTrigTight_EL_SF_Trigger_DOWN,"lepEffTrigTight_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigTightLoose_EL_SF_Trigger_DOWN",&lepEffTrigTightLoose_EL_SF_Trigger_DOWN,"lepEffTrigTightLoose_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigLooseTight_EL_SF_Trigger_DOWN",&lepEffTrigLooseTight_EL_SF_Trigger_DOWN,"lepEffTrigLooseTight_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigLoose_EL_SF_Trigger_DOWN",&lepDataEffTrigLoose_EL_SF_Trigger_DOWN,"lepDataEffTrigLoose_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigTight_EL_SF_Trigger_DOWN",&lepDataEffTrigTight_EL_SF_Trigger_DOWN,"lepDataEffTrigTight_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN",&lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN,"lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN",&lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN,"lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigLoose_MU_SF_Trigger_STAT_UP",&lepSFTrigLoose_MU_SF_Trigger_STAT_UP,"lepSFTrigLoose_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_STAT_UP",&lepSFTrigTight_MU_SF_Trigger_STAT_UP,"lepSFTrigTight_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP",&lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP,"lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP",&lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP,"lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepEffTrigLoose_MU_SF_Trigger_STAT_UP",&lepEffTrigLoose_MU_SF_Trigger_STAT_UP,"lepEffTrigLoose_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepEffTrigTight_MU_SF_Trigger_STAT_UP",&lepEffTrigTight_MU_SF_Trigger_STAT_UP,"lepEffTrigTight_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP",&lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP,"lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP",&lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP,"lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP",&lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP,"lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepDataEffTrigTight_MU_SF_Trigger_STAT_UP",&lepDataEffTrigTight_MU_SF_Trigger_STAT_UP,"lepDataEffTrigTight_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP",&lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP,"lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP",&lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP,"lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP/F");
  tree->Branch("lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN",&lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN,"lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_STAT_DOWN",&lepSFTrigTight_MU_SF_Trigger_STAT_DOWN,"lepSFTrigTight_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN",&lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN,"lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN",&lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN,"lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN",&lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN,"lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN",&lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN,"lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN",&lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN,"lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN",&lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN,"lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN/F");
  tree->Branch("lepEffTrigLoose_MU_SF_Trigger_SYST_UP",&lepEffTrigLoose_MU_SF_Trigger_SYST_UP,"lepEffTrigLoose_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepEffTrigTight_MU_SF_Trigger_SYST_UP",&lepEffTrigTight_MU_SF_Trigger_SYST_UP,"lepEffTrigTight_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP",&lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP,"lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP",&lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP,"lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP",&lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP,"lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepDataEffTrigTight_MU_SF_Trigger_SYST_UP",&lepDataEffTrigTight_MU_SF_Trigger_SYST_UP,"lepDataEffTrigTight_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP",&lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP,"lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP",&lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP,"lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP/F");
  tree->Branch("lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN",&lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN,"lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_SYST_DOWN",&lepSFTrigTight_MU_SF_Trigger_SYST_DOWN,"lepSFTrigTight_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN",&lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN,"lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN",&lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN,"lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN",&lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN,"lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepEffTrigTight_MU_SF_Trigger_SYST_DOWN",&lepEffTrigTight_MU_SF_Trigger_SYST_DOWN,"lepEffTrigTight_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN",&lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN,"lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN",&lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN,"lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN",&lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN,"lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN",&lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN,"lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN",&lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN,"lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN",&lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN,"lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN/F");
  tree->Branch("lepSFTrigLoose_EL_EFF_Trigger_UP",&lepSFTrigLoose_EL_EFF_Trigger_UP,"lepSFTrigLoose_EL_EFF_Trigger_UP/F");
  tree->Branch("lepSFTrigTight_EL_EFF_Trigger_UP",&lepSFTrigTight_EL_EFF_Trigger_UP,"lepSFTrigTight_EL_EFF_Trigger_UP/F");
  tree->Branch("lepSFTrigTightLoose_EL_EFF_Trigger_UP",&lepSFTrigTightLoose_EL_EFF_Trigger_UP,"lepSFTrigTightLoose_EL_EFF_Trigger_UP/F");
  tree->Branch("lepSFTrigLooseTight_EL_EFF_Trigger_UP",&lepSFTrigLooseTight_EL_EFF_Trigger_UP,"lepSFTrigLooseTight_EL_EFF_Trigger_UP/F");
  tree->Branch("lepEffTrigLoose_EL_EFF_Trigger_UP",&lepEffTrigLoose_EL_EFF_Trigger_UP,"lepEffTrigLoose_EL_EFF_Trigger_UP/F");
  tree->Branch("lepEffTrigTight_EL_EFF_Trigger_UP",&lepEffTrigTight_EL_EFF_Trigger_UP,"lepEffTrigTight_EL_EFF_Trigger_UP/F");
  tree->Branch("lepEffTrigTightLoose_EL_EFF_Trigger_UP",&lepEffTrigTightLoose_EL_EFF_Trigger_UP,"lepEffTrigTightLoose_EL_EFF_Trigger_UP/F");
  tree->Branch("lepEffTrigLooseTight_EL_EFF_Trigger_UP",&lepEffTrigLooseTight_EL_EFF_Trigger_UP,"lepEffTrigLooseTight_EL_EFF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigLoose_EL_EFF_Trigger_UP",&lepDataEffTrigLoose_EL_EFF_Trigger_UP,"lepDataEffTrigLoose_EL_EFF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigTight_EL_EFF_Trigger_UP",&lepDataEffTrigTight_EL_EFF_Trigger_UP,"lepDataEffTrigTight_EL_EFF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigTightLoose_EL_EFF_Trigger_UP",&lepDataEffTrigTightLoose_EL_EFF_Trigger_UP,"lepDataEffTrigTightLoose_EL_EFF_Trigger_UP/F");
  tree->Branch("lepDataEffTrigLooseTight_EL_EFF_Trigger_UP",&lepDataEffTrigLooseTight_EL_EFF_Trigger_UP,"lepDataEffTrigLooseTight_EL_EFF_Trigger_UP/F");
  tree->Branch("lepSFTrigLoose_EL_EFF_Trigger_DOWN",&lepSFTrigLoose_EL_EFF_Trigger_DOWN,"lepSFTrigLoose_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigTight_EL_EFF_Trigger_DOWN",&lepSFTrigTight_EL_EFF_Trigger_DOWN,"lepSFTrigTight_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigTightLoose_EL_EFF_Trigger_DOWN",&lepSFTrigTightLoose_EL_EFF_Trigger_DOWN,"lepSFTrigTightLoose_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepSFTrigLooseTight_EL_EFF_Trigger_DOWN",&lepSFTrigLooseTight_EL_EFF_Trigger_DOWN,"lepSFTrigLooseTight_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigLoose_EL_EFF_Trigger_DOWN",&lepEffTrigLoose_EL_EFF_Trigger_DOWN,"lepEffTrigLoose_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigTight_EL_EFF_Trigger_DOWN",&lepEffTrigTight_EL_EFF_Trigger_DOWN,"lepEffTrigTight_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigTightLoose_EL_EFF_Trigger_DOWN",&lepEffTrigTightLoose_EL_EFF_Trigger_DOWN,"lepEffTrigTightLoose_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepEffTrigLooseTight_EL_EFF_Trigger_DOWN",&lepEffTrigLooseTight_EL_EFF_Trigger_DOWN,"lepEffTrigLooseTight_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigLoose_EL_EFF_Trigger_DOWN",&lepDataEffTrigLoose_EL_EFF_Trigger_DOWN,"lepDataEffTrigLoose_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigTight_EL_EFF_Trigger_DOWN",&lepDataEffTrigTight_EL_EFF_Trigger_DOWN,"lepDataEffTrigTight_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN",&lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN,"lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN",&lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN,"lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN/F");
  tree->Branch("lepSFObjLoose_EL_SF_Reco_UP",&lepSFObjLoose_EL_SF_Reco_UP,"lepSFObjLoose_EL_SF_Reco_UP/F");
  tree->Branch("lepSFObjTight_EL_SF_Reco_UP",&lepSFObjTight_EL_SF_Reco_UP,"lepSFObjTight_EL_SF_Reco_UP/F");
  tree->Branch("lepSFObjLoose_EL_SF_Reco_DOWN",&lepSFObjLoose_EL_SF_Reco_DOWN,"lepSFObjLoose_EL_SF_Reco_DOWN/F");
  tree->Branch("lepSFObjTight_EL_SF_Reco_DOWN",&lepSFObjTight_EL_SF_Reco_DOWN,"lepSFObjTight_EL_SF_Reco_DOWN/F");
  tree->Branch("lepSFObjLoose_EL_SF_ID_UP",&lepSFObjLoose_EL_SF_ID_UP,"lepSFObjLoose_EL_SF_ID_UP/F");
  tree->Branch("lepSFObjTight_EL_SF_ID_UP",&lepSFObjTight_EL_SF_ID_UP,"lepSFObjTight_EL_SF_ID_UP/F");
  tree->Branch("lepSFObjLoose_EL_SF_ID_DOWN",&lepSFObjLoose_EL_SF_ID_DOWN,"lepSFObjLoose_EL_SF_ID_DOWN/F");
  tree->Branch("lepSFObjTight_EL_SF_ID_DOWN",&lepSFObjTight_EL_SF_ID_DOWN,"lepSFObjTight_EL_SF_ID_DOWN/F");
  tree->Branch("lepSFObjLoose_EL_SF_Isol_UP",&lepSFObjLoose_EL_SF_Isol_UP,"lepSFObjLoose_EL_SF_Isol_UP/F");
  tree->Branch("lepSFObjTight_EL_SF_Isol_UP",&lepSFObjTight_EL_SF_Isol_UP,"lepSFObjTight_EL_SF_Isol_UP/F");
  tree->Branch("lepSFObjLoose_EL_SF_Isol_DOWN",&lepSFObjLoose_EL_SF_Isol_DOWN,"lepSFObjLoose_EL_SF_Isol_DOWN/F");
  tree->Branch("lepSFObjTight_EL_SF_Isol_DOWN",&lepSFObjTight_EL_SF_Isol_DOWN,"lepSFObjTight_EL_SF_Isol_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_STAT_UP",&lepSFObjLoose_MU_SF_ID_STAT_UP,"lepSFObjLoose_MU_SF_ID_STAT_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_UP",&lepSFObjTight_MU_SF_ID_STAT_UP,"lepSFObjTight_MU_SF_ID_STAT_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_STAT_DOWN",&lepSFObjLoose_MU_SF_ID_STAT_DOWN,"lepSFObjLoose_MU_SF_ID_STAT_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_DOWN",&lepSFObjTight_MU_SF_ID_STAT_DOWN,"lepSFObjTight_MU_SF_ID_STAT_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_SYST_UP",&lepSFObjLoose_MU_SF_ID_SYST_UP,"lepSFObjLoose_MU_SF_ID_SYST_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_UP",&lepSFObjTight_MU_SF_ID_SYST_UP,"lepSFObjTight_MU_SF_ID_SYST_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_SYST_DOWN",&lepSFObjLoose_MU_SF_ID_SYST_DOWN,"lepSFObjLoose_MU_SF_ID_SYST_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_DOWN",&lepSFObjTight_MU_SF_ID_SYST_DOWN,"lepSFObjTight_MU_SF_ID_SYST_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP",&lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP,"lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP",&lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP,"lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN",&lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN,"lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN",&lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN,"lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP",&lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP,"lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP",&lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP,"lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN",&lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN,"lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN",&lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN,"lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_Isol_STAT_UP",&lepSFObjLoose_MU_SF_Isol_STAT_UP,"lepSFObjLoose_MU_SF_Isol_STAT_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_Isol_STAT_UP",&lepSFObjTight_MU_SF_Isol_STAT_UP,"lepSFObjTight_MU_SF_Isol_STAT_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_Isol_STAT_DOWN",&lepSFObjLoose_MU_SF_Isol_STAT_DOWN,"lepSFObjLoose_MU_SF_Isol_STAT_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_Isol_STAT_DOWN",&lepSFObjTight_MU_SF_Isol_STAT_DOWN,"lepSFObjTight_MU_SF_Isol_STAT_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_Isol_SYST_UP",&lepSFObjLoose_MU_SF_Isol_SYST_UP,"lepSFObjLoose_MU_SF_Isol_SYST_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_Isol_SYST_UP",&lepSFObjTight_MU_SF_Isol_SYST_UP,"lepSFObjTight_MU_SF_Isol_SYST_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_Isol_SYST_DOWN",&lepSFObjLoose_MU_SF_Isol_SYST_DOWN,"lepSFObjLoose_MU_SF_Isol_SYST_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_Isol_SYST_DOWN",&lepSFObjTight_MU_SF_Isol_SYST_DOWN,"lepSFObjTight_MU_SF_Isol_SYST_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_TTVA_STAT_UP",&lepSFObjLoose_MU_SF_TTVA_STAT_UP,"lepSFObjLoose_MU_SF_TTVA_STAT_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_TTVA_STAT_UP",&lepSFObjTight_MU_SF_TTVA_STAT_UP,"lepSFObjTight_MU_SF_TTVA_STAT_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_TTVA_STAT_DOWN",&lepSFObjLoose_MU_SF_TTVA_STAT_DOWN,"lepSFObjLoose_MU_SF_TTVA_STAT_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_TTVA_STAT_DOWN",&lepSFObjTight_MU_SF_TTVA_STAT_DOWN,"lepSFObjTight_MU_SF_TTVA_STAT_DOWN/F");
  tree->Branch("lepSFObjLoose_MU_SF_TTVA_SYST_UP",&lepSFObjLoose_MU_SF_TTVA_SYST_UP,"lepSFObjLoose_MU_SF_TTVA_SYST_UP/F");
  tree->Branch("lepSFObjTight_MU_SF_TTVA_SYST_UP",&lepSFObjTight_MU_SF_TTVA_SYST_UP,"lepSFObjTight_MU_SF_TTVA_SYST_UP/F");
  tree->Branch("lepSFObjLoose_MU_SF_TTVA_SYST_DOWN",&lepSFObjLoose_MU_SF_TTVA_SYST_DOWN,"lepSFObjLoose_MU_SF_TTVA_SYST_DOWN/F");
  tree->Branch("lepSFObjTight_MU_SF_TTVA_SYST_DOWN",&lepSFObjTight_MU_SF_TTVA_SYST_DOWN,"lepSFObjTight_MU_SF_TTVA_SYST_DOWN/F");
  tree->Branch("tauSFTight_TAU_SF_ELEOLR_TOTAL_UP",&tauSFTight_TAU_SF_ELEOLR_TOTAL_UP,"tauSFTight_TAU_SF_ELEOLR_TOTAL_UP/F");
  tree->Branch("tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP",&tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP,"tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP/F");
  tree->Branch("tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN",&tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN,"tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN/F");
  tree->Branch("tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN",&tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN,"tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN/F");
  tree->Branch("tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP",&tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP,"tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP/F");
  tree->Branch("tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP",&tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP,"tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP/F");
  tree->Branch("tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN",&tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN,"tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN/F");
  tree->Branch("tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN",&tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN,"tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN/F");
  tree->Branch("tauSFTight_TAU_SF_JETID_TOTAL_UP",&tauSFTight_TAU_SF_JETID_TOTAL_UP,"tauSFTight_TAU_SF_JETID_TOTAL_UP/F");
  tree->Branch("tauSFLoose_TAU_SF_JETID_TOTAL_UP",&tauSFLoose_TAU_SF_JETID_TOTAL_UP,"tauSFLoose_TAU_SF_JETID_TOTAL_UP/F");
  tree->Branch("tauSFTight_TAU_SF_JETID_TOTAL_DOWN",&tauSFTight_TAU_SF_JETID_TOTAL_DOWN,"tauSFTight_TAU_SF_JETID_TOTAL_DOWN/F");
  tree->Branch("tauSFLoose_TAU_SF_JETID_TOTAL_DOWN",&tauSFLoose_TAU_SF_JETID_TOTAL_DOWN,"tauSFLoose_TAU_SF_JETID_TOTAL_DOWN/F");
  tree->Branch("tauSFTight_TAU_SF_JETID_HIGHPT_UP",&tauSFTight_TAU_SF_JETID_HIGHPT_UP,"tauSFTight_TAU_SF_JETID_HIGHPT_UP/F");
  tree->Branch("tauSFLoose_TAU_SF_JETID_HIGHPT_UP",&tauSFLoose_TAU_SF_JETID_HIGHPT_UP,"tauSFLoose_TAU_SF_JETID_HIGHPT_UP/F");
  tree->Branch("tauSFTight_TAU_SF_JETID_HIGHPT_DOWN",&tauSFTight_TAU_SF_JETID_HIGHPT_DOWN,"tauSFTight_TAU_SF_JETID_HIGHPT_DOWN/F");
  tree->Branch("tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN",&tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN,"tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN/F");
  tree->Branch("tauSFTight_TAU_SF_RECO_TOTAL_UP",&tauSFTight_TAU_SF_RECO_TOTAL_UP,"tauSFTight_TAU_SF_RECO_TOTAL_UP/F");
  tree->Branch("tauSFLoose_TAU_SF_RECO_TOTAL_UP",&tauSFLoose_TAU_SF_RECO_TOTAL_UP,"tauSFLoose_TAU_SF_RECO_TOTAL_UP/F");
  tree->Branch("tauSFTight_TAU_SF_RECO_TOTAL_DOWN",&tauSFTight_TAU_SF_RECO_TOTAL_DOWN,"tauSFTight_TAU_SF_RECO_TOTAL_DOWN/F");
  tree->Branch("tauSFLoose_TAU_SF_RECO_TOTAL_DOWN",&tauSFLoose_TAU_SF_RECO_TOTAL_DOWN,"tauSFLoose_TAU_SF_RECO_TOTAL_DOWN/F");
  tree->Branch("tauSFTight_TAU_SF_RECO_HIGHPT_UP",&tauSFTight_TAU_SF_RECO_HIGHPT_UP,"tauSFTight_TAU_SF_RECO_HIGHPT_UP/F");
  tree->Branch("tauSFLoose_TAU_SF_RECO_HIGHPT_UP",&tauSFLoose_TAU_SF_RECO_HIGHPT_UP,"tauSFLoose_TAU_SF_RECO_HIGHPT_UP/F");
  tree->Branch("tauSFTight_TAU_SF_RECO_HIGHPT_DOWN",&tauSFTight_TAU_SF_RECO_HIGHPT_DOWN,"tauSFTight_TAU_SF_RECO_HIGHPT_DOWN/F");
  tree->Branch("tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN",&tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN,"tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN/F");
  tree->Branch("mc_norm",&mc_norm,"mc_norm/D");
  tree->Branch("l2tau_bdt",&l2tau_bdt,"l2tau_bdt/D");
  tree->Branch("tau_leadpt",&tau_leadpt,"tau_leadpt/D");
  tree->Branch("tau_subpt",&tau_subpt,"tau_subpt/D");
  tree->Branch("tau_btag70_0",&tau_btag70_0,"tau_btag70_0/D");
  tree->Branch("tau_tight_0",&tau_tight_0,"tau_tight_0/D");
  tree->Branch("tau_truth_0",&tau_truth_0,"tau_truth_0/I");
  tree->Branch("tau_btag70_1",&tau_btag70_1,"tau_btag70_1/D");
  tree->Branch("tau_tight_1",&tau_tight_1,"tau_tight_1/D");
  tree->Branch("tau_truth_1",&tau_truth_1,"tau_truth_1/I");
  tree->Branch("l2tau_htjets",&l2tau_htjets,"l2tau_htjets/D");
  tree->Branch("l2tau_jjdr",&l2tau_jjdr,"l2tau_jjdr/D");
  tree->Branch("l2tau_mtautau",&l2tau_mtautau,"l2tau_mtautau/D");
  tree->Branch("Channel",&Channel,"Channel/I");
  tree->Branch("Drhwwvis",&Drhwwvis,"Drhwwvis/D");
  tree->Branch("Mtwbvis",&Mtwbvis,"Mtwbvis/D");
  tree->Branch("Mhwwvis",&Mhwwvis,"Mhwwvis/D");
  tree->Branch("Mhwwqvis",&Mhwwqvis,"Mhwwqvis/D");
  tree->Branch("Msum",&Msum,"Msum/D");
  tree->Branch("Pthwl0",&Pthwl0,"Pthwl0/D");
  tree->Branch("Ptlep",&Ptlep,"Ptlep/D");
  tree->Branch("Pthwj",&Pthwj,"Pthwj/D");
  tree->Branch("Ptqj",&Ptqj,"Ptqj/D");
  tree->Branch("Ptbj",&Ptbj,"Ptbj/D");
  tree->Branch("Chisqmin",&Chisqmin,"Chisqmin/D");
  tree->Branch("Chisqmax",&Chisqmax,"Chisqmax/D");
  tree->Branch("Lepwiso",&Lepwiso,"Lepwiso/D");
  tree->Branch("Lepiso",&Lepiso,"Lepiso/D");
  tree->Branch("Bdt",&Bdt,"Bdt/D");
  tree->Branch("BdtvsttV",&BdtvsttV,"BdtvsttV/D");
}
