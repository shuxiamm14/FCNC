#include "nominal.h"
class tthmltree : public nominal{
public:
   bool SelectTLepid(int id);
   void definetree(TTree *tree);
   virtual void     Init(TTree *tree);
   void Loop(TTree *inputtree, TString samplename);
   void dumpTruth(int ipart);
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   UInt_t          hasBadMuon;
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
