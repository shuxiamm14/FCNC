#include "applyTF.h"
#include <TROOT.h>
#include <TChain.h>
#include "histSaver.h"
// Header file for the classes stored in the TTree if any.
#include <vector>
TMinuit* gM = 0;

const double btag70wt = 0.8303;

class nominal {
public :

// Fixed size dimensions of array or collections stored in the TTree if any.
   const double btagwpCut[4]={0.94,0.83,0.64,0.11};
   double fakeSFs[4][4] = {
      {1.028254, 0.060939, 2.842907, 0.802803},   //1prong <35
      {0.770841, 0.524360, 2.233151, 0.769241},   //1prong >35
      {1.157861, 0.792569, 1.349050, 1.426554},   //3prong <35
      {0.818782, 0.614790, 5.756198, 0.489836}    //3prong >35
   };
   applyTF m_applyTF;
   vector < TLorentzVector > ljets_v;
   fstream filetruth[6][2];
   bool dofcnc = 0;
   Double_t arglist[10];
   Int_t ierflg = 0;
   bool dumptruth = 0;
   vector<TString> fcnc_regions;
   int fcnc_nregions;
   TString **fake_regions;
   int fake_nregions;
   double nonfcncmatched = 0;
   double fcncmatched = 0;
   double leptonicw = 0;
   bool fcnc = 0;
   bool writetree = 1;
   TString bwps[4] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
   TString ptbin[2] = {"below35","above35"};
   map<TString, bool> ifregions;
   Double_t _lum = 80.;
   int debug = 0;
   bool dosys = 0;
   int reduce = 0;
   nominal();
   virtual ~nominal();
   void plot(TFile *outputfile);
   bool initdata = 0;
   bool initttbar = 0;
   bool doseppt = 0;
   bool dohist = 0;
   int version = 0;
   TFile *outputtreefile = 0;
   map<TString, TTree*> outputtree;
   void readTFmeanstd(TString filename);
   void initgM();
   void dumpTruth(int part);
   TLorentzVector vectorPtEtaPhiE(vector<float> vec);
   virtual void     Init(TTree *tree){};
   void definetree(TTree *tree){};
   virtual vector<int> findcjet(TString channel, vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus);
   virtual vector<int> findcjetML(TString channel, vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus, int part);
   vector<int> findwpair(vector<TLorentzVector> lightjets, int cjet);

   void finalise_sample();
   static  void     fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
   void fill_fake(TString region, int nprong, TString sample, int ptbin, float taubtag);
   void fill_fcnc(TString region, int nprong, TString sample, int ptbin, float taubtag);
   void fill_notau(TString region, TString sample);
   void init_sample(TString sample, TString sampletitle);
   bool SelectTLepid(int id);
   static void printv(TLorentzVector v);
   int leading_b = -1 ;
   int leading_ljet = -1 ;
   float pt_b = 0;
   float pt_ljet = 0;
   float taulmass = 0;
   float t1mass = 0;
   float drlbditau = 0;
   float mtw = 0;
   float tau_pt_ss = 0;
   float tau_pt_os = 0;
   float etamax = 0;
   float drltau   = 0;
   float drtauj   = 0;
   float drtautau = 0;
   float wmass     = 0;
   float t2mass    = 0;
   float tautaumass = 0;
   vector<int>     ljet_indice;
   vector<float>   *neutrino_pt;
   vector<float>   *neutrino_eta;
   vector<float>   *neutrino_phi;
   vector<float>   *neutrino_m;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<float>   *tau_charge;
   TLorentzVector bjet_v;
   TLorentzVector cjet_v;
   vector<TLorentzVector> taus_v;
   TLorentzVector lep_v;
   TVector3 mets;
   TVector3 truth_mets;
   TList forFit;
   histSaver *fcnc_plots = 0;
   histSaver *fake_plots = 0;
   histSaver *fake_notau_plots = 0;
   Double_t        t2vismass;
   Double_t        t1vismass;
   Double_t        ttvismass;
   Double_t        tautauvispt;
   Double_t        weight;
   Double_t        fakeSF;
   Double_t        x1fit;
   Double_t        x2fit;
   Double_t        drtaujmin;
};
