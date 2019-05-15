
#define hadhadtree_cxx
#include "hadhadtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "fcnc_include.h"


hadhadtree::hadhadtree() : nominal::nominal(){
  defGeV(1);
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
    outputtreefile = new TFile(TString(PACKAGE_DIR) + "/data/hadhadreduce" + char('0' + reduce) + "/" + sample + "_tree.root","recreate");
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
        fcnc_plots[iNP]->init_sample(sample + "_g",sample + "_g_NP" + char('0' + iNP),sampletitle + "(gluon fake #tau)",(enum EColor)7);
        fcnc_plots[iNP]->init_sample(sample + "_j",sample + "_j_NP" + char('0' + iNP),sampletitle + "(light-jet fake #tau)",kBlue);
        fcnc_plots[iNP]->init_sample(sample + "_b",sample + "_b_NP" + char('0' + iNP),sampletitle + "(b-jets fake #tau)",kViolet);
        fcnc_plots[iNP]->init_sample(sample + "_lep",sample + "_lep_NP" + char('0' + iNP),sampletitle + "(lepton fake #tau)",kGreen);
        fcnc_plots[iNP]->init_sample(sample + "_real",sample + "_real_NP" + char('0' + iNP),sampletitle + "(real #tau)",kRed);
        fcnc_plots[iNP]->init_sample(sample + "_c",sample + "_c_NP" + char('0' + iNP),sampletitle + "(c-jets fake #tau)",kOrange);
        fcnc_plots[iNP]->init_sample(sample + "_nomatch",sample + "_nomatch_NP" + char('0' + iNP),sampletitle + "(no truth matched fake #tau)",kGray);
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
  double cutflow2[] = {
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
  int cutflowraw[] = {
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
  printf("nentries: %d\n", nloop);
  for (Long64_t jentry = 0; jentry < nloop; jentry++) {
    inputtree->GetEntry(jentry);
    //if(mc_channel_number == 411172 || mc_channel_number == 411173 || mc_channel_number == 411176 || mc_channel_number == 411177)
    //  continue;
    if ((jentry % 100000 == 0) || debug)
      std::cout << " I am here event " << jentry << " Event " << event_number << " Run " << run_number << " ismc " << mc_channel_number << std::endl;
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

      cutflowraw[0]+=1;
      cutflow[0]+=weight;
      cutflow2[0]+=pow(weight,2);
      if(!tau_0_trig_trigger_matched || !tau_1_trig_trigger_matched) continue;
      cutflowraw[1]+=1;
      cutflow[1]+=weight;
      cutflow2[1]+=pow(weight,2);
      if((tau_1_n_charged_tracks!=1 && tau_1_n_charged_tracks!=3) || (tau_0_n_charged_tracks!=1 && tau_0_n_charged_tracks!=3)) continue;
      cutflowraw[2]+=1;
      cutflow[2]+=weight;
      cutflow2[2]+=pow(weight,2);
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


      if(ifregions["reg2mtau1b3jos"]) cutflowraw[3]+=1;

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
      cutflowraw[0]+=1;
      cutflow[0]+=weight;
      cutflow2[0]+=pow(weight,2);
      if(campaign !=1 && jets_p4->at(0)->Pt() < 50 && bjets_p4->at(0)->Pt() < 50) continue;
      cutflow[1]+=weight;
      cutflow2[1]+=pow(weight,2);
      cutflowraw[1]+=1;
      bool passbjetcut = 0;
      for(auto bjet : *bjets_p4){
        if(bjet->Pt() > 30 && abs(bjet->Eta()) < 2.5) passbjetcut = 1;
      }
      if(!passbjetcut) continue;
      cutflow[2]+=weight;
      cutflow2[2]+=pow(weight,2);
      cutflowraw[2]+=1;
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
      cutflow[3]+=weight;
      cutflow2[3]+=pow(weight,2);
      cutflowraw[3]+=1;
      if(ttvismass > 130) continue;
      cutflow[4]+=weight;
      cutflow2[4]+=pow(weight,2);
      cutflowraw[4]+=1;
      if(drtautau > 3.4) continue;
      cutflow[5]+=weight;
      cutflow2[5]+=pow(weight,2);
      cutflowraw[5]+=1;
  
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
      if(ifregions["reg2mtau1b3jos"] || ifregions["reg2mtau1b3jss"]) {
        BDTG_test = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + event_number%2) );
        BDTG_train = reader["reg2mtau1b3jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(event_number%2)) );
      }
      if(ifregions["reg2mtau1b2jos"] || ifregions["reg2mtau1b2jss"]) {
        BDTG_test = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + event_number%2) );
        BDTG_train = reader["reg2mtau1b2jos"]->EvaluateMVA( TString("BDTG_")+ char('1' + !(event_number%2)) );
      }
    }
    TString tauorigin;
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
      }
      if (tauabspdg == 15) tauorigin = sample + "_real";
      else if (tauabspdg == 13 || tauabspdg == 11) tauorigin = sample + "_lep";
      else if (tauabspdg == 5) tauorigin = sample + "_b";
      else if (tauabspdg == 4) tauorigin = sample + "_c";
      else if (tauabspdg ==21) tauorigin = sample + "_g";
      else if (tauabspdg <= 3 && tauabspdg >=1) tauorigin = sample + "_j";
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
          weights->push_back(weight);
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
              fill_fcnc(iter->first, taus_n_charged_tracks->at(1), tauorigin, tau_pt_1 > 35, taus_b_tagged->at(1),iNP);
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
  printf("cutflow: %f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f\n", cutflow[0],sqrt(cutflow2[0]),cutflow[1],sqrt(cutflow2[1]),cutflow[2],sqrt(cutflow2[2]),cutflow[3],sqrt(cutflow2[3]),cutflow[4],sqrt(cutflow2[4]),cutflow[5],sqrt(cutflow2[5]));
  printf("cutflowraw: %d, %d, %d, %d, %d, %d\n", cutflowraw[0],cutflowraw[1],cutflowraw[2],cutflowraw[3],cutflowraw[4],cutflowraw[5]);
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

void hadhadtree::definetree(TTree * tree) {
  tree->Branch("eventNumber", &event_number);
  tree->Branch("mc_channel_number", &mc_channel_number);
  tree->Branch("runNumber",&run_number);
  tree->Branch("weights",&weights);
  if(reduce == 1){
    tree->Branch("tau_pt_0",&tau_pt_0);
    tree->Branch("tau_pt_1",&tau_pt_1);
    tree->Branch("bjets_fjvt",bjets_fjvt);
    tree->Branch("bjets_is_Jvt_HS",bjets_is_Jvt_HS);
    tree->Branch("bjets_jvt",bjets_jvt);
    tree->Branch("bjets_origin",bjets_origin);
    tree->Branch("bjets_p4",bjets_p4);
    tree->Branch("bjets_type",bjets_type);
    tree->Branch("bjets_width",bjets_width);
    tree->Branch("ditau_coll_approx", &ditau_coll_approx);
    tree->Branch("ditau_coll_approx_m", &ditau_coll_approx_m);
    tree->Branch("ditau_coll_approx_x0", &ditau_coll_approx_x0);
    tree->Branch("ditau_coll_approx_x1", &ditau_coll_approx_x1);
    tree->Branch("ditau_cosalpha", &ditau_cosalpha);
    tree->Branch("ditau_deta", &ditau_deta);
    tree->Branch("ditau_dphi", &ditau_dphi);
    tree->Branch("ditau_dr", &ditau_dr);
    tree->Branch("ditau_higgspt", &ditau_higgspt);
    tree->Branch("ditau_met_centrality", &ditau_met_centrality);
    tree->Branch("ditau_met_lep0_cos_dphi", &ditau_met_lep0_cos_dphi);
    tree->Branch("ditau_met_lep1_cos_dphi", &ditau_met_lep1_cos_dphi);
    tree->Branch("ditau_met_min_dphi", &ditau_met_min_dphi);
    tree->Branch("ditau_met_sum_cos_dphi", &ditau_met_sum_cos_dphi);
    tree->Branch("ditau_mmc_maxw_eta", &ditau_mmc_maxw_eta);
    tree->Branch("ditau_mmc_maxw_fit_status", &ditau_mmc_maxw_fit_status);
    tree->Branch("ditau_mmc_maxw_m", &ditau_mmc_maxw_m);
    tree->Branch("ditau_mmc_maxw_met_et", &ditau_mmc_maxw_met_et);
    tree->Branch("ditau_mmc_maxw_met_phi", &ditau_mmc_maxw_met_phi);
    tree->Branch("ditau_mmc_maxw_phi", &ditau_mmc_maxw_phi);
    tree->Branch("ditau_mmc_maxw_pt", &ditau_mmc_maxw_pt);
    tree->Branch("ditau_mmc_maxw_x0", &ditau_mmc_maxw_x0);
    tree->Branch("ditau_mmc_maxw_x1", &ditau_mmc_maxw_x1);
    tree->Branch("ditau_mmc_mlm_fit_status", &ditau_mmc_mlm_fit_status);
    tree->Branch("ditau_mmc_mlm_m", &ditau_mmc_mlm_m);
    tree->Branch("ditau_mt_lep0_met", &ditau_mt_lep0_met);
    tree->Branch("ditau_mt_lep1_met", &ditau_mt_lep1_met);
    tree->Branch("met_p4", &met_p4);
    tree->Branch("met_sumet", &met_sumet);
    tree->Branch("taus_id",taus_id);
    tree->Branch("taus_b_tagged",&taus_b_tagged);
    tree->Branch("taus_decay_mode",taus_decay_mode);
    tree->Branch("taus_n_charged_tracks",&taus_n_charged_tracks);
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
  
    if(!isData) {
      tree->Branch("bjets_wztruth_p4",bjets_wztruth_p4);
      tree->Branch("bjets_wztruth_pdgid",bjets_wztruth_pdgid);
      tree->Branch("met_truth_p4", &met_truth_p4);
      tree->Branch("met_truth_sumet", &met_truth_sumet);
      tree->Branch("taus_matched_mother_pdgId",taus_matched_mother_pdgId);
      tree->Branch("taus_matched_mother_status",taus_matched_mother_status);
      tree->Branch("taus_matched_p4",taus_matched_p4);
      tree->Branch("taus_matched_pdgId",taus_matched_pdgId);
      tree->Branch("taus_matched_vis_p4",taus_matched_vis_p4);
      tree->Branch("jets_wztruth_p4",jets_wztruth_p4);
      tree->Branch("jets_wztruth_pdgid",jets_wztruth_pdgid);
    }
    return;
  }
  if(reduce == 2){
    tree->Branch("taus_b_tagged",&taus_b_tagged);
    tree->Branch("taus_n_charged_tracks",&taus_n_charged_tracks);
    tree->Branch("tauabspdg",&tauabspdg);
    tree->Branch("tau_pt_0",&tau_pt_0);
    tree->Branch("tau_pt_1",&tau_pt_1);
    tree->Branch("etmiss",&etmiss);
    tree->Branch("dphitauetmiss",&dphitauetmiss);
    tree->Branch("ttvismass",&ttvismass);
    tree->Branch("drtautau",&drtautau);
    tree->Branch("drtaujmin",&drtaujmin);
    tree->Branch("phicent",&phicent);
    tree->Branch("t1mass",&t1mass);
    tree->Branch("tautaumass",&tautaumass);
    tree->Branch("wmass",&wmass);
    tree->Branch("t2mass",&t2mass);
    tree->Branch("x1fit",&x1fit);
    tree->Branch("x2fit",&x2fit);
    return;
  }
}
void hadhadtree::definetaus(){
  if(taus_id->size()) taus_id->clear();
  if(taus_b_tagged->size()) taus_b_tagged->clear();
  if(taus_decay_mode->size()) taus_decay_mode->clear();
  if(!isData) if(taus_matched_mother_pdgId->size()) taus_matched_mother_pdgId->clear();
  if(!isData) if(taus_matched_mother_status->size()) taus_matched_mother_status->clear();
  if(!isData) if(taus_matched_p4->size()) taus_matched_p4->clear();
  if(!isData) if(taus_matched_pdgId->size()) taus_matched_pdgId->clear();
  if(!isData) if(taus_matched_vis_p4->size()) taus_matched_vis_p4->clear();
  if(taus_n_charged_tracks->size()) taus_n_charged_tracks->clear();
  if(taus_p4->size()) taus_p4->clear();
  if(taus_q->size()) taus_q->clear();
  if(taus_id->size()) taus_id->clear();

  int tau0id = tau_0_jet_bdt_tight?3:(tau_0_jet_bdt_medium?2:1);
  int tau1id = tau_1_jet_bdt_tight?3:(tau_1_jet_bdt_medium?2:1);

  taus_id->push_back(tau0id);
  taus_b_tagged->push_back(tau_0_b_tagged);
  taus_decay_mode->push_back(tau_0_decay_mode);
  if(!isData) taus_matched_mother_pdgId->push_back(tau_0_matched_mother_pdgId);
  if(!isData) taus_matched_mother_status->push_back(tau_0_matched_mother_status);
  if(!isData) taus_matched_p4->push_back(tau_0_matched_p4);
  if(!isData) taus_matched_pdgId->push_back(tau_0_matched_pdgId);
  if(!isData) taus_matched_vis_p4->push_back(tau_0_matched_vis_p4);
  taus_n_charged_tracks->push_back(tau_0_n_charged_tracks);
  taus_p4->push_back(tau_0_p4);
  taus_q->push_back(tau_0_q);

  taus_id->push_back(tau1id);
  taus_b_tagged->push_back(tau_1_b_tagged);
  taus_decay_mode->push_back(tau_1_decay_mode);
  if(!isData) taus_matched_mother_pdgId->push_back(tau_1_matched_mother_pdgId);
  if(!isData) taus_matched_mother_status->push_back(tau_1_matched_mother_status);
  if(!isData) taus_matched_p4->push_back(tau_1_matched_p4);
  if(!isData) taus_matched_pdgId->push_back(tau_1_matched_pdgId);
  if(!isData) taus_matched_vis_p4->push_back(tau_1_matched_vis_p4);
  taus_n_charged_tracks->push_back(tau_1_n_charged_tracks);
  taus_p4->push_back(tau_1_p4);
  taus_q->push_back(tau_1_q);
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
  if(bjets_fjvt->size()) bjets_fjvt->clear();
  if(bjets_is_Jvt_HS->size()) bjets_is_Jvt_HS->clear();
  if(bjets_jvt->size()) bjets_jvt->clear();
  if(bjets_p4->size()) bjets_p4->clear();
  if(bjets_width->size()) bjets_width->clear();
  if(bjets_wztruth_pdgid->size()) bjets_wztruth_pdgid->clear();
  if(bjets_wztruth_p4->size()) bjets_wztruth_p4->clear();
  if(jet_0_b_tagged){
    bjets_fjvt->push_back(jet_0_fjvt);
    bjets_is_Jvt_HS->push_back(jet_0_is_Jvt_HS);
    bjets_jvt->push_back(jet_0_jvt);
    bjets_p4->push_back(jet_0_p4);
    bjets_width->push_back(jet_0_width);
    if(!isData) bjets_wztruth_p4->push_back(jet_0_wztruth_p4);
    if(!isData) bjets_wztruth_pdgid->push_back(jet_0_wztruth_pdgid);
  }
  else{
    jets_fjvt->push_back(jet_0_fjvt);
    jets_is_Jvt_HS->push_back(jet_0_is_Jvt_HS);
    jets_jvt->push_back(jet_0_jvt);
    jets_p4->push_back(jet_0_p4);
    jets_width->push_back(jet_0_width);
    if(!isData) jets_wztruth_p4->push_back(jet_0_wztruth_p4);
    if(!isData) jets_wztruth_pdgid->push_back(jet_0_wztruth_pdgid);
  }
  if(jet_1_b_tagged){
    bjets_fjvt->push_back(jet_1_fjvt);
    bjets_is_Jvt_HS->push_back(jet_1_is_Jvt_HS);
    bjets_jvt->push_back(jet_1_jvt);
    bjets_p4->push_back(jet_1_p4);
    bjets_width->push_back(jet_1_width);
    if(!isData) bjets_wztruth_p4->push_back(jet_1_wztruth_p4);
    if(!isData) bjets_wztruth_pdgid->push_back(jet_1_wztruth_pdgid);
  }
  else{
    jets_fjvt->push_back(jet_1_fjvt);
    jets_is_Jvt_HS->push_back(jet_1_is_Jvt_HS);
    jets_jvt->push_back(jet_1_jvt);
    jets_p4->push_back(jet_1_p4);
    jets_width->push_back(jet_1_width);
    if(!isData) jets_wztruth_p4->push_back(jet_1_wztruth_p4);
    if(!isData) jets_wztruth_pdgid->push_back(jet_1_wztruth_pdgid);
  }
  if(jet_2_b_tagged){
    bjets_fjvt->push_back(jet_2_fjvt);
    bjets_is_Jvt_HS->push_back(jet_2_is_Jvt_HS);
    bjets_jvt->push_back(jet_2_jvt);
    bjets_p4->push_back(jet_2_p4);
    bjets_width->push_back(jet_2_width);
    if(!isData) bjets_wztruth_p4->push_back(jet_2_wztruth_p4);
    if(!isData) bjets_wztruth_pdgid->push_back(jet_2_wztruth_pdgid);
  }
  else{
    jets_fjvt->push_back(jet_2_fjvt);
    jets_is_Jvt_HS->push_back(jet_2_is_Jvt_HS);
    jets_jvt->push_back(jet_2_jvt);
    jets_p4->push_back(jet_2_p4);
    jets_width->push_back(jet_2_width);
    if(!isData) jets_wztruth_p4->push_back(jet_2_wztruth_p4);
    if(!isData) jets_wztruth_pdgid->push_back(jet_2_wztruth_pdgid);
  }
  if (jet_3)
  {
    if(jet_3_b_tagged){
      bjets_fjvt->push_back(jet_3_fjvt);
      bjets_is_Jvt_HS->push_back(jet_3_is_Jvt_HS);
      bjets_jvt->push_back(jet_3_jvt);
      bjets_p4->push_back(jet_3_p4);
      bjets_width->push_back(jet_3_width);
      if(!isData) bjets_wztruth_p4->push_back(jet_3_wztruth_p4);
      if(!isData) bjets_wztruth_pdgid->push_back(jet_3_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_3_fjvt);
      jets_is_Jvt_HS->push_back(jet_3_is_Jvt_HS);
      jets_jvt->push_back(jet_3_jvt);
      jets_p4->push_back(jet_3_p4);
      jets_width->push_back(jet_3_width);
      if(!isData) jets_wztruth_p4->push_back(jet_3_wztruth_p4);
      if(!isData) jets_wztruth_pdgid->push_back(jet_3_wztruth_pdgid);
    }
  }
  if (jet_4)
  {
    if(jet_4_b_tagged){
      bjets_fjvt->push_back(jet_4_fjvt);
      bjets_is_Jvt_HS->push_back(jet_4_is_Jvt_HS);
      bjets_jvt->push_back(jet_4_jvt);
      bjets_p4->push_back(jet_4_p4);
      bjets_width->push_back(jet_4_width);
      if(!isData) bjets_wztruth_p4->push_back(jet_4_wztruth_p4);
      if(!isData) bjets_wztruth_pdgid->push_back(jet_4_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_4_fjvt);
      jets_is_Jvt_HS->push_back(jet_4_is_Jvt_HS);
      jets_jvt->push_back(jet_4_jvt);
      jets_p4->push_back(jet_4_p4);
      jets_width->push_back(jet_4_width);
      if(!isData) jets_wztruth_p4->push_back(jet_4_wztruth_p4);
      if(!isData) jets_wztruth_pdgid->push_back(jet_4_wztruth_pdgid);
    }
  }
  if (jet_5)
  {
    if(jet_5_b_tagged){
      bjets_fjvt->push_back(jet_5_fjvt);
      bjets_is_Jvt_HS->push_back(jet_5_is_Jvt_HS);
      bjets_jvt->push_back(jet_5_jvt);
      bjets_p4->push_back(jet_5_p4);
      bjets_width->push_back(jet_5_width);
      if(!isData) bjets_wztruth_p4->push_back(jet_5_wztruth_p4);
      if(!isData) bjets_wztruth_pdgid->push_back(jet_5_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_5_fjvt);
      jets_is_Jvt_HS->push_back(jet_5_is_Jvt_HS);
      jets_jvt->push_back(jet_5_jvt);
      jets_p4->push_back(jet_5_p4);
      jets_width->push_back(jet_5_width);
      if(!isData) jets_wztruth_p4->push_back(jet_5_wztruth_p4);
      if(!isData) jets_wztruth_pdgid->push_back(jet_5_wztruth_pdgid);
    }
  }
  if (jet_6)
  {
    if(jet_6_b_tagged){
      bjets_fjvt->push_back(jet_6_fjvt);
      bjets_is_Jvt_HS->push_back(jet_6_is_Jvt_HS);
      bjets_jvt->push_back(jet_6_jvt);
      bjets_p4->push_back(jet_6_p4);
      bjets_width->push_back(jet_6_width);
      if(!isData) bjets_wztruth_p4->push_back(jet_6_wztruth_p4);
      if(!isData) bjets_wztruth_pdgid->push_back(jet_6_wztruth_pdgid);
    }
    else{
      jets_fjvt->push_back(jet_6_fjvt);
      jets_is_Jvt_HS->push_back(jet_6_is_Jvt_HS);
      jets_jvt->push_back(jet_6_jvt);
      jets_p4->push_back(jet_6_p4);
      jets_width->push_back(jet_6_width);
      if(!isData) jets_wztruth_p4->push_back(jet_6_wztruth_p4);
      if(!isData) jets_wztruth_pdgid->push_back(jet_6_wztruth_pdgid);
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
  if(reduce == 2){
   tree->SetBranchAddress("taus_b_tagged",&taus_b_tagged);
   tree->SetBranchAddress("taus_n_charged_tracks",&taus_n_charged_tracks);
   tree->SetBranchAddress("tauabspdg",&tauabspdg);
   tree->SetBranchAddress("eventNumber", &event_number);
   tree->SetBranchAddress("mc_channel_number", &mc_channel_number);
   tree->SetBranchAddress("runNumber", &run_number);
   tree->SetBranchAddress("weights", &weights);
   tree->SetBranchAddress("tauabspdg", &tauabspdg);
   tree->SetBranchAddress("tau_pt_0", &tau_pt_0);
   tree->SetBranchAddress("tau_pt_1", &tau_pt_1);
   tree->SetBranchAddress("etmiss", &etmiss);
   tree->SetBranchAddress("dphitauetmiss", &dphitauetmiss);
   tree->SetBranchAddress("ttvismass", &ttvismass);
   tree->SetBranchAddress("drtautau", &drtautau);
   tree->SetBranchAddress("drtaujmin", &drtaujmin);
   tree->SetBranchAddress("phicent", &phicent);
   tree->SetBranchAddress("t1mass", &t1mass);
   tree->SetBranchAddress("tautaumass", &tautaumass);
   tree->SetBranchAddress("wmass", &wmass);
   tree->SetBranchAddress("t2mass", &t2mass);
   tree->SetBranchAddress("x1fit", &x1fit);
   tree->SetBranchAddress("x2fit", &x2fit);
   return;
  }
  if(reduce == 1) {
    weights = 0;
    bjets_fjvt = 0;
    bjets_is_Jvt_HS = 0;
    bjets_jvt = 0;
    bjets_origin = 0;
    bjets_p4 = 0;
    bjets_type = 0;
    bjets_width = 0;
    met_p4 = 0;
    taus_id = 0;
    taus_b_tagged = 0;
    taus_decay_mode = 0;
    bjets_wztruth_p4 = 0;
    bjets_wztruth_pdgid = 0;
    met_truth_p4 = 0;
    taus_matched_mother_pdgId = 0;
    taus_matched_mother_status = 0;
    taus_matched_p4 = 0;
    taus_matched_pdgId = 0;
    taus_matched_vis_p4 = 0;
    jets_wztruth_p4 = 0;
    jets_wztruth_pdgid = 0;
    taus_n_charged_tracks = 0;
    taus_p4 = 0;
    taus_q = 0;
    jets_fjvt = 0;
    jets_is_Jvt_HS = 0;
    jets_jvt = 0;
    jets_origin = 0;
    jets_p4 = 0;
    jets_q = 0;
    jets_type = 0;
    jets_width = 0;
    tree->SetBranchAddress("eventNumber", &event_number);
    tree->SetBranchAddress("mc_channel_number", &mc_channel_number);
    tree->SetBranchAddress("runNumber", &run_number);
    tree->SetBranchAddress("weights", &weights);
    tree->SetBranchAddress("tau_pt_0", &tau_pt_0);
    tree->SetBranchAddress("tau_pt_1", &tau_pt_1);
    tree->SetBranchAddress("bjets_fjvt", &bjets_fjvt);
    tree->SetBranchAddress("bjets_is_Jvt_HS", &bjets_is_Jvt_HS);
    tree->SetBranchAddress("bjets_jvt", &bjets_jvt);
    tree->SetBranchAddress("bjets_origin", &bjets_origin);
    tree->SetBranchAddress("bjets_p4", &bjets_p4);
    tree->SetBranchAddress("bjets_type", &bjets_type);
    tree->SetBranchAddress("bjets_width", &bjets_width);
    tree->SetBranchAddress("ditau_coll_approx", &ditau_coll_approx);
    tree->SetBranchAddress("ditau_coll_approx_m", &ditau_coll_approx_m);
    tree->SetBranchAddress("ditau_coll_approx_x0", &ditau_coll_approx_x0);
    tree->SetBranchAddress("ditau_coll_approx_x1", &ditau_coll_approx_x1);
    tree->SetBranchAddress("ditau_cosalpha", &ditau_cosalpha);
    tree->SetBranchAddress("ditau_deta", &ditau_deta);
    tree->SetBranchAddress("ditau_dphi", &ditau_dphi);
    tree->SetBranchAddress("ditau_dr", &ditau_dr);
    tree->SetBranchAddress("ditau_higgspt", &ditau_higgspt);
    tree->SetBranchAddress("ditau_met_centrality", &ditau_met_centrality);
    tree->SetBranchAddress("ditau_met_lep0_cos_dphi", &ditau_met_lep0_cos_dphi);
    tree->SetBranchAddress("ditau_met_lep1_cos_dphi", &ditau_met_lep1_cos_dphi);
    tree->SetBranchAddress("ditau_met_min_dphi", &ditau_met_min_dphi);
    tree->SetBranchAddress("ditau_met_sum_cos_dphi", &ditau_met_sum_cos_dphi);
    tree->SetBranchAddress("ditau_mmc_maxw_eta", &ditau_mmc_maxw_eta);
    tree->SetBranchAddress("ditau_mmc_maxw_fit_status", &ditau_mmc_maxw_fit_status);
    tree->SetBranchAddress("ditau_mmc_maxw_m", &ditau_mmc_maxw_m);
    tree->SetBranchAddress("ditau_mmc_maxw_met_et", &ditau_mmc_maxw_met_et);
    tree->SetBranchAddress("ditau_mmc_maxw_met_phi", &ditau_mmc_maxw_met_phi);
    tree->SetBranchAddress("ditau_mmc_maxw_phi", &ditau_mmc_maxw_phi);
    tree->SetBranchAddress("ditau_mmc_maxw_pt", &ditau_mmc_maxw_pt);
    tree->SetBranchAddress("ditau_mmc_maxw_x0", &ditau_mmc_maxw_x0);
    tree->SetBranchAddress("ditau_mmc_maxw_x1", &ditau_mmc_maxw_x1);
    tree->SetBranchAddress("ditau_mmc_mlm_fit_status", &ditau_mmc_mlm_fit_status);
    tree->SetBranchAddress("ditau_mmc_mlm_m", &ditau_mmc_mlm_m);
    tree->SetBranchAddress("ditau_mt_lep0_met", &ditau_mt_lep0_met);
    tree->SetBranchAddress("ditau_mt_lep1_met", &ditau_mt_lep1_met);
    tree->SetBranchAddress("met_p4", &met_p4);
    tree->SetBranchAddress("met_sumet", &met_sumet);
    tree->SetBranchAddress("taus_id", &taus_id);
    tree->SetBranchAddress("taus_b_tagged", &taus_b_tagged);
    tree->SetBranchAddress("taus_decay_mode", &taus_decay_mode);
    tree->SetBranchAddress("bjets_wztruth_p4", &bjets_wztruth_p4);
    tree->SetBranchAddress("bjets_wztruth_pdgid", &bjets_wztruth_pdgid);
    tree->SetBranchAddress("met_truth_p4", &met_truth_p4);
    tree->SetBranchAddress("met_truth_sumet", &met_truth_sumet);
    tree->SetBranchAddress("taus_matched_mother_pdgId", &taus_matched_mother_pdgId);
    tree->SetBranchAddress("taus_matched_mother_status", &taus_matched_mother_status);
    tree->SetBranchAddress("taus_matched_p4", &taus_matched_p4);
    tree->SetBranchAddress("taus_matched_pdgId", &taus_matched_pdgId);
    tree->SetBranchAddress("taus_matched_vis_p4", &taus_matched_vis_p4);
    tree->SetBranchAddress("jets_wztruth_p4", &jets_wztruth_p4);
    tree->SetBranchAddress("jets_wztruth_pdgid", &jets_wztruth_pdgid);
    tree->SetBranchAddress("taus_n_charged_tracks", &taus_n_charged_tracks);
    tree->SetBranchAddress("taus_p4", &taus_p4);
    tree->SetBranchAddress("taus_q", &taus_q);
    tree->SetBranchAddress("jets_fjvt", &jets_fjvt);
    tree->SetBranchAddress("jets_is_Jvt_HS", &jets_is_Jvt_HS);
    tree->SetBranchAddress("jets_jvt", &jets_jvt);
    tree->SetBranchAddress("jets_origin", &jets_origin);
    tree->SetBranchAddress("jets_p4", &jets_p4);
    tree->SetBranchAddress("jets_q", &jets_q);
    tree->SetBranchAddress("jets_type", &jets_type);
    tree->SetBranchAddress("jets_width", &jets_width);
    return;
  }

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
  met_hpto_p4 = 0;
  met_p4 = 0;
  met_truth_p4 = 0;
  primary_vertex_v = 0;
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
  tree->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I);
  tree->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25);
  tree->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I);
  tree->SetBranchAddress("HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25", &HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25, &b_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25);
  tree->SetBranchAddress("dijet_deta", &dijet_deta, &b_dijet_deta);
  tree->SetBranchAddress("dijet_dphi", &dijet_dphi, &b_dijet_dphi);
  tree->SetBranchAddress("dijet_m", &dijet_m, &b_dijet_m);
  tree->SetBranchAddress("dijet_prod_eta", &dijet_prod_eta, &b_dijet_prod_eta);
  tree->SetBranchAddress("dijet_pt", &dijet_pt, &b_dijet_pt);
  tree->SetBranchAddress("ditau_coll_approx", &ditau_coll_approx, &b_ditau_coll_approx);
  tree->SetBranchAddress("ditau_coll_approx_m", &ditau_coll_approx_m, &b_ditau_coll_approx_m);
  tree->SetBranchAddress("ditau_coll_approx_x0", &ditau_coll_approx_x0, &b_ditau_coll_approx_x0);
  tree->SetBranchAddress("ditau_coll_approx_x1", &ditau_coll_approx_x1, &b_ditau_coll_approx_x1);
  tree->SetBranchAddress("ditau_cosalpha", &ditau_cosalpha, &b_ditau_cosalpha);
  tree->SetBranchAddress("ditau_deta", &ditau_deta, &b_ditau_deta);
  tree->SetBranchAddress("ditau_dphi", &ditau_dphi, &b_ditau_dphi);
  tree->SetBranchAddress("ditau_dr", &ditau_dr, &b_ditau_dr);
  tree->SetBranchAddress("ditau_higgspt", &ditau_higgspt, &b_ditau_higgspt);
  tree->SetBranchAddress("ditau_met_centrality", &ditau_met_centrality, &b_ditau_met_centrality);
  tree->SetBranchAddress("ditau_met_lep0_cos_dphi", &ditau_met_lep0_cos_dphi, &b_ditau_met_lep0_cos_dphi);
  tree->SetBranchAddress("ditau_met_lep1_cos_dphi", &ditau_met_lep1_cos_dphi, &b_ditau_met_lep1_cos_dphi);
  tree->SetBranchAddress("ditau_met_min_dphi", &ditau_met_min_dphi, &b_ditau_met_min_dphi);
  tree->SetBranchAddress("ditau_met_sum_cos_dphi", &ditau_met_sum_cos_dphi, &b_ditau_met_sum_cos_dphi);
  tree->SetBranchAddress("ditau_mmc_maxw_eta", &ditau_mmc_maxw_eta, &b_ditau_mmc_maxw_eta);
  tree->SetBranchAddress("ditau_mmc_maxw_fit_status", &ditau_mmc_maxw_fit_status, &b_ditau_mmc_maxw_fit_status);
  tree->SetBranchAddress("ditau_mmc_maxw_m", &ditau_mmc_maxw_m, &b_ditau_mmc_maxw_m);
  tree->SetBranchAddress("ditau_mmc_maxw_met_et", &ditau_mmc_maxw_met_et, &b_ditau_mmc_maxw_met_et);
  tree->SetBranchAddress("ditau_mmc_maxw_met_phi", &ditau_mmc_maxw_met_phi, &b_ditau_mmc_maxw_met_phi);
  tree->SetBranchAddress("ditau_mmc_maxw_phi", &ditau_mmc_maxw_phi, &b_ditau_mmc_maxw_phi);
  tree->SetBranchAddress("ditau_mmc_maxw_pt", &ditau_mmc_maxw_pt, &b_ditau_mmc_maxw_pt);
  tree->SetBranchAddress("ditau_mmc_maxw_x0", &ditau_mmc_maxw_x0, &b_ditau_mmc_maxw_x0);
  tree->SetBranchAddress("ditau_mmc_maxw_x1", &ditau_mmc_maxw_x1, &b_ditau_mmc_maxw_x1);
  tree->SetBranchAddress("ditau_mmc_mlm_fit_status", &ditau_mmc_mlm_fit_status, &b_ditau_mmc_mlm_fit_status);
  tree->SetBranchAddress("ditau_mmc_mlm_m", &ditau_mmc_mlm_m, &b_ditau_mmc_mlm_m);
  tree->SetBranchAddress("ditau_mt_lep0_met", &ditau_mt_lep0_met, &b_ditau_mt_lep0_met);
  tree->SetBranchAddress("ditau_mt_lep1_met", &ditau_mt_lep1_met, &b_ditau_mt_lep1_met);
  tree->SetBranchAddress("ditau_p4", &ditau_p4, &b_ditau_p4);
  tree->SetBranchAddress("ditau_qxq", &ditau_qxq, &b_ditau_qxq);
  tree->SetBranchAddress("ditau_scal_sum_pt", &ditau_scal_sum_pt, &b_ditau_scal_sum_pt);
  tree->SetBranchAddress("event_clean_EC_TightBad", &event_clean_EC_TightBad, &b_event_clean_EC_TightBad);
  tree->SetBranchAddress("event_number", &event_number, &b_event_number);
  tree->SetBranchAddress("is_dijet_centrality", &is_dijet_centrality, &b_is_dijet_centrality);
  tree->SetBranchAddress("jet_0_b_tagged", &jet_0_b_tagged, &b_jet_0_b_tagged);
  tree->SetBranchAddress("jet_0_fjvt", &jet_0_fjvt, &b_jet_0_fjvt);
  tree->SetBranchAddress("jet_0_flavorlabel_part", &jet_0_flavorlabel_part, &b_jet_0_flavorlabel_part);
  tree->SetBranchAddress("jet_0_is_Jvt_HS", &jet_0_is_Jvt_HS, &b_jet_0_is_Jvt_HS);
  tree->SetBranchAddress("jet_0_jvt", &jet_0_jvt, &b_jet_0_jvt);
  tree->SetBranchAddress("jet_0_p4", &jet_0_p4, &b_jet_0_p4);
  tree->SetBranchAddress("jet_0_width", &jet_0_width, &b_jet_0_width);
  tree->SetBranchAddress("jet_1_b_tagged", &jet_1_b_tagged, &b_jet_1_b_tagged);
  tree->SetBranchAddress("jet_1_fjvt", &jet_1_fjvt, &b_jet_1_fjvt);
  tree->SetBranchAddress("jet_1_flavorlabel_part", &jet_1_flavorlabel_part, &b_jet_1_flavorlabel_part);
  tree->SetBranchAddress("jet_1_is_Jvt_HS", &jet_1_is_Jvt_HS, &b_jet_1_is_Jvt_HS);
  tree->SetBranchAddress("jet_1_jvt", &jet_1_jvt, &b_jet_1_jvt);
  tree->SetBranchAddress("jet_1_p4", &jet_1_p4, &b_jet_1_p4);
  tree->SetBranchAddress("jet_1_width", &jet_1_width, &b_jet_1_width);
  tree->SetBranchAddress("jet_2_b_tagged", &jet_2_b_tagged, &b_jet_2_b_tagged);
  tree->SetBranchAddress("jet_2_fjvt", &jet_2_fjvt, &b_jet_2_fjvt);
  tree->SetBranchAddress("jet_2_flavorlabel_part", &jet_2_flavorlabel_part, &b_jet_2_flavorlabel_part);
  tree->SetBranchAddress("jet_2_is_Jvt_HS", &jet_2_is_Jvt_HS, &b_jet_2_is_Jvt_HS);
  tree->SetBranchAddress("jet_2_jvt", &jet_2_jvt, &b_jet_2_jvt);
  tree->SetBranchAddress("jet_2_p4", &jet_2_p4, &b_jet_2_p4);
  tree->SetBranchAddress("jet_2_width", &jet_2_width, &b_jet_2_width);
  tree->SetBranchAddress("jet_3", &jet_3, &b_jet_3);
  tree->SetBranchAddress("jet_3_b_tag_quantile", &jet_3_b_tag_quantile, &b_jet_3_b_tag_quantile);
  tree->SetBranchAddress("jet_3_b_tag_score", &jet_3_b_tag_score, &b_jet_3_b_tag_score);
  tree->SetBranchAddress("jet_3_b_tagged", &jet_3_b_tagged, &b_jet_3_b_tagged);
  tree->SetBranchAddress("jet_3_cleanJet_EC_LooseBad", &jet_3_cleanJet_EC_LooseBad, &b_jet_3_cleanJet_EC_LooseBad);
  tree->SetBranchAddress("jet_3_fjvt", &jet_3_fjvt, &b_jet_3_fjvt);
  tree->SetBranchAddress("jet_3_flavorlabel", &jet_3_flavorlabel, &b_jet_3_flavorlabel);
  tree->SetBranchAddress("jet_3_flavorlabel_cone", &jet_3_flavorlabel_cone, &b_jet_3_flavorlabel_cone);
  tree->SetBranchAddress("jet_3_flavorlabel_part", &jet_3_flavorlabel_part, &b_jet_3_flavorlabel_part);
  tree->SetBranchAddress("jet_3_is_Jvt_HS", &jet_3_is_Jvt_HS, &b_jet_3_is_Jvt_HS);
  tree->SetBranchAddress("jet_3_jvt", &jet_3_jvt, &b_jet_3_jvt);
  tree->SetBranchAddress("jet_3_p4", &jet_3_p4, &b_jet_3_p4);
  tree->SetBranchAddress("jet_3_width", &jet_3_width, &b_jet_3_width);
  tree->SetBranchAddress("jet_4", &jet_4, &b_jet_4);
  tree->SetBranchAddress("jet_4_b_tag_quantile", &jet_4_b_tag_quantile, &b_jet_4_b_tag_quantile);
  tree->SetBranchAddress("jet_4_b_tag_score", &jet_4_b_tag_score, &b_jet_4_b_tag_score);
  tree->SetBranchAddress("jet_4_b_tagged", &jet_4_b_tagged, &b_jet_4_b_tagged);
  tree->SetBranchAddress("jet_4_cleanJet_EC_LooseBad", &jet_4_cleanJet_EC_LooseBad, &b_jet_4_cleanJet_EC_LooseBad);
  tree->SetBranchAddress("jet_4_fjvt", &jet_4_fjvt, &b_jet_4_fjvt);
  tree->SetBranchAddress("jet_4_flavorlabel", &jet_4_flavorlabel, &b_jet_4_flavorlabel);
  tree->SetBranchAddress("jet_4_flavorlabel_cone", &jet_4_flavorlabel_cone, &b_jet_4_flavorlabel_cone);
  tree->SetBranchAddress("jet_4_flavorlabel_part", &jet_4_flavorlabel_part, &b_jet_4_flavorlabel_part);
  tree->SetBranchAddress("jet_4_is_Jvt_HS", &jet_4_is_Jvt_HS, &b_jet_4_is_Jvt_HS);
  tree->SetBranchAddress("jet_4_jvt", &jet_4_jvt, &b_jet_4_jvt);
  tree->SetBranchAddress("jet_4_p4", &jet_4_p4, &b_jet_4_p4);
  tree->SetBranchAddress("jet_4_width", &jet_4_width, &b_jet_4_width);
  tree->SetBranchAddress("jet_5", &jet_5, &b_jet_5);
  tree->SetBranchAddress("jet_5_b_tag_quantile", &jet_5_b_tag_quantile, &b_jet_5_b_tag_quantile);
  tree->SetBranchAddress("jet_5_b_tag_score", &jet_5_b_tag_score, &b_jet_5_b_tag_score);
  tree->SetBranchAddress("jet_5_b_tagged", &jet_5_b_tagged, &b_jet_5_b_tagged);
  tree->SetBranchAddress("jet_5_cleanJet_EC_LooseBad", &jet_5_cleanJet_EC_LooseBad, &b_jet_5_cleanJet_EC_LooseBad);
  tree->SetBranchAddress("jet_5_fjvt", &jet_5_fjvt, &b_jet_5_fjvt);
  tree->SetBranchAddress("jet_5_flavorlabel", &jet_5_flavorlabel, &b_jet_5_flavorlabel);
  tree->SetBranchAddress("jet_5_flavorlabel_cone", &jet_5_flavorlabel_cone, &b_jet_5_flavorlabel_cone);
  tree->SetBranchAddress("jet_5_flavorlabel_part", &jet_5_flavorlabel_part, &b_jet_5_flavorlabel_part);
  tree->SetBranchAddress("jet_5_is_Jvt_HS", &jet_5_is_Jvt_HS, &b_jet_5_is_Jvt_HS);
  tree->SetBranchAddress("jet_5_jvt", &jet_5_jvt, &b_jet_5_jvt);
  tree->SetBranchAddress("jet_5_p4", &jet_5_p4, &b_jet_5_p4);
  tree->SetBranchAddress("jet_5_width", &jet_5_width, &b_jet_5_width);
  tree->SetBranchAddress("jet_6", &jet_6, &b_jet_6);
  tree->SetBranchAddress("jet_6_b_tag_quantile", &jet_6_b_tag_quantile, &b_jet_6_b_tag_quantile);
  tree->SetBranchAddress("jet_6_b_tag_score", &jet_6_b_tag_score, &b_jet_6_b_tag_score);
  tree->SetBranchAddress("jet_6_b_tagged", &jet_6_b_tagged, &b_jet_6_b_tagged);
  tree->SetBranchAddress("jet_6_cleanJet_EC_LooseBad", &jet_6_cleanJet_EC_LooseBad, &b_jet_6_cleanJet_EC_LooseBad);
  tree->SetBranchAddress("jet_6_fjvt", &jet_6_fjvt, &b_jet_6_fjvt);
  tree->SetBranchAddress("jet_6_flavorlabel", &jet_6_flavorlabel, &b_jet_6_flavorlabel);
  tree->SetBranchAddress("jet_6_flavorlabel_cone", &jet_6_flavorlabel_cone, &b_jet_6_flavorlabel_cone);
  tree->SetBranchAddress("jet_6_flavorlabel_part", &jet_6_flavorlabel_part, &b_jet_6_flavorlabel_part);
  tree->SetBranchAddress("jet_6_is_Jvt_HS", &jet_6_is_Jvt_HS, &b_jet_6_is_Jvt_HS);
  tree->SetBranchAddress("jet_6_jvt", &jet_6_jvt, &b_jet_6_jvt);
  tree->SetBranchAddress("jet_6_p4", &jet_6_p4, &b_jet_6_p4);
  tree->SetBranchAddress("jet_6_width", &jet_6_width, &b_jet_6_width);
  tree->SetBranchAddress("lepton_eta_centrality", &lepton_eta_centrality, &b_lepton_eta_centrality);
  tree->SetBranchAddress("met_hpto_p4", &met_hpto_p4, &b_met_hpto_p4);
  tree->SetBranchAddress("met_more_met_et_ele", &met_more_met_et_ele, &b_met_more_met_et_ele);
  tree->SetBranchAddress("met_more_met_et_jet", &met_more_met_et_jet, &b_met_more_met_et_jet);
  tree->SetBranchAddress("met_more_met_et_muon", &met_more_met_et_muon, &b_met_more_met_et_muon);
  tree->SetBranchAddress("met_more_met_et_pho", &met_more_met_et_pho, &b_met_more_met_et_pho);
  tree->SetBranchAddress("met_more_met_et_soft", &met_more_met_et_soft, &b_met_more_met_et_soft);
  tree->SetBranchAddress("met_more_met_et_tau", &met_more_met_et_tau, &b_met_more_met_et_tau);
  tree->SetBranchAddress("met_more_met_phi_ele", &met_more_met_phi_ele, &b_met_more_met_phi_ele);
  tree->SetBranchAddress("met_more_met_phi_jet", &met_more_met_phi_jet, &b_met_more_met_phi_jet);
  tree->SetBranchAddress("met_more_met_phi_muon", &met_more_met_phi_muon, &b_met_more_met_phi_muon);
  tree->SetBranchAddress("met_more_met_phi_pho", &met_more_met_phi_pho, &b_met_more_met_phi_pho);
  tree->SetBranchAddress("met_more_met_phi_soft", &met_more_met_phi_soft, &b_met_more_met_phi_soft);
  tree->SetBranchAddress("met_more_met_phi_tau", &met_more_met_phi_tau, &b_met_more_met_phi_tau);
  tree->SetBranchAddress("met_more_met_sumet_ele", &met_more_met_sumet_ele, &b_met_more_met_sumet_ele);
  tree->SetBranchAddress("met_more_met_sumet_jet", &met_more_met_sumet_jet, &b_met_more_met_sumet_jet);
  tree->SetBranchAddress("met_more_met_sumet_muon", &met_more_met_sumet_muon, &b_met_more_met_sumet_muon);
  tree->SetBranchAddress("met_more_met_sumet_pho", &met_more_met_sumet_pho, &b_met_more_met_sumet_pho);
  tree->SetBranchAddress("met_more_met_sumet_soft", &met_more_met_sumet_soft, &b_met_more_met_sumet_soft);
  tree->SetBranchAddress("met_more_met_sumet_tau", &met_more_met_sumet_tau, &b_met_more_met_sumet_tau);
  tree->SetBranchAddress("met_p4", &met_p4, &b_met_p4);
  tree->SetBranchAddress("met_sign_met_over_sqrt_ht", &met_sign_met_over_sqrt_ht, &b_met_sign_met_over_sqrt_ht);
  tree->SetBranchAddress("met_sign_met_over_sqrt_sumet", &met_sign_met_over_sqrt_sumet, &b_met_sign_met_over_sqrt_sumet);
  tree->SetBranchAddress("met_sign_met_rho", &met_sign_met_rho, &b_met_sign_met_rho);
  tree->SetBranchAddress("met_sign_met_rho_ttdir", &met_sign_met_rho_ttdir, &b_met_sign_met_rho_ttdir);
  tree->SetBranchAddress("met_sign_met_sig_directional", &met_sign_met_sig_directional, &b_met_sign_met_sig_directional);
  tree->SetBranchAddress("met_sign_met_sig_directional_ttdir", &met_sign_met_sig_directional_ttdir, &b_met_sign_met_sig_directional_ttdir);
  tree->SetBranchAddress("met_sign_met_significance", &met_sign_met_significance, &b_met_sign_met_significance);
  tree->SetBranchAddress("met_sign_met_significance_ttdir", &met_sign_met_significance_ttdir, &b_met_sign_met_significance_ttdir);
  tree->SetBranchAddress("met_sign_met_valL", &met_sign_met_valL, &b_met_sign_met_valL);
  tree->SetBranchAddress("met_sign_met_valL_ttdir", &met_sign_met_valL_ttdir, &b_met_sign_met_valL_ttdir);
  tree->SetBranchAddress("met_sign_met_varT", &met_sign_met_varT, &b_met_sign_met_varT);
  tree->SetBranchAddress("met_sign_met_varT_ttdir", &met_sign_met_varT_ttdir, &b_met_sign_met_varT_ttdir);
  tree->SetBranchAddress("met_sumet", &met_sumet, &b_met_sumet);
  tree->SetBranchAddress("met_truth_p4", &met_truth_p4, &b_met_truth_p4);
  tree->SetBranchAddress("met_truth_sumet", &met_truth_sumet, &b_met_truth_sumet);
  tree->SetBranchAddress("mva_RRN", &mva_RRN, &b_mva_RRN);
  tree->SetBranchAddress("n_actual_int", &n_actual_int, &b_n_actual_int);
  tree->SetBranchAddress("n_actual_int_cor", &n_actual_int_cor, &b_n_actual_int_cor);
  tree->SetBranchAddress("n_avg_int", &n_avg_int, &b_n_avg_int);
  tree->SetBranchAddress("n_avg_int_cor", &n_avg_int_cor, &b_n_avg_int_cor);
  tree->SetBranchAddress("n_bjets", &n_bjets, &b_n_bjets);
  tree->SetBranchAddress("n_electrons", &n_electrons, &b_n_electrons);
  tree->SetBranchAddress("n_jets", &n_jets, &b_n_jets);
  tree->SetBranchAddress("n_jets_30", &n_jets_30, &b_n_jets_30);
  tree->SetBranchAddress("n_jets_40", &n_jets_40, &b_n_jets_40);
  tree->SetBranchAddress("n_jets_central", &n_jets_central, &b_n_jets_central);
  tree->SetBranchAddress("n_jets_central_30", &n_jets_central_30, &b_n_jets_central_30);
  tree->SetBranchAddress("n_jets_central_40", &n_jets_central_40, &b_n_jets_central_40);
  tree->SetBranchAddress("n_jets_forward", &n_jets_forward, &b_n_jets_forward);
  tree->SetBranchAddress("n_jets_forward_30", &n_jets_forward_30, &b_n_jets_forward_30);
  tree->SetBranchAddress("n_jets_forward_40", &n_jets_forward_40, &b_n_jets_forward_40);
  tree->SetBranchAddress("n_jets_l1j25", &n_jets_l1j25, &b_n_jets_l1j25);
  tree->SetBranchAddress("n_jets_mc_hs", &n_jets_mc_hs, &b_n_jets_mc_hs);
  tree->SetBranchAddress("n_muons", &n_muons, &b_n_muons);
  tree->SetBranchAddress("n_photons", &n_photons, &b_n_photons);
  tree->SetBranchAddress("n_pvx", &n_pvx, &b_n_pvx);
  tree->SetBranchAddress("n_taus", &n_taus, &b_n_taus);
  tree->SetBranchAddress("n_taus_loose", &n_taus_loose, &b_n_taus_loose);
  tree->SetBranchAddress("n_taus_medium", &n_taus_medium, &b_n_taus_medium);
  tree->SetBranchAddress("n_taus_tight", &n_taus_tight, &b_n_taus_tight);
  tree->SetBranchAddress("n_taus_veryloose", &n_taus_veryloose, &b_n_taus_veryloose);
  tree->SetBranchAddress("n_vx", &n_vx, &b_n_vx);
  tree->SetBranchAddress("primary_vertex", &primary_vertex, &b_primary_vertex);
  tree->SetBranchAddress("primary_vertex_v", &primary_vertex_v, &b_primary_vertex_v);
  tree->SetBranchAddress("pt_total", &pt_total, &b_pt_total);
  tree->SetBranchAddress("run_number", &run_number, &b_run_number);
  tree->SetBranchAddress("scalar_sum_pt", &scalar_sum_pt, &b_scalar_sum_pt);
  tree->SetBranchAddress("tau_0", &tau_0, &b_tau_0);
  tree->SetBranchAddress("tau_0_allTrk_eta", &tau_0_allTrk_eta, &b_tau_0_allTrk_eta);
  tree->SetBranchAddress("tau_0_allTrk_n", &tau_0_allTrk_n, &b_tau_0_allTrk_n);
  tree->SetBranchAddress("tau_0_allTrk_phi", &tau_0_allTrk_phi, &b_tau_0_allTrk_phi);
  tree->SetBranchAddress("tau_0_allTrk_pt", &tau_0_allTrk_pt, &b_tau_0_allTrk_pt);
  tree->SetBranchAddress("tau_0_b_tagged", &tau_0_b_tagged, &b_tau_0_b_tagged);
  tree->SetBranchAddress("tau_0_decay_mode", &tau_0_decay_mode, &b_tau_0_decay_mode);
  tree->SetBranchAddress("tau_0_ele_bdt_eff_sf", &tau_0_ele_bdt_eff_sf, &b_tau_0_ele_bdt_eff_sf);
  tree->SetBranchAddress("tau_0_ele_bdt_loose_retuned", &tau_0_ele_bdt_loose_retuned, &b_tau_0_ele_bdt_loose_retuned);
  tree->SetBranchAddress("tau_0_ele_bdt_medium_retuned", &tau_0_ele_bdt_medium_retuned, &b_tau_0_ele_bdt_medium_retuned);
  tree->SetBranchAddress("tau_0_ele_bdt_score", &tau_0_ele_bdt_score, &b_tau_0_ele_bdt_score);
  tree->SetBranchAddress("tau_0_ele_bdt_score_retuned", &tau_0_ele_bdt_score_retuned, &b_tau_0_ele_bdt_score_retuned);
  tree->SetBranchAddress("tau_0_ele_bdt_score_trans", &tau_0_ele_bdt_score_trans, &b_tau_0_ele_bdt_score_trans);
  tree->SetBranchAddress("tau_0_ele_bdt_score_trans_retuned", &tau_0_ele_bdt_score_trans_retuned, &b_tau_0_ele_bdt_score_trans_retuned);
  tree->SetBranchAddress("tau_0_ele_bdt_tight_retuned", &tau_0_ele_bdt_tight_retuned, &b_tau_0_ele_bdt_tight_retuned);
  tree->SetBranchAddress("tau_0_ele_match_lhscore", &tau_0_ele_match_lhscore, &b_tau_0_ele_match_lhscore);
  tree->SetBranchAddress("tau_0_ele_olr_pass", &tau_0_ele_olr_pass, &b_tau_0_ele_olr_pass);
  tree->SetBranchAddress("tau_0_jet_bdt_loose", &tau_0_jet_bdt_loose, &b_tau_0_jet_bdt_loose);
  tree->SetBranchAddress("tau_0_jet_bdt_medium", &tau_0_jet_bdt_medium, &b_tau_0_jet_bdt_medium);
  tree->SetBranchAddress("tau_0_jet_bdt_score_trans", &tau_0_jet_bdt_score_trans, &b_tau_0_jet_bdt_score_trans);
  tree->SetBranchAddress("tau_0_jet_bdt_tight", &tau_0_jet_bdt_tight, &b_tau_0_jet_bdt_tight);
  tree->SetBranchAddress("tau_0_jet_bdt_veryloose", &tau_0_jet_bdt_veryloose, &b_tau_0_jet_bdt_veryloose);
  tree->SetBranchAddress("tau_0_jet_jvt", &tau_0_jet_jvt, &b_tau_0_jet_jvt);
  tree->SetBranchAddress("tau_0_jet_rnn_loose", &tau_0_jet_rnn_loose, &b_tau_0_jet_rnn_loose);
  tree->SetBranchAddress("tau_0_jet_rnn_medium", &tau_0_jet_rnn_medium, &b_tau_0_jet_rnn_medium);
  tree->SetBranchAddress("tau_0_jet_rnn_score", &tau_0_jet_rnn_score, &b_tau_0_jet_rnn_score);
  tree->SetBranchAddress("tau_0_jet_rnn_score_trans", &tau_0_jet_rnn_score_trans, &b_tau_0_jet_rnn_score_trans);
  tree->SetBranchAddress("tau_0_jet_rnn_tight", &tau_0_jet_rnn_tight, &b_tau_0_jet_rnn_tight);
  tree->SetBranchAddress("tau_0_jet_rnn_veryloose", &tau_0_jet_rnn_veryloose, &b_tau_0_jet_rnn_veryloose);
  tree->SetBranchAddress("tau_0_jet_width", &tau_0_jet_width, &b_tau_0_jet_width);
  tree->SetBranchAddress("tau_0_leadTrk_eta", &tau_0_leadTrk_eta, &b_tau_0_leadTrk_eta);
  tree->SetBranchAddress("tau_0_leadTrk_phi", &tau_0_leadTrk_phi, &b_tau_0_leadTrk_phi);
  tree->SetBranchAddress("tau_0_leadTrk_pt", &tau_0_leadTrk_pt, &b_tau_0_leadTrk_pt);
  tree->SetBranchAddress("tau_0_n_all_tracks", &tau_0_n_all_tracks, &b_tau_0_n_all_tracks);
  tree->SetBranchAddress("tau_0_n_charged_tracks", &tau_0_n_charged_tracks, &b_tau_0_n_charged_tracks);
  tree->SetBranchAddress("tau_0_n_conversion_tracks", &tau_0_n_conversion_tracks, &b_tau_0_n_conversion_tracks);
  tree->SetBranchAddress("tau_0_n_core_tracks", &tau_0_n_core_tracks, &b_tau_0_n_core_tracks);
  tree->SetBranchAddress("tau_0_n_failTrackFilter_tracks", &tau_0_n_failTrackFilter_tracks, &b_tau_0_n_failTrackFilter_tracks);
  tree->SetBranchAddress("tau_0_n_fake_tracks", &tau_0_n_fake_tracks, &b_tau_0_n_fake_tracks);
  tree->SetBranchAddress("tau_0_n_isolation_tracks", &tau_0_n_isolation_tracks, &b_tau_0_n_isolation_tracks);
  tree->SetBranchAddress("tau_0_n_modified_isolation_tracks", &tau_0_n_modified_isolation_tracks, &b_tau_0_n_modified_isolation_tracks);
  tree->SetBranchAddress("tau_0_n_old_tracks", &tau_0_n_old_tracks, &b_tau_0_n_old_tracks);
  tree->SetBranchAddress("tau_0_n_passTrkSelectionTight_tracks", &tau_0_n_passTrkSelectionTight_tracks, &b_tau_0_n_passTrkSelectionTight_tracks);
  tree->SetBranchAddress("tau_0_n_passTrkSelector_tracks", &tau_0_n_passTrkSelector_tracks, &b_tau_0_n_passTrkSelector_tracks);
  tree->SetBranchAddress("tau_0_n_unclassified_tracks", &tau_0_n_unclassified_tracks, &b_tau_0_n_unclassified_tracks);
  tree->SetBranchAddress("tau_0_n_wide_tracks", &tau_0_n_wide_tracks, &b_tau_0_n_wide_tracks);
  tree->SetBranchAddress("tau_0_origin", &tau_0_origin, &b_tau_0_origin);
  tree->SetBranchAddress("tau_0_p4", &tau_0_p4, &b_tau_0_p4);
  tree->SetBranchAddress("tau_0_q", &tau_0_q, &b_tau_0_q);
  tree->SetBranchAddress("tau_0_track0_p4", &tau_0_track0_p4, &b_tau_0_track0_p4);
  tree->SetBranchAddress("tau_0_track1_p4", &tau_0_track1_p4, &b_tau_0_track1_p4);
  tree->SetBranchAddress("tau_0_track2_p4", &tau_0_track2_p4, &b_tau_0_track2_p4);
  tree->SetBranchAddress("tau_0_trig_HLT_tau25_medium1_tracktwo", &tau_0_trig_HLT_tau25_medium1_tracktwo, &b_tau_0_trig_HLT_tau25_medium1_tracktwo);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo", &tau_0_trig_HLT_tau35_medium1_tracktwo, &b_tau_0_trig_HLT_tau35_medium1_tracktwo);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25);
  tree->SetBranchAddress("tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM", &tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM, &b_tau_0_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM);
  tree->SetBranchAddress("tau_0_trig_trigger_matched", &tau_0_trig_trigger_matched, &b_tau_0_trig_trigger_matched);
  tree->SetBranchAddress("tau_0_type", &tau_0_type, &b_tau_0_type);
  tree->SetBranchAddress("tau_1", &tau_1, &b_tau_1);
  tree->SetBranchAddress("tau_1_allTrk_eta", &tau_1_allTrk_eta, &b_tau_1_allTrk_eta);
  tree->SetBranchAddress("tau_1_allTrk_n", &tau_1_allTrk_n, &b_tau_1_allTrk_n);
  tree->SetBranchAddress("tau_1_allTrk_phi", &tau_1_allTrk_phi, &b_tau_1_allTrk_phi);
  tree->SetBranchAddress("tau_1_allTrk_pt", &tau_1_allTrk_pt, &b_tau_1_allTrk_pt);
  tree->SetBranchAddress("tau_1_b_tagged", &tau_1_b_tagged, &b_tau_1_b_tagged);
  tree->SetBranchAddress("tau_1_decay_mode", &tau_1_decay_mode, &b_tau_1_decay_mode);
  tree->SetBranchAddress("tau_1_ele_bdt_eff_sf", &tau_1_ele_bdt_eff_sf, &b_tau_1_ele_bdt_eff_sf);
  tree->SetBranchAddress("tau_1_ele_bdt_loose_retuned", &tau_1_ele_bdt_loose_retuned, &b_tau_1_ele_bdt_loose_retuned);
  tree->SetBranchAddress("tau_1_ele_bdt_medium_retuned", &tau_1_ele_bdt_medium_retuned, &b_tau_1_ele_bdt_medium_retuned);
  tree->SetBranchAddress("tau_1_ele_bdt_score", &tau_1_ele_bdt_score, &b_tau_1_ele_bdt_score);
  tree->SetBranchAddress("tau_1_ele_bdt_score_retuned", &tau_1_ele_bdt_score_retuned, &b_tau_1_ele_bdt_score_retuned);
  tree->SetBranchAddress("tau_1_ele_bdt_score_trans", &tau_1_ele_bdt_score_trans, &b_tau_1_ele_bdt_score_trans);
  tree->SetBranchAddress("tau_1_ele_bdt_score_trans_retuned", &tau_1_ele_bdt_score_trans_retuned, &b_tau_1_ele_bdt_score_trans_retuned);
  tree->SetBranchAddress("tau_1_ele_bdt_tight_retuned", &tau_1_ele_bdt_tight_retuned, &b_tau_1_ele_bdt_tight_retuned);
  tree->SetBranchAddress("tau_1_ele_match_lhscore", &tau_1_ele_match_lhscore, &b_tau_1_ele_match_lhscore);
  tree->SetBranchAddress("tau_1_ele_olr_pass", &tau_1_ele_olr_pass, &b_tau_1_ele_olr_pass);
  tree->SetBranchAddress("tau_1_jet_bdt_loose", &tau_1_jet_bdt_loose, &b_tau_1_jet_bdt_loose);
  tree->SetBranchAddress("tau_1_jet_bdt_medium", &tau_1_jet_bdt_medium, &b_tau_1_jet_bdt_medium);
  tree->SetBranchAddress("tau_1_jet_bdt_score_trans", &tau_1_jet_bdt_score_trans, &b_tau_1_jet_bdt_score_trans);
  tree->SetBranchAddress("tau_1_jet_bdt_tight", &tau_1_jet_bdt_tight, &b_tau_1_jet_bdt_tight);
  tree->SetBranchAddress("tau_1_jet_bdt_veryloose", &tau_1_jet_bdt_veryloose, &b_tau_1_jet_bdt_veryloose);
  tree->SetBranchAddress("tau_1_jet_jvt", &tau_1_jet_jvt, &b_tau_1_jet_jvt);
  tree->SetBranchAddress("tau_1_jet_rnn_loose", &tau_1_jet_rnn_loose, &b_tau_1_jet_rnn_loose);
  tree->SetBranchAddress("tau_1_jet_rnn_medium", &tau_1_jet_rnn_medium, &b_tau_1_jet_rnn_medium);
  tree->SetBranchAddress("tau_1_jet_rnn_score", &tau_1_jet_rnn_score, &b_tau_1_jet_rnn_score);
  tree->SetBranchAddress("tau_1_jet_rnn_score_trans", &tau_1_jet_rnn_score_trans, &b_tau_1_jet_rnn_score_trans);
  tree->SetBranchAddress("tau_1_jet_rnn_tight", &tau_1_jet_rnn_tight, &b_tau_1_jet_rnn_tight);
  tree->SetBranchAddress("tau_1_jet_rnn_veryloose", &tau_1_jet_rnn_veryloose, &b_tau_1_jet_rnn_veryloose);
  tree->SetBranchAddress("tau_1_jet_width", &tau_1_jet_width, &b_tau_1_jet_width);
  tree->SetBranchAddress("tau_1_leadTrk_eta", &tau_1_leadTrk_eta, &b_tau_1_leadTrk_eta);
  tree->SetBranchAddress("tau_1_leadTrk_phi", &tau_1_leadTrk_phi, &b_tau_1_leadTrk_phi);
  tree->SetBranchAddress("tau_1_leadTrk_pt", &tau_1_leadTrk_pt, &b_tau_1_leadTrk_pt);
  tree->SetBranchAddress("tau_1_n_all_tracks", &tau_1_n_all_tracks, &b_tau_1_n_all_tracks);
  tree->SetBranchAddress("tau_1_n_charged_tracks", &tau_1_n_charged_tracks, &b_tau_1_n_charged_tracks);
  tree->SetBranchAddress("tau_1_n_conversion_tracks", &tau_1_n_conversion_tracks, &b_tau_1_n_conversion_tracks);
  tree->SetBranchAddress("tau_1_n_core_tracks", &tau_1_n_core_tracks, &b_tau_1_n_core_tracks);
  tree->SetBranchAddress("tau_1_n_failTrackFilter_tracks", &tau_1_n_failTrackFilter_tracks, &b_tau_1_n_failTrackFilter_tracks);
  tree->SetBranchAddress("tau_1_n_fake_tracks", &tau_1_n_fake_tracks, &b_tau_1_n_fake_tracks);
  tree->SetBranchAddress("tau_1_n_isolation_tracks", &tau_1_n_isolation_tracks, &b_tau_1_n_isolation_tracks);
  tree->SetBranchAddress("tau_1_n_modified_isolation_tracks", &tau_1_n_modified_isolation_tracks, &b_tau_1_n_modified_isolation_tracks);
  tree->SetBranchAddress("tau_1_n_old_tracks", &tau_1_n_old_tracks, &b_tau_1_n_old_tracks);
  tree->SetBranchAddress("tau_1_n_passTrkSelectionTight_tracks", &tau_1_n_passTrkSelectionTight_tracks, &b_tau_1_n_passTrkSelectionTight_tracks);
  tree->SetBranchAddress("tau_1_n_passTrkSelector_tracks", &tau_1_n_passTrkSelector_tracks, &b_tau_1_n_passTrkSelector_tracks);
  tree->SetBranchAddress("tau_1_n_unclassified_tracks", &tau_1_n_unclassified_tracks, &b_tau_1_n_unclassified_tracks);
  tree->SetBranchAddress("tau_1_n_wide_tracks", &tau_1_n_wide_tracks, &b_tau_1_n_wide_tracks);
  tree->SetBranchAddress("tau_1_origin", &tau_1_origin, &b_tau_1_origin);
  tree->SetBranchAddress("tau_1_p4", &tau_1_p4, &b_tau_1_p4);
  tree->SetBranchAddress("tau_1_q", &tau_1_q, &b_tau_1_q);
  tree->SetBranchAddress("tau_1_track0_p4", &tau_1_track0_p4, &b_tau_1_track0_p4);
  tree->SetBranchAddress("tau_1_track1_p4", &tau_1_track1_p4, &b_tau_1_track1_p4);
  tree->SetBranchAddress("tau_1_track2_p4", &tau_1_track2_p4, &b_tau_1_track2_p4);
  tree->SetBranchAddress("tau_1_trig_HLT_tau25_medium1_tracktwo", &tau_1_trig_HLT_tau25_medium1_tracktwo, &b_tau_1_trig_HLT_tau25_medium1_tracktwo);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo", &tau_1_trig_HLT_tau35_medium1_tracktwo, &b_tau_1_trig_HLT_tau35_medium1_tracktwo);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_03dR30_L1DR_TAU20ITAU12I_J25);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1DR_TAU20ITAU12I_J25);
  tree->SetBranchAddress("tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM", &tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM, &b_tau_1_trig_HLT_tau35_medium1_tracktwo_tau25_medium1_tracktwo_L1TAU20IM_2TAU12IM);
  tree->SetBranchAddress("tau_1_trig_trigger_matched", &tau_1_trig_trigger_matched, &b_tau_1_trig_trigger_matched);
  tree->SetBranchAddress("tau_1_type", &tau_1_type, &b_tau_1_type);

  if(!isData){
    tree->SetBranchAddress("NOMINAL_pileup_random_lb_number", &NOMINAL_pileup_random_lb_number, &b_NOMINAL_pileup_random_lb_number);
    tree->SetBranchAddress("NOMINAL_pileup_random_run_number", &NOMINAL_pileup_random_run_number, &b_NOMINAL_pileup_random_run_number);
    tree->SetBranchAddress("jet_3_wztruth_p4", &jet_3_wztruth_p4, &b_jet_3_wztruth_p4);
    tree->SetBranchAddress("jet_3_wztruth_pdgid", &jet_3_wztruth_pdgid, &b_jet_3_wztruth_pdgid);
    tree->SetBranchAddress("jet_4_wztruth_p4", &jet_4_wztruth_p4, &b_jet_4_wztruth_p4);
    tree->SetBranchAddress("jet_4_wztruth_pdgid", &jet_4_wztruth_pdgid, &b_jet_4_wztruth_pdgid);
    tree->SetBranchAddress("jet_5_wztruth_p4", &jet_5_wztruth_p4, &b_jet_5_wztruth_p4);
    tree->SetBranchAddress("jet_5_wztruth_pdgid", &jet_5_wztruth_pdgid, &b_jet_5_wztruth_pdgid);
    tree->SetBranchAddress("jet_6_wztruth_p4", &jet_6_wztruth_p4, &b_jet_6_wztruth_p4);
    tree->SetBranchAddress("jet_6_wztruth_pdgid", &jet_6_wztruth_pdgid, &b_jet_6_wztruth_pdgid);
    tree->SetBranchAddress("n_truth_gluon_jets", &n_truth_gluon_jets, &b_n_truth_gluon_jets);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad", &tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad, &b_tau_0_NOMINAL_TauEffSF_HadTauEleOLR_tauhad);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_JetBDTloose", &tau_0_NOMINAL_TauEffSF_JetBDTloose, &b_tau_0_NOMINAL_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_JetBDTmedium", &tau_0_NOMINAL_TauEffSF_JetBDTmedium, &b_tau_0_NOMINAL_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_JetBDTtight", &tau_0_NOMINAL_TauEffSF_JetBDTtight, &b_tau_0_NOMINAL_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_reco", &tau_0_NOMINAL_TauEffSF_reco, &b_tau_0_NOMINAL_TauEffSF_reco);
    tree->SetBranchAddress("tau_0_NOMINAL_TauEffSF_selection", &tau_0_NOMINAL_TauEffSF_selection, &b_tau_0_NOMINAL_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection", &tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight", &tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight, &b_tau_0_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection", &tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection, &b_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_0_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_0_matched", &tau_0_matched, &b_tau_0_matched);
    tree->SetBranchAddress("tau_0_matched_classifierParticleOrigin", &tau_0_matched_classifierParticleOrigin, &b_tau_0_matched_classifierParticleOrigin);
    tree->SetBranchAddress("tau_0_matched_classifierParticleType", &tau_0_matched_classifierParticleType, &b_tau_0_matched_classifierParticleType);
    tree->SetBranchAddress("tau_0_matched_decay_charged_p4", &tau_0_matched_decay_charged_p4, &b_tau_0_matched_decay_charged_p4);
    tree->SetBranchAddress("tau_0_matched_decay_mode", &tau_0_matched_decay_mode, &b_tau_0_matched_decay_mode);
    tree->SetBranchAddress("tau_0_matched_decay_neutral_p4", &tau_0_matched_decay_neutral_p4, &b_tau_0_matched_decay_neutral_p4);
    tree->SetBranchAddress("tau_0_matched_decay_neutrino_p4", &tau_0_matched_decay_neutrino_p4, &b_tau_0_matched_decay_neutrino_p4);
    tree->SetBranchAddress("tau_0_matched_isEle", &tau_0_matched_isEle, &b_tau_0_matched_isEle);
    tree->SetBranchAddress("tau_0_matched_isHadTau", &tau_0_matched_isHadTau, &b_tau_0_matched_isHadTau);
    tree->SetBranchAddress("tau_0_matched_isJet", &tau_0_matched_isJet, &b_tau_0_matched_isJet);
    tree->SetBranchAddress("tau_0_matched_isMuon", &tau_0_matched_isMuon, &b_tau_0_matched_isMuon);
    tree->SetBranchAddress("tau_0_matched_isTau", &tau_0_matched_isTau, &b_tau_0_matched_isTau);
    tree->SetBranchAddress("tau_0_matched_isTruthMatch", &tau_0_matched_isTruthMatch, &b_tau_0_matched_isTruthMatch);
    tree->SetBranchAddress("tau_0_matched_mother_pdgId", &tau_0_matched_mother_pdgId, &b_tau_0_matched_mother_pdgId);
    tree->SetBranchAddress("tau_0_matched_mother_status", &tau_0_matched_mother_status, &b_tau_0_matched_mother_status);
    tree->SetBranchAddress("tau_0_matched_n_charged", &tau_0_matched_n_charged, &b_tau_0_matched_n_charged);
    tree->SetBranchAddress("tau_0_matched_n_charged_pion", &tau_0_matched_n_charged_pion, &b_tau_0_matched_n_charged_pion);
    tree->SetBranchAddress("tau_0_matched_n_neutral", &tau_0_matched_n_neutral, &b_tau_0_matched_n_neutral);
    tree->SetBranchAddress("tau_0_matched_n_neutral_pion", &tau_0_matched_n_neutral_pion, &b_tau_0_matched_n_neutral_pion);
    tree->SetBranchAddress("tau_0_matched_p4", &tau_0_matched_p4, &b_tau_0_matched_p4);
    tree->SetBranchAddress("tau_0_matched_p4_vis_charged_track0", &tau_0_matched_p4_vis_charged_track0, &b_tau_0_matched_p4_vis_charged_track0);
    tree->SetBranchAddress("tau_0_matched_p4_vis_charged_track1", &tau_0_matched_p4_vis_charged_track1, &b_tau_0_matched_p4_vis_charged_track1);
    tree->SetBranchAddress("tau_0_matched_p4_vis_charged_track2", &tau_0_matched_p4_vis_charged_track2, &b_tau_0_matched_p4_vis_charged_track2);
    tree->SetBranchAddress("tau_0_matched_pdgId", &tau_0_matched_pdgId, &b_tau_0_matched_pdgId);
    tree->SetBranchAddress("tau_0_matched_q", &tau_0_matched_q, &b_tau_0_matched_q);
    tree->SetBranchAddress("tau_0_matched_status", &tau_0_matched_status, &b_tau_0_matched_status);
    tree->SetBranchAddress("tau_0_matched_type", &tau_0_matched_type, &b_tau_0_matched_type);
    tree->SetBranchAddress("tau_0_matched_vis_charged_p4", &tau_0_matched_vis_charged_p4, &b_tau_0_matched_vis_charged_p4);
    tree->SetBranchAddress("tau_0_matched_vis_neutral_others_p4", &tau_0_matched_vis_neutral_others_p4, &b_tau_0_matched_vis_neutral_others_p4);
    tree->SetBranchAddress("tau_0_matched_vis_neutral_p4", &tau_0_matched_vis_neutral_p4, &b_tau_0_matched_vis_neutral_p4);
    tree->SetBranchAddress("tau_0_matched_vis_neutral_pions_p4", &tau_0_matched_vis_neutral_pions_p4, &b_tau_0_matched_vis_neutral_pions_p4);
    tree->SetBranchAddress("tau_0_matched_vis_p4", &tau_0_matched_vis_p4, &b_tau_0_matched_vis_p4);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_NOMINAL_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_NOMINAL_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad", &tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad, &b_tau_1_NOMINAL_TauEffSF_HadTauEleOLR_tauhad);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_JetBDTloose", &tau_1_NOMINAL_TauEffSF_JetBDTloose, &b_tau_1_NOMINAL_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_JetBDTmedium", &tau_1_NOMINAL_TauEffSF_JetBDTmedium, &b_tau_1_NOMINAL_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_JetBDTtight", &tau_1_NOMINAL_TauEffSF_JetBDTtight, &b_tau_1_NOMINAL_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_NOMINAL_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_reco", &tau_1_NOMINAL_TauEffSF_reco, &b_tau_1_NOMINAL_TauEffSF_reco);
    tree->SetBranchAddress("tau_1_NOMINAL_TauEffSF_selection", &tau_1_NOMINAL_TauEffSF_selection, &b_tau_1_NOMINAL_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATHIGHMU_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_STATLOWMU_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_VeryLooseLlhEleOLR_electron);
    tree->SetBranchAddress("tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection", &tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEELECTRON_EFF_ELEOLR_SYST_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_HadTauEleOLR_tauhad);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_HadTauEleOLR_tauhad);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2025_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR2530_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORR3040_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_1PRONGSTATSYSTUNCORRGE40_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORR2030_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_3PRONGSTATSYSTUNCORRGE30_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_HIGHPT_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1down_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTloose);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTmedium);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight", &tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight, &b_tau_1_TAUS_TRUEHADTAU_EFF_JETID_SYST_1up_TauEffSF_JetBDTtight);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_reco);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_reco);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_HIGHPT_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection", &tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection, &b_tau_1_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATDATA2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_STATMC2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2015_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2016_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1down_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau25_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTLOOSE);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTMEDIUM);
    tree->SetBranchAddress("tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT", &tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT, &b_tau_1_TAUS_TRUEHADTAU_EFF_TRIGGER_SYST2017_1up_TauEffSF_HLT_tau35_medium1_tracktwo_JETIDBDTTIGHT);
    tree->SetBranchAddress("tau_1_matched", &tau_1_matched, &b_tau_1_matched);
    tree->SetBranchAddress("tau_1_matched_classifierParticleOrigin", &tau_1_matched_classifierParticleOrigin, &b_tau_1_matched_classifierParticleOrigin);
    tree->SetBranchAddress("tau_1_matched_classifierParticleType", &tau_1_matched_classifierParticleType, &b_tau_1_matched_classifierParticleType);
    tree->SetBranchAddress("tau_1_matched_decay_charged_p4", &tau_1_matched_decay_charged_p4, &b_tau_1_matched_decay_charged_p4);
    tree->SetBranchAddress("tau_1_matched_decay_mode", &tau_1_matched_decay_mode, &b_tau_1_matched_decay_mode);
    tree->SetBranchAddress("tau_1_matched_decay_neutral_p4", &tau_1_matched_decay_neutral_p4, &b_tau_1_matched_decay_neutral_p4);
    tree->SetBranchAddress("tau_1_matched_decay_neutrino_p4", &tau_1_matched_decay_neutrino_p4, &b_tau_1_matched_decay_neutrino_p4);
    tree->SetBranchAddress("tau_1_matched_isEle", &tau_1_matched_isEle, &b_tau_1_matched_isEle);
    tree->SetBranchAddress("tau_1_matched_isHadTau", &tau_1_matched_isHadTau, &b_tau_1_matched_isHadTau);
    tree->SetBranchAddress("tau_1_matched_isJet", &tau_1_matched_isJet, &b_tau_1_matched_isJet);
    tree->SetBranchAddress("tau_1_matched_isMuon", &tau_1_matched_isMuon, &b_tau_1_matched_isMuon);
    tree->SetBranchAddress("tau_1_matched_isTau", &tau_1_matched_isTau, &b_tau_1_matched_isTau);
    tree->SetBranchAddress("tau_1_matched_isTruthMatch", &tau_1_matched_isTruthMatch, &b_tau_1_matched_isTruthMatch);
    tree->SetBranchAddress("tau_1_matched_mother_pdgId", &tau_1_matched_mother_pdgId, &b_tau_1_matched_mother_pdgId);
    tree->SetBranchAddress("tau_1_matched_mother_status", &tau_1_matched_mother_status, &b_tau_1_matched_mother_status);
    tree->SetBranchAddress("tau_1_matched_n_charged", &tau_1_matched_n_charged, &b_tau_1_matched_n_charged);
    tree->SetBranchAddress("tau_1_matched_n_charged_pion", &tau_1_matched_n_charged_pion, &b_tau_1_matched_n_charged_pion);
    tree->SetBranchAddress("tau_1_matched_n_neutral", &tau_1_matched_n_neutral, &b_tau_1_matched_n_neutral);
    tree->SetBranchAddress("tau_1_matched_n_neutral_pion", &tau_1_matched_n_neutral_pion, &b_tau_1_matched_n_neutral_pion);
    tree->SetBranchAddress("tau_1_matched_p4", &tau_1_matched_p4, &b_tau_1_matched_p4);
    tree->SetBranchAddress("tau_1_matched_p4_vis_charged_track0", &tau_1_matched_p4_vis_charged_track0, &b_tau_1_matched_p4_vis_charged_track0);
    tree->SetBranchAddress("tau_1_matched_p4_vis_charged_track1", &tau_1_matched_p4_vis_charged_track1, &b_tau_1_matched_p4_vis_charged_track1);
    tree->SetBranchAddress("tau_1_matched_p4_vis_charged_track2", &tau_1_matched_p4_vis_charged_track2, &b_tau_1_matched_p4_vis_charged_track2);
    tree->SetBranchAddress("tau_1_matched_pdgId", &tau_1_matched_pdgId, &b_tau_1_matched_pdgId);
    tree->SetBranchAddress("tau_1_matched_pz", &tau_1_matched_pz, &b_tau_1_matched_pz);
    tree->SetBranchAddress("tau_1_matched_q", &tau_1_matched_q, &b_tau_1_matched_q);
    tree->SetBranchAddress("tau_1_matched_status", &tau_1_matched_status, &b_tau_1_matched_status);
    tree->SetBranchAddress("tau_1_matched_vis_charged_p4", &tau_1_matched_vis_charged_p4, &b_tau_1_matched_vis_charged_p4);
    tree->SetBranchAddress("tau_1_matched_vis_neutral_others_p4", &tau_1_matched_vis_neutral_others_p4, &b_tau_1_matched_vis_neutral_others_p4);
    tree->SetBranchAddress("tau_1_matched_vis_neutral_p4", &tau_1_matched_vis_neutral_p4, &b_tau_1_matched_vis_neutral_p4);
    tree->SetBranchAddress("tau_1_matched_vis_neutral_pions_p4", &tau_1_matched_vis_neutral_pions_p4, &b_tau_1_matched_vis_neutral_pions_p4);
    tree->SetBranchAddress("tau_1_matched_vis_p4", &tau_1_matched_vis_p4, &b_tau_1_matched_vis_p4);
    tree->SetBranchAddress("tau_eta_centrality", &tau_eta_centrality, &b_tau_eta_centrality);   
    tree->SetBranchAddress("HTXS_Njets_pTjet25", &HTXS_Njets_pTjet25, &b_HTXS_Njets_pTjet25);
    tree->SetBranchAddress("HTXS_Njets_pTjet30", &HTXS_Njets_pTjet30, &b_HTXS_Njets_pTjet30);
    tree->SetBranchAddress("HTXS_Stage0_Category", &HTXS_Stage0_Category, &b_HTXS_Stage0_Category);
    tree->SetBranchAddress("HTXS_Stage1_Category_pTjet25GeV", &HTXS_Stage1_Category_pTjet25GeV, &b_HTXS_Stage1_Category_pTjet25GeV);
    tree->SetBranchAddress("HTXS_Stage1_Category_pTjet30GeV", &HTXS_Stage1_Category_pTjet30GeV, &b_HTXS_Stage1_Category_pTjet30GeV);
    tree->SetBranchAddress("HTXS_errorMode", &HTXS_errorMode, &b_HTXS_errorMode);
    tree->SetBranchAddress("HTXS_prodMode", &HTXS_prodMode, &b_HTXS_prodMode);
    tree->SetBranchAddress("NOMINAL_pileup_combined_weight", &NOMINAL_pileup_combined_weight, &b_NOMINAL_pileup_combined_weight);
    tree->SetBranchAddress("PRW_DATASF_1down_pileup_combined_weight", &PRW_DATASF_1down_pileup_combined_weight, &b_PRW_DATASF_1down_pileup_combined_weight);
    tree->SetBranchAddress("PRW_DATASF_1up_pileup_combined_weight", &PRW_DATASF_1up_pileup_combined_weight, &b_PRW_DATASF_1up_pileup_combined_weight);
    tree->SetBranchAddress("boson_0_truth_p4", &boson_0_truth_p4, &b_boson_0_truth_p4);
    tree->SetBranchAddress("boson_0_truth_pdgId", &boson_0_truth_pdgId, &b_boson_0_truth_pdgId);
    tree->SetBranchAddress("boson_0_truth_q", &boson_0_truth_q, &b_boson_0_truth_q);
    tree->SetBranchAddress("boson_0_truth_status", &boson_0_truth_status, &b_boson_0_truth_status);
    tree->SetBranchAddress("ditau_matched", &ditau_matched, &b_ditau_matched);
    tree->SetBranchAddress("ditau_matched_cosalpha", &ditau_matched_cosalpha, &b_ditau_matched_cosalpha);
    tree->SetBranchAddress("ditau_matched_deta", &ditau_matched_deta, &b_ditau_matched_deta);
    tree->SetBranchAddress("ditau_matched_dphi", &ditau_matched_dphi, &b_ditau_matched_dphi);
    tree->SetBranchAddress("ditau_matched_dr", &ditau_matched_dr, &b_ditau_matched_dr);
    tree->SetBranchAddress("ditau_matched_p4", &ditau_matched_p4, &b_ditau_matched_p4);
    tree->SetBranchAddress("ditau_matched_qxq", &ditau_matched_qxq, &b_ditau_matched_qxq);
    tree->SetBranchAddress("ditau_matched_scal_sum_pt", &ditau_matched_scal_sum_pt, &b_ditau_matched_scal_sum_pt);
    tree->SetBranchAddress("ditau_matched_vis_cosalpha", &ditau_matched_vis_cosalpha, &b_ditau_matched_vis_cosalpha);
    tree->SetBranchAddress("ditau_matched_vis_deta", &ditau_matched_vis_deta, &b_ditau_matched_vis_deta);
    tree->SetBranchAddress("ditau_matched_vis_dphi", &ditau_matched_vis_dphi, &b_ditau_matched_vis_dphi);
    tree->SetBranchAddress("ditau_matched_vis_dr", &ditau_matched_vis_dr, &b_ditau_matched_vis_dr);
    tree->SetBranchAddress("ditau_matched_vis_mass", &ditau_matched_vis_mass, &b_ditau_matched_vis_mass);
    tree->SetBranchAddress("ditau_matched_vis_scal_sum_pt", &ditau_matched_vis_scal_sum_pt, &b_ditau_matched_vis_scal_sum_pt);
    tree->SetBranchAddress("ditau_matched_vis_vect_sum_pt", &ditau_matched_vis_vect_sum_pt, &b_ditau_matched_vis_vect_sum_pt);
    tree->SetBranchAddress("jet_0_wztruth_p4", &jet_0_wztruth_p4, &b_jet_0_wztruth_p4);
    tree->SetBranchAddress("jet_0_wztruth_pdgid", &jet_0_wztruth_pdgid, &b_jet_0_wztruth_pdgid);
    tree->SetBranchAddress("jet_1_wztruth_p4", &jet_1_wztruth_p4, &b_jet_1_wztruth_p4);
    tree->SetBranchAddress("jet_1_wztruth_pdgid", &jet_1_wztruth_pdgid, &b_jet_1_wztruth_pdgid);
    tree->SetBranchAddress("jet_2_wztruth_p4", &jet_2_wztruth_p4, &b_jet_2_wztruth_p4);
    tree->SetBranchAddress("jet_2_wztruth_pdgid", &jet_2_wztruth_pdgid, &b_jet_2_wztruth_pdgid);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_3_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_4_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_5_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_6_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_7_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_B_8_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10", &jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_Eigen_Light_4_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10", &jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10, &b_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10);
    tree->SetBranchAddress("jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT", &jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT, &b_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT);
    tree->SetBranchAddress("jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT", &jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT, &b_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT);
    tree->SetBranchAddress("jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT", &jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT, &b_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT);
    tree->SetBranchAddress("jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT", &jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT, &b_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT);
    tree->SetBranchAddress("jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT", &jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT, &b_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT);
    tree->SetBranchAddress("jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT", &jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT, &b_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT);
    tree->SetBranchAddress("jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT", &jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT, &b_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT);
    tree->SetBranchAddress("jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT", &jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT, &b_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT);
    tree->SetBranchAddress("jet_NOMINAL_central_jets_global_effSF_JVT", &jet_NOMINAL_central_jets_global_effSF_JVT, &b_jet_NOMINAL_central_jets_global_effSF_JVT);
    tree->SetBranchAddress("jet_NOMINAL_central_jets_global_ineffSF_JVT", &jet_NOMINAL_central_jets_global_ineffSF_JVT, &b_jet_NOMINAL_central_jets_global_ineffSF_JVT);
    tree->SetBranchAddress("jet_NOMINAL_forward_jets_global_effSF_JVT", &jet_NOMINAL_forward_jets_global_effSF_JVT, &b_jet_NOMINAL_forward_jets_global_effSF_JVT);
    tree->SetBranchAddress("jet_NOMINAL_forward_jets_global_ineffSF_JVT", &jet_NOMINAL_forward_jets_global_ineffSF_JVT, &b_jet_NOMINAL_forward_jets_global_ineffSF_JVT);
    tree->SetBranchAddress("jet_NOMINAL_global_effSF_MV2c10", &jet_NOMINAL_global_effSF_MV2c10, &b_jet_NOMINAL_global_effSF_MV2c10);
    tree->SetBranchAddress("jet_NOMINAL_global_ineffSF_MV2c10", &jet_NOMINAL_global_ineffSF_MV2c10, &b_jet_NOMINAL_global_ineffSF_MV2c10);
    tree->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
    tree->SetBranchAddress("n_truth_jets", &n_truth_jets, &b_n_truth_jets);
    tree->SetBranchAddress("n_truth_jets_pt20_eta45", &n_truth_jets_pt20_eta45, &b_n_truth_jets_pt20_eta45);
    tree->SetBranchAddress("n_truth_quark_jets", &n_truth_quark_jets, &b_n_truth_quark_jets);
    tree->SetBranchAddress("theory_weights_CT14_pdfset", &theory_weights_CT14_pdfset, &b_theory_weights_CT14_pdfset);
    tree->SetBranchAddress("theory_weights_MMHT_pdfset", &theory_weights_MMHT_pdfset, &b_theory_weights_MMHT_pdfset);
    tree->SetBranchAddress("theory_weights_PDF_central_value", &theory_weights_PDF_central_value, &b_theory_weights_PDF_central_value);
    tree->SetBranchAddress("theory_weights_PDF_error_down", &theory_weights_PDF_error_down, &b_theory_weights_PDF_error_down);
    tree->SetBranchAddress("theory_weights_PDF_error_up", &theory_weights_PDF_error_up, &b_theory_weights_PDF_error_up);
    tree->SetBranchAddress("theory_weights_alphaS_down", &theory_weights_alphaS_down, &b_theory_weights_alphaS_down);
    tree->SetBranchAddress("theory_weights_alphaS_up", &theory_weights_alphaS_up, &b_theory_weights_alphaS_up);
    tree->SetBranchAddress("truth_passedVBFFilter", &truth_passedVBFFilter, &b_truth_passedVBFFilter);
    tree->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
  }
}
