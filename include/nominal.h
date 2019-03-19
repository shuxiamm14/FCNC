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
   const double fakeSFs[4][4] = {
      {1.028254, 0.060939, 2.842907, 0.802803},   //1prong <35
      {0.770841, 0.524360, 2.233151, 0.769241},   //1prong >35
      {1.157861, 0.792569, 1.349050, 1.426554},   //3prong <35
      {0.818782, 0.614790, 5.756198, 0.489836}    //3prong >35
   };

   bool dofcnc;
   Int_t ierflg;
   bool dumptruth;
   double nonfcncmatched;
   double fcncmatched;
   double leptonicw;
   bool fcnc;
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
   float wmass    ;
   float t2mass   ;
   float tautaumass;
   TFile *outputtreefile;
   histSaver *fcnc_plots;
   histSaver *fake_plots;
   histSaver *fake_notau_plots;

   applyTF m_applyTF;
   vector < TLorentzVector > ljets_v;
   fstream filetruth[6][2];
   Double_t arglist[10];
   vector<TString> fcnc_regions;
   int fcnc_nregions;
   TString **fake_regions;
   int fake_nregions;
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
   bool SelectTLepid(int id);
   static void printv(TLorentzVector v);
   int leading_b = -1 ;
   int leading_ljet = -1 ;
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
