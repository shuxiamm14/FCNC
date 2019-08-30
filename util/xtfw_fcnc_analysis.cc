#include "histSaver.h"
#include "TH1D.h"
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <sys/ioctl.h>
#include "observable.h"
#include "fcnc_include.h"
using namespace std;
TString NPnames[] = {
//============weight sys==================
	"beforecorrection",
	"NOMINAL",
	"fakeSFNP1",
	"fakeSFNP2",
	"fakeSFNP3",
	"fakeSFNP4",
	"fakeSFNP5",
	"fakeSFNP6",
	"PRW_DATASF_1up_pileup_combined_weight",
	"PRW_DATASF_1down_pileup_combined_weight",
	"jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10",
	"jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10",
	"jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10",
	"jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT",
	"jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT",
	"jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT",
	"jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection",
	"TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM",
	"LHE3Weight_muR=10,muF=20",
	"LHE3Weight_muR=10,muF=05",
	"LHE3Weight_muR=20,muF=10",
	"LHE3Weight_muR=05,muF=10",
	"LHE3Weight_muR=05,muF=05",
	"LHE3Weight_muR=20,muF=20",
	"LHE3Weight_muR=20,muF=05",
	"LHE3Weight_muR=05,muF=20 ",
	"LHE3Weight_PDFset=260001",
	"LHE3Weight_PDFset=260002",
	"LHE3Weight_PDFset=260003",
	"LHE3Weight_PDFset=260004",
	"LHE3Weight_PDFset=260005",
	"LHE3Weight_PDFset=260006",
	"LHE3Weight_PDFset=260007",
	"LHE3Weight_PDFset=260008",
	"LHE3Weight_PDFset=260009",
	"LHE3Weight_PDFset=260010",
	"LHE3Weight_PDFset=260011",
	"LHE3Weight_PDFset=260012",
	"LHE3Weight_PDFset=260013",
	"LHE3Weight_PDFset=260014",
	"LHE3Weight_PDFset=260015",
	"LHE3Weight_PDFset=260016",
	"LHE3Weight_PDFset=260017",
	"LHE3Weight_PDFset=260018",
	"LHE3Weight_PDFset=260019",
	"LHE3Weight_PDFset=260020",
	"LHE3Weight_PDFset=260021",
	"LHE3Weight_PDFset=260022",
	"LHE3Weight_PDFset=260023",
	"LHE3Weight_PDFset=260024",
	"LHE3Weight_PDFset=260025",
	"LHE3Weight_PDFset=260026",
	"LHE3Weight_PDFset=260027",
	"LHE3Weight_PDFset=260028",
	"LHE3Weight_PDFset=260029",
	"LHE3Weight_PDFset=260030",
	"LHE3Weight_PDFset=260031",
	"LHE3Weight_PDFset=260032",
	"LHE3Weight_PDFset=260033",
	"LHE3Weight_PDFset=260034",
	"LHE3Weight_PDFset=260035",
	"LHE3Weight_PDFset=260036",
	"LHE3Weight_PDFset=260037",
	"LHE3Weight_PDFset=260038",
	"LHE3Weight_PDFset=260039",
	"LHE3Weight_PDFset=260040",
	"LHE3Weight_PDFset=260041",
	"LHE3Weight_PDFset=260042",
	"LHE3Weight_PDFset=260043",
	"LHE3Weight_PDFset=260044",
	"LHE3Weight_PDFset=260045",
	"LHE3Weight_PDFset=260046",
	"LHE3Weight_PDFset=260047",
	"LHE3Weight_PDFset=260048",
	"LHE3Weight_PDFset=260049",
	"LHE3Weight_PDFset=260050",
	"LHE3Weight_PDFset=260051",
	"LHE3Weight_PDFset=260052",
	"LHE3Weight_PDFset=260053",
	"LHE3Weight_PDFset=260054",
	"LHE3Weight_PDFset=260055",
	"LHE3Weight_PDFset=260056",
	"LHE3Weight_PDFset=260057",
	"LHE3Weight_PDFset=260058",
	"LHE3Weight_PDFset=260059",
	"LHE3Weight_PDFset=260060",
	"LHE3Weight_PDFset=260061",
	"LHE3Weight_PDFset=260062",
	"LHE3Weight_PDFset=260063",
	"LHE3Weight_PDFset=260064",
	"LHE3Weight_PDFset=260065",
	"LHE3Weight_PDFset=260066",
	"LHE3Weight_PDFset=260067",
	"LHE3Weight_PDFset=260068",
	"LHE3Weight_PDFset=260069",
	"LHE3Weight_PDFset=260070",
	"LHE3Weight_PDFset=260071",
	"LHE3Weight_PDFset=260072",
	"LHE3Weight_PDFset=260073",
	"LHE3Weight_PDFset=260074",
	"LHE3Weight_PDFset=260075",
	"LHE3Weight_PDFset=260076",
	"LHE3Weight_PDFset=260077",
	"LHE3Weight_PDFset=260078",
	"LHE3Weight_PDFset=260079",
	"LHE3Weight_PDFset=260080",
	"LHE3Weight_PDFset=260081",
	"LHE3Weight_PDFset=260082",
	"LHE3Weight_PDFset=260083",
	"LHE3Weight_PDFset=260084",
	"LHE3Weight_PDFset=260085",
	"LHE3Weight_PDFset=260086",
	"LHE3Weight_PDFset=260087",
	"LHE3Weight_PDFset=260088",
	"LHE3Weight_PDFset=260089",
	"LHE3Weight_PDFset=260090",
	"LHE3Weight_PDFset=260091",
	"LHE3Weight_PDFset=260092",
	"LHE3Weight_PDFset=260093",
	"LHE3Weight_PDFset=260094",
	"LHE3Weight_PDFset=260095",
	"LHE3Weight_PDFset=260096",
	"LHE3Weight_PDFset=260097",
	"LHE3Weight_PDFset=260098",
	"LHE3Weight_PDFset=260099",
	"LHE3Weight_PDFset=260100",
//=================Sys tree===================
	"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1down",
	"TAUS_TRUEHADTAU_SME_TES_DETECTOR_1up",
	"TAUS_TRUEHADTAU_SME_TES_INSITU_1down",
	"TAUS_TRUEHADTAU_SME_TES_INSITU_1up",
	"TAUS_TRUEHADTAU_SME_TES_MODEL_1down",
	"TAUS_TRUEHADTAU_SME_TES_MODEL_1up",
	"JET_BJES_Response_1up",
	"JET_BJES_Response_1down",
	"JET_EffectiveNP_Detector1_1up",
	"JET_EffectiveNP_Detector1_1down",
	"JET_EffectiveNP_Detector2_1up",
	"JET_EffectiveNP_Detector2_1down",
	"JET_EffectiveNP_Mixed1_1up",
	"JET_EffectiveNP_Mixed1_1down",
	"JET_EffectiveNP_Mixed2_1up",
	"JET_EffectiveNP_Mixed2_1down",
	"JET_EffectiveNP_Mixed3_1up",
	"JET_EffectiveNP_Mixed3_1down",
	"JET_EffectiveNP_Modelling1_1up",
	"JET_EffectiveNP_Modelling1_1down",
	"JET_EffectiveNP_Modelling2_1up",
	"JET_EffectiveNP_Modelling2_1down",
	"JET_EffectiveNP_Modelling3_1up",
	"JET_EffectiveNP_Modelling3_1down",
	"JET_EffectiveNP_Modelling4_1up",
	"JET_EffectiveNP_Modelling4_1down",
	"JET_EffectiveNP_Statistical1_1up",
	"JET_EffectiveNP_Statistical1_1down",
	"JET_EffectiveNP_Statistical2_1up",
	"JET_EffectiveNP_Statistical2_1down",
	"JET_EffectiveNP_Statistical3_1up",
	"JET_EffectiveNP_Statistical3_1down",
	"JET_EffectiveNP_Statistical4_1up",
	"JET_EffectiveNP_Statistical4_1down",
	"JET_EffectiveNP_Statistical5_1up",
	"JET_EffectiveNP_Statistical5_1down",
	"JET_EffectiveNP_Statistical6_1up",
	"JET_EffectiveNP_Statistical6_1down",
	"JET_EtaIntercalibration_Modelling_1up",
	"JET_EtaIntercalibration_Modelling_1down",
	"JET_EtaIntercalibration_NonClosure_highE_1up",
	"JET_EtaIntercalibration_NonClosure_highE_1down",
	"JET_EtaIntercalibration_NonClosure_negEta_1up",
	"JET_EtaIntercalibration_NonClosure_negEta_1down",
	"JET_EtaIntercalibration_NonClosure_posEta_1up",
	"JET_EtaIntercalibration_NonClosure_posEta_1down",
	"JET_EtaIntercalibration_TotalStat_1up",
	"JET_EtaIntercalibration_TotalStat_1down",
	"JET_Flavor_Composition_1up",
	"JET_Flavor_Composition_1down",
	"JET_Flavor_Response_1up",
	"JET_Flavor_Response_1down",
	"JET_JER_DataVsMC_MC16_1up",
	"JET_JER_DataVsMC_MC16_1down",
	"JET_JER_EffectiveNP_1_1up",
	"JET_JER_EffectiveNP_1_1down",
	"JET_JER_EffectiveNP_2_1up",
	"JET_JER_EffectiveNP_2_1down",
	"JET_JER_EffectiveNP_3_1up",
	"JET_JER_EffectiveNP_3_1down",
	"JET_JER_EffectiveNP_4_1up",
	"JET_JER_EffectiveNP_4_1down",
	"JET_JER_EffectiveNP_5_1up",
	"JET_JER_EffectiveNP_5_1down",
	"JET_JER_EffectiveNP_6_1up",
	"JET_JER_EffectiveNP_6_1down",
	"JET_JER_EffectiveNP_7restTerm_1up",
	"JET_JER_EffectiveNP_7restTerm_1down",
	"JET_Pileup_OffsetMu_1up",
	"JET_Pileup_OffsetMu_1down",
	"JET_Pileup_OffsetNPV_1up",
	"JET_Pileup_OffsetNPV_1down",
	"JET_Pileup_PtTerm_1up",
	"JET_Pileup_PtTerm_1down",
	"JET_Pileup_RhoTopology_1up",
	"JET_Pileup_RhoTopology_1down",
	"JET_PunchThrough_MC16_1up",
	"JET_PunchThrough_MC16_1down",
	"JET_SingleParticle_HighPt_1up",
	"JET_SingleParticle_HighPt_1down",
	"JET_TILECORR_Uncertainty_1down",
	"JET_TILECORR_Uncertainty_1up",
	"MET_SoftTrk_ResoPara",
	"MET_SoftTrk_ResoPerp",
	"MET_SoftTrk_ScaleDown",
	"MET_SoftTrk_ScaleUp",
//==========Sys sample==============
	"ttbarsys_frag",
	"ttbarsys_hscatter",
	"ttbarsys_ISR"
};

void plot(int iNP)
{
	int histoiNP = 1;
	bool calibfake = 1;
	bool fakeMC = 0;
	bool doTrex = 0;
	if(iNP < 124) histoiNP = iNP;
	bool doPlots = 1;
	int plot_option = 2;
	TString outputdir[] = {"merge_other","merge_sample","merge_origin"};
	histSaver *tau_plots = new histSaver("b4fakeSFplot");
	tau_plots->doROC = 0;
	tau_plots->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV, 140 fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
	tau_plots->debug = 0;
	vector<TString> samples;
	samples.push_back("smhiggs");
	samples.push_back("wjet");
	samples.push_back("diboson");
	samples.push_back("zll");
	samples.push_back("ztautau");
	samples.push_back("top");
	samples.push_back("fcnc_ch");
	samples.push_back("fcnc_prod_ch");
	samples.push_back("tcH");
	samples.push_back("fcnc_uh");
	samples.push_back("fcnc_prod_uh");
	samples.push_back("tuH");
	double norm[] = {1,1,1,1,1,1,0.2,0.2,0.2,0.2,0.2,0.2};
//	double norm[20] = {1,};
	vector<TString> sampletitle;
	sampletitle.push_back("SM Higgs");
	sampletitle.push_back("W+jets");
	sampletitle.push_back("Diboson");
	sampletitle.push_back("Z#rightarrowll");
	sampletitle.push_back("Z#rightarrow#tau#tau");
	sampletitle.push_back("Top production");
	sampletitle.push_back("#bar{t}t#rightarrowbWcH");
	sampletitle.push_back("ctH Prod Mode");
	sampletitle.push_back("tcH merged signal");
	sampletitle.push_back("#bar{t}t#rightarrowbWuH");
	sampletitle.push_back("utH Prod Mode");
	sampletitle.push_back("tuH merged signal");
	TString samplesys = "";
	if(NPnames[iNP].Contains("ttbar")){
		samplesys = "top";
	}
	tau_plots->inputfilename = "hists"+to_string(samplesys==""?iNP:1);

	tau_plots->sensitivevariable = "BDTG_test";
	tau_plots->add("BDT discriminant","BDTG_test","",5);
	//tau_plots->add("BDT discriminant","BDTG_train","",5);
  	//tau_plots->add("p_{T,lead-#tau}","tau_0_pt","GeV",5);
  	//tau_plots->add("p_{T,sublead-#tau}","tau_1_pt","GeV",5);
  	//tau_plots->add("#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss","",5);
  	//tau_plots->add("m_{#tau#tau,vis}","ttvismass","",5);
  	//tau_plots->add("#DeltaR(#tau,#tau)","drtautau","",5);
  	//tau_plots->add("#DeltaR(#tau,light-jet,min)","drtaujmin","",5);
  	//tau_plots->add("E^{T}_{miss} centrality","phicent","",5);
  	//tau_plots->add("m_{t,SM}","t1mass","GeV",20);
  	//tau_plots->add("m_{#tau,#tau}","tautaumass","GeV",5);
  	//tau_plots->add("m_{W}","wmass","GeV",5);
  	//tau_plots->add("m_{t,FCNC}","t2mass","GeV",20);
  	//tau_plots->add("E^{T}_{miss}","etmiss","GeV",5);
  	//tau_plots->add("#chi^2","chi2","",5);
  	//tau_plots->add("E_{vis,#tau,1}/E_{#tau,1}","x1fit","",5);
  	//tau_plots->add("E_{vis,#tau,2}/E_{#tau,2}","x2fit","",5);
  	gErrorIgnoreLevel = kWarning;
  	tau_plots->blinding = 1;
	vector<TString> regions;
	regions.push_back("reg2mtau1b2jss");
	regions.push_back("reg2mtau1b2jos");
	regions.push_back("reg2mtau1b3jss");
	regions.push_back("reg2mtau1b3jos");

	regions.push_back("reg2mtau2b2jss");
	regions.push_back("reg2mtau2b2jos");
	regions.push_back("reg2mtau2b3jss");
	regions.push_back("reg2mtau2b3jos");

	//regions.push_back("reg1mtau1ltau1b2jss");
	//regions.push_back("reg2ltau1b2jss");
	//regions.push_back("reg1mtau1ltau1b3jss");
	//regions.push_back("reg2ltau1b3jss");
	//regions.push_back("reg1mtau1ltau1b2jos");
	//regions.push_back("reg2ltau1b2jos");
	//regions.push_back("reg1mtau1ltau1b3jos");
	//regions.push_back("reg2ltau1b3jos");
	int nregions = regions.size();
	TString nprong[] = {"1prong","3prong"};
	for (int j = 0; j < nregions; ++j)
	  for (int k = 0; k < 2; ++k)
	    for (int i = 1; i < 2; i+=2){
	    	//TString addedregion = regions[j] + "_" + nprong[k] + "_veto";
	      	//printf("adding region: %s\n", addedregion.Data());
	      	//tau_plots->add_region(addedregion);
//	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_");
	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_above35_vetobtagwp70");
	    	tau_plots->add_region(regions[j] + "_" + nprong[k] + "_below35_vetobtagwp70");
	    }
	tau_plots->muteregion("prong");
	stringstream ss;
	ss<<"(BR=" << norm[6] << "%)";
	TString tmp;
	ss>>tmp;
	for(int i = 6; i<12 ; ++i) sampletitle[i]+=tmp;
	TString origin[] = {"b", "c", "g", "j", "lep", "nomatch", "real", "data","doublefake"};
	TString origintitle[] = {"(b-jets fake #tau)", "(c-jets fake #tau)", "(gluon-jets fake #tau)", "(light-jets fake #tau)", "(lepton fake #tau)", "(no truth matched fake #tau)", "real #tau"};
	int colors[] = {kViolet, kOrange, 7, kBlue, kGreen, kGray, kRed, kRed, kRed, kRed, kRed, kRed, kMagenta, kSpring, kTeal, kAzure};

	TFile *datafile = new TFile("histsdata.root");
	tau_plots->read_sample("data","data","data",kBlack, 1, datafile);
//============================ merge_sample============================
	if(plot_option == 1){
		for (int j = 0; j < samples.size(); ++j)
			for (int i = 0; i < 7; ++i)
				tau_plots->read_sample( origin[i], samples[j] + "_" + origin[i], origintitle[i], (enum EColor)colors[i], norm[j]);
	}
//============================ merge_origin ============================
	else if(plot_option == 2){
		for (int j = 0; j < samples.size(); ++j){
			for (int i = 0; i < 7; i++){
				if (fakeMC && origin[i] != "real")
				{
					tau_plots->read_sample( "fake1truth", (samplesys==samples[j] ? NPnames[iNP] : samples[j]) + "_" + origin[i] + "_NP" + to_string(histoiNP), "Fake MC, 1 truth #tau", kMagenta, norm[j]);
				}
				
				if(samples[j] == "tcH"){
					tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_qq_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_lv_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], TString("fcnc_prod_ch") + "_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
				}else if(samples[j] == "tuH"){
					tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_qq_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_lv_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], TString("fcnc_prod_uh") + "_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
				}else if(samples[j] == "fcnc_uh"){
					tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_qq_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], TString("fcnc_uh") + "_lv_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
				}else if(samples[j] == "fcnc_ch"){
					tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_qq_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
					tau_plots->read_sample( samples[j], TString("fcnc_ch") + "_lv_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
				}else if(origin[i] == "real"){
					tau_plots->read_sample( samples[j], (samplesys==samples[j] ? NPnames[iNP] : samples[j]) + "_" + origin[i] + "_NP" + to_string(histoiNP), sampletitle[j], (enum EColor)colors[j], norm[j]);
				}else if(origin[i] != "real" && !fakeMC && calibfake){
					tau_plots->read_sample( "fake", (samplesys==samples[j] ? NPnames[iNP] : samples[j]) + "_" + origin[i] + "_NP" + to_string(histoiNP), "MC Fake #tau", kTeal, norm[j]);
				}
				
			}
			if(fakeMC && j != samples.size()-1) tau_plots->read_sample( "fake0truth", (samplesys==samples[j] ? NPnames[iNP] : samples[j]) + "_" + origin[8] + "_NP" + to_string(histoiNP), "fake, 0 truth #tau", kTeal, norm[j]);
		}

	}
	for (int j = 0; j < nregions; ++j){
		for (int k = 0; k < 2; ++k)
			for (int i = 1; i < 2; i+=2){
			  tau_plots->merge_regions(regions[j] + "_" + nprong[k] + "_above35_vetobtagwp70",regions[j] + "_" + nprong[k] + "_below35_vetobtagwp70",regions[j] + "_" + nprong[k]);
			}
		tau_plots->merge_regions(regions[j] + "_" + nprong[0],regions[j] + "_" + nprong[1],regions[j]);
	}
	if(plot_option == 2){
  		vector<TString> stacks;
  		//tau_plots->overlay("fake");
  		stacks.push_back("ztautau");
  		stacks.push_back("top");
  		if(!fakeMC && calibfake) stacks.push_back("fake");
  		stacks.push_back("smhiggs");
  		stacks.push_back("wjet");
  		stacks.push_back("zll");
  		stacks.push_back("diboson");
  		if(!fakeMC) {
  			stacks.push_back("fakeSS");
  		}
  		else{
  			stacks.push_back("fake1truth");
  			stacks.push_back("fake0truth");
  		}
  		tau_plots->stackorder = stacks;
  		//double integralerr = 0;
  		//observable int1b3jssdata(integral(tau_plots->grabdatahist("reg2mtau1b3jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b3josdata(integral(tau_plots->grabdatahist("reg2mtau1b3jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2jssdata(integral(tau_plots->grabdatahist("reg2mtau1b2jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2josdata(integral(tau_plots->grabdatahist("reg2mtau1b2jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b3jssbkg(integral(tau_plots-> grabbkghist("reg2mtau1b3jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b3josbkg(integral(tau_plots-> grabbkghist("reg2mtau1b3jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2jssbkg(integral(tau_plots-> grabbkghist("reg2mtau1b2jss",0),-1,0.5,&integralerr),integralerr);
  		//observable int1b2josbkg(integral(tau_plots-> grabbkghist("reg2mtau1b2jos",0),-1,0.5,&integralerr),integralerr);
  		//observable int2b3jssdata(integral(tau_plots->grabdatahist("reg2mtau2b3jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b3josdata(integral(tau_plots->grabdatahist("reg2mtau2b3jos",0),-1,1,&integralerr),integralerr);
  		//observable int2b2jssdata(integral(tau_plots->grabdatahist("reg2mtau2b2jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b2josdata(integral(tau_plots->grabdatahist("reg2mtau2b2jos",0),-1,1,&integralerr),integralerr);
  		//observable int2b3jssbkg (integral(tau_plots-> grabbkghist("reg2mtau2b3jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b3josbkg (integral(tau_plots-> grabbkghist("reg2mtau2b3jos",0),-1,1,&integralerr),integralerr);
  		//observable int2b2jssbkg (integral(tau_plots-> grabbkghist("reg2mtau2b2jss",0),-1,1,&integralerr),integralerr);
  		//observable int2b2josbkg (integral(tau_plots-> grabbkghist("reg2mtau2b2jos",0),-1,1,&integralerr),integralerr);
  		//observable SF1b = ((int1b2josdata - int1b2josbkg + int1b3josdata - int1b3josbkg) / (int1b2jssdata - int1b2jssbkg + int1b3jssdata - int1b3jssbkg));
  		//observable SF2b = ((int2b2josdata - int2b2josbkg + int2b3josdata - int2b3josbkg) / (int2b2jssdata - int2b2jssbkg + int2b3jssdata - int2b3jssbkg));
  		//observable SF = ((int1b2josdata - int1b2josbkg + int1b3josdata - int1b3josbkg + int2b2josdata - int2b2josbkg + int2b3josdata - int2b3josbkg) 
  		//	/ (int1b2jssdata - int1b2jssbkg + int1b3jssdata - int1b3jssbkg + int2b2jssdata - int2b2jssbkg + int2b3jssdata - int2b3jssbkg));
  		//SF1b.print();
  		//SF2b.print();
  		//SF.print();

		if(!fakeMC){
  			tau_plots->templatesample("reg2mtau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau1b3jos","fakeSS","Fake",kYellow,0,1.31597);
  			tau_plots->templatesample("reg2mtau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau1b2jos","fakeSS","Fake",kYellow,0,1.31597);
  			//tau_plots->templatesample("reg2mtau2b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b3jos","fakeSS","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau2b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top -1 fake","reg2mtau2b2jos","fakeSS","Fake",kYellow,1);

  			//tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 smhiggs -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
	
  			//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
	
  			//tau_plots->templatesample("reg2mtau1b3jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b3jos","fake","Fake",kYellow,1);
  			//tau_plots->templatesample("reg2mtau1b2jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg2mtau1b2jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b3jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b3jos","fake","Fake",kYellow,1);
  			////tau_plots->templatesample("reg1mtau1ltau1b2jss","1 data -1 fakeMC -1 wjet -1 diboson -1 zll -1 ztautau -1 top","reg1mtau1ltau1b2jos","fake","Fake",kYellow,1);
  		}
  	}
  	//tau_plots->printyield("reg2mtau1b3jos");
  	//tau_plots->printyield("reg2mtau1b2jos");
	if(doTrex){
		if(NPnames[iNP].Contains("PDF")) tau_plots->trexdir = "PDF_trexinputs";
		else if(NPnames[iNP].Contains("muR")) tau_plots->trexdir = "scale_trexinputs";
		else tau_plots->trexdir = "trexinputs";
		tau_plots->write_trexinput(NPnames[iNP],"update");
	}
	if(doPlots){
		gSystem->mkdir(("output_"+to_string(iNP)).c_str());
		for (int i = samples.size()-6; i < samples.size(); ++i)
		{
  			tau_plots->overlay(samples[i]);
		}
		tau_plots->plot_stack(("output_"+to_string(iNP)).c_str());
		
	}
	//deletepointer(tau_plots);
}

int main(int argc, char const *argv[])
{
	int from = atoi(argv[1]);
	int to = atoi(argv[2]);
	for (int i = from; i <= to; ++i)
	{
//	struct winsize w; 
//	ioctl(0, TIOCGWINSZ, &w);
//	auto start = chrono::steady_clock::now();
//
//	for (int i = 0; i < 168; ++i)
//	{
//		if (i == 1)
//		{
//			continue;
//		}
//		auto end = chrono::steady_clock::now();
//		stringstream ss;
//		ss<<"Elapsed time in seconds : "<< chrono::duration_cast<chrono::seconds>(end - start).count()
//		<< " sec";
//	
//		printf("%*s\n" , w.ws_col, ss.str().c_str());
		printf("=============================generating NP %d : %s=============================\n", i, NPnames[i].Data());
		plot(i);
	}
	return 0;
}
