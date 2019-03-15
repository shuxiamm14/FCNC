#include "nominal.h"

void nominal::fill_fake(TString region, int nprong, TString sample, int iptbin, float taubtag){
  for (int i = 0; i < 4; ++i){
    if(taubtag>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[i]).Data(), sample.Data());
      if(doseppt) fake_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[i]);
      fake_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + bwps[i]);
    }else{
      if(doseppt) fake_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[i]);
      fake_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + "veto" + bwps[i]);
    }
  }
}
nominal::nominal(){
  TLorentzVector v1;
  for(int i = 0 ; i < 2 ; ++i){
    taus_v.push_back(v1);
  }
  forFit.Add(&(taus_v[0]));
  forFit.Add(&(taus_v[1]));
  forFit.Add(&bjet_v);
  forFit.Add(&cjet_v);
  forFit.Add(&lep_v);
  forFit.Add(&mets);

  neutrino_pt  = new vector<float>();
  neutrino_eta = new vector<float>();
  neutrino_phi = new vector<float>();
  neutrino_m   = new vector<float>();
}

void nominal::readTFmeanstd(TString filename){
  m_applyTF.configfolder = "/Users/Liby/work/tau_analysis/FCNC/ttH_fakes/run/MLmodels";
  m_applyTF.readmeanfile(filename);
}

void nominal::init_hist(){
  //init histSaver here:
  dohist = 1;
  fcnc_plots = new histSaver();
  fcnc_plots->set_weight(&weight);
  fcnc_plots->debug = 0;

  //fcnc_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
  fcnc_plots->add(10,25.,125.,"p_{T,SS#tau}","tauptss",&tau_pt_ss,true,"GeV");
  fcnc_plots->add(10,25.,125.,"p_{T,OS#tau}","tauptos",&tau_pt_os,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{t,SM}","t1mass",&t1mass,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m^{T}_{W}","mtw",&mtw,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{#tau,#tau}","tautaumass",&tautaumass,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{W}","wmass",&wmass,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{t,FCNC}","t2mass",&t2mass,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{#tau#tau,vis}","tautauvismass",&ttvismass,true,"GeV");
  fcnc_plots->add(100,50.,250.,"P_{t,#tau#tau,vis}","tautauvispt",&tautauvispt,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{t,FCNC,vis}","t2vismass",&t2vismass,true,"GeV");
  fcnc_plots->add(100,50.,250.,"m_{t,SM,vis}","t1vismass",&t1vismass,true,"GeV");
  fcnc_plots->add(100,0.,1.,"E_{#nu,1}/E_{#tau,1}","x1fit",&x1fit,false,"");
  fcnc_plots->add(100,0.,1.,"E_{#nu,2}/E_{#tau,2}","x2fit",&x2fit,false,"");
  fcnc_plots->add(100,0.,10.,"#DeltaR(l+b-jet,#tau+#tau)","drlbditau",&drlbditau,false,"");
  fcnc_plots->add(100,0.,5.,"#eta_{#tau,max}","etamax",&etamax,false,"");
  fcnc_plots->add(100,0.,5.,"#DeltaR(l,#tau)","drltau",&drltau,false,"");
  fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,fcnc-j)","drtauj",&drtauj,false,"");
  fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,#tau)","drtautau",&drtautau,false,"");
  fcnc_plots->add(100,0.,5.,"#DeltaR(#tau,#light-jet,min)","drtaujmin",&drtaujmin,false,"");
  TString _fcnc_regions[] = {"reg1l2tau1bnj","reg1l1tau1b2j","reg1l1tau1b3j"};
  fcnc_nregions = sizeof(_fcnc_regions)/sizeof(TString);
  fcnc_regions = (TString**)malloc(fcnc_nregions*sizeof(TString*));

  for (int i = 0; i < fcnc_nregions; ++i)
  {
    fcnc_regions[i] = new TString(_fcnc_regions[i]);
  }

  TString nprong[] = {"1prong","3prong"};
  
  for (int j = 0; j < 3; ++j){
    for (int k = 0; k < 2; ++k)
    {
      for (int i = 0; i < 4; ++i)
      {
        if(doseppt)
          for (int iptbin = 0; iptbin < 2; ++iptbin)
          {
            if(debug) printf("adding region: %s\n", (*fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
            fcnc_plots->add_region(*fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_" + bwps[i]);
            fcnc_plots->add_region(*fcnc_regions[j] + "_" + nprong[k] + "_" + ptbin[iptbin] + "_veto" + bwps[i]);
          }
        fcnc_plots->add_region(*fcnc_regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
        fcnc_plots->add_region(*fcnc_regions[j] + "_" + nprong[k] + "_" + bwps[i]);
      }
    }
  }
  fake_notau_plots = new histSaver();
  fake_notau_plots->set_weight(&weight);
  fake_notau_plots->debug = 0;
  fake_plots = new histSaver();
  fake_plots->set_weight(&weight);
  fake_plots->debug = 0;
  //fake_plots->add(10,25.,125.,"p_{T,#tau}","taupt",&tau_pt_0,true,"GeV");
  fake_plots->add(10,25.,125.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  fake_plots->add(10,25.,125.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  fake_plots->add(20,20.,120.,"m_{#tau,light-jet}","taulmass",&taulmass,true,"GeV");
  //fake_plots->add(100,0.,100.,"E_{miss}^{T}","met",&MET_RefFinal_et,true,"GeV");
  fake_notau_plots->add(10,0.,200.,"p_{T,b}","bpt",&pt_b,true,"GeV");
  fake_notau_plots->add(10,0.,200.,"p_{T,light-jet}","ljetpt",&pt_ljet,true,"GeV");
  
  TString _fake_regions[] = {"reg1e1mu1tau2b","reg1l1tau2b1j_os","reg1l1tau2b1j_ss_ptbin1","reg1l1tau2b1j_ss_ptbin2","reg1e1mu1tau1b"};

  TString fake_regions_notau[] = {"reg1e1mu2bnj","reg1l2b2j","reg1e1mu2b"};
  
  fake_nregions = sizeof(_fake_regions)/sizeof(TString);
  int fake_nregionsnotau = sizeof(fake_regions_notau)/sizeof(TString);
  fake_regions = (TString**)malloc((fake_nregions+fake_nregionsnotau)*sizeof(TString*));
  
  for (int j = 0; j < fake_nregions; ++j){
    fake_regions[j] = new TString(_fake_regions[j]);
    for (int k = 0; k < 2; ++k){
      for (int i = 0; i < 4; i+=1){
        if(debug) printf("adding region: %s\n", (*fake_regions[j] + "_" + nprong[k] + "_" + bwps[i]).Data());
        fake_plots->add_region(*fake_regions[j] + "_" + nprong[k] + "_" + bwps[i]);
        fake_plots->add_region(*fake_regions[j] + "_" + nprong[k] + "_veto" + bwps[i]);
      }
    }
  }
  for (int j = 0; j < sizeof(fake_regions_notau)/sizeof(TString); ++j){
    fake_notau_plots->add_region(fake_regions_notau[j]);
    fake_regions[j+fake_nregions] = new TString(fake_regions_notau[j]);
  }
  fake_nregions+=fake_nregionsnotau;
}
nominal::~nominal(){
  deletepointer(fake_plots);
  deletepointer(fcnc_plots);
  deletepointer(fake_notau_plots);
  deletepointer(gM);
  deletepointer(neutrino_pt  );
  deletepointer(neutrino_eta );
  deletepointer(neutrino_phi );
  deletepointer(neutrino_m   );
}

void nominal::plot(TFile *outputfile){
  fake_plots->write(outputfile);
  fake_plots->clearhist();
  fcnc_plots->write(outputfile);
  fcnc_plots->clearhist();
  fake_notau_plots->write(outputfile);
  fake_notau_plots->clearhist();
}

void nominal::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {
    TList *listforfit = (TList*) gM->GetObjectFit();
    if (!listforfit)
    {
      printf("list isnt found\n");
      exit(1);
    }
    enum lorentzv{tau1,tau2,bj,cj,lep};
  
    TLorentzVector vectors[5];
    TLorentzVector neutrino[3];
    for( int i = 0; i<5 ; ++i) {
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

    neutrino[0].SetPtEtaPhiM(par[0]*vectors[tau1].Pt(),vectors[tau1].Eta(),vectors[tau1].Phi(),vectors[lep].Pt()==0?par[2]:0);
    neutrino[1].SetPtEtaPhiM(par[1]*vectors[tau2].Pt(),vectors[tau2].Eta(),vectors[tau2].Phi(),0);
    Float_t Hmass = (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]).M();
    Float_t met_resol = 13100+0.50*sqrt(met[2]*1000);
    Double_t chisq = 1e10;

    if(vectors[lep].Pt()!=0){
      neutrino[2].SetPtEtaPhiM(par[2],par[3],par[4],0);
  
      TLorentzVector t1 = neutrino[2]+vectors[lep]+vectors[bj];
  
      Float_t t2mass= (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]+vectors[cj]).M();
      Float_t wmass = (vectors[lep] + neutrino[2]).M();
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
      Float_t pConstrain = (vectors[bj].Dot(vectors[lep])/100) + (vectors[bj].Dot(neutrino[2])/100);
      chisq =  pow((wmass-81000)/10000,2) + pow((t1.M()-172500)/25000,2) +pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2) + pow((Hmass-125000)/10000,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
    }else{
      Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
      Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
      chisq = pow((Hmass-125000)/10000,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
    }
    f = chisq;
}



vector<int> nominal::findcjet(TString channel, vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus){
  int j = 0;
  double m_w = 81000;
  vector<int> output;
  int nlightj = ljet.size();
  if(debug) printf("nlightj: %d\n", nlightj); 
  double smallDr = 999;
  int fcjet = 0;

  for (int i = 0; i < nlightj; ++i){
    double Dr = ljet[j].DeltaR(taus[0] + lepton);
    if(smallDr>Dr){
       smallDr = Dr;
       fcjet = j;
    }
    output.push_back(fcjet);
    if (channel.Contains("had")){
      if(nlightj <= 3){
        for (int i = 0; i < nlightj; ++i){
          if(i!=fcjet) output.push_back(i);
        }
      }else{
        vector<int> wpair = findwpair(ljet, fcjet);
        output.push_back(wpair[0]);
        output.push_back(wpair[1]);
      }
    }
  }
  return output;
}
vector<int> nominal::findcjetML(TString channel, vector<TLorentzVector> pool, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus, int trainpart){
  int nlightj = pool.size();
  vector<int>  output;
  vector<float> MLinput[10];
  int nentryML = 0;
  TString modelname;
  if(channel == "lephad"){
     modelname = "lephad";
  }
  else if(channel == "lep2tau"){
     modelname = "lep2tau";
  }else if(channel == "hadhad"){
     modelname = "hadhad";
  }
  modelname = channel + char(nlightj + '0') + "j";
 
  for (int i = 0; i < nlightj; ++i)
  {
     MLinput[nentryML].push_back(pool[i].Pt());
     MLinput[nentryML].push_back(pool[i].Eta());
     MLinput[nentryML].push_back(pool[i].Phi());
     MLinput[nentryML].push_back(pool[i].E());
     nentryML++;
  }
  MLinput[nentryML].push_back(bjet.Pt ());
  MLinput[nentryML].push_back(bjet.Eta());
  MLinput[nentryML].push_back(bjet.Phi());
  MLinput[nentryML].push_back(bjet.E  ());
  nentryML++;
  for (int i = 0; i < taus.size(); ++i)
  {
     MLinput[nentryML].push_back(taus[i].Pt());
     MLinput[nentryML].push_back(taus[i].Eta());
     MLinput[nentryML].push_back(taus[i].Phi());
     MLinput[nentryML].push_back(taus[i].E());
     nentryML++;
  }
  if(channel.Contains("lep")){
     MLinput[nentryML].push_back(lep_v.Pt());
     MLinput[nentryML].push_back(lep_v.Eta());
     MLinput[nentryML].push_back(lep_v.Phi());
     MLinput[nentryML].push_back(lep_v.E());
     nentryML++;
  }
  modelname += trainpart ? "even" : "odd";
  vector<vector<float>> predicted = m_applyTF.predictEvent(modelname,MLinput,nentryML,4,nlightj,2);
  float highest = 0;
  int cjettmp = 0;
  for (int i = 0; i < nlightj; ++i)
  {
     if(highest < predicted[i][0]) {
        highest = predicted[i][0];
        cjettmp = i;
     }
  }
  output.push_back(cjettmp);
  if (channel.Contains("had")){
    if(nlightj <= 3){
      for (int i = 0; i < nlightj; ++i){
        if(i!=cjettmp) output.push_back(i);
      }
    }else{
      vector<int> wpair = findwpair(pool, cjettmp);
      output.push_back(wpair[0]);
      output.push_back(wpair[1]);
    }
  }
  return output;
}

vector<int> nominal::findwpair(vector<TLorentzVector> lightjets, int cjet){
  float mindeltam = -1;
  float m_w = 81000;
  vector<int> output;
  int wjet1,wjet2;
  for (int i = 0; i < lightjets.size(); ++i)
  {
    if (i == cjet) continue;
    for (int j = 0; j < lightjets.size(); ++j)
    {
      if(i <= j || j == cjet) continue;
      float deltam = abs((lightjets[i] + lightjets[j]).M() - m_w);
      if(mindeltam<0 || mindeltam > deltam ){
        mindeltam = deltam;
        wjet1 = i; wjet2 = j;
      }
    }
  }
  output.push_back(wjet1);
  output.push_back(wjet2);
  return output;
}

void nominal::fill_fcnc(TString region, int nprong, TString sample, int iptbin, float taubtag){
  for (int i = 0; i < 4; ++i){
    if(taubtag>btagwpCut[i]) {
      if(debug) printf("fill region: %s sample: %s\n", (region+"_"+char('0'+nprong) + "prong" + "_"+bwps[i]).Data(), sample.Data());
      if(doseppt) fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[i]);
      fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + bwps[i]);
    }else{
      if(doseppt) fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[i]);
      fcnc_plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + "veto" + bwps[i]);
    }
  }
}


void nominal::printv(TLorentzVector v){
  printf("Pt : %f, Eta: %f, Phi: %f, E: %f, m: %f\n", v.Pt(),v.Eta(),v.Phi(),v.E(),v.M());
}

void nominal::fill_notau(TString region, TString sample){
  if(debug) printf("fill region: %s sample: %s\n", (region).Data(), (sample).Data());
  fake_notau_plots->fill_hist(sample, region);
}
void nominal::finalise_sample(){
  if(writetree) {
    outputtreefile->Close();
    deletepointer(outputtreefile);
  }
}

void nominal::initgM(){

  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);

}
void nominal::init_sample(TString sample, TString sampletitle){
//==========================init output n-tuple==========================
  if(writetree){
    outputtreefile = new TFile(sample + "_tree.root","update");
    map<TString, TTree*>::iterator iter;
    for (int i = 0; i < fcnc_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fcnc_regions[i]->Data());
      if (outputtreefile->Get(*fcnc_regions[i])) {
        outputtree[*fcnc_regions[i]] = (TTree*)(outputtreefile->Get(*fcnc_regions[i]));
        Init(outputtree[*fcnc_regions[i]]);
      }else{
        outputtree[*fcnc_regions[i]] = new TTree(*fcnc_regions[i],*fcnc_regions[i]);
        if(reduce<2 || !fcnc) definetree(outputtree[*fcnc_regions[i]]);
      }
      if(reduce >= 1 || reduce == 0){
        outputtree[*fcnc_regions[i]]->Branch("t1mass",&t1mass);
        outputtree[*fcnc_regions[i]]->Branch("tautaumass",&tautaumass);
        outputtree[*fcnc_regions[i]]->Branch("wmass",&wmass);
        outputtree[*fcnc_regions[i]]->Branch("t2mass",&t2mass);
      }
      if(reduce==2 || reduce == 0){
        //outputtree[*fcnc_regions[i]]->Branch("tau_truthType_0",&tau_truthType_0);
        //outputtree[*fcnc_regions[i]]->Branch("tau_truthType_1",&tau_truthType_1);
        //outputtree[*fcnc_regions[i]]->Branch("tau_charge_0",&tau_charge_0);
        //outputtree[*fcnc_regions[i]]->Branch("tau_charge_1",&tau_charge_1);
        //outputtree[*fcnc_regions[i]]->Branch("tau_JetBDTSigTight_0",&tau_JetBDTSigTight_0);
        //outputtree[*fcnc_regions[i]]->Branch("tau_JetBDTSigTight_1",&tau_JetBDTSigTight_1);
        //outputtree[*fcnc_regions[i]]->Branch("eventNumber", &eventNumber);
        outputtree[*fcnc_regions[i]]->Branch("neutrino_pt" , &neutrino_pt );
        outputtree[*fcnc_regions[i]]->Branch("neutrino_eta", &neutrino_eta);
        outputtree[*fcnc_regions[i]]->Branch("neutrino_phi", &neutrino_phi);
        outputtree[*fcnc_regions[i]]->Branch("neutrino_m"  , &neutrino_m  );
        outputtree[*fcnc_regions[i]]->Branch("weight",&weight);
        outputtree[*fcnc_regions[i]]->Branch("fakeSF",&fakeSF);
        outputtree[*fcnc_regions[i]]->Branch("ljet_indice", &ljet_indice );
        outputtree[*fcnc_regions[i]]->Branch("x1fit", &x1fit);
        outputtree[*fcnc_regions[i]]->Branch("x2fit", &x2fit);
        outputtree[*fcnc_regions[i]]->Branch("t1vismass",&t1vismass);
        outputtree[*fcnc_regions[i]]->Branch("t2vismass",&t2vismass);
        outputtree[*fcnc_regions[i]]->Branch("ttvismass",&ttvismass);
        outputtree[*fcnc_regions[i]]->Branch("tautauvispt",&tautauvispt);
        outputtree[*fcnc_regions[i]]->Branch("mtw",&mtw);
        outputtree[*fcnc_regions[i]]->Branch("tau_pt_ss",&tau_pt_ss);
        outputtree[*fcnc_regions[i]]->Branch("tau_pt_os",&tau_pt_os);
        outputtree[*fcnc_regions[i]]->Branch("drlbditau", &drlbditau);
        outputtree[*fcnc_regions[i]]->Branch("etamax", &etamax);
        outputtree[*fcnc_regions[i]]->Branch("drltau",&drltau);
        outputtree[*fcnc_regions[i]]->Branch("drtauj",&drtauj);
        outputtree[*fcnc_regions[i]]->Branch("drtautau",&drtautau);
        outputtree[*fcnc_regions[i]]->Branch("drtaujmin", &drtaujmin);

      }
    }

    for (int i = 0; i < fake_nregions; ++i)
    {
      if(debug) printf("init sample:: get region: %s\n", fake_regions[i]->Data());
      if (outputtreefile->Get(*fake_regions[i])) {
        outputtree[*fake_regions[i]] = (TTree*)(outputtreefile->Get(*fake_regions[i]));
        Init(outputtree[*fake_regions[i]]);
      }else{
        outputtree[*fake_regions[i]] = new TTree(*fake_regions[i],*fake_regions[i]);
        definetree(outputtree[*fake_regions[i]]);
      }
    }
  }
//==========================init output histogram==========================
  if(dohist){
    if (sample.Contains("data"))
    {
      fake_plots->init_sample("data","data","data",kBlack);
      fcnc_plots->init_sample("data","data","data",kBlack);
      fake_notau_plots->init_sample("data","data_notau","data",kBlue);
      initdata = 1;
    }else{
      if(sample.Contains("ttbar")) sample = "ttbar";
      else if(reduce == 1) sample.Remove(sample.Sizeof()-2);
      fake_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      fcnc_plots->init_sample(sample + "_g",sample + "_g",sampletitle + "(gluon fake #tau)",(enum EColor)7);
      fake_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
      fcnc_plots->init_sample(sample + "_j",sample + "_j",sampletitle + "(light-jet fake #tau)",kBlue);
      fake_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
      fcnc_plots->init_sample(sample + "_b",sample + "_b",sampletitle + "(b-jets fake #tau)",kViolet);
      fake_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
      fcnc_plots->init_sample(sample + "_lep",sample + "_lep",sampletitle + "(lepton fake #tau)",kGreen);
      fake_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
      fcnc_plots->init_sample(sample + "_real",sample + "_real",sampletitle + "(real #tau)",kRed);
      fake_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
      fcnc_plots->init_sample(sample + "_c",sample + "_c",sampletitle + "(c-jets fake #tau)",kOrange);
      fake_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
      fcnc_plots->init_sample(sample + "_nomatch",sample + "_nomatch",sampletitle + "(no truth matched fake #tau)",kGray);
      fake_notau_plots->init_sample(sample,sample+"_notau",sampletitle,kRed);
    }
  }
}
