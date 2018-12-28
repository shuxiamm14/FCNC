
#include <TROOT.h>
#include <TChain.h>
#include "histSaver.h"
// Header file for the classes stored in the TTree if any.
#include <vector>

class nominal {
public :

// Fixed size dimensions of array or collections stored in the TTree if any.
   const double btagwpCut[4]={0.94,0.83,0.64,0.11};
   TString bwps[4] = {"btagwp60","btagwp70","btagwp77","btagwp85"};
   TString ptbin[2] = {"below35","above35"};
   Double_t _lum = 80.;
   int debug = 0;
   bool dosys = 1;
   int reduce = 0;
   nominal();
   virtual ~nominal();
   void plot();
   bool initdata = 0;
   bool initttbar = 0;
   int version = 6;
   TFile *outputtreefile;
   map<TString, TTree*> outputtree;
   virtual void     Init(TTree *tree);
   virtual void     Loop(TTree *inputtree, TString sample, int _reduce);
   virtual int      findcjet();
   void finalise_sample();
   static  void     fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
   void fill_tau(TString region, int nprong, TString sample, int ptbin);
   void fill_notau(TString region, TString sample);
   void init_sample(TString sample, TString sampletitle);
   void definetree(TTree *tree);
   bool SelectTLepid(int id);
   static void printv(TLorentzVector v);
   int leading_b = -1 ;
   int leading_ljet = -1 ;
   float pt_b = 0;
   float pt_ljet = 0;
   float taulmass = 0;
   float t1_mass = 0;
   float Wmass     = 0;
   float t2_mass    = 0;
   float higgs_mass = 0;
   int cjet_index = 0;
   int wjet1_index = 0;
   int wjet2_index = 0;
   TLorentzVector bjet_v;
   TLorentzVector cjet_v;
   vector<TLorentzVector> taus_v;
   TLorentzVector lep_v;
   TVector3 mets;
   TVector3 truth_mets;
   TList forFit;

   histSaver *tau_plots = 0;
   histSaver *notau_plots = 0;

   Double_t        weight;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   UInt_t          hasBadMuon;
   vector<float>   *neutrino_pt;
   vector<float>   *neutrino_eta;
   vector<float>   *neutrino_phi;
   vector<float>   *neutrino_m;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<float>   *tau_charge;
   Float_t         met_met;
   Float_t         met_phi;
   Int_t           triggers;
   Int_t           loose;
   Char_t          HLT_mu40;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_mu26_imedium;
   Char_t          HLT_mu24_ivarmedium;
   Char_t          HLT_mu24_ivarloose;
   Char_t          HLT_mu24_imedium;
   Char_t          HLT_mu24;
   Char_t          HLT_mu20_mu8noL1;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_mu18_mu8noL1;
   Char_t          HLT_mu14_ivarloose_tau25_medium1_tracktwo;
   Char_t          HLT_e7_medium_mu24;
   Char_t          HLT_e17_lhmedium_tau25_medium1_tracktwo;
   Char_t          HLT_e17_lhloose_mu14;
   Char_t          HLT_e140_loose;
   Char_t          HLT_mu22_mu8noL1;
   Char_t          HLT_2e17_lhvloose_nod0;
   Char_t          HLT_e17_lhloose_2e9_lhloose;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_mu50;
   Char_t          HLT_e17_lhloose;
   Char_t          HLT_2e12_lhloose_L12EM10VH;
   Char_t          HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo;
   Char_t          HLT_2e12_loose_L12EM10VH;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_e60_medium;
   Char_t          HLT_e12_loose;
   Char_t          HLT_mu18;
   Char_t          HLT_e140_lhloose;
   Char_t          HLT_e5_lhloose;
   Char_t          HLT_2e17_lhvloose_nod0_L12EM15VHI;
   Char_t          HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo;
   Char_t          HLT_e24_lhmedium_nod0_L1EM20VH;
   Char_t          HLT_2e24_lhvloose_nod0;
   Char_t          HLT_e24_tight_iloose;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_2e12_lhvloose_nod0_L12EM10VH;
   Char_t          HLT_2mu10;
   Char_t          HLT_e12_lhloose;
   Char_t          HLT_2mu14;
   Char_t          HLT_e17_loose;
   Char_t          HLT_e17_loose_mu14;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_mu24_iloose;
   Char_t          HLT_e7_lhmedium_mu24;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_e24_lhmedium_iloose_L1EM18VH;
   Char_t          HLT_e24_lhmedium_L1EM18VH;
   Char_t          HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1;
   Char_t          HLT_e24_lhtight_iloose;
   Char_t          HLT_mu14;
   Char_t          HLT_mu10;
   Char_t          HLT_e24_lhtight_iloose_L1EM20VH;
   Char_t          HLT_e24_lhtight_ivarloose;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_e24_lhtight_nod0_ivarloose;
   Char_t          HLT_mu14_tau25_medium1_tracktwo;
   Char_t          HLT_e24_medium_L1EM20VHI_mu8noL1;
   Char_t          HLT_e24_tight_iloose_L1EM20VH;
   Char_t          HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;
   Char_t          HLT_e26_lhtight_iloose;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_2e15_lhvloose_nod0_L12EM13VH;
   Char_t          HLT_e26_tight_iloose;
   Char_t          HLT_e7_lhmedium_nod0_mu24;
   Char_t          HLT_e5_loose;
   Char_t          HLT_e300_etcut;
   Double_t        mcWeightOrg;
   vector<float>   *mcEventWeights;
   Double_t        pileupEventWeight_090;
   Double_t        MV2c10_60_EventWeight;
   Double_t        MV2c10_70_EventWeight;
   Double_t        MV2c10_77_EventWeight;
   Double_t        MV2c10_85_EventWeight;
   Double_t        MV2c10_Continuous_EventWeight;
   Double_t        JVT_EventWeight;
   Double_t        DL1_60_EventWeight;
   Double_t        DL1_70_EventWeight;
   Double_t        DL1_77_EventWeight;
   Double_t        DL1_85_EventWeight;
   Double_t        DL1_Continuous_EventWeight;
   Double_t        pileupEventWeight_UP;
   Double_t        pileupEventWeight_DOWN;
   Double_t        bTagSF_weight_MV2c10_FixedCutBEff_70;
   Double_t        bTagSF_weight_DL1_FixedCutBEff_70;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up;
   Float_t         bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B0_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B0_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B1_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B1_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B2_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B2_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B3_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B3_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B4_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B4_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B5_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B5_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B6_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B6_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B7_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B7_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B8_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_B8_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_C0_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_C0_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_C1_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_C1_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_C2_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_C2_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light0_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light0_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light1_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light1_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light2_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light2_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light3_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_Light3_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up;
   Float_t         bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down;
   Int_t           lep_firstEgMotherPdgId_0;
   Int_t           lep_firstEgMotherTruthType_0;
   Int_t           lep_firstEgMotherTruthOrigin_0;
   Int_t           lep_firstEgMotherPdgId_1;
   Int_t           lep_firstEgMotherTruthType_1;
   Int_t           lep_firstEgMotherTruthOrigin_1;
   Int_t           lep_firstEgMotherPdgId_2;
   Int_t           lep_firstEgMotherTruthType_2;
   Int_t           lep_firstEgMotherTruthOrigin_2;
   Int_t           lep_firstEgMotherPdgId_3;
   Int_t           lep_firstEgMotherTruthType_3;
   Int_t           lep_firstEgMotherTruthOrigin_3;
   Int_t           lep_firstEgMotherPdgId_4;
   Int_t           lep_firstEgMotherTruthType_4;
   Int_t           lep_firstEgMotherTruthOrigin_4;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   Double_t        bTagSF_weight_MV2c10_Continuous;
   Double_t        bTagSF_weight_DL1_Continuous;
   Float_t         bTagSF_weight_MV2c10_Continuous_B0_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B0_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B1_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B1_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B2_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B2_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B3_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B3_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B4_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B4_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B5_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B5_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B6_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B6_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B7_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B7_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B8_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B8_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B9_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B9_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B10_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B10_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B11_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B11_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B12_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B12_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B13_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B13_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B14_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B14_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B15_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B15_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B16_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B16_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B17_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B17_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B18_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B18_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B19_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B19_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B20_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B20_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B21_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B21_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B22_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B22_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B23_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B23_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B24_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B24_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B25_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B25_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B26_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B26_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B27_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B27_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B28_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B28_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B29_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B29_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B30_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B30_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B31_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B31_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B32_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B32_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B33_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B33_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B34_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B34_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B35_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B35_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B36_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B36_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B37_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B37_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B38_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B38_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B39_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B39_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B40_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B40_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B41_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B41_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B42_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B42_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B43_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B43_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_B44_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_B44_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C0_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C0_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C1_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C1_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C2_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C2_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C3_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C3_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C4_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C4_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C5_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C5_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C6_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C6_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C7_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C7_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C8_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C8_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C9_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C9_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C10_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C10_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C11_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C11_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C12_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C12_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C13_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C13_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_C14_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_C14_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light0_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light0_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light1_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light1_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light2_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light2_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light3_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light3_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light4_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light4_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light5_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light5_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light6_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light6_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light7_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light7_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light8_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light8_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light9_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light9_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light10_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light10_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light11_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light11_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light12_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light12_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light13_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light13_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light14_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light14_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light15_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light15_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light16_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light16_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light17_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light17_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light18_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light18_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light19_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light19_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light20_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light20_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light21_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light21_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light22_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light22_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light23_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light23_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light24_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light24_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light25_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light25_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light26_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light26_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light27_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light27_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light28_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light28_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light29_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light29_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light30_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light30_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light31_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light31_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light32_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light32_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light33_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light33_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light34_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light34_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light35_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light35_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light36_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light36_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light37_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light37_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light38_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light38_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light39_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light39_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light40_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light40_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light41_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light41_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light42_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light42_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light43_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light43_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light44_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light44_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light45_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light45_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light46_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light46_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light47_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light47_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light48_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light48_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light49_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light49_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light50_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light50_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light51_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light51_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light52_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light52_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light53_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light53_down;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light54_up;
   Float_t         bTagSF_weight_MV2c10_Continuous_Light54_down;
   Float_t         bTagSF_weight_DL1_Continuous_B0_up;
   Float_t         bTagSF_weight_DL1_Continuous_B0_down;
   Float_t         bTagSF_weight_DL1_Continuous_B1_up;
   Float_t         bTagSF_weight_DL1_Continuous_B1_down;
   Float_t         bTagSF_weight_DL1_Continuous_B2_up;
   Float_t         bTagSF_weight_DL1_Continuous_B2_down;
   Float_t         bTagSF_weight_DL1_Continuous_B3_up;
   Float_t         bTagSF_weight_DL1_Continuous_B3_down;
   Float_t         bTagSF_weight_DL1_Continuous_B4_up;
   Float_t         bTagSF_weight_DL1_Continuous_B4_down;
   Float_t         bTagSF_weight_DL1_Continuous_B5_up;
   Float_t         bTagSF_weight_DL1_Continuous_B5_down;
   Float_t         bTagSF_weight_DL1_Continuous_B6_up;
   Float_t         bTagSF_weight_DL1_Continuous_B6_down;
   Float_t         bTagSF_weight_DL1_Continuous_B7_up;
   Float_t         bTagSF_weight_DL1_Continuous_B7_down;
   Float_t         bTagSF_weight_DL1_Continuous_B8_up;
   Float_t         bTagSF_weight_DL1_Continuous_B8_down;
   Float_t         bTagSF_weight_DL1_Continuous_B9_up;
   Float_t         bTagSF_weight_DL1_Continuous_B9_down;
   Float_t         bTagSF_weight_DL1_Continuous_B10_up;
   Float_t         bTagSF_weight_DL1_Continuous_B10_down;
   Float_t         bTagSF_weight_DL1_Continuous_B11_up;
   Float_t         bTagSF_weight_DL1_Continuous_B11_down;
   Float_t         bTagSF_weight_DL1_Continuous_B12_up;
   Float_t         bTagSF_weight_DL1_Continuous_B12_down;
   Float_t         bTagSF_weight_DL1_Continuous_B13_up;
   Float_t         bTagSF_weight_DL1_Continuous_B13_down;
   Float_t         bTagSF_weight_DL1_Continuous_B14_up;
   Float_t         bTagSF_weight_DL1_Continuous_B14_down;
   Float_t         bTagSF_weight_DL1_Continuous_B15_up;
   Float_t         bTagSF_weight_DL1_Continuous_B15_down;
   Float_t         bTagSF_weight_DL1_Continuous_B16_up;
   Float_t         bTagSF_weight_DL1_Continuous_B16_down;
   Float_t         bTagSF_weight_DL1_Continuous_B17_up;
   Float_t         bTagSF_weight_DL1_Continuous_B17_down;
   Float_t         bTagSF_weight_DL1_Continuous_B18_up;
   Float_t         bTagSF_weight_DL1_Continuous_B18_down;
   Float_t         bTagSF_weight_DL1_Continuous_B19_up;
   Float_t         bTagSF_weight_DL1_Continuous_B19_down;
   Float_t         bTagSF_weight_DL1_Continuous_B20_up;
   Float_t         bTagSF_weight_DL1_Continuous_B20_down;
   Float_t         bTagSF_weight_DL1_Continuous_B21_up;
   Float_t         bTagSF_weight_DL1_Continuous_B21_down;
   Float_t         bTagSF_weight_DL1_Continuous_B22_up;
   Float_t         bTagSF_weight_DL1_Continuous_B22_down;
   Float_t         bTagSF_weight_DL1_Continuous_B23_up;
   Float_t         bTagSF_weight_DL1_Continuous_B23_down;
   Float_t         bTagSF_weight_DL1_Continuous_B24_up;
   Float_t         bTagSF_weight_DL1_Continuous_B24_down;
   Float_t         bTagSF_weight_DL1_Continuous_B25_up;
   Float_t         bTagSF_weight_DL1_Continuous_B25_down;
   Float_t         bTagSF_weight_DL1_Continuous_B26_up;
   Float_t         bTagSF_weight_DL1_Continuous_B26_down;
   Float_t         bTagSF_weight_DL1_Continuous_B27_up;
   Float_t         bTagSF_weight_DL1_Continuous_B27_down;
   Float_t         bTagSF_weight_DL1_Continuous_B28_up;
   Float_t         bTagSF_weight_DL1_Continuous_B28_down;
   Float_t         bTagSF_weight_DL1_Continuous_B29_up;
   Float_t         bTagSF_weight_DL1_Continuous_B29_down;
   Float_t         bTagSF_weight_DL1_Continuous_B30_up;
   Float_t         bTagSF_weight_DL1_Continuous_B30_down;
   Float_t         bTagSF_weight_DL1_Continuous_B31_up;
   Float_t         bTagSF_weight_DL1_Continuous_B31_down;
   Float_t         bTagSF_weight_DL1_Continuous_B32_up;
   Float_t         bTagSF_weight_DL1_Continuous_B32_down;
   Float_t         bTagSF_weight_DL1_Continuous_B33_up;
   Float_t         bTagSF_weight_DL1_Continuous_B33_down;
   Float_t         bTagSF_weight_DL1_Continuous_B34_up;
   Float_t         bTagSF_weight_DL1_Continuous_B34_down;
   Float_t         bTagSF_weight_DL1_Continuous_B35_up;
   Float_t         bTagSF_weight_DL1_Continuous_B35_down;
   Float_t         bTagSF_weight_DL1_Continuous_B36_up;
   Float_t         bTagSF_weight_DL1_Continuous_B36_down;
   Float_t         bTagSF_weight_DL1_Continuous_B37_up;
   Float_t         bTagSF_weight_DL1_Continuous_B37_down;
   Float_t         bTagSF_weight_DL1_Continuous_B38_up;
   Float_t         bTagSF_weight_DL1_Continuous_B38_down;
   Float_t         bTagSF_weight_DL1_Continuous_B39_up;
   Float_t         bTagSF_weight_DL1_Continuous_B39_down;
   Float_t         bTagSF_weight_DL1_Continuous_B40_up;
   Float_t         bTagSF_weight_DL1_Continuous_B40_down;
   Float_t         bTagSF_weight_DL1_Continuous_B41_up;
   Float_t         bTagSF_weight_DL1_Continuous_B41_down;
   Float_t         bTagSF_weight_DL1_Continuous_B42_up;
   Float_t         bTagSF_weight_DL1_Continuous_B42_down;
   Float_t         bTagSF_weight_DL1_Continuous_B43_up;
   Float_t         bTagSF_weight_DL1_Continuous_B43_down;
   Float_t         bTagSF_weight_DL1_Continuous_B44_up;
   Float_t         bTagSF_weight_DL1_Continuous_B44_down;
   Float_t         bTagSF_weight_DL1_Continuous_C0_up;
   Float_t         bTagSF_weight_DL1_Continuous_C0_down;
   Float_t         bTagSF_weight_DL1_Continuous_C1_up;
   Float_t         bTagSF_weight_DL1_Continuous_C1_down;
   Float_t         bTagSF_weight_DL1_Continuous_C2_up;
   Float_t         bTagSF_weight_DL1_Continuous_C2_down;
   Float_t         bTagSF_weight_DL1_Continuous_C3_up;
   Float_t         bTagSF_weight_DL1_Continuous_C3_down;
   Float_t         bTagSF_weight_DL1_Continuous_C4_up;
   Float_t         bTagSF_weight_DL1_Continuous_C4_down;
   Float_t         bTagSF_weight_DL1_Continuous_C5_up;
   Float_t         bTagSF_weight_DL1_Continuous_C5_down;
   Float_t         bTagSF_weight_DL1_Continuous_C6_up;
   Float_t         bTagSF_weight_DL1_Continuous_C6_down;
   Float_t         bTagSF_weight_DL1_Continuous_C7_up;
   Float_t         bTagSF_weight_DL1_Continuous_C7_down;
   Float_t         bTagSF_weight_DL1_Continuous_C8_up;
   Float_t         bTagSF_weight_DL1_Continuous_C8_down;
   Float_t         bTagSF_weight_DL1_Continuous_C9_up;
   Float_t         bTagSF_weight_DL1_Continuous_C9_down;
   Float_t         bTagSF_weight_DL1_Continuous_C10_up;
   Float_t         bTagSF_weight_DL1_Continuous_C10_down;
   Float_t         bTagSF_weight_DL1_Continuous_C11_up;
   Float_t         bTagSF_weight_DL1_Continuous_C11_down;
   Float_t         bTagSF_weight_DL1_Continuous_C12_up;
   Float_t         bTagSF_weight_DL1_Continuous_C12_down;
   Float_t         bTagSF_weight_DL1_Continuous_C13_up;
   Float_t         bTagSF_weight_DL1_Continuous_C13_down;
   Float_t         bTagSF_weight_DL1_Continuous_C14_up;
   Float_t         bTagSF_weight_DL1_Continuous_C14_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light0_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light0_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light1_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light1_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light2_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light2_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light3_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light3_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light4_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light4_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light5_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light5_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light6_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light6_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light7_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light7_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light8_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light8_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light9_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light9_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light10_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light10_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light11_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light11_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light12_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light12_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light13_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light13_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light14_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light14_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light15_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light15_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light16_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light16_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light17_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light17_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light18_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light18_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light19_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light19_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light20_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light20_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light21_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light21_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light22_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light22_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light23_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light23_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light24_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light24_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light25_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light25_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light26_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light26_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light27_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light27_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light28_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light28_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light29_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light29_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light30_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light30_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light31_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light31_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light32_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light32_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light33_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light33_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light34_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light34_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light35_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light35_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light36_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light36_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light37_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light37_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light38_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light38_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light39_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light39_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light40_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light40_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light41_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light41_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light42_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light42_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light43_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light43_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light44_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light44_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light45_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light45_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light46_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light46_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light47_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light47_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light48_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light48_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light49_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light49_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light50_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light50_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light51_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light51_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light52_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light52_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light53_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light53_down;
   Float_t         bTagSF_weight_DL1_Continuous_Light54_up;
   Float_t         bTagSF_weight_DL1_Continuous_Light54_down;
   vector<int>     *m_jet_tagWeightBin;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepEffTrigTight_MU_SF_Trigger_STAT_DOWN;
   Double_t        JVT_EventWeight_UP;
   Double_t        JVT_EventWeight_DOWN;
   vector<float>   *m_truth_m;
   vector<float>   *m_truth_pt;
   vector<float>   *m_truth_eta;
   vector<float>   *m_truth_phi;
   vector<float>   *m_truth_e;
   vector<int>     *m_truth_pdgId;
   vector<int>     *m_truth_status;
   vector<int>     *m_truth_barcode;
   vector<vector<int> > *m_truth_parents;
   vector<vector<int> > *m_truth_children;
   vector<float>   *m_mcevt_pdf_X1;
   vector<float>   *m_mcevt_pdf_X2;
   vector<int>     *m_mcevt_pdf_PDGID1;
   vector<int>     *m_mcevt_pdf_PDGID2;
   vector<float>   *m_mcevt_pdf_Q;
   vector<float>   *m_mcevt_pdf_XF1;
   vector<float>   *m_mcevt_pdf_XF2;
   ULong64_t       EventNumber;
   UInt_t          RunNumber;
   UInt_t          lbn;
   UInt_t          bcid;
   Bool_t          passEventCleaning;
   UInt_t          backgroundFlags;
   Float_t         m_vxp_x;
   Float_t         m_vxp_y;
   Float_t         m_vxp_z;
   Double_t        SherpaNJetWeight;
   Double_t        nTruthJets_SherpaRwght;
   Double_t        higgs_pt;
   Double_t        higgs_eta;
   Double_t        higgs_phi;
   Double_t        higgs_E;
   Double_t        higgs_rapidity;
   Double_t        top_pt;
   Double_t        top_eta;
   Double_t        top_phi;
   Double_t        top_E;
   Double_t        antitop_pt;
   Double_t        antitop_eta;
   Double_t        antitop_phi;
   Double_t        antitop_E;
   Int_t           RunYear;
   Int_t           higgsDecayMode;
   UInt_t          mc_channel_number;
   Char_t          mc_isAFII;
   Double_t        mc_xSection;
   Double_t        mc_rawXSection;
   Double_t        mc_kFactor;
   Int_t           mc_showering;
   Float_t         averageIntPerXing_uncorr;
   Float_t         averageIntPerXing;
   Float_t         actualIntPerXing;
   ULong64_t       pileupHash;
   Int_t           m_vxp_n;
   Int_t           m_vxpu_n;
   Float_t         m_vx_density;
   Float_t         m_beam_posz;
   Float_t         m_beam_sigmaz;
   Char_t          m_hasMEphoton;
   Char_t          m_hasMEphoton_DRgt02_nonhad;
   Float_t         m_MEphoton_e;
   Float_t         m_MEphoton_pt;
   Float_t         m_MEphoton_eta;
   Float_t         m_MEphoton_phi;
   Int_t           m_MEphoton_mother_pdgId;
   Float_t         m_MEphoton_mother_e;
   Float_t         m_MEphoton_mother_pt;
   Float_t         m_MEphoton_mother_eta;
   Float_t         m_MEphoton_mother_phi;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_phi;
   Float_t         MET_RefFinal_sumet;
   Float_t         MET_RefFinal_softTrk_et;
   Float_t         MET_RefFinal_softTrk_phi;
   Float_t         MET_RefFinal_softClus_et;
   Float_t         MET_RefFinal_softClus_phi;
   Float_t         MET_Truth_px;
   Float_t         MET_Truth_py;
   Float_t         MET_Truth_phi;
   Float_t         MET_Truth_sumet;
   vector<float>   *vtx_x;
   vector<float>   *vtx_y;
   vector<float>   *vtx_z;
   vector<int>     *vtx_type;
   vector<int>     *vtx_numTrk;
   vector<char>    *electron_isolationLooseTrackOnly;
   vector<char>    *muon_isolationLooseTrackOnly;
   vector<char>    *electron_isolationLoose;
   vector<char>    *muon_isolationLoose;
   vector<char>    *electron_isolationGradient;
   vector<char>    *muon_isolationGradient;
   vector<char>    *electron_isolationGradientLoose;
   vector<char>    *muon_isolationGradientLoose;
   vector<char>    *electron_isolationFixedCutTightTrackOnly;
   vector<char>    *muon_isolationFixedCutTightTrackOnly;
   vector<char>    *electron_isolationFixedCutLoose;
   vector<char>    *muon_isolationFixedCutLoose;
   vector<char>    *electron_isolationFixedCutTight;
   vector<float>   *electron_pt;
   vector<float>   *electron_eta;
   vector<float>   *electron_EtaBE2;
   vector<float>   *electron_phi;
   vector<float>   *electron_E;
   vector<int>     *electron_ID;
   vector<float>   *electron_sigd0PV;
   vector<float>   *electron_z0SinTheta;
   vector<float>   *electron_topoetcone20;
   vector<float>   *electron_topoetcone30;
   vector<float>   *electron_topoetcone40;
   vector<float>   *electron_ptvarcone20;
   vector<float>   *electron_ptvarcone30;
   vector<float>   *electron_ptvarcone40;
   vector<char>    *electron_isLooseLH;
   vector<char>    *electron_isMediumLH;
   vector<char>    *electron_isTightLH;
   vector<char>    *electron_sharesTrk;
   vector<char>    *electron_passOR;
   vector<char>    *electron_isQMisID;
   vector<float>   *electron_ChargeIDBDTLoose;
   vector<float>   *electron_ChargeIDBDTMedium;
   vector<float>   *electron_ChargeIDBDTTight;
   vector<int>     *electron_match_HLT_2e12_lhloose_L12EM10VH;
   vector<int>     *electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH;
   vector<int>     *electron_match_HLT_2e12_loose_L12EM10VH;
   vector<int>     *electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH;
   vector<int>     *electron_match_HLT_2e17_lhvloose_nod0;
   vector<int>     *electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI;
   vector<int>     *electron_match_HLT_2e24_lhvloose_nod0;
   vector<int>     *electron_match_HLT_e120_lhloose;
   vector<int>     *electron_match_HLT_e12_lhloose;
   vector<int>     *electron_match_HLT_e12_loose;
   vector<int>     *electron_match_HLT_e140_lhloose;
   vector<int>     *electron_match_HLT_e140_lhloose_nod0;
   vector<int>     *electron_match_HLT_e140_loose;
   vector<int>     *electron_match_HLT_e17_lhloose;
   vector<int>     *electron_match_HLT_e17_lhloose_2e9_lhloose;
   vector<int>     *electron_match_HLT_e17_lhloose_mu14;
   vector<int>     *electron_match_HLT_e17_lhloose_nod0_mu14;
   vector<int>     *electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo;
   vector<int>     *electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo;
   vector<int>     *electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo;
   vector<int>     *electron_match_HLT_e17_loose;
   vector<int>     *electron_match_HLT_e17_loose_mu14;
   vector<int>     *electron_match_HLT_e24_lhmedium_L1EM18VH;
   vector<int>     *electron_match_HLT_e24_lhmedium_L1EM20VH;
   vector<int>     *electron_match_HLT_e24_lhmedium_iloose_L1EM18VH;
   vector<int>     *electron_match_HLT_e24_lhmedium_nod0_L1EM20VH;
   vector<int>     *electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1;
   vector<int>     *electron_match_HLT_e24_lhtight_iloose;
   vector<int>     *electron_match_HLT_e24_lhtight_iloose_L1EM20VH;
   vector<int>     *electron_match_HLT_e24_lhtight_ivarloose;
   vector<int>     *electron_match_HLT_e24_lhtight_nod0_ivarloose;
   vector<int>     *electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1;
   vector<int>     *electron_match_HLT_e24_tight_iloose;
   vector<int>     *electron_match_HLT_e24_tight_iloose_L1EM20VH;
   vector<int>     *electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;
   vector<int>     *electron_match_HLT_e26_lhtight_iloose;
   vector<int>     *electron_match_HLT_e26_lhtight_nod0_ivarloose;
   vector<int>     *electron_match_HLT_e26_tight_iloose;
   vector<int>     *electron_match_HLT_e300_etcut;
   vector<int>     *electron_match_HLT_e5_lhloose;
   vector<int>     *electron_match_HLT_e5_loose;
   vector<int>     *electron_match_HLT_e60_lhmedium;
   vector<int>     *electron_match_HLT_e60_lhmedium_nod0;
   vector<int>     *electron_match_HLT_e60_medium;
   vector<int>     *electron_match_HLT_e7_lhmedium_mu24;
   vector<int>     *electron_match_HLT_e7_lhmedium_nod0_mu24;
   vector<int>     *electron_match_HLT_e7_medium_mu24;
   vector<int>     *electron_nInnerPix;
   vector<int>     *electron_author;
   vector<float>   *electron_d0;
   vector<float>   *electron_z0;
   vector<float>   *electron_vz;
   vector<float>   *electron_deltaz0;
   vector<int>     *electron_truthOrigin;
   vector<int>     *electron_truthType;
   vector<int>     *electron_firstEgMotherPdgId;
   vector<float>   *electron_jetFitterComb;
   vector<short>   *electron_PromptLeptonInput_sv1_jf_ntrkv;
   vector<short>   *electron_PromptLeptonInput_TrackJetNTrack;
   vector<float>   *electron_PromptLeptonInput_DL1mu;
   vector<float>   *electron_PromptLeptonInput_DRlj;
   vector<float>   *electron_PromptLeptonInput_LepJetPtFrac;
   vector<float>   *electron_PromptLeptonInput_PtFrac;
   vector<float>   *electron_PromptLeptonInput_PtRel;
   vector<float>   *electron_PromptLeptonInput_ip2;
   vector<float>   *electron_PromptLeptonInput_ip3;
   vector<float>   *electron_PromptLeptonInput_rnnip;
   vector<float>   *electron_PromptLeptonIso_TagWeight;
   vector<float>   *electron_PromptLeptonVeto_TagWeight;
   vector<unsigned char> *electron_ambiguityType;
   vector<unsigned char> *electron_numberOfInnermostPixelLayerHits;
   vector<unsigned char> *electron_numberOfInnermostPixelLayerOutliers;
   vector<unsigned char> *electron_expectInnerPixelLayerHit;
   vector<float>   *muon_pt;
   vector<float>   *muon_eta;
   vector<float>   *muon_phi;
   vector<float>   *muon_E;
   vector<char>    *muon_isLoose;
   vector<char>    *muon_isMedium;
   vector<char>    *muon_isTight;
   vector<int>     *muon_ID;
   vector<float>   *muon_sigd0PV;
   vector<float>   *muon_z0SinTheta;
   vector<float>   *muon_momBalSignif;
   vector<float>   *muon_scatCurvSignif;
   vector<float>   *muon_scatNeighSignif;
   vector<float>   *muon_rho;
   vector<float>   *muon_qOverPsigma;
   vector<float>   *muon_qOverPsignif;
   vector<float>   *muon_reducedChi2;
   vector<unsigned char> *muon_numPrecLayers;
   vector<float>   *muon_topoetcone20;
   vector<float>   *muon_topoetcone30;
   vector<float>   *muon_topoetcone40;
   vector<float>   *muon_ptvarcone20;
   vector<float>   *muon_ptvarcone30;
   vector<float>   *muon_ptvarcone40;
   vector<char>    *muon_sharesTrk;
   vector<char>    *muon_passOR;
   vector<char>    *muon_isQMisID;
   vector<int>     *muon_match_HLT_2mu10;
   vector<int>     *muon_match_HLT_2mu14;
   vector<int>     *muon_match_HLT_e17_lhloose_mu14;
   vector<int>     *muon_match_HLT_e17_lhloose_nod0_mu14;
   vector<int>     *muon_match_HLT_e17_loose_mu14;
   vector<int>     *muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1;
   vector<int>     *muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1;
   vector<int>     *muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;
   vector<int>     *muon_match_HLT_e7_lhmedium_mu24;
   vector<int>     *muon_match_HLT_e7_lhmedium_nod0_mu24;
   vector<int>     *muon_match_HLT_e7_medium_mu24;
   vector<int>     *muon_match_HLT_mu10;
   vector<int>     *muon_match_HLT_mu14;
   vector<int>     *muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo;
   vector<int>     *muon_match_HLT_mu14_tau25_medium1_tracktwo;
   vector<int>     *muon_match_HLT_mu18;
   vector<int>     *muon_match_HLT_mu18_mu8noL1;
   vector<int>     *muon_match_HLT_mu20_iloose_L1MU15;
   vector<int>     *muon_match_HLT_mu20_mu8noL1;
   vector<int>     *muon_match_HLT_mu22_mu8noL1;
   vector<int>     *muon_match_HLT_mu24;
   vector<int>     *muon_match_HLT_mu24_iloose;
   vector<int>     *muon_match_HLT_mu24_imedium;
   vector<int>     *muon_match_HLT_mu24_ivarloose;
   vector<int>     *muon_match_HLT_mu24_ivarmedium;
   vector<int>     *muon_match_HLT_mu26_imedium;
   vector<int>     *muon_match_HLT_mu26_ivarmedium;
   vector<int>     *muon_match_HLT_mu40;
   vector<int>     *muon_match_HLT_mu50;
   vector<float>   *muon_d0;
   vector<float>   *muon_z0;
   vector<float>   *muon_vz;
   vector<float>   *muon_deltaz0;
   vector<int>     *muon_author;
   vector<int>     *muon_type;
   vector<int>     *muon_truthType;
   vector<int>     *muon_truthOrigin;
   vector<int>     *muon_trackType;
   vector<int>     *muon_trackOrigin;
   vector<float>   *muon_jetFitterComb;
   vector<short>   *muon_PromptLeptonInput_sv1_jf_ntrkv;
   vector<short>   *muon_PromptLeptonInput_TrackJetNTrack;
   vector<float>   *muon_PromptLeptonInput_DL1mu;
   vector<float>   *muon_PromptLeptonInput_DRlj;
   vector<float>   *muon_PromptLeptonInput_LepJetPtFrac;
   vector<float>   *muon_PromptLeptonInput_PtFrac;
   vector<float>   *muon_PromptLeptonInput_PtRel;
   vector<float>   *muon_PromptLeptonInput_ip2;
   vector<float>   *muon_PromptLeptonInput_ip3;
   vector<float>   *muon_PromptLeptonInput_rnnip;
   vector<float>   *muon_PromptLeptonIso_TagWeight;
   vector<float>   *muon_PromptLeptonVeto_TagWeight;
   vector<float>   *muon_jet_pt;
   vector<float>   *muon_jet_eta;
   vector<float>   *muon_jet_phi;
   vector<float>   *muon_jet_dr;
   vector<float>   *muon_jet_ptRel;
   vector<float>   *muon_jet_numTrk;
   vector<float>   *muon_jet_sumPtTrk;
   vector<float>   *muon_jet_MV2c10_Weight;
   vector<float>   *muon_jet_tagWeightBin;
   vector<float>   *muon_jet_BDT;
   vector<float>   *m_jet_pt;
   vector<float>   *m_jet_eta;
   vector<float>   *m_jet_phi;
   vector<float>   *m_jet_E;
   vector<double>  *m_jet_etaEM;
   vector<float>   *m_jet_jvt;
   vector<int>     *m_jet_passjvt;
   vector<int>     *m_jet_isLooseBad;
   vector<float>   *m_jet_flavor_weight_MV2c10;
   vector<int>     *m_jet_numTrk;
   vector<char>    *m_jet_passOR;
   vector<char>    *m_jet_passTauOR;
   vector<float>   *m_jet_flavor_weight_MV2c00;
   vector<float>   *m_jet_flavor_weight_MV2c20;
   vector<float>   *m_jet_sumPtTrk;
   vector<float>   *m_jet_emfrac;
   vector<int>     *m_jet_flavor_truth_label;
   vector<int>     *m_jet_flavor_truth_label_ghost;
   vector<float>   *m_tau_pt;
   vector<float>   *m_tau_eta;
   vector<float>   *m_tau_phi;
   vector<float>   *m_tau_E;
   vector<float>   *m_tau_charge;
   vector<float>   *m_tau_numTrack;
   vector<double>  *m_tau_BDTJetScore;
   vector<int>     *m_tau_JetBDTSigLoose;
   vector<int>     *m_tau_JetBDTSigMedium;
   vector<int>     *m_tau_JetBDTSigTight;
   vector<int>     *m_tau_MVATESQuality;
   vector<char>    *m_tau_passOR;
   vector<int>     *m_tau_passEleOLR;
   vector<int>     *m_tau_passEleBDT;
   vector<int>     *m_tau_passMuonOLR;
   vector<int>     *m_tau_isHadronicTau;
   vector<float>   *m_tau_MV2c10;
   vector<int>     *m_tau_tagWeightBin;
   vector<char>    *m_tau_passJVT;
   vector<char>    *m_tau_fromPV;
   vector<float>   *m_tau_BDTEleScoreSigTrans;
   vector<double>  *m_tau_BDTJetScoreSigTrans;
   vector<float>   *m_tau_ptTauEtaCalib;
   vector<float>   *m_tau_etaTauEtaCalib;
   vector<float>   *m_tau_phiTauEtaCalib;
   vector<float>   *m_tau_mTauEtaCalib;
   vector<int>     *m_tau_isTruthMatched;
   vector<int>     *m_tau_truthOrigin;
   vector<int>     *m_tau_truthType;
   vector<int>     *m_tau_truthJetFlavour;
   vector<float>   *m_tau_ele_match_lhscore;
   vector<short>   *m_tau_PromptTauInput_TrackJetNTrack;
   vector<float>   *m_tau_PromptTauInput_DRlj;
   vector<float>   *m_tau_PromptTauInput_JetF;
   vector<float>   *m_tau_PromptTauInput_LepJetPtFrac;
   vector<float>   *m_tau_PromptTauInput_MV2c10rnn;
   vector<float>   *m_tau_PromptTauInput_SV1;
   vector<float>   *m_tau_PromptTauInput_ip2;
   vector<float>   *m_tau_PromptTauInput_ip3;
   vector<float>   *m_tau_PromptTauInput_rnnip;
   vector<float>   *m_tau_PromptTauInput_MV2c10;
   vector<float>   *m_tau_PromptTauVeto;
   vector<float>   *m_tau_PromptTauIso;
   Float_t         lep_ID_0;
   Int_t           lep_Index_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_Phi_0;
   Float_t         lep_EtaBE2_0;
   Float_t         lep_topoEtcone20_0;
   Float_t         lep_topoEtcone30_0;
   Float_t         lep_topoEtcone40_0;
   Float_t         lep_ptVarcone20_0;
   Float_t         lep_ptVarcone30_0;
   Float_t         lep_ptVarcone40_0;
   Float_t         lep_sigd0PV_0;
   Float_t         lep_Z0SinTheta_0;
   Float_t         lep_d0_0;
   Float_t         lep_z0_0;
   Float_t         lep_vz_0;
   Float_t         lep_deltaz0_0;
   Char_t          lep_isTightLH_0;
   Char_t          lep_isMediumLH_0;
   Char_t          lep_isLooseLH_0;
   Char_t          lep_isTight_0;
   Char_t          lep_isMedium_0;
   Char_t          lep_isLoose_0;
   Int_t           lep_isolationLooseTrackOnly_0;
   Int_t           lep_isolationLoose_0;
   Int_t           lep_isolationGradient_0;
   Int_t           lep_isolationGradientLoose_0;
   Int_t           lep_isolationFixedCutTight_0;
   Int_t           lep_isolationFixedCutTightTrackOnly_0;
   Int_t           lep_isolationFixedCutLoose_0;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_isTrigMatchDLT_0;
   Char_t          lep_isPrompt_0;
   Char_t          lep_isFakeLep_0;
   Char_t          lep_isQMisID_0;
   Char_t          lep_isConvPh_0;
   Char_t          lep_isExtConvPh_0;
   Char_t          lep_isIntConvPh_0;
   Char_t          lep_isISR_FSR_Ph_0;
   Char_t          lep_isBrems_0;
   Float_t         lep_chargeIDBDTLoose_0;
   Float_t         lep_chargeIDBDTMedium_0;
   Float_t         lep_chargeIDBDTTight_0;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_0;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_0;
   Float_t         lep_promptLeptonInput_DL1mu_0;
   Float_t         lep_promptLeptonInput_DRlj_0;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_0;
   Float_t         lep_promptLeptonInput_PtFrac_0;
   Float_t         lep_promptLeptonInput_PtRel_0;
   Float_t         lep_promptLeptonInput_ip2_0;
   Float_t         lep_promptLeptonInput_ip3_0;
   Float_t         lep_promptLeptonInput_rnnip_0;
   Float_t         lep_promptLeptonIso_TagWeight_0;
   Float_t         lep_promptLeptonVeto_TagWeight_0;
   Float_t         lep_jet_Pt_0;
   Float_t         lep_jet_nTrk_0;
   Float_t         lep_jet_sumPtTrk_0;
   Float_t         lep_jet_mv2c10_0;
   Float_t         lep_jet_deltaR_0;
   Float_t         lep_jet_ptRel_0;
   Float_t         lep_jet_ptOverMuPt_0;
   Float_t         lep_jet_BDT_0;
   Char_t          lep_isTruthMatched_0;
   Int_t           lep_truthType_0;
   Int_t           lep_truthOrigin_0;
   Int_t           lep_truthPdgId_0;
   Int_t           lep_truthStatus_0;
   Int_t           lep_truthParentType_0;
   Int_t           lep_truthParentOrigin_0;
   Int_t           lep_truthParentPdgId_0;
   Int_t           lep_truthParentStatus_0;
   Float_t         lep_truthPt_0;
   Float_t         lep_truthEta_0;
   Float_t         lep_truthPhi_0;
   Float_t         lep_truthM_0;
   Float_t         lep_truthE_0;
   Float_t         lep_truthRapidity_0;
   UChar_t         lep_ambiguityType_0;
   Float_t         lep_SFIDLoose_0;
   Float_t         lep_SFIDTight_0;
   Float_t         lep_SFTrigLoose_0;
   Float_t         lep_SFTrigTight_0;
   Float_t         lep_EffTrigLoose_0;
   Float_t         lep_EffTrigTight_0;
   Float_t         lep_SFIsoLoose_0;
   Float_t         lep_SFIsoTight_0;
   Float_t         lep_SFReco_0;
   Float_t         lep_SFTTVA_0;
   Float_t         lep_SFObjLoose_0;
   Float_t         lep_SFObjTight_0;
   Int_t           lep_nInnerPix_0;
   Float_t         lep_ID_1;
   Int_t           lep_Index_1;
   Float_t         lep_Pt_1;
   Float_t         lep_E_1;
   Float_t         lep_Eta_1;
   Float_t         lep_Phi_1;
   Float_t         lep_EtaBE2_1;
   Float_t         lep_topoEtcone20_1;
   Float_t         lep_topoEtcone30_1;
   Float_t         lep_topoEtcone40_1;
   Float_t         lep_ptVarcone20_1;
   Float_t         lep_ptVarcone30_1;
   Float_t         lep_ptVarcone40_1;
   Float_t         lep_sigd0PV_1;
   Float_t         lep_Z0SinTheta_1;
   Float_t         lep_d0_1;
   Float_t         lep_z0_1;
   Float_t         lep_vz_1;
   Float_t         lep_deltaz0_1;
   Char_t          lep_isTightLH_1;
   Char_t          lep_isMediumLH_1;
   Char_t          lep_isLooseLH_1;
   Char_t          lep_isTight_1;
   Char_t          lep_isMedium_1;
   Char_t          lep_isLoose_1;
   Int_t           lep_isolationLooseTrackOnly_1;
   Int_t           lep_isolationLoose_1;
   Int_t           lep_isolationGradient_1;
   Int_t           lep_isolationGradientLoose_1;
   Int_t           lep_isolationFixedCutTight_1;
   Int_t           lep_isolationFixedCutTightTrackOnly_1;
   Int_t           lep_isolationFixedCutLoose_1;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_isTrigMatchDLT_1;
   Char_t          lep_isPrompt_1;
   Char_t          lep_isFakeLep_1;
   Char_t          lep_isQMisID_1;
   Char_t          lep_isConvPh_1;
   Char_t          lep_isExtConvPh_1;
   Char_t          lep_isIntConvPh_1;
   Char_t          lep_isISR_FSR_Ph_1;
   Char_t          lep_isBrems_1;
   Float_t         lep_chargeIDBDTLoose_1;
   Float_t         lep_chargeIDBDTMedium_1;
   Float_t         lep_chargeIDBDTTight_1;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_1;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_1;
   Float_t         lep_promptLeptonInput_DL1mu_1;
   Float_t         lep_promptLeptonInput_DRlj_1;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_1;
   Float_t         lep_promptLeptonInput_PtFrac_1;
   Float_t         lep_promptLeptonInput_PtRel_1;
   Float_t         lep_promptLeptonInput_ip2_1;
   Float_t         lep_promptLeptonInput_ip3_1;
   Float_t         lep_promptLeptonInput_rnnip_1;
   Float_t         lep_promptLeptonIso_TagWeight_1;
   Float_t         lep_promptLeptonVeto_TagWeight_1;
   Float_t         lep_jet_Pt_1;
   Float_t         lep_jet_nTrk_1;
   Float_t         lep_jet_sumPtTrk_1;
   Float_t         lep_jet_mv2c10_1;
   Float_t         lep_jet_deltaR_1;
   Float_t         lep_jet_ptRel_1;
   Float_t         lep_jet_ptOverMuPt_1;
   Float_t         lep_jet_BDT_1;
   Char_t          lep_isTruthMatched_1;
   Int_t           lep_truthType_1;
   Int_t           lep_truthOrigin_1;
   Int_t           lep_truthPdgId_1;
   Int_t           lep_truthStatus_1;
   Int_t           lep_truthParentType_1;
   Int_t           lep_truthParentOrigin_1;
   Int_t           lep_truthParentPdgId_1;
   Int_t           lep_truthParentStatus_1;
   Float_t         lep_truthPt_1;
   Float_t         lep_truthEta_1;
   Float_t         lep_truthPhi_1;
   Float_t         lep_truthM_1;
   Float_t         lep_truthE_1;
   Float_t         lep_truthRapidity_1;
   UChar_t         lep_ambiguityType_1;
   Float_t         lep_SFIDLoose_1;
   Float_t         lep_SFIDTight_1;
   Float_t         lep_SFTrigLoose_1;
   Float_t         lep_SFTrigTight_1;
   Float_t         lep_EffTrigLoose_1;
   Float_t         lep_EffTrigTight_1;
   Float_t         lep_SFIsoLoose_1;
   Float_t         lep_SFIsoTight_1;
   Float_t         lep_SFReco_1;
   Float_t         lep_SFTTVA_1;
   Float_t         lep_SFObjLoose_1;
   Float_t         lep_SFObjTight_1;
   Int_t           lep_nInnerPix_1;
   Float_t         lep_ID_2;
   Int_t           lep_Index_2;
   Float_t         lep_Pt_2;
   Float_t         lep_E_2;
   Float_t         lep_Eta_2;
   Float_t         lep_Phi_2;
   Float_t         lep_EtaBE2_2;
   Float_t         lep_topoEtcone20_2;
   Float_t         lep_topoEtcone30_2;
   Float_t         lep_topoEtcone40_2;
   Float_t         lep_ptVarcone20_2;
   Float_t         lep_ptVarcone30_2;
   Float_t         lep_ptVarcone40_2;
   Float_t         lep_sigd0PV_2;
   Float_t         lep_Z0SinTheta_2;
   Float_t         lep_d0_2;
   Float_t         lep_z0_2;
   Float_t         lep_vz_2;
   Float_t         lep_deltaz0_2;
   Char_t          lep_isTightLH_2;
   Char_t          lep_isMediumLH_2;
   Char_t          lep_isLooseLH_2;
   Char_t          lep_isTight_2;
   Char_t          lep_isMedium_2;
   Char_t          lep_isLoose_2;
   Int_t           lep_isolationLooseTrackOnly_2;
   Int_t           lep_isolationLoose_2;
   Int_t           lep_isolationGradient_2;
   Int_t           lep_isolationGradientLoose_2;
   Int_t           lep_isolationFixedCutTight_2;
   Int_t           lep_isolationFixedCutTightTrackOnly_2;
   Int_t           lep_isolationFixedCutLoose_2;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_isTrigMatchDLT_2;
   Char_t          lep_isPrompt_2;
   Char_t          lep_isFakeLep_2;
   Char_t          lep_isQMisID_2;
   Char_t          lep_isConvPh_2;
   Char_t          lep_isExtConvPh_2;
   Char_t          lep_isIntConvPh_2;
   Char_t          lep_isISR_FSR_Ph_2;
   Char_t          lep_isBrems_2;
   Float_t         lep_chargeIDBDTLoose_2;
   Float_t         lep_chargeIDBDTMedium_2;
   Float_t         lep_chargeIDBDTTight_2;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_2;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_2;
   Float_t         lep_promptLeptonInput_DL1mu_2;
   Float_t         lep_promptLeptonInput_DRlj_2;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_2;
   Float_t         lep_promptLeptonInput_PtFrac_2;
   Float_t         lep_promptLeptonInput_PtRel_2;
   Float_t         lep_promptLeptonInput_ip2_2;
   Float_t         lep_promptLeptonInput_ip3_2;
   Float_t         lep_promptLeptonInput_rnnip_2;
   Float_t         lep_promptLeptonIso_TagWeight_2;
   Float_t         lep_promptLeptonVeto_TagWeight_2;
   Float_t         lep_jet_Pt_2;
   Float_t         lep_jet_nTrk_2;
   Float_t         lep_jet_sumPtTrk_2;
   Float_t         lep_jet_mv2c10_2;
   Float_t         lep_jet_deltaR_2;
   Float_t         lep_jet_ptRel_2;
   Float_t         lep_jet_ptOverMuPt_2;
   Float_t         lep_jet_BDT_2;
   Char_t          lep_isTruthMatched_2;
   Int_t           lep_truthType_2;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthPdgId_2;
   Int_t           lep_truthStatus_2;
   Int_t           lep_truthParentType_2;
   Int_t           lep_truthParentOrigin_2;
   Int_t           lep_truthParentPdgId_2;
   Int_t           lep_truthParentStatus_2;
   Float_t         lep_truthPt_2;
   Float_t         lep_truthEta_2;
   Float_t         lep_truthPhi_2;
   Float_t         lep_truthM_2;
   Float_t         lep_truthE_2;
   Float_t         lep_truthRapidity_2;
   UChar_t         lep_ambiguityType_2;
   Float_t         lep_SFIDLoose_2;
   Float_t         lep_SFIDTight_2;
   Float_t         lep_SFTrigLoose_2;
   Float_t         lep_SFTrigTight_2;
   Float_t         lep_EffTrigLoose_2;
   Float_t         lep_EffTrigTight_2;
   Float_t         lep_SFIsoLoose_2;
   Float_t         lep_SFIsoTight_2;
   Float_t         lep_SFReco_2;
   Float_t         lep_SFTTVA_2;
   Float_t         lep_SFObjLoose_2;
   Float_t         lep_SFObjTight_2;
   Int_t           lep_nInnerPix_2;
   Float_t         lep_ID_3;
   Int_t           lep_Index_3;
   Float_t         lep_Pt_3;
   Float_t         lep_E_3;
   Float_t         lep_Eta_3;
   Float_t         lep_Phi_3;
   Float_t         lep_EtaBE2_3;
   Float_t         lep_topoEtcone20_3;
   Float_t         lep_topoEtcone30_3;
   Float_t         lep_topoEtcone40_3;
   Float_t         lep_ptVarcone20_3;
   Float_t         lep_ptVarcone30_3;
   Float_t         lep_ptVarcone40_3;
   Float_t         lep_sigd0PV_3;
   Float_t         lep_Z0SinTheta_3;
   Float_t         lep_d0_3;
   Float_t         lep_z0_3;
   Float_t         lep_vz_3;
   Float_t         lep_deltaz0_3;
   Char_t          lep_isTightLH_3;
   Char_t          lep_isMediumLH_3;
   Char_t          lep_isLooseLH_3;
   Char_t          lep_isTight_3;
   Char_t          lep_isMedium_3;
   Char_t          lep_isLoose_3;
   Int_t           lep_isolationLooseTrackOnly_3;
   Int_t           lep_isolationLoose_3;
   Int_t           lep_isolationGradient_3;
   Int_t           lep_isolationGradientLoose_3;
   Int_t           lep_isolationFixedCutTight_3;
   Int_t           lep_isolationFixedCutTightTrackOnly_3;
   Int_t           lep_isolationFixedCutLoose_3;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_isTrigMatchDLT_3;
   Char_t          lep_isPrompt_3;
   Char_t          lep_isFakeLep_3;
   Char_t          lep_isQMisID_3;
   Char_t          lep_isConvPh_3;
   Char_t          lep_isExtConvPh_3;
   Char_t          lep_isIntConvPh_3;
   Char_t          lep_isISR_FSR_Ph_3;
   Char_t          lep_isBrems_3;
   Float_t         lep_chargeIDBDTLoose_3;
   Float_t         lep_chargeIDBDTMedium_3;
   Float_t         lep_chargeIDBDTTight_3;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_3;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_3;
   Float_t         lep_promptLeptonInput_DL1mu_3;
   Float_t         lep_promptLeptonInput_DRlj_3;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_3;
   Float_t         lep_promptLeptonInput_PtFrac_3;
   Float_t         lep_promptLeptonInput_PtRel_3;
   Float_t         lep_promptLeptonInput_ip2_3;
   Float_t         lep_promptLeptonInput_ip3_3;
   Float_t         lep_promptLeptonInput_rnnip_3;
   Float_t         lep_promptLeptonIso_TagWeight_3;
   Float_t         lep_promptLeptonVeto_TagWeight_3;
   Float_t         lep_jet_Pt_3;
   Float_t         lep_jet_nTrk_3;
   Float_t         lep_jet_sumPtTrk_3;
   Float_t         lep_jet_mv2c10_3;
   Float_t         lep_jet_deltaR_3;
   Float_t         lep_jet_ptRel_3;
   Float_t         lep_jet_ptOverMuPt_3;
   Float_t         lep_jet_BDT_3;
   Char_t          lep_isTruthMatched_3;
   Int_t           lep_truthType_3;
   Int_t           lep_truthOrigin_3;
   Int_t           lep_truthPdgId_3;
   Int_t           lep_truthStatus_3;
   Int_t           lep_truthParentType_3;
   Int_t           lep_truthParentOrigin_3;
   Int_t           lep_truthParentPdgId_3;
   Int_t           lep_truthParentStatus_3;
   Float_t         lep_truthPt_3;
   Float_t         lep_truthEta_3;
   Float_t         lep_truthPhi_3;
   Float_t         lep_truthM_3;
   Float_t         lep_truthE_3;
   Float_t         lep_truthRapidity_3;
   UChar_t         lep_ambiguityType_3;
   Float_t         lep_SFIDLoose_3;
   Float_t         lep_SFIDTight_3;
   Float_t         lep_SFTrigLoose_3;
   Float_t         lep_SFTrigTight_3;
   Float_t         lep_EffTrigLoose_3;
   Float_t         lep_EffTrigTight_3;
   Float_t         lep_SFIsoLoose_3;
   Float_t         lep_SFIsoTight_3;
   Float_t         lep_SFReco_3;
   Float_t         lep_SFTTVA_3;
   Float_t         lep_SFObjLoose_3;
   Float_t         lep_SFObjTight_3;
   Int_t           lep_nInnerPix_3;
   Float_t         lep_ID_4;
   Int_t           lep_Index_4;
   Float_t         lep_Pt_4;
   Float_t         lep_E_4;
   Float_t         lep_Eta_4;
   Float_t         lep_Phi_4;
   Float_t         lep_EtaBE2_4;
   Float_t         lep_topoEtcone20_4;
   Float_t         lep_topoEtcone30_4;
   Float_t         lep_topoEtcone40_4;
   Float_t         lep_ptVarcone20_4;
   Float_t         lep_ptVarcone30_4;
   Float_t         lep_ptVarcone40_4;
   Float_t         lep_sigd0PV_4;
   Float_t         lep_Z0SinTheta_4;
   Float_t         lep_d0_4;
   Float_t         lep_z0_4;
   Float_t         lep_vz_4;
   Float_t         lep_deltaz0_4;
   Char_t          lep_isTightLH_4;
   Char_t          lep_isMediumLH_4;
   Char_t          lep_isLooseLH_4;
   Char_t          lep_isTight_4;
   Char_t          lep_isMedium_4;
   Char_t          lep_isLoose_4;
   Int_t           lep_isolationLooseTrackOnly_4;
   Int_t           lep_isolationLoose_4;
   Int_t           lep_isolationGradient_4;
   Int_t           lep_isolationGradientLoose_4;
   Int_t           lep_isolationFixedCutTight_4;
   Int_t           lep_isolationFixedCutTightTrackOnly_4;
   Int_t           lep_isolationFixedCutLoose_4;
   Char_t          lep_isTrigMatch_4;
   Char_t          lep_isTrigMatchDLT_4;
   Char_t          lep_isPrompt_4;
   Char_t          lep_isFakeLep_4;
   Char_t          lep_isQMisID_4;
   Char_t          lep_isConvPh_4;
   Char_t          lep_isExtConvPh_4;
   Char_t          lep_isIntConvPh_4;
   Char_t          lep_isISR_FSR_Ph_4;
   Char_t          lep_isBrems_4;
   Float_t         lep_chargeIDBDTLoose_4;
   Float_t         lep_chargeIDBDTMedium_4;
   Float_t         lep_chargeIDBDTTight_4;
   Short_t         lep_promptLeptonInput_sv1_jf_ntrkv_4;
   Short_t         lep_promptLeptonInput_TrackJetNTrack_4;
   Float_t         lep_promptLeptonInput_DL1mu_4;
   Float_t         lep_promptLeptonInput_DRlj_4;
   Float_t         lep_promptLeptonInput_LepJetPtFrac_4;
   Float_t         lep_promptLeptonInput_PtFrac_4;
   Float_t         lep_promptLeptonInput_PtRel_4;
   Float_t         lep_promptLeptonInput_ip2_4;
   Float_t         lep_promptLeptonInput_ip3_4;
   Float_t         lep_promptLeptonInput_rnnip_4;
   Float_t         lep_promptLeptonIso_TagWeight_4;
   Float_t         lep_promptLeptonVeto_TagWeight_4;
   Float_t         lep_jet_Pt_4;
   Float_t         lep_jet_nTrk_4;
   Float_t         lep_jet_sumPtTrk_4;
   Float_t         lep_jet_mv2c10_4;
   Float_t         lep_jet_deltaR_4;
   Float_t         lep_jet_ptRel_4;
   Float_t         lep_jet_ptOverMuPt_4;
   Float_t         lep_jet_BDT_4;
   Char_t          lep_isTruthMatched_4;
   Int_t           lep_truthType_4;
   Int_t           lep_truthOrigin_4;
   Int_t           lep_truthPdgId_4;
   Int_t           lep_truthStatus_4;
   Int_t           lep_truthParentType_4;
   Int_t           lep_truthParentOrigin_4;
   Int_t           lep_truthParentPdgId_4;
   Int_t           lep_truthParentStatus_4;
   Float_t         lep_truthPt_4;
   Float_t         lep_truthEta_4;
   Float_t         lep_truthPhi_4;
   Float_t         lep_truthM_4;
   Float_t         lep_truthE_4;
   Float_t         lep_truthRapidity_4;
   UChar_t         lep_ambiguityType_4;
   Float_t         lep_SFIDLoose_4;
   Float_t         lep_SFIDTight_4;
   Float_t         lep_SFTrigLoose_4;
   Float_t         lep_SFTrigTight_4;
   Float_t         lep_EffTrigLoose_4;
   Float_t         lep_EffTrigTight_4;
   Float_t         lep_SFIsoLoose_4;
   Float_t         lep_SFIsoTight_4;
   Float_t         lep_SFReco_4;
   Float_t         lep_SFTTVA_4;
   Float_t         lep_SFObjLoose_4;
   Float_t         lep_SFObjTight_4;
   Int_t           lep_nInnerPix_4;
   Float_t         tau_pt_0;
   Float_t         tau_eta_0;
   Float_t         tau_phi_0;
   Float_t         tau_charge_0;
   Float_t         tau_E_0;
   Double_t        tau_BDTJetScore_0;
   Int_t           tau_JetBDTSigLoose_0;
   Int_t           tau_JetBDTSigMedium_0;
   Int_t           tau_JetBDTSigTight_0;
   Int_t           tau_numTrack_0;
   Int_t           tau_isHadronic_0;
   Int_t           tau_tagWeightBin_0;
   Float_t         tau_MV2c10_0;
   Char_t          tau_fromPV_0;
   Float_t         tau_SFTight_0;
   Float_t         tau_SFLoose_0;
   Int_t           tau_passEleOLR_0;
   Int_t           tau_passEleBDT_0;
   Int_t           tau_passMuonOLR_0;
   Float_t         tau_BDTEleScoreSigTrans_0;
   Float_t         tau_BDTJetScoreSigTrans_0;
   Int_t           tau_truthOrigin_0;
   Int_t           tau_truthType_0;
   Int_t           tau_truthJetFlavour_0;
   Short_t         tau_promptTauInput_TrackJetNTrack_0;
   Float_t         tau_promptTauInput_JetF_0;
   Float_t         tau_promptTauInput_DRlj_0;
   Float_t         tau_promptTauInput_LepJetPtFrac_0;
   Float_t         tau_promptTauInput_SV1_0;
   Float_t         tau_promptTauInput_MV2c10rnn_0;
   Float_t         tau_promptTauInput_ip2_0;
   Float_t         tau_promptTauInput_ip3_0;
   Float_t         tau_promptTauInput_rnnip_0;
   Float_t         tau_promptTauInput_MV2c10_0;
   Float_t         tau_promptTauVeto_0;
   Float_t         tau_promptTauIso_0;
   Float_t         tau_pt_1;
   Float_t         tau_eta_1;
   Float_t         tau_phi_1;
   Float_t         tau_charge_1;
   Float_t         tau_E_1;
   Double_t        tau_BDTJetScore_1;
   Int_t           tau_JetBDTSigLoose_1;
   Int_t           tau_JetBDTSigMedium_1;
   Int_t           tau_JetBDTSigTight_1;
   Int_t           tau_numTrack_1;
   Int_t           tau_isHadronic_1;
   Int_t           tau_tagWeightBin_1;
   Float_t         tau_MV2c10_1;
   Char_t          tau_fromPV_1;
   Float_t         tau_SFTight_1;
   Float_t         tau_SFLoose_1;
   Int_t           tau_passEleOLR_1;
   Int_t           tau_passEleBDT_1;
   Int_t           tau_passMuonOLR_1;
   Float_t         tau_BDTEleScoreSigTrans_1;
   Float_t         tau_BDTJetScoreSigTrans_1;
   Int_t           tau_truthOrigin_1;
   Int_t           tau_truthType_1;
   Int_t           tau_truthJetFlavour_1;
   Short_t         tau_promptTauInput_TrackJetNTrack_1;
   Float_t         tau_promptTauInput_JetF_1;
   Float_t         tau_promptTauInput_DRlj_1;
   Float_t         tau_promptTauInput_LepJetPtFrac_1;
   Float_t         tau_promptTauInput_SV1_1;
   Float_t         tau_promptTauInput_MV2c10rnn_1;
   Float_t         tau_promptTauInput_ip2_1;
   Float_t         tau_promptTauInput_ip3_1;
   Float_t         tau_promptTauInput_rnnip_1;
   Float_t         tau_promptTauInput_MV2c10_1;
   Float_t         tau_promptTauVeto_1;
   Float_t         tau_promptTauIso_1;
   Int_t           onelep_type;
   Int_t           dilep_type;
   Int_t           trilep_type;
   Int_t           quadlep_type;
   Int_t           total_charge;
   Int_t           total_leptons;
   Char_t          isQMisIDEvent;
   Char_t          isFakeEvent;
   Char_t          isLepFromPhEvent;
   Float_t         Mll01;
   Float_t         Ptll01;
   Float_t         DRll01;
   Char_t          matchDLTll01;
   Float_t         Mlll012;
   Float_t         Mllll0123;
   Float_t         Mllll0124;
   Float_t         Mlll013;
   Float_t         Mllll0134;
   Float_t         Mlll014;
   Float_t         Mll02;
   Float_t         Ptll02;
   Float_t         DRll02;
   Char_t          matchDLTll02;
   Float_t         Mlll023;
   Float_t         Mllll0234;
   Float_t         Mlll024;
   Float_t         Mll03;
   Float_t         Ptll03;
   Float_t         DRll03;
   Char_t          matchDLTll03;
   Float_t         Mlll034;
   Float_t         Mll04;
   Float_t         Ptll04;
   Float_t         DRll04;
   Char_t          matchDLTll04;
   Float_t         Mll12;
   Float_t         Ptll12;
   Float_t         DRll12;
   Char_t          matchDLTll12;
   Float_t         Mlll123;
   Float_t         Mllll1234;
   Float_t         Mlll124;
   Float_t         Mll13;
   Float_t         Ptll13;
   Float_t         DRll13;
   Char_t          matchDLTll13;
   Float_t         Mlll134;
   Float_t         Mll14;
   Float_t         Ptll14;
   Float_t         DRll14;
   Char_t          matchDLTll14;
   Float_t         Mll23;
   Float_t         Ptll23;
   Float_t         DRll23;
   Char_t          matchDLTll23;
   Float_t         Mlll234;
   Float_t         Mll24;
   Float_t         Ptll24;
   Float_t         DRll24;
   Char_t          matchDLTll24;
   Float_t         Mll34;
   Float_t         Ptll34;
   Float_t         DRll34;
   Char_t          matchDLTll34;
   Float_t         best_Z_Mll;
   Float_t         best_Z_other_MtLepMet;
   Float_t         best_Z_other_Mll;
   Float_t         minOSSFMll;
   Float_t         minOSMll;
   Int_t           nJets_OR_T;
   Int_t           nJets_OR;
   Int_t           nTruthJets;
   Int_t           nTruthJets_OR;
   Int_t           nJets_OR_T_MV2c10_60;
   Int_t           nJets_OR_T_MV2c10_70;
   Int_t           nJets_OR_T_MV2c10_77;
   Int_t           nJets_OR_T_MV2c10_85;
   Int_t           nJets_OR_MV2c10_85;
   Int_t           nJets_OR_MV2c10_60;
   Int_t           nJets_OR_MV2c10_77;
   Int_t           nJets_OR_MV2c10_70;
   Int_t           nJets_OR_T_DL1_60;
   Int_t           nJets_OR_T_DL1_70;
   Int_t           nJets_OR_T_DL1_77;
   Int_t           nJets_OR_T_DL1_85;
   Int_t           nJets_OR_DL1_85;
   Int_t           nJets_OR_DL1_60;
   Int_t           nJets_OR_DL1_77;
   Int_t           nJets_OR_DL1_70;
   Int_t           nTaus_OR_Pt25;
   Bool_t          isBlinded;
   Float_t         HT;
   Float_t         HT_lep;
   Float_t         HT_jets;
   Float_t         lead_jetPt;
   Float_t         lead_jetEta;
   Float_t         lead_jetPhi;
   Float_t         lead_jetE;
   Float_t         sublead_jetPt;
   Float_t         sublead_jetEta;
   Float_t         sublead_jetPhi;
   Float_t         sublead_jetE;
   vector<short>   *selected_jets;
   vector<short>   *selected_jets_T;
   vector<short>   *selected_jets_mv2c10_Ordrd;
   vector<short>   *selected_jets_T_mv2c10_Ordrd;
   Float_t         lepSFIDLoose;
   Float_t         lepSFIDTight;
   Float_t         lepSFIsoLoose;
   Float_t         lepSFIsoTight;
   Float_t         lepSFReco;
   Float_t         lepSFTTVA;
   Float_t         lepSFTrigLoose;
   Float_t         lepSFTrigTight;
   Float_t         lepSFTrigTightLoose;
   Float_t         lepSFTrigLooseTight;
   Float_t         lepEffTrigLoose;
   Float_t         lepEffTrigTight;
   Float_t         lepEffTrigTightLoose;
   Float_t         lepEffTrigLooseTight;
   Float_t         lepDataEffTrigLoose;
   Float_t         lepDataEffTrigTight;
   Float_t         lepDataEffTrigTightLoose;
   Float_t         lepDataEffTrigLooseTight;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         tauSFTight;
   Float_t         tauSFLoose;
   Float_t         lepSFTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepSFTrigTight_EL_SF_Trigger_UP;
   Float_t         lepSFTrigTightLoose_EL_SF_Trigger_UP;
   Float_t         lepSFTrigLooseTight_EL_SF_Trigger_UP;
   Float_t         lepEffTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepEffTrigTight_EL_SF_Trigger_UP;
   Float_t         lepEffTrigTightLoose_EL_SF_Trigger_UP;
   Float_t         lepEffTrigLooseTight_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigTight_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigTightLoose_EL_SF_Trigger_UP;
   Float_t         lepDataEffTrigLooseTight_EL_SF_Trigger_UP;
   Float_t         lepSFTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigTightLoose_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigLooseTight_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigTightLoose_EL_SF_Trigger_DOWN;
   Float_t         lepEffTrigLooseTight_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN;
   Float_t         lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigLoose_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigTight_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigTightLoose_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigLooseTight_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigLoose_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigTight_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigTightLoose_EL_EFF_Trigger_UP;
   Float_t         lepEffTrigLooseTight_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigLoose_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigTight_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigTightLoose_EL_EFF_Trigger_UP;
   Float_t         lepDataEffTrigLooseTight_EL_EFF_Trigger_UP;
   Float_t         lepSFTrigLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepSFTrigTight_EL_EFF_Trigger_DOWN;
   Float_t         lepSFTrigTightLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepSFTrigLooseTight_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigTight_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigTightLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepEffTrigLooseTight_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigTight_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN;
   Float_t         lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN;
   Float_t         lepSFObjLoose_EL_SF_Reco_UP;
   Float_t         lepSFObjTight_EL_SF_Reco_UP;
   Float_t         lepSFObjLoose_EL_SF_Reco_DOWN;
   Float_t         lepSFObjTight_EL_SF_Reco_DOWN;
   Float_t         lepSFObjLoose_EL_SF_ID_UP;
   Float_t         lepSFObjTight_EL_SF_ID_UP;
   Float_t         lepSFObjLoose_EL_SF_ID_DOWN;
   Float_t         lepSFObjTight_EL_SF_ID_DOWN;
   Float_t         lepSFObjLoose_EL_SF_Isol_UP;
   Float_t         lepSFObjTight_EL_SF_Isol_UP;
   Float_t         lepSFObjLoose_EL_SF_Isol_DOWN;
   Float_t         lepSFObjTight_EL_SF_Isol_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_TTVA_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_DOWN;
   Float_t         tauSFTight_TAU_SF_ELEOLR_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_JETID_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_JETID_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_JETID_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_JETID_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_JETID_HIGHPT_UP;
   Float_t         tauSFLoose_TAU_SF_JETID_HIGHPT_UP;
   Float_t         tauSFTight_TAU_SF_JETID_HIGHPT_DOWN;
   Float_t         tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN;
   Float_t         tauSFTight_TAU_SF_RECO_TOTAL_UP;
   Float_t         tauSFLoose_TAU_SF_RECO_TOTAL_UP;
   Float_t         tauSFTight_TAU_SF_RECO_TOTAL_DOWN;
   Float_t         tauSFLoose_TAU_SF_RECO_TOTAL_DOWN;
   Float_t         tauSFTight_TAU_SF_RECO_HIGHPT_UP;
   Float_t         tauSFLoose_TAU_SF_RECO_HIGHPT_UP;
   Float_t         tauSFTight_TAU_SF_RECO_HIGHPT_DOWN;
   Float_t         tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN;
   Double_t        mc_norm;
   Double_t        l2tau_bdt;
   Double_t        tau_leadpt;
   Double_t        tau_subpt;
   Double_t        tau_btag70_0;
   Double_t        tau_tight_0;
   Int_t           tau_truth_0;
   Double_t        tau_btag70_1;
   Double_t        tau_tight_1;
   Int_t           tau_truth_1;
   Double_t        l2tau_htjets;
   Double_t        l2tau_jjdr;
   Double_t        l2tau_mtautau;
   Int_t           Channel;
   Double_t        Drhwwvis;
   Double_t        Mtwbvis;
   Double_t        Mhwwvis;
   Double_t        Mhwwqvis;
   Double_t        Msum;
   Double_t        Pthwl0;
   Double_t        Ptlep;
   Double_t        Pthwj;
   Double_t        Ptqj;
   Double_t        Ptbj;
   Double_t        Chisqmin;
   Double_t        Chisqmax;
   Double_t        Lepwiso;
   Double_t        Lepiso;
   Double_t        Bdt;
   Double_t        BdtvsttV;

   // List of branches
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_hasBadMuon;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_charge;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_triggers;   //!
   TBranch        *b_HLT_mu40;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_mu26_imedium;   //!
   TBranch        *b_HLT_mu24_ivarmedium;   //!
   TBranch        *b_HLT_mu24_ivarloose;   //!
   TBranch        *b_HLT_mu24_imedium;   //!
   TBranch        *b_HLT_mu24;   //!
   TBranch        *b_HLT_mu20_mu8noL1;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_mu14_ivarloose_tau25_medium1_tracktwo;   //!
   TBranch        *b_HLT_e7_medium_mu24;   //!
   TBranch        *b_HLT_e17_lhmedium_tau25_medium1_tracktwo;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_HLT_e140_loose;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_HLT_e17_lhloose_2e9_lhloose;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e17_lhloose;   //!
   TBranch        *b_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo;   //!
   TBranch        *b_HLT_2e12_loose_L12EM10VH;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_e60_medium;   //!
   TBranch        *b_HLT_e12_loose;   //!
   TBranch        *b_HLT_mu18;   //!
   TBranch        *b_HLT_e140_lhloose;   //!
   TBranch        *b_HLT_e5_lhloose;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0_L12EM15VHI;   //!
   TBranch        *b_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo;   //!
   TBranch        *b_HLT_e24_lhmedium_nod0_L1EM20VH;   //!
   TBranch        *b_HLT_2e24_lhvloose_nod0;   //!
   TBranch        *b_HLT_e24_tight_iloose;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_2e12_lhvloose_nod0_L12EM10VH;   //!
   TBranch        *b_HLT_2mu10;   //!
   TBranch        *b_HLT_e12_lhloose;   //!
   TBranch        *b_HLT_2mu14;   //!
   TBranch        *b_HLT_e17_loose;   //!
   TBranch        *b_HLT_e17_loose_mu14;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_mu24_iloose;   //!
   TBranch        *b_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM18VH;   //!
   TBranch        *b_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_HLT_e24_lhtight_iloose;   //!
   TBranch        *b_HLT_mu14;   //!
   TBranch        *b_HLT_mu10;   //!
   TBranch        *b_HLT_e24_lhtight_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e24_lhtight_ivarloose;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_e24_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_mu14_tau25_medium1_tracktwo;   //!
   TBranch        *b_HLT_e24_medium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_HLT_e24_tight_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_HLT_e26_lhtight_iloose;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_2e15_lhvloose_nod0_L12EM13VH;   //!
   TBranch        *b_HLT_e26_tight_iloose;   //!
   TBranch        *b_HLT_e7_lhmedium_nod0_mu24;   //!
   TBranch        *b_HLT_e5_loose;   //!
   TBranch        *b_HLT_e300_etcut;   //!
   TBranch        *b_mcWeightOrg;   //!
   TBranch        *b_mcEventWeights;   //!
   TBranch        *b_pileupEventWeight_090;   //!
   TBranch        *b_MV2c10_60_EventWeight;   //!
   TBranch        *b_MV2c10_70_EventWeight;   //!
   TBranch        *b_MV2c10_77_EventWeight;   //!
   TBranch        *b_MV2c10_85_EventWeight;   //!
   TBranch        *b_MV2c10_Continuous_EventWeight;   //!
   TBranch        *b_JVT_EventWeight;   //!
   TBranch        *b_DL1_60_EventWeight;   //!
   TBranch        *b_DL1_70_EventWeight;   //!
   TBranch        *b_DL1_77_EventWeight;   //!
   TBranch        *b_DL1_85_EventWeight;   //!
   TBranch        *b_DL1_Continuous_EventWeight;   //!
   TBranch        *b_pileupEventWeight_UP;   //!
   TBranch        *b_pileupEventWeight_DOWN;   //!
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up;
   TBranch        *b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B0_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B0_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B1_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B1_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B2_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B2_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B3_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B3_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B4_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B4_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B5_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B5_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B6_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B6_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B7_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B7_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B8_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_B8_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_C0_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_C0_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_C1_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_C1_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_C2_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_C2_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light0_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light0_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light1_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light1_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light2_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light2_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light3_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_Light3_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up;
   TBranch        *b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down;
   TBranch        *b_lep_firstEgMotherPdgId_0;
   TBranch        *b_lep_firstEgMotherTruthType_0;
   TBranch        *b_lep_firstEgMotherTruthOrigin_0;
   TBranch        *b_lep_firstEgMotherPdgId_1;
   TBranch        *b_lep_firstEgMotherTruthType_1;
   TBranch        *b_lep_firstEgMotherTruthOrigin_1;
   TBranch        *b_lep_firstEgMotherPdgId_2;
   TBranch        *b_lep_firstEgMotherTruthType_2;
   TBranch        *b_lep_firstEgMotherTruthOrigin_2;
   TBranch        *b_lep_firstEgMotherPdgId_3;
   TBranch        *b_lep_firstEgMotherTruthType_3;
   TBranch        *b_lep_firstEgMotherTruthOrigin_3;
   TBranch        *b_lep_firstEgMotherPdgId_4;
   TBranch        *b_lep_firstEgMotherTruthType_4;
   TBranch        *b_lep_firstEgMotherTruthOrigin_4;
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP;
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN;
   TBranch        *b_bTagSF_weight_MV2c10_Continuous;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B0_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B0_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B1_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B1_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B2_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B2_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B3_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B3_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B4_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B4_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B5_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B5_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B6_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B6_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B7_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B7_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B8_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B8_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B9_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B9_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B10_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B10_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B11_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B11_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B12_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B12_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B13_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B13_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B14_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B14_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B15_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B15_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B16_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B16_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B17_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B17_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B18_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B18_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B19_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B19_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B20_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B20_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B21_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B21_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B22_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B22_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B23_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B23_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B24_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B24_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B25_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B25_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B26_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B26_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B27_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B27_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B28_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B28_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B29_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B29_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B30_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B30_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B31_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B31_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B32_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B32_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B33_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B33_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B34_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B34_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B35_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B35_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B36_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B36_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B37_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B37_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B38_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B38_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B39_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B39_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B40_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B40_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B41_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B41_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B42_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B42_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B43_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B43_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B44_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_B44_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C0_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C0_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C1_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C1_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C2_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C2_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C3_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C3_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C4_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C4_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C5_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C5_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C6_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C6_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C7_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C7_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C8_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C8_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C9_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C9_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C10_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C10_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C11_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C11_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C12_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C12_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C13_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C13_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C14_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_C14_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light0_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light0_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light1_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light1_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light2_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light2_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light3_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light3_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light4_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light4_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light5_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light5_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light6_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light6_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light7_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light7_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light8_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light8_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light9_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light9_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light10_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light10_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light11_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light11_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light12_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light12_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light13_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light13_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light14_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light14_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light15_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light15_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light16_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light16_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light17_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light17_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light18_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light18_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light19_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light19_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light20_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light20_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light21_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light21_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light22_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light22_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light23_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light23_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light24_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light24_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light25_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light25_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light26_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light26_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light27_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light27_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light28_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light28_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light29_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light29_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light30_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light30_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light31_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light31_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light32_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light32_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light33_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light33_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light34_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light34_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light35_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light35_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light36_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light36_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light37_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light37_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light38_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light38_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light39_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light39_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light40_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light40_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light41_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light41_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light42_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light42_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light43_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light43_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light44_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light44_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light45_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light45_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light46_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light46_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light47_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light47_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light48_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light48_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light49_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light49_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light50_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light50_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light51_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light51_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light52_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light52_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light53_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light53_down;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light54_up;   //!
   TBranch        *b_bTagSF_weight_MV2c10_Continuous_Light54_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B0_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B0_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B1_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B1_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B2_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B2_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B3_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B3_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B4_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B4_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B5_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B5_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B6_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B6_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B7_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B7_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B8_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B8_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B9_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B9_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B10_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B10_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B11_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B11_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B12_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B12_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B13_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B13_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B14_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B14_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B15_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B15_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B16_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B16_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B17_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B17_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B18_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B18_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B19_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B19_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B20_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B20_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B21_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B21_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B22_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B22_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B23_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B23_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B24_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B24_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B25_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B25_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B26_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B26_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B27_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B27_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B28_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B28_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B29_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B29_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B30_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B30_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B31_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B31_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B32_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B32_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B33_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B33_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B34_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B34_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B35_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B35_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B36_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B36_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B37_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B37_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B38_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B38_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B39_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B39_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B40_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B40_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B41_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B41_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B42_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B42_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B43_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B43_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B44_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_B44_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C0_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C0_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C1_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C1_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C2_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C2_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C3_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C3_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C4_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C4_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C5_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C5_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C6_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C6_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C7_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C7_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C8_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C8_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C9_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C9_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C10_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C10_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C11_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C11_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C12_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C12_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C13_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C13_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C14_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_C14_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light0_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light0_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light1_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light1_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light2_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light2_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light3_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light3_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light4_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light4_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light5_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light5_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light6_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light6_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light7_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light7_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light8_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light8_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light9_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light9_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light10_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light10_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light11_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light11_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light12_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light12_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light13_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light13_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light14_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light14_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light15_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light15_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light16_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light16_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light17_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light17_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light18_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light18_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light19_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light19_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light20_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light20_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light21_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light21_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light22_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light22_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light23_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light23_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light24_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light24_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light25_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light25_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light26_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light26_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light27_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light27_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light28_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light28_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light29_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light29_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light30_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light30_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light31_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light31_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light32_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light32_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light33_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light33_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light34_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light34_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light35_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light35_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light36_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light36_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light37_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light37_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light38_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light38_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light39_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light39_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light40_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light40_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light41_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light41_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light42_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light42_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light43_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light43_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light44_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light44_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light45_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light45_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light46_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light46_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light47_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light47_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light48_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light48_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light49_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light49_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light50_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light50_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light51_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light51_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light52_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light52_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light53_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light53_down;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light54_up;   //!
   TBranch        *b_bTagSF_weight_DL1_Continuous_Light54_down;   //!
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_m_jet_tagWeightBin;   //!
   TBranch        *b_JVT_EventWeight_UP;   //!
   TBranch        *b_JVT_EventWeight_DOWN;   //!
   TBranch        *b_m_truth_m;   //!
   TBranch        *b_m_truth_pt;   //!
   TBranch        *b_m_truth_eta;   //!
   TBranch        *b_m_truth_phi;   //!
   TBranch        *b_m_truth_e;   //!
   TBranch        *b_m_truth_pdgId;   //!
   TBranch        *b_m_truth_status;   //!
   TBranch        *b_m_truth_barcode;   //!
   TBranch        *b_m_truth_parents;   //!
   TBranch        *b_m_truth_children;   //!
   TBranch        *b_m_mcevt_pdf_X1;   //!
   TBranch        *b_m_mcevt_pdf_X2;   //!
   TBranch        *b_m_mcevt_pdf_PDGID1;   //!
   TBranch        *b_m_mcevt_pdf_PDGID2;   //!
   TBranch        *b_m_mcevt_pdf_Q;   //!
   TBranch        *b_m_mcevt_pdf_XF1;   //!
   TBranch        *b_m_mcevt_pdf_XF2;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_passEventCleaning;   //!
   TBranch        *b_backgroundFlags;   //!
   TBranch        *b_m_vxp_x;   //!
   TBranch        *b_m_vxp_y;   //!
   TBranch        *b_m_vxp_z;   //!
   TBranch        *b_SherpaNJetWeight;   //!
   TBranch        *b_nTruthJets_SherpaRwght;   //!
   TBranch        *b_higgs_pt;   //!
   TBranch        *b_higgs_eta;   //!
   TBranch        *b_higgs_phi;   //!
   TBranch        *b_higgs_E;   //!
   TBranch        *b_higgs_rapidity;   //!
   TBranch        *b_top_pt;   //!
   TBranch        *b_top_eta;   //!
   TBranch        *b_top_phi;   //!
   TBranch        *b_top_E;   //!
   TBranch        *b_antitop_pt;   //!
   TBranch        *b_antitop_eta;   //!
   TBranch        *b_antitop_phi;   //!
   TBranch        *b_antitop_E;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_higgsDecayMode;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_mc_isAFII;   //!
   TBranch        *b_mc_xSection;   //!
   TBranch        *b_mc_rawXSection;   //!
   TBranch        *b_mc_kFactor;   //!
   TBranch        *b_mc_showering;   //!
   TBranch        *b_averageIntPerXing_uncorr;   //!
   TBranch        *b_averageIntPerXing;   //!
   TBranch        *b_actualIntPerXing;   //!
   TBranch        *b_pileupHash;   //!
   TBranch        *b_m_vxp_n;   //!
   TBranch        *b_m_vxpu_n;   //!
   TBranch        *b_m_vx_density;   //!
   TBranch        *b_m_beam_posz;   //!
   TBranch        *b_m_beam_sigmaz;   //!
   TBranch        *b_m_hasMEphoton;   //!
   TBranch        *b_m_hasMEphoton_DRgt02_nonhad;   //!
   TBranch        *b_m_MEphoton_e;   //!
   TBranch        *b_m_MEphoton_pt;   //!
   TBranch        *b_m_MEphoton_eta;   //!
   TBranch        *b_m_MEphoton_phi;   //!
   TBranch        *b_m_MEphoton_mother_pdgId;   //!
   TBranch        *b_m_MEphoton_mother_e;   //!
   TBranch        *b_m_MEphoton_mother_pt;   //!
   TBranch        *b_m_MEphoton_mother_eta;   //!
   TBranch        *b_m_MEphoton_mother_phi;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_MET_RefFinal_sumet;   //!
   TBranch        *b_MET_RefFinal_softTrk_et;   //!
   TBranch        *b_MET_RefFinal_softTrk_phi;   //!
   TBranch        *b_MET_RefFinal_softClus_et;   //!
   TBranch        *b_MET_RefFinal_softClus_phi;   //!
   TBranch        *b_MET_Truth_px;   //!
   TBranch        *b_MET_Truth_py;   //!
   TBranch        *b_MET_Truth_phi;   //!
   TBranch        *b_MET_Truth_sumet;   //!
   TBranch        *b_vtx_x;   //!
   TBranch        *b_vtx_y;   //!
   TBranch        *b_vtx_z;   //!
   TBranch        *b_vtx_type;   //!
   TBranch        *b_vtx_numTrk;   //!
   TBranch        *b_electron_isolationLooseTrackOnly;   //!
   TBranch        *b_muon_isolationLooseTrackOnly;   //!
   TBranch        *b_electron_isolationLoose;   //!
   TBranch        *b_muon_isolationLoose;   //!
   TBranch        *b_electron_isolationGradient;   //!
   TBranch        *b_muon_isolationGradient;   //!
   TBranch        *b_electron_isolationGradientLoose;   //!
   TBranch        *b_muon_isolationGradientLoose;   //!
   TBranch        *b_electron_isolationFixedCutTightTrackOnly;   //!
   TBranch        *b_muon_isolationFixedCutTightTrackOnly;   //!
   TBranch        *b_electron_isolationFixedCutLoose;   //!
   TBranch        *b_muon_isolationFixedCutLoose;   //!
   TBranch        *b_electron_isolationFixedCutTight;   //!
   TBranch        *b_electron_pt;   //!
   TBranch        *b_electron_eta;   //!
   TBranch        *b_electron_EtaBE2;   //!
   TBranch        *b_electron_phi;   //!
   TBranch        *b_electron_E;   //!
   TBranch        *b_electron_ID;   //!
   TBranch        *b_electron_sigd0PV;   //!
   TBranch        *b_electron_z0SinTheta;   //!
   TBranch        *b_electron_topoetcone20;   //!
   TBranch        *b_electron_topoetcone30;   //!
   TBranch        *b_electron_topoetcone40;   //!
   TBranch        *b_electron_ptvarcone20;   //!
   TBranch        *b_electron_ptvarcone30;   //!
   TBranch        *b_electron_ptvarcone40;   //!
   TBranch        *b_electron_isLooseLH;   //!
   TBranch        *b_electron_isMediumLH;   //!
   TBranch        *b_electron_isTightLH;   //!
   TBranch        *b_electron_sharesTrk;   //!
   TBranch        *b_electron_passOR;   //!
   TBranch        *b_electron_isQMisID;   //!
   TBranch        *b_electron_ChargeIDBDTLoose;   //!
   TBranch        *b_electron_ChargeIDBDTMedium;   //!
   TBranch        *b_electron_ChargeIDBDTTight;   //!
   TBranch        *b_electron_match_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH;   //!
   TBranch        *b_electron_match_HLT_2e12_loose_L12EM10VH;   //!
   TBranch        *b_electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH;   //!
   TBranch        *b_electron_match_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI;   //!
   TBranch        *b_electron_match_HLT_2e24_lhvloose_nod0;   //!
   TBranch        *b_electron_match_HLT_e120_lhloose;   //!
   TBranch        *b_electron_match_HLT_e12_lhloose;   //!
   TBranch        *b_electron_match_HLT_e12_loose;   //!
   TBranch        *b_electron_match_HLT_e140_lhloose;   //!
   TBranch        *b_electron_match_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_electron_match_HLT_e140_loose;   //!
   TBranch        *b_electron_match_HLT_e17_lhloose;   //!
   TBranch        *b_electron_match_HLT_e17_lhloose_2e9_lhloose;   //!
   TBranch        *b_electron_match_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_electron_match_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo;   //!
   TBranch        *b_electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo;   //!
   TBranch        *b_electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo;   //!
   TBranch        *b_electron_match_HLT_e17_loose;   //!
   TBranch        *b_electron_match_HLT_e17_loose_mu14;   //!
   TBranch        *b_electron_match_HLT_e24_lhmedium_L1EM18VH;   //!
   TBranch        *b_electron_match_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_electron_match_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_electron_match_HLT_e24_lhmedium_nod0_L1EM20VH;   //!
   TBranch        *b_electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_electron_match_HLT_e24_lhtight_iloose;   //!
   TBranch        *b_electron_match_HLT_e24_lhtight_iloose_L1EM20VH;   //!
   TBranch        *b_electron_match_HLT_e24_lhtight_ivarloose;   //!
   TBranch        *b_electron_match_HLT_e24_lhtight_nod0_ivarloose;   //!
   TBranch        *b_electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_electron_match_HLT_e24_tight_iloose;   //!
   TBranch        *b_electron_match_HLT_e24_tight_iloose_L1EM20VH;   //!
   TBranch        *b_electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_electron_match_HLT_e26_lhtight_iloose;   //!
   TBranch        *b_electron_match_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_electron_match_HLT_e26_tight_iloose;   //!
   TBranch        *b_electron_match_HLT_e300_etcut;   //!
   TBranch        *b_electron_match_HLT_e5_lhloose;   //!
   TBranch        *b_electron_match_HLT_e5_loose;   //!
   TBranch        *b_electron_match_HLT_e60_lhmedium;   //!
   TBranch        *b_electron_match_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_electron_match_HLT_e60_medium;   //!
   TBranch        *b_electron_match_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_electron_match_HLT_e7_lhmedium_nod0_mu24;   //!
   TBranch        *b_electron_match_HLT_e7_medium_mu24;   //!
   TBranch        *b_electron_nInnerPix;   //!
   TBranch        *b_electron_author;   //!
   TBranch        *b_electron_d0;   //!
   TBranch        *b_electron_z0;   //!
   TBranch        *b_electron_vz;   //!
   TBranch        *b_electron_deltaz0;   //!
   TBranch        *b_electron_truthOrigin;   //!
   TBranch        *b_electron_truthType;   //!
   TBranch        *b_electron_firstEgMotherPdgId;   //!
   TBranch        *b_electron_jetFitterComb;   //!
   TBranch        *b_electron_PromptLeptonInput_sv1_jf_ntrkv;   //!
   TBranch        *b_electron_PromptLeptonInput_TrackJetNTrack;   //!
   TBranch        *b_electron_PromptLeptonInput_DL1mu;   //!
   TBranch        *b_electron_PromptLeptonInput_DRlj;   //!
   TBranch        *b_electron_PromptLeptonInput_LepJetPtFrac;   //!
   TBranch        *b_electron_PromptLeptonInput_PtFrac;   //!
   TBranch        *b_electron_PromptLeptonInput_PtRel;   //!
   TBranch        *b_electron_PromptLeptonInput_ip2;   //!
   TBranch        *b_electron_PromptLeptonInput_ip3;   //!
   TBranch        *b_electron_PromptLeptonInput_rnnip;   //!
   TBranch        *b_electron_PromptLeptonIso_TagWeight;   //!
   TBranch        *b_electron_PromptLeptonVeto_TagWeight;   //!
   TBranch        *b_electron_ambiguityType;   //!
   TBranch        *b_electron_numberOfInnermostPixelLayerHits;   //!
   TBranch        *b_electron_numberOfInnermostPixelLayerOutliers;   //!
   TBranch        *b_electron_expectInnerPixelLayerHit;   //!
   TBranch        *b_muon_pt;   //!
   TBranch        *b_muon_eta;   //!
   TBranch        *b_muon_phi;   //!
   TBranch        *b_muon_E;   //!
   TBranch        *b_muon_isLoose;   //!
   TBranch        *b_muon_isMedium;   //!
   TBranch        *b_muon_isTight;   //!
   TBranch        *b_muon_ID;   //!
   TBranch        *b_muon_sigd0PV;   //!
   TBranch        *b_muon_z0SinTheta;   //!
   TBranch        *b_muon_momBalSignif;   //!
   TBranch        *b_muon_scatCurvSignif;   //!
   TBranch        *b_muon_scatNeighSignif;   //!
   TBranch        *b_muon_rho;   //!
   TBranch        *b_muon_qOverPsigma;   //!
   TBranch        *b_muon_qOverPsignif;   //!
   TBranch        *b_muon_reducedChi2;   //!
   TBranch        *b_muon_numPrecLayers;   //!
   TBranch        *b_muon_topoetcone20;   //!
   TBranch        *b_muon_topoetcone30;   //!
   TBranch        *b_muon_topoetcone40;   //!
   TBranch        *b_muon_ptvarcone20;   //!
   TBranch        *b_muon_ptvarcone30;   //!
   TBranch        *b_muon_ptvarcone40;   //!
   TBranch        *b_muon_sharesTrk;   //!
   TBranch        *b_muon_passOR;   //!
   TBranch        *b_muon_isQMisID;   //!
   TBranch        *b_muon_match_HLT_2mu10;   //!
   TBranch        *b_muon_match_HLT_2mu14;   //!
   TBranch        *b_muon_match_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_muon_match_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_muon_match_HLT_e17_loose_mu14;   //!
   TBranch        *b_muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_muon_match_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_muon_match_HLT_e7_lhmedium_nod0_mu24;   //!
   TBranch        *b_muon_match_HLT_e7_medium_mu24;   //!
   TBranch        *b_muon_match_HLT_mu10;   //!
   TBranch        *b_muon_match_HLT_mu14;   //!
   TBranch        *b_muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo;   //!
   TBranch        *b_muon_match_HLT_mu14_tau25_medium1_tracktwo;   //!
   TBranch        *b_muon_match_HLT_mu18;   //!
   TBranch        *b_muon_match_HLT_mu18_mu8noL1;   //!
   TBranch        *b_muon_match_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_muon_match_HLT_mu20_mu8noL1;   //!
   TBranch        *b_muon_match_HLT_mu22_mu8noL1;   //!
   TBranch        *b_muon_match_HLT_mu24;   //!
   TBranch        *b_muon_match_HLT_mu24_iloose;   //!
   TBranch        *b_muon_match_HLT_mu24_imedium;   //!
   TBranch        *b_muon_match_HLT_mu24_ivarloose;   //!
   TBranch        *b_muon_match_HLT_mu24_ivarmedium;   //!
   TBranch        *b_muon_match_HLT_mu26_imedium;   //!
   TBranch        *b_muon_match_HLT_mu26_ivarmedium;   //!
   TBranch        *b_muon_match_HLT_mu40;   //!
   TBranch        *b_muon_match_HLT_mu50;   //!
   TBranch        *b_muon_d0;   //!
   TBranch        *b_muon_z0;   //!
   TBranch        *b_muon_vz;   //!
   TBranch        *b_muon_deltaz0;   //!
   TBranch        *b_muon_author;   //!
   TBranch        *b_muon_type;   //!
   TBranch        *b_muon_truthType;   //!
   TBranch        *b_muon_truthOrigin;   //!
   TBranch        *b_muon_trackType;   //!
   TBranch        *b_muon_trackOrigin;   //!
   TBranch        *b_muon_jetFitterComb;   //!
   TBranch        *b_muon_PromptLeptonInput_sv1_jf_ntrkv;   //!
   TBranch        *b_muon_PromptLeptonInput_TrackJetNTrack;   //!
   TBranch        *b_muon_PromptLeptonInput_DL1mu;   //!
   TBranch        *b_muon_PromptLeptonInput_DRlj;   //!
   TBranch        *b_muon_PromptLeptonInput_LepJetPtFrac;   //!
   TBranch        *b_muon_PromptLeptonInput_PtFrac;   //!
   TBranch        *b_muon_PromptLeptonInput_PtRel;   //!
   TBranch        *b_muon_PromptLeptonInput_ip2;   //!
   TBranch        *b_muon_PromptLeptonInput_ip3;   //!
   TBranch        *b_muon_PromptLeptonInput_rnnip;   //!
   TBranch        *b_muon_PromptLeptonIso_TagWeight;   //!
   TBranch        *b_muon_PromptLeptonVeto_TagWeight;   //!
   TBranch        *b_muon_jet_pt;   //!
   TBranch        *b_muon_jet_eta;   //!
   TBranch        *b_muon_jet_phi;   //!
   TBranch        *b_muon_jet_dr;   //!
   TBranch        *b_muon_jet_ptRel;   //!
   TBranch        *b_muon_jet_numTrk;   //!
   TBranch        *b_muon_jet_sumPtTrk;   //!
   TBranch        *b_muon_jet_MV2c10_Weight;   //!
   TBranch        *b_muon_jet_tagWeightBin;   //!
   TBranch        *b_muon_jet_BDT;   //!
   TBranch        *b_m_jet_pt;   //!
   TBranch        *b_m_jet_eta;   //!
   TBranch        *b_m_jet_phi;   //!
   TBranch        *b_m_jet_E;   //!
   TBranch        *b_m_jet_etaEM;   //!
   TBranch        *b_m_jet_jvt;   //!
   TBranch        *b_m_jet_passjvt;   //!
   TBranch        *b_m_jet_isLooseBad;   //!
   TBranch        *b_m_jet_flavor_weight_MV2c10;   //!
   TBranch        *b_m_jet_numTrk;   //!
   TBranch        *b_m_jet_passOR;   //!
   TBranch        *b_m_jet_passTauOR;   //!
   TBranch        *b_m_jet_flavor_weight_MV2c00;   //!
   TBranch        *b_m_jet_flavor_weight_MV2c20;   //!
   TBranch        *b_m_jet_sumPtTrk;   //!
   TBranch        *b_m_jet_emfrac;   //!
   TBranch        *b_m_jet_flavor_truth_label;   //!
   TBranch        *b_m_jet_flavor_truth_label_ghost;   //!
   TBranch        *b_m_tau_pt;   //!
   TBranch        *b_m_tau_eta;   //!
   TBranch        *b_m_tau_phi;   //!
   TBranch        *b_m_tau_E;   //!
   TBranch        *b_m_tau_charge;   //!
   TBranch        *b_m_tau_numTrack;   //!
   TBranch        *b_m_tau_BDTJetScore;   //!
   TBranch        *b_m_tau_JetBDTSigLoose;   //!
   TBranch        *b_m_tau_JetBDTSigMedium;   //!
   TBranch        *b_m_tau_JetBDTSigTight;   //!
   TBranch        *b_m_tau_MVATESQuality;   //!
   TBranch        *b_m_tau_passOR;   //!
   TBranch        *b_m_tau_passEleOLR;   //!
   TBranch        *b_m_tau_passEleBDT;   //!
   TBranch        *b_m_tau_passMuonOLR;   //!
   TBranch        *b_m_tau_isHadronicTau;   //!
   TBranch        *b_m_tau_MV2c10;   //!
   TBranch        *b_m_tau_tagWeightBin;   //!
   TBranch        *b_m_tau_passJVT;   //!
   TBranch        *b_m_tau_fromPV;   //!
   TBranch        *b_m_tau_BDTEleScoreSigTrans;   //!
   TBranch        *b_m_tau_BDTJetScoreSigTrans;   //!
   TBranch        *b_m_tau_ptTauEtaCalib;   //!
   TBranch        *b_m_tau_etaTauEtaCalib;   //!
   TBranch        *b_m_tau_phiTauEtaCalib;   //!
   TBranch        *b_m_tau_mTauEtaCalib;   //!
   TBranch        *b_m_tau_isTruthMatched;   //!
   TBranch        *b_m_tau_truthOrigin;   //!
   TBranch        *b_m_tau_truthType;   //!
   TBranch        *b_m_tau_truthJetFlavour;   //!
   TBranch        *b_m_tau_ele_match_lhscore;   //!
   TBranch        *b_m_tau_PromptTauInput_TrackJetNTrack;   //!
   TBranch        *b_m_tau_PromptTauInput_DRlj;   //!
   TBranch        *b_m_tau_PromptTauInput_JetF;   //!
   TBranch        *b_m_tau_PromptTauInput_LepJetPtFrac;   //!
   TBranch        *b_m_tau_PromptTauInput_MV2c10rnn;   //!
   TBranch        *b_m_tau_PromptTauInput_SV1;   //!
   TBranch        *b_m_tau_PromptTauInput_ip2;   //!
   TBranch        *b_m_tau_PromptTauInput_ip3;   //!
   TBranch        *b_m_tau_PromptTauInput_rnnip;   //!
   TBranch        *b_m_tau_PromptTauInput_MV2c10;   //!
   TBranch        *b_m_tau_PromptTauVeto;   //!
   TBranch        *b_m_tau_PromptTauIso;   //!
   TBranch        *b_loose;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Index_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_EtaBE2_0;   //!
   TBranch        *b_lep_topoEtcone20_0;   //!
   TBranch        *b_lep_topoEtcone30_0;   //!
   TBranch        *b_lep_topoEtcone40_0;   //!
   TBranch        *b_lep_ptVarcone20_0;   //!
   TBranch        *b_lep_ptVarcone30_0;   //!
   TBranch        *b_lep_ptVarcone40_0;   //!
   TBranch        *b_lep_sigd0PV_0;   //!
   TBranch        *b_lep_Z0SinTheta_0;   //!
   TBranch        *b_lep_d0_0;   //!
   TBranch        *b_lep_z0_0;   //!
   TBranch        *b_lep_vz_0;   //!
   TBranch        *b_lep_deltaz0_0;   //!
   TBranch        *b_lep_isTightLH_0;   //!
   TBranch        *b_lep_isMediumLH_0;   //!
   TBranch        *b_lep_isLooseLH_0;   //!
   TBranch        *b_lep_isTight_0;   //!
   TBranch        *b_lep_isMedium_0;   //!
   TBranch        *b_lep_isLoose_0;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_0;   //!
   TBranch        *b_lep_isolationLoose_0;   //!
   TBranch        *b_lep_isolationGradient_0;   //!
   TBranch        *b_lep_isolationGradientLoose_0;   //!
   TBranch        *b_lep_isolationFixedCutTight_0;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_0;   //!
   TBranch        *b_lep_isolationFixedCutLoose_0;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_isTrigMatchDLT_0;   //!
   TBranch        *b_lep_isPrompt_0;   //!
   TBranch        *b_lep_isFakeLep_0;   //!
   TBranch        *b_lep_isQMisID_0;   //!
   TBranch        *b_lep_isConvPh_0;   //!
   TBranch        *b_lep_isExtConvPh_0;   //!
   TBranch        *b_lep_isIntConvPh_0;   //!
   TBranch        *b_lep_isISR_FSR_Ph_0;   //!
   TBranch        *b_lep_isBrems_0;   //!
   TBranch        *b_lep_chargeIDBDTLoose_0;   //!
   TBranch        *b_lep_chargeIDBDTMedium_0;   //!
   TBranch        *b_lep_chargeIDBDTTight_0;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_0;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_0;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_0;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_0;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_0;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_0;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_0;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_0;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_0;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_0;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_0;   //!
   TBranch        *b_lep_jet_Pt_0;   //!
   TBranch        *b_lep_jet_nTrk_0;   //!
   TBranch        *b_lep_jet_sumPtTrk_0;   //!
   TBranch        *b_lep_jet_mv2c10_0;   //!
   TBranch        *b_lep_jet_deltaR_0;   //!
   TBranch        *b_lep_jet_ptRel_0;   //!
   TBranch        *b_lep_jet_ptOverMuPt_0;   //!
   TBranch        *b_lep_jet_BDT_0;   //!
   TBranch        *b_lep_isTruthMatched_0;   //!
   TBranch        *b_lep_truthType_0;   //!
   TBranch        *b_lep_truthOrigin_0;   //!
   TBranch        *b_lep_truthPdgId_0;   //!
   TBranch        *b_lep_truthStatus_0;   //!
   TBranch        *b_lep_truthParentType_0;   //!
   TBranch        *b_lep_truthParentOrigin_0;   //!
   TBranch        *b_lep_truthParentPdgId_0;   //!
   TBranch        *b_lep_truthParentStatus_0;   //!
   TBranch        *b_lep_truthPt_0;   //!
   TBranch        *b_lep_truthEta_0;   //!
   TBranch        *b_lep_truthPhi_0;   //!
   TBranch        *b_lep_truthM_0;   //!
   TBranch        *b_lep_truthE_0;   //!
   TBranch        *b_lep_truthRapidity_0;   //!
   TBranch        *b_lep_ambiguityType_0;   //!
   TBranch        *b_lep_SFIDLoose_0;   //!
   TBranch        *b_lep_SFIDTight_0;   //!
   TBranch        *b_lep_SFTrigLoose_0;   //!
   TBranch        *b_lep_SFTrigTight_0;   //!
   TBranch        *b_lep_EffTrigLoose_0;   //!
   TBranch        *b_lep_EffTrigTight_0;   //!
   TBranch        *b_lep_SFIsoLoose_0;   //!
   TBranch        *b_lep_SFIsoTight_0;   //!
   TBranch        *b_lep_SFReco_0;   //!
   TBranch        *b_lep_SFTTVA_0;   //!
   TBranch        *b_lep_SFObjLoose_0;   //!
   TBranch        *b_lep_SFObjTight_0;   //!
   TBranch        *b_lep_nInnerPix_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_Index_1;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_Phi_1;   //!
   TBranch        *b_lep_EtaBE2_1;   //!
   TBranch        *b_lep_topoEtcone20_1;   //!
   TBranch        *b_lep_topoEtcone30_1;   //!
   TBranch        *b_lep_topoEtcone40_1;   //!
   TBranch        *b_lep_ptVarcone20_1;   //!
   TBranch        *b_lep_ptVarcone30_1;   //!
   TBranch        *b_lep_ptVarcone40_1;   //!
   TBranch        *b_lep_sigd0PV_1;   //!
   TBranch        *b_lep_Z0SinTheta_1;   //!
   TBranch        *b_lep_d0_1;   //!
   TBranch        *b_lep_z0_1;   //!
   TBranch        *b_lep_vz_1;   //!
   TBranch        *b_lep_deltaz0_1;   //!
   TBranch        *b_lep_isTightLH_1;   //!
   TBranch        *b_lep_isMediumLH_1;   //!
   TBranch        *b_lep_isLooseLH_1;   //!
   TBranch        *b_lep_isTight_1;   //!
   TBranch        *b_lep_isMedium_1;   //!
   TBranch        *b_lep_isLoose_1;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_1;   //!
   TBranch        *b_lep_isolationLoose_1;   //!
   TBranch        *b_lep_isolationGradient_1;   //!
   TBranch        *b_lep_isolationGradientLoose_1;   //!
   TBranch        *b_lep_isolationFixedCutTight_1;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_1;   //!
   TBranch        *b_lep_isolationFixedCutLoose_1;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_isTrigMatchDLT_1;   //!
   TBranch        *b_lep_isPrompt_1;   //!
   TBranch        *b_lep_isFakeLep_1;   //!
   TBranch        *b_lep_isQMisID_1;   //!
   TBranch        *b_lep_isConvPh_1;   //!
   TBranch        *b_lep_isExtConvPh_1;   //!
   TBranch        *b_lep_isIntConvPh_1;   //!
   TBranch        *b_lep_isISR_FSR_Ph_1;   //!
   TBranch        *b_lep_isBrems_1;   //!
   TBranch        *b_lep_chargeIDBDTLoose_1;   //!
   TBranch        *b_lep_chargeIDBDTMedium_1;   //!
   TBranch        *b_lep_chargeIDBDTTight_1;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_1;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_1;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_1;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_1;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_1;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_1;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_1;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_1;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_1;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_1;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_1;   //!
   TBranch        *b_lep_jet_Pt_1;   //!
   TBranch        *b_lep_jet_nTrk_1;   //!
   TBranch        *b_lep_jet_sumPtTrk_1;   //!
   TBranch        *b_lep_jet_mv2c10_1;   //!
   TBranch        *b_lep_jet_deltaR_1;   //!
   TBranch        *b_lep_jet_ptRel_1;   //!
   TBranch        *b_lep_jet_ptOverMuPt_1;   //!
   TBranch        *b_lep_jet_BDT_1;   //!
   TBranch        *b_lep_isTruthMatched_1;   //!
   TBranch        *b_lep_truthType_1;   //!
   TBranch        *b_lep_truthOrigin_1;   //!
   TBranch        *b_lep_truthPdgId_1;   //!
   TBranch        *b_lep_truthStatus_1;   //!
   TBranch        *b_lep_truthParentType_1;   //!
   TBranch        *b_lep_truthParentOrigin_1;   //!
   TBranch        *b_lep_truthParentPdgId_1;   //!
   TBranch        *b_lep_truthParentStatus_1;   //!
   TBranch        *b_lep_truthPt_1;   //!
   TBranch        *b_lep_truthEta_1;   //!
   TBranch        *b_lep_truthPhi_1;   //!
   TBranch        *b_lep_truthM_1;   //!
   TBranch        *b_lep_truthE_1;   //!
   TBranch        *b_lep_truthRapidity_1;   //!
   TBranch        *b_lep_ambiguityType_1;   //!
   TBranch        *b_lep_SFIDLoose_1;   //!
   TBranch        *b_lep_SFIDTight_1;   //!
   TBranch        *b_lep_SFTrigLoose_1;   //!
   TBranch        *b_lep_SFTrigTight_1;   //!
   TBranch        *b_lep_EffTrigLoose_1;   //!
   TBranch        *b_lep_EffTrigTight_1;   //!
   TBranch        *b_lep_SFIsoLoose_1;   //!
   TBranch        *b_lep_SFIsoTight_1;   //!
   TBranch        *b_lep_SFReco_1;   //!
   TBranch        *b_lep_SFTTVA_1;   //!
   TBranch        *b_lep_SFObjLoose_1;   //!
   TBranch        *b_lep_SFObjTight_1;   //!
   TBranch        *b_lep_nInnerPix_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_Index_2;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_Phi_2;   //!
   TBranch        *b_lep_EtaBE2_2;   //!
   TBranch        *b_lep_topoEtcone20_2;   //!
   TBranch        *b_lep_topoEtcone30_2;   //!
   TBranch        *b_lep_topoEtcone40_2;   //!
   TBranch        *b_lep_ptVarcone20_2;   //!
   TBranch        *b_lep_ptVarcone30_2;   //!
   TBranch        *b_lep_ptVarcone40_2;   //!
   TBranch        *b_lep_sigd0PV_2;   //!
   TBranch        *b_lep_Z0SinTheta_2;   //!
   TBranch        *b_lep_d0_2;   //!
   TBranch        *b_lep_z0_2;   //!
   TBranch        *b_lep_vz_2;   //!
   TBranch        *b_lep_deltaz0_2;   //!
   TBranch        *b_lep_isTightLH_2;   //!
   TBranch        *b_lep_isMediumLH_2;   //!
   TBranch        *b_lep_isLooseLH_2;   //!
   TBranch        *b_lep_isTight_2;   //!
   TBranch        *b_lep_isMedium_2;   //!
   TBranch        *b_lep_isLoose_2;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_2;   //!
   TBranch        *b_lep_isolationLoose_2;   //!
   TBranch        *b_lep_isolationGradient_2;   //!
   TBranch        *b_lep_isolationGradientLoose_2;   //!
   TBranch        *b_lep_isolationFixedCutTight_2;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_2;   //!
   TBranch        *b_lep_isolationFixedCutLoose_2;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_isTrigMatchDLT_2;   //!
   TBranch        *b_lep_isPrompt_2;   //!
   TBranch        *b_lep_isFakeLep_2;   //!
   TBranch        *b_lep_isQMisID_2;   //!
   TBranch        *b_lep_isConvPh_2;   //!
   TBranch        *b_lep_isExtConvPh_2;   //!
   TBranch        *b_lep_isIntConvPh_2;   //!
   TBranch        *b_lep_isISR_FSR_Ph_2;   //!
   TBranch        *b_lep_isBrems_2;   //!
   TBranch        *b_lep_chargeIDBDTLoose_2;   //!
   TBranch        *b_lep_chargeIDBDTMedium_2;   //!
   TBranch        *b_lep_chargeIDBDTTight_2;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_2;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_2;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_2;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_2;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_2;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_2;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_2;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_2;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_2;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_2;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_2;   //!
   TBranch        *b_lep_jet_Pt_2;   //!
   TBranch        *b_lep_jet_nTrk_2;   //!
   TBranch        *b_lep_jet_sumPtTrk_2;   //!
   TBranch        *b_lep_jet_mv2c10_2;   //!
   TBranch        *b_lep_jet_deltaR_2;   //!
   TBranch        *b_lep_jet_ptRel_2;   //!
   TBranch        *b_lep_jet_ptOverMuPt_2;   //!
   TBranch        *b_lep_jet_BDT_2;   //!
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_truthStatus_2;   //!
   TBranch        *b_lep_truthParentType_2;   //!
   TBranch        *b_lep_truthParentOrigin_2;   //!
   TBranch        *b_lep_truthParentPdgId_2;   //!
   TBranch        *b_lep_truthParentStatus_2;   //!
   TBranch        *b_lep_truthPt_2;   //!
   TBranch        *b_lep_truthEta_2;   //!
   TBranch        *b_lep_truthPhi_2;   //!
   TBranch        *b_lep_truthM_2;   //!
   TBranch        *b_lep_truthE_2;   //!
   TBranch        *b_lep_truthRapidity_2;   //!
   TBranch        *b_lep_ambiguityType_2;   //!
   TBranch        *b_lep_SFIDLoose_2;   //!
   TBranch        *b_lep_SFIDTight_2;   //!
   TBranch        *b_lep_SFTrigLoose_2;   //!
   TBranch        *b_lep_SFTrigTight_2;   //!
   TBranch        *b_lep_EffTrigLoose_2;   //!
   TBranch        *b_lep_EffTrigTight_2;   //!
   TBranch        *b_lep_SFIsoLoose_2;   //!
   TBranch        *b_lep_SFIsoTight_2;   //!
   TBranch        *b_lep_SFReco_2;   //!
   TBranch        *b_lep_SFTTVA_2;   //!
   TBranch        *b_lep_SFObjLoose_2;   //!
   TBranch        *b_lep_SFObjTight_2;   //!
   TBranch        *b_lep_nInnerPix_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Index_3;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_Phi_3;   //!
   TBranch        *b_lep_EtaBE2_3;   //!
   TBranch        *b_lep_topoEtcone20_3;   //!
   TBranch        *b_lep_topoEtcone30_3;   //!
   TBranch        *b_lep_topoEtcone40_3;   //!
   TBranch        *b_lep_ptVarcone20_3;   //!
   TBranch        *b_lep_ptVarcone30_3;   //!
   TBranch        *b_lep_ptVarcone40_3;   //!
   TBranch        *b_lep_sigd0PV_3;   //!
   TBranch        *b_lep_Z0SinTheta_3;   //!
   TBranch        *b_lep_d0_3;   //!
   TBranch        *b_lep_z0_3;   //!
   TBranch        *b_lep_vz_3;   //!
   TBranch        *b_lep_deltaz0_3;   //!
   TBranch        *b_lep_isTightLH_3;   //!
   TBranch        *b_lep_isMediumLH_3;   //!
   TBranch        *b_lep_isLooseLH_3;   //!
   TBranch        *b_lep_isTight_3;   //!
   TBranch        *b_lep_isMedium_3;   //!
   TBranch        *b_lep_isLoose_3;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_3;   //!
   TBranch        *b_lep_isolationLoose_3;   //!
   TBranch        *b_lep_isolationGradient_3;   //!
   TBranch        *b_lep_isolationGradientLoose_3;   //!
   TBranch        *b_lep_isolationFixedCutTight_3;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_3;   //!
   TBranch        *b_lep_isolationFixedCutLoose_3;   //!
   TBranch        *b_lep_isTrigMatch_3;   //!
   TBranch        *b_lep_isTrigMatchDLT_3;   //!
   TBranch        *b_lep_isPrompt_3;   //!
   TBranch        *b_lep_isFakeLep_3;   //!
   TBranch        *b_lep_isQMisID_3;   //!
   TBranch        *b_lep_isConvPh_3;   //!
   TBranch        *b_lep_isExtConvPh_3;   //!
   TBranch        *b_lep_isIntConvPh_3;   //!
   TBranch        *b_lep_isISR_FSR_Ph_3;   //!
   TBranch        *b_lep_isBrems_3;   //!
   TBranch        *b_lep_chargeIDBDTLoose_3;   //!
   TBranch        *b_lep_chargeIDBDTMedium_3;   //!
   TBranch        *b_lep_chargeIDBDTTight_3;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_3;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_3;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_3;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_3;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_3;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_3;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_3;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_3;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_3;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_3;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_3;   //!
   TBranch        *b_lep_jet_Pt_3;   //!
   TBranch        *b_lep_jet_nTrk_3;   //!
   TBranch        *b_lep_jet_sumPtTrk_3;   //!
   TBranch        *b_lep_jet_mv2c10_3;   //!
   TBranch        *b_lep_jet_deltaR_3;   //!
   TBranch        *b_lep_jet_ptRel_3;   //!
   TBranch        *b_lep_jet_ptOverMuPt_3;   //!
   TBranch        *b_lep_jet_BDT_3;   //!
   TBranch        *b_lep_isTruthMatched_3;   //!
   TBranch        *b_lep_truthType_3;   //!
   TBranch        *b_lep_truthOrigin_3;   //!
   TBranch        *b_lep_truthPdgId_3;   //!
   TBranch        *b_lep_truthStatus_3;   //!
   TBranch        *b_lep_truthParentType_3;   //!
   TBranch        *b_lep_truthParentOrigin_3;   //!
   TBranch        *b_lep_truthParentPdgId_3;   //!
   TBranch        *b_lep_truthParentStatus_3;   //!
   TBranch        *b_lep_truthPt_3;   //!
   TBranch        *b_lep_truthEta_3;   //!
   TBranch        *b_lep_truthPhi_3;   //!
   TBranch        *b_lep_truthM_3;   //!
   TBranch        *b_lep_truthE_3;   //!
   TBranch        *b_lep_truthRapidity_3;   //!
   TBranch        *b_lep_ambiguityType_3;   //!
   TBranch        *b_lep_SFIDLoose_3;   //!
   TBranch        *b_lep_SFIDTight_3;   //!
   TBranch        *b_lep_SFTrigLoose_3;   //!
   TBranch        *b_lep_SFTrigTight_3;   //!
   TBranch        *b_lep_EffTrigLoose_3;   //!
   TBranch        *b_lep_EffTrigTight_3;   //!
   TBranch        *b_lep_SFIsoLoose_3;   //!
   TBranch        *b_lep_SFIsoTight_3;   //!
   TBranch        *b_lep_SFReco_3;   //!
   TBranch        *b_lep_SFTTVA_3;   //!
   TBranch        *b_lep_SFObjLoose_3;   //!
   TBranch        *b_lep_SFObjTight_3;   //!
   TBranch        *b_lep_nInnerPix_3;   //!
   TBranch        *b_lep_ID_4;   //!
   TBranch        *b_lep_Index_4;   //!
   TBranch        *b_lep_Pt_4;   //!
   TBranch        *b_lep_E_4;   //!
   TBranch        *b_lep_Eta_4;   //!
   TBranch        *b_lep_Phi_4;   //!
   TBranch        *b_lep_EtaBE2_4;   //!
   TBranch        *b_lep_topoEtcone20_4;   //!
   TBranch        *b_lep_topoEtcone30_4;   //!
   TBranch        *b_lep_topoEtcone40_4;   //!
   TBranch        *b_lep_ptVarcone20_4;   //!
   TBranch        *b_lep_ptVarcone30_4;   //!
   TBranch        *b_lep_ptVarcone40_4;   //!
   TBranch        *b_lep_sigd0PV_4;   //!
   TBranch        *b_lep_Z0SinTheta_4;   //!
   TBranch        *b_lep_d0_4;   //!
   TBranch        *b_lep_z0_4;   //!
   TBranch        *b_lep_vz_4;   //!
   TBranch        *b_lep_deltaz0_4;   //!
   TBranch        *b_lep_isTightLH_4;   //!
   TBranch        *b_lep_isMediumLH_4;   //!
   TBranch        *b_lep_isLooseLH_4;   //!
   TBranch        *b_lep_isTight_4;   //!
   TBranch        *b_lep_isMedium_4;   //!
   TBranch        *b_lep_isLoose_4;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_4;   //!
   TBranch        *b_lep_isolationLoose_4;   //!
   TBranch        *b_lep_isolationGradient_4;   //!
   TBranch        *b_lep_isolationGradientLoose_4;   //!
   TBranch        *b_lep_isolationFixedCutTight_4;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_4;   //!
   TBranch        *b_lep_isolationFixedCutLoose_4;   //!
   TBranch        *b_lep_isTrigMatch_4;   //!
   TBranch        *b_lep_isTrigMatchDLT_4;   //!
   TBranch        *b_lep_isPrompt_4;   //!
   TBranch        *b_lep_isFakeLep_4;   //!
   TBranch        *b_lep_isQMisID_4;   //!
   TBranch        *b_lep_isConvPh_4;   //!
   TBranch        *b_lep_isExtConvPh_4;   //!
   TBranch        *b_lep_isIntConvPh_4;   //!
   TBranch        *b_lep_isISR_FSR_Ph_4;   //!
   TBranch        *b_lep_isBrems_4;   //!
   TBranch        *b_lep_chargeIDBDTLoose_4;   //!
   TBranch        *b_lep_chargeIDBDTMedium_4;   //!
   TBranch        *b_lep_chargeIDBDTTight_4;   //!
   TBranch        *b_lep_promptLeptonInput_sv1_jf_ntrkv_4;   //!
   TBranch        *b_lep_promptLeptonInput_TrackJetNTrack_4;   //!
   TBranch        *b_lep_promptLeptonInput_DL1mu_4;   //!
   TBranch        *b_lep_promptLeptonInput_DRlj_4;   //!
   TBranch        *b_lep_promptLeptonInput_LepJetPtFrac_4;   //!
   TBranch        *b_lep_promptLeptonInput_PtFrac_4;   //!
   TBranch        *b_lep_promptLeptonInput_PtRel_4;   //!
   TBranch        *b_lep_promptLeptonInput_ip2_4;   //!
   TBranch        *b_lep_promptLeptonInput_ip3_4;   //!
   TBranch        *b_lep_promptLeptonInput_rnnip_4;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_4;   //!
   TBranch        *b_lep_jet_Pt_4;   //!
   TBranch        *b_lep_jet_nTrk_4;   //!
   TBranch        *b_lep_jet_sumPtTrk_4;   //!
   TBranch        *b_lep_jet_mv2c10_4;   //!
   TBranch        *b_lep_jet_deltaR_4;   //!
   TBranch        *b_lep_jet_ptRel_4;   //!
   TBranch        *b_lep_jet_ptOverMuPt_4;   //!
   TBranch        *b_lep_jet_BDT_4;   //!
   TBranch        *b_lep_isTruthMatched_4;   //!
   TBranch        *b_lep_truthType_4;   //!
   TBranch        *b_lep_truthOrigin_4;   //!
   TBranch        *b_lep_truthPdgId_4;   //!
   TBranch        *b_lep_truthStatus_4;   //!
   TBranch        *b_lep_truthParentType_4;   //!
   TBranch        *b_lep_truthParentOrigin_4;   //!
   TBranch        *b_lep_truthParentPdgId_4;   //!
   TBranch        *b_lep_truthParentStatus_4;   //!
   TBranch        *b_lep_truthPt_4;   //!
   TBranch        *b_lep_truthEta_4;   //!
   TBranch        *b_lep_truthPhi_4;   //!
   TBranch        *b_lep_truthM_4;   //!
   TBranch        *b_lep_truthE_4;   //!
   TBranch        *b_lep_truthRapidity_4;   //!
   TBranch        *b_lep_ambiguityType_4;   //!
   TBranch        *b_lep_SFIDLoose_4;   //!
   TBranch        *b_lep_SFIDTight_4;   //!
   TBranch        *b_lep_SFTrigLoose_4;   //!
   TBranch        *b_lep_SFTrigTight_4;   //!
   TBranch        *b_lep_EffTrigLoose_4;   //!
   TBranch        *b_lep_EffTrigTight_4;   //!
   TBranch        *b_lep_SFIsoLoose_4;   //!
   TBranch        *b_lep_SFIsoTight_4;   //!
   TBranch        *b_lep_SFReco_4;   //!
   TBranch        *b_lep_SFTTVA_4;   //!
   TBranch        *b_lep_SFObjLoose_4;   //!
   TBranch        *b_lep_SFObjTight_4;   //!
   TBranch        *b_lep_nInnerPix_4;   //!
   TBranch        *b_tau_pt_0;   //!
   TBranch        *b_tau_eta_0;   //!
   TBranch        *b_tau_phi_0;   //!
   TBranch        *b_tau_charge_0;   //!
   TBranch        *b_tau_E_0;   //!
   TBranch        *b_tau_BDTJetScore_0;   //!
   TBranch        *b_tau_JetBDTSigLoose_0;   //!
   TBranch        *b_tau_JetBDTSigMedium_0;   //!
   TBranch        *b_tau_JetBDTSigTight_0;   //!
   TBranch        *b_tau_numTrack_0;   //!
   TBranch        *b_tau_isHadronic_0;   //!
   TBranch        *b_tau_tagWeightBin_0;   //!
   TBranch        *b_tau_MV2c10_0;   //!
   TBranch        *b_tau_fromPV_0;   //!
   TBranch        *b_tau_SFTight_0;   //!
   TBranch        *b_tau_SFLoose_0;   //!
   TBranch        *b_tau_passEleOLR_0;   //!
   TBranch        *b_tau_passEleBDT_0;   //!
   TBranch        *b_tau_passMuonOLR_0;   //!
   TBranch        *b_tau_BDTEleScoreSigTrans_0;   //!
   TBranch        *b_tau_BDTJetScoreSigTrans_0;   //!
   TBranch        *b_tau_truthOrigin_0;   //!
   TBranch        *b_tau_truthType_0;   //!
   TBranch        *b_tau_truthJetFlavour_0;   //!
   TBranch        *b_tau_promptTauInput_TrackJetNTrack_0;   //!
   TBranch        *b_tau_promptTauInput_JetF_0;   //!
   TBranch        *b_tau_promptTauInput_DRlj_0;   //!
   TBranch        *b_tau_promptTauInput_LepJetPtFrac_0;   //!
   TBranch        *b_tau_promptTauInput_SV1_0;   //!
   TBranch        *b_tau_promptTauInput_MV2c10rnn_0;   //!
   TBranch        *b_tau_promptTauInput_ip2_0;   //!
   TBranch        *b_tau_promptTauInput_ip3_0;   //!
   TBranch        *b_tau_promptTauInput_rnnip_0;   //!
   TBranch        *b_tau_promptTauInput_MV2c10_0;   //!
   TBranch        *b_tau_promptTauVeto_0;   //!
   TBranch        *b_tau_promptTauIso_0;   //!
   TBranch        *b_tau_pt_1;   //!
   TBranch        *b_tau_eta_1;   //!
   TBranch        *b_tau_phi_1;   //!
   TBranch        *b_tau_charge_1;   //!
   TBranch        *b_tau_E_1;   //!
   TBranch        *b_tau_BDTJetScore_1;   //!
   TBranch        *b_tau_JetBDTSigLoose_1;   //!
   TBranch        *b_tau_JetBDTSigMedium_1;   //!
   TBranch        *b_tau_JetBDTSigTight_1;   //!
   TBranch        *b_tau_numTrack_1;   //!
   TBranch        *b_tau_isHadronic_1;   //!
   TBranch        *b_tau_tagWeightBin_1;   //!
   TBranch        *b_tau_MV2c10_1;   //!
   TBranch        *b_tau_fromPV_1;   //!
   TBranch        *b_tau_SFTight_1;   //!
   TBranch        *b_tau_SFLoose_1;   //!
   TBranch        *b_tau_passEleOLR_1;   //!
   TBranch        *b_tau_passEleBDT_1;   //!
   TBranch        *b_tau_passMuonOLR_1;   //!
   TBranch        *b_tau_BDTEleScoreSigTrans_1;   //!
   TBranch        *b_tau_BDTJetScoreSigTrans_1;   //!
   TBranch        *b_tau_truthOrigin_1;   //!
   TBranch        *b_tau_truthType_1;   //!
   TBranch        *b_tau_truthJetFlavour_1;   //!
   TBranch        *b_tau_promptTauInput_TrackJetNTrack_1;   //!
   TBranch        *b_tau_promptTauInput_JetF_1;   //!
   TBranch        *b_tau_promptTauInput_DRlj_1;   //!
   TBranch        *b_tau_promptTauInput_LepJetPtFrac_1;   //!
   TBranch        *b_tau_promptTauInput_SV1_1;   //!
   TBranch        *b_tau_promptTauInput_MV2c10rnn_1;   //!
   TBranch        *b_tau_promptTauInput_ip2_1;   //!
   TBranch        *b_tau_promptTauInput_ip3_1;   //!
   TBranch        *b_tau_promptTauInput_rnnip_1;   //!
   TBranch        *b_tau_promptTauInput_MV2c10_1;   //!
   TBranch        *b_tau_promptTauVeto_1;   //!
   TBranch        *b_tau_promptTauIso_1;   //!
   TBranch        *b_onelep_type;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_quadlep_type;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_isQMisIDEvent;   //!
   TBranch        *b_isFakeEvent;   //!
   TBranch        *b_isLepFromPhEvent;   //!
   TBranch        *b_Mll01;   //!
   TBranch        *b_Ptll01;   //!
   TBranch        *b_DRll01;   //!
   TBranch        *b_matchDLTll01;   //!
   TBranch        *b_Mlll012;   //!
   TBranch        *b_Mllll0123;   //!
   TBranch        *b_Mllll0124;   //!
   TBranch        *b_Mlll013;   //!
   TBranch        *b_Mllll0134;   //!
   TBranch        *b_Mlll014;   //!
   TBranch        *b_Mll02;   //!
   TBranch        *b_Ptll02;   //!
   TBranch        *b_DRll02;   //!
   TBranch        *b_matchDLTll02;   //!
   TBranch        *b_Mlll023;   //!
   TBranch        *b_Mllll0234;   //!
   TBranch        *b_Mlll024;   //!
   TBranch        *b_Mll03;   //!
   TBranch        *b_Ptll03;   //!
   TBranch        *b_DRll03;   //!
   TBranch        *b_matchDLTll03;   //!
   TBranch        *b_Mlll034;   //!
   TBranch        *b_Mll04;   //!
   TBranch        *b_Ptll04;   //!
   TBranch        *b_DRll04;   //!
   TBranch        *b_matchDLTll04;   //!
   TBranch        *b_Mll12;   //!
   TBranch        *b_Ptll12;   //!
   TBranch        *b_DRll12;   //!
   TBranch        *b_matchDLTll12;   //!
   TBranch        *b_Mlll123;   //!
   TBranch        *b_Mllll1234;   //!
   TBranch        *b_Mlll124;   //!
   TBranch        *b_Mll13;   //!
   TBranch        *b_Ptll13;   //!
   TBranch        *b_DRll13;   //!
   TBranch        *b_matchDLTll13;   //!
   TBranch        *b_Mlll134;   //!
   TBranch        *b_Mll14;   //!
   TBranch        *b_Ptll14;   //!
   TBranch        *b_DRll14;   //!
   TBranch        *b_matchDLTll14;   //!
   TBranch        *b_Mll23;   //!
   TBranch        *b_Ptll23;   //!
   TBranch        *b_DRll23;   //!
   TBranch        *b_matchDLTll23;   //!
   TBranch        *b_Mlll234;   //!
   TBranch        *b_Mll24;   //!
   TBranch        *b_Ptll24;   //!
   TBranch        *b_DRll24;   //!
   TBranch        *b_matchDLTll24;   //!
   TBranch        *b_Mll34;   //!
   TBranch        *b_Ptll34;   //!
   TBranch        *b_DRll34;   //!
   TBranch        *b_matchDLTll34;   //!
   TBranch        *b_best_Z_Mll;   //!
   TBranch        *b_best_Z_other_MtLepMet;   //!
   TBranch        *b_best_Z_other_Mll;   //!
   TBranch        *b_minOSSFMll;   //!
   TBranch        *b_minOSMll;   //!
   TBranch        *b_nJets_OR_T;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_nTruthJets;   //!
   TBranch        *b_nTruthJets_OR;   //!
   TBranch        *b_nJets_OR_T_MV2c10_60;   //!
   TBranch        *b_nJets_OR_T_MV2c10_70;   //!
   TBranch        *b_nJets_OR_T_MV2c10_77;   //!
   TBranch        *b_nJets_OR_T_MV2c10_85;   //!
   TBranch        *b_nJets_OR_MV2c10_85;   //!
   TBranch        *b_nJets_OR_MV2c10_60;   //!
   TBranch        *b_nJets_OR_MV2c10_77;   //!
   TBranch        *b_nJets_OR_MV2c10_70;   //!
   TBranch        *b_nJets_OR_T_DL1_60;   //!
   TBranch        *b_nJets_OR_T_DL1_70;   //!
   TBranch        *b_nJets_OR_T_DL1_77;   //!
   TBranch        *b_nJets_OR_T_DL1_85;   //!
   TBranch        *b_nJets_OR_DL1_85;   //!
   TBranch        *b_nJets_OR_DL1_60;   //!
   TBranch        *b_nJets_OR_DL1_77;   //!
   TBranch        *b_nJets_OR_DL1_70;   //!
   TBranch        *b_nTaus_OR_Pt25;   //!
   TBranch        *b_isBlinded;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_lead_jetPt;   //!
   TBranch        *b_lead_jetEta;   //!
   TBranch        *b_lead_jetPhi;   //!
   TBranch        *b_lead_jetE;   //!
   TBranch        *b_sublead_jetPt;   //!
   TBranch        *b_sublead_jetEta;   //!
   TBranch        *b_sublead_jetPhi;   //!
   TBranch        *b_sublead_jetE;   //!
   TBranch        *b_selected_jets;   //!
   TBranch        *b_selected_jets_T;   //!
   TBranch        *b_selected_jets_mv2c10_Ordrd;   //!
   TBranch        *b_selected_jets_T_mv2c10_Ordrd;   //!
   TBranch        *b_lepSFIDLoose;   //!
   TBranch        *b_lepSFIDTight;   //!
   TBranch        *b_lepSFIsoLoose;   //!
   TBranch        *b_lepSFIsoTight;   //!
   TBranch        *b_lepSFReco;   //!
   TBranch        *b_lepSFTTVA;   //!
   TBranch        *b_lepSFTrigLoose;   //!
   TBranch        *b_lepSFTrigTight;   //!
   TBranch        *b_lepSFTrigTightLoose;   //!
   TBranch        *b_lepSFTrigLooseTight;   //!
   TBranch        *b_lepEffTrigLoose;   //!
   TBranch        *b_lepEffTrigTight;   //!
   TBranch        *b_lepEffTrigTightLoose;   //!
   TBranch        *b_lepEffTrigLooseTight;   //!
   TBranch        *b_lepDataEffTrigLoose;   //!
   TBranch        *b_lepDataEffTrigTight;   //!
   TBranch        *b_lepDataEffTrigTightLoose;   //!
   TBranch        *b_lepDataEffTrigLooseTight;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_tauSFTight;   //!
   TBranch        *b_tauSFLoose;   //!
   TBranch        *b_lepSFTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepEffTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_EFF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTightLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigLooseTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigTightLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepEffTrigLooseTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_HIGHPT_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_HIGHPT_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_JETID_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_TOTAL_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_TOTAL_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_HIGHPT_UP;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_HIGHPT_UP;   //!
   TBranch        *b_tauSFTight_TAU_SF_RECO_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN;   //!
   TBranch        *b_mc_norm;   //!
   TBranch        *b_l2tau_bdt;   //!
   TBranch        *b_tau_leadpt;   //!
   TBranch        *b_tau_subpt;   //!
   TBranch        *b_tau_btag70_0;   //!
   TBranch        *b_tau_tight_0;   //!
   TBranch        *b_tau_truth_0;   //!
   TBranch        *b_tau_btag70_1;   //!
   TBranch        *b_tau_tight_1;   //!
   TBranch        *b_tau_truth_1;   //!
   TBranch        *b_l2tau_htjets;   //!
   TBranch        *b_l2tau_jjdr;   //!
   TBranch        *b_l2tau_mtautau;   //!
   TBranch        *b_Channel;   //!
   TBranch        *b_Drhwwvis;   //!
   TBranch        *b_Mtwbvis;   //!
   TBranch        *b_Mhwwvis;   //!
   TBranch        *b_Mhwwqvis;   //!
   TBranch        *b_Msum;   //!
   TBranch        *b_Pthwl0;   //!
   TBranch        *b_Ptlep;   //!
   TBranch        *b_Pthwj;   //!
   TBranch        *b_Ptqj;   //!
   TBranch        *b_Ptbj;   //!
   TBranch        *b_Chisqmin;   //!
   TBranch        *b_Chisqmax;   //!
   TBranch        *b_Lepwiso;   //!
   TBranch        *b_Lepiso;   //!
   TBranch        *b_Bdt;   //!
   TBranch        *b_BdtvsttV;   //!
};

void nominal::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_charge = 0;
   mcEventWeights = 0;
   m_truth_m = 0;
   m_truth_pt = 0;
   m_truth_eta = 0;
   m_truth_phi = 0;
   m_truth_e = 0;
   m_truth_pdgId = 0;
   m_truth_status = 0;
   m_truth_barcode = 0;
   m_truth_parents = 0;
   m_truth_children = 0;
   m_mcevt_pdf_X1 = 0;
   m_mcevt_pdf_X2 = 0;
   m_mcevt_pdf_PDGID1 = 0;
   m_mcevt_pdf_PDGID2 = 0;
   m_mcevt_pdf_Q = 0;
   m_mcevt_pdf_XF1 = 0;
   m_mcevt_pdf_XF2 = 0;
   vtx_x = 0;
   vtx_y = 0;
   vtx_z = 0;
   vtx_type = 0;
   vtx_numTrk = 0;
   electron_isolationLooseTrackOnly = 0;
   muon_isolationLooseTrackOnly = 0;
   electron_isolationLoose = 0;
   muon_isolationLoose = 0;
   electron_isolationGradient = 0;
   muon_isolationGradient = 0;
   electron_isolationGradientLoose = 0;
   muon_isolationGradientLoose = 0;
   electron_isolationFixedCutTightTrackOnly = 0;
   muon_isolationFixedCutTightTrackOnly = 0;
   electron_isolationFixedCutLoose = 0;
   muon_isolationFixedCutLoose = 0;
   electron_isolationFixedCutTight = 0;
   electron_pt = 0;
   electron_eta = 0;
   electron_EtaBE2 = 0;
   electron_phi = 0;
   electron_E = 0;
   electron_ID = 0;
   electron_sigd0PV = 0;
   electron_z0SinTheta = 0;
   electron_topoetcone20 = 0;
   electron_topoetcone30 = 0;
   electron_topoetcone40 = 0;
   electron_ptvarcone20 = 0;
   electron_ptvarcone30 = 0;
   electron_ptvarcone40 = 0;
   electron_isLooseLH = 0;
   electron_isMediumLH = 0;
   electron_isTightLH = 0;
   electron_sharesTrk = 0;
   electron_passOR = 0;
   electron_isQMisID = 0;
   electron_ChargeIDBDTLoose = 0;
   electron_ChargeIDBDTMedium = 0;
   electron_ChargeIDBDTTight = 0;
   electron_match_HLT_2e12_lhloose_L12EM10VH = 0;
   electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH = 0;
   electron_match_HLT_2e12_loose_L12EM10VH = 0;
   electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH = 0;
   electron_match_HLT_2e17_lhvloose_nod0 = 0;
   electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI = 0;
   electron_match_HLT_2e24_lhvloose_nod0 = 0;
   electron_match_HLT_e120_lhloose = 0;
   electron_match_HLT_e12_lhloose = 0;
   electron_match_HLT_e12_loose = 0;
   electron_match_HLT_e140_lhloose = 0;
   electron_match_HLT_e140_lhloose_nod0 = 0;
   electron_match_HLT_e140_loose = 0;
   electron_match_HLT_e17_lhloose = 0;
   electron_match_HLT_e17_lhloose_2e9_lhloose = 0;
   electron_match_HLT_e17_lhloose_mu14 = 0;
   electron_match_HLT_e17_lhloose_nod0_mu14 = 0;
   electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo = 0;
   electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo = 0;
   electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo = 0;
   electron_match_HLT_e17_loose = 0;
   electron_match_HLT_e17_loose_mu14 = 0;
   electron_match_HLT_e24_lhmedium_L1EM18VH = 0;
   electron_match_HLT_e24_lhmedium_L1EM20VH = 0;
   electron_match_HLT_e24_lhmedium_iloose_L1EM18VH = 0;
   electron_match_HLT_e24_lhmedium_nod0_L1EM20VH = 0;
   electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1 = 0;
   electron_match_HLT_e24_lhtight_iloose = 0;
   electron_match_HLT_e24_lhtight_iloose_L1EM20VH = 0;
   electron_match_HLT_e24_lhtight_ivarloose = 0;
   electron_match_HLT_e24_lhtight_nod0_ivarloose = 0;
   electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1 = 0;
   electron_match_HLT_e24_tight_iloose = 0;
   electron_match_HLT_e24_tight_iloose_L1EM20VH = 0;
   electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1 = 0;
   electron_match_HLT_e26_lhtight_iloose = 0;
   electron_match_HLT_e26_lhtight_nod0_ivarloose = 0;
   electron_match_HLT_e26_tight_iloose = 0;
   electron_match_HLT_e300_etcut = 0;
   electron_match_HLT_e5_lhloose = 0;
   electron_match_HLT_e5_loose = 0;
   electron_match_HLT_e60_lhmedium = 0;
   electron_match_HLT_e60_lhmedium_nod0 = 0;
   electron_match_HLT_e60_medium = 0;
   electron_match_HLT_e7_lhmedium_mu24 = 0;
   electron_match_HLT_e7_lhmedium_nod0_mu24 = 0;
   electron_match_HLT_e7_medium_mu24 = 0;
   electron_nInnerPix = 0;
   electron_author = 0;
   electron_d0 = 0;
   electron_z0 = 0;
   electron_vz = 0;
   electron_deltaz0 = 0;
   electron_truthOrigin = 0;
   electron_truthType = 0;
   electron_firstEgMotherPdgId = 0;
   electron_jetFitterComb = 0;
   electron_PromptLeptonInput_sv1_jf_ntrkv = 0;
   electron_PromptLeptonInput_TrackJetNTrack = 0;
   electron_PromptLeptonInput_DL1mu = 0;
   electron_PromptLeptonInput_DRlj = 0;
   electron_PromptLeptonInput_LepJetPtFrac = 0;
   electron_PromptLeptonInput_PtFrac = 0;
   electron_PromptLeptonInput_PtRel = 0;
   electron_PromptLeptonInput_ip2 = 0;
   electron_PromptLeptonInput_ip3 = 0;
   electron_PromptLeptonInput_rnnip = 0;
   electron_PromptLeptonIso_TagWeight = 0;
   electron_PromptLeptonVeto_TagWeight = 0;
   electron_ambiguityType = 0;
   electron_numberOfInnermostPixelLayerHits = 0;
   electron_numberOfInnermostPixelLayerOutliers = 0;
   electron_expectInnerPixelLayerHit = 0;
   muon_pt = 0;
   muon_eta = 0;
   muon_phi = 0;
   muon_E = 0;
   muon_isLoose = 0;
   muon_isMedium = 0;
   muon_isTight = 0;
   muon_ID = 0;
   muon_sigd0PV = 0;
   muon_z0SinTheta = 0;
   muon_momBalSignif = 0;
   muon_scatCurvSignif = 0;
   muon_scatNeighSignif = 0;
   muon_rho = 0;
   muon_qOverPsigma = 0;
   muon_qOverPsignif = 0;
   muon_reducedChi2 = 0;
   muon_numPrecLayers = 0;
   muon_topoetcone20 = 0;
   muon_topoetcone30 = 0;
   muon_topoetcone40 = 0;
   muon_ptvarcone20 = 0;
   muon_ptvarcone30 = 0;
   muon_ptvarcone40 = 0;
   muon_sharesTrk = 0;
   muon_passOR = 0;
   muon_isQMisID = 0;
   muon_match_HLT_2mu10 = 0;
   muon_match_HLT_2mu14 = 0;
   muon_match_HLT_e17_lhloose_mu14 = 0;
   muon_match_HLT_e17_lhloose_nod0_mu14 = 0;
   muon_match_HLT_e17_loose_mu14 = 0;
   muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1 = 0;
   muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1 = 0;
   muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1 = 0;
   muon_match_HLT_e7_lhmedium_mu24 = 0;
   muon_match_HLT_e7_lhmedium_nod0_mu24 = 0;
   muon_match_HLT_e7_medium_mu24 = 0;
   muon_match_HLT_mu10 = 0;
   muon_match_HLT_mu14 = 0;
   muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo = 0;
   muon_match_HLT_mu14_tau25_medium1_tracktwo = 0;
   muon_match_HLT_mu18 = 0;
   muon_match_HLT_mu18_mu8noL1 = 0;
   muon_match_HLT_mu20_iloose_L1MU15 = 0;
   muon_match_HLT_mu20_mu8noL1 = 0;
   muon_match_HLT_mu22_mu8noL1 = 0;
   muon_match_HLT_mu24 = 0;
   muon_match_HLT_mu24_iloose = 0;
   muon_match_HLT_mu24_imedium = 0;
   muon_match_HLT_mu24_ivarloose = 0;
   muon_match_HLT_mu24_ivarmedium = 0;
   muon_match_HLT_mu26_imedium = 0;
   muon_match_HLT_mu26_ivarmedium = 0;
   muon_match_HLT_mu40 = 0;
   muon_match_HLT_mu50 = 0;
   muon_d0 = 0;
   muon_z0 = 0;
   muon_vz = 0;
   muon_deltaz0 = 0;
   muon_author = 0;
   muon_type = 0;
   muon_truthType = 0;
   muon_truthOrigin = 0;
   muon_trackType = 0;
   muon_trackOrigin = 0;
   muon_jetFitterComb = 0;
   muon_PromptLeptonInput_sv1_jf_ntrkv = 0;
   muon_PromptLeptonInput_TrackJetNTrack = 0;
   muon_PromptLeptonInput_DL1mu = 0;
   muon_PromptLeptonInput_DRlj = 0;
   muon_PromptLeptonInput_LepJetPtFrac = 0;
   muon_PromptLeptonInput_PtFrac = 0;
   muon_PromptLeptonInput_PtRel = 0;
   muon_PromptLeptonInput_ip2 = 0;
   muon_PromptLeptonInput_ip3 = 0;
   muon_PromptLeptonInput_rnnip = 0;
   muon_PromptLeptonIso_TagWeight = 0;
   muon_PromptLeptonVeto_TagWeight = 0;
   muon_jet_pt = 0;
   muon_jet_eta = 0;
   muon_jet_phi = 0;
   muon_jet_dr = 0;
   muon_jet_ptRel = 0;
   muon_jet_numTrk = 0;
   muon_jet_sumPtTrk = 0;
   muon_jet_MV2c10_Weight = 0;
   muon_jet_tagWeightBin = 0;
   muon_jet_BDT = 0;
   m_jet_pt = 0;
   m_jet_eta = 0;
   m_jet_phi = 0;
   m_jet_E = 0;
   m_jet_etaEM = 0;
   m_jet_jvt = 0;
   m_jet_passjvt = 0;
   m_jet_isLooseBad = 0;
   m_jet_flavor_weight_MV2c10 = 0;
   m_jet_numTrk = 0;
   m_jet_tagWeightBin = 0;
   m_tau_BDTJetScoreSigTrans = 0;
   m_jet_passOR = 0;
   m_jet_passTauOR = 0;
   m_jet_flavor_weight_MV2c00 = 0;
   m_jet_flavor_weight_MV2c20 = 0;
   m_jet_sumPtTrk = 0;
   m_jet_emfrac = 0;
   m_jet_flavor_truth_label = 0;
   m_jet_flavor_truth_label_ghost = 0;
   m_tau_pt = 0;
   m_tau_eta = 0;
   m_tau_phi = 0;
   m_tau_E = 0;
   m_tau_charge = 0;
   m_tau_numTrack = 0;
   m_tau_BDTJetScore = 0;
   m_tau_JetBDTSigLoose = 0;
   m_tau_JetBDTSigMedium = 0;
   m_tau_JetBDTSigTight = 0;
   m_tau_MVATESQuality = 0;
   m_tau_passOR = 0;
   m_tau_passEleOLR = 0;
   m_tau_passEleBDT = 0;
   m_tau_passMuonOLR = 0;
   m_tau_isHadronicTau = 0;
   m_tau_MV2c10 = 0;
   m_tau_tagWeightBin = 0;
   m_tau_passJVT = 0;
   m_tau_fromPV = 0;
   m_tau_BDTEleScoreSigTrans = 0;
   m_tau_BDTJetScoreSigTrans = 0;
   m_tau_ptTauEtaCalib = 0;
   m_tau_etaTauEtaCalib = 0;
   m_tau_phiTauEtaCalib = 0;
   m_tau_mTauEtaCalib = 0;
   m_tau_isTruthMatched = 0;
   m_tau_truthOrigin = 0;
   m_tau_truthType = 0;
   m_tau_truthJetFlavour = 0;
   m_tau_ele_match_lhscore = 0;
   m_tau_PromptTauInput_TrackJetNTrack = 0;
   m_tau_PromptTauInput_DRlj = 0;
   m_tau_PromptTauInput_JetF = 0;
   m_tau_PromptTauInput_LepJetPtFrac = 0;
   m_tau_PromptTauInput_MV2c10rnn = 0;
   m_tau_PromptTauInput_SV1 = 0;
   m_tau_PromptTauInput_ip2 = 0;
   m_tau_PromptTauInput_ip3 = 0;
   m_tau_PromptTauInput_rnnip = 0;
   m_tau_PromptTauInput_MV2c10 = 0;
   m_tau_PromptTauVeto = 0;
   m_tau_PromptTauIso = 0;
   selected_jets = 0;
   selected_jets_T = 0;
   selected_jets_mv2c10_Ordrd = 0;
   selected_jets_T_mv2c10_Ordrd = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;

   tree->SetMakeClass(1);
   if(reduce>1 && reduce != 0){
      tree->SetBranchAddress("t1mass",&t1_mass);
      tree->SetBranchAddress("tautaumass",&higgs_mass);
      tree->SetBranchAddress("wmass",&Wmass);
      tree->SetBranchAddress("t2mass",&t2_mass);
   }
   if(reduce>2 && reduce != 0){
      tree->SetBranchAddress("neutrino_pt" , &neutrino_pt );
      tree->SetBranchAddress("neutrino_eta", &neutrino_eta);
      tree->SetBranchAddress("neutrino_phi", &neutrino_phi);
      tree->SetBranchAddress("neutrino_m"  , &neutrino_m);
      tree->SetBranchAddress("weight",&weight);
      tree->SetBranchAddress("cjet_index", &cjet_index );
      tree->SetBranchAddress("wjet1_index", &wjet1_index);
      tree->SetBranchAddress("wjet2_index", &wjet2_index);
   }

   tree->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   tree->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   tree->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   tree->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   tree->SetBranchAddress("mu", &mu, &b_mu);
   tree->SetBranchAddress("backgroundFlags", &backgroundFlags, &b_backgroundFlags);
   tree->SetBranchAddress("hasBadMuon", &hasBadMuon, &b_hasBadMuon);
   tree->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   tree->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   tree->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   tree->SetBranchAddress("tau_charge", &tau_charge, &b_tau_charge);
   tree->SetBranchAddress("met_met", &met_met, &b_met_met);
   tree->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   tree->SetBranchAddress("triggers", &triggers, &b_triggers);
   tree->SetBranchAddress("loose", &loose, &b_loose);
   tree->SetBranchAddress("HLT_mu40", &HLT_mu40, &b_HLT_mu40);
   tree->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   tree->SetBranchAddress("HLT_mu26_imedium", &HLT_mu26_imedium, &b_HLT_mu26_imedium);
   tree->SetBranchAddress("HLT_mu24_ivarmedium", &HLT_mu24_ivarmedium, &b_HLT_mu24_ivarmedium);
   tree->SetBranchAddress("HLT_mu24_ivarloose", &HLT_mu24_ivarloose, &b_HLT_mu24_ivarloose);
   tree->SetBranchAddress("HLT_mu24_imedium", &HLT_mu24_imedium, &b_HLT_mu24_imedium);
   tree->SetBranchAddress("HLT_mu20_mu8noL1", &HLT_mu20_mu8noL1, &b_HLT_mu20_mu8noL1);
   tree->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   tree->SetBranchAddress("HLT_mu18_mu8noL1", &HLT_mu18_mu8noL1, &b_HLT_mu18_mu8noL1);
   tree->SetBranchAddress("HLT_mu14_ivarloose_tau25_medium1_tracktwo", &HLT_mu14_ivarloose_tau25_medium1_tracktwo, &b_HLT_mu14_ivarloose_tau25_medium1_tracktwo);
   tree->SetBranchAddress("HLT_e7_medium_mu24", &HLT_e7_medium_mu24, &b_HLT_e7_medium_mu24);
   tree->SetBranchAddress("HLT_e17_lhmedium_tau25_medium1_tracktwo", &HLT_e17_lhmedium_tau25_medium1_tracktwo, &b_HLT_e17_lhmedium_tau25_medium1_tracktwo);
   tree->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14, &b_HLT_e17_lhloose_mu14);
   tree->SetBranchAddress("HLT_e140_loose", &HLT_e140_loose, &b_HLT_e140_loose);
   tree->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   tree->SetBranchAddress("HLT_2e17_lhvloose_nod0", &HLT_2e17_lhvloose_nod0, &b_HLT_2e17_lhvloose_nod0);
   tree->SetBranchAddress("HLT_e17_lhloose_2e9_lhloose", &HLT_e17_lhloose_2e9_lhloose, &b_HLT_e17_lhloose_2e9_lhloose);
   tree->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14, &b_HLT_e17_lhloose_nod0_mu14);
   tree->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   tree->SetBranchAddress("HLT_e17_lhloose", &HLT_e17_lhloose, &b_HLT_e17_lhloose);
   tree->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH", &HLT_2e12_lhloose_L12EM10VH, &b_HLT_2e12_lhloose_L12EM10VH);
   tree->SetBranchAddress("HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo", &HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo, &b_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo);
   tree->SetBranchAddress("HLT_2e12_loose_L12EM10VH", &HLT_2e12_loose_L12EM10VH, &b_HLT_2e12_loose_L12EM10VH);
   tree->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   tree->SetBranchAddress("HLT_e60_medium", &HLT_e60_medium, &b_HLT_e60_medium);
   tree->SetBranchAddress("HLT_e12_loose", &HLT_e12_loose, &b_HLT_e12_loose);
   tree->SetBranchAddress("HLT_mu18", &HLT_mu18, &b_HLT_mu18);
   tree->SetBranchAddress("HLT_e140_lhloose", &HLT_e140_lhloose, &b_HLT_e140_lhloose);
   tree->SetBranchAddress("HLT_e5_lhloose", &HLT_e5_lhloose, &b_HLT_e5_lhloose);
   tree->SetBranchAddress("HLT_2e17_lhvloose_nod0_L12EM15VHI", &HLT_2e17_lhvloose_nod0_L12EM15VHI, &b_HLT_2e17_lhvloose_nod0_L12EM15VHI);
   tree->SetBranchAddress("HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo", &HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo, &b_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo);
   tree->SetBranchAddress("HLT_e24_lhmedium_nod0_L1EM20VH", &HLT_e24_lhmedium_nod0_L1EM20VH, &b_HLT_e24_lhmedium_nod0_L1EM20VH);
   tree->SetBranchAddress("HLT_2e24_lhvloose_nod0", &HLT_2e24_lhvloose_nod0, &b_HLT_2e24_lhvloose_nod0);
   tree->SetBranchAddress("HLT_e24_tight_iloose", &HLT_e24_tight_iloose, &b_HLT_e24_tight_iloose);
   tree->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   tree->SetBranchAddress("HLT_2e12_lhvloose_nod0_L12EM10VH", &HLT_2e12_lhvloose_nod0_L12EM10VH, &b_HLT_2e12_lhvloose_nod0_L12EM10VH);
   tree->SetBranchAddress("HLT_2mu10", &HLT_2mu10, &b_HLT_2mu10);
   tree->SetBranchAddress("HLT_e12_lhloose", &HLT_e12_lhloose, &b_HLT_e12_lhloose);
   tree->SetBranchAddress("HLT_2mu14", &HLT_2mu14, &b_HLT_2mu14);
   tree->SetBranchAddress("HLT_e17_loose", &HLT_e17_loose, &b_HLT_e17_loose);
   tree->SetBranchAddress("HLT_e17_loose_mu14", &HLT_e17_loose_mu14, &b_HLT_e17_loose_mu14);
   tree->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   tree->SetBranchAddress("HLT_mu24_iloose", &HLT_mu24_iloose, &b_HLT_mu24_iloose);
   tree->SetBranchAddress("HLT_e7_lhmedium_mu24", &HLT_e7_lhmedium_mu24, &b_HLT_e7_lhmedium_mu24);
   tree->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   tree->SetBranchAddress("HLT_e24_lhmedium_iloose_L1EM18VH", &HLT_e24_lhmedium_iloose_L1EM18VH, &b_HLT_e24_lhmedium_iloose_L1EM18VH);
   tree->SetBranchAddress("HLT_e24_lhmedium_L1EM18VH", &HLT_e24_lhmedium_L1EM18VH, &b_HLT_e24_lhmedium_L1EM18VH);
   tree->SetBranchAddress("HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1", &HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1, &b_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1);
   tree->SetBranchAddress("HLT_e24_lhtight_iloose", &HLT_e24_lhtight_iloose, &b_HLT_e24_lhtight_iloose);
   tree->SetBranchAddress("HLT_mu14", &HLT_mu14, &b_HLT_mu14);
   tree->SetBranchAddress("HLT_mu10", &HLT_mu10, &b_HLT_mu10);
   tree->SetBranchAddress("HLT_e24_lhtight_iloose_L1EM20VH", &HLT_e24_lhtight_iloose_L1EM20VH, &b_HLT_e24_lhtight_iloose_L1EM20VH);
   tree->SetBranchAddress("HLT_e24_lhtight_ivarloose", &HLT_e24_lhtight_ivarloose, &b_HLT_e24_lhtight_ivarloose);
   tree->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   tree->SetBranchAddress("HLT_e24_lhtight_nod0_ivarloose", &HLT_e24_lhtight_nod0_ivarloose, &b_HLT_e24_lhtight_nod0_ivarloose);
   tree->SetBranchAddress("HLT_mu14_tau25_medium1_tracktwo", &HLT_mu14_tau25_medium1_tracktwo, &b_HLT_mu14_tau25_medium1_tracktwo);
   tree->SetBranchAddress("HLT_e24_medium_L1EM20VHI_mu8noL1", &HLT_e24_medium_L1EM20VHI_mu8noL1, &b_HLT_e24_medium_L1EM20VHI_mu8noL1);
   tree->SetBranchAddress("HLT_e24_tight_iloose_L1EM20VH", &HLT_e24_tight_iloose_L1EM20VH, &b_HLT_e24_tight_iloose_L1EM20VH);
   tree->SetBranchAddress("HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1", &HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1, &b_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1);
   tree->SetBranchAddress("HLT_e26_lhtight_iloose", &HLT_e26_lhtight_iloose, &b_HLT_e26_lhtight_iloose);
   tree->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   tree->SetBranchAddress("HLT_2e15_lhvloose_nod0_L12EM13VH", &HLT_2e15_lhvloose_nod0_L12EM13VH, &b_HLT_2e15_lhvloose_nod0_L12EM13VH);
   tree->SetBranchAddress("HLT_e26_tight_iloose", &HLT_e26_tight_iloose, &b_HLT_e26_tight_iloose);
   tree->SetBranchAddress("HLT_e7_lhmedium_nod0_mu24", &HLT_e7_lhmedium_nod0_mu24, &b_HLT_e7_lhmedium_nod0_mu24);
   tree->SetBranchAddress("HLT_e5_loose", &HLT_e5_loose, &b_HLT_e5_loose);
   tree->SetBranchAddress("HLT_e300_etcut", &HLT_e300_etcut, &b_HLT_e300_etcut);
   tree->SetBranchAddress("mcWeightOrg", &mcWeightOrg, &b_mcWeightOrg);
   tree->SetBranchAddress("mcEventWeights", &mcEventWeights, &b_mcEventWeights);
   tree->SetBranchAddress("pileupEventWeight_090", &pileupEventWeight_090, &b_pileupEventWeight_090);
   tree->SetBranchAddress("MV2c10_60_EventWeight", &MV2c10_60_EventWeight, &b_MV2c10_60_EventWeight);
   tree->SetBranchAddress("MV2c10_70_EventWeight", &MV2c10_70_EventWeight, &b_MV2c10_70_EventWeight);
   tree->SetBranchAddress("MV2c10_77_EventWeight", &MV2c10_77_EventWeight, &b_MV2c10_77_EventWeight);
   tree->SetBranchAddress("MV2c10_85_EventWeight", &MV2c10_85_EventWeight, &b_MV2c10_85_EventWeight);
   tree->SetBranchAddress("JVT_EventWeight", &JVT_EventWeight, &b_JVT_EventWeight);
   tree->SetBranchAddress("DL1_60_EventWeight", &DL1_60_EventWeight, &b_DL1_60_EventWeight);
   tree->SetBranchAddress("DL1_70_EventWeight", &DL1_70_EventWeight, &b_DL1_70_EventWeight);
   tree->SetBranchAddress("DL1_77_EventWeight", &DL1_77_EventWeight, &b_DL1_77_EventWeight);
   tree->SetBranchAddress("DL1_85_EventWeight", &DL1_85_EventWeight, &b_DL1_85_EventWeight);
   tree->SetBranchAddress("DL1_Continuous_EventWeight", &DL1_Continuous_EventWeight, &b_DL1_Continuous_EventWeight);
   tree->SetBranchAddress("MV2c10_Continuous_EventWeight", &MV2c10_Continuous_EventWeight, &b_MV2c10_Continuous_EventWeight);
   tree->SetBranchAddress("pileupEventWeight_UP", &pileupEventWeight_UP, &b_pileupEventWeight_UP);
   tree->SetBranchAddress("pileupEventWeight_DOWN", &pileupEventWeight_DOWN, &b_pileupEventWeight_DOWN);
   if(version == 7){
      tree->SetBranchAddress("HLT_mu24", &HLT_mu24, &b_HLT_mu24);
      if(dosys){
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70", &bTagSF_weight_MV2c10_FixedCutBEff_70, &b_bTagSF_weight_MV2c10_FixedCutBEff_70);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70", &bTagSF_weight_DL1_FixedCutBEff_70, &b_bTagSF_weight_DL1_FixedCutBEff_70);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B0_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B1_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B2_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B3_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B4_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B5_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B6_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B7_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_B8_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C0_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C1_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_C2_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light0_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light1_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light2_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_Light3_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down", &bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down, &b_bTagSF_weight_MV2c10_FixedCutBEff_70_extrapolation_from_charm_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B0_up", &bTagSF_weight_DL1_FixedCutBEff_70_B0_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B0_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B0_down", &bTagSF_weight_DL1_FixedCutBEff_70_B0_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B0_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B1_up", &bTagSF_weight_DL1_FixedCutBEff_70_B1_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B1_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B1_down", &bTagSF_weight_DL1_FixedCutBEff_70_B1_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B1_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B2_up", &bTagSF_weight_DL1_FixedCutBEff_70_B2_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B2_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B2_down", &bTagSF_weight_DL1_FixedCutBEff_70_B2_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B2_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B3_up", &bTagSF_weight_DL1_FixedCutBEff_70_B3_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B3_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B3_down", &bTagSF_weight_DL1_FixedCutBEff_70_B3_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B3_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B4_up", &bTagSF_weight_DL1_FixedCutBEff_70_B4_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B4_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B4_down", &bTagSF_weight_DL1_FixedCutBEff_70_B4_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B4_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B5_up", &bTagSF_weight_DL1_FixedCutBEff_70_B5_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B5_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B5_down", &bTagSF_weight_DL1_FixedCutBEff_70_B5_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B5_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B6_up", &bTagSF_weight_DL1_FixedCutBEff_70_B6_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B6_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B6_down", &bTagSF_weight_DL1_FixedCutBEff_70_B6_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B6_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B7_up", &bTagSF_weight_DL1_FixedCutBEff_70_B7_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B7_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B7_down", &bTagSF_weight_DL1_FixedCutBEff_70_B7_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B7_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B8_up", &bTagSF_weight_DL1_FixedCutBEff_70_B8_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_B8_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_B8_down", &bTagSF_weight_DL1_FixedCutBEff_70_B8_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_B8_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_C0_up", &bTagSF_weight_DL1_FixedCutBEff_70_C0_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_C0_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_C0_down", &bTagSF_weight_DL1_FixedCutBEff_70_C0_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_C0_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_C1_up", &bTagSF_weight_DL1_FixedCutBEff_70_C1_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_C1_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_C1_down", &bTagSF_weight_DL1_FixedCutBEff_70_C1_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_C1_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_C2_up", &bTagSF_weight_DL1_FixedCutBEff_70_C2_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_C2_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_C2_down", &bTagSF_weight_DL1_FixedCutBEff_70_C2_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_C2_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light0_up", &bTagSF_weight_DL1_FixedCutBEff_70_Light0_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light0_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light0_down", &bTagSF_weight_DL1_FixedCutBEff_70_Light0_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light0_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light1_up", &bTagSF_weight_DL1_FixedCutBEff_70_Light1_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light1_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light1_down", &bTagSF_weight_DL1_FixedCutBEff_70_Light1_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light1_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light2_up", &bTagSF_weight_DL1_FixedCutBEff_70_Light2_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light2_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light2_down", &bTagSF_weight_DL1_FixedCutBEff_70_Light2_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light2_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light3_up", &bTagSF_weight_DL1_FixedCutBEff_70_Light3_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light3_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_Light3_down", &bTagSF_weight_DL1_FixedCutBEff_70_Light3_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_Light3_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up", &bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down", &bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up", &bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up, &b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down", &bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down, &b_bTagSF_weight_DL1_FixedCutBEff_70_extrapolation_from_charm_down);
      }
         tree->SetBranchAddress("lep_firstEgMotherPdgId_0", &lep_firstEgMotherPdgId_0, &b_lep_firstEgMotherPdgId_0);
         tree->SetBranchAddress("lep_firstEgMotherTruthType_0", &lep_firstEgMotherTruthType_0, &b_lep_firstEgMotherTruthType_0);
         tree->SetBranchAddress("lep_firstEgMotherTruthOrigin_0", &lep_firstEgMotherTruthOrigin_0, &b_lep_firstEgMotherTruthOrigin_0);
         tree->SetBranchAddress("lep_firstEgMotherPdgId_1", &lep_firstEgMotherPdgId_1, &b_lep_firstEgMotherPdgId_1);
         tree->SetBranchAddress("lep_firstEgMotherTruthType_1", &lep_firstEgMotherTruthType_1, &b_lep_firstEgMotherTruthType_1);
         tree->SetBranchAddress("lep_firstEgMotherTruthOrigin_1", &lep_firstEgMotherTruthOrigin_1, &b_lep_firstEgMotherTruthOrigin_1);
         tree->SetBranchAddress("lep_firstEgMotherPdgId_2", &lep_firstEgMotherPdgId_2, &b_lep_firstEgMotherPdgId_2);
         tree->SetBranchAddress("lep_firstEgMotherTruthType_2", &lep_firstEgMotherTruthType_2, &b_lep_firstEgMotherTruthType_2);
         tree->SetBranchAddress("lep_firstEgMotherTruthOrigin_2", &lep_firstEgMotherTruthOrigin_2, &b_lep_firstEgMotherTruthOrigin_2);
         tree->SetBranchAddress("lep_firstEgMotherPdgId_3", &lep_firstEgMotherPdgId_3, &b_lep_firstEgMotherPdgId_3);
         tree->SetBranchAddress("lep_firstEgMotherTruthType_3", &lep_firstEgMotherTruthType_3, &b_lep_firstEgMotherTruthType_3);
         tree->SetBranchAddress("lep_firstEgMotherTruthOrigin_3", &lep_firstEgMotherTruthOrigin_3, &b_lep_firstEgMotherTruthOrigin_3);
         tree->SetBranchAddress("lep_firstEgMotherPdgId_4", &lep_firstEgMotherPdgId_4, &b_lep_firstEgMotherPdgId_4);
         tree->SetBranchAddress("lep_firstEgMotherTruthType_4", &lep_firstEgMotherTruthType_4, &b_lep_firstEgMotherTruthType_4);
         tree->SetBranchAddress("lep_firstEgMotherTruthOrigin_4", &lep_firstEgMotherTruthOrigin_4, &b_lep_firstEgMotherTruthOrigin_4);
      if(dosys){
         tree->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_SYST_UP", &lepEffTrigLoose_MU_SF_Trigger_SYST_UP, &b_lepEffTrigLoose_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_SYST_UP", &lepEffTrigTight_MU_SF_Trigger_SYST_UP, &b_lepEffTrigTight_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP", &lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP, &b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP", &lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP, &b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP", &lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_SYST_UP", &lepDataEffTrigTight_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigTight_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP", &lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP", &lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_UP);
         tree->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_DOWN", &lepSFTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN", &lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigTightLoose_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN", &lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigLooseTight_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigLoose_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_SYST_DOWN", &lepEffTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigTight_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN", &lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN", &lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN, &b_lepEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigLoose_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigTight_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_SYST_DOWN);
         tree->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN", &lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_SYST_DOWN);
      }
   }else{
      if(dosys){
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous", &bTagSF_weight_DL1_Continuous, &b_bTagSF_weight_DL1_Continuous);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous", &bTagSF_weight_MV2c10_Continuous, &b_bTagSF_weight_MV2c10_Continuous);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B0_up", &bTagSF_weight_MV2c10_Continuous_B0_up, &b_bTagSF_weight_MV2c10_Continuous_B0_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B0_down", &bTagSF_weight_MV2c10_Continuous_B0_down, &b_bTagSF_weight_MV2c10_Continuous_B0_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B1_up", &bTagSF_weight_MV2c10_Continuous_B1_up, &b_bTagSF_weight_MV2c10_Continuous_B1_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B1_down", &bTagSF_weight_MV2c10_Continuous_B1_down, &b_bTagSF_weight_MV2c10_Continuous_B1_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B2_up", &bTagSF_weight_MV2c10_Continuous_B2_up, &b_bTagSF_weight_MV2c10_Continuous_B2_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B2_down", &bTagSF_weight_MV2c10_Continuous_B2_down, &b_bTagSF_weight_MV2c10_Continuous_B2_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B3_up", &bTagSF_weight_MV2c10_Continuous_B3_up, &b_bTagSF_weight_MV2c10_Continuous_B3_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B3_down", &bTagSF_weight_MV2c10_Continuous_B3_down, &b_bTagSF_weight_MV2c10_Continuous_B3_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B4_up", &bTagSF_weight_MV2c10_Continuous_B4_up, &b_bTagSF_weight_MV2c10_Continuous_B4_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B4_down", &bTagSF_weight_MV2c10_Continuous_B4_down, &b_bTagSF_weight_MV2c10_Continuous_B4_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B5_up", &bTagSF_weight_MV2c10_Continuous_B5_up, &b_bTagSF_weight_MV2c10_Continuous_B5_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B5_down", &bTagSF_weight_MV2c10_Continuous_B5_down, &b_bTagSF_weight_MV2c10_Continuous_B5_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B6_up", &bTagSF_weight_MV2c10_Continuous_B6_up, &b_bTagSF_weight_MV2c10_Continuous_B6_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B6_down", &bTagSF_weight_MV2c10_Continuous_B6_down, &b_bTagSF_weight_MV2c10_Continuous_B6_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B7_up", &bTagSF_weight_MV2c10_Continuous_B7_up, &b_bTagSF_weight_MV2c10_Continuous_B7_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B7_down", &bTagSF_weight_MV2c10_Continuous_B7_down, &b_bTagSF_weight_MV2c10_Continuous_B7_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B8_up", &bTagSF_weight_MV2c10_Continuous_B8_up, &b_bTagSF_weight_MV2c10_Continuous_B8_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B8_down", &bTagSF_weight_MV2c10_Continuous_B8_down, &b_bTagSF_weight_MV2c10_Continuous_B8_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B9_up", &bTagSF_weight_MV2c10_Continuous_B9_up, &b_bTagSF_weight_MV2c10_Continuous_B9_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B9_down", &bTagSF_weight_MV2c10_Continuous_B9_down, &b_bTagSF_weight_MV2c10_Continuous_B9_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B10_up", &bTagSF_weight_MV2c10_Continuous_B10_up, &b_bTagSF_weight_MV2c10_Continuous_B10_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B10_down", &bTagSF_weight_MV2c10_Continuous_B10_down, &b_bTagSF_weight_MV2c10_Continuous_B10_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B11_up", &bTagSF_weight_MV2c10_Continuous_B11_up, &b_bTagSF_weight_MV2c10_Continuous_B11_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B11_down", &bTagSF_weight_MV2c10_Continuous_B11_down, &b_bTagSF_weight_MV2c10_Continuous_B11_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B12_up", &bTagSF_weight_MV2c10_Continuous_B12_up, &b_bTagSF_weight_MV2c10_Continuous_B12_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B12_down", &bTagSF_weight_MV2c10_Continuous_B12_down, &b_bTagSF_weight_MV2c10_Continuous_B12_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B13_up", &bTagSF_weight_MV2c10_Continuous_B13_up, &b_bTagSF_weight_MV2c10_Continuous_B13_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B13_down", &bTagSF_weight_MV2c10_Continuous_B13_down, &b_bTagSF_weight_MV2c10_Continuous_B13_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B14_up", &bTagSF_weight_MV2c10_Continuous_B14_up, &b_bTagSF_weight_MV2c10_Continuous_B14_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B14_down", &bTagSF_weight_MV2c10_Continuous_B14_down, &b_bTagSF_weight_MV2c10_Continuous_B14_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B15_up", &bTagSF_weight_MV2c10_Continuous_B15_up, &b_bTagSF_weight_MV2c10_Continuous_B15_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B15_down", &bTagSF_weight_MV2c10_Continuous_B15_down, &b_bTagSF_weight_MV2c10_Continuous_B15_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B16_up", &bTagSF_weight_MV2c10_Continuous_B16_up, &b_bTagSF_weight_MV2c10_Continuous_B16_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B16_down", &bTagSF_weight_MV2c10_Continuous_B16_down, &b_bTagSF_weight_MV2c10_Continuous_B16_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B17_up", &bTagSF_weight_MV2c10_Continuous_B17_up, &b_bTagSF_weight_MV2c10_Continuous_B17_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B17_down", &bTagSF_weight_MV2c10_Continuous_B17_down, &b_bTagSF_weight_MV2c10_Continuous_B17_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B18_up", &bTagSF_weight_MV2c10_Continuous_B18_up, &b_bTagSF_weight_MV2c10_Continuous_B18_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B18_down", &bTagSF_weight_MV2c10_Continuous_B18_down, &b_bTagSF_weight_MV2c10_Continuous_B18_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B19_up", &bTagSF_weight_MV2c10_Continuous_B19_up, &b_bTagSF_weight_MV2c10_Continuous_B19_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B19_down", &bTagSF_weight_MV2c10_Continuous_B19_down, &b_bTagSF_weight_MV2c10_Continuous_B19_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B20_up", &bTagSF_weight_MV2c10_Continuous_B20_up, &b_bTagSF_weight_MV2c10_Continuous_B20_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B20_down", &bTagSF_weight_MV2c10_Continuous_B20_down, &b_bTagSF_weight_MV2c10_Continuous_B20_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B21_up", &bTagSF_weight_MV2c10_Continuous_B21_up, &b_bTagSF_weight_MV2c10_Continuous_B21_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B21_down", &bTagSF_weight_MV2c10_Continuous_B21_down, &b_bTagSF_weight_MV2c10_Continuous_B21_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B22_up", &bTagSF_weight_MV2c10_Continuous_B22_up, &b_bTagSF_weight_MV2c10_Continuous_B22_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B22_down", &bTagSF_weight_MV2c10_Continuous_B22_down, &b_bTagSF_weight_MV2c10_Continuous_B22_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B23_up", &bTagSF_weight_MV2c10_Continuous_B23_up, &b_bTagSF_weight_MV2c10_Continuous_B23_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B23_down", &bTagSF_weight_MV2c10_Continuous_B23_down, &b_bTagSF_weight_MV2c10_Continuous_B23_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B24_up", &bTagSF_weight_MV2c10_Continuous_B24_up, &b_bTagSF_weight_MV2c10_Continuous_B24_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B24_down", &bTagSF_weight_MV2c10_Continuous_B24_down, &b_bTagSF_weight_MV2c10_Continuous_B24_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B25_up", &bTagSF_weight_MV2c10_Continuous_B25_up, &b_bTagSF_weight_MV2c10_Continuous_B25_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B25_down", &bTagSF_weight_MV2c10_Continuous_B25_down, &b_bTagSF_weight_MV2c10_Continuous_B25_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B26_up", &bTagSF_weight_MV2c10_Continuous_B26_up, &b_bTagSF_weight_MV2c10_Continuous_B26_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B26_down", &bTagSF_weight_MV2c10_Continuous_B26_down, &b_bTagSF_weight_MV2c10_Continuous_B26_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B27_up", &bTagSF_weight_MV2c10_Continuous_B27_up, &b_bTagSF_weight_MV2c10_Continuous_B27_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B27_down", &bTagSF_weight_MV2c10_Continuous_B27_down, &b_bTagSF_weight_MV2c10_Continuous_B27_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B28_up", &bTagSF_weight_MV2c10_Continuous_B28_up, &b_bTagSF_weight_MV2c10_Continuous_B28_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B28_down", &bTagSF_weight_MV2c10_Continuous_B28_down, &b_bTagSF_weight_MV2c10_Continuous_B28_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B29_up", &bTagSF_weight_MV2c10_Continuous_B29_up, &b_bTagSF_weight_MV2c10_Continuous_B29_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B29_down", &bTagSF_weight_MV2c10_Continuous_B29_down, &b_bTagSF_weight_MV2c10_Continuous_B29_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B30_up", &bTagSF_weight_MV2c10_Continuous_B30_up, &b_bTagSF_weight_MV2c10_Continuous_B30_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B30_down", &bTagSF_weight_MV2c10_Continuous_B30_down, &b_bTagSF_weight_MV2c10_Continuous_B30_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B31_up", &bTagSF_weight_MV2c10_Continuous_B31_up, &b_bTagSF_weight_MV2c10_Continuous_B31_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B31_down", &bTagSF_weight_MV2c10_Continuous_B31_down, &b_bTagSF_weight_MV2c10_Continuous_B31_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B32_up", &bTagSF_weight_MV2c10_Continuous_B32_up, &b_bTagSF_weight_MV2c10_Continuous_B32_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B32_down", &bTagSF_weight_MV2c10_Continuous_B32_down, &b_bTagSF_weight_MV2c10_Continuous_B32_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B33_up", &bTagSF_weight_MV2c10_Continuous_B33_up, &b_bTagSF_weight_MV2c10_Continuous_B33_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B33_down", &bTagSF_weight_MV2c10_Continuous_B33_down, &b_bTagSF_weight_MV2c10_Continuous_B33_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B34_up", &bTagSF_weight_MV2c10_Continuous_B34_up, &b_bTagSF_weight_MV2c10_Continuous_B34_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B34_down", &bTagSF_weight_MV2c10_Continuous_B34_down, &b_bTagSF_weight_MV2c10_Continuous_B34_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B35_up", &bTagSF_weight_MV2c10_Continuous_B35_up, &b_bTagSF_weight_MV2c10_Continuous_B35_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B35_down", &bTagSF_weight_MV2c10_Continuous_B35_down, &b_bTagSF_weight_MV2c10_Continuous_B35_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B36_up", &bTagSF_weight_MV2c10_Continuous_B36_up, &b_bTagSF_weight_MV2c10_Continuous_B36_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B36_down", &bTagSF_weight_MV2c10_Continuous_B36_down, &b_bTagSF_weight_MV2c10_Continuous_B36_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B37_up", &bTagSF_weight_MV2c10_Continuous_B37_up, &b_bTagSF_weight_MV2c10_Continuous_B37_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B37_down", &bTagSF_weight_MV2c10_Continuous_B37_down, &b_bTagSF_weight_MV2c10_Continuous_B37_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B38_up", &bTagSF_weight_MV2c10_Continuous_B38_up, &b_bTagSF_weight_MV2c10_Continuous_B38_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B38_down", &bTagSF_weight_MV2c10_Continuous_B38_down, &b_bTagSF_weight_MV2c10_Continuous_B38_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B39_up", &bTagSF_weight_MV2c10_Continuous_B39_up, &b_bTagSF_weight_MV2c10_Continuous_B39_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B39_down", &bTagSF_weight_MV2c10_Continuous_B39_down, &b_bTagSF_weight_MV2c10_Continuous_B39_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B40_up", &bTagSF_weight_MV2c10_Continuous_B40_up, &b_bTagSF_weight_MV2c10_Continuous_B40_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B40_down", &bTagSF_weight_MV2c10_Continuous_B40_down, &b_bTagSF_weight_MV2c10_Continuous_B40_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B41_up", &bTagSF_weight_MV2c10_Continuous_B41_up, &b_bTagSF_weight_MV2c10_Continuous_B41_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B41_down", &bTagSF_weight_MV2c10_Continuous_B41_down, &b_bTagSF_weight_MV2c10_Continuous_B41_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B42_up", &bTagSF_weight_MV2c10_Continuous_B42_up, &b_bTagSF_weight_MV2c10_Continuous_B42_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B42_down", &bTagSF_weight_MV2c10_Continuous_B42_down, &b_bTagSF_weight_MV2c10_Continuous_B42_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B43_up", &bTagSF_weight_MV2c10_Continuous_B43_up, &b_bTagSF_weight_MV2c10_Continuous_B43_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B43_down", &bTagSF_weight_MV2c10_Continuous_B43_down, &b_bTagSF_weight_MV2c10_Continuous_B43_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B44_up", &bTagSF_weight_MV2c10_Continuous_B44_up, &b_bTagSF_weight_MV2c10_Continuous_B44_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_B44_down", &bTagSF_weight_MV2c10_Continuous_B44_down, &b_bTagSF_weight_MV2c10_Continuous_B44_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C0_up", &bTagSF_weight_MV2c10_Continuous_C0_up, &b_bTagSF_weight_MV2c10_Continuous_C0_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C0_down", &bTagSF_weight_MV2c10_Continuous_C0_down, &b_bTagSF_weight_MV2c10_Continuous_C0_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C1_up", &bTagSF_weight_MV2c10_Continuous_C1_up, &b_bTagSF_weight_MV2c10_Continuous_C1_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C1_down", &bTagSF_weight_MV2c10_Continuous_C1_down, &b_bTagSF_weight_MV2c10_Continuous_C1_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C2_up", &bTagSF_weight_MV2c10_Continuous_C2_up, &b_bTagSF_weight_MV2c10_Continuous_C2_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C2_down", &bTagSF_weight_MV2c10_Continuous_C2_down, &b_bTagSF_weight_MV2c10_Continuous_C2_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C3_up", &bTagSF_weight_MV2c10_Continuous_C3_up, &b_bTagSF_weight_MV2c10_Continuous_C3_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C3_down", &bTagSF_weight_MV2c10_Continuous_C3_down, &b_bTagSF_weight_MV2c10_Continuous_C3_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C4_up", &bTagSF_weight_MV2c10_Continuous_C4_up, &b_bTagSF_weight_MV2c10_Continuous_C4_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C4_down", &bTagSF_weight_MV2c10_Continuous_C4_down, &b_bTagSF_weight_MV2c10_Continuous_C4_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C5_up", &bTagSF_weight_MV2c10_Continuous_C5_up, &b_bTagSF_weight_MV2c10_Continuous_C5_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C5_down", &bTagSF_weight_MV2c10_Continuous_C5_down, &b_bTagSF_weight_MV2c10_Continuous_C5_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C6_up", &bTagSF_weight_MV2c10_Continuous_C6_up, &b_bTagSF_weight_MV2c10_Continuous_C6_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C6_down", &bTagSF_weight_MV2c10_Continuous_C6_down, &b_bTagSF_weight_MV2c10_Continuous_C6_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C7_up", &bTagSF_weight_MV2c10_Continuous_C7_up, &b_bTagSF_weight_MV2c10_Continuous_C7_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C7_down", &bTagSF_weight_MV2c10_Continuous_C7_down, &b_bTagSF_weight_MV2c10_Continuous_C7_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C8_up", &bTagSF_weight_MV2c10_Continuous_C8_up, &b_bTagSF_weight_MV2c10_Continuous_C8_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C8_down", &bTagSF_weight_MV2c10_Continuous_C8_down, &b_bTagSF_weight_MV2c10_Continuous_C8_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C9_up", &bTagSF_weight_MV2c10_Continuous_C9_up, &b_bTagSF_weight_MV2c10_Continuous_C9_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C9_down", &bTagSF_weight_MV2c10_Continuous_C9_down, &b_bTagSF_weight_MV2c10_Continuous_C9_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C10_up", &bTagSF_weight_MV2c10_Continuous_C10_up, &b_bTagSF_weight_MV2c10_Continuous_C10_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C10_down", &bTagSF_weight_MV2c10_Continuous_C10_down, &b_bTagSF_weight_MV2c10_Continuous_C10_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C11_up", &bTagSF_weight_MV2c10_Continuous_C11_up, &b_bTagSF_weight_MV2c10_Continuous_C11_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C11_down", &bTagSF_weight_MV2c10_Continuous_C11_down, &b_bTagSF_weight_MV2c10_Continuous_C11_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C12_up", &bTagSF_weight_MV2c10_Continuous_C12_up, &b_bTagSF_weight_MV2c10_Continuous_C12_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C12_down", &bTagSF_weight_MV2c10_Continuous_C12_down, &b_bTagSF_weight_MV2c10_Continuous_C12_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C13_up", &bTagSF_weight_MV2c10_Continuous_C13_up, &b_bTagSF_weight_MV2c10_Continuous_C13_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C13_down", &bTagSF_weight_MV2c10_Continuous_C13_down, &b_bTagSF_weight_MV2c10_Continuous_C13_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C14_up", &bTagSF_weight_MV2c10_Continuous_C14_up, &b_bTagSF_weight_MV2c10_Continuous_C14_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_C14_down", &bTagSF_weight_MV2c10_Continuous_C14_down, &b_bTagSF_weight_MV2c10_Continuous_C14_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light0_up", &bTagSF_weight_MV2c10_Continuous_Light0_up, &b_bTagSF_weight_MV2c10_Continuous_Light0_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light0_down", &bTagSF_weight_MV2c10_Continuous_Light0_down, &b_bTagSF_weight_MV2c10_Continuous_Light0_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light1_up", &bTagSF_weight_MV2c10_Continuous_Light1_up, &b_bTagSF_weight_MV2c10_Continuous_Light1_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light1_down", &bTagSF_weight_MV2c10_Continuous_Light1_down, &b_bTagSF_weight_MV2c10_Continuous_Light1_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light2_up", &bTagSF_weight_MV2c10_Continuous_Light2_up, &b_bTagSF_weight_MV2c10_Continuous_Light2_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light2_down", &bTagSF_weight_MV2c10_Continuous_Light2_down, &b_bTagSF_weight_MV2c10_Continuous_Light2_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light3_up", &bTagSF_weight_MV2c10_Continuous_Light3_up, &b_bTagSF_weight_MV2c10_Continuous_Light3_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light3_down", &bTagSF_weight_MV2c10_Continuous_Light3_down, &b_bTagSF_weight_MV2c10_Continuous_Light3_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light4_up", &bTagSF_weight_MV2c10_Continuous_Light4_up, &b_bTagSF_weight_MV2c10_Continuous_Light4_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light4_down", &bTagSF_weight_MV2c10_Continuous_Light4_down, &b_bTagSF_weight_MV2c10_Continuous_Light4_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light5_up", &bTagSF_weight_MV2c10_Continuous_Light5_up, &b_bTagSF_weight_MV2c10_Continuous_Light5_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light5_down", &bTagSF_weight_MV2c10_Continuous_Light5_down, &b_bTagSF_weight_MV2c10_Continuous_Light5_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light6_up", &bTagSF_weight_MV2c10_Continuous_Light6_up, &b_bTagSF_weight_MV2c10_Continuous_Light6_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light6_down", &bTagSF_weight_MV2c10_Continuous_Light6_down, &b_bTagSF_weight_MV2c10_Continuous_Light6_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light7_up", &bTagSF_weight_MV2c10_Continuous_Light7_up, &b_bTagSF_weight_MV2c10_Continuous_Light7_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light7_down", &bTagSF_weight_MV2c10_Continuous_Light7_down, &b_bTagSF_weight_MV2c10_Continuous_Light7_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light8_up", &bTagSF_weight_MV2c10_Continuous_Light8_up, &b_bTagSF_weight_MV2c10_Continuous_Light8_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light8_down", &bTagSF_weight_MV2c10_Continuous_Light8_down, &b_bTagSF_weight_MV2c10_Continuous_Light8_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light9_up", &bTagSF_weight_MV2c10_Continuous_Light9_up, &b_bTagSF_weight_MV2c10_Continuous_Light9_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light9_down", &bTagSF_weight_MV2c10_Continuous_Light9_down, &b_bTagSF_weight_MV2c10_Continuous_Light9_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light10_up", &bTagSF_weight_MV2c10_Continuous_Light10_up, &b_bTagSF_weight_MV2c10_Continuous_Light10_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light10_down", &bTagSF_weight_MV2c10_Continuous_Light10_down, &b_bTagSF_weight_MV2c10_Continuous_Light10_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light11_up", &bTagSF_weight_MV2c10_Continuous_Light11_up, &b_bTagSF_weight_MV2c10_Continuous_Light11_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light11_down", &bTagSF_weight_MV2c10_Continuous_Light11_down, &b_bTagSF_weight_MV2c10_Continuous_Light11_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light12_up", &bTagSF_weight_MV2c10_Continuous_Light12_up, &b_bTagSF_weight_MV2c10_Continuous_Light12_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light12_down", &bTagSF_weight_MV2c10_Continuous_Light12_down, &b_bTagSF_weight_MV2c10_Continuous_Light12_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light13_up", &bTagSF_weight_MV2c10_Continuous_Light13_up, &b_bTagSF_weight_MV2c10_Continuous_Light13_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light13_down", &bTagSF_weight_MV2c10_Continuous_Light13_down, &b_bTagSF_weight_MV2c10_Continuous_Light13_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light14_up", &bTagSF_weight_MV2c10_Continuous_Light14_up, &b_bTagSF_weight_MV2c10_Continuous_Light14_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light14_down", &bTagSF_weight_MV2c10_Continuous_Light14_down, &b_bTagSF_weight_MV2c10_Continuous_Light14_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light15_up", &bTagSF_weight_MV2c10_Continuous_Light15_up, &b_bTagSF_weight_MV2c10_Continuous_Light15_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light15_down", &bTagSF_weight_MV2c10_Continuous_Light15_down, &b_bTagSF_weight_MV2c10_Continuous_Light15_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light16_up", &bTagSF_weight_MV2c10_Continuous_Light16_up, &b_bTagSF_weight_MV2c10_Continuous_Light16_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light16_down", &bTagSF_weight_MV2c10_Continuous_Light16_down, &b_bTagSF_weight_MV2c10_Continuous_Light16_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light17_up", &bTagSF_weight_MV2c10_Continuous_Light17_up, &b_bTagSF_weight_MV2c10_Continuous_Light17_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light17_down", &bTagSF_weight_MV2c10_Continuous_Light17_down, &b_bTagSF_weight_MV2c10_Continuous_Light17_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light18_up", &bTagSF_weight_MV2c10_Continuous_Light18_up, &b_bTagSF_weight_MV2c10_Continuous_Light18_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light18_down", &bTagSF_weight_MV2c10_Continuous_Light18_down, &b_bTagSF_weight_MV2c10_Continuous_Light18_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light19_up", &bTagSF_weight_MV2c10_Continuous_Light19_up, &b_bTagSF_weight_MV2c10_Continuous_Light19_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light19_down", &bTagSF_weight_MV2c10_Continuous_Light19_down, &b_bTagSF_weight_MV2c10_Continuous_Light19_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light20_up", &bTagSF_weight_MV2c10_Continuous_Light20_up, &b_bTagSF_weight_MV2c10_Continuous_Light20_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light20_down", &bTagSF_weight_MV2c10_Continuous_Light20_down, &b_bTagSF_weight_MV2c10_Continuous_Light20_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light21_up", &bTagSF_weight_MV2c10_Continuous_Light21_up, &b_bTagSF_weight_MV2c10_Continuous_Light21_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light21_down", &bTagSF_weight_MV2c10_Continuous_Light21_down, &b_bTagSF_weight_MV2c10_Continuous_Light21_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light22_up", &bTagSF_weight_MV2c10_Continuous_Light22_up, &b_bTagSF_weight_MV2c10_Continuous_Light22_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light22_down", &bTagSF_weight_MV2c10_Continuous_Light22_down, &b_bTagSF_weight_MV2c10_Continuous_Light22_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light23_up", &bTagSF_weight_MV2c10_Continuous_Light23_up, &b_bTagSF_weight_MV2c10_Continuous_Light23_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light23_down", &bTagSF_weight_MV2c10_Continuous_Light23_down, &b_bTagSF_weight_MV2c10_Continuous_Light23_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light24_up", &bTagSF_weight_MV2c10_Continuous_Light24_up, &b_bTagSF_weight_MV2c10_Continuous_Light24_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light24_down", &bTagSF_weight_MV2c10_Continuous_Light24_down, &b_bTagSF_weight_MV2c10_Continuous_Light24_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light25_up", &bTagSF_weight_MV2c10_Continuous_Light25_up, &b_bTagSF_weight_MV2c10_Continuous_Light25_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light25_down", &bTagSF_weight_MV2c10_Continuous_Light25_down, &b_bTagSF_weight_MV2c10_Continuous_Light25_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light26_up", &bTagSF_weight_MV2c10_Continuous_Light26_up, &b_bTagSF_weight_MV2c10_Continuous_Light26_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light26_down", &bTagSF_weight_MV2c10_Continuous_Light26_down, &b_bTagSF_weight_MV2c10_Continuous_Light26_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light27_up", &bTagSF_weight_MV2c10_Continuous_Light27_up, &b_bTagSF_weight_MV2c10_Continuous_Light27_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light27_down", &bTagSF_weight_MV2c10_Continuous_Light27_down, &b_bTagSF_weight_MV2c10_Continuous_Light27_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light28_up", &bTagSF_weight_MV2c10_Continuous_Light28_up, &b_bTagSF_weight_MV2c10_Continuous_Light28_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light28_down", &bTagSF_weight_MV2c10_Continuous_Light28_down, &b_bTagSF_weight_MV2c10_Continuous_Light28_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light29_up", &bTagSF_weight_MV2c10_Continuous_Light29_up, &b_bTagSF_weight_MV2c10_Continuous_Light29_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light29_down", &bTagSF_weight_MV2c10_Continuous_Light29_down, &b_bTagSF_weight_MV2c10_Continuous_Light29_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light30_up", &bTagSF_weight_MV2c10_Continuous_Light30_up, &b_bTagSF_weight_MV2c10_Continuous_Light30_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light30_down", &bTagSF_weight_MV2c10_Continuous_Light30_down, &b_bTagSF_weight_MV2c10_Continuous_Light30_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light31_up", &bTagSF_weight_MV2c10_Continuous_Light31_up, &b_bTagSF_weight_MV2c10_Continuous_Light31_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light31_down", &bTagSF_weight_MV2c10_Continuous_Light31_down, &b_bTagSF_weight_MV2c10_Continuous_Light31_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light32_up", &bTagSF_weight_MV2c10_Continuous_Light32_up, &b_bTagSF_weight_MV2c10_Continuous_Light32_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light32_down", &bTagSF_weight_MV2c10_Continuous_Light32_down, &b_bTagSF_weight_MV2c10_Continuous_Light32_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light33_up", &bTagSF_weight_MV2c10_Continuous_Light33_up, &b_bTagSF_weight_MV2c10_Continuous_Light33_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light33_down", &bTagSF_weight_MV2c10_Continuous_Light33_down, &b_bTagSF_weight_MV2c10_Continuous_Light33_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light34_up", &bTagSF_weight_MV2c10_Continuous_Light34_up, &b_bTagSF_weight_MV2c10_Continuous_Light34_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light34_down", &bTagSF_weight_MV2c10_Continuous_Light34_down, &b_bTagSF_weight_MV2c10_Continuous_Light34_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light35_up", &bTagSF_weight_MV2c10_Continuous_Light35_up, &b_bTagSF_weight_MV2c10_Continuous_Light35_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light35_down", &bTagSF_weight_MV2c10_Continuous_Light35_down, &b_bTagSF_weight_MV2c10_Continuous_Light35_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light36_up", &bTagSF_weight_MV2c10_Continuous_Light36_up, &b_bTagSF_weight_MV2c10_Continuous_Light36_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light36_down", &bTagSF_weight_MV2c10_Continuous_Light36_down, &b_bTagSF_weight_MV2c10_Continuous_Light36_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light37_up", &bTagSF_weight_MV2c10_Continuous_Light37_up, &b_bTagSF_weight_MV2c10_Continuous_Light37_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light37_down", &bTagSF_weight_MV2c10_Continuous_Light37_down, &b_bTagSF_weight_MV2c10_Continuous_Light37_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light38_up", &bTagSF_weight_MV2c10_Continuous_Light38_up, &b_bTagSF_weight_MV2c10_Continuous_Light38_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light38_down", &bTagSF_weight_MV2c10_Continuous_Light38_down, &b_bTagSF_weight_MV2c10_Continuous_Light38_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light39_up", &bTagSF_weight_MV2c10_Continuous_Light39_up, &b_bTagSF_weight_MV2c10_Continuous_Light39_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light39_down", &bTagSF_weight_MV2c10_Continuous_Light39_down, &b_bTagSF_weight_MV2c10_Continuous_Light39_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light40_up", &bTagSF_weight_MV2c10_Continuous_Light40_up, &b_bTagSF_weight_MV2c10_Continuous_Light40_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light40_down", &bTagSF_weight_MV2c10_Continuous_Light40_down, &b_bTagSF_weight_MV2c10_Continuous_Light40_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light41_up", &bTagSF_weight_MV2c10_Continuous_Light41_up, &b_bTagSF_weight_MV2c10_Continuous_Light41_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light41_down", &bTagSF_weight_MV2c10_Continuous_Light41_down, &b_bTagSF_weight_MV2c10_Continuous_Light41_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light42_up", &bTagSF_weight_MV2c10_Continuous_Light42_up, &b_bTagSF_weight_MV2c10_Continuous_Light42_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light42_down", &bTagSF_weight_MV2c10_Continuous_Light42_down, &b_bTagSF_weight_MV2c10_Continuous_Light42_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light43_up", &bTagSF_weight_MV2c10_Continuous_Light43_up, &b_bTagSF_weight_MV2c10_Continuous_Light43_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light43_down", &bTagSF_weight_MV2c10_Continuous_Light43_down, &b_bTagSF_weight_MV2c10_Continuous_Light43_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light44_up", &bTagSF_weight_MV2c10_Continuous_Light44_up, &b_bTagSF_weight_MV2c10_Continuous_Light44_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light44_down", &bTagSF_weight_MV2c10_Continuous_Light44_down, &b_bTagSF_weight_MV2c10_Continuous_Light44_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light45_up", &bTagSF_weight_MV2c10_Continuous_Light45_up, &b_bTagSF_weight_MV2c10_Continuous_Light45_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light45_down", &bTagSF_weight_MV2c10_Continuous_Light45_down, &b_bTagSF_weight_MV2c10_Continuous_Light45_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light46_up", &bTagSF_weight_MV2c10_Continuous_Light46_up, &b_bTagSF_weight_MV2c10_Continuous_Light46_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light46_down", &bTagSF_weight_MV2c10_Continuous_Light46_down, &b_bTagSF_weight_MV2c10_Continuous_Light46_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light47_up", &bTagSF_weight_MV2c10_Continuous_Light47_up, &b_bTagSF_weight_MV2c10_Continuous_Light47_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light47_down", &bTagSF_weight_MV2c10_Continuous_Light47_down, &b_bTagSF_weight_MV2c10_Continuous_Light47_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light48_up", &bTagSF_weight_MV2c10_Continuous_Light48_up, &b_bTagSF_weight_MV2c10_Continuous_Light48_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light48_down", &bTagSF_weight_MV2c10_Continuous_Light48_down, &b_bTagSF_weight_MV2c10_Continuous_Light48_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light49_up", &bTagSF_weight_MV2c10_Continuous_Light49_up, &b_bTagSF_weight_MV2c10_Continuous_Light49_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light49_down", &bTagSF_weight_MV2c10_Continuous_Light49_down, &b_bTagSF_weight_MV2c10_Continuous_Light49_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light50_up", &bTagSF_weight_MV2c10_Continuous_Light50_up, &b_bTagSF_weight_MV2c10_Continuous_Light50_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light50_down", &bTagSF_weight_MV2c10_Continuous_Light50_down, &b_bTagSF_weight_MV2c10_Continuous_Light50_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light51_up", &bTagSF_weight_MV2c10_Continuous_Light51_up, &b_bTagSF_weight_MV2c10_Continuous_Light51_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light51_down", &bTagSF_weight_MV2c10_Continuous_Light51_down, &b_bTagSF_weight_MV2c10_Continuous_Light51_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light52_up", &bTagSF_weight_MV2c10_Continuous_Light52_up, &b_bTagSF_weight_MV2c10_Continuous_Light52_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light52_down", &bTagSF_weight_MV2c10_Continuous_Light52_down, &b_bTagSF_weight_MV2c10_Continuous_Light52_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light53_up", &bTagSF_weight_MV2c10_Continuous_Light53_up, &b_bTagSF_weight_MV2c10_Continuous_Light53_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light53_down", &bTagSF_weight_MV2c10_Continuous_Light53_down, &b_bTagSF_weight_MV2c10_Continuous_Light53_down);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light54_up", &bTagSF_weight_MV2c10_Continuous_Light54_up, &b_bTagSF_weight_MV2c10_Continuous_Light54_up);
         tree->SetBranchAddress("bTagSF_weight_MV2c10_Continuous_Light54_down", &bTagSF_weight_MV2c10_Continuous_Light54_down, &b_bTagSF_weight_MV2c10_Continuous_Light54_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B0_up", &bTagSF_weight_DL1_Continuous_B0_up, &b_bTagSF_weight_DL1_Continuous_B0_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B0_down", &bTagSF_weight_DL1_Continuous_B0_down, &b_bTagSF_weight_DL1_Continuous_B0_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B1_up", &bTagSF_weight_DL1_Continuous_B1_up, &b_bTagSF_weight_DL1_Continuous_B1_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B1_down", &bTagSF_weight_DL1_Continuous_B1_down, &b_bTagSF_weight_DL1_Continuous_B1_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B2_up", &bTagSF_weight_DL1_Continuous_B2_up, &b_bTagSF_weight_DL1_Continuous_B2_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B2_down", &bTagSF_weight_DL1_Continuous_B2_down, &b_bTagSF_weight_DL1_Continuous_B2_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B3_up", &bTagSF_weight_DL1_Continuous_B3_up, &b_bTagSF_weight_DL1_Continuous_B3_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B3_down", &bTagSF_weight_DL1_Continuous_B3_down, &b_bTagSF_weight_DL1_Continuous_B3_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B4_up", &bTagSF_weight_DL1_Continuous_B4_up, &b_bTagSF_weight_DL1_Continuous_B4_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B4_down", &bTagSF_weight_DL1_Continuous_B4_down, &b_bTagSF_weight_DL1_Continuous_B4_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B5_up", &bTagSF_weight_DL1_Continuous_B5_up, &b_bTagSF_weight_DL1_Continuous_B5_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B5_down", &bTagSF_weight_DL1_Continuous_B5_down, &b_bTagSF_weight_DL1_Continuous_B5_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B6_up", &bTagSF_weight_DL1_Continuous_B6_up, &b_bTagSF_weight_DL1_Continuous_B6_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B6_down", &bTagSF_weight_DL1_Continuous_B6_down, &b_bTagSF_weight_DL1_Continuous_B6_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B7_up", &bTagSF_weight_DL1_Continuous_B7_up, &b_bTagSF_weight_DL1_Continuous_B7_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B7_down", &bTagSF_weight_DL1_Continuous_B7_down, &b_bTagSF_weight_DL1_Continuous_B7_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B8_up", &bTagSF_weight_DL1_Continuous_B8_up, &b_bTagSF_weight_DL1_Continuous_B8_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B8_down", &bTagSF_weight_DL1_Continuous_B8_down, &b_bTagSF_weight_DL1_Continuous_B8_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B9_up", &bTagSF_weight_DL1_Continuous_B9_up, &b_bTagSF_weight_DL1_Continuous_B9_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B9_down", &bTagSF_weight_DL1_Continuous_B9_down, &b_bTagSF_weight_DL1_Continuous_B9_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B10_up", &bTagSF_weight_DL1_Continuous_B10_up, &b_bTagSF_weight_DL1_Continuous_B10_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B10_down", &bTagSF_weight_DL1_Continuous_B10_down, &b_bTagSF_weight_DL1_Continuous_B10_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B11_up", &bTagSF_weight_DL1_Continuous_B11_up, &b_bTagSF_weight_DL1_Continuous_B11_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B11_down", &bTagSF_weight_DL1_Continuous_B11_down, &b_bTagSF_weight_DL1_Continuous_B11_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B12_up", &bTagSF_weight_DL1_Continuous_B12_up, &b_bTagSF_weight_DL1_Continuous_B12_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B12_down", &bTagSF_weight_DL1_Continuous_B12_down, &b_bTagSF_weight_DL1_Continuous_B12_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B13_up", &bTagSF_weight_DL1_Continuous_B13_up, &b_bTagSF_weight_DL1_Continuous_B13_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B13_down", &bTagSF_weight_DL1_Continuous_B13_down, &b_bTagSF_weight_DL1_Continuous_B13_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B14_up", &bTagSF_weight_DL1_Continuous_B14_up, &b_bTagSF_weight_DL1_Continuous_B14_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B14_down", &bTagSF_weight_DL1_Continuous_B14_down, &b_bTagSF_weight_DL1_Continuous_B14_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B15_up", &bTagSF_weight_DL1_Continuous_B15_up, &b_bTagSF_weight_DL1_Continuous_B15_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B15_down", &bTagSF_weight_DL1_Continuous_B15_down, &b_bTagSF_weight_DL1_Continuous_B15_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B16_up", &bTagSF_weight_DL1_Continuous_B16_up, &b_bTagSF_weight_DL1_Continuous_B16_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B16_down", &bTagSF_weight_DL1_Continuous_B16_down, &b_bTagSF_weight_DL1_Continuous_B16_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B17_up", &bTagSF_weight_DL1_Continuous_B17_up, &b_bTagSF_weight_DL1_Continuous_B17_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B17_down", &bTagSF_weight_DL1_Continuous_B17_down, &b_bTagSF_weight_DL1_Continuous_B17_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B18_up", &bTagSF_weight_DL1_Continuous_B18_up, &b_bTagSF_weight_DL1_Continuous_B18_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B18_down", &bTagSF_weight_DL1_Continuous_B18_down, &b_bTagSF_weight_DL1_Continuous_B18_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B19_up", &bTagSF_weight_DL1_Continuous_B19_up, &b_bTagSF_weight_DL1_Continuous_B19_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B19_down", &bTagSF_weight_DL1_Continuous_B19_down, &b_bTagSF_weight_DL1_Continuous_B19_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B20_up", &bTagSF_weight_DL1_Continuous_B20_up, &b_bTagSF_weight_DL1_Continuous_B20_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B20_down", &bTagSF_weight_DL1_Continuous_B20_down, &b_bTagSF_weight_DL1_Continuous_B20_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B21_up", &bTagSF_weight_DL1_Continuous_B21_up, &b_bTagSF_weight_DL1_Continuous_B21_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B21_down", &bTagSF_weight_DL1_Continuous_B21_down, &b_bTagSF_weight_DL1_Continuous_B21_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B22_up", &bTagSF_weight_DL1_Continuous_B22_up, &b_bTagSF_weight_DL1_Continuous_B22_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B22_down", &bTagSF_weight_DL1_Continuous_B22_down, &b_bTagSF_weight_DL1_Continuous_B22_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B23_up", &bTagSF_weight_DL1_Continuous_B23_up, &b_bTagSF_weight_DL1_Continuous_B23_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B23_down", &bTagSF_weight_DL1_Continuous_B23_down, &b_bTagSF_weight_DL1_Continuous_B23_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B24_up", &bTagSF_weight_DL1_Continuous_B24_up, &b_bTagSF_weight_DL1_Continuous_B24_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B24_down", &bTagSF_weight_DL1_Continuous_B24_down, &b_bTagSF_weight_DL1_Continuous_B24_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B25_up", &bTagSF_weight_DL1_Continuous_B25_up, &b_bTagSF_weight_DL1_Continuous_B25_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B25_down", &bTagSF_weight_DL1_Continuous_B25_down, &b_bTagSF_weight_DL1_Continuous_B25_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B26_up", &bTagSF_weight_DL1_Continuous_B26_up, &b_bTagSF_weight_DL1_Continuous_B26_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B26_down", &bTagSF_weight_DL1_Continuous_B26_down, &b_bTagSF_weight_DL1_Continuous_B26_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B27_up", &bTagSF_weight_DL1_Continuous_B27_up, &b_bTagSF_weight_DL1_Continuous_B27_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B27_down", &bTagSF_weight_DL1_Continuous_B27_down, &b_bTagSF_weight_DL1_Continuous_B27_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B28_up", &bTagSF_weight_DL1_Continuous_B28_up, &b_bTagSF_weight_DL1_Continuous_B28_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B28_down", &bTagSF_weight_DL1_Continuous_B28_down, &b_bTagSF_weight_DL1_Continuous_B28_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B29_up", &bTagSF_weight_DL1_Continuous_B29_up, &b_bTagSF_weight_DL1_Continuous_B29_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B29_down", &bTagSF_weight_DL1_Continuous_B29_down, &b_bTagSF_weight_DL1_Continuous_B29_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B30_up", &bTagSF_weight_DL1_Continuous_B30_up, &b_bTagSF_weight_DL1_Continuous_B30_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B30_down", &bTagSF_weight_DL1_Continuous_B30_down, &b_bTagSF_weight_DL1_Continuous_B30_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B31_up", &bTagSF_weight_DL1_Continuous_B31_up, &b_bTagSF_weight_DL1_Continuous_B31_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B31_down", &bTagSF_weight_DL1_Continuous_B31_down, &b_bTagSF_weight_DL1_Continuous_B31_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B32_up", &bTagSF_weight_DL1_Continuous_B32_up, &b_bTagSF_weight_DL1_Continuous_B32_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B32_down", &bTagSF_weight_DL1_Continuous_B32_down, &b_bTagSF_weight_DL1_Continuous_B32_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B33_up", &bTagSF_weight_DL1_Continuous_B33_up, &b_bTagSF_weight_DL1_Continuous_B33_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B33_down", &bTagSF_weight_DL1_Continuous_B33_down, &b_bTagSF_weight_DL1_Continuous_B33_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B34_up", &bTagSF_weight_DL1_Continuous_B34_up, &b_bTagSF_weight_DL1_Continuous_B34_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B34_down", &bTagSF_weight_DL1_Continuous_B34_down, &b_bTagSF_weight_DL1_Continuous_B34_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B35_up", &bTagSF_weight_DL1_Continuous_B35_up, &b_bTagSF_weight_DL1_Continuous_B35_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B35_down", &bTagSF_weight_DL1_Continuous_B35_down, &b_bTagSF_weight_DL1_Continuous_B35_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B36_up", &bTagSF_weight_DL1_Continuous_B36_up, &b_bTagSF_weight_DL1_Continuous_B36_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B36_down", &bTagSF_weight_DL1_Continuous_B36_down, &b_bTagSF_weight_DL1_Continuous_B36_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B37_up", &bTagSF_weight_DL1_Continuous_B37_up, &b_bTagSF_weight_DL1_Continuous_B37_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B37_down", &bTagSF_weight_DL1_Continuous_B37_down, &b_bTagSF_weight_DL1_Continuous_B37_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B38_up", &bTagSF_weight_DL1_Continuous_B38_up, &b_bTagSF_weight_DL1_Continuous_B38_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B38_down", &bTagSF_weight_DL1_Continuous_B38_down, &b_bTagSF_weight_DL1_Continuous_B38_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B39_up", &bTagSF_weight_DL1_Continuous_B39_up, &b_bTagSF_weight_DL1_Continuous_B39_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B39_down", &bTagSF_weight_DL1_Continuous_B39_down, &b_bTagSF_weight_DL1_Continuous_B39_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B40_up", &bTagSF_weight_DL1_Continuous_B40_up, &b_bTagSF_weight_DL1_Continuous_B40_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B40_down", &bTagSF_weight_DL1_Continuous_B40_down, &b_bTagSF_weight_DL1_Continuous_B40_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B41_up", &bTagSF_weight_DL1_Continuous_B41_up, &b_bTagSF_weight_DL1_Continuous_B41_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B41_down", &bTagSF_weight_DL1_Continuous_B41_down, &b_bTagSF_weight_DL1_Continuous_B41_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B42_up", &bTagSF_weight_DL1_Continuous_B42_up, &b_bTagSF_weight_DL1_Continuous_B42_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B42_down", &bTagSF_weight_DL1_Continuous_B42_down, &b_bTagSF_weight_DL1_Continuous_B42_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B43_up", &bTagSF_weight_DL1_Continuous_B43_up, &b_bTagSF_weight_DL1_Continuous_B43_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B43_down", &bTagSF_weight_DL1_Continuous_B43_down, &b_bTagSF_weight_DL1_Continuous_B43_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B44_up", &bTagSF_weight_DL1_Continuous_B44_up, &b_bTagSF_weight_DL1_Continuous_B44_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_B44_down", &bTagSF_weight_DL1_Continuous_B44_down, &b_bTagSF_weight_DL1_Continuous_B44_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C0_up", &bTagSF_weight_DL1_Continuous_C0_up, &b_bTagSF_weight_DL1_Continuous_C0_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C0_down", &bTagSF_weight_DL1_Continuous_C0_down, &b_bTagSF_weight_DL1_Continuous_C0_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C1_up", &bTagSF_weight_DL1_Continuous_C1_up, &b_bTagSF_weight_DL1_Continuous_C1_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C1_down", &bTagSF_weight_DL1_Continuous_C1_down, &b_bTagSF_weight_DL1_Continuous_C1_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C2_up", &bTagSF_weight_DL1_Continuous_C2_up, &b_bTagSF_weight_DL1_Continuous_C2_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C2_down", &bTagSF_weight_DL1_Continuous_C2_down, &b_bTagSF_weight_DL1_Continuous_C2_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C3_up", &bTagSF_weight_DL1_Continuous_C3_up, &b_bTagSF_weight_DL1_Continuous_C3_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C3_down", &bTagSF_weight_DL1_Continuous_C3_down, &b_bTagSF_weight_DL1_Continuous_C3_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C4_up", &bTagSF_weight_DL1_Continuous_C4_up, &b_bTagSF_weight_DL1_Continuous_C4_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C4_down", &bTagSF_weight_DL1_Continuous_C4_down, &b_bTagSF_weight_DL1_Continuous_C4_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C5_up", &bTagSF_weight_DL1_Continuous_C5_up, &b_bTagSF_weight_DL1_Continuous_C5_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C5_down", &bTagSF_weight_DL1_Continuous_C5_down, &b_bTagSF_weight_DL1_Continuous_C5_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C6_up", &bTagSF_weight_DL1_Continuous_C6_up, &b_bTagSF_weight_DL1_Continuous_C6_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C6_down", &bTagSF_weight_DL1_Continuous_C6_down, &b_bTagSF_weight_DL1_Continuous_C6_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C7_up", &bTagSF_weight_DL1_Continuous_C7_up, &b_bTagSF_weight_DL1_Continuous_C7_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C7_down", &bTagSF_weight_DL1_Continuous_C7_down, &b_bTagSF_weight_DL1_Continuous_C7_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C8_up", &bTagSF_weight_DL1_Continuous_C8_up, &b_bTagSF_weight_DL1_Continuous_C8_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C8_down", &bTagSF_weight_DL1_Continuous_C8_down, &b_bTagSF_weight_DL1_Continuous_C8_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C9_up", &bTagSF_weight_DL1_Continuous_C9_up, &b_bTagSF_weight_DL1_Continuous_C9_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C9_down", &bTagSF_weight_DL1_Continuous_C9_down, &b_bTagSF_weight_DL1_Continuous_C9_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C10_up", &bTagSF_weight_DL1_Continuous_C10_up, &b_bTagSF_weight_DL1_Continuous_C10_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C10_down", &bTagSF_weight_DL1_Continuous_C10_down, &b_bTagSF_weight_DL1_Continuous_C10_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C11_up", &bTagSF_weight_DL1_Continuous_C11_up, &b_bTagSF_weight_DL1_Continuous_C11_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C11_down", &bTagSF_weight_DL1_Continuous_C11_down, &b_bTagSF_weight_DL1_Continuous_C11_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C12_up", &bTagSF_weight_DL1_Continuous_C12_up, &b_bTagSF_weight_DL1_Continuous_C12_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C12_down", &bTagSF_weight_DL1_Continuous_C12_down, &b_bTagSF_weight_DL1_Continuous_C12_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C13_up", &bTagSF_weight_DL1_Continuous_C13_up, &b_bTagSF_weight_DL1_Continuous_C13_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C13_down", &bTagSF_weight_DL1_Continuous_C13_down, &b_bTagSF_weight_DL1_Continuous_C13_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C14_up", &bTagSF_weight_DL1_Continuous_C14_up, &b_bTagSF_weight_DL1_Continuous_C14_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_C14_down", &bTagSF_weight_DL1_Continuous_C14_down, &b_bTagSF_weight_DL1_Continuous_C14_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light0_up", &bTagSF_weight_DL1_Continuous_Light0_up, &b_bTagSF_weight_DL1_Continuous_Light0_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light0_down", &bTagSF_weight_DL1_Continuous_Light0_down, &b_bTagSF_weight_DL1_Continuous_Light0_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light1_up", &bTagSF_weight_DL1_Continuous_Light1_up, &b_bTagSF_weight_DL1_Continuous_Light1_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light1_down", &bTagSF_weight_DL1_Continuous_Light1_down, &b_bTagSF_weight_DL1_Continuous_Light1_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light2_up", &bTagSF_weight_DL1_Continuous_Light2_up, &b_bTagSF_weight_DL1_Continuous_Light2_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light2_down", &bTagSF_weight_DL1_Continuous_Light2_down, &b_bTagSF_weight_DL1_Continuous_Light2_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light3_up", &bTagSF_weight_DL1_Continuous_Light3_up, &b_bTagSF_weight_DL1_Continuous_Light3_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light3_down", &bTagSF_weight_DL1_Continuous_Light3_down, &b_bTagSF_weight_DL1_Continuous_Light3_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light4_up", &bTagSF_weight_DL1_Continuous_Light4_up, &b_bTagSF_weight_DL1_Continuous_Light4_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light4_down", &bTagSF_weight_DL1_Continuous_Light4_down, &b_bTagSF_weight_DL1_Continuous_Light4_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light5_up", &bTagSF_weight_DL1_Continuous_Light5_up, &b_bTagSF_weight_DL1_Continuous_Light5_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light5_down", &bTagSF_weight_DL1_Continuous_Light5_down, &b_bTagSF_weight_DL1_Continuous_Light5_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light6_up", &bTagSF_weight_DL1_Continuous_Light6_up, &b_bTagSF_weight_DL1_Continuous_Light6_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light6_down", &bTagSF_weight_DL1_Continuous_Light6_down, &b_bTagSF_weight_DL1_Continuous_Light6_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light7_up", &bTagSF_weight_DL1_Continuous_Light7_up, &b_bTagSF_weight_DL1_Continuous_Light7_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light7_down", &bTagSF_weight_DL1_Continuous_Light7_down, &b_bTagSF_weight_DL1_Continuous_Light7_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light8_up", &bTagSF_weight_DL1_Continuous_Light8_up, &b_bTagSF_weight_DL1_Continuous_Light8_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light8_down", &bTagSF_weight_DL1_Continuous_Light8_down, &b_bTagSF_weight_DL1_Continuous_Light8_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light9_up", &bTagSF_weight_DL1_Continuous_Light9_up, &b_bTagSF_weight_DL1_Continuous_Light9_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light9_down", &bTagSF_weight_DL1_Continuous_Light9_down, &b_bTagSF_weight_DL1_Continuous_Light9_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light10_up", &bTagSF_weight_DL1_Continuous_Light10_up, &b_bTagSF_weight_DL1_Continuous_Light10_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light10_down", &bTagSF_weight_DL1_Continuous_Light10_down, &b_bTagSF_weight_DL1_Continuous_Light10_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light11_up", &bTagSF_weight_DL1_Continuous_Light11_up, &b_bTagSF_weight_DL1_Continuous_Light11_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light11_down", &bTagSF_weight_DL1_Continuous_Light11_down, &b_bTagSF_weight_DL1_Continuous_Light11_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light12_up", &bTagSF_weight_DL1_Continuous_Light12_up, &b_bTagSF_weight_DL1_Continuous_Light12_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light12_down", &bTagSF_weight_DL1_Continuous_Light12_down, &b_bTagSF_weight_DL1_Continuous_Light12_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light13_up", &bTagSF_weight_DL1_Continuous_Light13_up, &b_bTagSF_weight_DL1_Continuous_Light13_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light13_down", &bTagSF_weight_DL1_Continuous_Light13_down, &b_bTagSF_weight_DL1_Continuous_Light13_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light14_up", &bTagSF_weight_DL1_Continuous_Light14_up, &b_bTagSF_weight_DL1_Continuous_Light14_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light14_down", &bTagSF_weight_DL1_Continuous_Light14_down, &b_bTagSF_weight_DL1_Continuous_Light14_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light15_up", &bTagSF_weight_DL1_Continuous_Light15_up, &b_bTagSF_weight_DL1_Continuous_Light15_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light15_down", &bTagSF_weight_DL1_Continuous_Light15_down, &b_bTagSF_weight_DL1_Continuous_Light15_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light16_up", &bTagSF_weight_DL1_Continuous_Light16_up, &b_bTagSF_weight_DL1_Continuous_Light16_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light16_down", &bTagSF_weight_DL1_Continuous_Light16_down, &b_bTagSF_weight_DL1_Continuous_Light16_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light17_up", &bTagSF_weight_DL1_Continuous_Light17_up, &b_bTagSF_weight_DL1_Continuous_Light17_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light17_down", &bTagSF_weight_DL1_Continuous_Light17_down, &b_bTagSF_weight_DL1_Continuous_Light17_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light18_up", &bTagSF_weight_DL1_Continuous_Light18_up, &b_bTagSF_weight_DL1_Continuous_Light18_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light18_down", &bTagSF_weight_DL1_Continuous_Light18_down, &b_bTagSF_weight_DL1_Continuous_Light18_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light19_up", &bTagSF_weight_DL1_Continuous_Light19_up, &b_bTagSF_weight_DL1_Continuous_Light19_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light19_down", &bTagSF_weight_DL1_Continuous_Light19_down, &b_bTagSF_weight_DL1_Continuous_Light19_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light20_up", &bTagSF_weight_DL1_Continuous_Light20_up, &b_bTagSF_weight_DL1_Continuous_Light20_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light20_down", &bTagSF_weight_DL1_Continuous_Light20_down, &b_bTagSF_weight_DL1_Continuous_Light20_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light21_up", &bTagSF_weight_DL1_Continuous_Light21_up, &b_bTagSF_weight_DL1_Continuous_Light21_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light21_down", &bTagSF_weight_DL1_Continuous_Light21_down, &b_bTagSF_weight_DL1_Continuous_Light21_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light22_up", &bTagSF_weight_DL1_Continuous_Light22_up, &b_bTagSF_weight_DL1_Continuous_Light22_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light22_down", &bTagSF_weight_DL1_Continuous_Light22_down, &b_bTagSF_weight_DL1_Continuous_Light22_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light23_up", &bTagSF_weight_DL1_Continuous_Light23_up, &b_bTagSF_weight_DL1_Continuous_Light23_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light23_down", &bTagSF_weight_DL1_Continuous_Light23_down, &b_bTagSF_weight_DL1_Continuous_Light23_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light24_up", &bTagSF_weight_DL1_Continuous_Light24_up, &b_bTagSF_weight_DL1_Continuous_Light24_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light24_down", &bTagSF_weight_DL1_Continuous_Light24_down, &b_bTagSF_weight_DL1_Continuous_Light24_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light25_up", &bTagSF_weight_DL1_Continuous_Light25_up, &b_bTagSF_weight_DL1_Continuous_Light25_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light25_down", &bTagSF_weight_DL1_Continuous_Light25_down, &b_bTagSF_weight_DL1_Continuous_Light25_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light26_up", &bTagSF_weight_DL1_Continuous_Light26_up, &b_bTagSF_weight_DL1_Continuous_Light26_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light26_down", &bTagSF_weight_DL1_Continuous_Light26_down, &b_bTagSF_weight_DL1_Continuous_Light26_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light27_up", &bTagSF_weight_DL1_Continuous_Light27_up, &b_bTagSF_weight_DL1_Continuous_Light27_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light27_down", &bTagSF_weight_DL1_Continuous_Light27_down, &b_bTagSF_weight_DL1_Continuous_Light27_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light28_up", &bTagSF_weight_DL1_Continuous_Light28_up, &b_bTagSF_weight_DL1_Continuous_Light28_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light28_down", &bTagSF_weight_DL1_Continuous_Light28_down, &b_bTagSF_weight_DL1_Continuous_Light28_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light29_up", &bTagSF_weight_DL1_Continuous_Light29_up, &b_bTagSF_weight_DL1_Continuous_Light29_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light29_down", &bTagSF_weight_DL1_Continuous_Light29_down, &b_bTagSF_weight_DL1_Continuous_Light29_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light30_up", &bTagSF_weight_DL1_Continuous_Light30_up, &b_bTagSF_weight_DL1_Continuous_Light30_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light30_down", &bTagSF_weight_DL1_Continuous_Light30_down, &b_bTagSF_weight_DL1_Continuous_Light30_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light31_up", &bTagSF_weight_DL1_Continuous_Light31_up, &b_bTagSF_weight_DL1_Continuous_Light31_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light31_down", &bTagSF_weight_DL1_Continuous_Light31_down, &b_bTagSF_weight_DL1_Continuous_Light31_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light32_up", &bTagSF_weight_DL1_Continuous_Light32_up, &b_bTagSF_weight_DL1_Continuous_Light32_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light32_down", &bTagSF_weight_DL1_Continuous_Light32_down, &b_bTagSF_weight_DL1_Continuous_Light32_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light33_up", &bTagSF_weight_DL1_Continuous_Light33_up, &b_bTagSF_weight_DL1_Continuous_Light33_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light33_down", &bTagSF_weight_DL1_Continuous_Light33_down, &b_bTagSF_weight_DL1_Continuous_Light33_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light34_up", &bTagSF_weight_DL1_Continuous_Light34_up, &b_bTagSF_weight_DL1_Continuous_Light34_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light34_down", &bTagSF_weight_DL1_Continuous_Light34_down, &b_bTagSF_weight_DL1_Continuous_Light34_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light35_up", &bTagSF_weight_DL1_Continuous_Light35_up, &b_bTagSF_weight_DL1_Continuous_Light35_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light35_down", &bTagSF_weight_DL1_Continuous_Light35_down, &b_bTagSF_weight_DL1_Continuous_Light35_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light36_up", &bTagSF_weight_DL1_Continuous_Light36_up, &b_bTagSF_weight_DL1_Continuous_Light36_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light36_down", &bTagSF_weight_DL1_Continuous_Light36_down, &b_bTagSF_weight_DL1_Continuous_Light36_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light37_up", &bTagSF_weight_DL1_Continuous_Light37_up, &b_bTagSF_weight_DL1_Continuous_Light37_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light37_down", &bTagSF_weight_DL1_Continuous_Light37_down, &b_bTagSF_weight_DL1_Continuous_Light37_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light38_up", &bTagSF_weight_DL1_Continuous_Light38_up, &b_bTagSF_weight_DL1_Continuous_Light38_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light38_down", &bTagSF_weight_DL1_Continuous_Light38_down, &b_bTagSF_weight_DL1_Continuous_Light38_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light39_up", &bTagSF_weight_DL1_Continuous_Light39_up, &b_bTagSF_weight_DL1_Continuous_Light39_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light39_down", &bTagSF_weight_DL1_Continuous_Light39_down, &b_bTagSF_weight_DL1_Continuous_Light39_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light40_up", &bTagSF_weight_DL1_Continuous_Light40_up, &b_bTagSF_weight_DL1_Continuous_Light40_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light40_down", &bTagSF_weight_DL1_Continuous_Light40_down, &b_bTagSF_weight_DL1_Continuous_Light40_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light41_up", &bTagSF_weight_DL1_Continuous_Light41_up, &b_bTagSF_weight_DL1_Continuous_Light41_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light41_down", &bTagSF_weight_DL1_Continuous_Light41_down, &b_bTagSF_weight_DL1_Continuous_Light41_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light42_up", &bTagSF_weight_DL1_Continuous_Light42_up, &b_bTagSF_weight_DL1_Continuous_Light42_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light42_down", &bTagSF_weight_DL1_Continuous_Light42_down, &b_bTagSF_weight_DL1_Continuous_Light42_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light43_up", &bTagSF_weight_DL1_Continuous_Light43_up, &b_bTagSF_weight_DL1_Continuous_Light43_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light43_down", &bTagSF_weight_DL1_Continuous_Light43_down, &b_bTagSF_weight_DL1_Continuous_Light43_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light44_up", &bTagSF_weight_DL1_Continuous_Light44_up, &b_bTagSF_weight_DL1_Continuous_Light44_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light44_down", &bTagSF_weight_DL1_Continuous_Light44_down, &b_bTagSF_weight_DL1_Continuous_Light44_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light45_up", &bTagSF_weight_DL1_Continuous_Light45_up, &b_bTagSF_weight_DL1_Continuous_Light45_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light45_down", &bTagSF_weight_DL1_Continuous_Light45_down, &b_bTagSF_weight_DL1_Continuous_Light45_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light46_up", &bTagSF_weight_DL1_Continuous_Light46_up, &b_bTagSF_weight_DL1_Continuous_Light46_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light46_down", &bTagSF_weight_DL1_Continuous_Light46_down, &b_bTagSF_weight_DL1_Continuous_Light46_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light47_up", &bTagSF_weight_DL1_Continuous_Light47_up, &b_bTagSF_weight_DL1_Continuous_Light47_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light47_down", &bTagSF_weight_DL1_Continuous_Light47_down, &b_bTagSF_weight_DL1_Continuous_Light47_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light48_up", &bTagSF_weight_DL1_Continuous_Light48_up, &b_bTagSF_weight_DL1_Continuous_Light48_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light48_down", &bTagSF_weight_DL1_Continuous_Light48_down, &b_bTagSF_weight_DL1_Continuous_Light48_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light49_up", &bTagSF_weight_DL1_Continuous_Light49_up, &b_bTagSF_weight_DL1_Continuous_Light49_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light49_down", &bTagSF_weight_DL1_Continuous_Light49_down, &b_bTagSF_weight_DL1_Continuous_Light49_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light50_up", &bTagSF_weight_DL1_Continuous_Light50_up, &b_bTagSF_weight_DL1_Continuous_Light50_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light50_down", &bTagSF_weight_DL1_Continuous_Light50_down, &b_bTagSF_weight_DL1_Continuous_Light50_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light51_up", &bTagSF_weight_DL1_Continuous_Light51_up, &b_bTagSF_weight_DL1_Continuous_Light51_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light51_down", &bTagSF_weight_DL1_Continuous_Light51_down, &b_bTagSF_weight_DL1_Continuous_Light51_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light52_up", &bTagSF_weight_DL1_Continuous_Light52_up, &b_bTagSF_weight_DL1_Continuous_Light52_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light52_down", &bTagSF_weight_DL1_Continuous_Light52_down, &b_bTagSF_weight_DL1_Continuous_Light52_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light53_up", &bTagSF_weight_DL1_Continuous_Light53_up, &b_bTagSF_weight_DL1_Continuous_Light53_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light53_down", &bTagSF_weight_DL1_Continuous_Light53_down, &b_bTagSF_weight_DL1_Continuous_Light53_down);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light54_up", &bTagSF_weight_DL1_Continuous_Light54_up, &b_bTagSF_weight_DL1_Continuous_Light54_up);
         tree->SetBranchAddress("bTagSF_weight_DL1_Continuous_Light54_down", &bTagSF_weight_DL1_Continuous_Light54_down, &b_bTagSF_weight_DL1_Continuous_Light54_down);
         tree->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepEffTrigLoose_MU_SF_Trigger_STAT_DOWN);
         tree->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_STAT_DOWN", &lepEffTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepEffTrigTight_MU_SF_Trigger_STAT_DOWN);
         tree->SetBranchAddress("lepEffTrigLoose_MU_SF_Trigger_STAT_UP", &lepEffTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepEffTrigLoose_MU_SF_Trigger_STAT_UP);
         tree->SetBranchAddress("lepEffTrigTight_MU_SF_Trigger_STAT_UP", &lepEffTrigTight_MU_SF_Trigger_STAT_UP, &b_lepEffTrigTight_MU_SF_Trigger_STAT_UP);
      }
      tree->SetBranchAddress("m_jet_tagWeightBin", &m_jet_tagWeightBin, &b_m_jet_tagWeightBin);
   }
   tree->SetBranchAddress("JVT_EventWeight_UP", &JVT_EventWeight_UP, &b_JVT_EventWeight_UP);
   tree->SetBranchAddress("JVT_EventWeight_DOWN", &JVT_EventWeight_DOWN, &b_JVT_EventWeight_DOWN);
   tree->SetBranchAddress("m_truth_m", &m_truth_m, &b_m_truth_m);
   tree->SetBranchAddress("m_truth_pt", &m_truth_pt, &b_m_truth_pt);
   tree->SetBranchAddress("m_truth_eta", &m_truth_eta, &b_m_truth_eta);
   tree->SetBranchAddress("m_truth_phi", &m_truth_phi, &b_m_truth_phi);
   tree->SetBranchAddress("m_truth_e", &m_truth_e, &b_m_truth_e);
   tree->SetBranchAddress("m_truth_pdgId", &m_truth_pdgId, &b_m_truth_pdgId);
   tree->SetBranchAddress("m_truth_status", &m_truth_status, &b_m_truth_status);
   tree->SetBranchAddress("m_truth_barcode", &m_truth_barcode, &b_m_truth_barcode);
   //tree->SetBranchAddress("m_truth_parents", &m_truth_parents, &b_m_truth_parents);
   //tree->SetBranchAddress("m_truth_children", &m_truth_children, &b_m_truth_children);
   tree->SetBranchAddress("m_mcevt_pdf_X1", &m_mcevt_pdf_X1, &b_m_mcevt_pdf_X1);
   tree->SetBranchAddress("m_mcevt_pdf_X2", &m_mcevt_pdf_X2, &b_m_mcevt_pdf_X2);
   tree->SetBranchAddress("m_mcevt_pdf_PDGID1", &m_mcevt_pdf_PDGID1, &b_m_mcevt_pdf_PDGID1);
   tree->SetBranchAddress("m_mcevt_pdf_PDGID2", &m_mcevt_pdf_PDGID2, &b_m_mcevt_pdf_PDGID2);
   tree->SetBranchAddress("m_mcevt_pdf_Q", &m_mcevt_pdf_Q, &b_m_mcevt_pdf_Q);
   tree->SetBranchAddress("m_mcevt_pdf_XF1", &m_mcevt_pdf_XF1, &b_m_mcevt_pdf_XF1);
   tree->SetBranchAddress("m_mcevt_pdf_XF2", &m_mcevt_pdf_XF2, &b_m_mcevt_pdf_XF2);
   tree->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   tree->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   tree->SetBranchAddress("lbn", &lbn, &b_lbn);
   tree->SetBranchAddress("bcid", &bcid, &b_bcid);
   tree->SetBranchAddress("passEventCleaning", &passEventCleaning, &b_passEventCleaning);
   tree->SetBranchAddress("m_vxp_x", &m_vxp_x, &b_m_vxp_x);
   tree->SetBranchAddress("m_vxp_y", &m_vxp_y, &b_m_vxp_y);
   tree->SetBranchAddress("m_vxp_z", &m_vxp_z, &b_m_vxp_z);
   tree->SetBranchAddress("SherpaNJetWeight", &SherpaNJetWeight, &b_SherpaNJetWeight);
   tree->SetBranchAddress("nTruthJets_SherpaRwght", &nTruthJets_SherpaRwght, &b_nTruthJets_SherpaRwght);
   tree->SetBranchAddress("higgs_pt", &higgs_pt, &b_higgs_pt);
   tree->SetBranchAddress("higgs_eta", &higgs_eta, &b_higgs_eta);
   tree->SetBranchAddress("higgs_phi", &higgs_phi, &b_higgs_phi);
   tree->SetBranchAddress("higgs_E", &higgs_E, &b_higgs_E);
   tree->SetBranchAddress("higgs_rapidity", &higgs_rapidity, &b_higgs_rapidity);
   tree->SetBranchAddress("top_pt", &top_pt, &b_top_pt);
   tree->SetBranchAddress("top_eta", &top_eta, &b_top_eta);
   tree->SetBranchAddress("top_phi", &top_phi, &b_top_phi);
   tree->SetBranchAddress("top_E", &top_E, &b_top_E);
   tree->SetBranchAddress("antitop_pt", &antitop_pt, &b_antitop_pt);
   tree->SetBranchAddress("antitop_eta", &antitop_eta, &b_antitop_eta);
   tree->SetBranchAddress("antitop_phi", &antitop_phi, &b_antitop_phi);
   tree->SetBranchAddress("antitop_E", &antitop_E, &b_antitop_E);
   tree->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   tree->SetBranchAddress("higgsDecayMode", &higgsDecayMode, &b_higgsDecayMode);
   tree->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   tree->SetBranchAddress("mc_isAFII", &mc_isAFII, &b_mc_isAFII);
   tree->SetBranchAddress("mc_xSection", &mc_xSection, &b_mc_xSection);
   tree->SetBranchAddress("mc_rawXSection", &mc_rawXSection, &b_mc_rawXSection);
   tree->SetBranchAddress("mc_kFactor", &mc_kFactor, &b_mc_kFactor);
   tree->SetBranchAddress("mc_showering", &mc_showering, &b_mc_showering);
   tree->SetBranchAddress("averageIntPerXing_uncorr", &averageIntPerXing_uncorr, &b_averageIntPerXing_uncorr);
   tree->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   tree->SetBranchAddress("actualIntPerXing", &actualIntPerXing, &b_actualIntPerXing);
   tree->SetBranchAddress("pileupHash", &pileupHash, &b_pileupHash);
   tree->SetBranchAddress("m_vxp_n", &m_vxp_n, &b_m_vxp_n);
   tree->SetBranchAddress("m_vxpu_n", &m_vxpu_n, &b_m_vxpu_n);
   tree->SetBranchAddress("m_vx_density", &m_vx_density, &b_m_vx_density);
   tree->SetBranchAddress("m_beam_posz", &m_beam_posz, &b_m_beam_posz);
   tree->SetBranchAddress("m_beam_sigmaz", &m_beam_sigmaz, &b_m_beam_sigmaz);
   tree->SetBranchAddress("m_hasMEphoton", &m_hasMEphoton, &b_m_hasMEphoton);
   tree->SetBranchAddress("m_hasMEphoton_DRgt02_nonhad", &m_hasMEphoton_DRgt02_nonhad, &b_m_hasMEphoton_DRgt02_nonhad);
   tree->SetBranchAddress("m_MEphoton_e", &m_MEphoton_e, &b_m_MEphoton_e);
   tree->SetBranchAddress("m_MEphoton_pt", &m_MEphoton_pt, &b_m_MEphoton_pt);
   tree->SetBranchAddress("m_MEphoton_eta", &m_MEphoton_eta, &b_m_MEphoton_eta);
   tree->SetBranchAddress("m_MEphoton_phi", &m_MEphoton_phi, &b_m_MEphoton_phi);
   tree->SetBranchAddress("m_MEphoton_mother_pdgId", &m_MEphoton_mother_pdgId, &b_m_MEphoton_mother_pdgId);
   tree->SetBranchAddress("m_MEphoton_mother_e", &m_MEphoton_mother_e, &b_m_MEphoton_mother_e);
   tree->SetBranchAddress("m_MEphoton_mother_pt", &m_MEphoton_mother_pt, &b_m_MEphoton_mother_pt);
   tree->SetBranchAddress("m_MEphoton_mother_eta", &m_MEphoton_mother_eta, &b_m_MEphoton_mother_eta);
   tree->SetBranchAddress("m_MEphoton_mother_phi", &m_MEphoton_mother_phi, &b_m_MEphoton_mother_phi);
   tree->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   tree->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   tree->SetBranchAddress("MET_RefFinal_sumet", &MET_RefFinal_sumet, &b_MET_RefFinal_sumet);
   tree->SetBranchAddress("MET_RefFinal_softTrk_et", &MET_RefFinal_softTrk_et, &b_MET_RefFinal_softTrk_et);
   tree->SetBranchAddress("MET_RefFinal_softTrk_phi", &MET_RefFinal_softTrk_phi, &b_MET_RefFinal_softTrk_phi);
   tree->SetBranchAddress("MET_RefFinal_softClus_et", &MET_RefFinal_softClus_et, &b_MET_RefFinal_softClus_et);
   tree->SetBranchAddress("MET_RefFinal_softClus_phi", &MET_RefFinal_softClus_phi, &b_MET_RefFinal_softClus_phi);
   tree->SetBranchAddress("MET_Truth_px", &MET_Truth_px, &b_MET_Truth_px);
   tree->SetBranchAddress("MET_Truth_py", &MET_Truth_py, &b_MET_Truth_py);
   tree->SetBranchAddress("MET_Truth_phi", &MET_Truth_phi, &b_MET_Truth_phi);
   tree->SetBranchAddress("MET_Truth_sumet", &MET_Truth_sumet, &b_MET_Truth_sumet);
   tree->SetBranchAddress("vtx_x", &vtx_x, &b_vtx_x);
   tree->SetBranchAddress("vtx_y", &vtx_y, &b_vtx_y);
   tree->SetBranchAddress("vtx_z", &vtx_z, &b_vtx_z);
   tree->SetBranchAddress("vtx_type", &vtx_type, &b_vtx_type);
   tree->SetBranchAddress("vtx_numTrk", &vtx_numTrk, &b_vtx_numTrk);
   tree->SetBranchAddress("electron_isolationLooseTrackOnly", &electron_isolationLooseTrackOnly, &b_electron_isolationLooseTrackOnly);
   tree->SetBranchAddress("muon_isolationLooseTrackOnly", &muon_isolationLooseTrackOnly, &b_muon_isolationLooseTrackOnly);
   tree->SetBranchAddress("electron_isolationLoose", &electron_isolationLoose, &b_electron_isolationLoose);
   tree->SetBranchAddress("muon_isolationLoose", &muon_isolationLoose, &b_muon_isolationLoose);
   tree->SetBranchAddress("electron_isolationGradient", &electron_isolationGradient, &b_electron_isolationGradient);
   tree->SetBranchAddress("muon_isolationGradient", &muon_isolationGradient, &b_muon_isolationGradient);
   tree->SetBranchAddress("electron_isolationGradientLoose", &electron_isolationGradientLoose, &b_electron_isolationGradientLoose);
   tree->SetBranchAddress("muon_isolationGradientLoose", &muon_isolationGradientLoose, &b_muon_isolationGradientLoose);
   tree->SetBranchAddress("electron_isolationFixedCutTightTrackOnly", &electron_isolationFixedCutTightTrackOnly, &b_electron_isolationFixedCutTightTrackOnly);
   tree->SetBranchAddress("muon_isolationFixedCutTightTrackOnly", &muon_isolationFixedCutTightTrackOnly, &b_muon_isolationFixedCutTightTrackOnly);
   tree->SetBranchAddress("electron_isolationFixedCutLoose", &electron_isolationFixedCutLoose, &b_electron_isolationFixedCutLoose);
   tree->SetBranchAddress("muon_isolationFixedCutLoose", &muon_isolationFixedCutLoose, &b_muon_isolationFixedCutLoose);
   tree->SetBranchAddress("electron_isolationFixedCutTight", &electron_isolationFixedCutTight, &b_electron_isolationFixedCutTight);
   tree->SetBranchAddress("electron_pt", &electron_pt, &b_electron_pt);
   tree->SetBranchAddress("electron_eta", &electron_eta, &b_electron_eta);
   tree->SetBranchAddress("electron_EtaBE2", &electron_EtaBE2, &b_electron_EtaBE2);
   tree->SetBranchAddress("electron_phi", &electron_phi, &b_electron_phi);
   tree->SetBranchAddress("electron_E", &electron_E, &b_electron_E);
   tree->SetBranchAddress("electron_ID", &electron_ID, &b_electron_ID);
   tree->SetBranchAddress("electron_sigd0PV", &electron_sigd0PV, &b_electron_sigd0PV);
   tree->SetBranchAddress("electron_z0SinTheta", &electron_z0SinTheta, &b_electron_z0SinTheta);
   tree->SetBranchAddress("electron_topoetcone20", &electron_topoetcone20, &b_electron_topoetcone20);
   tree->SetBranchAddress("electron_topoetcone30", &electron_topoetcone30, &b_electron_topoetcone30);
   tree->SetBranchAddress("electron_topoetcone40", &electron_topoetcone40, &b_electron_topoetcone40);
   tree->SetBranchAddress("electron_ptvarcone20", &electron_ptvarcone20, &b_electron_ptvarcone20);
   tree->SetBranchAddress("electron_ptvarcone30", &electron_ptvarcone30, &b_electron_ptvarcone30);
   tree->SetBranchAddress("electron_ptvarcone40", &electron_ptvarcone40, &b_electron_ptvarcone40);
   tree->SetBranchAddress("electron_isLooseLH", &electron_isLooseLH, &b_electron_isLooseLH);
   tree->SetBranchAddress("electron_isMediumLH", &electron_isMediumLH, &b_electron_isMediumLH);
   tree->SetBranchAddress("electron_isTightLH", &electron_isTightLH, &b_electron_isTightLH);
   tree->SetBranchAddress("electron_sharesTrk", &electron_sharesTrk, &b_electron_sharesTrk);
   tree->SetBranchAddress("electron_passOR", &electron_passOR, &b_electron_passOR);
   tree->SetBranchAddress("electron_isQMisID", &electron_isQMisID, &b_electron_isQMisID);
   tree->SetBranchAddress("electron_ChargeIDBDTLoose", &electron_ChargeIDBDTLoose, &b_electron_ChargeIDBDTLoose);
   tree->SetBranchAddress("electron_ChargeIDBDTMedium", &electron_ChargeIDBDTMedium, &b_electron_ChargeIDBDTMedium);
   tree->SetBranchAddress("electron_ChargeIDBDTTight", &electron_ChargeIDBDTTight, &b_electron_ChargeIDBDTTight);
   tree->SetBranchAddress("electron_match_HLT_2e12_lhloose_L12EM10VH", &electron_match_HLT_2e12_lhloose_L12EM10VH, &b_electron_match_HLT_2e12_lhloose_L12EM10VH);
   tree->SetBranchAddress("electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH", &electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH, &b_electron_match_HLT_2e12_lhvloose_nod0_L12EM10VH);
   tree->SetBranchAddress("electron_match_HLT_2e12_loose_L12EM10VH", &electron_match_HLT_2e12_loose_L12EM10VH, &b_electron_match_HLT_2e12_loose_L12EM10VH);
   tree->SetBranchAddress("electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH", &electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH, &b_electron_match_HLT_2e15_lhvloose_nod0_L12EM13VH);
   tree->SetBranchAddress("electron_match_HLT_2e17_lhvloose_nod0", &electron_match_HLT_2e17_lhvloose_nod0, &b_electron_match_HLT_2e17_lhvloose_nod0);
   tree->SetBranchAddress("electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI", &electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI, &b_electron_match_HLT_2e17_lhvloose_nod0_L12EM15VHI);
   tree->SetBranchAddress("electron_match_HLT_2e24_lhvloose_nod0", &electron_match_HLT_2e24_lhvloose_nod0, &b_electron_match_HLT_2e24_lhvloose_nod0);
   tree->SetBranchAddress("electron_match_HLT_e120_lhloose", &electron_match_HLT_e120_lhloose, &b_electron_match_HLT_e120_lhloose);
   tree->SetBranchAddress("electron_match_HLT_e12_lhloose", &electron_match_HLT_e12_lhloose, &b_electron_match_HLT_e12_lhloose);
   tree->SetBranchAddress("electron_match_HLT_e12_loose", &electron_match_HLT_e12_loose, &b_electron_match_HLT_e12_loose);
   tree->SetBranchAddress("electron_match_HLT_e140_lhloose", &electron_match_HLT_e140_lhloose, &b_electron_match_HLT_e140_lhloose);
   tree->SetBranchAddress("electron_match_HLT_e140_lhloose_nod0", &electron_match_HLT_e140_lhloose_nod0, &b_electron_match_HLT_e140_lhloose_nod0);
   tree->SetBranchAddress("electron_match_HLT_e140_loose", &electron_match_HLT_e140_loose, &b_electron_match_HLT_e140_loose);
   tree->SetBranchAddress("electron_match_HLT_e17_lhloose", &electron_match_HLT_e17_lhloose, &b_electron_match_HLT_e17_lhloose);
   tree->SetBranchAddress("electron_match_HLT_e17_lhloose_2e9_lhloose", &electron_match_HLT_e17_lhloose_2e9_lhloose, &b_electron_match_HLT_e17_lhloose_2e9_lhloose);
   tree->SetBranchAddress("electron_match_HLT_e17_lhloose_mu14", &electron_match_HLT_e17_lhloose_mu14, &b_electron_match_HLT_e17_lhloose_mu14);
   tree->SetBranchAddress("electron_match_HLT_e17_lhloose_nod0_mu14", &electron_match_HLT_e17_lhloose_nod0_mu14, &b_electron_match_HLT_e17_lhloose_nod0_mu14);
   tree->SetBranchAddress("electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo", &electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo, &b_electron_match_HLT_e17_lhmedium_nod0_ivarloose_tau25_medium1_tracktwo);
   tree->SetBranchAddress("electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo", &electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo, &b_electron_match_HLT_e17_lhmedium_nod0_tau25_medium1_tracktwo);
   tree->SetBranchAddress("electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo", &electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo, &b_electron_match_HLT_e17_lhmedium_tau25_medium1_tracktwo);
   tree->SetBranchAddress("electron_match_HLT_e17_loose", &electron_match_HLT_e17_loose, &b_electron_match_HLT_e17_loose);
   tree->SetBranchAddress("electron_match_HLT_e17_loose_mu14", &electron_match_HLT_e17_loose_mu14, &b_electron_match_HLT_e17_loose_mu14);
   tree->SetBranchAddress("electron_match_HLT_e24_lhmedium_L1EM18VH", &electron_match_HLT_e24_lhmedium_L1EM18VH, &b_electron_match_HLT_e24_lhmedium_L1EM18VH);
   tree->SetBranchAddress("electron_match_HLT_e24_lhmedium_L1EM20VH", &electron_match_HLT_e24_lhmedium_L1EM20VH, &b_electron_match_HLT_e24_lhmedium_L1EM20VH);
   tree->SetBranchAddress("electron_match_HLT_e24_lhmedium_iloose_L1EM18VH", &electron_match_HLT_e24_lhmedium_iloose_L1EM18VH, &b_electron_match_HLT_e24_lhmedium_iloose_L1EM18VH);
   tree->SetBranchAddress("electron_match_HLT_e24_lhmedium_nod0_L1EM20VH", &electron_match_HLT_e24_lhmedium_nod0_L1EM20VH, &b_electron_match_HLT_e24_lhmedium_nod0_L1EM20VH);
   tree->SetBranchAddress("electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1", &electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1, &b_electron_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1);
   tree->SetBranchAddress("electron_match_HLT_e24_lhtight_iloose", &electron_match_HLT_e24_lhtight_iloose, &b_electron_match_HLT_e24_lhtight_iloose);
   tree->SetBranchAddress("electron_match_HLT_e24_lhtight_iloose_L1EM20VH", &electron_match_HLT_e24_lhtight_iloose_L1EM20VH, &b_electron_match_HLT_e24_lhtight_iloose_L1EM20VH);
   tree->SetBranchAddress("electron_match_HLT_e24_lhtight_ivarloose", &electron_match_HLT_e24_lhtight_ivarloose, &b_electron_match_HLT_e24_lhtight_ivarloose);
   tree->SetBranchAddress("electron_match_HLT_e24_lhtight_nod0_ivarloose", &electron_match_HLT_e24_lhtight_nod0_ivarloose, &b_electron_match_HLT_e24_lhtight_nod0_ivarloose);
   tree->SetBranchAddress("electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1", &electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1, &b_electron_match_HLT_e24_medium_L1EM20VHI_mu8noL1);
   tree->SetBranchAddress("electron_match_HLT_e24_tight_iloose", &electron_match_HLT_e24_tight_iloose, &b_electron_match_HLT_e24_tight_iloose);
   tree->SetBranchAddress("electron_match_HLT_e24_tight_iloose_L1EM20VH", &electron_match_HLT_e24_tight_iloose_L1EM20VH, &b_electron_match_HLT_e24_tight_iloose_L1EM20VH);
   tree->SetBranchAddress("electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1", &electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1, &b_electron_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1);
   tree->SetBranchAddress("electron_match_HLT_e26_lhtight_iloose", &electron_match_HLT_e26_lhtight_iloose, &b_electron_match_HLT_e26_lhtight_iloose);
   tree->SetBranchAddress("electron_match_HLT_e26_lhtight_nod0_ivarloose", &electron_match_HLT_e26_lhtight_nod0_ivarloose, &b_electron_match_HLT_e26_lhtight_nod0_ivarloose);
   tree->SetBranchAddress("electron_match_HLT_e26_tight_iloose", &electron_match_HLT_e26_tight_iloose, &b_electron_match_HLT_e26_tight_iloose);
   tree->SetBranchAddress("electron_match_HLT_e300_etcut", &electron_match_HLT_e300_etcut, &b_electron_match_HLT_e300_etcut);
   tree->SetBranchAddress("electron_match_HLT_e5_lhloose", &electron_match_HLT_e5_lhloose, &b_electron_match_HLT_e5_lhloose);
   tree->SetBranchAddress("electron_match_HLT_e5_loose", &electron_match_HLT_e5_loose, &b_electron_match_HLT_e5_loose);
   tree->SetBranchAddress("electron_match_HLT_e60_lhmedium", &electron_match_HLT_e60_lhmedium, &b_electron_match_HLT_e60_lhmedium);
   tree->SetBranchAddress("electron_match_HLT_e60_lhmedium_nod0", &electron_match_HLT_e60_lhmedium_nod0, &b_electron_match_HLT_e60_lhmedium_nod0);
   tree->SetBranchAddress("electron_match_HLT_e60_medium", &electron_match_HLT_e60_medium, &b_electron_match_HLT_e60_medium);
   tree->SetBranchAddress("electron_match_HLT_e7_lhmedium_mu24", &electron_match_HLT_e7_lhmedium_mu24, &b_electron_match_HLT_e7_lhmedium_mu24);
   tree->SetBranchAddress("electron_match_HLT_e7_lhmedium_nod0_mu24", &electron_match_HLT_e7_lhmedium_nod0_mu24, &b_electron_match_HLT_e7_lhmedium_nod0_mu24);
   tree->SetBranchAddress("electron_match_HLT_e7_medium_mu24", &electron_match_HLT_e7_medium_mu24, &b_electron_match_HLT_e7_medium_mu24);
   tree->SetBranchAddress("electron_nInnerPix", &electron_nInnerPix, &b_electron_nInnerPix);
   tree->SetBranchAddress("electron_author", &electron_author, &b_electron_author);
   tree->SetBranchAddress("electron_d0", &electron_d0, &b_electron_d0);
   tree->SetBranchAddress("electron_z0", &electron_z0, &b_electron_z0);
   tree->SetBranchAddress("electron_vz", &electron_vz, &b_electron_vz);
   tree->SetBranchAddress("electron_deltaz0", &electron_deltaz0, &b_electron_deltaz0);
   tree->SetBranchAddress("electron_truthOrigin", &electron_truthOrigin, &b_electron_truthOrigin);
   tree->SetBranchAddress("electron_truthType", &electron_truthType, &b_electron_truthType);
   tree->SetBranchAddress("electron_firstEgMotherPdgId", &electron_firstEgMotherPdgId, &b_electron_firstEgMotherPdgId);
   tree->SetBranchAddress("electron_jetFitterComb", &electron_jetFitterComb, &b_electron_jetFitterComb);
   tree->SetBranchAddress("electron_PromptLeptonInput_sv1_jf_ntrkv", &electron_PromptLeptonInput_sv1_jf_ntrkv, &b_electron_PromptLeptonInput_sv1_jf_ntrkv);
   tree->SetBranchAddress("electron_PromptLeptonInput_TrackJetNTrack", &electron_PromptLeptonInput_TrackJetNTrack, &b_electron_PromptLeptonInput_TrackJetNTrack);
   tree->SetBranchAddress("electron_PromptLeptonInput_DL1mu", &electron_PromptLeptonInput_DL1mu, &b_electron_PromptLeptonInput_DL1mu);
   tree->SetBranchAddress("electron_PromptLeptonInput_DRlj", &electron_PromptLeptonInput_DRlj, &b_electron_PromptLeptonInput_DRlj);
   tree->SetBranchAddress("electron_PromptLeptonInput_LepJetPtFrac", &electron_PromptLeptonInput_LepJetPtFrac, &b_electron_PromptLeptonInput_LepJetPtFrac);
   tree->SetBranchAddress("electron_PromptLeptonInput_PtFrac", &electron_PromptLeptonInput_PtFrac, &b_electron_PromptLeptonInput_PtFrac);
   tree->SetBranchAddress("electron_PromptLeptonInput_PtRel", &electron_PromptLeptonInput_PtRel, &b_electron_PromptLeptonInput_PtRel);
   tree->SetBranchAddress("electron_PromptLeptonInput_ip2", &electron_PromptLeptonInput_ip2, &b_electron_PromptLeptonInput_ip2);
   tree->SetBranchAddress("electron_PromptLeptonInput_ip3", &electron_PromptLeptonInput_ip3, &b_electron_PromptLeptonInput_ip3);
   tree->SetBranchAddress("electron_PromptLeptonInput_rnnip", &electron_PromptLeptonInput_rnnip, &b_electron_PromptLeptonInput_rnnip);
   tree->SetBranchAddress("electron_PromptLeptonIso_TagWeight", &electron_PromptLeptonIso_TagWeight, &b_electron_PromptLeptonIso_TagWeight);
   tree->SetBranchAddress("electron_PromptLeptonVeto_TagWeight", &electron_PromptLeptonVeto_TagWeight, &b_electron_PromptLeptonVeto_TagWeight);
   tree->SetBranchAddress("electron_ambiguityType", &electron_ambiguityType, &b_electron_ambiguityType);
   tree->SetBranchAddress("electron_numberOfInnermostPixelLayerHits", &electron_numberOfInnermostPixelLayerHits, &b_electron_numberOfInnermostPixelLayerHits);
   tree->SetBranchAddress("electron_numberOfInnermostPixelLayerOutliers", &electron_numberOfInnermostPixelLayerOutliers, &b_electron_numberOfInnermostPixelLayerOutliers);
   tree->SetBranchAddress("electron_expectInnerPixelLayerHit", &electron_expectInnerPixelLayerHit, &b_electron_expectInnerPixelLayerHit);
   tree->SetBranchAddress("muon_pt", &muon_pt, &b_muon_pt);
   tree->SetBranchAddress("muon_eta", &muon_eta, &b_muon_eta);
   tree->SetBranchAddress("muon_phi", &muon_phi, &b_muon_phi);
   tree->SetBranchAddress("muon_E", &muon_E, &b_muon_E);
   tree->SetBranchAddress("muon_isLoose", &muon_isLoose, &b_muon_isLoose);
   tree->SetBranchAddress("muon_isMedium", &muon_isMedium, &b_muon_isMedium);
   tree->SetBranchAddress("muon_isTight", &muon_isTight, &b_muon_isTight);
   tree->SetBranchAddress("muon_ID", &muon_ID, &b_muon_ID);
   tree->SetBranchAddress("muon_sigd0PV", &muon_sigd0PV, &b_muon_sigd0PV);
   tree->SetBranchAddress("muon_z0SinTheta", &muon_z0SinTheta, &b_muon_z0SinTheta);
   tree->SetBranchAddress("muon_momBalSignif", &muon_momBalSignif, &b_muon_momBalSignif);
   tree->SetBranchAddress("muon_scatCurvSignif", &muon_scatCurvSignif, &b_muon_scatCurvSignif);
   tree->SetBranchAddress("muon_scatNeighSignif", &muon_scatNeighSignif, &b_muon_scatNeighSignif);
   tree->SetBranchAddress("muon_rho", &muon_rho, &b_muon_rho);
   tree->SetBranchAddress("muon_qOverPsigma", &muon_qOverPsigma, &b_muon_qOverPsigma);
   tree->SetBranchAddress("muon_qOverPsignif", &muon_qOverPsignif, &b_muon_qOverPsignif);
   tree->SetBranchAddress("muon_reducedChi2", &muon_reducedChi2, &b_muon_reducedChi2);
   tree->SetBranchAddress("muon_numPrecLayers", &muon_numPrecLayers, &b_muon_numPrecLayers);
   tree->SetBranchAddress("muon_topoetcone20", &muon_topoetcone20, &b_muon_topoetcone20);
   tree->SetBranchAddress("muon_topoetcone30", &muon_topoetcone30, &b_muon_topoetcone30);
   tree->SetBranchAddress("muon_topoetcone40", &muon_topoetcone40, &b_muon_topoetcone40);
   tree->SetBranchAddress("muon_ptvarcone20", &muon_ptvarcone20, &b_muon_ptvarcone20);
   tree->SetBranchAddress("muon_ptvarcone30", &muon_ptvarcone30, &b_muon_ptvarcone30);
   tree->SetBranchAddress("muon_ptvarcone40", &muon_ptvarcone40, &b_muon_ptvarcone40);
   tree->SetBranchAddress("muon_sharesTrk", &muon_sharesTrk, &b_muon_sharesTrk);
   tree->SetBranchAddress("muon_passOR", &muon_passOR, &b_muon_passOR);
   tree->SetBranchAddress("muon_isQMisID", &muon_isQMisID, &b_muon_isQMisID);
   tree->SetBranchAddress("muon_match_HLT_2mu10", &muon_match_HLT_2mu10, &b_muon_match_HLT_2mu10);
   tree->SetBranchAddress("muon_match_HLT_2mu14", &muon_match_HLT_2mu14, &b_muon_match_HLT_2mu14);
   tree->SetBranchAddress("muon_match_HLT_e17_lhloose_mu14", &muon_match_HLT_e17_lhloose_mu14, &b_muon_match_HLT_e17_lhloose_mu14);
   tree->SetBranchAddress("muon_match_HLT_e17_lhloose_nod0_mu14", &muon_match_HLT_e17_lhloose_nod0_mu14, &b_muon_match_HLT_e17_lhloose_nod0_mu14);
   tree->SetBranchAddress("muon_match_HLT_e17_loose_mu14", &muon_match_HLT_e17_loose_mu14, &b_muon_match_HLT_e17_loose_mu14);
   tree->SetBranchAddress("muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1", &muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1, &b_muon_match_HLT_e24_lhmedium_nod0_L1EM20VHI_mu8noL1);
   tree->SetBranchAddress("muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1", &muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1, &b_muon_match_HLT_e24_medium_L1EM20VHI_mu8noL1);
   tree->SetBranchAddress("muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1", &muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1, &b_muon_match_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1);
   tree->SetBranchAddress("muon_match_HLT_e7_lhmedium_mu24", &muon_match_HLT_e7_lhmedium_mu24, &b_muon_match_HLT_e7_lhmedium_mu24);
   tree->SetBranchAddress("muon_match_HLT_e7_lhmedium_nod0_mu24", &muon_match_HLT_e7_lhmedium_nod0_mu24, &b_muon_match_HLT_e7_lhmedium_nod0_mu24);
   tree->SetBranchAddress("muon_match_HLT_e7_medium_mu24", &muon_match_HLT_e7_medium_mu24, &b_muon_match_HLT_e7_medium_mu24);
   tree->SetBranchAddress("muon_match_HLT_mu10", &muon_match_HLT_mu10, &b_muon_match_HLT_mu10);
   tree->SetBranchAddress("muon_match_HLT_mu14", &muon_match_HLT_mu14, &b_muon_match_HLT_mu14);
   tree->SetBranchAddress("muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo", &muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo, &b_muon_match_HLT_mu14_ivarloose_tau25_medium1_tracktwo);
   tree->SetBranchAddress("muon_match_HLT_mu14_tau25_medium1_tracktwo", &muon_match_HLT_mu14_tau25_medium1_tracktwo, &b_muon_match_HLT_mu14_tau25_medium1_tracktwo);
   tree->SetBranchAddress("muon_match_HLT_mu18", &muon_match_HLT_mu18, &b_muon_match_HLT_mu18);
   tree->SetBranchAddress("muon_match_HLT_mu18_mu8noL1", &muon_match_HLT_mu18_mu8noL1, &b_muon_match_HLT_mu18_mu8noL1);
   tree->SetBranchAddress("muon_match_HLT_mu20_iloose_L1MU15", &muon_match_HLT_mu20_iloose_L1MU15, &b_muon_match_HLT_mu20_iloose_L1MU15);
   tree->SetBranchAddress("muon_match_HLT_mu20_mu8noL1", &muon_match_HLT_mu20_mu8noL1, &b_muon_match_HLT_mu20_mu8noL1);
   tree->SetBranchAddress("muon_match_HLT_mu22_mu8noL1", &muon_match_HLT_mu22_mu8noL1, &b_muon_match_HLT_mu22_mu8noL1);
   tree->SetBranchAddress("muon_match_HLT_mu24", &muon_match_HLT_mu24, &b_muon_match_HLT_mu24);
   tree->SetBranchAddress("muon_match_HLT_mu24_iloose", &muon_match_HLT_mu24_iloose, &b_muon_match_HLT_mu24_iloose);
   tree->SetBranchAddress("muon_match_HLT_mu24_imedium", &muon_match_HLT_mu24_imedium, &b_muon_match_HLT_mu24_imedium);
   tree->SetBranchAddress("muon_match_HLT_mu24_ivarloose", &muon_match_HLT_mu24_ivarloose, &b_muon_match_HLT_mu24_ivarloose);
   tree->SetBranchAddress("muon_match_HLT_mu24_ivarmedium", &muon_match_HLT_mu24_ivarmedium, &b_muon_match_HLT_mu24_ivarmedium);
   tree->SetBranchAddress("muon_match_HLT_mu26_imedium", &muon_match_HLT_mu26_imedium, &b_muon_match_HLT_mu26_imedium);
   tree->SetBranchAddress("muon_match_HLT_mu26_ivarmedium", &muon_match_HLT_mu26_ivarmedium, &b_muon_match_HLT_mu26_ivarmedium);
   tree->SetBranchAddress("muon_match_HLT_mu40", &muon_match_HLT_mu40, &b_muon_match_HLT_mu40);
   tree->SetBranchAddress("muon_match_HLT_mu50", &muon_match_HLT_mu50, &b_muon_match_HLT_mu50);
   tree->SetBranchAddress("muon_d0", &muon_d0, &b_muon_d0);
   tree->SetBranchAddress("muon_z0", &muon_z0, &b_muon_z0);
   tree->SetBranchAddress("muon_vz", &muon_vz, &b_muon_vz);
   tree->SetBranchAddress("muon_deltaz0", &muon_deltaz0, &b_muon_deltaz0);
   tree->SetBranchAddress("muon_author", &muon_author, &b_muon_author);
   tree->SetBranchAddress("muon_type", &muon_type, &b_muon_type);
   tree->SetBranchAddress("muon_truthType", &muon_truthType, &b_muon_truthType);
   tree->SetBranchAddress("muon_truthOrigin", &muon_truthOrigin, &b_muon_truthOrigin);
   tree->SetBranchAddress("muon_trackType", &muon_trackType, &b_muon_trackType);
   tree->SetBranchAddress("muon_trackOrigin", &muon_trackOrigin, &b_muon_trackOrigin);
   tree->SetBranchAddress("muon_jetFitterComb", &muon_jetFitterComb, &b_muon_jetFitterComb);
   tree->SetBranchAddress("muon_PromptLeptonInput_sv1_jf_ntrkv", &muon_PromptLeptonInput_sv1_jf_ntrkv, &b_muon_PromptLeptonInput_sv1_jf_ntrkv);
   tree->SetBranchAddress("muon_PromptLeptonInput_TrackJetNTrack", &muon_PromptLeptonInput_TrackJetNTrack, &b_muon_PromptLeptonInput_TrackJetNTrack);
   tree->SetBranchAddress("muon_PromptLeptonInput_DL1mu", &muon_PromptLeptonInput_DL1mu, &b_muon_PromptLeptonInput_DL1mu);
   tree->SetBranchAddress("muon_PromptLeptonInput_DRlj", &muon_PromptLeptonInput_DRlj, &b_muon_PromptLeptonInput_DRlj);
   tree->SetBranchAddress("muon_PromptLeptonInput_LepJetPtFrac", &muon_PromptLeptonInput_LepJetPtFrac, &b_muon_PromptLeptonInput_LepJetPtFrac);
   tree->SetBranchAddress("muon_PromptLeptonInput_PtFrac", &muon_PromptLeptonInput_PtFrac, &b_muon_PromptLeptonInput_PtFrac);
   tree->SetBranchAddress("muon_PromptLeptonInput_PtRel", &muon_PromptLeptonInput_PtRel, &b_muon_PromptLeptonInput_PtRel);
   tree->SetBranchAddress("muon_PromptLeptonInput_ip2", &muon_PromptLeptonInput_ip2, &b_muon_PromptLeptonInput_ip2);
   tree->SetBranchAddress("muon_PromptLeptonInput_ip3", &muon_PromptLeptonInput_ip3, &b_muon_PromptLeptonInput_ip3);
   tree->SetBranchAddress("muon_PromptLeptonInput_rnnip", &muon_PromptLeptonInput_rnnip, &b_muon_PromptLeptonInput_rnnip);
   tree->SetBranchAddress("muon_PromptLeptonIso_TagWeight", &muon_PromptLeptonIso_TagWeight, &b_muon_PromptLeptonIso_TagWeight);
   tree->SetBranchAddress("muon_PromptLeptonVeto_TagWeight", &muon_PromptLeptonVeto_TagWeight, &b_muon_PromptLeptonVeto_TagWeight);
   tree->SetBranchAddress("muon_jet_pt", &muon_jet_pt, &b_muon_jet_pt);
   tree->SetBranchAddress("muon_jet_eta", &muon_jet_eta, &b_muon_jet_eta);
   tree->SetBranchAddress("muon_jet_phi", &muon_jet_phi, &b_muon_jet_phi);
   tree->SetBranchAddress("muon_jet_dr", &muon_jet_dr, &b_muon_jet_dr);
   tree->SetBranchAddress("muon_jet_ptRel", &muon_jet_ptRel, &b_muon_jet_ptRel);
   tree->SetBranchAddress("muon_jet_numTrk", &muon_jet_numTrk, &b_muon_jet_numTrk);
   tree->SetBranchAddress("muon_jet_sumPtTrk", &muon_jet_sumPtTrk, &b_muon_jet_sumPtTrk);
   tree->SetBranchAddress("muon_jet_MV2c10_Weight", &muon_jet_MV2c10_Weight, &b_muon_jet_MV2c10_Weight);
   tree->SetBranchAddress("muon_jet_tagWeightBin", &muon_jet_tagWeightBin, &b_muon_jet_tagWeightBin);
   tree->SetBranchAddress("muon_jet_BDT", &muon_jet_BDT, &b_muon_jet_BDT);
   tree->SetBranchAddress("m_jet_pt", &m_jet_pt, &b_m_jet_pt);
   tree->SetBranchAddress("m_jet_eta", &m_jet_eta, &b_m_jet_eta);
   tree->SetBranchAddress("m_jet_phi", &m_jet_phi, &b_m_jet_phi);
   tree->SetBranchAddress("m_jet_E", &m_jet_E, &b_m_jet_E);
   tree->SetBranchAddress("m_jet_etaEM", &m_jet_etaEM, &b_m_jet_etaEM);
   tree->SetBranchAddress("m_jet_jvt", &m_jet_jvt, &b_m_jet_jvt);
   tree->SetBranchAddress("m_jet_passjvt", &m_jet_passjvt, &b_m_jet_passjvt);
   tree->SetBranchAddress("m_jet_isLooseBad", &m_jet_isLooseBad, &b_m_jet_isLooseBad);
   tree->SetBranchAddress("m_jet_flavor_weight_MV2c10", &m_jet_flavor_weight_MV2c10, &b_m_jet_flavor_weight_MV2c10);
   tree->SetBranchAddress("m_jet_numTrk", &m_jet_numTrk, &b_m_jet_numTrk);
   tree->SetBranchAddress("m_jet_passOR", &m_jet_passOR, &b_m_jet_passOR);
   tree->SetBranchAddress("m_jet_passTauOR", &m_jet_passTauOR, &b_m_jet_passTauOR);
   tree->SetBranchAddress("m_jet_flavor_weight_MV2c00", &m_jet_flavor_weight_MV2c00, &b_m_jet_flavor_weight_MV2c00);
   tree->SetBranchAddress("m_jet_flavor_weight_MV2c20", &m_jet_flavor_weight_MV2c20, &b_m_jet_flavor_weight_MV2c20);
   tree->SetBranchAddress("m_jet_sumPtTrk", &m_jet_sumPtTrk, &b_m_jet_sumPtTrk);
   tree->SetBranchAddress("m_jet_emfrac", &m_jet_emfrac, &b_m_jet_emfrac);
   tree->SetBranchAddress("m_jet_flavor_truth_label", &m_jet_flavor_truth_label, &b_m_jet_flavor_truth_label);
   tree->SetBranchAddress("m_jet_flavor_truth_label_ghost", &m_jet_flavor_truth_label_ghost, &b_m_jet_flavor_truth_label_ghost);
   tree->SetBranchAddress("m_tau_pt", &m_tau_pt, &b_m_tau_pt);
   tree->SetBranchAddress("m_tau_eta", &m_tau_eta, &b_m_tau_eta);
   tree->SetBranchAddress("m_tau_phi", &m_tau_phi, &b_m_tau_phi);
   tree->SetBranchAddress("m_tau_E", &m_tau_E, &b_m_tau_E);
   tree->SetBranchAddress("m_tau_charge", &m_tau_charge, &b_m_tau_charge);
   tree->SetBranchAddress("m_tau_numTrack", &m_tau_numTrack, &b_m_tau_numTrack);
   tree->SetBranchAddress("m_tau_BDTJetScore", &m_tau_BDTJetScore, &b_m_tau_BDTJetScore);
   tree->SetBranchAddress("m_tau_BDTJetScoreSigTrans", &m_tau_BDTJetScoreSigTrans, &b_m_tau_BDTJetScoreSigTrans);
   tree->SetBranchAddress("m_tau_JetBDTSigLoose", &m_tau_JetBDTSigLoose, &b_m_tau_JetBDTSigLoose);
   tree->SetBranchAddress("m_tau_JetBDTSigMedium", &m_tau_JetBDTSigMedium, &b_m_tau_JetBDTSigMedium);
   tree->SetBranchAddress("m_tau_JetBDTSigTight", &m_tau_JetBDTSigTight, &b_m_tau_JetBDTSigTight);
   tree->SetBranchAddress("m_tau_MVATESQuality", &m_tau_MVATESQuality, &b_m_tau_MVATESQuality);
   tree->SetBranchAddress("m_tau_passOR", &m_tau_passOR, &b_m_tau_passOR);
   tree->SetBranchAddress("m_tau_passEleOLR", &m_tau_passEleOLR, &b_m_tau_passEleOLR);
   tree->SetBranchAddress("m_tau_passEleBDT", &m_tau_passEleBDT, &b_m_tau_passEleBDT);
   tree->SetBranchAddress("m_tau_passMuonOLR", &m_tau_passMuonOLR, &b_m_tau_passMuonOLR);
   tree->SetBranchAddress("m_tau_isHadronicTau", &m_tau_isHadronicTau, &b_m_tau_isHadronicTau);
   tree->SetBranchAddress("m_tau_MV2c10", &m_tau_MV2c10, &b_m_tau_MV2c10);
   tree->SetBranchAddress("m_tau_tagWeightBin", &m_tau_tagWeightBin, &b_m_tau_tagWeightBin);
   tree->SetBranchAddress("m_tau_passJVT", &m_tau_passJVT, &b_m_tau_passJVT);
   tree->SetBranchAddress("m_tau_fromPV", &m_tau_fromPV, &b_m_tau_fromPV);
   tree->SetBranchAddress("m_tau_BDTEleScoreSigTrans", &m_tau_BDTEleScoreSigTrans, &b_m_tau_BDTEleScoreSigTrans);
   tree->SetBranchAddress("m_tau_ptTauEtaCalib", &m_tau_ptTauEtaCalib, &b_m_tau_ptTauEtaCalib);
   tree->SetBranchAddress("m_tau_etaTauEtaCalib", &m_tau_etaTauEtaCalib, &b_m_tau_etaTauEtaCalib);
   tree->SetBranchAddress("m_tau_phiTauEtaCalib", &m_tau_phiTauEtaCalib, &b_m_tau_phiTauEtaCalib);
   tree->SetBranchAddress("m_tau_mTauEtaCalib", &m_tau_mTauEtaCalib, &b_m_tau_mTauEtaCalib);
   tree->SetBranchAddress("m_tau_isTruthMatched", &m_tau_isTruthMatched, &b_m_tau_isTruthMatched);
   tree->SetBranchAddress("m_tau_truthOrigin", &m_tau_truthOrigin, &b_m_tau_truthOrigin);
   tree->SetBranchAddress("m_tau_truthType", &m_tau_truthType, &b_m_tau_truthType);
   tree->SetBranchAddress("m_tau_truthJetFlavour", &m_tau_truthJetFlavour, &b_m_tau_truthJetFlavour);
   tree->SetBranchAddress("m_tau_ele_match_lhscore", &m_tau_ele_match_lhscore, &b_m_tau_ele_match_lhscore);
   tree->SetBranchAddress("m_tau_PromptTauInput_TrackJetNTrack", &m_tau_PromptTauInput_TrackJetNTrack, &b_m_tau_PromptTauInput_TrackJetNTrack);
   tree->SetBranchAddress("m_tau_PromptTauInput_DRlj", &m_tau_PromptTauInput_DRlj, &b_m_tau_PromptTauInput_DRlj);
   tree->SetBranchAddress("m_tau_PromptTauInput_JetF", &m_tau_PromptTauInput_JetF, &b_m_tau_PromptTauInput_JetF);
   tree->SetBranchAddress("m_tau_PromptTauInput_LepJetPtFrac", &m_tau_PromptTauInput_LepJetPtFrac, &b_m_tau_PromptTauInput_LepJetPtFrac);
   tree->SetBranchAddress("m_tau_PromptTauInput_MV2c10rnn", &m_tau_PromptTauInput_MV2c10rnn, &b_m_tau_PromptTauInput_MV2c10rnn);
   tree->SetBranchAddress("m_tau_PromptTauInput_SV1", &m_tau_PromptTauInput_SV1, &b_m_tau_PromptTauInput_SV1);
   tree->SetBranchAddress("m_tau_PromptTauInput_ip2", &m_tau_PromptTauInput_ip2, &b_m_tau_PromptTauInput_ip2);
   tree->SetBranchAddress("m_tau_PromptTauInput_ip3", &m_tau_PromptTauInput_ip3, &b_m_tau_PromptTauInput_ip3);
   tree->SetBranchAddress("m_tau_PromptTauInput_rnnip", &m_tau_PromptTauInput_rnnip, &b_m_tau_PromptTauInput_rnnip);
   tree->SetBranchAddress("m_tau_PromptTauInput_MV2c10", &m_tau_PromptTauInput_MV2c10, &b_m_tau_PromptTauInput_MV2c10);
   tree->SetBranchAddress("m_tau_PromptTauVeto", &m_tau_PromptTauVeto, &b_m_tau_PromptTauVeto);
   tree->SetBranchAddress("m_tau_PromptTauIso", &m_tau_PromptTauIso, &b_m_tau_PromptTauIso);
   tree->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   tree->SetBranchAddress("lep_Index_0", &lep_Index_0, &b_lep_Index_0);
   tree->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   tree->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   tree->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   tree->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   tree->SetBranchAddress("lep_EtaBE2_0", &lep_EtaBE2_0, &b_lep_EtaBE2_0);
   tree->SetBranchAddress("lep_topoEtcone20_0", &lep_topoEtcone20_0, &b_lep_topoEtcone20_0);
   tree->SetBranchAddress("lep_topoEtcone30_0", &lep_topoEtcone30_0, &b_lep_topoEtcone30_0);
   tree->SetBranchAddress("lep_topoEtcone40_0", &lep_topoEtcone40_0, &b_lep_topoEtcone40_0);
   tree->SetBranchAddress("lep_ptVarcone20_0", &lep_ptVarcone20_0, &b_lep_ptVarcone20_0);
   tree->SetBranchAddress("lep_ptVarcone30_0", &lep_ptVarcone30_0, &b_lep_ptVarcone30_0);
   tree->SetBranchAddress("lep_ptVarcone40_0", &lep_ptVarcone40_0, &b_lep_ptVarcone40_0);
   tree->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   tree->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   tree->SetBranchAddress("lep_d0_0", &lep_d0_0, &b_lep_d0_0);
   tree->SetBranchAddress("lep_z0_0", &lep_z0_0, &b_lep_z0_0);
   tree->SetBranchAddress("lep_vz_0", &lep_vz_0, &b_lep_vz_0);
   tree->SetBranchAddress("lep_deltaz0_0", &lep_deltaz0_0, &b_lep_deltaz0_0);
   tree->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   tree->SetBranchAddress("lep_isMediumLH_0", &lep_isMediumLH_0, &b_lep_isMediumLH_0);
   tree->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   tree->SetBranchAddress("lep_isTight_0", &lep_isTight_0, &b_lep_isTight_0);
   tree->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   tree->SetBranchAddress("lep_isLoose_0", &lep_isLoose_0, &b_lep_isLoose_0);
   tree->SetBranchAddress("lep_isolationLooseTrackOnly_0", &lep_isolationLooseTrackOnly_0, &b_lep_isolationLooseTrackOnly_0);
   tree->SetBranchAddress("lep_isolationLoose_0", &lep_isolationLoose_0, &b_lep_isolationLoose_0);
   tree->SetBranchAddress("lep_isolationGradient_0", &lep_isolationGradient_0, &b_lep_isolationGradient_0);
   tree->SetBranchAddress("lep_isolationGradientLoose_0", &lep_isolationGradientLoose_0, &b_lep_isolationGradientLoose_0);
   tree->SetBranchAddress("lep_isolationFixedCutTight_0", &lep_isolationFixedCutTight_0, &b_lep_isolationFixedCutTight_0);
   tree->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_0", &lep_isolationFixedCutTightTrackOnly_0, &b_lep_isolationFixedCutTightTrackOnly_0);
   tree->SetBranchAddress("lep_isolationFixedCutLoose_0", &lep_isolationFixedCutLoose_0, &b_lep_isolationFixedCutLoose_0);
   tree->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   tree->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0, &b_lep_isTrigMatchDLT_0);
   tree->SetBranchAddress("lep_isPrompt_0", &lep_isPrompt_0, &b_lep_isPrompt_0);
   tree->SetBranchAddress("lep_isFakeLep_0", &lep_isFakeLep_0, &b_lep_isFakeLep_0);
   tree->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0, &b_lep_isQMisID_0);
   tree->SetBranchAddress("lep_isConvPh_0", &lep_isConvPh_0, &b_lep_isConvPh_0);
   tree->SetBranchAddress("lep_isExtConvPh_0", &lep_isExtConvPh_0, &b_lep_isExtConvPh_0);
   tree->SetBranchAddress("lep_isIntConvPh_0", &lep_isIntConvPh_0, &b_lep_isIntConvPh_0);
   tree->SetBranchAddress("lep_isISR_FSR_Ph_0", &lep_isISR_FSR_Ph_0, &b_lep_isISR_FSR_Ph_0);
   tree->SetBranchAddress("lep_isBrems_0", &lep_isBrems_0, &b_lep_isBrems_0);
   tree->SetBranchAddress("lep_chargeIDBDTLoose_0", &lep_chargeIDBDTLoose_0, &b_lep_chargeIDBDTLoose_0);
   tree->SetBranchAddress("lep_chargeIDBDTMedium_0", &lep_chargeIDBDTMedium_0, &b_lep_chargeIDBDTMedium_0);
   tree->SetBranchAddress("lep_chargeIDBDTTight_0", &lep_chargeIDBDTTight_0, &b_lep_chargeIDBDTTight_0);
   tree->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_0", &lep_promptLeptonInput_sv1_jf_ntrkv_0, &b_lep_promptLeptonInput_sv1_jf_ntrkv_0);
   tree->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_0", &lep_promptLeptonInput_TrackJetNTrack_0, &b_lep_promptLeptonInput_TrackJetNTrack_0);
   tree->SetBranchAddress("lep_promptLeptonInput_DL1mu_0", &lep_promptLeptonInput_DL1mu_0, &b_lep_promptLeptonInput_DL1mu_0);
   tree->SetBranchAddress("lep_promptLeptonInput_DRlj_0", &lep_promptLeptonInput_DRlj_0, &b_lep_promptLeptonInput_DRlj_0);
   tree->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_0", &lep_promptLeptonInput_LepJetPtFrac_0, &b_lep_promptLeptonInput_LepJetPtFrac_0);
   tree->SetBranchAddress("lep_promptLeptonInput_PtFrac_0", &lep_promptLeptonInput_PtFrac_0, &b_lep_promptLeptonInput_PtFrac_0);
   tree->SetBranchAddress("lep_promptLeptonInput_PtRel_0", &lep_promptLeptonInput_PtRel_0, &b_lep_promptLeptonInput_PtRel_0);
   tree->SetBranchAddress("lep_promptLeptonInput_ip2_0", &lep_promptLeptonInput_ip2_0, &b_lep_promptLeptonInput_ip2_0);
   tree->SetBranchAddress("lep_promptLeptonInput_ip3_0", &lep_promptLeptonInput_ip3_0, &b_lep_promptLeptonInput_ip3_0);
   tree->SetBranchAddress("lep_promptLeptonInput_rnnip_0", &lep_promptLeptonInput_rnnip_0, &b_lep_promptLeptonInput_rnnip_0);
   tree->SetBranchAddress("lep_promptLeptonIso_TagWeight_0", &lep_promptLeptonIso_TagWeight_0, &b_lep_promptLeptonIso_TagWeight_0);
   tree->SetBranchAddress("lep_promptLeptonVeto_TagWeight_0", &lep_promptLeptonVeto_TagWeight_0, &b_lep_promptLeptonVeto_TagWeight_0);
   tree->SetBranchAddress("lep_jet_Pt_0", &lep_jet_Pt_0, &b_lep_jet_Pt_0);
   tree->SetBranchAddress("lep_jet_nTrk_0", &lep_jet_nTrk_0, &b_lep_jet_nTrk_0);
   tree->SetBranchAddress("lep_jet_sumPtTrk_0", &lep_jet_sumPtTrk_0, &b_lep_jet_sumPtTrk_0);
   tree->SetBranchAddress("lep_jet_mv2c10_0", &lep_jet_mv2c10_0, &b_lep_jet_mv2c10_0);
   tree->SetBranchAddress("lep_jet_deltaR_0", &lep_jet_deltaR_0, &b_lep_jet_deltaR_0);
   tree->SetBranchAddress("lep_jet_ptRel_0", &lep_jet_ptRel_0, &b_lep_jet_ptRel_0);
   tree->SetBranchAddress("lep_jet_ptOverMuPt_0", &lep_jet_ptOverMuPt_0, &b_lep_jet_ptOverMuPt_0);
   tree->SetBranchAddress("lep_jet_BDT_0", &lep_jet_BDT_0, &b_lep_jet_BDT_0);
   tree->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   tree->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   tree->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   tree->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   tree->SetBranchAddress("lep_truthStatus_0", &lep_truthStatus_0, &b_lep_truthStatus_0);
   tree->SetBranchAddress("lep_truthParentType_0", &lep_truthParentType_0, &b_lep_truthParentType_0);
   tree->SetBranchAddress("lep_truthParentOrigin_0", &lep_truthParentOrigin_0, &b_lep_truthParentOrigin_0);
   tree->SetBranchAddress("lep_truthParentPdgId_0", &lep_truthParentPdgId_0, &b_lep_truthParentPdgId_0);
   tree->SetBranchAddress("lep_truthParentStatus_0", &lep_truthParentStatus_0, &b_lep_truthParentStatus_0);
   tree->SetBranchAddress("lep_truthPt_0", &lep_truthPt_0, &b_lep_truthPt_0);
   tree->SetBranchAddress("lep_truthEta_0", &lep_truthEta_0, &b_lep_truthEta_0);
   tree->SetBranchAddress("lep_truthPhi_0", &lep_truthPhi_0, &b_lep_truthPhi_0);
   tree->SetBranchAddress("lep_truthM_0", &lep_truthM_0, &b_lep_truthM_0);
   tree->SetBranchAddress("lep_truthE_0", &lep_truthE_0, &b_lep_truthE_0);
   tree->SetBranchAddress("lep_truthRapidity_0", &lep_truthRapidity_0, &b_lep_truthRapidity_0);
   tree->SetBranchAddress("lep_ambiguityType_0", &lep_ambiguityType_0, &b_lep_ambiguityType_0);
   tree->SetBranchAddress("lep_SFIDLoose_0", &lep_SFIDLoose_0, &b_lep_SFIDLoose_0);
   tree->SetBranchAddress("lep_SFIDTight_0", &lep_SFIDTight_0, &b_lep_SFIDTight_0);
   tree->SetBranchAddress("lep_SFTrigLoose_0", &lep_SFTrigLoose_0, &b_lep_SFTrigLoose_0);
   tree->SetBranchAddress("lep_SFTrigTight_0", &lep_SFTrigTight_0, &b_lep_SFTrigTight_0);
   tree->SetBranchAddress("lep_EffTrigLoose_0", &lep_EffTrigLoose_0, &b_lep_EffTrigLoose_0);
   tree->SetBranchAddress("lep_EffTrigTight_0", &lep_EffTrigTight_0, &b_lep_EffTrigTight_0);
   tree->SetBranchAddress("lep_SFIsoLoose_0", &lep_SFIsoLoose_0, &b_lep_SFIsoLoose_0);
   tree->SetBranchAddress("lep_SFIsoTight_0", &lep_SFIsoTight_0, &b_lep_SFIsoTight_0);
   tree->SetBranchAddress("lep_SFReco_0", &lep_SFReco_0, &b_lep_SFReco_0);
   tree->SetBranchAddress("lep_SFTTVA_0", &lep_SFTTVA_0, &b_lep_SFTTVA_0);
   tree->SetBranchAddress("lep_SFObjLoose_0", &lep_SFObjLoose_0, &b_lep_SFObjLoose_0);
   tree->SetBranchAddress("lep_SFObjTight_0", &lep_SFObjTight_0, &b_lep_SFObjTight_0);
   tree->SetBranchAddress("lep_nInnerPix_0", &lep_nInnerPix_0, &b_lep_nInnerPix_0);
   tree->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   tree->SetBranchAddress("lep_Index_1", &lep_Index_1, &b_lep_Index_1);
   tree->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   tree->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   tree->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   tree->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   tree->SetBranchAddress("lep_EtaBE2_1", &lep_EtaBE2_1, &b_lep_EtaBE2_1);
   tree->SetBranchAddress("lep_topoEtcone20_1", &lep_topoEtcone20_1, &b_lep_topoEtcone20_1);
   tree->SetBranchAddress("lep_topoEtcone30_1", &lep_topoEtcone30_1, &b_lep_topoEtcone30_1);
   tree->SetBranchAddress("lep_topoEtcone40_1", &lep_topoEtcone40_1, &b_lep_topoEtcone40_1);
   tree->SetBranchAddress("lep_ptVarcone20_1", &lep_ptVarcone20_1, &b_lep_ptVarcone20_1);
   tree->SetBranchAddress("lep_ptVarcone30_1", &lep_ptVarcone30_1, &b_lep_ptVarcone30_1);
   tree->SetBranchAddress("lep_ptVarcone40_1", &lep_ptVarcone40_1, &b_lep_ptVarcone40_1);
   tree->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   tree->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   tree->SetBranchAddress("lep_d0_1", &lep_d0_1, &b_lep_d0_1);
   tree->SetBranchAddress("lep_z0_1", &lep_z0_1, &b_lep_z0_1);
   tree->SetBranchAddress("lep_vz_1", &lep_vz_1, &b_lep_vz_1);
   tree->SetBranchAddress("lep_deltaz0_1", &lep_deltaz0_1, &b_lep_deltaz0_1);
   tree->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   tree->SetBranchAddress("lep_isMediumLH_1", &lep_isMediumLH_1, &b_lep_isMediumLH_1);
   tree->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   tree->SetBranchAddress("lep_isTight_1", &lep_isTight_1, &b_lep_isTight_1);
   tree->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   tree->SetBranchAddress("lep_isLoose_1", &lep_isLoose_1, &b_lep_isLoose_1);
   tree->SetBranchAddress("lep_isolationLooseTrackOnly_1", &lep_isolationLooseTrackOnly_1, &b_lep_isolationLooseTrackOnly_1);
   tree->SetBranchAddress("lep_isolationLoose_1", &lep_isolationLoose_1, &b_lep_isolationLoose_1);
   tree->SetBranchAddress("lep_isolationGradient_1", &lep_isolationGradient_1, &b_lep_isolationGradient_1);
   tree->SetBranchAddress("lep_isolationGradientLoose_1", &lep_isolationGradientLoose_1, &b_lep_isolationGradientLoose_1);
   tree->SetBranchAddress("lep_isolationFixedCutTight_1", &lep_isolationFixedCutTight_1, &b_lep_isolationFixedCutTight_1);
   tree->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_1", &lep_isolationFixedCutTightTrackOnly_1, &b_lep_isolationFixedCutTightTrackOnly_1);
   tree->SetBranchAddress("lep_isolationFixedCutLoose_1", &lep_isolationFixedCutLoose_1, &b_lep_isolationFixedCutLoose_1);
   tree->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   tree->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1, &b_lep_isTrigMatchDLT_1);
   tree->SetBranchAddress("lep_isPrompt_1", &lep_isPrompt_1, &b_lep_isPrompt_1);
   tree->SetBranchAddress("lep_isFakeLep_1", &lep_isFakeLep_1, &b_lep_isFakeLep_1);
   tree->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1, &b_lep_isQMisID_1);
   tree->SetBranchAddress("lep_isConvPh_1", &lep_isConvPh_1, &b_lep_isConvPh_1);
   tree->SetBranchAddress("lep_isExtConvPh_1", &lep_isExtConvPh_1, &b_lep_isExtConvPh_1);
   tree->SetBranchAddress("lep_isIntConvPh_1", &lep_isIntConvPh_1, &b_lep_isIntConvPh_1);
   tree->SetBranchAddress("lep_isISR_FSR_Ph_1", &lep_isISR_FSR_Ph_1, &b_lep_isISR_FSR_Ph_1);
   tree->SetBranchAddress("lep_isBrems_1", &lep_isBrems_1, &b_lep_isBrems_1);
   tree->SetBranchAddress("lep_chargeIDBDTLoose_1", &lep_chargeIDBDTLoose_1, &b_lep_chargeIDBDTLoose_1);
   tree->SetBranchAddress("lep_chargeIDBDTMedium_1", &lep_chargeIDBDTMedium_1, &b_lep_chargeIDBDTMedium_1);
   tree->SetBranchAddress("lep_chargeIDBDTTight_1", &lep_chargeIDBDTTight_1, &b_lep_chargeIDBDTTight_1);
   tree->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_1", &lep_promptLeptonInput_sv1_jf_ntrkv_1, &b_lep_promptLeptonInput_sv1_jf_ntrkv_1);
   tree->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_1", &lep_promptLeptonInput_TrackJetNTrack_1, &b_lep_promptLeptonInput_TrackJetNTrack_1);
   tree->SetBranchAddress("lep_promptLeptonInput_DL1mu_1", &lep_promptLeptonInput_DL1mu_1, &b_lep_promptLeptonInput_DL1mu_1);
   tree->SetBranchAddress("lep_promptLeptonInput_DRlj_1", &lep_promptLeptonInput_DRlj_1, &b_lep_promptLeptonInput_DRlj_1);
   tree->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_1", &lep_promptLeptonInput_LepJetPtFrac_1, &b_lep_promptLeptonInput_LepJetPtFrac_1);
   tree->SetBranchAddress("lep_promptLeptonInput_PtFrac_1", &lep_promptLeptonInput_PtFrac_1, &b_lep_promptLeptonInput_PtFrac_1);
   tree->SetBranchAddress("lep_promptLeptonInput_PtRel_1", &lep_promptLeptonInput_PtRel_1, &b_lep_promptLeptonInput_PtRel_1);
   tree->SetBranchAddress("lep_promptLeptonInput_ip2_1", &lep_promptLeptonInput_ip2_1, &b_lep_promptLeptonInput_ip2_1);
   tree->SetBranchAddress("lep_promptLeptonInput_ip3_1", &lep_promptLeptonInput_ip3_1, &b_lep_promptLeptonInput_ip3_1);
   tree->SetBranchAddress("lep_promptLeptonInput_rnnip_1", &lep_promptLeptonInput_rnnip_1, &b_lep_promptLeptonInput_rnnip_1);
   tree->SetBranchAddress("lep_promptLeptonIso_TagWeight_1", &lep_promptLeptonIso_TagWeight_1, &b_lep_promptLeptonIso_TagWeight_1);
   tree->SetBranchAddress("lep_promptLeptonVeto_TagWeight_1", &lep_promptLeptonVeto_TagWeight_1, &b_lep_promptLeptonVeto_TagWeight_1);
   tree->SetBranchAddress("lep_jet_Pt_1", &lep_jet_Pt_1, &b_lep_jet_Pt_1);
   tree->SetBranchAddress("lep_jet_nTrk_1", &lep_jet_nTrk_1, &b_lep_jet_nTrk_1);
   tree->SetBranchAddress("lep_jet_sumPtTrk_1", &lep_jet_sumPtTrk_1, &b_lep_jet_sumPtTrk_1);
   tree->SetBranchAddress("lep_jet_mv2c10_1", &lep_jet_mv2c10_1, &b_lep_jet_mv2c10_1);
   tree->SetBranchAddress("lep_jet_deltaR_1", &lep_jet_deltaR_1, &b_lep_jet_deltaR_1);
   tree->SetBranchAddress("lep_jet_ptRel_1", &lep_jet_ptRel_1, &b_lep_jet_ptRel_1);
   tree->SetBranchAddress("lep_jet_ptOverMuPt_1", &lep_jet_ptOverMuPt_1, &b_lep_jet_ptOverMuPt_1);
   tree->SetBranchAddress("lep_jet_BDT_1", &lep_jet_BDT_1, &b_lep_jet_BDT_1);
   tree->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   tree->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   tree->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   tree->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   tree->SetBranchAddress("lep_truthStatus_1", &lep_truthStatus_1, &b_lep_truthStatus_1);
   tree->SetBranchAddress("lep_truthParentType_1", &lep_truthParentType_1, &b_lep_truthParentType_1);
   tree->SetBranchAddress("lep_truthParentOrigin_1", &lep_truthParentOrigin_1, &b_lep_truthParentOrigin_1);
   tree->SetBranchAddress("lep_truthParentPdgId_1", &lep_truthParentPdgId_1, &b_lep_truthParentPdgId_1);
   tree->SetBranchAddress("lep_truthParentStatus_1", &lep_truthParentStatus_1, &b_lep_truthParentStatus_1);
   tree->SetBranchAddress("lep_truthPt_1", &lep_truthPt_1, &b_lep_truthPt_1);
   tree->SetBranchAddress("lep_truthEta_1", &lep_truthEta_1, &b_lep_truthEta_1);
   tree->SetBranchAddress("lep_truthPhi_1", &lep_truthPhi_1, &b_lep_truthPhi_1);
   tree->SetBranchAddress("lep_truthM_1", &lep_truthM_1, &b_lep_truthM_1);
   tree->SetBranchAddress("lep_truthE_1", &lep_truthE_1, &b_lep_truthE_1);
   tree->SetBranchAddress("lep_truthRapidity_1", &lep_truthRapidity_1, &b_lep_truthRapidity_1);
   tree->SetBranchAddress("lep_ambiguityType_1", &lep_ambiguityType_1, &b_lep_ambiguityType_1);
   tree->SetBranchAddress("lep_SFIDLoose_1", &lep_SFIDLoose_1, &b_lep_SFIDLoose_1);
   tree->SetBranchAddress("lep_SFIDTight_1", &lep_SFIDTight_1, &b_lep_SFIDTight_1);
   tree->SetBranchAddress("lep_SFTrigLoose_1", &lep_SFTrigLoose_1, &b_lep_SFTrigLoose_1);
   tree->SetBranchAddress("lep_SFTrigTight_1", &lep_SFTrigTight_1, &b_lep_SFTrigTight_1);
   tree->SetBranchAddress("lep_EffTrigLoose_1", &lep_EffTrigLoose_1, &b_lep_EffTrigLoose_1);
   tree->SetBranchAddress("lep_EffTrigTight_1", &lep_EffTrigTight_1, &b_lep_EffTrigTight_1);
   tree->SetBranchAddress("lep_SFIsoLoose_1", &lep_SFIsoLoose_1, &b_lep_SFIsoLoose_1);
   tree->SetBranchAddress("lep_SFIsoTight_1", &lep_SFIsoTight_1, &b_lep_SFIsoTight_1);
   tree->SetBranchAddress("lep_SFReco_1", &lep_SFReco_1, &b_lep_SFReco_1);
   tree->SetBranchAddress("lep_SFTTVA_1", &lep_SFTTVA_1, &b_lep_SFTTVA_1);
   tree->SetBranchAddress("lep_SFObjLoose_1", &lep_SFObjLoose_1, &b_lep_SFObjLoose_1);
   tree->SetBranchAddress("lep_SFObjTight_1", &lep_SFObjTight_1, &b_lep_SFObjTight_1);
   tree->SetBranchAddress("lep_nInnerPix_1", &lep_nInnerPix_1, &b_lep_nInnerPix_1);
   tree->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   tree->SetBranchAddress("lep_Index_2", &lep_Index_2, &b_lep_Index_2);
   tree->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   tree->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   tree->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   tree->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   tree->SetBranchAddress("lep_EtaBE2_2", &lep_EtaBE2_2, &b_lep_EtaBE2_2);
   tree->SetBranchAddress("lep_topoEtcone20_2", &lep_topoEtcone20_2, &b_lep_topoEtcone20_2);
   tree->SetBranchAddress("lep_topoEtcone30_2", &lep_topoEtcone30_2, &b_lep_topoEtcone30_2);
   tree->SetBranchAddress("lep_topoEtcone40_2", &lep_topoEtcone40_2, &b_lep_topoEtcone40_2);
   tree->SetBranchAddress("lep_ptVarcone20_2", &lep_ptVarcone20_2, &b_lep_ptVarcone20_2);
   tree->SetBranchAddress("lep_ptVarcone30_2", &lep_ptVarcone30_2, &b_lep_ptVarcone30_2);
   tree->SetBranchAddress("lep_ptVarcone40_2", &lep_ptVarcone40_2, &b_lep_ptVarcone40_2);
   tree->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   tree->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   tree->SetBranchAddress("lep_d0_2", &lep_d0_2, &b_lep_d0_2);
   tree->SetBranchAddress("lep_z0_2", &lep_z0_2, &b_lep_z0_2);
   tree->SetBranchAddress("lep_vz_2", &lep_vz_2, &b_lep_vz_2);
   tree->SetBranchAddress("lep_deltaz0_2", &lep_deltaz0_2, &b_lep_deltaz0_2);
   tree->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   tree->SetBranchAddress("lep_isMediumLH_2", &lep_isMediumLH_2, &b_lep_isMediumLH_2);
   tree->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   tree->SetBranchAddress("lep_isTight_2", &lep_isTight_2, &b_lep_isTight_2);
   tree->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   tree->SetBranchAddress("lep_isLoose_2", &lep_isLoose_2, &b_lep_isLoose_2);
   tree->SetBranchAddress("lep_isolationLooseTrackOnly_2", &lep_isolationLooseTrackOnly_2, &b_lep_isolationLooseTrackOnly_2);
   tree->SetBranchAddress("lep_isolationLoose_2", &lep_isolationLoose_2, &b_lep_isolationLoose_2);
   tree->SetBranchAddress("lep_isolationGradient_2", &lep_isolationGradient_2, &b_lep_isolationGradient_2);
   tree->SetBranchAddress("lep_isolationGradientLoose_2", &lep_isolationGradientLoose_2, &b_lep_isolationGradientLoose_2);
   tree->SetBranchAddress("lep_isolationFixedCutTight_2", &lep_isolationFixedCutTight_2, &b_lep_isolationFixedCutTight_2);
   tree->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_2", &lep_isolationFixedCutTightTrackOnly_2, &b_lep_isolationFixedCutTightTrackOnly_2);
   tree->SetBranchAddress("lep_isolationFixedCutLoose_2", &lep_isolationFixedCutLoose_2, &b_lep_isolationFixedCutLoose_2);
   tree->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   tree->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2, &b_lep_isTrigMatchDLT_2);
   tree->SetBranchAddress("lep_isPrompt_2", &lep_isPrompt_2, &b_lep_isPrompt_2);
   tree->SetBranchAddress("lep_isFakeLep_2", &lep_isFakeLep_2, &b_lep_isFakeLep_2);
   tree->SetBranchAddress("lep_isQMisID_2", &lep_isQMisID_2, &b_lep_isQMisID_2);
   tree->SetBranchAddress("lep_isConvPh_2", &lep_isConvPh_2, &b_lep_isConvPh_2);
   tree->SetBranchAddress("lep_isExtConvPh_2", &lep_isExtConvPh_2, &b_lep_isExtConvPh_2);
   tree->SetBranchAddress("lep_isIntConvPh_2", &lep_isIntConvPh_2, &b_lep_isIntConvPh_2);
   tree->SetBranchAddress("lep_isISR_FSR_Ph_2", &lep_isISR_FSR_Ph_2, &b_lep_isISR_FSR_Ph_2);
   tree->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   tree->SetBranchAddress("lep_chargeIDBDTLoose_2", &lep_chargeIDBDTLoose_2, &b_lep_chargeIDBDTLoose_2);
   tree->SetBranchAddress("lep_chargeIDBDTMedium_2", &lep_chargeIDBDTMedium_2, &b_lep_chargeIDBDTMedium_2);
   tree->SetBranchAddress("lep_chargeIDBDTTight_2", &lep_chargeIDBDTTight_2, &b_lep_chargeIDBDTTight_2);
   tree->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_2", &lep_promptLeptonInput_sv1_jf_ntrkv_2, &b_lep_promptLeptonInput_sv1_jf_ntrkv_2);
   tree->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_2", &lep_promptLeptonInput_TrackJetNTrack_2, &b_lep_promptLeptonInput_TrackJetNTrack_2);
   tree->SetBranchAddress("lep_promptLeptonInput_DL1mu_2", &lep_promptLeptonInput_DL1mu_2, &b_lep_promptLeptonInput_DL1mu_2);
   tree->SetBranchAddress("lep_promptLeptonInput_DRlj_2", &lep_promptLeptonInput_DRlj_2, &b_lep_promptLeptonInput_DRlj_2);
   tree->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_2", &lep_promptLeptonInput_LepJetPtFrac_2, &b_lep_promptLeptonInput_LepJetPtFrac_2);
   tree->SetBranchAddress("lep_promptLeptonInput_PtFrac_2", &lep_promptLeptonInput_PtFrac_2, &b_lep_promptLeptonInput_PtFrac_2);
   tree->SetBranchAddress("lep_promptLeptonInput_PtRel_2", &lep_promptLeptonInput_PtRel_2, &b_lep_promptLeptonInput_PtRel_2);
   tree->SetBranchAddress("lep_promptLeptonInput_ip2_2", &lep_promptLeptonInput_ip2_2, &b_lep_promptLeptonInput_ip2_2);
   tree->SetBranchAddress("lep_promptLeptonInput_ip3_2", &lep_promptLeptonInput_ip3_2, &b_lep_promptLeptonInput_ip3_2);
   tree->SetBranchAddress("lep_promptLeptonInput_rnnip_2", &lep_promptLeptonInput_rnnip_2, &b_lep_promptLeptonInput_rnnip_2);
   tree->SetBranchAddress("lep_promptLeptonIso_TagWeight_2", &lep_promptLeptonIso_TagWeight_2, &b_lep_promptLeptonIso_TagWeight_2);
   tree->SetBranchAddress("lep_promptLeptonVeto_TagWeight_2", &lep_promptLeptonVeto_TagWeight_2, &b_lep_promptLeptonVeto_TagWeight_2);
   tree->SetBranchAddress("lep_jet_Pt_2", &lep_jet_Pt_2, &b_lep_jet_Pt_2);
   tree->SetBranchAddress("lep_jet_nTrk_2", &lep_jet_nTrk_2, &b_lep_jet_nTrk_2);
   tree->SetBranchAddress("lep_jet_sumPtTrk_2", &lep_jet_sumPtTrk_2, &b_lep_jet_sumPtTrk_2);
   tree->SetBranchAddress("lep_jet_mv2c10_2", &lep_jet_mv2c10_2, &b_lep_jet_mv2c10_2);
   tree->SetBranchAddress("lep_jet_deltaR_2", &lep_jet_deltaR_2, &b_lep_jet_deltaR_2);
   tree->SetBranchAddress("lep_jet_ptRel_2", &lep_jet_ptRel_2, &b_lep_jet_ptRel_2);
   tree->SetBranchAddress("lep_jet_ptOverMuPt_2", &lep_jet_ptOverMuPt_2, &b_lep_jet_ptOverMuPt_2);
   tree->SetBranchAddress("lep_jet_BDT_2", &lep_jet_BDT_2, &b_lep_jet_BDT_2);
   tree->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   tree->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   tree->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   tree->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   tree->SetBranchAddress("lep_truthStatus_2", &lep_truthStatus_2, &b_lep_truthStatus_2);
   tree->SetBranchAddress("lep_truthParentType_2", &lep_truthParentType_2, &b_lep_truthParentType_2);
   tree->SetBranchAddress("lep_truthParentOrigin_2", &lep_truthParentOrigin_2, &b_lep_truthParentOrigin_2);
   tree->SetBranchAddress("lep_truthParentPdgId_2", &lep_truthParentPdgId_2, &b_lep_truthParentPdgId_2);
   tree->SetBranchAddress("lep_truthParentStatus_2", &lep_truthParentStatus_2, &b_lep_truthParentStatus_2);
   tree->SetBranchAddress("lep_truthPt_2", &lep_truthPt_2, &b_lep_truthPt_2);
   tree->SetBranchAddress("lep_truthEta_2", &lep_truthEta_2, &b_lep_truthEta_2);
   tree->SetBranchAddress("lep_truthPhi_2", &lep_truthPhi_2, &b_lep_truthPhi_2);
   tree->SetBranchAddress("lep_truthM_2", &lep_truthM_2, &b_lep_truthM_2);
   tree->SetBranchAddress("lep_truthE_2", &lep_truthE_2, &b_lep_truthE_2);
   tree->SetBranchAddress("lep_truthRapidity_2", &lep_truthRapidity_2, &b_lep_truthRapidity_2);
   tree->SetBranchAddress("lep_ambiguityType_2", &lep_ambiguityType_2, &b_lep_ambiguityType_2);
   tree->SetBranchAddress("lep_SFIDLoose_2", &lep_SFIDLoose_2, &b_lep_SFIDLoose_2);
   tree->SetBranchAddress("lep_SFIDTight_2", &lep_SFIDTight_2, &b_lep_SFIDTight_2);
   tree->SetBranchAddress("lep_SFTrigLoose_2", &lep_SFTrigLoose_2, &b_lep_SFTrigLoose_2);
   tree->SetBranchAddress("lep_SFTrigTight_2", &lep_SFTrigTight_2, &b_lep_SFTrigTight_2);
   tree->SetBranchAddress("lep_EffTrigLoose_2", &lep_EffTrigLoose_2, &b_lep_EffTrigLoose_2);
   tree->SetBranchAddress("lep_EffTrigTight_2", &lep_EffTrigTight_2, &b_lep_EffTrigTight_2);
   tree->SetBranchAddress("lep_SFIsoLoose_2", &lep_SFIsoLoose_2, &b_lep_SFIsoLoose_2);
   tree->SetBranchAddress("lep_SFIsoTight_2", &lep_SFIsoTight_2, &b_lep_SFIsoTight_2);
   tree->SetBranchAddress("lep_SFReco_2", &lep_SFReco_2, &b_lep_SFReco_2);
   tree->SetBranchAddress("lep_SFTTVA_2", &lep_SFTTVA_2, &b_lep_SFTTVA_2);
   tree->SetBranchAddress("lep_SFObjLoose_2", &lep_SFObjLoose_2, &b_lep_SFObjLoose_2);
   tree->SetBranchAddress("lep_SFObjTight_2", &lep_SFObjTight_2, &b_lep_SFObjTight_2);
   tree->SetBranchAddress("lep_nInnerPix_2", &lep_nInnerPix_2, &b_lep_nInnerPix_2);
   tree->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   tree->SetBranchAddress("lep_Index_3", &lep_Index_3, &b_lep_Index_3);
   tree->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   tree->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   tree->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   tree->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   tree->SetBranchAddress("lep_EtaBE2_3", &lep_EtaBE2_3, &b_lep_EtaBE2_3);
   tree->SetBranchAddress("lep_topoEtcone20_3", &lep_topoEtcone20_3, &b_lep_topoEtcone20_3);
   tree->SetBranchAddress("lep_topoEtcone30_3", &lep_topoEtcone30_3, &b_lep_topoEtcone30_3);
   tree->SetBranchAddress("lep_topoEtcone40_3", &lep_topoEtcone40_3, &b_lep_topoEtcone40_3);
   tree->SetBranchAddress("lep_ptVarcone20_3", &lep_ptVarcone20_3, &b_lep_ptVarcone20_3);
   tree->SetBranchAddress("lep_ptVarcone30_3", &lep_ptVarcone30_3, &b_lep_ptVarcone30_3);
   tree->SetBranchAddress("lep_ptVarcone40_3", &lep_ptVarcone40_3, &b_lep_ptVarcone40_3);
   tree->SetBranchAddress("lep_sigd0PV_3", &lep_sigd0PV_3, &b_lep_sigd0PV_3);
   tree->SetBranchAddress("lep_Z0SinTheta_3", &lep_Z0SinTheta_3, &b_lep_Z0SinTheta_3);
   tree->SetBranchAddress("lep_d0_3", &lep_d0_3, &b_lep_d0_3);
   tree->SetBranchAddress("lep_z0_3", &lep_z0_3, &b_lep_z0_3);
   tree->SetBranchAddress("lep_vz_3", &lep_vz_3, &b_lep_vz_3);
   tree->SetBranchAddress("lep_deltaz0_3", &lep_deltaz0_3, &b_lep_deltaz0_3);
   tree->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   tree->SetBranchAddress("lep_isMediumLH_3", &lep_isMediumLH_3, &b_lep_isMediumLH_3);
   tree->SetBranchAddress("lep_isLooseLH_3", &lep_isLooseLH_3, &b_lep_isLooseLH_3);
   tree->SetBranchAddress("lep_isTight_3", &lep_isTight_3, &b_lep_isTight_3);
   tree->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   tree->SetBranchAddress("lep_isLoose_3", &lep_isLoose_3, &b_lep_isLoose_3);
   tree->SetBranchAddress("lep_isolationLooseTrackOnly_3", &lep_isolationLooseTrackOnly_3, &b_lep_isolationLooseTrackOnly_3);
   tree->SetBranchAddress("lep_isolationLoose_3", &lep_isolationLoose_3, &b_lep_isolationLoose_3);
   tree->SetBranchAddress("lep_isolationGradient_3", &lep_isolationGradient_3, &b_lep_isolationGradient_3);
   tree->SetBranchAddress("lep_isolationGradientLoose_3", &lep_isolationGradientLoose_3, &b_lep_isolationGradientLoose_3);
   tree->SetBranchAddress("lep_isolationFixedCutTight_3", &lep_isolationFixedCutTight_3, &b_lep_isolationFixedCutTight_3);
   tree->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_3", &lep_isolationFixedCutTightTrackOnly_3, &b_lep_isolationFixedCutTightTrackOnly_3);
   tree->SetBranchAddress("lep_isolationFixedCutLoose_3", &lep_isolationFixedCutLoose_3, &b_lep_isolationFixedCutLoose_3);
   tree->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3, &b_lep_isTrigMatch_3);
   tree->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3, &b_lep_isTrigMatchDLT_3);
   tree->SetBranchAddress("lep_isPrompt_3", &lep_isPrompt_3, &b_lep_isPrompt_3);
   tree->SetBranchAddress("lep_isFakeLep_3", &lep_isFakeLep_3, &b_lep_isFakeLep_3);
   tree->SetBranchAddress("lep_isQMisID_3", &lep_isQMisID_3, &b_lep_isQMisID_3);
   tree->SetBranchAddress("lep_isConvPh_3", &lep_isConvPh_3, &b_lep_isConvPh_3);
   tree->SetBranchAddress("lep_isExtConvPh_3", &lep_isExtConvPh_3, &b_lep_isExtConvPh_3);
   tree->SetBranchAddress("lep_isIntConvPh_3", &lep_isIntConvPh_3, &b_lep_isIntConvPh_3);
   tree->SetBranchAddress("lep_isISR_FSR_Ph_3", &lep_isISR_FSR_Ph_3, &b_lep_isISR_FSR_Ph_3);
   tree->SetBranchAddress("lep_isBrems_3", &lep_isBrems_3, &b_lep_isBrems_3);
   tree->SetBranchAddress("lep_chargeIDBDTLoose_3", &lep_chargeIDBDTLoose_3, &b_lep_chargeIDBDTLoose_3);
   tree->SetBranchAddress("lep_chargeIDBDTMedium_3", &lep_chargeIDBDTMedium_3, &b_lep_chargeIDBDTMedium_3);
   tree->SetBranchAddress("lep_chargeIDBDTTight_3", &lep_chargeIDBDTTight_3, &b_lep_chargeIDBDTTight_3);
   tree->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_3", &lep_promptLeptonInput_sv1_jf_ntrkv_3, &b_lep_promptLeptonInput_sv1_jf_ntrkv_3);
   tree->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_3", &lep_promptLeptonInput_TrackJetNTrack_3, &b_lep_promptLeptonInput_TrackJetNTrack_3);
   tree->SetBranchAddress("lep_promptLeptonInput_DL1mu_3", &lep_promptLeptonInput_DL1mu_3, &b_lep_promptLeptonInput_DL1mu_3);
   tree->SetBranchAddress("lep_promptLeptonInput_DRlj_3", &lep_promptLeptonInput_DRlj_3, &b_lep_promptLeptonInput_DRlj_3);
   tree->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_3", &lep_promptLeptonInput_LepJetPtFrac_3, &b_lep_promptLeptonInput_LepJetPtFrac_3);
   tree->SetBranchAddress("lep_promptLeptonInput_PtFrac_3", &lep_promptLeptonInput_PtFrac_3, &b_lep_promptLeptonInput_PtFrac_3);
   tree->SetBranchAddress("lep_promptLeptonInput_PtRel_3", &lep_promptLeptonInput_PtRel_3, &b_lep_promptLeptonInput_PtRel_3);
   tree->SetBranchAddress("lep_promptLeptonInput_ip2_3", &lep_promptLeptonInput_ip2_3, &b_lep_promptLeptonInput_ip2_3);
   tree->SetBranchAddress("lep_promptLeptonInput_ip3_3", &lep_promptLeptonInput_ip3_3, &b_lep_promptLeptonInput_ip3_3);
   tree->SetBranchAddress("lep_promptLeptonInput_rnnip_3", &lep_promptLeptonInput_rnnip_3, &b_lep_promptLeptonInput_rnnip_3);
   tree->SetBranchAddress("lep_promptLeptonIso_TagWeight_3", &lep_promptLeptonIso_TagWeight_3, &b_lep_promptLeptonIso_TagWeight_3);
   tree->SetBranchAddress("lep_promptLeptonVeto_TagWeight_3", &lep_promptLeptonVeto_TagWeight_3, &b_lep_promptLeptonVeto_TagWeight_3);
   tree->SetBranchAddress("lep_jet_Pt_3", &lep_jet_Pt_3, &b_lep_jet_Pt_3);
   tree->SetBranchAddress("lep_jet_nTrk_3", &lep_jet_nTrk_3, &b_lep_jet_nTrk_3);
   tree->SetBranchAddress("lep_jet_sumPtTrk_3", &lep_jet_sumPtTrk_3, &b_lep_jet_sumPtTrk_3);
   tree->SetBranchAddress("lep_jet_mv2c10_3", &lep_jet_mv2c10_3, &b_lep_jet_mv2c10_3);
   tree->SetBranchAddress("lep_jet_deltaR_3", &lep_jet_deltaR_3, &b_lep_jet_deltaR_3);
   tree->SetBranchAddress("lep_jet_ptRel_3", &lep_jet_ptRel_3, &b_lep_jet_ptRel_3);
   tree->SetBranchAddress("lep_jet_ptOverMuPt_3", &lep_jet_ptOverMuPt_3, &b_lep_jet_ptOverMuPt_3);
   tree->SetBranchAddress("lep_jet_BDT_3", &lep_jet_BDT_3, &b_lep_jet_BDT_3);
   tree->SetBranchAddress("lep_isTruthMatched_3", &lep_isTruthMatched_3, &b_lep_isTruthMatched_3);
   tree->SetBranchAddress("lep_truthType_3", &lep_truthType_3, &b_lep_truthType_3);
   tree->SetBranchAddress("lep_truthOrigin_3", &lep_truthOrigin_3, &b_lep_truthOrigin_3);
   tree->SetBranchAddress("lep_truthPdgId_3", &lep_truthPdgId_3, &b_lep_truthPdgId_3);
   tree->SetBranchAddress("lep_truthStatus_3", &lep_truthStatus_3, &b_lep_truthStatus_3);
   tree->SetBranchAddress("lep_truthParentType_3", &lep_truthParentType_3, &b_lep_truthParentType_3);
   tree->SetBranchAddress("lep_truthParentOrigin_3", &lep_truthParentOrigin_3, &b_lep_truthParentOrigin_3);
   tree->SetBranchAddress("lep_truthParentPdgId_3", &lep_truthParentPdgId_3, &b_lep_truthParentPdgId_3);
   tree->SetBranchAddress("lep_truthParentStatus_3", &lep_truthParentStatus_3, &b_lep_truthParentStatus_3);
   tree->SetBranchAddress("lep_truthPt_3", &lep_truthPt_3, &b_lep_truthPt_3);
   tree->SetBranchAddress("lep_truthEta_3", &lep_truthEta_3, &b_lep_truthEta_3);
   tree->SetBranchAddress("lep_truthPhi_3", &lep_truthPhi_3, &b_lep_truthPhi_3);
   tree->SetBranchAddress("lep_truthM_3", &lep_truthM_3, &b_lep_truthM_3);
   tree->SetBranchAddress("lep_truthE_3", &lep_truthE_3, &b_lep_truthE_3);
   tree->SetBranchAddress("lep_truthRapidity_3", &lep_truthRapidity_3, &b_lep_truthRapidity_3);
   tree->SetBranchAddress("lep_ambiguityType_3", &lep_ambiguityType_3, &b_lep_ambiguityType_3);
   tree->SetBranchAddress("lep_SFIDLoose_3", &lep_SFIDLoose_3, &b_lep_SFIDLoose_3);
   tree->SetBranchAddress("lep_SFIDTight_3", &lep_SFIDTight_3, &b_lep_SFIDTight_3);
   tree->SetBranchAddress("lep_SFTrigLoose_3", &lep_SFTrigLoose_3, &b_lep_SFTrigLoose_3);
   tree->SetBranchAddress("lep_SFTrigTight_3", &lep_SFTrigTight_3, &b_lep_SFTrigTight_3);
   tree->SetBranchAddress("lep_EffTrigLoose_3", &lep_EffTrigLoose_3, &b_lep_EffTrigLoose_3);
   tree->SetBranchAddress("lep_EffTrigTight_3", &lep_EffTrigTight_3, &b_lep_EffTrigTight_3);
   tree->SetBranchAddress("lep_SFIsoLoose_3", &lep_SFIsoLoose_3, &b_lep_SFIsoLoose_3);
   tree->SetBranchAddress("lep_SFIsoTight_3", &lep_SFIsoTight_3, &b_lep_SFIsoTight_3);
   tree->SetBranchAddress("lep_SFReco_3", &lep_SFReco_3, &b_lep_SFReco_3);
   tree->SetBranchAddress("lep_SFTTVA_3", &lep_SFTTVA_3, &b_lep_SFTTVA_3);
   tree->SetBranchAddress("lep_SFObjLoose_3", &lep_SFObjLoose_3, &b_lep_SFObjLoose_3);
   tree->SetBranchAddress("lep_SFObjTight_3", &lep_SFObjTight_3, &b_lep_SFObjTight_3);
   tree->SetBranchAddress("lep_nInnerPix_3", &lep_nInnerPix_3, &b_lep_nInnerPix_3);
   tree->SetBranchAddress("lep_ID_4", &lep_ID_4, &b_lep_ID_4);
   tree->SetBranchAddress("lep_Index_4", &lep_Index_4, &b_lep_Index_4);
   tree->SetBranchAddress("lep_Pt_4", &lep_Pt_4, &b_lep_Pt_4);
   tree->SetBranchAddress("lep_E_4", &lep_E_4, &b_lep_E_4);
   tree->SetBranchAddress("lep_Eta_4", &lep_Eta_4, &b_lep_Eta_4);
   tree->SetBranchAddress("lep_Phi_4", &lep_Phi_4, &b_lep_Phi_4);
   tree->SetBranchAddress("lep_EtaBE2_4", &lep_EtaBE2_4, &b_lep_EtaBE2_4);
   tree->SetBranchAddress("lep_topoEtcone20_4", &lep_topoEtcone20_4, &b_lep_topoEtcone20_4);
   tree->SetBranchAddress("lep_topoEtcone30_4", &lep_topoEtcone30_4, &b_lep_topoEtcone30_4);
   tree->SetBranchAddress("lep_topoEtcone40_4", &lep_topoEtcone40_4, &b_lep_topoEtcone40_4);
   tree->SetBranchAddress("lep_ptVarcone20_4", &lep_ptVarcone20_4, &b_lep_ptVarcone20_4);
   tree->SetBranchAddress("lep_ptVarcone30_4", &lep_ptVarcone30_4, &b_lep_ptVarcone30_4);
   tree->SetBranchAddress("lep_ptVarcone40_4", &lep_ptVarcone40_4, &b_lep_ptVarcone40_4);
   tree->SetBranchAddress("lep_sigd0PV_4", &lep_sigd0PV_4, &b_lep_sigd0PV_4);
   tree->SetBranchAddress("lep_Z0SinTheta_4", &lep_Z0SinTheta_4, &b_lep_Z0SinTheta_4);
   tree->SetBranchAddress("lep_d0_4", &lep_d0_4, &b_lep_d0_4);
   tree->SetBranchAddress("lep_z0_4", &lep_z0_4, &b_lep_z0_4);
   tree->SetBranchAddress("lep_vz_4", &lep_vz_4, &b_lep_vz_4);
   tree->SetBranchAddress("lep_deltaz0_4", &lep_deltaz0_4, &b_lep_deltaz0_4);
   tree->SetBranchAddress("lep_isTightLH_4", &lep_isTightLH_4, &b_lep_isTightLH_4);
   tree->SetBranchAddress("lep_isMediumLH_4", &lep_isMediumLH_4, &b_lep_isMediumLH_4);
   tree->SetBranchAddress("lep_isLooseLH_4", &lep_isLooseLH_4, &b_lep_isLooseLH_4);
   tree->SetBranchAddress("lep_isTight_4", &lep_isTight_4, &b_lep_isTight_4);
   tree->SetBranchAddress("lep_isMedium_4", &lep_isMedium_4, &b_lep_isMedium_4);
   tree->SetBranchAddress("lep_isLoose_4", &lep_isLoose_4, &b_lep_isLoose_4);
   tree->SetBranchAddress("lep_isolationLooseTrackOnly_4", &lep_isolationLooseTrackOnly_4, &b_lep_isolationLooseTrackOnly_4);
   tree->SetBranchAddress("lep_isolationLoose_4", &lep_isolationLoose_4, &b_lep_isolationLoose_4);
   tree->SetBranchAddress("lep_isolationGradient_4", &lep_isolationGradient_4, &b_lep_isolationGradient_4);
   tree->SetBranchAddress("lep_isolationGradientLoose_4", &lep_isolationGradientLoose_4, &b_lep_isolationGradientLoose_4);
   tree->SetBranchAddress("lep_isolationFixedCutTight_4", &lep_isolationFixedCutTight_4, &b_lep_isolationFixedCutTight_4);
   tree->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_4", &lep_isolationFixedCutTightTrackOnly_4, &b_lep_isolationFixedCutTightTrackOnly_4);
   tree->SetBranchAddress("lep_isolationFixedCutLoose_4", &lep_isolationFixedCutLoose_4, &b_lep_isolationFixedCutLoose_4);
   tree->SetBranchAddress("lep_isTrigMatch_4", &lep_isTrigMatch_4, &b_lep_isTrigMatch_4);
   tree->SetBranchAddress("lep_isTrigMatchDLT_4", &lep_isTrigMatchDLT_4, &b_lep_isTrigMatchDLT_4);
   tree->SetBranchAddress("lep_isPrompt_4", &lep_isPrompt_4, &b_lep_isPrompt_4);
   tree->SetBranchAddress("lep_isFakeLep_4", &lep_isFakeLep_4, &b_lep_isFakeLep_4);
   tree->SetBranchAddress("lep_isQMisID_4", &lep_isQMisID_4, &b_lep_isQMisID_4);
   tree->SetBranchAddress("lep_isConvPh_4", &lep_isConvPh_4, &b_lep_isConvPh_4);
   tree->SetBranchAddress("lep_isExtConvPh_4", &lep_isExtConvPh_4, &b_lep_isExtConvPh_4);
   tree->SetBranchAddress("lep_isIntConvPh_4", &lep_isIntConvPh_4, &b_lep_isIntConvPh_4);
   tree->SetBranchAddress("lep_isISR_FSR_Ph_4", &lep_isISR_FSR_Ph_4, &b_lep_isISR_FSR_Ph_4);
   tree->SetBranchAddress("lep_isBrems_4", &lep_isBrems_4, &b_lep_isBrems_4);
   tree->SetBranchAddress("lep_chargeIDBDTLoose_4", &lep_chargeIDBDTLoose_4, &b_lep_chargeIDBDTLoose_4);
   tree->SetBranchAddress("lep_chargeIDBDTMedium_4", &lep_chargeIDBDTMedium_4, &b_lep_chargeIDBDTMedium_4);
   tree->SetBranchAddress("lep_chargeIDBDTTight_4", &lep_chargeIDBDTTight_4, &b_lep_chargeIDBDTTight_4);
   tree->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_4", &lep_promptLeptonInput_sv1_jf_ntrkv_4, &b_lep_promptLeptonInput_sv1_jf_ntrkv_4);
   tree->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_4", &lep_promptLeptonInput_TrackJetNTrack_4, &b_lep_promptLeptonInput_TrackJetNTrack_4);
   tree->SetBranchAddress("lep_promptLeptonInput_DL1mu_4", &lep_promptLeptonInput_DL1mu_4, &b_lep_promptLeptonInput_DL1mu_4);
   tree->SetBranchAddress("lep_promptLeptonInput_DRlj_4", &lep_promptLeptonInput_DRlj_4, &b_lep_promptLeptonInput_DRlj_4);
   tree->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_4", &lep_promptLeptonInput_LepJetPtFrac_4, &b_lep_promptLeptonInput_LepJetPtFrac_4);
   tree->SetBranchAddress("lep_promptLeptonInput_PtFrac_4", &lep_promptLeptonInput_PtFrac_4, &b_lep_promptLeptonInput_PtFrac_4);
   tree->SetBranchAddress("lep_promptLeptonInput_PtRel_4", &lep_promptLeptonInput_PtRel_4, &b_lep_promptLeptonInput_PtRel_4);
   tree->SetBranchAddress("lep_promptLeptonInput_ip2_4", &lep_promptLeptonInput_ip2_4, &b_lep_promptLeptonInput_ip2_4);
   tree->SetBranchAddress("lep_promptLeptonInput_ip3_4", &lep_promptLeptonInput_ip3_4, &b_lep_promptLeptonInput_ip3_4);
   tree->SetBranchAddress("lep_promptLeptonInput_rnnip_4", &lep_promptLeptonInput_rnnip_4, &b_lep_promptLeptonInput_rnnip_4);
   tree->SetBranchAddress("lep_promptLeptonIso_TagWeight_4", &lep_promptLeptonIso_TagWeight_4, &b_lep_promptLeptonIso_TagWeight_4);
   tree->SetBranchAddress("lep_promptLeptonVeto_TagWeight_4", &lep_promptLeptonVeto_TagWeight_4, &b_lep_promptLeptonVeto_TagWeight_4);
   tree->SetBranchAddress("lep_jet_Pt_4", &lep_jet_Pt_4, &b_lep_jet_Pt_4);
   tree->SetBranchAddress("lep_jet_nTrk_4", &lep_jet_nTrk_4, &b_lep_jet_nTrk_4);
   tree->SetBranchAddress("lep_jet_sumPtTrk_4", &lep_jet_sumPtTrk_4, &b_lep_jet_sumPtTrk_4);
   tree->SetBranchAddress("lep_jet_mv2c10_4", &lep_jet_mv2c10_4, &b_lep_jet_mv2c10_4);
   tree->SetBranchAddress("lep_jet_deltaR_4", &lep_jet_deltaR_4, &b_lep_jet_deltaR_4);
   tree->SetBranchAddress("lep_jet_ptRel_4", &lep_jet_ptRel_4, &b_lep_jet_ptRel_4);
   tree->SetBranchAddress("lep_jet_ptOverMuPt_4", &lep_jet_ptOverMuPt_4, &b_lep_jet_ptOverMuPt_4);
   tree->SetBranchAddress("lep_jet_BDT_4", &lep_jet_BDT_4, &b_lep_jet_BDT_4);
   tree->SetBranchAddress("lep_isTruthMatched_4", &lep_isTruthMatched_4, &b_lep_isTruthMatched_4);
   tree->SetBranchAddress("lep_truthType_4", &lep_truthType_4, &b_lep_truthType_4);
   tree->SetBranchAddress("lep_truthOrigin_4", &lep_truthOrigin_4, &b_lep_truthOrigin_4);
   tree->SetBranchAddress("lep_truthPdgId_4", &lep_truthPdgId_4, &b_lep_truthPdgId_4);
   tree->SetBranchAddress("lep_truthStatus_4", &lep_truthStatus_4, &b_lep_truthStatus_4);
   tree->SetBranchAddress("lep_truthParentType_4", &lep_truthParentType_4, &b_lep_truthParentType_4);
   tree->SetBranchAddress("lep_truthParentOrigin_4", &lep_truthParentOrigin_4, &b_lep_truthParentOrigin_4);
   tree->SetBranchAddress("lep_truthParentPdgId_4", &lep_truthParentPdgId_4, &b_lep_truthParentPdgId_4);
   tree->SetBranchAddress("lep_truthParentStatus_4", &lep_truthParentStatus_4, &b_lep_truthParentStatus_4);
   tree->SetBranchAddress("lep_truthPt_4", &lep_truthPt_4, &b_lep_truthPt_4);
   tree->SetBranchAddress("lep_truthEta_4", &lep_truthEta_4, &b_lep_truthEta_4);
   tree->SetBranchAddress("lep_truthPhi_4", &lep_truthPhi_4, &b_lep_truthPhi_4);
   tree->SetBranchAddress("lep_truthM_4", &lep_truthM_4, &b_lep_truthM_4);
   tree->SetBranchAddress("lep_truthE_4", &lep_truthE_4, &b_lep_truthE_4);
   tree->SetBranchAddress("lep_truthRapidity_4", &lep_truthRapidity_4, &b_lep_truthRapidity_4);
   tree->SetBranchAddress("lep_ambiguityType_4", &lep_ambiguityType_4, &b_lep_ambiguityType_4);
   tree->SetBranchAddress("lep_SFIDLoose_4", &lep_SFIDLoose_4, &b_lep_SFIDLoose_4);
   tree->SetBranchAddress("lep_SFIDTight_4", &lep_SFIDTight_4, &b_lep_SFIDTight_4);
   tree->SetBranchAddress("lep_SFTrigLoose_4", &lep_SFTrigLoose_4, &b_lep_SFTrigLoose_4);
   tree->SetBranchAddress("lep_SFTrigTight_4", &lep_SFTrigTight_4, &b_lep_SFTrigTight_4);
   tree->SetBranchAddress("lep_EffTrigLoose_4", &lep_EffTrigLoose_4, &b_lep_EffTrigLoose_4);
   tree->SetBranchAddress("lep_EffTrigTight_4", &lep_EffTrigTight_4, &b_lep_EffTrigTight_4);
   tree->SetBranchAddress("lep_SFIsoLoose_4", &lep_SFIsoLoose_4, &b_lep_SFIsoLoose_4);
   tree->SetBranchAddress("lep_SFIsoTight_4", &lep_SFIsoTight_4, &b_lep_SFIsoTight_4);
   tree->SetBranchAddress("lep_SFReco_4", &lep_SFReco_4, &b_lep_SFReco_4);
   tree->SetBranchAddress("lep_SFTTVA_4", &lep_SFTTVA_4, &b_lep_SFTTVA_4);
   tree->SetBranchAddress("lep_SFObjLoose_4", &lep_SFObjLoose_4, &b_lep_SFObjLoose_4);
   tree->SetBranchAddress("lep_SFObjTight_4", &lep_SFObjTight_4, &b_lep_SFObjTight_4);
   tree->SetBranchAddress("lep_nInnerPix_4", &lep_nInnerPix_4, &b_lep_nInnerPix_4);
   tree->SetBranchAddress("tau_pt_0", &tau_pt_0, &b_tau_pt_0);
   tree->SetBranchAddress("tau_eta_0", &tau_eta_0, &b_tau_eta_0);
   tree->SetBranchAddress("tau_phi_0", &tau_phi_0, &b_tau_phi_0);
   tree->SetBranchAddress("tau_charge_0", &tau_charge_0, &b_tau_charge_0);
   tree->SetBranchAddress("tau_E_0", &tau_E_0, &b_tau_E_0);
   tree->SetBranchAddress("tau_BDTJetScore_0", &tau_BDTJetScore_0, &b_tau_BDTJetScore_0);
   tree->SetBranchAddress("tau_JetBDTSigLoose_0", &tau_JetBDTSigLoose_0, &b_tau_JetBDTSigLoose_0);
   tree->SetBranchAddress("tau_JetBDTSigMedium_0", &tau_JetBDTSigMedium_0, &b_tau_JetBDTSigMedium_0);
   tree->SetBranchAddress("tau_JetBDTSigTight_0", &tau_JetBDTSigTight_0, &b_tau_JetBDTSigTight_0);
   tree->SetBranchAddress("tau_numTrack_0", &tau_numTrack_0, &b_tau_numTrack_0);
   tree->SetBranchAddress("tau_isHadronic_0", &tau_isHadronic_0, &b_tau_isHadronic_0);
   tree->SetBranchAddress("tau_tagWeightBin_0", &tau_tagWeightBin_0, &b_tau_tagWeightBin_0);
   tree->SetBranchAddress("tau_MV2c10_0", &tau_MV2c10_0, &b_tau_MV2c10_0);
   tree->SetBranchAddress("tau_fromPV_0", &tau_fromPV_0, &b_tau_fromPV_0);
   tree->SetBranchAddress("tau_SFTight_0", &tau_SFTight_0, &b_tau_SFTight_0);
   tree->SetBranchAddress("tau_SFLoose_0", &tau_SFLoose_0, &b_tau_SFLoose_0);
   tree->SetBranchAddress("tau_passEleOLR_0", &tau_passEleOLR_0, &b_tau_passEleOLR_0);
   tree->SetBranchAddress("tau_passEleBDT_0", &tau_passEleBDT_0, &b_tau_passEleBDT_0);
   tree->SetBranchAddress("tau_passMuonOLR_0", &tau_passMuonOLR_0, &b_tau_passMuonOLR_0);
   tree->SetBranchAddress("tau_BDTEleScoreSigTrans_0", &tau_BDTEleScoreSigTrans_0, &b_tau_BDTEleScoreSigTrans_0);
   tree->SetBranchAddress("tau_BDTJetScoreSigTrans_0", &tau_BDTJetScoreSigTrans_0, &b_tau_BDTJetScoreSigTrans_0);
   tree->SetBranchAddress("tau_truthOrigin_0", &tau_truthOrigin_0, &b_tau_truthOrigin_0);
   tree->SetBranchAddress("tau_truthType_0", &tau_truthType_0, &b_tau_truthType_0);
   tree->SetBranchAddress("tau_truthJetFlavour_0", &tau_truthJetFlavour_0, &b_tau_truthJetFlavour_0);
   tree->SetBranchAddress("tau_promptTauInput_TrackJetNTrack_0", &tau_promptTauInput_TrackJetNTrack_0, &b_tau_promptTauInput_TrackJetNTrack_0);
   tree->SetBranchAddress("tau_promptTauInput_JetF_0", &tau_promptTauInput_JetF_0, &b_tau_promptTauInput_JetF_0);
   tree->SetBranchAddress("tau_promptTauInput_DRlj_0", &tau_promptTauInput_DRlj_0, &b_tau_promptTauInput_DRlj_0);
   tree->SetBranchAddress("tau_promptTauInput_LepJetPtFrac_0", &tau_promptTauInput_LepJetPtFrac_0, &b_tau_promptTauInput_LepJetPtFrac_0);
   tree->SetBranchAddress("tau_promptTauInput_SV1_0", &tau_promptTauInput_SV1_0, &b_tau_promptTauInput_SV1_0);
   tree->SetBranchAddress("tau_promptTauInput_MV2c10rnn_0", &tau_promptTauInput_MV2c10rnn_0, &b_tau_promptTauInput_MV2c10rnn_0);
   tree->SetBranchAddress("tau_promptTauInput_ip2_0", &tau_promptTauInput_ip2_0, &b_tau_promptTauInput_ip2_0);
   tree->SetBranchAddress("tau_promptTauInput_ip3_0", &tau_promptTauInput_ip3_0, &b_tau_promptTauInput_ip3_0);
   tree->SetBranchAddress("tau_promptTauInput_rnnip_0", &tau_promptTauInput_rnnip_0, &b_tau_promptTauInput_rnnip_0);
   tree->SetBranchAddress("tau_promptTauInput_MV2c10_0", &tau_promptTauInput_MV2c10_0, &b_tau_promptTauInput_MV2c10_0);
   tree->SetBranchAddress("tau_promptTauVeto_0", &tau_promptTauVeto_0, &b_tau_promptTauVeto_0);
   tree->SetBranchAddress("tau_promptTauIso_0", &tau_promptTauIso_0, &b_tau_promptTauIso_0);
   tree->SetBranchAddress("tau_pt_1", &tau_pt_1, &b_tau_pt_1);
   tree->SetBranchAddress("tau_eta_1", &tau_eta_1, &b_tau_eta_1);
   tree->SetBranchAddress("tau_phi_1", &tau_phi_1, &b_tau_phi_1);
   tree->SetBranchAddress("tau_charge_1", &tau_charge_1, &b_tau_charge_1);
   tree->SetBranchAddress("tau_E_1", &tau_E_1, &b_tau_E_1);
   tree->SetBranchAddress("tau_BDTJetScore_1", &tau_BDTJetScore_1, &b_tau_BDTJetScore_1);
   tree->SetBranchAddress("tau_JetBDTSigLoose_1", &tau_JetBDTSigLoose_1, &b_tau_JetBDTSigLoose_1);
   tree->SetBranchAddress("tau_JetBDTSigMedium_1", &tau_JetBDTSigMedium_1, &b_tau_JetBDTSigMedium_1);
   tree->SetBranchAddress("tau_JetBDTSigTight_1", &tau_JetBDTSigTight_1, &b_tau_JetBDTSigTight_1);
   tree->SetBranchAddress("tau_numTrack_1", &tau_numTrack_1, &b_tau_numTrack_1);
   tree->SetBranchAddress("tau_isHadronic_1", &tau_isHadronic_1, &b_tau_isHadronic_1);
   tree->SetBranchAddress("tau_tagWeightBin_1", &tau_tagWeightBin_1, &b_tau_tagWeightBin_1);
   tree->SetBranchAddress("tau_MV2c10_1", &tau_MV2c10_1, &b_tau_MV2c10_1);
   tree->SetBranchAddress("tau_fromPV_1", &tau_fromPV_1, &b_tau_fromPV_1);
   tree->SetBranchAddress("tau_SFTight_1", &tau_SFTight_1, &b_tau_SFTight_1);
   tree->SetBranchAddress("tau_SFLoose_1", &tau_SFLoose_1, &b_tau_SFLoose_1);
   tree->SetBranchAddress("tau_passEleOLR_1", &tau_passEleOLR_1, &b_tau_passEleOLR_1);
   tree->SetBranchAddress("tau_passEleBDT_1", &tau_passEleBDT_1, &b_tau_passEleBDT_1);
   tree->SetBranchAddress("tau_passMuonOLR_1", &tau_passMuonOLR_1, &b_tau_passMuonOLR_1);
   tree->SetBranchAddress("tau_BDTEleScoreSigTrans_1", &tau_BDTEleScoreSigTrans_1, &b_tau_BDTEleScoreSigTrans_1);
   tree->SetBranchAddress("tau_BDTJetScoreSigTrans_1", &tau_BDTJetScoreSigTrans_1, &b_tau_BDTJetScoreSigTrans_1);
   tree->SetBranchAddress("tau_truthOrigin_1", &tau_truthOrigin_1, &b_tau_truthOrigin_1);
   tree->SetBranchAddress("tau_truthType_1", &tau_truthType_1, &b_tau_truthType_1);
   tree->SetBranchAddress("tau_truthJetFlavour_1", &tau_truthJetFlavour_1, &b_tau_truthJetFlavour_1);
   tree->SetBranchAddress("tau_promptTauInput_TrackJetNTrack_1", &tau_promptTauInput_TrackJetNTrack_1, &b_tau_promptTauInput_TrackJetNTrack_1);
   tree->SetBranchAddress("tau_promptTauInput_JetF_1", &tau_promptTauInput_JetF_1, &b_tau_promptTauInput_JetF_1);
   tree->SetBranchAddress("tau_promptTauInput_DRlj_1", &tau_promptTauInput_DRlj_1, &b_tau_promptTauInput_DRlj_1);
   tree->SetBranchAddress("tau_promptTauInput_LepJetPtFrac_1", &tau_promptTauInput_LepJetPtFrac_1, &b_tau_promptTauInput_LepJetPtFrac_1);
   tree->SetBranchAddress("tau_promptTauInput_SV1_1", &tau_promptTauInput_SV1_1, &b_tau_promptTauInput_SV1_1);
   tree->SetBranchAddress("tau_promptTauInput_MV2c10rnn_1", &tau_promptTauInput_MV2c10rnn_1, &b_tau_promptTauInput_MV2c10rnn_1);
   tree->SetBranchAddress("tau_promptTauInput_ip2_1", &tau_promptTauInput_ip2_1, &b_tau_promptTauInput_ip2_1);
   tree->SetBranchAddress("tau_promptTauInput_ip3_1", &tau_promptTauInput_ip3_1, &b_tau_promptTauInput_ip3_1);
   tree->SetBranchAddress("tau_promptTauInput_rnnip_1", &tau_promptTauInput_rnnip_1, &b_tau_promptTauInput_rnnip_1);
   tree->SetBranchAddress("tau_promptTauInput_MV2c10_1", &tau_promptTauInput_MV2c10_1, &b_tau_promptTauInput_MV2c10_1);
   tree->SetBranchAddress("tau_promptTauVeto_1", &tau_promptTauVeto_1, &b_tau_promptTauVeto_1);
   tree->SetBranchAddress("tau_promptTauIso_1", &tau_promptTauIso_1, &b_tau_promptTauIso_1);
   tree->SetBranchAddress("onelep_type", &onelep_type, &b_onelep_type);
   tree->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   tree->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   tree->SetBranchAddress("quadlep_type", &quadlep_type, &b_quadlep_type);
   tree->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   tree->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   tree->SetBranchAddress("isQMisIDEvent", &isQMisIDEvent, &b_isQMisIDEvent);
   tree->SetBranchAddress("isFakeEvent", &isFakeEvent, &b_isFakeEvent);
   tree->SetBranchAddress("isLepFromPhEvent", &isLepFromPhEvent, &b_isLepFromPhEvent);
   tree->SetBranchAddress("Mll01", &Mll01, &b_Mll01);
   tree->SetBranchAddress("Ptll01", &Ptll01, &b_Ptll01);
   tree->SetBranchAddress("DRll01", &DRll01, &b_DRll01);
   tree->SetBranchAddress("matchDLTll01", &matchDLTll01, &b_matchDLTll01);
   tree->SetBranchAddress("Mlll012", &Mlll012, &b_Mlll012);
   tree->SetBranchAddress("Mllll0123", &Mllll0123, &b_Mllll0123);
   tree->SetBranchAddress("Mllll0124", &Mllll0124, &b_Mllll0124);
   tree->SetBranchAddress("Mlll013", &Mlll013, &b_Mlll013);
   tree->SetBranchAddress("Mllll0134", &Mllll0134, &b_Mllll0134);
   tree->SetBranchAddress("Mlll014", &Mlll014, &b_Mlll014);
   tree->SetBranchAddress("Mll02", &Mll02, &b_Mll02);
   tree->SetBranchAddress("Ptll02", &Ptll02, &b_Ptll02);
   tree->SetBranchAddress("DRll02", &DRll02, &b_DRll02);
   tree->SetBranchAddress("matchDLTll02", &matchDLTll02, &b_matchDLTll02);
   tree->SetBranchAddress("Mlll023", &Mlll023, &b_Mlll023);
   tree->SetBranchAddress("Mllll0234", &Mllll0234, &b_Mllll0234);
   tree->SetBranchAddress("Mlll024", &Mlll024, &b_Mlll024);
   tree->SetBranchAddress("Mll03", &Mll03, &b_Mll03);
   tree->SetBranchAddress("Ptll03", &Ptll03, &b_Ptll03);
   tree->SetBranchAddress("DRll03", &DRll03, &b_DRll03);
   tree->SetBranchAddress("matchDLTll03", &matchDLTll03, &b_matchDLTll03);
   tree->SetBranchAddress("Mlll034", &Mlll034, &b_Mlll034);
   tree->SetBranchAddress("Mll04", &Mll04, &b_Mll04);
   tree->SetBranchAddress("Ptll04", &Ptll04, &b_Ptll04);
   tree->SetBranchAddress("DRll04", &DRll04, &b_DRll04);
   tree->SetBranchAddress("matchDLTll04", &matchDLTll04, &b_matchDLTll04);
   tree->SetBranchAddress("Mll12", &Mll12, &b_Mll12);
   tree->SetBranchAddress("Ptll12", &Ptll12, &b_Ptll12);
   tree->SetBranchAddress("DRll12", &DRll12, &b_DRll12);
   tree->SetBranchAddress("matchDLTll12", &matchDLTll12, &b_matchDLTll12);
   tree->SetBranchAddress("Mlll123", &Mlll123, &b_Mlll123);
   tree->SetBranchAddress("Mllll1234", &Mllll1234, &b_Mllll1234);
   tree->SetBranchAddress("Mlll124", &Mlll124, &b_Mlll124);
   tree->SetBranchAddress("Mll13", &Mll13, &b_Mll13);
   tree->SetBranchAddress("Ptll13", &Ptll13, &b_Ptll13);
   tree->SetBranchAddress("DRll13", &DRll13, &b_DRll13);
   tree->SetBranchAddress("matchDLTll13", &matchDLTll13, &b_matchDLTll13);
   tree->SetBranchAddress("Mlll134", &Mlll134, &b_Mlll134);
   tree->SetBranchAddress("Mll14", &Mll14, &b_Mll14);
   tree->SetBranchAddress("Ptll14", &Ptll14, &b_Ptll14);
   tree->SetBranchAddress("DRll14", &DRll14, &b_DRll14);
   tree->SetBranchAddress("matchDLTll14", &matchDLTll14, &b_matchDLTll14);
   tree->SetBranchAddress("Mll23", &Mll23, &b_Mll23);
   tree->SetBranchAddress("Ptll23", &Ptll23, &b_Ptll23);
   tree->SetBranchAddress("DRll23", &DRll23, &b_DRll23);
   tree->SetBranchAddress("matchDLTll23", &matchDLTll23, &b_matchDLTll23);
   tree->SetBranchAddress("Mlll234", &Mlll234, &b_Mlll234);
   tree->SetBranchAddress("Mll24", &Mll24, &b_Mll24);
   tree->SetBranchAddress("Ptll24", &Ptll24, &b_Ptll24);
   tree->SetBranchAddress("DRll24", &DRll24, &b_DRll24);
   tree->SetBranchAddress("matchDLTll24", &matchDLTll24, &b_matchDLTll24);
   tree->SetBranchAddress("Mll34", &Mll34, &b_Mll34);
   tree->SetBranchAddress("Ptll34", &Ptll34, &b_Ptll34);
   tree->SetBranchAddress("DRll34", &DRll34, &b_DRll34);
   tree->SetBranchAddress("matchDLTll34", &matchDLTll34, &b_matchDLTll34);
   tree->SetBranchAddress("best_Z_Mll", &best_Z_Mll, &b_best_Z_Mll);
   tree->SetBranchAddress("best_Z_other_MtLepMet", &best_Z_other_MtLepMet, &b_best_Z_other_MtLepMet);
   tree->SetBranchAddress("best_Z_other_Mll", &best_Z_other_Mll, &b_best_Z_other_Mll);
   tree->SetBranchAddress("minOSSFMll", &minOSSFMll, &b_minOSSFMll);
   tree->SetBranchAddress("minOSMll", &minOSMll, &b_minOSMll);
   tree->SetBranchAddress("nJets_OR_T", &nJets_OR_T, &b_nJets_OR_T);
   tree->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   tree->SetBranchAddress("nTruthJets", &nTruthJets, &b_nTruthJets);
   tree->SetBranchAddress("nTruthJets_OR", &nTruthJets_OR, &b_nTruthJets_OR);
   tree->SetBranchAddress("nJets_OR_T_MV2c10_60", &nJets_OR_T_MV2c10_60, &b_nJets_OR_T_MV2c10_60);
   tree->SetBranchAddress("nJets_OR_T_MV2c10_70", &nJets_OR_T_MV2c10_70, &b_nJets_OR_T_MV2c10_70);
   tree->SetBranchAddress("nJets_OR_T_MV2c10_77", &nJets_OR_T_MV2c10_77, &b_nJets_OR_T_MV2c10_77);
   tree->SetBranchAddress("nJets_OR_T_MV2c10_85", &nJets_OR_T_MV2c10_85, &b_nJets_OR_T_MV2c10_85);
   tree->SetBranchAddress("nJets_OR_MV2c10_85", &nJets_OR_MV2c10_85, &b_nJets_OR_MV2c10_85);
   tree->SetBranchAddress("nJets_OR_MV2c10_60", &nJets_OR_MV2c10_60, &b_nJets_OR_MV2c10_60);
   tree->SetBranchAddress("nJets_OR_MV2c10_77", &nJets_OR_MV2c10_77, &b_nJets_OR_MV2c10_77);
   tree->SetBranchAddress("nJets_OR_MV2c10_70", &nJets_OR_MV2c10_70, &b_nJets_OR_MV2c10_70);
   tree->SetBranchAddress("nJets_OR_T_DL1_60", &nJets_OR_T_DL1_60, &b_nJets_OR_T_DL1_60);
   tree->SetBranchAddress("nJets_OR_T_DL1_70", &nJets_OR_T_DL1_70, &b_nJets_OR_T_DL1_70);
   tree->SetBranchAddress("nJets_OR_T_DL1_77", &nJets_OR_T_DL1_77, &b_nJets_OR_T_DL1_77);
   tree->SetBranchAddress("nJets_OR_T_DL1_85", &nJets_OR_T_DL1_85, &b_nJets_OR_T_DL1_85);
   tree->SetBranchAddress("nJets_OR_DL1_85", &nJets_OR_DL1_85, &b_nJets_OR_DL1_85);
   tree->SetBranchAddress("nJets_OR_DL1_60", &nJets_OR_DL1_60, &b_nJets_OR_DL1_60);
   tree->SetBranchAddress("nJets_OR_DL1_77", &nJets_OR_DL1_77, &b_nJets_OR_DL1_77);
   tree->SetBranchAddress("nJets_OR_DL1_70", &nJets_OR_DL1_70, &b_nJets_OR_DL1_70);
   tree->SetBranchAddress("nTaus_OR_Pt25", &nTaus_OR_Pt25, &b_nTaus_OR_Pt25);
   tree->SetBranchAddress("isBlinded", &isBlinded, &b_isBlinded);
   tree->SetBranchAddress("HT", &HT, &b_HT);
   tree->SetBranchAddress("HT_lep", &HT_lep, &b_HT_lep);
   tree->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   tree->SetBranchAddress("lead_jetPt", &lead_jetPt, &b_lead_jetPt);
   tree->SetBranchAddress("lead_jetEta", &lead_jetEta, &b_lead_jetEta);
   tree->SetBranchAddress("lead_jetPhi", &lead_jetPhi, &b_lead_jetPhi);
   tree->SetBranchAddress("lead_jetE", &lead_jetE, &b_lead_jetE);
   tree->SetBranchAddress("sublead_jetPt", &sublead_jetPt, &b_sublead_jetPt);
   tree->SetBranchAddress("sublead_jetEta", &sublead_jetEta, &b_sublead_jetEta);
   tree->SetBranchAddress("sublead_jetPhi", &sublead_jetPhi, &b_sublead_jetPhi);
   tree->SetBranchAddress("sublead_jetE", &sublead_jetE, &b_sublead_jetE);
   tree->SetBranchAddress("selected_jets", &selected_jets, &b_selected_jets);
   tree->SetBranchAddress("selected_jets_T", &selected_jets_T, &b_selected_jets_T);
   tree->SetBranchAddress("selected_jets_mv2c10_Ordrd", &selected_jets_mv2c10_Ordrd, &b_selected_jets_mv2c10_Ordrd);
   tree->SetBranchAddress("selected_jets_T_mv2c10_Ordrd", &selected_jets_T_mv2c10_Ordrd, &b_selected_jets_T_mv2c10_Ordrd);
   tree->SetBranchAddress("lepSFIDLoose", &lepSFIDLoose, &b_lepSFIDLoose);
   tree->SetBranchAddress("lepSFIDTight", &lepSFIDTight, &b_lepSFIDTight);
   tree->SetBranchAddress("lepSFIsoLoose", &lepSFIsoLoose, &b_lepSFIsoLoose);
   tree->SetBranchAddress("lepSFIsoTight", &lepSFIsoTight, &b_lepSFIsoTight);
   tree->SetBranchAddress("lepSFReco", &lepSFReco, &b_lepSFReco);
   tree->SetBranchAddress("lepSFTTVA", &lepSFTTVA, &b_lepSFTTVA);
   tree->SetBranchAddress("lepSFTrigLoose", &lepSFTrigLoose, &b_lepSFTrigLoose);
   tree->SetBranchAddress("lepSFTrigTight", &lepSFTrigTight, &b_lepSFTrigTight);
   tree->SetBranchAddress("lepSFTrigTightLoose", &lepSFTrigTightLoose, &b_lepSFTrigTightLoose);
   tree->SetBranchAddress("lepSFTrigLooseTight", &lepSFTrigLooseTight, &b_lepSFTrigLooseTight);
   tree->SetBranchAddress("lepEffTrigLoose", &lepEffTrigLoose, &b_lepEffTrigLoose);
   tree->SetBranchAddress("lepEffTrigTight", &lepEffTrigTight, &b_lepEffTrigTight);
   tree->SetBranchAddress("lepEffTrigTightLoose", &lepEffTrigTightLoose, &b_lepEffTrigTightLoose);
   tree->SetBranchAddress("lepEffTrigLooseTight", &lepEffTrigLooseTight, &b_lepEffTrigLooseTight);
   tree->SetBranchAddress("lepDataEffTrigLoose", &lepDataEffTrigLoose, &b_lepDataEffTrigLoose);
   tree->SetBranchAddress("lepDataEffTrigTight", &lepDataEffTrigTight, &b_lepDataEffTrigTight);
   tree->SetBranchAddress("lepDataEffTrigTightLoose", &lepDataEffTrigTightLoose, &b_lepDataEffTrigTightLoose);
   tree->SetBranchAddress("lepDataEffTrigLooseTight", &lepDataEffTrigLooseTight, &b_lepDataEffTrigLooseTight);
   tree->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   tree->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   tree->SetBranchAddress("tauSFTight", &tauSFTight, &b_tauSFTight);
   tree->SetBranchAddress("tauSFLoose", &tauSFLoose, &b_tauSFLoose);
   if(dosys){
      tree->SetBranchAddress("lepSFTrigLoose_EL_SF_Trigger_UP", &lepSFTrigLoose_EL_SF_Trigger_UP, &b_lepSFTrigLoose_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_UP", &lepSFTrigTight_EL_SF_Trigger_UP, &b_lepSFTrigTight_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigTightLoose_EL_SF_Trigger_UP", &lepSFTrigTightLoose_EL_SF_Trigger_UP, &b_lepSFTrigTightLoose_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigLooseTight_EL_SF_Trigger_UP", &lepSFTrigLooseTight_EL_SF_Trigger_UP, &b_lepSFTrigLooseTight_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigLoose_EL_SF_Trigger_UP", &lepEffTrigLoose_EL_SF_Trigger_UP, &b_lepEffTrigLoose_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigTight_EL_SF_Trigger_UP", &lepEffTrigTight_EL_SF_Trigger_UP, &b_lepEffTrigTight_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigTightLoose_EL_SF_Trigger_UP", &lepEffTrigTightLoose_EL_SF_Trigger_UP, &b_lepEffTrigTightLoose_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigLooseTight_EL_SF_Trigger_UP", &lepEffTrigLooseTight_EL_SF_Trigger_UP, &b_lepEffTrigLooseTight_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigLoose_EL_SF_Trigger_UP", &lepDataEffTrigLoose_EL_SF_Trigger_UP, &b_lepDataEffTrigLoose_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigTight_EL_SF_Trigger_UP", &lepDataEffTrigTight_EL_SF_Trigger_UP, &b_lepDataEffTrigTight_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigTightLoose_EL_SF_Trigger_UP", &lepDataEffTrigTightLoose_EL_SF_Trigger_UP, &b_lepDataEffTrigTightLoose_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigLooseTight_EL_SF_Trigger_UP", &lepDataEffTrigLooseTight_EL_SF_Trigger_UP, &b_lepDataEffTrigLooseTight_EL_SF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigLoose_EL_SF_Trigger_DOWN", &lepSFTrigLoose_EL_SF_Trigger_DOWN, &b_lepSFTrigLoose_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_DOWN", &lepSFTrigTight_EL_SF_Trigger_DOWN, &b_lepSFTrigTight_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigTightLoose_EL_SF_Trigger_DOWN", &lepSFTrigTightLoose_EL_SF_Trigger_DOWN, &b_lepSFTrigTightLoose_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigLooseTight_EL_SF_Trigger_DOWN", &lepSFTrigLooseTight_EL_SF_Trigger_DOWN, &b_lepSFTrigLooseTight_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigLoose_EL_SF_Trigger_DOWN", &lepEffTrigLoose_EL_SF_Trigger_DOWN, &b_lepEffTrigLoose_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigTight_EL_SF_Trigger_DOWN", &lepEffTrigTight_EL_SF_Trigger_DOWN, &b_lepEffTrigTight_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigTightLoose_EL_SF_Trigger_DOWN", &lepEffTrigTightLoose_EL_SF_Trigger_DOWN, &b_lepEffTrigTightLoose_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigLooseTight_EL_SF_Trigger_DOWN", &lepEffTrigLooseTight_EL_SF_Trigger_DOWN, &b_lepEffTrigLooseTight_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigLoose_EL_SF_Trigger_DOWN", &lepDataEffTrigLoose_EL_SF_Trigger_DOWN, &b_lepDataEffTrigLoose_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigTight_EL_SF_Trigger_DOWN", &lepDataEffTrigTight_EL_SF_Trigger_DOWN, &b_lepDataEffTrigTight_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN", &lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN, &b_lepDataEffTrigTightLoose_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN", &lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN, &b_lepDataEffTrigLooseTight_EL_SF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_STAT_UP", &lepSFTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepSFTrigLoose_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_UP", &lepSFTrigTight_MU_SF_Trigger_STAT_UP, &b_lepSFTrigTight_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP", &lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP, &b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP", &lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP, &b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP", &lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP, &b_lepEffTrigTightLoose_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP", &lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP, &b_lepEffTrigLooseTight_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP", &lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_STAT_UP", &lepDataEffTrigTight_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigTight_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP", &lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP", &lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_UP);
      tree->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_DOWN", &lepSFTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN", &lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigTightLoose_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN", &lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigLooseTight_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigLoose_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigTight_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigTightLoose_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN", &lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN, &b_lepDataEffTrigLooseTight_MU_SF_Trigger_STAT_DOWN);
      tree->SetBranchAddress("lepSFTrigLoose_EL_EFF_Trigger_UP", &lepSFTrigLoose_EL_EFF_Trigger_UP, &b_lepSFTrigLoose_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigTight_EL_EFF_Trigger_UP", &lepSFTrigTight_EL_EFF_Trigger_UP, &b_lepSFTrigTight_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigTightLoose_EL_EFF_Trigger_UP", &lepSFTrigTightLoose_EL_EFF_Trigger_UP, &b_lepSFTrigTightLoose_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigLooseTight_EL_EFF_Trigger_UP", &lepSFTrigLooseTight_EL_EFF_Trigger_UP, &b_lepSFTrigLooseTight_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigLoose_EL_EFF_Trigger_UP", &lepEffTrigLoose_EL_EFF_Trigger_UP, &b_lepEffTrigLoose_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigTight_EL_EFF_Trigger_UP", &lepEffTrigTight_EL_EFF_Trigger_UP, &b_lepEffTrigTight_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigTightLoose_EL_EFF_Trigger_UP", &lepEffTrigTightLoose_EL_EFF_Trigger_UP, &b_lepEffTrigTightLoose_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepEffTrigLooseTight_EL_EFF_Trigger_UP", &lepEffTrigLooseTight_EL_EFF_Trigger_UP, &b_lepEffTrigLooseTight_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigLoose_EL_EFF_Trigger_UP", &lepDataEffTrigLoose_EL_EFF_Trigger_UP, &b_lepDataEffTrigLoose_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigTight_EL_EFF_Trigger_UP", &lepDataEffTrigTight_EL_EFF_Trigger_UP, &b_lepDataEffTrigTight_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigTightLoose_EL_EFF_Trigger_UP", &lepDataEffTrigTightLoose_EL_EFF_Trigger_UP, &b_lepDataEffTrigTightLoose_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepDataEffTrigLooseTight_EL_EFF_Trigger_UP", &lepDataEffTrigLooseTight_EL_EFF_Trigger_UP, &b_lepDataEffTrigLooseTight_EL_EFF_Trigger_UP);
      tree->SetBranchAddress("lepSFTrigLoose_EL_EFF_Trigger_DOWN", &lepSFTrigLoose_EL_EFF_Trigger_DOWN, &b_lepSFTrigLoose_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigTight_EL_EFF_Trigger_DOWN", &lepSFTrigTight_EL_EFF_Trigger_DOWN, &b_lepSFTrigTight_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigTightLoose_EL_EFF_Trigger_DOWN", &lepSFTrigTightLoose_EL_EFF_Trigger_DOWN, &b_lepSFTrigTightLoose_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFTrigLooseTight_EL_EFF_Trigger_DOWN", &lepSFTrigLooseTight_EL_EFF_Trigger_DOWN, &b_lepSFTrigLooseTight_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigLoose_EL_EFF_Trigger_DOWN", &lepEffTrigLoose_EL_EFF_Trigger_DOWN, &b_lepEffTrigLoose_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigTight_EL_EFF_Trigger_DOWN", &lepEffTrigTight_EL_EFF_Trigger_DOWN, &b_lepEffTrigTight_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigTightLoose_EL_EFF_Trigger_DOWN", &lepEffTrigTightLoose_EL_EFF_Trigger_DOWN, &b_lepEffTrigTightLoose_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepEffTrigLooseTight_EL_EFF_Trigger_DOWN", &lepEffTrigLooseTight_EL_EFF_Trigger_DOWN, &b_lepEffTrigLooseTight_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigLoose_EL_EFF_Trigger_DOWN", &lepDataEffTrigLoose_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigLoose_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigTight_EL_EFF_Trigger_DOWN", &lepDataEffTrigTight_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigTight_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN", &lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigTightLoose_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN", &lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN, &b_lepDataEffTrigLooseTight_EL_EFF_Trigger_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_EL_SF_Reco_UP", &lepSFObjLoose_EL_SF_Reco_UP, &b_lepSFObjLoose_EL_SF_Reco_UP);
      tree->SetBranchAddress("lepSFObjTight_EL_SF_Reco_UP", &lepSFObjTight_EL_SF_Reco_UP, &b_lepSFObjTight_EL_SF_Reco_UP);
      tree->SetBranchAddress("lepSFObjLoose_EL_SF_Reco_DOWN", &lepSFObjLoose_EL_SF_Reco_DOWN, &b_lepSFObjLoose_EL_SF_Reco_DOWN);
      tree->SetBranchAddress("lepSFObjTight_EL_SF_Reco_DOWN", &lepSFObjTight_EL_SF_Reco_DOWN, &b_lepSFObjTight_EL_SF_Reco_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_EL_SF_ID_UP", &lepSFObjLoose_EL_SF_ID_UP, &b_lepSFObjLoose_EL_SF_ID_UP);
      tree->SetBranchAddress("lepSFObjTight_EL_SF_ID_UP", &lepSFObjTight_EL_SF_ID_UP, &b_lepSFObjTight_EL_SF_ID_UP);
      tree->SetBranchAddress("lepSFObjLoose_EL_SF_ID_DOWN", &lepSFObjLoose_EL_SF_ID_DOWN, &b_lepSFObjLoose_EL_SF_ID_DOWN);
      tree->SetBranchAddress("lepSFObjTight_EL_SF_ID_DOWN", &lepSFObjTight_EL_SF_ID_DOWN, &b_lepSFObjTight_EL_SF_ID_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_EL_SF_Isol_UP", &lepSFObjLoose_EL_SF_Isol_UP, &b_lepSFObjLoose_EL_SF_Isol_UP);
      tree->SetBranchAddress("lepSFObjTight_EL_SF_Isol_UP", &lepSFObjTight_EL_SF_Isol_UP, &b_lepSFObjTight_EL_SF_Isol_UP);
      tree->SetBranchAddress("lepSFObjLoose_EL_SF_Isol_DOWN", &lepSFObjLoose_EL_SF_Isol_DOWN, &b_lepSFObjLoose_EL_SF_Isol_DOWN);
      tree->SetBranchAddress("lepSFObjTight_EL_SF_Isol_DOWN", &lepSFObjTight_EL_SF_Isol_DOWN, &b_lepSFObjTight_EL_SF_Isol_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_UP", &lepSFObjLoose_MU_SF_ID_STAT_UP, &b_lepSFObjLoose_MU_SF_ID_STAT_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_UP", &lepSFObjTight_MU_SF_ID_STAT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_DOWN", &lepSFObjLoose_MU_SF_ID_STAT_DOWN, &b_lepSFObjLoose_MU_SF_ID_STAT_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_UP", &lepSFObjLoose_MU_SF_ID_SYST_UP, &b_lepSFObjLoose_MU_SF_ID_SYST_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_UP", &lepSFObjTight_MU_SF_ID_SYST_UP, &b_lepSFObjTight_MU_SF_ID_SYST_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_DOWN", &lepSFObjLoose_MU_SF_ID_SYST_DOWN, &b_lepSFObjLoose_MU_SF_ID_SYST_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_DOWN", &lepSFObjTight_MU_SF_ID_SYST_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_UP", &lepSFObjLoose_MU_SF_Isol_STAT_UP, &b_lepSFObjLoose_MU_SF_Isol_STAT_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_UP", &lepSFObjTight_MU_SF_Isol_STAT_UP, &b_lepSFObjTight_MU_SF_Isol_STAT_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_DOWN", &lepSFObjLoose_MU_SF_Isol_STAT_DOWN, &b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_DOWN", &lepSFObjTight_MU_SF_Isol_STAT_DOWN, &b_lepSFObjTight_MU_SF_Isol_STAT_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_SYST_UP", &lepSFObjLoose_MU_SF_Isol_SYST_UP, &b_lepSFObjLoose_MU_SF_Isol_SYST_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_UP", &lepSFObjTight_MU_SF_Isol_SYST_UP, &b_lepSFObjTight_MU_SF_Isol_SYST_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_SYST_DOWN", &lepSFObjLoose_MU_SF_Isol_SYST_DOWN, &b_lepSFObjLoose_MU_SF_Isol_SYST_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_DOWN", &lepSFObjTight_MU_SF_Isol_SYST_DOWN, &b_lepSFObjTight_MU_SF_Isol_SYST_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_STAT_UP", &lepSFObjLoose_MU_SF_TTVA_STAT_UP, &b_lepSFObjLoose_MU_SF_TTVA_STAT_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_UP", &lepSFObjTight_MU_SF_TTVA_STAT_UP, &b_lepSFObjTight_MU_SF_TTVA_STAT_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_STAT_DOWN", &lepSFObjLoose_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjLoose_MU_SF_TTVA_STAT_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_DOWN", &lepSFObjTight_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_SYST_UP", &lepSFObjLoose_MU_SF_TTVA_SYST_UP, &b_lepSFObjLoose_MU_SF_TTVA_SYST_UP);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_UP", &lepSFObjTight_MU_SF_TTVA_SYST_UP, &b_lepSFObjTight_MU_SF_TTVA_SYST_UP);
      tree->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_SYST_DOWN", &lepSFObjLoose_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjLoose_MU_SF_TTVA_SYST_DOWN);
      tree->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_DOWN", &lepSFObjTight_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN);
      tree->SetBranchAddress("tauSFTight_TAU_SF_ELEOLR_TOTAL_UP", &tauSFTight_TAU_SF_ELEOLR_TOTAL_UP, &b_tauSFTight_TAU_SF_ELEOLR_TOTAL_UP);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP", &tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP, &b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_UP);
      tree->SetBranchAddress("tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN", &tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN, &b_tauSFTight_TAU_SF_ELEOLR_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN", &tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_ELEOLR_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP", &tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP, &b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP", &tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP, &b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP);
      tree->SetBranchAddress("tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN", &tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN, &b_tauSFTight_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN", &tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFTight_TAU_SF_JETID_TOTAL_UP", &tauSFTight_TAU_SF_JETID_TOTAL_UP, &b_tauSFTight_TAU_SF_JETID_TOTAL_UP);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_JETID_TOTAL_UP", &tauSFLoose_TAU_SF_JETID_TOTAL_UP, &b_tauSFLoose_TAU_SF_JETID_TOTAL_UP);
      tree->SetBranchAddress("tauSFTight_TAU_SF_JETID_TOTAL_DOWN", &tauSFTight_TAU_SF_JETID_TOTAL_DOWN, &b_tauSFTight_TAU_SF_JETID_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_JETID_TOTAL_DOWN", &tauSFLoose_TAU_SF_JETID_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_JETID_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFTight_TAU_SF_JETID_HIGHPT_UP", &tauSFTight_TAU_SF_JETID_HIGHPT_UP, &b_tauSFTight_TAU_SF_JETID_HIGHPT_UP);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_JETID_HIGHPT_UP", &tauSFLoose_TAU_SF_JETID_HIGHPT_UP, &b_tauSFLoose_TAU_SF_JETID_HIGHPT_UP);
      tree->SetBranchAddress("tauSFTight_TAU_SF_JETID_HIGHPT_DOWN", &tauSFTight_TAU_SF_JETID_HIGHPT_DOWN, &b_tauSFTight_TAU_SF_JETID_HIGHPT_DOWN);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN", &tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN, &b_tauSFLoose_TAU_SF_JETID_HIGHPT_DOWN);
      tree->SetBranchAddress("tauSFTight_TAU_SF_RECO_TOTAL_UP", &tauSFTight_TAU_SF_RECO_TOTAL_UP, &b_tauSFTight_TAU_SF_RECO_TOTAL_UP);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_RECO_TOTAL_UP", &tauSFLoose_TAU_SF_RECO_TOTAL_UP, &b_tauSFLoose_TAU_SF_RECO_TOTAL_UP);
      tree->SetBranchAddress("tauSFTight_TAU_SF_RECO_TOTAL_DOWN", &tauSFTight_TAU_SF_RECO_TOTAL_DOWN, &b_tauSFTight_TAU_SF_RECO_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_RECO_TOTAL_DOWN", &tauSFLoose_TAU_SF_RECO_TOTAL_DOWN, &b_tauSFLoose_TAU_SF_RECO_TOTAL_DOWN);
      tree->SetBranchAddress("tauSFTight_TAU_SF_RECO_HIGHPT_UP", &tauSFTight_TAU_SF_RECO_HIGHPT_UP, &b_tauSFTight_TAU_SF_RECO_HIGHPT_UP);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_RECO_HIGHPT_UP", &tauSFLoose_TAU_SF_RECO_HIGHPT_UP, &b_tauSFLoose_TAU_SF_RECO_HIGHPT_UP);
      tree->SetBranchAddress("tauSFTight_TAU_SF_RECO_HIGHPT_DOWN", &tauSFTight_TAU_SF_RECO_HIGHPT_DOWN, &b_tauSFTight_TAU_SF_RECO_HIGHPT_DOWN);
      tree->SetBranchAddress("tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN", &tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN, &b_tauSFLoose_TAU_SF_RECO_HIGHPT_DOWN);
   }
   tree->SetBranchAddress("mc_norm", &mc_norm, &b_mc_norm);
   tree->SetBranchAddress("l2tau_bdt", &l2tau_bdt, &b_l2tau_bdt);
   tree->SetBranchAddress("tau_leadpt", &tau_leadpt, &b_tau_leadpt);
   tree->SetBranchAddress("tau_subpt", &tau_subpt, &b_tau_subpt);
   tree->SetBranchAddress("tau_btag70_0", &tau_btag70_0, &b_tau_btag70_0);
   tree->SetBranchAddress("tau_tight_0", &tau_tight_0, &b_tau_tight_0);
   tree->SetBranchAddress("tau_truth_0", &tau_truth_0, &b_tau_truth_0);
   tree->SetBranchAddress("tau_btag70_1", &tau_btag70_1, &b_tau_btag70_1);
   tree->SetBranchAddress("tau_tight_1", &tau_tight_1, &b_tau_tight_1);
   tree->SetBranchAddress("tau_truth_1", &tau_truth_1, &b_tau_truth_1);
   tree->SetBranchAddress("l2tau_htjets", &l2tau_htjets, &b_l2tau_htjets);
   tree->SetBranchAddress("l2tau_jjdr", &l2tau_jjdr, &b_l2tau_jjdr);
   tree->SetBranchAddress("l2tau_mtautau", &l2tau_mtautau, &b_l2tau_mtautau);
   tree->SetBranchAddress("Channel", &Channel, &b_Channel);
   tree->SetBranchAddress("Drhwwvis", &Drhwwvis, &b_Drhwwvis);
   tree->SetBranchAddress("Mtwbvis", &Mtwbvis, &b_Mtwbvis);
   tree->SetBranchAddress("Mhwwvis", &Mhwwvis, &b_Mhwwvis);
   tree->SetBranchAddress("Mhwwqvis", &Mhwwqvis, &b_Mhwwqvis);
   tree->SetBranchAddress("Msum", &Msum, &b_Msum);
   tree->SetBranchAddress("Pthwl0", &Pthwl0, &b_Pthwl0);
   tree->SetBranchAddress("Ptlep", &Ptlep, &b_Ptlep);
   tree->SetBranchAddress("Pthwj", &Pthwj, &b_Pthwj);
   tree->SetBranchAddress("Ptqj", &Ptqj, &b_Ptqj);
   tree->SetBranchAddress("Ptbj", &Ptbj, &b_Ptbj);
   tree->SetBranchAddress("Chisqmin", &Chisqmin, &b_Chisqmin);
   tree->SetBranchAddress("Chisqmax", &Chisqmax, &b_Chisqmax);
   tree->SetBranchAddress("Lepwiso", &Lepwiso, &b_Lepwiso);
   tree->SetBranchAddress("Lepiso", &Lepiso, &b_Lepiso);
   tree->SetBranchAddress("Bdt", &Bdt, &b_Bdt);
   tree->SetBranchAddress("BdtvsttV", &BdtvsttV, &b_BdtvsttV);
}