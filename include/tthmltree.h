#include "nominal.h"
#include "truthpart.h"
#ifndef TTHMLTREE
#define TTHMLTREE
class tthmltree : public nominal{
public:
   tthmltree();
   void init_sample(TString sample, TString sampletitle);
   void init_hist(TString outputhistfile);
   static Float_t getLepTauProb(Float_t _dR, Float_t _minv, Float_t _p) ;
   void initialize_fit(const char* input);
   static void fillOverFlow(TH2F* h);
   static Float_t eval(const Float_t x, const Float_t y, const TH2F* h);
   static void fillOverFlow(TH1F* h);
   void constructTruth();
   truthpart* truthmatch(TLorentzVector *p4);
   void constructwmatchmap(TTree *tree);
   bool passRegionCut();
   std::vector<truthpart*> truthparticles;


   std::vector<float>   *m_truth_m;
   std::vector<float>   *m_truth_pt;
   std::vector<float>   *m_truth_eta;
   std::vector<float>   *m_truth_phi;
   std::vector<float>   *m_truth_e;
   std::vector<int>     *m_truth_pdgId;
   std::vector<int>     *m_truth_status;
   std::vector<int>     *m_truth_barcode;
   std::vector<std::vector<int> > *m_truth_parents;
   std::vector<std::vector<int> > *m_truth_children;

   //===========================These should be overriden in different versions===========================

   virtual void dumpTruth(int ipart) { printf("Warning: virtual function dumpTruth(int ipart) is used in class tthmltree\n"); };
   virtual bool passBasicCut() { printf("Warning: virtual function passBasicCut() is used in class tthmltree\n"); return true;};
   virtual void defineObject() { printf("Warning: virtual function defineObject() is used in class tthmltree\n"); };
   virtual void calcGeneralWeight() { printf("Warning: virtual function calcGeneralWeight() is used in class tthmltree\n"); };
   float calcRegionSF(TString region){return 1;};
   virtual void defineLepTruth() { printf("Warning: virtual function defineLepTruth() is used in class tthmltree\n"); };
   virtual void defineTauTruth() { printf("Warning: virtual function defineTauTruth() is used in class tthmltree\n"); };
   virtual bool SelectTLepid(int id) { printf("Warning: virtual function SelectTLepid(int id) is used in class tthmltree\n"); return 1;};
   virtual bool IsoLepid(int id) { printf("Warning: virtual function IsoLepid(int id) is used in class tthmltree\n");  return 1;};
   virtual bool addWeightSys() { printf("Warning: virtual function addWeightSys() is used in class tthmltree\n");  return 1;};
   virtual void init(TTree*tree) { printf("Warning: virtual function init(TTree*tree) is used in class tthmltree\n"); };
};
#endif
