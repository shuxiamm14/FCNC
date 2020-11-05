#ifndef NOMINAL
#define NOMINAL
#include "region.h"
#include "applyTF.h"
#include <TROOT.h>
#include <TChain.h>
#include "TString.h"
#include "histSaver.h"
#include "TMinuit.h"
#include "RooRealVar.h"
#include "RooGaussian.h"
#include "RooLandau.h"
#include "RooAddPdf.h"
#include "TMVA/Reader.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "observable.h"
#include "cutflow.h"
// Header file for the classes stored in the TTree if any.

#ifndef NO_TMINUIT
static TMinuit* gM = 0;
#endif
const double btag70wt = 2.96;

class nominal {
public :
  //=============================configurations===============================
  bool dofit1l2tau = 0;
  bool applyfakeSF = 0;
  bool ctagFCNC = 0;
  std::map<TString,bool> dobwp;
  std::map<TString,bool> dovetobwp;
  bool doubleCounting = 0;
  bool dumpeventnumber;
  bool dumptruth;
  bool applyNewFakeSF;
  double nonfcncmatched;
  double fcncmatched;
  double leptonicw;
  bool fcnc;
  bool doBDT;
  bool dofit;
  double BDTG_train;
  double BDTG_test;
  double fcncjetbscore;
  int debug;
  bool dosys;
  int reduce;
  bool initdata;
  bool initttbar;
  bool dohist;
  int version;
  bool plotTauFake;
  bool isData;
  bool tightLep = 1;
  bool tightTau;
  bool fit_collinear;
  bool mass_collinear;
  //=============================configurations===============================
  TString dataDir = ".";
  TString SystematicsName = "NOMINAL";
  CutFlow cut_flow;
  TMinuit* gMinside;
// Fixed size dimensions of array or collections stored in the TTree if any.
  //const double btagwpCut[4]={0.94,0.83,0.64,0.11};
  const double btagwpCut[4]={4.31,2.96,2.20,1.27};  //DL1r
  double defaultbtagwp;
  //const double fakeSFs[4][4] = {
  //  {1.028254, 0.060939, 2.842907, 0.802803},  //1prong <35
  //  {0.770841, 0.524360, 2.233151, 0.769241},  //1prong >35
  //  {1.157861, 0.792569, 1.349050, 1.426554},  //3prong <35
  //  {0.818782, 0.614790, 5.756198, 0.489836}   //3prong >35
  //};  
  
  const double fakeSFML[2][3] = {{1.05,0.94,0.64} , {1.25,1.30,0.52}}; //1prong: 25-45, 45-70, 70- ; 3prong: 25-50, 50-75, 75-
  const double fakeSFMLNP[2][3] = {{0.064,0.2247,0.122} , {0.422,0.7879,0.7068}};

  const double fakeSFs[2][4] = {
    {1.060928,0.538011,2.654738,0.955523},  // <35
    {0.814329,1.013681,1.297911,0.958773}  // >35
  };

  const double fakeSFsNPbase[2][4][4] = {
    {
      {0.298063,0.940926,-0.159135,0.022190},
      {0.275509,0.073081,0.956598,0.060620},
      {0.201924,-0.039721,0.006891,-0.978571},
      {0.891336,-0.328237,-0.244028,0.195528}
    },
    {
      {-0.874323,0.469344,-0.121289,0.023737},
      {-0.241613,-0.203613,0.948367,-0.027652},
      {-0.075295,-0.108700,-0.071347,-0.988648},
      {-0.414142,-0.852316,-0.284250,0.145765}
    }
  };
  const double fakeSFsNPsSigma2[2][4]{
    {0.000501,0.001053,0.008590,0.136083},
    {0.000436,0.000705,0.007718,0.250730}
  };
  
  std::map<TString, TMVA::Reader*> reader;

  static int GeV;
  std::vector<TString> plotNPs;
  std::map<TString,std::map<TString,std::vector<observable>>> newFakeSF;
  std::map<TString,std::vector<observable>> newFakeSFSys;
  Int_t ierflg;
  int ifill = 0;

  bool nominaltree = 1;
  std::map<int, std::vector<TString>> weightsysmap; //only used after reduce 1
  std::vector<TString> weightlist; //only used in reduce 1
  TH1D* theoryweightsum = 0;
  TFile *outputtreefile;
  histSaver *fcnc_plots;
  histSaver *fake_plots;
  histSaver *fake_notau_plots;

  applyTF m_applyTF;
  std::vector < TLorentzVector > ljets_v;
  std::vector < float > ljets_score;
  std::fstream filetruth[6][2];
  std::fstream file_event_number;
  std::fstream event_info;
  std::fstream srcr_file_event_number;
  std::fstream srcr_event_info;
  Double_t arglist[10];
  std::vector<TString> fcnc_regions;
  std::vector<TString> fake_regions;
  std::vector<TString> fake_regions_notau;
  int fcnc_nregions;
  int fake_nregions;
  int fake_nregions_notau;
  bool writetree = 1;
  TString bwps[4] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
  BelongRegion belong_regions;
  Double_t _lum = 80.;
  nominal();
  virtual ~nominal();
  void plot();
  std::map<TString, TTree*> outputtree;
  void init_dsid();
  void ConfigNewFakeSF();
  void initReduce1();
  static Float_t eval(const Float_t x, const Float_t y, const TH2F* h);
  observable FindNewFakeSF(TString NP);
  observable FindNewFakeSF(TString NP, int itau, TString &name);
  observable FindNewFakeSF(TString NP, int itau);
  void addweights(double weight, TString name);
  void saveweightslist(TString filename);
  void readTFmeanstd(TString filename);
  TMinuit* initgM();
  void initMVA(TString fcnc_region);
  void dumpTruth(int part){}
  void readweightsysmap(int dsid,TString framework);
  TLorentzVector vectorPtEtaPhiE(std::vector<float> vec);
  std::vector<int>* findcjet();
  std::vector<int> findcjetML(int part);
  std::vector<int> findwpair(int cjet);
  static Float_t getHadTauProb(Float_t _dR, Float_t _p);
  static Float_t getLepTauProb(Float_t _dR, Float_t _minv, Float_t _p);
  Double_t phi_centrality(Double_t aPhi, Double_t bPhi, Double_t cPhi);
  void finalise_sample();
  static  void    fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
  static  void    fcn_collinear(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);

  bool MassCollinearCore(const TLorentzVector &k1, const TLorentzVector &k2,  // particles
                              const float metetx, const float metety,            // met
                              float &mass, float &xp1, float &xp2);
  bool MassCollinear(bool kMMCsynchronize, float &mass, float &xp1, float &xp2);
  void fillhist(histSaver *plots, TString region, int nprong, TString sample, int taubtag, TString NP);
  void fill_notau(TString region, TString sample, TString NP);
  bool SelectTLepid(int id);
  void calcfakesf(std::vector<int> origin);
  void calcfakesf_pdg();
  void defGeV(int _GeV);
  bool addTheorySys();
  void initCommon();
  void initFit();
  static void printv(TLorentzVector v);
  void setVecBranch(TTree *tree);
  void vecBranch(TTree *tree);
  void setBDTBranch(TTree *tree);
  void BDTBranch(TTree *tree);
  void init(TTree *tree);
  void defineTree(TTree *tree);
  virtual void initRaw(TTree *tree){ printf("WARNING: virtual function initRaw is used\n"); }
  virtual void init_hist(TString histfilename){ printf("WARNING: virtual function init_hist is used\n"); }
  void Loop(TTree*inputtree, TString samplename, float globalweight);
  virtual void init_sample(TString sample, TString sampletitle){ printf("WARNING: virtual function init_sample is used\n"); }
  virtual void constructwmatchmap(TTree *tree){ printf("WARNING: virtual function constructwmatchmap is used\n"); }
  virtual void calcGeneralWeight(){ printf("WARNING: virtual function calcGeneralWeight is used\n"); }
  virtual float calcRegionSF(TString region){ printf("WARNING: virtual function calcGeneralWeight is used\n"); return 0;}
  virtual bool passBasicCut(){ printf("WARNING: virtual function passBasicCut is used in nominal.h\n"); return 1; }
  virtual void defineObjects(){ printf("WARNING: virtual function defineObjects is used in nominal.h\n"); }
  virtual void defineRegions();
  virtual void defineTauTruth(){ printf("WARNING: virtual function defineTauTruth is used in nominal.h\n"); }
  virtual void defineLepTruth(){ printf("WARNING: virtual function defineLepTruth is used in nominal.h\n"); }
  virtual bool addWeightSys(){ printf("WARNING: virtual function addWeightSys is used in nominal.h\n"); return 1;}
  virtual bool passRegionCut(){return 1;}
  virtual void prepare(){ printf("WARNING: virtual function prepare is used in nominal.h\n"); }
  TString classifyLepFakes(int ilep);
  //======================================================general necessary variables========================================
  ULong64_t  eventNumber;
  UInt_t        runNumber;
  UInt_t     mcChannelNumber;
  float     weight_mc;
  float      generalweight;
  TString    samplename;
  int        campaign;
  //======================================================vector variables for analysis========================================
  std::vector<float>           *weight_mc_v;
  std::vector<double>          *weights;
  std::vector<int>             *ljet_indice;
  std::vector<UInt_t>          *taus_n_charged_tracks;
  std::vector<Int_t>           *taus_b_tagged;
  std::vector<Int_t>           *taus_id;
  std::vector<Float_t>         *taus_q;
  std::vector<TLorentzVector*> *taus_p4;
  std::vector<int> *taus_matched_mother_pdgId;
  std::vector<int> *taus_matched_pdgId;
  std::vector<TLorentzVector*> *neutrinos_p4;
  TLorentzVector               *met_p4;
  std::vector<TLorentzVector*> *bjets_p4;
  std::vector<TLorentzVector*> *ljets_p4;
  std::vector<TLorentzVector*> *leps_p4;
  std::vector<Int_t>           *leps_id;
  std::vector<Int_t>           *leps_iso;
  std::vector<Int_t>           *leps_tight;
  std::vector<int> *leps_matched_pdgId;
  std::vector<int> *leps_truth_type;
  std::vector<int> *leps_truth_origin;
  std::vector<int> *leps_first_EgMother_pdgId;
  std::vector<int> *leps_first_EgMother_truth_origin;
  std::vector<int> *leps_first_EgMother_truth_type;
  std::vector<TLorentzVector*>  *totaljets_p4;
  std::map<ULong64_t,std::vector<int>*> taumatchmap;// cannot use eventnumber as a vector index
  std::vector<float>           *bjets_score;
  std::vector<float>           *ljets_bscore;
  //======================================================flat variables for BDT========================================
  float      mll;
  float      drttjmin;
  float      t2vismass;
  float      t1vismass;
  float      ttvismass;
  float      tautauvispt;
  float      weight;
  float      x1fit;
  float      x2fit;
  float      mtaujmin;
  float      mttjmin;
  float      tau_pt_0;
  float      tau_pt_1;
  float      pt_b;
  float      pt_ljet;
  float      taulmass;
  float      t1mass;
  float      drlbditau;
  float      mtw;
  float      tau_pt_ss;
  float      tau_pt_os;
  float      etamax;
  float      drltau  ;
  float      drttj  ;
  float      drtautau;
  float      wmass   ;
  float      t2mass  ;
  float      tautaumass;
  float      etmiss;
  float      dphitauetmiss;
  float      phicent;
  float      chi2;
  float      allmass;
  float      allpz;
  float      mjjmin;
  float      drlb;
  float      drtaub;
  float      lep_pt_0;
  float      lep_pt_1;
  int        nljet;
  float      drtaujmin;
  float      drtauj;
  float      MET_RefFinal_et;
  // hadhad specific
  float      tau0RNN;
  float      tau1RNN;
  float      ditau_coll_approx_m;
  float      ditau_coll_approx_x0;
  float      ditau_coll_approx_x1;
  float      met_sumet;
  float      met_sigma;
  //======================================================variables for kinematic fit========================================
  static TH2F* prob_20_40;
  static TH2F* prob_40_60;
  static TH2F* prob_60_80;
  static TH2F* prob_80_100;
  static TH2F* prob_100_120;
  static TH2F* prob_120_140;
  static TH2F* prob_140_160;
  static TH2F* prob_160_200;
  static TH2F* prob_200_300;
  static TH2F* prob_300_400;
  static TH2F* prob_400;
  static RooRealVar  _dR_;
  static RooRealVar  _m1_;
  static RooRealVar  _w1_;
  static RooGaussian _gaus_;
  static RooRealVar  _m2_;
  static RooRealVar  _w2_;
  static RooLandau   _land_;
  static RooRealVar  _fr1_;
  static RooAddPdf   _pdf_;

  std::map<TString,std::vector<TLorentzVector*>*> fitvec;

};
#endif
