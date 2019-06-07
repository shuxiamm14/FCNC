
#define hadhadtree_cxx
#include "hadhadtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "fcnc_include.h"


hadhadtree::hadhadtree() : nominal::nominal(){
  defGeV(1);
  hadcutflow.set_weight(&weight);
}

void hadhadtree::init_reduce2(){
  taus_n_charged_tracks = new vector<UInt_t> ();
  taus_b_tagged = new vector<Int_t> ();
}

void hadhadtree::init_reduce1(){
  reduce = 1;
  weights = new vector<double> ();
  taus_id = new vector<Int_t> ();
  taus_b_tagged = new vector<Int_t> ();
  taus_decay_mode = new vector<UInt_t> ();
  taus_matched_mother_pdgId = new vector<Int_t> ();
  taus_matched_mother_status = new vector<Int_t> ();
  taus_matched_p4 = new vector<TLorentzVector*>();
  taus_matched_pdgId = new vector<Int_t> ();
  taus_matched_vis_p4 = new vector<TLorentzVector*>();
  taus_n_charged_tracks = new vector<UInt_t> ();
  taus_p4 = new vector<TLorentzVector*>();
  taus_q = new vector<Float_t> ();
  bjets_fjvt = new vector<Float_t> ();
  bjets_is_Jvt_HS = new vector<Int_t> ();
  bjets_jvt = new vector<Float_t> ();
  bjets_origin = new vector<Int_t> ();
  bjets_p4 = new vector<TLorentzVector*>;
  bjets_type = new vector<Int_t> ();
  bjets_width = new vector<Float_t> ();
  bjets_wztruth_p4 = new vector<TLorentzVector*>();
  bjets_wztruth_pdgid = new vector<Float_t> ();
  jets_fjvt = new vector<Float_t> ();
  jets_is_Jvt_HS = new vector<Int_t> ();
  jets_jvt = new vector<Float_t> ();
  jets_origin = new vector<Int_t> ();
  jets_p4 = new vector<TLorentzVector*>();
  jets_q = new vector<Float_t> ();
  jets_type = new vector<Int_t> ();
  jets_width = new vector<Float_t> ();
  jets_wztruth_p4 = new vector<TLorentzVector*>();
  jets_wztruth_pdgid = new vector<Float_t> ();

}

void hadhadtree::init_hist(TString histfilename){
  //init histSaver here:
  dohist = 1;
  TString nprong[] = {"1prong","3prong"};
  if(reduce == 3){
    initMVA("reg2mtau1b3jos");
    initMVA("reg2mtau1b2jos");
  }
  for (int iNP = 0; iNP < plotNPs.size(); ++iNP)
  {
    fcnc_plots.push_back(new histSaver(histfilename + "_" + char(plotNPs[iNP] + '0') ));
    fcnc_plots[iNP]->SetLumiAnaWorkflow("#it{#sqrt{s}} = 13TeV,  fb^{-1}","FCNC tqH H#rightarrow tautau","Internal");
    fcnc_plots[iNP]->set_weight(&weight);
    fcnc_plots[iNP]->debug = debug;
    if(reduce == 3 && doBDT) fcnc_plots[iNP]->add(100,-1.,1.,"BDT discriminant","BDTG_train",&BDTG_train,false,"");
    if(reduce == 3 && doBDT) fcnc_plots[iNP]->add(100,-1.,1.,"BDT discriminant","BDTG_test",&BDTG_test,false,"");
    fcnc_plots[iNP]->add(100,40.,140.,"p_{T,lead-#tau}","tau_0_pt",&tau_pt_0,false,"GeV");
    fcnc_plots[iNP]->add(100,30.,80.,"p_{T,sublead-#tau}","tau_1_pt",&tau_pt_1,false,"GeV");
    fcnc_plots[iNP]->add(100,15.,115.,"E^{T}_{miss}","etmiss",&etmiss,false,"GeV");
    fcnc_plots[iNP]->add(60,0.,3.,"#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss",&dphitauetmiss,false);
    fcnc_plots[iNP]->add(80,50.,130.,"m_{#tau#tau,vis}","ttvismass",&ttvismass,false,"GeV");
    fcnc_plots[iNP]->add(100,0.4,3.4,"#DeltaR(#tau,#tau)","drtautau",&drtautau,false,"");
    fcnc_plots[iNP]->add(100,0.2,5.2,"#DeltaR(#tau,#light-jet,min)","drtaujmin",&drtaujmin,false,"");
    fcnc_plots[iNP]->add(60,-1.5,1.5,"E^{T}_{miss} centrality","phicent",&phicent,false,"");
    fcnc_plots[iNP]->add(900,100.,1000.,"m_{t,SM}","t1mass",&t1mass,false,"GeV");
    fcnc_plots[iNP]->add(100,50.,150.,"m_{#tau,#tau}","tautaumass",&tautaumass,false,"GeV");
    fcnc_plots[iNP]->add(100,30.,530.,"m_{W}","wmass",&wmass,false,"GeV");
    fcnc_plots[iNP]->add(900,100.,1000.,"m_{t,FCNC}","t2mass",&t2mass,false,"GeV");
    //fcnc_plots[iNP]->add(100,50.,250.,"P_{t,#tau#tau,vis}","tautauvispt",&tautauvispt,false,"GeV");
    //fcnc_plots[iNP]->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,false,"GeV");
    //fcnc_plots[iNP]->add(100,50.,250.,"m_{t,SM,vis}","t1vismass",&t1vismass,false,"GeV");
    fcnc_plots[iNP]->add(100,0.,1.,"E_{vis-#tau,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
    fcnc_plots[iNP]->add(100,0.,1.,"E_{vis-#tau,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
    //fcnc_plots[iNP]->add(100,0.,5.,"#eta_{#tau,max}","etamax",&etamax,false,"");
    //fcnc_plots[iNP]->add(100,0.,5.,"#DeltaR(#tau,fcnc-j)","drtauj",&drtauj,false,"");
    for (int j = 0; j < fcnc_regions.size(); ++j)
    {
      for (int k = 0; k < 2; ++k)
      {
        for (int iptbin = 0; iptbin < 2; ++iptbin)
        {
          if(debug) printf("adding region: %s\n", (fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[1]).Data());
          //fcnc_plots[iNP]->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[1]);
          fcnc_plots[iNP]->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[1]);
        }
      }
    }
  }
}

void hadhadtree::init_sample(TString sample, TString sampletitle){
//==========================init output n-tuple==========================
  if(writetree){
    gSystem->mkdir(TString(PACKAGE_DIR) + "/data/hadhadreduce" + char('0' + reduce) + "/" + SystematicsName);
    outputtreefile = new TFile(TString(PACKAGE_DIR) + "/data/hadhadreduce" + char('0' + reduce) + "/" + SystematicsName + "/" + sample + "_tree.root","recreate");
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
      fcnc_plots[0]->init_sample("data","data","data",kBlack);
      initdata = 1;
    }else{
      sample.Remove(0,6);
      for (int iNP = 0; iNP < plotNPs.size(); ++iNP)
      {
        fcnc_plots[iNP]->init_sample(sample + "_g",sample + "_g_NP" + char('0' + plotNPs[iNP]),sampletitle + "(gluon fake #tau)",(enum EColor)7);
        fcnc_plots[iNP]->init_sample(sample + "_j",sample + "_j_NP" + char('0' + plotNPs[iNP]),sampletitle + "(light-jet fake #tau)",kBlue);
        fcnc_plots[iNP]->init_sample(sample + "_b",sample + "_b_NP" + char('0' + plotNPs[iNP]),sampletitle + "(b-jets fake #tau)",kViolet);
        fcnc_plots[iNP]->init_sample(sample + "_lep",sample + "_lep_NP" + char('0' + plotNPs[iNP]),sampletitle + "(lepton fake #tau)",kGreen);
        fcnc_plots[iNP]->init_sample(sample + "_real",sample + "_real_NP" + char('0' + plotNPs[iNP]),sampletitle + "(real #tau)",kRed);
        fcnc_plots[iNP]->init_sample(sample + "_c",sample + "_c_NP" + char('0' + plotNPs[iNP]),sampletitle + "(c-jets fake #tau)",kOrange);
        fcnc_plots[iNP]->init_sample(sample + "_nomatch",sample + "_nomatch_NP" + char('0' + plotNPs[iNP]),sampletitle + "(no truth matched fake #tau)",kGray);
        fcnc_plots[iNP]->init_sample(sample + "_doublefake",sample + "_doublefake_NP" + char('0' + plotNPs[iNP]),sampletitle + "(no truth matched fake #tau)",kGray);
      } 
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
  if(debug && dohist) for (int iNP = 0; iNP < plotNPs.size(); ++iNP) fcnc_plots[iNP]->show();
  isData = samplename.Contains("data");
  int campaign = 0;
  if(isData) {
    campaign = samplename.Contains("1516") ? 1: (samplename.Contains("17")? 2:3);
  }else{
    campaign = samplename.Contains("mc16a") ? 1: (samplename.Contains("mc16d")? 2:3);
  }
  bool doweightsys = ((TString)inputtree->GetName() == "NOMINAL")? 1 : 0;
  if(reduce > 1) ifregions[inputtree->GetName()] = 1;
  reduce -= 1;
  Init(inputtree);
  reduce += 1;
  map < TString, bool > ::iterator iter;
  if(debug) printf("reduce scheme: %d\n", reduce);
  if (reduce > 1) {
    ifregions.clear();
    ifregions[inputtree->GetName()] = 1;
  }
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
  gM = initgM();
  fstream signalevtnb;
  if(samplename.Contains("fcnc")) signalevtnb.open((samplename+"_evt.txt").Data(), fstream:: in | fstream::out | fstream::app);
  printf("nentries: %d\n", nloop);
  if(nentries == 0) return;
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    hadcutflow.newEvent();
    inputtree->GetEntry(jentry);
    //if(mc_channel_number == 411172 || mc_channel_number == 411173 || mc_channel_number == 411176 || mc_channel_number == 411177)
    //  continue;
    if ((jentry % 100000 == 0) || debug)
      std::cout << " I am here event " << jentry << " Event " << event_number << " Run " << run_number << " ismc " << mc_channel_number << std::endl;
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
      float jetSFs = 
        jet_NOMINAL_central_jets_global_effSF_JVT*
        jet_NOMINAL_central_jets_global_ineffSF_JVT*
        jet_NOMINAL_forward_jets_global_effSF_JVT*
        jet_NOMINAL_forward_jets_global_ineffSF_JVT*
        jet_NOMINAL_global_effSF_MV2c10*
        jet_NOMINAL_global_ineffSF_MV2c10;
      float weight_pileup = NOMINAL_pileup_combined_weight;
      weight = isData?1:weight_mc*weight_pileup*jetSFs*globalweight;
      hadcutflow.fill();
      if(!tau_0_trig_trigger_matched || !tau_1_trig_trigger_matched) continue;
      hadcutflow.fill();
      if((tau_1_n_charged_tracks!=1 && tau_1_n_charged_tracks!=3) || (tau_0_n_charged_tracks!=1 && tau_0_n_charged_tracks!=3)) continue;
      hadcutflow.fill();
      if(weight > 5) continue;
      lepton_SF = 
        tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
        tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad*
        tau_0_NOMINAL_TauEffSF_reco*
        tau_1_NOMINAL_TauEffSF_reco*
        tau_0_NOMINAL_TauEffSF_selection*
        tau_1_NOMINAL_TauEffSF_selection;
      definetaus();
      definejets();
      ifregions["reg2mtau1b2jss"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg1mtau1ltau1b2jss"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2ltau1b2jss"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2ttau1b2jss"] =      tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg1ttau1mtau1b2jss"] = tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2mtau1b3jss"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg1mtau1ltau1b3jss"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2ltau1b3jss"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2ttau1b3jss"] =      tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg1ttau1mtau1b3jss"] = tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2mtau1b2jos"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg1mtau1ltau1b2jos"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg2ltau1b2jos"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg2mtau1b3jos"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg1mtau1ltau1b3jos"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg2ltau1b3jos"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg2ttau1b2jos"] =      tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg1ttau1mtau1b2jos"] = tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg2ttau1b3jos"] =      tau_0_jet_bdt_tight && tau_1_jet_bdt_tight && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg1ttau1mtau1b3jos"] = tau_0_jet_bdt_tight + tau_1_jet_bdt_tight == 1 && tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;

      ifregions["reg2mtau2b2jss"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2mtau2b3jss"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
      ifregions["reg2mtau2b2jos"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
      ifregions["reg2mtau2b3jos"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 2 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;

      for (auto iter : ifregions)
        if(iter.second == 0 || find(fcnc_regions.begin(),fcnc_regions.end(),iter.first) == fcnc_regions.end())
          ifregions.erase(iter.first);

      if(!ifregions.size()) continue;
      if(debug){
        printf("event: %llu\n",event_number);
        printf("weight_mc: %f\n",weight_mc);
        printf("weight_pileup: %f\n",weight_pileup);
        printf("lepton_SF: %f\n",lepton_SF);
        printf("jetSFs: %f\n",jetSFs);
        printf("globalweight: %f\n",globalweight);
      }
    }else{
      weight = weights->at(0);
    }
    //===============================pre-selections===============================
    if(reduce == 2) {
      hadcutflow.fill();
      if(!isData && sample.Contains("fcnc") && !(abs(taus_matched_pdgId->at(0)) == 15 && abs(taus_matched_pdgId->at(1)) == 15)) continue;
      hadcutflow.fill();
      if(campaign !=1 && jets_p4->at(0)->Pt() < 50 && bjets_p4->at(0)->Pt() < 50) continue;
      hadcutflow.fill();
      bool passbjetcut = 0;
      for(auto bjet : *bjets_p4){
        if(bjet->Pt() > 30 && abs(bjet->Eta()) < 2.5) passbjetcut = 1;
      }
      if(!passbjetcut) continue;
      hadcutflow.fill();
      tau_pt_0 = taus_p4->at(0)->Pt();
      tau_pt_1 = taus_p4->at(1)->Pt();
      etmiss = met_p4->Pt();
      ttvismass = (*(taus_p4->at(0)) + *(taus_p4->at(1))).M();
      dphitauetmiss = fabs(met_p4->DeltaPhi(*(taus_p4->at(0)) + *(taus_p4->at(1))));
      drtautau = taus_p4->at(0)->DeltaR(*(taus_p4->at(1)));
      drtaujmin = 999;
      for(auto jetp4 : *jets_p4){
        if(drtaujmin > (*(taus_p4->at(0)) + *(taus_p4->at(1))).DeltaR(*jetp4))
          drtaujmin = (*(taus_p4->at(0)) + *(taus_p4->at(1))).DeltaR(*jetp4);
      }
      if(ttvismass < 50) continue;
      hadcutflow.fill();
      if(ttvismass > 130) continue;
      hadcutflow.fill();
      if(drtautau > 3.4) continue;
      hadcutflow.fill();
  
      phicent = phi_centrality(taus_p4->at(0)->Phi(),taus_p4->at(1)->Phi(),met_p4->Phi());
  
      ljet_indice = findcjet("hadhad",convertv(*jets_p4),*bjets_p4->at(0),lep_v,convertv(*taus_p4));
  
      gM->mnparm(0, "v1pt",  tau_pt_0, 0.01, 0., 1000, ierflg);
      gM->mnparm(1, "v1eta", taus_p4->at(0)->Eta(), 0.01, taus_p4->at(0)->Eta()-0.25, taus_p4->at(0)->Eta()+0.25, ierflg);
      gM->mnparm(2, "v1phi", taus_p4->at(0)->Phi(), 0.01, taus_p4->at(0)->Phi()-0.25, taus_p4->at(0)->Phi()+0.25, ierflg);
      gM->mnparm(3, "v2pt",  tau_pt_1, 0.01, 0., 1000, ierflg);
      gM->mnparm(4, "v2eta", taus_p4->at(1)->Eta(), 0.01, taus_p4->at(1)->Eta()-0.25, taus_p4->at(1)->Eta()+0.25, ierflg);
      gM->mnparm(5, "v2phi", taus_p4->at(1)->Phi(), 0.01, taus_p4->at(1)->Phi()-0.25, taus_p4->at(1)->Phi()+0.25, ierflg);
  
      taus_v[0] = *taus_p4->at(0);
      taus_v[1] = *taus_p4->at(1);
      mets.SetXYZ(met_p4->Px(), met_p4->Py(), met_sumet);
      gM->SetObjectFit( & forFit);
  
      arglist[0] = 1000;
      arglist[1] = 0;
      double val[6],err[6];
      gM->mnexcm("MIGRADE", arglist, 2, ierflg);
      for (int i = 0; i < 6; ++i) gM->GetParameter(i, val[i], err[i]);
  
      TLorentzVector tauv1_v,tauv2_v;
      tauv1_v.SetPtEtaPhiM(val[0], val[1], val[2], 0);
      tauv2_v.SetPtEtaPhiM(val[3], val[4], val[5], 0);
      if(jets_p4->size()>=3){
        t1mass = (*(jets_p4->at(ljet_indice[1])) + *(jets_p4->at(ljet_indice[2])) + *(bjets_p4->at(0))).M();
        wmass = (*(jets_p4->at(ljet_indice[1])) + *(jets_p4->at(ljet_indice[2]))).M();
      }else{
        t1mass = (*(jets_p4->at(ljet_indice[0])) + *(jets_p4->at(ljet_indice[1])) + *(bjets_p4->at(0))).M();
        wmass = (*(jets_p4->at(ljet_indice[0])) + *(jets_p4->at(ljet_indice[1]))).M();
      }
      t2mass = (*(jets_p4->at(ljet_indice[0])) + *(taus_p4->at(0)) + *(taus_p4->at(1)) + tauv1_v + tauv2_v).M();
      tautaumass = (*(taus_p4->at(0)) + *(taus_p4->at(1)) + tauv1_v + tauv2_v).M();
  
      x1fit = 1 - tauv1_v.E() / (*(taus_p4->at(0)) + tauv1_v).E();
      x2fit = 1 - tauv2_v.E() / (*(taus_p4->at(1)) + tauv2_v).E();
  
    }
    if(reduce == 3){
      if(ifregions["reg2mtau1b3jos"] || ifregions["reg2mtau1b3jss"] || ifregions["reg2mtau2b3jos"] || ifregions["reg2mtau2b3jss"]) {
        BDTG_test = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + event_number%2) );
        BDTG_train = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(event_number%2)) );
      }
      if(ifregions["reg2mtau1b2jos"] || ifregions["reg2mtau1b2jss"] || ifregions["reg2mtau2b2jos"] || ifregions["reg2mtau2b2jss"]) {
        BDTG_test = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + event_number%2) );
        BDTG_train = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(event_number%2)) );
      }
      if(ifregions["reg2mtau1b3jos"] || ifregions["reg2mtau1b2jos"]) if(samplename.Contains("fcnc") && BDTG_test > 0.5) signalevtnb<<mc_channel_number<<" "<<event_number<<endl;
    }
    TString tauorigin;
    int faketau = -1;
    if (sample.Contains("data")) {
      tauorigin = "data";
      sample = "data";
      tauabspdg = 0;
    } else {
      if(reduce == 2){
        tauabspdg = (abs(taus_matched_pdgId->at(0)) == 15 && abs(taus_matched_pdgId->at(1)) == 15) ? 15 :
          (
            abs(taus_matched_pdgId->at(0)) == 15 ? abs(taus_matched_pdgId->at(1)) : abs(taus_matched_pdgId->at(0))
          );
        if(abs(taus_matched_pdgId->at(0)) != 15 && abs(taus_matched_pdgId->at(1)) != 15) tauabspdg = 14;
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
    for (iter = ifregions.begin(); iter != ifregions.end(); iter++) {
      if (iter->second == 1) {
        if(debug) printf("fill region: %s\n", iter->first.Data());
        float savewt = 1;
        if(reduce == 1){
          weights->clear();
          if(!isData){
            Float_t trig_SF = 1;
            if(!iter->first.Contains("ttau")){
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
          }
          weights->push_back(weight); //nominal
          if(nominaltree){
            if(faketau >=0 && sample.Contains("top")){
              int prongbin = taus_n_charged_tracks->at(faketau) == 3;
              int ptbin;
              double faketaupt = taus_p4->at(faketau)->Pt();
              if(prongbin == 0) {
                if(faketaupt<45) ptbin = 0;
                else if(faketaupt < 70) ptbin = 1;
                else ptbin = 2;
              }else{
                if(faketaupt<50) ptbin = 0;
                else if(faketaupt < 75) ptbin = 1;
                else ptbin = 2;
              }
              weights->push_back(fakeSFML[prongbin][ptbin]);
            }else{
              weights->push_back(1);
            } //fake SF, need to be multiplied by weight
            addWeightSys();
          }
        }
        if (writetree){
          if(outputtree.find(iter->first) != outputtree.end()){
            outputtree[iter->first]->Fill();
          }
          else{
            printf("Error: outputtree cannot find: %s\n", iter->first.Data());
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
              weight = weights->at(plotNPs[iNP]);
              fill_fcnc(iter->first, taus_n_charged_tracks->at(1), tauorigin, tau_pt_1 > 35, taus_b_tagged->at(1),plotNPs[iNP]);
            }
          else
              fill_fcnc(iter->first, taus_n_charged_tracks->at(1), tauorigin, tau_pt_1 > 35, taus_b_tagged->at(1),0);
        }
        if(debug == 2) printf("finish hist\n");
      }
    }
  }
  if (writetree) {
    outputtreefile->cd();
    for (auto itertmp : outputtree)
      itertmp.second->Write(itertmp.first, TObject::kWriteDelete);
  }
  if(reduce <=2){
    printf("%s \n", inputtree->GetName());
    hadcutflow.print();
    hadcutflow.clear();
  }
}

void hadhadtree::fill_fcnc(TString region, int nprong, TString sample, int iptbin, bool taubtag, int iNP){
  //if(taubtag) {
  //  if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[1]).Data(), sample.Data());
  //  fcnc_plots[iNP]->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[1]);
  //}else{
  if(!taubtag) {
    fcnc_plots[iNP]->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[1]);
  }
}

// input parameter _p in GeV (>25 GeV)

void hadhadtree::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {

  TList *listforfit = (TList*) gM->GetObjectFit();
  if (!listforfit)
  {
    printf("list isnt found\n");
    exit(1);
  }
  enum lorentzv{tau1,tau2};
  
  TLorentzVector vectors[2];
  TLorentzVector neutrino[2];
  for( int i = 0; i<2 ; ++i) {
    if (listforfit->At(i))
    {
      vectors[i] = *((TLorentzVector*)listforfit->At(i));
    }else{
      printf("i-th parameter is not found\n");
      exit(1);
    }
  }
  double met[3];
  if (listforfit->At(5)) {
    met[0] = ((TVector3*)listforfit->At(5))->x();
    met[1] = ((TVector3*)listforfit->At(5))->y();
    met[2] = ((TVector3*)listforfit->At(5))->z();
  }
  else { printf("met parameter is not found\n"); exit(1); }

  neutrino[0].SetPtEtaPhiM(par[0],par[1],par[2],0);
  neutrino[1].SetPtEtaPhiM(par[3],par[4],par[5],0);
  Float_t prob1(0), prob2(0);

  prob1 = getHadTauProb(vectors[tau1].DeltaR(neutrino[0]),(vectors[tau1]+neutrino[0]).P());
  prob2 = getHadTauProb(vectors[tau2].DeltaR(neutrino[1]),(vectors[tau2]+neutrino[1]).P());

  Float_t mass1 = (vectors[tau1]+neutrino[0]).M();
  Float_t mass2 = (vectors[tau2]+neutrino[1]).M();
  Float_t mass = (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]).M();
  Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
  Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
  
  Double_t chisq = 1e10;
  if(prob1>0 && prob2>0) {
    Float_t met_resol = 13.1+0.50*sqrt(met[2]);
    chisq = -2*log(prob1) -2*log(prob2) + pow((mass1-1.777)/1.777,2) + pow((mass2-1.777)/1.777,2) + pow((mass-125)/20,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
  }
  
  f = chisq;
}
TMinuit* hadhadtree::initgM(){

  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);
  return gM;
}
