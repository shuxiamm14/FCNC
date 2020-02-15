#include "nominal.h"
#include "fcnc_include.h"
#include "commen.h"
using namespace std;
int nominal::GeV = 0;

void nominal::initMVA(TString fcnc_region){

  doBDT = 1;

  reader[fcnc_region] = new TMVA::Reader( "!Color:!Silent" );

  reader[fcnc_region]->AddVariable("tau_pt_0",&tau_pt_0);
  reader[fcnc_region]->AddVariable("tau_pt_1",&tau_pt_1);
  reader[fcnc_region]->AddVariable("drtautau",&drtautau);
  if(fcnc_region.Contains("2j") || fcnc_region.Contains("3j")){
     reader[fcnc_region]->AddVariable("etmiss",&etmiss);
     reader[fcnc_region]->AddVariable("dphitauetmiss",&dphitauetmiss);
     reader[fcnc_region]->AddVariable("phicent",&phicent);
     reader[fcnc_region]->AddVariable("tautaumass",&tautaumass);
     reader[fcnc_region]->AddVariable("t2mass",&t2mass);
     reader[fcnc_region]->AddVariable("x1fit",&x1fit);
     reader[fcnc_region]->AddVariable("x2fit",&x2fit);
     if(fcnc_region.Contains("1l1tau")){
        reader[fcnc_region]->AddVariable("drlb",&drlb);
        reader[fcnc_region]->AddVariable("drtaub",&drtaub);
        reader[fcnc_region]->AddVariable("mjjmin",&mjjmin);
     }
     if(fcnc_region != "reg1l1tau1b2j"){
        reader[fcnc_region]->AddVariable("wmass",&wmass);
        reader[fcnc_region]->AddVariable("t1mass",&t1mass);
     }
     if(fcnc_region.Contains("1l1tau1b2j")){
        reader[fcnc_region]->AddVariable("allpz",&allpz);
        reader[fcnc_region]->AddVariable("allmass",&allmass);
     }
  }else if(fcnc_region.Contains("1l2tau1")){
     reader[fcnc_region]->AddVariable("t1vismass",&t1vismass);
     reader[fcnc_region]->AddVariable("mtaujmin",&mtaujmin);
     reader[fcnc_region]->AddVariable("drltau",&drltau);
     reader[fcnc_region]->AddVariable("etamax",&etamax);
     reader[fcnc_region]->AddVariable("mtw",&mtw);
     reader[fcnc_region]->AddVariable("drlbditau",&drlbditau);
     reader[fcnc_region]->AddVariable("tautauvispt",&tautauvispt);
     reader[fcnc_region]->AddVariable("t2vismass",&t2vismass);
  }

  reader[fcnc_region]->AddVariable("ttvismass",&ttvismass);
  reader[fcnc_region]->AddVariable("drtaujmin",&drtaujmin);

  reader[fcnc_region]->BookMVA( "BDTG_1" , TString(PACKAGE_DIR) + "/config/weights/" + fcnc_region + "TMVAClassification_1_BDTG.weights.xml" );
  reader[fcnc_region]->BookMVA( "BDTG_2" , TString(PACKAGE_DIR) + "/config/weights/" + fcnc_region + "TMVAClassification_2_BDTG.weights.xml" );
}


Double_t nominal::phi_centrality(Double_t aPhi, Double_t bPhi, Double_t cPhi) {
//     Calculate the phi centrality score for an object to be between two other objects in phi
//     Returns sqrt(2) if in dead center
//     Returns smaller than 1 if an object is not between
//     a and b are the bounds, c is the vector to be tested

  Double_t A = sin(cPhi - aPhi)/sin(bPhi - aPhi);
  Double_t B = sin(bPhi - cPhi)/sin(bPhi - aPhi);

  return (A+B)/sqrt(A*A + B*B);
}



RooRealVar  nominal::_dR_("_dR_","",0,0.8);
RooRealVar  nominal::_m1_("_m1_","",0.06);
RooRealVar  nominal::_w1_("_w1_","",0.03);
RooGaussian nominal::_gaus_("_gaus_","",_dR_,_m1_,_w1_);
RooRealVar  nominal::_m2_("_m2_","",0.1);
RooRealVar  nominal::_w2_("_w2_","",0.1);
RooLandau   nominal::_land_("_land_","",_dR_,_m2_,_w2_);
RooRealVar  nominal::_fr1_("_fr1_","",0.56);
RooAddPdf   nominal::_pdf_("_pdf_","",_gaus_,_land_,_fr1_);

Float_t nominal::getHadTauProb(Float_t _dR, Float_t _p) {
  if(_dR>=_dR_.getMax()) return 0;
  if(_p<25) _p = 25;
  Float_t m1 = 4.56088e+00/(_p+2.30554e-02*_p*_p)+2.00545e-02;
  Float_t w1 = 2.56901e+01/(_p*_p)+9.63415e-03;
  Float_t m2 = 5.70742e+00/(_p+2.07263e-02*_p*_p)+4.32004e-02;
  Float_t w2 = 4.34997e+00/pow(_p,1.5)+7.31908e-03;
  _m1_.setVal(m1);
  _w1_.setVal(w1);
  _m2_.setVal(m2);
  _w2_.setVal(w2);
  _dR_.setVal(_dR);
  return _pdf_.getVal(_dR_);
}


nominal::nominal(){
  doBDT = 0;
  ierflg = 0;
  dumptruth = 0;
  nonfcncmatched = 0;
  fcncmatched = 0;
  leptonicw = 0;
  fcnc = 0;
  debug = 0;
  dosys = 0;
  reduce = 0;
  initdata = 0;
  initttbar = 0;
  dohist = 0;
  version = 0;
  pt_b = 0;
  pt_ljet = 0;
  taulmass = 0;
  t1mass = 0;
  drlbditau = 0;
  mtw = 0;
  tau_pt_ss = 0;
  tau_pt_os = 0;
  etamax = 0;
  drltau   = 0;
  drtauj   = 0;
  drtautau = 0;
  wmass     = 0;
  t2mass    = 0;
  tautaumass = 0;
  outputtreefile = 0;
  fake_plots = 0;
  fake_notau_plots = 0;
  TLorentzVector v1;
  for(int i = 0 ; i < 2 ; ++i){
    taus_v.push_back(v1);
  }

  for (int i = 0; i < 4; ++i)
  {
    dobwp[bwps[i]] = 0;
    dovetobwp[bwps[i]] = 0;
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
  fake_plots = 0;
  fake_notau_plots = 0;
  gM = 0;
}

void nominal::defGeV(int _GeV){
  GeV = _GeV;
}

void nominal::readTFmeanstd(TString filename){
  m_applyTF.configfolder = "/Users/Liby/work/tau_analysis/FCNC/ttH_fakes/run/MLmodels";
  m_applyTF.readmeanfile(filename);
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

void nominal::init_dsid(){
  ifill = 0;
  weightlist.clear();
}

void nominal::plot(){
  if(fake_plots) {
    if(debug) printf("write fake_plots\n");
    fake_plots->write();
  }
  if(fcnc_plots) {
    if(debug) printf("write fcnc_plots\n");
    fcnc_plots->write();
  }
  if(fake_notau_plots) {
    if(debug) printf("write fake_notau_plots\n");
    fake_notau_plots->write();
  }
}

void nominal::fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag) {
  if(!GeV) {
    printf("Error: nominal::GeV not initialised\n");
    exit(0);
  }
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
  Float_t met_resol = 13.1*GeV+0.50*sqrt(met[2]*GeV);
  Double_t chisq = 1e10;

  if(vectors[lep].Pt()!=0){
    neutrino[2].SetPtEtaPhiM(par[2],par[3],par[4],0);
  
    TLorentzVector t1 = neutrino[2]+vectors[lep]+vectors[bj];
  
    Float_t t2mass= (vectors[tau1]+neutrino[0]+vectors[tau2]+neutrino[1]+vectors[cj]).M();
    Float_t wmass = (vectors[lep] + neutrino[2]).M();
    Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px()+neutrino[2].Px();
    Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py()+neutrino[2].Py();
    Float_t pConstrain = (vectors[bj].Dot(vectors[lep])/100) + (vectors[bj].Dot(neutrino[2])/100);
    chisq =  pow((wmass-81*GeV)/10*GeV,2) + pow((t1.M()-172500)/25*GeV,2) +pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2) + pow((Hmass-125*GeV)/10*GeV,2);// + pow((t2mass-172.5)/30,2);// + pow((pConstrain-110)/20,2);
  }else{
    Float_t pxMiss = neutrino[0].Px()+neutrino[1].Px();
    Float_t pyMiss = neutrino[0].Py()+neutrino[1].Py();
    chisq = pow((Hmass-125*GeV)/10*GeV,2) + pow((pxMiss-met[0])/met_resol,2) + pow((pyMiss-met[1])/met_resol,2);
  }
  f = chisq;
}



vector<int> nominal::findcjet(TString channel, vector<TLorentzVector> ljet, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus){
  double m_w = 81*GeV;
  vector<int> output;
  int nlightj = ljet.size();
  if(debug) printf("nlightj: %d\n", nlightj); 
  double smallDr = 999;
  int fcjet = 0;

  for (int j = 0; j < nlightj; ++j){
    double Dr = ljet[j].DeltaR(taus.size() == 2? taus[0] + taus[1] : taus[0] + lepton);
    if(smallDr>Dr){
      smallDr = Dr;
      fcjet = j;
    }
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
  return output;
}
vector<int> nominal::findcjetML(TString channel, vector<TLorentzVector> pool, TLorentzVector bjet, TLorentzVector lepton, vector<TLorentzVector> taus, int trainpart){
  int nlightj = taus.size()>=2?(pool.size()>3?3:pool.size()):(pool.size()>4?4:pool.size());
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
  if(debug) printf("lightjet:\n");
  for (int i = 0; i < nlightj; ++i)
  {
    if(debug) printv(pool[i]);
    //MLinput[nentryML].push_back(pool[i].Pt());
    MLinput[nentryML].push_back(pool[i].Eta());
    MLinput[nentryML].push_back(pool[i].Phi());
    MLinput[nentryML].push_back(pool[i].E());
    nentryML++;
  }
  if(debug) printf("bjet:\n");
  //printv(bjet);
  //MLinput[nentryML].push_back(bjet.Pt ());
  MLinput[nentryML].push_back(bjet.Eta());
  MLinput[nentryML].push_back(bjet.Phi());
  MLinput[nentryML].push_back(bjet.E  ());
  nentryML++;

  if(debug) printf("taus:\n");
  for (int i = 0; i < taus.size(); ++i)
  {
    if(debug) printv(taus[i]);
    //MLinput[nentryML].push_back(taus[i].Pt());
    MLinput[nentryML].push_back(taus[i].Eta());
    MLinput[nentryML].push_back(taus[i].Phi());
    MLinput[nentryML].push_back(taus[i].E());
    nentryML++;
  }
  if(channel.Contains("lep")){
    if(debug) {
      printf("lepton:\n");
      printv(lep_v);
    }
    //MLinput[nentryML].push_back(lep_v.Pt());
    MLinput[nentryML].push_back(lep_v.Eta());
    MLinput[nentryML].push_back(lep_v.Phi());
    MLinput[nentryML].push_back(lep_v.E());
    nentryML++;
  }
  modelname += trainpart ? "even" : "odd";
  if(debug) printf("ML input: %s,%d, %lu,%d\n", modelname.Data(),nentryML,MLinput[0].size(),nlightj);
  vector<vector<float>> predicted = m_applyTF.predictEvent(modelname,MLinput,nentryML,(int)MLinput[0].size(),nlightj,2);
  float highest = 0;
  ljets_score.clear();

  double smallDr = 999;
  int cjettmp = -1;

  for (int j = 0; j < nlightj; ++j){
    ljets_score.push_back(predicted[j][0]);
    if(predicted[j][0]<0.1) continue;
    double Dr = pool[j].DeltaR(taus.size() == 2? taus[0] + taus[1] : taus[0] + lepton);
    if(smallDr>Dr){
      smallDr = Dr;
      cjettmp = j;
    }
  }
  if(cjettmp<0)
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

void nominal::calcfakesf(std::vector<int> origin, std::vector<float> pt, std::vector<int> prong){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  if(origin.size()!=pt.size() || pt.size()!=prong.size()) {
    printf("nominal::calcfakesf(): ERROR: origin, pt, prong vector size are not equal.\n");
    exit(0);
  }
  int ntau = origin.size();
  float fakeSF_origin = 1;
  float fakeSF_origin_NP[2][4] = {{1,1,1,1},{1,1,1,1}};
  float fakeSF_tthML = 1;
  float fakeSF_tthML_NP[2][3] = {{1,1,1},{1,1,1}};
  int ptbin;
  for (int i = 0; i < ntau; ++i)
  {
    if(origin[i]<0) continue;
    pt[i] = pt[i]/GeV;
    fakeSF_origin*=fakeSFs[ pt[i]>35 ][origin[i]];
    int prongbin = prong[i] == 3;
    if(prongbin == 0) {
      if(pt[i]<45) ptbin = 0;
      else if(pt[i] < 70) ptbin = 1;
      else ptbin = 2;
    }else{
      if(pt[i]<50) ptbin = 0;
      else if(pt[i] < 75) ptbin = 1;
      else ptbin = 2;
    }
    fakeSF_tthML *= fakeSFML[prongbin][ptbin];
    if(nominaltree) fakeSF_tthML_NP[prongbin][ptbin] *= fakeSFMLNP[prongbin][ptbin]/fakeSF_tthML + 1;
  }
  addweights(fakeSF_tthML*weights->at(0),"fakeSF_tthML");
  addweights(fakeSF_origin*weights->at(0),"fakeSF_origin");

  if(nominaltree) {
    for (int inpprongbin = 0; inpprongbin < 2; ++inpprongbin)
    {
      for (int inpptbin = 0; inpptbin < 3; ++inpptbin)
      {
        addweights(fakeSF_tthML_NP[inpprongbin][inpptbin],TString("fakeSFNP_tthML_ptbin" + to_string(inpptbin) + "_prongbin" + to_string(inpprongbin)));
      }
    }
    for (int iNP = 0; iNP < 8; ++iNP)
    {
      double valNP = 1;
      for (int itau = 0; itau < ntau; ++itau)
      {
        if(origin[itau] >= 0 ){
          if ( iNP < 4 && pt[itau]>35 == 0 )
             valNP *= fakeSFsNPbase[pt[itau]>35][origin[itau]][iNP]*sqrt(fakeSFsNPsSigma2[pt[itau]>35][iNP])/fakeSFs[pt[itau]>35][origin[itau]] + 1;
          else if (iNP >= 4 && pt[itau]>35 == 1) {
             valNP *= fakeSFsNPbase[pt[itau]>35][origin[itau]][iNP-4]*sqrt(fakeSFsNPsSigma2[pt[itau]>35][iNP-4])/fakeSFs[pt[itau]>35][origin[itau]] + 1;
          }
        }
      }
      addweights(valNP, TString("fakeSFNP_origin_" + to_string(iNP)));
    }
  }

}

double nominal::FindNewFakeSF(TString NP, TString tauorigin, float taupt, TString region){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  if(!newFakeSF.size()) {
    printf("nominal::FindNewFakeSF() Error : newFakeSF is Empty, please call nominal::ConfigNewFakeSF() first\n");
    exit(0);
  }
  if(tauorigin.Contains("_real") || tauorigin.Contains("_lep")) return 1;
  bool isOs = region.Contains("os");
  bool iswjet = tauorigin.Contains("_wjet");
  int slice = 0;
  for (int islice = 0; islice < fakePtSlices.size(); ++islice)
  {
    if(taupt<fakePtSlices[islice]) {
      slice = islice-1;
      break;
    }
  }
  return newFakeSF[NP][isOs][iswjet][slice].nominal;
}

bool nominal::AddTheorySys(){
  if(weight_mc_v){
    for (int i = 1; i <= theoryweightsum->GetNbinsX(); ++i)
    {
      TString weightName = theoryweightsum->GetXaxis()->GetBinLabel(i);
      if(weightName!=""){ //https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PmgTopProcesses, Top, Single Top, ttH
        if((weightName.Contains("muR=") && weightName.Contains(",muF=")) || weightName.Contains("PDFset=260") ){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),weightName);
        }else if(weightName.Contains("isr:muRfac=10_fsr:muRfac=20")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"FSR_up");
        }else if(weightName.Contains("isr:muRfac=10_fsr:muRfac=05")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"FSR_down");
        }else if(weightName.Contains("Var3cUp")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"ISR_up");
        }else if(weightName.Contains("Var3cDown")){
          addweights(weight_mc_v->at(i-1)/weight_mc*theoryweightsum->GetBinContent(1)/theoryweightsum->GetBinContent(i),"ISR_down");
        }
      }
    }
  }
  for(int i = 0; i < weights->size(); i++){
    if(weights->at(i)!=weights->at(i)) {
      printf("weight is nan, eventNumber: %llu, n_weight: %d\n", eventNumber, i);
      return 0;
    }
  }
  return 1;
}

void nominal::ConfigNewFakeSF(){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  TFile *sfFile[2];
  newFakeSF.clear();
  TString prefix = PACKAGE_DIR;
  prefix += "/data/";
  sfFile[0] = new TFile(prefix + "scale_factors_ss.root");
  sfFile[1] = new TFile(prefix + "scale_factors_os.root");
  string iswjetstring[2] = {"fake", "wjet-fake"};
  for (int iswjet = 0; iswjet < 2; ++iswjet)
  {
    for (int islice = 0; islice < fakePtSlices.size()-1; ++islice)
    {
      for (int isOs = 0; isOs < 2; ++isOs)
      {
        TString histname = ( "Fit_sf_" + iswjetstring[iswjet] + "_pt" + to_string(int(fakePtSlices[islice])) + to_string(int(fakePtSlices[islice+1])) ).c_str();
        TH1D *SFhist = (TH1D*)sfFile[isOs]->Get(histname);
        if(!SFhist) printf("histogram not found in SF file: %s\n", histname.Data());
        TAxis *xaxis = SFhist->GetXaxis();
        for (int ibin = 1; ibin <= SFhist->GetNbinsX(); ++ibin)
        {
          TString NPname = xaxis->GetBinLabel(ibin);
          if(find(plotNPs.begin(),plotNPs.end(),NPname) == plotNPs.end()) continue;
          if(!newFakeSF[NPname].size()) newFakeSF[NPname] = {{{0,0},{0,0}},{{0,0},{0,0}}};
          newFakeSF[NPname][isOs][iswjet][islice] = observable(SFhist->GetBinContent(ibin),SFhist->GetBinError(ibin));
        }
      }
    }
  }
  printf("new SFs: \n");
  for (int isOS = 0; isOS < 2; ++isOS)
  {
    printf("isOs: %d\n", isOS);
    printf("Slices: ");
    for (int islice = 0; islice < fakePtSlices.size(); ++islice)
    {
      printf(" %s ", ( to_string(int(fakePtSlices[islice])) + to_string(int(fakePtSlices[islice+1])) ).c_str());
    }
    printf("\n");
    for (int iswjet = 0; iswjet < 2; ++iswjet)
    {
      printf("%s", iswjetstring[iswjet]);
      for (int islice = 0; islice < fakePtSlices.size(); ++islice)
      {
        printf(" %s ", newFakeSF[NPname][isOs][iswjet][islice].nominal);
      }
      printf("\n");
    }
  }
  delete sfFile[0];
  delete sfFile[1];
  applyNewFakeSF = 1;
}

void nominal::calcfakesf_pdg(std::vector<int> originpdg, std::vector<float> pt, std::vector<int> prong){ //origin=-1,0,1,2,3 for real/lep,b,c,g,j
  std::vector<int> origin;
  for (int i = 0; i < originpdg.size(); ++i)
  {
    switch(originpdg[i]){
      case 11: case 13: case 15:
      origin.push_back(-1);
      break;
      case 5:
      origin.push_back(0);
      break;
      case 4:
      origin.push_back(1);
      break;
      case 21:
      origin.push_back(2);
      break;
      default:
      origin.push_back(3);
    }
  }
  calcfakesf(origin,pt,prong);
}

void nominal::addweights(double weight, TString name){
  if(weight == 0) printf("Warning: %s weight is 0\n", name.Data());
  weights->push_back(weight);
  if(ifill==0) weightlist.push_back(name);
}

void nominal::saveweightslist(TString filename){
  ofstream out(filename.Data());
  for(auto names: weightlist){
    out<<names<<endl;
  }
  out.close();
}

vector<int> nominal::findwpair(vector<TLorentzVector> lightjets, int cjet){
  if(!GeV) {
    printf("Error: nominal::GeV not initialised\n");
    exit(0);
  }
  float mindeltam = -1;
  float m_w = 81*GeV;
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

void nominal::fillhist(histSaver* plots, TString region, int nprong, TString sample, int iptbin, float taubtag, TString NP){
  for (int i = 0; i < 4; ++i){
    if(taubtag>btagwpCut[i]) {
      if(dobwp[bwps[i]] == 1) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_" + bwps[i],NP);
    }else{
      if(dovetobwp[bwps[i]] == 1) plots->fill_hist(sample,region+"_"+char('0'+nprong)+"prong_" + ptbin[iptbin] + "_veto" + bwps[i],NP);
    }
  }
}

void nominal::readweightsysmap(int dsid, TString framework){
  if(weightsysmap.find(dsid) != weightsysmap.end()) return;
  TString prefix = PACKAGE_DIR;
  prefix = prefix + "/config/theoryweightlist/" + framework + "_" + TString(to_string(dsid)) + ".txt";
  ifstream f(prefix);
  if(f.good())
    weightsysmap[dsid] = readTovecString(prefix);
}

void nominal::printv(TLorentzVector v){
  printf("Pt : %f, Eta: %f, Phi: %f, E: %f, m: %f\n", v.Pt(),v.Eta(),v.Phi(),v.E(),v.M());
}

void nominal::fill_notau(TString region, TString sample, TString NP){
  if(debug) printf("fill region: %s sample: %s\n", (region).Data(), (sample).Data());
  fake_notau_plots->fill_hist(sample, region, NP);
}
void nominal::finalise_sample(){
  printf("finalising sample\n");
  if(dohist) {
    plot();
  }
  if (writetree) {
    outputtreefile->cd();
    map < TString, TTree*> ::iterator iter;
    for (iter = outputtree.begin(); iter != outputtree.end(); ++iter)
      iter->second->Write(iter->first, TObject::kWriteDelete);
    outputtreefile->Close();
    deletepointer(outputtreefile);
  }
}

TMinuit* nominal::initgM(){

  gM = new TMinuit(5);
  gM->SetFCN(fcn);
  gM->SetPrintLevel(-1);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  
  arglist[0] = 1;
  gM->mnexcm("SET ERR", arglist ,1,ierflg);
  return gM;
}
