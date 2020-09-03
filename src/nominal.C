#include "nominal.h"
#include "fcnc_include.h"
#include "common.h"
#include "LatexChart.h"
using namespace std;
int nominal::GeV = 0;

void nominal::initMVA(TString fcnc_region){

  doBDT = 1;

  reader[fcnc_region] = new TMVA::Reader( "!Color:!Silent" );

  reader[fcnc_region]->AddVariable("tau_pt_0",&tau_pt_0);
  //reader[fcnc_region]->AddVariable("tau_pt_1",&tau_pt_1);
  reader[fcnc_region]->AddVariable("drtautau",&drtautau);
  reader[fcnc_region]->AddVariable("etmiss",&etmiss);
  reader[fcnc_region]->AddVariable("ttvismass",&ttvismass);
  reader[fcnc_region]->AddVariable("drtaujmin",&drtaujmin);
  //reader[fcnc_region]->AddVariable("mttjmin",&mttjmin);
  if(!fcnc_region.Contains("2mtau")&& !fcnc_region.Contains("2ltau")) {
    reader[fcnc_region]->AddVariable("drlb",&drlb);
    if(fcnc_region.Contains("2lSS")) reader[fcnc_region]->AddVariable("lep_pt_0",&lep_pt_0);
  }
  if(fcnc_region.Contains("2j") || fcnc_region.Contains("3j")){
    reader[fcnc_region]->AddVariable("dphitauetmiss",&dphitauetmiss);
    reader[fcnc_region]->AddVariable("phicent",&phicent);
    reader[fcnc_region]->AddVariable("tautaumass",&tautaumass);
    reader[fcnc_region]->AddVariable("t2mass",&t2mass);
    reader[fcnc_region]->AddVariable("x1fit",&x1fit);
    reader[fcnc_region]->AddVariable("x2fit",&x2fit);
    reader[fcnc_region]->AddVariable("t1mass",&t1mass);
    if(fcnc_region.Contains("1l1tau")){
       reader[fcnc_region]->AddVariable("drtaub",&drtaub);
       reader[fcnc_region]->AddVariable("mjjmin",&mjjmin);
    }
    if(!fcnc_region.Contains("reg1l1tau1b2j")){
       reader[fcnc_region]->AddVariable("wmass",&wmass);
    }
    //if(fcnc_region.Contains("1l1tau1b2j")){
    //   reader[fcnc_region]->AddVariable("allpz",&allpz);
    //   reader[fcnc_region]->AddVariable("allmass",&allmass);
    //}
  }else if(fcnc_region.Contains("1l2tau1") || fcnc_region.Contains("2lSS")){
    reader[fcnc_region]->AddVariable("t1vismass",&t1vismass);
    reader[fcnc_region]->AddVariable("mtaujmin",&mtaujmin);
    reader[fcnc_region]->AddVariable("drltau",&drltau);
    reader[fcnc_region]->AddVariable("etamax",&etamax);
    reader[fcnc_region]->AddVariable("mtw",&mtw);
    reader[fcnc_region]->AddVariable("drlbditau",&drlbditau);
    reader[fcnc_region]->AddVariable("tautauvispt",&tautauvispt);
    reader[fcnc_region]->AddVariable("t2vismass",&t2vismass);
  }


  reader[fcnc_region]->BookMVA( "BDTG_1" , TString(PACKAGE_DIR) + "/config/weights/" + fcnc_region + "TMVAClassification_1_BDTG.weights.xml" );
  reader[fcnc_region]->BookMVA( "BDTG_2" , TString(PACKAGE_DIR) + "/config/weights/" + fcnc_region + "TMVAClassification_2_BDTG.weights.xml" );
}

void nominal::init(TTree *tree){
  if(reduce == 0) initRaw(tree);
  else {
    tree->SetBranchAddress("eventNumber", &eventNumber);
    tree->SetBranchAddress("runNumber", &runNumber);
    tree->SetBranchAddress("mcChannelNumber", &mcChannelNumber);
    if(reduce == 1) setVecBranch(tree);
    else if(reduce == 2) setBDTBranch(tree);
  }
}

void nominal::defineTree(TTree *tree){
  tree->Branch("eventNumber", &eventNumber);
  tree->Branch("runNumber", &runNumber);
  tree->Branch("mcChannelNumber", &mcChannelNumber);
  if(reduce == 1) vecBranch(tree);
  else if(reduce == 2) BDTBranch(tree);
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
  mll = 0;
  drltau   = 0;
  drttj   = 0;
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
  gMinside = 0;
  fake_plots = 0;
  fake_notau_plots = 0;
  
  cut_flow.setWeight(&weight);
  cut_flow.setEventNumber(&eventNumber);
  defaultbtagwp = btagwpCut[1];
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
  deletepointer(neutrinos_p4);
}

void nominal::initReduce1(){
  weights = new vector<double> ();
  ljet_indice = new std::vector<int>();
  taus_n_charged_tracks = new std::vector<UInt_t>();
  taus_b_tagged = new std::vector<Int_t>();
  taus_id = new std::vector<Int_t>();
  taus_q = new std::vector<Float_t>();
  taus_p4 = new std::vector<TLorentzVector*>();
  taus_matched_mother_pdgId = new std::vector<int>();
  taus_matched_pdgId = new std::vector<int>();
  neutrinos_p4 = new std::vector<TLorentzVector*>();
  met_p4 = new TLorentzVector();
  bjets_p4 = new std::vector<TLorentzVector*>();
  ljets_p4 = new std::vector<TLorentzVector*>();
  leps_p4 = new std::vector<TLorentzVector*>();
  leps_id = new std::vector<Int_t>();
  leps_iso = new std::vector<Int_t>();
  leps_tight = new std::vector<Int_t>();
  leps_matched_pdgId = new std::vector<int>();
  leps_truth_type = new std::vector<int>();
  bjets_score = new vector<float> ();
  ljets_bscore = new vector<float> ();
  leps_truth_origin = new vector<int>;
  leps_first_EgMother_pdgId = new vector<int>;
  leps_first_EgMother_truth_origin = new vector<int>;
  leps_first_EgMother_truth_type = new vector<int>;
}

void nominal::setBDTBranch(TTree *tree){
  tree->SetBranchAddress("fcncjetbscore", &fcncjetbscore);
  tree->SetBranchAddress("taus_q", &taus_q);
  tree->SetBranchAddress("taus_matched_pdgId", &taus_matched_pdgId);
  tree->SetBranchAddress("taus_matched_mother_pdgId", &taus_matched_mother_pdgId);
  tree->SetBranchAddress("weights", & weights);
  tree->SetBranchAddress("nljet",&nljet);
  tree->SetBranchAddress("chi2", &chi2);
  tree->SetBranchAddress("drlb", &drlb);
  tree->SetBranchAddress("drtaub", &drtaub);
  tree->SetBranchAddress("mjjmin", &mjjmin);
  tree->SetBranchAddress("x1fit", & x1fit);
  tree->SetBranchAddress("x2fit", & x2fit);
  tree->SetBranchAddress("t2vismass", & t2vismass);
  tree->SetBranchAddress("t1vismass", & t1vismass);
  tree->SetBranchAddress("t2mass", & t2mass);
  tree->SetBranchAddress("t1mass", & t1mass);
  tree->SetBranchAddress("ttvismass", & ttvismass);
  tree->SetBranchAddress("tautauvispt", & tautauvispt);
  tree->SetBranchAddress("drlbditau", & drlbditau);
  tree->SetBranchAddress("tau_pt_ss", & tau_pt_ss);
  tree->SetBranchAddress("tau_pt_os", & tau_pt_os);
  tree->SetBranchAddress("tau_pt_0", & tau_pt_0);
  tree->SetBranchAddress("tau_pt_1", & tau_pt_1);
  tree->SetBranchAddress("lep_pt_0", & lep_pt_0);
  tree->SetBranchAddress("lep_pt_1", & lep_pt_1);
  tree->SetBranchAddress("mtw", & mtw);
  tree->SetBranchAddress("etamax", & etamax);
  tree->SetBranchAddress("mll", & mll);
  tree->SetBranchAddress("drltau", & drltau);
  tree->SetBranchAddress("drttj", & drttj);
  tree->SetBranchAddress("drtautau", & drtautau);
  tree->SetBranchAddress("drttjmin", & drttjmin);
  tree->SetBranchAddress("mtaujmin", & mtaujmin);
  tree->SetBranchAddress("mttjmin", & mttjmin);
  tree->SetBranchAddress("drtaujmin", & drtaujmin);
  tree->SetBranchAddress("etmiss",&etmiss);
  tree->SetBranchAddress("dphitauetmiss",&dphitauetmiss);
  tree->SetBranchAddress("phicent",&phicent);
  tree->SetBranchAddress("tautaumass", &tautaumass);
  tree->SetBranchAddress("wmass", &wmass);
  tree->SetBranchAddress("taus_n_charged_tracks", &taus_n_charged_tracks);
  tree->SetBranchAddress("taus_b_tagged", &taus_b_tagged);
  tree->SetBranchAddress("leps_matched_pdgId", &leps_matched_pdgId);
  tree->SetBranchAddress("leps_truth_type", &leps_truth_type);
  tree->SetBranchAddress("leps_id", &leps_id);
  tree->SetBranchAddress("leps_truth_origin", &leps_truth_origin);
  tree->SetBranchAddress("leps_first_EgMother_pdgId", &leps_first_EgMother_pdgId);
  tree->SetBranchAddress("leps_first_EgMother_truth_origin", &leps_first_EgMother_truth_origin);
  tree->SetBranchAddress("leps_first_EgMother_truth_type", &leps_first_EgMother_truth_type);
  // hadhad specific
  tree->SetBranchAddress("ditau_coll_approx_m", &ditau_coll_approx_m);
  tree->SetBranchAddress("ditau_coll_approx_x0", &ditau_coll_approx_x0);
  tree->SetBranchAddress("ditau_coll_approx_x1", &ditau_coll_approx_x1);
  tree->SetBranchAddress("met_sumet", &met_sumet);
  tree->SetBranchAddress("tau0RNN",&tau0RNN);
  tree->SetBranchAddress("tau1RNN",&tau1RNN);
}

void nominal::BDTBranch(TTree *tree){
  tree->Branch("fcncjetbscore", &fcncjetbscore);
  tree->Branch("taus_b_tagged", &taus_b_tagged);
  tree->Branch("taus_q", &taus_q);
  tree->Branch("taus_n_charged_tracks", &taus_n_charged_tracks);
  tree->Branch("taus_matched_pdgId", &taus_matched_pdgId);
  tree->Branch("taus_matched_mother_pdgId", &taus_matched_mother_pdgId);
  tree->Branch("weights", & weights);
  tree->Branch("nljet",&nljet);
  tree->Branch("chi2", &chi2);
  tree->Branch("drlb", &drlb);
  tree->Branch("drtaub", &drtaub);
  tree->Branch("mjjmin", &mjjmin);
  tree->Branch("x1fit", & x1fit);
  tree->Branch("x2fit", & x2fit);
  tree->Branch("t2vismass", & t2vismass);
  tree->Branch("t1vismass", & t1vismass);
  tree->Branch("t2mass", & t2mass);
  tree->Branch("t1mass", & t1mass);
  tree->Branch("ttvismass", & ttvismass);
  tree->Branch("tautauvispt", & tautauvispt);
  tree->Branch("drlbditau", & drlbditau);
  tree->Branch("tau_pt_ss", & tau_pt_ss);
  tree->Branch("tau_pt_os", & tau_pt_os);
  tree->Branch("tau_pt_0", & tau_pt_0);
  tree->Branch("tau_pt_1", & tau_pt_1);
  tree->Branch("lep_pt_0", & lep_pt_0);
  tree->Branch("lep_pt_1", & lep_pt_1);
  tree->Branch("mtw", & mtw);
  tree->Branch("etamax", & etamax);
  tree->Branch("mll", & mll);
  tree->Branch("drltau", & drltau);
  tree->Branch("drttj", & drttj);
  tree->Branch("drtautau", & drtautau);
  tree->Branch("drttjmin", & drttjmin);
  tree->Branch("mtaujmin", & mtaujmin);
  tree->Branch("mttjmin", & mttjmin);
  tree->Branch("drtaujmin", & drtaujmin);
  tree->Branch("etmiss",&etmiss);
  tree->Branch("dphitauetmiss",&dphitauetmiss);
  tree->Branch("phicent",&phicent);
  tree->Branch("tautaumass", &tautaumass);
  tree->Branch("wmass", &wmass);
  tree->Branch("leps_matched_pdgId", &leps_matched_pdgId);
  tree->Branch("leps_truth_type", &leps_truth_type);
  tree->Branch("leps_id", &leps_id);
  tree->Branch("leps_truth_origin", &leps_truth_origin);
  tree->Branch("leps_first_EgMother_pdgId", &leps_first_EgMother_pdgId);
  tree->Branch("leps_first_EgMother_truth_origin", &leps_first_EgMother_truth_origin);
  tree->Branch("leps_first_EgMother_truth_type", &leps_first_EgMother_truth_type);
  // hadhad specific
  tree->Branch("ditau_coll_approx_m",  &ditau_coll_approx_m);
  tree->Branch("ditau_coll_approx_x0", &ditau_coll_approx_x0);
  tree->Branch("ditau_coll_approx_x1", &ditau_coll_approx_x1);
  tree->Branch("met_sumet", &met_sumet);
  tree->Branch("tau0RNN",&tau0RNN);
  tree->Branch("tau1RNN",&tau1RNN);
}


void nominal::setVecBranch(TTree *tree){
  tree->SetBranchAddress("bjets_score", &bjets_score);
  tree->SetBranchAddress("ljets_bscore", &ljets_bscore);
  tree->SetBranchAddress("weights", &weights);
  tree->SetBranchAddress("ljet_indice", &ljet_indice);
  tree->SetBranchAddress("taus_n_charged_tracks", &taus_n_charged_tracks);
  tree->SetBranchAddress("taus_b_tagged", &taus_b_tagged);
  tree->SetBranchAddress("taus_id", &taus_id);
  tree->SetBranchAddress("taus_q", &taus_q);
  tree->SetBranchAddress("taus_p4", &taus_p4);
  tree->SetBranchAddress("taus_matched_mother_pdgId", &taus_matched_mother_pdgId);
  tree->SetBranchAddress("taus_matched_pdgId", &taus_matched_pdgId);
  tree->SetBranchAddress("neutrinos_p4", &neutrinos_p4);
  tree->SetBranchAddress("met_p4", &met_p4);
  tree->SetBranchAddress("bjets_p4", &bjets_p4);
  tree->SetBranchAddress("ljets_p4", &ljets_p4);
  tree->SetBranchAddress("leps_p4", &leps_p4);
  tree->SetBranchAddress("leps_id", &leps_id);
  tree->SetBranchAddress("leps_iso", &leps_iso);
  tree->SetBranchAddress("leps_tight", &leps_tight);
  tree->SetBranchAddress("leps_matched_pdgId", &leps_matched_pdgId);
  tree->SetBranchAddress("leps_truth_type", &leps_truth_type);
  tree->SetBranchAddress("leps_truth_origin", &leps_truth_origin);
  tree->SetBranchAddress("leps_first_EgMother_pdgId", &leps_first_EgMother_pdgId);
  tree->SetBranchAddress("leps_first_EgMother_truth_origin", &leps_first_EgMother_truth_origin);
  tree->SetBranchAddress("leps_first_EgMother_truth_type", &leps_first_EgMother_truth_type);
  // hadhad specific
  tree->SetBranchAddress("ditau_coll_approx_m", &ditau_coll_approx_m);
  tree->SetBranchAddress("ditau_coll_approx_x0", &ditau_coll_approx_x0);
  tree->SetBranchAddress("ditau_coll_approx_x1", &ditau_coll_approx_x1);
  tree->SetBranchAddress("met_sumet", &met_sumet);
  tree->SetBranchAddress("tau0RNN",&tau0RNN);
  tree->SetBranchAddress("tau1RNN",&tau1RNN);
}

void nominal::vecBranch(TTree *tree){
  tree->Branch("bjets_score", &bjets_score);
  tree->Branch("ljets_bscore", &ljets_bscore);
  tree->Branch("weights", &weights);
  tree->Branch("ljet_indice", &ljet_indice);
  tree->Branch("taus_n_charged_tracks", &taus_n_charged_tracks);
  tree->Branch("taus_b_tagged", &taus_b_tagged);
  tree->Branch("taus_id", &taus_id);
  tree->Branch("taus_q", &taus_q);
  tree->Branch("taus_p4", &taus_p4);
  tree->Branch("taus_matched_mother_pdgId", &taus_matched_mother_pdgId);
  tree->Branch("taus_matched_pdgId", &taus_matched_pdgId);
  tree->Branch("neutrinos_p4", &neutrinos_p4);
  tree->Branch("met_p4", &met_p4);
  tree->Branch("bjets_p4", &bjets_p4);
  tree->Branch("ljets_p4", &ljets_p4);
  tree->Branch("leps_p4", &leps_p4);
  tree->Branch("leps_id", &leps_id);
  tree->Branch("leps_iso", &leps_iso);
  tree->Branch("leps_tight", &leps_tight);
  tree->Branch("leps_matched_pdgId", &leps_matched_pdgId);
  tree->Branch("leps_truth_type", &leps_truth_type);
  tree->Branch("leps_truth_origin", &leps_truth_origin);
  tree->Branch("leps_first_EgMother_pdgId", &leps_first_EgMother_pdgId);
  tree->Branch("leps_first_EgMother_truth_origin", &leps_first_EgMother_truth_origin);
  tree->Branch("leps_first_EgMother_truth_type", &leps_first_EgMother_truth_type);
  // hadhad specific
  tree->Branch("ditau_coll_approx_m",  &ditau_coll_approx_m);
  tree->Branch("ditau_coll_approx_x0", &ditau_coll_approx_x0);
  tree->Branch("ditau_coll_approx_x1", &ditau_coll_approx_x1);
  tree->Branch("met_sumet", &met_sumet);
  tree->Branch("tau0RNN",&tau0RNN);
  tree->Branch("tau1RNN",&tau1RNN);
}

void nominal::initFit(){
  if(!gMinside) gMinside = initgM();
  fitvec["taus"] = taus_p4;
  fitvec["leps"] = leps_p4;
  fitvec["bjets"] = bjets_p4;
  fitvec["ljets"] = ljets_p4;
  if(fitvec.find("met") == fitvec.end()){
  	fitvec["met"] = new vector<TLorentzVector*>();
  	fitvec["met"]->push_back(met_p4);
  }
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
    neutrino[1].SetPtEtaPhiM(par[3],par[4],par[5],channel == "lephad" ? par[6] : 0);
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
  //  std::cout<<"prob1: "<<prob1<<"prob2: "<<prob2<<std::endl;
    if(prob1>0 && prob2>0) {
      Float_t met_resol = (13.1+0.50*sqrt(met->at(0)->Pz()/GeV))*GeV;
      f = -2*log(prob1) -2*log(prob2) + pow((mass1-1.777*GeV)/1.777/GeV,2) + pow((mass2-1.777*GeV)/1.777/GeV,2) + pow((mass-125*GeV)/20/GeV,2) + pow((pxMiss-met->at(0)->Px())/met_resol,2) + pow((pyMiss-met->at(0)->Py())/met_resol,2);
    }
  }
}

void nominal::fcn_collinear(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {
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
    Float_t mass;
    neutrino[0].SetPtEtaPhiM(par[0]*taus->at(0)->Pt(),taus->at(0)->Eta(),taus->at(0)->Phi(),0);
    if(channel == "lephad") {
      neutrino[1].SetPtEtaPhiM(par[1]*leps->at(0)->Pt(),leps->at(0)->Eta(),leps->at(0)->Phi(),par[2]);
      mass = (*taus->at(0)+neutrino[0]+*leps->at(0)+neutrino[1]).M();
    }
    else if(channel == "hadhad") {
      neutrino[1].SetPtEtaPhiM(par[1]*taus->at(1)->Pt(),taus->at(1)->Eta(),taus->at(1)->Phi(),0);
      mass = (*taus->at(0)+neutrino[0]+*taus->at(1)+neutrino[1]).M();
    }
    Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
    Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
    
    Float_t met_resol = (13.1+0.50*sqrt(met->at(0)->Pz()/GeV))*GeV;
    f = pow((mass-125*GeV)/20/GeV,2) + pow((pxMiss-met->at(0)->Px())/met_resol,2) + pow((pyMiss-met->at(0)->Py())/met_resol,2);
  }
}

vector<int>* nominal::findcjet(){
  double m_w = 81*GeV;
  vector<int> *output = new vector<int>();
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
  output->push_back(fcjet);
  if (channel == "hadronicW"){
    if(nlightj <= 3){
      for (int i = 0; i < nlightj; ++i){
        if(i!=fcjet) output->push_back(i);
      }
    }else{
      vector<int> wpair = findwpair(fcjet);
      output->push_back(wpair[0]);
      output->push_back(wpair[1]);
      wmass = (*ljets_p4->at(output->at(1)) + *ljets_p4->at(output->at(2))).M();
    }
    TLorentzVector top = *bjets_p4->at(0);
    for (int i = 1; i < output->size(); ++i)
    {
      top = top + *ljets_p4->at(output->at(i));
    }
    t1vismass = top.M();
    t1mass = t1vismass;
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

void nominal::calcfakesf(std::vector<int> origin){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  int ntau = taus_p4->size();
  float fakeSF_origin = 1;
  float fakeSF_origin_NP[2][4] = {{1,1,1,1},{1,1,1,1}};
  float fakeSF_tthML = 1;
  float fakeSF_tthML_NP[2][3] = {{1,1,1},{1,1,1}};
  int ptbin;
  for (int i = 0; i < ntau; ++i)
  {
    if(origin[i]<0) continue;
    fakeSF_origin*=fakeSFs[ taus_p4->at(i)->Pt()>35*GeV ][origin[i]];
    int prongbin = taus_n_charged_tracks->at(i) == 3;
    if(prongbin == 0) {
      if(taus_p4->at(i)->Pt()<45*GeV) ptbin = 0;
      else if(taus_p4->at(i)->Pt() < 70*GeV) ptbin = 1;
      else ptbin = 2;
    }else{
      if(taus_p4->at(i)->Pt()<50*GeV) ptbin = 0;
      else if(taus_p4->at(i)->Pt() < 75*GeV) ptbin = 1;
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
          if ( iNP < 4 && taus_p4->at(itau)->Pt()>35*GeV == 0 )
             valNP *= fakeSFsNPbase[taus_p4->at(itau)->Pt()>35*GeV][origin[itau]][iNP]*sqrt(fakeSFsNPsSigma2[taus_p4->at(itau)->Pt()>35*GeV][iNP])/fakeSFs[taus_p4->at(itau)->Pt()>35*GeV][origin[itau]] + 1;
          else if (iNP >= 4 && taus_p4->at(itau)->Pt()>35*GeV == 1) {
             valNP *= fakeSFsNPbase[taus_p4->at(itau)->Pt()>35*GeV][origin[itau]][iNP-4]*sqrt(fakeSFsNPsSigma2[taus_p4->at(itau)->Pt()>35*GeV][iNP-4])/fakeSFs[taus_p4->at(itau)->Pt()>35*GeV][origin[itau]] + 1;
          }
        }
      }
      addweights(valNP, TString("fakeSFNP_origin_" + to_string(iNP)));
    }
  }

}

observable nominal::FindNewFakeSF(TString NP){ //origin=-1,0,1,2,3,4 for real/lep,b,c,g,j,wjet
  observable result = 1;
  if(belong_regions.have("tau")) result *= FindNewFakeSF(NP, 0);
  if(belong_regions.have("2tau") || belong_regions.have("2mtau")) result *= FindNewFakeSF(NP, 1);
  return result;
}

observable nominal::FindNewFakeSF(TString NP, int itau, TString &name){ //origin=-1,0,1,2,3,4 for real/lep,b,c,g,j,wjet
  double taupt = itau == 0? tau_pt_0 : tau_pt_1;
  if(!newFakeSF.size()) {
    printf("nominal::FindNewFakeSF() Error : newFakeSF is Empty, please call nominal::ConfigNewFakeSF() first\n");
    exit(0);
  }
  TString origin;
  if(abs(taus_matched_pdgId->at(itau)) == 5) origin = "bjet-fake";
  else if(abs(taus_matched_pdgId->at(itau)) < 6) {
    if(abs(taus_matched_mother_pdgId->at(itau)) == 24) origin = "wjet-fake";
    else origin = "other-fake";
  }else{
    return 1;
  }

  int slice = 0;
  for (int islice = 1; islice < fakePtSlices.size(); ++islice)
  {
    if(taupt/GeV<fakePtSlices[islice]) {
      slice = islice-1;
      break;
    }
  }

  observable result = doubleCounting? newFakeSFSys[origin][slice] : newFakeSF[NP][origin][slice];
  string ss = "fakeSFNP_ptbin" + to_string(slice) + "_" + origin.Data();
  name = ss.c_str();
  if(!newFakeSF[NP].size()) printf("nominal::FindNewFakeSF : NP %s not found\n", NP.Data());
  if(debug) printf("%s = %f +/- %f\n", name.Data(), result.nominal, result.error);
  return result;
}

observable nominal::FindNewFakeSF(TString NP, int itau){
  TString name;
  return FindNewFakeSF(NP, itau, name);
}

bool nominal::addTheorySys(){
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
  newFakeSF.clear();
  newFakeSFSys.clear();
  TFile *sfFile =  TFile::Open(SFfilename);
  printf("nominal::ConfigNewFakeSF() : Done reading\n");
  TH1D *SFhist = 0;
  for (auto origin : SForigins)
  {
    for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
    {
      string histname = ( "sf_" + string(origin.Data()) + "_pt" + to_string(int(fakePtSlices[islice])) + to_string(int(fakePtSlices[islice+1])) );
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
        if(!newFakeSF[NPname].size()) {
          for (int i = 0; i < fakePtSlices.size()-1; ++i)
          {
            for (auto theorigin:SForigins)
            {
              newFakeSF[NPname][theorigin].emplace_back(0);
            }
          }
        }
        newFakeSF[NPname][origin][islice] = observable(content,err);
      }
      if(!newFakeSFSys.size()) {
        for (int i = 0; i < fakePtSlices.size()-1; ++i)
        {
          for (auto theorigin:SForigins)
          {
            newFakeSFSys[theorigin].emplace_back(0);
          }
        }
      }
      newFakeSFSys[origin][islice] = observable(newFakeSFnominal,sqrt(err2));
      deletepointer(SFhist);
    }
  }
  
  LatexChart *chart = 0;
  printf("saved SF for NP:");
  for(auto iter : newFakeSF){
    printf(" %s", iter.first.Data());
  }
  printf("\nnew SFs: \n");
  string chartname = "scale_factors";
  if(access( chartname.c_str(), F_OK ) == -1) chart = new LatexChart(chartname);
  printf("Slices: ");
  for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
  {
    printf(" %s ", ( to_string(int(fakePtSlices[islice])) + to_string(int(fakePtSlices[islice+1])) ).c_str());
  }
  printf("\n");
  for (auto origin : SForigins)
  {
    printf("%s", origin.Data());
    for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
    {
      printf(" %f+/-%f ", newFakeSFSys[origin][islice].nominal, newFakeSFSys[origin][islice].error);
      if(chart){
        string rowname = origin == "wjet-fake"? "$\\tau_{W}$" : (origin == "bjet-fake"? "$\\tau_{b}$" : "$\\tau_{other}$");
        string columnname = "$" + to_string(int(fakePtSlices[islice])) + "-" + to_string(int(fakePtSlices[islice+1])) + "$~GeV";
        if(islice == fakePtSlices.size()-2) columnname = to_string(int(fakePtSlices[islice])) + "GeV$-$";
        chart->set(rowname, columnname, newFakeSFSys[origin][islice]);
      }
    }
    printf("\n");
  }
  if(chart) {
    chart->caption = "The results of the fit in CR regions.";
    chart->print(chart->label);
    deletepointer(chart);
  }
  applyNewFakeSF = 1;
  printf("nominal::ConfigNewFakeSF() : End\n");
}

void nominal::calcfakesf_pdg(){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  std::vector<int> origin;
  for (int i = 0; i < taus_matched_pdgId->size(); ++i)
  {
    switch(abs(taus_matched_pdgId->at(i))){
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
  calcfakesf(origin);
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

void nominal::fillhist(histSaver* plots, TString region, int nprong, TString sample, int taubtag, TString NP){
  //for (int i = 0; i < 4; ++i){
  //  if(taubtag>btagwpCut[i]) {
  //    if(dobwp[bwps[i]] == 1) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + bwps[i],NP);
  //  }else{
  //    if(dovetobwp[bwps[i]] == 1) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_veto" + bwps[i],NP);
  //  }
  //}
  if(dobwp[bwps[1]] == 1 && taubtag) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + bwps[1],NP);
  if(dovetobwp[bwps[1]] == 1 && !taubtag) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_veto" + bwps[1],NP);
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
    for (iter = outputtree.begin(); iter != outputtree.end(); ++iter){
      if(iter->second->GetEntries() != 0)
        iter->second->Write(iter->first, TObject::kWriteDelete);
      else
        printf("Output tree %s is empty\n", iter->first.Data());
    }
    outputtreefile->Close();
    deletepointer(outputtreefile);
  }
}

TMinuit* nominal::initgM(){
  deletepointer(gM);
  gM = new TMinuit(5);
  if(fit_collinear)  gM->SetFCN(fcn_collinear);
  else gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);
  return gM;
}

void nominal::Loop(TTree* inputtree, TString _samplename, float globalweight = 1)
{
  if(!inputtree) {
    printf("WARNING: input tree is empty\n");
    return;
  }
  samplename = _samplename;
  if(isData) {
    campaign = samplename.Contains("1516") ? 1: (samplename.Contains("17")? 2:3);
  }else{
    campaign = samplename.Contains("mc16a") ? 1: (samplename.Contains("mc16d")? 2:3);
  }
  belong_regions.clear();

  if(reduce > 1) {
    belong_regions.add(inputtree->GetName());
    fcnc = belong_regions.isCategory("SR") || belong_regions.isCategory("SRCR");
    printf("is FCNC SR or SRCR? %d\n", fcnc);
  }

  nonfcncmatched = 0;
  fcncmatched = 0;
  leptonicw = 0;

  bool cutmass = 0;

  reduce -= 1;
  init(inputtree);
  reduce += 1;
  if(reduce == 2) initFit();
  if(debug) printf("reduce scheme: %d\n", reduce);
  Long64_t nentries = inputtree->GetEntriesFast();
  cut_flow.sample = samplename;
  cut_flow.region = reduce==1? "all" : (inputtree->GetName());

  if (dumptruth) {
    for (int i = 0; i < 3; ++i) {
      filetruth[i][0].open(CharAppend("hadhad", i + 2) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
      filetruth[i][1].open(CharAppend("hadhad", i + 2) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
    }
  }
  int nloop = debug ? min((Long64_t)1000,nentries) : nentries;

  fstream signalevtnb;
  if(samplename.Contains("fcnc")) signalevtnb.open((samplename+"_evt.txt").Data(), fstream:: in | fstream::out | fstream::app);
  printf("nentries: %d\n", nloop);
  if(nentries == 0) return;
  float droppedweight = 0;
  fstream evtfile;
  if(dumpeventnumber) evtfile.open((samplename+"_evt.txt").Data(), fstream:: in | fstream::out | fstream::app);

  TString sample = samplename.Contains("data")? "data":samplename.Remove(0,6).Data();
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
      printf("please dumptruth after reduce1\n"); //not supported yet
      exit(0);
    }
  }


  int printperentry = reduce == 1? 100000 : 5000;
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    cut_flow.newEvent();
    inputtree->GetEntry(jentry);
    //if(mcChannelNumber == 411172 || mcChannelNumber == 411173 || mcChannelNumber == 411176 || mcChannelNumber == 411177)
    //  continue;
    prepare();
    if ((jentry % printperentry == 0) || debug)
      std::cout << " I am here event " << jentry << " Event " << eventNumber << " Run " << runNumber << " ismc " << mcChannelNumber << " Filled events "<< ifill<<std::endl;
//===============================SFs and weights===============================
    if(reduce == 1){
      belong_regions.clear();
      calcGeneralWeight();
      if(globalweight!=0) generalweight*=globalweight;
      if(generalweight == 0) continue;
      weight = generalweight;
      cut_flow.fill("n-tuple");
      //if(fabs(generalweight) > 5) {
      //  droppedweight+=generalweight;
      //  continue;
      //}
      // cut_flow.fill("weight<5");
      
      if(!passBasicCut()) continue;

      defineObjects();
  
      defineRegions();
      if(belong_regions.isEmpty()) continue;
  
      cut_flow.fill("SR+CR");
      
      defineTauTruth();

      defineLepTruth();
  
      tau_pt_0 = taus_p4->at(0)->Pt();
      if(taus_p4->size()>=2) tau_pt_1 = taus_p4->at(1)->Pt();
      if(leps_p4->size()) {
        tau_pt_0 = taus_p4->at(0)->Pt();
        if(leps_p4->size()>=2) lep_pt_1 = leps_p4->at(1)->Pt();
      }
        
    }else{
      weight = weights->at(0);
      if(debug)std::cout<<"weight_size: "<<weights->size()<<"  weight[0]: "<<weights->at(0)<<std::endl;
    }
      //===============================pre-selections===============================
    if(reduce == 2) {
      cut_flow.fill("this region");
      if(!passRegionCut()) continue;
      if (taus_p4->size() && taus_b_tagged->at(0) == 1) continue;
      if (taus_p4->size()>1)
        if(taus_b_tagged->at(1) == 1)
          continue;
      cut_flow.fill("tau b-veto");  
  
      if(!nominaltree && taus_p4->size()) {
        taus_matched_mother_pdgId = taumatchmap[eventNumber];
      }
      if(fcnc){
        if(bjets_p4->size() >= 2){
           if(!bjets_score || !bjets_score->size() || bjets_score->at(0) > bjets_score->at(1)){
             ljets_p4->push_back(bjets_p4->at(1));
             ljets_bscore->push_back(bjets_score->at(1));
             bjets_p4->erase(bjets_p4->begin()+1);
             bjets_score->erase(bjets_score->begin()+1);
           }else{
             ljets_p4->push_back(bjets_p4->at(0));
             ljets_bscore->push_back(bjets_score->at(0));
             bjets_p4->erase(bjets_p4->begin());
             bjets_score->erase(bjets_score->begin());
           }
        }
  
        ljet_indice = findcjet();
        if(debug)std::cout<<"ljet_indice->size: "<<ljet_indice->size()<<std::endl;
        if(debug)std::cout<<"ljets_bscore: "<<ljets_bscore->size()<<std::endl;
        if(debug)std::cout<<"ljet_indice->at(0): "<<ljet_indice->at(0)<<std::endl;
        if(ljet_indice->size()) fcncjetbscore = ljets_bscore->at(ljet_indice->at(0));
        else fcncjetbscore = 0;
        TLorentzVector *tau2 = 0;
        TLorentzVector *wlep = 0;
        if(taus_p4->size() == 2) {
          tau2 = taus_p4->at(1);
          if(leps_p4->size()!=0) wlep = leps_p4->at(0);
        }
        else {
          tau2 = leps_p4->at(0);
          if(leps_p4->size() == 2){
            if((belong_regions.have("2lSS1tau") && tau2->DeltaR(*taus_p4->at(0)) > leps_p4->at(1)->DeltaR(*taus_p4->at(0)))
              || (!belong_regions.have("2l1tau") && leps_id->at(0)*taus_q->at(0) < 0) ){
              tau2 = leps_p4->at(1);
              wlep = leps_p4->at(0);
            }else{
              wlep = leps_p4->at(1);
            }
            
          }else{
            wlep = 0;
          }
        }
        if(wlep) t1vismass = (*wlep + *bjets_p4->at(0)).M();
        ttvismass = (*taus_p4->at(0) + *tau2).M();
        drtautau = taus_p4->at(0)->DeltaR(*tau2);
        if(belong_regions.have("2mtau")){
          if(ttvismass < 50*GeV) continue;
          cut_flow.fill("$m_{\\tau\\tau,vis}>50$");
          if(ttvismass > 130*GeV) continue;
          cut_flow.fill("$m_{\\tau\\tau,vis}<130$");
          if(drtautau > 3.4) continue;
          cut_flow.fill("$\\Delta R(\\tau,\\tau)<3.4$");
          if (belong_regions.have("1l2tau"))
          {
            if(t1vismass > 190*GeV )
              continue;
            cut_flow.fill("$m_{l,b}<190$");
          }
        }
        if(dofit && (taus_p4->size() + leps_p4->size() == 2 || dofit1l2tau)){
          if (taus_p4->size() + leps_p4->size() >= 3) {
            gMinside->mnparm(0, "rpt1", 0.4, 0.01, 0., 2., ierflg);
            gMinside->mnparm(1, "rpt2", 0.4, 0.01, 0., 2., ierflg);
            gMinside->mnparm(2, "pt3", 10*GeV, 10*GeV, 0., 1000*GeV, ierflg);
            gMinside->mnparm(3, "eta3", 0, 0.1, -5, 5, ierflg);
            gMinside->mnparm(4, "phi3", 0, 0.1, -PI, PI, ierflg);
            arglist[0] = 5;
          } else if (fit_collinear){
          	gMinside->mnparm(0, "rpt1", 0.4, 0.01, 0., 2., ierflg);
            gMinside->mnparm(1, "rpt2", 0.4, 0.01, 0., 2., ierflg);
            arglist[0] = 2;
            if(leps_p4->size()) {
              gMinside->mnparm(2, "v2m", 0.5*GeV, 1e-5*GeV, 0, 1.776*GeV, ierflg);
              arglist[0]++;
            }
          } else {
            gMinside->mnparm(0, "v1pt",  taus_p4->at(0)->Pt(), 1*GeV, 0., 1000*GeV, ierflg);
            gMinside->mnparm(1, "v1eta", taus_p4->at(0)->Eta(), 0.01, taus_p4->at(0)->Eta()-0.25, taus_p4->at(0)->Eta()+0.25, ierflg);
            gMinside->mnparm(2, "v1phi", taus_p4->at(0)->Phi(), 0.01, taus_p4->at(0)->Phi()-0.25, taus_p4->at(0)->Phi()+0.25, ierflg);
            gMinside->mnparm(3, "v2pt",  tau2->Pt(), 1*GeV, 0., 1000*GeV, ierflg);
            gMinside->mnparm(4, "v2eta", tau2->Eta(), 0.01, tau2->Eta()-0.25, tau2->Eta()+0.25, ierflg);
            gMinside->mnparm(5, "v2phi", tau2->Phi(), 0.01, tau2->Phi()-0.25, tau2->Phi()+0.25, ierflg);
            arglist[0] = 6;
            if(leps_p4->size()) {
              gMinside->mnparm(6, "v2m", 0.5*GeV, 1e-5*GeV, 0, 1.776*GeV, ierflg);
              arglist[0]++;
            }
          }

          gMinside->SetObjectFit((TObject*)&fitvec);
          arglist[1] = 60.;
          Double_t val[7] = {0,0,0,0,0,0,0};
          Double_t err[7] = {0,0,0,0,0,0,0};

          if(debug) printf("start kinematic fit\n");
          gMinside->mnexcm("SCAN", arglist, 2, ierflg);
          for (int i = 0; i < 7; ++i) gMinside->GetParameter(i, val[i], err[i]);

          if (taus_p4->size() + leps_p4->size() >= 3) {
            gMinside->mnparm(0, "rpt1", val[0], 0.01, 0., 2., ierflg);
            gMinside->mnparm(1, "rpt2", val[1], 0.01, 0., 2., ierflg);
            gMinside->mnparm(2, "pt3",  val[2], 10*GeV, 0., 1000*GeV, ierflg);
            gMinside->mnparm(3, "eta3", val[3], 0.1, -5, 5, ierflg);
            gMinside->mnparm(4, "phi3", val[4], 0.1, -PI, PI, ierflg);
          } else if (fit_collinear){
            gMinside->mnparm(0, "rpt1", val[0], 0.01, 0., 2., ierflg);
            gMinside->mnparm(1, "rpt2", val[1], 0.01, 0., 2., ierflg);
            if(leps_p4->size()) gMinside->mnparm(2, "v2m",   val[2], 0.01, 0, 1776, ierflg);
          } else {
            gMinside->mnparm(0, "v1pt",  val[0], 1, 0., 1000*GeV, ierflg);
            gMinside->mnparm(1, "v1eta", val[1], 0.01, taus_p4->at(0)->Eta()-0.25, taus_p4->at(0)->Eta()+0.25, ierflg);
            gMinside->mnparm(2, "v1phi", val[2], 0.01, taus_p4->at(0)->Phi()-0.25, taus_p4->at(0)->Phi()+0.25, ierflg);
            gMinside->mnparm(3, "v2pt",  val[3], 1, 0., 1000*GeV, ierflg);
            gMinside->mnparm(4, "v2eta", val[4], 0.01, tau2->Eta()-0.25, tau2->Eta()+0.25, ierflg);
            gMinside->mnparm(5, "v2phi", val[5], 0.01, tau2->Phi()-0.25, tau2->Phi()+0.25, ierflg);
            if(leps_p4->size()) gMinside->mnparm(6, "v2m",   val[6], 0.01, 0, 1776, ierflg);
          }

          arglist[0] = 1000;
          arglist[1] = 0;
          gMinside->mnexcm("MIGRADE", arglist, 2, ierflg);

          Double_t fmin,edm,errdef;
          Int_t nvpar,nparx,icstat;
          //gMinuit->mnstat(fmin,edm,errdef,nvpar,nparx,icstat);
          gMinside->mnstat(fmin,edm,errdef,nvpar,nparx,icstat);

          chi2 = fmin;

          for (int i = 0; i < (taus_p4->size() + leps_p4->size() >= 3 ? 5 : (leps_p4->size()?7:6)); ++i) gMinside->GetParameter(i, val[i], err[i]);
          neutrinos_p4->clear();
  
          TLorentzVector *tauv1_v = new TLorentzVector();
          TLorentzVector *tauv2_v = new TLorentzVector();
          TLorentzVector *wv_v = new TLorentzVector();
          if(taus_p4->size() + leps_p4->size() >= 3) {
            tauv1_v->SetPtEtaPhiM(val[0]*taus_p4->at(0)->Pt(), taus_p4->at(0)->Eta(), taus_p4->at(0)->Phi(),0);
            tauv2_v->SetPtEtaPhiM(val[1]*tau2->Pt(), tau2->Eta(), tau2->Phi(), 0);
            x1fit = 1 / (1 + val[0]);
            x2fit = 1 / (1 + val[1]);
            wv_v->SetPtEtaPhiM(val[2], val[3], val[4], 0);
            t1mass = (*wlep + *wv_v + *bjets_p4->at(0)).M();
            wmass = (*wlep + *wv_v).M();
          } else if (fit_collinear){
            x1fit = 1 / (1 + val[0]);
            x2fit = 1 / (1 + val[1]);
            tauv1_v->SetPtEtaPhiM(val[0]*taus_p4->at(0)->Pt(), taus_p4->at(0)->Eta(), taus_p4->at(0)->Phi(), 0);
            tauv2_v->SetPtEtaPhiM(val[1]*tau2->Pt(), tau2->Eta(), tau2->Phi(), leps_p4->size()? val[2]:0);
          }
          else {
            tauv1_v->SetPtEtaPhiM(val[0],val[1],val[2],0);
            tauv2_v->SetPtEtaPhiM(val[3],val[4],val[5],val[6]);
            x1fit = taus_p4->at(0)->E() / (*taus_p4->at(0) + *tauv1_v).E();
            x2fit = tau2->E() / (*tau2 + *tauv2_v).E();
          }
          neutrinos_p4->push_back(tauv1_v);
          neutrinos_p4->push_back(tauv2_v);
          if(taus_p4->size() + leps_p4->size() >= 3) neutrinos_p4->push_back(wv_v);
          else deletepointer(wv_v);
  
          if(taus_p4->size() + leps_p4->size() == 2){
            if(ljets_p4->size()>=3){
              t1mass = (*(ljets_p4->at(ljet_indice->at(1))) + *(ljets_p4->at(ljet_indice->at(2))) + *(bjets_p4->at(0))).M();
              wmass = (*(ljets_p4->at(ljet_indice->at(1))) + *(ljets_p4->at(ljet_indice->at(2)))).M();
            }else{
              t1mass = (*(ljets_p4->at(ljet_indice->at(0))) + *(ljets_p4->at(ljet_indice->at(1))) + *(bjets_p4->at(0))).M();
              wmass = (*(ljets_p4->at(ljet_indice->at(0))) + *(ljets_p4->at(ljet_indice->at(1)))).M();
            }
            t2mass = (*(ljets_p4->at(ljet_indice->at(0))) + *(taus_p4->at(0)) + *(tau2) + *neutrinos_p4->at(0) + *neutrinos_p4->at(1)).M();
            tautaumass = (*(taus_p4->at(0)) + *(tau2) + *neutrinos_p4->at(0) + *neutrinos_p4->at(1)).M();
          }
          x1fit = 1 - neutrinos_p4->at(0)->E() / (*(taus_p4->at(0)) + *neutrinos_p4->at(0)).E();
          x2fit = 1 - neutrinos_p4->at(1)->E() / (*(tau2) + *neutrinos_p4->at(1)).E();
        }
        phicent = phi_centrality(taus_p4->at(0)->Phi(),tau2->Phi(),met_p4->Phi());
        tautauvispt = (*taus_p4->at(0) + *tau2).Pt();
        t2vismass = ljets_p4->size() >= 1 ? (*taus_p4->at(0) + *tau2 + *ljets_p4->at(ljet_indice->at(0))).M() : 0;
        drttj = ljets_p4->size() >= 1 ? (*taus_p4->at(0) + *tau2).DeltaR(*ljets_p4->at(ljet_indice->at(0))) : 0;
        dphitauetmiss = fabs(met_p4->DeltaPhi(*taus_p4->at(0) + *tau2));
        etmiss = met_p4->Pt();
        mtaujmin = 0;
        drttjmin = 999;
        mttjmin = 0;
        mjjmin = 0;
        if(leps_p4->size()!=0) drlb = leps_p4->at(0)->DeltaR(*bjets_p4->at(0));
        drtaub = taus_p4->at(0)->DeltaR(*bjets_p4->at(0));
        if(leps_p4->size()!=0) drltau = taus_p4->at(0)->DeltaR(*leps_p4->at(0));
        
        if(leps_p4->size()!=0){
          if(wlep && wlep != leps_p4->at(0)) drltau = taus_p4->at(0)->DeltaR(*wlep);
        }
        etamax = 0;
        for (auto tau: *taus_p4)
        {
          etamax = max(etamax,(float)fabs(tau->Eta()));
        }
        if(wlep) mtw = sqrt(2*wlep->Pt()*etmiss*(1 - cos( met_p4->DeltaPhi(*wlep) )));
        if(taus_p4->size() >= 2&&leps_p4->size()!=0) drlbditau = (*leps_p4->at(0) + *bjets_p4->at(0)).DeltaR(*taus_p4->at(0) + *taus_p4->at(1));
        else if(wlep) drlbditau = (*wlep + *bjets_p4->at(0)).DeltaR(*taus_p4->at(0) + *tau2);
  
        drtaujmin = 0;
        for (int ijet = 0 ; ijet < ljets_p4->size(); ijet ++ ) {
  
          double tmpmttjmin =  (*taus_p4->at(0) + *tau2 + *ljets_p4->at(ijet)).M();
          double tmpmtaujmin = (*taus_p4->at(0) + *ljets_p4->at(ijet)).M();
          if(mtaujmin == 0 || mtaujmin > tmpmtaujmin){
            mtaujmin = tmpmtaujmin;
          }
          if(mttjmin == 0 || mttjmin > tmpmttjmin){
            mttjmin = tmpmttjmin;
          }
  
          if(drtaujmin == 0 || drtaujmin > taus_p4->at(0)->DeltaR(*ljets_p4->at(ijet))){
            drtaujmin = taus_p4->at(0)->DeltaR(*ljets_p4->at(ijet));
            if(taus_p4->size() >= 2) drtaujmin = min(drtaujmin, (float)taus_p4->at(1)->DeltaR(*ljets_p4->at(ijet)));
          }
          if(drttjmin > (*(taus_p4->at(0)) + *(tau2)).DeltaR(*ljets_p4->at(ijet)))
            drttjmin = (*(taus_p4->at(0)) + *(tau2)).DeltaR(*ljets_p4->at(ijet));
          if(mttjmin > (*(taus_p4->at(0)) + *(tau2)+ *ljets_p4->at(ijet)).M() || mttjmin == 0)
            mttjmin = (*(taus_p4->at(0)) + *(tau2) + *ljets_p4->at(ijet)).M();
  
          for(int jjet = ijet+1 ; jjet < ljets_p4->size(); jjet ++ ){
            double tmpmjj = (*ljets_p4->at(ijet)+*ljets_p4->at(jjet)).M();
            if(mjjmin > tmpmjj || mjjmin==0) mjjmin = tmpmjj;
          }
        }
        pt_b = bjets_p4->at(0)->Pt();
        pt_ljet = ljets_p4->size() ? ljets_p4->at(0)->Pt():0;
        if(leps_p4->size()){
          lep_pt_0 = leps_p4->at(0)->Pt();
          lep_pt_1 = leps_p4->size() == 1? 0 : leps_p4->at(1)->Pt();
        }
        if (dumptruth && fcnc && sample.Contains("fcnc")) dumpTruth(eventNumber % 2);
        tau_pt_0 = taus_p4->at(0)->Pt();
        if(taus_p4->size()>=2) tau_pt_1 = taus_p4->at(1)->Pt();
        if(leps_p4->size()) {
          tau_pt_0 = taus_p4->at(0)->Pt();
          if(leps_p4->size()>=2) lep_pt_1 = leps_p4->at(1)->Pt();
        }
      }else {
        tau_pt_0 = taus_p4->at(0)->Pt();
        lep_pt_0 = leps_p4->at(0)->Pt();
        lep_pt_1 = leps_p4->at(1)->Pt();
        if(leps_p4->size() >= 2) mll = (*leps_p4->at(0)+*leps_p4->at(1)).M();
      }
    }

    if(reduce == 3){
      BDTG_test  = 0;
      BDTG_train  = 0;
      if(ctagFCNC && fcncjetbscore < btagwpCut[3]) {
        continue;
      }
      cut_flow.fill("Loose btag FCNC jet");
      if(doBDT){
        if(debug) printf("eval BDTG\n");
        if(belong_regions.have("2mtau")||belong_regions.have("2ltau")){
          if(belong_regions.have("3j")) {
            BDTG_test = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2) );
            BDTG_train = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)) );
          }
          if(belong_regions.have("2j")) {
            BDTG_test = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2) );
            BDTG_train = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)) );
          }
        }else{
          if(belong_regions.have("1l2tau")) {
            BDTG_test  = reader["reg1l2tau1bnj_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
            BDTG_train = reader["reg1l2tau1bnj_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
          }
          if(belong_regions.have("2j"    )) {
            BDTG_test  = reader["reg1l1tau1b2j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
            BDTG_train = reader["reg1l1tau1b2j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
          }
          if(belong_regions.have("3j"    )) {
            BDTG_test  = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
            BDTG_train = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
          }
          if(belong_regions.have("2lSS"    )) {
            BDTG_test  = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
            BDTG_train = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
          }
        }
      }
      if(dumpeventnumber) {
        for(auto reg : belong_regions.all()){
          if(mcChannelNumber>0)
            evtfile<<reg<<" "<<mcChannelNumber<<" "<<eventNumber<<" "<<weights->at(0)<<endl;
          else
            evtfile<<reg<<" "<<runNumber<<" "<<eventNumber<<" "<<weights->at(0)<<endl;
        }
      }
    }
  
    if(debug) printf("nominal::Loop : Finding origins\n");
  
    if (dohist && mcChannelNumber && weightsysmap.find(mcChannelNumber) == weightsysmap.end()) {
      readweightsysmap(mcChannelNumber,(!(belong_regions.have("2l")||belong_regions.have("1l")) || belong_regions.have("ltau"))? "xTFW" : "tthML");
      if(weightsysmap.find(mcChannelNumber) == weightsysmap.end()) {
        printf("tthmltree::Loop() WARNING: channel number %d not found in the systematics map, skipping\n", mcChannelNumber);
        continue;
      }
    }
    for (auto region: belong_regions.all()) {
      if(debug) printf("fill region: %s\n", region.Data());
      if(reduce == 1){
        weights->clear();
        if(!isData){
          weight = generalweight*calcRegionSF(region);
          addweights(weight,"NOMINAL");
          calcfakesf_pdg();
          if(nominaltree){
            if(!addWeightSys()) continue;
            if(!addTheorySys()) {
              printf("Warning: cannot add weight systematics\n");
              continue;
            }
          }
        }else{
          addweights(1,"NOMINAL");
        }
      }
      if (writetree){
        if(outputtree.find(region) != outputtree.end()){
          outputtree[region]->Fill();
        }
        else{
          printf("Error: outputtree cannot find: %s\n", region.Data());
          for(auto itertmp : outputtree){
            printf("output tree list: %s\n", itertmp.first.Data());
          }
          exit(1);
        }
      }
      if (dohist) {
  
        TString    leporigin;
        TString    tauorigin;
        if(leps_id->size()){
          if (sample.Contains("data")) {
            leporigin = "data";
            sample = "data";
          } else {
            int nfakelep = leps_matched_pdgId->size();
            for (int i = 0; i < leps_matched_pdgId->size(); ++i){
              TString origin = classifyLepFakes(i);
              if(origin == "realLep") nfakelep -= 1;
              else leporigin = sample + "_" + origin;
            }
            if(nfakelep == 0) leporigin = sample + "_realLep";
            else if(nfakelep >= 2) leporigin = sample + "_doubleFakeLep";
          }
        }
        if (sample.Contains("data")) {
          tauorigin = "data";
          sample = "data";
        } else {
          int nfaketau = 0;
          for (int i = 0; i < taus_matched_pdgId->size(); ++i){
            int tauabspdg = abs(taus_matched_pdgId->at(i));
            if(tauabspdg != 15 || taus_matched_pdgId->at(i) * taus_q->at(i) > 0) {
              nfaketau++;
              if (tauabspdg == 13 || tauabspdg == 11) tauorigin = sample + "_lep";
              else if (tauabspdg == 5) tauorigin = sample + "_b";
              else if (tauabspdg == 4) tauorigin = sample + "_c";
              else if (tauabspdg <= 3 && tauabspdg >=1) tauorigin = sample + "_j";
              else if (tauabspdg == 21) tauorigin = sample + "_g";
              else tauorigin = sample + "_nomatch";
              if((tauabspdg == 4 || (tauabspdg <= 3 && tauabspdg >=1)) && abs(taus_matched_mother_pdgId->at(i)) == 24) tauorigin = sample + "_wjet";
            }
          }
          if(nfaketau == 0) tauorigin = sample + "_real";
          else if(nfaketau >= 2) tauorigin = sample + "_doublefake";
        }
        if(debug) printf("fill hist\n");

        if(!plotTauFake){
          region += abs(leps_id->at(0)) == 11?"_e":"_mu";
          region += abs(leps_id->at(1)) == 11?"e":"mu";
      	}
        if(mcChannelNumber!=0){
          auto weightvec = weightsysmap.at(mcChannelNumber);
          for (int iNP = 0; iNP < plotNPs.size(); ++iNP){
            auto theNP = plotNPs.at(iNP);
            if(debug) printf("fill NP %s\n", theNP.Data());
            weight = weights->at(0);
            if(applyNewFakeSF){
              if(theNP.Contains("fakeSF")){
                TString SFname;
                if(debug) printf("weight = %f\nPlotNP = %s\n",weight,theNP.Data());
                observable thefakeSF;
                if(leps_id->size()) thefakeSF= FindNewFakeSF("NOMINAL", 0,SFname);
                else thefakeSF= FindNewFakeSF("NOMINAL", 0,SFname);
                weight *= thefakeSF.nominal + thefakeSF.error*(theNP==SFname);
                if(taus_p4->size() >= 2) {
                  if(leps_id->size()) thefakeSF= FindNewFakeSF("NOMINAL", 1,SFname);
                  else thefakeSF = FindNewFakeSF("NOMINAL", 1, SFname);
                  weight *= thefakeSF.nominal + thefakeSF.error*(theNP==SFname);
                }
                if(debug) printf("weight = %f after apply fakeSF\n",weight);
              }else{
                if(doubleCounting){
                  weight *= FindNewFakeSF("NOMINAL").nominal;
                }else if(nominaltree) 
                  weight *= FindNewFakeSF(theNP).nominal;
                else if(theNP == "NOMINAL"){
                  weight *= FindNewFakeSF(SystematicsName).nominal;
                }
              }
            }
            if(!theNP.Contains("Xsec") && !theNP.Contains("fakeSF") && nominaltree) {
              std::vector<TString>::iterator it = std::find(weightvec.begin(), weightvec.end(), theNP);
              int index = 2;
              if(it != weightvec.end()) index = std::distance(weightvec.begin(), it);
              else continue;
              if(index==2 || index==1) weight = weights->at(index);
              //else if(index > 8 && index < 17)
              //  weight = weights->at(2) * weights->at(index);
              else if(index !=0)
                weight *= weights->at(index);
            }
            if(plotTauFake && region.Contains("tau")) fillhist(fcnc?fcnc_plots:fake_plots, region, taus_n_charged_tracks->at(0), tauorigin, taus_b_tagged->at(0), theNP);
            else if((taus_b_tagged->size()==0 || !taus_b_tagged->at(0)) && region.Contains("2l")) (fcnc?fcnc_plots:fake_plots)->fill_hist(leporigin,region,theNP);
            if(!region.Contains("tau")) fill_notau(region, sample, theNP);
          }
        }else{ //data
          if(plotTauFake && region.Contains("tau")) fillhist(fcnc?fcnc_plots:fake_plots, region, taus_n_charged_tracks->at(0), tauorigin, taus_b_tagged->at(0), "NOMINAL");
          else if(!taus_b_tagged->at(0) && region.Contains("2l")) (fcnc?fcnc_plots:fake_plots)->fill_hist("data",region,"NOMINAL");
          if(!region.Contains("tau")) fill_notau(region, sample, "NOMINAL");
        }
      } // match dohist
      if(debug == 2) printf("finish hist\n");
    }
    ifill ++;
  }
  if(dumpeventnumber) evtfile.close();
  printf("dropped events total weight: %f\n", droppedweight);
  if(reduce != 1){
    printf("%s \n", inputtree->GetName());
    cut_flow.print();
    cut_flow.save(20);
    cut_flow.clear();
  }
  if (dumptruth) {
    if (TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) {
      filetruth[0][0].close();
      filetruth[0][1].close();
    } else {
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
  } 
}


void nominal::defineRegions(){
  if(!leps_p4 || leps_p4->size()==0){
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau1b2jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau1b3jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau1b2jos");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau1b3jos");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau2b2jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau2b3jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau2b2jos");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau2b3jos");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 0 && ljets_p4->size() >= 4 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau0b4jos");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 0 && ljets_p4->size() == 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau0b3jos");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 0 && ljets_p4->size() >= 4 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau0b4jss");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 0 && ljets_p4->size() == 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau0b3jss");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && (bjets_p4->size()+ljets_p4->size()) >= 4 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau4jos");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && (bjets_p4->size()+ljets_p4->size()) == 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau3jos");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && (bjets_p4->size()+ljets_p4->size()) >= 4 && taus_q->at(0)*taus_q->at(1) ==  1) belong_regions.add("reg2mtau4jss");
    //if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && (bjets_p4->size()+ljets_p4->size()) == 3 && taus_q->at(0)*taus_q->at(1) ==  1) belong_regions.add("reg2mtau3jss");
    if((taus_id->at(0)>=1) && (taus_id->at(1)>=1) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ltau1b2jss");
    if((taus_id->at(0)>=1) && (taus_id->at(1)>=1) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ltau1b3jss");
    if((taus_id->at(0)>=1) && (taus_id->at(1)>=1) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ltau1b2jos");
    if((taus_id->at(0)>=1) && (taus_id->at(1)>=1) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ltau1b3jos");
    /* if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau1b2jss");
    if((taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 &&  bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1mtau1ltau1b2jss");
    if(!(taus_id->at(0)>=2) && !(taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ltau1b2jss");
    if(taus_id->at(0)==3 && taus_id->at(1)==3 && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ttau1b2jss");
    if(taus_id->at(0)==3 + (taus_id->at(1)==3) == 1 && (taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1ttau1mtau1b2jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau1b3jss");
    if((taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 &&  bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1mtau1ltau1b3jss");
    if(!(taus_id->at(0)>=2) && !(taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ltau1b3jss");
    if(taus_id->at(0)==3 && taus_id->at(1)==3 && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ttau1b3jss");
    if(taus_id->at(0)==3 + (taus_id->at(1)==3) == 1 && (taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1ttau1mtau1b3jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau1b2jos");
    if((taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 &&  bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1mtau1ltau1b2jos");
    if(!(taus_id->at(0)>=2) && !(taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ltau1b2jos");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau1b3jos");
    if((taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 &&  bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1mtau1ltau1b3jos");
    if(!(taus_id->at(0)>=2) && !(taus_id->at(1)>=2) && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ltau1b3jos");
    if(taus_id->at(0)==3 && taus_id->at(1)==3 && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ttau1b2jos");
    if(taus_id->at(0)==3 + (taus_id->at(1)==3) == 1 && (taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 && bjets_p4->size() == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1ttau1mtau1b2jos");
    if(taus_id->at(0)==3 && taus_id->at(1)==3 && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ttau1b3jos");
    if(taus_id->at(0)==3 + (taus_id->at(1)==3) == 1 && (taus_id->at(0)>=2) + (taus_id->at(1)>=2) == 1 && bjets_p4->size() == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1ttau1mtau1b3jos");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau2b2jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau2b3jss");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau2b2jos");
    if((taus_id->at(0)>=2) && (taus_id->at(1)>=2) && bjets_p4->size() == 2 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau2b3jos");*/
  }else if(leps_p4->size()==1){
    if(ljets_p4->size() == 2 && bjets_p4->size() == 1 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg1l1tau1b2j_os");
    if(ljets_p4->size() >= 3 && bjets_p4->size() == 1 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg1l1tau1b3j_os");
    if(bjets_p4->size() == 1 && taus_p4->size() >= 2 && taus_q->at(0)*taus_q->at(1) < 0) belong_regions.add("reg1l2tau1bnj_os");
    if(ljets_p4->size() == 2 && bjets_p4->size() == 1 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg1l1tau1b2j_ss");
    if(ljets_p4->size() >= 3 && bjets_p4->size() == 1 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg1l1tau1b3j_ss");
    if(ljets_p4->size() == 2 && bjets_p4->size() == 2 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg1l1tau2b2j_os");
    if(ljets_p4->size() >= 3 && bjets_p4->size() == 2 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg1l1tau2b3j_os");
    if(ljets_p4->size() == 2 && bjets_p4->size() == 2 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg1l1tau2b2j_ss");
    if(ljets_p4->size() >= 3 && bjets_p4->size() == 2 && taus_p4->size() == 1 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg1l1tau2b3j_ss");
    if(bjets_p4->size() == 1 && taus_p4->size() >= 2 && taus_q->at(0)*taus_q->at(1) > 0) belong_regions.add("reg1l2tau1bnj_ss");
    if(bjets_p4->size() == 2 && taus_p4->size() >= 2 && taus_q->at(0)*taus_q->at(1) < 0) belong_regions.add("reg1l2tau2bnj_os");
    if(bjets_p4->size() == 2 && taus_p4->size() >= 2 && taus_q->at(0)*taus_q->at(1) > 0) belong_regions.add("reg1l2tau2bnj_ss");
    if(bjets_p4->size() == 2 && ljets_p4->size() == 1 && taus_p4->size() == 1 && (leps_id->at(0) > 0 ? -1 : 1)*taus_q->at(0) < 0) belong_regions.add("reg1l1tau2b1j_os");
    if(bjets_p4->size() == 2 && ljets_p4->size() == 1 && taus_p4->size() == 1 && (leps_id->at(0) > 0 ? -1 : 1)*taus_q->at(0) > 0) belong_regions.add("reg1l1tau2b1j_ss");
    if(bjets_p4->size() == 2 && ljets_p4->size() == 0 && taus_p4->size() == 1 && (leps_id->at(0) > 0 ? -1 : 1)*taus_q->at(0) < 0) belong_regions.add("reg1l1tau2b_os");
    if(bjets_p4->size() == 2 && ljets_p4->size() == 0 && taus_p4->size() == 1 && (leps_id->at(0) > 0 ? -1 : 1)*taus_q->at(0) > 0) belong_regions.add("reg1l1tau2b_ss");
  }else if (leps_p4->size()==2){
    mll = (*leps_p4->at(0)+*leps_p4->at(1)).M();
    if(leps_iso->at(0) && leps_iso->at(1)) { //PLV + isolation
      bool sameflavor = abs(leps_id->at(0)) == abs(leps_id->at(1));
      if((!sameflavor || (sameflavor && (mll < 80*GeV || mll > 100*GeV))) && leps_id->at(0)*leps_id->at(1)<0){ //2l ttbar CR
        if(bjets_p4->size() == 2 && taus_p4->size() == 1) belong_regions.add("reg2l1tau2bnj");
        if(bjets_p4->size() == 1 && taus_p4->size() == 1) belong_regions.add("reg2l1tau1bnj");
        if(bjets_p4->size() == 2 && taus_p4->size() == 0) belong_regions.add("reg2l2bnj");
      }
      if(bjets_p4->size() == 1 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1tau1bnj_os");
      if(bjets_p4->size() == 0 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1taunj_os");
      if(ljets_p4->size() >= 1 && bjets_p4->size() == 0 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1taunj_os");
      //if(bjets_p4->size() == 1 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg2lSS1tau1bnj_ss");
      //if(bjets_p4->size() == 2 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1tau2bnj_os");
      //if(bjets_p4->size() == 2 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg2lSS1tau2bnj_ss");
    }else if(leps_iso->at(0) && !leps_iso->at(1)){ //reverse iso only for 2nd lepton
      if(bjets_p4->size() == 1 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1tau1bnj_os_antiiso");
      if(ljets_p4->size() >= 1 && bjets_p4->size() == 0 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1taunj_os_antiiso");
      //if(bjets_p4->size() == 1 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg2lSS1tau1bnj_ss_antiiso");
      //if(bjets_p4->size() == 2 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1tau2bnj_os_antiiso");
      //if(bjets_p4->size() == 2 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg2lSS1tau2bnj_ss_antiiso");
    }else if(leps_iso->at(1) && !leps_iso->at(0)){ //reverse iso only for 1st lepton
      if(bjets_p4->size() == 1 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1tau1bnj_os_antiisolead");
      if(ljets_p4->size() >= 1 && bjets_p4->size() == 0 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1taunj_os_antiisolead");
      //if(bjets_p4->size() == 1 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg2lSS1tau1bnj_ss_antiisolead");
      //if(bjets_p4->size() == 2 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) > 0) belong_regions.add("reg2lSS1tau2bnj_os_antiisolead");
      //if(bjets_p4->size() == 2 && taus_p4->size() == 1 && leps_id->at(0) * leps_id->at(1) > 0 && taus_q->at(0)*leps_id->at(0) < 0) belong_regions.add("reg2lSS1tau2bnj_ss_antiisolead");
    }
  }
}

TString nominal::classifyLepFakes(int ilep){ //https://indico.cern.ch/event/725960/contributions/2987219/attachments/1641430/2621432/TruthDef_April242018.pdf

  int T = leps_truth_type->at(ilep);
  int O = leps_truth_origin->at(ilep);
  int RecoCharge = -leps_id->at(ilep);
  int firstEgMotherPdgId = leps_first_EgMother_pdgId->at(ilep);
  int firstEgMotherO = leps_first_EgMother_truth_origin->at(ilep);
  int firstEgMotherT = leps_first_EgMother_truth_type->at(ilep);

  //Prompt muon
  if(
    T==6 && (O==10 || O==12 || O==13 || O==14 || O==15 || O==22 || O==43)
  ) return "realLep";

  bool C1 = T==2 || ( T==4 && O==5 && fabs(firstEgMotherPdgId) == 11) ||
  ( T==4 && O==7 && firstEgMotherT==2 && (firstEgMotherO == 10 || firstEgMotherO == 12 || firstEgMotherO == 13 || firstEgMotherO == 14 || firstEgMotherO == 43) && fabs(firstEgMotherPdgId) == 11);

  //Prompt electron
  if(
    (C1 && firstEgMotherPdgId*RecoCharge<0) || (T==4 && (O==5 || O==7) && firstEgMotherO==40) || ( T==15 && O==40 )
  ) return "realLep";
  //charge flip
  if(
    C1 && firstEgMotherPdgId*RecoCharge>0
  ) return "chargeFlip";

   //Non-prompt
  if(
    ((T==3 || T==15 ) && O==9) || ( T==4 && O==5 && firstEgMotherT==15 && firstEgMotherO==9 ) || (T==7 && O==9) ||
    (T==3 && (O==26 || O==29 || O==33 ) )||
    ((T==16 && O==26) || ( T==4 && O==5 && firstEgMotherT==16 && firstEgMotherO==26 ) || (( T==6 || T==7 ) && (O==26 || O==29 || O==33 ) ))||
    (T==3 && ( O==25 || O==32 || O==27 ) )||
    (T==4 && O==27 )||
    (T==16 && ( O==25 || O==27 )) || ( T==4 && O==5 && firstEgMotherT==16 && ( firstEgMotherO==25 || firstEgMotherO==27 ) ) || (T==7 && ( O==25 || O==32 || O==27 )) || (( T==6 || T==8 ) && ( O==27 ))
  ) return "nonPrompt";

  //Hadron decay (light flavor)
  if(
    (T==4 && ( O==6 || O==23 || O==24 ) ) ||
    ((T==4 && O==5 && firstEgMotherT==16 && ( firstEgMotherO==42 || firstEgMotherO==23 || firstEgMotherO==24 )) || (T==4 && O==7 && ( (firstEgMotherT==4 && firstEgMotherO==24) || (firstEgMotherT==16 && firstEgMotherO==42) ) ) || (T==16 && (O==42 || O==23) ) ) ||
    (T==8 && ( O==34 || O==35 || O==23 ||24 ) ) || T==17
  ) return "otherFakeLep";

  //Muons reconstructed as e
  if(
    (( T==3 || T==15 ) && O==8) || ( T==4 && O==7 && firstEgMotherT==3 && firstEgMotherO==8 ) || ( T==4 && O==5 && firstEgMotherT==15 && firstEgMotherO==8 )
  ) return "otherFakeLep";

  //Prompt photon conversion
  if(
    (T==14 && O==37) || (T==4 && (O==5 || O==7)&& firstEgMotherT==14 && firstEgMotherO==37) || (T==4 && O==5 && firstEgMotherT==16 && firstEgMotherO==38) || (T==16 && O==38)
  ) return "conversion";

  printf("Warning: fake origin not found: T==%d,O==%d,RecoCharge==%d,firstEgMotherPdgId==%d,firstEgMotherO==%d ; classify as unknown_fakes\n",T,O,RecoCharge,firstEgMotherPdgId,firstEgMotherO);
  return "unknownFakeLep";
}
