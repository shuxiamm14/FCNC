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
    for (int k = 0; k < 2; ++k){
      for (int i = 0; i < 4; ++i){
        printf("adding region: %s\n", (regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
        tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + bwps[i]);
        tau_plots->add_region(regions[j] + "_" + nprong[k] + "_" + "veto" + bwps[i]);
      }
    }

  TLorentzVector v1;
  for(int i = 0 ; i < 2 ; ++i){
    taus_v.push_back(v1);
    forFit.Add(&(taus_v[i]));
  }
  forFit.Add(&bjet_v);
  forFit.Add(&cjet_v);
  forFit.Add(&lep_v);
  forFit.Add(&mets);
}

nominal::~nominal(){
  deletepointer(tau_plots);
  deletepointer(gM);
}

void nominal::fill_tau(TString region, int nprong, TString sample){
  for (int i = 0; i < 4; ++i){
    if(tau_MV2c10_0>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[i]).Data(), sample.Data());
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_"+bwps[i]);
    }
    if(tau_MV2c10_0<btagwpCut[i]) {
      tau_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_"+"veto"+bwps[i]);
    }
  }
}


void nominal::init_sample(TString sample, TString sampletitle){

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

void nominal::Loop(TTree *inputtree, TString samplename)
{
  Init(inputtree);
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
      (RunYear>=2016 && (HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1)); // assuming triggers for 2017 is same for 2016 

    if (!basic_selection) continue;

    bool trig_match = (lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
    bool SLtrig_match = 
      ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
    	(RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 )))&&lep_isTrigMatch_0;

    weight = (mc_channel_number>0&&!(mc_channel_number>2014&&mc_channel_number<2018))?mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_MV2c10_FixedCutBEff_70*JVT_EventWeight*SherpaNJetWeight*((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0; 
//===============================find leading b,non b jets===============================
    leading_b = -1;
    leading_ljet = -1;
    pt_b = 0;
    pt_ljet = 0;
    for (int i = 0; i < m_jet_flavor_weight_MV2c10->size(); ++i)
    {
      if((*m_jet_flavor_weight_MV2c10)[i] > 0.83 && leading_b == -1) {
        leading_b = i;
        pt_b = (*m_jet_pt)[i];
      }else if((*m_jet_flavor_weight_MV2c10)[i] < 0.83 && leading_ljet == -1){
        leading_ljet = i;
        pt_ljet = (*m_jet_pt)[i];
      }
    }
//===============================define regions, find c-jet===============================
    map<TString, bool> ifregions;
    ifregions["reg1l1tau1b2j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T==3 && nTaus_OR_Pt25==1;
    ifregions["reg1l1tau1b3j"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T>4 && nTaus_OR_Pt25==1;
    ifregions["reg1l2tau1bnj"]  = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70==1 && nJets_OR_T>=2 && nTaus_OR_Pt25>=2;
    if(ifregions["reg1l2tau1bnj"]){
      cjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_ljet],(*m_jet_eta)[leading_ljet],(*m_jet_phi)[leading_ljet],(*m_jet_E)[leading_ljet]);
      for (int i = 0; i < 2; ++i) taus_v[i].SetPtEtaPhiE((*m_tau_pt)[i],(*m_tau_eta)[i],(*m_tau_phi)[i],(*m_tau_E)[i]);
      if (abs(lep_ID_0)==11) lep_v.SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
      else lep_v.SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
      bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
    }
    else if(ifregions["reg1l1tau1b2j"] || ifregions["reg1l1tau1b3j"]){
      if (abs(lep_ID_0)==11) taus_v[0].SetPtEtaPhiE((*electron_pt)[0],(*electron_eta)[0],(*electron_phi)[0],(*electron_E)[0]);
      else taus_v[0].SetPtEtaPhiE((*muon_pt)[0],(*muon_eta)[0],(*muon_phi)[0],(*muon_E)[0]);
      taus_v[1].SetPtEtaPhiE((*m_tau_pt)[0],(*m_tau_eta)[0],(*m_tau_phi)[0],(*m_tau_E)[0]);
      lep_v.SetPtEtaPhiE(0,0,0,0);
      bjet_v.SetPtEtaPhiE((*m_jet_pt)[leading_b],(*m_jet_eta)[leading_b],(*m_jet_phi)[leading_b],(*m_jet_E)[leading_b]);
      int cjetn = findcjet();
      cjet_v.SetPtEtaPhiE((*m_jet_pt)[cjetn],(*m_jet_eta)[cjetn],(*m_jet_phi)[cjetn],(*m_jet_E)[cjetn]);
    }else continue;
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
      if(iter->second == 1 & iter->first.Contains("tau")  & ( tau_numTrack_0 == 1 | tau_numTrack_0 == 3 ) ) fill_tau(iter->first,tau_numTrack_0,tauorigin);
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
    Float_t met_resol = 13.1+0.50*sqrt(met[2]);
    Double_t chisq = 1e10;

    if(vectors[lep].Pt()!=0){
      neutrino[2].SetPtEtaPhiM(par[2],par[3],par[4],0);
  
      TLorentzVector t1 = neutrino[2]+vectors[lep]+vectors[bj];
  
      Float_t t2mass= (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]+vectors[cj]).M();
      Float_t Wmass = (vectors[lep] + neutrino[2]).M();
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
      Float_t pConstrain = (vectors[bj].Dot(vectors[lep])/100) + (vectors[bj].Dot(neutrino[2])/100);
      chisq =  pow((Wmass-81)/10,2) + pow((t1.M()-172.5)/25,2) +pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2) + pow((Hmass-125)/10,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
    }else{
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
      chisq = pow((Hmass-125)/10,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
    }
    f = chisq;
}


int nominal::findcjet(){
  TLorentzVector ljet[3];
  int nljet[3];
  int j = 0;
  double m_w = 81000;
  int nlightj = nJets_OR_T - nJets_OR_T_MV2c10_70;
  for (int i = 0; j < nlightj && j < 3 ; ++i)
    if ((*m_jet_flavor_weight_MV2c10)[i] < 0.83){
      nljet[j] = i;
      ljet[j].SetPtEtaPhiM((*m_jet_pt)[i],(*m_jet_eta)[i],(*m_jet_phi)[i],(*m_jet_E)[i]);
      ++j;
    }
  if (nlightj == 2) {
    return ljet[0].DeltaR(taus_v[0] + taus_v[0]) + ljet[1].DeltaR(bjet_v) < ljet[1].DeltaR(taus_v[0] + taus_v[0]) + ljet[0].DeltaR(bjet_v) ? nljet[0]:nljet[1];
  }else{
    if( abs((ljet[0] + ljet[1]).M() - m_w) > abs((ljet[0] + ljet[2]).M() - m_w) )
      if(abs((ljet[0] + ljet[2]).M() - m_w) > abs((ljet[1] + ljet[2]).M() - m_w)) 
      {
        t1_mass     = ( lep_v + ljet[1] + ljet[2] + bjet_v ) .M();
        Wmass      = ( ljet[1] + ljet[2] ).M();
        return nljet[0];
      }
      else{
        t1_mass     = ( lep_v + ljet[0] + ljet[2] + bjet_v ) .M();
        Wmass      = ( ljet[0] + ljet[2] ).M();
        return nljet[1];
      }
    else if(abs((ljet[0] + ljet[1]).M() - m_w) > abs((ljet[1] + ljet[2]).M() - m_w)) 
      {
        t1_mass     = ( lep_v + ljet[1] + ljet[2] + bjet_v ) .M();
        Wmass      = ( ljet[1] + ljet[2] ).M();
        return nljet[0];
      }
      else{
        t1_mass     = ( lep_v + ljet[0] + ljet[1] + bjet_v ) .M();
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
