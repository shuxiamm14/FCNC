#ifndef NOMINAL
#define NOMINAL
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
// Header file for the classes stored in the TTree if any.

#ifndef NO_TMINUIT
static TMinuit* gM = 0;
#endif
const double btag70wt = 0.8303;

class nominal {
public :
  std::map<TString,bool> dobwp;
  std::map<TString,bool> dovetobwp;
  bool dumpeventnumber;
  TString SystematicsName = "NOMINAL";
// Fixed size dimensions of array or collections stored in the TTree if any.
  const double btagwpCut[4]={0.94,0.83,0.64,0.11};
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

  static RooRealVar  _dR_;
  static RooRealVar  _m1_;
  static RooRealVar  _w1_;
  static RooGaussian _gaus_;
  static RooRealVar  _m2_;
  static RooRealVar  _w2_;
  static RooLandau   _land_;
  static RooRealVar  _fr1_;
  static RooAddPdf   _pdf_;

  static int GeV;
  std::vector<TString> plotNPs;
  Int_t ierflg;
  int ifill = 0;
  bool dumptruth;
  double nonfcncmatched;
  double fcncmatched;
  double leptonicw;
  bool fcnc;
  bool doBDT;
  bool dofit;
  double BDTG_train;
  double BDTG_test;
  int debug;
  bool dosys;
  int reduce;
  bool initdata;
  bool initttbar;
  bool dohist;
  int version;
  float pt_b;
  float pt_ljet;
  float taulmass;
  float t1mass;
  float drlbditau;
  float mtw;
  float tau_pt_ss;
  float tau_pt_os;
  float etamax;
  float drltau  ;
  float drtauj  ;
  float drtautau;
  float wmass   ;
  float t2mass  ;
  float tautaumass;
  float etmiss = 0;
  float dphitauetmiss = 0;
  float phicent = 0;
  float chi2;
  float allmass = 0;
  float allpz = 0;
  float mjjmin;
  float drlb;
  float drtaub;
  int nljet = 0;
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
  Double_t arglist[10];
  std::vector<TString> fcnc_regions;
  std::vector<TString> fake_regions;
  std::vector<TString> fake_regions_notau;
  int fcnc_nregions;
  int fake_nregions;
  int fake_nregions_notau;
  bool writetree = 1;
  TString bwps[4] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
  TString ptbin[2] = {"below35","above35"};
  std::map<TString, bool> ifregions;
  Double_t _lum = 80.;
  nominal();
  virtual ~nominal();
  void plot();
  std::map<TString, TTree*> outputtree;
  void init_dsid();
  void addweights(double weight, TString name);
  void saveweightslist(TString filename);
  void readTFmeanstd(TString filename);
  TMinuit* initgM();
  void initMVA(TString fcnc_region);
  void dumpTruth(int part);
  void readweightsysmap(int dsid,TString framework);
  TLorentzVector vectorPtEtaPhiE(std::vector<float> vec);
  virtual std::vector<int> findcjet(TString channel, std::vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, std::vector<TLorentzVector> taus);
  virtual std::vector<int> findcjetML(TString channel, std::vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, std::vector<TLorentzVector> taus, int part);
  std::vector<int> findwpair(std::vector<TLorentzVector> lightjets, int cjet);
  static Float_t getHadTauProb(Float_t _dR, Float_t _p);
  Double_t phi_centrality(Double_t aPhi, Double_t bPhi, Double_t cPhi);
  void finalise_sample();
  static  void    fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
  void fillhist(histSaver *plots, TString region, int nprong, TString sample, int ptbin, float taubtag, TString NP);
  void fill_notau(TString region, TString sample, TString NP);
  bool SelectTLepid(int id);
  void calcfakesf(std::vector<int> origin, std::vector<float> pt, std::vector<int> prong);
  void calcfakesf_pdg(std::vector<int> originpdg, std::vector<float> pt, std::vector<int> prong);
  void defGeV(int _GeV);
  virtual void init_reduce1(){ printf("WARNING: virtual function init_reduce1() is used\n");};
  virtual void init_reduce2(){ printf("WARNING: virtual function init_reduce2() is used\n");};
  virtual void init_hist(TString histfilename){ printf("WARNING: virtual function init_hist is used\n");};
  virtual void Loop(TTree*inputtree, TString samplename, float globalweight){ printf("WARNING: virtual function Loop is used\n");};
  virtual void init_sample(TString sample, TString sampletitle){ printf("WARNING: virtual function init_sample is used\n");};
  virtual void constructwmatchmap(TTree *tree){ printf("WARNING: virtual function constructwmatchmap is used\n");};
  static void printv(TLorentzVector v);
  int leading_b = -1 ;
  int leading_ljet = -1 ;
  std::vector<float> *weight_mc_v;
  std::vector<double>           *weights;
  std::vector<int>    ljet_indice;
  std::vector<float>  *neutrino_pt;
  std::vector<float>  *neutrino_eta;
  std::vector<float>  *neutrino_phi;
  std::vector<float>  *neutrino_m;
  std::vector<float>  *tau_pt;
  std::vector<float>  *tau_eta;
  std::vector<float>  *tau_phi;
  std::vector<float>  *tau_charge;
  TLorentzVector bjet_v;
  TLorentzVector cjet_v;
  std::vector<TLorentzVector> taus_v;
  TLorentzVector lep_v;
  TVector3 mets;
  TVector3 truth_mets;
  TList forFit;
  float      t2vismass;
  float      t1vismass;
  float      ttvismass;
  float      tautauvispt;
  float      weight;
  float      x1fit;
  float      x2fit;
  float      drtaujmin;
  float      mtaujmin;
  float      tau_pt_0;
  float      tau_pt_1;
};
#endif
