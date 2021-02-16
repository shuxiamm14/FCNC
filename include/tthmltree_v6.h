#include "tthmltree.h"
using namespace std;
class tthmltree_v6 : public tthmltree {
public :
   void dumpTruth(int ipart) ;
   bool addWeightSys();
   bool addTheorySys();
   bool passBasicCut();
   void defineObjects();
   void calcGeneralWeight();
   void defineLepTruth();
   void defineTauTruth();
   bool SelectTLepid(int id);
   bool IsoLepid(int id);
   void initRaw(TTree *tree);
   Float_t         weight_pileup;
   Float_t         weight_pileup_UP;
   Float_t         weight_pileup_DOWN;
   UInt_t          randomRunNumber;
   Float_t         mu;
   Float_t         mu_actual;
   UInt_t          backgroundFlags;
   UInt_t          hasBadMuon;
   Float_t         met_met;
   Float_t         met_phi;
   Int_t           triggers;
   Int_t           loose;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_mu22_mu8noL1;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu18_mu8noL1;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_2e12_lhloose_L12EM10VH;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_2e17_lhvloose_nod0;
   Char_t          HLT_e17_lhloose_mu14;
   Char_t          onelep_type;
   Char_t          dilep_type;
   Char_t          trilep_type;
   Char_t          quadlep_type;
   Char_t          total_charge;
   Char_t          total_leptons;
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
   Char_t          nJets_OR;
   Char_t          nJets_OR_TauOR;
   Char_t          nFwdJets_OR;
   Char_t          nFwdJets_OR_TauOR;
   Char_t          nTruthJets_OR;
   Char_t          nJets_OR_DL1r_85;
   Char_t          nJets_OR_DL1r_60;
   Char_t          nJets_OR_DL1r_77;
   Char_t          nJets_OR_DL1r_70;
   Char_t          nFwdJets_OR_DL1r_85;
   Char_t          nFwdJets_OR_DL1r_60;
   Char_t          nFwdJets_OR_DL1r_77;
   Char_t          nFwdJets_OR_DL1r_70;
   Char_t          nTaus_OR_Pt25;
   Char_t          nTaus_OR;
   Char_t          nTaus_OR_Medium;
   Char_t          nTaus_OR_Tight;
   Bool_t          isBlinded;
   Float_t         HT;
   Float_t         HT_inclFwdJets;
   Float_t         HT_lep;
   Float_t         HT_jets;
   Float_t         HT_fwdJets;
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
   Char_t          lep_isolationLoose_0;
   Char_t          lep_isolationGradient_0;
   Char_t          lep_isolationGradientLoose_0;
   Char_t          lep_isolationTightTrackOnly_0;
   Char_t          lep_isolationFCLoose_0;
   Char_t          lep_isolationPflowTight_0;
   Char_t          lep_isolationPflowLoose_0;
   Char_t          lep_isolationHighPtCaloOnly_0;
   Char_t          lep_isolationPflowTight_VarRad_0;
   Char_t          lep_isolationPflowTight_FixedRad_0;
   Char_t          lep_isolationPflowLoose_VarRad_0;
   Char_t          lep_isolationPflowLoose_FixedRad_0;
   Char_t          lep_isolationHighPtTrackOnly_0;
   Char_t          lep_isolationTight_FixedRad_0;
   Char_t          lep_isolationLoose_FixedRad_0;
   Char_t          lep_isolationTightTrackOnly_VarRad_0;
   Char_t          lep_isolationTightTrackOnly_FixedRad_0;
   Char_t          lep_isolationTight_VarRad_0;
   Char_t          lep_isolationLoose_VarRad_0;
   Char_t          lep_plvWP_Loose_0;
   Char_t          lep_plvWP_Tight_0;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;
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
   Float_t         lep_DFCommonJetDr_0;
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
   Char_t          lep_isolationLoose_1;
   Char_t          lep_isolationGradient_1;
   Char_t          lep_isolationGradientLoose_1;
   Char_t          lep_isolationTightTrackOnly_1;
   Char_t          lep_isolationFCLoose_1;
   Char_t          lep_isolationPflowTight_1;
   Char_t          lep_isolationPflowLoose_1;
   Char_t          lep_isolationHighPtCaloOnly_1;
   Char_t          lep_isolationPflowTight_VarRad_1;
   Char_t          lep_isolationPflowTight_FixedRad_1;
   Char_t          lep_isolationPflowLoose_VarRad_1;
   Char_t          lep_isolationPflowLoose_FixedRad_1;
   Char_t          lep_isolationHighPtTrackOnly_1;
   Char_t          lep_isolationTight_FixedRad_1;
   Char_t          lep_isolationLoose_FixedRad_1;
   Char_t          lep_isolationTightTrackOnly_VarRad_1;
   Char_t          lep_isolationTightTrackOnly_FixedRad_1;
   Char_t          lep_isolationTight_VarRad_1;
   Char_t          lep_isolationLoose_VarRad_1;
   Char_t          lep_plvWP_Loose_1;
   Char_t          lep_plvWP_Tight_1;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;
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
   Float_t         lep_DFCommonJetDr_1;
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
   Char_t          lep_isolationLoose_2;
   Char_t          lep_isolationGradient_2;
   Char_t          lep_isolationGradientLoose_2;
   Char_t          lep_isolationTightTrackOnly_2;
   Char_t          lep_isolationFCLoose_2;
   Char_t          lep_isolationPflowTight_2;
   Char_t          lep_isolationPflowLoose_2;
   Char_t          lep_isolationHighPtCaloOnly_2;
   Char_t          lep_isolationPflowTight_VarRad_2;
   Char_t          lep_isolationPflowTight_FixedRad_2;
   Char_t          lep_isolationPflowLoose_VarRad_2;
   Char_t          lep_isolationPflowLoose_FixedRad_2;
   Char_t          lep_isolationHighPtTrackOnly_2;
   Char_t          lep_isolationTight_FixedRad_2;
   Char_t          lep_isolationLoose_FixedRad_2;
   Char_t          lep_isolationTightTrackOnly_VarRad_2;
   Char_t          lep_isolationTightTrackOnly_FixedRad_2;
   Char_t          lep_isolationTight_VarRad_2;
   Char_t          lep_isolationLoose_VarRad_2;
   Char_t          lep_plvWP_Loose_2;
   Char_t          lep_plvWP_Tight_2;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;
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
   Float_t         lep_DFCommonJetDr_2;
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
   Char_t          lep_isolationLoose_3;
   Char_t          lep_isolationGradient_3;
   Char_t          lep_isolationGradientLoose_3;
   Char_t          lep_isolationTightTrackOnly_3;
   Char_t          lep_isolationFCLoose_3;
   Char_t          lep_isolationPflowTight_3;
   Char_t          lep_isolationPflowLoose_3;
   Char_t          lep_isolationHighPtCaloOnly_3;
   Char_t          lep_isolationPflowTight_VarRad_3;
   Char_t          lep_isolationPflowTight_FixedRad_3;
   Char_t          lep_isolationPflowLoose_VarRad_3;
   Char_t          lep_isolationPflowLoose_FixedRad_3;
   Char_t          lep_isolationHighPtTrackOnly_3;
   Char_t          lep_isolationTight_FixedRad_3;
   Char_t          lep_isolationLoose_FixedRad_3;
   Char_t          lep_isolationTightTrackOnly_VarRad_3;
   Char_t          lep_isolationTightTrackOnly_FixedRad_3;
   Char_t          lep_isolationTight_VarRad_3;
   Char_t          lep_isolationLoose_VarRad_3;
   Char_t          lep_plvWP_Loose_3;
   Char_t          lep_plvWP_Tight_3;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_3;
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
   Float_t         lep_DFCommonJetDr_3;
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
   Char_t          lep_isolationLoose_4;
   Char_t          lep_isolationGradient_4;
   Char_t          lep_isolationGradientLoose_4;
   Char_t          lep_isolationTightTrackOnly_4;
   Char_t          lep_isolationFCLoose_4;
   Char_t          lep_isolationPflowTight_4;
   Char_t          lep_isolationPflowLoose_4;
   Char_t          lep_isolationHighPtCaloOnly_4;
   Char_t          lep_isolationPflowTight_VarRad_4;
   Char_t          lep_isolationPflowTight_FixedRad_4;
   Char_t          lep_isolationPflowLoose_VarRad_4;
   Char_t          lep_isolationPflowLoose_FixedRad_4;
   Char_t          lep_isolationHighPtTrackOnly_4;
   Char_t          lep_isolationTight_FixedRad_4;
   Char_t          lep_isolationLoose_FixedRad_4;
   Char_t          lep_isolationTightTrackOnly_VarRad_4;
   Char_t          lep_isolationTightTrackOnly_FixedRad_4;
   Char_t          lep_isolationTight_VarRad_4;
   Char_t          lep_isolationLoose_VarRad_4;
   Char_t          lep_plvWP_Loose_4;
   Char_t          lep_plvWP_Tight_4;
   Char_t          lep_isTrigMatch_4;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_4;
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
   Float_t         lep_DFCommonJetDr_4;
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
   Char_t          taus_decayMode_0;
   Double_t        taus_BDTJetScore_0;
   Double_t        taus_BDTJetScoreSigTrans_0;
   Char_t          taus_JetBDTSigLoose_0;
   Char_t          taus_JetBDTSigMedium_0;
   Char_t          taus_JetBDTSigTight_0;
   Double_t        taus_RNNJetScore_0;
   Double_t        taus_RNNJetScoreSigTrans_0;
   Char_t          taus_JetRNNSigLoose_0;
   Char_t          taus_JetRNNSigMedium_0;
   Char_t          taus_JetRNNSigTight_0;
   Char_t          taus_numTrack_0;
   Char_t          taus_isHadronic_0;
   Char_t          taus_tagWeightBin_0;
   Float_t         taus_MV2c10_0;
   Float_t         taus_DL1r_0;
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
   Char_t          taus_decayMode_1;
   Double_t        taus_BDTJetScore_1;
   Double_t        taus_BDTJetScoreSigTrans_1;
   Char_t          taus_JetBDTSigLoose_1;
   Char_t          taus_JetBDTSigMedium_1;
   Char_t          taus_JetBDTSigTight_1;
   Double_t        taus_RNNJetScore_1;
   Double_t        taus_RNNJetScoreSigTrans_1;
   Char_t          taus_JetRNNSigLoose_1;
   Char_t          taus_JetRNNSigMedium_1;
   Char_t          taus_JetRNNSigTight_1;
   Char_t          taus_numTrack_1;
   Char_t          taus_isHadronic_1;
   Char_t          taus_tagWeightBin_1;
   Float_t         taus_MV2c10_1;
   Float_t         taus_DL1r_1;
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
   vector<float>   *jets_score_DL1r;
   vector<char>    *jets_btagFlag_DL1r_ContinuousBin;
   vector<float>   *jets_score_DL1r_pu;
   vector<float>   *jets_score_DL1r_pc;
   vector<float>   *jets_score_DL1r_pb;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_60;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_70;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_77;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_85;
   vector<float>   *jets_btag_JetVertexCharge_discriminant;
   vector<char>    *jets_ConeTruthLabelID;
   vector<char>    *jets_HadronConeExclExtendedTruthLabelID;
   vector<char>    *jets_HadronConeExclTruthLabelID;
   vector<char>    *jets_PartonTruthLabelID;
   vector<char>    *jets_isQuarkJet;
   vector<char>    *jets_isQuarkJetBDT;
   vector<int>     *jets_DFCommonJets_QGTagger_NTracks;
   vector<float>   *jets_DFCommonJets_QGTagger_TracksWidth;
   vector<float>   *jets_DFCommonJets_QGTagger_TracksC1;
   vector<float>   *jets_DFCommonJets_fJvt;
   Char_t          GlobalTrigMatch_AT_default_postOR;
   Char_t          GlobalTrigDecision;
   Int_t           flag_JetCleaning_LooseBad;
   Float_t         custTrigSF_AT_default_preOR;
   Float_t         custTrigSF_AT_default_postOR;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_DLT;
   Char_t          custTrigMatch_LooseID_FCLooseIso_SLTorDLT;
   Char_t          custTrigMatch_LooseID_FCLooseIso_SLT;
   Char_t          custTrigMatch_LooseID_FCLooseIso_DLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_SLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_DLT;
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
   Float_t         met_sumet;
   Int_t           higgsDecayMode;
   Int_t           hhiggsDecayMode;
   Int_t           initial_state;
   vector<vector<int> > *m_truth_parentsID;
   vector<vector<int> > *m_truth_childrenID;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         lepSFObjChannelCombined;
   Float_t         jvtSF_customOR;
   Float_t         fjvtSF_customOR;
   Float_t         tauSFRNNMedium_TAU_SF_NOMINAL;
   Float_t         tauSFRNNLoose_TAU_SF_NOMINAL;
   Float_t         tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP;
   Float_t         tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP;
   Float_t         tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN;
   Float_t         tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP;
   Float_t         tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP;
   Float_t         tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN;
   Float_t         tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN;
   Float_t         tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP;
   Float_t         tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP;
   Float_t         tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN;
   Float_t         tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_HIGHPT_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_HIGHPT_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN;
   Float_t         tauSFRNNMedium_EFF_RNNID_SYST_UP;
   Float_t         tauSFRNNLoose_EFF_RNNID_SYST_UP;
   Float_t         tauSFRNNMedium_EFF_RNNID_SYST_DOWN;
   Float_t         tauSFRNNLoose_EFF_RNNID_SYST_DOWN;
   Float_t         tauSFRNNMedium_EFF_RECO_TOTAL_UP;
   Float_t         tauSFRNNLoose_EFF_RECO_TOTAL_UP;
   Float_t         tauSFRNNMedium_EFF_RECO_TOTAL_DOWN;
   Float_t         tauSFRNNLoose_EFF_RECO_TOTAL_DOWN;
   Float_t         lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;
   Float_t         lepSF_SF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;
   Float_t         lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;
   Float_t         lepSF_SF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;
   Float_t         lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;
   Float_t         lepSF_SF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;
   Float_t         lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;
   Float_t         lepSF_SF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;
   Float_t         lepSF_SF_El_Reco_UP_AT;
   Float_t         lepSF_SF_El_Reco_DOWN_AT;
   Float_t         lepSF_SF_El_ID_LooseAndBLayerLH_UP_AT;
   Float_t         lepSF_SF_El_ID_TightLH_UP_AT;
   Float_t         lepSF_SF_El_ID_LooseAndBLayerLH_DOWN_AT;
   Float_t         lepSF_SF_El_ID_TightLH_DOWN_AT;
   Float_t         lepSF_SF_El_Iso_FCLoose_UP_AT;
   Float_t         lepSF_SF_El_Iso_FCLoose_DOWN_AT;
   Float_t         lepSF_SF_Mu_TTVA_STAT_UP_AT;
   Float_t         lepSF_SF_Mu_TTVA_STAT_DOWN_AT;
   Float_t         lepSF_SF_Mu_TTVA_SYST_UP_AT;
   Float_t         lepSF_SF_Mu_TTVA_SYST_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_STAT_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_STAT_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_STAT_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_STAT_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_SYST_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_SYST_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_SYST_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_SYST_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_STAT_LOWPT_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_STAT_LOWPT_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_SYST_LOWPT_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_SYST_LOWPT_UP_AT;
   Float_t         lepSF_SF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;
   Float_t         lepSF_SF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;
   Float_t         lepSF_SF_Mu_Iso_FCLoose_SYST_UP_AT;
   Float_t         lepSF_SF_Mu_Iso_FCLoose_SYST_DOWN_AT;
   Float_t         lepSF_SF_Mu_Iso_FCLoose_STAT_UP_AT;
   Float_t         lepSF_SF_Mu_Iso_FCLoose_STAT_DOWN_AT;
   Float_t         bTagSF_weight_DL1r_60;
   Float_t         bTagSF_weight_DL1r_70;
   Float_t         bTagSF_weight_DL1r_77;
   Float_t         bTagSF_weight_DL1r_85;
   Float_t         bTagSF_weight_DL1r_Continuous;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_0__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_0__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_10__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_10__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_11__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_11__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_12__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_12__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_13__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_13__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_14__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_14__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_15__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_15__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_16__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_16__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_17__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_17__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_18__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_18__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_19__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_19__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_1__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_1__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_20__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_20__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_21__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_21__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_22__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_22__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_23__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_23__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_24__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_24__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_25__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_25__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_26__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_26__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_27__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_27__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_28__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_28__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_29__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_29__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_2__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_2__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_30__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_30__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_31__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_31__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_32__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_32__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_33__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_33__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_34__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_34__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_35__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_35__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_36__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_36__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_37__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_37__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_38__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_38__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_39__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_39__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_3__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_3__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_40__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_40__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_41__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_41__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_42__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_42__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_43__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_43__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_44__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_44__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_4__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_4__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_5__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_5__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_6__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_6__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_7__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_7__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_8__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_8__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_9__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_9__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_0__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_0__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_10__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_10__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_11__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_11__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_12__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_12__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_13__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_13__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_14__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_14__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_15__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_15__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_16__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_16__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_17__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_17__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_18__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_18__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_19__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_19__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_1__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_1__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_2__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_2__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_3__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_3__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_4__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_4__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_5__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_5__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_6__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_6__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_7__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_7__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_8__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_8__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_9__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_9__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down;
   Float_t         bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigSystUncertainty__1down;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigSystUncertainty__1down;
   Float_t         jvtSF_customOR__1up;
   Float_t         jvtSF_customOR__1down;
   Float_t         fjvtSF_customOR__1up;
   Float_t         fjvtSF_customOR__1down;
   Double_t        mc_norm;

   // List of branches
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_pileup_UP;   //!
   TBranch        *b_weight_pileup_DOWN;   //!
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
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
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
   TBranch        *b_nTaus_OR_Pt25;   //!
   TBranch        *b_nTaus_OR;   //!
   TBranch        *b_nTaus_OR_Medium;   //!
   TBranch        *b_nTaus_OR_Tight;   //!
   TBranch        *b_isBlinded;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_inclFwdJets;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_HT_fwdJets;   //!
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
   TBranch        *b_lep_isolationHighPtCaloOnly_0;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_0;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_0;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_0;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_0;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_0;   //!
   TBranch        *b_lep_isolationTight_FixedRad_0;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_0;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_0;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_0;   //!
   TBranch        *b_lep_isolationTight_VarRad_0;   //!
   TBranch        *b_lep_isolationLoose_VarRad_0;   //!
   TBranch        *b_lep_plvWP_Loose_0;   //!
   TBranch        *b_lep_plvWP_Tight_0;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;   //!
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
   TBranch        *b_lep_DFCommonJetDr_0;   //!
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
   TBranch        *b_lep_isolationHighPtCaloOnly_1;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_1;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_1;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_1;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_1;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_1;   //!
   TBranch        *b_lep_isolationTight_FixedRad_1;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_1;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_1;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_1;   //!
   TBranch        *b_lep_isolationTight_VarRad_1;   //!
   TBranch        *b_lep_isolationLoose_VarRad_1;   //!
   TBranch        *b_lep_plvWP_Loose_1;   //!
   TBranch        *b_lep_plvWP_Tight_1;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;   //!
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
   TBranch        *b_lep_DFCommonJetDr_1;   //!
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
   TBranch        *b_lep_isolationHighPtCaloOnly_2;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_2;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_2;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_2;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_2;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_2;   //!
   TBranch        *b_lep_isolationTight_FixedRad_2;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_2;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_2;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_2;   //!
   TBranch        *b_lep_isolationTight_VarRad_2;   //!
   TBranch        *b_lep_isolationLoose_VarRad_2;   //!
   TBranch        *b_lep_plvWP_Loose_2;   //!
   TBranch        *b_lep_plvWP_Tight_2;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;   //!
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
   TBranch        *b_lep_DFCommonJetDr_2;   //!
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
   TBranch        *b_lep_isolationHighPtCaloOnly_3;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_3;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_3;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_3;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_3;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_3;   //!
   TBranch        *b_lep_isolationTight_FixedRad_3;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_3;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_3;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_3;   //!
   TBranch        *b_lep_isolationTight_VarRad_3;   //!
   TBranch        *b_lep_isolationLoose_VarRad_3;   //!
   TBranch        *b_lep_plvWP_Loose_3;   //!
   TBranch        *b_lep_plvWP_Tight_3;   //!
   TBranch        *b_lep_isTrigMatch_3;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_3;   //!
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
   TBranch        *b_lep_DFCommonJetDr_3;   //!
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
   TBranch        *b_lep_isolationHighPtCaloOnly_4;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_4;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_4;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_4;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_4;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_4;   //!
   TBranch        *b_lep_isolationTight_FixedRad_4;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_4;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_4;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_4;   //!
   TBranch        *b_lep_isolationTight_VarRad_4;   //!
   TBranch        *b_lep_isolationLoose_VarRad_4;   //!
   TBranch        *b_lep_plvWP_Loose_4;   //!
   TBranch        *b_lep_plvWP_Tight_4;   //!
   TBranch        *b_lep_isTrigMatch_4;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_4;   //!
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
   TBranch        *b_lep_DFCommonJetDr_4;   //!
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
   TBranch        *b_jets_score_DL1r;   //!
   TBranch        *b_jets_btagFlag_DL1r_ContinuousBin;   //!
   TBranch        *b_jets_score_DL1r_pu;   //!
   TBranch        *b_jets_score_DL1r_pc;   //!
   TBranch        *b_jets_score_DL1r_pb;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_60;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_77;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jets_btag_JetVertexCharge_discriminant;   //!
   TBranch        *b_jets_ConeTruthLabelID;   //!
   TBranch        *b_jets_HadronConeExclExtendedTruthLabelID;   //!
   TBranch        *b_jets_HadronConeExclTruthLabelID;   //!
   TBranch        *b_jets_PartonTruthLabelID;   //!
   TBranch        *b_jets_isQuarkJet;   //!
   TBranch        *b_jets_isQuarkJetBDT;   //!
   TBranch        *b_jets_DFCommonJets_QGTagger_NTracks;   //!
   TBranch        *b_jets_DFCommonJets_QGTagger_TracksWidth;   //!
   TBranch        *b_jets_DFCommonJets_QGTagger_TracksC1;   //!
   TBranch        *b_jets_DFCommonJets_fJvt;   //!
   TBranch        *b_GlobalTrigMatch_AT_default_postOR;   //!
   TBranch        *b_GlobalTrigDecision;   //!
   TBranch        *b_flag_JetCleaning_LooseBad;   //!
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
   TBranch        *b_met_sumet;   //!
   TBranch        *b_higgsDecayMode;   //!
   TBranch        *b_hhiggsDecayMode;   //!
   TBranch        *b_initial_state;   //!
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
   TBranch        *b_m_truth_parentsID;   //!
   TBranch        *b_m_truth_childrenID;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_lepSFObjChannelCombined;   //!
   TBranch        *b_jvtSF_customOR;   //!
   TBranch        *b_fjvtSF_customOR;   //!
   TBranch        *b_tauSFRNNMedium_TAU_SF_NOMINAL;   //!
   TBranch        *b_tauSFRNNLoose_TAU_SF_NOMINAL;   //!
   TBranch        *b_tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP;   //!
   TBranch        *b_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP;   //!
   TBranch        *b_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP;   //!
   TBranch        *b_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP;   //!
   TBranch        *b_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_HIGHPT_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_HIGHPT_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_SYST_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_SYST_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RNNID_SYST_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RNNID_SYST_DOWN;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RECO_TOTAL_UP;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RECO_TOTAL_UP;   //!
   TBranch        *b_tauSFRNNMedium_EFF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_tauSFRNNLoose_EFF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_Reco_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_Reco_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_ID_LooseAndBLayerLH_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_ID_TightLH_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_ID_LooseAndBLayerLH_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_ID_TightLH_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_El_Iso_FCLoose_UP_AT;   //!
   TBranch        *b_lepSF_SF_El_Iso_FCLoose_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_TTVA_STAT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_TTVA_STAT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_TTVA_SYST_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_TTVA_SYST_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_STAT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_STAT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_STAT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_STAT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_SYST_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_SYST_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_SYST_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_SYST_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_Iso_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_Iso_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_lepSF_SF_Mu_Iso_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_lepSF_SF_Mu_Iso_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_bTagSF_weight_DL1r_60;   //!
   TBranch        *b_bTagSF_weight_DL1r_70;   //!
   TBranch        *b_bTagSF_weight_DL1r_77;   //!
   TBranch        *b_bTagSF_weight_DL1r_85;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_0__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_0__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_10__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_10__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_11__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_11__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_12__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_12__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_13__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_13__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_14__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_14__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_15__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_15__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_16__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_16__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_17__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_17__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_18__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_18__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_19__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_19__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_1__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_1__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_20__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_20__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_21__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_21__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_22__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_22__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_23__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_23__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_24__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_24__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_25__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_25__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_26__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_26__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_27__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_27__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_28__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_28__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_29__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_29__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_2__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_2__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_30__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_30__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_31__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_31__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_32__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_32__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_33__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_33__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_34__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_34__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_35__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_35__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_36__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_36__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_37__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_37__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_38__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_38__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_39__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_39__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_3__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_3__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_40__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_40__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_41__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_41__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_42__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_42__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_43__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_43__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_44__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_44__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_4__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_4__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_5__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_5__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_6__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_6__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_7__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_7__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_8__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_8__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_9__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_B_9__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_0__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_0__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_10__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_10__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_11__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_11__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_12__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_12__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_13__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_13__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_14__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_14__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_15__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_15__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_16__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_16__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_17__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_17__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_18__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_18__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_19__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_19__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_1__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_1__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_2__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_2__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_3__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_3__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_4__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_4__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_5__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_5__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_6__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_6__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_7__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_7__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_8__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_8__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_9__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_C_9__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT_MUON_EFF_TrigSystUncertainty__1down;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT_MUON_EFF_TrigSystUncertainty__1down;   //!
   TBranch        *b_jvtSF_customOR__1up;   //!
   TBranch        *b_jvtSF_customOR__1down;   //!
   TBranch        *b_fjvtSF_customOR__1up;   //!
   TBranch        *b_fjvtSF_customOR__1down;   //!
   TBranch        *b_mc_norm;   //!
};
