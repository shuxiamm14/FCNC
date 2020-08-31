#include "tthmltree.h"
#define nominal_cxx
#include "TH2F.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcnc_include.h"
#include "common.h"
using namespace std;
tthmltree::tthmltree():nominal::nominal(){
  defGeV(1000);
  dofit1l2tau = 0;
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
    "reg2lSS1tau2bnj_os_antiiso",
    "reg2lSS1tau2bnj_ss_antiiso",
    "reg2lSS1tau1bnj_ss_antiiso",
    "reg2lSS1tau1bnj_os_antiiso",
    "reg2lSS1tau2bnj_os_antiisolead",
    "reg2lSS1tau2bnj_ss_antiisolead",
    "reg2lSS1tau1bnj_ss_antiisolead",
    "reg2lSS1tau1bnj_os_antiisolead",
    "reg2l1tau2bnj"
  };
  belong_regions.m_region_map["FakeCR"] = {
    "reg1l1tau2b1j_os",
    "reg1l1tau2b1j_ss",
    "reg1l1tau2b_os",
    "reg1l1tau2b_ss",
    "reg2lSS1taunj_os",
    "reg2lSS1taunj_os_antiiso",
    "reg2lSS1taunj_os_antiisolead",
    "reg2l2bnj",
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
  auto vars = getVariables("tthML");
  if(fcnc_nregions && plotNPs.size()){
    fcnc_plots = new histSaver(outputfilename);
    fcnc_plots->set_weight(&weight);
    fcnc_plots->debug = !!debug;
    if(reduce >= 2) {
      fcnc_plots->add(vars.at("chi2"),&chi2);
      if(reduce == 3 && doBDT) {
        fcnc_plots->add(vars.at("BDTG_test"),&BDTG_test);
        fcnc_plots->add(vars.at("BDTG_train"),&BDTG_train);
      }
      fcnc_plots->add(vars.at("t1mass"),&t1mass);
      fcnc_plots->add(vars.at("mtw"),&mtw);
      fcnc_plots->add(vars.at("tautaumass"),&tautaumass);
      fcnc_plots->add(vars.at("wmass"),&wmass);
      fcnc_plots->add(vars.at("t2mass"),&t2mass);
      fcnc_plots->add(vars.at("ttvismass"),&ttvismass);
      fcnc_plots->add(vars.at("tautauvispt"),&tautauvispt);
      fcnc_plots->add(vars.at("t2vismass"),&t2vismass);
      fcnc_plots->add(vars.at("t1vismass"),&t1vismass);
      fcnc_plots->add(vars.at("mtaujmin"),&mtaujmin);
      fcnc_plots->add(vars.at("mjjmin"),&mjjmin);
      fcnc_plots->add(vars.at("etmiss"),&etmiss);
      fcnc_plots->add(vars.at("x1fit"),&x1fit);
      fcnc_plots->add(vars.at("x2fit"),&x2fit);
      fcnc_plots->add(vars.at("drlbditau"),&drlbditau);
      fcnc_plots->add(vars.at("drlb"),&drlb);
      fcnc_plots->add(vars.at("drtaub"),&drtaub);
      fcnc_plots->add(vars.at("etamax"),&etamax);
      fcnc_plots->add(vars.at("drltau"),&drltau);
      fcnc_plots->add(vars.at("drtauj"),&drtauj);
      fcnc_plots->add(vars.at("drtautau"),&drtautau);
      fcnc_plots->add(vars.at("drtaujmin"),&drtaujmin);
      fcnc_plots->add(vars.at("nljet"),&nljet);
      fcnc_plots->add(vars.at("dphitauetmiss"),&dphitauetmiss);
      fcnc_plots->add(vars.at("phicent"),&phicent);
    }
    fcnc_plots->add(vars.at("tau_pt_0"),&tau_pt_0);
    fcnc_plots->add(vars.at("tau_pt_1"),&tau_pt_1);
    fcnc_plots->add(vars.at("lep_pt_0"),&lep_pt_0);
    fcnc_plots->add(vars.at("lep_pt_1"),&lep_pt_1);
    fcnc_plots->add(vars.at("mll"),&mll);
    for (int j = 0; j < fcnc_nregions; ++j){
      if(plotTauFake){
        for (int k = 0; k < 2; ++k)
        {
          for (int i = 0; i < 4; ++i)
          {
            if(dobwp[bwps[i]]) fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[i]);
            if(dovetobwp[bwps[i]]) fcnc_plots->add_region(fcnc_regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
          }
        }
      }else{
        fcnc_plots->add_region(fcnc_regions[j]+"_emu");
        fcnc_plots->add_region(fcnc_regions[j]+"_ee");
        fcnc_plots->add_region(fcnc_regions[j]+"_mumu");
        fcnc_plots->add_region(fcnc_regions[j]+"_mue");
      }
    }
  }

  fake_nregions_notau = fake_regions_notau.size();
  if(fake_nregions_notau){
    fake_notau_plots = new histSaver(outputfilename + "_fake_notau");
    fake_notau_plots->set_weight(&weight);
    fake_notau_plots->debug = !!debug;
    fake_notau_plots->add(vars.at("bpt"),&pt_b);
    fake_notau_plots->add(vars.at("ljetpt"),&pt_ljet);
    for (int j = 0; j < fake_nregions_notau; ++j){
      fake_notau_plots->add_region(fake_regions_notau[j]);
    }
  }

  fake_nregions = fake_regions.size();
  if(fake_nregions){
    fake_plots = new histSaver(outputfilename);
    fake_plots->set_weight(&weight);
    fake_plots->debug = !!debug;
    fake_plots->add(vars.at("tau_pt_0"),&tau_pt_0);
    fake_plots->add(vars.at("lep_pt_0"),&lep_pt_0);
    fake_plots->add(vars.at("lep_pt_1"),&lep_pt_1);
//    fake_plots->add(atvars.("bpt"),&pt_b);
//    fake_plots->add(atvars.("ljetpt"),&pt_ljet);
    fake_plots->add(vars.at("etmiss"),&etmiss);
    fake_plots->add(vars.at("mll"),&mll);
    for (int j = 0; j < fake_nregions; ++j){
      if(plotTauFake){
        for (int k = 0; k < 2; ++k){
          for (int i = 0; i < 4; i+=1){
            if(dobwp[bwps[i]]) fake_plots->add_region(fake_regions[j] + "_" + nprong[k] + "_" + bwps[i]);
            if(dovetobwp[bwps[i]]) fake_plots->add_region(fake_regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
          }
        }
      }else{
        fake_plots->add_region(fake_regions[j]+"_emu");
        fake_plots->add_region(fake_regions[j]+"_ee");
        fake_plots->add_region(fake_regions[j]+"_mumu");
        fake_plots->add_region(fake_regions[j]+"_mue");
      }
    }
  }
}

bool tthmltree::passRegionCut(){
  if(belong_regions.have("1l1tau")){
    if(met_p4->Pt()<20*GeV) return false;
    cut_flow.fill("$MET>20$");
  }
  return true;
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
    outputtreefile = new TFile(outfile,"update");
    for (int i = 0; i < fcnc_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n",fcnc_regions[i].Data());
      TTree *target = new TTree(fcnc_regions[i],fcnc_regions[i]);
      outputtree[fcnc_regions[i]] = target;
      defineTree(target);
    }

    for (int i = 0; i < fake_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions[i].Data());
      TTree* target = 0;
      target = new TTree(fake_regions[i],fake_regions[i]);
      defineTree(target);
      outputtree[fake_regions[i]] = target;
    }
    for (int i = 0; i < fake_nregions_notau; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions_notau[i].Data());
      outputtree[fake_regions_notau[i]] = new TTree(fake_regions_notau[i],fake_regions_notau[i]);
      defineTree(outputtree[fake_regions_notau[i]]);
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
      if(plotTauFake){
        if(fcnc_nregions){
          fcnc_plots->init_sample(sample + "_g",plotNPs[0],sampletitle + "(gluon fake #tau)",(enum EColor)7);
          fcnc_plots->init_sample(sample + "_j",plotNPs[0],sampletitle + "(light-jet fake #tau)",kBlue);
          fcnc_plots->init_sample(sample + "_b",plotNPs[0],sampletitle + "(b-jets fake #tau)",kViolet);
          fcnc_plots->init_sample(sample + "_lep",plotNPs[0],sampletitle + "(lepton fake #tau)",kGreen);
          fcnc_plots->init_sample(sample + "_real",plotNPs[0],sampletitle + "(real #tau)",kRed);
          fcnc_plots->init_sample(sample + "_c",plotNPs[0],sampletitle + "(c-jets fake #tau)",kOrange);
          fcnc_plots->init_sample(sample + "_wjet",plotNPs[0],sampletitle + "(w-jet matched fake #tau)",kGray);
          fcnc_plots->init_sample(sample + "_doublefake",plotNPs[0],sampletitle + "(double fake #tau)",kGray);
          fcnc_plots->init_sample(sample + "_nomatch",plotNPs[0],sampletitle + "(no match fake #tau)",kGray);
        }
        if(fake_nregions){
          fake_plots->init_sample(sample + "_g","NOMINAL",sampletitle + "(gluon fake #tau)",(enum EColor)7);
          fake_plots->init_sample(sample + "_j","NOMINAL",sampletitle + "(light-jet fake #tau)",kBlue);
          fake_plots->init_sample(sample + "_b","NOMINAL",sampletitle + "(b-jets fake #tau)",kViolet);
          fake_plots->init_sample(sample + "_lep","NOMINAL",sampletitle + "(lepton fake #tau)",kGreen);
          fake_plots->init_sample(sample + "_real","NOMINAL",sampletitle + "(real #tau)",kRed);
          fake_plots->init_sample(sample + "_c","NOMINAL",sampletitle + "(c-jets fake #tau)",kOrange);
          fake_plots->init_sample(sample + "_wjet","NOMINAL",sampletitle + "(w-jet matched fake #tau)",kGray);
          fake_plots->init_sample(sample + "_nomatch","NOMINAL",sampletitle + "(no match fake #tau)",kGray);
        }
      }else{
        if(fcnc_nregions){
          fcnc_plots->init_sample(sample + "_realLep",plotNPs[0],sampletitle + "(real lepton)",(enum EColor)7);
          fcnc_plots->init_sample(sample + "_chargeFlip",plotNPs[0],sampletitle + "(lepton charge flip)",kBlue);
          fcnc_plots->init_sample(sample + "_conversion",plotNPs[0],sampletitle + "(lepton flavor flip)",kViolet);
          fcnc_plots->init_sample(sample + "_nonPrompt",plotNPs[0],sampletitle + "(non-prompt lepton)",kGreen);
          fcnc_plots->init_sample(sample + "_otherFakeLep",plotNPs[0],sampletitle + "(fake lepton)",kOrange);
          fcnc_plots->init_sample(sample + "_unknownFakeLep",plotNPs[0],sampletitle + "(fake lepton)",kOrange);
          fcnc_plots->init_sample(sample + "_doubleFakeLep",plotNPs[0],sampletitle + "(double fake lepton)",kGray);
        }
        if(fake_nregions){
          fake_plots->init_sample(sample + "_realLep","NOMINAL",sampletitle + "(real lepton)",(enum EColor)7);
          fake_plots->init_sample(sample + "_chargeFlip","NOMINAL",sampletitle + "(lepton charge flip)",kBlue);
          fake_plots->init_sample(sample + "_conversion","NOMINAL",sampletitle + "(lepton flavor flip)",kViolet);
          fake_plots->init_sample(sample + "_nonPrompt","NOMINAL",sampletitle + "(non-prompt lepton)",kGreen);
          fake_plots->init_sample(sample + "_otherFakeLep","NOMINAL",sampletitle + "(fake lepton)",kOrange);
          fake_plots->init_sample(sample + "_unknownFakeLep","NOMINAL",sampletitle + "(fake lepton)",kOrange);
          fake_plots->init_sample(sample + "_doubleFake","NOMINAL",sampletitle + "(double fake lepton)",kGray);
        }
      }
      if(fake_nregions_notau) fake_notau_plots->init_sample(sample,"NOMINAL",sampletitle,kRed);
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

void tthmltree::constructwmatchmap(TTree *tree){
  ULong64_t eventnumber;
  std::vector<int> *matched;
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus("eventNumber",1);
  tree->SetBranchStatus("taus_matched_mother_pdgId",1);
  tree->SetBranchAddress("eventNumber",&eventnumber);
  tree->SetBranchAddress("taus_matched_mother_pdgId",&matched);
  Long64_t nentries = tree->GetEntriesFast();
  for (int i = 0; i < nentries; ++i)
  {
    tree->GetEntry(i);
    taumatchmap[eventnumber] = matched;
  }
}

void tthmltree::initialize_fit(const char* input) {
  printf("reading in histograms\n");
  TFile f(input,"READ");

  prob_20_40 = (TH2F*) f.Get("prob_20_40");
  prob_40_60 = (TH2F*) f.Get("prob_40_60");
  prob_60_80 = (TH2F*) f.Get("prob_60_80");
  prob_80_100 = (TH2F*) f.Get("prob_80_100");
  prob_100_120 = (TH2F*) f.Get("prob_100_120");
  prob_120_140 = (TH2F*) f.Get("prob_120_140");
  prob_140_160 = (TH2F*) f.Get("prob_140_160");
  prob_160_200 = (TH2F*) f.Get("prob_160_200");
  prob_200_300 = (TH2F*) f.Get("prob_200_300");
  prob_300_400 = (TH2F*) f.Get("prob_300_400");
  prob_400 = (TH2F*) f.Get("prob_400");

  prob_20_40->SetDirectory(0);
  prob_40_60->SetDirectory(0);
  prob_60_80->SetDirectory(0);
  prob_80_100->SetDirectory(0);
  prob_100_120->SetDirectory(0);
  prob_120_140->SetDirectory(0);
  prob_140_160->SetDirectory(0);
  prob_160_200->SetDirectory(0);
  prob_200_300->SetDirectory(0);
  prob_300_400->SetDirectory(0);
  prob_400->SetDirectory(0);

  fillOverFlow(prob_20_40);
  fillOverFlow(prob_40_60);
  fillOverFlow(prob_60_80);
  fillOverFlow(prob_80_100);
  fillOverFlow(prob_100_120);
  fillOverFlow(prob_120_140);
  fillOverFlow(prob_140_160);
  fillOverFlow(prob_160_200);
  fillOverFlow(prob_200_300);
  fillOverFlow(prob_300_400);
  fillOverFlow(prob_400);

  f.Close();
}

//at least 2x2 bins:
void tthmltree::fillOverFlow(TH2F* h) {
  Int_t nx = h->GetNbinsX();
  Int_t ny = h->GetNbinsY();
  for(Int_t i=1; i<=nx; i++) {
    h->SetBinContent(i,0,2*h->GetBinContent(i,1)-h->GetBinContent(i,2));
    h->SetBinContent(i,ny+1,2*h->GetBinContent(i,ny)-h->GetBinContent(i,ny-1));
  }
  for(Int_t j=1; j<=ny; j++) {
    h->SetBinContent(0,j,2*h->GetBinContent(1,j)-h->GetBinContent(2,j));
    h->SetBinContent(nx+1,j,2*h->GetBinContent(nx,j)-h->GetBinContent(nx-1,j));
  }
  h->SetBinContent(0,0,h->GetBinContent(0,1)+h->GetBinContent(1,0)-h->GetBinContent(1,1));
  h->SetBinContent(0,ny+1,h->GetBinContent(0,ny)+h->GetBinContent(1,ny+1)-h->GetBinContent(1,ny));
  h->SetBinContent(nx+1,0,h->GetBinContent(nx,0)+h->GetBinContent(nx+1,1)-h->GetBinContent(nx,1));
  h->SetBinContent(nx+1,ny+1,h->GetBinContent(nx,ny+1)+h->GetBinContent(nx+1,ny)-h->GetBinContent(nx,ny));
}

// get smooth output from 2-d histogram (at least 2x2 bins)

//at least 2 bins:
void tthmltree::fillOverFlow(TH1F* h) {
  Int_t nx = h->GetNbinsX();
  h->SetBinContent(0,2*h->GetBinContent(1)-h->GetBinContent(2));
  h->SetBinContent(nx+1,2*h->GetBinContent(nx)-h->GetBinContent(nx-1));
}

// get smooth output from 1-d histogram (at least 2 bins)


