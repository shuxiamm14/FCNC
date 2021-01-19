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
/*  "reg2mtau1b2jss",
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
    "reg2mtau1b2jss",
    "reg2mtau1b3jss",
    "reg2mtau1b2jos",
    "reg2mtau1b3jos",
    "reg2mtau2b2jss",
    "reg2mtau2b3jss",
    "reg2mtau2b2jos",
    "reg2mtau2b3jos",
    "reg2mtau2b1jos",
    "reg2mtau2b1jss",
    "reg2ltau1b2jss",
    "reg2ltau1b3jss",
    "reg2ltau1b2jos",
    "reg2ltau1b3jos",
    "reg2mtau0b3jos",
    "reg2mtau0b4jos",
    "reg2mtau0b3jss",
    "reg2mtau0b4jss",
    "reg2mtau3jos" ,
    "reg2mtau4jos" ,
    "reg2mtau0b3jss",
    "reg2mtau0b4jss"*/
    "reg2mtau1b2jss",
    "reg2mtau1b2jos",
    "reg2mtau1b3jos",
    "reg2mtau1b3jss",
    "reg1mtau1ltau1b2jos",
    "reg1ltau1mtau1b2jos",
    "reg1mtau1ltau1b3jos",
    "reg1ltau1mtau1b3jos",
    "reg1ltau1ntau1b2jos",
    "reg1ltau1ntau1b3jos",
    "reg1ntau1ltau1b2jos",
    "reg1ntau1ltau1b3jos",
    "reg2ltau1b2jos",
    "reg2ltau1b3jos",
    "reg1mtau1ltau1b2jss",
    "reg1ltau1mtau1b2jss",
    "reg1mtau1ltau1b3jss",
    "reg1ltau1mtau1b3jss",
    "reg1ltau1ntau1b2jss",
    "reg1ltau1ntau1b3jss",
    "reg1ntau1ltau1b2jss",
    "reg1ntau1ltau1b3jss",
    "reg2ltau1b2jss",
    "reg2ltau1b3jss",
    // new
    "reg1lnmtau1mtau1b2jss",
    "reg1lnmtau1mtau1b2jos",
    "reg1lnmtau1mtau1b3jss",
    "reg1lnmtau1mtau1b3jos",
    "reg1mtau1lnmtau1b2jss",
    "reg1mtau1lnmtau1b2jos",
    "reg1mtau1lnmtau1b3jss",
    "reg1mtau1lnmtau1b3jos",
    //"reg2mtau1b5jos",
    //"reg2mtau1b5jss",
    //"reg1mtau1ltau1b5jos",
    //"reg1ltau1mtau1b5jos",
    //"reg1ltau1ntau1b5jos",
    //"reg1ntau1ltau1b5jos",
    //"reg2ltau1b5jos",
  };
}

bool hadhadtree::x0_x1_cut(float& x0,float& x1) { // false ==> cannot pass ====> 被 continue

        float m(0);// x0(0), x1(0);
        if (MassCollinear(true, m, x0, x1)) {
          //  std::cout<<"mass_collinear: "<<"  x0: "<<x0<<",  x1:"<<x1<<std::endl;
                        if (x0 > 1.400000 || x0 < -0.100000) return false;
                        if (x1 > 1.400000 || x1 < -0.100000) return false;
       }
        return true;
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
  fcnc_plots->debug =debug;
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
  fcnc_plots->add(vars["drtaujmin"],&drtaujmin);
  fcnc_plots->add(vars["phicent"],&phicent);
  fcnc_plots->add(vars["t1mass"],&t1mass);
  fcnc_plots->add(vars["tautaumass"],&tautaumass);
  fcnc_plots->add(vars["wmass"],&wmass);
  fcnc_plots->add(vars["t2mass"],&t2mass);
  fcnc_plots->add(vars["tautauvispt"],&tautauvispt);
  fcnc_plots->add(vars["t2vismass"],&t2vismass);
  fcnc_plots->add(vars["t1vismass"],&t1vismass);
  fcnc_plots->add(vars["x1fit"],&x1fit);
  fcnc_plots->add(vars["x2fit"],&x2fit);
  fcnc_plots->add(vars["chi2"],&chi2);
  fcnc_plots->add(vars["leading_bin"],&leading_bin); //
  fcnc_plots->add(vars["subleading_bin"],&subleading_bin); 
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

void hadhadtree::init_sample(TString sample, TString sampletitle){ // in reduce.cc, invoke definetree in hadhad_listfunc.C
//==========================init output n-tuple==========================
  if(reduce == 1){
    // weights = new vector<double> ();
    //taus_id = new vector<Int_t> ();
    taus_decay_mode = new vector<UInt_t> ();
    //taus_matched_mother_pdgId = new vector<Int_t> ();
    taus_matched_mother_status = new vector<Int_t> ();
    taus_matched_p4 = new vector<TLorentzVector*>();
    //taus_matched_pdgId = new vector<Int_t> ();
    taus_matched_vis_p4 = new vector<TLorentzVector*>();
    //taus_n_charged_tracks = new vector<UInt_t> ();
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
  if(writetree){ //reduce=1,2
    TString treedir = dataDir + "/xTFWreduce" + char('0' + reduce);
    gSystem->mkdir(treedir);
    gSystem->mkdir(treedir + "/" + SystematicsName);
    printf("create outputfile: %s\n", (treedir + "/" + SystematicsName + "/" + sample + "_tree.root").Data());
    outputtreefile = new TFile(treedir + "/" + SystematicsName + "/" + sample + "_tree.root","recreate");
    for (int i = 0; i < fcnc_regions.size(); ++i)
    {
      if(debug) printf("init sample:: get region: %s\n",fcnc_regions[i].Data());
      if (outputtreefile->Get(fcnc_regions[i])) {
        outputtree[fcnc_regions[i]] = (TTree*)(outputtreefile->Get(fcnc_regions[i]));
        initRaw(outputtree[fcnc_regions[i]]);// reduce=2  ?????
      }else{
        outputtree[fcnc_regions[i]] = new TTree(fcnc_regions[i],fcnc_regions[i]);
        defineTree(outputtree[fcnc_regions[i]]); //reduce=1  hadhad_listfunc.c 
      }
    }
  }
//==========================init output histogram==========================
  if(dohist){//reduce=3
    if (sample.Contains("data"))
    {
      fcnc_plots->add_sample("data","data",kBlack);
      initdata = 1;
    }else{
      sample.Remove(0,6);
      auto origins = getFakeTauOrigin();
      for(auto origin : origins) fcnc_plots->add_sample(sample + "_" + origin.name,sampletitle + "(" + origin.title + ")",origin.color);
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
  
  //ret *= tau_0_NOMINAL_TauEffSF_JetRNNmedium*tau_1_NOMINAL_TauEffSF_JetRNNmedium;
  /*
  if(region.Contains("2ttau")){
     ret *=tau_0_NOMINAL_TauEffSF_JetRNNtight*tau_1_NOMINAL_TauEffSF_JetRNNtight;
  }
  if(region.Contains("2mtau")){
     ret *=tau_0_NOMINAL_TauEffSF_JetRNNmedium*tau_1_NOMINAL_TauEffSF_JetRNNmedium;
  }
  if(region.Contains("1l1mtau")){
     ret *=tau_0_NOMINAL_TauEffSF_JetRNNmedium*tau_1_NOMINAL_TauEffSF_JetRNNloose;
  }*/

  if(year!=2018){
      ret  *=tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDRNNMEDIUM * tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDRNNMEDIUM;
  }else{
      ret  *=tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwoEF_JETIDRNNMEDIUM * tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwoEF_JETIDRNNMEDIUM;
  }
  return ret;
}

bool hadhadtree::passRegionCut(){
  //cut_flow.fill("this region");

  drtautau = taus_p4->at(0)->DeltaR(*(taus_p4->at(1)));

  /*
  for(auto bjets: *bjets_p4){
    if(bjets->Pt() < 30 || abs(bjets->Eta()) > 2.5) return false;
  }
  cut_flow.fill("bjet pt>30 eta<2.5");
*/
  //if(!isData && samplename.Contains("fcnc") && !(abs(taus_matched_pdgId->at(0)) == 15 && abs(taus_matched_pdgId->at(1)) == 15)) return false;
  //cut_flow.fill("Only real tau");
  return true;
}

void hadhadtree::prepare(){

  if(reduce==1){
    mcChannelNumber = mc_channel_number;
    eventNumber     = event_number;
    runNumber       = run_number;
    tau0RNN=tau_0_jet_rnn_score_trans;
    tau1RNN=tau_1_jet_rnn_score_trans;
    met_sumet=met_sumet_;
    if(isData){
      if(0 < run_number && run_number <= 284484){year=2015;}
      else if(284484 < run_number && run_number <= 311563){year=2016;}
      else if(311563 <= run_number && run_number <= 341649){year=2017;}
      else if(341649 <= run_number){year=2018;}
    }else{
      if(0 < NOMINAL_pileup_random_run_number && NOMINAL_pileup_random_run_number <= 284484){year=2015;}
      else if(284484 < NOMINAL_pileup_random_run_number && NOMINAL_pileup_random_run_number <= 311563){year=2016;}
      else if(311563 < NOMINAL_pileup_random_run_number && NOMINAL_pileup_random_run_number <= 341649){year=2017;}
      else if(341649 < NOMINAL_pileup_random_run_number ){year=2018;}
    }
  }
}

bool hadhadtree::passBasicCut(){

  if(year == 2015)  passtrigger = tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM && tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM;
  if(year == 2016)  passtrigger = tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo && tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
  if(year == 2017)  passtrigger = tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25 && tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25;
  if(year == 2018)  passtrigger = tau_0_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25 && tau_1_trig_HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_03dR30_L1DR_TAU20ITAU12I_J25;
  if(!passtrigger) return false;
  cut_flow.fill("pass trigger");
  
  // bool loose_atleast=tau_0_jet_rnn_loose&&tau_1_jet_rnn_loose;
  // if(!loose_atleast) return false;
  // cut_flow.fill("at least loose");
 
  // if(drtautau > 2.5) return false;
  // cut_flow.fill("$\\Delta R(\\tau,\\tau)$<2.5");

  //if(!tau_0_trig_trigger_matched || !tau_1_trig_trigger_matched) return false;
  //cut_flow.fill("trigger matching");

  if((tau_1_n_charged_tracks!=1 && tau_1_n_charged_tracks!=3) || (tau_0_n_charged_tracks!=1 && tau_0_n_charged_tracks!=3)) return false;
  cut_flow.fill("ntrack = 1,3");

  if(!tau_0_ele_bdt_medium_retuned || !tau_1_ele_bdt_medium_retuned) return false;
  //if(!tau_0_ele_bdt_loose_retuned || !tau_1_ele_bdt_loose_retuned) return false;
  cut_flow.fill("ele veto");

  if(jet_2_p4->Pt() < 1e-5) return false;
  cut_flow.fill("jet num>=3");

  if(tau_0_jet_rnn_score_trans <0.01||tau_1_jet_rnn_score_trans <0.01) return false;
  cut_flow.fill("tau rnn score>=0.01");

  return true;
}

void hadhadtree::defineObjects(){
  met_p4->SetPz(met_sumet);
  weight_mc = weight_mc_d;
  definetaus();
  definejets();
}

void hadhadtree::calcGeneralWeight(){
  float jetSFs = 
    jet_NOMINAL_central_jets_global_effSF_JVT*
    jet_NOMINAL_central_jets_global_ineffSF_JVT*
    jet_NOMINAL_global_effSF_DL1r_FixedCutBEff_70*
    jet_NOMINAL_global_ineffSF_DL1r_FixedCutBEff_70; 
  float tauSF = 
    tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
    tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
    tau_0_NOMINAL_TauEffSF_reco*
    tau_1_NOMINAL_TauEffSF_reco*
    tau_0_NOMINAL_TauEffSF_selection*
    tau_1_NOMINAL_TauEffSF_selection*
    tau_0_NOMINAL_TauEffSF_LooseEleBDT_electron*
    tau_1_NOMINAL_TauEffSF_LooseEleBDT_electron;
  float tauIDSF=1;
  if(tau_0_jet_rnn_medium==1)      tauIDSF*=tau_0_NOMINAL_TauEffSF_JetRNNmedium;  // m
  else if(tau_0_jet_rnn_loose==1)  tauIDSF*=tau_0_NOMINAL_TauEffSF_JetRNNloose;  // nm
  else                             tauIDSF*=1;
  
  if(tau_1_jet_rnn_medium==1)      tauIDSF*=tau_1_NOMINAL_TauEffSF_JetRNNmedium;  // m
  else if(tau_1_jet_rnn_loose==1)  tauIDSF*=tau_1_NOMINAL_TauEffSF_JetRNNloose;  // nm
  else                             tauIDSF*=1;

  generalweight = isData?1:weight_mc_d*NOMINAL_pileup_combined_weight*jetSFs*tauSF*tauIDSF;
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
  //if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[1]).Data(), sample.Data());
  //fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[1]);
  //}else{
  if(!taubtag) {
    fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_veto" + bwps[1], NPname);
  }
}
