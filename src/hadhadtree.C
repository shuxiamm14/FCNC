
#define hadhadtree_cxx
#include "hadhadtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "fcnc_include.h"

hadhadtree::hadhadtree() : nominal::nominal(){
  weights = new vector<Int_t> ();
  taus_id = new vector<Int_t> ();
  taus_b_tagged = new vector<Int_t> ();
  taus_decay_mode = new vector<UInt_t> ();
  taus_matched_mother_pdgId = new vector<Int_t> ();
  taus_matched_mother_status = new vector<Int_t> ();
  taus_matched_p4 = new vector<TLorentzVector>();
  taus_matched_pdgId = new vector<Int_t> ();
  taus_matched_vis_p4 = new vector<TLorentzVector>();
  taus_n_charged_tracks = new vector<UInt_t> ();
  taus_p4 = new vector<TLorentzVector>();
  taus_q = new vector<Float_t> ();
  bjets_fjvt = new vector<Float_t> ();
  bjets_is_Jvt_HS = new vector<Int_t> ();
  bjets_jvt = new vector<Float_t> ();
  bjets_origin = new vector<Int_t> ();
  bjets_p4 = new vector<TLorentzVector>();
  bjets_q = new vector<Float_t> ();
  bjets_type = new vector<Int_t> ();
  bjets_width = new vector<Float_t> ();
  bjets_wztruth_p4 = new vector<TLorentzVector>();
  bjets_wztruth_pdgid = new vector<Float_t> ();
  jets_fjvt = new vector<Float_t> ();
  jets_is_Jvt_HS = new vector<Int_t> ();
  jets_jvt = new vector<Float_t> ();
  jets_origin = new vector<Int_t> ();
  jets_p4 = new vector<TLorentzVector>();
  jets_q = new vector<Float_t> ();
  jets_type = new vector<Int_t> ();
  jets_width = new vector<Float_t> ();
  jets_wztruth_p4 = new vector<TLorentzVector>();
  jets_wztruth_pdgid = new vector<Float_t> ();
}

void hadhadtree::init_hist(TString histfilename){
  //init histSaver here:
  dohist = 1;
  fcnc_plots = new histSaver(histfilename);
  fcnc_plots->set_weight(&weight);
  fcnc_plots->debug = debug;

  //fcnc_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
  fcnc_plots->add(10,25.,125.,"p_{T,lead-#tau}","tau_0_pt",&tau_pt_0,false,"GeV");
  fcnc_plots->add(10,25.,125.,"p_{T,sublead-#tau}","tau_1_pt",&tau_pt_1,false,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{t,SM}","t1mass",&t1mass,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{#tau,#tau}","tautaumass",&tautaumass,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{W}","wmass",&wmass,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{t,FCNC}","t2mass",&t2mass,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{#tau#tau,vis}","ttvismass",&ttvismass,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"P_{t,#tau#tau,vis}","tautauvispt",&tautauvispt,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,true,"GeV");
  //fcnc_plots->add(100,50.,250.,"m_{t,SM,vis}","t1vismass",&t1vismass,true,"GeV");
  //fcnc_plots->add(100,0.,1.,"E_{#nu,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
  //fcnc_plots->add(100,0.,1.,"E_{#nu,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
  //fcnc_plots->add(100,0.,5.,"#eta_{#tau,max}","etamax",&etamax,false,"");
  //fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,fcnc-j)","drtauj",&drtauj,false,"");
  //fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,#tau)","drtautau",&drtautau,false,"");
  //fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,#light-jet,min)","drtaujmin",&drtaujmin,false,"");

  fcnc_regions.push_back("reg2mtau1b2jss");
  fcnc_regions.push_back("reg1mtau1ltau1b2jss");
  fcnc_regions.push_back("reg2ltau1b2jss");
  fcnc_regions.push_back("reg2mtau1b3jss");
  fcnc_regions.push_back("reg1mtau1ltau1b3jss");
  fcnc_regions.push_back("reg2ltau1b3jss");
  fcnc_regions.push_back("reg2mtau1b2jos");
  fcnc_regions.push_back("reg1mtau1ltau1b2jos");
  fcnc_regions.push_back("reg2ltau1b2jos");
  fcnc_regions.push_back("reg2mtau1b3jos");
  fcnc_regions.push_back("reg1mtau1ltau1b3jos");
  fcnc_regions.push_back("reg2ltau1b3jos");

  TString nprong[] = {"1prong","3prong"};
  
  for (int j = 0; j < fcnc_regions.size(); ++j)
  {
    for (int k = 0; k < 2; ++k)
    {
      for (int iptbin = 0; iptbin < 2; ++iptbin)
      {
        if(debug) printf("adding region: %s\n", (fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[1]).Data());
        fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[1]);
        fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[1]);
      }
    }
  }
}

void hadhadtree::init_sample(TString sample, TString sampletitle){
//==========================init output n-tuple==========================
  if(writetree){
    outputtreefile = new TFile(sample + "_tree.root","update");
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
      if(reduce == 1) sample.Remove(0,6);
      fcnc_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      fcnc_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
      fcnc_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
      fcnc_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
      fcnc_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
      fcnc_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
      fcnc_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
    }
  }
}


void hadhadtree::Loop(TTree* inputtree, TString samplename, float globalweight)
{
  if(debug) fcnc_plots->show();
  bool isData = samplename.Contains("data");

  bool doweightsys = ((TString)inputtree->GetName() == "NOMINAL")? 1 : 0;
  double cutflow[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
  };
  reduce -= 1;
  Init(inputtree);
  reduce += 1;
  map < TString, bool > ::iterator iter;
  printf("reduce scheme: %d\n", reduce);
  if (reduce > 1) {
    ifregions.clear();
    ifregions[inputtree->GetName()] = 1;
  }
  if (inputtree == 0) return;
  Long64_t nentries = inputtree->GetEntriesFast();
  TString sample = samplename.Contains("data")? "data":samplename.Remove(0,6).Data();
  initgM();

  if (dumptruth) {
    for (int i = 0; i < 3; ++i) {
      filetruth[i][0].open(CharAppend("hadhad", i + 2) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
      filetruth[i][1].open(CharAppend("hadhad", i + 2) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
    }
  }
  int nloop = debug ? 1000 : nentries;
  float ngluon = 0;
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    inputtree->GetEntry(jentry);
    if ((jentry % 100000 == 0))
      std::cout << " I am here event " << jentry << " Event " << event_number << " Run " << run_number << " ismc " << mc_channel_number << std::endl;
    cutflow[0]+=1;

//===============================SFs and weights===============================
    Float_t trig_SF = 1;
    Float_t lepton_SF = 
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
    ifregions["reg2mtau1b3jss"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
    ifregions["reg1mtau1ltau1b3jss"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
    ifregions["reg2ltau1b3jss"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == 1;
    ifregions["reg2mtau1b2jos"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
    ifregions["reg1mtau1ltau1b2jos"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
    ifregions["reg2ltau1b2jos"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() == 2 && taus_q->at(0)*taus_q->at(1) == -1;
    ifregions["reg2mtau1b3jos"] =      tau_0_jet_bdt_medium && tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;
    ifregions["reg1mtau1ltau1b3jos"] = tau_0_jet_bdt_medium + tau_1_jet_bdt_medium == 1 &&  n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;
    ifregions["reg2ltau1b3jos"] =      !tau_0_jet_bdt_medium && !tau_1_jet_bdt_medium && n_bjets == 1 && jets_p4->size() >= 3 && taus_q->at(0)*taus_q->at(1) == -1;

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
    float jetSFs = 
      jet_NOMINAL_central_jets_global_effSF_JVT*
      jet_NOMINAL_central_jets_global_ineffSF_JVT*
      jet_NOMINAL_forward_jets_global_effSF_JVT*
      jet_NOMINAL_forward_jets_global_ineffSF_JVT*
      jet_NOMINAL_global_effSF_MV2c10*
      jet_NOMINAL_global_ineffSF_MV2c10;
    float weight_pileup = NOMINAL_pileup_combined_weight;
    //weight = weight_mc*weight_pileup*lepton_SF*trig_SF*jetSFs*globalweight;
    weight = 1;
    weights->push_back(weight);
    //===============================pre-selections===============================
    cutflow[0]+=weight;

    tau_pt_0 = taus_p4->at(0).Pt();
    tau_pt_1 = taus_p4->at(1).Pt();

    TString tauorigin;

    if (sample.Contains("data")) {
      tauorigin = "data";
      sample = "data";
    } else {
      if (tau_1_matched_isTau) tauorigin = sample + "_real";
      else if (tau_1_matched_isEle || tau_1_matched_isMuon) tauorigin = sample + "_lep";
      else if (tau_1_matched_isJet){
        if(abs(taus_matched_pdgId->at(1)) == 5) tauorigin = sample + "_b";
        else if(abs(taus_matched_pdgId->at(1)) == 4) tauorigin = sample + "_c";
        else if(taus_matched_pdgId->at(1) == 21) tauorigin = sample + "_g";
        else tauorigin = sample + "_j";
      }else{
        tauorigin = sample + "_nomatch";
      }
    }

    for (iter = ifregions.begin(); iter != ifregions.end(); iter++) {
      if (iter->second == 1) {
        if (writetree){
          if(outputtree.find(iter->first) != outputtree.end())
            outputtree[iter->first]->Fill();
          else{
            printf("Error: outputtree cannot find: %s\n", iter->first.Data());
            for(auto itertmp : outputtree){
              printf("output tree list: %s\n", itertmp.first.Data());
            }
            exit(1);
          }
        }
        if (dohist) {
          fill_fcnc(iter->first, taus_n_charged_tracks->at(1), tauorigin, tau_pt_1 > 35, taus_b_tagged->at(1));
        }
      }
    }
  }
  if (writetree) {
    outputtreefile->cd();
    for (auto itertmp : outputtree)
      itertmp.second->Write(itertmp.first, TObject::kWriteDelete);
  }
}

void hadhadtree::fill_fcnc(TString region, int nprong, TString sample, int iptbin, bool taubtag){
  if(taubtag) {
    if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[1]).Data(), sample.Data());
    fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[1]);
  }else{
    fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[1]);
  }
}


void hadhadtree::definetree(TTree * tree) {

  tree->Branch("eventNumber", &event_number);
  tree->Branch("runNumber",&run_number);
  tree->Branch("weights",&weights);
  tree->Branch("tau_pt_0",&tau_pt_0);
  tree->Branch("tau_pt_1",&tau_pt_1);
  tree->Branch("bjets_fjvt",bjets_fjvt);
  tree->Branch("bjets_is_Jvt_HS",bjets_is_Jvt_HS);
  tree->Branch("bjets_jvt",bjets_jvt);
  tree->Branch("bjets_origin",bjets_origin);
  tree->Branch("bjets_p4",bjets_p4);
  tree->Branch("bjets_q",bjets_q);
  tree->Branch("bjets_type",bjets_type);
  tree->Branch("bjets_width",bjets_width);
  tree->Branch("bjets_wztruth_p4",bjets_wztruth_p4);
  tree->Branch("bjets_wztruth_pdgid",bjets_wztruth_pdgid);


  tree->Branch("taus_id",taus_id);
  tree->Branch("taus_b_tagged",taus_b_tagged);
  tree->Branch("taus_decay_mode",taus_decay_mode);
  tree->Branch("taus_matched_mother_pdgId",taus_matched_mother_pdgId);
  tree->Branch("taus_matched_mother_status",taus_matched_mother_status);
  tree->Branch("taus_matched_p4",taus_matched_p4);
  tree->Branch("taus_matched_pdgId",taus_matched_pdgId);
  tree->Branch("taus_matched_vis_p4",taus_matched_vis_p4);
  tree->Branch("taus_n_charged_tracks",taus_n_charged_tracks);
  tree->Branch("taus_p4",taus_p4);
  tree->Branch("taus_q",taus_q);
  tree->Branch("jets_fjvt",jets_fjvt);
  tree->Branch("jets_is_Jvt_HS",jets_is_Jvt_HS);
  tree->Branch("jets_jvt",jets_jvt);
  tree->Branch("jets_origin",jets_origin);
  tree->Branch("jets_p4",jets_p4);
  tree->Branch("jets_q",jets_q);
  tree->Branch("jets_type",jets_type);
  tree->Branch("jets_width",jets_width);
  tree->Branch("jets_wztruth_p4",jets_wztruth_p4);
  tree->Branch("jets_wztruth_pdgid",jets_wztruth_pdgid);

}
void hadhadtree::definetaus(){
  if(taus_id->size()) taus_id->clear();
  if(taus_b_tagged->size()) taus_b_tagged->clear();
  if(taus_decay_mode->size()) taus_decay_mode->clear();
  if(taus_matched_mother_pdgId->size()) taus_matched_mother_pdgId->clear();
  if(taus_matched_mother_status->size()) taus_matched_mother_status->clear();
  if(taus_matched_p4->size()) taus_matched_p4->clear();
  if(taus_matched_pdgId->size()) taus_matched_pdgId->clear();
  if(taus_matched_vis_p4->size()) taus_matched_vis_p4->clear();
  if(taus_n_charged_tracks->size()) taus_n_charged_tracks->clear();
  if(taus_p4->size()) taus_p4->clear();
  if(taus_q->size()) taus_q->clear();
  if(taus_id->size()) taus_id->clear();

  int tau0id = tau_0_jet_bdt_tight?3:(tau_0_jet_bdt_medium?2:1);
  int tau1id = tau_1_jet_bdt_tight?3:(tau_1_jet_bdt_medium?2:1);

  if(tau0id >= tau1id){

    taus_id->push_back(tau0id);
    taus_b_tagged->push_back(tau_0_b_tagged);
    taus_decay_mode->push_back(tau_0_decay_mode);
    taus_matched_mother_pdgId->push_back(tau_0_matched_mother_pdgId);
    taus_matched_mother_status->push_back(tau_0_matched_mother_status);
    taus_matched_p4->push_back(*tau_0_matched_p4);
    taus_matched_pdgId->push_back(tau_0_matched_pdgId);
    taus_matched_vis_p4->push_back(*tau_0_matched_vis_p4);
    taus_n_charged_tracks->push_back(tau_0_n_charged_tracks);
    taus_p4->push_back(*tau_0_p4);
    taus_q->push_back(tau_0_q);

    taus_id->push_back(tau1id);
    taus_b_tagged->push_back(tau_1_b_tagged);
    taus_decay_mode->push_back(tau_1_decay_mode);
    taus_matched_mother_pdgId->push_back(tau_1_matched_mother_pdgId);
    taus_matched_mother_status->push_back(tau_1_matched_mother_status);
    taus_matched_p4->push_back(*tau_1_matched_p4);
    taus_matched_pdgId->push_back(tau_1_matched_pdgId);
    taus_matched_vis_p4->push_back(*tau_1_matched_vis_p4);
    taus_n_charged_tracks->push_back(tau_1_n_charged_tracks);
    taus_p4->push_back(*tau_1_p4);
    taus_q->push_back(tau_1_q);

  }else{

    taus_id->push_back(tau1id);
    taus_b_tagged->push_back(tau_1_b_tagged);
    taus_decay_mode->push_back(tau_1_decay_mode);
    taus_matched_mother_pdgId->push_back(tau_1_matched_mother_pdgId);
    taus_matched_mother_status->push_back(tau_1_matched_mother_status);
    taus_matched_p4->push_back(*tau_1_matched_p4);
    taus_matched_pdgId->push_back(tau_1_matched_pdgId);
    taus_matched_vis_p4->push_back(*tau_1_matched_vis_p4);
    taus_n_charged_tracks->push_back(tau_1_n_charged_tracks);
    taus_p4->push_back(*tau_1_p4);
    taus_q->push_back(tau_1_q);

    taus_id->push_back(tau0id);
    taus_b_tagged->push_back(tau_0_b_tagged);
    taus_decay_mode->push_back(tau_0_decay_mode);
    taus_matched_mother_pdgId->push_back(tau_0_matched_mother_pdgId);
    taus_matched_mother_status->push_back(tau_0_matched_mother_status);
    taus_matched_p4->push_back(*tau_0_matched_p4);
    taus_matched_pdgId->push_back(tau_0_matched_pdgId);
    taus_matched_vis_p4->push_back(*tau_0_matched_vis_p4);
    taus_n_charged_tracks->push_back(tau_0_n_charged_tracks);
    taus_p4->push_back(*tau_0_p4);
    taus_q->push_back(tau_0_q);

  }
}

void hadhadtree::definejets(){
  if(jets_fjvt->size()) jets_fjvt->clear();
  if(jets_is_Jvt_HS->size()) jets_is_Jvt_HS->clear();
  if(jets_jvt->size()) jets_jvt->clear();
  if(jets_origin->size()) jets_origin->clear();
  if(jets_p4->size()) jets_p4->clear();
  if(jets_q->size()) jets_q->clear();
  if(jets_type->size()) jets_type->clear();
  if(jets_width->size()) jets_width->clear();
  if(jets_wztruth_p4->size()) jets_wztruth_p4->clear();
  if(jets_wztruth_pdgid->size()) jets_wztruth_pdgid->clear();
  if (jet_0)
  {
    if(jet_0_b_tagged){
      bjets_fjvt->push_back(jet_0_fjvt);
      bjets_is_Jvt_HS->push_back(jet_0_is_Jvt_HS);
      bjets_jvt->push_back(jet_0_jvt);
      bjets_origin->push_back(jet_0_origin);
      bjets_p4->push_back(*jet_0_p4);
      bjets_q->push_back(jet_0_q);
      bjets_type->push_back(jet_0_type);
      bjets_width->push_back(jet_0_width);
      bjets_wztruth_p4->push_back(*jet_0_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_0_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_0_fjvt);
      jets_is_Jvt_HS->push_back(jet_0_is_Jvt_HS);
      jets_jvt->push_back(jet_0_jvt);
      jets_origin->push_back(jet_0_origin);
      jets_p4->push_back(*jet_0_p4);
      jets_q->push_back(jet_0_q);
      jets_type->push_back(jet_0_type);
      jets_width->push_back(jet_0_width);
      jets_wztruth_p4->push_back(*jet_0_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_0_wztruth_pdgid);
    }
  }
  if (jet_1)
  {
    if(jet_1_b_tagged){
      bjets_fjvt->push_back(jet_1_fjvt);
      bjets_is_Jvt_HS->push_back(jet_1_is_Jvt_HS);
      bjets_jvt->push_back(jet_1_jvt);
      bjets_origin->push_back(jet_1_origin);
      bjets_p4->push_back(*jet_1_p4);
      bjets_q->push_back(jet_1_q);
      bjets_type->push_back(jet_1_type);
      bjets_width->push_back(jet_1_width);
      bjets_wztruth_p4->push_back(*jet_1_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_1_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_1_fjvt);
      jets_is_Jvt_HS->push_back(jet_1_is_Jvt_HS);
      jets_jvt->push_back(jet_1_jvt);
      jets_origin->push_back(jet_1_origin);
      jets_p4->push_back(*jet_1_p4);
      jets_q->push_back(jet_1_q);
      jets_type->push_back(jet_1_type);
      jets_width->push_back(jet_1_width);
      jets_wztruth_p4->push_back(*jet_1_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_1_wztruth_pdgid);
    }
  }
  if (jet_2)
  {
    if(jet_2_b_tagged){
      bjets_fjvt->push_back(jet_2_fjvt);
      bjets_is_Jvt_HS->push_back(jet_2_is_Jvt_HS);
      bjets_jvt->push_back(jet_2_jvt);
      bjets_origin->push_back(jet_2_origin);
      bjets_p4->push_back(*jet_2_p4);
      bjets_q->push_back(jet_2_q);
      bjets_type->push_back(jet_2_type);
      bjets_width->push_back(jet_2_width);
      bjets_wztruth_p4->push_back(*jet_2_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_2_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_2_fjvt);
      jets_is_Jvt_HS->push_back(jet_2_is_Jvt_HS);
      jets_jvt->push_back(jet_2_jvt);
      jets_origin->push_back(jet_2_origin);
      jets_p4->push_back(*jet_2_p4);
      jets_q->push_back(jet_2_q);
      jets_type->push_back(jet_2_type);
      jets_width->push_back(jet_2_width);
      jets_wztruth_p4->push_back(*jet_2_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_2_wztruth_pdgid);
    }
  }
  if (jet_3)
  {
    if(jet_3_b_tagged){
      bjets_fjvt->push_back(jet_3_fjvt);
      bjets_is_Jvt_HS->push_back(jet_3_is_Jvt_HS);
      bjets_jvt->push_back(jet_3_jvt);
      bjets_origin->push_back(jet_3_origin);
      bjets_p4->push_back(*jet_3_p4);
      bjets_q->push_back(jet_3_q);
      bjets_type->push_back(jet_3_type);
      bjets_width->push_back(jet_3_width);
      bjets_wztruth_p4->push_back(*jet_3_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_3_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_3_fjvt);
      jets_is_Jvt_HS->push_back(jet_3_is_Jvt_HS);
      jets_jvt->push_back(jet_3_jvt);
      jets_origin->push_back(jet_3_origin);
      jets_p4->push_back(*jet_3_p4);
      jets_q->push_back(jet_3_q);
      jets_type->push_back(jet_3_type);
      jets_width->push_back(jet_3_width);
      jets_wztruth_p4->push_back(*jet_3_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_3_wztruth_pdgid);
    }
  }
  if (jet_4)
  {
    if(jet_4_b_tagged){
      bjets_fjvt->push_back(jet_4_fjvt);
      bjets_is_Jvt_HS->push_back(jet_4_is_Jvt_HS);
      bjets_jvt->push_back(jet_4_jvt);
      bjets_origin->push_back(jet_4_origin);
      bjets_p4->push_back(*jet_4_p4);
      bjets_q->push_back(jet_4_q);
      bjets_type->push_back(jet_4_type);
      bjets_width->push_back(jet_4_width);
      bjets_wztruth_p4->push_back(*jet_4_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_4_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_4_fjvt);
      jets_is_Jvt_HS->push_back(jet_4_is_Jvt_HS);
      jets_jvt->push_back(jet_4_jvt);
      jets_origin->push_back(jet_4_origin);
      jets_p4->push_back(*jet_4_p4);
      jets_q->push_back(jet_4_q);
      jets_type->push_back(jet_4_type);
      jets_width->push_back(jet_4_width);
      jets_wztruth_p4->push_back(*jet_4_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_4_wztruth_pdgid);
    }
  }
  if (jet_5)
  {
    if(jet_5_b_tagged){
      bjets_fjvt->push_back(jet_5_fjvt);
      bjets_is_Jvt_HS->push_back(jet_5_is_Jvt_HS);
      bjets_jvt->push_back(jet_5_jvt);
      bjets_origin->push_back(jet_5_origin);
      bjets_p4->push_back(*jet_5_p4);
      bjets_q->push_back(jet_5_q);
      bjets_type->push_back(jet_5_type);
      bjets_width->push_back(jet_5_width);
      bjets_wztruth_p4->push_back(*jet_5_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_5_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_5_fjvt);
      jets_is_Jvt_HS->push_back(jet_5_is_Jvt_HS);
      jets_jvt->push_back(jet_5_jvt);
      jets_origin->push_back(jet_5_origin);
      jets_p4->push_back(*jet_5_p4);
      jets_q->push_back(jet_5_q);
      jets_type->push_back(jet_5_type);
      jets_width->push_back(jet_5_width);
      jets_wztruth_p4->push_back(*jet_5_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_5_wztruth_pdgid);
    }
  }
  if (jet_6)
  {
    if(jet_6_b_tagged){
      bjets_fjvt->push_back(jet_6_fjvt);
      bjets_is_Jvt_HS->push_back(jet_6_is_Jvt_HS);
      bjets_jvt->push_back(jet_6_jvt);
      bjets_origin->push_back(jet_6_origin);
      bjets_p4->push_back(*jet_6_p4);
      bjets_q->push_back(jet_6_q);
      bjets_type->push_back(jet_6_type);
      bjets_width->push_back(jet_6_width);
      bjets_wztruth_p4->push_back(*jet_6_wztruth_p4);
      bjets_wztruth_pdgid->push_back(jet_6_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_6_fjvt);
      jets_is_Jvt_HS->push_back(jet_6_is_Jvt_HS);
      jets_jvt->push_back(jet_6_jvt);
      jets_origin->push_back(jet_6_origin);
      jets_p4->push_back(*jet_6_p4);
      jets_q->push_back(jet_6_q);
      jets_type->push_back(jet_6_type);
      jets_width->push_back(jet_6_width);
      jets_wztruth_p4->push_back(*jet_6_wztruth_p4);
      jets_wztruth_pdgid->push_back(jet_6_wztruth_pdgid);
    }
  }
}

void hadhadtree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   boson_0_truth_p4 = 0;
   ditau_matched_p4 = 0;
   ditau_p4 = 0;
   jet_0_p4 = 0;
   jet_0_wztruth_p4 = 0;
   jet_1_p4 = 0;
   jet_1_wztruth_p4 = 0;
   jet_2_p4 = 0;
   jet_2_wztruth_p4 = 0;
   jet_3_p4 = 0;
   jet_3_wztruth_p4 = 0;
   jet_4_p4 = 0;
   jet_4_wztruth_p4 = 0;
   jet_5_p4 = 0;
   jet_5_wztruth_p4 = 0;
   jet_6_p4 = 0;
   jet_6_wztruth_p4 = 0;
   jet_7_p4 = 0;
   jet_7_wztruth_p4 = 0;
   met_hpto_p4 = 0;
   met_p4 = 0;
   met_truth_p4 = 0;
   primary_vertex_v = 0;
   tau_0_decay_charged_p4 = 0;
   tau_0_decay_neutral_p4 = 0;
   tau_0_leadTrk_vertex_v = 0;
   tau_0_matched_decay_charged_p4 = 0;
   tau_0_matched_decay_neutral_p4 = 0;
   tau_0_matched_decay_neutrino_p4 = 0;
   tau_0_matched_p4 = 0;
   tau_0_matched_p4_vis_charged_track0 = 0;
   tau_0_matched_p4_vis_charged_track1 = 0;
   tau_0_matched_p4_vis_charged_track2 = 0;
   tau_0_matched_vis_charged_p4 = 0;
   tau_0_matched_vis_neutral_others_p4 = 0;
   tau_0_matched_vis_neutral_p4 = 0;
   tau_0_matched_vis_neutral_pions_p4 = 0;
   tau_0_matched_vis_p4 = 0;
   tau_0_p4 = 0;
   tau_0_track0_p4 = 0;
   tau_0_track1_p4 = 0;
   tau_0_track2_p4 = 0;
   tau_1_decay_charged_p4 = 0;
   tau_1_decay_neutral_p4 = 0;
   tau_1_leadTrk_vertex_v = 0;
   tau_1_matched_decay_charged_p4 = 0;
   tau_1_matched_decay_neutral_p4 = 0;
   tau_1_matched_decay_neutrino_p4 = 0;
   tau_1_matched_p4 = 0;
   tau_1_matched_p4_vis_charged_track0 = 0;
   tau_1_matched_p4_vis_charged_track1 = 0;
   tau_1_matched_p4_vis_charged_track2 = 0;
   tau_1_matched_vis_charged_p4 = 0;
   tau_1_matched_vis_neutral_others_p4 = 0;
   tau_1_matched_vis_neutral_p4 = 0;
   tau_1_matched_vis_neutral_pions_p4 = 0;
   tau_1_matched_vis_p4 = 0;
   tau_1_p4 = 0;
   tau_1_track0_p4 = 0;
   tau_1_track1_p4 = 0;
   tau_1_track2_p4 = 0;
   // Set branch addresses and branch pointers

   fChain->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I);
   fChain->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25);
   fChain->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I);
   fChain->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25);
   fChain->SetBranchAddress("HTXS_Njets_pTjet25", &HTXS_Njets_pTjet25, &b_HTXS_Njets_pTjet25);
   fChain->SetBranchAddress("HTXS_Njets_pTjet30", &HTXS_Njets_pTjet30, &b_HTXS_Njets_pTjet30);
   fChain->SetBranchAddress("HTXS_Stage0_Category", &HTXS_Stage0_Category, &b_HTXS_Stage0_Category);
   fChain->SetBranchAddress("HTXS_Stage1_Category_pTjet25GeV", &HTXS_Stage1_Category_pTjet25GeV, &b_HTXS_Stage1_Category_pTjet25GeV);
   fChain->SetBranchAddress("HTXS_Stage1_Category_pTjet30GeV", &HTXS_Stage1_Category_pTjet30GeV, &b_HTXS_Stage1_Category_pTjet30GeV);
   fChain->SetBranchAddress("HTXS_errorMode", &HTXS_errorMode, &b_HTXS_errorMode);
   fChain->SetBranchAddress("HTXS_prodMode", &HTXS_prodMode, &b_HTXS_prodMode);
   fChain->SetBranchAddress("NOMINAL_pileup_combined_weight", &NOMINAL_pileup_combined_weight, &b_NOMINAL_pileup_combined_weight);
   fChain->SetBranchAddress("NOMINAL_pileup_random_lb_number", &NOMINAL_pileup_random_lb_number, &b_NOMINAL_pileup_random_lb_number);
   fChain->SetBranchAddress("NOMINAL_pileup_random_run_number", &NOMINAL_pileup_random_run_number, &b_NOMINAL_pileup_random_run_number);
   fChain->SetBranchAddress("PRW_DATASF_1down_pileup_combined_weight", &PRW_DATASF_1down_pileup_combined_weight, &b_PRW_DATASF_1down_pileup_combined_weight);
   fChain->SetBranchAddress("PRW_DATASF_1up_pileup_combined_weight", &PRW_DATASF_1up_pileup_combined_weight, &b_PRW_DATASF_1up_pileup_combined_weight);
   fChain->SetBranchAddress("boson_0_truth_p4", &boson_0_truth_p4, &b_boson_0_truth_p4);
   fChain->SetBranchAddress("boson_0_truth_pdgId", &boson_0_truth_pdgId, &b_boson_0_truth_pdgId);
   fChain->SetBranchAddress("boson_0_truth_q", &boson_0_truth_q, &b_boson_0_truth_q);
   fChain->SetBranchAddress("boson_0_truth_status", &boson_0_truth_status, &b_boson_0_truth_status);
   fChain->SetBranchAddress("dijet_deta", &dijet_deta, &b_dijet_deta);
   fChain->SetBranchAddress("dijet_dphi", &dijet_dphi, &b_dijet_dphi);
   fChain->SetBranchAddress("dijet_m", &dijet_m, &b_dijet_m);
   fChain->SetBranchAddress("dijet_prod_eta", &dijet_prod_eta, &b_dijet_prod_eta);
   fChain->SetBranchAddress("dijet_pt", &dijet_pt, &b_dijet_pt);
   fChain->SetBranchAddress("ditau_coll_approx", &ditau_coll_approx, &b_ditau_coll_approx);
   fChain->SetBranchAddress("ditau_coll_approx_m", &ditau_coll_approx_m, &b_ditau_coll_approx_m);
   fChain->SetBranchAddress("ditau_coll_approx_x0", &ditau_coll_approx_x0, &b_ditau_coll_approx_x0);
   fChain->SetBranchAddress("ditau_coll_approx_x1", &ditau_coll_approx_x1, &b_ditau_coll_approx_x1);
   fChain->SetBranchAddress("ditau_cosalpha", &ditau_cosalpha, &b_ditau_cosalpha);
   fChain->SetBranchAddress("ditau_deta", &ditau_deta, &b_ditau_deta);
   fChain->SetBranchAddress("ditau_dphi", &ditau_dphi, &b_ditau_dphi);
   fChain->SetBranchAddress("ditau_dr", &ditau_dr, &b_ditau_dr);
   fChain->SetBranchAddress("ditau_higgspt", &ditau_higgspt, &b_ditau_higgspt);
   fChain->SetBranchAddress("ditau_matched", &ditau_matched, &b_ditau_matched);
   fChain->SetBranchAddress("ditau_matched_cosalpha", &ditau_matched_cosalpha, &b_ditau_matched_cosalpha);
   fChain->SetBranchAddress("ditau_matched_deta", &ditau_matched_deta, &b_ditau_matched_deta);
   fChain->SetBranchAddress("ditau_matched_dphi", &ditau_matched_dphi, &b_ditau_matched_dphi);
   fChain->SetBranchAddress("ditau_matched_dr", &ditau_matched_dr, &b_ditau_matched_dr);
   fChain->SetBranchAddress("ditau_matched_p4", &ditau_matched_p4, &b_ditau_matched_p4);
   fChain->SetBranchAddress("ditau_matched_qxq", &ditau_matched_qxq, &b_ditau_matched_qxq);
   fChain->SetBranchAddress("ditau_matched_scal_sum_pt", &ditau_matched_scal_sum_pt, &b_ditau_matched_scal_sum_pt);
   fChain->SetBranchAddress("ditau_matched_vis_cosalpha", &ditau_matched_vis_cosalpha, &b_ditau_matched_vis_cosalpha);
   fChain->SetBranchAddress("ditau_matched_vis_deta", &ditau_matched_vis_deta, &b_ditau_matched_vis_deta);
   fChain->SetBranchAddress("ditau_matched_vis_dphi", &ditau_matched_vis_dphi, &b_ditau_matched_vis_dphi);
   fChain->SetBranchAddress("ditau_matched_vis_dr", &ditau_matched_vis_dr, &b_ditau_matched_vis_dr);
   fChain->SetBranchAddress("ditau_matched_vis_mass", &ditau_matched_vis_mass, &b_ditau_matched_vis_mass);
   fChain->SetBranchAddress("ditau_matched_vis_scal_sum_pt", &ditau_matched_vis_scal_sum_pt, &b_ditau_matched_vis_scal_sum_pt);
   fChain->SetBranchAddress("ditau_matched_vis_vect_sum_pt", &ditau_matched_vis_vect_sum_pt, &b_ditau_matched_vis_vect_sum_pt);
   fChain->SetBranchAddress("ditau_met_centrality", &ditau_met_centrality, &b_ditau_met_centrality);
   fChain->SetBranchAddress("ditau_met_lep0_cos_dphi", &ditau_met_lep0_cos_dphi, &b_ditau_met_lep0_cos_dphi);
   fChain->SetBranchAddress("ditau_met_lep1_cos_dphi", &ditau_met_lep1_cos_dphi, &b_ditau_met_lep1_cos_dphi);
   fChain->SetBranchAddress("ditau_met_min_dphi", &ditau_met_min_dphi, &b_ditau_met_min_dphi);
   fChain->SetBranchAddress("ditau_met_sum_cos_dphi", &ditau_met_sum_cos_dphi, &b_ditau_met_sum_cos_dphi);
   fChain->SetBranchAddress("ditau_mmc_maxw_eta", &ditau_mmc_maxw_eta, &b_ditau_mmc_maxw_eta);
   fChain->SetBranchAddress("ditau_mmc_maxw_fit_status", &ditau_mmc_maxw_fit_status, &b_ditau_mmc_maxw_fit_status);
   fChain->SetBranchAddress("ditau_mmc_maxw_m", &ditau_mmc_maxw_m, &b_ditau_mmc_maxw_m);
   fChain->SetBranchAddress("ditau_mmc_maxw_met_et", &ditau_mmc_maxw_met_et, &b_ditau_mmc_maxw_met_et);
   fChain->SetBranchAddress("ditau_mmc_maxw_met_phi", &ditau_mmc_maxw_met_phi, &b_ditau_mmc_maxw_met_phi);
   fChain->SetBranchAddress("ditau_mmc_maxw_phi", &ditau_mmc_maxw_phi, &b_ditau_mmc_maxw_phi);
   fChain->SetBranchAddress("ditau_mmc_maxw_pt", &ditau_mmc_maxw_pt, &b_ditau_mmc_maxw_pt);
   fChain->SetBranchAddress("ditau_mmc_maxw_x0", &ditau_mmc_maxw_x0, &b_ditau_mmc_maxw_x0);
   fChain->SetBranchAddress("ditau_mmc_maxw_x1", &ditau_mmc_maxw_x1, &b_ditau_mmc_maxw_x1);
   fChain->SetBranchAddress("ditau_mmc_mlm_fit_status", &ditau_mmc_mlm_fit_status, &b_ditau_mmc_mlm_fit_status);
   fChain->SetBranchAddress("ditau_mmc_mlm_m", &ditau_mmc_mlm_m, &b_ditau_mmc_mlm_m);
   fChain->SetBranchAddress("ditau_mt_lep0_met", &ditau_mt_lep0_met, &b_ditau_mt_lep0_met);
   fChain->SetBranchAddress("ditau_mt_lep1_met", &ditau_mt_lep1_met, &b_ditau_mt_lep1_met);
   fChain->SetBranchAddress("ditau_p4", &ditau_p4, &b_ditau_p4);
   fChain->SetBranchAddress("ditau_qxq", &ditau_qxq, &b_ditau_qxq);
   fChain->SetBranchAddress("ditau_scal_sum_pt", &ditau_scal_sum_pt, &b_ditau_scal_sum_pt);
   fChain->SetBranchAddress("event_clean_EC_TightBad", &event_clean_EC_TightBad, &b_event_clean_EC_TightBad);
   fChain->SetBranchAddress("event_number", &event_number, &b_event_number);
   fChain->SetBranchAddress("is_dijet_centrality", &is_dijet_centrality, &b_is_dijet_centrality);
   fChain->SetBranchAddress("jet_0_b_tagged", &jet_0_b_tagged, &b_jet_0_b_tagged);
   fChain->SetBranchAddress("jet_0_fjvt", &jet_0_fjvt, &b_jet_0_fjvt);
   fChain->SetBranchAddress("jet_0_flavorlabel_part", &jet_0_flavorlabel_part, &b_jet_0_flavorlabel_part);
   fChain->SetBranchAddress("jet_0_is_Jvt_HS", &jet_0_is_Jvt_HS, &b_jet_0_is_Jvt_HS);
   fChain->SetBranchAddress("jet_0_jvt", &jet_0_jvt, &b_jet_0_jvt);
   fChain->SetBranchAddress("jet_0_p4", &jet_0_p4, &b_jet_0_p4);
   fChain->SetBranchAddress("jet_0_width", &jet_0_width, &b_jet_0_width);
   fChain->SetBranchAddress("jet_0_wztruth_p4", &jet_0_wztruth_p4, &b_jet_0_wztruth_p4);
   fChain->SetBranchAddress("jet_0_wztruth_pdgid", &jet_0_wztruth_pdgid, &b_jet_0_wztruth_pdgid);
   fChain->SetBranchAddress("jet_1_b_tagged", &jet_1_b_tagged, &b_jet_1_b_tagged);
   fChain->SetBranchAddress("jet_1_fjvt", &jet_1_fjvt, &b_jet_1_fjvt);
   fChain->SetBranchAddress("jet_1_flavorlabel_part", &jet_1_flavorlabel_part, &b_jet_1_flavorlabel_part);
   fChain->SetBranchAddress("jet_1_is_Jvt_HS", &jet_1_is_Jvt_HS, &b_jet_1_is_Jvt_HS);
   fChain->SetBranchAddress("jet_1_jvt", &jet_1_jvt, &b_jet_1_jvt);
   fChain->SetBranchAddress("jet_1_p4", &jet_1_p4, &b_jet_1_p4);
   fChain->SetBranchAddress("jet_1_width", &jet_1_width, &b_jet_1_width);
   fChain->SetBranchAddress("jet_1_wztruth_p4", &jet_1_wztruth_p4, &b_jet_1_wztruth_p4);
   fChain->SetBranchAddress("jet_1_wztruth_pdgid", &jet_1_wztruth_pdgid, &b_jet_1_wztruth_pdgid);
   fChain->SetBranchAddress("jet_2_b_tagged", &jet_2_b_tagged, &b_jet_2_b_tagged);
   fChain->SetBranchAddress("jet_2_fjvt", &jet_2_fjvt, &b_jet_2_fjvt);
   fChain->SetBranchAddress("jet_2_flavorlabel_part", &jet_2_flavorlabel_part, &b_jet_2_flavorlabel_part);
   fChain->SetBranchAddress("jet_2_is_Jvt_HS", &jet_2_is_Jvt_HS, &b_jet_2_is_Jvt_HS);
   fChain->SetBranchAddress("jet_2_jvt", &jet_2_jvt, &b_jet_2_jvt);
   fChain->SetBranchAddress("jet_2_p4", &jet_2_p4, &b_jet_2_p4);
   fChain->SetBranchAddress("jet_2_width", &jet_2_width, &b_jet_2_width);
   fChain->SetBranchAddress("jet_2_wztruth_p4", &jet_2_wztruth_p4, &b_jet_2_wztruth_p4);
   fChain->SetBranchAddress("jet_2_wztruth_pdgid", &jet_2_wztruth_pdgid, &b_jet_2_wztruth_pdgid);
   fChain->SetBranchAddress("jet_3", &jet_3, &b_jet_3);
   fChain->SetBranchAddress("jet_3_b_tag_quantile", &jet_3_b_tag_quantile, &b_jet_3_b_tag_quantile);
   fChain->SetBranchAddress("jet_3_b_tag_score", &jet_3_b_tag_score, &b_jet_3_b_tag_score);
   fChain->SetBranchAddress("jet_3_b_tagged", &jet_3_b_tagged, &b_jet_3_b_tagged);
   fChain->SetBranchAddress("jet_3_cleanJet_EC_LooseBad", &jet_3_cleanJet_EC_LooseBad, &b_jet_3_cleanJet_EC_LooseBad);
   fChain->SetBranchAddress("jet_3_fjvt", &jet_3_fjvt, &b_jet_3_fjvt);
   fChain->SetBranchAddress("jet_3_flavorlabel", &jet_3_flavorlabel, &b_jet_3_flavorlabel);
   fChain->SetBranchAddress("jet_3_flavorlabel_cone", &jet_3_flavorlabel_cone, &b_jet_3_flavorlabel_cone);
   fChain->SetBranchAddress("jet_3_flavorlabel_part", &jet_3_flavorlabel_part, &b_jet_3_flavorlabel_part);
   fChain->SetBranchAddress("jet_3_is_Jvt_HS", &jet_3_is_Jvt_HS, &b_jet_3_is_Jvt_HS);
   fChain->SetBranchAddress("jet_3_jvt", &jet_3_jvt, &b_jet_3_jvt);
   fChain->SetBranchAddress("jet_3_origin", &jet_3_origin, &b_jet_3_origin);
   fChain->SetBranchAddress("jet_3_p4", &jet_3_p4, &b_jet_3_p4);
   fChain->SetBranchAddress("jet_3_q", &jet_3_q, &b_jet_3_q);
   fChain->SetBranchAddress("jet_3_type", &jet_3_type, &b_jet_3_type);
   fChain->SetBranchAddress("jet_3_width", &jet_3_width, &b_jet_3_width);
   fChain->SetBranchAddress("jet_3_wztruth_p4", &jet_3_wztruth_p4, &b_jet_3_wztruth_p4);
   fChain->SetBranchAddress("jet_3_wztruth_pdgid", &jet_3_wztruth_pdgid, &b_jet_3_wztruth_pdgid);
   fChain->SetBranchAddress("jet_4", &jet_4, &b_jet_4);
   fChain->SetBranchAddress("jet_4_b_tag_quantile", &jet_4_b_tag_quantile, &b_jet_4_b_tag_quantile);
   fChain->SetBranchAddress("jet_4_b_tag_score", &jet_4_b_tag_score, &b_jet_4_b_tag_score);
   fChain->SetBranchAddress("jet_4_b_tagged", &jet_4_b_tagged, &b_jet_4_b_tagged);
   fChain->SetBranchAddress("jet_4_cleanJet_EC_LooseBad", &jet_4_cleanJet_EC_LooseBad, &b_jet_4_cleanJet_EC_LooseBad);
   fChain->SetBranchAddress("jet_4_fjvt", &jet_4_fjvt, &b_jet_4_fjvt);
   fChain->SetBranchAddress("jet_4_flavorlabel", &jet_4_flavorlabel, &b_jet_4_flavorlabel);
   fChain->SetBranchAddress("jet_4_flavorlabel_cone", &jet_4_flavorlabel_cone, &b_jet_4_flavorlabel_cone);
   fChain->SetBranchAddress("jet_4_flavorlabel_part", &jet_4_flavorlabel_part, &b_jet_4_flavorlabel_part);
   fChain->SetBranchAddress("jet_4_is_Jvt_HS", &jet_4_is_Jvt_HS, &b_jet_4_is_Jvt_HS);
   fChain->SetBranchAddress("jet_4_jvt", &jet_4_jvt, &b_jet_4_jvt);
   fChain->SetBranchAddress("jet_4_origin", &jet_4_origin, &b_jet_4_origin);
   fChain->SetBranchAddress("jet_4_p4", &jet_4_p4, &b_jet_4_p4);
   fChain->SetBranchAddress("jet_4_q", &jet_4_q, &b_jet_4_q);
   fChain->SetBranchAddress("jet_4_type", &jet_4_type, &b_jet_4_type);
   fChain->SetBranchAddress("jet_4_width", &jet_4_width, &b_jet_4_width);
   fChain->SetBranchAddress("jet_4_wztruth_p4", &jet_4_wztruth_p4, &b_jet_4_wztruth_p4);
   fChain->SetBranchAddress("jet_4_wztruth_pdgid", &jet_4_wztruth_pdgid, &b_jet_4_wztruth_pdgid);
   fChain->SetBranchAddress("jet_5", &jet_5, &b_jet_5);
   fChain->SetBranchAddress("jet_5_b_tag_quantile", &jet_5_b_tag_quantile, &b_jet_5_b_tag_quantile);
   fChain->SetBranchAddress("jet_5_b_tag_score", &jet_5_b_tag_score, &b_jet_5_b_tag_score);
   fChain->SetBranchAddress("jet_5_b_tagged", &jet_5_b_tagged, &b_jet_5_b_tagged);
   fChain->SetBranchAddress("jet_5_cleanJet_EC_LooseBad", &jet_5_cleanJet_EC_LooseBad, &b_jet_5_cleanJet_EC_LooseBad);
   fChain->SetBranchAddress("jet_5_fjvt", &jet_5_fjvt, &b_jet_5_fjvt);
   fChain->SetBranchAddress("jet_5_flavorlabel", &jet_5_flavorlabel, &b_jet_5_flavorlabel);
   fChain->SetBranchAddress("jet_5_flavorlabel_cone", &jet_5_flavorlabel_cone, &b_jet_5_flavorlabel_cone);
   fChain->SetBranchAddress("jet_5_flavorlabel_part", &jet_5_flavorlabel_part, &b_jet_5_flavorlabel_part);
   fChain->SetBranchAddress("jet_5_is_Jvt_HS", &jet_5_is_Jvt_HS, &b_jet_5_is_Jvt_HS);
   fChain->SetBranchAddress("jet_5_jvt", &jet_5_jvt, &b_jet_5_jvt);
   fChain->SetBranchAddress("jet_5_origin", &jet_5_origin, &b_jet_5_origin);
   fChain->SetBranchAddress("jet_5_p4", &jet_5_p4, &b_jet_5_p4);
   fChain->SetBranchAddress("jet_5_q", &jet_5_q, &b_jet_5_q);
   fChain->SetBranchAddress("jet_5_type", &jet_5_type, &b_jet_5_type);
   fChain->SetBranchAddress("jet_5_width", &jet_5_width, &b_jet_5_width);
   fChain->SetBranchAddress("jet_5_wztruth_p4", &jet_5_wztruth_p4, &b_jet_5_wztruth_p4);
   fChain->SetBranchAddress("jet_5_wztruth_pdgid", &jet_5_wztruth_pdgid, &b_jet_5_wztruth_pdgid);
   fChain->SetBranchAddress("jet_6", &jet_6, &b_jet_6);
   fChain->SetBranchAddress("jet_6_b_tag_quantile", &jet_6_b_tag_quantile, &b_jet_6_b_tag_quantile);
   fChain->SetBranchAddress("jet_6_b_tag_score", &jet_6_b_tag_score, &b_jet_6_b_tag_score);
   fChain->SetBranchAddress("jet_6_b_tagged", &jet_6_b_tagged, &b_jet_6_b_tagged);
   fChain->SetBranchAddress("jet_6_cleanJet_EC_LooseBad", &jet_6_cleanJet_EC_LooseBad, &b_jet_6_cleanJet_EC_LooseBad);
   fChain->SetBranchAddress("jet_6_fjvt", &jet_6_fjvt, &b_jet_6_fjvt);
   fChain->SetBranchAddress("jet_6_flavorlabel", &jet_6_flavorlabel, &b_jet_6_flavorlabel);
   fChain->SetBranchAddress("jet_6_flavorlabel_cone", &jet_6_flavorlabel_cone, &b_jet_6_flavorlabel_cone);
   fChain->SetBranchAddress("jet_6_flavorlabel_part", &jet_6_flavorlabel_part, &b_jet_6_flavorlabel_part);
   fChain->SetBranchAddress("jet_6_is_Jvt_HS", &jet_6_is_Jvt_HS, &b_jet_6_is_Jvt_HS);
   fChain->SetBranchAddress("jet_6_jvt", &jet_6_jvt, &b_jet_6_jvt);
   fChain->SetBranchAddress("jet_6_origin", &jet_6_origin, &b_jet_6_origin);
   fChain->SetBranchAddress("jet_6_p4", &jet_6_p4, &b_jet_6_p4);
   fChain->SetBranchAddress("jet_6_q", &jet_6_q, &b_jet_6_q);
   fChain->SetBranchAddress("jet_6_type", &jet_6_type, &b_jet_6_type);
   fChain->SetBranchAddress("jet_6_width", &jet_6_width, &b_jet_6_width);
   fChain->SetBranchAddress("jet_6_wztruth_p4", &jet_6_wztruth_p4, &b_jet_6_wztruth_p4);
   fChain->SetBranchAddress("jet_6_wztruth_pdgid", &jet_6_wztruth_pdgid, &b_jet_6_wztruth_pdgid);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT", &jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT, &b_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT", &jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT, &b_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT", &jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT, &b_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT", &jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT, &b_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT", &jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT, &b_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT", &jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT, &b_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT", &jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT, &b_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT", &jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT, &b_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_central_jets_global_effSF_JVT", &jet_NOMINAL_central_jets_global_effSF_JVT, &b_jet_NOMINAL_central_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_central_jets_global_ineffSF_JVT", &jet_NOMINAL_central_jets_global_ineffSF_JVT, &b_jet_NOMINAL_central_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_forward_jets_global_effSF_JVT", &jet_NOMINAL_forward_jets_global_effSF_JVT, &b_jet_NOMINAL_forward_jets_global_effSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_forward_jets_global_ineffSF_JVT", &jet_NOMINAL_forward_jets_global_ineffSF_JVT, &b_jet_NOMINAL_forward_jets_global_ineffSF_JVT);
   fChain->SetBranchAddress("jet_NOMINAL_global_effSF_MV2c10", &jet_NOMINAL_global_effSF_MV2c10, &b_jet_NOMINAL_global_effSF_MV2c10);
   fChain->SetBranchAddress("jet_NOMINAL_global_ineffSF_MV2c10", &jet_NOMINAL_global_ineffSF_MV2c10, &b_jet_NOMINAL_global_ineffSF_MV2c10);
   fChain->SetBranchAddress("lepton_eta_centrality", &lepton_eta_centrality, &b_lepton_eta_centrality);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("met_hpto_p4", &met_hpto_p4, &b_met_hpto_p4);
   fChain->SetBranchAddress("met_more_met_et_ele", &met_more_met_et_ele, &b_met_more_met_et_ele);
   fChain->SetBranchAddress("met_more_met_et_jet", &met_more_met_et_jet, &b_met_more_met_et_jet);
   fChain->SetBranchAddress("met_more_met_et_muon", &met_more_met_et_muon, &b_met_more_met_et_muon);
   fChain->SetBranchAddress("met_more_met_et_pho", &met_more_met_et_pho, &b_met_more_met_et_pho);
   fChain->SetBranchAddress("met_more_met_et_soft", &met_more_met_et_soft, &b_met_more_met_et_soft);
   fChain->SetBranchAddress("met_more_met_et_tau", &met_more_met_et_tau, &b_met_more_met_et_tau);
   fChain->SetBranchAddress("met_more_met_phi_ele", &met_more_met_phi_ele, &b_met_more_met_phi_ele);
   fChain->SetBranchAddress("met_more_met_phi_jet", &met_more_met_phi_jet, &b_met_more_met_phi_jet);
   fChain->SetBranchAddress("met_more_met_phi_muon", &met_more_met_phi_muon, &b_met_more_met_phi_muon);
   fChain->SetBranchAddress("met_more_met_phi_pho", &met_more_met_phi_pho, &b_met_more_met_phi_pho);
   fChain->SetBranchAddress("met_more_met_phi_soft", &met_more_met_phi_soft, &b_met_more_met_phi_soft);
   fChain->SetBranchAddress("met_more_met_phi_tau", &met_more_met_phi_tau, &b_met_more_met_phi_tau);
   fChain->SetBranchAddress("met_more_met_sumet_ele", &met_more_met_sumet_ele, &b_met_more_met_sumet_ele);
   fChain->SetBranchAddress("met_more_met_sumet_jet", &met_more_met_sumet_jet, &b_met_more_met_sumet_jet);
   fChain->SetBranchAddress("met_more_met_sumet_muon", &met_more_met_sumet_muon, &b_met_more_met_sumet_muon);
   fChain->SetBranchAddress("met_more_met_sumet_pho", &met_more_met_sumet_pho, &b_met_more_met_sumet_pho);
   fChain->SetBranchAddress("met_more_met_sumet_soft", &met_more_met_sumet_soft, &b_met_more_met_sumet_soft);
   fChain->SetBranchAddress("met_more_met_sumet_tau", &met_more_met_sumet_tau, &b_met_more_met_sumet_tau);
   fChain->SetBranchAddress("met_p4", &met_p4, &b_met_p4);
   fChain->SetBranchAddress("met_sign_met_over_sqrt_ht", &met_sign_met_over_sqrt_ht, &b_met_sign_met_over_sqrt_ht);
   fChain->SetBranchAddress("met_sign_met_over_sqrt_sumet", &met_sign_met_over_sqrt_sumet, &b_met_sign_met_over_sqrt_sumet);
   fChain->SetBranchAddress("met_sign_met_rho", &met_sign_met_rho, &b_met_sign_met_rho);
   fChain->SetBranchAddress("met_sign_met_rho_ttdir", &met_sign_met_rho_ttdir, &b_met_sign_met_rho_ttdir);
   fChain->SetBranchAddress("met_sign_met_sig_directional", &met_sign_met_sig_directional, &b_met_sign_met_sig_directional);
   fChain->SetBranchAddress("met_sign_met_sig_directional_ttdir", &met_sign_met_sig_directional_ttdir, &b_met_sign_met_sig_directional_ttdir);
   fChain->SetBranchAddress("met_sign_met_significance", &met_sign_met_significance, &b_met_sign_met_significance);
   fChain->SetBranchAddress("met_sign_met_significance_ttdir", &met_sign_met_significance_ttdir, &b_met_sign_met_significance_ttdir);
   fChain->SetBranchAddress("met_sign_met_valL", &met_sign_met_valL, &b_met_sign_met_valL);
   fChain->SetBranchAddress("met_sign_met_valL_ttdir", &met_sign_met_valL_ttdir, &b_met_sign_met_valL_ttdir);
   fChain->SetBranchAddress("met_sign_met_varT", &met_sign_met_varT, &b_met_sign_met_varT);
   fChain->SetBranchAddress("met_sign_met_varT_ttdir", &met_sign_met_varT_ttdir, &b_met_sign_met_varT_ttdir);
   fChain->SetBranchAddress("met_sumet", &met_sumet, &b_met_sumet);
   fChain->SetBranchAddress("met_truth_p4", &met_truth_p4, &b_met_truth_p4);
   fChain->SetBranchAddress("met_truth_sumet", &met_truth_sumet, &b_met_truth_sumet);
   fChain->SetBranchAddress("mva_RRN", &mva_RRN, &b_mva_RRN);
   fChain->SetBranchAddress("n_actual_int", &n_actual_int, &b_n_actual_int);
   fChain->SetBranchAddress("n_actual_int_cor", &n_actual_int_cor, &b_n_actual_int_cor);
   fChain->SetBranchAddress("n_avg_int", &n_avg_int, &b_n_avg_int);
   fChain->SetBranchAddress("n_avg_int_cor", &n_avg_int_cor, &b_n_avg_int_cor);
   fChain->SetBranchAddress("n_bjets", &n_bjets, &b_n_bjets);
   fChain->SetBranchAddress("n_electrons", &n_electrons, &b_n_electrons);
   fChain->SetBranchAddress("n_jets", &n_jets, &b_n_jets);
   fChain->SetBranchAddress("n_jets_30", &n_jets_30, &b_n_jets_30);
   fChain->SetBranchAddress("n_jets_40", &n_jets_40, &b_n_jets_40);
   fChain->SetBranchAddress("n_jets_central", &n_jets_central, &b_n_jets_central);
   fChain->SetBranchAddress("n_jets_central_30", &n_jets_central_30, &b_n_jets_central_30);
   fChain->SetBranchAddress("n_jets_central_40", &n_jets_central_40, &b_n_jets_central_40);
   fChain->SetBranchAddress("n_jets_forward", &n_jets_forward, &b_n_jets_forward);
   fChain->SetBranchAddress("n_jets_forward_30", &n_jets_forward_30, &b_n_jets_forward_30);
   fChain->SetBranchAddress("n_jets_forward_40", &n_jets_forward_40, &b_n_jets_forward_40);
   fChain->SetBranchAddress("n_jets_l1j25", &n_jets_l1j25, &b_n_jets_l1j25);
   fChain->SetBranchAddress("n_jets_mc_hs", &n_jets_mc_hs, &b_n_jets_mc_hs);
   fChain->SetBranchAddress("n_muons", &n_muons, &b_n_muons);
   fChain->SetBranchAddress("n_photons", &n_photons, &b_n_photons);
   fChain->SetBranchAddress("n_pvx", &n_pvx, &b_n_pvx);
   fChain->SetBranchAddress("n_taus", &n_taus, &b_n_taus);
   fChain->SetBranchAddress("n_taus_loose", &n_taus_loose, &b_n_taus_loose);
   fChain->SetBranchAddress("n_taus_medium", &n_taus_medium, &b_n_taus_medium);
   fChain->SetBranchAddress("n_taus_tight", &n_taus_tight, &b_n_taus_tight);
   fChain->SetBranchAddress("n_taus_veryloose", &n_taus_veryloose, &b_n_taus_veryloose);
   fChain->SetBranchAddress("n_truth_gluon_jets", &n_truth_gluon_jets, &b_n_truth_gluon_jets);
   fChain->SetBranchAddress("n_truth_jets", &n_truth_jets, &b_n_truth_jets);
   fChain->SetBranchAddress("n_truth_jets_pt20_eta45", &n_truth_jets_pt20_eta45, &b_n_truth_jets_pt20_eta45);
   fChain->SetBranchAddress("n_truth_quark_jets", &n_truth_quark_jets, &b_n_truth_quark_jets);
   fChain->SetBranchAddress("n_vx", &n_vx, &b_n_vx);
   fChain->SetBranchAddress("primary_vertex", &primary_vertex, &b_primary_vertex);
   fChain->SetBranchAddress("primary_vertex_v", &primary_vertex_v, &b_primary_vertex_v);
   fChain->SetBranchAddress("pt_total", &pt_total, &b_pt_total);
   fChain->SetBranchAddress("run_number", &run_number, &b_run_number);
   fChain->SetBranchAddress("scalar_sum_pt", &scalar_sum_pt, &b_scalar_sum_pt);
   fChain->SetBranchAddress("tau_0", &tau_0, &b_tau_0);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad", &tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad, &b_tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_JetBDTloose", &tau_0_NOMINAL_TauEffSF_JetBDTloose, &b_tau_0_NOMINAL_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_JetBDTmedium", &tau_0_NOMINAL_TauEffSF_JetBDTmedium, &b_tau_0_NOMINAL_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_JetBDTtight", &tau_0_NOMINAL_TauEffSF_JetBDTtight, &b_tau_0_NOMINAL_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_reco", &tau_0_NOMINAL_TauEffSF_reco, &b_tau_0_NOMINAL_TauEffSF_reco);
   fChain->SetBranchAddress("tau_0_NOMINAL_TauEffSF_selection", &tau_0_NOMINAL_TauEffSF_selection, &b_tau_0_NOMINAL_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_0_allTrk_eta", &tau_0_allTrk_eta, &b_tau_0_allTrk_eta);
   fChain->SetBranchAddress("tau_0_allTrk_n", &tau_0_allTrk_n, &b_tau_0_allTrk_n);
   fChain->SetBranchAddress("tau_0_allTrk_phi", &tau_0_allTrk_phi, &b_tau_0_allTrk_phi);
   fChain->SetBranchAddress("tau_0_allTrk_pt", &tau_0_allTrk_pt, &b_tau_0_allTrk_pt);
   fChain->SetBranchAddress("tau_0_b_tagged", &tau_0_b_tagged, &b_tau_0_b_tagged);
   fChain->SetBranchAddress("tau_0_decay_mode", &tau_0_decay_mode, &b_tau_0_decay_mode);
   fChain->SetBranchAddress("tau_0_ele_bdt_eff_sf", &tau_0_ele_bdt_eff_sf, &b_tau_0_ele_bdt_eff_sf);
   fChain->SetBranchAddress("tau_0_ele_bdt_loose_retuned", &tau_0_ele_bdt_loose_retuned, &b_tau_0_ele_bdt_loose_retuned);
   fChain->SetBranchAddress("tau_0_ele_bdt_medium_retuned", &tau_0_ele_bdt_medium_retuned, &b_tau_0_ele_bdt_medium_retuned);
   fChain->SetBranchAddress("tau_0_ele_bdt_score", &tau_0_ele_bdt_score, &b_tau_0_ele_bdt_score);
   fChain->SetBranchAddress("tau_0_ele_bdt_score_retuned", &tau_0_ele_bdt_score_retuned, &b_tau_0_ele_bdt_score_retuned);
   fChain->SetBranchAddress("tau_0_ele_bdt_score_trans", &tau_0_ele_bdt_score_trans, &b_tau_0_ele_bdt_score_trans);
   fChain->SetBranchAddress("tau_0_ele_bdt_score_trans_retuned", &tau_0_ele_bdt_score_trans_retuned, &b_tau_0_ele_bdt_score_trans_retuned);
   fChain->SetBranchAddress("tau_0_ele_bdt_tight_retuned", &tau_0_ele_bdt_tight_retuned, &b_tau_0_ele_bdt_tight_retuned);
   fChain->SetBranchAddress("tau_0_ele_match_lhscore", &tau_0_ele_match_lhscore, &b_tau_0_ele_match_lhscore);
   fChain->SetBranchAddress("tau_0_ele_olr_pass", &tau_0_ele_olr_pass, &b_tau_0_ele_olr_pass);
   fChain->SetBranchAddress("tau_0_jet_bdt_loose", &tau_0_jet_bdt_loose, &b_tau_0_jet_bdt_loose);
   fChain->SetBranchAddress("tau_0_jet_bdt_medium", &tau_0_jet_bdt_medium, &b_tau_0_jet_bdt_medium);
   fChain->SetBranchAddress("tau_0_jet_bdt_score_trans", &tau_0_jet_bdt_score_trans, &b_tau_0_jet_bdt_score_trans);
   fChain->SetBranchAddress("tau_0_jet_bdt_tight", &tau_0_jet_bdt_tight, &b_tau_0_jet_bdt_tight);
   fChain->SetBranchAddress("tau_0_jet_bdt_veryloose", &tau_0_jet_bdt_veryloose, &b_tau_0_jet_bdt_veryloose);
   fChain->SetBranchAddress("tau_0_jet_jvt", &tau_0_jet_jvt, &b_tau_0_jet_jvt);
   fChain->SetBranchAddress("tau_0_jet_rnn_loose", &tau_0_jet_rnn_loose, &b_tau_0_jet_rnn_loose);
   fChain->SetBranchAddress("tau_0_jet_rnn_medium", &tau_0_jet_rnn_medium, &b_tau_0_jet_rnn_medium);
   fChain->SetBranchAddress("tau_0_jet_rnn_score", &tau_0_jet_rnn_score, &b_tau_0_jet_rnn_score);
   fChain->SetBranchAddress("tau_0_jet_rnn_score_trans", &tau_0_jet_rnn_score_trans, &b_tau_0_jet_rnn_score_trans);
   fChain->SetBranchAddress("tau_0_jet_rnn_tight", &tau_0_jet_rnn_tight, &b_tau_0_jet_rnn_tight);
   fChain->SetBranchAddress("tau_0_jet_rnn_veryloose", &tau_0_jet_rnn_veryloose, &b_tau_0_jet_rnn_veryloose);
   fChain->SetBranchAddress("tau_0_jet_width", &tau_0_jet_width, &b_tau_0_jet_width);
   fChain->SetBranchAddress("tau_0_leadTrk_eta", &tau_0_leadTrk_eta, &b_tau_0_leadTrk_eta);
   fChain->SetBranchAddress("tau_0_leadTrk_phi", &tau_0_leadTrk_phi, &b_tau_0_leadTrk_phi);
   fChain->SetBranchAddress("tau_0_leadTrk_pt", &tau_0_leadTrk_pt, &b_tau_0_leadTrk_pt);
   fChain->SetBranchAddress("tau_0_matched", &tau_0_matched, &b_tau_0_matched);
   fChain->SetBranchAddress("tau_0_matched_classifierParticleOrigin", &tau_0_matched_classifierParticleOrigin, &b_tau_0_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("tau_0_matched_classifierParticleType", &tau_0_matched_classifierParticleType, &b_tau_0_matched_classifierParticleType);
   fChain->SetBranchAddress("tau_0_matched_decay_charged_p4", &tau_0_matched_decay_charged_p4, &b_tau_0_matched_decay_charged_p4);
   fChain->SetBranchAddress("tau_0_matched_decay_mode", &tau_0_matched_decay_mode, &b_tau_0_matched_decay_mode);
   fChain->SetBranchAddress("tau_0_matched_decay_neutral_p4", &tau_0_matched_decay_neutral_p4, &b_tau_0_matched_decay_neutral_p4);
   fChain->SetBranchAddress("tau_0_matched_decay_neutrino_p4", &tau_0_matched_decay_neutrino_p4, &b_tau_0_matched_decay_neutrino_p4);
   fChain->SetBranchAddress("tau_0_matched_isEle", &tau_0_matched_isEle, &b_tau_0_matched_isEle);
   fChain->SetBranchAddress("tau_0_matched_isHadTau", &tau_0_matched_isHadTau, &b_tau_0_matched_isHadTau);
   fChain->SetBranchAddress("tau_0_matched_isJet", &tau_0_matched_isJet, &b_tau_0_matched_isJet);
   fChain->SetBranchAddress("tau_0_matched_isMuon", &tau_0_matched_isMuon, &b_tau_0_matched_isMuon);
   fChain->SetBranchAddress("tau_0_matched_isTau", &tau_0_matched_isTau, &b_tau_0_matched_isTau);
   fChain->SetBranchAddress("tau_0_matched_isTruthMatch", &tau_0_matched_isTruthMatch, &b_tau_0_matched_isTruthMatch);
   fChain->SetBranchAddress("tau_0_matched_mother_pdgId", &tau_0_matched_mother_pdgId, &b_tau_0_matched_mother_pdgId);
   fChain->SetBranchAddress("tau_0_matched_mother_status", &tau_0_matched_mother_status, &b_tau_0_matched_mother_status);
   fChain->SetBranchAddress("tau_0_matched_n_charged", &tau_0_matched_n_charged, &b_tau_0_matched_n_charged);
   fChain->SetBranchAddress("tau_0_matched_n_charged_pion", &tau_0_matched_n_charged_pion, &b_tau_0_matched_n_charged_pion);
   fChain->SetBranchAddress("tau_0_matched_n_neutral", &tau_0_matched_n_neutral, &b_tau_0_matched_n_neutral);
   fChain->SetBranchAddress("tau_0_matched_n_neutral_pion", &tau_0_matched_n_neutral_pion, &b_tau_0_matched_n_neutral_pion);
   fChain->SetBranchAddress("tau_0_matched_p4", &tau_0_matched_p4, &b_tau_0_matched_p4);
   fChain->SetBranchAddress("tau_0_matched_p4_vis_charged_track0", &tau_0_matched_p4_vis_charged_track0, &b_tau_0_matched_p4_vis_charged_track0);
   fChain->SetBranchAddress("tau_0_matched_p4_vis_charged_track1", &tau_0_matched_p4_vis_charged_track1, &b_tau_0_matched_p4_vis_charged_track1);
   fChain->SetBranchAddress("tau_0_matched_p4_vis_charged_track2", &tau_0_matched_p4_vis_charged_track2, &b_tau_0_matched_p4_vis_charged_track2);
   fChain->SetBranchAddress("tau_0_matched_pdgId", &tau_0_matched_pdgId, &b_tau_0_matched_pdgId);
   fChain->SetBranchAddress("tau_0_matched_q", &tau_0_matched_q, &b_tau_0_matched_q);
   fChain->SetBranchAddress("tau_0_matched_status", &tau_0_matched_status, &b_tau_0_matched_status);
   fChain->SetBranchAddress("tau_0_matched_type", &tau_0_matched_type, &b_tau_0_matched_type);
   fChain->SetBranchAddress("tau_0_matched_vis_charged_p4", &tau_0_matched_vis_charged_p4, &b_tau_0_matched_vis_charged_p4);
   fChain->SetBranchAddress("tau_0_matched_vis_neutral_others_p4", &tau_0_matched_vis_neutral_others_p4, &b_tau_0_matched_vis_neutral_others_p4);
   fChain->SetBranchAddress("tau_0_matched_vis_neutral_p4", &tau_0_matched_vis_neutral_p4, &b_tau_0_matched_vis_neutral_p4);
   fChain->SetBranchAddress("tau_0_matched_vis_neutral_pions_p4", &tau_0_matched_vis_neutral_pions_p4, &b_tau_0_matched_vis_neutral_pions_p4);
   fChain->SetBranchAddress("tau_0_matched_vis_p4", &tau_0_matched_vis_p4, &b_tau_0_matched_vis_p4);
   fChain->SetBranchAddress("tau_0_n_all_tracks", &tau_0_n_all_tracks, &b_tau_0_n_all_tracks);
   fChain->SetBranchAddress("tau_0_n_charged_tracks", &tau_0_n_charged_tracks, &b_tau_0_n_charged_tracks);
   fChain->SetBranchAddress("tau_0_n_conversion_tracks", &tau_0_n_conversion_tracks, &b_tau_0_n_conversion_tracks);
   fChain->SetBranchAddress("tau_0_n_core_tracks", &tau_0_n_core_tracks, &b_tau_0_n_core_tracks);
   fChain->SetBranchAddress("tau_0_n_failTrackFilter_tracks", &tau_0_n_failTrackFilter_tracks, &b_tau_0_n_failTrackFilter_tracks);
   fChain->SetBranchAddress("tau_0_n_fake_tracks", &tau_0_n_fake_tracks, &b_tau_0_n_fake_tracks);
   fChain->SetBranchAddress("tau_0_n_isolation_tracks", &tau_0_n_isolation_tracks, &b_tau_0_n_isolation_tracks);
   fChain->SetBranchAddress("tau_0_n_modified_isolation_tracks", &tau_0_n_modified_isolation_tracks, &b_tau_0_n_modified_isolation_tracks);
   fChain->SetBranchAddress("tau_0_n_old_tracks", &tau_0_n_old_tracks, &b_tau_0_n_old_tracks);
   fChain->SetBranchAddress("tau_0_n_passTrkSelectionTight_tracks", &tau_0_n_passTrkSelectionTight_tracks, &b_tau_0_n_passTrkSelectionTight_tracks);
   fChain->SetBranchAddress("tau_0_n_passTrkSelector_tracks", &tau_0_n_passTrkSelector_tracks, &b_tau_0_n_passTrkSelector_tracks);
   fChain->SetBranchAddress("tau_0_n_unclassified_tracks", &tau_0_n_unclassified_tracks, &b_tau_0_n_unclassified_tracks);
   fChain->SetBranchAddress("tau_0_n_wide_tracks", &tau_0_n_wide_tracks, &b_tau_0_n_wide_tracks);
   fChain->SetBranchAddress("tau_0_origin", &tau_0_origin, &b_tau_0_origin);
   fChain->SetBranchAddress("tau_0_p4", &tau_0_p4, &b_tau_0_p4);
   fChain->SetBranchAddress("tau_0_q", &tau_0_q, &b_tau_0_q);
   fChain->SetBranchAddress("tau_0_track0_p4", &tau_0_track0_p4, &b_tau_0_track0_p4);
   fChain->SetBranchAddress("tau_0_track1_p4", &tau_0_track1_p4, &b_tau_0_track1_p4);
   fChain->SetBranchAddress("tau_0_track2_p4", &tau_0_track2_p4, &b_tau_0_track2_p4);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau25_medium1_tracktwo", &tau_0_trig_HLT_tau25_medium1_tracktwo, &b_tau_0_trig_HLT_tau25_medium1_tracktwo);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo", &tau_0_trig_HLT_tau35_medium1_tracktwo, &b_tau_0_trig_HLT_tau35_medium1_tracktwo);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25);
   fChain->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM);
   fChain->SetBranchAddress("tau_0_trig_trigger_matched", &tau_0_trig_trigger_matched, &b_tau_0_trig_trigger_matched);
   fChain->SetBranchAddress("tau_0_type", &tau_0_type, &b_tau_0_type);
   fChain->SetBranchAddress("tau_1", &tau_1, &b_tau_1);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad", &tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad, &b_tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_JetBDTloose", &tau_1_NOMINAL_TauEffSF_JetBDTloose, &b_tau_1_NOMINAL_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_JetBDTmedium", &tau_1_NOMINAL_TauEffSF_JetBDTmedium, &b_tau_1_NOMINAL_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_JetBDTtight", &tau_1_NOMINAL_TauEffSF_JetBDTtight, &b_tau_1_NOMINAL_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_reco", &tau_1_NOMINAL_TauEffSF_reco, &b_tau_1_NOMINAL_TauEffSF_reco);
   fChain->SetBranchAddress("tau_1_NOMINAL_TauEffSF_selection", &tau_1_NOMINAL_TauEffSF_selection, &b_tau_1_NOMINAL_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
   fChain->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
   fChain->SetBranchAddress("tau_1_allTrk_eta", &tau_1_allTrk_eta, &b_tau_1_allTrk_eta);
   fChain->SetBranchAddress("tau_1_allTrk_n", &tau_1_allTrk_n, &b_tau_1_allTrk_n);
   fChain->SetBranchAddress("tau_1_allTrk_phi", &tau_1_allTrk_phi, &b_tau_1_allTrk_phi);
   fChain->SetBranchAddress("tau_1_allTrk_pt", &tau_1_allTrk_pt, &b_tau_1_allTrk_pt);
   fChain->SetBranchAddress("tau_1_b_tagged", &tau_1_b_tagged, &b_tau_1_b_tagged);
   fChain->SetBranchAddress("tau_1_decay_mode", &tau_1_decay_mode, &b_tau_1_decay_mode);
   fChain->SetBranchAddress("tau_1_ele_bdt_eff_sf", &tau_1_ele_bdt_eff_sf, &b_tau_1_ele_bdt_eff_sf);
   fChain->SetBranchAddress("tau_1_ele_bdt_loose_retuned", &tau_1_ele_bdt_loose_retuned, &b_tau_1_ele_bdt_loose_retuned);
   fChain->SetBranchAddress("tau_1_ele_bdt_medium_retuned", &tau_1_ele_bdt_medium_retuned, &b_tau_1_ele_bdt_medium_retuned);
   fChain->SetBranchAddress("tau_1_ele_bdt_score", &tau_1_ele_bdt_score, &b_tau_1_ele_bdt_score);
   fChain->SetBranchAddress("tau_1_ele_bdt_score_retuned", &tau_1_ele_bdt_score_retuned, &b_tau_1_ele_bdt_score_retuned);
   fChain->SetBranchAddress("tau_1_ele_bdt_score_trans", &tau_1_ele_bdt_score_trans, &b_tau_1_ele_bdt_score_trans);
   fChain->SetBranchAddress("tau_1_ele_bdt_score_trans_retuned", &tau_1_ele_bdt_score_trans_retuned, &b_tau_1_ele_bdt_score_trans_retuned);
   fChain->SetBranchAddress("tau_1_ele_bdt_tight_retuned", &tau_1_ele_bdt_tight_retuned, &b_tau_1_ele_bdt_tight_retuned);
   fChain->SetBranchAddress("tau_1_ele_match_lhscore", &tau_1_ele_match_lhscore, &b_tau_1_ele_match_lhscore);
   fChain->SetBranchAddress("tau_1_ele_olr_pass", &tau_1_ele_olr_pass, &b_tau_1_ele_olr_pass);
   fChain->SetBranchAddress("tau_1_jet_bdt_loose", &tau_1_jet_bdt_loose, &b_tau_1_jet_bdt_loose);
   fChain->SetBranchAddress("tau_1_jet_bdt_medium", &tau_1_jet_bdt_medium, &b_tau_1_jet_bdt_medium);
   fChain->SetBranchAddress("tau_1_jet_bdt_score_trans", &tau_1_jet_bdt_score_trans, &b_tau_1_jet_bdt_score_trans);
   fChain->SetBranchAddress("tau_1_jet_bdt_tight", &tau_1_jet_bdt_tight, &b_tau_1_jet_bdt_tight);
   fChain->SetBranchAddress("tau_1_jet_bdt_veryloose", &tau_1_jet_bdt_veryloose, &b_tau_1_jet_bdt_veryloose);
   fChain->SetBranchAddress("tau_1_jet_jvt", &tau_1_jet_jvt, &b_tau_1_jet_jvt);
   fChain->SetBranchAddress("tau_1_jet_rnn_loose", &tau_1_jet_rnn_loose, &b_tau_1_jet_rnn_loose);
   fChain->SetBranchAddress("tau_1_jet_rnn_medium", &tau_1_jet_rnn_medium, &b_tau_1_jet_rnn_medium);
   fChain->SetBranchAddress("tau_1_jet_rnn_score", &tau_1_jet_rnn_score, &b_tau_1_jet_rnn_score);
   fChain->SetBranchAddress("tau_1_jet_rnn_score_trans", &tau_1_jet_rnn_score_trans, &b_tau_1_jet_rnn_score_trans);
   fChain->SetBranchAddress("tau_1_jet_rnn_tight", &tau_1_jet_rnn_tight, &b_tau_1_jet_rnn_tight);
   fChain->SetBranchAddress("tau_1_jet_rnn_veryloose", &tau_1_jet_rnn_veryloose, &b_tau_1_jet_rnn_veryloose);
   fChain->SetBranchAddress("tau_1_jet_width", &tau_1_jet_width, &b_tau_1_jet_width);
   fChain->SetBranchAddress("tau_1_leadTrk_eta", &tau_1_leadTrk_eta, &b_tau_1_leadTrk_eta);
   fChain->SetBranchAddress("tau_1_leadTrk_phi", &tau_1_leadTrk_phi, &b_tau_1_leadTrk_phi);
   fChain->SetBranchAddress("tau_1_leadTrk_pt", &tau_1_leadTrk_pt, &b_tau_1_leadTrk_pt);
   fChain->SetBranchAddress("tau_1_matched", &tau_1_matched, &b_tau_1_matched);
   fChain->SetBranchAddress("tau_1_matched_classifierParticleOrigin", &tau_1_matched_classifierParticleOrigin, &b_tau_1_matched_classifierParticleOrigin);
   fChain->SetBranchAddress("tau_1_matched_classifierParticleType", &tau_1_matched_classifierParticleType, &b_tau_1_matched_classifierParticleType);
   fChain->SetBranchAddress("tau_1_matched_decay_charged_p4", &tau_1_matched_decay_charged_p4, &b_tau_1_matched_decay_charged_p4);
   fChain->SetBranchAddress("tau_1_matched_decay_mode", &tau_1_matched_decay_mode, &b_tau_1_matched_decay_mode);
   fChain->SetBranchAddress("tau_1_matched_decay_neutral_p4", &tau_1_matched_decay_neutral_p4, &b_tau_1_matched_decay_neutral_p4);
   fChain->SetBranchAddress("tau_1_matched_decay_neutrino_p4", &tau_1_matched_decay_neutrino_p4, &b_tau_1_matched_decay_neutrino_p4);
   fChain->SetBranchAddress("tau_1_matched_isEle", &tau_1_matched_isEle, &b_tau_1_matched_isEle);
   fChain->SetBranchAddress("tau_1_matched_isHadTau", &tau_1_matched_isHadTau, &b_tau_1_matched_isHadTau);
   fChain->SetBranchAddress("tau_1_matched_isJet", &tau_1_matched_isJet, &b_tau_1_matched_isJet);
   fChain->SetBranchAddress("tau_1_matched_isMuon", &tau_1_matched_isMuon, &b_tau_1_matched_isMuon);
   fChain->SetBranchAddress("tau_1_matched_isTau", &tau_1_matched_isTau, &b_tau_1_matched_isTau);
   fChain->SetBranchAddress("tau_1_matched_isTruthMatch", &tau_1_matched_isTruthMatch, &b_tau_1_matched_isTruthMatch);
   fChain->SetBranchAddress("tau_1_matched_mother_pdgId", &tau_1_matched_mother_pdgId, &b_tau_1_matched_mother_pdgId);
   fChain->SetBranchAddress("tau_1_matched_mother_status", &tau_1_matched_mother_status, &b_tau_1_matched_mother_status);
   fChain->SetBranchAddress("tau_1_matched_n_charged", &tau_1_matched_n_charged, &b_tau_1_matched_n_charged);
   fChain->SetBranchAddress("tau_1_matched_n_charged_pion", &tau_1_matched_n_charged_pion, &b_tau_1_matched_n_charged_pion);
   fChain->SetBranchAddress("tau_1_matched_n_neutral", &tau_1_matched_n_neutral, &b_tau_1_matched_n_neutral);
   fChain->SetBranchAddress("tau_1_matched_n_neutral_pion", &tau_1_matched_n_neutral_pion, &b_tau_1_matched_n_neutral_pion);
   fChain->SetBranchAddress("tau_1_matched_p4", &tau_1_matched_p4, &b_tau_1_matched_p4);
   fChain->SetBranchAddress("tau_1_matched_p4_vis_charged_track0", &tau_1_matched_p4_vis_charged_track0, &b_tau_1_matched_p4_vis_charged_track0);
   fChain->SetBranchAddress("tau_1_matched_p4_vis_charged_track1", &tau_1_matched_p4_vis_charged_track1, &b_tau_1_matched_p4_vis_charged_track1);
   fChain->SetBranchAddress("tau_1_matched_p4_vis_charged_track2", &tau_1_matched_p4_vis_charged_track2, &b_tau_1_matched_p4_vis_charged_track2);
   fChain->SetBranchAddress("tau_1_matched_pdgId", &tau_1_matched_pdgId, &b_tau_1_matched_pdgId);
   fChain->SetBranchAddress("tau_1_matched_pz", &tau_1_matched_pz, &b_tau_1_matched_pz);
   fChain->SetBranchAddress("tau_1_matched_q", &tau_1_matched_q, &b_tau_1_matched_q);
   fChain->SetBranchAddress("tau_1_matched_status", &tau_1_matched_status, &b_tau_1_matched_status);
   fChain->SetBranchAddress("tau_1_matched_vis_charged_p4", &tau_1_matched_vis_charged_p4, &b_tau_1_matched_vis_charged_p4);
   fChain->SetBranchAddress("tau_1_matched_vis_neutral_others_p4", &tau_1_matched_vis_neutral_others_p4, &b_tau_1_matched_vis_neutral_others_p4);
   fChain->SetBranchAddress("tau_1_matched_vis_neutral_p4", &tau_1_matched_vis_neutral_p4, &b_tau_1_matched_vis_neutral_p4);
   fChain->SetBranchAddress("tau_1_matched_vis_neutral_pions_p4", &tau_1_matched_vis_neutral_pions_p4, &b_tau_1_matched_vis_neutral_pions_p4);
   fChain->SetBranchAddress("tau_1_matched_vis_p4", &tau_1_matched_vis_p4, &b_tau_1_matched_vis_p4);
   fChain->SetBranchAddress("tau_1_n_all_tracks", &tau_1_n_all_tracks, &b_tau_1_n_all_tracks);
   fChain->SetBranchAddress("tau_1_n_charged_tracks", &tau_1_n_charged_tracks, &b_tau_1_n_charged_tracks);
   fChain->SetBranchAddress("tau_1_n_conversion_tracks", &tau_1_n_conversion_tracks, &b_tau_1_n_conversion_tracks);
   fChain->SetBranchAddress("tau_1_n_core_tracks", &tau_1_n_core_tracks, &b_tau_1_n_core_tracks);
   fChain->SetBranchAddress("tau_1_n_failTrackFilter_tracks", &tau_1_n_failTrackFilter_tracks, &b_tau_1_n_failTrackFilter_tracks);
   fChain->SetBranchAddress("tau_1_n_fake_tracks", &tau_1_n_fake_tracks, &b_tau_1_n_fake_tracks);
   fChain->SetBranchAddress("tau_1_n_isolation_tracks", &tau_1_n_isolation_tracks, &b_tau_1_n_isolation_tracks);
   fChain->SetBranchAddress("tau_1_n_modified_isolation_tracks", &tau_1_n_modified_isolation_tracks, &b_tau_1_n_modified_isolation_tracks);
   fChain->SetBranchAddress("tau_1_n_old_tracks", &tau_1_n_old_tracks, &b_tau_1_n_old_tracks);
   fChain->SetBranchAddress("tau_1_n_passTrkSelectionTight_tracks", &tau_1_n_passTrkSelectionTight_tracks, &b_tau_1_n_passTrkSelectionTight_tracks);
   fChain->SetBranchAddress("tau_1_n_passTrkSelector_tracks", &tau_1_n_passTrkSelector_tracks, &b_tau_1_n_passTrkSelector_tracks);
   fChain->SetBranchAddress("tau_1_n_unclassified_tracks", &tau_1_n_unclassified_tracks, &b_tau_1_n_unclassified_tracks);
   fChain->SetBranchAddress("tau_1_n_wide_tracks", &tau_1_n_wide_tracks, &b_tau_1_n_wide_tracks);
   fChain->SetBranchAddress("tau_1_origin", &tau_1_origin, &b_tau_1_origin);
   fChain->SetBranchAddress("tau_1_p4", &tau_1_p4, &b_tau_1_p4);
   fChain->SetBranchAddress("tau_1_q", &tau_1_q, &b_tau_1_q);
   fChain->SetBranchAddress("tau_1_track0_p4", &tau_1_track0_p4, &b_tau_1_track0_p4);
   fChain->SetBranchAddress("tau_1_track1_p4", &tau_1_track1_p4, &b_tau_1_track1_p4);
   fChain->SetBranchAddress("tau_1_track2_p4", &tau_1_track2_p4, &b_tau_1_track2_p4);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau25_medium1_tracktwo", &tau_1_trig_HLT_tau25_medium1_tracktwo, &b_tau_1_trig_HLT_tau25_medium1_tracktwo);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo", &tau_1_trig_HLT_tau35_medium1_tracktwo, &b_tau_1_trig_HLT_tau35_medium1_tracktwo);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25);
   fChain->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM);
   fChain->SetBranchAddress("tau_1_trig_trigger_matched", &tau_1_trig_trigger_matched, &b_tau_1_trig_trigger_matched);
   fChain->SetBranchAddress("tau_1_type", &tau_1_type, &b_tau_1_type);
   fChain->SetBranchAddress("tau_eta_centrality", &tau_eta_centrality, &b_tau_eta_centrality);
   fChain->SetBranchAddress("theory_weights_CT14_pdfset", &theory_weights_CT14_pdfset, &b_theory_weights_CT14_pdfset);
   fChain->SetBranchAddress("theory_weights_MMHT_pdfset", &theory_weights_MMHT_pdfset, &b_theory_weights_MMHT_pdfset);
   fChain->SetBranchAddress("theory_weights_PDF_central_value", &theory_weights_PDF_central_value, &b_theory_weights_PDF_central_value);
   fChain->SetBranchAddress("theory_weights_PDF_error_down", &theory_weights_PDF_error_down, &b_theory_weights_PDF_error_down);
   fChain->SetBranchAddress("theory_weights_PDF_error_up", &theory_weights_PDF_error_up, &b_theory_weights_PDF_error_up);
   fChain->SetBranchAddress("theory_weights_alphaS_down", &theory_weights_alphaS_down, &b_theory_weights_alphaS_down);
   fChain->SetBranchAddress("theory_weights_alphaS_up", &theory_weights_alphaS_up, &b_theory_weights_alphaS_up);
   fChain->SetBranchAddress("truth_passedVBFFilter", &truth_passedVBFFilter, &b_truth_passedVBFFilter);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
}
