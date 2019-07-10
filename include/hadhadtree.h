
#ifndef hadhadtree_h
#define hadhadtree_h
#include "nominal.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "cutflow.h"
// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"
#include "TVector3.h"

// Fixed size dimensions of array or collections stored in the TTree if any.

class hadhadtree : public nominal{
public :
   // Declaration of leaf types
   hadhadtree();
   void Loop(TTree*inputtree, TString samplename, float globalweight);
   virtual void     Init(TTree *tree);
   void init_sample(TString sample, TString sampletitle);
   void init_hist(TString histfilename);
   void definetaus();
   void definejets();
   void definetree(TTree * tree);
   bool addWeightSys();
   void fill_fcnc(TString region, int nprong, TString sample, int iptbin, bool taubtag, int iNP);
   static  void     fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
   TMinuit* initgM();
   void init_reduce1();
   void init_reduce2();
   bool isData = 0;
   int tauabspdg = 0;
   bool nominaltree = 0;
   cutflow hadcutflow;
   vector<Int_t>           *taus_id = 0;
   vector<Int_t>           *taus_b_tagged = 0;
   vector<UInt_t>          *taus_decay_mode = 0;
   vector<Int_t>           *taus_matched_mother_pdgId = 0;
   vector<Int_t>           *taus_matched_mother_status = 0;
   vector<Int_t>           *taus_matched_pdgId = 0;
   vector<UInt_t>          *taus_n_charged_tracks = 0;
   vector<Float_t>         *taus_q = 0;
   vector<Float_t>         *bjets_fjvt = 0;
   vector<Int_t>           *bjets_is_Jvt_HS = 0;
   vector<Float_t>         *bjets_jvt = 0;
   vector<Int_t>           *bjets_origin = 0;
   vector<Float_t>         *bjets_q = 0;
   vector<Int_t>           *bjets_type = 0;
   vector<Float_t>         *bjets_width = 0;
   vector<Float_t>         *bjets_wztruth_pdgid = 0;
   vector<Float_t>         *jets_fjvt = 0;
   vector<Int_t>           *jets_is_Jvt_HS = 0;
   vector<Float_t>         *jets_jvt = 0;
   vector<Int_t>           *jets_origin = 0;
   vector<Float_t>         *jets_q = 0;
   vector<Int_t>           *jets_type = 0;
   vector<Float_t>         *jets_width = 0;
   vector<Float_t>         *jets_wztruth_pdgid = 0;

   vector<TLorentzVector*>  *taus_matched_p4;
   vector<TLorentzVector*>  *taus_matched_vis_p4;
   vector<TLorentzVector*>  *taus_p4;
   vector<TLorentzVector*>  *bjets_p4;
   vector<TLorentzVector*>  *bjets_wztruth_p4;
   vector<TLorentzVector*>  *jets_p4;
   vector<TLorentzVector*>  *jets_wztruth_p4;

   UInt_t          HLT_tau35_loose1_tracktwo_tau25_loose1_tracktwo;
   UInt_t          HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;
   UInt_t          HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          HLT_tau40_medium1_tracktwoEF_tau35_medium1_tracktwoEF;
   UInt_t          HLT_tau40_medium1_tracktwo_tau35_medium1_tracktwo;
   UInt_t          HLT_tau40_mediumRNN_tracktwoMVA_tau35_mediumRNN_tracktwoMVA;
   UInt_t          HLT_tau80_medium1_TAU60_tau50_medium1_L1TAU12;
   UInt_t          HLT_tau80_medium1_tracktwoEF_L1TAU60_tau35_medium1_tracktwoEF_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I;
   UInt_t          HLT_tau80_medium1_tracktwoEF_L1TAU60_tau60_medium1_tracktwoEF_L1TAU40;
   UInt_t          HLT_tau80_medium1_tracktwo_L1TAU60_tau35_medium1_tracktwo_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I;
   UInt_t          HLT_tau80_medium1_tracktwo_L1TAU60_tau50_medium1_tracktwo_L1TAU12;
   UInt_t          HLT_tau80_medium1_tracktwo_L1TAU60_tau60_medium1_tracktwo_L1TAU40;
   UInt_t          HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau35_mediumRNN_tracktwoMVA_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I;
   UInt_t          HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau60_mediumRNN_tracktwoMVA_L1TAU40;
   Int_t           HTXS_Njets_pTjet25;
   Int_t           HTXS_Njets_pTjet30;
   Int_t           HTXS_Stage0_Category;
   Int_t           HTXS_Stage1_Category_pTjet25GeV;
   Int_t           HTXS_Stage1_Category_pTjet30GeV;
   Int_t           HTXS_errorMode;
   Int_t           HTXS_prodMode;
   Float_t         NOMINAL_pileup_combined_weight;
   UInt_t          NOMINAL_pileup_random_lb_number;
   UInt_t          NOMINAL_pileup_random_run_number;
   Float_t         PRW_DATASF_1down_pileup_combined_weight;
   Float_t         PRW_DATASF_1up_pileup_combined_weight;
   TLorentzVector  *boson_0_truth_p4;
   Int_t           boson_0_truth_pdgId;
   Float_t         boson_0_truth_q;
   Int_t           boson_0_truth_status;
   Int_t           channel_index;
   TLorentzVector  *dijet_p4;
   Int_t           ditau_coll_approx;
   Float_t         ditau_coll_approx_m;
   Float_t         ditau_coll_approx_x0;
   Float_t         ditau_coll_approx_x1;
   Float_t         ditau_cosalpha;
   Float_t         ditau_deta;
   Float_t         ditau_dphi;
   Float_t         ditau_dr;
   Double_t        ditau_higgspt;
   Int_t           ditau_matched;
   Float_t         ditau_matched_cosalpha;
   Float_t         ditau_matched_deta;
   Float_t         ditau_matched_dphi;
   Float_t         ditau_matched_dr;
   TLorentzVector  *ditau_matched_p4;
   Float_t         ditau_matched_qxq;
   Float_t         ditau_matched_scal_sum_pt;
   Float_t         ditau_matched_vis_cosalpha;
   Float_t         ditau_matched_vis_deta;
   Float_t         ditau_matched_vis_dphi;
   Float_t         ditau_matched_vis_dr;
   Float_t         ditau_matched_vis_mass;
   Float_t         ditau_matched_vis_scal_sum_pt;
   Float_t         ditau_matched_vis_vect_sum_pt;
   Float_t         ditau_met_centrality;
   Float_t         ditau_met_lep0_cos_dphi;
   Float_t         ditau_met_lep1_cos_dphi;
   Float_t         ditau_met_min_dphi;
   Float_t         ditau_met_sum_cos_dphi;
   Float_t         ditau_mmc_maxw_eta;
   Int_t           ditau_mmc_maxw_fit_status;
   Float_t         ditau_mmc_maxw_m;
   Float_t         ditau_mmc_maxw_met_et;
   Float_t         ditau_mmc_maxw_met_phi;
   Float_t         ditau_mmc_maxw_phi;
   Float_t         ditau_mmc_maxw_pt;
   Float_t         ditau_mmc_maxw_x0;
   Float_t         ditau_mmc_maxw_x1;
   Int_t           ditau_mmc_mlm_fit_status;
   Float_t         ditau_mmc_mlm_m;
   Float_t         ditau_mt_lep0_met;
   Float_t         ditau_mt_lep1_met;
   TLorentzVector  *ditau_p4;
   Float_t         ditau_qxq;
   Float_t         ditau_scal_sum_pt;
   UInt_t          event_clean_EC_TightBad;
   ULong64_t       event_number;
   UInt_t          higgs;
   UInt_t          higgs_child1;
   Int_t           higgs_child1_classifierParticleOrigin;
   Int_t           higgs_child1_classifierParticleType;
   Int_t           higgs_child1_mother_pdgId;
   Int_t           higgs_child1_mother_status;
   Int_t           higgs_child1_origin;
   TLorentzVector  *higgs_child1_p4;
   Int_t           higgs_child1_pdgId;
   Float_t         higgs_child1_pz;
   Float_t         higgs_child1_q;
   Int_t           higgs_child1_status;
   Int_t           higgs_child1_type;
   UInt_t          higgs_child2;
   Int_t           higgs_child2_classifierParticleOrigin;
   Int_t           higgs_child2_classifierParticleType;
   Int_t           higgs_child2_mother_pdgId;
   Int_t           higgs_child2_mother_status;
   Int_t           higgs_child2_origin;
   TLorentzVector  *higgs_child2_p4;
   Int_t           higgs_child2_pdgId;
   Float_t         higgs_child2_pz;
   Float_t         higgs_child2_q;
   Int_t           higgs_child2_status;
   Int_t           higgs_child2_type;
   UInt_t          higgs_child3;
   Int_t           higgs_child3_classifierParticleOrigin;
   Int_t           higgs_child3_classifierParticleType;
   Int_t           higgs_child3_mother_pdgId;
   Int_t           higgs_child3_mother_status;
   Int_t           higgs_child3_origin;
   TLorentzVector  *higgs_child3_p4;
   Int_t           higgs_child3_pdgId;
   Float_t         higgs_child3_pz;
   Float_t         higgs_child3_q;
   Int_t           higgs_child3_status;
   Int_t           higgs_child3_type;
   UInt_t          higgs_child4;
   Int_t           higgs_child4_classifierParticleOrigin;
   Int_t           higgs_child4_classifierParticleType;
   Int_t           higgs_child4_mother_pdgId;
   Int_t           higgs_child4_mother_status;
   Int_t           higgs_child4_origin;
   TLorentzVector  *higgs_child4_p4;
   Int_t           higgs_child4_pdgId;
   Float_t         higgs_child4_pz;
   Float_t         higgs_child4_q;
   Int_t           higgs_child4_status;
   Int_t           higgs_child4_type;
   Int_t           higgs_classifierParticleOrigin;
   Int_t           higgs_classifierParticleType;
   Int_t           higgs_mother_pdgId;
   Int_t           higgs_mother_status;
   Int_t           higgs_origin;
   TLorentzVector  *higgs_p4;
   Int_t           higgs_pdgId;
   Float_t         higgs_pz;
   Float_t         higgs_q;
   Int_t           higgs_status;
   Int_t           higgs_type;
   UInt_t          is_dijet_centrality;
   Int_t           jet_0_b_tagged;
   Float_t         jet_0_fjvt;
   Int_t           jet_0_flavorlabel_part;
   Int_t           jet_0_is_Jvt_HS;
   Float_t         jet_0_jvt;
   TLorentzVector  *jet_0_p4;
   Float_t         jet_0_width;
   TLorentzVector  *jet_0_wztruth_p4;
   Float_t         jet_0_wztruth_pdgid;
   Int_t           jet_1_b_tagged;
   Float_t         jet_1_fjvt;
   Int_t           jet_1_flavorlabel_part;
   Int_t           jet_1_is_Jvt_HS;
   Float_t         jet_1_jvt;
   TLorentzVector  *jet_1_p4;
   Float_t         jet_1_width;
   TLorentzVector  *jet_1_wztruth_p4;
   Float_t         jet_1_wztruth_pdgid;
   Int_t           jet_2_b_tagged;
   Float_t         jet_2_fjvt;
   Int_t           jet_2_flavorlabel_part;
   Int_t           jet_2_is_Jvt_HS;
   Float_t         jet_2_jvt;
   TLorentzVector  *jet_2_p4;
   Float_t         jet_2_width;
   TLorentzVector  *jet_2_wztruth_p4;
   Float_t         jet_2_wztruth_pdgid;
   UInt_t          jet_3;
   Int_t           jet_3_b_tag_quantile;
   Float_t         jet_3_b_tag_score;
   Int_t           jet_3_b_tagged;
   UInt_t          jet_3_cleanJet_EC_LooseBad;
   Float_t         jet_3_fjvt;
   Int_t           jet_3_flavorlabel;
   Int_t           jet_3_flavorlabel_cone;
   Int_t           jet_3_flavorlabel_part;
   Int_t           jet_3_is_Jvt_HS;
   Float_t         jet_3_jvt;
   Int_t           jet_3_origin;
   TLorentzVector  *jet_3_p4;
   Float_t         jet_3_q;
   Int_t           jet_3_type;
   Float_t         jet_3_width;
   TLorentzVector  *jet_3_wztruth_p4;
   Float_t         jet_3_wztruth_pdgid;
   UInt_t          jet_4;
   Int_t           jet_4_b_tag_quantile;
   Float_t         jet_4_b_tag_score;
   Int_t           jet_4_b_tagged;
   UInt_t          jet_4_cleanJet_EC_LooseBad;
   Float_t         jet_4_fjvt;
   Int_t           jet_4_flavorlabel;
   Int_t           jet_4_flavorlabel_cone;
   Int_t           jet_4_flavorlabel_part;
   Int_t           jet_4_is_Jvt_HS;
   Float_t         jet_4_jvt;
   Int_t           jet_4_origin;
   TLorentzVector  *jet_4_p4;
   Float_t         jet_4_q;
   Int_t           jet_4_type;
   Float_t         jet_4_width;
   TLorentzVector  *jet_4_wztruth_p4;
   Float_t         jet_4_wztruth_pdgid;
   UInt_t          jet_5;
   Int_t           jet_5_b_tag_quantile;
   Float_t         jet_5_b_tag_score;
   Int_t           jet_5_b_tagged;
   UInt_t          jet_5_cleanJet_EC_LooseBad;
   Float_t         jet_5_fjvt;
   Int_t           jet_5_flavorlabel;
   Int_t           jet_5_flavorlabel_cone;
   Int_t           jet_5_flavorlabel_part;
   Int_t           jet_5_is_Jvt_HS;
   Float_t         jet_5_jvt;
   Int_t           jet_5_origin;
   TLorentzVector  *jet_5_p4;
   Float_t         jet_5_q;
   Int_t           jet_5_type;
   Float_t         jet_5_width;
   TLorentzVector  *jet_5_wztruth_p4;
   Float_t         jet_5_wztruth_pdgid;
   UInt_t          jet_6;
   Int_t           jet_6_b_tag_quantile;
   Float_t         jet_6_b_tag_score;
   Int_t           jet_6_b_tagged;
   UInt_t          jet_6_cleanJet_EC_LooseBad;
   Float_t         jet_6_fjvt;
   Int_t           jet_6_flavorlabel;
   Int_t           jet_6_flavorlabel_cone;
   Int_t           jet_6_flavorlabel_part;
   Int_t           jet_6_is_Jvt_HS;
   Float_t         jet_6_jvt;
   Int_t           jet_6_origin;
   TLorentzVector  *jet_6_p4;
   Float_t         jet_6_q;
   Int_t           jet_6_type;
   Float_t         jet_6_width;
   TLorentzVector  *jet_6_wztruth_p4;
   Float_t         jet_6_wztruth_pdgid;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10;
   Float_t         jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT;
   Float_t         jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT;
   Float_t         jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT;
   Float_t         jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT;
   Float_t         jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT;
   Float_t         jet_NOMINAL_central_jets_global_effSF_JVT;
   Float_t         jet_NOMINAL_central_jets_global_ineffSF_JVT;
   Float_t         jet_NOMINAL_forward_jets_global_effSF_JVT;
   Float_t         jet_NOMINAL_forward_jets_global_ineffSF_JVT;
   Float_t         jet_NOMINAL_global_effSF_MV2c10;
   Float_t         jet_NOMINAL_global_ineffSF_MV2c10;
   Float_t         lepton_eta_centrality;
   UInt_t          mc_channel_number;
   TLorentzVector  *met_hpto_p4;
   Float_t         met_more_met_et_ele;
   Float_t         met_more_met_et_jet;
   Float_t         met_more_met_et_muon;
   Float_t         met_more_met_et_pho;
   Float_t         met_more_met_et_soft;
   Float_t         met_more_met_et_tau;
   Float_t         met_more_met_phi_ele;
   Float_t         met_more_met_phi_jet;
   Float_t         met_more_met_phi_muon;
   Float_t         met_more_met_phi_pho;
   Float_t         met_more_met_phi_soft;
   Float_t         met_more_met_phi_tau;
   Float_t         met_more_met_sumet_ele;
   Float_t         met_more_met_sumet_jet;
   Float_t         met_more_met_sumet_muon;
   Float_t         met_more_met_sumet_pho;
   Float_t         met_more_met_sumet_soft;
   Float_t         met_more_met_sumet_tau;
   TLorentzVector  *met_p4;
   Float_t         met_sign_met_over_sqrt_ht;
   Float_t         met_sign_met_over_sqrt_sumet;
   Float_t         met_sign_met_rho;
   Float_t         met_sign_met_rho_ttdir;
   Float_t         met_sign_met_sig_directional;
   Float_t         met_sign_met_sig_directional_ttdir;
   Float_t         met_sign_met_significance;
   Float_t         met_sign_met_significance_ttdir;
   Float_t         met_sign_met_valL;
   Float_t         met_sign_met_valL_ttdir;
   Float_t         met_sign_met_varT;
   Float_t         met_sign_met_varT_ttdir;
   Float_t         met_sumet;
   TLorentzVector  *met_truth_p4;
   Float_t         met_truth_sumet;
   Double_t        mva_random_number;
   Float_t         n_actual_int;
   Float_t         n_actual_int_cor;
   Float_t         n_avg_int;
   Float_t         n_avg_int_cor;
   Int_t           n_bjets;
   Int_t           n_electrons;
   Int_t           n_jets;
   Int_t           n_jets_30;
   Int_t           n_jets_40;
   Int_t           n_jets_central;
   Int_t           n_jets_central_30;
   Int_t           n_jets_central_40;
   Int_t           n_jets_forward;
   Int_t           n_jets_forward_30;
   Int_t           n_jets_forward_40;
   Int_t           n_jets_l1j25;
   Int_t           n_jets_mc_hs;
   Int_t           n_muons;
   Int_t           n_photons;
   Int_t           n_pvx;
   Int_t           n_taus;
   Int_t           n_taus_loose;
   Int_t           n_taus_medium;
   Int_t           n_taus_tight;
   Int_t           n_taus_veryloose;
   UInt_t          n_truth_gluon_jets;
   UInt_t          n_truth_jets;
   UInt_t          n_truth_jets_pt20_eta45;
   UInt_t          n_truth_quark_jets;
   Int_t           n_vx;
   Int_t           primary_vertex;
   TVector3        *primary_vertex_v;
   Float_t         pt_total;
   UInt_t          run_number;
   Float_t         scalar_sum_pt;
   UInt_t          tau_0;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_0_NOMINAL_TauEffSF_JetBDTloose;
   Float_t         tau_0_NOMINAL_TauEffSF_JetBDTmedium;
   Float_t         tau_0_NOMINAL_TauEffSF_JetBDTtight;
   Float_t         tau_0_NOMINAL_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_NOMINAL_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_NOMINAL_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_NOMINAL_TauEffSF_reco;
   Float_t         tau_0_NOMINAL_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_0_allTrk_eta;
   UInt_t          tau_0_allTrk_n;
   Float_t         tau_0_allTrk_phi;
   Float_t         tau_0_allTrk_pt;
   Int_t           tau_0_b_tagged;
   UInt_t          tau_0_decay_mode;
   Float_t         tau_0_ele_bdt_eff_sf;
   Int_t           tau_0_ele_bdt_loose_retuned;
   Int_t           tau_0_ele_bdt_medium_retuned;
   Float_t         tau_0_ele_bdt_score;
   Float_t         tau_0_ele_bdt_score_retuned;
   Float_t         tau_0_ele_bdt_score_trans;
   Float_t         tau_0_ele_bdt_score_trans_retuned;
   Int_t           tau_0_ele_bdt_tight_retuned;
   Float_t         tau_0_ele_match_lhscore;
   UInt_t          tau_0_ele_olr_pass;
   UInt_t          tau_0_jet_bdt_loose;
   UInt_t          tau_0_jet_bdt_medium;
   Float_t         tau_0_jet_bdt_score_trans;
   UInt_t          tau_0_jet_bdt_tight;
   UInt_t          tau_0_jet_bdt_veryloose;
   Float_t         tau_0_jet_jvt;
   UInt_t          tau_0_jet_rnn_loose;
   UInt_t          tau_0_jet_rnn_medium;
   Float_t         tau_0_jet_rnn_score;
   Float_t         tau_0_jet_rnn_score_trans;
   UInt_t          tau_0_jet_rnn_tight;
   UInt_t          tau_0_jet_rnn_veryloose;
   Float_t         tau_0_jet_width;
   Float_t         tau_0_leadTrk_eta;
   Float_t         tau_0_leadTrk_phi;
   Float_t         tau_0_leadTrk_pt;
   UInt_t          tau_0_matched;
   Int_t           tau_0_matched_classifierParticleOrigin;
   Int_t           tau_0_matched_classifierParticleType;
   TLorentzVector  *tau_0_matched_decay_charged_p4;
   Int_t           tau_0_matched_decay_mode;
   TLorentzVector  *tau_0_matched_decay_neutral_p4;
   TLorentzVector  *tau_0_matched_decay_neutrino_p4;
   UInt_t          tau_0_matched_isEle;
   UInt_t          tau_0_matched_isHadTau;
   UInt_t          tau_0_matched_isJet;
   UInt_t          tau_0_matched_isMuon;
   UInt_t          tau_0_matched_isTau;
   UInt_t          tau_0_matched_isTruthMatch;
   Int_t           tau_0_matched_mother_pdgId;
   Int_t           tau_0_matched_mother_status;
   Int_t           tau_0_matched_n_charged;
   Int_t           tau_0_matched_n_charged_pion;
   Int_t           tau_0_matched_n_neutral;
   Int_t           tau_0_matched_n_neutral_pion;
   TLorentzVector  *tau_0_matched_p4;
   TLorentzVector  *tau_0_matched_p4_vis_charged_track0;
   TLorentzVector  *tau_0_matched_p4_vis_charged_track1;
   TLorentzVector  *tau_0_matched_p4_vis_charged_track2;
   Int_t           tau_0_matched_pdgId;
   Float_t         tau_0_matched_q;
   Int_t           tau_0_matched_status;
   Int_t           tau_0_matched_type;
   TLorentzVector  *tau_0_matched_vis_charged_p4;
   TLorentzVector  *tau_0_matched_vis_neutral_others_p4;
   TLorentzVector  *tau_0_matched_vis_neutral_p4;
   TLorentzVector  *tau_0_matched_vis_neutral_pions_p4;
   TLorentzVector  *tau_0_matched_vis_p4;
   UInt_t          tau_0_n_all_tracks;
   UInt_t          tau_0_n_charged_tracks;
   UInt_t          tau_0_n_conversion_tracks;
   UInt_t          tau_0_n_core_tracks;
   UInt_t          tau_0_n_failTrackFilter_tracks;
   UInt_t          tau_0_n_fake_tracks;
   UInt_t          tau_0_n_isolation_tracks;
   UInt_t          tau_0_n_modified_isolation_tracks;
   UInt_t          tau_0_n_old_tracks;
   UInt_t          tau_0_n_passTrkSelectionTight_tracks;
   UInt_t          tau_0_n_passTrkSelector_tracks;
   UInt_t          tau_0_n_unclassified_tracks;
   UInt_t          tau_0_n_wide_tracks;
   Int_t           tau_0_origin;
   TLorentzVector  *tau_0_p4;
   Float_t         tau_0_q;
   TLorentzVector  *tau_0_track0_p4;
   TLorentzVector  *tau_0_track1_p4;
   TLorentzVector  *tau_0_track2_p4;
   UInt_t          tau_0_trig_HLT_tau25_medium1_tracktwo;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;
   UInt_t          tau_0_trig_trigger_matched;
   Int_t           tau_0_type;
   UInt_t          tau_1;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_1_NOMINAL_TauEffSF_JetBDTloose;
   Float_t         tau_1_NOMINAL_TauEffSF_JetBDTmedium;
   Float_t         tau_1_NOMINAL_TauEffSF_JetBDTtight;
   Float_t         tau_1_NOMINAL_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_NOMINAL_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_NOMINAL_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_NOMINAL_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_NOMINAL_TauEffSF_reco;
   Float_t         tau_1_NOMINAL_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDTPlusVeto_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
   Float_t         tau_1_allTrk_eta;
   UInt_t          tau_1_allTrk_n;
   Float_t         tau_1_allTrk_phi;
   Float_t         tau_1_allTrk_pt;
   Int_t           tau_1_b_tagged;
   UInt_t          tau_1_decay_mode;
   Float_t         tau_1_ele_bdt_eff_sf;
   Int_t           tau_1_ele_bdt_loose_retuned;
   Int_t           tau_1_ele_bdt_medium_retuned;
   Float_t         tau_1_ele_bdt_score;
   Float_t         tau_1_ele_bdt_score_retuned;
   Float_t         tau_1_ele_bdt_score_trans;
   Float_t         tau_1_ele_bdt_score_trans_retuned;
   Int_t           tau_1_ele_bdt_tight_retuned;
   Float_t         tau_1_ele_match_lhscore;
   UInt_t          tau_1_ele_olr_pass;
   UInt_t          tau_1_jet_bdt_loose;
   UInt_t          tau_1_jet_bdt_medium;
   Float_t         tau_1_jet_bdt_score_trans;
   UInt_t          tau_1_jet_bdt_tight;
   UInt_t          tau_1_jet_bdt_veryloose;
   Float_t         tau_1_jet_jvt;
   UInt_t          tau_1_jet_rnn_loose;
   UInt_t          tau_1_jet_rnn_medium;
   Float_t         tau_1_jet_rnn_score;
   Float_t         tau_1_jet_rnn_score_trans;
   UInt_t          tau_1_jet_rnn_tight;
   UInt_t          tau_1_jet_rnn_veryloose;
   Float_t         tau_1_jet_width;
   Float_t         tau_1_leadTrk_eta;
   Float_t         tau_1_leadTrk_phi;
   Float_t         tau_1_leadTrk_pt;
   UInt_t          tau_1_matched;
   Int_t           tau_1_matched_classifierParticleOrigin;
   Int_t           tau_1_matched_classifierParticleType;
   TLorentzVector  *tau_1_matched_decay_charged_p4;
   Int_t           tau_1_matched_decay_mode;
   TLorentzVector  *tau_1_matched_decay_neutral_p4;
   TLorentzVector  *tau_1_matched_decay_neutrino_p4;
   UInt_t          tau_1_matched_isEle;
   UInt_t          tau_1_matched_isHadTau;
   UInt_t          tau_1_matched_isJet;
   UInt_t          tau_1_matched_isMuon;
   UInt_t          tau_1_matched_isTau;
   UInt_t          tau_1_matched_isTruthMatch;
   Int_t           tau_1_matched_mother_pdgId;
   Int_t           tau_1_matched_mother_status;
   Int_t           tau_1_matched_n_charged;
   Int_t           tau_1_matched_n_charged_pion;
   Int_t           tau_1_matched_n_neutral;
   Int_t           tau_1_matched_n_neutral_pion;
   TLorentzVector  *tau_1_matched_p4;
   TLorentzVector  *tau_1_matched_p4_vis_charged_track0;
   TLorentzVector  *tau_1_matched_p4_vis_charged_track1;
   TLorentzVector  *tau_1_matched_p4_vis_charged_track2;
   Int_t           tau_1_matched_pdgId;
   Float_t         tau_1_matched_pz;
   Float_t         tau_1_matched_q;
   Int_t           tau_1_matched_status;
   TLorentzVector  *tau_1_matched_vis_charged_p4;
   TLorentzVector  *tau_1_matched_vis_neutral_others_p4;
   TLorentzVector  *tau_1_matched_vis_neutral_p4;
   TLorentzVector  *tau_1_matched_vis_neutral_pions_p4;
   TLorentzVector  *tau_1_matched_vis_p4;
   UInt_t          tau_1_n_all_tracks;
   UInt_t          tau_1_n_charged_tracks;
   UInt_t          tau_1_n_conversion_tracks;
   UInt_t          tau_1_n_core_tracks;
   UInt_t          tau_1_n_failTrackFilter_tracks;
   UInt_t          tau_1_n_fake_tracks;
   UInt_t          tau_1_n_isolation_tracks;
   UInt_t          tau_1_n_modified_isolation_tracks;
   UInt_t          tau_1_n_old_tracks;
   UInt_t          tau_1_n_passTrkSelectionTight_tracks;
   UInt_t          tau_1_n_passTrkSelector_tracks;
   UInt_t          tau_1_n_unclassified_tracks;
   UInt_t          tau_1_n_wide_tracks;
   Int_t           tau_1_origin;
   TLorentzVector  *tau_1_p4;
   Float_t         tau_1_q;
   TLorentzVector  *tau_1_track0_p4;
   TLorentzVector  *tau_1_track1_p4;
   TLorentzVector  *tau_1_track2_p4;
   UInt_t          tau_1_trig_HLT_tau25_medium1_tracktwo;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;
   UInt_t          tau_1_trig_trigger_matched;
   Int_t           tau_1_type;
   Float_t         tau_eta_centrality;
   UInt_t          tb;
   UInt_t          tb_childq;
   Int_t           tb_childq_classifierParticleOrigin;
   Int_t           tb_childq_classifierParticleType;
   Int_t           tb_childq_mother_pdgId;
   Int_t           tb_childq_mother_status;
   Int_t           tb_childq_origin;
   TLorentzVector  *tb_childq_p4;
   Int_t           tb_childq_pdgId;
   Float_t         tb_childq_pz;
   Float_t         tb_childq_q;
   Int_t           tb_childq_status;
   Int_t           tb_childq_type;
   Int_t           tb_classifierParticleOrigin;
   Int_t           tb_classifierParticleType;
   Int_t           tb_mother_pdgId;
   Int_t           tb_mother_status;
   Int_t           tb_origin;
   TLorentzVector  *tb_p4;
   Int_t           tb_pdgId;
   Float_t         tb_pz;
   Float_t         tb_q;
   Int_t           tb_status;
   Int_t           tb_type;
   UInt_t          top;
   UInt_t          top_childq;
   Int_t           top_childq_classifierParticleOrigin;
   Int_t           top_childq_classifierParticleType;
   Int_t           top_childq_mother_pdgId;
   Int_t           top_childq_mother_status;
   Int_t           top_childq_origin;
   TLorentzVector  *top_childq_p4;
   Int_t           top_childq_pdgId;
   Float_t         top_childq_pz;
   Float_t         top_childq_q;
   Int_t           top_childq_status;
   Int_t           top_childq_type;
   Int_t           top_classifierParticleOrigin;
   Int_t           top_classifierParticleType;
   Int_t           top_mother_pdgId;
   Int_t           top_mother_status;
   Int_t           top_origin;
   TLorentzVector  *top_p4;
   Int_t           top_pdgId;
   Float_t         top_pz;
   Float_t         top_q;
   Int_t           top_status;
   Int_t           top_type;
   UInt_t          truth_passedVBFFilter;
   Double_t        weight_mc;
   UInt_t          wm_childq1;
   Int_t           wm_childq1_classifierParticleOrigin;
   Int_t           wm_childq1_classifierParticleType;
   Int_t           wm_childq1_mother_pdgId;
   Int_t           wm_childq1_mother_status;
   Int_t           wm_childq1_origin;
   TLorentzVector  *wm_childq1_p4;
   Int_t           wm_childq1_pdgId;
   Float_t         wm_childq1_pz;
   Float_t         wm_childq1_q;
   Int_t           wm_childq1_status;
   Int_t           wm_childq1_type;
   UInt_t          wm_childq2;
   Int_t           wm_childq2_classifierParticleOrigin;
   Int_t           wm_childq2_classifierParticleType;
   Int_t           wm_childq2_mother_pdgId;
   Int_t           wm_childq2_mother_status;
   Int_t           wm_childq2_origin;
   TLorentzVector  *wm_childq2_p4;
   Int_t           wm_childq2_pdgId;
   Float_t         wm_childq2_pz;
   Float_t         wm_childq2_q;
   Int_t           wm_childq2_status;
   Int_t           wm_childq2_type;
   UInt_t          wp_childq1;
   Int_t           wp_childq1_classifierParticleOrigin;
   Int_t           wp_childq1_classifierParticleType;
   Int_t           wp_childq1_mother_pdgId;
   Int_t           wp_childq1_mother_status;
   Int_t           wp_childq1_origin;
   TLorentzVector  *wp_childq1_p4;
   Int_t           wp_childq1_pdgId;
   Float_t         wp_childq1_pz;
   Float_t         wp_childq1_q;
   Int_t           wp_childq1_status;
   Int_t           wp_childq1_type;
   UInt_t          wp_childq2;
   Int_t           wp_childq2_classifierParticleOrigin;
   Int_t           wp_childq2_classifierParticleType;
   Int_t           wp_childq2_mother_pdgId;
   Int_t           wp_childq2_mother_status;
   Int_t           wp_childq2_origin;
   TLorentzVector  *wp_childq2_p4;
   Int_t           wp_childq2_pdgId;
   Float_t         wp_childq2_pz;
   Float_t         wp_childq2_q;
   Int_t           wp_childq2_status;
   Int_t           wp_childq2_type;
   Float_t         theory_weights_LHE3Weight_muR_05_muF_05;
   Float_t         theory_weights_LHE3Weight_muR_05_muF_10;
   Float_t         theory_weights_LHE3Weight_muR_05_muF_20;
   Float_t         theory_weights_LHE3Weight_muR_10_muF_05;
   Float_t         theory_weights_LHE3Weight_muR_10_muF_20;
   Float_t         theory_weights_LHE3Weight_muR_20_muF_05;
   Float_t         theory_weights_LHE3Weight_muR_20_muF_10;
   Float_t         theory_weights_LHE3Weight_muR_20_muF_20;

   // List of branches
   TBranch        *b_HLT_tau35_loose1_tracktwo_tau25_loose1_tracktwo;   //!
   TBranch        *b_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_HLT_tau40_medium1_tracktwoEF_tau35_medium1_tracktwoEF;   //!
   TBranch        *b_HLT_tau40_medium1_tracktwo_tau35_medium1_tracktwo;   //!
   TBranch        *b_HLT_tau40_mediumRNN_tracktwoMVA_tau35_mediumRNN_tracktwoMVA;   //!
   TBranch        *b_HLT_tau80_medium1_TAU60_tau50_medium1_L1TAU12;   //!
   TBranch        *b_HLT_tau80_medium1_tracktwoEF_L1TAU60_tau35_medium1_tracktwoEF_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I;   //!
   TBranch        *b_HLT_tau80_medium1_tracktwoEF_L1TAU60_tau60_medium1_tracktwoEF_L1TAU40;   //!
   TBranch        *b_HLT_tau80_medium1_tracktwo_L1TAU60_tau35_medium1_tracktwo_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I;   //!
   TBranch        *b_HLT_tau80_medium1_tracktwo_L1TAU60_tau50_medium1_tracktwo_L1TAU12;   //!
   TBranch        *b_HLT_tau80_medium1_tracktwo_L1TAU60_tau60_medium1_tracktwo_L1TAU40;   //!
   TBranch        *b_HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau35_mediumRNN_tracktwoMVA_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I;   //!
   TBranch        *b_HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau60_mediumRNN_tracktwoMVA_L1TAU40;   //!
   TBranch        *b_HTXS_Njets_pTjet25;   //!
   TBranch        *b_HTXS_Njets_pTjet30;   //!
   TBranch        *b_HTXS_Stage0_Category;   //!
   TBranch        *b_HTXS_Stage1_Category_pTjet25GeV;   //!
   TBranch        *b_HTXS_Stage1_Category_pTjet30GeV;   //!
   TBranch        *b_HTXS_errorMode;   //!
   TBranch        *b_HTXS_prodMode;   //!
   TBranch        *b_NOMINAL_pileup_combined_weight;   //!
   TBranch        *b_NOMINAL_pileup_random_lb_number;   //!
   TBranch        *b_NOMINAL_pileup_random_run_number;   //!
   TBranch        *b_PRW_DATASF_1down_pileup_combined_weight;   //!
   TBranch        *b_PRW_DATASF_1up_pileup_combined_weight;   //!
   TBranch        *b_boson_0_truth_p4;   //!
   TBranch        *b_boson_0_truth_pdgId;   //!
   TBranch        *b_boson_0_truth_q;   //!
   TBranch        *b_boson_0_truth_status;   //!
   TBranch        *b_channel_index;   //!
   TBranch        *b_dijet_p4;   //!
   TBranch        *b_ditau_coll_approx;   //!
   TBranch        *b_ditau_coll_approx_m;   //!
   TBranch        *b_ditau_coll_approx_x0;   //!
   TBranch        *b_ditau_coll_approx_x1;   //!
   TBranch        *b_ditau_cosalpha;   //!
   TBranch        *b_ditau_deta;   //!
   TBranch        *b_ditau_dphi;   //!
   TBranch        *b_ditau_dr;   //!
   TBranch        *b_ditau_higgspt;   //!
   TBranch        *b_ditau_matched;   //!
   TBranch        *b_ditau_matched_cosalpha;   //!
   TBranch        *b_ditau_matched_deta;   //!
   TBranch        *b_ditau_matched_dphi;   //!
   TBranch        *b_ditau_matched_dr;   //!
   TBranch        *b_ditau_matched_p4;   //!
   TBranch        *b_ditau_matched_qxq;   //!
   TBranch        *b_ditau_matched_scal_sum_pt;   //!
   TBranch        *b_ditau_matched_vis_cosalpha;   //!
   TBranch        *b_ditau_matched_vis_deta;   //!
   TBranch        *b_ditau_matched_vis_dphi;   //!
   TBranch        *b_ditau_matched_vis_dr;   //!
   TBranch        *b_ditau_matched_vis_mass;   //!
   TBranch        *b_ditau_matched_vis_scal_sum_pt;   //!
   TBranch        *b_ditau_matched_vis_vect_sum_pt;   //!
   TBranch        *b_ditau_met_centrality;   //!
   TBranch        *b_ditau_met_lep0_cos_dphi;   //!
   TBranch        *b_ditau_met_lep1_cos_dphi;   //!
   TBranch        *b_ditau_met_min_dphi;   //!
   TBranch        *b_ditau_met_sum_cos_dphi;   //!
   TBranch        *b_ditau_mmc_maxw_eta;   //!
   TBranch        *b_ditau_mmc_maxw_fit_status;   //!
   TBranch        *b_ditau_mmc_maxw_m;   //!
   TBranch        *b_ditau_mmc_maxw_met_et;   //!
   TBranch        *b_ditau_mmc_maxw_met_phi;   //!
   TBranch        *b_ditau_mmc_maxw_phi;   //!
   TBranch        *b_ditau_mmc_maxw_pt;   //!
   TBranch        *b_ditau_mmc_maxw_x0;   //!
   TBranch        *b_ditau_mmc_maxw_x1;   //!
   TBranch        *b_ditau_mmc_mlm_fit_status;   //!
   TBranch        *b_ditau_mmc_mlm_m;   //!
   TBranch        *b_ditau_mt_lep0_met;   //!
   TBranch        *b_ditau_mt_lep1_met;   //!
   TBranch        *b_ditau_p4;   //!
   TBranch        *b_ditau_qxq;   //!
   TBranch        *b_ditau_scal_sum_pt;   //!
   TBranch        *b_event_clean_EC_TightBad;   //!
   TBranch        *b_event_number;   //!
   TBranch        *b_higgs;   //!
   TBranch        *b_higgs_child1;   //!
   TBranch        *b_higgs_child1_classifierParticleOrigin;   //!
   TBranch        *b_higgs_child1_classifierParticleType;   //!
   TBranch        *b_higgs_child1_mother_pdgId;   //!
   TBranch        *b_higgs_child1_mother_status;   //!
   TBranch        *b_higgs_child1_origin;   //!
   TBranch        *b_higgs_child1_p4;   //!
   TBranch        *b_higgs_child1_pdgId;   //!
   TBranch        *b_higgs_child1_pz;   //!
   TBranch        *b_higgs_child1_q;   //!
   TBranch        *b_higgs_child1_status;   //!
   TBranch        *b_higgs_child1_type;   //!
   TBranch        *b_higgs_child2;   //!
   TBranch        *b_higgs_child2_classifierParticleOrigin;   //!
   TBranch        *b_higgs_child2_classifierParticleType;   //!
   TBranch        *b_higgs_child2_mother_pdgId;   //!
   TBranch        *b_higgs_child2_mother_status;   //!
   TBranch        *b_higgs_child2_origin;   //!
   TBranch        *b_higgs_child2_p4;   //!
   TBranch        *b_higgs_child2_pdgId;   //!
   TBranch        *b_higgs_child2_pz;   //!
   TBranch        *b_higgs_child2_q;   //!
   TBranch        *b_higgs_child2_status;   //!
   TBranch        *b_higgs_child2_type;   //!
   TBranch        *b_higgs_child3;   //!
   TBranch        *b_higgs_child3_classifierParticleOrigin;   //!
   TBranch        *b_higgs_child3_classifierParticleType;   //!
   TBranch        *b_higgs_child3_mother_pdgId;   //!
   TBranch        *b_higgs_child3_mother_status;   //!
   TBranch        *b_higgs_child3_origin;   //!
   TBranch        *b_higgs_child3_p4;   //!
   TBranch        *b_higgs_child3_pdgId;   //!
   TBranch        *b_higgs_child3_pz;   //!
   TBranch        *b_higgs_child3_q;   //!
   TBranch        *b_higgs_child3_status;   //!
   TBranch        *b_higgs_child3_type;   //!
   TBranch        *b_higgs_child4;   //!
   TBranch        *b_higgs_child4_classifierParticleOrigin;   //!
   TBranch        *b_higgs_child4_classifierParticleType;   //!
   TBranch        *b_higgs_child4_mother_pdgId;   //!
   TBranch        *b_higgs_child4_mother_status;   //!
   TBranch        *b_higgs_child4_origin;   //!
   TBranch        *b_higgs_child4_p4;   //!
   TBranch        *b_higgs_child4_pdgId;   //!
   TBranch        *b_higgs_child4_pz;   //!
   TBranch        *b_higgs_child4_q;   //!
   TBranch        *b_higgs_child4_status;   //!
   TBranch        *b_higgs_child4_type;   //!
   TBranch        *b_higgs_classifierParticleOrigin;   //!
   TBranch        *b_higgs_classifierParticleType;   //!
   TBranch        *b_higgs_mother_pdgId;   //!
   TBranch        *b_higgs_mother_status;   //!
   TBranch        *b_higgs_origin;   //!
   TBranch        *b_higgs_p4;   //!
   TBranch        *b_higgs_pdgId;   //!
   TBranch        *b_higgs_pz;   //!
   TBranch        *b_higgs_q;   //!
   TBranch        *b_higgs_status;   //!
   TBranch        *b_higgs_type;   //!
   TBranch        *b_is_dijet_centrality;   //!
   TBranch        *b_jet_0_b_tagged;   //!
   TBranch        *b_jet_0_fjvt;   //!
   TBranch        *b_jet_0_flavorlabel_part;   //!
   TBranch        *b_jet_0_is_Jvt_HS;   //!
   TBranch        *b_jet_0_jvt;   //!
   TBranch        *b_jet_0_p4;   //!
   TBranch        *b_jet_0_width;   //!
   TBranch        *b_jet_0_wztruth_p4;   //!
   TBranch        *b_jet_0_wztruth_pdgid;   //!
   TBranch        *b_jet_1_b_tagged;   //!
   TBranch        *b_jet_1_fjvt;   //!
   TBranch        *b_jet_1_flavorlabel_part;   //!
   TBranch        *b_jet_1_is_Jvt_HS;   //!
   TBranch        *b_jet_1_jvt;   //!
   TBranch        *b_jet_1_p4;   //!
   TBranch        *b_jet_1_width;   //!
   TBranch        *b_jet_1_wztruth_p4;   //!
   TBranch        *b_jet_1_wztruth_pdgid;   //!
   TBranch        *b_jet_2_b_tagged;   //!
   TBranch        *b_jet_2_fjvt;   //!
   TBranch        *b_jet_2_flavorlabel_part;   //!
   TBranch        *b_jet_2_is_Jvt_HS;   //!
   TBranch        *b_jet_2_jvt;   //!
   TBranch        *b_jet_2_p4;   //!
   TBranch        *b_jet_2_width;   //!
   TBranch        *b_jet_2_wztruth_p4;   //!
   TBranch        *b_jet_2_wztruth_pdgid;   //!
   TBranch        *b_jet_3;   //!
   TBranch        *b_jet_3_b_tag_quantile;   //!
   TBranch        *b_jet_3_b_tag_score;   //!
   TBranch        *b_jet_3_b_tagged;   //!
   TBranch        *b_jet_3_cleanJet_EC_LooseBad;   //!
   TBranch        *b_jet_3_fjvt;   //!
   TBranch        *b_jet_3_flavorlabel;   //!
   TBranch        *b_jet_3_flavorlabel_cone;   //!
   TBranch        *b_jet_3_flavorlabel_part;   //!
   TBranch        *b_jet_3_is_Jvt_HS;   //!
   TBranch        *b_jet_3_jvt;   //!
   TBranch        *b_jet_3_origin;   //!
   TBranch        *b_jet_3_p4;   //!
   TBranch        *b_jet_3_q;   //!
   TBranch        *b_jet_3_type;   //!
   TBranch        *b_jet_3_width;   //!
   TBranch        *b_jet_3_wztruth_p4;   //!
   TBranch        *b_jet_3_wztruth_pdgid;   //!
   TBranch        *b_jet_4;   //!
   TBranch        *b_jet_4_b_tag_quantile;   //!
   TBranch        *b_jet_4_b_tag_score;   //!
   TBranch        *b_jet_4_b_tagged;   //!
   TBranch        *b_jet_4_cleanJet_EC_LooseBad;   //!
   TBranch        *b_jet_4_fjvt;   //!
   TBranch        *b_jet_4_flavorlabel;   //!
   TBranch        *b_jet_4_flavorlabel_cone;   //!
   TBranch        *b_jet_4_flavorlabel_part;   //!
   TBranch        *b_jet_4_is_Jvt_HS;   //!
   TBranch        *b_jet_4_jvt;   //!
   TBranch        *b_jet_4_origin;   //!
   TBranch        *b_jet_4_p4;   //!
   TBranch        *b_jet_4_q;   //!
   TBranch        *b_jet_4_type;   //!
   TBranch        *b_jet_4_width;   //!
   TBranch        *b_jet_4_wztruth_p4;   //!
   TBranch        *b_jet_4_wztruth_pdgid;   //!
   TBranch        *b_jet_5;   //!
   TBranch        *b_jet_5_b_tag_quantile;   //!
   TBranch        *b_jet_5_b_tag_score;   //!
   TBranch        *b_jet_5_b_tagged;   //!
   TBranch        *b_jet_5_cleanJet_EC_LooseBad;   //!
   TBranch        *b_jet_5_fjvt;   //!
   TBranch        *b_jet_5_flavorlabel;   //!
   TBranch        *b_jet_5_flavorlabel_cone;   //!
   TBranch        *b_jet_5_flavorlabel_part;   //!
   TBranch        *b_jet_5_is_Jvt_HS;   //!
   TBranch        *b_jet_5_jvt;   //!
   TBranch        *b_jet_5_origin;   //!
   TBranch        *b_jet_5_p4;   //!
   TBranch        *b_jet_5_q;   //!
   TBranch        *b_jet_5_type;   //!
   TBranch        *b_jet_5_width;   //!
   TBranch        *b_jet_5_wztruth_p4;   //!
   TBranch        *b_jet_5_wztruth_pdgid;   //!
   TBranch        *b_jet_6;   //!
   TBranch        *b_jet_6_b_tag_quantile;   //!
   TBranch        *b_jet_6_b_tag_score;   //!
   TBranch        *b_jet_6_b_tagged;   //!
   TBranch        *b_jet_6_cleanJet_EC_LooseBad;   //!
   TBranch        *b_jet_6_fjvt;   //!
   TBranch        *b_jet_6_flavorlabel;   //!
   TBranch        *b_jet_6_flavorlabel_cone;   //!
   TBranch        *b_jet_6_flavorlabel_part;   //!
   TBranch        *b_jet_6_is_Jvt_HS;   //!
   TBranch        *b_jet_6_jvt;   //!
   TBranch        *b_jet_6_origin;   //!
   TBranch        *b_jet_6_p4;   //!
   TBranch        *b_jet_6_q;   //!
   TBranch        *b_jet_6_type;   //!
   TBranch        *b_jet_6_width;   //!
   TBranch        *b_jet_6_wztruth_p4;   //!
   TBranch        *b_jet_6_wztruth_pdgid;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_central_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_central_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_forward_jets_global_effSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_forward_jets_global_ineffSF_JVT;   //!
   TBranch        *b_jet_NOMINAL_global_effSF_MV2c10;   //!
   TBranch        *b_jet_NOMINAL_global_ineffSF_MV2c10;   //!
   TBranch        *b_lepton_eta_centrality;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_met_hpto_p4;   //!
   TBranch        *b_met_more_met_et_ele;   //!
   TBranch        *b_met_more_met_et_jet;   //!
   TBranch        *b_met_more_met_et_muon;   //!
   TBranch        *b_met_more_met_et_pho;   //!
   TBranch        *b_met_more_met_et_soft;   //!
   TBranch        *b_met_more_met_et_tau;   //!
   TBranch        *b_met_more_met_phi_ele;   //!
   TBranch        *b_met_more_met_phi_jet;   //!
   TBranch        *b_met_more_met_phi_muon;   //!
   TBranch        *b_met_more_met_phi_pho;   //!
   TBranch        *b_met_more_met_phi_soft;   //!
   TBranch        *b_met_more_met_phi_tau;   //!
   TBranch        *b_met_more_met_sumet_ele;   //!
   TBranch        *b_met_more_met_sumet_jet;   //!
   TBranch        *b_met_more_met_sumet_muon;   //!
   TBranch        *b_met_more_met_sumet_pho;   //!
   TBranch        *b_met_more_met_sumet_soft;   //!
   TBranch        *b_met_more_met_sumet_tau;   //!
   TBranch        *b_met_p4;   //!
   TBranch        *b_met_sign_met_over_sqrt_ht;   //!
   TBranch        *b_met_sign_met_over_sqrt_sumet;   //!
   TBranch        *b_met_sign_met_rho;   //!
   TBranch        *b_met_sign_met_rho_ttdir;   //!
   TBranch        *b_met_sign_met_sig_directional;   //!
   TBranch        *b_met_sign_met_sig_directional_ttdir;   //!
   TBranch        *b_met_sign_met_significance;   //!
   TBranch        *b_met_sign_met_significance_ttdir;   //!
   TBranch        *b_met_sign_met_valL;   //!
   TBranch        *b_met_sign_met_valL_ttdir;   //!
   TBranch        *b_met_sign_met_varT;   //!
   TBranch        *b_met_sign_met_varT_ttdir;   //!
   TBranch        *b_met_sumet;   //!
   TBranch        *b_met_truth_p4;   //!
   TBranch        *b_met_truth_sumet;   //!
   TBranch        *b_mva_random_number;   //!
   TBranch        *b_n_actual_int;   //!
   TBranch        *b_n_actual_int_cor;   //!
   TBranch        *b_n_avg_int;   //!
   TBranch        *b_n_avg_int_cor;   //!
   TBranch        *b_n_bjets;   //!
   TBranch        *b_n_electrons;   //!
   TBranch        *b_n_jets;   //!
   TBranch        *b_n_jets_30;   //!
   TBranch        *b_n_jets_40;   //!
   TBranch        *b_n_jets_central;   //!
   TBranch        *b_n_jets_central_30;   //!
   TBranch        *b_n_jets_central_40;   //!
   TBranch        *b_n_jets_forward;   //!
   TBranch        *b_n_jets_forward_30;   //!
   TBranch        *b_n_jets_forward_40;   //!
   TBranch        *b_n_jets_l1j25;   //!
   TBranch        *b_n_jets_mc_hs;   //!
   TBranch        *b_n_muons;   //!
   TBranch        *b_n_photons;   //!
   TBranch        *b_n_pvx;   //!
   TBranch        *b_n_taus;   //!
   TBranch        *b_n_taus_loose;   //!
   TBranch        *b_n_taus_medium;   //!
   TBranch        *b_n_taus_tight;   //!
   TBranch        *b_n_taus_veryloose;   //!
   TBranch        *b_n_truth_gluon_jets;   //!
   TBranch        *b_n_truth_jets;   //!
   TBranch        *b_n_truth_jets_pt20_eta45;   //!
   TBranch        *b_n_truth_quark_jets;   //!
   TBranch        *b_n_vx;   //!
   TBranch        *b_primary_vertex;   //!
   TBranch        *b_primary_vertex_v;   //!
   TBranch        *b_pt_total;   //!
   TBranch        *b_run_number;   //!
   TBranch        *b_scalar_sum_pt;   //!
   TBranch        *b_tau_0;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_reco;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_0_allTrk_eta;   //!
   TBranch        *b_tau_0_allTrk_n;   //!
   TBranch        *b_tau_0_allTrk_phi;   //!
   TBranch        *b_tau_0_allTrk_pt;   //!
   TBranch        *b_tau_0_b_tagged;   //!
   TBranch        *b_tau_0_decay_mode;   //!
   TBranch        *b_tau_0_ele_bdt_eff_sf;   //!
   TBranch        *b_tau_0_ele_bdt_loose_retuned;   //!
   TBranch        *b_tau_0_ele_bdt_medium_retuned;   //!
   TBranch        *b_tau_0_ele_bdt_score;   //!
   TBranch        *b_tau_0_ele_bdt_score_retuned;   //!
   TBranch        *b_tau_0_ele_bdt_score_trans;   //!
   TBranch        *b_tau_0_ele_bdt_score_trans_retuned;   //!
   TBranch        *b_tau_0_ele_bdt_tight_retuned;   //!
   TBranch        *b_tau_0_ele_match_lhscore;   //!
   TBranch        *b_tau_0_ele_olr_pass;   //!
   TBranch        *b_tau_0_jet_bdt_loose;   //!
   TBranch        *b_tau_0_jet_bdt_medium;   //!
   TBranch        *b_tau_0_jet_bdt_score_trans;   //!
   TBranch        *b_tau_0_jet_bdt_tight;   //!
   TBranch        *b_tau_0_jet_bdt_veryloose;   //!
   TBranch        *b_tau_0_jet_jvt;   //!
   TBranch        *b_tau_0_jet_rnn_loose;   //!
   TBranch        *b_tau_0_jet_rnn_medium;   //!
   TBranch        *b_tau_0_jet_rnn_score;   //!
   TBranch        *b_tau_0_jet_rnn_score_trans;   //!
   TBranch        *b_tau_0_jet_rnn_tight;   //!
   TBranch        *b_tau_0_jet_rnn_veryloose;   //!
   TBranch        *b_tau_0_jet_width;   //!
   TBranch        *b_tau_0_leadTrk_eta;   //!
   TBranch        *b_tau_0_leadTrk_phi;   //!
   TBranch        *b_tau_0_leadTrk_pt;   //!
   TBranch        *b_tau_0_matched;   //!
   TBranch        *b_tau_0_matched_classifierParticleOrigin;   //!
   TBranch        *b_tau_0_matched_classifierParticleType;   //!
   TBranch        *b_tau_0_matched_decay_charged_p4;   //!
   TBranch        *b_tau_0_matched_decay_mode;   //!
   TBranch        *b_tau_0_matched_decay_neutral_p4;   //!
   TBranch        *b_tau_0_matched_decay_neutrino_p4;   //!
   TBranch        *b_tau_0_matched_isEle;   //!
   TBranch        *b_tau_0_matched_isHadTau;   //!
   TBranch        *b_tau_0_matched_isJet;   //!
   TBranch        *b_tau_0_matched_isMuon;   //!
   TBranch        *b_tau_0_matched_isTau;   //!
   TBranch        *b_tau_0_matched_isTruthMatch;   //!
   TBranch        *b_tau_0_matched_mother_pdgId;   //!
   TBranch        *b_tau_0_matched_mother_status;   //!
   TBranch        *b_tau_0_matched_n_charged;   //!
   TBranch        *b_tau_0_matched_n_charged_pion;   //!
   TBranch        *b_tau_0_matched_n_neutral;   //!
   TBranch        *b_tau_0_matched_n_neutral_pion;   //!
   TBranch        *b_tau_0_matched_p4;   //!
   TBranch        *b_tau_0_matched_p4_vis_charged_track0;   //!
   TBranch        *b_tau_0_matched_p4_vis_charged_track1;   //!
   TBranch        *b_tau_0_matched_p4_vis_charged_track2;   //!
   TBranch        *b_tau_0_matched_pdgId;   //!
   TBranch        *b_tau_0_matched_q;   //!
   TBranch        *b_tau_0_matched_status;   //!
   TBranch        *b_tau_0_matched_type;   //!
   TBranch        *b_tau_0_matched_vis_charged_p4;   //!
   TBranch        *b_tau_0_matched_vis_neutral_others_p4;   //!
   TBranch        *b_tau_0_matched_vis_neutral_p4;   //!
   TBranch        *b_tau_0_matched_vis_neutral_pions_p4;   //!
   TBranch        *b_tau_0_matched_vis_p4;   //!
   TBranch        *b_tau_0_n_all_tracks;   //!
   TBranch        *b_tau_0_n_charged_tracks;   //!
   TBranch        *b_tau_0_n_conversion_tracks;   //!
   TBranch        *b_tau_0_n_core_tracks;   //!
   TBranch        *b_tau_0_n_failTrackFilter_tracks;   //!
   TBranch        *b_tau_0_n_fake_tracks;   //!
   TBranch        *b_tau_0_n_isolation_tracks;   //!
   TBranch        *b_tau_0_n_modified_isolation_tracks;   //!
   TBranch        *b_tau_0_n_old_tracks;   //!
   TBranch        *b_tau_0_n_passTrkSelectionTight_tracks;   //!
   TBranch        *b_tau_0_n_passTrkSelector_tracks;   //!
   TBranch        *b_tau_0_n_unclassified_tracks;   //!
   TBranch        *b_tau_0_n_wide_tracks;   //!
   TBranch        *b_tau_0_origin;   //!
   TBranch        *b_tau_0_p4;   //!
   TBranch        *b_tau_0_q;   //!
   TBranch        *b_tau_0_track0_p4;   //!
   TBranch        *b_tau_0_track1_p4;   //!
   TBranch        *b_tau_0_track2_p4;   //!
   TBranch        *b_tau_0_trig_HLT_tau25_medium1_tracktwo;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;   //!
   TBranch        *b_tau_0_trig_trigger_matched;   //!
   TBranch        *b_tau_0_type;   //!
   TBranch        *b_tau_1;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_reco;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1down_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16A_1up_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1down_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STATMC16D_1up_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDTPlusVeto_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_MediumEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;   //!
   TBranch        *b_tau_1_allTrk_eta;   //!
   TBranch        *b_tau_1_allTrk_n;   //!
   TBranch        *b_tau_1_allTrk_phi;   //!
   TBranch        *b_tau_1_allTrk_pt;   //!
   TBranch        *b_tau_1_b_tagged;   //!
   TBranch        *b_tau_1_decay_mode;   //!
   TBranch        *b_tau_1_ele_bdt_eff_sf;   //!
   TBranch        *b_tau_1_ele_bdt_loose_retuned;   //!
   TBranch        *b_tau_1_ele_bdt_medium_retuned;   //!
   TBranch        *b_tau_1_ele_bdt_score;   //!
   TBranch        *b_tau_1_ele_bdt_score_retuned;   //!
   TBranch        *b_tau_1_ele_bdt_score_trans;   //!
   TBranch        *b_tau_1_ele_bdt_score_trans_retuned;   //!
   TBranch        *b_tau_1_ele_bdt_tight_retuned;   //!
   TBranch        *b_tau_1_ele_match_lhscore;   //!
   TBranch        *b_tau_1_ele_olr_pass;   //!
   TBranch        *b_tau_1_jet_bdt_loose;   //!
   TBranch        *b_tau_1_jet_bdt_medium;   //!
   TBranch        *b_tau_1_jet_bdt_score_trans;   //!
   TBranch        *b_tau_1_jet_bdt_tight;   //!
   TBranch        *b_tau_1_jet_bdt_veryloose;   //!
   TBranch        *b_tau_1_jet_jvt;   //!
   TBranch        *b_tau_1_jet_rnn_loose;   //!
   TBranch        *b_tau_1_jet_rnn_medium;   //!
   TBranch        *b_tau_1_jet_rnn_score;   //!
   TBranch        *b_tau_1_jet_rnn_score_trans;   //!
   TBranch        *b_tau_1_jet_rnn_tight;   //!
   TBranch        *b_tau_1_jet_rnn_veryloose;   //!
   TBranch        *b_tau_1_jet_width;   //!
   TBranch        *b_tau_1_leadTrk_eta;   //!
   TBranch        *b_tau_1_leadTrk_phi;   //!
   TBranch        *b_tau_1_leadTrk_pt;   //!
   TBranch        *b_tau_1_matched;   //!
   TBranch        *b_tau_1_matched_classifierParticleOrigin;   //!
   TBranch        *b_tau_1_matched_classifierParticleType;   //!
   TBranch        *b_tau_1_matched_decay_charged_p4;   //!
   TBranch        *b_tau_1_matched_decay_mode;   //!
   TBranch        *b_tau_1_matched_decay_neutral_p4;   //!
   TBranch        *b_tau_1_matched_decay_neutrino_p4;   //!
   TBranch        *b_tau_1_matched_isEle;   //!
   TBranch        *b_tau_1_matched_isHadTau;   //!
   TBranch        *b_tau_1_matched_isJet;   //!
   TBranch        *b_tau_1_matched_isMuon;   //!
   TBranch        *b_tau_1_matched_isTau;   //!
   TBranch        *b_tau_1_matched_isTruthMatch;   //!
   TBranch        *b_tau_1_matched_mother_pdgId;   //!
   TBranch        *b_tau_1_matched_mother_status;   //!
   TBranch        *b_tau_1_matched_n_charged;   //!
   TBranch        *b_tau_1_matched_n_charged_pion;   //!
   TBranch        *b_tau_1_matched_n_neutral;   //!
   TBranch        *b_tau_1_matched_n_neutral_pion;   //!
   TBranch        *b_tau_1_matched_p4;   //!
   TBranch        *b_tau_1_matched_p4_vis_charged_track0;   //!
   TBranch        *b_tau_1_matched_p4_vis_charged_track1;   //!
   TBranch        *b_tau_1_matched_p4_vis_charged_track2;   //!
   TBranch        *b_tau_1_matched_pdgId;   //!
   TBranch        *b_tau_1_matched_pz;   //!
   TBranch        *b_tau_1_matched_q;   //!
   TBranch        *b_tau_1_matched_status;   //!
   TBranch        *b_tau_1_matched_vis_charged_p4;   //!
   TBranch        *b_tau_1_matched_vis_neutral_others_p4;   //!
   TBranch        *b_tau_1_matched_vis_neutral_p4;   //!
   TBranch        *b_tau_1_matched_vis_neutral_pions_p4;   //!
   TBranch        *b_tau_1_matched_vis_p4;   //!
   TBranch        *b_tau_1_n_all_tracks;   //!
   TBranch        *b_tau_1_n_charged_tracks;   //!
   TBranch        *b_tau_1_n_conversion_tracks;   //!
   TBranch        *b_tau_1_n_core_tracks;   //!
   TBranch        *b_tau_1_n_failTrackFilter_tracks;   //!
   TBranch        *b_tau_1_n_fake_tracks;   //!
   TBranch        *b_tau_1_n_isolation_tracks;   //!
   TBranch        *b_tau_1_n_modified_isolation_tracks;   //!
   TBranch        *b_tau_1_n_old_tracks;   //!
   TBranch        *b_tau_1_n_passTrkSelectionTight_tracks;   //!
   TBranch        *b_tau_1_n_passTrkSelector_tracks;   //!
   TBranch        *b_tau_1_n_unclassified_tracks;   //!
   TBranch        *b_tau_1_n_wide_tracks;   //!
   TBranch        *b_tau_1_origin;   //!
   TBranch        *b_tau_1_p4;   //!
   TBranch        *b_tau_1_q;   //!
   TBranch        *b_tau_1_track0_p4;   //!
   TBranch        *b_tau_1_track1_p4;   //!
   TBranch        *b_tau_1_track2_p4;   //!
   TBranch        *b_tau_1_trig_HLT_tau25_medium1_tracktwo;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;   //!
   TBranch        *b_tau_1_trig_trigger_matched;   //!
   TBranch        *b_tau_1_type;   //!
   TBranch        *b_tau_eta_centrality;   //!
   TBranch        *b_tb;   //!
   TBranch        *b_tb_childq;   //!
   TBranch        *b_tb_childq_classifierParticleOrigin;   //!
   TBranch        *b_tb_childq_classifierParticleType;   //!
   TBranch        *b_tb_childq_mother_pdgId;   //!
   TBranch        *b_tb_childq_mother_status;   //!
   TBranch        *b_tb_childq_origin;   //!
   TBranch        *b_tb_childq_p4;   //!
   TBranch        *b_tb_childq_pdgId;   //!
   TBranch        *b_tb_childq_pz;   //!
   TBranch        *b_tb_childq_q;   //!
   TBranch        *b_tb_childq_status;   //!
   TBranch        *b_tb_childq_type;   //!
   TBranch        *b_tb_classifierParticleOrigin;   //!
   TBranch        *b_tb_classifierParticleType;   //!
   TBranch        *b_tb_mother_pdgId;   //!
   TBranch        *b_tb_mother_status;   //!
   TBranch        *b_tb_origin;   //!
   TBranch        *b_tb_p4;   //!
   TBranch        *b_tb_pdgId;   //!
   TBranch        *b_tb_pz;   //!
   TBranch        *b_tb_q;   //!
   TBranch        *b_tb_status;   //!
   TBranch        *b_tb_type;   //!
   TBranch        *b_top;   //!
   TBranch        *b_top_childq;   //!
   TBranch        *b_top_childq_classifierParticleOrigin;   //!
   TBranch        *b_top_childq_classifierParticleType;   //!
   TBranch        *b_top_childq_mother_pdgId;   //!
   TBranch        *b_top_childq_mother_status;   //!
   TBranch        *b_top_childq_origin;   //!
   TBranch        *b_top_childq_p4;   //!
   TBranch        *b_top_childq_pdgId;   //!
   TBranch        *b_top_childq_pz;   //!
   TBranch        *b_top_childq_q;   //!
   TBranch        *b_top_childq_status;   //!
   TBranch        *b_top_childq_type;   //!
   TBranch        *b_top_classifierParticleOrigin;   //!
   TBranch        *b_top_classifierParticleType;   //!
   TBranch        *b_top_mother_pdgId;   //!
   TBranch        *b_top_mother_status;   //!
   TBranch        *b_top_origin;   //!
   TBranch        *b_top_p4;   //!
   TBranch        *b_top_pdgId;   //!
   TBranch        *b_top_pz;   //!
   TBranch        *b_top_q;   //!
   TBranch        *b_top_status;   //!
   TBranch        *b_top_type;   //!
   TBranch        *b_truth_passedVBFFilter;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_wm_childq1;   //!
   TBranch        *b_wm_childq1_classifierParticleOrigin;   //!
   TBranch        *b_wm_childq1_classifierParticleType;   //!
   TBranch        *b_wm_childq1_mother_pdgId;   //!
   TBranch        *b_wm_childq1_mother_status;   //!
   TBranch        *b_wm_childq1_origin;   //!
   TBranch        *b_wm_childq1_p4;   //!
   TBranch        *b_wm_childq1_pdgId;   //!
   TBranch        *b_wm_childq1_pz;   //!
   TBranch        *b_wm_childq1_q;   //!
   TBranch        *b_wm_childq1_status;   //!
   TBranch        *b_wm_childq1_type;   //!
   TBranch        *b_wm_childq2;   //!
   TBranch        *b_wm_childq2_classifierParticleOrigin;   //!
   TBranch        *b_wm_childq2_classifierParticleType;   //!
   TBranch        *b_wm_childq2_mother_pdgId;   //!
   TBranch        *b_wm_childq2_mother_status;   //!
   TBranch        *b_wm_childq2_origin;   //!
   TBranch        *b_wm_childq2_p4;   //!
   TBranch        *b_wm_childq2_pdgId;   //!
   TBranch        *b_wm_childq2_pz;   //!
   TBranch        *b_wm_childq2_q;   //!
   TBranch        *b_wm_childq2_status;   //!
   TBranch        *b_wm_childq2_type;   //!
   TBranch        *b_wp_childq1;   //!
   TBranch        *b_wp_childq1_classifierParticleOrigin;   //!
   TBranch        *b_wp_childq1_classifierParticleType;   //!
   TBranch        *b_wp_childq1_mother_pdgId;   //!
   TBranch        *b_wp_childq1_mother_status;   //!
   TBranch        *b_wp_childq1_origin;   //!
   TBranch        *b_wp_childq1_p4;   //!
   TBranch        *b_wp_childq1_pdgId;   //!
   TBranch        *b_wp_childq1_pz;   //!
   TBranch        *b_wp_childq1_q;   //!
   TBranch        *b_wp_childq1_status;   //!
   TBranch        *b_wp_childq1_type;   //!
   TBranch        *b_wp_childq2;   //!
   TBranch        *b_wp_childq2_classifierParticleOrigin;   //!
   TBranch        *b_wp_childq2_classifierParticleType;   //!
   TBranch        *b_wp_childq2_mother_pdgId;   //!
   TBranch        *b_wp_childq2_mother_status;   //!
   TBranch        *b_wp_childq2_origin;   //!
   TBranch        *b_wp_childq2_p4;   //!
   TBranch        *b_wp_childq2_pdgId;   //!
   TBranch        *b_wp_childq2_pz;   //!
   TBranch        *b_wp_childq2_q;   //!
   TBranch        *b_wp_childq2_status;   //!
   TBranch        *b_wp_childq2_type;   //!
   TBranch        *b_theory_weights_LHE3Weight_muR_05_muF_05;
   TBranch        *b_theory_weights_LHE3Weight_muR_05_muF_10;
   TBranch        *b_theory_weights_LHE3Weight_muR_05_muF_20;
   TBranch        *b_theory_weights_LHE3Weight_muR_10_muF_05;
   TBranch        *b_theory_weights_LHE3Weight_muR_10_muF_20;
   TBranch        *b_theory_weights_LHE3Weight_muR_20_muF_05;
   TBranch        *b_theory_weights_LHE3Weight_muR_20_muF_10;
   TBranch        *b_theory_weights_LHE3Weight_muR_20_muF_20;

};
#endif // #ifdef hadhadtree_cxx
