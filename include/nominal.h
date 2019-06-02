#include "applyTF.h"
#include <TROOT.h>
#include <TChain.h>
#include "histSaver.h"

#include "RooRealVar.h"
#include "RooGaussian.h"
#include "RooLandau.h"
#include "RooAddPdf.h"


// Header file for the classes stored in the TTree if any.
#include <vector>
TMinuit* gM = 0;

const double btag70wt = 0.8303;

class nominal {
public :
  map<TString,bool> dobwp;
  map<TString,bool> dovetobwp;
// Fixed size dimensions of array or collections stored in the TTree if any.
  const double btagwpCut[4]={0.94,0.83,0.64,0.11};
  //const double fakeSFs[4][4] = {
  //  {1.028254, 0.060939, 2.842907, 0.802803},  //1prong <35
  //  {0.770841, 0.524360, 2.233151, 0.769241},  //1prong >35
  //  {1.157861, 0.792569, 1.349050, 1.426554},  //3prong <35
  //  {0.818782, 0.614790, 5.756198, 0.489836}   //3prong >35
  //};
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
  
  map<TString, TMVA::Reader*> reader;

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
  vector<int> plotNPs;
  Int_t ierflg;
  bool dumptruth;
  double nonfcncmatched;
  double fcncmatched;
  double leptonicw;
  bool fcnc;
  bool doBDT;
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

  TFile *outputtreefile;
  vector<histSaver*> fcnc_plots;
  histSaver *fake_plots;
  histSaver *fake_notau_plots;

  applyTF m_applyTF;
  vector < TLorentzVector > ljets_v;
  vector < float > ljets_score;
  fstream filetruth[6][2];
  Double_t arglist[10];
  vector<TString> fcnc_regions;
  vector<TString> fake_regions;
  vector<TString> fake_regions_notau;
  int fcnc_nregions;
  int fake_nregions;
  int fake_nregions_notau;
  bool writetree = 1;
  TString bwps[4] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
  TString ptbin[2] = {"below35","above35"};
  map<TString, bool> ifregions;
  Double_t _lum = 80.;
  nominal();
  virtual ~nominal();
  void plot();
  map<TString, TTree*> outputtree;
  void readTFmeanstd(TString filename);
  TMinuit* initgM();
  void initMVA(TString fcnc_region);
  void dumpTruth(int part);
  TLorentzVector vectorPtEtaPhiE(vector<float> vec);
  virtual void    Init(TTree *tree){};
  void definetree(TTree *tree){};
  virtual vector<int> findcjet(TString channel, vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus);
  virtual vector<int> findcjetML(TString channel, vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus, int part);
  vector<int> findwpair(vector<TLorentzVector> lightjets, int cjet);
  static Float_t getHadTauProb(Float_t _dR, Float_t _p);
  Double_t phi_centrality(Double_t aPhi, Double_t bPhi, Double_t cPhi);
  void finalise_sample();
  static  void    fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
  void fill_fake(TString region, int nprong, TString sample, int ptbin, float taubtag);
  void fill_fcnc(TString region, int nprong, TString sample, int ptbin, float taubtag, int iNP);
  void fill_notau(TString region, TString sample);
  bool SelectTLepid(int id);
  void defGeV(int _GeV);
  static void printv(TLorentzVector v);
  int leading_b = -1 ;
  int leading_ljet = -1 ;
  vector<double>           *weights;
  vector<int>    ljet_indice;
  vector<float>  *neutrino_pt;
  vector<float>  *neutrino_eta;
  vector<float>  *neutrino_phi;
  vector<float>  *neutrino_m;
  vector<float>  *tau_pt;
  vector<float>  *tau_eta;
  vector<float>  *tau_phi;
  vector<float>  *tau_charge;
  TLorentzVector bjet_v;
  TLorentzVector cjet_v;
  vector<TLorentzVector> taus_v;
  TLorentzVector lep_v;
  TVector3 mets;
  TVector3 truth_mets;
  TList forFit;
  float      t2vismass;
  float      t1vismass;
  float      ttvismass;
  float      tautauvispt;
  float      weight;
  float      fakeSF;
  float      x1fit;
  float      x2fit;
  float      drtaujmin;
  float      mtaujmin;
  float      tau_pt_0;
  float      tau_pt_1;
};
