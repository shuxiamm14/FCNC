#define AnathqMini_cxx
#include "AnathqMini.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

const double btagwpCut[4]={0.94,0.83,0.64,0.11}; // 60, 70, 77, 85 % (0.8244273); // 0.645925 77% for MV2c10; 70% 0.8244273

void AnathqMini::Loop()
{
//   In a ROOT session, you can do:
//      root> .L AnathqMini.C
//      root> AnathqMini t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   int GeV(1000);
   bool dump(true);
   if(!_ismc)dump = true;
   _histf = new TFile(_outhist+".root", "RECREATE");
   std::ofstream* fout_txt;
   if(dump)fout_txt = new std::ofstream(_outhist+".txt");
   //TString BDT_tth1l2tau = "TMVAClassification_BDTG.weights9varbtagtaupt25Triglept27tauTTbvetoWT_R21.xml";
   //std::cout<<" which BDT ? "<<BDT_tth1l2tau<<std::endl;
   //initialiseTMVA_tth1l2tau(BDT_tth1l2tau,BDT_tth1l2tauEven,BDT_tth1l2tauOdd);
   //const char *mylabel[5]={"Other","Gluon","Light","C","B"};
   //const char *mylabelx[3]={"TwoFakes", "OneFake","RealTaus"};
   //Float_t xbins[4]={-1.,0.0,0.6,1.0};
   //2lss1b
   TH1D* h2lss1b_mll = new TH1D("h2lss1b_mll","h2lss1b_mll", 50, 0., 500.);
   TH1D* h2lss1b_njet = new TH1D("h2lss1b_njet","h2lss1b_njet", 8, 0.,8.);
   TH1D* h2lss1b_sumet =  new TH1D("h2lss1b_sumet","h2lss1b_sumet", 50, 0., 500.);
   TH1D* h2lss1b_dphimin = new TH1D("h2lss1b_dphimin", "h2lss1b_dphimin", 5, 0., 5.);
   TH1D* h2lss1b_dphix = new TH1D("h2lss1b_dphix", "h2lss1b_dphix", 5, 0., 5.);
   TH1D* h2lss1b_mblt = new TH1D("h2lss1b_mblt","h2lss1b_mblt",50, 0., 500.);
   TH1D* h2lss1b_ptblt = new TH1D("h2lss1b_ptblt","h2lss1b_ptblt",50, 0., 500.);
   TH1D* h2lss1b_mwlh = new TH1D("h2lss1b_mwlh","h2lss1b_mwlh",50, 0., 500.);
   TH1D* h2lss1b_ptwlh = new TH1D("h2lss1b_ptwlh","h2lss1b_ptwlh",50, 0., 500.);
   TH1D* h2lss1b_mwlhq = new TH1D("h2lss1b_mwlhq","h2lss1b_mwlhq",100, 0., 1000.);
   TH1D* h2lss1b_ptwlhq = new TH1D("h2lss1b_ptwlhq","h2lss1b_ptwlhq",100, 0., 1000.);
   TH1D* h2lss1b_ttdphi = new TH1D("h2lss1b_ttdphi","h2lss1b_ttdphi",50, 0., 12.);
   TH1D* h2lss1b_dm = new TH1D("h2lss1b_dm","h2lss1b_dm",46, 0., 460.);
   //2lss2b
   TH1D* h2lss2b_mll = new TH1D("h2lss2b_mll","h2lss2b_mll", 50, 0., 500.);
   TH1D* h2lss2b_njet = new TH1D("h2lss2b_njet","h2lss2b_njet", 8, 0.,8.);
   TH1D* h2lss2b_sumet =  new TH1D("h2lss2b_sumet","h2lss2b_sumet", 50, 0., 500.);
   TH1D* h2lss2b_dphimin = new TH1D("h2lss2b_dphimin", "h2lss2b_dphimin", 5, 0., 5.);
   TH1D* h2lss2b_dphix = new TH1D("h2lss2b_dphix", "h2lss2b_dphix", 5, 0., 5.);
   TH1D* h2lss2b_mblt = new TH1D("h2lss2b_mblt","h2lss2b_mblt",50, 0., 500.);
   TH1D* h2lss2b_ptblt = new TH1D("h2lss2b_ptblt","h2lss2b_ptblt",50, 0., 500.);
   TH1D* h2lss2b_mwlh = new TH1D("h2lss2b_mwlh","h2lss2b_mwlh",50, 0., 500.);
   TH1D* h2lss2b_ptwlh = new TH1D("h2lss2b_ptwlh","h2lss2b_ptwlh",50, 0., 500.);
   TH1D* h2lss2b_mwlhq = new TH1D("h2lss2b_mwlhq","h2lss2b_mwlhq",100, 0., 1000.);
   TH1D* h2lss2b_ptwlhq = new TH1D("h2lss2b_ptwlhq","h2lss2b_ptwlhq",100, 0., 1000.);
   TH1D* h2lss2b_ttdphi = new TH1D("h2lss2b_ttdphi","h2lss2b_ttdphi",50, 0., 12.);
   TH1D* h2lss2b_dm = new TH1D("h2lss2b_dm","h2lss2b_dm",46, 0., 460.);
   //3l-1b
   TH1D* h3l1b_mll01 = new TH1D("h3l1b_mll01","h3l1b_mll01", 50, 0., 500.);
   TH1D* h3l1b_mll02 = new TH1D("h3l1b_mll02","h3l1b_mll02", 50, 0., 500.);
   TH1D* h3l1b_mlll = new TH1D("h3l1b_mlll","h3l1b_mlll", 50, 0., 500.);
   TH1D* h3l1b_njet = new TH1D("h3l1b_njet","h3l1b_njet", 8, 0.,8.);
   TH1D* h3l1b_sumet =  new TH1D("h3l1b_sumet","h3l1b_sumet", 50, 0., 500.);
   TH1D* h3l1b_dphimin = new TH1D("h3l1b_dphimin", "h3l1b_dphimin", 5, 0., 5.);
   TH1D* h3l1b_dphix = new TH1D("h3l1b_dphix", "h3l1b_dphix", 5, 0., 5.);
   TH1D* h3l1b_mblt = new TH1D("h3l1b_mblt","h3l1b_mblt",50, 0., 500.);
   TH1D* h3l1b_ptblt = new TH1D("h3l1b_ptblt","h3l1b_ptblt",50, 0., 500.);
   TH1D* h3l1b_mwlh = new TH1D("h3l1b_mwlh","h3l1b_mwlh",50, 0., 500.);
   TH1D* h3l1b_ptwlh = new TH1D("h3l1b_ptwlh","h3l1b_ptwlh",50, 0., 500.);
   TH1D* h3l1b_mwlhq = new TH1D("h3l1b_mwlhq","h3l1b_mwlhq",100, 0., 1000.);
   TH1D* h3l1b_ptwlhq = new TH1D("h3l1b_ptwlhq","h3l1b_ptwlhq",100, 0., 1000.);
   TH1D* h3l1b_ttdphi = new TH1D("h3l1b_ttdphi","h3l1b_ttdphi",50, 0., 12.);
   TH1D* h3l1b_dm = new TH1D("h3l1b_dm","h3l1b_dm",46, 0., 460.);
   //3l-2b
   TH1D* h3l2b_mll01 = new TH1D("h3l2b_mll01","h3l2b_mll01", 50, 0., 500.);
   TH1D* h3l2b_mll02 = new TH1D("h3l2b_mll02","h3l2b_mll02", 50, 0., 500.);
   TH1D* h3l2b_mlll = new TH1D("h3l2b_mlll","h3l2b_mlll", 50, 0., 500.);
   TH1D* h3l2b_njet = new TH1D("h3l2b_njet","h3l2b_njet", 8, 0.,8.);
   TH1D* h3l2b_sumet =  new TH1D("h3l2b_sumet","h3l2b_sumet", 50, 0., 500.);
   TH1D* h3l2b_dphimin = new TH1D("h3l2b_dphimin", "h3l2b_dphimin", 5, 0., 5.);
   TH1D* h3l2b_dphix = new TH1D("h3l2b_dphix", "h3l2b_dphix", 5, 0., 5.);
   TH1D* h3l2b_mblt = new TH1D("h3l2b_mblt","h3l2b_mblt",50, 0., 500.);
   TH1D* h3l2b_ptblt = new TH1D("h3l2b_ptblt","h3l2b_ptblt",50, 0., 500.);
   TH1D* h3l2b_mwlh = new TH1D("h3l2b_mwlh","h3l2b_mwlh",50, 0., 500.);
   TH1D* h3l2b_ptwlh = new TH1D("h3l2b_ptwlh","h3l2b_ptwlh",50, 0., 500.);
   TH1D* h3l2b_mwlhq = new TH1D("h3l2b_mwlhq","h3l2b_mwlhq",100, 0., 1000.);
   TH1D* h3l2b_ptwlhq = new TH1D("h3l2b_ptwlhq","h3l2b_ptwlhq",100, 0., 1000.);
   TH1D* h3l2b_ttdphi = new TH1D("h3l2b_ttdphi","h3l2b_ttdphi",50, 0., 12.);
   TH1D* h3l2b_dm = new TH1D("h3l2b_dm","h3l2b_dm",46, 0., 460.);
   h2lss1b_mll->Sumw2(); 
   h2lss1b_njet->Sumw2();
   h2lss1b_sumet->Sumw2();
   h2lss1b_dphimin->Sumw2();
   h2lss1b_dphix->Sumw2();
   h2lss1b_mblt->Sumw2();
   h2lss1b_ptblt->Sumw2();
   h2lss1b_mwlh->Sumw2();
   h2lss1b_ptwlh->Sumw2();
   h2lss1b_mwlhq->Sumw2();
   h2lss1b_ptwlhq->Sumw2();
   h2lss1b_ttdphi->Sumw2();
   h2lss1b_dm->Sumw2();
   //
   h2lss2b_mll->Sumw2();
   h2lss2b_njet->Sumw2();
   h2lss2b_sumet->Sumw2();
   h2lss2b_dphimin->Sumw2();
   h2lss2b_dphix->Sumw2();
   h2lss2b_mblt->Sumw2();
   h2lss2b_ptblt->Sumw2();
   h2lss2b_mwlh->Sumw2();
   h2lss2b_ptwlh->Sumw2();
   h2lss2b_mwlhq->Sumw2();
   h2lss2b_ptwlhq->Sumw2();
   h2lss2b_ttdphi->Sumw2();
   h2lss2b_dm->Sumw2();
   //3l
   h3l1b_mll01->Sumw2();
   h3l1b_mll02->Sumw2();
   h3l1b_mlll->Sumw2();
   h3l1b_njet->Sumw2();
   h3l1b_sumet->Sumw2();
   h3l1b_dphimin->Sumw2();
   h3l1b_dphix->Sumw2();
   h3l1b_mblt->Sumw2();
   h3l1b_ptblt->Sumw2();
   h3l1b_mwlh->Sumw2();
   h3l1b_ptwlh->Sumw2();
   h3l1b_mwlhq->Sumw2();
   h3l1b_ptwlhq->Sumw2();
   h3l1b_ttdphi->Sumw2();
   h3l1b_dm->Sumw2();
   //
   h3l2b_mll01->Sumw2();
   h3l2b_mll02->Sumw2();
   h3l2b_mlll->Sumw2();
   h3l2b_njet->Sumw2();
   h3l2b_sumet->Sumw2();
   h3l2b_dphimin->Sumw2();
   h3l2b_dphix->Sumw2();
   h3l2b_mblt->Sumw2();
   h3l2b_ptblt->Sumw2();
   h3l2b_mwlh->Sumw2();
   h3l2b_ptwlh->Sumw2();
   h3l2b_mwlhq->Sumw2();
   h3l2b_ptwlhq->Sumw2();
   h3l2b_ttdphi->Sumw2();
   h3l2b_dm->Sumw2();
   //
   if (fChain == 0) return;
   //TString treename = fChain->GetTree()->GetName();
   //fChain->LoadTree(0);
   //TTree *newtree = fChain->GetTree()->CloneTree(0);
   //newtree->Branch("Mybdt", &myBDT, "Mybdt/D");
   //newtree->Branch("Mybdtx", &myBDTx, "Mybdtx/D");
   //myBDT = -2.;
   //myBDTx = -2.;
   Long64_t nentries = GetNevtAna()>10?GetNevtAna():fChain->GetEntriesFast();
   if(GetNevtAna()>-1)std::cout<<" This is a test run with part of dataset: "<<GetNevtAna()<<" ismc "<<_ismc<<std::endl;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(jentry%1000==0||_debug)std::cout<<" Analysised "<<jentry<<" run "<<Run<<" event "<<Event<<std::endl;

      // job control: control(0); signal(1);
      // if((GetNevtAna()==0) && Evtclass>0 && Njets25>=3)continue; // for  control regions
      //if((GetNevtAna()>0&&GetNevtAna()<3) && Evtclass>0 && Njets25<3)continue; // for signal regions
      //if((GetNevtAna()==3) && Evtclass>0 && Njets25>=5)continue; // for  control regions
      if(_debug)std::cout<<" Debug "<<Run<<" "<<Event<<" class "<<Class<<" njets "<<Njetx<<" nbjets "<<Nbjetx<<std::endl;
      double wtx = Weight;
      TLorentzVector p4lep[20];
      TLorentzVector p4jet[20];
      TLorentzVector p4nu;
      p4nu.SetPtEtaPhiE(Met,0.,Metphi,Met);
      for(int i = 0; i<Nlep; ++i){
	p4lep[i].SetPtEtaPhiE(LepPt->at(i),LepEta->at(i),LepPhi->at(i),LepE->at(i));
      }
      for(int i = 0; i<Njetx; ++i){
	p4jet[i].SetPtEtaPhiE(JetPt->at(i),JetEta->at(i),JetPhi->at(i),JetE->at(i));
      }
      double metjetdphi(99.); // including bjet
      for(int i = 0; i<Njetx; ++i){
	double dphi = fabs(p4nu.DeltaPhi(p4jet[i])); 
	if(dphi<metjetdphi)metjetdphi = dphi;
      }
      double metlepdphi(99.);
      for(int i = 0; i<Nlep; ++i){
	double dphi = fabs(p4nu.DeltaPhi(p4lep[i])); // wmy fix
	if(dphi<metlepdphi)metlepdphi = dphi;
      }
      if(_debug)std::cout<<" finisihing counting dr met vs jet and lep "<<metjetdphi<<" "<<metlepdphi<<std::endl;
      // check 2lss and save the histograms 
      if(Class==1&&LepTrig->at(0)>0&&LepTrig->at(1)>0&&((fabs(LepId->at(0))==11&&LepPlv->at(0)<-0.7&&(_ismc?LepQmis->at(0):LepChargedID->at(0)>0.7))||(fabs(LepId->at(0))==13&&LepPlv->at(0)<-0.5))&&((fabs(LepId->at(1))==11&&LepPlv->at(1)<-0.7&&(_ismc?LepQmis->at(1):LepChargedID->at(0)>0.7))||(fabs(LepId->at(1))==13&&LepPlv->at(1)<-0.5))&&Nljetx>0&&Nbjetx>0){ 
	if(_debug)std::cout<<" Debug "<<" class "<<Class<<" Nbjetx "<<Nbjetx<<std::endl;
	if(Nbjetx==1){ // topfcnc signal
	  h2lss1b_mll->Fill(Mll01/GeV, wtx); 
	  h2lss1b_njet->Fill(Njetx,wtx);
	  h2lss1b_sumet->Fill(Sumljets/GeV, wtx); 
	  h2lss1b_dphimin->Fill(Dphimin, wtx);
	  h2lss1b_dphix->Fill(Dphix, wtx); 
	  h2lss1b_mblt->Fill(Mblt,wtx); // GeV
	  h2lss1b_ptblt->Fill(Ptblt, wtx);
	  h2lss1b_mwlh->Fill(Mwlh,wtx);
	  h2lss1b_ptwlh->Fill(Ptwlh,wtx);
	  h2lss1b_mwlhq->Fill((Mwlhq<280?Mwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h2lss1b_ptwlhq->Fill((Ptwlhq<280?Ptwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
	  h2lss1b_ttdphi->Fill(Ttdphi+4*(Nljetx<4?Nljetx-1:2), wtx);
          h2lss1b_dm->Fill((Dm<140?Dm:139)+150*(Nljetx<4?Nljetx-1:2), wtx);
	}
	else{ // control region   
          h2lss2b_mll->Fill(Mll01/GeV, wtx);
          h2lss2b_njet->Fill(Njetx,wtx);
          h2lss2b_sumet->Fill(Sumljets/GeV, wtx);
          h2lss2b_dphimin->Fill(Dphimin, wtx);
          h2lss2b_dphix->Fill(Dphix, wtx);
          h2lss2b_mblt->Fill(Mblt,wtx);
          h2lss2b_ptblt->Fill(Ptblt, wtx);
          h2lss2b_mwlh->Fill(Mwlh,wtx);
          h2lss2b_ptwlh->Fill(Ptwlh,wtx);
          h2lss2b_mwlhq->Fill((Mwlhq<280?Mwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h2lss2b_ptwlhq->Fill((Ptwlhq<280?Ptwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h2lss2b_ttdphi->Fill(Ttdphi+4*(Nljetx<4?Nljetx-1:2), wtx);
	  h2lss2b_dm->Fill((Dm<140?Dm:139)+150*(Nljetx<4?Nljetx-1:2), wtx);
	}
      }
      if(_debug)std::cout<<" Debug "<<" class "<<Class<<std::endl;
      if(Class==2&&((LepTrig->at(0)>0&&LepTrig->at(1)>0)||(LepTrig->at(0)>0&&LepTrig->at(2)>0)||
		    (LepTrig->at(1)>0&&LepTrig->at(2)>0))&&
	 ((fabs(LepId->at(1))==11&&LepPlv->at(1)<-0.7&&(_ismc?LepQmis->at(1):LepChargedID->at(1)>0.7))||(fabs(LepId->at(1))==13&&LepPlv->at(1)<-0.5))&&
	 ((fabs(LepId->at(2))==11&&LepPlv->at(2)<-0.7&&(_ismc?LepQmis->at(2):LepChargedID->at(2)>0.7))||(fabs(LepId->at(2))==13&&LepPlv->at(2)<-0.5))&&
	 Nljetx>0&&Nbjetx>0&&(abs(LepId->at(0))!=abs(LepId->at(1))||(abs(LepId->at(0))==abs(LepId->at(1))&&fabs(Mll01/GeV-91)>10))&&
	 (abs(LepId->at(0))!=abs(LepId->at(2))||(abs(LepId->at(0))==abs(LepId->at(2))&&fabs(Mll02/GeV-91)>10))
	 &&Mll01/GeV>12&&Mll02/GeV>12){
	if(_debug)std::cout<<" Debug "<<" class "<<Class<<" Nbjetx "<<Nbjetx<<std::endl;
	if(Nbjetx==1){
          h3l1b_mll01->Fill(Mll01/GeV, wtx);
          h3l1b_mll02->Fill(Mll02/GeV, wtx);
          h3l1b_mlll->Fill(Mlll012/GeV, wtx);
          h3l1b_njet->Fill(Njetx,wtx);
          h3l1b_sumet->Fill(Sumljets/GeV, wtx);
          h3l1b_dphimin->Fill(Dphimin, wtx);
          h3l1b_dphix->Fill(Dphix, wtx);
          h3l1b_mblt->Fill(Mblt,wtx);
          h3l1b_ptblt->Fill(Ptblt, wtx);
          h3l1b_mwlh->Fill(Mwlh,wtx);
          h3l1b_ptwlh->Fill(Ptwlh,wtx);
          h3l1b_mwlhq->Fill((Mwlhq<280?Mwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h3l1b_ptwlhq->Fill((Ptwlhq<280?Ptwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h3l1b_ttdphi->Fill(Ttdphi+4*(Nljetx<4?Nljetx-1:2), wtx);
          h3l1b_dm->Fill((Dm<140?Dm:139)+150*(Nljetx<4?Nljetx-1:2), wtx);
	}
	else{
          h3l2b_mll01->Fill(Mll01/GeV, wtx);
          h3l2b_mll02->Fill(Mll02/GeV, wtx);
          h3l2b_mlll->Fill(Mlll012/GeV, wtx);
          h3l2b_njet->Fill(Njetx,wtx);
          h3l2b_sumet->Fill(Sumljets/GeV, wtx);
          h3l2b_dphimin->Fill(Dphimin, wtx);
          h3l2b_dphix->Fill(Dphix, wtx);
          h3l2b_mblt->Fill(Mblt,wtx);
          h3l2b_ptblt->Fill(Ptblt, wtx);
          h3l2b_mwlh->Fill(Mwlh,wtx);
          h3l2b_ptwlh->Fill(Ptwlh,wtx);
          h3l2b_mwlhq->Fill((Mwlhq<280?Mwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h3l2b_ptwlhq->Fill((Ptwlhq<280?Ptwlhq:279)+300*(Nljetx<4?Nljetx-1:2), wtx);
          h3l2b_ttdphi->Fill(Ttdphi+4*(Nljetx<4?Nljetx-1:2), wtx);
          h3l2b_dm->Fill((Dm<140?Dm:139)+150*(Nljetx<4?Nljetx-1:2), wtx);
	}
      }
      if(_debug)std::cout<<" Debug "<<" finished  for Run "<<Run<<" event "<<Event<<std::endl;
      //
   }
   _histf->cd();
   _histf->Write();
   _histf->Close();
}
