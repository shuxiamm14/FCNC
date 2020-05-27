#define hadhadtree_cxx
#include "hadhadtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "fcnc_include.h"
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
  if(reduce == 3 && doBDT) fcnc_plots->add(100,-1.,1.,"BDT discriminant","BDTG_train",&BDTG_train,false,"");
  if(reduce == 3 && doBDT) fcnc_plots->add(100,-1.,1.,"BDT discriminant","BDTG_test",&BDTG_test,false,"");
  fcnc_plots->add(100,40.,140.,"p_{T,lead-#tau}","taupt_0",&tau_pt_0,false,"GeV");
  fcnc_plots->add(100,30.,80.,"p_{T,sublead-#tau}","taupt_1",&tau_pt_1,false,"GeV");
  fcnc_plots->add(100,15.,115.,"E^{T}_{miss}","etmiss",&etmiss,false,"GeV");
  fcnc_plots->add(60,0.,3.,"#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss",&dphitauetmiss,false);
  fcnc_plots->add(80,50.,130.,"m_{#tau#tau,vis}","ttvismass",&ttvismass,false,"GeV");
  fcnc_plots->add(100,0.4,3.4,"#DeltaR(#tau,#tau)","drtautau",&drtautau,false,"");
  fcnc_plots->add(80,0.2,4.2,"#DeltaR(#tau,#light-jet,min)","drtaujmin",&drtaujmin,false,"");
  fcnc_plots->add(60,-1.5,1.5,"E^{T}_{miss} centrality","phicent",&phicent,false,"");
  fcnc_plots->add(900,100.,1000.,"m_{t,SM}","t1mass",&t1mass,false,"GeV");
  fcnc_plots->add(100,70.,170.,"m_{#tau,#tau}","tautaumass",&tautaumass,false,"GeV");
  fcnc_plots->add(100,30.,530.,"m_{W}","wmass",&wmass,false,"GeV");
  fcnc_plots->add(400,100.,500.,"m_{t,FCNC}","t2mass",&t2mass,false,"GeV");
  //fcnc_plots->add(100,50.,250.,"P_{t,#tau#tau,vis}","tautauvispt",&tautauvispt,false,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,false,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{t,SM,vis}","t1vismass",&t1vismass,false,"GeV");
  fcnc_plots->add(80,0.2,1.,"E_{vis-#tau,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
  fcnc_plots->add(80,0.2,1.,"E_{vis-#tau,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
  fcnc_plots->add(60,-13.,17.,"#chi^2","chi2",&chi2,false,"");
  fcnc_plots->add(500,0.,1000.,"m_{all}","allmass",&allmass,false,"GeV");
  fcnc_plots->add(500,0.,1000.,"P_{z,all}","allpz",&allpz,false,"GeV");
  //fcnc_plots->add(100,0.,5.,"#eta_{#tau,max}","etamax",&etamax,false,"");
  //fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,fcnc-j)","drtauj",&drtauj,false,"");
  for (int j = 0; j < fcnc_regions.size(); ++j)
  {
    for (int k = 0; k < 2; ++k)
    {
      for (int iptbin = 0; iptbin < 2; ++iptbin)
      {
        if(debug) printf("adding region: %s\n", (fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[1]).Data());
        //fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[1]);
        fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[1]);
      }
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

void hadhadtree::Loop(TTree* inputtree, TString samplename, float globalweight)
{
  if(!inputtree) {
    printf("ERROR: input tree is empty\n");
    exit(0);
  }
  if(debug && dohist) for (int iNP = 0; iNP < plotNPs.size(); ++iNP) fcnc_plots->show();
  int campaign = 0;
  if(isData) {
    campaign = samplename.Contains("1516") ? 1: (samplename.Contains("17")? 2:3);
  }else{
    campaign = samplename.Contains("mc16a") ? 1: (samplename.Contains("mc16d")? 2:3);
  }
  belong_regions.clear();
  if(reduce > 1) belong_regions.add(inputtree->GetName());
  reduce -= 1;
  Init(inputtree);
  reduce += 1;
  if(reduce == 2 && fitvec.size() == 0) initFit();
  map < TString, bool > ::iterator iter;
  if(debug) printf("reduce scheme: %d\n", reduce);
  if (inputtree == 0) return;
  Long64_t nentries = inputtree->GetEntriesFast();
  TString sample = samplename.Contains("data")? "data":samplename.Remove(0,6).Data();
  if (dumptruth) {
    for (int i = 0; i < 3; ++i) {
      filetruth[i][0].open(CharAppend("hadhad", i + 2) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
      filetruth[i][1].open(CharAppend("hadhad", i + 2) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
    }
  }
  int nloop = debug ? min((Long64_t)1000,nentries) : nentries;
  float ngluon = 0;
  fstream signalevtnb;
  if(samplename.Contains("fcnc")) signalevtnb.open((samplename+"_evt.txt").Data(), fstream:: in | fstream::out | fstream::app);
  printf("nentries: %d\n", nloop);
  if(nentries == 0) return;
  float droppedweight = 0;
  cut_flow.sample = samplename;
  cut_flow.region = reduce==1? "all" : (inputtree->GetName());
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    cut_flow.newEvent();
    inputtree->GetEntry(jentry);
    //if(mc_channel_number == 411172 || mc_channel_number == 411173 || mc_channel_number == 411176 || mc_channel_number == 411177)
    //  continue;
    if ((jentry % 100000 == 0) || debug)
      std::cout << " I am here event " << jentry << " Event " << eventNumber << " Run " << run_number << " ismc " << mc_channel_number << " Filled events "<< ifill<<std::endl;
/*
    if(year == 2015) passtrigger = HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM || HLT_tau35_loose1_tracktwo_tau25_loose1_tracktwo;
    if(year == 2016) passtrigger = HLT_tau35_loose1_tracktwo_tau25_loose1_tracktwo || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo || HLT_tau80_medium1_TAU60_tau50_medium1_L1TAU12 || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo;
    if(year == 2017) passtrigger = HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25 || HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25 || HLT_tau40_medium1_tracktwo_tau35_medium1_tracktwo
      || HLT_tau80_medium1_tracktwo_L1TAU60_tau50_medium1_tracktwo_L1TAU12 || HLT_tau80_medium1_tracktwo_L1TAU60_tau35_medium1_tracktwo_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I || HLT_tau80_medium1_tracktwo_L1TAU60_tau50_medium1_tracktwo_L1TAU12 || HLT_tau80_medium1_tracktwo_L1TAU60_tau35_medium1_tracktwo_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I || HLT_tau80_medium1_tracktwo_L1TAU60_tau60_medium1_tracktwo_L1TAU40;
    if(year == 2018) passtrigger = HLT_tau80_medium1_tracktwoEF_L1TAU60_tau60_medium1_tracktwoEF_L1TAU40 || HLT_tau80_medium1_tracktwoEF_L1TAU60_tau35_medium1_tracktwoEF_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I || HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau60_mediumRNN_tracktwoMVA_L1TAU40 || HLT_tau80_mediumRNN_tracktwoMVA_L1TAU60_tau35_mediumRNN_tracktwoMVA_L1TAU12IM_L1TAU60_DR_TAU20ITAU12I
      || HLT_tau40_medium1_tracktwoEF_tau35_medium1_tracktwoEF || HLT_tau35_medium1_tracktwoEF_tau25_medium1_tracktwoEF_L1DR_TAU20ITAU12I_J25 || HLT_tau40_mediumRNN_tracktwoMVA_tau35_mediumRNN_tracktwoMVA || HLT_tau35_mediumRNN_tracktwoMVA_tau25_mediumRNN_tracktwoMVA_L1DR_TAU20ITAU12I_J25;
    if(!passtrigger) continue;
*/
//===============================SFs and weights===============================
    Float_t lepton_SF = 0;
    if(reduce == 1){
      belong_regions.clear();
      float jetSFs = 
        jet_NOMINAL_central_jets_global_effSF_JVT*
        jet_NOMINAL_central_jets_global_ineffSF_JVT*
        jet_NOMINAL_forward_jets_global_effSF_JVT*
        jet_NOMINAL_forward_jets_global_ineffSF_JVT*
        jet_NOMINAL_global_effSF_MV2c10*
        jet_NOMINAL_global_ineffSF_MV2c10;
      float weight_pileup = NOMINAL_pileup_combined_weight;
      weight = isData?1:weight_mc*weight_pileup*jetSFs*globalweight;
      if(weight == 0) continue;
      cut_flow.fill("n-tuple");
      if(!tau_0_trig_trigger_matched || !tau_1_trig_trigger_matched) continue;
      cut_flow.fill("trigger matching");
      if((tau_1_allTrk_n!=1 && tau_1_allTrk_n!=3) || (tau_0_allTrk_n!=1 && tau_0_allTrk_n!=3)) continue;
      cut_flow.fill("ntrack = 1,3");
      if(!isData/*This is wrong but eveto is buggy for data, waiting for new n-tuples*/ && (!tau_0_ele_bdt_medium_retuned || !tau_1_ele_bdt_medium_retuned)) continue;
      cut_flow.fill("ele veto");
      if(fabs(weight) > 5) {
        droppedweight+=weight;
        continue;
      }
      lepton_SF = 
        tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
        tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
        tau_0_NOMINAL_TauEffSF_reco*
        tau_1_NOMINAL_TauEffSF_reco*
        tau_0_NOMINAL_TauEffSF_selection*
        tau_1_NOMINAL_TauEffSF_selection;
      definetaus();
      definejets();
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau1b2jss");
      if(tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1mtau1ltau1b2jss");
      if(!tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ltau1b2jss");
      if(tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ttau1b2jss");
      if(tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1ttau1mtau1b2jss");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau1b3jss");
      if(tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1mtau1ltau1b3jss");
      if(!tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ltau1b3jss");
      if(tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2ttau1b3jss");
      if(tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg1ttau1mtau1b3jss");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau1b2jos");
      if(tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1mtau1ltau1b2jos");
      if(!tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ltau1b2jos");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau1b3jos");
      if(tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1mtau1ltau1b3jos");
      if(!tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ltau1b3jos");
      if(tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ttau1b2jos");
      if(tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1ttau1mtau1b2jos");
      if(tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2ttau1b3jos");
      if(tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg1ttau1mtau1b3jos");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau2b2jss");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1) belong_regions.add("reg2mtau2b3jss");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && ljets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau2b2jos");
      if(tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && ljets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1) belong_regions.add("reg2mtau2b3jos");

      if(belong_regions.isEmpty()) continue;

      cut_flow.fill("SR+CR");
      if(debug){
        printf("event: %llu\n",eventNumber);
        printf("weight_mc: %f\n",weight_mc);
        printf("weight_pileup: %f\n",weight_pileup);
        printf("lepton_SF: %f\n",lepton_SF);
        printf("jetSFs: %f\n",jetSFs);
        printf("globalweight: %f\n",globalweight);
      }
      tau_pt_0 = taus_p4->at(0)->Pt();
      tau_pt_1 = taus_p4->at(1)->Pt();
    }else{
      weight = weights->at(0);
    }
    //===============================pre-selections===============================
    if(reduce == 2) {
      cut_flow.fill("this region");
      if(!isData && sample.Contains("fcnc") && !(abs(taus_matched_pdgId->at(0)) == 15 && abs(taus_matched_pdgId->at(1)) == 15)) continue;
      cut_flow.fill("Only real tau");
      if(campaign !=1 && ljets_p4->at(0)->Pt() < 50 && bjets_p4->at(0)->Pt() < 50) continue;
      cut_flow.fill("year1718 Jet pt<50");
      bool passbjetcut = 0;
      for(auto bjet : *bjets_p4){
        if(bjet->Pt() > 30 && abs(bjet->Eta()) < 2.5) passbjetcut = 1;
      }
      if(!passbjetcut) continue;
      cut_flow.fill("bjet pt>30 eta<2.5");
      etmiss = met_p4->Pt();
      ttvismass = (*(taus_p4->at(0)) + *(taus_p4->at(1))).M();
      dphitauetmiss = fabs(met_p4->DeltaPhi(*(taus_p4->at(0)) + *(taus_p4->at(1))));
      drtautau = taus_p4->at(0)->DeltaR(*(taus_p4->at(1)));
      drtaujmin = 999;
      for(auto jetp4 : *ljets_p4){
        if(drtaujmin > (*(taus_p4->at(0)) + *(taus_p4->at(1))).DeltaR(*jetp4))
          drtaujmin = (*(taus_p4->at(0)) + *(taus_p4->at(1))).DeltaR(*jetp4);
      }
      if(ttvismass < 50) continue;
      cut_flow.fill("$m_{\\tau\\tau$,vis}>50");
      if(ttvismass > 130) continue;
      cut_flow.fill("$m_{\\tau\\tau$,vis}<130");
      if(drtautau > 3.4) continue;
      cut_flow.fill("\\Delta R(\\tau,\\tau)>3.4");
  
      phicent = phi_centrality(taus_p4->at(0)->Phi(),taus_p4->at(1)->Phi(),met_p4->Phi());

      ljet_indice = findcjet();
  
      gMinside->mnparm(0, "v1pt",  tau_pt_0, 0.01, 0., 1000, ierflg);
      gMinside->mnparm(1, "v1eta", taus_p4->at(0)->Eta(), 0.01, taus_p4->at(0)->Eta()-0.25, taus_p4->at(0)->Eta()+0.25, ierflg);
      gMinside->mnparm(2, "v1phi", taus_p4->at(0)->Phi(), 0.01, taus_p4->at(0)->Phi()-0.25, taus_p4->at(0)->Phi()+0.25, ierflg);
      gMinside->mnparm(3, "v2pt",  tau_pt_1, 0.01, 0., 1000, ierflg);
      gMinside->mnparm(4, "v2eta", taus_p4->at(1)->Eta(), 0.01, taus_p4->at(1)->Eta()-0.25, taus_p4->at(1)->Eta()+0.25, ierflg);
      gMinside->mnparm(5, "v2phi", taus_p4->at(1)->Phi(), 0.01, taus_p4->at(1)->Phi()-0.25, taus_p4->at(1)->Phi()+0.25, ierflg);
  
      gMinside->SetObjectFit((TObject*)&fitvec);

      arglist[0] = 1000;
      arglist[1] = 0;
      double val[6],err[6];
      gMinside->mnexcm("MIGRADE", arglist, 2, ierflg);

      Double_t fmin,edm,errdef;
      Int_t nvpar,nparx,icstat;
      gMinuit->mnstat(fmin,edm,errdef,nvpar,nparx,icstat);

      chi2 = fmin;
      for (int i = 0; i < 6; ++i) gMinside->GetParameter(i, val[i], err[i]);
  
      TLorentzVector tauv1_v,tauv2_v;
      tauv1_v.SetPtEtaPhiM(val[0], val[1], val[2], 0);
      tauv2_v.SetPtEtaPhiM(val[3], val[4], val[5], 0);
      if(ljets_p4->size()>=3){
        t1mass = (*(ljets_p4->at(ljet_indice[1])) + *(ljets_p4->at(ljet_indice[2])) + *(bjets_p4->at(0))).M();
        wmass = (*(ljets_p4->at(ljet_indice[1])) + *(ljets_p4->at(ljet_indice[2]))).M();
      }else{
        t1mass = (*(ljets_p4->at(ljet_indice[0])) + *(ljets_p4->at(ljet_indice[1])) + *(bjets_p4->at(0))).M();
        wmass = (*(ljets_p4->at(ljet_indice[0])) + *(ljets_p4->at(ljet_indice[1]))).M();
      }
      t2mass = (*(ljets_p4->at(ljet_indice[0])) + *(taus_p4->at(0)) + *(taus_p4->at(1)) + tauv1_v + tauv2_v).M();
      tautaumass = (*(taus_p4->at(0)) + *(taus_p4->at(1)) + tauv1_v + tauv2_v).M();
      TLorentzVector all = *(ljets_p4->at(ljet_indice[0])) + *(taus_p4->at(0)) + *(taus_p4->at(1)) + tauv1_v + tauv2_v + ( ljets_p4->size() == 2? *(ljets_p4->at(ljet_indice[1])) : *(ljets_p4->at(ljet_indice[1])) + *(ljets_p4->at(ljet_indice[2])) );
      allmass = all.M();
      allpz = all.Pz();
      x1fit = 1 - tauv1_v.E() / (*(taus_p4->at(0)) + tauv1_v).E();
      x2fit = 1 - tauv2_v.E() / (*(taus_p4->at(1)) + tauv2_v).E();
  
    }
    if(reduce == 3){
      if(belong_regions.have("3j")) {
        BDTG_test = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2) );
        BDTG_train = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)) );
      }
      if(belong_regions.have("2j")) {
        BDTG_test = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2) );
        BDTG_train = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)) );
      }
      if(belong_regions.have("reg2mtau1b3jos") || belong_regions.have("reg2mtau1b2jos")) if(samplename.Contains("fcnc") && BDTG_test > 0.5) signalevtnb<<mc_channel_number<<" "<<eventNumber<<endl;
    }
    TString tauorigin;
    int faketau = -1;
    if (sample.Contains("data")) {
      tauorigin = "data";
      sample = "data";
      tauabspdg = 0;
    } else {
      if(reduce <= 2){
        tauabspdg = (abs(taus_matched_pdgId->at(0)) == 15 && abs(taus_matched_pdgId->at(1)) == 15) ? 15 :
          (
            abs(taus_matched_pdgId->at(0)) == 15 ? abs(taus_matched_pdgId->at(1)) : abs(taus_matched_pdgId->at(0))
          );
        if(abs(taus_matched_pdgId->at(0)) != 15 && abs(taus_matched_pdgId->at(1)) != 15) {
          tauabspdg = 14;
          faketau = 2;
        }
        else if (abs(taus_matched_pdgId->at(0)) == 15) faketau = 1;
        else faketau = 0;
      }
      if (tauabspdg == 15) tauorigin = sample + "_real";
      else if (tauabspdg == 13 || tauabspdg == 11) tauorigin = sample + "_lep";
      else if (tauabspdg == 5) tauorigin = sample + "_b";
      else if (tauabspdg == 4) tauorigin = sample + "_c";
      else if (tauabspdg ==21) tauorigin = sample + "_g";
      else if (tauabspdg <= 3 && tauabspdg >=1) tauorigin = sample + "_j";
      else if (tauabspdg == 14) tauorigin = sample + "_doublefake";
      else tauorigin = sample + "_nomatch";
    }
    if(debug) printf("fill hist\n");
    if (dohist) readweightsysmap(mc_channel_number,"xTFW");
    for (auto region: belong_regions.all()) {
      if(debug) printf("fill region: %s\n", region.Data());
      if(reduce == 1){
        weights->clear();
        if(!isData){
          Float_t trig_SF = 1;
          if(!region.Contains("ttau")){
            if(tau_0_jet_bdt_medium){
              lepton_SF *= tau_0_NOMINAL_TauEffSF_JetBDTmedium;
              trig_SF *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
            }else{
              lepton_SF *= tau_0_NOMINAL_TauEffSF_JetBDTloose;
              trig_SF *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
            }
            if(tau_1_jet_bdt_medium){
              lepton_SF *= tau_1_NOMINAL_TauEffSF_JetBDTmedium;
              trig_SF *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
            }else{
              lepton_SF *= tau_1_NOMINAL_TauEffSF_JetBDTloose;
              trig_SF *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE;
            }
          }else{
            if(tau_0_jet_bdt_tight){
              lepton_SF *= tau_0_NOMINAL_TauEffSF_JetBDTtight;
              trig_SF *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
            }else{
              lepton_SF *= tau_0_NOMINAL_TauEffSF_JetBDTmedium;
              trig_SF *= tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
            }
            if(tau_1_jet_bdt_tight){
              lepton_SF *= tau_1_NOMINAL_TauEffSF_JetBDTtight;
              trig_SF *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT;
            }else{
              lepton_SF *= tau_1_NOMINAL_TauEffSF_JetBDTmedium;
              trig_SF *= tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM;
            }
          }
          weight *= lepton_SF*trig_SF;
          addweights(weight,"NOMINAL");
          vector<float> vtaupt;
          vector<int> vtauprong;
          vector<int> vtaupdg;
          for (int i = 0; i < taus_p4->size(); ++i)
          {
            vtaupt.push_back(taus_p4->at(i)->Pt());
            vtauprong.push_back(taus_n_charged_tracks->at(i));
            vtaupdg.push_back(fabs(taus_matched_pdgId->at(i)));
          }
          calcfakesf_pdg(vtaupdg,vtaupt,vtauprong);
          if(nominaltree){
            if(!addWeightSys()) continue;
            if(!AddTheorySys()) {
              printf("Warning: cannot add weight systematics\n");
              continue;
            }
          }
        }else{
          addweights(1,"NOMINAL");
        }
      }
      if (writetree){
        if(outputtree.find(region) != outputtree.end()){
          outputtree[region]->Fill();
        }
        else{
          printf("Error: outputtree cannot find: %s\n", region.Data());
          for(auto itertmp : outputtree){
            printf("output tree list: %s\n", itertmp.first.Data());
          }
          exit(1);
        }
      }
      if (dohist) {
        if(!isData)
          for (int iNP = 0; iNP < plotNPs.size(); ++iNP)
          {
            std::vector<TString>::iterator it = std::find(weightsysmap[mc_channel_number].begin(), weightsysmap[mc_channel_number].end(), plotNPs[iNP]);
            int index = 2;
            if(it != weightsysmap[mc_channel_number].end()) index = std::distance(weightsysmap[mc_channel_number].begin(), it);
            else continue;
            if(index<3) weight = weights->at(index);
            else weight = weights->at(2) * weights->at(index);
            fill_fcnc(region, taus_n_charged_tracks->at(1), tauorigin, tau_pt_1 > 35, taus_b_tagged->at(1),plotNPs[iNP]);
          }
        else
            fill_fcnc(region, taus_n_charged_tracks->at(1), tauorigin, tau_pt_1 > 35, taus_b_tagged->at(1),"NOMINAL");
      }
      if(debug == 2) printf("finish hist\n");
    }
    ifill ++;
  }
  printf("dropped events total weight: %f\n", droppedweight);
  printf("%s \n", inputtree->GetName());
  cut_flow.print();
  cut_flow.save(20);
  cut_flow.clear();
}

void hadhadtree::fill_fcnc(TString region, int nprong, TString sample, int iptbin, bool taubtag, TString NPname){
  //if(taubtag) {
  //  if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[1]).Data(), sample.Data());
  //  fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[1]);
  //}else{
  if(!taubtag) {
    fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[1], NPname);
  }
}
