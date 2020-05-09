#include "tthmltree.h"
#define nominal_cxx
#include "TH2F.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcnc_include.h"
using namespace std;
tthmltree::tthmltree():nominal::nominal(){
  defGeV(1000);
  dofit1l2tau = 0;
  weights = new vector<double> ();
  initialize_fit(TString(PACKAGE_DIR) + "/data/tau_pars.root");

  belong_regions.m_region_map["SR"] = {"reg1l1tau1b2j_os","reg1l1tau1b3j_os","reg1l2tau1bnj_os","reg2lSS1tau1bnj_os","reg2l1tau1bnj"};
  belong_regions.m_region_map["SRCR"] = {
    "reg1l1tau1b2j_ss",
    "reg1l1tau1b3j_ss",
    "reg1l1tau2b2j_os",
    "reg1l1tau2b3j_os",
    "reg1l1tau2b2j_ss",
    "reg1l1tau2b3j_ss",
    "reg1l1tau2b2j_os_85",
    "reg1l1tau2b3j_os_85",
    "reg1l1tau2b2j_ss_85",
    "reg1l1tau2b3j_ss_85",
    "reg1l2tau1bnj_ss",
    "reg1l2tau2bnj_os",
    "reg1l2tau2bnj_ss",
    "reg2lSS1tau2bnj_os",
    "reg2lSS1tau2bnj_ss",
    "reg2lSS1tau1bnj_ss",
    "reg2lSS1tau2bnj_os_antitight",
    "reg2lSS1tau2bnj_ss_antitight",
    "reg2lSS1tau1bnj_ss_antitight",
    "reg2lSS1tau1bnj_os_antitight",
    "reg2l1tau2bnj"
  };
  belong_regions.m_region_map["FakeCR"] = {
    "reg1l1tau2b1j_os",
    "reg1l1tau2b1j_ss",
    "reg1l1tau2b_os",
    "reg1l1tau2b_ss",
    "reg2l1tau2b",
    "reg2l2bnj",
    "reg2l1tau1b",
    "reg2l2b"
  };

}

void tthmltree::init_hist(TString outputfilename){
  //init histSaver here:
  dohist = 1;

  fcnc_nregions = fcnc_regions.size();

  TString nprong[] = {"1prong","3prong"};
  
  if(reduce == 3 && doBDT){
    initMVA("reg1l2tau1bnj_os");
    initMVA("reg1l1tau1b2j_os");
    initMVA("reg1l1tau1b3j_os");
  }
  if(fcnc_nregions && plotNPs.size()){
    fcnc_plots = new histSaver(outputfilename + "_fcnc");
    fcnc_plots->set_weight(&weight);
    fcnc_plots->debug = !!debug;
    if(reduce == 3 && doBDT) fcnc_plots->add(100,-1.,1.,"BDT discriminant","BDTG_train",&BDTG_train,false,"");
    if(reduce == 3 && doBDT) fcnc_plots->add(100,-1.,1.,"BDT discriminant","BDTG_test",&BDTG_test,false,"");
    if(reduce >= 2) {
      fcnc_plots->add(100,5.,55.,"#chi^2","chi2",&chi2,false,"");
      fcnc_plots->add(500,200.,1200.,"m_{all}","allmass",&allmass,true,"GeV");
      fcnc_plots->add(500,0.,1000.,"P_{z,all}","allpz",&allpz,true,"GeV");
      fcnc_plots->add(20,20.,120.,"m_{#tau,light-jet}","taulmass",&taulmass,true,"GeV");
    }
    fcnc_plots->add(10,25.,125.,"p_{T,#tau}","taupt_0",&tau_pt_0,true,"GeV");
    fcnc_plots->add(10,25.,125.,"p_{T,#tau}","taupt_1",&tau_pt_1,true,"GeV");
    fcnc_plots->add(10,25.,125.,"p_{T,SS#tau}","tauptss",&tau_pt_ss,true,"GeV");
    fcnc_plots->add(10,25.,125.,"p_{T,OS#tau}","tauptos",&tau_pt_os,true,"GeV");
    fcnc_plots->add(100,100.,300.,"m_{t,SM}","t1mass",&t1mass,true,"GeV");
    fcnc_plots->add(100,0.,200.,"m^{T}_{W}","mtw",&mtw,true,"GeV");
    fcnc_plots->add(100,50.,250.,"m_{#tau,#tau}","tautaumass",&tautaumass,true,"GeV");
    fcnc_plots->add(100,0.,250.,"m_{W}","wmass",&wmass,true,"GeV");
    fcnc_plots->add(150,120.,270.,"m_{t,FCNC}","t2mass",&t2mass,true,"GeV");
    fcnc_plots->add(100,25.,125.,"m_{#tau#tau,vis}","tautauvismass",&ttvismass,true,"GeV");
    fcnc_plots->add(100,0.,200.,"P_{t,#tau#tau,vis}","tautauvispt",&tautauvispt,true,"GeV");
    fcnc_plots->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,true,"GeV");
    fcnc_plots->add(150,40.,190.,"m_{t,SM,vis}","t1vismass",&t1vismass,true,"GeV");
    fcnc_plots->add(100,0.,1.,"E_{#nu,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
    fcnc_plots->add(100,0.,1.,"E_{#nu,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
    fcnc_plots->add(60,0.,6.,"#DeltaR(l+b-jet,#tau+#tau)","drlbditau",&drlbditau,false,"");
    fcnc_plots->add(60,0.,6.,"#DeltaR(l,b-jet)","drlb",&drlb,false,"");
    fcnc_plots->add(60,0.,6.,"#DeltaR(l,b-jet)","drtaub",&drtaub,false,"");
    fcnc_plots->add(100,0.,2.5,"#eta_{#tau,max}","etamax",&etamax,false,"");
    fcnc_plots->add(72,0.4,4.,"#DeltaR(l,#tau)","drltau",&drltau,false,"");
    fcnc_plots->add(120,0.,6.,"#DeltaR(#tau,fcnc-j)","drtauj",&drtauj,false,"");
    fcnc_plots->add(92,0.4,5.,"#DeltaR(#tau,#tau)","drtautau",&drtautau,false,"");
    fcnc_plots->add(60,0.4,3.4,"#DeltaR(#tau,#light-jet,min)","drtaujmin",&drtaujmin,false,"");
    fcnc_plots->add(100,50.,250.,"M(#tau#tau#light-jet,min)","mtaujmin",&mtaujmin,true,"GeV");
    fcnc_plots->add(100,20.,200.,"M(light-jet,light-jet,min)","mjjmin",&mjjmin,true,"GeV");
    fcnc_plots->add(10,0.,10.,"N_{l-jet}","njet",&nljet,false,"");
    fcnc_plots->add(100,15.,115.,"E^{T}_{miss}","etmiss",&etmiss,true,"GeV");
    fcnc_plots->add(60,0.,3.,"#Delta#phi(#tau#tau,P^{T}_{miss})","dphitauetmiss",&dphitauetmiss,false);
    fcnc_plots->add(60,-1.5,1.5,"E^{T}_{miss} centrality","phicent",&phicent,false,"");
    for (int j = 0; j < fcnc_nregions; ++j){
      for (int k = 0; k < 2; ++k)
      {
        for (int i = 0; i < 4; ++i)
        {
          for (int iptbin = 0; iptbin < 2; ++iptbin)
          {
            if(debug) printf("adding region: %s\n", (fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
            if(dobwp[bwps[i]]) fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
            if(dovetobwp[bwps[i]]) fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
          }
        }
      }
    }
  }

  fake_nregions_notau = fake_regions_notau.size();
  if(fake_nregions_notau){
    fake_notau_plots = new histSaver(outputfilename + "_fake_notau");
    fake_notau_plots->set_weight(&weight);
    fake_notau_plots->debug = !!debug;
    fake_notau_plots->add(10,0.,200.,"p_{T,b}","bpt",&pt_b,true,"GeV");
    fake_notau_plots->add(10,0.,200.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
    for (int j = 0; j < fake_nregions_notau; ++j){
      fake_notau_plots->add_region(fake_regions_notau[j]);
    }
  }

  fake_nregions = fake_regions.size();
  if(fake_nregions){
    fake_plots = new histSaver(outputfilename + "_fake");
    fake_plots->set_weight(&weight);
    fake_plots->debug = !!debug;
    fake_plots->add(10,25.,125.,"p_{T,#tau}","taupt_0",&tau_pt_0,true,"GeV");
    fake_plots->add(10,25.,125.,"p_{T,b}","bpt",&pt_b,true,"GeV");
    fake_plots->add(10,25.,125.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
    fake_plots->add(20,20.,120.,"m_{#tau,light-jet}","taulmass",&taulmass,true,"GeV");
    fake_plots->add(100,0.,100.,"E_{miss}^{T}","met",&MET_RefFinal_et,true,"GeV");
    for (int j = 0; j < fake_nregions; ++j){
      for (int k = 0; k < 2; ++k){
        for (int i = 0; i < 4; i+=1){
          for (int iptbin = 0; iptbin < 2; ++iptbin)
          {
            if(dobwp[bwps[i]]) fake_plots->add_region(fake_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
            if(dovetobwp[bwps[i]]) fake_plots->add_region(fake_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
          }
        }
      }
    }
  }
}
void tthmltree::init_sample(TString sample, TString sampletitle){
//==========================init output n-tuple==========================
  if(reduce == 1) initReduce1();
  fcnc_nregions = fcnc_regions.size();
  fake_nregions = fake_regions.size();
  fake_nregions_notau = fake_regions_notau.size();

  if(writetree){
    TString outdir=TString(PACKAGE_DIR) + "/data/tthMLreduce" + char('0' + reduce);
    gSystem->mkdir(outdir);
    gSystem->mkdir(outdir + "/" + SystematicsName);
    TString outfile=(outdir + "/" + SystematicsName + "/" + sample + "_tree.root").Data();
    printf("create outputfile: %s\n", outfile.Data());
    outputtreefile = new TFile(outfile,"recreate");
    for (int i = 0; i < fcnc_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n",fcnc_regions[i].Data());
      TTree *target = new TTree(fcnc_regions[i],fcnc_regions[i]);
      outputtree[fcnc_regions[i]] = target;
      if(reduce==1) {
        definetree(target);
        if(nominaltree) {
          target->Branch("taumatchwjet", &taumatchwjet);
          if(fcnc_regions[i].Contains("2tau")) target->Branch("subtaumatchwjet", &subtaumatchwjet);
        }
        vecBranch(target);
      }
      if(reduce==2 ){
        if(sample.Contains("data")) target->Branch("runNumber", &runNumber);
        target->Branch("taumatchwjet", &taumatchwjet);
        if(fcnc_regions[i].Contains("2tau")) target->Branch("subtaumatchwjet", &subtaumatchwjet);
        target->Branch("chi2",&chi2);
        target->Branch("allmass", &allmass);
        target->Branch("allpz", &allpz);
        target->Branch("t1mass",&t1mass);
        target->Branch("tautaumass",&tautaumass);
        target->Branch("wmass",&wmass);
        target->Branch("t2mass",&t2mass);
        target->Branch("tau_truthType_0",&tau_truthType_0);
        target->Branch("tau_numTrack_0", & tau_numTrack_0);
        target->Branch("tau_truthType_1",&tau_truthType_1);
        target->Branch("tau_charge_0",&tau_charge_0);
        target->Branch("tau_charge_1",&tau_charge_1);
        target->Branch("tau_JetBDTSigTight_0",&tau_JetBDTSigTight_0);
        target->Branch("tau_JetBDTSigTight_1",&tau_JetBDTSigTight_1);
        target->Branch("eventNumber", &eventNumber);
        target->Branch("weights",&weights);
        target->Branch("ljet_indice", &ljet_indice );
        target->Branch("x1fit", &x1fit);
        target->Branch("tau_pt_0", &tau_pt_0);
        target->Branch("tau_pt_1", &tau_pt_1);
        target->Branch("x2fit", &x2fit);
        target->Branch("t1vismass",&t1vismass);
        target->Branch("t2vismass",&t2vismass);
        target->Branch("ttvismass",&ttvismass);
        target->Branch("tautauvispt",&tautauvispt);
        target->Branch("mtw",&mtw);
        target->Branch("tau_pt_ss",&tau_pt_ss);
        target->Branch("tau_pt_os",&tau_pt_os);
        target->Branch("drlbditau", &drlbditau);
        target->Branch("drlb", &drlb);
        target->Branch("drtaub", &drtaub);
        target->Branch("etamax", &etamax);
        target->Branch("drltau",&drltau);
        target->Branch("drtauj",&drtauj);
        target->Branch("drtautau",&drtautau);
        target->Branch("drtaujmin", &drtaujmin);
        target->Branch("mtaujmin", &mtaujmin);
        target->Branch("mjjmin", &mjjmin);
        target->Branch("etmiss",&etmiss);
        target->Branch("dphitauetmiss",&dphitauetmiss);
        target->Branch("phicent",&phicent);
        target->Branch("mc_channel_number", &mc_channel_number);
        target->Branch("nljet", &nljet);
        target->Branch("tau_truthJetFlavour_0", & tau_truthJetFlavour_0);
        target->Branch("PLV_0", &lep_promptLeptonVeto_TagWeight_0);
        target->Branch("PLV_1", &lep_promptLeptonVeto_TagWeight_1);
        target->Branch("lep_ID_0",&lep_ID_0);
        target->Branch("lep_ID_1",&lep_ID_1);
        target->Branch("taulmass", &taulmass);
        target->Branch("nTaus_OR_Pt25", &nTaus_OR_Pt25);
      }
    }

    for (int i = 0; i < fake_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions[i].Data());
      TTree* target = 0;
      if (outputtreefile->Get(fake_regions[i])) {
        target = (TTree*)(outputtreefile->Get(fake_regions[i]));
        Init(target);
      }else{
        target = new TTree(fake_regions[i],fake_regions[i]);
        definetree(target);
        target->Branch("taumatchwjet", &taumatchwjet);
        if(fake_regions[i].Contains("2tau")) target->Branch("subtaumatchwjet", &subtaumatchwjet);
      }
      outputtree[fake_regions[i]] = target;
    }
    for (int i = 0; i < fake_nregions_notau; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions_notau[i].Data());
      if (outputtreefile->Get(fake_regions_notau[i])) {
        outputtree[fake_regions_notau[i]] = (TTree*)(outputtreefile->Get(fake_regions_notau[i]));
        Init(outputtree[fake_regions_notau[i]]);
      }else{
        outputtree[fake_regions_notau[i]] = new TTree(fake_regions_notau[i],fake_regions_notau[i]);
        definetree(outputtree[fake_regions_notau[i]]);
      }
    }
  }
//==========================init output histogram==========================
  if(dohist){
    if (sample.Contains("data"))
    {
      if(fcnc_nregions && plotNPs.size()) fcnc_plots->init_sample("data","NOMINAL","data",kBlack);
      if(fake_nregions) fake_plots->init_sample("data","NOMINAL","data",kBlack);
      if(fake_nregions_notau) fake_notau_plots->init_sample("data","NOMINAL","data",kBlue);
      initdata = 1;
    }else{
      if(sample.Contains("ttbar")) sample = "ttbar";
      else sample.Remove(0,6);
      if(fcnc_nregions){
        fcnc_plots->init_sample(sample + "_g",plotNPs[0],sampletitle + "(gluon fake #tau)",(enum EColor)7);
        fcnc_plots->init_sample(sample + "_j",plotNPs[0],sampletitle + "(light-jet fake #tau)",kBlue);
        fcnc_plots->init_sample(sample + "_b",plotNPs[0],sampletitle + "(b-jets fake #tau)",kViolet);
        fcnc_plots->init_sample(sample + "_lep",plotNPs[0],sampletitle + "(lepton fake #tau)",kGreen);
        fcnc_plots->init_sample(sample + "_real",plotNPs[0],sampletitle + "(real #tau)",kRed);
        fcnc_plots->init_sample(sample + "_c",plotNPs[0],sampletitle + "(c-jets fake #tau)",kOrange);
        fcnc_plots->init_sample(sample + "_wjet",plotNPs[0],sampletitle + "(w-jet matched fake #tau)",kGray);
        fcnc_plots->init_sample(sample + "_doublefake",plotNPs[0],sampletitle + "double fake #tau)",kGray);
      }
      if(fake_nregions){
        fake_plots->init_sample(sample + "_g","NOMINAL",sampletitle + "(gluon fake #tau)",(enum EColor)7);
        fake_plots->init_sample(sample + "_j","NOMINAL",sampletitle + "(light-jet fake #tau)",kBlue);
        fake_plots->init_sample(sample + "_b","NOMINAL",sampletitle + "(b-jets fake #tau)",kViolet);
        fake_plots->init_sample(sample + "_lep","NOMINAL",sampletitle + "(lepton fake #tau)",kGreen);
        fake_plots->init_sample(sample + "_real","NOMINAL",sampletitle + "(real #tau)",kRed);
        fake_plots->init_sample(sample + "_c","NOMINAL",sampletitle + "(c-jets fake #tau)",kOrange);
        fake_plots->init_sample(sample + "_wjet","NOMINAL",sampletitle + "(w-jet matched fake #tau)",kGray);
        fake_plots->init_sample(sample + "_doublefake","NOMINAL",sampletitle + "(double fake #tau)",kGray);
      }
      if(fake_nregions_notau) fake_notau_plots->init_sample(sample,"NOMINAL",sampletitle,kRed);
    }
  }
}

void tthmltree::Loop(TTree* inputtree, TString samplename, float globalweight) {
  if(!inputtree) {
    printf("Error: input tree is NULL\n");
    exit(0);
  }
  if (reduce > 1) {
    belong_regions.clear();
    belong_regions.add(inputtree->GetName());
    if(belong_regions.isEmpty()){
      printf("Disabled region: %s, continue\n", inputtree->GetName());
      return;
    }
  }
  nonfcncmatched = 0;
  fcncmatched = 0;
  leptonicw = 0;
  bool cutPLV = 1;
  bool cutmass = 0;
  bool cutmet = 1;
  reduce -= 1;
  Init(inputtree);
  reduce += 1;
  if(reduce == 2 && fitvec.size() == 0) initFit();
  map < TString, bool > ::iterator iter;
  printf("reduce scheme: %d\n", reduce);
  if (inputtree == 0) {
    printf("Init inputtree failed\n");
    return;
  }
  Long64_t nentries = inputtree->GetEntriesFast();
  TString sample = samplename;
  if (samplename.Contains("ttbar")) sample = "ttbar";
  else if (!samplename.Contains("data")) 
      sample.Remove(0,6);
  fstream evtfile;
  if(dumpeventnumber) evtfile.open((samplename+"_evt.txt").Data(), fstream:: in | fstream::out | fstream::app);
  if (dumptruth) {
    if(reduce > 1){
      if (TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) {
        filetruth[0][0].open("lephad2jodd.txt", fstream:: in | fstream::out | fstream::app);
        filetruth[0][1].open("lephad2jeven.txt", fstream:: in | fstream::out | fstream::app);
      } else
        for (int i = 0; i < 3; ++i) {
          if (TString(inputtree->GetName()).Contains("reg1l1tau1b3j")) {
            if (i != 0) {
              filetruth[i][0].open(CharAppend("lephad", i + 2) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
              filetruth[i][1].open(CharAppend("lephad", i + 2) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
            }
          } else {
            filetruth[i][0].open(CharAppend("lep2tau", i + 1) + "jodd.txt", fstream:: in | fstream::out | fstream::app);
            filetruth[i][1].open(CharAppend("lep2tau", i + 1) + "jeven.txt", fstream:: in | fstream::out | fstream::app);
          }
        }
    }else{
      printf("please dumptruth after reduce1\n"); //not supported yet
      exit(0);
    }
  }
  int nloop = debug ? 1000 : nentries;
  double defaultbtagwp = btagwpCut[1];
  if(reduce > 1) {
      fcnc = belong_regions.isCategory("SR") || belong_regions.isCategory("SRCR");
      printf("is FCNC SR or SRCR? %d\n", fcnc);
      if(belong_regions.have("85")) defaultbtagwp = btagwpCut[3];
  }
  float ngluon = 0;
  float droppedweight = 0;
  cut_flow.sample = samplename;
  cut_flow.region = reduce==1? "all" : (inputtree->GetName());
  printf("Start Loop\n");
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    inputtree->GetEntry(jentry);
    cut_flow.newEvent();
    if ((jentry % 100000 == 0))
      std::cout << " I am here event " << jentry << " Event " << eventNumber << " Run " << mc_channel_number << " ismc " << mc_channel_number << " Filled events "<< ifill<<std::endl;
    //===============================pre-selections===============================
    if (debug >= 2) printf("reduce scheme during loop: %d\n", reduce);
    if (reduce == 1) {
      if (selected_jets_T->size() == 0 && nJets_OR_T != 0) {
        printf("error: read jet vector failed entry: %lld\n", jentry);
        continue;
      }
      bool basic_selection = passEventCleaning;
      if (debug == 2) printf("passEventCleaning: %d\n", passEventCleaning);
      if (samplename.Contains("ttbargamma")) {
        basic_selection &= m_hasMEphoton_DRgt02_nonhad;
      }
      if (samplename.Contains("ttbarnohad")) {
        basic_selection &= !m_hasMEphoton_DRgt02_nonhad;
      }

      basic_selection &=
        (RunYear == 2015 && (( lep_Pt_0/1000>21 && HLT_mu20_iloose_L1MU15 ) || ( lep_Pt_0/1000>51 && HLT_mu50 ) || ( lep_Pt_0/1000>25 && HLT_e24_lhmedium_L1EM20VH )|| (lep_Pt_0/1000>61 &&HLT_e60_lhmedium) || ( lep_Pt_0/1000>121 && HLT_e120_lhloose))) ||
        (RunYear == 2015 && (HLT_2e12_lhloose_L12EM10VH || HLT_e17_lhloose_mu14 || HLT_mu18_mu8noL1)) ||
        (RunYear >= 2016 && (( lep_Pt_0/1000>27 && HLT_mu26_ivarmedium ) || ( lep_Pt_0/1000>51 && HLT_mu50 ) || ( lep_Pt_0/1000>27 && HLT_e26_lhtight_nod0_ivarloose ) || ( lep_Pt_0/1000>61 && HLT_e60_lhmedium_nod0) || ( lep_Pt_0/1000>141 && HLT_e140_lhloose_nod0))) ||
        (RunYear >= 2016 && (HLT_2e17_lhvloose_nod0 || HLT_e17_lhloose_nod0_mu14 || HLT_mu22_mu8noL1));

      if(nTaus_OR_Pt25) basic_selection = basic_selection && (tau_numTrack_0 == 1 || tau_numTrack_0 == 3); // assuming triggers for 2017 is same for 2016 
      weight = mc_channel_number > 0 ? mc_norm*weight_mc*pileupEventWeight_090*(version == 7 ? bTagSF_weight_MV2c10_FixedCutBEff_70 : bTagSF_weight_MV2c10_Continuous)*JVT_EventWeight*SherpaNJetWeight: 1.0;
      if( mc_channel_number > 0) weight*=tightLep?lepSFObjLoose:lepSFIDLoose*lepSFTrigLoose;
      if(nTaus_OR_Pt25 &&  mc_channel_number >0) weight*=tightTau?tauSFLoose:tauSFTight; // stupid and confusing but this is how it is.
      if(weight == 0) continue;
      cut_flow.fill("n-tuple");
      if (!basic_selection) continue;
      cut_flow.fill("basic selection");

      bool trig_match = (lep_isTrigMatch_0 || lep_isTrigMatch_1 || lep_isTrigMatch_2 || lep_isTrigMatch_3 || matchDLTll01 || matchDLTll02 || matchDLTll12 || matchDLTll03 || matchDLTll13 || matchDLTll23);
      bool SLtrig_match =
        ((RunYear == 2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose)) ||
          (RunYear >= 2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0))) && lep_isTrigMatch_0;

      //===============================define regions===============================

      belong_regions.clear();
      if(SLtrig_match && onelep_type && (!tightLep || SelectTLepid(0)) && nTaus_OR_Pt25 && (tau_passEleBDT_0 && tau_passMuonOLR_0)){
        if(nJets_OR_T == 3 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg1l1tau1b2j_os");
        if(nJets_OR_T >= 4 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg1l1tau1b3j_os");
        if(nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 < 0) belong_regions.add("reg1l2tau1bnj_os");
        if(nJets_OR_T == 3 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg1l1tau1b2j_ss");
        if(nJets_OR_T >= 4 && nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg1l1tau1b3j_ss");
        if(nJets_OR_T == 4 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg1l1tau2b2j_os");
        if(nJets_OR_T >= 5 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg1l1tau2b3j_os");
        if(nJets_OR_T == 4 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg1l1tau2b2j_ss");
        if(nJets_OR_T >= 5 && nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg1l1tau2b3j_ss");
        if(nJets_OR_T == 4 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T == 4 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg1l1tau2b2j_os_85");
        if(nJets_OR_T >= 5 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T == 5 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg1l1tau2b3j_os_85");
        if(nJets_OR_T == 4 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T == 4 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg1l1tau2b2j_ss_85");
        if(nJets_OR_T >= 5 && nJets_OR_T_MV2c10_85 == 2 && nJets_OR_T == 5 && nTaus_OR_Pt25 == 1 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg1l1tau2b3j_ss_85");
        if(nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 > 0) belong_regions.add("reg1l2tau1bnj_ss");
        if(nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 < 0) belong_regions.add("reg1l2tau2bnj_os");
        if(nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 >= 2 && (tau_passEleBDT_1 && tau_passMuonOLR_1) && tau_charge_0*tau_charge_1 > 0) belong_regions.add("reg1l2tau2bnj_ss");
        if(onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 3 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 < 0) belong_regions.add("reg1l1tau2b1j_os");
        if(onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 3 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 > 0) belong_regions.add("reg1l1tau2b1j_ss");
        if(onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 < 0) belong_regions.add("reg1l1tau2b_os");
        if(onelep_type && SLtrig_match && nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 1 && (lep_ID_0 > 0 ? -1 : 1)*tau_charge_0 > 0) belong_regions.add("reg1l1tau2b_ss");
      }
      if (trig_match && dilep_type && lep_Pt_0 > 20*GeV && lep_Pt_1 > 20*GeV && (nTaus_OR_Pt25 == 0 || (tau_passEleBDT_0 && tau_passMuonOLR_0))){
        if(((abs(lep_ID_0) == 11 && lep_promptLeptonVeto_TagWeight_0 < -0.7) || (abs(lep_ID_0) == 13 && lep_promptLeptonVeto_TagWeight_0 < -0.5)) && (!tightLep || SelectTLepid(0)) &&
           ((abs(lep_ID_1) == 11 && lep_promptLeptonVeto_TagWeight_1 < -0.7) || (abs(lep_ID_1) == 13 && lep_promptLeptonVeto_TagWeight_1 < -0.5)) && (!tightLep || SelectTLepid(1))) { //tight lepton
          if((dilep_type == 2 || ((dilep_type == 1 || dilep_type == 3) && (Mll01 < 80*GeV || Mll01 > 100*GeV))) && total_charge == 0){ //2l ttbar CR
            if(nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 1) belong_regions.add("reg2l1tau2b");
            if(nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T >= 3 && nTaus_OR_Pt25 == 0) belong_regions.add("reg2l2bnj");
            if(nJets_OR_T_MV2c10_70 == 1 && nJets_OR_T == 1 && nTaus_OR_Pt25 == 1) belong_regions.add("reg2l1tau1b");
            if(nJets_OR_T_MV2c10_70 == 1 && nJets_OR_T >= 2 && nTaus_OR_Pt25 == 1) belong_regions.add("reg2l1tau1bnj");
            if(nJets_OR_T_MV2c10_70 == 1 && nJets_OR_T >= 2 && nTaus_OR_Pt25 == 1) belong_regions.add("reg2l1tau2bnj");
            if(nJets_OR_T_MV2c10_70 == 2 && nJets_OR_T == 2 && nTaus_OR_Pt25 == 0) belong_regions.add("reg2l2b");
          }
          if(nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg2lSS1tau1bnj_os");
          if(nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg2lSS1tau1bnj_ss");
          if(nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg2lSS1tau2bnj_os");
          if(nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg2lSS1tau2bnj_ss");
        }else{
          if(nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg2lSS1tau1bnj_os_antitight");
          if(nJets_OR_T_MV2c10_70 == 1 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg2lSS1tau1bnj_ss_antitight");
          if(nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 > 0) belong_regions.add("reg2lSS1tau2bnj_os_antitight");
          if(nJets_OR_T_MV2c10_70 == 2 && nTaus_OR_Pt25 == 1 && lep_ID_0 * lep_ID_1 > 0 && tau_charge_0*lep_ID_0 < 0) belong_regions.add("reg2lSS1tau2bnj_ss_antitight");
        }
      }
      if(belong_regions.isEmpty()) continue;
      fcnc = belong_regions.isCategory("SR") || belong_regions.isCategory("SRCR");
      taus_p4->clear();
      taus_b_tagged->clear();
      taus_q->clear();
      taus_n_charged_tracks->clear();
      if(nTaus_OR_Pt25) {
        TLorentzVector *tmptau = new TLorentzVector();
        tmptau->SetPtEtaPhiE(tau_pt_0,tau_eta_0,tau_phi_0,tau_E_0);
        taus_p4->push_back(tmptau);
        taus_b_tagged->push_back(tau_MV2c10_0 > defaultbtagwp);
        taus_q->push_back(tau_charge_0);
        taus_n_charged_tracks->push_back(tau_numTrack_0);
      }
      if(nTaus_OR_Pt25>1) {
        TLorentzVector *tmptau = new TLorentzVector();
        tmptau->SetPtEtaPhiE(tau_pt_1,tau_eta_1,tau_phi_1,tau_E_1);
        taus_p4->push_back(tmptau);
        taus_b_tagged->push_back(tau_MV2c10_1 > defaultbtagwp);
        taus_q->push_back(tau_charge_1);
        taus_n_charged_tracks->push_back(tau_numTrack_1);
      }
      leps_p4->clear();
      leps_id->clear();
      TLorentzVector *tmplep = new TLorentzVector();
      tmplep->SetPtEtaPhiE(lep_Pt_0, lep_Eta_0, lep_Phi_0, lep_E_0);
      leps_p4->push_back(tmplep);
      leps_id->push_back(lep_ID_0);
      if(dilep_type){
        tmplep = new TLorentzVector();
        tmplep->SetPtEtaPhiE(lep_Pt_1, lep_Eta_1, lep_Phi_1, lep_E_1);
        leps_p4->push_back(tmplep);
        leps_id->push_back(lep_ID_1);
      }

      if (nJets_OR_T != selected_jets_T->size()) {
        printf("ERROR: nJets_OR_T,%d != selected_jets_T->size(),%lu; Entry: %lld\n", nJets_OR_T, selected_jets_T->size(), jentry);
        continue;
      }
      if (debug == 2) printf("Loop jets\n");
      bjets_p4->clear();
      vector<double> bjetscores;
      ljets_p4->clear();
      for (int i = 0; i < nJets_OR_T; ++i) {
        if(debug == 2) printf("%dth jet btag: %f\n", i,(*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)]);
        if ((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)] > defaultbtagwp) {
          TLorentzVector *tmp = new TLorentzVector();
          tmp->SetPtEtaPhiE((*m_jet_pt)[selected_jets_T->at(i)], (*m_jet_eta)[selected_jets_T->at(i)], (*m_jet_phi)[selected_jets_T->at(i)], (*m_jet_E)[selected_jets_T->at(i)]);
          bjets_p4->push_back(tmp);
          bjetscores.push_back((*m_jet_flavor_weight_MV2c10)[selected_jets_T->at(i)]);
        }else{
          if(!pt_ljet) pt_ljet = (*m_jet_pt)[selected_jets_T->at(i)];
          TLorentzVector *tmp = new TLorentzVector();
          tmp->SetPtEtaPhiE((*m_jet_pt)[selected_jets_T->at(i)], (*m_jet_eta)[selected_jets_T->at(i)], (*m_jet_phi)[selected_jets_T->at(i)], (*m_jet_E)[selected_jets_T->at(i)]);
          ljets_p4->push_back(tmp);
        }
        if(bjets_p4->size() >= 2){
          if(bjetscores[0] > bjetscores[1]){
            ljets_p4->push_back(bjets_p4->at(1));
            bjets_p4->erase(bjets_p4->begin()+1);
          }else{
            ljets_p4->push_back(bjets_p4->at(0));
            bjets_p4->erase(bjets_p4->begin());
          }
        }
      }
      met_p4->SetXYZM(met_met*cos(met_phi), met_met*sin(met_phi), MET_RefFinal_sumet, 0);

      if(nominaltree && taus_p4->size()){
        constructTruth();
        taumatchwjet = 0;
        subtaumatchwjet = 0;
        auto matchedlead = truthmatch(taus_p4->at(0));
        if(matchedlead)
          if(matchedlead->mother)
            taumatchwjet = abs(matchedlead->mother->pdg) == 24;
        if(taus_p4->size() >= 2) {
          auto matchedsublead = truthmatch(taus_p4->at(1));
          if(matchedsublead)
            if(matchedsublead->mother)
              subtaumatchwjet = abs(matchedsublead->mother->pdg) == 24;
        }
      }

    }else if(tightTau) {
      if((belong_regions.have("tau") && tau_JetBDTSigTight_0 == 0) || (belong_regions.have("2tau") && tau_JetBDTSigTight_1 == 0))
        continue;
      cut_flow.fill("tight tau");
    }
    else weight = weights->at(0);

    if (reduce == 2) {
      etmiss = met_p4->Pt();
      if(bjets_p4->size() == 0){
        printf("ERROR: bjet not found\n");
        continue;
      }
      if(!nominaltree && taus_p4->size()) {
        taumatchwjet = taumatchmap[eventNumber];
        subtaumatchwjet = subtaumatchmap[eventNumber];
      }
      cut_flow.fill("this region");
      if (debug == 2) printf("event weight: %f\n", weight);
      //===============================find leading b,non b jets===============================
      if(fabs(weight) > 2) {
        printf("fabs(weight) > 2, drop the event\n");
        droppedweight+=weight;
        continue;
      }
      //cut_flow.fill("fabs(weight) > 2");
      if(  mc_channel_number <= 0 ) weight = 1;

      int subhighscore_b = -1;
      leading_ljet = -1;
      pt_b = bjets_p4->at(0)->Pt();
      pt_ljet = ljets_p4->size() ? ljets_p4->at(0)->Pt():0;
      drtaujmin = 10;
      mtaujmin = 0;
      mjjmin = 0;

      TLorentzVector *tau2,*wlep;
      if(taus_p4->size() == 2) {
        tau2 = taus_p4->at(1);
        wlep = leps_p4->at(0);
      }
      else {
        tau2 = leps_p4->at(0);
        if(leps_p4->size() == 2){
          if((belong_regions.have("2lSS1tau") && tau2->DeltaR(*taus_p4->at(0)) > leps_p4->at(1)->DeltaR(*taus_p4->at(0)))
            || (!belong_regions.have("2l1tau") && lep_ID_0*tau_charge_0 < 0) ){
            tau2 = leps_p4->at(1);
            wlep = leps_p4->at(0);
          }else{
            wlep = leps_p4->at(1);
          }
        }else{
          wlep = 0;
        }
      }

      if (fcnc) {
        double tmpdr;
        double tmpm;
        for (auto lj1:(*ljets_p4)) {
          for(auto lj2:(*ljets_p4)){
            if (!(*lj1==*lj2)){
              double tmpmjj = (*lj1+*lj2).M();
              if(mjjmin > tmpmjj || mjjmin==0) mjjmin = tmpmjj;
            }
          }
          tmpdr = min(taus_p4->at(0)->DeltaR(*lj1), tau2->DeltaR(*lj1));
          tmpm = min((*taus_p4->at(0)+*lj1).M(), (*tau2+*lj1).M());
          if (drtaujmin > tmpdr) {
            drtaujmin = tmpdr;
          }if(mtaujmin > tmpm){
            mtaujmin = tmpm;
          }
        }
      }
      if (debug == 2) printf("kine fcnc\n");
      if (fcnc) {
        if (taus_p4->size() && taus_b_tagged->at(0) == 1) continue;
        if (taus_p4->size()>1 && taus_b_tagged->at(1) == 1) continue;
        cut_flow.fill("tau b-veto");
        ljet_indice = findcjet();

        //==  =============================fit neutrino===============================
        chi2 = 0;
        if(dofit && (taus_p4->size() + leps_p4->size() == 2 || dofit1l2tau)){
          if (taus_p4->size() >= 2) {
            gMinside->mnparm(0, "rpt1", 0.4, 0.01, 0., 2., ierflg);
            gMinside->mnparm(1, "rpt2", 0.4, 0.01, 0., 2., ierflg);
            gMinside->mnparm(2, "pt3", 10000, 10000, 0., 1000000., ierflg);
            gMinside->mnparm(3, "eta3", 0, 0.1, -5, 5, ierflg);
            gMinside->mnparm(4, "phi3", 0, 0.1, -PI, PI, ierflg);
            arglist[0] = 5;
          } else {
            gMinside->mnparm(0, "v1pt",  tau_pt_0, 1, 0., 1000000, ierflg);
            gMinside->mnparm(1, "v1eta", taus_p4->at(0)->Eta(), 0.01, taus_p4->at(0)->Eta()-0.25, taus_p4->at(0)->Eta()+0.25, ierflg);
            gMinside->mnparm(2, "v1phi", taus_p4->at(0)->Phi(), 0.01, taus_p4->at(0)->Phi()-0.25, taus_p4->at(0)->Phi()+0.25, ierflg);
            gMinside->mnparm(3, "v2pt",  leps_p4->at(0)->Pt(), 1, 0., 1000000, ierflg);
            gMinside->mnparm(4, "v2eta", leps_p4->at(0)->Eta(), 0.01, leps_p4->at(0)->Eta()-0.25, leps_p4->at(0)->Eta()+0.25, ierflg);
            gMinside->mnparm(5, "v2phi", leps_p4->at(0)->Phi(), 0.01, leps_p4->at(0)->Phi()-0.25, leps_p4->at(0)->Phi()+0.25, ierflg);
            gMinside->mnparm(6, "v2m", 500, 0.01, 0, 1776, ierflg);
            arglist[0] = 7;
          }
  
          gMinside->SetObjectFit((TObject*)&fitvec);
  
          arglist[1] = 60.;
          Double_t val[7] = {
            0,
            0,
            0,
            0,
            0,
            0,
            0
          };
          Double_t err[7] = {
            0,
            0,
            0,
            0,
            0,
            0,
            0
          };
  
          if(debug) printf("start kinematic fit\n");
          gMinside->mnexcm("SCAN", arglist, 2, ierflg);
          for (int i = 0; i < 7; ++i) gMinside->GetParameter(i, val[i], err[i]);
  
          if (taus_p4->size() >= 2) {
            gMinside->mnparm(0, "rpt1", val[0], 0.01, 0., 2., ierflg);
            gMinside->mnparm(1, "rpt2", val[1], 0.01, 0., 2., ierflg);
            gMinside->mnparm(2, "pt3",  val[2], 10*GeV, 0., 1000*GeV, ierflg);
            gMinside->mnparm(3, "eta3", val[3], 0.1, -5, 5, ierflg);
            gMinside->mnparm(4, "phi3", val[4], 0.1, -PI, PI, ierflg);
          } else {
            gMinside->mnparm(0, "v1pt",  val[0], 1, 0., 1000*GeV, ierflg);
            gMinside->mnparm(1, "v1eta", val[1], 0.01, taus_p4->at(0)->Eta()-0.25, taus_p4->at(0)->Eta()+0.25, ierflg);
            gMinside->mnparm(2, "v1phi", val[2], 0.01, taus_p4->at(0)->Phi()-0.25, taus_p4->at(0)->Phi()+0.25, ierflg);
            gMinside->mnparm(3, "v2pt",  val[3], 1, 0., 1000*GeV, ierflg);
            gMinside->mnparm(4, "v2eta", val[4], 0.01, leps_p4->at(0)->Eta()-0.25, leps_p4->at(0)->Eta()+0.25, ierflg);
            gMinside->mnparm(5, "v2phi", val[5], 0.01, leps_p4->at(0)->Phi()-0.25, leps_p4->at(0)->Phi()+0.25, ierflg);
            gMinside->mnparm(6, "v2m",   val[6], 0.01, 0, 1776, ierflg);
          }
  
          arglist[0] = 1000;
          arglist[1] = 0;
  
          gMinside->mnexcm("MIGRADE", arglist, 2, ierflg);
          for (int i = 0; i < (taus_p4->size() >= 2 ? 5 : 7); ++i) gMinside->GetParameter(i, val[i], err[i]);
          if(debug) printf("finish kinematic fit\n");
          Double_t fmin, fedm, errdef;
          Int_t npari, nparx, istat;
          gMinside->mnstat(fmin, fedm, errdef, npari, nparx, istat);
          chi2 = fmin;
          TLorentzVector tauv1_v,tauv2_v,all;
          if(taus_p4->size() >= 2) {
            tauv1_v.SetPtEtaPhiM(val[0]*taus_p4->at(0)->Pt(), taus_p4->at(0)->Eta(), taus_p4->at(0)->Phi(), ljets_p4->size() >= 2 ? 0 : val[2]);
            tauv2_v.SetPtEtaPhiM(val[1]*tau2->Pt(), tau2->Eta(), tau2->Phi(), 0);
            x1fit = 1 / (1 + val[0]);
            x2fit = 1 / (1 + val[1]);
            TLorentzVector wv_v;
            wv_v.SetPtEtaPhiM(val[2], val[3], val[4], 0);
            t1mass = (*wlep + wv_v + *bjets_p4->at(0)).M();
            wmass = (*wlep + wv_v).M();
          }
          else {
            tauv1_v.SetPtEtaPhiM(val[0],val[1],val[2],0);
            tauv2_v.SetPtEtaPhiM(val[3],val[4],val[5],val[6]);
            x1fit = taus_p4->at(0)->E() / (*taus_p4->at(0) + tauv1_v).E();
            x2fit = tau2->E() / (*tau2 + tauv2_v).E();
          }

          t2mass = ljets_p4->size() ? (tauv2_v + *taus_p4->at(0) + tauv1_v + *tau2 + *ljets_p4->at(ljet_indice[0])).M() : 0;
          tautaumass = (tauv2_v + *taus_p4->at(0) + tauv1_v + *tau2).M();

        }
        if (taus_p4->size() == 1 && leps_p4->size() == 1){
          tau_pt_1 = tau2->Pt();
          tau_pt_ss = 0;
          tau_pt_os = 0;
          drlbditau = 0;
          mtw = 0;
          etamax = 0;
          drltau = 0;
          drlb = leps_p4->at(0)->DeltaR(*bjets_p4->at(0));
        }else{
          tau_pt_ss = (wlep == leps_p4->at(0)? lep_ID_0 : lep_ID_1)*tau_charge_0 > 0 ? tau_pt_0 : tau2->Pt();
          tau_pt_os = (wlep == leps_p4->at(0)? lep_ID_0 : lep_ID_1)*tau_charge_0 < 0 ? tau_pt_0 : tau2->Pt();
          drlbditau = (*wlep + *bjets_p4->at(0)).DeltaR(*taus_p4->at(0) + *tau2);
          drlb = wlep->DeltaR(*bjets_p4->at(0));
          drtaub = bjets_p4->at(0)->DeltaR(*taus_p4->at(0));
          t1vismass = (*wlep + *bjets_p4->at(0)).M();
          mtw = 2*wlep->Pt()*MET_RefFinal_et*(1 - cos(MET_RefFinal_phi - wlep->Phi()));
          mtw = mtw > 0 ? sqrt(mtw) : 0.;
          etamax = max(fabs(taus_p4->at(0)->Eta()),fabs(tau2->Eta()));
          drltau = min(taus_p4->at(0)->DeltaR(*wlep), tau2->DeltaR(*wlep));
          if(drltau < 0.2) {
            printf("WARINING: Delta(l,tau) is less than 0.2, please check: eventNumber = %llu\n",eventNumber);
            printv(*taus_p4->at(0));
            printv(*tau2);
            printv(*wlep);
          }
        }
        phicent = phi_centrality(taus_p4->at(0)->Phi(),tau2->Phi(),met_phi);
        ttvismass = (*taus_p4->at(0) + *tau2).M();
        tautauvispt = (*taus_p4->at(0) + *tau2).Pt();
        t2vismass = ljets_p4->size() >= 1 ? (*taus_p4->at(0) + *tau2 + *ljets_p4->at(ljet_indice[0])).M() : 0;
        drtautau = taus_p4->at(0)->DeltaR(*tau2);
        drtauj = ljets_p4->size() >= 2 ? (*taus_p4->at(0) + *tau2).DeltaR(*ljets_p4->at(ljet_indice[0])) : 0;
        dphitauetmiss = fabs(met_phi - (*taus_p4->at(0) + *tau2).Phi());
      }
      taulmass = 0;
      TLorentzVector all = *taus_p4->at(0)+ *tau2 + *bjets_p4->at(0);
      for (int i = 0; i < ljet_indice.size(); ++i)
      {
        all+=*ljets_p4->at(ljet_indice[i]);
      }
      allmass = all.M();
      allpz = fabs(all.Pz());
      if (ljets_p4->size() && taus_p4->size()){
        for(auto jv: (*ljets_p4)){
          if(taulmass == 0 || taulmass > (*taus_p4->at(0) + *jv).M()){
            taulmass = (*taus_p4->at(0) + *jv).M();
          }
        }
      }
    }
    if((reduce == 3 && fcnc)|| (reduce == 2 && !fcnc)){
      if (!belong_regions.have("antitight") && cutPLV == 1 && ((lep_ID_0 == 11 && lep_promptLeptonVeto_TagWeight_0 > -0.7) || (lep_ID_0 == 13 && lep_promptLeptonVeto_TagWeight_0 > -0.5))) continue;
      cut_flow.fill("PLV");
      if (cutmet == 1 && etmiss<30*GeV) continue;
      cut_flow.fill("MET>30");
    }
    if(reduce == 3){
      if (belong_regions.have("1l2tau"))
      {
        if(t1vismass > 190*GeV )
          continue;
        cut_flow.fill("$m_{l,b}<190$");
      }
      if(cutmass == 1){
        if(ttvismass > 125*GeV ) continue;
        cut_flow.fill("$m_{\\tau\\tau$,vis}<125");
        if(ttvismass < 25*GeV ) continue;      
        cut_flow.fill("$m_{\\tau\\tau$,vis}>25");
      }
      BDTG_test  = 0;
      BDTG_train  = 0;
      if(doBDT){
        if(debug) printf("eval BDTG\n");
        if(belong_regions.have("1l2tau")) BDTG_test  = reader["reg1l2tau1bnj_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
        if(belong_regions.have("2j"    )) BDTG_test  = reader["reg1l1tau1b2j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
        if(belong_regions.have("3j"    )) BDTG_test  = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + eventNumber%2));
        if(belong_regions.have("1l2tau")) BDTG_train = reader["reg1l2tau1bnj_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
        if(belong_regions.have("2j"    )) BDTG_train = reader["reg1l1tau1b2j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
        if(belong_regions.have("3j"    )) BDTG_train = reader["reg1l1tau1b3j_os"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(eventNumber%2)));
      }
      if(dumpeventnumber) {
        for(auto reg : belong_regions.all()){
          if(mc_channel_number>0)
            evtfile<<reg<<" "<<mc_channel_number<<" "<<eventNumber<<" "<<weights->at(0)<<endl;
          else
            evtfile<<reg<<" "<<runNumber<<" "<<eventNumber<<" "<<weights->at(0)<<endl;
        }
      }
    }
      //===============================fill histograms, fill tree===============================
    if(debug) printf("derive origin\n");
    TString tauorigin;
    std::vector<float> vtaupt;
    std::vector<int> vtauprong;
    vector<int> origintag;
    if (sample.Contains("data")) {
      tauorigin = "data";
      sample = "data";
    } else if (nTaus_OR_Pt25 >= 1) {
      vtaupt.push_back(tau_pt_0);
      vtauprong.push_back(tau_numTrack_0);
      if (tau_truthType_0 == 10) {tauorigin = sample + "_real"; origintag.push_back(-1);}
      else if (tau_truthJetFlavour_0 < 0 && (tau_truthType_0 == 2 || tau_truthType_0 == 6)) {tauorigin = sample + "_lep"; origintag.push_back(-1);}
      else
        switch (tau_truthJetFlavour_0) {
        case 5:
          tauorigin = sample + "_b";
          origintag.push_back(0);
          break;
        case 4:
          if(taumatchwjet) {
            tauorigin = sample + "_wjet";
            origintag.push_back(4);
          }else{
            tauorigin = sample + "_c";
            origintag.push_back(1);
          }
          break;
        case 21:
          tauorigin = sample + "_g";
          origintag.push_back(2);
          break;
        default:
          if(taumatchwjet) {
            tauorigin = sample + "_wjet";
            origintag.push_back(4);
          }
          else {
            tauorigin = sample + "_j";
            origintag.push_back(3);
          }
        }
      if(belong_regions.have("1l2tau1bnj")){
        vtaupt.push_back(tau_pt_1);
        vtauprong.push_back(tau_numTrack_1);
        if (tau_truthType_1 == 10 || (tau_truthJetFlavour_1 < 0 && (tau_truthType_1 == 2 || tau_truthType_1 == 6))) origintag.push_back(-1);
        else
          switch (tau_truthJetFlavour_1) {
            case 5:
              if(tauorigin.Contains("real") || tauorigin.Contains("lep")) tauorigin = sample + "_b";
              else tauorigin = sample + "_doublefake";
              origintag.push_back(0);
              break;
            case 4:
              if(tauorigin.Contains("real") || tauorigin.Contains("lep")) {
                if(subtaumatchwjet) tauorigin = sample + "_wjet";
                else tauorigin = sample + "_c";
              } else tauorigin = sample + "_doublefake";
              if(subtaumatchwjet) origintag.push_back(4);
              else origintag.push_back(1);
              break;
            case 21:
              if(tauorigin.Contains("real") || tauorigin.Contains("lep")) tauorigin = sample + "_g";
              else tauorigin = sample + "_doublefake";
              origintag.push_back(2);
              break;
            default:
              if(tauorigin.Contains("real") || tauorigin.Contains("lep")) {
                if(subtaumatchwjet) tauorigin = sample + "_wjet";
                else tauorigin = sample + "_j";
              }else tauorigin = sample + "_doublefake";
              if(subtaumatchwjet)  origintag.push_back(4);
              else origintag.push_back(3);
          }
      }
    }
    if(debug) printf("calc SF\n");
    if(reduce == 1){
      weights->clear();
      addweights(weight,"NOMINAL");
      if(mc_channel_number){
        calcfakesf(origintag,vtaupt,vtauprong);
        if(nominaltree){
          if(!addWeightSys()) {
            printf("Warning: cannot add weight systematics\n");
            continue;
          }
          if(!AddTheorySys()) {
            printf("Warning: cannot add weight systematics\n");
            continue;
          }
        }
      }
    }

    if (dumptruth && fcnc && sample.Contains("fcnc")) dumpTruth(eventNumber % 2);
    if (dohist && mc_channel_number && weightsysmap.find(mc_channel_number) == weightsysmap.end()) {
      readweightsysmap(mc_channel_number,"tthML");
      if(weightsysmap.find(mc_channel_number) == weightsysmap.end()) {
        printf("tthmltree::Loop() WARNING: channel number %d not found in the systematics map, skipping\n", mc_channel_number);
        continue;
      }
    }
    vector<int> isOS;
    isOS.push_back(tau_charge_0*lep_ID_0>0);
    if(nTaus_OR_Pt25 >= 2) isOS.push_back(tau_charge_1*lep_ID_0>0);
    for (auto region: belong_regions.all()) {
      if (writetree) {
        if(debug) printf("fill tree: %s\n", region.Data());
        if(outputtree.find(region) == outputtree.end()) {
          printf("ERROR: Loop() outputtree not found: %s",region.Data());
          exit(0);
        }
        outputtree[region]->Fill();
      }
      if (dohist) {
        if(debug) printf("fill hist\n");
        if(mc_channel_number!=0){
          auto weightvec = weightsysmap.at(mc_channel_number);
          for (int iNP = 0; iNP < plotNPs.size(); ++iNP){
            auto theNP = plotNPs.at(iNP);
            if(debug) printf("fill NP %s\n", theNP.Data());
            weight = weights->at(0);
            if(applyNewFakeSF){
              if(theNP.Contains("fakeSF")){
                TString SFname;
                if(debug) printf("weight = %f\nPlotNP = %s\n",weight,theNP.Data());
                observable thefakeSF = FindNewFakeSF("NOMINAL", origintag[0], vtaupt[0], isOS[0],SFname);
                weight *= thefakeSF.nominal + thefakeSF.error*(theNP==SFname);
                if(nTaus_OR_Pt25 >= 2) {
                  thefakeSF = FindNewFakeSF("NOMINAL", origintag[1], vtaupt[1], isOS[1], SFname);
                  weight *= thefakeSF.nominal + thefakeSF.error*(theNP==SFname);
                }
                if(debug) printf("weight = %f after apply fakeSF\n",weight);
              }else{
                if(doubleCounting){
                  weight *= FindNewFakeSF("NOMINAL", origintag, vtaupt, isOS).nominal;
                }else if(nominaltree) 
                  weight *= FindNewFakeSF(theNP, origintag, vtaupt, isOS).nominal;
                else if(theNP == "NOMINAL"){
                  weight *= FindNewFakeSF(SystematicsName, origintag, vtaupt, isOS).nominal;
                }
              }
            }
            if(!theNP.Contains("Xsec") && !theNP.Contains("fakeSF") && nominaltree) {
              std::vector<TString>::iterator it = std::find(weightvec.begin(), weightvec.end(), theNP);
              int index = 2;
              if(it != weightvec.end()) index = std::distance(weightvec.begin(), it);
              else continue;
              if(index==2 || index==1) weight = weights->at(index);
              else if(index > 8 && index < 17)
                weight = weights->at(2) * weights->at(index);
              else if(index !=0)
                weight *= weights->at(index);
            }
            if (fcnc) fillhist(fcnc_plots, region, tau_numTrack_0, tauorigin, tau_pt_0 / GeV > 35, tau_MV2c10_0, theNP);
            else if(region.Contains("tau")) fillhist(fake_plots, region, tau_numTrack_0, tauorigin, tau_pt_0 / GeV > 35, tau_MV2c10_0, theNP);
            else fill_notau(region, sample, theNP);
          }
        }else{ //data
          if (region.Contains("tau")) {
            if (fcnc) fillhist(fcnc_plots, region, tau_numTrack_0, tauorigin, tau_pt_0 / GeV > 35, tau_MV2c10_0, "NOMINAL");
            else fillhist(fake_plots, region, tau_numTrack_0, tauorigin, tau_pt_0 / GeV > 35, tau_MV2c10_0, "NOMINAL");
          } else fill_notau(region, sample, "NOMINAL");
        }
      }
    }
    if(fcnc) ifill ++;
  }
  printf("dropped events total weight: %f\n", droppedweight);
  if(reduce > 1) printf("%s ", inputtree->GetName());
  if(reduce != 1){
    cut_flow.print();
    cut_flow.save(20);
    cut_flow.clear();
  }
  if(dumpeventnumber) evtfile.close();
  if (dumptruth) {
    if (TString(inputtree->GetName()).Contains("reg1l1tau1b2j")) {
      filetruth[0][0].close();
      filetruth[0][1].close();
    } else
      for (int i = 0; i < 6; ++i) {
        if (TString(inputtree->GetName()).Contains("reg1l1tau1b3j")) {
          if (i != 0) {
            filetruth[i][0].close();
            filetruth[i][1].close();
          }
        } else {
          filetruth[i][0].close();
          filetruth[i][1].close();
        }
      }
  }
}

void tthmltree::constructTruth(){
  //vector<truthpart*> truthparticles
  for(auto &parts : truthparticles){
    deletepointer(parts);
  }
  truthparticles.clear();
  if(!m_truth_pdgId) {
    printf("tthmltree::constructTruth() : WARNING: m_truth is not saved in the n-tuple, cannot reconstruct truth\n");
    return;
  }
  //===========================save all particle information==============================
  for (int itruth = 0; itruth < m_truth_pdgId->size(); ++itruth) {
    TLorentzVector truthpartp4;
    truthpartp4.SetPtEtaPhiM(m_truth_pt->at(itruth), m_truth_eta->at(itruth), m_truth_phi->at(itruth), m_truth_m->at(itruth));
    truthpart *thispart = new truthpart(m_truth_pdgId->at(itruth), truthpartp4);
    thispart->barcode = m_truth_barcode->at(itruth);
    if(m_truth_parents->at(itruth).size()) thispart->motherbarcode = m_truth_parents->at(itruth)[0];
    if(m_truth_children->at(itruth).size()) thispart->childrenbarcode = m_truth_children->at(itruth);
    truthparticles.push_back(thispart);
  }
  //===========================link mother and children===================================
  for(auto parts : truthparticles){
    if(parts->motherbarcode >= 0){
      for(auto motherparts: truthparticles){
        if(parts->motherbarcode == motherparts->barcode){
          parts->mother = motherparts;
          motherparts->children.push_back(parts);
        }
      }
    }
  }
  //===========================remove intermediate particles: eg. g->g->g->bb====================
  if(debug) printf("%lu truth particles in total\n", truthparticles.size());
  vector<truthpart*> forerase;
  for(auto parts : truthparticles){
    if(debug){
      printf("tthmltree::constructTruth() : particle %d: pt %f, eta %f, phi %f, m %f", parts->pdg, parts->p4.Pt(), parts->p4.Eta(), parts->p4.Phi(), parts->p4.M());
      if(parts->mother) printf(", mother %d", parts->mother->pdg);
      if(parts->children.size()) {
        printf(", children ");
        for (int i = 0; i < parts->children.size(); ++i)
        {
          printf("%d ", parts->children[i]->pdg);
        }
      }
      printf("\n");
    }
    if(parts->children.size() == 1){
      if(parts->children[0]->pdg == parts->pdg){
        if(parts->mother){
          for (int i = 0; i < parts->mother->children.size(); ++i)
          {
            if(parts->mother->children[i] == parts){
              parts->mother->children[i] = parts->children[0];
              parts->children[0]->mother = parts->mother;
            }
          }
        }
        forerase.push_back(parts);
        
        if(debug){
          printf("Erase particle: %d\n", parts->pdg);
        }
      }else{
        if(debug) printf("WARNING: only 1 child found: %d but not itself %d\n", parts->children[0]->pdg, parts->pdg);
      }
    }
  }
  for(auto erase: forerase){
    auto eraseiter = find(truthparticles.begin(), truthparticles.end(), erase);
    truthparticles.erase(eraseiter);
  }
  if(debug) printf("%lu truth particles after removal\n", truthparticles.size());
}

truthpart* tthmltree::truthmatch(TLorentzVector *p4){
  truthpart* matched = 0;
  for(auto parts : truthparticles){
    if(abs(parts->pdg) == 12 || abs(parts->pdg) == 14 || abs(parts->pdg) == 16) continue;  //do not match neutrinos
    if(parts->children.size()) continue;   //do not match intermediate particles
    if(parts->p4.DeltaR(*p4) < 0.4){
      if(matched){
        if(parts->p4.DeltaR(*p4) < matched->p4.DeltaR(*p4)) matched = parts;
      }else{
        matched = parts;
      }
    }
  }
  return matched;
}

void tthmltree::dumpTruth(int ipart) {
  TLorentzVector wchild[2], fcncjet, wboson;
  stringstream outstream;
  fstream nonmatchedfile;
  nonmatchedfile.open("nonmatch.txt", fstream:: in | fstream::out | fstream::app);
  if (debug) printf("truth particles: %lu\n", m_truth_pdgId->size());
  bool foundcjet = 0;
  int foundw = 0;
  int ifcncmatched = -1;
  bool foundhiggs = 0;
  if (debug) printf("find truth: mc channel: %d\n", mc_channel_number);
  for (int itruth = 0; itruth < m_truth_pdgId->size(); ++itruth) {
    if (debug) printf("pdg: %d,\tbarcode: %d,\tparent: %d\n", m_truth_pdgId->at(itruth), m_truth_barcode->at(itruth), m_truth_parents->at(itruth).size() ? m_truth_parents->at(itruth)[0] : 0);
    if (taus_p4->size() == 1 && abs(m_truth_pdgId->at(itruth)) == 24 && m_truth_m->at(itruth) / GeV > 70 && m_truth_m->at(itruth) / GeV < 90) {
      for (int ichild = 0; ichild < m_truth_children->at(itruth).size(); ++ichild) {
        int childbarcode = m_truth_children->at(itruth)[ichild];
        if (debug) printf("child barcode %d\n", childbarcode);
        int childid = 0;
        for (int i = 0; i < m_truth_barcode->size(); ++i) {
          if (m_truth_barcode->at(i) == childbarcode) {
            childid = i;
            break;
          }
        }
        if (debug) printf("child pdg: %d\n", m_truth_pdgId->at(childid));
        if (!(mc_channel_number == 411170 || mc_channel_number == 411171 || mc_channel_number == 411174 || mc_channel_number == 411175)) {
          leptonicw += weight;
          return;
        }
        if (abs(m_truth_pdgId->at(childid)) > 4 || abs(m_truth_pdgId->at(childid)) < 1) {
          break;
        }
        if (debug) printf("childid: %d\n", childid);
        wchild[foundw].SetPtEtaPhiM(m_truth_pt->at(childid), m_truth_eta->at(childid), m_truth_phi->at(childid), m_truth_m->at(childid));
        if (debug) outstream << "wjet:\t" << wchild[foundw].Pt() << " " << wchild[foundw].Eta() << " " << wchild[foundw].Phi() << " " << wchild[foundw].E() << " " << m_truth_pdgId->at(childid) << endl;
        foundw += 1;
        if (foundw == 1) wboson.SetPtEtaPhiM(m_truth_pt->at(itruth), m_truth_eta->at(itruth), m_truth_phi->at(itruth), m_truth_m->at(itruth));
      }
    } else if ((abs(m_truth_pdgId->at(itruth)) == 2 || abs(m_truth_pdgId->at(itruth)) == 4)) {
      int parent = -1;
      for (int i = 0; i < m_truth_barcode->size(); ++i) {
        if (m_truth_barcode->at(i) == m_truth_parents->at(itruth)[0]) {
          parent = i;
          break;
        }
      }
      if (abs(m_truth_pdgId->at(parent)) == 6) {
        foundcjet = 1;
        fcncjet.SetPtEtaPhiM(m_truth_pt->at(itruth), m_truth_eta->at(itruth), m_truth_phi->at(itruth), m_truth_m->at(itruth));
        if (debug) outstream << "cjet:\t" << fcncjet.Pt() << " " << fcncjet.Eta() << " " << fcncjet.Phi() << " " << fcncjet.E() << " " << m_truth_pdgId->at(itruth) << endl;
        if (debug) outstream << "fcnctop:\t" << m_truth_pt->at(parent) << " " << m_truth_eta->at(parent) << " " << m_truth_phi->at(parent) << " " << m_truth_m->at(parent) << " " << m_truth_pdgId->at(parent) << endl;
      }
    }
    if (m_truth_pdgId->at(itruth) == 25) {
      if (debug) outstream << "higgs:\t" << m_truth_pt->at(itruth) << " " << m_truth_eta->at(itruth) << " " << m_truth_phi->at(itruth) << " " << m_truth_m->at(itruth) << " " << m_truth_pdgId->at(itruth) << endl;
      foundhiggs = 1;
    }
    if (foundw == 2 && foundcjet && foundhiggs) break;
  }
  if (debug && !foundw) printf("coundn't find truth w jets\n");
  if (debug && !foundcjet) printf("coundn't find truth fcnc jets\n");
  if ((!foundw && taus_p4->size() == 1) || !foundcjet) return;
  if (taus_p4->size() == 1) {
    if (foundw == 1) {
      wchild[1] = wboson - wchild[0];
      if (debug) outstream << "wjet:\t" << wchild[1].Pt() << " " << wchild[1].Eta() << " " << wchild[1].Phi() << " " << wchild[1].E() << endl;
    }
  }
  int loopmax = (taus_p4->size() == 1 ? 4 : 3);
  int ijet = 0;
  outstream << "bjet: " << bjets_p4->at(0)->Pt() << " " << bjets_p4->at(0)->Eta() << " " << bjets_p4->at(0)->Phi() << " " << bjets_p4->at(0)->E() << "\n";
  for (int i = 0; i < 2; ++i) {
    outstream << "taus: " << taus_p4->at(i)->Pt() << " " << taus_p4->at(i)->Eta() << " " << taus_p4->at(i)->Phi() << " " << taus_p4->at(i)->E() << "\n";
  }
  if (taus_p4->size() >= 2) {
    outstream << "leptons: " << leps_p4->at(0)->Pt() << " " << leps_p4->at(0)->Eta() << " " << leps_p4->at(0)->Phi() << " " << leps_p4->at(0)->E() << "\n";
  }
  for (auto jetv: (*ljets_p4)) {
    ijet += 1;
    if(ijet > loopmax) break;
    outstream << "pool" << ijet << ": " << jetv->Pt() << " " << jetv->Eta() << " " << jetv->Phi() << " " << jetv->E();
    bool wmatched = 0;
    if (jetv->DeltaR(fcncjet) < 0.4) {
      outstream << " 1 0 0\n";
      ifcncmatched = ijet;
    } else if (taus_p4->size() == 1) {
      for (int ichild = 0; ichild < 2; ++ichild) {
        if (jetv->DeltaR(wchild[ichild]) < 0.4) {
          outstream << " 0 1 0\n";
          wmatched = 1;
          break;
        }
      }
    }
    if (!(ifcncmatched==ijet) && !wmatched) outstream << " 0 0 1\n";
    int ifile = ijet - (taus_p4->size() == 1 ? 2 : 1);
    if(ifcncmatched>=0 && ifile>=0 && ljet_indice[0]<ijet){
      filetruth[ifile][ipart] << outstream.str() << "eventweight: " << weight << " cjet_inv_mass_method: " << ljet_indice[0] << endl;
    }
  }
  outstream.clear();
  
  if (ifcncmatched>=0) {
    fcncmatched += weight;
  } else {
    nonmatchedfile << outstream.rdbuf() << nonfcncmatched << endl;
    nonfcncmatched += weight;
  }
  nonmatchedfile.close();
}

bool tthmltree::SelectTLepid(int id) {
  bool pass(false);
  //lep_ambiguityType_0==0 for electron
  if (id == 0) {
    pass = lep_isolationFixedCutLoose_0 && (abs(lep_ID_0) == 13 || ((abs(lep_ID_0) == 11) && lep_isTightLH_0));
  } else if (id == 1) {
    pass = lep_isolationFixedCutLoose_1 && (abs(lep_ID_1) == 13 || ((abs(lep_ID_1) == 11) && lep_isTightLH_1));
  } else if (id == 2) {
    pass = lep_isolationFixedCutLoose_2 && (abs(lep_ID_2) == 13 || ((abs(lep_ID_2) == 11) && lep_isTightLH_2));
  } else if (id == 3) {
    pass = lep_isolationFixedCutLoose_3 && (abs(lep_ID_3) == 13 || ((abs(lep_ID_3) == 11) && lep_isTightLH_3));
  } else if (id == 4) {
    pass = lep_isolationFixedCutLoose_4 && (abs(lep_ID_4) == 13 || ((abs(lep_ID_4) == 11) && lep_isTightLH_4));
  }
  return pass;
}

void tthmltree::constructwmatchmap(TTree *tree){
  ULong64_t eventnumber;
  bool matched,submatched;
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus("eventNumber",1);
  tree->SetBranchStatus("taumatchwjet",1);
  tree->SetBranchAddress("eventNumber",&eventnumber);
  tree->SetBranchAddress("taumatchwjet",&matched);
  if(TString(tree->GetName()).Contains("2tau")) {
    tree->SetBranchStatus("subtaumatchwjet",1);
    tree->SetBranchAddress("subtaumatchwjet",&submatched);
  }
  Long64_t nentries = tree->GetEntriesFast();
  for (int i = 0; i < nentries; ++i)
  {
    tree->GetEntry(i);
    taumatchmap[eventnumber] = matched;
    if(TString(tree->GetName()).Contains("2tau")) subtaumatchmap[eventnumber] = submatched;
  }
}
