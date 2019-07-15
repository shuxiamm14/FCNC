#include "tthmltree.h"
#define nominal_cxx
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "stdio.h"
#include "stdlib.h"

tthmltree::tthmltree():nominal::nominal(){
  defGeV(1000);
  dofit1l2tau = 0;
  weights = new vector<double> ();
  initialize_fit(TString(PACKAGE_DIR) + "/data/tau_pars.root");
  tthcutflow.set_weight(&weight);
}

TH2F* tthmltree::prob_20_40 = 0;
TH2F* tthmltree::prob_40_60 = 0;
TH2F* tthmltree::prob_60_80 = 0;
TH2F* tthmltree::prob_80_100 = 0;
TH2F* tthmltree::prob_100_120 = 0;
TH2F* tthmltree::prob_120_140 = 0;
TH2F* tthmltree::prob_140_160 = 0;
TH2F* tthmltree::prob_160_200 = 0;
TH2F* tthmltree::prob_200_300 = 0;
TH2F* tthmltree::prob_300_400 = 0;
TH2F* tthmltree::prob_400 = 0;

TMinuit* tthmltree::initgM(){

  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);
  return gM;
}


//void tthmltree::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {
//  if(!GeV) {
//    printf("Error: nominal::GeV not initialised\n");
//    exit(0);
//  }
//  TList *listforfit = (TList*) gM->GetObjectFit();
//  if (!listforfit)
//  {
//    printf("list isnt found\n");
//    exit(1);
//  }
//  enum lorentzv{tau1,tau2,bj,cj,lep};
//  
//  TLorentzVector vectors[5];
//  TLorentzVector neutrino[3];
//  for( int i = 0; i<5 ; ++i) {
//    if (listforfit->At(i))
//    {
//      vectors[i] = *((TLorentzVector*)listforfit->At(i));
//    }else{
//      printf("i-th parameter is not found\n");
//      exit(1);
//    }
//  }
//  double met[3];
//  if (listforfit->At(5)) {
//    met[0] = ((TVector3*)listforfit->At(5))->x();
//    met[1] = ((TVector3*)listforfit->At(5))->y();
//    met[2] = ((TVector3*)listforfit->At(5))->z();
//  }
//  else { printf("met parameter is not found\n"); exit(1); }
//
//  neutrino[0].SetPtEtaPhiM(par[0]*vectors[tau1].Pt(),vectors[tau1].Eta(),vectors[tau1].Phi(),vectors[lep].Pt()==0?par[2]:0);
//  neutrino[1].SetPtEtaPhiM(par[1]*vectors[tau2].Pt(),vectors[tau2].Eta(),vectors[tau2].Phi(),0);
//  Float_t Hmass = (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]).M();
//  Float_t met_resol = 13.1*GeV+0.50*sqrt(met[2]*GeV);
//  Double_t chisq = 1e10;
//
//  if(vectors[lep].Pt()!=0){
//    neutrino[2].SetPtEtaPhiM(par[2],par[3],par[4],0);
//  
//    TLorentzVector t1 = neutrino[2]+vectors[lep]+vectors[bj];
//  
//    Float_t t2mass= (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]+vectors[cj]).M();
//    Float_t wmass = (vectors[lep] + neutrino[2]).M();
//    Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
//    Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
//    Float_t pConstrain = (vectors[bj].Dot(vectors[lep])/100) + (vectors[bj].Dot(neutrino[2])/100);
//    chisq =  pow((wmass-81*GeV)/10/GeV,2) + pow((t1.M()-172.5*GeV)/25/GeV,2) +pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2) + pow((Hmass-125*GeV)/10/GeV,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
//  }else{
//    Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
//    Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
//    chisq = pow((Hmass-125*GeV)/10*GeV,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
//  }
//  f = chisq;
//}

void tthmltree::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {

  TList *listforfit = (TList*) gM->GetObjectFit();
  if (!listforfit)
  {
    printf("list isnt found\n");
    exit(1);
  }
  enum lorentzv{tau1,tau2};
  
  TLorentzVector vectors[2];
  TLorentzVector neutrino[2];
  for( int i = 0; i<2 ; ++i) {
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

  neutrino[0].SetPtEtaPhiM(par[0],par[1],par[2],par[6]);
  neutrino[1].SetPtEtaPhiM(par[3],par[4],par[5],0);
  Float_t prob1(0), prob2(0);

  prob1 = getLepTauProb(vectors[tau1].DeltaR(neutrino[0]),neutrino[0].M()/GeV,(vectors[tau1]+neutrino[0]).P()/GeV);
  prob2 = getHadTauProb(vectors[tau2].DeltaR(neutrino[1]),(vectors[tau2]+neutrino[1]).P()/GeV);

  Float_t mass1 = (vectors[tau1]+neutrino[0]).M();
  Float_t mass2 = (vectors[tau2]+neutrino[1]).M();
  Float_t mass = (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]).M();
  Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
  Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
  
  Double_t chisq = 1e10;
  if(prob1>0 && prob2>0) {
    Float_t met_resol = (13.1+0.50*sqrt(met[2]/GeV))*GeV;
    chisq = -2*log(prob1) -2*log(prob2) + pow((mass1-1.777*GeV)/1.777/GeV,2) + pow((mass2-1.777*GeV)/1.777/GeV,2) + pow((mass-125*GeV)/20/GeV,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
  }
  
  f = chisq;
}


void tthmltree::init_hist(TString outputfilename){
  //init histSaver here:
  dohist = 1;

  fcnc_nregions = fcnc_regions.size();

  TString nprong[] = {"1prong","3prong"};
  
  if(reduce == 3){
    initMVA("reg1l2tau1bnj_os");
    initMVA("reg1l1tau1b2j_os");
    initMVA("reg1l1tau1b3j_os");
  }

  for (int iNP = 0; iNP < plotNPs.size(); ++iNP)
  {
    fcnc_plots.push_back(new histSaver(outputfilename + "_fcnc" + char('0' + plotNPs[iNP])));
    fcnc_plots[iNP]->set_weight(&weight);
    fcnc_plots[iNP]->debug = !!debug;
    if(reduce == 3) fcnc_plots[iNP]->add(100,-1.,1.,"BDT discriminant","BDTG_train",&BDTG_train,false,"");
    if(reduce == 3) fcnc_plots[iNP]->add(100,-1.,1.,"BDT discriminant","BDTG_test",&BDTG_test,false,"");
    if(reduce >= 2) {
      fcnc_plots[iNP]->add(100,5.,55.,"#chi^2","chi2",&chi2,false,"");
      fcnc_plots[iNP]->add(500,200.,1200.,"m_{all}","allmass",&allmass,true,"GeV");
      fcnc_plots[iNP]->add(500,0.,1000.,"P_{z,all}","allpz",&allpz,true,"GeV");
    }
    fcnc_plots[iNP]->add(10,25.,125.,"p_{T,#tau}","taupt_0",&tau_pt_0,true,"GeV");
    fcnc_plots[iNP]->add(10,25.,125.,"p_{T,#tau}","taupt_1",&tau_pt_1,true,"GeV");
    fcnc_plots[iNP]->add(10,25.,125.,"p_{T,SS#tau}","tauptss",&tau_pt_ss,true,"GeV");
    fcnc_plots[iNP]->add(10,25.,125.,"p_{T,OS#tau}","tauptos",&tau_pt_os,true,"GeV");
    fcnc_plots[iNP]->add(100,100.,300.,"m_{t,SM}","t1mass",&t1mass,true,"GeV");
    fcnc_plots[iNP]->add(100,0.,200.,"m^{T}_{W}","mtw",&mtw,true,"GeV");
    fcnc_plots[iNP]->add(100,50.,250.,"m_{#tau,#tau}","tautaumass",&tautaumass,true,"GeV");
    fcnc_plots[iNP]->add(100,0.,250.,"m_{W}","wmass",&wmass,true,"GeV");
    fcnc_plots[iNP]->add(150,120.,270.,"m_{t,FCNC}","t2mass",&t2mass,true,"GeV");
    fcnc_plots[iNP]->add(100,25.,125.,"m_{#tau#tau,vis}","tautauvismass",&ttvismass,true,"GeV");
    fcnc_plots[iNP]->add(100,0.,200.,"P_{t,#tau#tau,vis}","tautauvispt",&tautauvispt,true,"GeV");
    fcnc_plots[iNP]->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,true,"GeV");
    fcnc_plots[iNP]->add(150,40.,190.,"m_{t,SM,vis}","t1vismass",&t1vismass,true,"GeV");
    fcnc_plots[iNP]->add(100,0.,1.,"E_{#nu,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
    fcnc_plots[iNP]->add(100,0.,1.,"E_{#nu,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
    fcnc_plots[iNP]->add(60,0.,6.,"#DeltaR(l+b-jet,#tau+#tau)","drlbditau",&drlbditau,false,"");
    fcnc_plots[iNP]->add(60,0.,6.,"#DeltaR(l,b-jet)","drlb",&drlb,false,"");
    fcnc_plots[iNP]->add(60,0.,6.,"#DeltaR(l,b-jet)","drtaub",&drtaub,false,"");
    fcnc_plots[iNP]->add(100,0.,2.5,"#eta_{#tau,max}","etamax",&etamax,false,"");
    fcnc_plots[iNP]->add(72,0.4,4.,"#DeltaR(l,#tau)","drltau",&drltau,false,"");
    fcnc_plots[iNP]->add(120,0.,6.,"#DeltaR(#tau,fcnc-j)","drtauj",&drtauj,false,"");
    fcnc_plots[iNP]->add(92,0.4,5.,"#DeltaR(#tau,#tau)","drtautau",&drtautau,false,"");
    fcnc_plots[iNP]->add(60,0.4,3.4,"#DeltaR(#tau,#light-jet,min)","drtaujmin",&drtaujmin,false,"");
    fcnc_plots[iNP]->add(100,50.,250.,"M(#tau#tau#light-jet,min)","mtaujmin",&mtaujmin,true,"GeV");
    fcnc_plots[iNP]->add(100,20.,200.,"M(light-jet,light-jet,min)","mjjmin",&mjjmin,true,"GeV");
    fcnc_plots[iNP]->add(10,0.,10.,"N_{l-jet}","njet",&nljet,false,"");
    fcnc_plots[iNP]->add(100,15.,115.,"E^{T}_{miss}","etmiss",&etmiss,true,"GeV");
    fcnc_plots[iNP]->add(60,0.,3.,"#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss",&dphitauetmiss,false);
    fcnc_plots[iNP]->add(60,-1.5,1.5,"E^{T}_{miss} centrality","phicent",&phicent,false,"");

    for (int j = 0; j < fcnc_nregions; ++j){
      for (int k = 0; k < 2; ++k)
      {
        for (int i = 0; i < 4; ++i)
        {
          for (int iptbin = 0; iptbin < 2; ++iptbin)
          {
            if(debug) printf("adding region: %s\n", (fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
            if(dobwp[bwps[i]]) fcnc_plots[iNP]->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
            if(dovetobwp[bwps[i]]) fcnc_plots[iNP]->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
          }
        }
      }
    }
  }
  fake_notau_plots = new histSaver(outputfilename + "_fake_notau");
  fake_notau_plots->set_weight(&weight);
  fake_notau_plots->debug = !!debug;
  fake_plots = new histSaver(outputfilename + "_fake");
  fake_plots->set_weight(&weight);
  fake_plots->debug = !!debug;
  fake_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
  fake_plots->add(10,25.,125.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  fake_plots->add(10,25.,125.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  fake_plots->add(20,20.,120.,"m_{#tau,light-jet}","taulmass",&taulmass,true,"GeV");
  fake_plots->add(100,0.,100.,"E_{miss}^{T}","met",&MET_RefFinal_et,true,"GeV");
  fake_notau_plots->add(10,0.,200.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  fake_notau_plots->add(10,0.,200.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  
  fake_nregions = fake_regions.size();
  fake_nregions_notau = fake_regions_notau.size();
  
  for (int j = 0; j < fake_nregions; ++j){
    for (int k = 0; k < 2; ++k){
      for (int i = 0; i < 4; i+=1){
        for (int iptbin = 0; iptbin < 2; ++iptbin)
        {
          if(dobwp[bwps[i]]) fake_plots->add_region(fake_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
          if(dovetobwp[bwps[i]]) fake_plots->add_region(fake_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
        }
      }
    }
  }
  for (int j = 0; j < fake_nregions_notau; ++j){
    fake_notau_plots->add_region(fake_regions_notau[j]);
  }
}

void tthmltree::init_sample(TString sample, TString sampletitle){
//==========================init output n-tuple==========================
  fcnc_nregions = fcnc_regions.size();
  fake_nregions = fake_regions.size();
  fake_nregions_notau = fake_regions_notau.size();

  if(writetree){
    gSystem->mkdir(TString(PACKAGE_DIR) + "/data/tthmlreduce" + char('0' + reduce));
    gSystem->mkdir(TString(PACKAGE_DIR) + "/data/tthmlreduce" + char('0' + reduce) + "/" + SystematicsName);
    printf("create outputfile: %s\n", (TString(PACKAGE_DIR) + "/data/tthmlreduce" + char('0' + reduce) + "/" + SystematicsName + "/" + sample + "_tree.root").Data());
    outputtreefile = new TFile(TString(PACKAGE_DIR) + "/data/tthmlreduce" + char('0' + reduce) + "/" + SystematicsName + "/" + sample + "_tree.root","update");

    map<TString, TTree*>::iterator iter;
    for (int i = 0; i < fcnc_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n",fcnc_regions[i].Data());
      outputtree[fcnc_regions[i]] = new TTree(fcnc_regions[i],fcnc_regions[i]);
      if(reduce<2 || !fcnc) definetree(outputtree[fcnc_regions[i]]);
      if(reduce==2 ){
        outputtree[fcnc_regions[i]]->Branch("chi2",&chi2);
        outputtree[fcnc_regions[i]]->Branch("allmass", &allmass);
        outputtree[fcnc_regions[i]]->Branch("allpz", &allpz);
        outputtree[fcnc_regions[i]]->Branch("t1mass",&t1mass);
        outputtree[fcnc_regions[i]]->Branch("tautaumass",&tautaumass);
        outputtree[fcnc_regions[i]]->Branch("wmass",&wmass);
        outputtree[fcnc_regions[i]]->Branch("t2mass",&t2mass);
        outputtree[fcnc_regions[i]]->Branch("tau_truthType_0",&tau_truthType_0);
        outputtree[fcnc_regions[i]]->Branch("tau_numTrack_0", & tau_numTrack_0);
        outputtree[fcnc_regions[i]]->Branch("tau_truthType_1",&tau_truthType_1);
        outputtree[fcnc_regions[i]]->Branch("tau_charge_0",&tau_charge_0);
        outputtree[fcnc_regions[i]]->Branch("tau_charge_1",&tau_charge_1);
        outputtree[fcnc_regions[i]]->Branch("tau_JetBDTSigTight_0",&tau_JetBDTSigTight_0);
        outputtree[fcnc_regions[i]]->Branch("tau_JetBDTSigTight_1",&tau_JetBDTSigTight_1);
        outputtree[fcnc_regions[i]]->Branch("eventNumber", &eventNumber);
        outputtree[fcnc_regions[i]]->Branch("neutrino_pt" , &neutrino_pt );
        outputtree[fcnc_regions[i]]->Branch("neutrino_eta", &neutrino_eta);
        outputtree[fcnc_regions[i]]->Branch("neutrino_phi", &neutrino_phi);
        outputtree[fcnc_regions[i]]->Branch("neutrino_m"  , &neutrino_m  );
        outputtree[fcnc_regions[i]]->Branch("weights",&weights);
        outputtree[fcnc_regions[i]]->Branch("fakeSF",&fakeSF);
        outputtree[fcnc_regions[i]]->Branch("ljet_indice", &ljet_indice );
        outputtree[fcnc_regions[i]]->Branch("x1fit", &x1fit);
        outputtree[fcnc_regions[i]]->Branch("tau_pt_0", &tau_pt_0);
        outputtree[fcnc_regions[i]]->Branch("tau_pt_1", &tau_pt_1);
        outputtree[fcnc_regions[i]]->Branch("x2fit", &x2fit);
        outputtree[fcnc_regions[i]]->Branch("t1vismass",&t1vismass);
        outputtree[fcnc_regions[i]]->Branch("t2vismass",&t2vismass);
        outputtree[fcnc_regions[i]]->Branch("ttvismass",&ttvismass);
        outputtree[fcnc_regions[i]]->Branch("tautauvispt",&tautauvispt);
        outputtree[fcnc_regions[i]]->Branch("mtw",&mtw);
        outputtree[fcnc_regions[i]]->Branch("tau_pt_ss",&tau_pt_ss);
        outputtree[fcnc_regions[i]]->Branch("tau_pt_os",&tau_pt_os);
        outputtree[fcnc_regions[i]]->Branch("drlbditau", &drlbditau);
        outputtree[fcnc_regions[i]]->Branch("drlb", &drlb);
        outputtree[fcnc_regions[i]]->Branch("drtaub", &drtaub);
        outputtree[fcnc_regions[i]]->Branch("etamax", &etamax);
        outputtree[fcnc_regions[i]]->Branch("drltau",&drltau);
        outputtree[fcnc_regions[i]]->Branch("drtauj",&drtauj);
        outputtree[fcnc_regions[i]]->Branch("drtautau",&drtautau);
        outputtree[fcnc_regions[i]]->Branch("drtaujmin", &drtaujmin);
        outputtree[fcnc_regions[i]]->Branch("mtaujmin", &mtaujmin);
        outputtree[fcnc_regions[i]]->Branch("mjjmin", &mjjmin);
        outputtree[fcnc_regions[i]]->Branch("etmiss",&etmiss);
        outputtree[fcnc_regions[i]]->Branch("dphitauetmiss",&dphitauetmiss);
        outputtree[fcnc_regions[i]]->Branch("phicent",&phicent);
        outputtree[fcnc_regions[i]]->Branch("mc_channel_number", &mc_channel_number);
        outputtree[fcnc_regions[i]]->Branch("nljet", &nljet);


      }
    }

    for (int i = 0; i < fake_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions[i].Data());
      if (outputtreefile->Get(fake_regions[i])) {
        outputtree[fake_regions[i]] = (TTree*)(outputtreefile->Get(fake_regions[i]));
        Init(outputtree[fake_regions[i]]);
      }else{
        outputtree[fake_regions[i]] = new TTree(fake_regions[i],fake_regions[i]);
        definetree(outputtree[fake_regions[i]]);
      }
    }
    for (int i = 0; i < fake_nregions_notau; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions_notau[i].Data());
      if (outputtreefile->Get(fake_regions_notau[i])) {
        outputtree[fake_regions_notau[i]] = (TTree*)(outputtreefile->Get(fake_regions_notau[i]));
        Init(outputtree[fake_regions_notau[i]]);
      }else{
        outputtree[fake_regions_notau[i]] = new TTree(fake_regions_notau[i],fake_regions_notau[i]);
        definetree(outputtree[fake_regions_notau[i]]);
      }
    }
  }
//==========================init output histogram==========================
  if(dohist){
    if (sample.Contains("data"))
    {
      fcnc_plots[0]->init_sample("data","data","data",kBlack);
      fake_plots->init_sample("data","data","data",kBlack);
      fake_notau_plots->init_sample("data","data_notau","data",kBlue);
      initdata = 1;
    }else{
      if(sample.Contains("ttbar")) sample = "ttbar";
      else sample.Remove(sample.Sizeof()-2);
      for (int iNP = 0; iNP < plotNPs.size(); ++iNP)
      {
        fcnc_plots[iNP]->init_sample(sample + "_g",sample + "_g_NP" + char('0' + plotNPs[iNP]),sampletitle + "(gluon fake #tau)",(enum EColor)7);
        fcnc_plots[iNP]->init_sample(sample + "_j",sample + "_j_NP" + char('0' + plotNPs[iNP]),sampletitle + "(light-jet fake #tau)",kBlue);
        fcnc_plots[iNP]->init_sample(sample + "_b",sample + "_b_NP" + char('0' + plotNPs[iNP]),sampletitle + "(b-jets fake #tau)",kViolet);
        fcnc_plots[iNP]->init_sample(sample + "_lep",sample + "_lep_NP" + char('0' + plotNPs[iNP]),sampletitle + "(lepton fake #tau)",kGreen);
        fcnc_plots[iNP]->init_sample(sample + "_real",sample + "_real_NP" + char('0' + plotNPs[iNP]),sampletitle + "(real #tau)",kRed);
        fcnc_plots[iNP]->init_sample(sample + "_c",sample + "_c_NP" + char('0' + plotNPs[iNP]),sampletitle + "(c-jets fake #tau)",kOrange);
        fcnc_plots[iNP]->init_sample(sample + "_nomatch",sample + "_nomatch_NP" + char('0' + plotNPs[iNP]),sampletitle + "(no truth matched fake #tau)",kGray);
      }
      fake_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      fake_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
      fake_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
      fake_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
      fake_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
      fake_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
      fake_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
      fake_notau_plots->init_sample(sample,sample+"_notau",sampletitle,kRed);
    }
  }
}


void tthmltree::Loop(TTree* inputtree, TString samplename) {
  if(SystematicsName == "nominal") nominaltree = 1;
  else nominaltree = 0;
  nonfcncmatched = 0;
  fcncmatched = 0;
  leptonicw = 0;
  TString cutflowregion = "";
  bool tightLep = 1;
  bool tightTau = 0;
  double cutflow[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
  };
  fcnc = 0;
  if (reduce > 1) {
    ifregions.clear();
    ifregions[inputtree->GetName()] = 1;
    for (int i = 0; i < fcnc_regions.size(); ++i)
    {
      if(fcnc_regions[i] == inputtree->GetName()) fcnc = 1;
    }
  }
  reduce -= 1;
  Init(inputtree);
  reduce += 1;
  map < TString, bool > ::iterator iter;
  printf("reduce scheme: %d\n", reduce);
  if (inputtree == 0) return;
  Long64_t nentries = inputtree->GetEntriesFast();
  TString sample = samplename;
  if (samplename.Contains("ttbar")) sample = "ttbar";
  else if (!samplename.Contains("data")) sample.Remove(sample.Sizeof() - 2);
  gM = initgM();
  fstream evtfile;
  if(dumpeventnumber) evtfile.open((samplename+"_evt.txt").Data(), fstream:: in | fstream::out | fstream::app);
  if (dumptruth) {
    if(reduce > 1){
      if (TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) {
        filetruth[0][0].open("lephad2jodd.txt", fstream:: in | fstream::out | fstream::app);
        filetruth[0][1].open("lephad2jeven.txt", fstream:: in | fstream::out | fstream::app);
      } else
        for (int i = 0; i < 3; ++i) {
          if (TString(inputtree->GetName()).Contains("reg1l1tau1b3j")) {
            if (i != 0) {
              filetruth[i][0].open(CharAppend("lephad", i + 2) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
              filetruth[i][1].open(CharAppend("lephad", i + 2) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
            }
          } else {
            filetruth[i][0].open(CharAppend("lep2tau", i + 1) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
            filetruth[i][1].open(CharAppend("lep2tau", i + 1) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
          }
        }
    }else{
      for (int i = 0; i < 3; ++i) {
        filetruth[i][0].open(CharAppend("lephad", i + 2) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
        filetruth[i][1].open(CharAppend("lephad", i + 2) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
        filetruth[i][0].open(CharAppend("lep2tau", i + 1) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
        filetruth[i][1].open(CharAppend("lep2tau", i + 1) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
      }
    }
  }
  int nloop = debug ? 1000 : nentries;
  bool triggeredfcnc = 0;
  TString fcncreg = "";
  double defaultbtagwp = btagwpCut[1];
  if(reduce > 1) {
    TString namestring = ((TString)inputtree->GetName());
    triggeredfcnc = namestring.Contains("1l1tau1b2j")|| namestring.Contains("1l1tau1b3j") || namestring.Contains("1l2tau1bnj");
    triggeredfcnc = triggeredfcnc || namestring.Contains("1l1tau2b2j")|| namestring.Contains("1l1tau2b3j") || namestring.Contains("1l2tau2bnj");
    if(triggeredfcnc){
      if(namestring.Contains("2tau")) fcncreg = "1l2tau";
      else if(namestring.Contains("2j")) fcncreg = "lh3j";
      else if(namestring.Contains("3j")) fcncreg = "lh4j";
      if(namestring.Contains("85")) defaultbtagwp = btagwpCut[3];
    }
  }
  float ngluon = 0;
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    inputtree->GetEntry(jentry);
    tthcutflow.newEvent();
    if ((jentry % 100000 == 0))
      std::cout << " I am here event " << jentry << " Event " << eventNumber << " Run " << runNumber << " ismc " << mc_channel_number << std::endl;
    //===============================pre-selections===============================
    if (reduce == 1 && selected_jets_T->size() == 0 && nJets_OR_T != 0) {
      printf("error: read jet vector failed entry: %lld\n", jentry);
      continue;
    }
    if (debug == 2) printf("reduce scheme during loop: %d\n", reduce);
    if (reduce == 1) {
      bool basic_selection = passEventCleaning;
      if (debug == 2) printf("passEventCleaning: %d\n", passEventCleaning);
      if (samplename.Contains("ttbargamma")) {
        basic_selection &= m_hasMEphoton_DRgt02_nonhad;
      }
      if (samplename.Contains("ttbarnohad")) {
        basic_selection &= !m_hasMEphoton_DRgt02_nonhad;
      }

      basic_selection &=
        (RunYear == 2015 && (( lep_Pt_0/GeV>21 && HLT_mu20_iloose_L1MU15 ) || ( lep_Pt_0/GeV>51 && HLT_mu50 ) || ( lep_Pt_0/GeV>25 && HLT_e24_lhmedium_L1EM20VH )|| (lep_Pt_0/GeV>61 &&HLT_e60_lhmedium) || ( lep_Pt_0/GeV>121 && HLT_e120_lhloose))) ||
        (RunYear == 2015 && (HLT_2e12_lhloose_L12EM10VH || HLT_e17_lhloose_mu14 || HLT_mu18_mu8noL1)) ||
        (RunYear >= 2016 && (( lep_Pt_0/GeV>27 && HLT_mu26_ivarmedium ) || ( lep_Pt_0/GeV>51 && HLT_mu50 ) || ( lep_Pt_0/GeV>27 && HLT_e26_lhtight_nod0_ivarloose ) || ( lep_Pt_0/GeV>61 && HLT_e60_lhmedium_nod0) || ( lep_Pt_0/GeV>141 && HLT_e140_lhloose_nod0))) ||
        (RunYear >= 2016 && (HLT_2e17_lhvloose_nod0 || HLT_e17_lhloose_nod0_mu14 || HLT_mu22_mu8noL1));

      if(nTaus_OR_Pt25) basic_selection = basic_selection && (tau_numTrack_0 == 1 || tau_numTrack_0 == 3); // assuming triggers for 2017 is same for 2016 
      weight = mc_channel_number > 0 ? mc_norm*mcWeightOrg*pileupEventWeight_090*(version == 7 ? bTagSF_weight_MV2c10_FixedCutBEff_70 : bTagSF_weight_MV2c10_Continuous)*JVT_EventWeight*SherpaNJetWeight: 1.0;
      if( mc_channel_number > 0) weight*=tightLep?lepSFObjLoose:lepSFIDLoose*lepSFTrigLoose;
      if(nTaus_OR_Pt25 &&  mc_channel_number >0) weight*=tightTau?tauSFLoose:tauSFTight; // stupid and confusing but this is how it is.
      tthcutflow.fill();
      if (!basic_selection) continue;
      tthcutflow.fill();

      bool trig_match = (lep_isTrigMatch_0 || lep_isTrigMatch_1 || lep_isTrigMatch_2 || lep_isTrigMatch_3 || matchDLTll01 || matchDLTll02 || matchDLTll12 || matchDLTll03 || matchDLTll13 || matchDLTll23);
      bool SLtrig_match =
        ((RunYear == 2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose)) ||
          (RunYear >= 2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))) && lep_isTrigMatch_0;

      //===============================define regions===============================

      if (onelep_type || dilep_type) {
        lep_v.SetPtEtaPhiE(lep_Pt_0, lep_Eta_0, lep_Phi_0, lep_E_0);
      }
      taus_v[0].SetPtEtaPhiE(tau_pt_0,tau_eta_0,tau_phi_0,tau_E_0);
      taus_v[1].SetPtEtaPhiE(tau_pt_1,tau_eta_1,tau_phi_1,tau_E_1);
      if(nTaus_OR_Pt25 == 1){
        taus_v[1] = taus_v[0];
        taus_v[0] = lep_v;
        lep_v.SetPtEtaPhiE(0, 0, 0, 0);
      }
      triggeredfcnc = 0;
      bool triggered = 0;
      ifregions.clear();
      if(SLtrig_match && onelep_type && (!tightLep || SelectTLepid(0)) && nTaus_OR_Pt25 && (tau_passEleBDT_0 && tau_passMuonOLR_0)){
        ifregions["reg1l1tau1b2j_os"] = nJets_OR_T == 3 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0;
        ifregions["reg1l1tau1b3j_os"] = nJets_OR_T >= 4 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0;
        ifregions["reg1l1tau1b2j_ss"] = nJets_OR_T == 3 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0;
        ifregions["reg1l1tau1b3j_ss"] = nJets_OR_T >= 4 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0;
        ifregions["reg1l1tau2b2j_os"] = nJets_OR_T == 3 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0;
        ifregions["reg1l1tau2b3j_os"] = nJets_OR_T >= 4 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0;
        ifregions["reg1l1tau2b2j_ss"] = nJets_OR_T == 3 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0;
        ifregions["reg1l1tau2b3j_ss"] = nJets_OR_T >= 4 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0;
        ifregions["reg1l1tau2b2j_os_85"] = nJets_OR_T == 3 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T_MV2c10_70 == 0 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0;
        ifregions["reg1l1tau2b3j_os_85"] = nJets_OR_T >= 4 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T_MV2c10_70 == 0 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0;
        ifregions["reg1l1tau2b2j_ss_85"] = nJets_OR_T == 3 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T_MV2c10_70 == 0 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0;
        ifregions["reg1l1tau2b3j_ss_85"] = nJets_OR_T >= 4 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T_MV2c10_70 == 0 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0;
        ifregions["reg1l2tau1bnj_os"] = nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 < 0;
        ifregions["reg1l2tau1bnj_ss"] = nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 > 0;
        ifregions["reg1l2tau2bnj_os"] = nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 < 0;
        ifregions["reg1l2tau2bnj_ss"] = nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 > 0;
        for(auto reg: ifregions){
          if(reg.second == 1) {
            triggeredfcnc = 1;
            break;
          }
        }
        ifregions["reg1l2b2j"] = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T >= 4 && nTaus_OR_Pt25 == 0;
        ifregions["reg1l1tau2b1j_os"] = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 3 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 < 0;
        ifregions["reg1l1tau2b1j_ss"] = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 3 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 > 0;
        ifregions["reg1l1tau2b_os"] = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 < 0;
        ifregions["reg1l1tau2b_ss"] = onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 > 0;
      }
      if (trig_match && dilep_type && total_charge == 0 && lep_Pt_0 > 20e3 && lep_Pt_1 > 20e3 &&
        ((abs(lep_ID_0) == 11 && lep_promptLeptonVeto_TagWeight_0 < -0.7) || (abs(lep_ID_0) == 13 && lep_promptLeptonVeto_TagWeight_0 < -0.5)) && (!tightLep || SelectTLepid(0)) &&
        ((abs(lep_ID_1) == 11 && lep_promptLeptonVeto_TagWeight_1 < -0.7) || (abs(lep_ID_1) == 13 && lep_promptLeptonVeto_TagWeight_1 < -0.5)) && (!tightLep || SelectTLepid(1)) &&
        (nTaus_OR_Pt25 == 0 || (tau_passEleBDT_0 && tau_passMuonOLR_0)) &&
        (dilep_type == 2 || ((dilep_type == 1 || dilep_type == 3) && (Mll01 / GeV < 80 || Mll01 / GeV > 100))) && total_charge == 0) { //met>30 GeV ? ttbar vs z+bb:
      if(debug == 2){
        printf("ntaus: %d, nleptons: %d, njets: %d, nbjets: %d, charge prod: %f\n",nTaus_OR_Pt25,onelep_type?1:(dilep_type?2:0),nJets_OR_T,nJets_OR_T_MV2c10_70, -tau_charge_0*lep_ID_0/fabs(lep_ID_0));
      }
        ifregions["reg1e1mu1tau2b"] = nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 1;
        ifregions["reg1e1mu2bnj"] = nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T >= 3 && nTaus_OR_Pt25 == 0;
        ifregions["reg1e1mu1tau1b"] = nJets_OR_T_MV2c10_70 == 1 && nJets_OR_T == 1 && nTaus_OR_Pt25 == 1;
        ifregions["reg1e1mu2b"] = nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 0;
      }
      for (iter = ifregions.begin(); iter != ifregions.end();){
        if(debug == 2) 
          printf("region: %s, %d\n", iter->first.Data(), iter->second);
        if (iter->second && (find(fcnc_regions.begin(),fcnc_regions.end(),iter->first) != fcnc_regions.end() || find(fake_regions.begin(),fake_regions.end(),iter->first) != fake_regions.end() || find(fake_regions_notau.begin(),fake_regions_notau.end(),iter->first) != fake_regions_notau.end() ) ) {
          triggered = 1;
          iter++;
        }else{
          ifregions.erase(iter->first);
        }
      }

      if (!triggered) continue;
    }else if(tightTau) {
      bool passtight = 1;
      for(auto & iter : ifregions){
        if(iter.second == 1) {
          if((iter.first.Contains("tau") && tau_JetBDTSigTight_0 == 0) || (iter.first.Contains("2tau") && tau_JetBDTSigTight_1 == 0))
            passtight = 0;
        }
      }
      if(!passtight) continue;
      tthcutflow.fill();
    }
    else weight = weights->at(0);

    if (reduce == 2) {

      tthcutflow.fill();
      if (debug == 2) printf("event weight: %f\n", weight);
      if (debug == 2) {
        for (iter = ifregions.begin(); iter != ifregions.end(); iter++) {
          if (iter->second)
            printf("region: %s\n", iter->first.Data());
        }
      }
      //===============================find leading b,non b jets===============================
      if(weight > 2) {
        printf("weight > 1, drop the event\n");
        continue;
      }
      tthcutflow.fill();
      if(  mc_channel_number <= 0 ) weight = 1;

      if (reduce != 1){
        if (onelep_type || dilep_type) {
          lep_v.SetPtEtaPhiE(lep_Pt_0, lep_Eta_0, lep_Phi_0, lep_E_0);
        }
        taus_v[0].SetPtEtaPhiE(tau_pt_0,tau_eta_0,tau_phi_0,tau_E_0);
        taus_v[1].SetPtEtaPhiE(tau_pt_1,tau_eta_1,tau_phi_1,tau_E_1);
        if(nTaus_OR_Pt25 == 1){
          taus_v[1] = taus_v[0];
          taus_v[0] = lep_v;
          lep_v.SetPtEtaPhiE(0, 0, 0, 0);
        }
      }
      nljet = nJets_OR_T - nJets_OR_T_MV2c10_70;
      int highscore_b = -1;
      int subhighscore_b = -1;
      leading_ljet = -1;
      pt_b = 0;
      pt_ljet = 0;
      bool reloop = 1;
      drtaujmin = 10;
      mtaujmin = 0;
      mjjmin = 0;
      ljets_v.clear();
      TLorentzVector subbjet_v;
      if (nJets_OR_T != selected_jets_T->size()) {
        printf("ERROR: nJets_OR_T,%d != selected_jets_T->size(),%lu; Entry: %lld\n", nJets_OR_T, selected_jets_T->size(), jentry);
        continue;
      }
      if (debug == 2) printf("Loop jets\n");
      for (int i = 0; i < nJets_OR_T; ++i) {
        if(debug == 2) printf("%dth jet btag: %f\n", i,(*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)]);
        if ((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] > defaultbtagwp) {
          if(highscore_b == -1){
            highscore_b = selected_jets_T->at(i);
            pt_b = (*m_jet_pt)[selected_jets_T->at(i)];
            bjet_v.SetPtEtaPhiE((*m_jet_pt)[highscore_b], (*m_jet_eta)[highscore_b], (*m_jet_phi)[highscore_b], (*m_jet_E)[highscore_b]);
          }else{
            if((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)]<(*m_jet_flavor_weight_MV2c10)[highscore_b]){
              subhighscore_b = selected_jets_T->at(i);
              subbjet_v.SetPtEtaPhiE((*m_jet_pt)[highscore_b], (*m_jet_eta)[highscore_b], (*m_jet_phi)[highscore_b], (*m_jet_E)[highscore_b]);
              if (triggeredfcnc) { ljets_v.push_back(subbjet_v); }
            }else{
              subhighscore_b = highscore_b;
              subbjet_v = bjet_v;
              highscore_b = selected_jets_T->at(i);
              pt_b = (*m_jet_pt)[selected_jets_T->at(i)];
              bjet_v.SetPtEtaPhiE((*m_jet_pt)[highscore_b], (*m_jet_eta)[highscore_b], (*m_jet_phi)[highscore_b], (*m_jet_E)[highscore_b]);
              if (triggeredfcnc) { ljets_v.push_back(subbjet_v); }
            }
          }
        }
        if ((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] <= btagwpCut[1]) {
          TLorentzVector tmpljet_v;
          tmpljet_v.SetPtEtaPhiE((*m_jet_pt)[selected_jets_T->at(i)], (*m_jet_eta)[selected_jets_T->at(i)], (*m_jet_phi)[selected_jets_T->at(i)], (*m_jet_E)[selected_jets_T->at(i)]);
          ljets_v.push_back(tmpljet_v);
          if (reloop && !triggeredfcnc) {
            pt_ljet = (*m_jet_pt)[selected_jets_T->at(i)];
            reloop = 0;
          }
        }
      }
      if (triggeredfcnc) {
        double tmpdr;
        double tmpm;
        for (auto lj1:ljets_v) {
          for(auto lj2:ljets_v){
            if (!(lj1==lj2)){
              double tmpmjj = (lj1+lj2).M();
              if(mjjmin > tmpmjj || mjjmin==0) mjjmin = tmpmjj;
            }
          }
          tmpdr = min(taus_v[0].DeltaR(lj1), taus_v[1].DeltaR(lj1));
          tmpm = min((taus_v[0]+lj1).M(), (taus_v[1]+lj1).M());
          if (drtaujmin > tmpdr) {
            drtaujmin = tmpdr;
          }if(mtaujmin > tmpm){
            mtaujmin = tmpm;
          }
        }
        if(drtaujmin<0.4) {
          if(debug) printf("drtaujmin<0.4\n");
          continue;
        }
        tthcutflow.fill();
      }
      if(subhighscore_b<0 && (defaultbtagwp == btagwpCut[1] ? nJets_OR_T_MV2c10_70 >=2 : nJets_OR_T_MV2c10_85 >=2)){
        printf("ERROR: bjet not found\n");
        continue;
      }
      if (highscore_b == -1) {
        printf("ERROR: bjet not found\n");
        for (iter = ifregions.begin(); iter != ifregions.end(); iter++)
          if(iter->second) printf("region: %s\n", iter->first.Data());
        continue;
      }
      if (debug == 2) printf("kine fcnc\n");
      if (triggeredfcnc) {
        if (tau_MV2c10_0 > btagwpCut[1]) continue;
        if (nTaus_OR_Pt25 == 2 && tau_MV2c10_1 > btagwpCut[1]) continue;
        tthcutflow.fill();
        if (nTaus_OR_Pt25 >= 2) {
          if (nljet > 1)
            //ljet_indice = findcjetML("lep2tau",ljets_v,bjet_v,lep_v,taus_v,eventNumber%2);
            ljet_indice = findcjet("lep2tau",ljets_v,bjet_v,lep_v,taus_v);
          else if(nljet == 1) ljet_indice.push_back(0);
        } else {
          //ljet_indice = findcjetML("lephad",ljets_v,bjet_v,lep_v,taus_v,eventNumber%2);
          ljet_indice = findcjet("lephad",ljets_v,bjet_v,lep_v,taus_v);
          if (debug) {
            printf("wmass: %f, t1mass: %f, cjet %d, wjet1 %d\n", wmass, t1mass, ljet_indice[0], ljet_indice[1]);
          }
          if(debug) printf("nljets: %lu\n", ljets_v.size());
          if(ljets_v.size()==2){
            wmass = (ljets_v[0] + ljets_v[1]).M();
            t1mass = (ljets_v[0] + ljets_v[1] + bjet_v).M();
          }else{
            wmass = (ljets_v[ljet_indice[1]] + ljets_v[ljet_indice[2]]).M();
            t1mass = (ljets_v[ljet_indice[1]] + ljets_v[ljet_indice[2]] + bjet_v).M();
          }
        }
        if (nJets_OR_T >= 2) cjet_v = ljets_v[ljet_indice[0]];
        mets.SetXYZ(met_met*cos(met_phi), met_met*sin(met_phi), MET_RefFinal_sumet);
        etmiss = met_met;
        //==  =============================fit neutrino===============================
        if(nTaus_OR_Pt25 == 1 || dofit1l2tau){
          if (nTaus_OR_Pt25 >= 2) {
            gM->mnparm(0, "rpt1", 0.4, 0.01, 0., 2., ierflg);
            gM->mnparm(1, "rpt2", 0.4, 0.01, 0., 2., ierflg);
            gM->mnparm(2, "pt3", 10000, 10000, 0., 1000000., ierflg);
            gM->mnparm(3, "eta3", 0, 0.1, -5, 5, ierflg);
            gM->mnparm(4, "phi3", 0, 0.1, -PI, PI, ierflg);
            arglist[0] = 5;
          } else {
            gM->mnparm(0, "v1pt",  tau_pt_0, 1, 0., 1000000, ierflg);
            gM->mnparm(1, "v1eta", taus_v[0].Eta(), 0.01, taus_v[0].Eta()-0.25, taus_v[0].Eta()+0.25, ierflg);
            gM->mnparm(2, "v1phi", taus_v[0].Phi(), 0.01, taus_v[0].Phi()-0.25, taus_v[0].Phi()+0.25, ierflg);
            gM->mnparm(3, "v2pt",  tau_pt_1, 1, 0., 1000000, ierflg);
            gM->mnparm(4, "v2eta", taus_v[1].Eta(), 0.01, taus_v[1].Eta()-0.25, taus_v[1].Eta()+0.25, ierflg);
            gM->mnparm(5, "v2phi", taus_v[1].Phi(), 0.01, taus_v[1].Phi()-0.25, taus_v[1].Phi()+0.25, ierflg);
            gM->mnparm(6, "v1m", 500, 0.01, 0, 1776, ierflg);
            arglist[0] = 7;
          }
  
          gM->SetObjectFit( & forFit);
  
          arglist[1] = 60.;
          Double_t val[7] = {
            0,
            0,
            0,
            0,
            0,
            0,
            0
          };
          Double_t err[7] = {
            0,
            0,
            0,
            0,
            0,
            0,
            0
          };
  
          if(debug) printf("start kinematic fit\n");
          gM->mnexcm("SCAN", arglist, 2, ierflg);
          for (int i = 0; i < 7; ++i) gM->GetParameter(i, val[i], err[i]);
  
          if (nTaus_OR_Pt25 >= 2) {
            gM->mnparm(0, "rpt1", val[0], 0.01, 0., 2., ierflg);
            gM->mnparm(1, "rpt2", val[1], 0.01, 0., 2., ierflg);
            gM->mnparm(2, "pt3",  val[2], 10000, 0., 1000000., ierflg);
            gM->mnparm(3, "eta3", val[3], 0.1, -5, 5, ierflg);
            gM->mnparm(4, "phi3", val[4], 0.1, -PI, PI, ierflg);
          } else {
            gM->mnparm(0, "v1pt",  val[0], 1, 0., 1000000, ierflg);
            gM->mnparm(1, "v1eta", val[1], 0.01, taus_v[0].Eta()-0.25, taus_v[0].Eta()+0.25, ierflg);
            gM->mnparm(2, "v1phi", val[2], 0.01, taus_v[0].Phi()-0.25, taus_v[0].Phi()+0.25, ierflg);
            gM->mnparm(3, "v2pt",  val[3], 1, 0., 1000000, ierflg);
            gM->mnparm(4, "v2eta", val[4], 0.01, taus_v[1].Eta()-0.25, taus_v[1].Eta()+0.25, ierflg);
            gM->mnparm(5, "v2phi", val[5], 0.01, taus_v[1].Phi()-0.25, taus_v[1].Phi()+0.25, ierflg);
            gM->mnparm(6, "v1m",   val[6], 0.01, 0, 1776, ierflg);
          }
  
          arglist[0] = 1000;
          arglist[1] = 0;
  
          gM->mnexcm("MIGRADE", arglist, 2, ierflg);
          for (int i = 0; i < (nTaus_OR_Pt25 >= 2 ? 5 : 7); ++i) gM->GetParameter(i, val[i], err[i]);
          if(debug) printf("finish kinematic fit\n");
          Double_t fmin, fedm, errdef;
          Int_t npari, nparx, istat;
          gM->mnstat(fmin, fedm, errdef, npari, nparx, istat);
          chi2 = fmin;
          TLorentzVector tauv1_v;
          if(nTaus_OR_Pt25 >= 2) tauv1_v.SetPtEtaPhiM(val[0]*taus_v[0].Pt(), taus_v[0].Eta(), taus_v[0].Phi(), nJets_OR_T >= 2 ? 0 : val[2]);
          else tauv1_v.SetPtEtaPhiM(val[0],val[1],val[2],val[6]);
          TLorentzVector tauv2_v;
          if(nTaus_OR_Pt25 >= 2) tauv2_v.SetPtEtaPhiM(val[1]*taus_v[1].Pt(), taus_v[1].Eta(), taus_v[1].Phi(), 0);
          else tauv2_v.SetPtEtaPhiM(val[3],val[4],val[5],6);
          if(nTaus_OR_Pt25 >= 2) {
            x1fit = 1 / (1 + val[0]);
            x2fit = 1 / (1 + val[1]);
          }else{
            drlb = taus_v[0].DeltaR(bjet_v);
            drtaub = taus_v[1].DeltaR(bjet_v);
            x1fit = taus_v[0].E() / (taus_v[0] + tauv1_v).E();
            x2fit = taus_v[1].E() / (taus_v[1] + tauv2_v).E();
          }
          neutrino_pt->push_back(tauv1_v.Pt());
          neutrino_pt->push_back(tauv2_v.Pt());
          neutrino_eta->push_back(tauv1_v.Eta());
          neutrino_eta->push_back(tauv2_v.Eta());
          neutrino_phi->push_back(tauv1_v.Phi());
          neutrino_phi->push_back(tauv2_v.Phi());
          neutrino_m->push_back(tauv1_v.M());
          neutrino_m->push_back(tauv2_v.M());
          if (nTaus_OR_Pt25 >= 2) {
            TLorentzVector wv_v;
            wv_v.SetPtEtaPhiM(val[2], val[3], val[4], 0);
            neutrino_pt->push_back(wv_v.Pt());
            neutrino_eta->push_back(wv_v.Eta());
            neutrino_phi->push_back(wv_v.Phi());
            neutrino_m->push_back(wv_v.M());
            t1mass = (lep_v + wv_v + bjet_v).M();
            wmass = (lep_v + wv_v).M();
          }
          t2mass = (tauv2_v + taus_v[0] + tauv1_v + taus_v[1] + cjet_v).M();
          tautaumass = (tauv2_v + taus_v[0] + tauv1_v + taus_v[1]).M();
          TLorentzVector all = taus_v[0]+ taus_v[1] + bjet_v;
          for (int i = 0; i < ljet_indice.size(); ++i)
          {
            all+=ljets_v[ljet_indice[i]];
          }
          allmass = all.M();
          allpz = all.Pz();
        }

        if (nTaus_OR_Pt25 >= 2) {
          tau_pt_ss = lep_ID_0*tau_charge_0 > 0 ? tau_pt_0 : tau_pt_1;
          tau_pt_os = lep_ID_0*tau_charge_0 < 0 ? tau_pt_0 : tau_pt_1;
          drlbditau = (lep_v + bjet_v).DeltaR(taus_v[0] + taus_v[1]);
          drlb = lep_v.DeltaR(bjet_v);
          drtaub = bjet_v.DeltaR(taus_v[0]);
          t1vismass = (lep_v + bjet_v).M();
          mtw = 2*lep_Pt_0*MET_RefFinal_et*(1 - cos(MET_RefFinal_phi - lep_Phi_0));
          mtw = mtw > 0 ? sqrt(mtw) : 0.;
          etamax = fabs(tau_eta_0) > fabs(tau_eta_1) ? fabs(tau_eta_0) : fabs(tau_eta_1);
          drltau = min(taus_v[0].DeltaR(lep_v), taus_v[1].DeltaR(lep_v));
          if(drltau < 0.2) {
            printf("WARINING: Delta(l,tau) is less than 0.2, please check: eventNumber = %llu\n",eventNumber);
            printv(taus_v[0]);
            printv(taus_v[1]);
            printv(lep_v);
          }
          TLorentzVector all = taus_v[0]+ taus_v[1] + bjet_v;
          for (int i = 0; i < ljet_indice.size(); ++i)
          {
            all+=ljets_v[ljet_indice[i]];
          }
          allmass = all.M();
          allpz = all.Pz();
          phicent = 0;
        } else {
          tau_pt_1 = lep_Pt_0;
          phicent = phi_centrality(taus_v[0].Phi(),taus_v[1].Phi(),met_phi);
          t1vismass = t1mass;
          drlbditau = 0;
          mtw = 0;
          etamax = 0;
          tau_pt_ss = 0;
          tau_pt_os = 0;
          drltau = 0;
        }
        tau_leadpt = taus_v[0].Pt();
        tau_subpt = taus_v[1].Pt();
        ttvismass = (taus_v[0] + taus_v[1]).M();
        tautauvispt = (taus_v[0] + taus_v[1]).Pt();
        t2vismass = nJets_OR_T >= 2 ? (taus_v[0] + taus_v[1] + cjet_v).M() : 0;
        drtautau = taus_v[0].DeltaR(taus_v[1]);
        drtauj = nJets_OR_T >= 2 ? (taus_v[0] + taus_v[1]).DeltaR(cjet_v) : 0;

      } else if (nljet) {
        if (ifregions["reg1l1tau2b1j_os"] || ifregions["reg1l1tau2b1j_ss"]) {
          if(nJets_OR_T != 3) continue;
          taulmass = (taus_v[1] + ljets_v[0]).M();
        } else taulmass = 0;
      }
      dphitauetmiss = fabs(met_phi - (taus_v[0] + taus_v[1]).Phi());
    }
    if(reduce == 3){
      if (ifregions["reg1l2tau1bnj_os"] || ifregions["reg1l2tau1bnj_ss"] || ifregions["reg1l2tau2bnj_os"] || ifregions["reg1l2tau2bnj_ss"])
        if(t1vismass > 190*GeV )
          continue;
      tthcutflow.fill();
      if(ttvismass > 125*GeV ) continue;
      tthcutflow.fill();
      if(ttvismass < 25*GeV ) continue;      
      tthcutflow.fill();
      allpz = fabs(allpz);
      if(debug) printf("eval BDTG\n");

      if(fcncreg=="1l2tau") BDTG_test  = reader["reg1l2tau1bnj_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
      if(fcncreg=="lh3j"  ) BDTG_test  = reader["reg1l1tau1b2j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
      if(fcncreg=="lh4j"  ) BDTG_test  = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
      if(fcncreg=="1l2tau") BDTG_train = reader["reg1l2tau1bnj_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
      if(fcncreg=="lh3j"  ) BDTG_train = reader["reg1l1tau1b2j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
      if(fcncreg=="lh4j"  ) BDTG_train = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
      if(dumpeventnumber) {
        for(auto reg : ifregions){
          if(reg.second == 0) continue;
          if(mc_channel_number>0)
            evtfile<<reg.first<<" "<<mc_channel_number<<" "<<eventNumber<<endl;
          else
            evtfile<<reg.first<<" "<<runNumber<<" "<<eventNumber<<endl;
        }
      }
    }
      //===============================fill histograms, fill tree===============================
    if(debug) printf("derive origin\n");
    TString tauorigin;
    int SFbin[2] = {tau_pt_0 / GeV > 35, tau_pt_1 / GeV > 35};
    fakeSF = 1;
    int origintag[2] = {-1,-1};
    if (sample.Contains("data")) {
      tauorigin = "data";
      sample = "data";
    } else if (nTaus_OR_Pt25 >= 1 || reduce == 3) {
      if (tau_truthType_0 == 10) tauorigin = sample + "_real";
      else if (tau_truthJetFlavour_0 < 0 && (tau_truthType_0 == 2 || tau_truthType_0 == 6)) tauorigin = sample + "_lep";
      else
        switch (tau_truthJetFlavour_0) {
        case 5:
          tauorigin = sample + "_b";
          fakeSF = fakeSFs[SFbin[0]][0];
          origintag[0] = 0;
          break;
        case 4:
          tauorigin = sample + "_c";
          fakeSF = fakeSFs[SFbin[0]][1];
          origintag[0] = 1;
          break;
        case 21:
          tauorigin = sample + "_g";
          fakeSF = fakeSFs[SFbin[0]][2];
          origintag[0] = 2;
          break;
        default:
          tauorigin = sample + "_j";
          fakeSF = fakeSFs[SFbin[0]][3];
          origintag[0] = 3;
        }
      if(ifregions["reg1l2tau1bnj_os"] || ifregions["reg1l2tau1bnj_ss"])
        if (tau_truthType_1 != 10 && tau_truthType_1 !=2 && tau_truthType_1 !=6 && tau_truthJetFlavour_1 < 0)
          switch (tau_truthJetFlavour_1) {
          case 5:
            fakeSF *= fakeSFs[SFbin[1]][0];
            origintag[1] = 0;
            break;
          case 4:
            fakeSF *= fakeSFs[SFbin[1]][1];
            origintag[1] = 1;
            break;
          case 21:
            fakeSF *= fakeSFs[SFbin[1]][2];
            origintag[1] = 2;
            break;
          default:
            fakeSF *= fakeSFs[SFbin[1]][3];
            origintag[1] = 3;
          }
    }
    if(debug) printf("calc SF\n");
    if(reduce == 1){
      weights->clear();
      weights->push_back(weight);
      if(triggeredfcnc && mc_channel_number){
        weights->push_back(fakeSF);
        //for (int iNP = 0; iNP < 8; ++iNP)
        //{
        //  double valNP = weight;
        //  for (int itau = 0; itau < nTaus_OR_Pt25; ++itau)
        //  {
        //    if(origintag[itau] >= 0 ){
        //      if ( iNP < 4 && SFbin[itau] == 0 )
        //         valNP *= fakeSFs[SFbin[itau]][origintag[itau]]+fakeSFsNPbase[SFbin[itau]][origintag[itau]][iNP]*sqrt(fakeSFsNPsSigma2[SFbin[itau]][iNP]);
        //      else if (iNP >= 4 && iNP < 8 && SFbin[itau] == 1) {
        //         valNP *= fakeSFs[SFbin[itau]][origintag[itau]]+fakeSFsNPbase[SFbin[itau]][origintag[itau]][iNP-4]*sqrt(fakeSFsNPsSigma2[SFbin[itau]][iNP-4]);
        //      }
        //    }
        //  }
        //  weights->push_back(valNP);
        //}

        if(origintag[0] >=0 || origintag[1] >= 0){
          double faketauSF = 1;
          double faketauSFNP[2][3] = {{1,1,1},{1,1,1}};
          for (int ifaketau = 0; ifaketau < 2; ++ifaketau){

            if( origintag[ifaketau] < 0) continue; 
            int prongbin = (ifaketau==0?tau_numTrack_0:tau_numTrack_1)  == 3;
            int ptbin;
            double faketaupt = (ifaketau==0?tau_pt_0:tau_pt_1) / GeV;
            if(prongbin == 0) {
              if(faketaupt<45) ptbin = 0;
              else if(faketaupt < 70) ptbin = 1;
              else ptbin = 2;
            }else{
              if(faketaupt<50) ptbin = 0;
              else if(faketaupt < 75) ptbin = 1;
              else ptbin = 2;
            }
            faketauSF *= fakeSFML[prongbin][ptbin];
            if(nominaltree) faketauSFNP[prongbin][ptbin] *= fakeSFMLNP[prongbin][ptbin]/fakeSFML[prongbin][ptbin] + 1;
          }
          weights->push_back(faketauSF);
          if(nominaltree) {
            for (int inpprongbin = 0; inpprongbin < 2; ++inpprongbin)
            {
              for (int inpptbin = 0; inpptbin < 3; ++inpptbin)
              {
                weights->push_back(faketauSFNP[inpprongbin][inpptbin]);
              }
            }
          }
        }else{
          weights->push_back(1);
          if(nominaltree) for (int i = 0 ; i < 6 ; ++i) weights->push_back(1);
        } //fake SF, need to be multiplied by weight
      }
    }

    if (dumptruth && triggeredfcnc && sample.Contains("fcnc")) dumpTruth(eventNumber % 2);

    for (iter = ifregions.begin(); iter != ifregions.end(); iter++) {
      if (iter->second == 1) {
        if (writetree) {
          if(debug) printf("fill tree: %s\n", iter->first.Data());
          outputtree[iter->first]->Fill();
        }
        if (dohist) {
          if(debug) printf("fill hist\n");
          for (int iNP = 0; iNP < plotNPs.size(); ++iNP)
          {
            if(iNP != 0 && tauorigin.Contains("data")) continue;
            if(plotNPs[iNP]==1) weight = weights->at(1);
            else
              weight = weights->at(0) * ((tauorigin.Contains("data")||plotNPs[iNP]!=0)?1:weights->at(2)) * ((plotNPs[iNP]==0 || plotNPs[iNP]==2)? 1:weights->at(plotNPs[iNP]));
            if (iter->first.Contains("tau")) {
              if (triggeredfcnc) fill_fcnc(iter->first, tau_numTrack_0, tauorigin, tau_pt_0 / GeV > 35, tau_MV2c10_0, iNP);
              else if (!sample.Contains("fcnc")) fill_fake(iter->first, tau_numTrack_0, tauorigin, tau_pt_0 / GeV > 35, tau_MV2c10_0);
            } else fill_notau(iter->first, sample);
          }
        }
      }
    }
    if(reduce ==2){
      neutrino_pt->clear();
      neutrino_eta->clear();
      neutrino_phi->clear();
      neutrino_m->clear();
      ljets_v.clear();
    }
  }
  if(reduce > 1) printf("%s ", inputtree->GetName());
  tthcutflow.print();
  tthcutflow.clear();
  evtfile.close()
  if (dumptruth) {
    if (TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) {
      filetruth[0][0].close();
      filetruth[0][1].close();
    } else
      for (int i = 0; i < 6; ++i) {
        if (TString(inputtree->GetName()).Contains("reg1l1tau1b3j")) {
          if (i != 0) {
            filetruth[i][0].close();
            filetruth[i][1].close();
          }
        } else {
          filetruth[i][0].close();
          filetruth[i][1].close();
        }
      }
  }
  if (writetree) {
    outputtreefile->cd();
    map < TString, TTree*> ::iterator iter;
    for (iter = outputtree.begin(); iter != outputtree.end(); ++iter)
      iter->second->Write(iter->first, TObject::kWriteDelete);
  }
}
void tthmltree::dumpTruth(int ipart) {
  TLorentzVector wchild[2], fcncjet, wboson;
  stringstream outstream;
  fstream*truthfile = & (filetruth[min(nJets_OR_T - (nTaus_OR_Pt25 == 1 ? 3 : 2), 2)][ipart]);
  fstream nonmatchedfile;
  nonmatchedfile.open("nonmatch.txt", fstream:: in | fstream::out | fstream::app);
  if (debug) printf("truth particles: %lu\n", m_truth_pdgId->size());
  bool foundcjet = 0;
  int foundw = 0;
  bool iffcncmatched = 0;
  bool foundhiggs = 0;
  if (debug) printf("find truth: mc channel: %d\n", mc_channel_number);
  for (int itruth = 0; itruth < m_truth_pdgId->size(); ++itruth) {
    if (debug) printf("pdg: %d,\tbarcode: %d,\tparent: %d\n", m_truth_pdgId->at(itruth), m_truth_barcode->at(itruth), m_truth_parents->at(itruth).size() ? m_truth_parents->at(itruth)[0] : 0);
    if (nTaus_OR_Pt25 == 1 && abs(m_truth_pdgId->at(itruth)) == 24 && m_truth_m->at(itruth) / GeV > 70 && m_truth_m->at(itruth) / GeV < 90) {
      for (int ichild = 0; ichild < m_truth_children->at(itruth).size(); ++ichild) {
        int childbarcode = m_truth_children->at(itruth)[ichild];
        if (debug) printf("child barcode %d\n", childbarcode);
        int childid = 0;
        for (int i = 0; i < m_truth_barcode->size(); ++i) {
          if (m_truth_barcode->at(i) == childbarcode) {
            childid = i;
            break;
          }
        }
        if (debug) printf("child pdg: %d\n", m_truth_pdgId->at(childid));
        if (!(mc_channel_number == 411170 || mc_channel_number == 411171 || mc_channel_number == 411174 || mc_channel_number == 411175)) {
          leptonicw += weight;
          return;
        }
        if (abs(m_truth_pdgId->at(childid)) > 4 || abs(m_truth_pdgId->at(childid)) < 1) {
          break;
        }
        if (debug) printf("childid: %d\n", childid);
        wchild[foundw].SetPtEtaPhiM(m_truth_pt->at(childid), m_truth_eta->at(childid), m_truth_phi->at(childid), m_truth_m->at(childid));
        if (debug) outstream << "wjet:\t" << wchild[foundw].Pt() << " " << wchild[foundw].Eta() << " " << wchild[foundw].Phi() << " " << wchild[foundw].E() << " " << m_truth_pdgId->at(childid) << endl;
        foundw += 1;
        if (foundw == 1) wboson.SetPtEtaPhiM(m_truth_pt->at(itruth), m_truth_eta->at(itruth), m_truth_phi->at(itruth), m_truth_m->at(itruth));
      }
    } else if ((abs(m_truth_pdgId->at(itruth)) == 2 || abs(m_truth_pdgId->at(itruth)) == 4)) {
      int parent = -1;
      for (int i = 0; i < m_truth_barcode->size(); ++i) {
        if (m_truth_barcode->at(i) == m_truth_parents->at(itruth)[0]) {
          parent = i;
          break;
        }
      }
      if (abs(m_truth_pdgId->at(parent)) == 6) {
        foundcjet = 1;
        fcncjet.SetPtEtaPhiM(m_truth_pt->at(itruth), m_truth_eta->at(itruth), m_truth_phi->at(itruth), m_truth_m->at(itruth));
        if (debug) outstream << "cjet:\t" << fcncjet.Pt() << " " << fcncjet.Eta() << " " << fcncjet.Phi() << " " << fcncjet.E() << " " << m_truth_pdgId->at(itruth) << endl;
        if (debug) outstream << "fcnctop:\t" << m_truth_pt->at(parent) << " " << m_truth_eta->at(parent) << " " << m_truth_phi->at(parent) << " " << m_truth_m->at(parent) << " " << m_truth_pdgId->at(parent) << endl;
      }
    }
    if (m_truth_pdgId->at(itruth) == 25) {
      if (debug) outstream << "higgs:\t" << m_truth_pt->at(itruth) << " " << m_truth_eta->at(itruth) << " " << m_truth_phi->at(itruth) << " " << m_truth_m->at(itruth) << " " << m_truth_pdgId->at(itruth) << endl;
      foundhiggs = 1;
    }
    if (foundw == 2 && foundcjet && foundhiggs) break;
  }
  if (debug && !foundw) printf("coundn't find truth w jets\n");
  if (debug && !foundcjet) printf("coundn't find truth fcnc jets\n");
  if ((!foundw && nTaus_OR_Pt25 == 1) || !foundcjet) return;
  if (nTaus_OR_Pt25 == 1) {
    if (foundw == 1) {
      wchild[1] = wboson - wchild[0];
      if (debug) outstream << "wjet:\t" << wchild[1].Pt() << " " << wchild[1].Eta() << " " << wchild[1].Phi() << " " << wchild[1].E() << endl;
    }
  }
  int loopmax = min(nJets_OR_T, (nTaus_OR_Pt25 == 1 ? 3 : 2) + 2);
  int ijet = 0;
  for (auto jetv : ljets_v) {
    ijet += 1;
    if(ijet >= loopmax) break;
    outstream << "pool: " << jetv.Pt() << " " << jetv.Eta() << " " << jetv.Phi() << " " << jetv.E();
    bool wmatched = 0;
    if (jetv.DeltaR(fcncjet) < 0.4) {
      outstream << " 1 0 0\n";
      iffcncmatched = 1;
      continue;
    } else if (nTaus_OR_Pt25 == 1) {
      for (int ichild = 0; ichild < 2; ++ichild) {
        if (jetv.DeltaR(wchild[ichild]) < 0.4) {
          outstream << " 0 1 0\n";
          wmatched = 1;
          break;
        }
      }
    }
    if (!wmatched) outstream << " 0 0 1\n";
  }
  outstream << "bjet: " << bjet_v.Pt() << " " << bjet_v.Eta() << " " << bjet_v.Phi() << " " << bjet_v.E() << "\n";
  for (int i = 0; i < 2; ++i) {
    outstream << "taus: " << taus_v[i].Pt() << " " << taus_v[i].Eta() << " " << taus_v[i].Phi() << " " << taus_v[i].E() << "\n";
  }
  if (nTaus_OR_Pt25 >= 2) {
    outstream << "leptons: " << lep_v.Pt() << " " << lep_v.Eta() << " " << lep_v.Phi() << " " << lep_v.E() << "\n";
  }
  if (iffcncmatched) {
    (*truthfile) << outstream.rdbuf() << "eventweight: " << weight << " cjet_inv_mass_method: " << ljet_indice[0] << endl;
    fcncmatched += weight;
  } else {
    nonmatchedfile << outstream.rdbuf() << nonfcncmatched << endl;
    nonfcncmatched += weight;
  }
  nonmatchedfile.close();
}

bool tthmltree::SelectTLepid(int id) {
  bool pass(false);
  //lep_ambiguityType_0==0 for electron
  if (id == 0) {
    pass = lep_isolationFixedCutLoose_0 && (abs(lep_ID_0) == 13 || ((abs(lep_ID_0) == 11) && lep_isTightLH_0));
  } else if (id == 1) {
    pass = lep_isolationFixedCutLoose_1 && (abs(lep_ID_1) == 13 || ((abs(lep_ID_1) == 11) && lep_isTightLH_1));
  } else if (id == 2) {
    pass = lep_isolationFixedCutLoose_2 && (abs(lep_ID_2) == 13 || ((abs(lep_ID_2) == 11) && lep_isTightLH_2));
  } else if (id == 3) {
    pass = lep_isolationFixedCutLoose_3 && (abs(lep_ID_3) == 13 || ((abs(lep_ID_3) == 11) && lep_isTightLH_3));
  } else if (id == 4) {
    pass = lep_isolationFixedCutLoose_4 && (abs(lep_ID_4) == 13 || ((abs(lep_ID_4) == 11) && lep_isTightLH_4));
  }
  return pass;
}
