#include "nominal.h"
#include "fcnc_include.h"
#include "common.h"
#include "makechart.h"
using namespace std;
int nominal::GeV = 0;

void nominal::initMVA(TString fcnc_region){

  doBDT = 1;

  reader[fcnc_region] = new TMVA::Reader( "!Color:!Silent" );

  reader[fcnc_region]->AddVariable("tau_pt_0",&tau_pt_0);
  reader[fcnc_region]->AddVariable("tau_pt_1",&tau_pt_1);
  reader[fcnc_region]->AddVariable("drtautau",&drtautau);
  if(fcnc_region.Contains("2j") || fcnc_region.Contains("3j")){
     reader[fcnc_region]->AddVariable("etmiss",&etmiss);
     reader[fcnc_region]->AddVariable("dphitauetmiss",&dphitauetmiss);
     reader[fcnc_region]->AddVariable("phicent",&phicent);
     reader[fcnc_region]->AddVariable("tautaumass",&tautaumass);
     reader[fcnc_region]->AddVariable("t2mass",&t2mass);
     reader[fcnc_region]->AddVariable("x1fit",&x1fit);
     reader[fcnc_region]->AddVariable("x2fit",&x2fit);
     if(fcnc_region.Contains("1l1tau")){
        reader[fcnc_region]->AddVariable("drlb",&drlb);
        reader[fcnc_region]->AddVariable("drtaub",&drtaub);
        reader[fcnc_region]->AddVariable("mjjmin",&mjjmin);
     }
     if(fcnc_region != "reg1l1tau1b2j"){
        reader[fcnc_region]->AddVariable("wmass",&wmass);
        reader[fcnc_region]->AddVariable("t1mass",&t1mass);
     }
     if(fcnc_region.Contains("1l1tau1b2j")){
        reader[fcnc_region]->AddVariable("allpz",&allpz);
        reader[fcnc_region]->AddVariable("allmass",&allmass);
     }
  }else if(fcnc_region.Contains("1l2tau1")){
     reader[fcnc_region]->AddVariable("t1vismass",&t1vismass);
     reader[fcnc_region]->AddVariable("mtaujmin",&mtaujmin);
     reader[fcnc_region]->AddVariable("drltau",&drltau);
     reader[fcnc_region]->AddVariable("etamax",&etamax);
     reader[fcnc_region]->AddVariable("mtw",&mtw);
     reader[fcnc_region]->AddVariable("drlbditau",&drlbditau);
     reader[fcnc_region]->AddVariable("tautauvispt",&tautauvispt);
     reader[fcnc_region]->AddVariable("t2vismass",&t2vismass);
  }

  reader[fcnc_region]->AddVariable("ttvismass",&ttvismass);
  reader[fcnc_region]->AddVariable("drtaujmin",&drtaujmin);

  reader[fcnc_region]->BookMVA( "BDTG_1" , TString(PACKAGE_DIR) + "/config/weights/" + fcnc_region + "TMVAClassification_1_BDTG.weights.xml" );
  reader[fcnc_region]->BookMVA( "BDTG_2" , TString(PACKAGE_DIR) + "/config/weights/" + fcnc_region + "TMVAClassification_2_BDTG.weights.xml" );
}


Double_t nominal::phi_centrality(Double_t aPhi, Double_t bPhi, Double_t cPhi) {
//     Calculate the phi centrality score for an object to be between two other objects in phi
//     Returns sqrt(2) if in dead center
//     Returns smaller than 1 if an object is not between
//     a and b are the bounds, c is the vector to be tested

  Double_t A = sin(cPhi - aPhi)/sin(bPhi - aPhi);
  Double_t B = sin(bPhi - cPhi)/sin(bPhi - aPhi);

  return (A+B)/sqrt(A*A + B*B);
}



RooRealVar  nominal::_dR_("_dR_","",0,0.8);
RooRealVar  nominal::_m1_("_m1_","",0.06);
RooRealVar  nominal::_w1_("_w1_","",0.03);
RooGaussian nominal::_gaus_("_gaus_","",_dR_,_m1_,_w1_);
RooRealVar  nominal::_m2_("_m2_","",0.1);
RooRealVar  nominal::_w2_("_w2_","",0.1);
RooLandau   nominal::_land_("_land_","",_dR_,_m2_,_w2_);
RooRealVar  nominal::_fr1_("_fr1_","",0.56);
RooAddPdf   nominal::_pdf_("_pdf_","",_gaus_,_land_,_fr1_);

Float_t nominal::getHadTauProb(Float_t _dR, Float_t _p) {
  if(_dR>=_dR_.getMax()) return 0;
  if(_p<25) _p = 25;
  Float_t m1 = 4.56088e+00/(_p+2.30554e-02*_p*_p)+2.00545e-02;
  Float_t w1 = 2.56901e+01/(_p*_p)+9.63415e-03;
  Float_t m2 = 5.70742e+00/(_p+2.07263e-02*_p*_p)+4.32004e-02;
  Float_t w2 = 4.34997e+00/pow(_p,1.5)+7.31908e-03;
  _m1_.setVal(m1);
  _w1_.setVal(w1);
  _m2_.setVal(m2);
  _w2_.setVal(w2);
  _dR_.setVal(_dR);
  return _pdf_.getVal(_dR_);
}


nominal::nominal(){
  doBDT = 0;
  ierflg = 0;
  dumptruth = 0;
  nonfcncmatched = 0;
  fcncmatched = 0;
  leptonicw = 0;
  fcnc = 0;
  debug = 0;
  dosys = 0;
  reduce = 0;
  initdata = 0;
  initttbar = 0;
  dohist = 0;
  version = 0;
  pt_b = 0;
  pt_ljet = 0;
  taulmass = 0;
  t1mass = 0;
  drlbditau = 0;
  mtw = 0;
  tau_pt_ss = 0;
  tau_pt_os = 0;
  etamax = 0;
  drltau   = 0;
  drtauj   = 0;
  drtautau = 0;
  wmass     = 0;
  t2mass    = 0;
  tautaumass = 0;
  outputtreefile = 0;
  fake_plots = 0;
  fake_notau_plots = 0;

  for (int i = 0; i < 4; ++i)
  {
    dobwp[bwps[i]] = 0;
    dovetobwp[bwps[i]] = 0;
  }

  neutrino_pt  = new vector<float>();
  neutrino_eta = new vector<float>();
  neutrino_phi = new vector<float>();
  neutrino_m   = new vector<float>();
  fake_plots = 0;
  fake_notau_plots = 0;
  gMinside = initgM();
  
  cut_flow.setWeight(&weight);
  cut_flow.setEventNumber(&eventNumber);
}

void nominal::defGeV(int _GeV){
  GeV = _GeV;
}

void nominal::readTFmeanstd(TString filename){
  m_applyTF.configfolder = "/Users/Liby/work/tau_analysis/FCNC/ttH_fakes/run/MLmodels";
  m_applyTF.readmeanfile(filename);
}


nominal::~nominal(){
  deletepointer(fake_plots);
  deletepointer(fcnc_plots);
  deletepointer(fake_notau_plots);
  deletepointer(gM);
  deletepointer(neutrino_pt  );
  deletepointer(neutrino_eta );
  deletepointer(neutrino_phi );
  deletepointer(neutrino_m   );
}

void nominal::initReduce1(){
  taus_n_charged_tracks = new vector<UInt_t> ();
  taus_b_tagged = new vector<Int_t> ();
  taus_p4 = new vector<TLorentzVector*>();
  taus_q = new vector<Float_t> ();
  leps_id = new vector<Int_t> ();
  bjets_p4 = new vector<TLorentzVector*>;
  ljets_p4 = new vector<TLorentzVector*>();
  leps_p4 = new vector<TLorentzVector*>();
  met_p4 = new TLorentzVector();
}

void nominal::setVecBranch(TTree *tree){
  tree->SetBranchAddress("leps_p4", &leps_p4);
  tree->SetBranchAddress("leps_id", &leps_id);
  tree->SetBranchAddress("bjets_p4", &bjets_p4);
  tree->SetBranchAddress("met_p4", &met_p4);
  tree->SetBranchAddress("taus_p4", &taus_p4);
  tree->SetBranchAddress("ljets_p4", &ljets_p4);
  tree->SetBranchAddress("taus_n_charged_tracks", &taus_n_charged_tracks);
  tree->SetBranchAddress("taus_b_tagged", &taus_b_tagged);
  tree->SetBranchAddress("taus_q", &taus_q);
}

void nominal::vecBranch(TTree *tree){
  tree->Branch("leps_p4", &leps_p4);
  tree->Branch("leps_id", &leps_id);
  tree->Branch("bjets_p4", &bjets_p4);
  tree->Branch("met_p4", &met_p4);
  tree->Branch("taus_p4", &taus_p4);
  tree->Branch("ljets_p4", &ljets_p4);
  tree->Branch("taus_n_charged_tracks", &taus_n_charged_tracks);
  tree->Branch("taus_b_tagged", &taus_b_tagged);
  tree->Branch("taus_q", &taus_q);
}


void nominal::initFit(){
  fitvec["taus"] = taus_p4;
  fitvec["leps"] = leps_p4;
  fitvec["bjets"] = bjets_p4;
  fitvec["ljets"] = ljets_p4;
  fitvec["met"] = new vector<TLorentzVector*>();
  fitvec["met"]->push_back(met_p4);
}

void nominal::init_dsid(){
  ifill = 0;
  weightlist.clear();
}

void nominal::plot(){
  if(fake_plots) {
    if(debug) printf("write fake_plots\n");
    fake_plots->write();
  }
  if(fcnc_plots) {
    if(debug) printf("write fcnc_plots\n");
    fcnc_plots->write();
  }
  if(fake_notau_plots) {
    if(debug) printf("write fake_notau_plots\n");
    fake_notau_plots->write();
  }
}

void nominal::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {

  auto *fitvec = (std::map<TString,std::vector<TLorentzVector*>*>*) gM->GetObjectFit();
  if (!fitvec)
  {
    printf("list isnt found\n");
    exit(1);
  }

  std::vector<TLorentzVector*> *taus = fitvec->at("taus");
  std::vector<TLorentzVector*> *leps = fitvec->at("leps");
  std::vector<TLorentzVector*> *bjets = fitvec->at("bjets");
  std::vector<TLorentzVector*> *ljets = fitvec->at("ljets");
  std::vector<TLorentzVector*> *met = fitvec->at("met");
  TString channel;
  if(taus->size() == 2 && leps->size() == 0) channel = "hadhad";
  else if(taus->size() == 1 && leps->size() == 1) channel = "lephad";
  else if(taus->size() == 2 && leps->size() == 1) channel = "lep2tau";
  else if(taus->size() == 1 && leps->size() == 2) channel = "2lSStau";
  else {
    printf("nominal::fcn() Error: Channel not found: %lu leptons, %lu taus\n", leps->size(), taus->size());
    exit(1);
  }

  TLorentzVector neutrino[3];
  //neutrino 0 is from leading tau. neutrino 1 is from subleading tau or leptonic tau.

  if(channel == "lep2tau"){

    neutrino[0].SetPtEtaPhiM(par[0]*taus->at(0)->Pt(),taus->at(0)->Eta(),taus->at(0)->Phi(),0);
    neutrino[1].SetPtEtaPhiM(par[1]*taus->at(1)->Pt(),taus->at(1)->Eta(),taus->at(1)->Phi(),0);
    Float_t Hmass = (*taus->at(0)+neutrino[0]+*taus->at(1)+neutrino[1]).M();
    Float_t met_resol = 13.1*GeV+0.50*sqrt(met->at(0)->Pz()*GeV);
    f = 1e10;
  
    neutrino[2].SetPtEtaPhiM(par[2],par[3],par[4],0);
    TLorentzVector t1 = neutrino[2]+*leps->at(0)+*bjets->at(0);
    //Float_t t2mass= (*taus->at(0)+neutrino[0]+*taus->at(1)+neutrino[1]+*ljet->at(0)).M();
    Float_t wmass = (*leps->at(0) + neutrino[2]).M();
    Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
    Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
    //Float_t pConstrain = (bjets->at(0).Dot(leps->at(0))/100) + (bjets->at(0).Dot(neutrino[2])/100);
    f =  pow((wmass-81*GeV)/10/GeV,2) + pow((t1.M()-172.5*GeV)/25/GeV,2) +pow((pxMiss-met->at(0)->Px())/met_resol,2) + pow((pyMiss-met->at(0)->Py())/met_resol,2) + pow((Hmass-125*GeV)/10/GeV,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
  }else{
    neutrino[0].SetPtEtaPhiM(par[0],par[1],par[2],0);
    neutrino[1].SetPtEtaPhiM(par[3],par[4],par[5],par[6]);
  
    Float_t prob1(0), prob2(0);
    Float_t mass1, mass2, mass, pxMiss, pyMiss;
  
    prob1 = getHadTauProb(taus->at(0)->DeltaR(neutrino[0]),(*taus->at(0)+neutrino[0]).P()/GeV);
    mass1 = (*taus->at(0)+neutrino[0]).M();
  
    if(channel == "lephad") {
      prob2 = getLepTauProb(leps->at(0)->DeltaR(neutrino[1]),neutrino[1].M()/GeV,(*leps->at(0)+neutrino[1]).P()/GeV);
      mass2 = (*leps->at(0)+neutrino[1]).M();
      mass = (*taus->at(0)+neutrino[0]+*leps->at(0)+neutrino[1]).M();
    }
    else if(channel == "hadhad") {
      prob2 = getHadTauProb(taus->at(1)->DeltaR(neutrino[1]),(*taus->at(1)+neutrino[1]).P()/GeV);
      mass2 = (*taus->at(1)+neutrino[1]).M();
      mass = (*taus->at(0)+neutrino[0]+*taus->at(1)+neutrino[1]).M();
    }
    pxMiss = neutrino[0].Px()+neutrino[1].Px();
    pyMiss = neutrino[0].Py()+neutrino[1].Py();
    
    f = 1e10;
    if(prob1>0 && prob2>0) {
      Float_t met_resol = (13.1+0.50*sqrt(met->at(0)->Pz()/GeV))*GeV;
      f = -2*log(prob1) -2*log(prob2) + pow((mass1-1.777*GeV)/1.777/GeV,2) + pow((mass2-1.777*GeV)/1.777/GeV,2) + pow((mass-125*GeV)/20/GeV,2) + pow((pxMiss-met->at(0)->Px())/met_resol,2) + pow((pyMiss-met->at(0)->Py())/met_resol,2);
    }
  }
}



vector<int> nominal::findcjet(){
  double m_w = 81*GeV;
  vector<int> output;
  TString channel;
  if(taus_p4->size() + leps_p4->size() == 3) channel = "leponicW";
  else if(taus_p4->size() + leps_p4->size() == 2) channel = "hadronicW";
  else printf("ERROR: channel not recognized: %lu leptons and %lu taus\n", leps_p4->size(), taus_p4->size());
  int nlightj = ljets_p4->size();
  if(!nlightj) return output;
  if(debug) printf("nlightj: %d\n", nlightj); 
  double smallDr = NAN;
  TLorentzVector *closelep = 0;
  int fcjet = 0;
  if(leps_p4->size() >= 1){
    for(auto lep: *leps_p4){
      double Dr = lep->DeltaR(*taus_p4->at(0));
      if(Dr<smallDr || smallDr != smallDr) {
        closelep = lep;
        smallDr = Dr;
      }
    }
  }
  smallDr = NAN;
  for (int j = 0; j < nlightj; ++j){
    double Dr = ljets_p4->at(j)->DeltaR(taus_p4->size()>=2? *taus_p4->at(0) + *taus_p4->at(1) : *taus_p4->at(0) + *closelep);
    if(smallDr>Dr || smallDr != smallDr){
      smallDr = Dr;
      fcjet = j;
    }
  }
  output.push_back(fcjet);
  if (channel == "hadronicW"){
    if(nlightj <= 3){
      for (int i = 0; i < nlightj; ++i){
        if(i!=fcjet) output.push_back(i);
      }
    }else{
      vector<int> wpair = findwpair(fcjet);
      output.push_back(wpair[0]);
      output.push_back(wpair[1]);
      wmass = (*ljets_p4->at(output[1]) + *ljets_p4->at(output[2])).M();
    }
    TLorentzVector top = *bjets_p4->at(0);
    for (int i = 1; i < output.size(); ++i)
    {
      top = top + *ljets_p4->at(output[i]);
    }
    t1vismass = top.M();
    t1mass = t1vismass;
  }else{
    t1vismass = (*leps_p4->at(0) + *bjets_p4->at(0)).M();
  }
  return output;
}

vector<int> nominal::findcjetML(int trainpart){
  int nlightj = taus_p4->size()>=2?(ljets_p4->size()>3?3:ljets_p4->size()):(ljets_p4->size()>4?4:ljets_p4->size());
  vector<int>  output;
  vector<float> MLinput[10];
  int nentryML = 0;
  TString modelname;
  if(leps_p4->size() == 1 && taus_p4->size() == 1){
    modelname = "lephad";
  }
  else if(leps_p4->size() == 1 && taus_p4->size() == 2){
    modelname = "lep2tau";
  }else if(leps_p4->size() == 0 && taus_p4->size() == 2){
    modelname = "hadhad";
  }else{
    printf("channel not recognized: %lu leptons, %lu taus\n", leps_p4->size(), taus_p4->size());
    exit(0);
  }
  modelname = modelname + char(nlightj + '0') + "j";
  if(debug) printf("lightjet:\n");
  for (int i = 0; i < nlightj; ++i)
  {
    if(debug) printv(*ljets_p4->at(i));
    //MLinput[nentryML].push_back(ljets_p4->at(i)->Pt());
    MLinput[nentryML].push_back(ljets_p4->at(i)->Eta());
    MLinput[nentryML].push_back(ljets_p4->at(i)->Phi());
    MLinput[nentryML].push_back(ljets_p4->at(i)->E());
    nentryML++;
  }
  if(debug) printf("bjet:\n");
  //printv(bjet);
  //MLinput[nentryML].push_back(bjets_p4->at(0)->Pt ());
  MLinput[nentryML].push_back(bjets_p4->at(0)->Eta());
  MLinput[nentryML].push_back(bjets_p4->at(0)->Phi());
  MLinput[nentryML].push_back(bjets_p4->at(0)->E  ());
  nentryML++;

  if(debug) printf("taus:\n");
  for (int i = 0; i < taus_p4->size(); ++i)
  {
    if(debug) printv(*taus_p4->at(i));
    //MLinput[nentryML].push_back(taus_p4->at(i)->Pt());
    MLinput[nentryML].push_back(taus_p4->at(i)->Eta());
    MLinput[nentryML].push_back(taus_p4->at(i)->Phi());
    MLinput[nentryML].push_back(taus_p4->at(i)->E());
    nentryML++;
  }
  if(modelname.Contains("lep")){
    if(debug) {
      printf("lepton:\n");
      printv(*leps_p4->at(0));
    }
    //MLinput[nentryML].push_back(leps_p4->at(0)->Pt());
    MLinput[nentryML].push_back(leps_p4->at(0)->Eta());
    MLinput[nentryML].push_back(leps_p4->at(0)->Phi());
    MLinput[nentryML].push_back(leps_p4->at(0)->E());
    nentryML++;
  }
  modelname += trainpart ? "even" : "odd";
  if(debug) printf("ML input: %s,%d, %lu,%d\n", modelname.Data(),nentryML,MLinput[0].size(),nlightj);
  vector<vector<float>> predicted = m_applyTF.predictEvent(modelname,MLinput,nentryML,(int)MLinput[0].size(),nlightj,2);
  float highest = 0;
  ljets_score.clear();

  double smallDr = 999;
  int cjettmp = -1;

  for (int j = 0; j < nlightj; ++j){
    ljets_score.push_back(predicted[j][0]);
    if(predicted[j][0]<0.1) continue;
    double Dr = ljets_p4->at(j)->DeltaR(taus_p4->size() == 2? *taus_p4->at(0) + *taus_p4->at(1) : *taus_p4->at(0) + *leps_p4->at(0));
    if(smallDr>Dr){
      smallDr = Dr;
      cjettmp = j;
    }
  }
  if(cjettmp<0)
    for (int i = 0; i < nlightj; ++i)
    {
      if(highest < predicted[i][0]) {
        highest = predicted[i][0];
        cjettmp = i;
      }
    }
  output.push_back(cjettmp);
  if (modelname.Contains("had")){
    if(nlightj <= 3){
      for (int i = 0; i < nlightj; ++i){
        if(i!=cjettmp) output.push_back(i);
      }
    }else{
      vector<int> wpair = findwpair(cjettmp);
      output.push_back(wpair[0]);
      output.push_back(wpair[1]);
    }
  }
  return output;
}

void nominal::calcfakesf(std::vector<int> origin, std::vector<float> pt, std::vector<int> prong){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  if(origin.size()!=pt.size() || pt.size()!=prong.size()) {
    printf("nominal::calcfakesf(): ERROR: origin, pt, prong vector size are not equal.\n");
    exit(0);
  }
  int ntau = origin.size();
  float fakeSF_origin = 1;
  float fakeSF_origin_NP[2][4] = {{1,1,1,1},{1,1,1,1}};
  float fakeSF_tthML = 1;
  float fakeSF_tthML_NP[2][3] = {{1,1,1},{1,1,1}};
  int ptbin;
  for (int i = 0; i < ntau; ++i)
  {
    if(origin[i]<0) continue;
    pt[i] = pt[i]/GeV;
    fakeSF_origin*=fakeSFs[ pt[i]>35 ][origin[i]];
    int prongbin = prong[i] == 3;
    if(prongbin == 0) {
      if(pt[i]<45) ptbin = 0;
      else if(pt[i] < 70) ptbin = 1;
      else ptbin = 2;
    }else{
      if(pt[i]<50) ptbin = 0;
      else if(pt[i] < 75) ptbin = 1;
      else ptbin = 2;
    }
    fakeSF_tthML *= fakeSFML[prongbin][ptbin];
    if(nominaltree) fakeSF_tthML_NP[prongbin][ptbin] *= fakeSFMLNP[prongbin][ptbin]/fakeSF_tthML + 1;
  }
  addweights(fakeSF_tthML*weights->at(0),"fakeSF_tthML");
  addweights(fakeSF_origin*weights->at(0),"fakeSF_origin");

  if(nominaltree) {
    for (int inpprongbin = 0; inpprongbin < 2; ++inpprongbin)
    {
      for (int inpptbin = 0; inpptbin < 3; ++inpptbin)
      {
        addweights(fakeSF_tthML_NP[inpprongbin][inpptbin],TString("fakeSFNP_tthML_ptbin" + to_string(inpptbin) + "_prongbin" + to_string(inpprongbin)));
      }
    }
    for (int iNP = 0; iNP < 8; ++iNP)
    {
      double valNP = 1;
      for (int itau = 0; itau < ntau; ++itau)
      {
        if(origin[itau] >= 0 ){
          if ( iNP < 4 && pt[itau]>35 == 0 )
             valNP *= fakeSFsNPbase[pt[itau]>35][origin[itau]][iNP]*sqrt(fakeSFsNPsSigma2[pt[itau]>35][iNP])/fakeSFs[pt[itau]>35][origin[itau]] + 1;
          else if (iNP >= 4 && pt[itau]>35 == 1) {
             valNP *= fakeSFsNPbase[pt[itau]>35][origin[itau]][iNP-4]*sqrt(fakeSFsNPsSigma2[pt[itau]>35][iNP-4])/fakeSFs[pt[itau]>35][origin[itau]] + 1;
          }
        }
      }
      addweights(valNP, TString("fakeSFNP_origin_" + to_string(iNP)));
    }
  }

}

observable nominal::FindNewFakeSF(TString NP, vector<int> origintag, vector<float> taupt, vector<int> isOS){ //origin=-1,0,1,2,3,4 for real/lep,b,c,g,j,wjet
  observable result = 1;
  for (int i = 0; i < origintag.size(); ++i)
  {
    result *= FindNewFakeSF(NP, origintag[i], taupt[i], isOS[i]);
  }
  return result;
}

observable nominal::FindNewFakeSF(TString NP, int origintag, float taupt, int isOS, TString &name){ //origin=-1,0,1,2,3,4 for real/lep,b,c,g,j,wjet
  if(!newFakeSF.size()) {
    printf("nominal::FindNewFakeSF() Error : newFakeSF is Empty, please call nominal::ConfigNewFakeSF() first\n");
    exit(0);
  }
  if(origintag < 0) return 1;
  bool iswjet = origintag == 4;
  int slice = 0;
  for (int islice = 1; islice < fakePtSlices.size(); ++islice)
  {
    if(taupt/GeV<fakePtSlices[islice]) {
      slice = islice-1;
      break;
    }
  }

  observable result = doubleCounting? newFakeSFSys[isOS][iswjet][slice] : newFakeSF[NP][isOS][iswjet][slice];
  string ss = "fakeSFNP_ptbin" + to_string(slice) + (iswjet?"_wjet":"");
  name = ss.c_str();
  if(!newFakeSF[NP].size()) printf("nominal::FindNewFakeSF : NP %s not found\n", NP.Data());
  if(debug) printf("%s = %f +/- %f\n", name.Data(), result.nominal, result.error);
  return result;
}

observable nominal::FindNewFakeSF(TString NP, int origintag, float taupt, int isOS){
  TString name;
  return FindNewFakeSF(NP, origintag, taupt, isOS, name);
}

bool nominal::AddTheorySys(){
  if(weight_mc_v){
    for (int i = 1; i <= theoryweightsum->GetNbinsX(); ++i)
    {
      TString weightName = theoryweightsum->GetXaxis()->GetBinLabel(i);
      if(weightName!=""){ //https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PmgTopProcesses, Top, Single Top, ttH
        if((weightName.Contains("muR=") && weightName.Contains(",muF=")) || weightName.Contains("PDFset=260") ){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),weightName);
        }else if(weightName.Contains("isr:muRfac=10_fsr:muRfac=20")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"FSR_up");
        }else if(weightName.Contains("isr:muRfac=10_fsr:muRfac=05")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"FSR_down");
        }else if(weightName.Contains("Var3cUp")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"ISR_up");
        }else if(weightName.Contains("Var3cDown")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"ISR_down");
        }
      }
    }
  }
  for(int i = 0; i < weights->size(); i++){
    if(weights->at(i)!=weights->at(i)) {
      printf("weight is nan, eventNumber: %llu, n_weight: %d\n", eventNumber, i);
      return 0;
    }
  }
  return 1;
}

void nominal::ConfigNewFakeSF(){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  printf("nominal::ConfigNewFakeSF() : Starting\n");
  TString prefix = PACKAGE_DIR;
  prefix += "/data/";
  newFakeSF.clear();
  newFakeSFSys.clear();
  string iswjetstring[2] = {"fake", "wjet-fake"};
  for (int isOS = 0; isOS < 2; ++isOS)
  {
    TString filename = prefix + (isOS?"scale_factors_os.root" : "scale_factors_ss.root");
    printf("nominal::ConfigNewFakeSF() : Reading file %s\n",filename.Data());
    TFile *sfFile =  TFile::Open(filename);
    printf("nominal::ConfigNewFakeSF() : Done reading\n");
    TH1D *SFhist = 0;
    for (int iswjet = 0; iswjet < 2 ; ++iswjet)
    {
      for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
      {
        string histname = ( "Fit_sf_" + iswjetstring[iswjet] + "_pt" + to_string(int(fakePtSlices[islice])) + to_string(int(fakePtSlices[islice+1])) );
        printf("nominal::ConfigNewFakeSF() : Read histogram %s\n", histname.c_str());
        //SFhist = (TH1D*)(sfFile.Get(histname.c_str())->Clone((histname+"_buffer").c_str()));
        sfFile->GetObject(histname.c_str(),SFhist);
        SFhist->SetDirectory(0);  //It crashes without this line!
        if(!SFhist) printf("histogram not found in SF file: %s\n", histname.c_str());
        TAxis *xaxis = SFhist->GetXaxis();
        double newFakeSFnominal;
        double err2 = 0;
        for (int ibin = 1; ibin <= SFhist->GetNbinsX(); ++ibin)
        {
          if(!strncmp(xaxis->GetBinLabel(ibin),"NOMINAL",100)){
            newFakeSFnominal = SFhist->GetBinContent(ibin);
            err2 += pow(SFhist->GetBinError(ibin),2);
            break;
          }
        }
        for (int ibin = 1; ibin <= SFhist->GetNbinsX(); ++ibin)
        {
          TString NPname = xaxis->GetBinLabel(ibin);
          double content = SFhist->GetBinContent(ibin);
          double err = SFhist->GetBinError(ibin);
          if(!content || NPname.Contains("Punch")) continue;
          if(NPname != "NOMINAL" && !NPname.Contains("fake") && !NPname.Contains("down")){
            err2 += pow(content - newFakeSFnominal, 2);
          }
          if((find(plotNPs.begin(),plotNPs.end(),NPname) == plotNPs.end()) && SystematicsName!=NPname && NPname!="NOMINAL") {
            continue;
          }
          if(!newFakeSF[NPname].size()) newFakeSF[NPname] = {{{0,0,0},{0,0,0}},{{0,0,0},{0,0,0}}};
          newFakeSF[NPname][isOS][iswjet][islice] = observable(content,err);
        }
        if(!newFakeSFSys.size()) newFakeSFSys = {{{0,0,0},{0,0,0}},{{0,0,0},{0,0,0}}};
        newFakeSFSys[isOS][iswjet][islice] = observable(newFakeSFnominal,sqrt(err2));
        deletepointer(SFhist);
      }
    }
  }
  LatexChart *chart[2] = {0,0};
  printf("saved SF for NP:");
  for(auto iter : newFakeSF){
    printf(" %s", iter.first.Data());
  }
  printf("\nnew SFs: \n");
  for (int isOS = 0; isOS < 2; ++isOS)
  {
    string chartname = isOS?"scale_factors_os" : "scale_factors_ss";
    if(access( chartname.c_str(), F_OK ) == -1) chart[isOS] = new LatexChart(chartname);
    printf("isOS: %d\n", isOS);
    printf("Slices: ");
    for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
    {
      printf(" %s ", ( to_string(int(fakePtSlices[islice])) + to_string(int(fakePtSlices[islice+1])) ).c_str());
    }
    printf("\n");
    for (int iswjet = 0; iswjet < 2; ++iswjet)
    {
      printf("%s", iswjetstring[iswjet].c_str());
      for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
      {
        printf(" %f+/-%f ", newFakeSFSys[isOS][iswjet][islice].nominal, newFakeSFSys[isOS][iswjet][islice].error);
        if(chart[isOS]){
          string rowname = iswjet? "$\\tau_{W}$" : "non-$\\tau_{W}$ fakes";
          string columnname = "$" + to_string(int(fakePtSlices[islice])) + "-" + to_string(int(fakePtSlices[islice+1])) + "$~GeV";
          if(islice == fakePtSlices.size()-2) columnname = to_string(int(fakePtSlices[islice])) + "GeV$-$";
          chart[isOS]->set(rowname, columnname, newFakeSFSys[isOS][iswjet][islice]);
        }
      }
      printf("\n");
    }
    if(chart[isOS]) {
      chart[isOS]->caption = "The results of the fit in di-lep and $2b" + string(isOS? "OS":"SS") + "$ regions.";
      chart[isOS]->print(chart[isOS]->label);
      deletepointer(chart[isOS]);
    }
  }
  applyNewFakeSF = 1;
  printf("nominal::ConfigNewFakeSF() : End\n");
}

void nominal::calcfakesf_pdg(std::vector<int> originpdg, std::vector<float> pt, std::vector<int> prong){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  std::vector<int> origin;
  for (int i = 0; i < originpdg.size(); ++i)
  {
    switch(originpdg[i]){
      case 11: case 13: case 15:
      origin.push_back(-1);
      break;
      case 5:
      origin.push_back(0);
      break;
      case 4:
      origin.push_back(1);
      break;
      case 21:
      origin.push_back(2);
      break;
      default:
      origin.push_back(3);
    }
  }
  calcfakesf(origin,pt,prong);
}

void nominal::addweights(double weight, TString name){
  if(weight == 0) printf("Warning: %s weight is 0\n", name.Data());
  weights->push_back(weight);
  if(ifill==0) weightlist.push_back(name);
}

void nominal::saveweightslist(TString filename){
  ofstream out(filename.Data());
  for(auto names: weightlist){
    out<<names<<endl;
  }
  out.close();
}

vector<int> nominal::findwpair(int cjet){
  if(!GeV) {
    printf("Error: nominal::GeV not initialised\n");
    exit(0);
  }
  float mindeltam = -1;
  float m_w = 81*GeV;
  vector<int> output;
  int wjet1,wjet2;
  for (int i = 0; i < (*ljets_p4).size(); ++i)
  {
    if (i == cjet) continue;
    for (int j = 0; j < (*ljets_p4).size(); ++j)
    {
      if(i <= j || j == cjet) continue;
      float deltam = abs((*ljets_p4->at(i) + *ljets_p4->at(j)).M() - m_w);
      if(mindeltam<0 || mindeltam > deltam ){
        mindeltam = deltam;
        wjet1 = i; wjet2 = j;
      }
    }
  }
  output.push_back(wjet1);
  output.push_back(wjet2);
  return output;
}

void nominal::fillhist(histSaver* plots, TString region, int nprong, TString sample, int iptbin, float taubtag, TString NP){
  for (int i = 0; i < 4; ++i){
    if(taubtag>btagwpCut[i]) {
      if(dobwp[bwps[i]] == 1) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[i],NP);
    }else{
      if(dovetobwp[bwps[i]] == 1) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[i],NP);
    }
  }
}

void nominal::readweightsysmap(int dsid, TString framework){
  if(weightsysmap.find(dsid) != weightsysmap.end()) return;
  TString prefix = PACKAGE_DIR;
  prefix = prefix + "/config/theoryweightlist/" + framework + "_" + TString(to_string(dsid)) + ".txt";
  ifstream f(prefix);
  if(f.good())
    weightsysmap[dsid] = readTovecString(prefix);
}

void nominal::printv(TLorentzVector v){
  printf("Pt : %f, Eta: %f, Phi: %f, E: %f, m: %f\n", v.Pt(),v.Eta(),v.Phi(),v.E(),v.M());
}

void nominal::fill_notau(TString region, TString sample, TString NP){
  if(debug) printf("fill region: %s sample: %s\n", (region).Data(), (sample).Data());
  fake_notau_plots->fill_hist(sample, region, NP);
}
void nominal::finalise_sample(){
  printf("finalising sample\n");
  if(dohist) {
    plot();
  }
  if (writetree) {
    outputtreefile->cd();
    map < TString, TTree*> ::iterator iter;
    for (iter = outputtree.begin(); iter != outputtree.end(); ++iter)
      iter->second->Write(iter->first, TObject::kWriteDelete);
    outputtreefile->Close();
    deletepointer(outputtreefile);
  }
}

TMinuit* nominal::initgM(){
  deletepointer(gM);
  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);
  return gM;
}
