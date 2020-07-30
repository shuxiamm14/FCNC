#define hadhadtree_cxx
#include "hadhadtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "fcnc_include.h"
#include "common.h"
using namespace std;

hadhadtree::hadhadtree() : nominal::nominal(){
  defGeV(1);
  cut_flow.setWeight(&weight);
  belong_regions.m_region_map["SR"] = {
    "reg2mtau1b2jss",
    "reg1mtau1ltau1b2jss",
    "reg2ltau1b2jss",
    "reg2ttau1b2jss",
    "reg1ttau1mtau1b2jss",
    "reg2mtau1b3jss",
    "reg1mtau1ltau1b3jss",
    "reg2ltau1b3jss",
    "reg2ttau1b3jss",
    "reg1ttau1mtau1b3jss",
    "reg2mtau1b2jos",
    "reg1mtau1ltau1b2jos",
    "reg2ltau1b2jos",
    "reg2mtau1b3jos",
    "reg1mtau1ltau1b3jos",
    "reg2ltau1b3jos",
    "reg2ttau1b2jos",
    "reg1ttau1mtau1b2jos",
    "reg2ttau1b3jos",
    "reg1ttau1mtau1b3jos",
    "reg2mtau2b2jss",
    "reg2mtau2b3jss",
    "reg2mtau2b2jos",
    "reg2mtau2b3jos"
  };
}

void hadhadtree::init_hist(TString histfilename){
  //init histSaver here:
  dohist = 1;
  TString nprong[] = {"1prong","3prong"};
  if(reduce == 3){
    initMVA("reg2mtau1b3jos");
    initMVA("reg2mtau1b2jos");
  }
  fcnc_plots = new histSaver(histfilename);
  fcnc_plots->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV,  fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
  fcnc_plots->set_weight(&weight);
  fcnc_plots->debug = debug;
  auto vars = getVariables("xTFW");
  if(reduce == 3 && doBDT)
  fcnc_plots->add(vars["BDTG_train"],&BDTG_train);
  fcnc_plots->add(vars["BDTG_test"],&BDTG_test);
  fcnc_plots->add(vars["tau_pt_0"],&tau_pt_0);
  fcnc_plots->add(vars["tau_pt_1"],&tau_pt_1);
  fcnc_plots->add(vars["etmiss"],&etmiss);
  fcnc_plots->add(vars["dphitauetmiss"],&dphitauetmiss);
  fcnc_plots->add(vars["ttvismass"],&ttvismass);
  fcnc_plots->add(vars["drtautau"],&drtautau);
  fcnc_plots->add(vars["drttjmin"],&drttjmin);
  fcnc_plots->add(vars["phicent"],&phicent);
  fcnc_plots->add(vars["t1mass"],&t1mass);
  fcnc_plots->add(vars["tautaumass"],&tautaumass);
  fcnc_plots->add(vars["wmass"],&wmass);
  fcnc_plots->add(vars["t2mass"],&t2mass);
//fcnc_plots->add(vars["tautauvispt"],&tautauvispt);
//fcnc_plots->add(vars["t2vismass"],&t2vismass);
  fcnc_plots->add(vars["t1vismass"],&t1vismass);
  fcnc_plots->add(vars["x1fit"],&x1fit);
  fcnc_plots->add(vars["x2fit"],&x2fit);
  fcnc_plots->add(vars["chi2"],&chi2);
  fcnc_plots->add(vars["allmass"],&allmass);
  fcnc_plots->add(vars["allpz"],&allpz);
//fcnc_plots->add(vars["etamax"],&etamax);
//fcnc_plots->add(vars["drtauj"],&drtauj);
  for (int j = 0; j < fcnc_regions.size(); ++j)
  {
    for (int k = 0; k < 2; ++k)
    {
      if(debug) printf("adding region: %s\n", (fcnc_regions[j] + "_" + bwps[1]).Data());
      //fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[1]);
      fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_veto" + bwps[1]);
    }
  }
}

void hadhadtree::init_sample(TString sample, TString sampletitle){
//==========================init output n-tuple==========================
  if(reduce == 1){
    weights = new vector<double> ();
    taus_id = new vector<Int_t> ();
    taus_decay_mode = new vector<UInt_t> ();
    taus_matched_mother_pdgId = new vector<Int_t> ();
    taus_matched_mother_status = new vector<Int_t> ();
    taus_matched_p4 = new vector<TLorentzVector*>();
    taus_matched_pdgId = new vector<Int_t> ();
    taus_matched_vis_p4 = new vector<TLorentzVector*>();
    taus_n_charged_tracks = new vector<UInt_t> ();
    bjets_fjvt = new vector<Float_t> ();
    bjets_is_Jvt_HS = new vector<Int_t> ();
    bjets_jvt = new vector<Float_t> ();
    bjets_origin = new vector<Int_t> ();
    bjets_type = new vector<Int_t> ();
    bjets_width = new vector<Float_t> ();
    ljets_fjvt = new vector<Float_t> ();
    ljets_is_Jvt_HS = new vector<Int_t> ();
    ljets_jvt = new vector<Float_t> ();
    ljets_origin = new vector<Int_t> ();
    ljets_q = new vector<Float_t> ();
    ljets_type = new vector<Int_t> ();
    ljets_width = new vector<Float_t> ();
    initReduce1();
  }
  if(writetree){
    gSystem->mkdir(TString(PACKAGE_DIR) + "/data/xTFWreduce" + char('0' + reduce));
    gSystem->mkdir(TString(PACKAGE_DIR) + "/data/xTFWreduce" + char('0' + reduce) + "/" + SystematicsName);
    printf("create outputfile: %s\n", (TString(PACKAGE_DIR) + "/data/xTFWreduce" + char('0' + reduce) + "/" + SystematicsName + "/" + sample + "_tree.root").Data());
    outputtreefile = new TFile(TString(PACKAGE_DIR) + "/data/xTFWreduce" + char('0' + reduce) + "/" + SystematicsName + "/" + sample + "_tree.root","recreate");
    for (int i = 0; i < fcnc_regions.size(); ++i)
    {
      if(debug) printf("init sample:: get region: %s\n",fcnc_regions[i].Data());
      if (outputtreefile->Get(fcnc_regions[i])) {
        outputtree[fcnc_regions[i]] = (TTree*)(outputtreefile->Get(fcnc_regions[i]));
        Init(outputtree[fcnc_regions[i]]);
      }else{
        outputtree[fcnc_regions[i]] = new TTree(fcnc_regions[i],fcnc_regions[i]);
        definetree(outputtree[fcnc_regions[i]]);
      }
    }
  }
//==========================init output histogram==========================
  if(dohist){
    if (sample.Contains("data"))
    {
      fcnc_plots->init_sample("data","data","data",kBlack);
      initdata = 1;
    }else{
      sample.Remove(0,6);
      fcnc_plots->init_sample(sample + "_g","NOMINAL",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      fcnc_plots->init_sample(sample + "_j","NOMINAL",sampletitle + "(light-jet fake #tau)",kBlue);
      fcnc_plots->init_sample(sample + "_b","NOMINAL",sampletitle + "(b-jets fake #tau)",kViolet);
      fcnc_plots->init_sample(sample + "_lep","NOMINAL",sampletitle + "(lepton fake #tau)",kGreen);
      fcnc_plots->init_sample(sample + "_real","NOMINAL",sampletitle + "(real #tau)",kRed);
      fcnc_plots->init_sample(sample + "_c","NOMINAL",sampletitle + "(c-jets fake #tau)",kOrange);
      fcnc_plots->init_sample(sample + "_nomatch","NOMINAL",sampletitle + "(no truth matched fake #tau)",kGray);
      fcnc_plots->init_sample(sample + "_doublefake","NOMINAL",sampletitle + "(no truth matched fake #tau)",kGray);
    }
  }
}

vector<TLorentzVector> convertv(vector<TLorentzVector*> vv){
  vector<TLorentzVector> output;
  for(auto v: vv)
    output.push_back(*v);
  return output;
}

float hadhadtree::calcRegionSF(TString region){
  float ret = 1;
  if(!region.Contains("ttau")){
    if((taus_id->at(0)>=2)){
      ret *= tau_0_NOMINAL_TauEffSF_JetBDTmedium;
      ret *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
    }else{
      ret *= tau_0_NOMINAL_TauEffSF_JetBDTloose;
      ret *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
    }
    if((taus_id->at(1)>=2)){
      ret *= tau_1_NOMINAL_TauEffSF_JetBDTmedium;
      ret *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
    }else{
      ret *= tau_1_NOMINAL_TauEffSF_JetBDTloose;
      ret *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
    }
  }else{
    if(taus_id->at(0)==3){
      ret *= tau_0_NOMINAL_TauEffSF_JetBDTtight;
      ret *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
    }else{
      ret *= tau_0_NOMINAL_TauEffSF_JetBDTmedium;
      ret *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
    }
    if(taus_id->at(1)==3){
      ret *= tau_1_NOMINAL_TauEffSF_JetBDTtight;
      ret *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
    }else{
      ret *= tau_1_NOMINAL_TauEffSF_JetBDTmedium;
      ret *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
    }
  }
  return ret;
}

bool hadhadtree::passRegionCut(){
  cut_flow.fill("this region");
  //if(!isData && sample.Contains("fcnc") && !(abs(taus_matched_pdgId->at(0)) == 15 && abs(taus_matched_pdgId->at(1)) == 15)) continue;
  //cut_flow.fill("Only real tau");
  if(campaign !=1 && ljets_p4->at(0)->Pt() < 50 && bjets_p4->at(0)->Pt() < 50) return false;
  cut_flow.fill("year1718 Jet pt<50");
  return true;
}

bool hadhadtree::passBasicCut(){
/*
  if(year == 2015) passtrigger = HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM || HLT_tau35_loose1_tracktwo_tau25_loose1_tracktwo;
  if(year == 2016) passtrigger = HLT_tau35_loose1_tracktwo_tau25_loose1_tracktwo || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo || HLT_tau80_medium1_TAU60_tau50_medium1_L1TAU12 || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
  if(year == 2017) passtrigger = HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25 || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25 || HLT_tau40_medium1_tracktwo_tau35_medium1_tracktwo
    || HLT_tau80_medium1_tracktwo_L1TAU60_tau50_medium1_tracktwo_L1TAU12 || HLT_tau80_medium1_tracktwo_L1TAU60_tau35_medium1_tracktwo_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I || HLT_tau80_medium1_tracktwo_L1TAU60_tau50_medium1_tracktwo_L1TAU12 || HLT_tau80_medium1_tracktwo_L1TAU60_tau35_medium1_tracktwo_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I || HLT_tau80_medium1_tracktwo_L1TAU60_tau60_medium1_tracktwo_L1TAU40;
  if(year == 2018) passtrigger = HLT_tau80_medium1_tracktwoEF_L1TAU60_tau60_medium1_tracktwoEF_L1TAU40 || HLT_tau80_medium1_tracktwoEF_L1TAU60_tau35_medium1_tracktwoEF_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I || HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau60_mediumRNN_tracktwoMVA_L1TAU40 || HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau35_mediumRNN_tracktwoMVA_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I
    || HLT_tau40_medium1_tracktwoEF_tau35_medium1_tracktwoEF || HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25 || HLT_tau40_mediumRNN_tracktwoMVA_tau35_mediumRNN_tracktwoMVA || HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
  if(!passtrigger) return false;
  cut_flow.fill("pass trigger");
*/  
  if(!tau_0_trig_trigger_matched || !tau_1_trig_trigger_matched) return false;
  cut_flow.fill("trigger matching");
  if((tau_1_allTrk_n!=1 && tau_1_allTrk_n!=3) || (tau_0_allTrk_n!=1 && tau_0_allTrk_n!=3)) return false;
  cut_flow.fill("ntrack = 1,3");
  if(!tau_0_ele_bdt_medium_retuned || !tau_1_ele_bdt_medium_retuned) return false;
  cut_flow.fill("ele veto");
  return true;
}

void hadhadtree::defineObjects(){
  met_p4->SetPz(met_sumet);
  weight_mc = weight_mc_d;
  mcChannelNumber = mc_channel_number;
  definetaus();
  definejets();
}

void hadhadtree::calcGeneralWeight(){
  float jetSFs = 
    jet_NOMINAL_central_jets_global_effSF_JVT*
    jet_NOMINAL_central_jets_global_ineffSF_JVT*
    jet_NOMINAL_forward_jets_global_effSF_JVT*
    jet_NOMINAL_forward_jets_global_ineffSF_JVT*
    jet_NOMINAL_global_effSF_MV2c10*
    jet_NOMINAL_global_ineffSF_MV2c10;
  float tauSF = 
    tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
    tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
    tau_0_NOMINAL_TauEffSF_reco*
    tau_1_NOMINAL_TauEffSF_reco*
    tau_0_NOMINAL_TauEffSF_selection*
    tau_1_NOMINAL_TauEffSF_selection;
  generalweight = isData?1:weight_mc*NOMINAL_pileup_combined_weight*jetSFs*tauSF;
  if(debug){
    printf("event: %llu\n",eventNumber);
    printf("weight_mc: %f\n",weight_mc);
    printf("weight_pileup: %f\n",NOMINAL_pileup_combined_weight);
    printf("tauSF_noID: %f\n",tauSF);
    printf("jetSFs: %f\n",jetSFs);
  }
}


void hadhadtree::fill_fcnc(TString region, int nprong, TString sample, bool taubtag, TString NPname){
  //if(taubtag) {
  //  if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[1]).Data(), sample.Data());
  //  fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[1]);
  //}else{
  if(!taubtag) {
    fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_veto" + bwps[1], NPname);
  }
}
