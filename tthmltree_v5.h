//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  3 05:01:25 2020 by ROOT version 6.20/06
// from TTree nominal/tree
// found on file: /global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimttV5/MytthAnaSkim_364290_FS_mc16e_ttWML_v05.root
//////////////////////////////////////////////////////////

#ifndef tthmltree_v5_h
#define tthmltree_v5_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class tthmltree_v5 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         weight_mc;
   Float_t         weight_pileup;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   Float_t         mu_actual;
   UInt_t          backgroundFlags;
   UInt_t          hasBadMuon;
   Float_t         met_met;
   Float_t         met_phi;
   Int_t           triggers;
   Int_t           loose;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_2e24_lhvloose_nod0;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu22_mu8noL1;
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
   Int_t           nJets_OR;
   Int_t           nJets_OR_TauOR;
   Int_t           nFwdJets_OR;
   Int_t           nFwdJets_OR_TauOR;
   Int_t           nTruthJets_OR;
   Int_t           nJets_OR_DL1r_85;
   Int_t           nJets_OR_DL1r_60;
   Int_t           nJets_OR_DL1r_77;
   Int_t           nJets_OR_DL1r_70;
   Int_t           nFwdJets_OR_DL1r_85;
   Int_t           nFwdJets_OR_DL1r_60;
   Int_t           nFwdJets_OR_DL1r_77;
   Int_t           nFwdJets_OR_DL1r_70;
   Int_t           nJets_OR_DL1_85;
   Int_t           nJets_OR_DL1_60;
   Int_t           nJets_OR_DL1_77;
   Int_t           nJets_OR_DL1_70;
   Int_t           nTaus_OR_Pt25;
   Int_t           nTaus_OR;
   Int_t           nTaus_OR_Medium;
   Int_t           nTaus_OR_Tight;
   Bool_t          isBlinded;
   Float_t         HT;
   Float_t         HT_lep;
   Float_t         HT_jets;
   Int_t           RunYear;
   Double_t        mc_xSection;
   vector<float>   *mc_genWeights;
   Float_t         lep_ID_0;
   Int_t           lep_Index_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_EtaBE2_0;
   Float_t         lep_Phi_0;
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
   Char_t          lep_isolationFCTight_0;
   Int_t           lep_isolationLoose_0;
   Int_t           lep_isolationGradient_0;
   Int_t           lep_isolationGradientLoose_0;
   Int_t           lep_isolationTightTrackOnly_0;
   Char_t          lep_isolationFCLoose_0;
   Int_t           lep_isolationPflowTight_0;
   Int_t           lep_isolationPflowLoose_0;
   Int_t           lep_plvWP_Loose_0;
   Int_t           lep_plvWP_Tight_0;
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
   Int_t           lep_nTrackParticles_0;
   Float_t         lep_Mtrktrk_atPV_CO_0;
   Float_t         lep_Mtrktrk_atConvV_CO_0;
   Float_t         lep_RadiusCO_0;
   Float_t         lep_RadiusCOX_0;
   Float_t         lep_RadiusCOY_0;
   Float_t         lep_SeparationMinDCT_0;
   Float_t         lep_ClosestSiTracknIL_0;
   Float_t         lep_ClosestSiTrackeIL_0;
   Float_t         lep_ClosestSiTracknNIL_0;
   Float_t         lep_ClosestSiTrackeNIL_0;
   Float_t         lep_BestMatchTrackPt_0;
   Float_t         lep_BestMatchTrackEta_0;
   Float_t         lep_BestMatchTrackPhi_0;
   Float_t         lep_BestMatchTrackD0_0;
   Float_t         lep_BestMatchTrackZ0_0;
   Float_t         lep_BestMatchTrackQ_0;
   Float_t         lep_ClosestSiTrackPt_0;
   Float_t         lep_ClosestSiTrackEta_0;
   Float_t         lep_ClosestSiTrackPhi_0;
   Float_t         lep_ClosestSiTrackD0_0;
   Float_t         lep_ClosestSiTrackZ0_0;
   Float_t         lep_ClosestSiTrackQ_0;
   Float_t         lep_DFCommonSimpleConvRadius_0;
   Float_t         lep_DFCommonSimpleConvPhi_0;
   Float_t         lep_DFCommonSimpleMee_0;
   Float_t         lep_DFCommonSimpleMeeAtVtx_0;
   Float_t         lep_DFCommonSimpleSeparation_0;
   Int_t           lep_DFCommonAddAmbiguity_0;
   Float_t         lep_DFCommonProdTrueRadius_0;
   Float_t         lep_DFCommonProdTruePhi_0;
   Float_t         lep_DFCommonProdTrueZ_0;
   Char_t          lep_chargeIDBDTLoose_0;
   Double_t        lep_chargeIDBDTResult_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_0;
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
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_0;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_0;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_0;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_0;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_0;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_0;
   Float_t         lep_PromptLeptonRNN_prompt_0;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_0;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_0;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_0;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0;
   Float_t         lep_jet_Pt_0;
   Float_t         lep_jet_nTrk_0;
   Float_t         lep_jet_sumPtTrk_0;
   Float_t         lep_jet_mv2c10_0;
   Float_t         lep_jet_deltaR_0;
   Float_t         lep_jet_ptRel_0;
   Float_t         lep_jet_ptOverMuPt_0;
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
   Int_t           lep_nInnerPix_0;
   Int_t           lep_firstEgMotherPdgId_0;
   Int_t           lep_firstEgMotherTruthType_0;
   Int_t           lep_firstEgMotherTruthOrigin_0;
   Int_t           lep_lastEgMotherPdgId_0;
   Int_t           lep_lastEgMotherTruthType_0;
   Int_t           lep_lastEgMotherTruthOrigin_0;
   Float_t         lep_SF_El_Reco_AT_0;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_0;
   Float_t         lep_SF_El_ID_TightLH_AT_0;
   Float_t         lep_SF_El_Iso_FCLoose_AT_0;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_0;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_0;
   Float_t         lep_SF_El_PLVTight_QmisID_0;
   Float_t         lep_SF_El_PLVTight_0;
   Float_t         lep_SF_El_PLVLoose_0;
   Float_t         lep_SF_El_ID_MediumLH_0;
   Float_t         lep_SF_Mu_TTVA_AT_0;
   Float_t         lep_SF_Mu_ID_Loose_AT_0;
   Float_t         lep_SF_Mu_ID_Medium_AT_0;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_0;
   Float_t         lep_SF_Mu_ID_Tight_0;
   Float_t         lep_SF_Mu_PLVTight_0;
   Float_t         lep_SF_Mu_PLVLoose_0;
   Float_t         lep_SF_CombinedLoose_0;
   Float_t         lep_SF_CombinedTight_0;
   Float_t         lep_ID_1;
   Int_t           lep_Index_1;
   Float_t         lep_Pt_1;
   Float_t         lep_E_1;
   Float_t         lep_Eta_1;
   Float_t         lep_EtaBE2_1;
   Float_t         lep_Phi_1;
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
   Char_t          lep_isolationFCTight_1;
   Int_t           lep_isolationLoose_1;
   Int_t           lep_isolationGradient_1;
   Int_t           lep_isolationGradientLoose_1;
   Int_t           lep_isolationTightTrackOnly_1;
   Char_t          lep_isolationFCLoose_1;
   Int_t           lep_isolationPflowTight_1;
   Int_t           lep_isolationPflowLoose_1;
   Int_t           lep_plvWP_Loose_1;
   Int_t           lep_plvWP_Tight_1;
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
   Int_t           lep_nTrackParticles_1;
   Float_t         lep_Mtrktrk_atPV_CO_1;
   Float_t         lep_Mtrktrk_atConvV_CO_1;
   Float_t         lep_RadiusCO_1;
   Float_t         lep_RadiusCOX_1;
   Float_t         lep_RadiusCOY_1;
   Float_t         lep_SeparationMinDCT_1;
   Float_t         lep_ClosestSiTracknIL_1;
   Float_t         lep_ClosestSiTrackeIL_1;
   Float_t         lep_ClosestSiTracknNIL_1;
   Float_t         lep_ClosestSiTrackeNIL_1;
   Float_t         lep_BestMatchTrackPt_1;
   Float_t         lep_BestMatchTrackEta_1;
   Float_t         lep_BestMatchTrackPhi_1;
   Float_t         lep_BestMatchTrackD0_1;
   Float_t         lep_BestMatchTrackZ0_1;
   Float_t         lep_BestMatchTrackQ_1;
   Float_t         lep_ClosestSiTrackPt_1;
   Float_t         lep_ClosestSiTrackEta_1;
   Float_t         lep_ClosestSiTrackPhi_1;
   Float_t         lep_ClosestSiTrackD0_1;
   Float_t         lep_ClosestSiTrackZ0_1;
   Float_t         lep_ClosestSiTrackQ_1;
   Float_t         lep_DFCommonSimpleConvRadius_1;
   Float_t         lep_DFCommonSimpleConvPhi_1;
   Float_t         lep_DFCommonSimpleMee_1;
   Float_t         lep_DFCommonSimpleMeeAtVtx_1;
   Float_t         lep_DFCommonSimpleSeparation_1;
   Int_t           lep_DFCommonAddAmbiguity_1;
   Float_t         lep_DFCommonProdTrueRadius_1;
   Float_t         lep_DFCommonProdTruePhi_1;
   Float_t         lep_DFCommonProdTrueZ_1;
   Char_t          lep_chargeIDBDTLoose_1;
   Double_t        lep_chargeIDBDTResult_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_1;
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
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_1;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_1;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_1;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_1;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_1;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_1;
   Float_t         lep_PromptLeptonRNN_prompt_1;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_1;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_1;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_1;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1;
   Float_t         lep_jet_Pt_1;
   Float_t         lep_jet_nTrk_1;
   Float_t         lep_jet_sumPtTrk_1;
   Float_t         lep_jet_mv2c10_1;
   Float_t         lep_jet_deltaR_1;
   Float_t         lep_jet_ptRel_1;
   Float_t         lep_jet_ptOverMuPt_1;
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
   Int_t           lep_nInnerPix_1;
   Int_t           lep_firstEgMotherPdgId_1;
   Int_t           lep_firstEgMotherTruthType_1;
   Int_t           lep_firstEgMotherTruthOrigin_1;
   Int_t           lep_lastEgMotherPdgId_1;
   Int_t           lep_lastEgMotherTruthType_1;
   Int_t           lep_lastEgMotherTruthOrigin_1;
   Float_t         lep_SF_El_Reco_AT_1;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_1;
   Float_t         lep_SF_El_ID_TightLH_AT_1;
   Float_t         lep_SF_El_Iso_FCLoose_AT_1;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_1;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_1;
   Float_t         lep_SF_El_PLVTight_QmisID_1;
   Float_t         lep_SF_El_PLVTight_1;
   Float_t         lep_SF_El_PLVLoose_1;
   Float_t         lep_SF_El_ID_MediumLH_1;
   Float_t         lep_SF_Mu_TTVA_AT_1;
   Float_t         lep_SF_Mu_ID_Loose_AT_1;
   Float_t         lep_SF_Mu_ID_Medium_AT_1;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_1;
   Float_t         lep_SF_Mu_ID_Tight_1;
   Float_t         lep_SF_Mu_PLVTight_1;
   Float_t         lep_SF_Mu_PLVLoose_1;
   Float_t         lep_SF_CombinedLoose_1;
   Float_t         lep_SF_CombinedTight_1;
   Float_t         lep_ID_2;
   Int_t           lep_Index_2;
   Float_t         lep_Pt_2;
   Float_t         lep_E_2;
   Float_t         lep_Eta_2;
   Float_t         lep_EtaBE2_2;
   Float_t         lep_Phi_2;
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
   Char_t          lep_isolationFCTight_2;
   Int_t           lep_isolationLoose_2;
   Int_t           lep_isolationGradient_2;
   Int_t           lep_isolationGradientLoose_2;
   Int_t           lep_isolationTightTrackOnly_2;
   Char_t          lep_isolationFCLoose_2;
   Int_t           lep_isolationPflowTight_2;
   Int_t           lep_isolationPflowLoose_2;
   Int_t           lep_plvWP_Loose_2;
   Int_t           lep_plvWP_Tight_2;
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
   Int_t           lep_nTrackParticles_2;
   Float_t         lep_Mtrktrk_atPV_CO_2;
   Float_t         lep_Mtrktrk_atConvV_CO_2;
   Float_t         lep_RadiusCO_2;
   Float_t         lep_RadiusCOX_2;
   Float_t         lep_RadiusCOY_2;
   Float_t         lep_SeparationMinDCT_2;
   Float_t         lep_ClosestSiTracknIL_2;
   Float_t         lep_ClosestSiTrackeIL_2;
   Float_t         lep_ClosestSiTracknNIL_2;
   Float_t         lep_ClosestSiTrackeNIL_2;
   Float_t         lep_BestMatchTrackPt_2;
   Float_t         lep_BestMatchTrackEta_2;
   Float_t         lep_BestMatchTrackPhi_2;
   Float_t         lep_BestMatchTrackD0_2;
   Float_t         lep_BestMatchTrackZ0_2;
   Float_t         lep_BestMatchTrackQ_2;
   Float_t         lep_ClosestSiTrackPt_2;
   Float_t         lep_ClosestSiTrackEta_2;
   Float_t         lep_ClosestSiTrackPhi_2;
   Float_t         lep_ClosestSiTrackD0_2;
   Float_t         lep_ClosestSiTrackZ0_2;
   Float_t         lep_ClosestSiTrackQ_2;
   Float_t         lep_DFCommonSimpleConvRadius_2;
   Float_t         lep_DFCommonSimpleConvPhi_2;
   Float_t         lep_DFCommonSimpleMee_2;
   Float_t         lep_DFCommonSimpleMeeAtVtx_2;
   Float_t         lep_DFCommonSimpleSeparation_2;
   Int_t           lep_DFCommonAddAmbiguity_2;
   Float_t         lep_DFCommonProdTrueRadius_2;
   Float_t         lep_DFCommonProdTruePhi_2;
   Float_t         lep_DFCommonProdTrueZ_2;
   Char_t          lep_chargeIDBDTLoose_2;
   Double_t        lep_chargeIDBDTResult_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_2;
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
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_2;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_2;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_2;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_2;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_2;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_2;
   Float_t         lep_PromptLeptonRNN_prompt_2;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_2;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_2;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_2;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2;
   Float_t         lep_jet_Pt_2;
   Float_t         lep_jet_nTrk_2;
   Float_t         lep_jet_sumPtTrk_2;
   Float_t         lep_jet_mv2c10_2;
   Float_t         lep_jet_deltaR_2;
   Float_t         lep_jet_ptRel_2;
   Float_t         lep_jet_ptOverMuPt_2;
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
   Int_t           lep_nInnerPix_2;
   Int_t           lep_firstEgMotherPdgId_2;
   Int_t           lep_firstEgMotherTruthType_2;
   Int_t           lep_firstEgMotherTruthOrigin_2;
   Int_t           lep_lastEgMotherPdgId_2;
   Int_t           lep_lastEgMotherTruthType_2;
   Int_t           lep_lastEgMotherTruthOrigin_2;
   Float_t         lep_SF_El_Reco_AT_2;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_2;
   Float_t         lep_SF_El_ID_TightLH_AT_2;
   Float_t         lep_SF_El_Iso_FCLoose_AT_2;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_2;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_2;
   Float_t         lep_SF_El_PLVTight_QmisID_2;
   Float_t         lep_SF_El_PLVTight_2;
   Float_t         lep_SF_El_PLVLoose_2;
   Float_t         lep_SF_El_ID_MediumLH_2;
   Float_t         lep_SF_Mu_TTVA_AT_2;
   Float_t         lep_SF_Mu_ID_Loose_AT_2;
   Float_t         lep_SF_Mu_ID_Medium_AT_2;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_2;
   Float_t         lep_SF_Mu_ID_Tight_2;
   Float_t         lep_SF_Mu_PLVTight_2;
   Float_t         lep_SF_Mu_PLVLoose_2;
   Float_t         lep_SF_CombinedLoose_2;
   Float_t         lep_SF_CombinedTight_2;
   Float_t         lep_ID_3;
   Int_t           lep_Index_3;
   Float_t         lep_Pt_3;
   Float_t         lep_E_3;
   Float_t         lep_Eta_3;
   Float_t         lep_EtaBE2_3;
   Float_t         lep_Phi_3;
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
   Char_t          lep_isolationFCTight_3;
   Int_t           lep_isolationLoose_3;
   Int_t           lep_isolationGradient_3;
   Int_t           lep_isolationGradientLoose_3;
   Int_t           lep_isolationTightTrackOnly_3;
   Char_t          lep_isolationFCLoose_3;
   Int_t           lep_isolationPflowTight_3;
   Int_t           lep_isolationPflowLoose_3;
   Int_t           lep_plvWP_Loose_3;
   Int_t           lep_plvWP_Tight_3;
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
   Int_t           lep_nTrackParticles_3;
   Float_t         lep_Mtrktrk_atPV_CO_3;
   Float_t         lep_Mtrktrk_atConvV_CO_3;
   Float_t         lep_RadiusCO_3;
   Float_t         lep_RadiusCOX_3;
   Float_t         lep_RadiusCOY_3;
   Float_t         lep_SeparationMinDCT_3;
   Float_t         lep_ClosestSiTracknIL_3;
   Float_t         lep_ClosestSiTrackeIL_3;
   Float_t         lep_ClosestSiTracknNIL_3;
   Float_t         lep_ClosestSiTrackeNIL_3;
   Float_t         lep_BestMatchTrackPt_3;
   Float_t         lep_BestMatchTrackEta_3;
   Float_t         lep_BestMatchTrackPhi_3;
   Float_t         lep_BestMatchTrackD0_3;
   Float_t         lep_BestMatchTrackZ0_3;
   Float_t         lep_BestMatchTrackQ_3;
   Float_t         lep_ClosestSiTrackPt_3;
   Float_t         lep_ClosestSiTrackEta_3;
   Float_t         lep_ClosestSiTrackPhi_3;
   Float_t         lep_ClosestSiTrackD0_3;
   Float_t         lep_ClosestSiTrackZ0_3;
   Float_t         lep_ClosestSiTrackQ_3;
   Float_t         lep_DFCommonSimpleConvRadius_3;
   Float_t         lep_DFCommonSimpleConvPhi_3;
   Float_t         lep_DFCommonSimpleMee_3;
   Float_t         lep_DFCommonSimpleMeeAtVtx_3;
   Float_t         lep_DFCommonSimpleSeparation_3;
   Int_t           lep_DFCommonAddAmbiguity_3;
   Float_t         lep_DFCommonProdTrueRadius_3;
   Float_t         lep_DFCommonProdTruePhi_3;
   Float_t         lep_DFCommonProdTrueZ_3;
   Char_t          lep_chargeIDBDTLoose_3;
   Double_t        lep_chargeIDBDTResult_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_3;
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
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_3;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_3;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_3;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_3;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_3;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_3;
   Float_t         lep_PromptLeptonRNN_prompt_3;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_3;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_3;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_3;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_3;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_3;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_3;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_3;
   Float_t         lep_jet_Pt_3;
   Float_t         lep_jet_nTrk_3;
   Float_t         lep_jet_sumPtTrk_3;
   Float_t         lep_jet_mv2c10_3;
   Float_t         lep_jet_deltaR_3;
   Float_t         lep_jet_ptRel_3;
   Float_t         lep_jet_ptOverMuPt_3;
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
   Int_t           lep_nInnerPix_3;
   Int_t           lep_firstEgMotherPdgId_3;
   Int_t           lep_firstEgMotherTruthType_3;
   Int_t           lep_firstEgMotherTruthOrigin_3;
   Int_t           lep_lastEgMotherPdgId_3;
   Int_t           lep_lastEgMotherTruthType_3;
   Int_t           lep_lastEgMotherTruthOrigin_3;
   Float_t         lep_SF_El_Reco_AT_3;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_3;
   Float_t         lep_SF_El_ID_TightLH_AT_3;
   Float_t         lep_SF_El_Iso_FCLoose_AT_3;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_3;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_3;
   Float_t         lep_SF_El_PLVTight_QmisID_3;
   Float_t         lep_SF_El_PLVTight_3;
   Float_t         lep_SF_El_PLVLoose_3;
   Float_t         lep_SF_El_ID_MediumLH_3;
   Float_t         lep_SF_Mu_TTVA_AT_3;
   Float_t         lep_SF_Mu_ID_Loose_AT_3;
   Float_t         lep_SF_Mu_ID_Medium_AT_3;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_3;
   Float_t         lep_SF_Mu_ID_Tight_3;
   Float_t         lep_SF_Mu_PLVTight_3;
   Float_t         lep_SF_Mu_PLVLoose_3;
   Float_t         lep_SF_CombinedLoose_3;
   Float_t         lep_SF_CombinedTight_3;
   Float_t         lep_ID_4;
   Int_t           lep_Index_4;
   Float_t         lep_Pt_4;
   Float_t         lep_E_4;
   Float_t         lep_Eta_4;
   Float_t         lep_EtaBE2_4;
   Float_t         lep_Phi_4;
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
   Char_t          lep_isolationFCTight_4;
   Int_t           lep_isolationLoose_4;
   Int_t           lep_isolationGradient_4;
   Int_t           lep_isolationGradientLoose_4;
   Int_t           lep_isolationTightTrackOnly_4;
   Char_t          lep_isolationFCLoose_4;
   Int_t           lep_isolationPflowTight_4;
   Int_t           lep_isolationPflowLoose_4;
   Int_t           lep_plvWP_Loose_4;
   Int_t           lep_plvWP_Tight_4;
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
   Int_t           lep_nTrackParticles_4;
   Float_t         lep_Mtrktrk_atPV_CO_4;
   Float_t         lep_Mtrktrk_atConvV_CO_4;
   Float_t         lep_RadiusCO_4;
   Float_t         lep_RadiusCOX_4;
   Float_t         lep_RadiusCOY_4;
   Float_t         lep_SeparationMinDCT_4;
   Float_t         lep_ClosestSiTracknIL_4;
   Float_t         lep_ClosestSiTrackeIL_4;
   Float_t         lep_ClosestSiTracknNIL_4;
   Float_t         lep_ClosestSiTrackeNIL_4;
   Float_t         lep_BestMatchTrackPt_4;
   Float_t         lep_BestMatchTrackEta_4;
   Float_t         lep_BestMatchTrackPhi_4;
   Float_t         lep_BestMatchTrackD0_4;
   Float_t         lep_BestMatchTrackZ0_4;
   Float_t         lep_BestMatchTrackQ_4;
   Float_t         lep_ClosestSiTrackPt_4;
   Float_t         lep_ClosestSiTrackEta_4;
   Float_t         lep_ClosestSiTrackPhi_4;
   Float_t         lep_ClosestSiTrackD0_4;
   Float_t         lep_ClosestSiTrackZ0_4;
   Float_t         lep_ClosestSiTrackQ_4;
   Float_t         lep_DFCommonSimpleConvRadius_4;
   Float_t         lep_DFCommonSimpleConvPhi_4;
   Float_t         lep_DFCommonSimpleMee_4;
   Float_t         lep_DFCommonSimpleMeeAtVtx_4;
   Float_t         lep_DFCommonSimpleSeparation_4;
   Int_t           lep_DFCommonAddAmbiguity_4;
   Float_t         lep_DFCommonProdTrueRadius_4;
   Float_t         lep_DFCommonProdTruePhi_4;
   Float_t         lep_DFCommonProdTrueZ_4;
   Char_t          lep_chargeIDBDTLoose_4;
   Double_t        lep_chargeIDBDTResult_4;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_4;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_4;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_4;
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
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_4;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_4;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_4;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_4;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_4;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_4;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_4;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_4;
   Float_t         lep_PromptLeptonRNN_prompt_4;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_4;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_4;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_4;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_4;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_4;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_4;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_4;
   Float_t         lep_jet_Pt_4;
   Float_t         lep_jet_nTrk_4;
   Float_t         lep_jet_sumPtTrk_4;
   Float_t         lep_jet_mv2c10_4;
   Float_t         lep_jet_deltaR_4;
   Float_t         lep_jet_ptRel_4;
   Float_t         lep_jet_ptOverMuPt_4;
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
   Int_t           lep_nInnerPix_4;
   Int_t           lep_firstEgMotherPdgId_4;
   Int_t           lep_firstEgMotherTruthType_4;
   Int_t           lep_firstEgMotherTruthOrigin_4;
   Int_t           lep_lastEgMotherPdgId_4;
   Int_t           lep_lastEgMotherTruthType_4;
   Int_t           lep_lastEgMotherTruthOrigin_4;
   Float_t         lep_SF_El_Reco_AT_4;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_4;
   Float_t         lep_SF_El_ID_TightLH_AT_4;
   Float_t         lep_SF_El_Iso_FCLoose_AT_4;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_4;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_4;
   Float_t         lep_SF_El_PLVTight_QmisID_4;
   Float_t         lep_SF_El_PLVTight_4;
   Float_t         lep_SF_El_PLVLoose_4;
   Float_t         lep_SF_El_ID_MediumLH_4;
   Float_t         lep_SF_Mu_TTVA_AT_4;
   Float_t         lep_SF_Mu_ID_Loose_AT_4;
   Float_t         lep_SF_Mu_ID_Medium_AT_4;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_4;
   Float_t         lep_SF_Mu_ID_Tight_4;
   Float_t         lep_SF_Mu_PLVTight_4;
   Float_t         lep_SF_Mu_PLVLoose_4;
   Float_t         lep_SF_CombinedLoose_4;
   Float_t         lep_SF_CombinedTight_4;
   Float_t         taus_pt_0;
   Float_t         taus_eta_0;
   Float_t         taus_phi_0;
   Float_t         taus_charge_0;
   Float_t         taus_E_0;
   Float_t         taus_width_0;
   Int_t           taus_decayMode_0;
   Double_t        taus_BDTJetScore_0;
   Double_t        taus_BDTJetScoreSigTrans_0;
   Int_t           taus_JetBDTSigLoose_0;
   Int_t           taus_JetBDTSigMedium_0;
   Int_t           taus_JetBDTSigTight_0;
   Double_t        taus_RNNJetScore_0;
   Double_t        taus_RNNJetScoreSigTrans_0;
   Int_t           taus_JetRNNSigLoose_0;
   Int_t           taus_JetRNNSigMedium_0;
   Int_t           taus_JetRNNSigTight_0;
   Int_t           taus_numTrack_0;
   Int_t           taus_isHadronic_0;
   Int_t           taus_tagWeightBin_0;
   Float_t         taus_MV2c10_0;
   Float_t         taus_DL1r_0;
   Float_t         taus_DL1_0;
   Char_t          taus_fromPV_0;
   Char_t          taus_passJVT_0;
   Int_t           taus_passEleOLR_0;
   Int_t           taus_passEleBDT_0;
   Int_t           taus_passMuonOLR_0;
   Int_t           taus_truthOrigin_0;
   Int_t           taus_truthType_0;
   Int_t           taus_truthJetFlavour_0;
   Float_t         taus_pt_1;
   Float_t         taus_eta_1;
   Float_t         taus_phi_1;
   Float_t         taus_charge_1;
   Float_t         taus_E_1;
   Float_t         taus_width_1;
   Int_t           taus_decayMode_1;
   Double_t        taus_BDTJetScore_1;
   Double_t        taus_BDTJetScoreSigTrans_1;
   Int_t           taus_JetBDTSigLoose_1;
   Int_t           taus_JetBDTSigMedium_1;
   Int_t           taus_JetBDTSigTight_1;
   Double_t        taus_RNNJetScore_1;
   Double_t        taus_RNNJetScoreSigTrans_1;
   Int_t           taus_JetRNNSigLoose_1;
   Int_t           taus_JetRNNSigMedium_1;
   Int_t           taus_JetRNNSigTight_1;
   Int_t           taus_numTrack_1;
   Int_t           taus_isHadronic_1;
   Int_t           taus_tagWeightBin_1;
   Float_t         taus_MV2c10_1;
   Float_t         taus_DL1r_1;
   Float_t         taus_DL1_1;
   Char_t          taus_fromPV_1;
   Char_t          taus_passJVT_1;
   Int_t           taus_passEleOLR_1;
   Int_t           taus_passEleBDT_1;
   Int_t           taus_passMuonOLR_1;
   Int_t           taus_truthOrigin_1;
   Int_t           taus_truthType_1;
   Int_t           taus_truthJetFlavour_1;
   vector<float>   *jets_pt;
   vector<float>   *jets_e;
   vector<float>   *jets_eta;
   vector<float>   *jets_phi;
   vector<char>    *jets_tauOR;
   vector<char>    *jets_fJVT;
   vector<float>   *jets_score_DL1r;
   vector<float>   *jets_score_DL1r_pu;
   vector<float>   *jets_score_DL1r_pc;
   vector<float>   *jets_score_DL1r_pb;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_60;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_70;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_77;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_85;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         lepSFObjChannelCombined;
   Float_t         jvtSF_customOR;
   Int_t           GlobalTrigMatch_AT_default_postOR;
   Int_t           GlobalTrigDecision;
   Float_t         custTrigSF_AT_default_preOR;
   Float_t         custTrigSF_AT_default_postOR;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_DLT;
   Int_t           custTrigMatch_LooseID_FCLooseIso_SLTorDLT;
   Int_t           custTrigMatch_LooseID_FCLooseIso_SLT;
   Int_t           custTrigMatch_LooseID_FCLooseIso_DLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT;
   Int_t           custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Int_t           custTrigMatch_TightElMediumMuID_FCLooseIso_SLT;
   Int_t           custTrigMatch_TightElMediumMuID_FCLooseIso_DLT;
   Char_t          GlobalTrigDecision_2e12_lhloose_L12EM10VH;
   Char_t          GlobalTrigDecision_2e17_lhvloose_nod0;
   Char_t          GlobalTrigDecision_2e24_lhvloose_nod0;
   Char_t          GlobalTrigDecision_e120_lhloose;
   Char_t          GlobalTrigDecision_e140_lhloose_nod0;
   Char_t          GlobalTrigDecision_e17_lhloose_mu14;
   Char_t          GlobalTrigDecision_e17_lhloose_nod0_mu14;
   Char_t          GlobalTrigDecision_e24_lhmedium_L1EM20VH;
   Char_t          GlobalTrigDecision_e26_lhtight_nod0_ivarloose;
   Char_t          GlobalTrigDecision_e60_lhmedium;
   Char_t          GlobalTrigDecision_e60_lhmedium_nod0;
   Char_t          GlobalTrigDecision_mu18_mu8noL1;
   Char_t          GlobalTrigDecision_mu20_iloose_L1MU15;
   Char_t          GlobalTrigDecision_mu22_mu8noL1;
   Char_t          GlobalTrigDecision_mu26_ivarmedium;
   Char_t          GlobalTrigDecision_mu50;
   Int_t           higgsDecayMode;
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
   Float_t         met_sumet;
   Float_t         tauSFRNNMedium_TAU_SF_NOMINAL;
   Float_t         tauSFRNNLoose_TAU_SF_NOMINAL;
   Float_t         bTagSF_weight_DL1_70;
   Float_t         bTagSF_weight_DL1_77;
   Float_t         bTagSF_weight_DL1_85;
   Float_t         bTagSF_weight_DL1_60;
   Float_t         bTagSF_weight_DL1r_70;
   Float_t         bTagSF_weight_DL1r_77;
   Float_t         bTagSF_weight_DL1r_85;
   Float_t         bTagSF_weight_DL1r_60;
   Float_t         bTagSF_weight_DL1r_Continuous;
   Double_t        mc_norm;

   // List of branches
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_mu_actual;   //!
   TBranch        *b_backgroundFlags;   //!
   TBranch        *b_hasBadMuon;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_triggers;   //!
   TBranch        *b_loose;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_2e24_lhvloose_nod0;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
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
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_nJets_OR_TauOR;   //!
   TBranch        *b_nFwdJets_OR;   //!
   TBranch        *b_nFwdJets_OR_TauOR;   //!
   TBranch        *b_nTruthJets_OR;   //!
   TBranch        *b_nJets_OR_DL1r_85;   //!
   TBranch        *b_nJets_OR_DL1r_60;   //!
   TBranch        *b_nJets_OR_DL1r_77;   //!
   TBranch        *b_nJets_OR_DL1r_70;   //!
   TBranch        *b_nFwdJets_OR_DL1r_85;   //!
   TBranch        *b_nFwdJets_OR_DL1r_60;   //!
   TBranch        *b_nFwdJets_OR_DL1r_77;   //!
   TBranch        *b_nFwdJets_OR_DL1r_70;   //!
   TBranch        *b_nJets_OR_DL1_85;   //!
   TBranch        *b_nJets_OR_DL1_60;   //!
   TBranch        *b_nJets_OR_DL1_77;   //!
   TBranch        *b_nJets_OR_DL1_70;   //!
   TBranch        *b_nTaus_OR_Pt25;   //!
   TBranch        *b_nTaus_OR;   //!
   TBranch        *b_nTaus_OR_Medium;   //!
   TBranch        *b_nTaus_OR_Tight;   //!
   TBranch        *b_isBlinded;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_mc_xSection;   //!
   TBranch        *b_mc_genWeights;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Index_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_EtaBE2_0;   //!
   TBranch        *b_lep_Phi_0;   //!
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
   TBranch        *b_lep_isolationFCTight_0;   //!
   TBranch        *b_lep_isolationLoose_0;   //!
   TBranch        *b_lep_isolationGradient_0;   //!
   TBranch        *b_lep_isolationGradientLoose_0;   //!
   TBranch        *b_lep_isolationTightTrackOnly_0;   //!
   TBranch        *b_lep_isolationFCLoose_0;   //!
   TBranch        *b_lep_isolationPflowTight_0;   //!
   TBranch        *b_lep_isolationPflowLoose_0;   //!
   TBranch        *b_lep_plvWP_Loose_0;   //!
   TBranch        *b_lep_plvWP_Tight_0;   //!
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
   TBranch        *b_lep_nTrackParticles_0;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_0;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_0;   //!
   TBranch        *b_lep_RadiusCO_0;   //!
   TBranch        *b_lep_RadiusCOX_0;   //!
   TBranch        *b_lep_RadiusCOY_0;   //!
   TBranch        *b_lep_SeparationMinDCT_0;   //!
   TBranch        *b_lep_ClosestSiTracknIL_0;   //!
   TBranch        *b_lep_ClosestSiTrackeIL_0;   //!
   TBranch        *b_lep_ClosestSiTracknNIL_0;   //!
   TBranch        *b_lep_ClosestSiTrackeNIL_0;   //!
   TBranch        *b_lep_BestMatchTrackPt_0;   //!
   TBranch        *b_lep_BestMatchTrackEta_0;   //!
   TBranch        *b_lep_BestMatchTrackPhi_0;   //!
   TBranch        *b_lep_BestMatchTrackD0_0;   //!
   TBranch        *b_lep_BestMatchTrackZ0_0;   //!
   TBranch        *b_lep_BestMatchTrackQ_0;   //!
   TBranch        *b_lep_ClosestSiTrackPt_0;   //!
   TBranch        *b_lep_ClosestSiTrackEta_0;   //!
   TBranch        *b_lep_ClosestSiTrackPhi_0;   //!
   TBranch        *b_lep_ClosestSiTrackD0_0;   //!
   TBranch        *b_lep_ClosestSiTrackZ0_0;   //!
   TBranch        *b_lep_ClosestSiTrackQ_0;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_0;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_0;   //!
   TBranch        *b_lep_DFCommonSimpleMee_0;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_0;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_0;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_0;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_0;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_0;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_0;   //!
   TBranch        *b_lep_chargeIDBDTLoose_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_0;   //!
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
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_0;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0;   //!
   TBranch        *b_lep_jet_Pt_0;   //!
   TBranch        *b_lep_jet_nTrk_0;   //!
   TBranch        *b_lep_jet_sumPtTrk_0;   //!
   TBranch        *b_lep_jet_mv2c10_0;   //!
   TBranch        *b_lep_jet_deltaR_0;   //!
   TBranch        *b_lep_jet_ptRel_0;   //!
   TBranch        *b_lep_jet_ptOverMuPt_0;   //!
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
   TBranch        *b_lep_nInnerPix_0;   //!
   TBranch        *b_lep_firstEgMotherPdgId_0;   //!
   TBranch        *b_lep_firstEgMotherTruthType_0;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_0;   //!
   TBranch        *b_lep_lastEgMotherPdgId_0;   //!
   TBranch        *b_lep_lastEgMotherTruthType_0;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_0;   //!
   TBranch        *b_lep_SF_El_Reco_AT_0;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_0;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_0;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_0;   //!
   TBranch        *b_lep_SF_El_PLVTight_0;   //!
   TBranch        *b_lep_SF_El_PLVLoose_0;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_0;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_0;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_0;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_0;   //!
   TBranch        *b_lep_SF_CombinedLoose_0;   //!
   TBranch        *b_lep_SF_CombinedTight_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_Index_1;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_EtaBE2_1;   //!
   TBranch        *b_lep_Phi_1;   //!
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
   TBranch        *b_lep_isolationFCTight_1;   //!
   TBranch        *b_lep_isolationLoose_1;   //!
   TBranch        *b_lep_isolationGradient_1;   //!
   TBranch        *b_lep_isolationGradientLoose_1;   //!
   TBranch        *b_lep_isolationTightTrackOnly_1;   //!
   TBranch        *b_lep_isolationFCLoose_1;   //!
   TBranch        *b_lep_isolationPflowTight_1;   //!
   TBranch        *b_lep_isolationPflowLoose_1;   //!
   TBranch        *b_lep_plvWP_Loose_1;   //!
   TBranch        *b_lep_plvWP_Tight_1;   //!
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
   TBranch        *b_lep_nTrackParticles_1;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_1;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_1;   //!
   TBranch        *b_lep_RadiusCO_1;   //!
   TBranch        *b_lep_RadiusCOX_1;   //!
   TBranch        *b_lep_RadiusCOY_1;   //!
   TBranch        *b_lep_SeparationMinDCT_1;   //!
   TBranch        *b_lep_ClosestSiTracknIL_1;   //!
   TBranch        *b_lep_ClosestSiTrackeIL_1;   //!
   TBranch        *b_lep_ClosestSiTracknNIL_1;   //!
   TBranch        *b_lep_ClosestSiTrackeNIL_1;   //!
   TBranch        *b_lep_BestMatchTrackPt_1;   //!
   TBranch        *b_lep_BestMatchTrackEta_1;   //!
   TBranch        *b_lep_BestMatchTrackPhi_1;   //!
   TBranch        *b_lep_BestMatchTrackD0_1;   //!
   TBranch        *b_lep_BestMatchTrackZ0_1;   //!
   TBranch        *b_lep_BestMatchTrackQ_1;   //!
   TBranch        *b_lep_ClosestSiTrackPt_1;   //!
   TBranch        *b_lep_ClosestSiTrackEta_1;   //!
   TBranch        *b_lep_ClosestSiTrackPhi_1;   //!
   TBranch        *b_lep_ClosestSiTrackD0_1;   //!
   TBranch        *b_lep_ClosestSiTrackZ0_1;   //!
   TBranch        *b_lep_ClosestSiTrackQ_1;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_1;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_1;   //!
   TBranch        *b_lep_DFCommonSimpleMee_1;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_1;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_1;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_1;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_1;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_1;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_1;   //!
   TBranch        *b_lep_chargeIDBDTLoose_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_1;   //!
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
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_1;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1;   //!
   TBranch        *b_lep_jet_Pt_1;   //!
   TBranch        *b_lep_jet_nTrk_1;   //!
   TBranch        *b_lep_jet_sumPtTrk_1;   //!
   TBranch        *b_lep_jet_mv2c10_1;   //!
   TBranch        *b_lep_jet_deltaR_1;   //!
   TBranch        *b_lep_jet_ptRel_1;   //!
   TBranch        *b_lep_jet_ptOverMuPt_1;   //!
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
   TBranch        *b_lep_nInnerPix_1;   //!
   TBranch        *b_lep_firstEgMotherPdgId_1;   //!
   TBranch        *b_lep_firstEgMotherTruthType_1;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_1;   //!
   TBranch        *b_lep_lastEgMotherPdgId_1;   //!
   TBranch        *b_lep_lastEgMotherTruthType_1;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_1;   //!
   TBranch        *b_lep_SF_El_Reco_AT_1;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_1;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_1;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_1;   //!
   TBranch        *b_lep_SF_El_PLVTight_1;   //!
   TBranch        *b_lep_SF_El_PLVLoose_1;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_1;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_1;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_1;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_1;   //!
   TBranch        *b_lep_SF_CombinedLoose_1;   //!
   TBranch        *b_lep_SF_CombinedTight_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_Index_2;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_EtaBE2_2;   //!
   TBranch        *b_lep_Phi_2;   //!
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
   TBranch        *b_lep_isolationFCTight_2;   //!
   TBranch        *b_lep_isolationLoose_2;   //!
   TBranch        *b_lep_isolationGradient_2;   //!
   TBranch        *b_lep_isolationGradientLoose_2;   //!
   TBranch        *b_lep_isolationTightTrackOnly_2;   //!
   TBranch        *b_lep_isolationFCLoose_2;   //!
   TBranch        *b_lep_isolationPflowTight_2;   //!
   TBranch        *b_lep_isolationPflowLoose_2;   //!
   TBranch        *b_lep_plvWP_Loose_2;   //!
   TBranch        *b_lep_plvWP_Tight_2;   //!
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
   TBranch        *b_lep_nTrackParticles_2;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_2;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_2;   //!
   TBranch        *b_lep_RadiusCO_2;   //!
   TBranch        *b_lep_RadiusCOX_2;   //!
   TBranch        *b_lep_RadiusCOY_2;   //!
   TBranch        *b_lep_SeparationMinDCT_2;   //!
   TBranch        *b_lep_ClosestSiTracknIL_2;   //!
   TBranch        *b_lep_ClosestSiTrackeIL_2;   //!
   TBranch        *b_lep_ClosestSiTracknNIL_2;   //!
   TBranch        *b_lep_ClosestSiTrackeNIL_2;   //!
   TBranch        *b_lep_BestMatchTrackPt_2;   //!
   TBranch        *b_lep_BestMatchTrackEta_2;   //!
   TBranch        *b_lep_BestMatchTrackPhi_2;   //!
   TBranch        *b_lep_BestMatchTrackD0_2;   //!
   TBranch        *b_lep_BestMatchTrackZ0_2;   //!
   TBranch        *b_lep_BestMatchTrackQ_2;   //!
   TBranch        *b_lep_ClosestSiTrackPt_2;   //!
   TBranch        *b_lep_ClosestSiTrackEta_2;   //!
   TBranch        *b_lep_ClosestSiTrackPhi_2;   //!
   TBranch        *b_lep_ClosestSiTrackD0_2;   //!
   TBranch        *b_lep_ClosestSiTrackZ0_2;   //!
   TBranch        *b_lep_ClosestSiTrackQ_2;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_2;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_2;   //!
   TBranch        *b_lep_DFCommonSimpleMee_2;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_2;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_2;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_2;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_2;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_2;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_2;   //!
   TBranch        *b_lep_chargeIDBDTLoose_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_2;   //!
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
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_2;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2;   //!
   TBranch        *b_lep_jet_Pt_2;   //!
   TBranch        *b_lep_jet_nTrk_2;   //!
   TBranch        *b_lep_jet_sumPtTrk_2;   //!
   TBranch        *b_lep_jet_mv2c10_2;   //!
   TBranch        *b_lep_jet_deltaR_2;   //!
   TBranch        *b_lep_jet_ptRel_2;   //!
   TBranch        *b_lep_jet_ptOverMuPt_2;   //!
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
   TBranch        *b_lep_nInnerPix_2;   //!
   TBranch        *b_lep_firstEgMotherPdgId_2;   //!
   TBranch        *b_lep_firstEgMotherTruthType_2;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_2;   //!
   TBranch        *b_lep_lastEgMotherPdgId_2;   //!
   TBranch        *b_lep_lastEgMotherTruthType_2;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_2;   //!
   TBranch        *b_lep_SF_El_Reco_AT_2;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_2;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_2;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_2;   //!
   TBranch        *b_lep_SF_El_PLVTight_2;   //!
   TBranch        *b_lep_SF_El_PLVLoose_2;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_2;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_2;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_2;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_2;   //!
   TBranch        *b_lep_SF_CombinedLoose_2;   //!
   TBranch        *b_lep_SF_CombinedTight_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Index_3;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_EtaBE2_3;   //!
   TBranch        *b_lep_Phi_3;   //!
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
   TBranch        *b_lep_isolationFCTight_3;   //!
   TBranch        *b_lep_isolationLoose_3;   //!
   TBranch        *b_lep_isolationGradient_3;   //!
   TBranch        *b_lep_isolationGradientLoose_3;   //!
   TBranch        *b_lep_isolationTightTrackOnly_3;   //!
   TBranch        *b_lep_isolationFCLoose_3;   //!
   TBranch        *b_lep_isolationPflowTight_3;   //!
   TBranch        *b_lep_isolationPflowLoose_3;   //!
   TBranch        *b_lep_plvWP_Loose_3;   //!
   TBranch        *b_lep_plvWP_Tight_3;   //!
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
   TBranch        *b_lep_nTrackParticles_3;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_3;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_3;   //!
   TBranch        *b_lep_RadiusCO_3;   //!
   TBranch        *b_lep_RadiusCOX_3;   //!
   TBranch        *b_lep_RadiusCOY_3;   //!
   TBranch        *b_lep_SeparationMinDCT_3;   //!
   TBranch        *b_lep_ClosestSiTracknIL_3;   //!
   TBranch        *b_lep_ClosestSiTrackeIL_3;   //!
   TBranch        *b_lep_ClosestSiTracknNIL_3;   //!
   TBranch        *b_lep_ClosestSiTrackeNIL_3;   //!
   TBranch        *b_lep_BestMatchTrackPt_3;   //!
   TBranch        *b_lep_BestMatchTrackEta_3;   //!
   TBranch        *b_lep_BestMatchTrackPhi_3;   //!
   TBranch        *b_lep_BestMatchTrackD0_3;   //!
   TBranch        *b_lep_BestMatchTrackZ0_3;   //!
   TBranch        *b_lep_BestMatchTrackQ_3;   //!
   TBranch        *b_lep_ClosestSiTrackPt_3;   //!
   TBranch        *b_lep_ClosestSiTrackEta_3;   //!
   TBranch        *b_lep_ClosestSiTrackPhi_3;   //!
   TBranch        *b_lep_ClosestSiTrackD0_3;   //!
   TBranch        *b_lep_ClosestSiTrackZ0_3;   //!
   TBranch        *b_lep_ClosestSiTrackQ_3;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_3;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_3;   //!
   TBranch        *b_lep_DFCommonSimpleMee_3;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_3;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_3;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_3;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_3;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_3;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_3;   //!
   TBranch        *b_lep_chargeIDBDTLoose_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_3;   //!
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
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_3;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_3;   //!
   TBranch        *b_lep_jet_Pt_3;   //!
   TBranch        *b_lep_jet_nTrk_3;   //!
   TBranch        *b_lep_jet_sumPtTrk_3;   //!
   TBranch        *b_lep_jet_mv2c10_3;   //!
   TBranch        *b_lep_jet_deltaR_3;   //!
   TBranch        *b_lep_jet_ptRel_3;   //!
   TBranch        *b_lep_jet_ptOverMuPt_3;   //!
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
   TBranch        *b_lep_nInnerPix_3;   //!
   TBranch        *b_lep_firstEgMotherPdgId_3;   //!
   TBranch        *b_lep_firstEgMotherTruthType_3;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_3;   //!
   TBranch        *b_lep_lastEgMotherPdgId_3;   //!
   TBranch        *b_lep_lastEgMotherTruthType_3;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_3;   //!
   TBranch        *b_lep_SF_El_Reco_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_3;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_3;   //!
   TBranch        *b_lep_SF_El_PLVTight_3;   //!
   TBranch        *b_lep_SF_El_PLVLoose_3;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_3;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_3;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_3;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_3;   //!
   TBranch        *b_lep_SF_CombinedLoose_3;   //!
   TBranch        *b_lep_SF_CombinedTight_3;   //!
   TBranch        *b_lep_ID_4;   //!
   TBranch        *b_lep_Index_4;   //!
   TBranch        *b_lep_Pt_4;   //!
   TBranch        *b_lep_E_4;   //!
   TBranch        *b_lep_Eta_4;   //!
   TBranch        *b_lep_EtaBE2_4;   //!
   TBranch        *b_lep_Phi_4;   //!
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
   TBranch        *b_lep_isolationFCTight_4;   //!
   TBranch        *b_lep_isolationLoose_4;   //!
   TBranch        *b_lep_isolationGradient_4;   //!
   TBranch        *b_lep_isolationGradientLoose_4;   //!
   TBranch        *b_lep_isolationTightTrackOnly_4;   //!
   TBranch        *b_lep_isolationFCLoose_4;   //!
   TBranch        *b_lep_isolationPflowTight_4;   //!
   TBranch        *b_lep_isolationPflowLoose_4;   //!
   TBranch        *b_lep_plvWP_Loose_4;   //!
   TBranch        *b_lep_plvWP_Tight_4;   //!
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
   TBranch        *b_lep_nTrackParticles_4;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_4;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_4;   //!
   TBranch        *b_lep_RadiusCO_4;   //!
   TBranch        *b_lep_RadiusCOX_4;   //!
   TBranch        *b_lep_RadiusCOY_4;   //!
   TBranch        *b_lep_SeparationMinDCT_4;   //!
   TBranch        *b_lep_ClosestSiTracknIL_4;   //!
   TBranch        *b_lep_ClosestSiTrackeIL_4;   //!
   TBranch        *b_lep_ClosestSiTracknNIL_4;   //!
   TBranch        *b_lep_ClosestSiTrackeNIL_4;   //!
   TBranch        *b_lep_BestMatchTrackPt_4;   //!
   TBranch        *b_lep_BestMatchTrackEta_4;   //!
   TBranch        *b_lep_BestMatchTrackPhi_4;   //!
   TBranch        *b_lep_BestMatchTrackD0_4;   //!
   TBranch        *b_lep_BestMatchTrackZ0_4;   //!
   TBranch        *b_lep_BestMatchTrackQ_4;   //!
   TBranch        *b_lep_ClosestSiTrackPt_4;   //!
   TBranch        *b_lep_ClosestSiTrackEta_4;   //!
   TBranch        *b_lep_ClosestSiTrackPhi_4;   //!
   TBranch        *b_lep_ClosestSiTrackD0_4;   //!
   TBranch        *b_lep_ClosestSiTrackZ0_4;   //!
   TBranch        *b_lep_ClosestSiTrackQ_4;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_4;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_4;   //!
   TBranch        *b_lep_DFCommonSimpleMee_4;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_4;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_4;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_4;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_4;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_4;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_4;   //!
   TBranch        *b_lep_chargeIDBDTLoose_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_4;   //!
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
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_4;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_4;   //!
   TBranch        *b_lep_jet_Pt_4;   //!
   TBranch        *b_lep_jet_nTrk_4;   //!
   TBranch        *b_lep_jet_sumPtTrk_4;   //!
   TBranch        *b_lep_jet_mv2c10_4;   //!
   TBranch        *b_lep_jet_deltaR_4;   //!
   TBranch        *b_lep_jet_ptRel_4;   //!
   TBranch        *b_lep_jet_ptOverMuPt_4;   //!
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
   TBranch        *b_lep_nInnerPix_4;   //!
   TBranch        *b_lep_firstEgMotherPdgId_4;   //!
   TBranch        *b_lep_firstEgMotherTruthType_4;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_4;   //!
   TBranch        *b_lep_lastEgMotherPdgId_4;   //!
   TBranch        *b_lep_lastEgMotherTruthType_4;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_4;   //!
   TBranch        *b_lep_SF_El_Reco_AT_4;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_4;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_4;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_4;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_4;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_4;   //!
   TBranch        *b_lep_SF_El_PLVTight_4;   //!
   TBranch        *b_lep_SF_El_PLVLoose_4;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_4;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_4;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_4;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_4;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_4;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_4;   //!
   TBranch        *b_lep_SF_CombinedLoose_4;   //!
   TBranch        *b_lep_SF_CombinedTight_4;   //!
   TBranch        *b_taus_pt_0;   //!
   TBranch        *b_taus_eta_0;   //!
   TBranch        *b_taus_phi_0;   //!
   TBranch        *b_taus_charge_0;   //!
   TBranch        *b_taus_E_0;   //!
   TBranch        *b_taus_width_0;   //!
   TBranch        *b_taus_decayMode_0;   //!
   TBranch        *b_taus_BDTJetScore_0;   //!
   TBranch        *b_taus_BDTJetScoreSigTrans_0;   //!
   TBranch        *b_taus_JetBDTSigLoose_0;   //!
   TBranch        *b_taus_JetBDTSigMedium_0;   //!
   TBranch        *b_taus_JetBDTSigTight_0;   //!
   TBranch        *b_taus_RNNJetScore_0;   //!
   TBranch        *b_taus_RNNJetScoreSigTrans_0;   //!
   TBranch        *b_taus_JetRNNSigLoose_0;   //!
   TBranch        *b_taus_JetRNNSigMedium_0;   //!
   TBranch        *b_taus_JetRNNSigTight_0;   //!
   TBranch        *b_taus_numTrack_0;   //!
   TBranch        *b_taus_isHadronic_0;   //!
   TBranch        *b_taus_tagWeightBin_0;   //!
   TBranch        *b_taus_MV2c10_0;   //!
   TBranch        *b_taus_DL1r_0;   //!
   TBranch        *b_taus_DL1_0;   //!
   TBranch        *b_taus_fromPV_0;   //!
   TBranch        *b_taus_passJVT_0;   //!
   TBranch        *b_taus_passEleOLR_0;   //!
   TBranch        *b_taus_passEleBDT_0;   //!
   TBranch        *b_taus_passMuonOLR_0;   //!
   TBranch        *b_taus_truthOrigin_0;   //!
   TBranch        *b_taus_truthType_0;   //!
   TBranch        *b_taus_truthJetFlavour_0;   //!
   TBranch        *b_taus_pt_1;   //!
   TBranch        *b_taus_eta_1;   //!
   TBranch        *b_taus_phi_1;   //!
   TBranch        *b_taus_charge_1;   //!
   TBranch        *b_taus_E_1;   //!
   TBranch        *b_taus_width_1;   //!
   TBranch        *b_taus_decayMode_1;   //!
   TBranch        *b_taus_BDTJetScore_1;   //!
   TBranch        *b_taus_BDTJetScoreSigTrans_1;   //!
   TBranch        *b_taus_JetBDTSigLoose_1;   //!
   TBranch        *b_taus_JetBDTSigMedium_1;   //!
   TBranch        *b_taus_JetBDTSigTight_1;   //!
   TBranch        *b_taus_RNNJetScore_1;   //!
   TBranch        *b_taus_RNNJetScoreSigTrans_1;   //!
   TBranch        *b_taus_JetRNNSigLoose_1;   //!
   TBranch        *b_taus_JetRNNSigMedium_1;   //!
   TBranch        *b_taus_JetRNNSigTight_1;   //!
   TBranch        *b_taus_numTrack_1;   //!
   TBranch        *b_taus_isHadronic_1;   //!
   TBranch        *b_taus_tagWeightBin_1;   //!
   TBranch        *b_taus_MV2c10_1;   //!
   TBranch        *b_taus_DL1r_1;   //!
   TBranch        *b_taus_DL1_1;   //!
   TBranch        *b_taus_fromPV_1;   //!
   TBranch        *b_taus_passJVT_1;   //!
   TBranch        *b_taus_passEleOLR_1;   //!
   TBranch        *b_taus_passEleBDT_1;   //!
   TBranch        *b_taus_passMuonOLR_1;   //!
   TBranch        *b_taus_truthOrigin_1;   //!
   TBranch        *b_taus_truthType_1;   //!
   TBranch        *b_taus_truthJetFlavour_1;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_e;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_tauOR;   //!
   TBranch        *b_jets_fJVT;   //!
   TBranch        *b_jets_score_DL1r;   //!
   TBranch        *b_jets_score_DL1r_pu;   //!
   TBranch        *b_jets_score_DL1r_pc;   //!
   TBranch        *b_jets_score_DL1r_pb;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_60;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_77;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_lepSFObjChannelCombined;   //!
   TBranch        *b_jvtSF_customOR;   //!
   TBranch        *b_GlobalTrigMatch_AT_default_postOR;   //!
   TBranch        *b_GlobalTrigDecision;   //!
   TBranch        *b_custTrigSF_AT_default_preOR;   //!
   TBranch        *b_custTrigSF_AT_default_postOR;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_DLT;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_DLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_DLT;   //!
   TBranch        *b_GlobalTrigDecision_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_GlobalTrigDecision_2e17_lhvloose_nod0;   //!
   TBranch        *b_GlobalTrigDecision_2e24_lhvloose_nod0;   //!
   TBranch        *b_GlobalTrigDecision_e120_lhloose;   //!
   TBranch        *b_GlobalTrigDecision_e140_lhloose_nod0;   //!
   TBranch        *b_GlobalTrigDecision_e17_lhloose_mu14;   //!
   TBranch        *b_GlobalTrigDecision_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_GlobalTrigDecision_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_GlobalTrigDecision_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_GlobalTrigDecision_e60_lhmedium;   //!
   TBranch        *b_GlobalTrigDecision_e60_lhmedium_nod0;   //!
   TBranch        *b_GlobalTrigDecision_mu18_mu8noL1;   //!
   TBranch        *b_GlobalTrigDecision_mu20_iloose_L1MU15;   //!
   TBranch        *b_GlobalTrigDecision_mu22_mu8noL1;   //!
   TBranch        *b_GlobalTrigDecision_mu26_ivarmedium;   //!
   TBranch        *b_GlobalTrigDecision_mu50;   //!
   TBranch        *b_higgsDecayMode;   //!
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
   TBranch        *b_met_sumet;   //!
   TBranch        *b_tauSFRNNMedium_TAU_SF_NOMINAL;   //!
   TBranch        *b_tauSFRNNLoose_TAU_SF_NOMINAL;   //!
   TBranch        *b_bTagSF_weight_DL1_70;   //!
   TBranch        *b_bTagSF_weight_DL1_77;   //!
   TBranch        *b_bTagSF_weight_DL1_85;   //!
   TBranch        *b_bTagSF_weight_DL1_60;   //!
   TBranch        *b_bTagSF_weight_DL1r_70;   //!
   TBranch        *b_bTagSF_weight_DL1r_77;   //!
   TBranch        *b_bTagSF_weight_DL1r_85;   //!
   TBranch        *b_bTagSF_weight_DL1r_60;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous;   //!
   TBranch        *b_mc_norm;   //!

   tthmltree_v5(TTree *tree=0);
   virtual ~tthmltree_v5();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tthmltree_v5_cxx
tthmltree_v5::tthmltree_v5(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimttV5/MytthAnaSkim_364290_FS_mc16e_ttWML_v05.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/Hist/25ns_R21SkimttV5/MytthAnaSkim_364290_FS_mc16e_ttWML_v05.root");
      }
      f->GetObject("nominal",tree);

   }
   Init(tree);
}

tthmltree_v5::~tthmltree_v5()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tthmltree_v5::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tthmltree_v5::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tthmltree_v5::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mc_genWeights = 0;
   jets_pt = 0;
   jets_e = 0;
   jets_eta = 0;
   jets_phi = 0;
   jets_tauOR = 0;
   jets_fJVT = 0;
   jets_score_DL1r = 0;
   jets_score_DL1r_pu = 0;
   jets_score_DL1r_pc = 0;
   jets_score_DL1r_pb = 0;
   jets_btagFlag_DL1r_FixedCutBEff_60 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_70 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_77 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_85 = 0;
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
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("mu_actual", &mu_actual, &b_mu_actual);
   fChain->SetBranchAddress("backgroundFlags", &backgroundFlags, &b_backgroundFlags);
   fChain->SetBranchAddress("hasBadMuon", &hasBadMuon, &b_hasBadMuon);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("triggers", &triggers, &b_triggers);
   fChain->SetBranchAddress("loose", &loose, &b_loose);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14, &b_HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_2e24_lhvloose_nod0", &HLT_2e24_lhvloose_nod0, &b_HLT_2e24_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("onelep_type", &onelep_type, &b_onelep_type);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("quadlep_type", &quadlep_type, &b_quadlep_type);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("isQMisIDEvent", &isQMisIDEvent, &b_isQMisIDEvent);
   fChain->SetBranchAddress("isFakeEvent", &isFakeEvent, &b_isFakeEvent);
   fChain->SetBranchAddress("isLepFromPhEvent", &isLepFromPhEvent, &b_isLepFromPhEvent);
   fChain->SetBranchAddress("Mll01", &Mll01, &b_Mll01);
   fChain->SetBranchAddress("Ptll01", &Ptll01, &b_Ptll01);
   fChain->SetBranchAddress("DRll01", &DRll01, &b_DRll01);
   fChain->SetBranchAddress("matchDLTll01", &matchDLTll01, &b_matchDLTll01);
   fChain->SetBranchAddress("Mlll012", &Mlll012, &b_Mlll012);
   fChain->SetBranchAddress("Mllll0123", &Mllll0123, &b_Mllll0123);
   fChain->SetBranchAddress("Mllll0124", &Mllll0124, &b_Mllll0124);
   fChain->SetBranchAddress("Mlll013", &Mlll013, &b_Mlll013);
   fChain->SetBranchAddress("Mllll0134", &Mllll0134, &b_Mllll0134);
   fChain->SetBranchAddress("Mlll014", &Mlll014, &b_Mlll014);
   fChain->SetBranchAddress("Mll02", &Mll02, &b_Mll02);
   fChain->SetBranchAddress("Ptll02", &Ptll02, &b_Ptll02);
   fChain->SetBranchAddress("DRll02", &DRll02, &b_DRll02);
   fChain->SetBranchAddress("matchDLTll02", &matchDLTll02, &b_matchDLTll02);
   fChain->SetBranchAddress("Mlll023", &Mlll023, &b_Mlll023);
   fChain->SetBranchAddress("Mllll0234", &Mllll0234, &b_Mllll0234);
   fChain->SetBranchAddress("Mlll024", &Mlll024, &b_Mlll024);
   fChain->SetBranchAddress("Mll03", &Mll03, &b_Mll03);
   fChain->SetBranchAddress("Ptll03", &Ptll03, &b_Ptll03);
   fChain->SetBranchAddress("DRll03", &DRll03, &b_DRll03);
   fChain->SetBranchAddress("matchDLTll03", &matchDLTll03, &b_matchDLTll03);
   fChain->SetBranchAddress("Mlll034", &Mlll034, &b_Mlll034);
   fChain->SetBranchAddress("Mll04", &Mll04, &b_Mll04);
   fChain->SetBranchAddress("Ptll04", &Ptll04, &b_Ptll04);
   fChain->SetBranchAddress("DRll04", &DRll04, &b_DRll04);
   fChain->SetBranchAddress("matchDLTll04", &matchDLTll04, &b_matchDLTll04);
   fChain->SetBranchAddress("Mll12", &Mll12, &b_Mll12);
   fChain->SetBranchAddress("Ptll12", &Ptll12, &b_Ptll12);
   fChain->SetBranchAddress("DRll12", &DRll12, &b_DRll12);
   fChain->SetBranchAddress("matchDLTll12", &matchDLTll12, &b_matchDLTll12);
   fChain->SetBranchAddress("Mlll123", &Mlll123, &b_Mlll123);
   fChain->SetBranchAddress("Mllll1234", &Mllll1234, &b_Mllll1234);
   fChain->SetBranchAddress("Mlll124", &Mlll124, &b_Mlll124);
   fChain->SetBranchAddress("Mll13", &Mll13, &b_Mll13);
   fChain->SetBranchAddress("Ptll13", &Ptll13, &b_Ptll13);
   fChain->SetBranchAddress("DRll13", &DRll13, &b_DRll13);
   fChain->SetBranchAddress("matchDLTll13", &matchDLTll13, &b_matchDLTll13);
   fChain->SetBranchAddress("Mlll134", &Mlll134, &b_Mlll134);
   fChain->SetBranchAddress("Mll14", &Mll14, &b_Mll14);
   fChain->SetBranchAddress("Ptll14", &Ptll14, &b_Ptll14);
   fChain->SetBranchAddress("DRll14", &DRll14, &b_DRll14);
   fChain->SetBranchAddress("matchDLTll14", &matchDLTll14, &b_matchDLTll14);
   fChain->SetBranchAddress("Mll23", &Mll23, &b_Mll23);
   fChain->SetBranchAddress("Ptll23", &Ptll23, &b_Ptll23);
   fChain->SetBranchAddress("DRll23", &DRll23, &b_DRll23);
   fChain->SetBranchAddress("matchDLTll23", &matchDLTll23, &b_matchDLTll23);
   fChain->SetBranchAddress("Mlll234", &Mlll234, &b_Mlll234);
   fChain->SetBranchAddress("Mll24", &Mll24, &b_Mll24);
   fChain->SetBranchAddress("Ptll24", &Ptll24, &b_Ptll24);
   fChain->SetBranchAddress("DRll24", &DRll24, &b_DRll24);
   fChain->SetBranchAddress("matchDLTll24", &matchDLTll24, &b_matchDLTll24);
   fChain->SetBranchAddress("Mll34", &Mll34, &b_Mll34);
   fChain->SetBranchAddress("Ptll34", &Ptll34, &b_Ptll34);
   fChain->SetBranchAddress("DRll34", &DRll34, &b_DRll34);
   fChain->SetBranchAddress("matchDLTll34", &matchDLTll34, &b_matchDLTll34);
   fChain->SetBranchAddress("best_Z_Mll", &best_Z_Mll, &b_best_Z_Mll);
   fChain->SetBranchAddress("best_Z_other_MtLepMet", &best_Z_other_MtLepMet, &b_best_Z_other_MtLepMet);
   fChain->SetBranchAddress("best_Z_other_Mll", &best_Z_other_Mll, &b_best_Z_other_Mll);
   fChain->SetBranchAddress("minOSSFMll", &minOSSFMll, &b_minOSSFMll);
   fChain->SetBranchAddress("minOSMll", &minOSMll, &b_minOSMll);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("nJets_OR_TauOR", &nJets_OR_TauOR, &b_nJets_OR_TauOR);
   fChain->SetBranchAddress("nFwdJets_OR", &nFwdJets_OR, &b_nFwdJets_OR);
   fChain->SetBranchAddress("nFwdJets_OR_TauOR", &nFwdJets_OR_TauOR, &b_nFwdJets_OR_TauOR);
   fChain->SetBranchAddress("nTruthJets_OR", &nTruthJets_OR, &b_nTruthJets_OR);
   fChain->SetBranchAddress("nJets_OR_DL1r_85", &nJets_OR_DL1r_85, &b_nJets_OR_DL1r_85);
   fChain->SetBranchAddress("nJets_OR_DL1r_60", &nJets_OR_DL1r_60, &b_nJets_OR_DL1r_60);
   fChain->SetBranchAddress("nJets_OR_DL1r_77", &nJets_OR_DL1r_77, &b_nJets_OR_DL1r_77);
   fChain->SetBranchAddress("nJets_OR_DL1r_70", &nJets_OR_DL1r_70, &b_nJets_OR_DL1r_70);
   fChain->SetBranchAddress("nFwdJets_OR_DL1r_85", &nFwdJets_OR_DL1r_85, &b_nFwdJets_OR_DL1r_85);
   fChain->SetBranchAddress("nFwdJets_OR_DL1r_60", &nFwdJets_OR_DL1r_60, &b_nFwdJets_OR_DL1r_60);
   fChain->SetBranchAddress("nFwdJets_OR_DL1r_77", &nFwdJets_OR_DL1r_77, &b_nFwdJets_OR_DL1r_77);
   fChain->SetBranchAddress("nFwdJets_OR_DL1r_70", &nFwdJets_OR_DL1r_70, &b_nFwdJets_OR_DL1r_70);
   fChain->SetBranchAddress("nJets_OR_DL1_85", &nJets_OR_DL1_85, &b_nJets_OR_DL1_85);
   fChain->SetBranchAddress("nJets_OR_DL1_60", &nJets_OR_DL1_60, &b_nJets_OR_DL1_60);
   fChain->SetBranchAddress("nJets_OR_DL1_77", &nJets_OR_DL1_77, &b_nJets_OR_DL1_77);
   fChain->SetBranchAddress("nJets_OR_DL1_70", &nJets_OR_DL1_70, &b_nJets_OR_DL1_70);
   fChain->SetBranchAddress("nTaus_OR_Pt25", &nTaus_OR_Pt25, &b_nTaus_OR_Pt25);
   fChain->SetBranchAddress("nTaus_OR", &nTaus_OR, &b_nTaus_OR);
   fChain->SetBranchAddress("nTaus_OR_Medium", &nTaus_OR_Medium, &b_nTaus_OR_Medium);
   fChain->SetBranchAddress("nTaus_OR_Tight", &nTaus_OR_Tight, &b_nTaus_OR_Tight);
   fChain->SetBranchAddress("isBlinded", &isBlinded, &b_isBlinded);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HT_lep", &HT_lep, &b_HT_lep);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   fChain->SetBranchAddress("mc_xSection", &mc_xSection, &b_mc_xSection);
   fChain->SetBranchAddress("mc_genWeights", &mc_genWeights, &b_mc_genWeights);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_Index_0", &lep_Index_0, &b_lep_Index_0);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_EtaBE2_0", &lep_EtaBE2_0, &b_lep_EtaBE2_0);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   fChain->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   fChain->SetBranchAddress("lep_d0_0", &lep_d0_0, &b_lep_d0_0);
   fChain->SetBranchAddress("lep_z0_0", &lep_z0_0, &b_lep_z0_0);
   fChain->SetBranchAddress("lep_vz_0", &lep_vz_0, &b_lep_vz_0);
   fChain->SetBranchAddress("lep_deltaz0_0", &lep_deltaz0_0, &b_lep_deltaz0_0);
   fChain->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   fChain->SetBranchAddress("lep_isMediumLH_0", &lep_isMediumLH_0, &b_lep_isMediumLH_0);
   fChain->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   fChain->SetBranchAddress("lep_isTight_0", &lep_isTight_0, &b_lep_isTight_0);
   fChain->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   fChain->SetBranchAddress("lep_isLoose_0", &lep_isLoose_0, &b_lep_isLoose_0);
   fChain->SetBranchAddress("lep_isolationFCTight_0", &lep_isolationFCTight_0, &b_lep_isolationFCTight_0);
   fChain->SetBranchAddress("lep_isolationLoose_0", &lep_isolationLoose_0, &b_lep_isolationLoose_0);
   fChain->SetBranchAddress("lep_isolationGradient_0", &lep_isolationGradient_0, &b_lep_isolationGradient_0);
   fChain->SetBranchAddress("lep_isolationGradientLoose_0", &lep_isolationGradientLoose_0, &b_lep_isolationGradientLoose_0);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_0", &lep_isolationTightTrackOnly_0, &b_lep_isolationTightTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationFCLoose_0", &lep_isolationFCLoose_0, &b_lep_isolationFCLoose_0);
   fChain->SetBranchAddress("lep_isolationPflowTight_0", &lep_isolationPflowTight_0, &b_lep_isolationPflowTight_0);
   fChain->SetBranchAddress("lep_isolationPflowLoose_0", &lep_isolationPflowLoose_0, &b_lep_isolationPflowLoose_0);
   fChain->SetBranchAddress("lep_plvWP_Loose_0", &lep_plvWP_Loose_0, &b_lep_plvWP_Loose_0);
   fChain->SetBranchAddress("lep_plvWP_Tight_0", &lep_plvWP_Tight_0, &b_lep_plvWP_Tight_0);
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0, &b_lep_isTrigMatchDLT_0);
   fChain->SetBranchAddress("lep_isPrompt_0", &lep_isPrompt_0, &b_lep_isPrompt_0);
   fChain->SetBranchAddress("lep_isFakeLep_0", &lep_isFakeLep_0, &b_lep_isFakeLep_0);
   fChain->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0, &b_lep_isQMisID_0);
   fChain->SetBranchAddress("lep_isConvPh_0", &lep_isConvPh_0, &b_lep_isConvPh_0);
   fChain->SetBranchAddress("lep_isExtConvPh_0", &lep_isExtConvPh_0, &b_lep_isExtConvPh_0);
   fChain->SetBranchAddress("lep_isIntConvPh_0", &lep_isIntConvPh_0, &b_lep_isIntConvPh_0);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_0", &lep_isISR_FSR_Ph_0, &b_lep_isISR_FSR_Ph_0);
   fChain->SetBranchAddress("lep_isBrems_0", &lep_isBrems_0, &b_lep_isBrems_0);
   fChain->SetBranchAddress("lep_nTrackParticles_0", &lep_nTrackParticles_0, &b_lep_nTrackParticles_0);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_0", &lep_Mtrktrk_atPV_CO_0, &b_lep_Mtrktrk_atPV_CO_0);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_0", &lep_Mtrktrk_atConvV_CO_0, &b_lep_Mtrktrk_atConvV_CO_0);
   fChain->SetBranchAddress("lep_RadiusCO_0", &lep_RadiusCO_0, &b_lep_RadiusCO_0);
   fChain->SetBranchAddress("lep_RadiusCOX_0", &lep_RadiusCOX_0, &b_lep_RadiusCOX_0);
   fChain->SetBranchAddress("lep_RadiusCOY_0", &lep_RadiusCOY_0, &b_lep_RadiusCOY_0);
   fChain->SetBranchAddress("lep_SeparationMinDCT_0", &lep_SeparationMinDCT_0, &b_lep_SeparationMinDCT_0);
   fChain->SetBranchAddress("lep_ClosestSiTracknIL_0", &lep_ClosestSiTracknIL_0, &b_lep_ClosestSiTracknIL_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackeIL_0", &lep_ClosestSiTrackeIL_0, &b_lep_ClosestSiTrackeIL_0);
   fChain->SetBranchAddress("lep_ClosestSiTracknNIL_0", &lep_ClosestSiTracknNIL_0, &b_lep_ClosestSiTracknNIL_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackeNIL_0", &lep_ClosestSiTrackeNIL_0, &b_lep_ClosestSiTrackeNIL_0);
   fChain->SetBranchAddress("lep_BestMatchTrackPt_0", &lep_BestMatchTrackPt_0, &b_lep_BestMatchTrackPt_0);
   fChain->SetBranchAddress("lep_BestMatchTrackEta_0", &lep_BestMatchTrackEta_0, &b_lep_BestMatchTrackEta_0);
   fChain->SetBranchAddress("lep_BestMatchTrackPhi_0", &lep_BestMatchTrackPhi_0, &b_lep_BestMatchTrackPhi_0);
   fChain->SetBranchAddress("lep_BestMatchTrackD0_0", &lep_BestMatchTrackD0_0, &b_lep_BestMatchTrackD0_0);
   fChain->SetBranchAddress("lep_BestMatchTrackZ0_0", &lep_BestMatchTrackZ0_0, &b_lep_BestMatchTrackZ0_0);
   fChain->SetBranchAddress("lep_BestMatchTrackQ_0", &lep_BestMatchTrackQ_0, &b_lep_BestMatchTrackQ_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackPt_0", &lep_ClosestSiTrackPt_0, &b_lep_ClosestSiTrackPt_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackEta_0", &lep_ClosestSiTrackEta_0, &b_lep_ClosestSiTrackEta_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackPhi_0", &lep_ClosestSiTrackPhi_0, &b_lep_ClosestSiTrackPhi_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackD0_0", &lep_ClosestSiTrackD0_0, &b_lep_ClosestSiTrackD0_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackZ0_0", &lep_ClosestSiTrackZ0_0, &b_lep_ClosestSiTrackZ0_0);
   fChain->SetBranchAddress("lep_ClosestSiTrackQ_0", &lep_ClosestSiTrackQ_0, &b_lep_ClosestSiTrackQ_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_0", &lep_DFCommonSimpleConvRadius_0, &b_lep_DFCommonSimpleConvRadius_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_0", &lep_DFCommonSimpleConvPhi_0, &b_lep_DFCommonSimpleConvPhi_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_0", &lep_DFCommonSimpleMee_0, &b_lep_DFCommonSimpleMee_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_0", &lep_DFCommonSimpleMeeAtVtx_0, &b_lep_DFCommonSimpleMeeAtVtx_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_0", &lep_DFCommonSimpleSeparation_0, &b_lep_DFCommonSimpleSeparation_0);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_0", &lep_DFCommonAddAmbiguity_0, &b_lep_DFCommonAddAmbiguity_0);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_0", &lep_DFCommonProdTrueRadius_0, &b_lep_DFCommonProdTrueRadius_0);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_0", &lep_DFCommonProdTruePhi_0, &b_lep_DFCommonProdTruePhi_0);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_0", &lep_DFCommonProdTrueZ_0, &b_lep_DFCommonProdTrueZ_0);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_0", &lep_chargeIDBDTLoose_0, &b_lep_chargeIDBDTLoose_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_0", &lep_chargeIDBDTResult_0, &b_lep_chargeIDBDTResult_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_0", &lep_chargeIDBDTResult_recalc_rel207_loose_0, &b_lep_chargeIDBDTResult_recalc_rel207_loose_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_0", &lep_chargeIDBDTResult_recalc_rel207_medium_0, &b_lep_chargeIDBDTResult_recalc_rel207_medium_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_0", &lep_chargeIDBDTResult_recalc_rel207_tight_0, &b_lep_chargeIDBDTResult_recalc_rel207_tight_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_0", &lep_promptLeptonInput_sv1_jf_ntrkv_0, &b_lep_promptLeptonInput_sv1_jf_ntrkv_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_0", &lep_promptLeptonInput_TrackJetNTrack_0, &b_lep_promptLeptonInput_TrackJetNTrack_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_0", &lep_promptLeptonInput_DL1mu_0, &b_lep_promptLeptonInput_DL1mu_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_0", &lep_promptLeptonInput_DRlj_0, &b_lep_promptLeptonInput_DRlj_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_0", &lep_promptLeptonInput_LepJetPtFrac_0, &b_lep_promptLeptonInput_LepJetPtFrac_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_0", &lep_promptLeptonInput_PtFrac_0, &b_lep_promptLeptonInput_PtFrac_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_0", &lep_promptLeptonInput_PtRel_0, &b_lep_promptLeptonInput_PtRel_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_0", &lep_promptLeptonInput_ip2_0, &b_lep_promptLeptonInput_ip2_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_0", &lep_promptLeptonInput_ip3_0, &b_lep_promptLeptonInput_ip3_0);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_0", &lep_promptLeptonInput_rnnip_0, &b_lep_promptLeptonInput_rnnip_0);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_0", &lep_promptLeptonIso_TagWeight_0, &b_lep_promptLeptonIso_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_0", &lep_promptLeptonVeto_TagWeight_0, &b_lep_promptLeptonVeto_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_0", &lep_promptLeptonImprovedVeto_TagWeight_0, &b_lep_promptLeptonImprovedVeto_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_0", &lep_promptLeptonImprovedVetoBARR_TagWeight_0, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_0", &lep_promptLeptonImprovedVetoECAP_TagWeight_0, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_0", &lep_PromptLeptonImprovedInput_MVAXBin_0, &b_lep_PromptLeptonImprovedInput_MVAXBin_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_0", &lep_PromptLeptonImprovedInput_PtFrac_0, &b_lep_PromptLeptonImprovedInput_PtFrac_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_0", &lep_PromptLeptonImprovedInput_DRlj_0, &b_lep_PromptLeptonImprovedInput_DRlj_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_0", &lep_PromptLeptonImprovedInput_reltopoetcone30_0, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_0", &lep_PromptLeptonImprovedInput_relptvarcone30_0, &b_lep_PromptLeptonImprovedInput_relptvarcone30_0);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_0", &lep_PromptLeptonRNN_prompt_0, &b_lep_PromptLeptonRNN_prompt_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_0", &lep_PromptLeptonImprovedInput_TrackJetNTrack_0, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_0", &lep_PromptLeptonImprovedInput_RelPt_0, &b_lep_PromptLeptonImprovedInput_RelPt_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_0", &lep_PromptLeptonImprovedInput_RelCaloClusterE_0, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0);
   fChain->SetBranchAddress("lep_jet_Pt_0", &lep_jet_Pt_0, &b_lep_jet_Pt_0);
   fChain->SetBranchAddress("lep_jet_nTrk_0", &lep_jet_nTrk_0, &b_lep_jet_nTrk_0);
   fChain->SetBranchAddress("lep_jet_sumPtTrk_0", &lep_jet_sumPtTrk_0, &b_lep_jet_sumPtTrk_0);
   fChain->SetBranchAddress("lep_jet_mv2c10_0", &lep_jet_mv2c10_0, &b_lep_jet_mv2c10_0);
   fChain->SetBranchAddress("lep_jet_deltaR_0", &lep_jet_deltaR_0, &b_lep_jet_deltaR_0);
   fChain->SetBranchAddress("lep_jet_ptRel_0", &lep_jet_ptRel_0, &b_lep_jet_ptRel_0);
   fChain->SetBranchAddress("lep_jet_ptOverMuPt_0", &lep_jet_ptOverMuPt_0, &b_lep_jet_ptOverMuPt_0);
   fChain->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   fChain->SetBranchAddress("lep_truthStatus_0", &lep_truthStatus_0, &b_lep_truthStatus_0);
   fChain->SetBranchAddress("lep_truthParentType_0", &lep_truthParentType_0, &b_lep_truthParentType_0);
   fChain->SetBranchAddress("lep_truthParentOrigin_0", &lep_truthParentOrigin_0, &b_lep_truthParentOrigin_0);
   fChain->SetBranchAddress("lep_truthParentPdgId_0", &lep_truthParentPdgId_0, &b_lep_truthParentPdgId_0);
   fChain->SetBranchAddress("lep_truthParentStatus_0", &lep_truthParentStatus_0, &b_lep_truthParentStatus_0);
   fChain->SetBranchAddress("lep_truthPt_0", &lep_truthPt_0, &b_lep_truthPt_0);
   fChain->SetBranchAddress("lep_truthEta_0", &lep_truthEta_0, &b_lep_truthEta_0);
   fChain->SetBranchAddress("lep_truthPhi_0", &lep_truthPhi_0, &b_lep_truthPhi_0);
   fChain->SetBranchAddress("lep_truthM_0", &lep_truthM_0, &b_lep_truthM_0);
   fChain->SetBranchAddress("lep_truthE_0", &lep_truthE_0, &b_lep_truthE_0);
   fChain->SetBranchAddress("lep_truthRapidity_0", &lep_truthRapidity_0, &b_lep_truthRapidity_0);
   fChain->SetBranchAddress("lep_ambiguityType_0", &lep_ambiguityType_0, &b_lep_ambiguityType_0);
   fChain->SetBranchAddress("lep_nInnerPix_0", &lep_nInnerPix_0, &b_lep_nInnerPix_0);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_0", &lep_firstEgMotherPdgId_0, &b_lep_firstEgMotherPdgId_0);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_0", &lep_firstEgMotherTruthType_0, &b_lep_firstEgMotherTruthType_0);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_0", &lep_firstEgMotherTruthOrigin_0, &b_lep_firstEgMotherTruthOrigin_0);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_0", &lep_lastEgMotherPdgId_0, &b_lep_lastEgMotherPdgId_0);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_0", &lep_lastEgMotherTruthType_0, &b_lep_lastEgMotherTruthType_0);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_0", &lep_lastEgMotherTruthOrigin_0, &b_lep_lastEgMotherTruthOrigin_0);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_0", &lep_SF_El_Reco_AT_0, &b_lep_SF_El_Reco_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_0", &lep_SF_El_ID_LooseAndBLayerLH_AT_0, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_0", &lep_SF_El_ID_TightLH_AT_0, &b_lep_SF_El_ID_TightLH_AT_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_0", &lep_SF_El_Iso_FCLoose_AT_0, &b_lep_SF_El_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_0", &lep_SF_El_FCLooseTightLHQMisID_0, &b_lep_SF_El_FCLooseTightLHQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_0", &lep_SF_El_Iso_FCLoose_TightLH_0, &b_lep_SF_El_Iso_FCLoose_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_0", &lep_SF_El_PLVTight_QmisID_0, &b_lep_SF_El_PLVTight_QmisID_0);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_0", &lep_SF_El_PLVTight_0, &b_lep_SF_El_PLVTight_0);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_0", &lep_SF_El_PLVLoose_0, &b_lep_SF_El_PLVLoose_0);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_0", &lep_SF_El_ID_MediumLH_0, &b_lep_SF_El_ID_MediumLH_0);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_0", &lep_SF_Mu_TTVA_AT_0, &b_lep_SF_Mu_TTVA_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_0", &lep_SF_Mu_ID_Loose_AT_0, &b_lep_SF_Mu_ID_Loose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_0", &lep_SF_Mu_ID_Medium_AT_0, &b_lep_SF_Mu_ID_Medium_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_0", &lep_SF_Mu_Iso_FCLoose_AT_0, &b_lep_SF_Mu_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_0", &lep_SF_Mu_ID_Tight_0, &b_lep_SF_Mu_ID_Tight_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_0", &lep_SF_Mu_PLVTight_0, &b_lep_SF_Mu_PLVTight_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_0", &lep_SF_Mu_PLVLoose_0, &b_lep_SF_Mu_PLVLoose_0);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_0", &lep_SF_CombinedLoose_0, &b_lep_SF_CombinedLoose_0);
   fChain->SetBranchAddress("lep_SF_CombinedTight_0", &lep_SF_CombinedTight_0, &b_lep_SF_CombinedTight_0);
   fChain->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   fChain->SetBranchAddress("lep_Index_1", &lep_Index_1, &b_lep_Index_1);
   fChain->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   fChain->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   fChain->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   fChain->SetBranchAddress("lep_EtaBE2_1", &lep_EtaBE2_1, &b_lep_EtaBE2_1);
   fChain->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   fChain->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   fChain->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   fChain->SetBranchAddress("lep_d0_1", &lep_d0_1, &b_lep_d0_1);
   fChain->SetBranchAddress("lep_z0_1", &lep_z0_1, &b_lep_z0_1);
   fChain->SetBranchAddress("lep_vz_1", &lep_vz_1, &b_lep_vz_1);
   fChain->SetBranchAddress("lep_deltaz0_1", &lep_deltaz0_1, &b_lep_deltaz0_1);
   fChain->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   fChain->SetBranchAddress("lep_isMediumLH_1", &lep_isMediumLH_1, &b_lep_isMediumLH_1);
   fChain->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   fChain->SetBranchAddress("lep_isTight_1", &lep_isTight_1, &b_lep_isTight_1);
   fChain->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   fChain->SetBranchAddress("lep_isLoose_1", &lep_isLoose_1, &b_lep_isLoose_1);
   fChain->SetBranchAddress("lep_isolationFCTight_1", &lep_isolationFCTight_1, &b_lep_isolationFCTight_1);
   fChain->SetBranchAddress("lep_isolationLoose_1", &lep_isolationLoose_1, &b_lep_isolationLoose_1);
   fChain->SetBranchAddress("lep_isolationGradient_1", &lep_isolationGradient_1, &b_lep_isolationGradient_1);
   fChain->SetBranchAddress("lep_isolationGradientLoose_1", &lep_isolationGradientLoose_1, &b_lep_isolationGradientLoose_1);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_1", &lep_isolationTightTrackOnly_1, &b_lep_isolationTightTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationFCLoose_1", &lep_isolationFCLoose_1, &b_lep_isolationFCLoose_1);
   fChain->SetBranchAddress("lep_isolationPflowTight_1", &lep_isolationPflowTight_1, &b_lep_isolationPflowTight_1);
   fChain->SetBranchAddress("lep_isolationPflowLoose_1", &lep_isolationPflowLoose_1, &b_lep_isolationPflowLoose_1);
   fChain->SetBranchAddress("lep_plvWP_Loose_1", &lep_plvWP_Loose_1, &b_lep_plvWP_Loose_1);
   fChain->SetBranchAddress("lep_plvWP_Tight_1", &lep_plvWP_Tight_1, &b_lep_plvWP_Tight_1);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1, &b_lep_isTrigMatchDLT_1);
   fChain->SetBranchAddress("lep_isPrompt_1", &lep_isPrompt_1, &b_lep_isPrompt_1);
   fChain->SetBranchAddress("lep_isFakeLep_1", &lep_isFakeLep_1, &b_lep_isFakeLep_1);
   fChain->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1, &b_lep_isQMisID_1);
   fChain->SetBranchAddress("lep_isConvPh_1", &lep_isConvPh_1, &b_lep_isConvPh_1);
   fChain->SetBranchAddress("lep_isExtConvPh_1", &lep_isExtConvPh_1, &b_lep_isExtConvPh_1);
   fChain->SetBranchAddress("lep_isIntConvPh_1", &lep_isIntConvPh_1, &b_lep_isIntConvPh_1);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_1", &lep_isISR_FSR_Ph_1, &b_lep_isISR_FSR_Ph_1);
   fChain->SetBranchAddress("lep_isBrems_1", &lep_isBrems_1, &b_lep_isBrems_1);
   fChain->SetBranchAddress("lep_nTrackParticles_1", &lep_nTrackParticles_1, &b_lep_nTrackParticles_1);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_1", &lep_Mtrktrk_atPV_CO_1, &b_lep_Mtrktrk_atPV_CO_1);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_1", &lep_Mtrktrk_atConvV_CO_1, &b_lep_Mtrktrk_atConvV_CO_1);
   fChain->SetBranchAddress("lep_RadiusCO_1", &lep_RadiusCO_1, &b_lep_RadiusCO_1);
   fChain->SetBranchAddress("lep_RadiusCOX_1", &lep_RadiusCOX_1, &b_lep_RadiusCOX_1);
   fChain->SetBranchAddress("lep_RadiusCOY_1", &lep_RadiusCOY_1, &b_lep_RadiusCOY_1);
   fChain->SetBranchAddress("lep_SeparationMinDCT_1", &lep_SeparationMinDCT_1, &b_lep_SeparationMinDCT_1);
   fChain->SetBranchAddress("lep_ClosestSiTracknIL_1", &lep_ClosestSiTracknIL_1, &b_lep_ClosestSiTracknIL_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackeIL_1", &lep_ClosestSiTrackeIL_1, &b_lep_ClosestSiTrackeIL_1);
   fChain->SetBranchAddress("lep_ClosestSiTracknNIL_1", &lep_ClosestSiTracknNIL_1, &b_lep_ClosestSiTracknNIL_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackeNIL_1", &lep_ClosestSiTrackeNIL_1, &b_lep_ClosestSiTrackeNIL_1);
   fChain->SetBranchAddress("lep_BestMatchTrackPt_1", &lep_BestMatchTrackPt_1, &b_lep_BestMatchTrackPt_1);
   fChain->SetBranchAddress("lep_BestMatchTrackEta_1", &lep_BestMatchTrackEta_1, &b_lep_BestMatchTrackEta_1);
   fChain->SetBranchAddress("lep_BestMatchTrackPhi_1", &lep_BestMatchTrackPhi_1, &b_lep_BestMatchTrackPhi_1);
   fChain->SetBranchAddress("lep_BestMatchTrackD0_1", &lep_BestMatchTrackD0_1, &b_lep_BestMatchTrackD0_1);
   fChain->SetBranchAddress("lep_BestMatchTrackZ0_1", &lep_BestMatchTrackZ0_1, &b_lep_BestMatchTrackZ0_1);
   fChain->SetBranchAddress("lep_BestMatchTrackQ_1", &lep_BestMatchTrackQ_1, &b_lep_BestMatchTrackQ_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackPt_1", &lep_ClosestSiTrackPt_1, &b_lep_ClosestSiTrackPt_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackEta_1", &lep_ClosestSiTrackEta_1, &b_lep_ClosestSiTrackEta_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackPhi_1", &lep_ClosestSiTrackPhi_1, &b_lep_ClosestSiTrackPhi_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackD0_1", &lep_ClosestSiTrackD0_1, &b_lep_ClosestSiTrackD0_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackZ0_1", &lep_ClosestSiTrackZ0_1, &b_lep_ClosestSiTrackZ0_1);
   fChain->SetBranchAddress("lep_ClosestSiTrackQ_1", &lep_ClosestSiTrackQ_1, &b_lep_ClosestSiTrackQ_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_1", &lep_DFCommonSimpleConvRadius_1, &b_lep_DFCommonSimpleConvRadius_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_1", &lep_DFCommonSimpleConvPhi_1, &b_lep_DFCommonSimpleConvPhi_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_1", &lep_DFCommonSimpleMee_1, &b_lep_DFCommonSimpleMee_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_1", &lep_DFCommonSimpleMeeAtVtx_1, &b_lep_DFCommonSimpleMeeAtVtx_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_1", &lep_DFCommonSimpleSeparation_1, &b_lep_DFCommonSimpleSeparation_1);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_1", &lep_DFCommonAddAmbiguity_1, &b_lep_DFCommonAddAmbiguity_1);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_1", &lep_DFCommonProdTrueRadius_1, &b_lep_DFCommonProdTrueRadius_1);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_1", &lep_DFCommonProdTruePhi_1, &b_lep_DFCommonProdTruePhi_1);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_1", &lep_DFCommonProdTrueZ_1, &b_lep_DFCommonProdTrueZ_1);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_1", &lep_chargeIDBDTLoose_1, &b_lep_chargeIDBDTLoose_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_1", &lep_chargeIDBDTResult_1, &b_lep_chargeIDBDTResult_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_1", &lep_chargeIDBDTResult_recalc_rel207_loose_1, &b_lep_chargeIDBDTResult_recalc_rel207_loose_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_1", &lep_chargeIDBDTResult_recalc_rel207_medium_1, &b_lep_chargeIDBDTResult_recalc_rel207_medium_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_1", &lep_chargeIDBDTResult_recalc_rel207_tight_1, &b_lep_chargeIDBDTResult_recalc_rel207_tight_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_1", &lep_promptLeptonInput_sv1_jf_ntrkv_1, &b_lep_promptLeptonInput_sv1_jf_ntrkv_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_1", &lep_promptLeptonInput_TrackJetNTrack_1, &b_lep_promptLeptonInput_TrackJetNTrack_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_1", &lep_promptLeptonInput_DL1mu_1, &b_lep_promptLeptonInput_DL1mu_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_1", &lep_promptLeptonInput_DRlj_1, &b_lep_promptLeptonInput_DRlj_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_1", &lep_promptLeptonInput_LepJetPtFrac_1, &b_lep_promptLeptonInput_LepJetPtFrac_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_1", &lep_promptLeptonInput_PtFrac_1, &b_lep_promptLeptonInput_PtFrac_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_1", &lep_promptLeptonInput_PtRel_1, &b_lep_promptLeptonInput_PtRel_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_1", &lep_promptLeptonInput_ip2_1, &b_lep_promptLeptonInput_ip2_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_1", &lep_promptLeptonInput_ip3_1, &b_lep_promptLeptonInput_ip3_1);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_1", &lep_promptLeptonInput_rnnip_1, &b_lep_promptLeptonInput_rnnip_1);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_1", &lep_promptLeptonIso_TagWeight_1, &b_lep_promptLeptonIso_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_1", &lep_promptLeptonVeto_TagWeight_1, &b_lep_promptLeptonVeto_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_1", &lep_promptLeptonImprovedVeto_TagWeight_1, &b_lep_promptLeptonImprovedVeto_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_1", &lep_promptLeptonImprovedVetoBARR_TagWeight_1, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_1", &lep_promptLeptonImprovedVetoECAP_TagWeight_1, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_1", &lep_PromptLeptonImprovedInput_MVAXBin_1, &b_lep_PromptLeptonImprovedInput_MVAXBin_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_1", &lep_PromptLeptonImprovedInput_PtFrac_1, &b_lep_PromptLeptonImprovedInput_PtFrac_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_1", &lep_PromptLeptonImprovedInput_DRlj_1, &b_lep_PromptLeptonImprovedInput_DRlj_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_1", &lep_PromptLeptonImprovedInput_reltopoetcone30_1, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_1", &lep_PromptLeptonImprovedInput_relptvarcone30_1, &b_lep_PromptLeptonImprovedInput_relptvarcone30_1);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_1", &lep_PromptLeptonRNN_prompt_1, &b_lep_PromptLeptonRNN_prompt_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_1", &lep_PromptLeptonImprovedInput_TrackJetNTrack_1, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_1", &lep_PromptLeptonImprovedInput_RelPt_1, &b_lep_PromptLeptonImprovedInput_RelPt_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_1", &lep_PromptLeptonImprovedInput_RelCaloClusterE_1, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1);
   fChain->SetBranchAddress("lep_jet_Pt_1", &lep_jet_Pt_1, &b_lep_jet_Pt_1);
   fChain->SetBranchAddress("lep_jet_nTrk_1", &lep_jet_nTrk_1, &b_lep_jet_nTrk_1);
   fChain->SetBranchAddress("lep_jet_sumPtTrk_1", &lep_jet_sumPtTrk_1, &b_lep_jet_sumPtTrk_1);
   fChain->SetBranchAddress("lep_jet_mv2c10_1", &lep_jet_mv2c10_1, &b_lep_jet_mv2c10_1);
   fChain->SetBranchAddress("lep_jet_deltaR_1", &lep_jet_deltaR_1, &b_lep_jet_deltaR_1);
   fChain->SetBranchAddress("lep_jet_ptRel_1", &lep_jet_ptRel_1, &b_lep_jet_ptRel_1);
   fChain->SetBranchAddress("lep_jet_ptOverMuPt_1", &lep_jet_ptOverMuPt_1, &b_lep_jet_ptOverMuPt_1);
   fChain->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   fChain->SetBranchAddress("lep_truthStatus_1", &lep_truthStatus_1, &b_lep_truthStatus_1);
   fChain->SetBranchAddress("lep_truthParentType_1", &lep_truthParentType_1, &b_lep_truthParentType_1);
   fChain->SetBranchAddress("lep_truthParentOrigin_1", &lep_truthParentOrigin_1, &b_lep_truthParentOrigin_1);
   fChain->SetBranchAddress("lep_truthParentPdgId_1", &lep_truthParentPdgId_1, &b_lep_truthParentPdgId_1);
   fChain->SetBranchAddress("lep_truthParentStatus_1", &lep_truthParentStatus_1, &b_lep_truthParentStatus_1);
   fChain->SetBranchAddress("lep_truthPt_1", &lep_truthPt_1, &b_lep_truthPt_1);
   fChain->SetBranchAddress("lep_truthEta_1", &lep_truthEta_1, &b_lep_truthEta_1);
   fChain->SetBranchAddress("lep_truthPhi_1", &lep_truthPhi_1, &b_lep_truthPhi_1);
   fChain->SetBranchAddress("lep_truthM_1", &lep_truthM_1, &b_lep_truthM_1);
   fChain->SetBranchAddress("lep_truthE_1", &lep_truthE_1, &b_lep_truthE_1);
   fChain->SetBranchAddress("lep_truthRapidity_1", &lep_truthRapidity_1, &b_lep_truthRapidity_1);
   fChain->SetBranchAddress("lep_ambiguityType_1", &lep_ambiguityType_1, &b_lep_ambiguityType_1);
   fChain->SetBranchAddress("lep_nInnerPix_1", &lep_nInnerPix_1, &b_lep_nInnerPix_1);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_1", &lep_firstEgMotherPdgId_1, &b_lep_firstEgMotherPdgId_1);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_1", &lep_firstEgMotherTruthType_1, &b_lep_firstEgMotherTruthType_1);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_1", &lep_firstEgMotherTruthOrigin_1, &b_lep_firstEgMotherTruthOrigin_1);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_1", &lep_lastEgMotherPdgId_1, &b_lep_lastEgMotherPdgId_1);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_1", &lep_lastEgMotherTruthType_1, &b_lep_lastEgMotherTruthType_1);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_1", &lep_lastEgMotherTruthOrigin_1, &b_lep_lastEgMotherTruthOrigin_1);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_1", &lep_SF_El_Reco_AT_1, &b_lep_SF_El_Reco_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_1", &lep_SF_El_ID_LooseAndBLayerLH_AT_1, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_1", &lep_SF_El_ID_TightLH_AT_1, &b_lep_SF_El_ID_TightLH_AT_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_1", &lep_SF_El_Iso_FCLoose_AT_1, &b_lep_SF_El_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_1", &lep_SF_El_FCLooseTightLHQMisID_1, &b_lep_SF_El_FCLooseTightLHQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_1", &lep_SF_El_Iso_FCLoose_TightLH_1, &b_lep_SF_El_Iso_FCLoose_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_1", &lep_SF_El_PLVTight_QmisID_1, &b_lep_SF_El_PLVTight_QmisID_1);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_1", &lep_SF_El_PLVTight_1, &b_lep_SF_El_PLVTight_1);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_1", &lep_SF_El_PLVLoose_1, &b_lep_SF_El_PLVLoose_1);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_1", &lep_SF_El_ID_MediumLH_1, &b_lep_SF_El_ID_MediumLH_1);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_1", &lep_SF_Mu_TTVA_AT_1, &b_lep_SF_Mu_TTVA_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_1", &lep_SF_Mu_ID_Loose_AT_1, &b_lep_SF_Mu_ID_Loose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_1", &lep_SF_Mu_ID_Medium_AT_1, &b_lep_SF_Mu_ID_Medium_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_1", &lep_SF_Mu_Iso_FCLoose_AT_1, &b_lep_SF_Mu_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_1", &lep_SF_Mu_ID_Tight_1, &b_lep_SF_Mu_ID_Tight_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_1", &lep_SF_Mu_PLVTight_1, &b_lep_SF_Mu_PLVTight_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_1", &lep_SF_Mu_PLVLoose_1, &b_lep_SF_Mu_PLVLoose_1);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_1", &lep_SF_CombinedLoose_1, &b_lep_SF_CombinedLoose_1);
   fChain->SetBranchAddress("lep_SF_CombinedTight_1", &lep_SF_CombinedTight_1, &b_lep_SF_CombinedTight_1);
   fChain->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   fChain->SetBranchAddress("lep_Index_2", &lep_Index_2, &b_lep_Index_2);
   fChain->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   fChain->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   fChain->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   fChain->SetBranchAddress("lep_EtaBE2_2", &lep_EtaBE2_2, &b_lep_EtaBE2_2);
   fChain->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   fChain->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   fChain->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   fChain->SetBranchAddress("lep_d0_2", &lep_d0_2, &b_lep_d0_2);
   fChain->SetBranchAddress("lep_z0_2", &lep_z0_2, &b_lep_z0_2);
   fChain->SetBranchAddress("lep_vz_2", &lep_vz_2, &b_lep_vz_2);
   fChain->SetBranchAddress("lep_deltaz0_2", &lep_deltaz0_2, &b_lep_deltaz0_2);
   fChain->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   fChain->SetBranchAddress("lep_isMediumLH_2", &lep_isMediumLH_2, &b_lep_isMediumLH_2);
   fChain->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   fChain->SetBranchAddress("lep_isTight_2", &lep_isTight_2, &b_lep_isTight_2);
   fChain->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   fChain->SetBranchAddress("lep_isLoose_2", &lep_isLoose_2, &b_lep_isLoose_2);
   fChain->SetBranchAddress("lep_isolationFCTight_2", &lep_isolationFCTight_2, &b_lep_isolationFCTight_2);
   fChain->SetBranchAddress("lep_isolationLoose_2", &lep_isolationLoose_2, &b_lep_isolationLoose_2);
   fChain->SetBranchAddress("lep_isolationGradient_2", &lep_isolationGradient_2, &b_lep_isolationGradient_2);
   fChain->SetBranchAddress("lep_isolationGradientLoose_2", &lep_isolationGradientLoose_2, &b_lep_isolationGradientLoose_2);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_2", &lep_isolationTightTrackOnly_2, &b_lep_isolationTightTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationFCLoose_2", &lep_isolationFCLoose_2, &b_lep_isolationFCLoose_2);
   fChain->SetBranchAddress("lep_isolationPflowTight_2", &lep_isolationPflowTight_2, &b_lep_isolationPflowTight_2);
   fChain->SetBranchAddress("lep_isolationPflowLoose_2", &lep_isolationPflowLoose_2, &b_lep_isolationPflowLoose_2);
   fChain->SetBranchAddress("lep_plvWP_Loose_2", &lep_plvWP_Loose_2, &b_lep_plvWP_Loose_2);
   fChain->SetBranchAddress("lep_plvWP_Tight_2", &lep_plvWP_Tight_2, &b_lep_plvWP_Tight_2);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2, &b_lep_isTrigMatchDLT_2);
   fChain->SetBranchAddress("lep_isPrompt_2", &lep_isPrompt_2, &b_lep_isPrompt_2);
   fChain->SetBranchAddress("lep_isFakeLep_2", &lep_isFakeLep_2, &b_lep_isFakeLep_2);
   fChain->SetBranchAddress("lep_isQMisID_2", &lep_isQMisID_2, &b_lep_isQMisID_2);
   fChain->SetBranchAddress("lep_isConvPh_2", &lep_isConvPh_2, &b_lep_isConvPh_2);
   fChain->SetBranchAddress("lep_isExtConvPh_2", &lep_isExtConvPh_2, &b_lep_isExtConvPh_2);
   fChain->SetBranchAddress("lep_isIntConvPh_2", &lep_isIntConvPh_2, &b_lep_isIntConvPh_2);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_2", &lep_isISR_FSR_Ph_2, &b_lep_isISR_FSR_Ph_2);
   fChain->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   fChain->SetBranchAddress("lep_nTrackParticles_2", &lep_nTrackParticles_2, &b_lep_nTrackParticles_2);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_2", &lep_Mtrktrk_atPV_CO_2, &b_lep_Mtrktrk_atPV_CO_2);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_2", &lep_Mtrktrk_atConvV_CO_2, &b_lep_Mtrktrk_atConvV_CO_2);
   fChain->SetBranchAddress("lep_RadiusCO_2", &lep_RadiusCO_2, &b_lep_RadiusCO_2);
   fChain->SetBranchAddress("lep_RadiusCOX_2", &lep_RadiusCOX_2, &b_lep_RadiusCOX_2);
   fChain->SetBranchAddress("lep_RadiusCOY_2", &lep_RadiusCOY_2, &b_lep_RadiusCOY_2);
   fChain->SetBranchAddress("lep_SeparationMinDCT_2", &lep_SeparationMinDCT_2, &b_lep_SeparationMinDCT_2);
   fChain->SetBranchAddress("lep_ClosestSiTracknIL_2", &lep_ClosestSiTracknIL_2, &b_lep_ClosestSiTracknIL_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackeIL_2", &lep_ClosestSiTrackeIL_2, &b_lep_ClosestSiTrackeIL_2);
   fChain->SetBranchAddress("lep_ClosestSiTracknNIL_2", &lep_ClosestSiTracknNIL_2, &b_lep_ClosestSiTracknNIL_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackeNIL_2", &lep_ClosestSiTrackeNIL_2, &b_lep_ClosestSiTrackeNIL_2);
   fChain->SetBranchAddress("lep_BestMatchTrackPt_2", &lep_BestMatchTrackPt_2, &b_lep_BestMatchTrackPt_2);
   fChain->SetBranchAddress("lep_BestMatchTrackEta_2", &lep_BestMatchTrackEta_2, &b_lep_BestMatchTrackEta_2);
   fChain->SetBranchAddress("lep_BestMatchTrackPhi_2", &lep_BestMatchTrackPhi_2, &b_lep_BestMatchTrackPhi_2);
   fChain->SetBranchAddress("lep_BestMatchTrackD0_2", &lep_BestMatchTrackD0_2, &b_lep_BestMatchTrackD0_2);
   fChain->SetBranchAddress("lep_BestMatchTrackZ0_2", &lep_BestMatchTrackZ0_2, &b_lep_BestMatchTrackZ0_2);
   fChain->SetBranchAddress("lep_BestMatchTrackQ_2", &lep_BestMatchTrackQ_2, &b_lep_BestMatchTrackQ_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackPt_2", &lep_ClosestSiTrackPt_2, &b_lep_ClosestSiTrackPt_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackEta_2", &lep_ClosestSiTrackEta_2, &b_lep_ClosestSiTrackEta_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackPhi_2", &lep_ClosestSiTrackPhi_2, &b_lep_ClosestSiTrackPhi_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackD0_2", &lep_ClosestSiTrackD0_2, &b_lep_ClosestSiTrackD0_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackZ0_2", &lep_ClosestSiTrackZ0_2, &b_lep_ClosestSiTrackZ0_2);
   fChain->SetBranchAddress("lep_ClosestSiTrackQ_2", &lep_ClosestSiTrackQ_2, &b_lep_ClosestSiTrackQ_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_2", &lep_DFCommonSimpleConvRadius_2, &b_lep_DFCommonSimpleConvRadius_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_2", &lep_DFCommonSimpleConvPhi_2, &b_lep_DFCommonSimpleConvPhi_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_2", &lep_DFCommonSimpleMee_2, &b_lep_DFCommonSimpleMee_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_2", &lep_DFCommonSimpleMeeAtVtx_2, &b_lep_DFCommonSimpleMeeAtVtx_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_2", &lep_DFCommonSimpleSeparation_2, &b_lep_DFCommonSimpleSeparation_2);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_2", &lep_DFCommonAddAmbiguity_2, &b_lep_DFCommonAddAmbiguity_2);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_2", &lep_DFCommonProdTrueRadius_2, &b_lep_DFCommonProdTrueRadius_2);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_2", &lep_DFCommonProdTruePhi_2, &b_lep_DFCommonProdTruePhi_2);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_2", &lep_DFCommonProdTrueZ_2, &b_lep_DFCommonProdTrueZ_2);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_2", &lep_chargeIDBDTLoose_2, &b_lep_chargeIDBDTLoose_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_2", &lep_chargeIDBDTResult_2, &b_lep_chargeIDBDTResult_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_2", &lep_chargeIDBDTResult_recalc_rel207_loose_2, &b_lep_chargeIDBDTResult_recalc_rel207_loose_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_2", &lep_chargeIDBDTResult_recalc_rel207_medium_2, &b_lep_chargeIDBDTResult_recalc_rel207_medium_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_2", &lep_chargeIDBDTResult_recalc_rel207_tight_2, &b_lep_chargeIDBDTResult_recalc_rel207_tight_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_2", &lep_promptLeptonInput_sv1_jf_ntrkv_2, &b_lep_promptLeptonInput_sv1_jf_ntrkv_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_2", &lep_promptLeptonInput_TrackJetNTrack_2, &b_lep_promptLeptonInput_TrackJetNTrack_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_2", &lep_promptLeptonInput_DL1mu_2, &b_lep_promptLeptonInput_DL1mu_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_2", &lep_promptLeptonInput_DRlj_2, &b_lep_promptLeptonInput_DRlj_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_2", &lep_promptLeptonInput_LepJetPtFrac_2, &b_lep_promptLeptonInput_LepJetPtFrac_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_2", &lep_promptLeptonInput_PtFrac_2, &b_lep_promptLeptonInput_PtFrac_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_2", &lep_promptLeptonInput_PtRel_2, &b_lep_promptLeptonInput_PtRel_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_2", &lep_promptLeptonInput_ip2_2, &b_lep_promptLeptonInput_ip2_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_2", &lep_promptLeptonInput_ip3_2, &b_lep_promptLeptonInput_ip3_2);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_2", &lep_promptLeptonInput_rnnip_2, &b_lep_promptLeptonInput_rnnip_2);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_2", &lep_promptLeptonIso_TagWeight_2, &b_lep_promptLeptonIso_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_2", &lep_promptLeptonVeto_TagWeight_2, &b_lep_promptLeptonVeto_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_2", &lep_promptLeptonImprovedVeto_TagWeight_2, &b_lep_promptLeptonImprovedVeto_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_2", &lep_promptLeptonImprovedVetoBARR_TagWeight_2, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_2", &lep_promptLeptonImprovedVetoECAP_TagWeight_2, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_2", &lep_PromptLeptonImprovedInput_MVAXBin_2, &b_lep_PromptLeptonImprovedInput_MVAXBin_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_2", &lep_PromptLeptonImprovedInput_PtFrac_2, &b_lep_PromptLeptonImprovedInput_PtFrac_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_2", &lep_PromptLeptonImprovedInput_DRlj_2, &b_lep_PromptLeptonImprovedInput_DRlj_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_2", &lep_PromptLeptonImprovedInput_reltopoetcone30_2, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_2", &lep_PromptLeptonImprovedInput_relptvarcone30_2, &b_lep_PromptLeptonImprovedInput_relptvarcone30_2);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_2", &lep_PromptLeptonRNN_prompt_2, &b_lep_PromptLeptonRNN_prompt_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_2", &lep_PromptLeptonImprovedInput_TrackJetNTrack_2, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_2", &lep_PromptLeptonImprovedInput_RelPt_2, &b_lep_PromptLeptonImprovedInput_RelPt_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_2", &lep_PromptLeptonImprovedInput_RelCaloClusterE_2, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2);
   fChain->SetBranchAddress("lep_jet_Pt_2", &lep_jet_Pt_2, &b_lep_jet_Pt_2);
   fChain->SetBranchAddress("lep_jet_nTrk_2", &lep_jet_nTrk_2, &b_lep_jet_nTrk_2);
   fChain->SetBranchAddress("lep_jet_sumPtTrk_2", &lep_jet_sumPtTrk_2, &b_lep_jet_sumPtTrk_2);
   fChain->SetBranchAddress("lep_jet_mv2c10_2", &lep_jet_mv2c10_2, &b_lep_jet_mv2c10_2);
   fChain->SetBranchAddress("lep_jet_deltaR_2", &lep_jet_deltaR_2, &b_lep_jet_deltaR_2);
   fChain->SetBranchAddress("lep_jet_ptRel_2", &lep_jet_ptRel_2, &b_lep_jet_ptRel_2);
   fChain->SetBranchAddress("lep_jet_ptOverMuPt_2", &lep_jet_ptOverMuPt_2, &b_lep_jet_ptOverMuPt_2);
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_truthStatus_2", &lep_truthStatus_2, &b_lep_truthStatus_2);
   fChain->SetBranchAddress("lep_truthParentType_2", &lep_truthParentType_2, &b_lep_truthParentType_2);
   fChain->SetBranchAddress("lep_truthParentOrigin_2", &lep_truthParentOrigin_2, &b_lep_truthParentOrigin_2);
   fChain->SetBranchAddress("lep_truthParentPdgId_2", &lep_truthParentPdgId_2, &b_lep_truthParentPdgId_2);
   fChain->SetBranchAddress("lep_truthParentStatus_2", &lep_truthParentStatus_2, &b_lep_truthParentStatus_2);
   fChain->SetBranchAddress("lep_truthPt_2", &lep_truthPt_2, &b_lep_truthPt_2);
   fChain->SetBranchAddress("lep_truthEta_2", &lep_truthEta_2, &b_lep_truthEta_2);
   fChain->SetBranchAddress("lep_truthPhi_2", &lep_truthPhi_2, &b_lep_truthPhi_2);
   fChain->SetBranchAddress("lep_truthM_2", &lep_truthM_2, &b_lep_truthM_2);
   fChain->SetBranchAddress("lep_truthE_2", &lep_truthE_2, &b_lep_truthE_2);
   fChain->SetBranchAddress("lep_truthRapidity_2", &lep_truthRapidity_2, &b_lep_truthRapidity_2);
   fChain->SetBranchAddress("lep_ambiguityType_2", &lep_ambiguityType_2, &b_lep_ambiguityType_2);
   fChain->SetBranchAddress("lep_nInnerPix_2", &lep_nInnerPix_2, &b_lep_nInnerPix_2);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_2", &lep_firstEgMotherPdgId_2, &b_lep_firstEgMotherPdgId_2);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_2", &lep_firstEgMotherTruthType_2, &b_lep_firstEgMotherTruthType_2);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_2", &lep_firstEgMotherTruthOrigin_2, &b_lep_firstEgMotherTruthOrigin_2);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_2", &lep_lastEgMotherPdgId_2, &b_lep_lastEgMotherPdgId_2);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_2", &lep_lastEgMotherTruthType_2, &b_lep_lastEgMotherTruthType_2);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_2", &lep_lastEgMotherTruthOrigin_2, &b_lep_lastEgMotherTruthOrigin_2);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_2", &lep_SF_El_Reco_AT_2, &b_lep_SF_El_Reco_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_2", &lep_SF_El_ID_LooseAndBLayerLH_AT_2, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_2", &lep_SF_El_ID_TightLH_AT_2, &b_lep_SF_El_ID_TightLH_AT_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_2", &lep_SF_El_Iso_FCLoose_AT_2, &b_lep_SF_El_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_2", &lep_SF_El_FCLooseTightLHQMisID_2, &b_lep_SF_El_FCLooseTightLHQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_2", &lep_SF_El_Iso_FCLoose_TightLH_2, &b_lep_SF_El_Iso_FCLoose_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_2", &lep_SF_El_PLVTight_QmisID_2, &b_lep_SF_El_PLVTight_QmisID_2);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_2", &lep_SF_El_PLVTight_2, &b_lep_SF_El_PLVTight_2);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_2", &lep_SF_El_PLVLoose_2, &b_lep_SF_El_PLVLoose_2);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_2", &lep_SF_El_ID_MediumLH_2, &b_lep_SF_El_ID_MediumLH_2);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_2", &lep_SF_Mu_TTVA_AT_2, &b_lep_SF_Mu_TTVA_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_2", &lep_SF_Mu_ID_Loose_AT_2, &b_lep_SF_Mu_ID_Loose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_2", &lep_SF_Mu_ID_Medium_AT_2, &b_lep_SF_Mu_ID_Medium_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_2", &lep_SF_Mu_Iso_FCLoose_AT_2, &b_lep_SF_Mu_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_2", &lep_SF_Mu_ID_Tight_2, &b_lep_SF_Mu_ID_Tight_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_2", &lep_SF_Mu_PLVTight_2, &b_lep_SF_Mu_PLVTight_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_2", &lep_SF_Mu_PLVLoose_2, &b_lep_SF_Mu_PLVLoose_2);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_2", &lep_SF_CombinedLoose_2, &b_lep_SF_CombinedLoose_2);
   fChain->SetBranchAddress("lep_SF_CombinedTight_2", &lep_SF_CombinedTight_2, &b_lep_SF_CombinedTight_2);
   fChain->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   fChain->SetBranchAddress("lep_Index_3", &lep_Index_3, &b_lep_Index_3);
   fChain->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   fChain->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   fChain->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   fChain->SetBranchAddress("lep_EtaBE2_3", &lep_EtaBE2_3, &b_lep_EtaBE2_3);
   fChain->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   fChain->SetBranchAddress("lep_sigd0PV_3", &lep_sigd0PV_3, &b_lep_sigd0PV_3);
   fChain->SetBranchAddress("lep_Z0SinTheta_3", &lep_Z0SinTheta_3, &b_lep_Z0SinTheta_3);
   fChain->SetBranchAddress("lep_d0_3", &lep_d0_3, &b_lep_d0_3);
   fChain->SetBranchAddress("lep_z0_3", &lep_z0_3, &b_lep_z0_3);
   fChain->SetBranchAddress("lep_vz_3", &lep_vz_3, &b_lep_vz_3);
   fChain->SetBranchAddress("lep_deltaz0_3", &lep_deltaz0_3, &b_lep_deltaz0_3);
   fChain->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   fChain->SetBranchAddress("lep_isMediumLH_3", &lep_isMediumLH_3, &b_lep_isMediumLH_3);
   fChain->SetBranchAddress("lep_isLooseLH_3", &lep_isLooseLH_3, &b_lep_isLooseLH_3);
   fChain->SetBranchAddress("lep_isTight_3", &lep_isTight_3, &b_lep_isTight_3);
   fChain->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   fChain->SetBranchAddress("lep_isLoose_3", &lep_isLoose_3, &b_lep_isLoose_3);
   fChain->SetBranchAddress("lep_isolationFCTight_3", &lep_isolationFCTight_3, &b_lep_isolationFCTight_3);
   fChain->SetBranchAddress("lep_isolationLoose_3", &lep_isolationLoose_3, &b_lep_isolationLoose_3);
   fChain->SetBranchAddress("lep_isolationGradient_3", &lep_isolationGradient_3, &b_lep_isolationGradient_3);
   fChain->SetBranchAddress("lep_isolationGradientLoose_3", &lep_isolationGradientLoose_3, &b_lep_isolationGradientLoose_3);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_3", &lep_isolationTightTrackOnly_3, &b_lep_isolationTightTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationFCLoose_3", &lep_isolationFCLoose_3, &b_lep_isolationFCLoose_3);
   fChain->SetBranchAddress("lep_isolationPflowTight_3", &lep_isolationPflowTight_3, &b_lep_isolationPflowTight_3);
   fChain->SetBranchAddress("lep_isolationPflowLoose_3", &lep_isolationPflowLoose_3, &b_lep_isolationPflowLoose_3);
   fChain->SetBranchAddress("lep_plvWP_Loose_3", &lep_plvWP_Loose_3, &b_lep_plvWP_Loose_3);
   fChain->SetBranchAddress("lep_plvWP_Tight_3", &lep_plvWP_Tight_3, &b_lep_plvWP_Tight_3);
   fChain->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3, &b_lep_isTrigMatch_3);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3, &b_lep_isTrigMatchDLT_3);
   fChain->SetBranchAddress("lep_isPrompt_3", &lep_isPrompt_3, &b_lep_isPrompt_3);
   fChain->SetBranchAddress("lep_isFakeLep_3", &lep_isFakeLep_3, &b_lep_isFakeLep_3);
   fChain->SetBranchAddress("lep_isQMisID_3", &lep_isQMisID_3, &b_lep_isQMisID_3);
   fChain->SetBranchAddress("lep_isConvPh_3", &lep_isConvPh_3, &b_lep_isConvPh_3);
   fChain->SetBranchAddress("lep_isExtConvPh_3", &lep_isExtConvPh_3, &b_lep_isExtConvPh_3);
   fChain->SetBranchAddress("lep_isIntConvPh_3", &lep_isIntConvPh_3, &b_lep_isIntConvPh_3);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_3", &lep_isISR_FSR_Ph_3, &b_lep_isISR_FSR_Ph_3);
   fChain->SetBranchAddress("lep_isBrems_3", &lep_isBrems_3, &b_lep_isBrems_3);
   fChain->SetBranchAddress("lep_nTrackParticles_3", &lep_nTrackParticles_3, &b_lep_nTrackParticles_3);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_3", &lep_Mtrktrk_atPV_CO_3, &b_lep_Mtrktrk_atPV_CO_3);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_3", &lep_Mtrktrk_atConvV_CO_3, &b_lep_Mtrktrk_atConvV_CO_3);
   fChain->SetBranchAddress("lep_RadiusCO_3", &lep_RadiusCO_3, &b_lep_RadiusCO_3);
   fChain->SetBranchAddress("lep_RadiusCOX_3", &lep_RadiusCOX_3, &b_lep_RadiusCOX_3);
   fChain->SetBranchAddress("lep_RadiusCOY_3", &lep_RadiusCOY_3, &b_lep_RadiusCOY_3);
   fChain->SetBranchAddress("lep_SeparationMinDCT_3", &lep_SeparationMinDCT_3, &b_lep_SeparationMinDCT_3);
   fChain->SetBranchAddress("lep_ClosestSiTracknIL_3", &lep_ClosestSiTracknIL_3, &b_lep_ClosestSiTracknIL_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackeIL_3", &lep_ClosestSiTrackeIL_3, &b_lep_ClosestSiTrackeIL_3);
   fChain->SetBranchAddress("lep_ClosestSiTracknNIL_3", &lep_ClosestSiTracknNIL_3, &b_lep_ClosestSiTracknNIL_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackeNIL_3", &lep_ClosestSiTrackeNIL_3, &b_lep_ClosestSiTrackeNIL_3);
   fChain->SetBranchAddress("lep_BestMatchTrackPt_3", &lep_BestMatchTrackPt_3, &b_lep_BestMatchTrackPt_3);
   fChain->SetBranchAddress("lep_BestMatchTrackEta_3", &lep_BestMatchTrackEta_3, &b_lep_BestMatchTrackEta_3);
   fChain->SetBranchAddress("lep_BestMatchTrackPhi_3", &lep_BestMatchTrackPhi_3, &b_lep_BestMatchTrackPhi_3);
   fChain->SetBranchAddress("lep_BestMatchTrackD0_3", &lep_BestMatchTrackD0_3, &b_lep_BestMatchTrackD0_3);
   fChain->SetBranchAddress("lep_BestMatchTrackZ0_3", &lep_BestMatchTrackZ0_3, &b_lep_BestMatchTrackZ0_3);
   fChain->SetBranchAddress("lep_BestMatchTrackQ_3", &lep_BestMatchTrackQ_3, &b_lep_BestMatchTrackQ_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackPt_3", &lep_ClosestSiTrackPt_3, &b_lep_ClosestSiTrackPt_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackEta_3", &lep_ClosestSiTrackEta_3, &b_lep_ClosestSiTrackEta_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackPhi_3", &lep_ClosestSiTrackPhi_3, &b_lep_ClosestSiTrackPhi_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackD0_3", &lep_ClosestSiTrackD0_3, &b_lep_ClosestSiTrackD0_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackZ0_3", &lep_ClosestSiTrackZ0_3, &b_lep_ClosestSiTrackZ0_3);
   fChain->SetBranchAddress("lep_ClosestSiTrackQ_3", &lep_ClosestSiTrackQ_3, &b_lep_ClosestSiTrackQ_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_3", &lep_DFCommonSimpleConvRadius_3, &b_lep_DFCommonSimpleConvRadius_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_3", &lep_DFCommonSimpleConvPhi_3, &b_lep_DFCommonSimpleConvPhi_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_3", &lep_DFCommonSimpleMee_3, &b_lep_DFCommonSimpleMee_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_3", &lep_DFCommonSimpleMeeAtVtx_3, &b_lep_DFCommonSimpleMeeAtVtx_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_3", &lep_DFCommonSimpleSeparation_3, &b_lep_DFCommonSimpleSeparation_3);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_3", &lep_DFCommonAddAmbiguity_3, &b_lep_DFCommonAddAmbiguity_3);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_3", &lep_DFCommonProdTrueRadius_3, &b_lep_DFCommonProdTrueRadius_3);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_3", &lep_DFCommonProdTruePhi_3, &b_lep_DFCommonProdTruePhi_3);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_3", &lep_DFCommonProdTrueZ_3, &b_lep_DFCommonProdTrueZ_3);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_3", &lep_chargeIDBDTLoose_3, &b_lep_chargeIDBDTLoose_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_3", &lep_chargeIDBDTResult_3, &b_lep_chargeIDBDTResult_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_3", &lep_chargeIDBDTResult_recalc_rel207_loose_3, &b_lep_chargeIDBDTResult_recalc_rel207_loose_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_3", &lep_chargeIDBDTResult_recalc_rel207_medium_3, &b_lep_chargeIDBDTResult_recalc_rel207_medium_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_3", &lep_chargeIDBDTResult_recalc_rel207_tight_3, &b_lep_chargeIDBDTResult_recalc_rel207_tight_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_3", &lep_promptLeptonInput_sv1_jf_ntrkv_3, &b_lep_promptLeptonInput_sv1_jf_ntrkv_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_3", &lep_promptLeptonInput_TrackJetNTrack_3, &b_lep_promptLeptonInput_TrackJetNTrack_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_3", &lep_promptLeptonInput_DL1mu_3, &b_lep_promptLeptonInput_DL1mu_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_3", &lep_promptLeptonInput_DRlj_3, &b_lep_promptLeptonInput_DRlj_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_3", &lep_promptLeptonInput_LepJetPtFrac_3, &b_lep_promptLeptonInput_LepJetPtFrac_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_3", &lep_promptLeptonInput_PtFrac_3, &b_lep_promptLeptonInput_PtFrac_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_3", &lep_promptLeptonInput_PtRel_3, &b_lep_promptLeptonInput_PtRel_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_3", &lep_promptLeptonInput_ip2_3, &b_lep_promptLeptonInput_ip2_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_3", &lep_promptLeptonInput_ip3_3, &b_lep_promptLeptonInput_ip3_3);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_3", &lep_promptLeptonInput_rnnip_3, &b_lep_promptLeptonInput_rnnip_3);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_3", &lep_promptLeptonIso_TagWeight_3, &b_lep_promptLeptonIso_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_3", &lep_promptLeptonVeto_TagWeight_3, &b_lep_promptLeptonVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_3", &lep_promptLeptonImprovedVeto_TagWeight_3, &b_lep_promptLeptonImprovedVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_3", &lep_promptLeptonImprovedVetoBARR_TagWeight_3, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_3", &lep_promptLeptonImprovedVetoECAP_TagWeight_3, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_3", &lep_PromptLeptonImprovedInput_MVAXBin_3, &b_lep_PromptLeptonImprovedInput_MVAXBin_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_3", &lep_PromptLeptonImprovedInput_PtFrac_3, &b_lep_PromptLeptonImprovedInput_PtFrac_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_3", &lep_PromptLeptonImprovedInput_DRlj_3, &b_lep_PromptLeptonImprovedInput_DRlj_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_3", &lep_PromptLeptonImprovedInput_reltopoetcone30_3, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_3", &lep_PromptLeptonImprovedInput_relptvarcone30_3, &b_lep_PromptLeptonImprovedInput_relptvarcone30_3);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_3", &lep_PromptLeptonRNN_prompt_3, &b_lep_PromptLeptonRNN_prompt_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_3", &lep_PromptLeptonImprovedInput_TrackJetNTrack_3, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_3", &lep_PromptLeptonImprovedInput_RelPt_3, &b_lep_PromptLeptonImprovedInput_RelPt_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_3", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_3, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_3", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_3, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_3", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_3, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_3", &lep_PromptLeptonImprovedInput_RelCaloClusterE_3, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_3", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_3, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_3);
   fChain->SetBranchAddress("lep_jet_Pt_3", &lep_jet_Pt_3, &b_lep_jet_Pt_3);
   fChain->SetBranchAddress("lep_jet_nTrk_3", &lep_jet_nTrk_3, &b_lep_jet_nTrk_3);
   fChain->SetBranchAddress("lep_jet_sumPtTrk_3", &lep_jet_sumPtTrk_3, &b_lep_jet_sumPtTrk_3);
   fChain->SetBranchAddress("lep_jet_mv2c10_3", &lep_jet_mv2c10_3, &b_lep_jet_mv2c10_3);
   fChain->SetBranchAddress("lep_jet_deltaR_3", &lep_jet_deltaR_3, &b_lep_jet_deltaR_3);
   fChain->SetBranchAddress("lep_jet_ptRel_3", &lep_jet_ptRel_3, &b_lep_jet_ptRel_3);
   fChain->SetBranchAddress("lep_jet_ptOverMuPt_3", &lep_jet_ptOverMuPt_3, &b_lep_jet_ptOverMuPt_3);
   fChain->SetBranchAddress("lep_isTruthMatched_3", &lep_isTruthMatched_3, &b_lep_isTruthMatched_3);
   fChain->SetBranchAddress("lep_truthType_3", &lep_truthType_3, &b_lep_truthType_3);
   fChain->SetBranchAddress("lep_truthOrigin_3", &lep_truthOrigin_3, &b_lep_truthOrigin_3);
   fChain->SetBranchAddress("lep_truthPdgId_3", &lep_truthPdgId_3, &b_lep_truthPdgId_3);
   fChain->SetBranchAddress("lep_truthStatus_3", &lep_truthStatus_3, &b_lep_truthStatus_3);
   fChain->SetBranchAddress("lep_truthParentType_3", &lep_truthParentType_3, &b_lep_truthParentType_3);
   fChain->SetBranchAddress("lep_truthParentOrigin_3", &lep_truthParentOrigin_3, &b_lep_truthParentOrigin_3);
   fChain->SetBranchAddress("lep_truthParentPdgId_3", &lep_truthParentPdgId_3, &b_lep_truthParentPdgId_3);
   fChain->SetBranchAddress("lep_truthParentStatus_3", &lep_truthParentStatus_3, &b_lep_truthParentStatus_3);
   fChain->SetBranchAddress("lep_truthPt_3", &lep_truthPt_3, &b_lep_truthPt_3);
   fChain->SetBranchAddress("lep_truthEta_3", &lep_truthEta_3, &b_lep_truthEta_3);
   fChain->SetBranchAddress("lep_truthPhi_3", &lep_truthPhi_3, &b_lep_truthPhi_3);
   fChain->SetBranchAddress("lep_truthM_3", &lep_truthM_3, &b_lep_truthM_3);
   fChain->SetBranchAddress("lep_truthE_3", &lep_truthE_3, &b_lep_truthE_3);
   fChain->SetBranchAddress("lep_truthRapidity_3", &lep_truthRapidity_3, &b_lep_truthRapidity_3);
   fChain->SetBranchAddress("lep_ambiguityType_3", &lep_ambiguityType_3, &b_lep_ambiguityType_3);
   fChain->SetBranchAddress("lep_nInnerPix_3", &lep_nInnerPix_3, &b_lep_nInnerPix_3);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_3", &lep_firstEgMotherPdgId_3, &b_lep_firstEgMotherPdgId_3);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_3", &lep_firstEgMotherTruthType_3, &b_lep_firstEgMotherTruthType_3);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_3", &lep_firstEgMotherTruthOrigin_3, &b_lep_firstEgMotherTruthOrigin_3);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_3", &lep_lastEgMotherPdgId_3, &b_lep_lastEgMotherPdgId_3);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_3", &lep_lastEgMotherTruthType_3, &b_lep_lastEgMotherTruthType_3);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_3", &lep_lastEgMotherTruthOrigin_3, &b_lep_lastEgMotherTruthOrigin_3);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_3", &lep_SF_El_Reco_AT_3, &b_lep_SF_El_Reco_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_3", &lep_SF_El_ID_LooseAndBLayerLH_AT_3, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_3", &lep_SF_El_ID_TightLH_AT_3, &b_lep_SF_El_ID_TightLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_3", &lep_SF_El_Iso_FCLoose_AT_3, &b_lep_SF_El_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_3", &lep_SF_El_FCLooseTightLHQMisID_3, &b_lep_SF_El_FCLooseTightLHQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_3", &lep_SF_El_Iso_FCLoose_TightLH_3, &b_lep_SF_El_Iso_FCLoose_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_3", &lep_SF_El_PLVTight_QmisID_3, &b_lep_SF_El_PLVTight_QmisID_3);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_3", &lep_SF_El_PLVTight_3, &b_lep_SF_El_PLVTight_3);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_3", &lep_SF_El_PLVLoose_3, &b_lep_SF_El_PLVLoose_3);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_3", &lep_SF_El_ID_MediumLH_3, &b_lep_SF_El_ID_MediumLH_3);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_3", &lep_SF_Mu_TTVA_AT_3, &b_lep_SF_Mu_TTVA_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_3", &lep_SF_Mu_ID_Loose_AT_3, &b_lep_SF_Mu_ID_Loose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_3", &lep_SF_Mu_ID_Medium_AT_3, &b_lep_SF_Mu_ID_Medium_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_3", &lep_SF_Mu_Iso_FCLoose_AT_3, &b_lep_SF_Mu_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_3", &lep_SF_Mu_ID_Tight_3, &b_lep_SF_Mu_ID_Tight_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_3", &lep_SF_Mu_PLVTight_3, &b_lep_SF_Mu_PLVTight_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_3", &lep_SF_Mu_PLVLoose_3, &b_lep_SF_Mu_PLVLoose_3);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_3", &lep_SF_CombinedLoose_3, &b_lep_SF_CombinedLoose_3);
   fChain->SetBranchAddress("lep_SF_CombinedTight_3", &lep_SF_CombinedTight_3, &b_lep_SF_CombinedTight_3);
   fChain->SetBranchAddress("lep_ID_4", &lep_ID_4, &b_lep_ID_4);
   fChain->SetBranchAddress("lep_Index_4", &lep_Index_4, &b_lep_Index_4);
   fChain->SetBranchAddress("lep_Pt_4", &lep_Pt_4, &b_lep_Pt_4);
   fChain->SetBranchAddress("lep_E_4", &lep_E_4, &b_lep_E_4);
   fChain->SetBranchAddress("lep_Eta_4", &lep_Eta_4, &b_lep_Eta_4);
   fChain->SetBranchAddress("lep_EtaBE2_4", &lep_EtaBE2_4, &b_lep_EtaBE2_4);
   fChain->SetBranchAddress("lep_Phi_4", &lep_Phi_4, &b_lep_Phi_4);
   fChain->SetBranchAddress("lep_sigd0PV_4", &lep_sigd0PV_4, &b_lep_sigd0PV_4);
   fChain->SetBranchAddress("lep_Z0SinTheta_4", &lep_Z0SinTheta_4, &b_lep_Z0SinTheta_4);
   fChain->SetBranchAddress("lep_d0_4", &lep_d0_4, &b_lep_d0_4);
   fChain->SetBranchAddress("lep_z0_4", &lep_z0_4, &b_lep_z0_4);
   fChain->SetBranchAddress("lep_vz_4", &lep_vz_4, &b_lep_vz_4);
   fChain->SetBranchAddress("lep_deltaz0_4", &lep_deltaz0_4, &b_lep_deltaz0_4);
   fChain->SetBranchAddress("lep_isTightLH_4", &lep_isTightLH_4, &b_lep_isTightLH_4);
   fChain->SetBranchAddress("lep_isMediumLH_4", &lep_isMediumLH_4, &b_lep_isMediumLH_4);
   fChain->SetBranchAddress("lep_isLooseLH_4", &lep_isLooseLH_4, &b_lep_isLooseLH_4);
   fChain->SetBranchAddress("lep_isTight_4", &lep_isTight_4, &b_lep_isTight_4);
   fChain->SetBranchAddress("lep_isMedium_4", &lep_isMedium_4, &b_lep_isMedium_4);
   fChain->SetBranchAddress("lep_isLoose_4", &lep_isLoose_4, &b_lep_isLoose_4);
   fChain->SetBranchAddress("lep_isolationFCTight_4", &lep_isolationFCTight_4, &b_lep_isolationFCTight_4);
   fChain->SetBranchAddress("lep_isolationLoose_4", &lep_isolationLoose_4, &b_lep_isolationLoose_4);
   fChain->SetBranchAddress("lep_isolationGradient_4", &lep_isolationGradient_4, &b_lep_isolationGradient_4);
   fChain->SetBranchAddress("lep_isolationGradientLoose_4", &lep_isolationGradientLoose_4, &b_lep_isolationGradientLoose_4);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_4", &lep_isolationTightTrackOnly_4, &b_lep_isolationTightTrackOnly_4);
   fChain->SetBranchAddress("lep_isolationFCLoose_4", &lep_isolationFCLoose_4, &b_lep_isolationFCLoose_4);
   fChain->SetBranchAddress("lep_isolationPflowTight_4", &lep_isolationPflowTight_4, &b_lep_isolationPflowTight_4);
   fChain->SetBranchAddress("lep_isolationPflowLoose_4", &lep_isolationPflowLoose_4, &b_lep_isolationPflowLoose_4);
   fChain->SetBranchAddress("lep_plvWP_Loose_4", &lep_plvWP_Loose_4, &b_lep_plvWP_Loose_4);
   fChain->SetBranchAddress("lep_plvWP_Tight_4", &lep_plvWP_Tight_4, &b_lep_plvWP_Tight_4);
   fChain->SetBranchAddress("lep_isTrigMatch_4", &lep_isTrigMatch_4, &b_lep_isTrigMatch_4);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_4", &lep_isTrigMatchDLT_4, &b_lep_isTrigMatchDLT_4);
   fChain->SetBranchAddress("lep_isPrompt_4", &lep_isPrompt_4, &b_lep_isPrompt_4);
   fChain->SetBranchAddress("lep_isFakeLep_4", &lep_isFakeLep_4, &b_lep_isFakeLep_4);
   fChain->SetBranchAddress("lep_isQMisID_4", &lep_isQMisID_4, &b_lep_isQMisID_4);
   fChain->SetBranchAddress("lep_isConvPh_4", &lep_isConvPh_4, &b_lep_isConvPh_4);
   fChain->SetBranchAddress("lep_isExtConvPh_4", &lep_isExtConvPh_4, &b_lep_isExtConvPh_4);
   fChain->SetBranchAddress("lep_isIntConvPh_4", &lep_isIntConvPh_4, &b_lep_isIntConvPh_4);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_4", &lep_isISR_FSR_Ph_4, &b_lep_isISR_FSR_Ph_4);
   fChain->SetBranchAddress("lep_isBrems_4", &lep_isBrems_4, &b_lep_isBrems_4);
   fChain->SetBranchAddress("lep_nTrackParticles_4", &lep_nTrackParticles_4, &b_lep_nTrackParticles_4);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_4", &lep_Mtrktrk_atPV_CO_4, &b_lep_Mtrktrk_atPV_CO_4);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_4", &lep_Mtrktrk_atConvV_CO_4, &b_lep_Mtrktrk_atConvV_CO_4);
   fChain->SetBranchAddress("lep_RadiusCO_4", &lep_RadiusCO_4, &b_lep_RadiusCO_4);
   fChain->SetBranchAddress("lep_RadiusCOX_4", &lep_RadiusCOX_4, &b_lep_RadiusCOX_4);
   fChain->SetBranchAddress("lep_RadiusCOY_4", &lep_RadiusCOY_4, &b_lep_RadiusCOY_4);
   fChain->SetBranchAddress("lep_SeparationMinDCT_4", &lep_SeparationMinDCT_4, &b_lep_SeparationMinDCT_4);
   fChain->SetBranchAddress("lep_ClosestSiTracknIL_4", &lep_ClosestSiTracknIL_4, &b_lep_ClosestSiTracknIL_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackeIL_4", &lep_ClosestSiTrackeIL_4, &b_lep_ClosestSiTrackeIL_4);
   fChain->SetBranchAddress("lep_ClosestSiTracknNIL_4", &lep_ClosestSiTracknNIL_4, &b_lep_ClosestSiTracknNIL_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackeNIL_4", &lep_ClosestSiTrackeNIL_4, &b_lep_ClosestSiTrackeNIL_4);
   fChain->SetBranchAddress("lep_BestMatchTrackPt_4", &lep_BestMatchTrackPt_4, &b_lep_BestMatchTrackPt_4);
   fChain->SetBranchAddress("lep_BestMatchTrackEta_4", &lep_BestMatchTrackEta_4, &b_lep_BestMatchTrackEta_4);
   fChain->SetBranchAddress("lep_BestMatchTrackPhi_4", &lep_BestMatchTrackPhi_4, &b_lep_BestMatchTrackPhi_4);
   fChain->SetBranchAddress("lep_BestMatchTrackD0_4", &lep_BestMatchTrackD0_4, &b_lep_BestMatchTrackD0_4);
   fChain->SetBranchAddress("lep_BestMatchTrackZ0_4", &lep_BestMatchTrackZ0_4, &b_lep_BestMatchTrackZ0_4);
   fChain->SetBranchAddress("lep_BestMatchTrackQ_4", &lep_BestMatchTrackQ_4, &b_lep_BestMatchTrackQ_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackPt_4", &lep_ClosestSiTrackPt_4, &b_lep_ClosestSiTrackPt_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackEta_4", &lep_ClosestSiTrackEta_4, &b_lep_ClosestSiTrackEta_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackPhi_4", &lep_ClosestSiTrackPhi_4, &b_lep_ClosestSiTrackPhi_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackD0_4", &lep_ClosestSiTrackD0_4, &b_lep_ClosestSiTrackD0_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackZ0_4", &lep_ClosestSiTrackZ0_4, &b_lep_ClosestSiTrackZ0_4);
   fChain->SetBranchAddress("lep_ClosestSiTrackQ_4", &lep_ClosestSiTrackQ_4, &b_lep_ClosestSiTrackQ_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_4", &lep_DFCommonSimpleConvRadius_4, &b_lep_DFCommonSimpleConvRadius_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_4", &lep_DFCommonSimpleConvPhi_4, &b_lep_DFCommonSimpleConvPhi_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_4", &lep_DFCommonSimpleMee_4, &b_lep_DFCommonSimpleMee_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_4", &lep_DFCommonSimpleMeeAtVtx_4, &b_lep_DFCommonSimpleMeeAtVtx_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_4", &lep_DFCommonSimpleSeparation_4, &b_lep_DFCommonSimpleSeparation_4);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_4", &lep_DFCommonAddAmbiguity_4, &b_lep_DFCommonAddAmbiguity_4);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_4", &lep_DFCommonProdTrueRadius_4, &b_lep_DFCommonProdTrueRadius_4);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_4", &lep_DFCommonProdTruePhi_4, &b_lep_DFCommonProdTruePhi_4);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_4", &lep_DFCommonProdTrueZ_4, &b_lep_DFCommonProdTrueZ_4);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_4", &lep_chargeIDBDTLoose_4, &b_lep_chargeIDBDTLoose_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_4", &lep_chargeIDBDTResult_4, &b_lep_chargeIDBDTResult_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_4", &lep_chargeIDBDTResult_recalc_rel207_loose_4, &b_lep_chargeIDBDTResult_recalc_rel207_loose_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_4", &lep_chargeIDBDTResult_recalc_rel207_medium_4, &b_lep_chargeIDBDTResult_recalc_rel207_medium_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_4", &lep_chargeIDBDTResult_recalc_rel207_tight_4, &b_lep_chargeIDBDTResult_recalc_rel207_tight_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_sv1_jf_ntrkv_4", &lep_promptLeptonInput_sv1_jf_ntrkv_4, &b_lep_promptLeptonInput_sv1_jf_ntrkv_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_TrackJetNTrack_4", &lep_promptLeptonInput_TrackJetNTrack_4, &b_lep_promptLeptonInput_TrackJetNTrack_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_DL1mu_4", &lep_promptLeptonInput_DL1mu_4, &b_lep_promptLeptonInput_DL1mu_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_DRlj_4", &lep_promptLeptonInput_DRlj_4, &b_lep_promptLeptonInput_DRlj_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_LepJetPtFrac_4", &lep_promptLeptonInput_LepJetPtFrac_4, &b_lep_promptLeptonInput_LepJetPtFrac_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtFrac_4", &lep_promptLeptonInput_PtFrac_4, &b_lep_promptLeptonInput_PtFrac_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_PtRel_4", &lep_promptLeptonInput_PtRel_4, &b_lep_promptLeptonInput_PtRel_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip2_4", &lep_promptLeptonInput_ip2_4, &b_lep_promptLeptonInput_ip2_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_ip3_4", &lep_promptLeptonInput_ip3_4, &b_lep_promptLeptonInput_ip3_4);
   fChain->SetBranchAddress("lep_promptLeptonInput_rnnip_4", &lep_promptLeptonInput_rnnip_4, &b_lep_promptLeptonInput_rnnip_4);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_4", &lep_promptLeptonIso_TagWeight_4, &b_lep_promptLeptonIso_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_4", &lep_promptLeptonVeto_TagWeight_4, &b_lep_promptLeptonVeto_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_4", &lep_promptLeptonImprovedVeto_TagWeight_4, &b_lep_promptLeptonImprovedVeto_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_4", &lep_promptLeptonImprovedVetoBARR_TagWeight_4, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_4", &lep_promptLeptonImprovedVetoECAP_TagWeight_4, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_4", &lep_PromptLeptonImprovedInput_MVAXBin_4, &b_lep_PromptLeptonImprovedInput_MVAXBin_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_4", &lep_PromptLeptonImprovedInput_PtFrac_4, &b_lep_PromptLeptonImprovedInput_PtFrac_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_4", &lep_PromptLeptonImprovedInput_DRlj_4, &b_lep_PromptLeptonImprovedInput_DRlj_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_4", &lep_PromptLeptonImprovedInput_reltopoetcone30_4, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_4", &lep_PromptLeptonImprovedInput_relptvarcone30_4, &b_lep_PromptLeptonImprovedInput_relptvarcone30_4);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_4", &lep_PromptLeptonRNN_prompt_4, &b_lep_PromptLeptonRNN_prompt_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_4", &lep_PromptLeptonImprovedInput_TrackJetNTrack_4, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_4", &lep_PromptLeptonImprovedInput_RelPt_4, &b_lep_PromptLeptonImprovedInput_RelPt_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_4", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_4, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_4", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_4, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_4", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_4, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_4", &lep_PromptLeptonImprovedInput_RelCaloClusterE_4, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_4", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_4, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_4);
   fChain->SetBranchAddress("lep_jet_Pt_4", &lep_jet_Pt_4, &b_lep_jet_Pt_4);
   fChain->SetBranchAddress("lep_jet_nTrk_4", &lep_jet_nTrk_4, &b_lep_jet_nTrk_4);
   fChain->SetBranchAddress("lep_jet_sumPtTrk_4", &lep_jet_sumPtTrk_4, &b_lep_jet_sumPtTrk_4);
   fChain->SetBranchAddress("lep_jet_mv2c10_4", &lep_jet_mv2c10_4, &b_lep_jet_mv2c10_4);
   fChain->SetBranchAddress("lep_jet_deltaR_4", &lep_jet_deltaR_4, &b_lep_jet_deltaR_4);
   fChain->SetBranchAddress("lep_jet_ptRel_4", &lep_jet_ptRel_4, &b_lep_jet_ptRel_4);
   fChain->SetBranchAddress("lep_jet_ptOverMuPt_4", &lep_jet_ptOverMuPt_4, &b_lep_jet_ptOverMuPt_4);
   fChain->SetBranchAddress("lep_isTruthMatched_4", &lep_isTruthMatched_4, &b_lep_isTruthMatched_4);
   fChain->SetBranchAddress("lep_truthType_4", &lep_truthType_4, &b_lep_truthType_4);
   fChain->SetBranchAddress("lep_truthOrigin_4", &lep_truthOrigin_4, &b_lep_truthOrigin_4);
   fChain->SetBranchAddress("lep_truthPdgId_4", &lep_truthPdgId_4, &b_lep_truthPdgId_4);
   fChain->SetBranchAddress("lep_truthStatus_4", &lep_truthStatus_4, &b_lep_truthStatus_4);
   fChain->SetBranchAddress("lep_truthParentType_4", &lep_truthParentType_4, &b_lep_truthParentType_4);
   fChain->SetBranchAddress("lep_truthParentOrigin_4", &lep_truthParentOrigin_4, &b_lep_truthParentOrigin_4);
   fChain->SetBranchAddress("lep_truthParentPdgId_4", &lep_truthParentPdgId_4, &b_lep_truthParentPdgId_4);
   fChain->SetBranchAddress("lep_truthParentStatus_4", &lep_truthParentStatus_4, &b_lep_truthParentStatus_4);
   fChain->SetBranchAddress("lep_truthPt_4", &lep_truthPt_4, &b_lep_truthPt_4);
   fChain->SetBranchAddress("lep_truthEta_4", &lep_truthEta_4, &b_lep_truthEta_4);
   fChain->SetBranchAddress("lep_truthPhi_4", &lep_truthPhi_4, &b_lep_truthPhi_4);
   fChain->SetBranchAddress("lep_truthM_4", &lep_truthM_4, &b_lep_truthM_4);
   fChain->SetBranchAddress("lep_truthE_4", &lep_truthE_4, &b_lep_truthE_4);
   fChain->SetBranchAddress("lep_truthRapidity_4", &lep_truthRapidity_4, &b_lep_truthRapidity_4);
   fChain->SetBranchAddress("lep_ambiguityType_4", &lep_ambiguityType_4, &b_lep_ambiguityType_4);
   fChain->SetBranchAddress("lep_nInnerPix_4", &lep_nInnerPix_4, &b_lep_nInnerPix_4);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_4", &lep_firstEgMotherPdgId_4, &b_lep_firstEgMotherPdgId_4);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_4", &lep_firstEgMotherTruthType_4, &b_lep_firstEgMotherTruthType_4);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_4", &lep_firstEgMotherTruthOrigin_4, &b_lep_firstEgMotherTruthOrigin_4);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_4", &lep_lastEgMotherPdgId_4, &b_lep_lastEgMotherPdgId_4);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_4", &lep_lastEgMotherTruthType_4, &b_lep_lastEgMotherTruthType_4);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_4", &lep_lastEgMotherTruthOrigin_4, &b_lep_lastEgMotherTruthOrigin_4);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_4", &lep_SF_El_Reco_AT_4, &b_lep_SF_El_Reco_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_4", &lep_SF_El_ID_LooseAndBLayerLH_AT_4, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_4", &lep_SF_El_ID_TightLH_AT_4, &b_lep_SF_El_ID_TightLH_AT_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_4", &lep_SF_El_Iso_FCLoose_AT_4, &b_lep_SF_El_Iso_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_4", &lep_SF_El_FCLooseTightLHQMisID_4, &b_lep_SF_El_FCLooseTightLHQMisID_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_4", &lep_SF_El_Iso_FCLoose_TightLH_4, &b_lep_SF_El_Iso_FCLoose_TightLH_4);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_4", &lep_SF_El_PLVTight_QmisID_4, &b_lep_SF_El_PLVTight_QmisID_4);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_4", &lep_SF_El_PLVTight_4, &b_lep_SF_El_PLVTight_4);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_4", &lep_SF_El_PLVLoose_4, &b_lep_SF_El_PLVLoose_4);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_4", &lep_SF_El_ID_MediumLH_4, &b_lep_SF_El_ID_MediumLH_4);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_4", &lep_SF_Mu_TTVA_AT_4, &b_lep_SF_Mu_TTVA_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_4", &lep_SF_Mu_ID_Loose_AT_4, &b_lep_SF_Mu_ID_Loose_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_4", &lep_SF_Mu_ID_Medium_AT_4, &b_lep_SF_Mu_ID_Medium_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_4", &lep_SF_Mu_Iso_FCLoose_AT_4, &b_lep_SF_Mu_Iso_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_4", &lep_SF_Mu_ID_Tight_4, &b_lep_SF_Mu_ID_Tight_4);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_4", &lep_SF_Mu_PLVTight_4, &b_lep_SF_Mu_PLVTight_4);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_4", &lep_SF_Mu_PLVLoose_4, &b_lep_SF_Mu_PLVLoose_4);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_4", &lep_SF_CombinedLoose_4, &b_lep_SF_CombinedLoose_4);
   fChain->SetBranchAddress("lep_SF_CombinedTight_4", &lep_SF_CombinedTight_4, &b_lep_SF_CombinedTight_4);
   fChain->SetBranchAddress("taus_pt_0", &taus_pt_0, &b_taus_pt_0);
   fChain->SetBranchAddress("taus_eta_0", &taus_eta_0, &b_taus_eta_0);
   fChain->SetBranchAddress("taus_phi_0", &taus_phi_0, &b_taus_phi_0);
   fChain->SetBranchAddress("taus_charge_0", &taus_charge_0, &b_taus_charge_0);
   fChain->SetBranchAddress("taus_E_0", &taus_E_0, &b_taus_E_0);
   fChain->SetBranchAddress("taus_width_0", &taus_width_0, &b_taus_width_0);
   fChain->SetBranchAddress("taus_decayMode_0", &taus_decayMode_0, &b_taus_decayMode_0);
   fChain->SetBranchAddress("taus_BDTJetScore_0", &taus_BDTJetScore_0, &b_taus_BDTJetScore_0);
   fChain->SetBranchAddress("taus_BDTJetScoreSigTrans_0", &taus_BDTJetScoreSigTrans_0, &b_taus_BDTJetScoreSigTrans_0);
   fChain->SetBranchAddress("taus_JetBDTSigLoose_0", &taus_JetBDTSigLoose_0, &b_taus_JetBDTSigLoose_0);
   fChain->SetBranchAddress("taus_JetBDTSigMedium_0", &taus_JetBDTSigMedium_0, &b_taus_JetBDTSigMedium_0);
   fChain->SetBranchAddress("taus_JetBDTSigTight_0", &taus_JetBDTSigTight_0, &b_taus_JetBDTSigTight_0);
   fChain->SetBranchAddress("taus_RNNJetScore_0", &taus_RNNJetScore_0, &b_taus_RNNJetScore_0);
   fChain->SetBranchAddress("taus_RNNJetScoreSigTrans_0", &taus_RNNJetScoreSigTrans_0, &b_taus_RNNJetScoreSigTrans_0);
   fChain->SetBranchAddress("taus_JetRNNSigLoose_0", &taus_JetRNNSigLoose_0, &b_taus_JetRNNSigLoose_0);
   fChain->SetBranchAddress("taus_JetRNNSigMedium_0", &taus_JetRNNSigMedium_0, &b_taus_JetRNNSigMedium_0);
   fChain->SetBranchAddress("taus_JetRNNSigTight_0", &taus_JetRNNSigTight_0, &b_taus_JetRNNSigTight_0);
   fChain->SetBranchAddress("taus_numTrack_0", &taus_numTrack_0, &b_taus_numTrack_0);
   fChain->SetBranchAddress("taus_isHadronic_0", &taus_isHadronic_0, &b_taus_isHadronic_0);
   fChain->SetBranchAddress("taus_tagWeightBin_0", &taus_tagWeightBin_0, &b_taus_tagWeightBin_0);
   fChain->SetBranchAddress("taus_MV2c10_0", &taus_MV2c10_0, &b_taus_MV2c10_0);
   fChain->SetBranchAddress("taus_DL1r_0", &taus_DL1r_0, &b_taus_DL1r_0);
   fChain->SetBranchAddress("taus_DL1_0", &taus_DL1_0, &b_taus_DL1_0);
   fChain->SetBranchAddress("taus_fromPV_0", &taus_fromPV_0, &b_taus_fromPV_0);
   fChain->SetBranchAddress("taus_passJVT_0", &taus_passJVT_0, &b_taus_passJVT_0);
   fChain->SetBranchAddress("taus_passEleOLR_0", &taus_passEleOLR_0, &b_taus_passEleOLR_0);
   fChain->SetBranchAddress("taus_passEleBDT_0", &taus_passEleBDT_0, &b_taus_passEleBDT_0);
   fChain->SetBranchAddress("taus_passMuonOLR_0", &taus_passMuonOLR_0, &b_taus_passMuonOLR_0);
   fChain->SetBranchAddress("taus_truthOrigin_0", &taus_truthOrigin_0, &b_taus_truthOrigin_0);
   fChain->SetBranchAddress("taus_truthType_0", &taus_truthType_0, &b_taus_truthType_0);
   fChain->SetBranchAddress("taus_truthJetFlavour_0", &taus_truthJetFlavour_0, &b_taus_truthJetFlavour_0);
   fChain->SetBranchAddress("taus_pt_1", &taus_pt_1, &b_taus_pt_1);
   fChain->SetBranchAddress("taus_eta_1", &taus_eta_1, &b_taus_eta_1);
   fChain->SetBranchAddress("taus_phi_1", &taus_phi_1, &b_taus_phi_1);
   fChain->SetBranchAddress("taus_charge_1", &taus_charge_1, &b_taus_charge_1);
   fChain->SetBranchAddress("taus_E_1", &taus_E_1, &b_taus_E_1);
   fChain->SetBranchAddress("taus_width_1", &taus_width_1, &b_taus_width_1);
   fChain->SetBranchAddress("taus_decayMode_1", &taus_decayMode_1, &b_taus_decayMode_1);
   fChain->SetBranchAddress("taus_BDTJetScore_1", &taus_BDTJetScore_1, &b_taus_BDTJetScore_1);
   fChain->SetBranchAddress("taus_BDTJetScoreSigTrans_1", &taus_BDTJetScoreSigTrans_1, &b_taus_BDTJetScoreSigTrans_1);
   fChain->SetBranchAddress("taus_JetBDTSigLoose_1", &taus_JetBDTSigLoose_1, &b_taus_JetBDTSigLoose_1);
   fChain->SetBranchAddress("taus_JetBDTSigMedium_1", &taus_JetBDTSigMedium_1, &b_taus_JetBDTSigMedium_1);
   fChain->SetBranchAddress("taus_JetBDTSigTight_1", &taus_JetBDTSigTight_1, &b_taus_JetBDTSigTight_1);
   fChain->SetBranchAddress("taus_RNNJetScore_1", &taus_RNNJetScore_1, &b_taus_RNNJetScore_1);
   fChain->SetBranchAddress("taus_RNNJetScoreSigTrans_1", &taus_RNNJetScoreSigTrans_1, &b_taus_RNNJetScoreSigTrans_1);
   fChain->SetBranchAddress("taus_JetRNNSigLoose_1", &taus_JetRNNSigLoose_1, &b_taus_JetRNNSigLoose_1);
   fChain->SetBranchAddress("taus_JetRNNSigMedium_1", &taus_JetRNNSigMedium_1, &b_taus_JetRNNSigMedium_1);
   fChain->SetBranchAddress("taus_JetRNNSigTight_1", &taus_JetRNNSigTight_1, &b_taus_JetRNNSigTight_1);
   fChain->SetBranchAddress("taus_numTrack_1", &taus_numTrack_1, &b_taus_numTrack_1);
   fChain->SetBranchAddress("taus_isHadronic_1", &taus_isHadronic_1, &b_taus_isHadronic_1);
   fChain->SetBranchAddress("taus_tagWeightBin_1", &taus_tagWeightBin_1, &b_taus_tagWeightBin_1);
   fChain->SetBranchAddress("taus_MV2c10_1", &taus_MV2c10_1, &b_taus_MV2c10_1);
   fChain->SetBranchAddress("taus_DL1r_1", &taus_DL1r_1, &b_taus_DL1r_1);
   fChain->SetBranchAddress("taus_DL1_1", &taus_DL1_1, &b_taus_DL1_1);
   fChain->SetBranchAddress("taus_fromPV_1", &taus_fromPV_1, &b_taus_fromPV_1);
   fChain->SetBranchAddress("taus_passJVT_1", &taus_passJVT_1, &b_taus_passJVT_1);
   fChain->SetBranchAddress("taus_passEleOLR_1", &taus_passEleOLR_1, &b_taus_passEleOLR_1);
   fChain->SetBranchAddress("taus_passEleBDT_1", &taus_passEleBDT_1, &b_taus_passEleBDT_1);
   fChain->SetBranchAddress("taus_passMuonOLR_1", &taus_passMuonOLR_1, &b_taus_passMuonOLR_1);
   fChain->SetBranchAddress("taus_truthOrigin_1", &taus_truthOrigin_1, &b_taus_truthOrigin_1);
   fChain->SetBranchAddress("taus_truthType_1", &taus_truthType_1, &b_taus_truthType_1);
   fChain->SetBranchAddress("taus_truthJetFlavour_1", &taus_truthJetFlavour_1, &b_taus_truthJetFlavour_1);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_e", &jets_e, &b_jets_e);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_tauOR", &jets_tauOR, &b_jets_tauOR);
   fChain->SetBranchAddress("jets_fJVT", &jets_fJVT, &b_jets_fJVT);
   fChain->SetBranchAddress("jets_score_DL1r", &jets_score_DL1r, &b_jets_score_DL1r);
   fChain->SetBranchAddress("jets_score_DL1r_pu", &jets_score_DL1r_pu, &b_jets_score_DL1r_pu);
   fChain->SetBranchAddress("jets_score_DL1r_pc", &jets_score_DL1r_pc, &b_jets_score_DL1r_pc);
   fChain->SetBranchAddress("jets_score_DL1r_pb", &jets_score_DL1r_pb, &b_jets_score_DL1r_pb);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_60", &jets_btagFlag_DL1r_FixedCutBEff_60, &b_jets_btagFlag_DL1r_FixedCutBEff_60);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_70", &jets_btagFlag_DL1r_FixedCutBEff_70, &b_jets_btagFlag_DL1r_FixedCutBEff_70);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_77", &jets_btagFlag_DL1r_FixedCutBEff_77, &b_jets_btagFlag_DL1r_FixedCutBEff_77);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_85", &jets_btagFlag_DL1r_FixedCutBEff_85, &b_jets_btagFlag_DL1r_FixedCutBEff_85);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   fChain->SetBranchAddress("lepSFObjChannelCombined", &lepSFObjChannelCombined, &b_lepSFObjChannelCombined);
   fChain->SetBranchAddress("jvtSF_customOR", &jvtSF_customOR, &b_jvtSF_customOR);
   fChain->SetBranchAddress("GlobalTrigMatch_AT_default_postOR", &GlobalTrigMatch_AT_default_postOR, &b_GlobalTrigMatch_AT_default_postOR);
   fChain->SetBranchAddress("GlobalTrigDecision", &GlobalTrigDecision, &b_GlobalTrigDecision);
   fChain->SetBranchAddress("custTrigSF_AT_default_preOR", &custTrigSF_AT_default_preOR, &b_custTrigSF_AT_default_preOR);
   fChain->SetBranchAddress("custTrigSF_AT_default_postOR", &custTrigSF_AT_default_postOR, &b_custTrigSF_AT_default_postOR);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_SLTorDLT", &custTrigSF_LooseID_FCLooseIso_SLTorDLT, &b_custTrigSF_LooseID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_SLT", &custTrigSF_LooseID_FCLooseIso_SLT, &b_custTrigSF_LooseID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_DLT", &custTrigSF_LooseID_FCLooseIso_DLT, &b_custTrigSF_LooseID_FCLooseIso_DLT);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_SLTorDLT", &custTrigMatch_LooseID_FCLooseIso_SLTorDLT, &b_custTrigMatch_LooseID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_SLT", &custTrigMatch_LooseID_FCLooseIso_SLT, &b_custTrigMatch_LooseID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_DLT", &custTrigMatch_LooseID_FCLooseIso_DLT, &b_custTrigMatch_LooseID_FCLooseIso_DLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT", &custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_SLT", &custTrigSF_TightElMediumMuID_FCLooseIso_SLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_DLT", &custTrigSF_TightElMediumMuID_FCLooseIso_DLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_SLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_SLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_DLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_DLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_DLT);
   fChain->SetBranchAddress("GlobalTrigDecision_2e12_lhloose_L12EM10VH", &GlobalTrigDecision_2e12_lhloose_L12EM10VH, &b_GlobalTrigDecision_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("GlobalTrigDecision_2e17_lhvloose_nod0", &GlobalTrigDecision_2e17_lhvloose_nod0, &b_GlobalTrigDecision_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_2e24_lhvloose_nod0", &GlobalTrigDecision_2e24_lhvloose_nod0, &b_GlobalTrigDecision_2e24_lhvloose_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_e120_lhloose", &GlobalTrigDecision_e120_lhloose, &b_GlobalTrigDecision_e120_lhloose);
   fChain->SetBranchAddress("GlobalTrigDecision_e140_lhloose_nod0", &GlobalTrigDecision_e140_lhloose_nod0, &b_GlobalTrigDecision_e140_lhloose_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_e17_lhloose_mu14", &GlobalTrigDecision_e17_lhloose_mu14, &b_GlobalTrigDecision_e17_lhloose_mu14);
   fChain->SetBranchAddress("GlobalTrigDecision_e17_lhloose_nod0_mu14", &GlobalTrigDecision_e17_lhloose_nod0_mu14, &b_GlobalTrigDecision_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("GlobalTrigDecision_e24_lhmedium_L1EM20VH", &GlobalTrigDecision_e24_lhmedium_L1EM20VH, &b_GlobalTrigDecision_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("GlobalTrigDecision_e26_lhtight_nod0_ivarloose", &GlobalTrigDecision_e26_lhtight_nod0_ivarloose, &b_GlobalTrigDecision_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("GlobalTrigDecision_e60_lhmedium", &GlobalTrigDecision_e60_lhmedium, &b_GlobalTrigDecision_e60_lhmedium);
   fChain->SetBranchAddress("GlobalTrigDecision_e60_lhmedium_nod0", &GlobalTrigDecision_e60_lhmedium_nod0, &b_GlobalTrigDecision_e60_lhmedium_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_mu18_mu8noL1", &GlobalTrigDecision_mu18_mu8noL1, &b_GlobalTrigDecision_mu18_mu8noL1);
   fChain->SetBranchAddress("GlobalTrigDecision_mu20_iloose_L1MU15", &GlobalTrigDecision_mu20_iloose_L1MU15, &b_GlobalTrigDecision_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("GlobalTrigDecision_mu22_mu8noL1", &GlobalTrigDecision_mu22_mu8noL1, &b_GlobalTrigDecision_mu22_mu8noL1);
   fChain->SetBranchAddress("GlobalTrigDecision_mu26_ivarmedium", &GlobalTrigDecision_mu26_ivarmedium, &b_GlobalTrigDecision_mu26_ivarmedium);
   fChain->SetBranchAddress("GlobalTrigDecision_mu50", &GlobalTrigDecision_mu50, &b_GlobalTrigDecision_mu50);
   fChain->SetBranchAddress("higgsDecayMode", &higgsDecayMode, &b_higgsDecayMode);
   fChain->SetBranchAddress("m_truth_m", &m_truth_m, &b_m_truth_m);
   fChain->SetBranchAddress("m_truth_pt", &m_truth_pt, &b_m_truth_pt);
   fChain->SetBranchAddress("m_truth_eta", &m_truth_eta, &b_m_truth_eta);
   fChain->SetBranchAddress("m_truth_phi", &m_truth_phi, &b_m_truth_phi);
   fChain->SetBranchAddress("m_truth_e", &m_truth_e, &b_m_truth_e);
   fChain->SetBranchAddress("m_truth_pdgId", &m_truth_pdgId, &b_m_truth_pdgId);
   fChain->SetBranchAddress("m_truth_status", &m_truth_status, &b_m_truth_status);
   fChain->SetBranchAddress("m_truth_barcode", &m_truth_barcode, &b_m_truth_barcode);
   fChain->SetBranchAddress("m_truth_parents", &m_truth_parents, &b_m_truth_parents);
   fChain->SetBranchAddress("m_truth_children", &m_truth_children, &b_m_truth_children);
   fChain->SetBranchAddress("met_sumet", &met_sumet, &b_met_sumet);
   fChain->SetBranchAddress("tauSFRNNMedium_TAU_SF_NOMINAL", &tauSFRNNMedium_TAU_SF_NOMINAL, &b_tauSFRNNMedium_TAU_SF_NOMINAL);
   fChain->SetBranchAddress("tauSFRNNLoose_TAU_SF_NOMINAL", &tauSFRNNLoose_TAU_SF_NOMINAL, &b_tauSFRNNLoose_TAU_SF_NOMINAL);
   fChain->SetBranchAddress("bTagSF_weight_DL1_70", &bTagSF_weight_DL1_70, &b_bTagSF_weight_DL1_70);
   fChain->SetBranchAddress("bTagSF_weight_DL1_77", &bTagSF_weight_DL1_77, &b_bTagSF_weight_DL1_77);
   fChain->SetBranchAddress("bTagSF_weight_DL1_85", &bTagSF_weight_DL1_85, &b_bTagSF_weight_DL1_85);
   fChain->SetBranchAddress("bTagSF_weight_DL1_60", &bTagSF_weight_DL1_60, &b_bTagSF_weight_DL1_60);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_70", &bTagSF_weight_DL1r_70, &b_bTagSF_weight_DL1r_70);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_77", &bTagSF_weight_DL1r_77, &b_bTagSF_weight_DL1r_77);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_85", &bTagSF_weight_DL1r_85, &b_bTagSF_weight_DL1r_85);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_60", &bTagSF_weight_DL1r_60, &b_bTagSF_weight_DL1r_60);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_Continuous", &bTagSF_weight_DL1r_Continuous, &b_bTagSF_weight_DL1r_Continuous);
   fChain->SetBranchAddress("mc_norm", &mc_norm, &b_mc_norm);
   Notify();
}

Bool_t tthmltree_v5::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tthmltree_v5::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tthmltree_v5::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tthmltree_v5_cxx
