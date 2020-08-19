#ifndef hadhadtree_h
#define hadhadtree_h
#include "nominal.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"
#include "TVector3.h"

// Fixed size dimensions of array or collections stored in the TTree if any.

class hadhadtree : public nominal{
public :
   // Declaration of leaf types
   hadhadtree();
   void defineObjects();
   void definetaus();
   void definejets();
   void init_hist(TString histfilename);
   void     initRaw(TTree *tree);
   void init_sample(TString sample, TString sampletitle);
   void fill_fcnc(TString region, int nprong, TString sample, bool taubtag, TString NPname);
   void definetree(TTree *tree);
   bool addWeightSys();
   bool passRegionCut();
   bool passBasicCut();
   void calcGeneralWeight();
   float calcRegionSF(TString region);
   int tauabspdg = 0;
   void  prepare();

  bool MassCollinearCore(const TLorentzVector &k1, const TLorentzVector &k2,  // particles
                               const double metetx, const double metety,            // met
                               double &mass, double &xp1, double &xp2);
  bool MassCollinear(const std::vector<TLorentzVector*>  *taus_p4,
                           const TLorentzVector *met,
                           UInt_t tau_0_allTrk_n,UInt_t tau_1_allTrk_n,             // met
                           const bool kMMCsynchronize,                // mmc sychronization
                           double &mass, double &xp1, double &xp2);
   bool x0_x1_cut(const std::vector<TLorentzVector*>  *taus_p4,
   const TLorentzVector *met,
   UInt_t tau_0_allTrk_n,UInt_t tau_1_allTrk_n,double& x0,double& x1);
   
   bool passtrigger=1;
   TString mode="";

   //std::vector<Int_t>           *taus_id = 0;
   std::vector<UInt_t>          *taus_decay_mode = 0;
// std::vector<Int_t>           *taus_matched_mother_pdgId = 0;
   std::vector<Int_t>           *taus_matched_mother_status = 0;
 //std::vector<Int_t>           *taus_matched_pdgId = 0;
 //std::vector<UInt_t>          *taus_n_charged_tracks = 0;
   std::vector<Float_t>         *bjets_fjvt = 0;
   std::vector<Int_t>           *bjets_is_Jvt_HS = 0;
   std::vector<Float_t>         *bjets_jvt = 0;
   std::vector<Int_t>           *bjets_origin = 0;
   std::vector<Float_t>         *bjets_q = 0;
   std::vector<Int_t>           *bjets_type = 0;
   std::vector<Float_t>         *bjets_width = 0;
   std::vector<Float_t>         *bjets_wztruth_pdgid = 0;
   std::vector<Float_t>         *ljets_fjvt = 0;
   std::vector<Int_t>           *ljets_is_Jvt_HS = 0;
   std::vector<Float_t>         *ljets_jvt = 0;
   std::vector<Int_t>           *ljets_origin = 0;
   std::vector<Float_t>         *ljets_q = 0;
   std::vector<Int_t>           *ljets_type = 0;
   std::vector<Float_t>         *ljets_width = 0;
   std::vector<Float_t>         *ljets_wztruth_pdgid = 0;
   std::vector<TLorentzVector*>  *taus_matched_p4;
   std::vector<TLorentzVector*>  *taus_matched_vis_p4;
   std::vector<TLorentzVector*>  *bjets_wztruth_p4;
   std::vector<TLorentzVector*>  *jets_wztruth_p4;

   int tau_origin=0;
   double weight_mc_d;
   Double_t        AMI_cross_section;
   ULong64_t       event_number;
   Float_t         HTXS_Higgs_eta;
   Float_t         HTXS_Higgs_pt;
   Int_t           HTXS_Njets_pTjet25;
   Int_t           HTXS_Njets_pTjet30;
   Int_t           HTXS_Stage0_Category;
   Int_t           HTXS_Stage1_2_Category_pTjet25GeV;
   Int_t           HTXS_Stage1_2_Category_pTjet30GeV;
   Int_t           HTXS_Stage1_2_Fine_Category_pTjet25GeV;
   Int_t           HTXS_Stage1_2_Fine_Category_pTjet30GeV;
   Int_t           HTXS_Stage1_Category_pTjet25GeV;
   Int_t           HTXS_Stage1_Category_pTjet30GeV;
   Int_t           HTXS_errorMode;
   Int_t           HTXS_prodMode;
   Float_t         HTjets;
   Float_t         NOMINAL_pileup_combined_weight;
   UInt_t          NOMINAL_pileup_random_lb_number;
   UInt_t          NOMINAL_pileup_random_run_number;
   Float_t         PRW_DATASF_1down_pileup_combined_weight;
   Float_t         PRW_DATASF_1up_pileup_combined_weight;
   Float_t         SumPtBjet;
   TLorentzVector  *boson_0_truth_p4;
   Int_t           boson_0_truth_pdgId;
   Float_t         boson_0_truth_q;
   Int_t           boson_0_truth_status;
   Int_t           channel_index;
   Double_t        cross_section;
   TLorentzVector  *dijet_p4;
   Float_t         ditau_CP_alphaminus_ip;
   Float_t         ditau_CP_alphaminus_ip_rho;
   Float_t         ditau_CP_alphaminus_rho_rho;
   Float_t         ditau_CP_ip_tau0_mag;
   Float_t         ditau_CP_ip_tau0_x_ip;
   Float_t         ditau_CP_ip_tau0_y_ip;
   Float_t         ditau_CP_ip_tau0_z_ip;
   Float_t         ditau_CP_ip_tau1_mag;
   Float_t         ditau_CP_ip_tau1_x_ip;
   Float_t         ditau_CP_ip_tau1_y_ip;
   Float_t         ditau_CP_ip_tau1_z_ip;
   Float_t         ditau_CP_phi_star_cp_a1_rho;
   Float_t         ditau_CP_phi_star_cp_ip_ip;
   Float_t         ditau_CP_phi_star_cp_ip_rho;
   Float_t         ditau_CP_phi_star_cp_ip_rho_opt;
   Float_t         ditau_CP_phi_star_cp_rho_ip;
   Float_t         ditau_CP_phi_star_cp_rho_rho;
   Float_t         ditau_CP_tau0_upsilon;
   Float_t         ditau_CP_tau1_upsilon;
   Float_t         ditau_CP_upsilon_a1;
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
   Float_t         ditau_matched_CP_alphaminus_ip;
   Float_t         ditau_matched_CP_alphaminus_ip_rho;
   Float_t         ditau_matched_CP_alphaminus_rho_rho;
   Float_t         ditau_matched_CP_ip_tau0_mag;
   Float_t         ditau_matched_CP_ip_tau0_x_ip;
   Float_t         ditau_matched_CP_ip_tau0_y_ip;
   Float_t         ditau_matched_CP_ip_tau0_z_ip;
   Float_t         ditau_matched_CP_ip_tau1_mag;
   Float_t         ditau_matched_CP_ip_tau1_x_ip;
   Float_t         ditau_matched_CP_ip_tau1_y_ip;
   Float_t         ditau_matched_CP_ip_tau1_z_ip;
   Float_t         ditau_matched_CP_phi_star_cp_a1_rho;
   Float_t         ditau_matched_CP_phi_star_cp_ip_ip;
   Float_t         ditau_matched_CP_phi_star_cp_ip_rho;
   Float_t         ditau_matched_CP_phi_star_cp_ip_rho_opt;
   Float_t         ditau_matched_CP_phi_star_cp_rho_ip;
   Float_t         ditau_matched_CP_phi_star_cp_rho_rho;
   Float_t         ditau_matched_CP_tau0_upsilon;
   Float_t         ditau_matched_CP_tau1_upsilon;
   Float_t         ditau_matched_CP_upsilon_a1;
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
   Float_t         ditau_mmc_maxw_phi;
   Float_t         ditau_mmc_maxw_pt;
   Int_t           ditau_mmc_mlm_fit_status;
   Float_t         ditau_mmc_mlm_m;
   Float_t         ditau_mt_lep0_met;
   Float_t         ditau_mt_lep1_met;
   TLorentzVector  *ditau_p4;
   Float_t         ditau_qxq;
   Float_t         ditau_scal_sum_pt;
   UInt_t          event_clean_EC_TightBad;
   Int_t           event_is_bad_batman;
   Double_t        filter_efficiency;
   UInt_t          is_dijet_centrality;
   Float_t         jet_0_b_tag_score;
   Int_t           jet_0_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_0_b_tagged_DL1r_FixedCutBEff_85;
   Float_t         jet_0_fjvt;
   Int_t           jet_0_flavorlabel_part;
   Int_t           jet_0_is_Jvt_HS;
   Float_t         jet_0_jvt;
   TLorentzVector  *jet_0_p4;
   Float_t         jet_0_width;
   TLorentzVector  *jet_0_wztruth_p4;
   Float_t         jet_0_wztruth_pdgid;
   Float_t         jet_1_b_tag_score;
   Int_t           jet_1_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_1_b_tagged_DL1r_FixedCutBEff_85;
   Float_t         jet_1_fjvt;
   Int_t           jet_1_flavorlabel_part;
   Int_t           jet_1_is_Jvt_HS;
   Float_t         jet_1_jvt;
   TLorentzVector  *jet_1_p4;
   Float_t         jet_1_width;
   TLorentzVector  *jet_1_wztruth_p4;
   Float_t         jet_1_wztruth_pdgid;
   Float_t         jet_2_b_tag_score;
   Int_t           jet_2_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_2_b_tagged_DL1r_FixedCutBEff_85;
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
   Int_t           jet_3_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_3_b_tagged_DL1r_FixedCutBEff_85;
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
   Int_t           jet_4_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_4_b_tagged_DL1r_FixedCutBEff_85;
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
   Int_t           jet_5_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_5_b_tagged_DL1r_FixedCutBEff_85;
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
   Int_t           jet_6_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_6_b_tagged_DL1r_FixedCutBEff_85;
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
   UInt_t          jet_7;
   Int_t           jet_7_b_tag_quantile;
   Float_t         jet_7_b_tag_score;
   Int_t           jet_7_b_tagged_DL1r_FixedCutBEff_70;
   Int_t           jet_7_b_tagged_DL1r_FixedCutBEff_85;
   UInt_t          jet_7_cleanJet_EC_LooseBad;
   Float_t         jet_7_fjvt;
   Int_t           jet_7_flavorlabel;
   Int_t           jet_7_flavorlabel_cone;
   Int_t           jet_7_flavorlabel_part;
   Int_t           jet_7_is_Jvt_HS;
   Float_t         jet_7_jvt;
   Int_t           jet_7_origin;
   TLorentzVector  *jet_7_p4;
   Float_t         jet_7_q;
   Int_t           jet_7_type;
   Float_t         jet_7_width;
   TLorentzVector  *jet_7_wztruth_p4;
   Float_t         jet_7_wztruth_pdgid;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_4_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_4_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_4_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_4_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_1up_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_DL1r_FixedCutBEff_85;
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
   Float_t         jet_NOMINAL_global_effSF_DL1r_FixedCutBEff_70;
   Float_t         jet_NOMINAL_global_effSF_DL1r_FixedCutBEff_85;
   Float_t         jet_NOMINAL_global_ineffSF_DL1r_FixedCutBEff_70;
   Float_t         jet_NOMINAL_global_ineffSF_DL1r_FixedCutBEff_85;
   Float_t         jjdrmin;
   Double_t        kfactor;
   Float_t         lepton_eta_centrality;
   Float_t         mTopWbest;
   Float_t         mWbest;
   Float_t         mWsubbest;
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
   //TLorentzVector  *met_p4;
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
   Int_t           n_bjets_DL1r_FixedCutBEff_70;
   Int_t           n_bjets_DL1r_FixedCutBEff_85;
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
   Int_t           n_taus_rnn_loose;
   Int_t           n_taus_rnn_medium;
   Int_t           n_taus_rnn_tight;
   Int_t           n_taus_rnn_veryloose;
   UInt_t          n_truth_gluon_jets;
   UInt_t          n_truth_jets;
   UInt_t          n_truth_jets_pt20_eta45;
   UInt_t          n_truth_quark_jets;
   Int_t           n_vx;
   Float_t         pmg_truth_weight_FSRHi;
   Float_t         pmg_truth_weight_FSRLo;
   Float_t         pmg_truth_weight_ISRLo;
   Float_t         pmg_truth_weight_pdf_signal_weight_0;
   Float_t         pmg_truth_weight_pdf_signal_weight_1;
   Float_t         pmg_truth_weight_pdf_signal_weight_10;
   Float_t         pmg_truth_weight_pdf_signal_weight_11;
   Float_t         pmg_truth_weight_pdf_signal_weight_12;
   Float_t         pmg_truth_weight_pdf_signal_weight_13;
   Float_t         pmg_truth_weight_pdf_signal_weight_14;
   Float_t         pmg_truth_weight_pdf_signal_weight_15;
   Float_t         pmg_truth_weight_pdf_signal_weight_16;
   Float_t         pmg_truth_weight_pdf_signal_weight_17;
   Float_t         pmg_truth_weight_pdf_signal_weight_18;
   Float_t         pmg_truth_weight_pdf_signal_weight_19;
   Float_t         pmg_truth_weight_pdf_signal_weight_2;
   Float_t         pmg_truth_weight_pdf_signal_weight_20;
   Float_t         pmg_truth_weight_pdf_signal_weight_21;
   Float_t         pmg_truth_weight_pdf_signal_weight_22;
   Float_t         pmg_truth_weight_pdf_signal_weight_23;
   Float_t         pmg_truth_weight_pdf_signal_weight_24;
   Float_t         pmg_truth_weight_pdf_signal_weight_25;
   Float_t         pmg_truth_weight_pdf_signal_weight_26;
   Float_t         pmg_truth_weight_pdf_signal_weight_27;
   Float_t         pmg_truth_weight_pdf_signal_weight_28;
   Float_t         pmg_truth_weight_pdf_signal_weight_29;
   Float_t         pmg_truth_weight_pdf_signal_weight_3;
   Float_t         pmg_truth_weight_pdf_signal_weight_30;
   Float_t         pmg_truth_weight_pdf_signal_weight_4;
   Float_t         pmg_truth_weight_pdf_signal_weight_5;
   Float_t         pmg_truth_weight_pdf_signal_weight_6;
   Float_t         pmg_truth_weight_pdf_signal_weight_7;
   Float_t         pmg_truth_weight_pdf_signal_weight_8;
   Float_t         pmg_truth_weight_pdf_signal_weight_9;
   Int_t           primary_vertex;
   TVector3        *primary_vertex_v;
   Float_t         pt_total;
   UInt_t          run_number;
   Float_t         scalar_sum_pt;
   UInt_t          tau_0;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_0_NOMINAL_TauEffSF_JetRNNloose;
   Float_t         tau_0_NOMINAL_TauEffSF_JetRNNmedium;
   Float_t         tau_0_NOMINAL_TauEffSF_JetRNNtight;
   Float_t         tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_NOMINAL_TauEffSF_reco;
   Float_t         tau_0_NOMINAL_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNloose;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNtight;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_0_allTrk_eta;
   UInt_t          tau_0_allTrk_n;
   Float_t         tau_0_allTrk_phi;
   Float_t         tau_0_allTrk_pt;
   Int_t           tau_0_b_tagged;
   TLorentzVector  *tau_0_decay_charged_p4;
   UInt_t          tau_0_decay_mode;
   TLorentzVector  *tau_0_decay_neutral_p4;
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
   Float_t         tau_0_jet_jvt;
   UInt_t          tau_0_jet_rnn_loose;
   UInt_t          tau_0_jet_rnn_medium;
   Float_t         tau_0_jet_rnn_score;
   Float_t         tau_0_jet_rnn_score_trans;
   UInt_t          tau_0_jet_rnn_tight;
   UInt_t          tau_0_jet_rnn_veryloose;
   Float_t         tau_0_jet_width;
   Float_t         tau_0_jetseed_TrackWidthPt1000_wrt_PV;
   Float_t         tau_0_jetseed_TrackWidthPt1000_wrt_TV;
   TLorentzVector  *tau_0_jetseed_p4;
   Double_t        tau_0_leadTrk_d0;
   Double_t        tau_0_leadTrk_d0_sig;
   Float_t         tau_0_leadTrk_eta;
   Float_t         tau_0_leadTrk_phi;
   Float_t         tau_0_leadTrk_pt;
   Double_t        tau_0_leadTrk_pvx_z0;
   Double_t        tau_0_leadTrk_pvx_z0_sig;
   Double_t        tau_0_leadTrk_pvx_z0_sintheta;
   TVector3        *tau_0_leadTrk_vertex_v;
   Double_t        tau_0_leadTrk_z0;
   Double_t        tau_0_leadTrk_z0_sig;
   Double_t        tau_0_leadTrk_z0_sintheta;
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
   UInt_t          tau_0_trig_HLT_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;
   UInt_t          tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_0_trig_trigger_matched;
   Int_t           tau_0_type;
   UInt_t          tau_1;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_1_NOMINAL_TauEffSF_JetRNNloose;
   Float_t         tau_1_NOMINAL_TauEffSF_JetRNNmedium;
   Float_t         tau_1_NOMINAL_TauEffSF_JetRNNtight;
   Float_t         tau_1_NOMINAL_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_NOMINAL_TauEffSF_reco;
   Float_t         tau_1_NOMINAL_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNloose;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNtight;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;
   Float_t         tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;
   Float_t         tau_1_allTrk_eta;
   UInt_t          tau_1_allTrk_n;
   Float_t         tau_1_allTrk_phi;
   Float_t         tau_1_allTrk_pt;
   Int_t           tau_1_b_tagged;
   TLorentzVector  *tau_1_decay_charged_p4;
   UInt_t          tau_1_decay_mode;
   TLorentzVector  *tau_1_decay_neutral_p4;
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
   Float_t         tau_1_jet_jvt;
   UInt_t          tau_1_jet_rnn_loose;
   UInt_t          tau_1_jet_rnn_medium;
   Float_t         tau_1_jet_rnn_score;
   Float_t         tau_1_jet_rnn_score_trans;
   UInt_t          tau_1_jet_rnn_tight;
   UInt_t          tau_1_jet_rnn_veryloose;
   Float_t         tau_1_jet_width;
   Float_t         tau_1_jetseed_TrackWidthPt1000_wrt_PV;
   Float_t         tau_1_jetseed_TrackWidthPt1000_wrt_TV;
   TLorentzVector  *tau_1_jetseed_p4;
   Double_t        tau_1_leadTrk_d0;
   Double_t        tau_1_leadTrk_d0_sig;
   Float_t         tau_1_leadTrk_eta;
   Float_t         tau_1_leadTrk_phi;
   Float_t         tau_1_leadTrk_pt;
   Double_t        tau_1_leadTrk_pvx_z0;
   Double_t        tau_1_leadTrk_pvx_z0_sig;
   Double_t        tau_1_leadTrk_pvx_z0_sintheta;
   TVector3        *tau_1_leadTrk_vertex_v;
   Double_t        tau_1_leadTrk_z0;
   Double_t        tau_1_leadTrk_z0_sig;
   Double_t        tau_1_leadTrk_z0_sintheta;
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
   UInt_t          tau_1_trig_HLT_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;
   UInt_t          tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
   UInt_t          tau_1_trig_trigger_matched;
   Int_t           tau_1_type;
   Float_t         tau_eta_centrality;
   UInt_t          truth_passedVBFFilter;

   TBranch        *b_truth_passedVBFFilter;   //!
   TBranch        *b_AMI_cross_section;   //!
   TBranch        *b_HTXS_Higgs_eta;   //!
   TBranch        *b_HTXS_Higgs_pt;   //!
   TBranch        *b_HTXS_Njets_pTjet25;   //!
   TBranch        *b_HTXS_Njets_pTjet30;   //!
   TBranch        *b_HTXS_Stage0_Category;   //!
   TBranch        *b_HTXS_Stage1_2_Category_pTjet25GeV;   //!
   TBranch        *b_HTXS_Stage1_2_Category_pTjet30GeV;   //!
   TBranch        *b_HTXS_Stage1_2_Fine_Category_pTjet25GeV;   //!
   TBranch        *b_HTXS_Stage1_2_Fine_Category_pTjet30GeV;   //!
   TBranch        *b_HTXS_Stage1_Category_pTjet25GeV;   //!
   TBranch        *b_HTXS_Stage1_Category_pTjet30GeV;   //!
   TBranch        *b_HTXS_errorMode;   //!
   TBranch        *b_HTXS_prodMode;   //!
   TBranch        *b_HTjets;   //!
   TBranch        *b_NOMINAL_pileup_combined_weight;   //!
   TBranch        *b_NOMINAL_pileup_random_lb_number;   //!
   TBranch        *b_NOMINAL_pileup_random_run_number;   //!
   TBranch        *b_PRW_DATASF_1down_pileup_combined_weight;   //!
   TBranch        *b_PRW_DATASF_1up_pileup_combined_weight;   //!
   TBranch        *b_SumPtBjet;   //!
   TBranch        *b_boson_0_truth_p4;   //!
   TBranch        *b_boson_0_truth_pdgId;   //!
   TBranch        *b_boson_0_truth_q;   //!
   TBranch        *b_boson_0_truth_status;   //!
   TBranch        *b_channel_index;   //!
   TBranch        *b_cross_section;   //!
   TBranch        *b_dijet_p4;   //!
   TBranch        *b_ditau_CP_alphaminus_ip;   //!
   TBranch        *b_ditau_CP_alphaminus_ip_rho;   //!
   TBranch        *b_ditau_CP_alphaminus_rho_rho;   //!
   TBranch        *b_ditau_CP_ip_tau0_mag;   //!
   TBranch        *b_ditau_CP_ip_tau0_x_ip;   //!
   TBranch        *b_ditau_CP_ip_tau0_y_ip;   //!
   TBranch        *b_ditau_CP_ip_tau0_z_ip;   //!
   TBranch        *b_ditau_CP_ip_tau1_mag;   //!
   TBranch        *b_ditau_CP_ip_tau1_x_ip;   //!
   TBranch        *b_ditau_CP_ip_tau1_y_ip;   //!
   TBranch        *b_ditau_CP_ip_tau1_z_ip;   //!
   TBranch        *b_ditau_CP_phi_star_cp_a1_rho;   //!
   TBranch        *b_ditau_CP_phi_star_cp_ip_ip;   //!
   TBranch        *b_ditau_CP_phi_star_cp_ip_rho;   //!
   TBranch        *b_ditau_CP_phi_star_cp_ip_rho_opt;   //!
   TBranch        *b_ditau_CP_phi_star_cp_rho_ip;   //!
   TBranch        *b_ditau_CP_phi_star_cp_rho_rho;   //!
   TBranch        *b_ditau_CP_tau0_upsilon;   //!
   TBranch        *b_ditau_CP_tau1_upsilon;   //!
   TBranch        *b_ditau_CP_upsilon_a1;   //!
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
   TBranch        *b_ditau_matched_CP_alphaminus_ip;   //!
   TBranch        *b_ditau_matched_CP_alphaminus_ip_rho;   //!
   TBranch        *b_ditau_matched_CP_alphaminus_rho_rho;   //!
   TBranch        *b_ditau_matched_CP_ip_tau0_mag;   //!
   TBranch        *b_ditau_matched_CP_ip_tau0_x_ip;   //!
   TBranch        *b_ditau_matched_CP_ip_tau0_y_ip;   //!
   TBranch        *b_ditau_matched_CP_ip_tau0_z_ip;   //!
   TBranch        *b_ditau_matched_CP_ip_tau1_mag;   //!
   TBranch        *b_ditau_matched_CP_ip_tau1_x_ip;   //!
   TBranch        *b_ditau_matched_CP_ip_tau1_y_ip;   //!
   TBranch        *b_ditau_matched_CP_ip_tau1_z_ip;   //!
   TBranch        *b_ditau_matched_CP_phi_star_cp_a1_rho;   //!
   TBranch        *b_ditau_matched_CP_phi_star_cp_ip_ip;   //!
   TBranch        *b_ditau_matched_CP_phi_star_cp_ip_rho;   //!
   TBranch        *b_ditau_matched_CP_phi_star_cp_ip_rho_opt;   //!
   TBranch        *b_ditau_matched_CP_phi_star_cp_rho_ip;   //!
   TBranch        *b_ditau_matched_CP_phi_star_cp_rho_rho;   //!
   TBranch        *b_ditau_matched_CP_tau0_upsilon;   //!
   TBranch        *b_ditau_matched_CP_tau1_upsilon;   //!
   TBranch        *b_ditau_matched_CP_upsilon_a1;   //!
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
   TBranch        *b_ditau_mmc_maxw_phi;   //!
   TBranch        *b_ditau_mmc_maxw_pt;   //!
   TBranch        *b_ditau_mmc_mlm_fit_status;   //!
   TBranch        *b_ditau_mmc_mlm_m;   //!
   TBranch        *b_ditau_mt_lep0_met;   //!
   TBranch        *b_ditau_mt_lep1_met;   //!
   TBranch        *b_ditau_p4;   //!
   TBranch        *b_ditau_qxq;   //!
   TBranch        *b_ditau_scal_sum_pt;   //!
   TBranch        *b_event_clean_EC_TightBad;   //!
   TBranch        *b_event_is_bad_batman;   //!
   TBranch        *b_event_number;   //!
   TBranch        *b_filter_efficiency;   //!
   TBranch        *b_is_dijet_centrality;   //!
   TBranch        *b_jet_0_b_tag_score;   //!
   TBranch        *b_jet_0_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_0_b_tagged_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_0_fjvt;   //!
   TBranch        *b_jet_0_flavorlabel_part;   //!
   TBranch        *b_jet_0_is_Jvt_HS;   //!
   TBranch        *b_jet_0_jvt;   //!
   TBranch        *b_jet_0_p4;   //!
   TBranch        *b_jet_0_width;   //!
   TBranch        *b_jet_0_wztruth_p4;   //!
   TBranch        *b_jet_0_wztruth_pdgid;   //!
   TBranch        *b_jet_1_b_tag_score;   //!
   TBranch        *b_jet_1_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_1_b_tagged_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_1_fjvt;   //!
   TBranch        *b_jet_1_flavorlabel_part;   //!
   TBranch        *b_jet_1_is_Jvt_HS;   //!
   TBranch        *b_jet_1_jvt;   //!
   TBranch        *b_jet_1_p4;   //!
   TBranch        *b_jet_1_width;   //!
   TBranch        *b_jet_1_wztruth_p4;   //!
   TBranch        *b_jet_1_wztruth_pdgid;   //!
   TBranch        *b_jet_2_b_tag_score;   //!
   TBranch        *b_jet_2_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_2_b_tagged_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_jet_3_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_3_b_tagged_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_jet_4_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_4_b_tagged_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_jet_5_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_5_b_tagged_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_jet_6_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_6_b_tagged_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_jet_7;   //!
   TBranch        *b_jet_7_b_tag_quantile;   //!
   TBranch        *b_jet_7_b_tag_score;   //!
   TBranch        *b_jet_7_b_tagged_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_7_b_tagged_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_7_cleanJet_EC_LooseBad;   //!
   TBranch        *b_jet_7_fjvt;   //!
   TBranch        *b_jet_7_flavorlabel;   //!
   TBranch        *b_jet_7_flavorlabel_cone;   //!
   TBranch        *b_jet_7_flavorlabel_part;   //!
   TBranch        *b_jet_7_is_Jvt_HS;   //!
   TBranch        *b_jet_7_jvt;   //!
   TBranch        *b_jet_7_origin;   //!
   TBranch        *b_jet_7_p4;   //!
   TBranch        *b_jet_7_q;   //!
   TBranch        *b_jet_7_type;   //!
   TBranch        *b_jet_7_width;   //!
   TBranch        *b_jet_7_wztruth_p4;   //!
   TBranch        *b_jet_7_wztruth_pdgid;   //!



   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_jet_NOMINAL_global_effSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_NOMINAL_global_effSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jet_NOMINAL_global_ineffSF_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jet_NOMINAL_global_ineffSF_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jjdrmin;   //!
   TBranch        *b_kfactor;   //!
   TBranch        *b_lepton_eta_centrality;   //!
   TBranch        *b_mTopWbest;   //!
   TBranch        *b_mWbest;   //!
   TBranch        *b_mWsubbest;   //!
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
   TBranch        *b_n_bjets_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_n_bjets_DL1r_FixedCutBEff_85;   //!
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
   TBranch        *b_n_taus_rnn_loose;   //!
   TBranch        *b_n_taus_rnn_medium;   //!
   TBranch        *b_n_taus_rnn_tight;   //!
   TBranch        *b_n_taus_rnn_veryloose;   //!
   TBranch        *b_n_truth_gluon_jets;   //!
   TBranch        *b_n_truth_jets;   //!
   TBranch        *b_n_truth_jets_pt20_eta45;   //!
   TBranch        *b_n_truth_quark_jets;   //!
   TBranch        *b_n_vx;   //!
   TBranch        *b_pmg_truth_weight_FSRHi;   //!
   TBranch        *b_pmg_truth_weight_FSRLo;   //!
   TBranch        *b_pmg_truth_weight_ISRLo;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_0;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_1;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_10;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_11;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_12;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_13;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_14;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_15;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_16;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_17;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_18;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_19;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_2;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_20;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_21;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_22;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_23;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_24;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_25;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_26;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_27;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_28;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_29;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_3;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_30;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_4;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_5;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_6;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_7;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_8;   //!
   TBranch        *b_pmg_truth_weight_pdf_signal_weight_9;   //!
   TBranch        *b_primary_vertex;   //!
   TBranch        *b_primary_vertex_v;   //!
   TBranch        *b_pt_total;   //!
   TBranch        *b_run_number;   //!
   TBranch        *b_scalar_sum_pt;   //!
   TBranch        *b_tau_0;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_reco;   //!
   TBranch        *b_tau_0_NOMINAL_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_0_allTrk_eta;   //!
   TBranch        *b_tau_0_allTrk_n;   //!
   TBranch        *b_tau_0_allTrk_phi;   //!
   TBranch        *b_tau_0_allTrk_pt;   //!
   TBranch        *b_tau_0_b_tagged;   //!
   TBranch        *b_tau_0_decay_charged_p4;   //!
   TBranch        *b_tau_0_decay_mode;   //!
   TBranch        *b_tau_0_decay_neutral_p4;   //!
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
   TBranch        *b_tau_0_jet_jvt;   //!
   TBranch        *b_tau_0_jet_rnn_loose;   //!
   TBranch        *b_tau_0_jet_rnn_medium;   //!
   TBranch        *b_tau_0_jet_rnn_score;   //!
   TBranch        *b_tau_0_jet_rnn_score_trans;   //!
   TBranch        *b_tau_0_jet_rnn_tight;   //!
   TBranch        *b_tau_0_jet_rnn_veryloose;   //!
   TBranch        *b_tau_0_jet_width;   //!
   TBranch        *b_tau_0_jetseed_TrackWidthPt1000_wrt_PV;   //!
   TBranch        *b_tau_0_jetseed_TrackWidthPt1000_wrt_TV;   //!
   TBranch        *b_tau_0_jetseed_p4;   //!
   TBranch        *b_tau_0_leadTrk_d0;   //!
   TBranch        *b_tau_0_leadTrk_d0_sig;   //!
   TBranch        *b_tau_0_leadTrk_eta;   //!
   TBranch        *b_tau_0_leadTrk_phi;   //!
   TBranch        *b_tau_0_leadTrk_pt;   //!
   TBranch        *b_tau_0_leadTrk_pvx_z0;   //!
   TBranch        *b_tau_0_leadTrk_pvx_z0_sig;   //!
   TBranch        *b_tau_0_leadTrk_pvx_z0_sintheta;   //!
   TBranch        *b_tau_0_leadTrk_vertex_v;   //!
   TBranch        *b_tau_0_leadTrk_z0;   //!
   TBranch        *b_tau_0_leadTrk_z0_sig;   //!
   TBranch        *b_tau_0_leadTrk_z0_sintheta;   //!
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
   TBranch        *b_tau_0_trig_HLT_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_0_trig_trigger_matched;   //!
   TBranch        *b_tau_0_type;   //!
   TBranch        *b_tau_1;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_reco;   //!
   TBranch        *b_tau_1_NOMINAL_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_STAT_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1down_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEELECTRON_EFF_ELEBDT_SYST_1up_TauEffSF_LooseEleBDT_electron;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_1PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2025_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT2530_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPT3040_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_3PRONGSTATSYSTPTGE40_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_HIGHPT_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1down_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNloose;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNmedium;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_RNNID_SYST_1up_TauEffSF_JetRNNtight;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU161718_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1down_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNLOOSE;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM;   //!
   TBranch        *b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYSTMU2018_1up_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNTIGHT;   //!
   TBranch        *b_tau_1_allTrk_eta;   //!
   TBranch        *b_tau_1_allTrk_n;   //!
   TBranch        *b_tau_1_allTrk_phi;   //!
   TBranch        *b_tau_1_allTrk_pt;   //!
   TBranch        *b_tau_1_b_tagged;   //!
   TBranch        *b_tau_1_decay_charged_p4;   //!
   TBranch        *b_tau_1_decay_mode;   //!
   TBranch        *b_tau_1_decay_neutral_p4;   //!
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
   TBranch        *b_tau_1_jet_jvt;   //!
   TBranch        *b_tau_1_jet_rnn_loose;   //!
   TBranch        *b_tau_1_jet_rnn_medium;   //!
   TBranch        *b_tau_1_jet_rnn_score;   //!
   TBranch        *b_tau_1_jet_rnn_score_trans;   //!
   TBranch        *b_tau_1_jet_rnn_tight;   //!
   TBranch        *b_tau_1_jet_rnn_veryloose;   //!
   TBranch        *b_tau_1_jet_width;   //!
   TBranch        *b_tau_1_jetseed_TrackWidthPt1000_wrt_PV;   //!
   TBranch        *b_tau_1_jetseed_TrackWidthPt1000_wrt_TV;   //!
   TBranch        *b_tau_1_jetseed_p4;   //!
   TBranch        *b_tau_1_leadTrk_d0;   //!
   TBranch        *b_tau_1_leadTrk_d0_sig;   //!
   TBranch        *b_tau_1_leadTrk_eta;   //!
   TBranch        *b_tau_1_leadTrk_phi;   //!
   TBranch        *b_tau_1_leadTrk_pt;   //!
   TBranch        *b_tau_1_leadTrk_pvx_z0;   //!
   TBranch        *b_tau_1_leadTrk_pvx_z0_sig;   //!
   TBranch        *b_tau_1_leadTrk_pvx_z0_sintheta;   //!
   TBranch        *b_tau_1_leadTrk_vertex_v;   //!
   TBranch        *b_tau_1_leadTrk_z0;   //!
   TBranch        *b_tau_1_leadTrk_z0_sig;   //!
   TBranch        *b_tau_1_leadTrk_z0_sintheta;   //!
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
   TBranch        *b_tau_1_trig_HLT_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_03dR30_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;   //!
   TBranch        *b_tau_1_trig_trigger_matched;   //!
   TBranch        *b_tau_1_type;   //!
   TBranch        *b_tau_eta_centrality; 

};
#endif // #ifdef hadhadtree_cxx








