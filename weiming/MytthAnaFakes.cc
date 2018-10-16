#define MytthAnaFakes_cxx
#include "MytthAnaFakes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "BDTcalculation.h"
const double btagwpCut[4]={0.94,0.83,0.64,0.11}; // 60, 70, 77, 85 % (0.8244273); // 0.645925 77% for MV2c10; 70% 0.8244273   
// tight muon: &&((abs(lep_ID_0)==13 && lep_isolationFixedCutLoose_0 && lep_promptLeptonVeto_TagWeight_0<-0.5)
// tight electron: (abs(lep_ID_0)==11 && lep_isolationFixedCutLoose_0 && lep_isTightLH_0 && lep_chargeIDBDTTight_0>0.7 && lep_ambiguityType_0 == 0 
//                 && lep_promptLeptonVeto_TagWeight_0<-0.7)) 

void MytthAnaFakes::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MytthAnaSkim.C
//      root> MytthAnaSkim t
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
// To study fake leptons: 
//   Conversion: data vs MC 
//   QmisID:  
//   HF jets: 
//  trilep_type: mumumu(1); mumue(2); muee(3); eee(4)
//  dilep_type: mumu(1); emu(2); ee(3); 
   
   int GeV(1000);
   double FaketauSF[4]={1.07, 1.03, 0.998, 0.681}; //{1.22,1.13,0.83,0.92}; v2901
   double qmisRate[6][16];
   double xbins[5]={0.,20.,30.,40.,60.}; // mu 

   //bool dump(true);
   bool debug(false);
   debug = _debug>0;
   // obtain the qmis rate
   TFile* file = new TFile("/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/EPS/25ns_R21Skim/data17/Hqmis/SinglePlot/Plots_qmisRate_summary.root","read");
   TString idname[2]={"data","mc"};
   TString ctname[3]={"","ct","loose"};
   TString etaname[4]={"eta0","eta1","eta2","eta3"};
   for(int kid=0; kid<2; ++kid){
     for(int kct=0; kct<3; ++kct){
       int ix = kct+kid*3;
       for(int keta=0; keta<4; ++keta){
         TH1F* h =(TH1F*)file->Get("hrqmis"+idname[kid]+ctname[kct]+etaname[keta])->Clone();
         for(int kpt=0; kpt<4; ++kpt){
           qmisRate[ix][kpt+4*keta]=h->GetBinContent(kpt+1);
         }
       }
     }
   }
   file->Close();
  //histf = new TFile(_outhist+".root", "RECREATE");
   _histf->cd();
   initialiseOutNtp(); // making ttree of tnp
   std::ofstream* fout_txt(0);
   if(debug)fout_txt = new std::ofstream(_outhist+".txt");
   TString BDT_tth1l2tau = "/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/makingPlots/MakingMini/TMVAClassification_BDTG.weightsv2901var7taupt25Triglept27tauTMnobtag_capnjets5nbjets3.xml";
   std::cout<<" which BDT ? "<<BDT_tth1l2tau<<std::endl;
   initialiseTMVA_tth1l2tau(BDT_tth1l2tau);
   // Booking here: 
   //TH1F*
   // z->mumu gamma 
   TH1F* hmet = new TH1F("hmet","hmet",40, 0., 200.); 
   TH1F* hmt = new TH1F("hmt","hmt", 40, 0., 200.);
   TH1F* hnbjets = new TH1F("hnbjets","hnbjets", 5, 0., 5.);
   TH1F* hnjets = new TH1F("hnjets","hnjets", 10, 0., 10.);
   TH1F* hmmumu = new TH1F("hmmumu","hmmumu", 50, 0., 150.); 
   TH1F* hmmumue = new TH1F("hmmumue","hmmumue", 50, 0., 150.); 
   TH1F* hconorig = new TH1F("hconorig","hconorig", 50, 0., 50.); 
   TH1F* hplicon = new TH1F("hplicon", "hplicon", 40, -2., 2.);
   TH1F* hplivcon = new TH1F("hplivcon", "hplivcon", 40, -2., 2.);
   TH1F* hdrlcon = new TH1F("hdrlcon","hdrlcon",25, 0., 5.); //new
   TH1F* hpliconTruth = new TH1F("hpliconTruth", "hpliconTruth", 40, -2., 2.);
   TH1F* hplivconTruth = new TH1F("hplivconTruth", "hplivconTruth", 40, -2., 2.);
   TH1F* hptcon = new TH1F("hptcon", "hptcon", 10, 0., 100.); 
   TH1F* hptconTruth = new TH1F("hptconTruth", "hptconTruth", 10, 0., 100.); 
   TH1F* hptfcon = new TH1F("hptfcon", "hptfcon", 10, 0., 100.); 
   TH1F* hptfconTruth = new TH1F("hptfconTruth", "hptfconTruth", 10, 0., 100.); 
   TH1F* hmmumuB = new TH1F("hmmumuB","hmmumuB", 50, 0., 150.); 
   TH1F* hmmumueB = new TH1F("hmmumueB","hmmumueB", 50, 0., 150.); 
   TH1F* hconorigB = new TH1F("hconorigB","hconorigB", 50, 0., 50.); 
   TH1F* hpliconB = new TH1F("hpliconB", "hpliconB", 40, -2., 2.);
   TH1F* hpliconTruthB = new TH1F("hpliconTruthB", "hpliconTruthB", 40, -2., 2.);
   TH1F* hplivconB = new TH1F("hplivconB", "hplivconB", 40, -2., 2.);
   TH1F* hplivconTruthB = new TH1F("hplivconTruthB", "hplivconTruthB", 40, -2., 2.);
   TH1F* hptconB = new TH1F("hptconB", "hptconB", 10, 0., 100.); 
   TH1F* hptconTruthB = new TH1F("hptconTruthB", "hptconTruthB", 10, 0., 100.); 
   TH1F* hptfconB = new TH1F("hptfconB", "hptfconB", 10, 0., 100.); 
   TH1F* hptfconTruthB = new TH1F("hptfconTruthB", "hptfconTruthB", 10, 0., 100.); 
   TH1F* hdrej = new TH1F("hdrej","hdrej", 25, 0.,5.);
   TH1F* hptratioej = new TH1F("hptratioej","hptratioej", 50, 0., 5.);
   TH1F* hemfej = new TH1F("hemfej","hemfej", 40, 0., 2.0);
   TH1F* hntrkej = new TH1F("hntrkej","hntrkej", 10, 0., 10.);
   TH1F* hsumptej = new TH1F("hsumptej","hsumptej", 50, 0., 100.);
   TH1F* hsumptet = new TH1F("hsumptet","hsumptet", 20, 0., 1.);//new
   TH1F* hetacon = new TH1F("hetacon", "hetacon", 6, 0., 3.0);
   TH1F* hetafcon = new TH1F("hetafcon", "hetafcon", 6, 0., 3.0);
   // eee
   TH1F* hmee = new TH1F("hmee","hmee", 50, 0., 150.);
   TH1F* hmeee = new TH1F("hmeee","hmeee", 50, 0., 150.);
   TH1F* hconorig3e = new TH1F("hconorig3e","hconorig3e", 50, 0., 50.);
   TH1F* hplicon3e = new TH1F("hplicon3e", "hplicon3e", 40, -2., 2.);
   TH1F* hdrlcon3e = new TH1F("hdrlcon3e","hdrlcon3e",25, 0., 5.); 
   TH1F* hpliconTruth3e = new TH1F("hpliconTruth3e", "hpliconTruth3e", 40, -2., 2.);
   TH1F* hptcon3e = new TH1F("hptcon3e", "hptcon3e", 10, 0., 100.);
   TH1F* hptconTruth3e = new TH1F("hptconTruth3e", "hptconTruth3e", 10, 0., 100.);
   TH1F* hptfcon3e = new TH1F("hptfcon3e", "hptfcon3e", 10, 0., 100.);
   TH1F* hptfconTruth3e = new TH1F("hptfconTruth3e", "hptfconTruth3e", 10, 0., 100.);
   TH1F* hetacon3e = new TH1F("hetacon3e", "hetacon3e", 6, 0., 3.0);
   TH1F* hetafcon3e = new TH1F("hetafcon3e", "hetafcon3e", 6, 0., 3.0);
   // april 17 
   TH1F* hfconorig = new TH1F("hfconorig","hfconorig", 50, 0., 50.);
   TH1F* hfconorigB = new TH1F("hfconorigB","hfconorigB", 50, 0., 50.);
   TH1F* hfconorig3e = new TH1F("hfconorig3e","hfconorig3e", 50, 0., 50.);
   hmet->Sumw2();
   hmt->Sumw2();
   hnbjets->Sumw2();
   hnjets->Sumw2();
   hmmumu->Sumw2();
   hmmumue->Sumw2();
   hconorig->Sumw2();
   hplicon->Sumw2();
   hplivcon->Sumw2();
   hdrlcon->Sumw2();
   hpliconTruth->Sumw2();
   hplivconTruth->Sumw2();
   hptcon->Sumw2();
   hptconTruth->Sumw2();
   hptfcon->Sumw2();
   hptfconTruth->Sumw2();
   hmmumuB->Sumw2();
   hmmumueB->Sumw2();
   hconorigB->Sumw2();
   hpliconB->Sumw2();
   hpliconTruthB->Sumw2();
   hplivconB->Sumw2();
   hplivconTruthB->Sumw2();
   hptconB->Sumw2();
   hptconTruthB->Sumw2();
   hptfconB->Sumw2();
   hptfconTruthB->Sumw2();   
   hdrej->Sumw2();
   hptratioej->Sumw2();
   hemfej->Sumw2();
   hntrkej->Sumw2();
   hsumptej->Sumw2();
   hsumptet->Sumw2();
   hetacon->Sumw2();
   hetafcon->Sumw2();
   //
   hmee->Sumw2();
   hmeee->Sumw2();
   hconorig3e->Sumw2();
   hplicon3e->Sumw2();
   hdrlcon3e->Sumw2();
   hpliconTruth3e->Sumw2();
   hptcon3e->Sumw2();
   hptconTruth3e->Sumw2();
   hptfcon3e->Sumw2();
   hptfconTruth3e->Sumw2();
   hetacon3e->Sumw2();
   hetafcon3e->Sumw2();
   hfconorig->Sumw2();
   hfconorigB->Sumw2();
   hfconorig3e->Sumw2();
   // QmisID 
   TH1F* hmet2ess = new TH1F("hmet2ess","hmet2ess",40, 0., 200.); 
   TH1F* hnbjets2ess = new TH1F("hnbjets2ess","hnbjets2ess", 5, 0., 5.);
   TH1F* hm2ess = new TH1F("hm2ess","hm2ess",50, 0., 150.);
   TH1F* hnjets2ess = new TH1F("hnjets2ess","hnjets2ess", 10, 0., 10.);
   TH1F* hm2esscut = new TH1F("hm2esscut","hm2esscut",50, 0., 150.);
   TH1F* hm2essctcut = new TH1F("hm2essctcut","hm2essctcut",50, 0., 150.); // new
   TH2F* h2d2ess = new TH2F("h2d2ess","h2d2ess",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2essct = new TH2F("h2d2essct","h2d2essct",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2essb = new TH2F("h2d2essb","h2d2essb",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2essbct = new TH2F("h2d2essbct","h2d2essbct",16,0.,16.,16,0.,16.); // new
   TH1F* hnjets2esscut = new TH1F("hnjets2esscut","hnjets2esscut", 10, 0., 10.);
   TH1F* heta2ess = new TH1F("heta2ess","heta2ess",4,0., 2.8); 
   TH1F* hpt2ess = new TH1F("hpt2ess","hpt2ess", 3, 20., 140.); 
   TH1F* heta2essb = new TH1F("heta2essb","heta2essb",4,0., 2.8); 
   TH1F* hpt2essb = new TH1F("hpt2essb","hpt2essb", 3, 20., 140.); 
   hmet2ess->Sumw2();
   hnbjets2ess->Sumw2();
   hm2ess->Sumw2();
   hnjets2ess->Sumw2();
   hm2esscut->Sumw2();
   hm2essctcut->Sumw2();
   h2d2ess->Sumw2();
   h2d2essct->Sumw2();
   h2d2essb->Sumw2();
   h2d2essbct->Sumw2();
   hnjets2esscut->Sumw2(); 
   heta2ess->Sumw2();
   hpt2ess->Sumw2();
   heta2essb->Sumw2();
   hpt2essb->Sumw2();
   // qmis loose april 5
   TH1F* hmet2eloosess = new TH1F("hmet2eloosess","hmet2eloosess",40, 0., 200.);
   TH1F* hnbjets2eloosess = new TH1F("hnbjets2eloosess","hnbjets2eloosess", 5, 0., 5.);
   TH1F* hm2eloosess = new TH1F("hm2eloosess","hm2eloosess",50, 0., 150.);
   TH1F* hnjets2eloosess = new TH1F("hnjets2eloosess","hnjets2eloosess", 10, 0., 10.);
   TH1F* hm2eloosesscut = new TH1F("hm2eloosesscut","hm2eloosesscut",50, 0., 150.);
   TH1F* hm2eloosessctcut = new TH1F("hm2eloosessctcut","hm2eloosessctcut",50, 0., 150.); // new
   TH2F* h2d2eloosess = new TH2F("h2d2eloosess","h2d2eloosess",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2eloosessct = new TH2F("h2d2eloosessct","h2d2eloosessct",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2eloosessb = new TH2F("h2d2eloosessb","h2d2eloosessb",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2eloosessbct = new TH2F("h2d2eloosessbct","h2d2eloosessbct",16,0.,16.,16,0.,16.); // new
   TH1F* hnjets2eloosesscut = new TH1F("hnjets2eloosesscut","hnjets2eloosesscut", 10, 0., 10.);
   TH1F* heta2eloosess = new TH1F("heta2eloosess","heta2eloosess",4,0., 2.8);
   TH1F* hpt2eloosess = new TH1F("hpt2eloosess","hpt2eloosess", 3, 20., 140.);
   TH1F* heta2eloosessb = new TH1F("heta2eloosessb","heta2eloosessb",4,0., 2.8);
   TH1F* hpt2eloosessb = new TH1F("hpt2eloosessb","hpt2eloosessb", 3, 20., 140.);
   hmet2eloosess->Sumw2();
   hnbjets2eloosess->Sumw2();
   hm2eloosess->Sumw2();
   hnjets2eloosess->Sumw2();
   hm2eloosesscut->Sumw2();
   hm2eloosessctcut->Sumw2();
   h2d2eloosess->Sumw2();
   h2d2eloosessct->Sumw2();
   h2d2eloosessb->Sumw2();
   h2d2eloosessbct->Sumw2();
   hnjets2eloosesscut->Sumw2();
   heta2eloosess->Sumw2();
   hpt2eloosess->Sumw2();
   heta2eloosessb->Sumw2();
   hpt2eloosessb->Sumw2();
   // mumuss 
   TH1F* hmet2mussq = new TH1F("hmet2mussq","hmet2mussq",40, 0., 200.); 
   TH1F* hnbjets2mussq = new TH1F("hnbjets2mussq","hnbjets2mussq", 5, 0., 5.);
   TH1F* hm2mussq = new TH1F("hm2mussq","hm2mussq",50, 0., 150.);
   TH1F* hnjets2mussq = new TH1F("hnjets2mussq","hnjets2mussq", 10, 0., 10.);
   TH1F* hm2mussqcut = new TH1F("hm2mussqcut","hm2mussqcut",50, 0., 150.);
   TH1F* hnjets2mussqcut = new TH1F("hnjets2mussqcut","hnjets2mussqcut", 10, 0., 10.);
   TH1F* heta2mussq = new TH1F("heta2mussq","heta2mussq",4,0., 2.8); 
   TH1F* hpt2mussq = new TH1F("hpt2mussq","hpt2mussq", 3, 20., 140.); 
   TH1F* heta2mussqb = new TH1F("heta2mussqb","heta2mussqb",4,0., 2.8); 
   TH1F* hpt2mussqb = new TH1F("hpt2mussqb","hpt2mussqb", 3, 20., 140.); 
   hmet2mussq->Sumw2();
   hnbjets2mussq->Sumw2();
   hm2mussq->Sumw2();
   hnjets2mussq->Sumw2();
   hm2mussqcut->Sumw2();
   hnjets2mussqcut->Sumw2(); 
   heta2mussq->Sumw2();
   hpt2mussq->Sumw2();
   heta2mussqb->Sumw2();
   hpt2mussqb->Sumw2();
   //2eos
   TH1F* hmet2eos = new TH1F("hmet2eos","hmet2eos",40, 0., 200.); 
   TH1F* hnbjets2eos = new TH1F("hnbjets2eos","hnbjets2eos", 5, 0., 5.);
   TH1F* hm2eos = new TH1F("hm2eos","hm2eos",50, 0., 150.);
   TH1F* hnjets2eos = new TH1F("hnjets2eos","hnjets2eos", 10, 0., 10.);
   TH1F* hm2eoscut = new TH1F("hm2eoscut","hm2eoscut",50, 0., 150.);
   TH1F* hm2eosctcut = new TH1F("hm2eosctcut","hm2eosctcut",50, 0., 150.); // new
   TH2F* h2d2eos = new TH2F("h2d2eos","h2d2eos",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2eosct = new TH2F("h2d2eosct","h2d2eosct",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2eosb = new TH2F("h2d2eosb","h2d2eosb",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2eosbct = new TH2F("h2d2eosbct","h2d2eosbct",16,0.,16.,16,0.,16.); // new
   TH1F* hnjets2eoscut = new TH1F("hnjets2eoscut","hnjets2eoscut", 10, 0., 10.);
   TH1F* heta2eos = new TH1F("heta2eos","heta2eos",4,0., 2.8); 
   TH1F* hpt2eos = new TH1F("hpt2eos","hpt2eos", 3, 20., 140.); 
   TH1F* heta2eosb = new TH1F("heta2eosb","heta2eosb",4,0., 2.8); 
   TH1F* hpt2eosb = new TH1F("hpt2eosb","hpt2eosb", 3, 20., 140.); 
   // ee+ej new 2-20-2018
   TH1F* hm2eosxg = new TH1F("hm2eosxg","hm2eosxg",50, 0., 150.);
   TH1F* hm2eosgamma = new TH1F("hm2eosgamma","hm2eosgamma",50, 0., 150.);
   TH1F* hm2eosgmatched = new TH1F("hm2eosgmatched","hm2eosgmatched",50, 0., 150.);
   TH1F* hphpt2eos = new TH1F("hphpt2eos","hphpt2eos",50, 0., 250.);
   TH1F* hphdr2eos = new TH1F("hphdr2eos","hphdr2eos",25, 0., 5.); // new
   TH1F* hphpt2eosmatched = new TH1F("hphpt2eosmatched","hphpt2eosmatched",50, 0., 250.);
   TH1F* hnph2eos = new TH1F("hnph2eos","hnph2eos",10, 0., 10.);
   TH1F* hm2eosele = new TH1F("hm2eosele","hm2eosele",50, 0., 150.); //new 
   TH1F* h2ephsumpt = new TH1F("h2ephsumpt","h2ephsumpt",50,0.,100.); //new
   TH1F* h2ephsumptet = new TH1F("h2ephsumptet","h2ephsumptet",20,0.,1.); //new
   TH1F* hept2eos = new TH1F("hept2eos","hept2eos",50, 0., 250.); //new
   TH1F* hedr2eos = new TH1F("hedr2eos","hedr2eos",25, 0., 5.); // new 
   TH1F* h2ephsumptmatched = new TH1F("h2ephsumptmatched","h2ephsumptmatched",50,0.,100.); //new
   TH1F* h2ephsumptetmatched = new TH1F("h2ephsumptetmatched","h2ephsumptetmatched",20,0.,1.); //new
   TH1F* hm2eosematched = new TH1F("hm2eosematched","hm2eosematched",50, 0., 150.);//new
   TH1F* hept2eosmatched = new TH1F("hept2eosmatched","hept2eosmatched",50, 0., 250.);//new
   hmet2eos->Sumw2();
   hnbjets2eos->Sumw2();
   hm2eos->Sumw2();
   hnjets2eos->Sumw2();
   hm2eoscut->Sumw2();
   hm2eosctcut->Sumw2();
   h2d2eos->Sumw2();
   h2d2eosct->Sumw2();
   h2d2eosb->Sumw2();
   h2d2eosbct->Sumw2();
   hnjets2eoscut->Sumw2();
   heta2eos->Sumw2();
   hpt2eos->Sumw2();
   heta2eosb->Sumw2();
   hpt2eosb->Sumw2();
   //
   hm2eosxg->Sumw2();
   hm2eosgamma->Sumw2();
   hm2eosgmatched->Sumw2();
   hphpt2eos->Sumw2();
   hphdr2eos->Sumw2();
   hphpt2eosmatched->Sumw2();
   hnph2eos->Sumw2();
   hm2eosele->Sumw2();
   h2ephsumpt->Sumw2();
   h2ephsumptet->Sumw2();
   hept2eos->Sumw2();
   hedr2eos->Sumw2();
   h2ephsumptmatched->Sumw2();
   h2ephsumptetmatched->Sumw2();
   hm2eosematched->Sumw2();
   hept2eosmatched->Sumw2();
   // os ee loose April 5
   TH1F* hmet2elooseos = new TH1F("hmet2elooseos","hmet2elooseos",40, 0., 200.);
   TH1F* hnbjets2elooseos = new TH1F("hnbjets2elooseos","hnbjets2elooseos", 5, 0., 5.);
   TH1F* hm2elooseos = new TH1F("hm2elooseos","hm2elooseos",50, 0., 150.);
   TH1F* hnjets2elooseos = new TH1F("hnjets2elooseos","hnjets2elooseos", 10, 0., 10.);
   TH1F* hm2elooseoscut = new TH1F("hm2elooseoscut","hm2elooseoscut",50, 0., 150.);
   TH1F* hm2elooseosctcut = new TH1F("hm2elooseosctcut","hm2elooseosctcut",50, 0., 150.); // new
   TH2F* h2d2elooseos = new TH2F("h2d2elooseos","h2d2elooseos",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2elooseosct = new TH2F("h2d2elooseosct","h2d2elooseosct",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2elooseosb = new TH2F("h2d2elooseosb","h2d2elooseosb",16,0.,16.,16,0.,16.); // new
   TH2F* h2d2elooseosbct = new TH2F("h2d2elooseosbct","h2d2elooseosbct",16,0.,16.,16,0.,16.); // new
   TH1F* hnjets2elooseoscut = new TH1F("hnjets2elooseoscut","hnjets2elooseoscut", 10, 0., 10.);
   TH1F* heta2elooseos = new TH1F("heta2elooseos","heta2elooseos",4,0., 2.8);
   TH1F* hpt2elooseos = new TH1F("hpt2elooseos","hpt2elooseos", 3, 20., 140.);
   TH1F* heta2elooseosb = new TH1F("heta2elooseosb","heta2elooseosb",4,0., 2.8);
   TH1F* hpt2elooseosb = new TH1F("hpt2elooseosb","hpt2elooseosb", 3, 20., 140.);
   TH1F* hm2elooseosxg = new TH1F("hm2elooseosxg","hm2elooseosxg",50, 0., 150.);
   TH1F* hm2elooseosgamma = new TH1F("hm2elooseosgamma","hm2elooseosgamma",50, 0., 150.);
   TH1F* hm2elooseosgmatched = new TH1F("hm2elooseosgmatched","hm2elooseosgmatched",50, 0., 150.);
   TH1F* hphpt2elooseos = new TH1F("hphpt2elooseos","hphpt2elooseos",50, 0., 250.);
   TH1F* hphdr2elooseos = new TH1F("hphdr2elooseos","hphdr2elooseos",25, 0., 5.); // new
   TH1F* hphpt2elooseosmatched = new TH1F("hphpt2elooseosmatched","hphpt2elooseosmatched",50, 0., 250.);
   TH1F* hnph2elooseos = new TH1F("hnph2elooseos","hnph2elooseos",10, 0., 10.);
   TH1F* hm2elooseosele = new TH1F("hm2elooseosele","hm2elooseosele",50, 0., 150.); //new
   TH1F* h2eloosephsumpt = new TH1F("h2eloosephsumpt","h2eloosephsumpt",50,0.,100.); //new
   TH1F* h2eloosephsumptet = new TH1F("h2eloosephsumptet","h2eloosephsumptet",20,0.,1.); //new
   TH1F* hept2elooseos = new TH1F("hept2elooseos","hept2elooseos",50, 0., 250.); //new
   TH1F* hedr2elooseos = new TH1F("hedr2elooseos","hedr2elooseos",25, 0., 5.); // new
   TH1F* h2eloosephsumptmatched = new TH1F("h2eloosephsumptmatched","h2eloosephsumptmatched",50,0.,100.); //new
   TH1F* h2eloosephsumptetmatched = new TH1F("h2eloosephsumptetmatched","h2eloosephsumptetmatched",20,0.,1.); //new
   TH1F* hm2elooseosematched = new TH1F("hm2elooseosematched","hm2elooseosematched",50, 0., 150.);//new
   TH1F* hept2elooseosmatched = new TH1F("hept2elooseosmatched","hept2elooseosmatched",50, 0., 250.);//new
   hmet2elooseos->Sumw2();
   hnbjets2elooseos->Sumw2();
   hm2elooseos->Sumw2();
   hnjets2elooseos->Sumw2();
   hm2elooseoscut->Sumw2();
   hm2elooseosctcut->Sumw2();
   h2d2elooseos->Sumw2();
   h2d2elooseosct->Sumw2();
   h2d2elooseosb->Sumw2();
   h2d2elooseosbct->Sumw2();
   hnjets2elooseoscut->Sumw2();
   heta2elooseos->Sumw2();
   hpt2elooseos->Sumw2();
   heta2elooseosb->Sumw2();
   hpt2elooseosb->Sumw2();
   //
   hm2elooseosxg->Sumw2();
   hm2elooseosgamma->Sumw2();
   hm2elooseosgmatched->Sumw2();
   hphpt2elooseos->Sumw2();
   hphdr2elooseos->Sumw2();
   hphpt2elooseosmatched->Sumw2();
   hnph2elooseos->Sumw2();
   hm2elooseosele->Sumw2();
   h2eloosephsumpt->Sumw2();
   h2eloosephsumptet->Sumw2();
   hept2elooseos->Sumw2();
   hedr2elooseos->Sumw2();
   h2eloosephsumptmatched->Sumw2();
   h2eloosephsumptetmatched->Sumw2();
   hm2elooseosematched->Sumw2();
   hept2elooseosmatched->Sumw2();
   // os mumu 
   TH1F* hmet2muos = new TH1F("hmet2muos","hmet2muos",40, 0., 200.); 
   TH1F* hnbjets2muos = new TH1F("hnbjets2muos","hnbjets2muos", 5, 0., 5.);
   TH1F* hm2muos = new TH1F("hm2muos","hm2muos",50, 0., 150.);
   TH1F* hnjets2muos = new TH1F("hnjets2muos","hnjets2muos", 10, 0., 10.);
   TH1F* hm2muoscut = new TH1F("hm2muoscut","hm2muoscut",50, 0., 150.);
   TH1F* hnjets2muoscut = new TH1F("hnjets2muoscut","hnjets2muoscut", 10, 0., 10.);
   TH1F* heta2muos = new TH1F("heta2muos","heta2muos",4,0., 2.8); 
   TH1F* hpt2muos = new TH1F("hpt2muos","hpt2muos", 3, 20., 140.); 
   TH1F* heta2muosb = new TH1F("heta2muosb","heta2muosb",4,0., 2.8); 
   TH1F* hpt2muosb = new TH1F("hpt2muosb","hpt2muosb", 3, 20., 140.); 
   TH1F* hmephpt2muos = new TH1F("hmephpt2muos","hmephpt2muos",50, 0., 250.); 
   TH1F* hm2muosx = new TH1F("hm2muosx","hm2muosx",50, 0., 150.);
   TH1F* hm2muosxg = new TH1F("hm2muosxg","hm2muosxg",50, 0., 150.);
   TH1F* hm2muosgamma = new TH1F("hm2muosgamma","hm2muosgamma",50, 0., 150.);
   TH1F* hm2muosgmatched = new TH1F("hm2muosgmatched","hm2muosgmatched",50, 0., 150.);
   TH1F* hphpt2muos = new TH1F("hphpt2muos","hphpt2muos",50, 0., 250.);
   TH1F* hphdr2muos = new TH1F("hphdr2muos","hphdr2muos",25, 0., 5.); // new 
   TH1F* hphpt2muosmatched = new TH1F("hphpt2muosmatched","hphpt2muosmatched",50, 0., 250.);
   TH1F* hnph2muos = new TH1F("hnph2muos","hnph2muos",10, 0., 10.);
   TH1F* hm2muosele = new TH1F("hm2muosele","hm2muosele",50, 0., 150.); //new 
   TH1F* hphsumpt = new TH1F("hphsumpt","hphsumpt",50,0.,100.); //new
   TH1F* hphsumptet = new TH1F("hphsumptet","hphsumptet",20,0.,1.); //new
   TH1F* hept2muos = new TH1F("hept2muos","hept2muos",50, 0., 250.); //new
   TH1F* hedr2muos = new TH1F("hedr2muos","hedr2muos",25, 0., 5.); // new
   TH1F* hphsumptmatched = new TH1F("hphsumptmatched","hphsumptmatched",50,0.,100.); //new
   TH1F* hphsumptetmatched = new TH1F("hphsumptetmatched","hphsumptetmatched",20,0.,1.); //new
   TH1F* hm2muosematched = new TH1F("hm2muosematched","hm2muosematched",50, 0., 150.);//new
   TH1F* hept2muosmatched = new TH1F("hept2muosmatched","hept2muosmatched",50, 0., 250.);//new
   hmet2muos->Sumw2();
   hnbjets2muos->Sumw2();
   hm2muos->Sumw2();
   hnjets2muos->Sumw2();
   hm2muoscut->Sumw2();
   hnjets2muoscut->Sumw2();
   heta2muos->Sumw2();
   hpt2muos->Sumw2();
   heta2muosb->Sumw2();
   hpt2muosb->Sumw2();
   hmephpt2muos->Sumw2();
   hm2muosx->Sumw2();
   hm2muosxg->Sumw2();
   hm2muosgamma->Sumw2();
   hm2muosgmatched->Sumw2();
   hphpt2muos->Sumw2();
   hphdr2muos->Sumw2();
   hphpt2muosmatched->Sumw2();
   hnph2muos->Sumw2();
   hm2muosele->Sumw2();
   hphsumpt->Sumw2();
   hphsumptet->Sumw2();
   hept2muos->Sumw2();
   hedr2muos->Sumw2();
   hphsumptmatched->Sumw2();
   hphsumptetmatched->Sumw2();
   hm2muosematched->Sumw2();
   hept2muosmatched->Sumw2();
   // muon fakes from dilep 2muss   
   TH1F* hmet2muss = new TH1F("hmet2muss","hmet2muss",40, 0., 200.); 
   TH1F* hmt2muss = new TH1F("hmt2muss","hmt2muss", 40, 0., 200.);
   TH1F* hnbjets2muss = new TH1F("hnbjets2muss","hnbjets2muss", 5, 0., 5.);
   TH1F* hnjets2muss = new TH1F("hnjets2muss","hnjets2muss", 10, 0., 10.);
   TH1F* hmhadw2muss = new TH1F("hmhadw2muss","hmhadw2muss",50, 0., 150.);
   TH1F* hmuorig = new TH1F("hmuorig","hmuorig", 50, 0., 50.); 
   TH1F* hplimu = new TH1F("hplimu", "hplimu", 40, -2., 2.);
   TH1F* hplimuTruth = new TH1F("hplimuTruth", "hplimuTruth", 40, -2., 2.);
   TH1F* hplivmu = new TH1F("hplivmu", "hplivmu", 40, -2., 2.);
   TH1F* hplivmuTruth = new TH1F("hplivmuTruth", "hplivmuTruth", 40, -2., 2.);
   TH1F* hptmu = new TH1F("hptmu", "hptmu", 10, 0., 100.); 
   TH1F* hptmuTruth = new TH1F("hptmuTruth", "hptmuTruth", 10, 0., 100.); 
   TH1F* hdrmu = new TH1F("hdrmu","hdrmu",10, 0., 5.);
   TH1F* hdrmuTruth = new TH1F("hdrmuTruth","hdrmuTruth",10, 0., 5.);
   TH1F* hdrmulpt = new TH1F("hdrmulpt","hdrmulpt",10, 0., 5.);
   TH1F* hdrmulptTruth = new TH1F("hdrmulptTruth","hdrmulptTruth",10, 0., 5.);
   TH1F* hdrmuhpt = new TH1F("hdrmuhpt","hdrmuhpt",10, 0., 5.);
   TH1F* hdrmuhptTruth = new TH1F("hdrmuhptTruth","hdrmuhptTruth",10, 0., 5.);
   TH1F* hptfmu = new TH1F("hptfmu", "hptfmu", 10, 0., 100.); 
   TH1F* hptfmuTruth = new TH1F("hptfmuTruth", "hptfmuTruth", 10, 0., 100.); 
   TH1F* hdrfmu = new TH1F("hdrfmu","hdrfmu",10, 0., 5.);
   TH1F* hdrfmuTruth = new TH1F("hdrfmuTruth","hdrfmuTruth",10, 0., 5.);
   TH1F* hdrfmulpt = new TH1F("hdrfmulpt","hdrfmulpt",10, 0., 5.);
   TH1F* hdrfmulptTruth = new TH1F("hdrfmulptTruth","hdrfmulptTruth",10, 0., 5.);
   TH1F* hdrfmuhpt = new TH1F("hdrfmuhpt","hdrfmuhpt",10, 0., 5.);
   TH1F* hdrfmuhptTruth = new TH1F("hdrfmuhptTruth","hdrfmuhptTruth",10, 0., 5.);
   TH1F* hmuorigX = new TH1F("hmuorigX","hmuorigX", 50, 0., 50.); 
   TH1F* hplimuX = new TH1F("hplimuX", "hplimuX", 40, -2., 2.);
   TH1F* hplimuXTruth = new TH1F("hplimuXTruth", "hplimuXTruth", 40, -2., 2.);
   TH1F* hplivmuX = new TH1F("hplivmuX", "hplivmuX", 40, -2., 2.);
   TH1F* hplivmuXTruth = new TH1F("hplivmuXTruth", "hplivmuXTruth", 40, -2., 2.);
   TH1F* hptmuX = new TH1F("hptmuX", "hptmuX", 10, 0., 100.); 
   TH1F* hptmuXTruth = new TH1F("hptmuXTruth", "hptmuXTruth", 10, 0., 100.); 
   TH1F* hdrmuX = new TH1F("hdrmuX","hdrmuX",10, 0., 5.);
   TH1F* hdrmuXTruth = new TH1F("hdrmuXTruth","hdrmuXTruth",10, 0., 5.);
   TH1F* hdrmulptX = new TH1F("hdrmulptX","hdrmulptX",10, 0., 5.);
   TH1F* hdrmulptXTruth = new TH1F("hdrmulptXTruth","hdrmulptXTruth",10, 0., 5.);
   TH1F* hdrmuhptX = new TH1F("hdrmuhptX","hdrmuhptX",10, 0., 5.);
   TH1F* hdrmuhptXTruth = new TH1F("hdrmuhptXTruth","hdrmuhptXTruth",10, 0., 5.);
   TH1F* hptfmuX = new TH1F("hptfmuX", "hptfmuX", 10, 0., 100.); 
   TH1F* hptfmuXTruth = new TH1F("hptfmuXTruth", "hptfmuXTruth", 10, 0., 100.); 
   TH1F* hdrfmuX = new TH1F("hdrfmuX","hdrfmuX",10, 0., 5.);
   TH1F* hdrfmuXTruth = new TH1F("hdrfmuXTruth","hdrfmuXTruth",10, 0., 5.);
   TH1F* hdrfmulptX = new TH1F("hdrfmulptX","hdrfmulptX",10, 0., 5.);
   TH1F* hdrfmulptXTruth = new TH1F("hdrfmulptXTruth","hdrfmulptXTruth",10, 0., 5.);
   TH1F* hdrfmuhptX = new TH1F("hdrfmuhptX","hdrfmuhptX",10, 0., 5.);
   TH1F* hdrfmuhptXTruth = new TH1F("hdrfmuhptXTruth","hdrfmuhptXTruth",10, 0., 5.);
   // no tag
   TH1F* hmuorigN = new TH1F("hmuorigN","hmuorigN", 50, 0., 50.); 
   TH1F* hplimuN = new TH1F("hplimuN", "hplimuN", 40, -2., 2.);
   TH1F* hplimuNTruth = new TH1F("hplimuNTruth", "hplimuNTruth", 40, -2., 2.);
   TH1F* hplivmuN = new TH1F("hplivmuN", "hplivmuN", 40, -2., 2.);
   TH1F* hplivmuNTruth = new TH1F("hplivmuNTruth", "hplivmuNTruth", 40, -2., 2.);
   TH1F* hptmuN = new TH1F("hptmuN", "hptmuN", 10, 0., 100.); 
   TH1F* hptmuNTruth = new TH1F("hptmuNTruth", "hptmuNTruth", 10, 0., 100.); 
   TH1F* hdrmuN = new TH1F("hdrmuN","hdrmuN",10, 0., 5.);
   TH1F* hdrmuNTruth = new TH1F("hdrmuNTruth","hdrmuNTruth",10, 0., 5.);
   TH1F* hdrmulptN = new TH1F("hdrmulptN","hdrmulptN",10, 0., 5.);
   TH1F* hdrmulptNTruth = new TH1F("hdrmulptNTruth","hdrmulptNTruth",10, 0., 5.);
   TH1F* hdrmuhptN = new TH1F("hdrmuhptN","hdrmuhptN",10, 0., 5.);
   TH1F* hdrmuhptNTruth = new TH1F("hdrmuhptNTruth","hdrmuhptNTruth",10, 0., 5.);
   TH1F* hptfmuN = new TH1F("hptfmuN", "hptfmuN", 10, 0., 100.); 
   TH1F* hptfmuNTruth = new TH1F("hptfmuNTruth", "hptfmuNTruth", 10, 0., 100.); 
   TH1F* hdrfmuN = new TH1F("hdrfmuN","hdrfmuN",10, 0., 5.);
   TH1F* hdrfmuNTruth = new TH1F("hdrfmuNTruth","hdrfmuNTruth",10, 0., 5.);
   TH1F* hdrfmulptN = new TH1F("hdrfmulptN","hdrfmulptN",10, 0., 5.);
   TH1F* hdrfmulptNTruth = new TH1F("hdrfmulptNTruth","hdrfmulptNTruth",10, 0., 5.);
   TH1F* hdrfmuhptN = new TH1F("hdrfmuhptN","hdrfmuhptN",10, 0., 5.);
   TH1F* hdrfmuhptNTruth = new TH1F("hdrfmuhptNTruth","hdrfmuhptNTruth",10, 0., 5.);
   // April 17
   TH1F* hfmuorig = new TH1F("hfmuorig","hfmuorig", 50, 0., 50.);
   TH1F* hfmuorigX = new TH1F("hfmuorigX","hfmuorigX", 50, 0., 50.);
   TH1F* hfmuorigN = new TH1F("hfmuorigN","hfmuorigN", 50, 0., 50.);
   //
   hmet2muss->Sumw2();
   hmt2muss->Sumw2();
   hnbjets2muss->Sumw2();
   hnjets2muss->Sumw2();
   hmhadw2muss->Sumw2();
   hmuorig->Sumw2();
   hplimu->Sumw2();
   hplimuTruth->Sumw2();
   hplivmu->Sumw2();
   hplivmuTruth->Sumw2();
   hptmu->Sumw2();
   hptmuTruth->Sumw2();
   hdrmu->Sumw2();
   hdrmuTruth->Sumw2();
   hdrmulpt->Sumw2();
   hdrmulptTruth->Sumw2();
   hdrmuhpt->Sumw2();
   hdrmuhptTruth->Sumw2();
   hptfmu->Sumw2();
   hptfmuTruth->Sumw2();
   hdrfmu->Sumw2();
   hdrfmuTruth->Sumw2();
   hdrfmulpt->Sumw2();
   hdrfmulptTruth->Sumw2();
   hdrfmuhpt->Sumw2();
   hdrfmuhptTruth->Sumw2();
   hmuorigX->Sumw2();
   hplimuX->Sumw2();
   hplimuXTruth->Sumw2();
   hplivmuX->Sumw2();
   hplivmuXTruth->Sumw2();
   hptmuX->Sumw2();
   hptmuXTruth->Sumw2();
   hdrmuX->Sumw2();
   hdrmuXTruth->Sumw2();
   hdrmulptX->Sumw2();
   hdrmulptXTruth->Sumw2();
   hdrmuhptX->Sumw2();
   hdrmuhptXTruth->Sumw2();
   hptfmuX->Sumw2();
   hptfmuXTruth->Sumw2();
   hdrfmuX->Sumw2();
   hdrfmuXTruth->Sumw2();
   hdrfmulptX->Sumw2();
   hdrfmulptXTruth->Sumw2();
   hdrfmuhptX->Sumw2();
   hdrfmuhptXTruth->Sumw2();
   // notag 
   hmuorigN->Sumw2();
   hplimuN->Sumw2();
   hplimuNTruth->Sumw2();
   hplivmuN->Sumw2();
   hplivmuNTruth->Sumw2();
   hptmuN->Sumw2();
   hptmuNTruth->Sumw2();
   hdrmuN->Sumw2();
   hdrmuNTruth->Sumw2();
   hdrmulptN->Sumw2();
   hdrmulptNTruth->Sumw2();
   hdrmuhptN->Sumw2();
   hdrmuhptNTruth->Sumw2();
   hptfmuN->Sumw2();
   hptfmuNTruth->Sumw2();
   hdrfmuN->Sumw2();
   hdrfmuNTruth->Sumw2();
   hdrfmulptN->Sumw2();
   hdrfmulptNTruth->Sumw2();
   hdrfmuhptN->Sumw2();
   hdrfmuhptNTruth->Sumw2();
   hfmuorig->Sumw2();
   hfmuorigX->Sumw2();
   hfmuorigN->Sumw2();
   // electron fake from 2lemuss 
   TH1F* hmetemuss = new TH1F("hmetemuss","hmetemuss",40, 0., 200.); 
   TH1F* hmtemuss = new TH1F("hmtemuss","hmtemuss", 40, 0., 200.);
   TH1F* hnbjetsemuss = new TH1F("hnbjetsemuss","hnbjetsemuss", 5, 0., 5.);
   TH1F* hnjetsemuss = new TH1F("hnjetsemuss","hnjetsemuss", 10, 0., 10.);
   TH1F* hmhadwemuss = new TH1F("hmhadwemuss","hmhadwemuss",50, 0., 150.);
   TH1F* heorig = new TH1F("heorig","heorig", 50, 0., 50.); 
   TH1F* hplie = new TH1F("hplie", "hplie", 40, -2., 2.);
   TH1F* hplieTruth = new TH1F("hplieTruth", "hplieTruth", 40, -2., 2.);
   TH1F* hplive = new TH1F("hplive", "hplive", 40, -2., 2.);
   TH1F* hpliveTruth = new TH1F("hpliveTruth", "hpliveTruth", 40, -2., 2.);
   TH1F* hpte = new TH1F("hpte", "hpte", 10, 0., 100.); 
   TH1F* hpteTruth = new TH1F("hpteTruth", "hpteTruth", 10, 0., 100.); 
   TH1F* hptfe = new TH1F("hptfe", "hptfe", 10, 0., 100.); 
   TH1F* hptfeTruth = new TH1F("hptfeTruth", "hptfeTruth", 10, 0., 100.); 
   TH1F* heorigX = new TH1F("heorigX","heorigX", 50, 0., 50.); 
   TH1F* hplieX = new TH1F("hplieX", "hplieX", 40, -2., 2.);
   TH1F* hplieXTruth = new TH1F("hplieXTruth", "hplieXTruth", 40, -2., 2.);
   TH1F* hpliveX = new TH1F("hpliveX", "hpliveX", 40, -2., 2.);
   TH1F* hpliveXTruth = new TH1F("hpliveXTruth", "hpliveXTruth", 40, -2., 2.);
   TH1F* hpteX = new TH1F("hpteX", "hpteX", 10, 0., 100.); 
   TH1F* hpteXTruth = new TH1F("hpteXTruth", "hpteXTruth", 10, 0., 100.); 
   TH1F* hptfeX = new TH1F("hptfeX", "hptfeX", 10, 0., 100.); 
   TH1F* hptfeXTruth = new TH1F("hptfeXTruth", "hptfeXTruth", 10, 0., 100.); 
   // no tag
   TH1F* heorigN = new TH1F("heorigN","heorigN", 50, 0., 50.); 
   TH1F* hplieN = new TH1F("hplieN", "hplieN", 40, -2., 2.);
   TH1F* hplieNTruth = new TH1F("hplieNTruth", "hplieNTruth", 40, -2., 2.);
   TH1F* hpliveN = new TH1F("hpliveN", "hpliveN", 40, -2., 2.);
   TH1F* hpliveNTruth = new TH1F("hpliveNTruth", "hpliveNTruth", 40, -2., 2.);
   TH1F* hpteN = new TH1F("hpteN", "hpteN", 10, 0., 100.); 
   TH1F* hpteNTruth = new TH1F("hpteNTruth", "hpteNTruth", 10, 0., 100.); 
   TH1F* hptfeN = new TH1F("hptfeN", "hptfeN", 10, 0., 100.); 
   TH1F* hptfeNTruth = new TH1F("hptfeNTruth", "hptfeNTruth", 10, 0., 100.); 
   // April 17
   TH1F* hfeorig = new TH1F("hfeorig","hfeorig", 50, 0., 50.);
   TH1F* hfeorigX = new TH1F("hfeorigX","hfeorigX", 50, 0., 50.);
   TH1F* hfeorigN = new TH1F("hfeorigN","hfeorigN", 50, 0., 50.);
   hmetemuss->Sumw2();
   hmtemuss->Sumw2();
   hnbjetsemuss->Sumw2();
   hnjetsemuss->Sumw2();
   hmhadwemuss->Sumw2();
   heorig->Sumw2();
   hplie->Sumw2();
   hplieTruth->Sumw2();
   hplive->Sumw2();
   hpliveTruth->Sumw2();
   hpte->Sumw2();
   hpteTruth->Sumw2();
   hptfe->Sumw2();
   hptfeTruth->Sumw2();
   heorigX->Sumw2();
   hplieX->Sumw2();
   hplieXTruth->Sumw2();
   hpliveX->Sumw2();
   hpliveXTruth->Sumw2();
   hpteX->Sumw2();
   hpteXTruth->Sumw2();
   hptfeX->Sumw2();
   hptfeXTruth->Sumw2();
   // no tag
   heorigN->Sumw2();
   hplieN->Sumw2();
   hplieNTruth->Sumw2();
   hpliveN->Sumw2();
   hpliveNTruth->Sumw2();
   hpteN->Sumw2();
   hpteNTruth->Sumw2();
   hptfeN->Sumw2();
   hptfeNTruth->Sumw2();
   hfeorig->Sumw2();
   hfeorigX->Sumw2();
   hfeorigN->Sumw2();
   // electron qmis fake from 2lemuos April 5 new 
   TH1F* hmetemuos = new TH1F("hmetemuos","hmetemuos",40, 0., 200.);
   TH1F* hmtemuos = new TH1F("hmtemuos","hmtemuos", 40, 0., 200.);
   TH1F* hnbjetsemuos = new TH1F("hnbjetsemuos","hnbjetsemuos", 5, 0., 5.);
   TH1F* hnjetsemuos = new TH1F("hnjetsemuos","hnjetsemuos", 10, 0., 10.);
   TH1F* hmhadwemuos = new TH1F("hmhadwemuos","hmhadwemuos",50, 0., 150.);
   TH1F* heqorig = new TH1F("heqorig","heqorig", 50, 0., 50.);
   TH1F* hplieq = new TH1F("hplieq", "hplieq", 40, -2., 2.);
   TH1F* hplieqTruth = new TH1F("hplieqTruth", "hplieqTruth", 40, -2., 2.);
   TH1F* hpliveq = new TH1F("hpliveq", "hpliveq", 40, -2., 2.);
   TH1F* hpliveqTruth = new TH1F("hpliveqTruth", "hpliveqTruth", 40, -2., 2.);
   TH1F* hpteq = new TH1F("hpteq", "hpteq", 10, 0., 100.);
   TH1F* hpteqTruth = new TH1F("hpteqTruth", "hpteqTruth", 10, 0., 100.);
   TH1F* hptfeq = new TH1F("hptfeq", "hptfeq", 10, 0., 100.);
   TH1F* hptfeqTruth = new TH1F("hptfeqTruth", "hptfeqTruth", 10, 0., 100.);
   TH1F* heqorigX = new TH1F("heqorigX","heqorigX", 50, 0., 50.);
   TH1F* hplieqX = new TH1F("hplieqX", "hplieqX", 40, -2., 2.);
   TH1F* hplieqXTruth = new TH1F("hplieqXTruth", "hplieqXTruth", 40, -2., 2.);
   TH1F* hpliveqX = new TH1F("hpliveqX", "hpliveqX", 40, -2., 2.);
   TH1F* hpliveqXTruth = new TH1F("hpliveqXTruth", "hpliveqXTruth", 40, -2., 2.);
   TH1F* hpteqX = new TH1F("hpteqX", "hpteqX", 10, 0., 100.);
   TH1F* hpteqXTruth = new TH1F("hpteqXTruth", "hpteqXTruth", 10, 0., 100.);
   TH1F* hptfeqX = new TH1F("hptfeqX", "hptfeqX", 10, 0., 100.);
   TH1F* hptfeqXTruth = new TH1F("hptfeqXTruth", "hptfeqXTruth", 10, 0., 100.);
   // no tag
   TH1F* heqorigN = new TH1F("heqorigN","heqorigN", 50, 0., 50.);
   TH1F* hplieqN = new TH1F("hplieqN", "hplieqN", 40, -2., 2.);
   TH1F* hplieqNTruth = new TH1F("hplieqNTruth", "hplieqNTruth", 40, -2., 2.);
   TH1F* hpliveqN = new TH1F("hpliveqN", "hpliveqN", 40, -2., 2.);
   TH1F* hpliveqNTruth = new TH1F("hpliveqNTruth", "hpliveqNTruth", 40, -2., 2.);
   TH1F* hpteqN = new TH1F("hpteqN", "hpteqN", 10, 0., 100.);
   TH1F* hpteqNTruth = new TH1F("hpteqNTruth", "hpteqNTruth", 10, 0., 100.);
   TH1F* hptfeqN = new TH1F("hptfeqN", "hptfeqN", 10, 0., 100.);
   TH1F* hptfeqNTruth = new TH1F("hptfeqNTruth", "hptfeqNTruth", 10, 0., 100.);
   hmetemuos->Sumw2();
   hmtemuos->Sumw2();
   hnbjetsemuos->Sumw2();
   hnjetsemuos->Sumw2();
   hmhadwemuos->Sumw2();
   heqorig->Sumw2();
   hplieq->Sumw2();
   hplieqTruth->Sumw2();
   hpliveq->Sumw2();
   hpliveqTruth->Sumw2();
   hpteq->Sumw2();
   hpteqTruth->Sumw2();
   hptfeq->Sumw2();
   hptfeqTruth->Sumw2();
   heqorigX->Sumw2();
   hplieqX->Sumw2();
   hplieqXTruth->Sumw2();
   hpliveqX->Sumw2();
   hpliveqXTruth->Sumw2();
   hpteqX->Sumw2();
   hpteqXTruth->Sumw2();
   hptfeqX->Sumw2();
   hptfeqXTruth->Sumw2();
   // no tag
   heqorigN->Sumw2();
   hplieqN->Sumw2();
   hplieqNTruth->Sumw2();
   hpliveqN->Sumw2();
   hpliveqNTruth->Sumw2();
   hpteqN->Sumw2();
   hpteqNTruth->Sumw2();
   hptfeqN->Sumw2();
   hptfeqNTruth->Sumw2();
   // vbf stuff 
   TH1F* hmjjmax = new TH1F("hmjjmax","hmjjmax",50, 0., 2000.); 
   TH1F* hvbfnjets = new TH1F("hvbfnjets","hvbfnjets",10, 0.,10.);
   TH1F* hvbfbjets = new TH1F("hvbfbjets","hvbfbjets",5, 0.,5.);
   TH1F* hvbfht = new TH1F("hvbfht","hvbfht",50, 0.,2000.);
   TH1F* hvbfnjets2B = new TH1F("hvbfnjets2B","hvbfnjets2B",10, 0.,10.);
   TH1F* hvbfht2B = new TH1F("hvbfht2B","hvbfht2B",50, 0.,2000.);
   TH1F* hvbfnjets1B = new TH1F("hvbfnjets1B","hvbfnjets1B",10, 0.,10.);
   TH1F* hvbfht1B = new TH1F("hvbfht1B","hvbfht1B",50, 0.,2000.);
   TH1F* hvbfnjets0B = new TH1F("hvbfnjets0B","hvbfnjets0B",10, 0.,10.);
   TH1F* hvbfht0B = new TH1F("hvbfht0B","hvbfht0B",50, 0.,2000.);
   hmjjmax->Sumw2();
   hvbfnjets->Sumw2();
   hvbfbjets->Sumw2();
   hvbfht->Sumw2();
   hvbfnjets2B->Sumw2();
   hvbfht2B->Sumw2();
   hvbfnjets1B->Sumw2();
   hvbfht1B->Sumw2();
   hvbfnjets0B->Sumw2();
   hvbfht0B->Sumw2();
   //tau fake stuff
   TH1F* hnjetz = new TH1F("hnjetz","hnjetz",5,0.,5.); // mar 2
   TH1F* hnjetemuB = new TH1F("hnjetemuB","hnjetemuB",5,0.,5.);// mar 2
   TH1F* hdrltauz = new TH1F("hdrltauz","hdrltauz",25,0.,5.);
   TH1F* hdrltauemuB = new TH1F("hdrltauemuB","hdrltauemuB",25,0.,5.);
   TH1F* hptltauz = new TH1F("hptltauz","hptltauz",3,25.,115.);
   TH1F* hptltauzTruth = new TH1F("hptltauzTruth","hptltauzTruth",3,25.,115.);
   TH1F* hptmtauz = new TH1F("hptmtauz","hptmtauz",3,25.,115.);
   TH1F* hptmtauzTruth = new TH1F("hptmtauzTruth","hptmtauzTruth",3,25.,115.);
   TH1F* hptltauemuB = new TH1F("hptltauemuB","hptltauemuB",3,25.,115.);
   TH1F* hptltauemuBTruth = new TH1F("hptltauemuBTruth","hptltauemuBTruth",3,25.,115.);
   TH1F* hptmtauemuB = new TH1F("hptmtauemuB","hptmtauemuB",3,25.,115.);
   TH1F* hptmtauemuBTruth = new TH1F("hptmtauemuBTruth","hptmtauemuBTruth",3,25.,115.);
   // 2d
   TH1F* hptltauzx = new TH1F("hptltauzx","hptltauzx",3,25.,115.); // new mar 5
   TH1F* hptltauzl = new TH1F("hptltauzl","hptltauzl",3,25.,115.); // new
   TH1F* hptltauzc = new TH1F("hptltauzc","hptltauzc",3,25.,115.); // new
   TH1F* hptltauzb = new TH1F("hptltauzb","hptltauzb",3,25.,115.); // new
   TH1F* hptltauzg = new TH1F("hptltauzg","hptltauzg",3,25.,115.); // new
   TH1F* hptmtauzx = new TH1F("hptmtauzx","hptmtauzx",3,25.,115.); // new mar 5
   TH1F* hptmtauzl = new TH1F("hptmtauzl","hptmtauzl",3,25.,115.); // new
   TH1F* hptmtauzc = new TH1F("hptmtauzc","hptmtauzc",3,25.,115.); // new
   TH1F* hptmtauzb = new TH1F("hptmtauzb","hptmtauzb",3,25.,115.); // new
   TH1F* hptmtauzg = new TH1F("hptmtauzg","hptmtauzg",3,25.,115.); // new

   TH1F* hptltauemuBx = new TH1F("hptltauemuBx","hptltauemuBx",3,25.,115.); // new mar 5
   TH1F* hptltauemuBl = new TH1F("hptltauemuBl","hptltauemuBl",3,25.,115.); // new
   TH1F* hptltauemuBc = new TH1F("hptltauemuBc","hptltauemuBc",3,25.,115.); // new
   TH1F* hptltauemuBb = new TH1F("hptltauemuBb","hptltauemuBb",3,25.,115.); // new
   TH1F* hptltauemuBg = new TH1F("hptltauemuBg","hptltauemuBg",3,25.,115.); // new
   TH1F* hptmtauemuBx = new TH1F("hptmtauemuBx","hptmtauemuBx",3,25.,115.); // new mar 5
   TH1F* hptmtauemuBl = new TH1F("hptmtauemuBl","hptmtauemuBl",3,25.,115.); // new
   TH1F* hptmtauemuBc = new TH1F("hptmtauemuBc","hptmtauemuBc",3,25.,115.); // new
   TH1F* hptmtauemuBb = new TH1F("hptmtauemuBb","hptmtauemuBb",3,25.,115.); // new
   TH1F* hptmtauemuBg = new TH1F("hptmtauemuBg","hptmtauemuBg",3,25.,115.); // new
   // mar 13 added 
   TH1F* htruthmtauzl = new TH1F("htruthmtauzl","htruthmtauzl",25,0.,25.);
   TH1F* horigmtauzl =new TH1F("horigmtauzl","horigmtauzl",50,0.,50.);
   TH1F* htruthmtauzx =new TH1F("htruthmtauzx","htruthmtauzx",25,0.,25.);
   TH1F* horigmtauzx =new TH1F("horigmtauzx","horigmtauzx",50,0.,50.);
   TH1F* htruthltauzl =new TH1F("htruthltauzl","htruthltauzl",25,0.,25.);
   TH1F* horigltauzl =new TH1F("horigltauzl","horigltauzl",50,0.,50.);
   TH1F* htruthltauzx =new TH1F("htruthltauzx","htruthltauzx",25,0.,25.);
   TH1F* horigltauzx =new TH1F("horigltauzx","horigltauzx",50,0.,50.);
   //
   TH1F* htruthmtauemuBl =new TH1F("htruthmtauemuBl","htruthmtauemuBl",25,0.,25.);
   TH1F* horigmtauemuBl =new TH1F("horigmtauemuBl","horigmtauemuBl",50,0.,50.);
   TH1F* htruthmtauemuBx =new TH1F("htruthmtauemuBx","htruthmtauemuBx",25,0.,25.);
   TH1F* horigmtauemuBx =new TH1F("horigmtauemuBx","horigmtauemuBx",50,0.,50.);
   TH1F* htruthltauemuBl =new TH1F("htruthltauemuBl","htruthltauemuBl",25,0.,25.);
   TH1F* horigltauemuBl =new TH1F("horigltauemuBl","horigltauemuBl",50,0.,50.);
   TH1F* htruthltauemuBx =new TH1F("htruthltauemuBx","htruthltauemuBx",25,0.,25.);
   TH1F* horigltauemuBx =new TH1F("horigltauemuBx","horigltauemuBx",50,0.,50.);
   //
   TH1F* hptltauzele = new TH1F("hptltauzele","hptltauzele",3,25.,115.);
   TH1F* hptltauzmu = new TH1F("hptltauzmu","hptltauzmu",3,25.,115.);
   TH1F* hptmtauzele = new TH1F("hptmtauzele","hptmtauzele",3,25.,115.);
   TH1F* hptmtauzmu = new TH1F("hptmtauzmu","hptmtauzmu",3,25.,115.);
   TH1F* hptltauemuBele = new TH1F("hptltauemuBele","hptltauemuBele",3,25.,115.);
   TH1F* hptltauemuBmu = new TH1F("hptltauemuBmu","hptltauemuBmu",3,25.,115.);
   TH1F* hptmtauemuBele = new TH1F("hptmtauemuBele","hptmtauemuBele",3,25.,115.);
   TH1F* hptmtauemuBmu = new TH1F("hptmtauemuBmu","hptmtauemuBmu",3,25.,115.);
   //ltau rate 
   TH1F* hmetltau = new TH1F("hmetltau","hmetltau",40,0., 200.);
   TH1F* hmtltau = new TH1F("hmtltau","hmtltau",40,0., 200.);
   TH1F* nbjetsltau = new TH1F("nbjetsltau","nbjetsltau", 5, 0., 5.);
   TH1F* njetsltau = new TH1F("njetsltau","njetsltau", 10, 0., 10.);
   TH1F* ntausltau = new TH1F("ntausltau","ntausltau", 5, 0., 5.);
   TH1F* hptltauos = new TH1F("hptltauos","hptltauos", 3,25.,115.);
   TH1F* hptltauosTruth = new TH1F("hptltauosTruth","hptltauosTruth", 3,25.,115.);
   TH1F* hleptruthltauos = new TH1F("hleptruthltauos","hleptruthltauos",25,0.,25.); // mar 3
   TH1F* hptmutauos = new TH1F("hptmutauos","hptmutauos", 3,25.,115.); // mar 3
   TH1F* hptmutauosTruth = new TH1F("hptmutauosTruth","hptmutauosTruth", 3,25.,115.); // new mar 3
   TH1F* hleptruthmutauos = new TH1F("hleptruthmutauos","hleptruthmutauos",25,0.,25.); // mar 3
   TH1F* hetaltauos = new TH1F("hetaltauos","hetaltauos", 20, 0., 2.5);
   TH1F* htightltauos = new TH1F("htightltauos","htightltauos", 2, 0., 2.);
   TH1F* htagltauos = new TH1F("htagltauos","htagltauos", 2, 0., 2.);
   TH1F* hntkltauos = new TH1F("hntkltauos","hntkltauos", 5, 0., 5.);
   TH1F* hmorltauos = new TH1F("hmorltauos","hmorltauos", 2, 0., 2.);
   TH1F* horigltauos = new TH1F("horigltauos","horigltauos", 50, 0., 50.);
   TH1F* htypeltauos = new TH1F("htypeltauos","htypeltauos", 50, 0., 50.);
   TH1F* hjfltauos = new TH1F("hjfltauos","hjfltauos", 26, -1., 25.);
   //ltau ss
   TH1F* hptltauss = new TH1F("hptltauss","hptltauss", 3,25.,115.);
   TH1F* hptltaussTruth = new TH1F("hptltaussTruth","hptltaussTruth", 3,25.,115.);
   TH1F* hleptruthltauss = new TH1F("hleptruthltauss","hleptruthltauss",25,0.,25.); // mar 3
   TH1F* hptmutauss = new TH1F("hptmutauss","hptmutauss", 3,25.,115.); // mar 3 
   TH1F* hptmutaussTruth = new TH1F("hptmutaussTruth","hptmutaussTruth", 3,25.,115.); // new mar 3
   TH1F* hleptruthmutauss = new TH1F("hleptruthmutauss","hleptruthmutauss",25,0.,25.); // mar 3 
   TH1F* hetaltauss = new TH1F("hetaltauss","hetaltauss", 20, 0., 2.5);
   TH1F* htightltauss = new TH1F("htightltauss","htightltauss", 2, 0., 2.);
   TH1F* htagltauss = new TH1F("htagltauss","htagltauss", 2, 0., 2.);
   TH1F* hntkltauss = new TH1F("hntkltauss","hntkltauss", 5, 0., 5.);
   TH1F* hmorltauss = new TH1F("hmorltauss","hmorltauss", 2, 0., 2.);
   TH1F* horigltauss = new TH1F("horigltauss","horigltauss", 50, 0., 50.);
   TH1F* htypeltauss = new TH1F("htypeltauss","htypeltauss", 50, 0., 50.);
   TH1F* hjfltauss = new TH1F("hjfltauss","hjfltauss", 26, -1., 25.);
   // ltauftau
   TH1F* hptltauftauos = new TH1F("hptltauftauos","hptltauftauos", 3,25.,115.); // new 
   TH1F* hptltauftauosTruth = new TH1F("hptltauftauosTruth","hptltauftauosTruth", 3,25.,115.); // new
   TH1F* hptltauosftauos = new TH1F("hptltauosftauos","hptltauosftauos", 3,25.,115.); // new 
   TH1F* hptltauosftauosTruth = new TH1F("hptltauosftauosTruth","hptltauosftauosTruth", 3,25.,115.); // new
   TH1F* hptltaussftauos = new TH1F("hptltaussftauos","hptltaussftauos", 3,25.,115.); // new 
   TH1F* hptltaussftauosTruth = new TH1F("hptltaussftauosTruth","hptltaussftauosTruth", 3,25.,115.); // new
   TH1F* hptltauftauosx = new TH1F("hptltauftauosx","hptltauftauosx", 3,25.,115.); // new mar 5
   TH1F* hptltauftauosl = new TH1F("hptltauftauosl","hptltauftauosl", 3,25.,115.); // new
   TH1F* hptltauftauosc = new TH1F("hptltauftauosc","hptltauftauosc", 3,25.,115.); // new
   TH1F* hptltauftauosb = new TH1F("hptltauftauosb","hptltauftauosb", 3,25.,115.); // new
   TH1F* hptltauftauosg = new TH1F("hptltauftauosg","hptltauftauosg", 3,25.,115.); // new
   TH1F* hptltauftauss = new TH1F("hptltauftauss","hptltauftauss", 3,25.,115.); //new
   TH1F* hptltauftaussTruth = new TH1F("hptltauftaussTruth","hptltauftaussTruth", 3,25.,115.); //new
   TH1F* hptltauosftauss = new TH1F("hptltauosftauss","hptltauosftauss", 3,25.,115.); //new
   TH1F* hptltauosftaussTruth = new TH1F("hptltauosftaussTruth","hptltauosftaussTruth", 3,25.,115.); //new
   TH1F* hptltaussftauss = new TH1F("hptltaussftauss","hptltaussftauss", 3,25.,115.); //new
   TH1F* hptltaussftaussTruth = new TH1F("hptltaussftaussTruth","hptltaussftaussTruth", 3,25.,115.); //new
   TH1F* hptltauftaussx = new TH1F("hptltauftaussx","hptltauftaussx", 3,25.,115.); // new mar 5
   TH1F* hptltauftaussl = new TH1F("hptltauftaussl","hptltauftaussl", 3,25.,115.); // new
   TH1F* hptltauftaussc = new TH1F("hptltauftaussc","hptltauftaussc", 3,25.,115.); // new
   TH1F* hptltauftaussb = new TH1F("hptltauftaussb","hptltauftaussb", 3,25.,115.); // new
   TH1F* hptltauftaussg = new TH1F("hptltauftaussg","hptltauftaussg", 3,25.,115.); // new
    //1l2tau os 
   TH1F* hptl2tauos = new TH1F("hptl2tauos","hptl2tauos",3,25.,115.);
   TH1F* hleptruthl2tauos = new TH1F("hleptruthl2tauos","hleptruthl2tauos",25,0.,25.);// mar 3  
   TH1F* hptsubl2tauos = new TH1F("hptsubl2tauos","hptsubl2tauos",3,25.,115.);
   TH1F* htightl2tauos = new TH1F("htightl2tauos","htightl2tauos",3,0.,3.);
   TH1F* htagl2tauos = new TH1F("htagl2tauos","htagl2tauos",3,0.,3.);
   TH1F* hmassl2tauos = new TH1F("hmassl2tauos","hmassl2tauos",25,0.,250.);
   TH1F* htruthl2tauos = new TH1F("htruthl2tauos","htruthl2tauos",5,0.,5.);
   TH1F* hjfl2tauos = new TH1F("hjfl2tauos","hjfl2tauos",25,0.,25.);
   //1l2tau ss
   TH1F* hptl2tauss = new TH1F("hptl2tauss","hptl2tauss",3,25.,115.);
   TH1F* hleptruthl2tauss = new TH1F("hleptruthl2tauss","hleptruthl2tauss",25,0.,25.);// mar 3  
   TH1F* hptsubl2tauss = new TH1F("hptsubl2tauss","hptsubl2tauss",3,25.,115.);
   TH1F* htightl2tauss = new TH1F("htightl2tauss","htightl2tauss",3,0.,3.);
   TH1F* htagl2tauss = new TH1F("htagl2tauss","htagl2tauss",3,0.,3.);
   TH1F* hmassl2tauss = new TH1F("hmassl2tauss","hmassl2tauss",25,0.,250.);
   TH1F* hlepchl2tauss = new TH1F("hlepchl2tauss","hlepchl2tauss",3,-1.,2.); // mar 3 
   TH1F* htruthl2tauss = new TH1F("htruthl2tauss","htruthl2tauss",5,0.,5.);
   TH1F* hjfl2tauss = new TH1F("hjfl2tauss","hjfl2tauss",25,0.,25.);
   // weight
   TH1F* hptltauoswt = new TH1F("hptltauoswt","hptltauoswt", 3,25.,115.); // mar 3
   TH1F* hptltausswt = new TH1F("hptltausswt","hptltausswt", 3,25.,115.); // mar 3
   TH1F* hptl2tauoswt = new TH1F("hptl2tauoswt","hptl2tauoswt",3,25.,115.); // mar 3
   TH1F* hptsubl2tauoswt = new TH1F("hptsubl2tauoswt","hptsubl2tauoswt",3,25.,115.); // mar 3
   TH1F* hmassl2tauoswt = new TH1F("hmassl2tauoswt","hmassl2tauoswt",25,0.,250.); // mar 3
   TH1F* hptl2tausswt = new TH1F("hptl2tausswt","hptl2tausswt",3,25.,115.); // mar 3
   TH1F* hptsubl2tausswt = new TH1F("hptsubl2tausswt","hptsubl2tausswt",3,25.,115.); // mar 3
   TH1F* hmassl2tausswt = new TH1F("hmassl2tausswt","hmassl2tausswt",25,0.,250.); // mar 3
   TH1F* hptmutauoswt = new TH1F("hptmutauoswt","hptmutauoswt", 3,25.,115.); // mar 12
   TH1F* hptmutausswt = new TH1F("hptmutausswt","hptmutausswt", 3,25.,115.); // mar 12

   // QCD studies 
   TH1F* hptmutauoslow = new TH1F("hptmutauoslow","hptmutauoslow", 3,25.,115.); // mar 6
   TH1F* hptmutauoslowTruth = new TH1F("hptmutauoslowTruth","hptmutauoslowTruth", 3,25.,115.); // new mar 6
   TH1F* hleptruthmutauoslow = new TH1F("hleptruthmutauoslow","hleptruthmutauoslow",25,0.,25.); // mar 6
   TH1F* hptmutausslow = new TH1F("hptmutausslow","hptmutausslow", 3,25.,115.); // mar 6
   TH1F* hptmutausslowTruth = new TH1F("hptmutausslowTruth","hptmutausslowTruth", 3,25.,115.); // new mar 6
   TH1F* hleptruthmutausslow = new TH1F("hleptruthmutausslow","hleptruthmutausslow",25,0.,25.); // mar 6
   TH1F* hptmutauosqcd = new TH1F("hptmutauosqcd","hptmutauosqcd", 3,25.,115.); // mar 6
   TH1F* hptmutauosqcdTruth = new TH1F("hptmutauosqcdTruth","hptmutauosqcdTruth", 3,25.,115.); // new mar 6
   TH1F* hleptruthmutauosqcd = new TH1F("hleptruthmutauosqcd","hleptruthmutauosqcd",25,0.,25.); // mar 6
   TH1F* hptmutaussqcd = new TH1F("hptmutaussqcd","hptmutaussqcd", 3,25.,115.); // mar 6
   TH1F* hptmutaussqcdTruth = new TH1F("hptmutaussqcdTruth","hptmutaussqcdTruth", 3,25.,115.); // new mar 6
   TH1F* hleptruthmutaussqcd = new TH1F("hleptruthmutaussqcd","hleptruthmutaussqcd",25,0.,25.); // mar 6
   TH1F* hptmutauosqcdlow = new TH1F("hptmutauosqcdlow","hptmutauosqcdlow", 3,25.,115.); // mar 6
   TH1F* hptmutauosqcdlowTruth = new TH1F("hptmutauosqcdlowTruth","hptmutauosqcdlowTruth", 3,25.,115.); // new mar 6
   TH1F* hleptruthmutauosqcdlow = new TH1F("hleptruthmutauosqcdlow","hleptruthmutauosqcdlow",25,0.,25.); // mar 6
   TH1F* hptmutaussqcdlow = new TH1F("hptmutaussqcdlow","hptmutaussqcdlow", 3,25.,115.); // mar 6
   TH1F* hptmutaussqcdlowTruth = new TH1F("hptmutaussqcdlowTruth","hptmutaussqcdlowTruth", 3,25.,115.); // new mar 6
   TH1F* hleptruthmutaussqcdlow = new TH1F("hleptruthmutaussqcdlow","hleptruthmutaussqcdlow",25,0.,25.); // mar 6
   // SF vs eta and ntk mar 10 new
   TH1F* hetaltauz = new TH1F("hetaltauz","hetaltauz",5, 0., 2.5);
   TH1F* hntkltauz = new TH1F("hntkltauz","hntkltauz",5, 0., 5.);
   TH1F* hetaltauzTruth = new TH1F("hetaltauzTruth","hetaltauzTruth",5, 0., 2.5);
   TH1F* hntkltauzTruth = new TH1F("hntkltauzTruth","hntkltauzTruth",5, 0., 5.);
   TH1F* hetamtauz = new TH1F("hetamtauz","hetamtauz",5, 0., 2.5);
   TH1F* hntkmtauz = new TH1F("hntkmtauz","hntkmtauz",5, 0., 5.);
   TH1F* hetamtauzTruth = new TH1F("hetamtauzTruth","hetamtauzTruth",5, 0., 2.5);
   TH1F* hntkmtauzTruth = new TH1F("hntkmtauzTruth","hntkmtauzTruth",5, 0., 5.);
   TH1F* hetaltauemuB = new TH1F("hetaltauemuB","hetaltauemuB",5, 0., 2.5);
   TH1F* hntkltauemuB = new TH1F("hntkltauemuB","hntkltauemuB",5, 0., 5.);
   TH1F* hetaltauemuBTruth = new TH1F("hetaltauemuBTruth","hetaltauemuBTruth",5, 0., 2.5);
   TH1F* hntkltauemuBTruth = new TH1F("hntkltauemuBTruth","hntkltauemuBTruth",5, 0., 5.);
   TH1F* hetamtauemuB = new TH1F("hetamtauemuB","hetamtauemuB",5, 0., 2.5);
   TH1F* hntkmtauemuB = new TH1F("hntkmtauemuB","hntkmtauemuB",5, 0., 5.);
   TH1F* hetamtauemuBTruth = new TH1F("hetamtauemuBTruth","hetamtauemuBTruth",5, 0., 2.5);
   TH1F* hntkmtauemuBTruth = new TH1F("hntkmtauemuBTruth","hntkmtauemuBTruth",5, 0., 5.);
   //os
   TH1F* hetamutauosqcd = new TH1F("hetamutauosqcd","hetamutauosqcd",5, 0., 2.5);
   TH1F* hntkmutauosqcd = new TH1F("hntkmutauosqcd","hntkmutauosqcd",5, 0., 5.0);
   TH1F* hetamutauosqcdTruth = new TH1F("hetamutauosqcdTruth","hetamutauosqcdTruth",5,0., 2.5);
   TH1F* hntkmutauosqcdTruth = new TH1F("hntkmutauosqcdTruth","hntkmutauosqcdTruth",5,0., 5.0);
   TH1F* hetamutauosqcdlow = new TH1F("hetamutauosqcdlow","hetamutauosqcdlow",5,0., 2.5);
   TH1F* hntkmutauosqcdlow = new TH1F("hntkmutauosqcdlow","hntkmutauosqcdlow",5,0., 5.0);
   TH1F* hetamutauosqcdlowTruth = new TH1F("hetamutauosqcdlowTruth","hetamutauosqcdlowTruth",5,0., 2.5);
   TH1F* hntkmutauosqcdlowTruth = new TH1F("hntkmutauosqcdlowTruth","hntkmutauosqcdlowTruth",5,0., 5.0);
   TH1F* hetamutauos = new TH1F("hetamutauos","hetamutauos",5,0., 2.5);
   TH1F* hntkmutauos = new TH1F("hntkmutauos","hntkmutauos",5,0., 5.0);
   TH1F* hetamutauosTruth = new TH1F("hetamutauosTruth","hetamutauosTruth",5,0., 2.5);
   TH1F* hntkmutauosTruth = new TH1F("hntkmutauosTruth","hntkmutauosTruth",5,0., 5.0);
   TH1F* hetamutauoslow = new TH1F("hetamutauoslow","hetamutauoslow",5,0., 2.5);
   TH1F* hntkmutauoslow = new TH1F("hntkmutauoslow","hntkmutauoslow",5,0., 5.0);
   TH1F* hetamutauoslowTruth = new TH1F("hetamutauoslowTruth","hetamutauoslowTruth",5,0., 2.5);
   TH1F* hntkmutauoslowTruth = new TH1F("hntkmutauoslowTruth","hntkmutauoslowTruth",5,0., 5.0);
   //ss
   TH1F* hetamutaussqcd = new TH1F("hetamutaussqcd","hetamutaussqcd",5, 0., 2.5);
   TH1F* hntkmutaussqcd = new TH1F("hntkmutaussqcd","hntkmutaussqcd",5, 0., 5.0);
   TH1F* hetamutaussqcdTruth = new TH1F("hetamutaussqcdTruth","hetamutaussqcdTruth",5,0., 2.5);
   TH1F* hntkmutaussqcdTruth = new TH1F("hntkmutaussqcdTruth","hntkmutaussqcdTruth",5,0., 5.0);
   TH1F* hetamutaussqcdlow = new TH1F("hetamutaussqcdlow","hetamutaussqcdlow",5,0., 2.5);
   TH1F* hntkmutaussqcdlow = new TH1F("hntkmutaussqcdlow","hntkmutaussqcdlow",5,0., 5.0);
   TH1F* hetamutaussqcdlowTruth = new TH1F("hetamutaussqcdlowTruth","hetamutaussqcdlowTruth",5,0., 2.5);
   TH1F* hntkmutaussqcdlowTruth = new TH1F("hntkmutaussqcdlowTruth","hntkmutaussqcdlowTruth",5,0., 5.0);
   TH1F* hetamutauss = new TH1F("hetamutauss","hetamutauss",5,0., 2.5);
   TH1F* hntkmutauss = new TH1F("hntkmutauss","hntkmutauss",5,0., 5.0);
   TH1F* hetamutaussTruth = new TH1F("hetamutaussTruth","hetamutaussTruth",5,0., 2.5);
   TH1F* hntkmutaussTruth = new TH1F("hntkmutaussTruth","hntkmutaussTruth",5,0., 5.0);
   TH1F* hetamutausslow = new TH1F("hetamutausslow","hetamutausslow",5,0., 2.5);
   TH1F* hntkmutausslow = new TH1F("hntkmutausslow","hntkmutausslow",5,0., 5.0);
   TH1F* hetamutausslowTruth = new TH1F("hetamutausslowTruth","hetamutausslowTruth",5,0., 2.5);
   TH1F* hntkmutausslowTruth = new TH1F("hntkmutausslowTruth","hntkmutausslowTruth",5,0., 5.0);
   // QCD l2tau mar 10                                                                                                 
   TH1F* hptl2tauosqcd = new TH1F("hptl2tauosqcd","hptl2tauosqcd",3,25.,115.);
   TH1F* hleptruthl2tauosqcd = new TH1F("hleptruthl2tauosqcd","hleptruthl2tauosqcd",25,0.,25.);
   TH1F* hptsubl2tauosqcd = new TH1F("hptsubl2tauosqcd","hptsubl2tauosqcd",3,25.,115.);
   TH1F* hptl2tauosqcdlow = new TH1F("hptl2tauosqcdlow","hptl2tauosqcdlow",3,25.,115.);
   TH1F* hleptruthl2tauosqcdlow = new TH1F("hleptruthl2tauosqcdlow","hleptruthl2tauosqcdlow",25,0.,25.);
   TH1F* hptsubl2tauosqcdlow = new TH1F("hptsubl2tauosqcdlow","hptsubl2tauosqcdlow",3,25.,115.);
   TH1F* hptl2tauoslow = new TH1F("hptl2tauoslow","hptl2tauoslow",3,25.,115.);
   TH1F* hleptruthl2tauoslow = new TH1F("hleptruthl2tauoslow","hleptruthl2tauoslow",25,0.,25.);
   TH1F* hptsubl2tauoslow = new TH1F("hptsubl2tauoslow","hptsubl2tauoslow",3,25.,115.);
   //
   TH1F* hptl2taussqcd = new TH1F("hptl2taussqcd","hptl2taussqcd",3,25.,115.);
   TH1F* hleptruthl2taussqcd = new TH1F("hleptruthl2taussqcd","hleptruthl2taussqcd",25,0.,25.);
   TH1F* hptsubl2taussqcd = new TH1F("hptsubl2taussqcd","hptsubl2taussqcd",3,25.,115.);
   TH1F* hptl2taussqcdlow = new TH1F("hptl2taussqcdlow","hptl2taussqcdlow",3,25.,115.);
   TH1F* hleptruthl2taussqcdlow = new TH1F("hleptruthl2taussqcdlow","hleptruthl2taussqcdlow",25,0.,25.);
   TH1F* hptsubl2taussqcdlow = new TH1F("hptsubl2taussqcdlow","hptsubl2taussqcdlow",3,25.,115.);
   TH1F* hptl2tausslow = new TH1F("hptl2tausslow","hptl2tausslow",3,25.,115.);
   TH1F* hleptruthl2tausslow = new TH1F("hleptruthl2tausslow","hleptruthl2tausslow",25,0.,25.);
   TH1F* hptsubl2tausslow = new TH1F("hptsubl2tausslow","hptsubl2tausslow",3,25.,115.);
   // mar 15 
   TH1F* htpvmtauz = new TH1F("htpvmtauz","htpvmtauz",20, -1., 1.);
   TH1F* htpvmtauzTruth = new TH1F("htpvmtauzTruth","htpvmtauzTruth",20, -1., 1.);
   TH1F* htpvltauz = new TH1F("htpvltauz","htpvltauz",20, -1., 1.);
   TH1F* htpvltauzTruth = new TH1F("htpvltauzTruth","htpvltauzTruth",20, -1., 1.);
   TH1F* htpvmtauemuB = new TH1F("htpvmtauemuB","htpvmtauemuB",20, -1., 1.);
   TH1F* htpvmtauemuBTruth = new TH1F("htpvmtauemuBTruth","htpvmtauemuBTruth",20, -1., 1.);
   TH1F* htpvltauemuB = new TH1F("htpvltauemuB","htpvltauemuB",20, -1., 1.);
   TH1F* htpvltauemuBTruth = new TH1F("htpvltauemuBTruth","htpvltauemuBTruth",20, -1., 1.);
   TH1F* htpvltauos = new TH1F("htpvltauos","htpvltauos",20, -1., 1.);
   TH1F* htpvltauosTruth = new TH1F("htpvltauosTruth","htpvltauosTruth",20, -1., 1.);
   TH1F* htpvltauss = new TH1F("htpvltauss","htpvltauss",20, -1., 1.);
   TH1F* htpvltaussTruth = new TH1F("htpvltaussTruth","htpvltaussTruth",20, -1., 1.);
   TH1F* htpvl2tauos = new TH1F("htpvl2tauos","htpvl2tauos",20, -1., 1.);
   TH1F* htpvsubl2tauos = new TH1F("htpvsubl2tauos","htpvsubl2tauos",20, -1., 1.);
   TH1F* htpvl2tauss = new TH1F("htpvl2tauss","htpvl2tauss",20, -1., 1.);
   TH1F* htpvsubl2tauss = new TH1F("htpvsubl2tauss","htpvsubl2tauss",20, -1., 1.);

   // mar 15 l2tau medium loose for qcd 
   TH1F* hptl2taumlosqcd = new TH1F("hptl2taumlosqcd","hptl2taumlosqcd",3,25.,115.);
   TH1F* hleptruthl2taumlosqcd = new TH1F("hleptruthl2taumlosqcd","hleptruthl2taumlosqcd",25,0.,25.);
   TH1F* hptl2taumlssqcd = new TH1F("hptl2taumlssqcd","hptl2taumlssqcd",3,25.,115.);
   TH1F* hleptruthl2taumlssqcd = new TH1F("hleptruthl2taumlssqcd","hleptruthl2taumlssqcd",25,0.,25.);
   TH1F* hptl2taumlosqcdlow = new TH1F("hptl2taumlosqcdlow","hptl2taumlosqcdlow",3,25.,115.);
   TH1F* hleptruthl2taumlosqcdlow = new TH1F("hleptruthl2taumlosqcdlow","hleptruthl2taumlosqcdlow",25,0.,25.);
   TH1F* hptl2taumlssqcdlow = new TH1F("hptl2taumlssqcdlow","hptl2taumlssqcdlow",3,25.,115.);
   TH1F* hleptruthl2taumlssqcdlow = new TH1F("hleptruthl2taumlssqcdlow","hleptruthl2taumlssqcdlow",25,0.,25.);
   TH1F* hptl2taumlos = new TH1F("hptl2taumlos","hptl2taumlos",3,25.,115.);
   TH1F* hleptruthl2taumlos = new TH1F("hleptruthl2taumlos","hleptruthl2taumlos",25,0.,25.);
   TH1F* hptl2taumlss = new TH1F("hptl2taumlss","hptl2taumlss",3,25.,115.);
   TH1F* hleptruthl2taumlss = new TH1F("hleptruthl2taumlss","hleptruthl2taumlss",25,0.,25.);
   TH1F* hptl2taumloslow = new TH1F("hptl2taumloslow","hptl2taumloslow",3,25.,115.);
   TH1F* hleptruthl2taumloslow = new TH1F("hleptruthl2taumloslow","hleptruthl2taumloslow",25,0.,25.);
   TH1F* hptl2taumlsslow = new TH1F("hptl2taumlsslow","hptl2taumlsslow",3,25.,115.);
   TH1F* hleptruthl2taumlsslow = new TH1F("hleptruthl2taumlsslow","hleptruthl2taumlsslow",25,0.,25.);
   //
   // mar 25
   TH1F* hmv2cmtauz = new TH1F("hmv2cmtauz","hmv2cmtauz",20, -1., 1.);
   TH1F* hmv2cmtauzTruth = new TH1F("hmv2cmtauzTruth","hmv2cmtauzTruth",20, -1., 1.);
   TH1F* hmv2cltauz = new TH1F("hmv2cltauz","hmv2cltauz",20, -1., 1.);
   TH1F* hmv2cltauzTruth = new TH1F("hmv2cltauzTruth","hmv2cltauzTruth",20, -1., 1.);
   TH1F* hmv2cmtauemuB = new TH1F("hmv2cmtauemuB","hmv2cmtauemuB",20, -1., 1.);
   TH1F* hmv2cmtauemuBTruth = new TH1F("hmv2cmtauemuBTruth","hmv2cmtauemuBTruth",20, -1., 1.);
   TH1F* hmv2cltauemuB = new TH1F("hmv2cltauemuB","hmv2cltauemuB",20, -1., 1.);
   TH1F* hmv2cltauemuBTruth = new TH1F("hmv2cltauemuBTruth","hmv2cltauemuBTruth",20, -1., 1.);
   TH1F* hmv2cltauos = new TH1F("hmv2cltauos","hmv2cltauos",20, -1., 1.);
   TH1F* hmv2cltauosTruth = new TH1F("hmv2cltauosTruth","hmv2cltauosTruth",20, -1., 1.);
   TH1F* hmv2cltauss = new TH1F("hmv2cltauss","hmv2cltauss",20, -1., 1.);
   TH1F* hmv2cltaussTruth = new TH1F("hmv2cltaussTruth","hmv2cltaussTruth",20, -1., 1.);
   TH1F* hmv2cl2tauos = new TH1F("hmv2cl2tauos","hmv2cl2tauos",20, -1., 1.);
   TH1F* hmv2csubl2tauos = new TH1F("hmv2csubl2tauos","hmv2csubl2tauos",20, -1., 1.);
   TH1F* hmv2cl2tauss = new TH1F("hmv2cl2tauss","hmv2cl2tauss",20, -1., 1.);
   TH1F* hmv2csubl2tauss = new TH1F("hmv2csubl2tauss","hmv2csubl2tauss",20, -1., 1.);
   TH1F* hbdtsigtransz = new TH1F("hbdtsigtransz","hbdtsigtransz",20, 0.,1.);
   TH1F* hbdtsigtransemuB = new TH1F("hbdtsigtransemuB","hbdtsigtransemuB",20, 0.,1.);
   TH1F* hbdtsigtransltau = new TH1F("hbdtsigtransltau","hbdtsigtransltau",20, 0.,1.);
   //cutflow
   TH1F* hltaucutflow = new TH1F("hltaucutflow","hltaucutflow",25, 0.,25.0);
   TH1F* hltaucutflowct =new TH1F("hltaucutflowct","hltaucutflowct",25, 0.,25.0);
   // 5-14 
   TH1F* hjfltau1pos = new TH1F("hjfltau1pos","hjfltau1pos", 26, -1., 25.);
   TH1F* hleptruth1pos = new TH1F("hleptruth1pos","hleptruth1pos",25,0.,25.);
   TH1F* hjfltau3pos = new TH1F("hjfltau3pos","hjfltau3pos", 26, -1., 25.);
   TH1F* hleptruth3pos = new TH1F("hleptruth3pos","hleptruth3pos",25,0.,25.);
   TH1F* hjfltau1pss = new TH1F("hjfltau1pss","hjfltau1pss", 26, -1., 25.);
   TH1F* hleptruth1pss = new TH1F("hleptruth1pss","hleptruth1pss",25,0.,25.);
   TH1F* hjfltau3pss = new TH1F("hjfltau3pss","hjfltau3pss", 26, -1., 25.);
   TH1F* hleptruth3pss = new TH1F("hleptruth3pss","hleptruth3pss",25,0.,25.);
   //5-18
   TH1F* hjfltau1posbwp1 = new TH1F("hjfltau1posbwp1","hjfltau1posbwp1", 26, -1., 25.);
   TH1F* hjfltau3posbwp1 = new TH1F("hjfltau3posbwp1","hjfltau3posbwp1", 26, -1., 25.);
   TH1F* hjfltau1pssbwp1 = new TH1F("hjfltau1pssbwp1","hjfltau1pssbwp1", 26, -1., 25.);
   TH1F* hjfltau3pssbwp1 = new TH1F("hjfltau3pssbwp1","hjfltau3pssbwp1", 26, -1., 25.);
   //5-22
   TH1F* hjfltau1poslowbwp1 = new TH1F("hjfltau1poslowbwp1","hjfltau1poslowbwp1", 26, -1., 25.);
   TH1F* hjfltau3poslowbwp1 = new TH1F("hjfltau3poslowbwp1","hjfltau3poslowbwp1", 26, -1., 25.);
   TH1F* hjfltau1psslowbwp1 = new TH1F("hjfltau1psslowbwp1","hjfltau1psslowbwp1", 26, -1., 25.);
   TH1F* hjfltau3psslowbwp1 = new TH1F("hjfltau3psslowbwp1","hjfltau3psslowbwp1", 26, -1., 25.);
   TH1F* hjfltau1poslow = new TH1F("hjfltau1poslow","hjfltau1poslow", 26, -1., 25.);
   TH1F* hjfltau3poslow = new TH1F("hjfltau3poslow","hjfltau3poslow", 26, -1., 25.);
   TH1F* hjfltau1psslow = new TH1F("hjfltau1psslow","hjfltau1psslow", 26, -1., 25.);
   TH1F* hjfltau3psslow = new TH1F("hjfltau3psslow","hjfltau3psslow", 26, -1., 25.);
   TH1F* hjfltau1poslowbwp0 = new TH1F("hjfltau1poslowbwp0","hjfltau1poslowbwp0", 26, -1., 25.);
   TH1F* hjfltau3poslowbwp0 = new TH1F("hjfltau3poslowbwp0","hjfltau3poslowbwp0", 26, -1., 25.);
   TH1F* hjfltau1psslowbwp0 = new TH1F("hjfltau1psslowbwp0","hjfltau1psslowbwp0", 26, -1., 25.);
   TH1F* hjfltau3psslowbwp0 = new TH1F("hjfltau3psslowbwp0","hjfltau3psslowbwp0", 26, -1., 25.);
   TH1F* hjfltau1poslowbwp2 = new TH1F("hjfltau1poslowbwp2","hjfltau1poslowbwp2", 26, -1., 25.);
   TH1F* hjfltau3poslowbwp2 = new TH1F("hjfltau3poslowbwp2","hjfltau3poslowbwp2", 26, -1., 25.);
   TH1F* hjfltau1psslowbwp2 = new TH1F("hjfltau1psslowbwp2","hjfltau1psslowbwp2", 26, -1., 25.);
   TH1F* hjfltau3psslowbwp2 = new TH1F("hjfltau3psslowbwp2","hjfltau3psslowbwp2", 26, -1., 25.);
   TH1F* hjfltau1poslowbwp3 = new TH1F("hjfltau1poslowbwp3","hjfltau1poslowbwp3", 26, -1., 25.);
   TH1F* hjfltau3poslowbwp3 = new TH1F("hjfltau3poslowbwp3","hjfltau3poslowbwp3", 26, -1., 25.);
   TH1F* hjfltau1psslowbwp3 = new TH1F("hjfltau1psslowbwp3","hjfltau1psslowbwp3", 26, -1., 25.);
   TH1F* hjfltau3psslowbwp3 = new TH1F("hjfltau3psslowbwp3","hjfltau3psslowbwp3", 26, -1., 25.);
   hjfltau1pos->Sumw2();
   hleptruth1pos->Sumw2();
   hjfltau3pos->Sumw2();
   hleptruth3pos->Sumw2();
   hjfltau1pss->Sumw2();
   hleptruth1pss->Sumw2();
   hjfltau3pss->Sumw2();
   hleptruth3pss->Sumw2();
   hjfltau1posbwp1->Sumw2();
   hjfltau3posbwp1->Sumw2();
   hjfltau1pssbwp1->Sumw2();
   hjfltau3pssbwp1->Sumw2();
   //
   hjfltau1poslowbwp1->Sumw2();
   hjfltau3poslowbwp1->Sumw2();
   hjfltau1psslowbwp1->Sumw2();
   hjfltau3psslowbwp1->Sumw2();
   hjfltau1poslow->Sumw2();
   hjfltau3poslow->Sumw2();
   hjfltau1psslow->Sumw2();
   hjfltau3psslow->Sumw2();
   hjfltau1poslowbwp0->Sumw2();
   hjfltau3poslowbwp0->Sumw2();
   hjfltau1psslowbwp0->Sumw2();
   hjfltau3psslowbwp0->Sumw2();
   hjfltau1poslowbwp2->Sumw2();
   hjfltau3poslowbwp2->Sumw2();
   hjfltau1psslowbwp2->Sumw2();
   hjfltau3psslowbwp2->Sumw2();
   hjfltau1poslowbwp3->Sumw2();
   hjfltau3poslowbwp3->Sumw2();
   hjfltau1psslowbwp3->Sumw2();
   hjfltau3psslowbwp3->Sumw2();
   //
   hnjetz->Sumw2();
   hnjetemuB->Sumw2();
   hdrltauz->Sumw2();
   hdrltauemuB->Sumw2();
   hptltauz->Sumw2();
   hptltauzTruth->Sumw2();
   hptmtauz->Sumw2();
   hptmtauzTruth->Sumw2();
   hptltauemuB->Sumw2();
   hptltauemuBTruth->Sumw2();
   hptmtauemuB->Sumw2();
   hptmtauemuBTruth->Sumw2();
   //
   hptltauzx->Sumw2();
   hptltauzl->Sumw2();
   hptltauzc->Sumw2();
   hptltauzb->Sumw2();
   hptltauzg->Sumw2();
   hptmtauzx->Sumw2();
   hptmtauzl->Sumw2();
   hptmtauzc->Sumw2();
   hptmtauzb->Sumw2();
   hptmtauzg->Sumw2();
   hptltauemuBx->Sumw2();
   hptltauemuBl->Sumw2();
   hptltauemuBc->Sumw2();
   hptltauemuBb->Sumw2();
   hptltauemuBg->Sumw2();
   hptmtauemuBx->Sumw2();
   hptmtauemuBl->Sumw2();
   hptmtauemuBc->Sumw2();
   hptmtauemuBb->Sumw2();
   hptmtauemuBg->Sumw2();
   // mar 13 added
   htruthmtauzl->Sumw2();
   horigmtauzl->Sumw2();
   htruthmtauzx->Sumw2();
   horigmtauzx->Sumw2();
   htruthltauzl->Sumw2();
   horigltauzl->Sumw2();
   htruthltauzx->Sumw2();
   horigltauzx->Sumw2();
   //
   htruthmtauemuBl->Sumw2();
   horigmtauemuBl->Sumw2();
   htruthmtauemuBx->Sumw2();
   horigmtauemuBx->Sumw2();
   htruthltauemuBl->Sumw2();
   horigltauemuBl->Sumw2();
   htruthltauemuBx->Sumw2();
   horigltauemuBx->Sumw2();
   // 
   hptltauzele->Sumw2();
   hptltauzmu->Sumw2();
   hptmtauzele->Sumw2();
   hptmtauzmu->Sumw2();
   hptltauemuBele->Sumw2();
   hptltauemuBmu->Sumw2();
   hptmtauemuBele->Sumw2();
   hptmtauemuBmu->Sumw2();
   //
   hmetltau->Sumw2();
   hmtltau->Sumw2();
   nbjetsltau->Sumw2();
   njetsltau->Sumw2();
   ntausltau->Sumw2();
   // 1ltau os 
   hptltauos->Sumw2();
   hptltauosTruth->Sumw2();
   hleptruthltauos->Sumw2();
   hptmutauos->Sumw2();
   hptmutauosTruth->Sumw2();
   hleptruthmutauos->Sumw2();
   hetaltauos->Sumw2();
   htightltauos->Sumw2();
   htagltauos->Sumw2();
   hntkltauos->Sumw2();
   hmorltauos->Sumw2();
   horigltauos->Sumw2();
   htypeltauos->Sumw2();
   hjfltauos->Sumw2();
   //1ltau ss
   hptltauss->Sumw2();
   hptltaussTruth->Sumw2();
   hleptruthltauss->Sumw2();
   hptmutauss->Sumw2();
   hptmutaussTruth->Sumw2();
   hleptruthmutauss->Sumw2();
   hetaltauss->Sumw2();
   htightltauss->Sumw2();
   htagltauss->Sumw2();
   hntkltauss->Sumw2();
   hmorltauss->Sumw2();
   horigltauss->Sumw2();
   htypeltauss->Sumw2();
   hjfltauss->Sumw2();
   //1ltauftau
   hptltauftauos->Sumw2();
   hptltauftauosTruth->Sumw2();
   hptltauosftauos->Sumw2();
   hptltauosftauosTruth->Sumw2();
   hptltaussftauos->Sumw2();
   hptltaussftauosTruth->Sumw2();
   hptltauftauosx->Sumw2();
   hptltauftauosl->Sumw2();
   hptltauftauosc->Sumw2();
   hptltauftauosb->Sumw2();
   hptltauftauosg->Sumw2();
   hptltauftauss->Sumw2();
   hptltauftaussTruth->Sumw2();
   hptltauosftauss->Sumw2();
   hptltauosftaussTruth->Sumw2();
   hptltaussftauss->Sumw2();
   hptltaussftaussTruth->Sumw2();
   hptltauftaussx->Sumw2();
   hptltauftaussl->Sumw2();
   hptltauftaussc->Sumw2();
   hptltauftaussb->Sumw2();
   hptltauftaussg->Sumw2();
   // 1l2tu os
   hptl2tauos->Sumw2();
   hleptruthl2tauos->Sumw2();
   hptsubl2tauos->Sumw2();
   htightl2tauos->Sumw2();
   htagl2tauos->Sumw2();
   hmassl2tauos->Sumw2();
   htruthl2tauos->Sumw2();
   hjfl2tauos->Sumw2();
   //1l2tau ss
   hptl2tauss->Sumw2();
   hleptruthl2tauss->Sumw2();
   hptsubl2tauss->Sumw2();
   htightl2tauss->Sumw2();
   htagl2tauss->Sumw2();
   hmassl2tauss->Sumw2();
   hlepchl2tauss->Sumw2();
   htruthl2tauss->Sumw2();
   hjfl2tauss->Sumw2();
   // weighted
   hptltauoswt->Sumw2();
   hptltausswt->Sumw2();
   hptl2tauoswt->Sumw2();
   hptsubl2tauoswt->Sumw2();
   hmassl2tauoswt->Sumw2();
   hptl2tausswt->Sumw2();
   hptsubl2tausswt->Sumw2();
   hmassl2tausswt->Sumw2();
   hptmutauoswt->Sumw2();
   hptmutausswt->Sumw2();

   // qcd
   hptmutauoslow->Sumw2();
   hptmutauoslowTruth->Sumw2();
   hleptruthmutauoslow->Sumw2();
   hptmutausslow->Sumw2();
   hptmutausslowTruth->Sumw2();
   hleptruthmutausslow->Sumw2();
   hptmutauosqcd->Sumw2();
   hptmutauosqcdTruth->Sumw2();
   hleptruthmutauosqcd->Sumw2();
   hptmutaussqcd->Sumw2();
   hptmutaussqcdTruth->Sumw2();
   hleptruthmutaussqcd->Sumw2();
   hptmutauosqcdlow->Sumw2();
   hptmutauosqcdlowTruth->Sumw2();
   hleptruthmutauosqcdlow->Sumw2();
   hptmutaussqcdlow->Sumw2();
   hptmutaussqcdlowTruth->Sumw2();
   hleptruthmutaussqcdlow->Sumw2();
   // mar 10 for eta and ntrk for tau sf                                                                                                                               
   hetaltauz->Sumw2();
   hntkltauz->Sumw2();
   hetaltauzTruth->Sumw2();
   hntkltauzTruth->Sumw2();
   hetamtauz->Sumw2();
   hntkmtauz->Sumw2();
   hetamtauzTruth->Sumw2();
   hntkmtauzTruth->Sumw2();
   hetaltauemuB->Sumw2();
   hntkltauemuB->Sumw2();
   hetaltauemuBTruth->Sumw2();
   hntkltauemuBTruth->Sumw2();
   hetamtauemuB->Sumw2();
   hntkmtauemuB->Sumw2();
   hetamtauemuBTruth->Sumw2();
   hntkmtauemuBTruth->Sumw2();
   //
   hetamutauosqcd->Sumw2();
   hntkmutauosqcd->Sumw2();
   hetamutauosqcdTruth->Sumw2();
   hntkmutauosqcdTruth->Sumw2();
   hetamutauosqcdlow->Sumw2();
   hntkmutauosqcdlow->Sumw2();
   hetamutauosqcdlowTruth->Sumw2();
   hntkmutauosqcdlowTruth->Sumw2();
   hetamutauos->Sumw2();
   hntkmutauos->Sumw2();
   hetamutauosTruth->Sumw2();
   hntkmutauosTruth->Sumw2();
   hetamutauoslow->Sumw2();
   hntkmutauoslow->Sumw2();
   hetamutauoslowTruth->Sumw2();
   hntkmutauoslowTruth->Sumw2();
   //
   hetamutaussqcd->Sumw2();
   hntkmutaussqcd->Sumw2();
   hetamutaussqcdTruth->Sumw2();
   hntkmutaussqcdTruth->Sumw2();
   hetamutaussqcdlow->Sumw2();
   hntkmutaussqcdlow->Sumw2();
   hetamutaussqcdlowTruth->Sumw2();
   hntkmutaussqcdlowTruth->Sumw2();
   hetamutauss->Sumw2();
   hntkmutauss->Sumw2();
   hetamutaussTruth->Sumw2();
   hntkmutaussTruth->Sumw2();
   hetamutausslow->Sumw2();
   hntkmutausslow->Sumw2();
   hetamutausslowTruth->Sumw2();
   hntkmutausslowTruth->Sumw2();
   //
   // qcd l2taau mar 10                                                                                                
   hptl2tauosqcd->Sumw2();
   hleptruthl2tauosqcd->Sumw2();
   hptsubl2tauosqcd->Sumw2();
   hptl2tauosqcdlow->Sumw2();
   hleptruthl2tauosqcdlow->Sumw2();
   hptsubl2tauosqcdlow->Sumw2();
   hptl2tauoslow->Sumw2();
   hleptruthl2tauoslow->Sumw2();
   hptsubl2tauoslow->Sumw2();
   //
   hptl2taussqcd->Sumw2();
   hleptruthl2taussqcd->Sumw2();
   hptsubl2taussqcd->Sumw2();
   hptl2taussqcdlow->Sumw2();
   hleptruthl2taussqcdlow->Sumw2();
   hptsubl2taussqcdlow->Sumw2();
   hptl2tausslow->Sumw2();
   hleptruthl2tausslow->Sumw2();
   hptsubl2tausslow->Sumw2();
   // mar 15 
   htpvmtauz->Sumw2();
   htpvmtauzTruth->Sumw2();
   htpvltauz->Sumw2();
   htpvltauzTruth->Sumw2();
   htpvmtauemuB->Sumw2();
   htpvmtauemuBTruth->Sumw2();
   htpvltauemuB->Sumw2();
   htpvltauemuBTruth->Sumw2();
   htpvltauos->Sumw2();
   htpvltauosTruth->Sumw2();
   htpvltauss->Sumw2();
   htpvltaussTruth->Sumw2();
   htpvl2tauos->Sumw2();
   htpvsubl2tauos->Sumw2();
   htpvl2tauss->Sumw2();
   htpvsubl2tauss->Sumw2();
   // mar 15
   hptl2taumlosqcd->Sumw2();
   hleptruthl2taumlosqcd->Sumw2();
   hptl2taumlssqcd->Sumw2();
   hleptruthl2taumlssqcd->Sumw2();
   hptl2taumlosqcdlow->Sumw2();
   hleptruthl2taumlosqcdlow->Sumw2();
   hptl2taumlssqcdlow->Sumw2();
   hleptruthl2taumlssqcdlow->Sumw2();
   hptl2taumlos->Sumw2();
   hleptruthl2taumlos->Sumw2();
   hptl2taumlss->Sumw2();
   hleptruthl2taumlss->Sumw2();
   hptl2taumloslow->Sumw2();
   hleptruthl2taumloslow->Sumw2();
   hptl2taumlsslow->Sumw2();
   hleptruthl2taumlsslow->Sumw2();
   //
   // mar 25
   hmv2cmtauz->Sumw2();
   hmv2cmtauzTruth->Sumw2();
   hmv2cltauz->Sumw2();
   hmv2cltauzTruth->Sumw2();
   hmv2cmtauemuB->Sumw2();
   hmv2cmtauemuBTruth->Sumw2();
   hmv2cltauemuB->Sumw2();
   hmv2cltauemuBTruth->Sumw2();
   hmv2cltauos->Sumw2();
   hmv2cltauosTruth->Sumw2();
   hmv2cltauss->Sumw2();
   hmv2cltaussTruth->Sumw2();
   hmv2cl2tauos->Sumw2();
   hmv2csubl2tauos->Sumw2();
   hmv2cl2tauss->Sumw2();
   hmv2csubl2tauss->Sumw2();
   hbdtsigtransz->Sumw2();
   hbdtsigtransemuB->Sumw2();
   hbdtsigtransltau->Sumw2();
   // April 6
   //os
   TH1F* hptltauosbwp0 = new TH1F("hptltauosbwp0","hptltauosbwp0",3,25.,115.);
   TH1F* hptltauosbwp1 = new TH1F("hptltauosbwp1","hptltauosbwp1",3,25.,115.);
   TH1F* hptltauosbwp2 = new TH1F("hptltauosbwp2","hptltauosbwp2",3,25.,115.);
   TH1F* hptltauosbwp3 = new TH1F("hptltauosbwp3","hptltauosbwp3",3,25.,115.);
   TH1F* hptltauosTruthbwp0 = new TH1F("hptltauosTruthbwp0","hptltauosTruthbwp0",3,25.,115.);
   TH1F* hptltauosTruthbwp1 = new TH1F("hptltauosTruthbwp1","hptltauosTruthbwp1",3,25.,115.);
   TH1F* hptltauosTruthbwp2 = new TH1F("hptltauosTruthbwp2","hptltauosTruthbwp2",3,25.,115.);
   TH1F* hptltauosTruthbwp3 = new TH1F("hptltauosTruthbwp3","hptltauosTruthbwp3",3,25.,115.);
   TH1F* hptltau1pos = new TH1F("hptltau1pos","hptltau1pos",3,25.,115.);
   TH1F* hptltau1posTruth = new TH1F("hptltau1posTruth","hptltau1posTruth",3,25.,115.);
   TH1F* hptltau1posbwp0 = new TH1F("hptltau1posbwp0","hptltau1posbwp0",3,25.,115.);
   TH1F* hptltau1posbwp1 = new TH1F("hptltau1posbwp1","hptltau1posbwp1",3,25.,115.);
   TH1F* hptltau1posbwp2 = new TH1F("hptltau1posbwp2","hptltau1posbwp2",3,25.,115.);
   TH1F* hptltau1posbwp3 = new TH1F("hptltau1posbwp3","hptltau1posbwp3",3,25.,115.);
   TH1F* hptltau1posTruthbwp0 = new TH1F("hptltau1posTruthbwp0","hptltau1posTruthbwp0",3,25.,115.);
   TH1F* hptltau1posTruthbwp1 = new TH1F("hptltau1posTruthbwp1","hptltau1posTruthbwp1",3,25.,115.);
   TH1F* hptltau1posTruthbwp2 = new TH1F("hptltau1posTruthbwp2","hptltau1posTruthbwp2",3,25.,115.);
   TH1F* hptltau1posTruthbwp3 = new TH1F("hptltau1posTruthbwp3","hptltau1posTruthbwp3",3,25.,115.);
   TH1F* hptltau3pos = new TH1F("hptltau3pos","hptltau3pos",3,25.,115.);
   TH1F* hptltau3posTruth = new TH1F("hptltau3posTruth","hptltau3posTruth",3,25.,115.);
   TH1F* hptltau3posbwp0 = new TH1F("hptltau3posbwp0","hptltau3posbwp0",3,25.,115.);
   TH1F* hptltau3posbwp1 = new TH1F("hptltau3posbwp1","hptltau3posbwp1",3,25.,115.);
   TH1F* hptltau3posbwp2 = new TH1F("hptltau3posbwp2","hptltau3posbwp2",3,25.,115.);
   TH1F* hptltau3posbwp3 = new TH1F("hptltau3posbwp3","hptltau3posbwp3",3,25.,115.);
   TH1F* hptltau3posTruthbwp0 = new TH1F("hptltau3posTruthbwp0","hptltau3posTruthbwp0",3,25.,115.);
   TH1F* hptltau3posTruthbwp1 = new TH1F("hptltau3posTruthbwp1","hptltau3posTruthbwp1",3,25.,115.);
   TH1F* hptltau3posTruthbwp2 = new TH1F("hptltau3posTruthbwp2","hptltau3posTruthbwp2",3,25.,115.);
   TH1F* hptltau3posTruthbwp3 = new TH1F("hptltau3posTruthbwp3","hptltau3posTruthbwp3",3,25.,115.);
   //ss
   TH1F* hptltaussbwp0 = new TH1F("hptltaussbwp0","hptltaussbwp0",3,25.,115.);
   TH1F* hptltaussbwp1 = new TH1F("hptltaussbwp1","hptltaussbwp1",3,25.,115.);
   TH1F* hptltaussbwp2 = new TH1F("hptltaussbwp2","hptltaussbwp2",3,25.,115.);
   TH1F* hptltaussbwp3 = new TH1F("hptltaussbwp3","hptltaussbwp3",3,25.,115.);
   TH1F* hptltaussTruthbwp0 = new TH1F("hptltaussTruthbwp0","hptltaussTruthbwp0",3,25.,115.);
   TH1F* hptltaussTruthbwp1 = new TH1F("hptltaussTruthbwp1","hptltaussTruthbwp1",3,25.,115.);
   TH1F* hptltaussTruthbwp2 = new TH1F("hptltaussTruthbwp2","hptltaussTruthbwp2",3,25.,115.);
   TH1F* hptltaussTruthbwp3 = new TH1F("hptltaussTruthbwp3","hptltaussTruthbwp3",3,25.,115.);
   TH1F* hptltau1pss = new TH1F("hptltau1pss","hptltau1pss",3,25.,115.);
   TH1F* hptltau1pssTruth = new TH1F("hptltau1pssTruth","hptltau1pssTruth",3,25.,115.);
   TH1F* hptltau1pssbwp0 = new TH1F("hptltau1pssbwp0","hptltau1pssbwp0",3,25.,115.);
   TH1F* hptltau1pssbwp1 = new TH1F("hptltau1pssbwp1","hptltau1pssbwp1",3,25.,115.);
   TH1F* hptltau1pssbwp2 = new TH1F("hptltau1pssbwp2","hptltau1pssbwp2",3,25.,115.);
   TH1F* hptltau1pssbwp3 = new TH1F("hptltau1pssbwp3","hptltau1pssbwp3",3,25.,115.);
   TH1F* hptltau1pssTruthbwp0 = new TH1F("hptltau1pssTruthbwp0","hptltau1pssTruthbwp0",3,25.,115.);
   TH1F* hptltau1pssTruthbwp1 = new TH1F("hptltau1pssTruthbwp1","hptltau1pssTruthbwp1",3,25.,115.);
   TH1F* hptltau1pssTruthbwp2 = new TH1F("hptltau1pssTruthbwp2","hptltau1pssTruthbwp2",3,25.,115.);
   TH1F* hptltau1pssTruthbwp3 = new TH1F("hptltau1pssTruthbwp3","hptltau1pssTruthbwp3",3,25.,115.);
   TH1F* hptltau3pss = new TH1F("hptltau3pss","hptltau3pss",3,25.,115.);
   TH1F* hptltau3pssTruth = new TH1F("hptltau3pssTruth","hptltau3pssTruth",3,25.,115.);
   TH1F* hptltau3pssbwp0 = new TH1F("hptltau3pssbwp0","hptltau3pssbwp0",3,25.,115.);
   TH1F* hptltau3pssbwp1 = new TH1F("hptltau3pssbwp1","hptltau3pssbwp1",3,25.,115.);
   TH1F* hptltau3pssbwp2 = new TH1F("hptltau3pssbwp2","hptltau3pssbwp2",3,25.,115.);
   TH1F* hptltau3pssbwp3 = new TH1F("hptltau3pssbwp3","hptltau3pssbwp3",3,25.,115.);
   TH1F* hptltau3pssTruthbwp0 = new TH1F("hptltau3pssTruthbwp0","hptltau3pssTruthbwp0",3,25.,115.);
   TH1F* hptltau3pssTruthbwp1 = new TH1F("hptltau3pssTruthbwp1","hptltau3pssTruthbwp1",3,25.,115.);
   TH1F* hptltau3pssTruthbwp2 = new TH1F("hptltau3pssTruthbwp2","hptltau3pssTruthbwp2",3,25.,115.);
   TH1F* hptltau3pssTruthbwp3 = new TH1F("hptltau3pssTruthbwp3","hptltau3pssTruthbwp3",3,25.,115.);
   //--low   
   //os
   TH1F* hptltauoslowbwp0 = new TH1F("hptltauoslowbwp0","hptltauoslowbwp0",3,25.,115.);
   TH1F* hptltauoslowbwp1 = new TH1F("hptltauoslowbwp1","hptltauoslowbwp1",3,25.,115.);
   TH1F* hptltauoslowbwp2 = new TH1F("hptltauoslowbwp2","hptltauoslowbwp2",3,25.,115.);
   TH1F* hptltauoslowbwp3 = new TH1F("hptltauoslowbwp3","hptltauoslowbwp3",3,25.,115.);
   TH1F* hptltauoslowTruthbwp0 = new TH1F("hptltauoslowTruthbwp0","hptltauoslowTruthbwp0",3,25.,115.);
   TH1F* hptltauoslowTruthbwp1 = new TH1F("hptltauoslowTruthbwp1","hptltauoslowTruthbwp1",3,25.,115.);
   TH1F* hptltauoslowTruthbwp2 = new TH1F("hptltauoslowTruthbwp2","hptltauoslowTruthbwp2",3,25.,115.);
   TH1F* hptltauoslowTruthbwp3 = new TH1F("hptltauoslowTruthbwp3","hptltauoslowTruthbwp3",3,25.,115.);
   TH1F* hptltau1poslow = new TH1F("hptltau1poslow","hptltau1poslow",3,25.,115.);
   TH1F* hptltau1poslowTruth = new TH1F("hptltau1poslowTruth","hptltau1poslowTruth",3,25.,115.);
   TH1F* hptltau1poslowbwp0 = new TH1F("hptltau1poslowbwp0","hptltau1poslowbwp0",3,25.,115.);
   TH1F* hptltau1poslowbwp1 = new TH1F("hptltau1poslowbwp1","hptltau1poslowbwp1",3,25.,115.);
   TH1F* hptltau1poslowbwp2 = new TH1F("hptltau1poslowbwp2","hptltau1poslowbwp2",3,25.,115.);
   TH1F* hptltau1poslowbwp3 = new TH1F("hptltau1poslowbwp3","hptltau1poslowbwp3",3,25.,115.);
   TH1F* hptltau1poslowTruthbwp0 = new TH1F("hptltau1poslowTruthbwp0","hptltau1poslowTruthbwp0",3,25.,115.);
   TH1F* hptltau1poslowTruthbwp1 = new TH1F("hptltau1poslowTruthbwp1","hptltau1poslowTruthbwp1",3,25.,115.);
   TH1F* hptltau1poslowTruthbwp2 = new TH1F("hptltau1poslowTruthbwp2","hptltau1poslowTruthbwp2",3,25.,115.);
   TH1F* hptltau1poslowTruthbwp3 = new TH1F("hptltau1poslowTruthbwp3","hptltau1poslowTruthbwp3",3,25.,115.);
   TH1F* hptltau3poslow = new TH1F("hptltau3poslow","hptltau3poslow",3,25.,115.);
   TH1F* hptltau3poslowTruth = new TH1F("hptltau3poslowTruth","hptltau3poslowTruth",3,25.,115.);
   TH1F* hptltau3poslowbwp0 = new TH1F("hptltau3poslowbwp0","hptltau3poslowbwp0",3,25.,115.);
   TH1F* hptltau3poslowbwp1 = new TH1F("hptltau3poslowbwp1","hptltau3poslowbwp1",3,25.,115.);
   TH1F* hptltau3poslowbwp2 = new TH1F("hptltau3poslowbwp2","hptltau3poslowbwp2",3,25.,115.);
   TH1F* hptltau3poslowbwp3 = new TH1F("hptltau3poslowbwp3","hptltau3poslowbwp3",3,25.,115.);
   TH1F* hptltau3poslowTruthbwp0 = new TH1F("hptltau3poslowTruthbwp0","hptltau3poslowTruthbwp0",3,25.,115.);
   TH1F* hptltau3poslowTruthbwp1 = new TH1F("hptltau3poslowTruthbwp1","hptltau3poslowTruthbwp1",3,25.,115.);
   TH1F* hptltau3poslowTruthbwp2 = new TH1F("hptltau3poslowTruthbwp2","hptltau3poslowTruthbwp2",3,25.,115.);
   TH1F* hptltau3poslowTruthbwp3 = new TH1F("hptltau3poslowTruthbwp3","hptltau3poslowTruthbwp3",3,25.,115.);
   //ss
   TH1F* hptltausslowbwp0 = new TH1F("hptltausslowbwp0","hptltausslowbwp0",3,25.,115.);
   TH1F* hptltausslowbwp1 = new TH1F("hptltausslowbwp1","hptltausslowbwp1",3,25.,115.);
   TH1F* hptltausslowbwp2 = new TH1F("hptltausslowbwp2","hptltausslowbwp2",3,25.,115.);
   TH1F* hptltausslowbwp3 = new TH1F("hptltausslowbwp3","hptltausslowbwp3",3,25.,115.);
   TH1F* hptltausslowTruthbwp0 = new TH1F("hptltausslowTruthbwp0","hptltausslowTruthbwp0",3,25.,115.);
   TH1F* hptltausslowTruthbwp1 = new TH1F("hptltausslowTruthbwp1","hptltausslowTruthbwp1",3,25.,115.);
   TH1F* hptltausslowTruthbwp2 = new TH1F("hptltausslowTruthbwp2","hptltausslowTruthbwp2",3,25.,115.);
   TH1F* hptltausslowTruthbwp3 = new TH1F("hptltausslowTruthbwp3","hptltausslowTruthbwp3",3,25.,115.);
   TH1F* hptltau1psslow = new TH1F("hptltau1psslow","hptltau1psslow",3,25.,115.);
   TH1F* hptltau1psslowTruth = new TH1F("hptltau1psslowTruth","hptltau1psslowTruth",3,25.,115.);
   TH1F* hptltau1psslowbwp0 = new TH1F("hptltau1psslowbwp0","hptltau1psslowbwp0",3,25.,115.);
   TH1F* hptltau1psslowbwp1 = new TH1F("hptltau1psslowbwp1","hptltau1psslowbwp1",3,25.,115.);
   TH1F* hptltau1psslowbwp2 = new TH1F("hptltau1psslowbwp2","hptltau1psslowbwp2",3,25.,115.);
   TH1F* hptltau1psslowbwp3 = new TH1F("hptltau1psslowbwp3","hptltau1psslowbwp3",3,25.,115.);
   TH1F* hptltau1psslowTruthbwp0 = new TH1F("hptltau1psslowTruthbwp0","hptltau1psslowTruthbwp0",3,25.,115.);
   TH1F* hptltau1psslowTruthbwp1 = new TH1F("hptltau1psslowTruthbwp1","hptltau1psslowTruthbwp1",3,25.,115.);
   TH1F* hptltau1psslowTruthbwp2 = new TH1F("hptltau1psslowTruthbwp2","hptltau1psslowTruthbwp2",3,25.,115.);
   TH1F* hptltau1psslowTruthbwp3 = new TH1F("hptltau1psslowTruthbwp3","hptltau1psslowTruthbwp3",3,25.,115.);
   TH1F* hptltau3psslow = new TH1F("hptltau3psslow","hptltau3psslow",3,25.,115.);
   TH1F* hptltau3psslowTruth = new TH1F("hptltau3psslowTruth","hptltau3psslowTruth",3,25.,115.);
   TH1F* hptltau3psslowbwp0 = new TH1F("hptltau3psslowbwp0","hptltau3psslowbwp0",3,25.,115.);
   TH1F* hptltau3psslowbwp1 = new TH1F("hptltau3psslowbwp1","hptltau3psslowbwp1",3,25.,115.);
   TH1F* hptltau3psslowbwp2 = new TH1F("hptltau3psslowbwp2","hptltau3psslowbwp2",3,25.,115.);
   TH1F* hptltau3psslowbwp3 = new TH1F("hptltau3psslowbwp3","hptltau3psslowbwp3",3,25.,115.);
   TH1F* hptltau3psslowTruthbwp0 = new TH1F("hptltau3psslowTruthbwp0","hptltau3psslowTruthbwp0",3,25.,115.);
   TH1F* hptltau3psslowTruthbwp1 = new TH1F("hptltau3psslowTruthbwp1","hptltau3psslowTruthbwp1",3,25.,115.);
   TH1F* hptltau3psslowTruthbwp2 = new TH1F("hptltau3psslowTruthbwp2","hptltau3psslowTruthbwp2",3,25.,115.);
   TH1F* hptltau3psslowTruthbwp3 = new TH1F("hptltau3psslowTruthbwp3","hptltau3psslowTruthbwp3",3,25.,115.);
   //--qcd
   //os
   TH1F* hptltauosqcdbwp0 = new TH1F("hptltauosqcdbwp0","hptltauosqcdbwp0",3,25.,115.);
   TH1F* hptltauosqcdbwp1 = new TH1F("hptltauosqcdbwp1","hptltauosqcdbwp1",3,25.,115.);
   TH1F* hptltauosqcdbwp2 = new TH1F("hptltauosqcdbwp2","hptltauosqcdbwp2",3,25.,115.);
   TH1F* hptltauosqcdbwp3 = new TH1F("hptltauosqcdbwp3","hptltauosqcdbwp3",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp0 = new TH1F("hptltauosqcdTruthbwp0","hptltauosqcdTruthbwp0",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp1 = new TH1F("hptltauosqcdTruthbwp1","hptltauosqcdTruthbwp1",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp2 = new TH1F("hptltauosqcdTruthbwp2","hptltauosqcdTruthbwp2",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp3 = new TH1F("hptltauosqcdTruthbwp3","hptltauosqcdTruthbwp3",3,25.,115.);
   TH1F* hptltau1posqcd = new TH1F("hptltau1posqcd","hptltau1posqcd",3,25.,115.);
   TH1F* hptltau1posqcdTruth = new TH1F("hptltau1posqcdTruth","hptltau1posqcdTruth",3,25.,115.);
   TH1F* hptltau1posqcdbwp0 = new TH1F("hptltau1posqcdbwp0","hptltau1posqcdbwp0",3,25.,115.);
   TH1F* hptltau1posqcdbwp1 = new TH1F("hptltau1posqcdbwp1","hptltau1posqcdbwp1",3,25.,115.);
   TH1F* hptltau1posqcdbwp2 = new TH1F("hptltau1posqcdbwp2","hptltau1posqcdbwp2",3,25.,115.);
   TH1F* hptltau1posqcdbwp3 = new TH1F("hptltau1posqcdbwp3","hptltau1posqcdbwp3",3,25.,115.);
   TH1F* hptltau1posqcdTruthbwp0 = new TH1F("hptltau1posqcdTruthbwp0","hptltau1posqcdTruthbwp0",3,25.,115.);
   TH1F* hptltau1posqcdTruthbwp1 = new TH1F("hptltau1posqcdTruthbwp1","hptltau1posqcdTruthbwp1",3,25.,115.);
   TH1F* hptltau1posqcdTruthbwp2 = new TH1F("hptltau1posqcdTruthbwp2","hptltau1posqcdTruthbwp2",3,25.,115.);
   TH1F* hptltau1posqcdTruthbwp3 = new TH1F("hptltau1posqcdTruthbwp3","hptltau1posqcdTruthbwp3",3,25.,115.);
   TH1F* hptltau3posqcd = new TH1F("hptltau3posqcd","hptltau3posqcd",3,25.,115.);
   TH1F* hptltau3posqcdTruth = new TH1F("hptltau3posqcdTruth","hptltau3posqcdTruth",3,25.,115.);
   TH1F* hptltau3posqcdbwp0 = new TH1F("hptltau3posqcdbwp0","hptltau3posqcdbwp0",3,25.,115.);
   TH1F* hptltau3posqcdbwp1 = new TH1F("hptltau3posqcdbwp1","hptltau3posqcdbwp1",3,25.,115.);
   TH1F* hptltau3posqcdbwp2 = new TH1F("hptltau3posqcdbwp2","hptltau3posqcdbwp2",3,25.,115.);
   TH1F* hptltau3posqcdbwp3 = new TH1F("hptltau3posqcdbwp3","hptltau3posqcdbwp3",3,25.,115.);
   TH1F* hptltau3posqcdTruthbwp0 = new TH1F("hptltau3posqcdTruthbwp0","hptltau3posqcdTruthbwp0",3,25.,115.);
   TH1F* hptltau3posqcdTruthbwp1 = new TH1F("hptltau3posqcdTruthbwp1","hptltau3posqcdTruthbwp1",3,25.,115.);
   TH1F* hptltau3posqcdTruthbwp2 = new TH1F("hptltau3posqcdTruthbwp2","hptltau3posqcdTruthbwp2",3,25.,115.);
   TH1F* hptltau3posqcdTruthbwp3 = new TH1F("hptltau3posqcdTruthbwp3","hptltau3posqcdTruthbwp3",3,25.,115.);
   //ss
   TH1F* hptltaussqcdbwp0 = new TH1F("hptltaussqcdbwp0","hptltaussqcdbwp0",3,25.,115.);
   TH1F* hptltaussqcdbwp1 = new TH1F("hptltaussqcdbwp1","hptltaussqcdbwp1",3,25.,115.);
   TH1F* hptltaussqcdbwp2 = new TH1F("hptltaussqcdbwp2","hptltaussqcdbwp2",3,25.,115.);
   TH1F* hptltaussqcdbwp3 = new TH1F("hptltaussqcdbwp3","hptltaussqcdbwp3",3,25.,115.);
   TH1F* hptltaussqcdTruthbwp0 = new TH1F("hptltaussqcdTruthbwp0","hptltaussqcdTruthbwp0",3,25.,115.);
   TH1F* hptltaussqcdTruthbwp1 = new TH1F("hptltaussqcdTruthbwp1","hptltaussqcdTruthbwp1",3,25.,115.);
   TH1F* hptltaussqcdTruthbwp2 = new TH1F("hptltaussqcdTruthbwp2","hptltaussqcdTruthbwp2",3,25.,115.);
   TH1F* hptltaussqcdTruthbwp3 = new TH1F("hptltaussqcdTruthbwp3","hptltaussqcdTruthbwp3",3,25.,115.);
   TH1F* hptltau1pssqcd = new TH1F("hptltau1pssqcd","hptltau1pssqcd",3,25.,115.);
   TH1F* hptltau1pssqcdTruth = new TH1F("hptltau1pssqcdTruth","hptltau1pssqcdTruth",3,25.,115.);
   TH1F* hptltau1pssqcdbwp0 = new TH1F("hptltau1pssqcdbwp0","hptltau1pssqcdbwp0",3,25.,115.);
   TH1F* hptltau1pssqcdbwp1 = new TH1F("hptltau1pssqcdbwp1","hptltau1pssqcdbwp1",3,25.,115.);
   TH1F* hptltau1pssqcdbwp2 = new TH1F("hptltau1pssqcdbwp2","hptltau1pssqcdbwp2",3,25.,115.);
   TH1F* hptltau1pssqcdbwp3 = new TH1F("hptltau1pssqcdbwp3","hptltau1pssqcdbwp3",3,25.,115.);
   TH1F* hptltau1pssqcdTruthbwp0 = new TH1F("hptltau1pssqcdTruthbwp0","hptltau1pssqcdTruthbwp0",3,25.,115.);
   TH1F* hptltau1pssqcdTruthbwp1 = new TH1F("hptltau1pssqcdTruthbwp1","hptltau1pssqcdTruthbwp1",3,25.,115.);
   TH1F* hptltau1pssqcdTruthbwp2 = new TH1F("hptltau1pssqcdTruthbwp2","hptltau1pssqcdTruthbwp2",3,25.,115.);
   TH1F* hptltau1pssqcdTruthbwp3 = new TH1F("hptltau1pssqcdTruthbwp3","hptltau1pssqcdTruthbwp3",3,25.,115.);
   TH1F* hptltau3pssqcd = new TH1F("hptltau3pssqcd","hptltau3pssqcd",3,25.,115.);
   TH1F* hptltau3pssqcdTruth = new TH1F("hptltau3pssqcdTruth","hptltau3pssqcdTruth",3,25.,115.);
   TH1F* hptltau3pssqcdbwp0 = new TH1F("hptltau3pssqcdbwp0","hptltau3pssqcdbwp0",3,25.,115.);
   TH1F* hptltau3pssqcdbwp1 = new TH1F("hptltau3pssqcdbwp1","hptltau3pssqcdbwp1",3,25.,115.);
   TH1F* hptltau3pssqcdbwp2 = new TH1F("hptltau3pssqcdbwp2","hptltau3pssqcdbwp2",3,25.,115.);
   TH1F* hptltau3pssqcdbwp3 = new TH1F("hptltau3pssqcdbwp3","hptltau3pssqcdbwp3",3,25.,115.);
   TH1F* hptltau3pssqcdTruthbwp0 = new TH1F("hptltau3pssqcdTruthbwp0","hptltau3pssqcdTruthbwp0",3,25.,115.);
   TH1F* hptltau3pssqcdTruthbwp1 = new TH1F("hptltau3pssqcdTruthbwp1","hptltau3pssqcdTruthbwp1",3,25.,115.);
   TH1F* hptltau3pssqcdTruthbwp2 = new TH1F("hptltau3pssqcdTruthbwp2","hptltau3pssqcdTruthbwp2",3,25.,115.);
   TH1F* hptltau3pssqcdTruthbwp3 = new TH1F("hptltau3pssqcdTruthbwp3","hptltau3pssqcdTruthbwp3",3,25.,115.);
   //qcdlow 
   //os
   TH1F* hptltauosqcdlowbwp0 = new TH1F("hptltauosqcdlowbwp0","hptltauosqcdlowbwp0",3,25.,115.);
   TH1F* hptltauosqcdlowbwp1 = new TH1F("hptltauosqcdlowbwp1","hptltauosqcdlowbwp1",3,25.,115.);
   TH1F* hptltauosqcdlowbwp2 = new TH1F("hptltauosqcdlowbwp2","hptltauosqcdlowbwp2",3,25.,115.);
   TH1F* hptltauosqcdlowbwp3 = new TH1F("hptltauosqcdlowbwp3","hptltauosqcdlowbwp3",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp0 = new TH1F("hptltauosqcdlowTruthbwp0","hptltauosqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp1 = new TH1F("hptltauosqcdlowTruthbwp1","hptltauosqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp2 = new TH1F("hptltauosqcdlowTruthbwp2","hptltauosqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp3 = new TH1F("hptltauosqcdlowTruthbwp3","hptltauosqcdlowTruthbwp3",3,25.,115.);
   TH1F* hptltau1posqcdlow = new TH1F("hptltau1posqcdlow","hptltau1posqcdlow",3,25.,115.);
   TH1F* hptltau1posqcdlowTruth = new TH1F("hptltau1posqcdlowTruth","hptltau1posqcdlowTruth",3,25.,115.);
   TH1F* hptltau1posqcdlowbwp0 = new TH1F("hptltau1posqcdlowbwp0","hptltau1posqcdlowbwp0",3,25.,115.);
   TH1F* hptltau1posqcdlowbwp1 = new TH1F("hptltau1posqcdlowbwp1","hptltau1posqcdlowbwp1",3,25.,115.);
   TH1F* hptltau1posqcdlowbwp2 = new TH1F("hptltau1posqcdlowbwp2","hptltau1posqcdlowbwp2",3,25.,115.);
   TH1F* hptltau1posqcdlowbwp3 = new TH1F("hptltau1posqcdlowbwp3","hptltau1posqcdlowbwp3",3,25.,115.);
   TH1F* hptltau1posqcdlowTruthbwp0 = new TH1F("hptltau1posqcdlowTruthbwp0","hptltau1posqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltau1posqcdlowTruthbwp1 = new TH1F("hptltau1posqcdlowTruthbwp1","hptltau1posqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltau1posqcdlowTruthbwp2 = new TH1F("hptltau1posqcdlowTruthbwp2","hptltau1posqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltau1posqcdlowTruthbwp3 = new TH1F("hptltau1posqcdlowTruthbwp3","hptltau1posqcdlowTruthbwp3",3,25.,115.);
   TH1F* hptltau3posqcdlow = new TH1F("hptltau3posqcdlow","hptltau3posqcdlow",3,25.,115.);
   TH1F* hptltau3posqcdlowTruth = new TH1F("hptltau3posqcdlowTruth","hptltau3posqcdlowTruth",3,25.,115.);
   TH1F* hptltau3posqcdlowbwp0 = new TH1F("hptltau3posqcdlowbwp0","hptltau3posqcdlowbwp0",3,25.,115.);
   TH1F* hptltau3posqcdlowbwp1 = new TH1F("hptltau3posqcdlowbwp1","hptltau3posqcdlowbwp1",3,25.,115.);
   TH1F* hptltau3posqcdlowbwp2 = new TH1F("hptltau3posqcdlowbwp2","hptltau3posqcdlowbwp2",3,25.,115.);
   TH1F* hptltau3posqcdlowbwp3 = new TH1F("hptltau3posqcdlowbwp3","hptltau3posqcdlowbwp3",3,25.,115.);
   TH1F* hptltau3posqcdlowTruthbwp0 = new TH1F("hptltau3posqcdlowTruthbwp0","hptltau3posqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltau3posqcdlowTruthbwp1 = new TH1F("hptltau3posqcdlowTruthbwp1","hptltau3posqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltau3posqcdlowTruthbwp2 = new TH1F("hptltau3posqcdlowTruthbwp2","hptltau3posqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltau3posqcdlowTruthbwp3 = new TH1F("hptltau3posqcdlowTruthbwp3","hptltau3posqcdlowTruthbwp3",3,25.,115.);
   //ss
   TH1F* hptltaussqcdlowbwp0 = new TH1F("hptltaussqcdlowbwp0","hptltaussqcdlowbwp0",3,25.,115.);
   TH1F* hptltaussqcdlowbwp1 = new TH1F("hptltaussqcdlowbwp1","hptltaussqcdlowbwp1",3,25.,115.);
   TH1F* hptltaussqcdlowbwp2 = new TH1F("hptltaussqcdlowbwp2","hptltaussqcdlowbwp2",3,25.,115.);
   TH1F* hptltaussqcdlowbwp3 = new TH1F("hptltaussqcdlowbwp3","hptltaussqcdlowbwp3",3,25.,115.);
   TH1F* hptltaussqcdlowTruthbwp0 = new TH1F("hptltaussqcdlowTruthbwp0","hptltaussqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltaussqcdlowTruthbwp1 = new TH1F("hptltaussqcdlowTruthbwp1","hptltaussqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltaussqcdlowTruthbwp2 = new TH1F("hptltaussqcdlowTruthbwp2","hptltaussqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltaussqcdlowTruthbwp3 = new TH1F("hptltaussqcdlowTruthbwp3","hptltaussqcdlowTruthbwp3",3,25.,115.);
   TH1F* hptltau1pssqcdlow = new TH1F("hptltau1pssqcdlow","hptltau1pssqcdlow",3,25.,115.);
   TH1F* hptltau1pssqcdlowTruth = new TH1F("hptltau1pssqcdlowTruth","hptltau1pssqcdlowTruth",3,25.,115.);
   TH1F* hptltau1pssqcdlowbwp0 = new TH1F("hptltau1pssqcdlowbwp0","hptltau1pssqcdlowbwp0",3,25.,115.);
   TH1F* hptltau1pssqcdlowbwp1 = new TH1F("hptltau1pssqcdlowbwp1","hptltau1pssqcdlowbwp1",3,25.,115.);
   TH1F* hptltau1pssqcdlowbwp2 = new TH1F("hptltau1pssqcdlowbwp2","hptltau1pssqcdlowbwp2",3,25.,115.);
   TH1F* hptltau1pssqcdlowbwp3 = new TH1F("hptltau1pssqcdlowbwp3","hptltau1pssqcdlowbwp3",3,25.,115.);
   TH1F* hptltau1pssqcdlowTruthbwp0 = new TH1F("hptltau1pssqcdlowTruthbwp0","hptltau1pssqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltau1pssqcdlowTruthbwp1 = new TH1F("hptltau1pssqcdlowTruthbwp1","hptltau1pssqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltau1pssqcdlowTruthbwp2 = new TH1F("hptltau1pssqcdlowTruthbwp2","hptltau1pssqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltau1pssqcdlowTruthbwp3 = new TH1F("hptltau1pssqcdlowTruthbwp3","hptltau1pssqcdlowTruthbwp3",3,25.,115.);
   TH1F* hptltau3pssqcdlow = new TH1F("hptltau3pssqcdlow","hptltau3pssqcdlow",3,25.,115.);
   TH1F* hptltau3pssqcdlowTruth = new TH1F("hptltau3pssqcdlowTruth","hptltau3pssqcdlowTruth",3,25.,115.);
   TH1F* hptltau3pssqcdlowbwp0 = new TH1F("hptltau3pssqcdlowbwp0","hptltau3pssqcdlowbwp0",3,25.,115.);
   TH1F* hptltau3pssqcdlowbwp1 = new TH1F("hptltau3pssqcdlowbwp1","hptltau3pssqcdlowbwp1",3,25.,115.);
   TH1F* hptltau3pssqcdlowbwp2 = new TH1F("hptltau3pssqcdlowbwp2","hptltau3pssqcdlowbwp2",3,25.,115.);
   TH1F* hptltau3pssqcdlowbwp3 = new TH1F("hptltau3pssqcdlowbwp3","hptltau3pssqcdlowbwp3",3,25.,115.);
   TH1F* hptltau3pssqcdlowTruthbwp0 = new TH1F("hptltau3pssqcdlowTruthbwp0","hptltau3pssqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltau3pssqcdlowTruthbwp1 = new TH1F("hptltau3pssqcdlowTruthbwp1","hptltau3pssqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltau3pssqcdlowTruthbwp2 = new TH1F("hptltau3pssqcdlowTruthbwp2","hptltau3pssqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltau3pssqcdlowTruthbwp3 = new TH1F("hptltau3pssqcdlowTruthbwp3","hptltau3pssqcdlowTruthbwp3",3,25.,115.);
   // may-16 
   TH1F*  hmwltau1posqcdlow = new TH1F("hmwltau1posqcdlow","hmwltau1posqcdlow",30, 0., 150.);
   TH1F*  hmwltau1posqcdlowTruth = new TH1F("hmwltau1posqcdlowTruth","hmwltau1posqcdlowTruth",30, 0., 150.);
   TH1F*  hmwltau3posqcdlow = new TH1F("hmwltau3posqcdlow","hmwltau3posqcdlow",30, 0., 150.);
   TH1F*  hmwltau3posqcdlowTruth = new TH1F("hmwltau3posqcdlowTruth","hmwltau3posqcdlowTruth",30, 0., 150.);
   TH1F*  hmwltau1pssqcdlow = new TH1F("hmwltau1pssqcdlow","hmwltau1pssqcdlow",30, 0., 150.);
   TH1F*  hmwltau1pssqcdlowTruth = new TH1F("hmwltau1pssqcdlowTruth","hmwltau1pssqcdlowTruth",30, 0., 150.);
   TH1F*  hmwltau3pssqcdlow = new TH1F("hmwltau3pssqcdlow","hmwltau3pssqcdlow",30, 0., 150.);
   TH1F*  hmwltau3pssqcdlowTruth = new TH1F("hmwltau3pssqcdlowTruth","hmwltau3pssqcdlowTruth",30, 0., 150.);
   //
   TH1F*  hmwltau1poslow = new TH1F("hmwltau1poslow","hmwltau1poslow",30, 0., 150.);
   TH1F*  hmwltau1poslowTruth = new TH1F("hmwltau1poslowTruth","hmwltau1poslowTruth",30, 0., 150.);
   TH1F*  hmwltau3poslow = new TH1F("hmwltau3poslow","hmwltau3poslow",30, 0., 150.);
   TH1F*  hmwltau3poslowTruth = new TH1F("hmwltau3poslowTruth","hmwltau3poslowTruth",30, 0., 150.);
   TH1F*  hmwltau1psslow = new TH1F("hmwltau1psslow","hmwltau1psslow",30, 0., 150.);
   TH1F*  hmwltau1psslowTruth = new TH1F("hmwltau1psslowTruth","hmwltau1psslowTruth",30, 0., 150.);
   TH1F*  hmwltau3psslow = new TH1F("hmwltau3psslow","hmwltau3psslow",30, 0., 150.);
   TH1F*  hmwltau3psslowTruth = new TH1F("hmwltau3psslowTruth","hmwltau3psslowTruth",30, 0., 150.);
   // 5-22 
   TH1F*  hmwltau1poslowWjj = new TH1F("hmwltau1poslowWjj","hmwltau1poslowWjj",30, 0., 150.);
   TH1F*  hmwltau1poslowbwp0 = new TH1F("hmwltau1poslowbwp0","hmwltau1poslowbwp0",30, 0., 150.);
   TH1F*  hmwltau1poslowbwp1 = new TH1F("hmwltau1poslowbwp1","hmwltau1poslowbwp1",30, 0., 150.);
   TH1F*  hmwltau1poslowbwp2 = new TH1F("hmwltau1poslowbwp2","hmwltau1poslowbwp2",30, 0., 150.);
   TH1F*  hmwltau1poslowbwp3 = new TH1F("hmwltau1poslowbwp3","hmwltau1poslowbwp3",30, 0., 150.);
   TH1F*  hmwltau1psslowWjj = new TH1F("hmwltau1psslowWjj","hmwltau1psslowWjj",30, 0., 150.);
   TH1F*  hmwltau1psslowbwp0 = new TH1F("hmwltau1psslowbwp0","hmwltau1psslowbwp0",30, 0., 150.);
   TH1F*  hmwltau1psslowbwp1 = new TH1F("hmwltau1psslowbwp1","hmwltau1psslowbwp1",30, 0., 150.);
   TH1F*  hmwltau1psslowbwp2 = new TH1F("hmwltau1psslowbwp2","hmwltau1psslowbwp2",30, 0., 150.);
   TH1F*  hmwltau1psslowbwp3 = new TH1F("hmwltau1psslowbwp3","hmwltau1psslowbwp3",30, 0., 150.);
   TH1F*  hmwltau3poslowWjj = new TH1F("hmwltau3poslowWjj","hmwltau3poslowWjj",30, 0., 150.);
   TH1F*  hmwltau3poslowbwp0 = new TH1F("hmwltau3poslowbwp0","hmwltau3poslowbwp0",30, 0., 150.);
   TH1F*  hmwltau3poslowbwp1 = new TH1F("hmwltau3poslowbwp1","hmwltau3poslowbwp1",30, 0., 150.);
   TH1F*  hmwltau3poslowbwp2 = new TH1F("hmwltau3poslowbwp2","hmwltau3poslowbwp2",30, 0., 150.);
   TH1F*  hmwltau3poslowbwp3 = new TH1F("hmwltau3poslowbwp3","hmwltau3poslowbwp3",30, 0., 150.);
   TH1F*  hmwltau3psslowWjj = new TH1F("hmwltau3psslowWjj","hmwltau3psslowWjj",30, 0., 150.);
   TH1F*  hmwltau3psslowbwp0 = new TH1F("hmwltau3psslowbwp0","hmwltau3psslowbwp0",30, 0., 150.);
   TH1F*  hmwltau3psslowbwp1 = new TH1F("hmwltau3psslowbwp1","hmwltau3psslowbwp1",30, 0., 150.);
   TH1F*  hmwltau3psslowbwp2 = new TH1F("hmwltau3psslowbwp2","hmwltau3psslowbwp2",30, 0., 150.);
   TH1F*  hmwltau3psslowbwp3 = new TH1F("hmwltau3psslowbwp3","hmwltau3psslowbwp3",30, 0., 150.);
   // may-17
   TH1F* hnjetltauosqcdlow = new TH1F("hnjetltauosqcdlow","hnjetltauosqcdlow",4,0.,4.);
   TH1F* hnjetltauosqcdlowTruth = new TH1F("hnjetltauosqcdlowTruth","hnjetltauosqcdlowTruth",4,0.,4.);
   TH1F* hnjetltaussqcdlow = new TH1F("hnjetltaussqcdlow","hnjetltaussqcdlow",4,0.,4.);
   TH1F* hnjetltaussqcdlowTruth = new TH1F("hnjetltaussqcdlowTruth","hnjetltaussqcdlowTruth",4,0.,4.);
   TH1F* hnjetltauos = new TH1F("hnjetltauos","hnjetltauos",4,0.,4.);
   TH1F* hnjetltauosTruth = new TH1F("hnjetltauosTruth","hnjetltauosTruth",4,0.,4.);
   TH1F* hnjetltauss = new TH1F("hnjetltauss","hnjetltauss",4,0.,4.);
   TH1F* hnjetltaussTruth = new TH1F("hnjetltaussTruth","hnjetltaussTruth",4,0.,4.);
   // 5-18
   TH1F* hnjetltautightosqcdlow = new TH1F("hnjetltautightosqcdlow","hnjetltautightosqcdlow",4,0.,4.);
   TH1F* hnjetltauosqcdlowbwp1 = new TH1F("hnjetltauosqcdlowbwp1","hnjetltauosqcdlowbwp1",4,0.,4.);
   TH1F* hnjetltautightosqcdlowbwp1 = new TH1F("hnjetltautightosqcdlowbwp1","hnjetltautightosqcdlowbwp1",4,0.,4.);
   TH1F* hnjetltautightosqcdlowTruth = new TH1F("hnjetltautightosqcdlowTruth","hnjetltautightosqcdlowTruth",4,0.,4.);
   TH1F* hnjetltauosqcdlowTruthbwp1 = new TH1F("hnjetltauosqcdlowTruthbwp1","hnjetltauosqcdlowTruthbwp1",4,0.,4.);
   TH1F* hnjetltautightosqcdlowTruthbwp1 = new TH1F("hnjetltautightosqcdlowTruthbwp1","hnjetltautightosqcdlowTruthbwp1",4,0.,4.);
   //
   TH1F* hnjetltautightssqcdlow = new TH1F("hnjetltautightssqcdlow","hnjetltautightssqcdlow",4,0.,4.);
   TH1F* hnjetltaussqcdlowbwp1 = new TH1F("hnjetltaussqcdlowbwp1","hnjetltaussqcdlowbwp1",4,0.,4.);
   TH1F* hnjetltautightssqcdlowbwp1 = new TH1F("hnjetltautightssqcdlowbwp1","hnjetltautightssqcdlowbwp1",4,0.,4.);
   TH1F* hnjetltautightssqcdlowTruth = new TH1F("hnjetltautightssqcdlowTruth","hnjetltautightssqcdlowTruth",4,0.,4.);
   TH1F* hnjetltaussqcdlowTruthbwp1 = new TH1F("hnjetltaussqcdlowTruthbwp1","hnjetltaussqcdlowTruthbwp1",4,0.,4.);
   TH1F* hnjetltautightssqcdlowTruthbwp1 = new TH1F("hnjetltautightssqcdlowTruthbwp1","hnjetltautightssqcdlowTruthbwp1",4,0.,4.);
   //
   TH1F* hnjetltautightos = new TH1F("hnjetltautightos","hnjetltautightos",4,0.,4.);
   TH1F* hnjetltauosbwp1 = new TH1F("hnjetltauosbwp1","hnjetltauosbwp1",4,0.,4.);
   TH1F* hnjetltautightosbwp1 = new TH1F("hnjetltautightosbwp1","hnjetltautightosbwp1",4,0.,4.);
   TH1F* hnjetltautightosTruth = new TH1F("hnjetltautightosTruth","hnjetltautightosTruth",4,0.,4.);
   TH1F* hnjetltauosTruthbwp1 = new TH1F("hnjetltauosTruthbwp1","hnjetltauosTruthbwp1",4,0.,4.);
   TH1F* hnjetltautightosTruthbwp1 = new TH1F("hnjetltautightosTruthbwp1","hnjetltautightosTruthbwp1",4,0.,4.);
   //
   TH1F* hnjetltautightss = new TH1F("hnjetltautightss","hnjetltautightss",4,0.,4.);
   TH1F* hnjetltaussbwp1 = new TH1F("hnjetltaussbwp1","hnjetltaussbwp1",4,0.,4.);
   TH1F* hnjetltautightssbwp1 = new TH1F("hnjetltautightssbwp1","hnjetltautightssbwp1",4,0.,4.);
   TH1F* hnjetltautightssTruth = new TH1F("hnjetltautightssTruth","hnjetltautightssTruth",4,0.,4.);
   TH1F* hnjetltaussTruthbwp1 = new TH1F("hnjetltaussTruthbwp1","hnjetltaussTruthbwp1",4,0.,4.);
   TH1F* hnjetltautightssTruthbwp1 = new TH1F("hnjetltautightssTruthbwp1","hnjetltautightssTruthbwp1",4,0.,4.);
   // 5-24 
   TH1F* hptltau1posbj = new TH1F("hptltau1posbj","hptltau1posbj",3,25.,115.);
   TH1F* hptltau1posbjbwp0 = new TH1F("hptltau1posbjbwp0","hptltau1posbjbwp0",3,25.,115.);
   TH1F* hptltau1posbjbwp1 = new TH1F("hptltau1posbjbwp1","hptltau1posbjbwp1",3,25.,115.);
   TH1F* hptltau1posbjbwp2 = new TH1F("hptltau1posbjbwp2","hptltau1posbjbwp2",3,25.,115.);
   TH1F* hptltau1posbjbwp3 = new TH1F("hptltau1posbjbwp3","hptltau1posbjbwp3",3,25.,115.);
   TH1F* hptltau3posbj = new TH1F("hptltau3posbj","hptltau3posbj",3,25.,115.);
   TH1F* hptltau3posbjbwp0 = new TH1F("hptltau3posbjbwp0","hptltau3posbjbwp0",3,25.,115.);
   TH1F* hptltau3posbjbwp1 = new TH1F("hptltau3posbjbwp1","hptltau3posbjbwp1",3,25.,115.);
   TH1F* hptltau3posbjbwp2 = new TH1F("hptltau3posbjbwp2","hptltau3posbjbwp2",3,25.,115.);
   TH1F* hptltau3posbjbwp3 = new TH1F("hptltau3posbjbwp3","hptltau3posbjbwp3",3,25.,115.);
   TH1F* hptltau1pssbj = new TH1F("hptltau1pssbj","hptltau1pssbj",3,25.,115.);
   TH1F* hptltau1pssbjbwp0 = new TH1F("hptltau1pssbjbwp0","hptltau1pssbjbwp0",3,25.,115.);
   TH1F* hptltau1pssbjbwp1 = new TH1F("hptltau1pssbjbwp1","hptltau1pssbjbwp1",3,25.,115.);
   TH1F* hptltau1pssbjbwp2 = new TH1F("hptltau1pssbjbwp2","hptltau1pssbjbwp2",3,25.,115.);
   TH1F* hptltau1pssbjbwp3 = new TH1F("hptltau1pssbjbwp3","hptltau1pssbjbwp3",3,25.,115.);
   TH1F* hptltau3pssbj = new TH1F("hptltau3pssbj","hptltau3pssbj",3,25.,115.);
   TH1F* hptltau3pssbjbwp0 = new TH1F("hptltau3pssbjbwp0","hptltau3pssbjbwp0",3,25.,115.);
   TH1F* hptltau3pssbjbwp1 = new TH1F("hptltau3pssbjbwp1","hptltau3pssbjbwp1",3,25.,115.);
   TH1F* hptltau3pssbjbwp2 = new TH1F("hptltau3pssbjbwp2","hptltau3pssbjbwp2",3,25.,115.);
   TH1F* hptltau3pssbjbwp3 = new TH1F("hptltau3pssbjbwp3","hptltau3pssbjbwp3",3,25.,115.);
   // 5-25
   TH1F* hptltau1poswj = new TH1F("hptltau1poswj","hptltau1poswj",3,25.,115.);
   TH1F* hptltau1poswjbwp0 = new TH1F("hptltau1poswjbwp0","hptltau1poswjbwp0",3,25.,115.);
   TH1F* hptltau1poswjbwp1 = new TH1F("hptltau1poswjbwp1","hptltau1poswjbwp1",3,25.,115.);
   TH1F* hptltau1poswjbwp2 = new TH1F("hptltau1poswjbwp2","hptltau1poswjbwp2",3,25.,115.);
   TH1F* hptltau1poswjbwp3 = new TH1F("hptltau1poswjbwp3","hptltau1poswjbwp3",3,25.,115.);
   TH1F* hptltau3poswj = new TH1F("hptltau3poswj","hptltau3poswj",3,25.,115.);
   TH1F* hptltau3poswjbwp0 = new TH1F("hptltau3poswjbwp0","hptltau3poswjbwp0",3,25.,115.);
   TH1F* hptltau3poswjbwp1 = new TH1F("hptltau3poswjbwp1","hptltau3poswjbwp1",3,25.,115.);
   TH1F* hptltau3poswjbwp2 = new TH1F("hptltau3poswjbwp2","hptltau3poswjbwp2",3,25.,115.);
   TH1F* hptltau3poswjbwp3 = new TH1F("hptltau3poswjbwp3","hptltau3poswjbwp3",3,25.,115.);
   TH1F* hptltau1psswj = new TH1F("hptltau1psswj","hptltau1psswj",3,25.,115.);
   TH1F* hptltau1psswjbwp0 = new TH1F("hptltau1psswjbwp0","hptltau1psswjbwp0",3,25.,115.);
   TH1F* hptltau1psswjbwp1 = new TH1F("hptltau1psswjbwp1","hptltau1psswjbwp1",3,25.,115.);
   TH1F* hptltau1psswjbwp2 = new TH1F("hptltau1psswjbwp2","hptltau1psswjbwp2",3,25.,115.);
   TH1F* hptltau1psswjbwp3 = new TH1F("hptltau1psswjbwp3","hptltau1psswjbwp3",3,25.,115.);
   TH1F* hptltau3psswj = new TH1F("hptltau3psswj","hptltau3psswj",3,25.,115.);
   TH1F* hptltau3psswjbwp0 = new TH1F("hptltau3psswjbwp0","hptltau3psswjbwp0",3,25.,115.);
   TH1F* hptltau3psswjbwp1 = new TH1F("hptltau3psswjbwp1","hptltau3psswjbwp1",3,25.,115.);
   TH1F* hptltau3psswjbwp2 = new TH1F("hptltau3psswjbwp2","hptltau3psswjbwp2",3,25.,115.);
   TH1F* hptltau3psswjbwp3 = new TH1F("hptltau3psswjbwp3","hptltau3psswjbwp3",3,25.,115.);
   //5-24 fake tau from leptons 
   TH1F* hptltau1poslep = new TH1F("hptltau1poslep","hptltau1poslep",3,25.,115.);
   TH1F* hptltau1poslepbwp0 = new TH1F("hptltau1poslepbwp0","hptltau1poslepbwp0",3,25.,115.);
   TH1F* hptltau1poslepbwp1 = new TH1F("hptltau1poslepbwp1","hptltau1poslepbwp1",3,25.,115.);
   TH1F* hptltau1poslepbwp2 = new TH1F("hptltau1poslepbwp2","hptltau1poslepbwp2",3,25.,115.);
   TH1F* hptltau1poslepbwp3 = new TH1F("hptltau1poslepbwp3","hptltau1poslepbwp3",3,25.,115.);
   TH1F* hptltau1poslowlep = new TH1F("hptltau1poslowlep","hptltau1poslowlep",3,25.,115.);
   TH1F* hptltau1poslowlepbwp0 = new TH1F("hptltau1poslowlepbwp0","hptltau1poslowlepbwp0",3,25.,115.);
   TH1F* hptltau1poslowlepbwp1 = new TH1F("hptltau1poslowlepbwp1","hptltau1poslowlepbwp1",3,25.,115.);
   TH1F* hptltau1poslowlepbwp2 = new TH1F("hptltau1poslowlepbwp2","hptltau1poslowlepbwp2",3,25.,115.);
   TH1F* hptltau1poslowlepbwp3 = new TH1F("hptltau1poslowlepbwp3","hptltau1poslowlepbwp3",3,25.,115.);
   TH1F* hmwltau1poslowlep = new TH1F("hmwltau1poslowlep","hmwltau1poslowlep",30, 0., 150.);
   TH1F* hptltau3poslep = new TH1F("hptltau3poslep","hptltau3poslep",3,25.,115.);
   TH1F* hptltau3poslepbwp0 = new TH1F("hptltau3poslepbwp0","hptltau3poslepbwp0",3,25.,115.);
   TH1F* hptltau3poslepbwp1 = new TH1F("hptltau3poslepbwp1","hptltau3poslepbwp1",3,25.,115.);
   TH1F* hptltau3poslepbwp2 = new TH1F("hptltau3poslepbwp2","hptltau3poslepbwp2",3,25.,115.);
   TH1F* hptltau3poslepbwp3 = new TH1F("hptltau3poslepbwp3","hptltau3poslepbwp3",3,25.,115.);
   TH1F* hptltau3poslowlep = new TH1F("hptltau3poslowlep","hptltau3poslowlep",3,25.,115.);
   TH1F* hptltau3poslowlepbwp0 = new TH1F("hptltau3poslowlepbwp0","hptltau3poslowlepbwp0",3,25.,115.);
   TH1F* hptltau3poslowlepbwp1 = new TH1F("hptltau3poslowlepbwp1","hptltau3poslowlepbwp1",3,25.,115.);
   TH1F* hptltau3poslowlepbwp2 = new TH1F("hptltau3poslowlepbwp2","hptltau3poslowlepbwp2",3,25.,115.);
   TH1F* hptltau3poslowlepbwp3 = new TH1F("hptltau3poslowlepbwp3","hptltau3poslowlepbwp3",3,25.,115.);
   TH1F* hmwltau3poslowlep = new TH1F("hmwltau3poslowlep","hmwltau3poslowlep",30, 0., 150.);
   TH1F* hptltau1psslep = new TH1F("hptltau1psslep","hptltau1psslep",3,25.,115.);
   TH1F* hptltau1psslepbwp0 = new TH1F("hptltau1psslepbwp0","hptltau1psslepbwp0",3,25.,115.);
   TH1F* hptltau1psslepbwp1 = new TH1F("hptltau1psslepbwp1","hptltau1psslepbwp1",3,25.,115.);
   TH1F* hptltau1psslepbwp2 = new TH1F("hptltau1psslepbwp2","hptltau1psslepbwp2",3,25.,115.);
   TH1F* hptltau1psslepbwp3 = new TH1F("hptltau1psslepbwp3","hptltau1psslepbwp3",3,25.,115.);
   TH1F* hptltau1psslowlep = new TH1F("hptltau1psslowlep","hptltau1psslowlep",3,25.,115.);
   TH1F* hptltau1psslowlepbwp0 = new TH1F("hptltau1psslowlepbwp0","hptltau1psslowlepbwp0",3,25.,115.);
   TH1F* hptltau1psslowlepbwp1 = new TH1F("hptltau1psslowlepbwp1","hptltau1psslowlepbwp1",3,25.,115.);
   TH1F* hptltau1psslowlepbwp2 = new TH1F("hptltau1psslowlepbwp2","hptltau1psslowlepbwp2",3,25.,115.);
   TH1F* hptltau1psslowlepbwp3 = new TH1F("hptltau1psslowlepbwp3","hptltau1psslowlepbwp3",3,25.,115.);
   TH1F* hmwltau1psslowlep = new TH1F("hmwltau1psslowlep","hmwltau1psslowlep",30, 0., 150.);
   TH1F* hptltau3psslep = new TH1F("hptltau3psslep","hptltau3psslep",3,25.,115.);
   TH1F* hptltau3psslepbwp0 = new TH1F("hptltau3psslepbwp0","hptltau3psslepbwp0",3,25.,115.);
   TH1F* hptltau3psslepbwp1 = new TH1F("hptltau3psslepbwp1","hptltau3psslepbwp1",3,25.,115.);
   TH1F* hptltau3psslepbwp2 = new TH1F("hptltau3psslepbwp2","hptltau3psslepbwp2",3,25.,115.);
   TH1F* hptltau3psslepbwp3 = new TH1F("hptltau3psslepbwp3","hptltau3psslepbwp3",3,25.,115.);
   TH1F* hptltau3psslowlep = new TH1F("hptltau3psslowlep","hptltau3psslowlep",3,25.,115.);
   TH1F* hptltau3psslowlepbwp0 = new TH1F("hptltau3psslowlepbwp0","hptltau3psslowlepbwp0",3,25.,115.);
   TH1F* hptltau3psslowlepbwp1 = new TH1F("hptltau3psslowlepbwp1","hptltau3psslowlepbwp1",3,25.,115.);
   TH1F* hptltau3psslowlepbwp2 = new TH1F("hptltau3psslowlepbwp2","hptltau3psslowlepbwp2",3,25.,115.);
   TH1F* hptltau3psslowlepbwp3 = new TH1F("hptltau3psslowlepbwp3","hptltau3psslowlepbwp3",3,25.,115.);
   TH1F* hmwltau3psslowlep = new TH1F("hmwltau3psslowlep","hmwltau3psslowlep",30, 0., 150.);
   // 5-25
   TH1F* hptltau1poslowwj = new TH1F("hptltau1poslowwj","hptltau1poslowwj",3,25.,115.);
   TH1F* hptltau1poslowwjbwp0 = new TH1F("hptltau1poslowwjbwp0","hptltau1poslowwjbwp0",3,25.,115.);
   TH1F* hptltau1poslowwjbwp1 = new TH1F("hptltau1poslowwjbwp1","hptltau1poslowwjbwp1",3,25.,115.);
   TH1F* hptltau1poslowwjbwp2 = new TH1F("hptltau1poslowwjbwp2","hptltau1poslowwjbwp2",3,25.,115.);
   TH1F* hptltau1poslowwjbwp3 = new TH1F("hptltau1poslowwjbwp3","hptltau1poslowwjbwp3",3,25.,115.);
   TH1F* hptltau3poslowwj = new TH1F("hptltau3poslowwj","hptltau3poslowwj",3,25.,115.);
   TH1F* hptltau3poslowwjbwp0 = new TH1F("hptltau3poslowwjbwp0","hptltau3poslowwjbwp0",3,25.,115.);
   TH1F* hptltau3poslowwjbwp1 = new TH1F("hptltau3poslowwjbwp1","hptltau3poslowwjbwp1",3,25.,115.);
   TH1F* hptltau3poslowwjbwp2 = new TH1F("hptltau3poslowwjbwp2","hptltau3poslowwjbwp2",3,25.,115.);
   TH1F* hptltau3poslowwjbwp3 = new TH1F("hptltau3poslowwjbwp3","hptltau3poslowwjbwp3",3,25.,115.);
   TH1F* hptltau1psslowwj = new TH1F("hptltau1psslowwj","hptltau1psslowwj",3,25.,115.);
   TH1F* hptltau1psslowwjbwp0 = new TH1F("hptltau1psslowwjbwp0","hptltau1psslowwjbwp0",3,25.,115.);
   TH1F* hptltau1psslowwjbwp1 = new TH1F("hptltau1psslowwjbwp1","hptltau1psslowwjbwp1",3,25.,115.);
   TH1F* hptltau1psslowwjbwp2 = new TH1F("hptltau1psslowwjbwp2","hptltau1psslowwjbwp2",3,25.,115.);
   TH1F* hptltau1psslowwjbwp3 = new TH1F("hptltau1psslowwjbwp3","hptltau1psslowwjbwp3",3,25.,115.);
   TH1F* hptltau3psslowwj = new TH1F("hptltau3psslowwj","hptltau3psslowwj",3,25.,115.);
   TH1F* hptltau3psslowwjbwp0 = new TH1F("hptltau3psslowwjbwp0","hptltau3psslowwjbwp0",3,25.,115.);
   TH1F* hptltau3psslowwjbwp1 = new TH1F("hptltau3psslowwjbwp1","hptltau3psslowwjbwp1",3,25.,115.);
   TH1F* hptltau3psslowwjbwp2 = new TH1F("hptltau3psslowwjbwp2","hptltau3psslowwjbwp2",3,25.,115.);
   TH1F* hptltau3psslowwjbwp3 = new TH1F("hptltau3psslowwjbwp3","hptltau3psslowwjbwp3",3,25.,115.);
   // 5-25
   TH1F* hptltau1poslowbj = new TH1F("hptltau1poslowbj","hptltau1poslowbj",3,25.,115.);
   TH1F* hptltau1poslowbjbwp0 = new TH1F("hptltau1poslowbjbwp0","hptltau1poslowbjbwp0",3,25.,115.);
   TH1F* hptltau1poslowbjbwp1 = new TH1F("hptltau1poslowbjbwp1","hptltau1poslowbjbwp1",3,25.,115.);
   TH1F* hptltau1poslowbjbwp2 = new TH1F("hptltau1poslowbjbwp2","hptltau1poslowbjbwp2",3,25.,115.);
   TH1F* hptltau1poslowbjbwp3 = new TH1F("hptltau1poslowbjbwp3","hptltau1poslowbjbwp3",3,25.,115.);
   TH1F* hptltau3poslowbj = new TH1F("hptltau3poslowbj","hptltau3poslowbj",3,25.,115.);
   TH1F* hptltau3poslowbjbwp0 = new TH1F("hptltau3poslowbjbwp0","hptltau3poslowbjbwp0",3,25.,115.);
   TH1F* hptltau3poslowbjbwp1 = new TH1F("hptltau3poslowbjbwp1","hptltau3poslowbjbwp1",3,25.,115.);
   TH1F* hptltau3poslowbjbwp2 = new TH1F("hptltau3poslowbjbwp2","hptltau3poslowbjbwp2",3,25.,115.);
   TH1F* hptltau3poslowbjbwp3 = new TH1F("hptltau3poslowbjbwp3","hptltau3poslowbjbwp3",3,25.,115.);
   TH1F* hptltau1psslowbj = new TH1F("hptltau1psslowbj","hptltau1psslowbj",3,25.,115.);
   TH1F* hptltau1psslowbjbwp0 = new TH1F("hptltau1psslowbjbwp0","hptltau1psslowbjbwp0",3,25.,115.);
   TH1F* hptltau1psslowbjbwp1 = new TH1F("hptltau1psslowbjbwp1","hptltau1psslowbjbwp1",3,25.,115.);
   TH1F* hptltau1psslowbjbwp2 = new TH1F("hptltau1psslowbjbwp2","hptltau1psslowbjbwp2",3,25.,115.);
   TH1F* hptltau1psslowbjbwp3 = new TH1F("hptltau1psslowbjbwp3","hptltau1psslowbjbwp3",3,25.,115.);
   TH1F* hptltau3psslowbj = new TH1F("hptltau3psslowbj","hptltau3psslowbj",3,25.,115.);
   TH1F* hptltau3psslowbjbwp0 = new TH1F("hptltau3psslowbjbwp0","hptltau3psslowbjbwp0",3,25.,115.);
   TH1F* hptltau3psslowbjbwp1 = new TH1F("hptltau3psslowbjbwp1","hptltau3psslowbjbwp1",3,25.,115.);
   TH1F* hptltau3psslowbjbwp2 = new TH1F("hptltau3psslowbjbwp2","hptltau3psslowbjbwp2",3,25.,115.);
   TH1F* hptltau3psslowbjbwp3 = new TH1F("hptltau3psslowbjbwp3","hptltau3psslowbjbwp3",3,25.,115.);
   // 5-26
   TH1F* hmwltau1poslowbj = new TH1F("hmwltau1poslowbj","hmwltau1poslowbj",30, 0., 150.);
   TH1F* hmwltau3poslowbj = new TH1F("hmwltau3poslowbj","hmwltau3poslowbj",30, 0., 150.);
   TH1F* hmwltau1psslowbj = new TH1F("hmwltau1psslowbj","hmwltau1psslowbj",30, 0., 150.);
   TH1F* hmwltau3psslowbj = new TH1F("hmwltau3psslowbj","hmwltau3psslowbj",30, 0., 150.);
   // 5-29 
   TH1F* hjfltauos1B = new TH1F("hjfltauos1B","hjfltauos1B", 26, -1., 25.);
   TH1F* hmwltauos1Bbj = new TH1F("hmwltauos1Bbj","hmwltauos1Bbj",30, 0., 150.);
   TH1F* hjfltauss1B = new TH1F("hjfltauss1B","hjfltauss1B", 26, -1., 25.);
   TH1F* hmwltauss1Bbj = new TH1F("hmwltauss1Bbj","hmwltauss1Bbj",30, 0., 150.);
   TH1F* hmwltau3posqcd = new TH1F("hmwltau3posqcd","hmwltau3posqcd",30, 0., 150.);
   TH1F* hmwltau3posqcdTruth = new TH1F("hmwltau3posqcdTruth","hmwltau3posqcdTruth",30, 0., 150.);
   TH1F* hmwltau3pssqcd = new TH1F("hmwltau3pssqcd","hmwltau3pssqcd",30, 0., 150.);
   TH1F* hmwltau3pssqcdTruth = new TH1F("hmwltau3pssqcdTruth","hmwltau3pssqcdTruth",30, 0., 150.);
   TH1F* hmwltau3posmetlow = new TH1F("hmwltau3posmetlow","hmwltau3posmetlow",30, 0., 150.);
   TH1F* hmwltau3posmetlowTruth = new TH1F("hmwltau3posmetlowTruth","hmwltau3posmetlowTruth",30, 0., 150.);
   TH1F* hmwltau3pssmetlow = new TH1F("hmwltau3pssmetlow","hmwltau3pssmetlow",30, 0., 150.);
   TH1F* hmwltau3pssmetlowTruth = new TH1F("hmwltau3pssmetlowTruth","hmwltau3pssmetlowTruth",30, 0., 150.);
   //
   TH1F* hptltau1posmetlow = new TH1F("hptltau1posmetlow","hptltau1posmetlow",3,25.,115.);
   TH1F* hptltau1posmetlowTruth = new TH1F("hptltau1posmetlowTruth","hptltau1posmetlowTruth",3,25.,115.);
   TH1F* hptltau1posmetlowbwp0 = new TH1F("hptltau1posmetlowbwp0","hptltau1posmetlowbwp0",3,25.,115.);
   TH1F* hptltau1posmetlowbwp1 = new TH1F("hptltau1posmetlowbwp1","hptltau1posmetlowbwp1",3,25.,115.);
   TH1F* hptltau1posmetlowbwp2 = new TH1F("hptltau1posmetlowbwp2","hptltau1posmetlowbwp2",3,25.,115.);
   TH1F* hptltau1posmetlowbwp3 = new TH1F("hptltau1posmetlowbwp3","hptltau1posmetlowbwp3",3,25.,115.);
   TH1F* hptltau1posmetlowTruthbwp0 = new TH1F("hptltau1posmetlowTruthbwp0","hptltau1posmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltau1posmetlowTruthbwp1 = new TH1F("hptltau1posmetlowTruthbwp1","hptltau1posmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltau1posmetlowTruthbwp2 = new TH1F("hptltau1posmetlowTruthbwp2","hptltau1posmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltau1posmetlowTruthbwp3 = new TH1F("hptltau1posmetlowTruthbwp3","hptltau1posmetlowTruthbwp3",3,25.,115.);
   //
   TH1F* hptltau3posmetlow = new TH1F("hptltau3posmetlow","hptltau3posmetlow",3,25.,115.);
   TH1F* hptltau3posmetlowTruth = new TH1F("hptltau3posmetlowTruth","hptltau3posmetlowTruth",3,25.,115.);
   TH1F* hptltau3posmetlowbwp0 = new TH1F("hptltau3posmetlowbwp0","hptltau3posmetlowbwp0",3,25.,115.);
   TH1F* hptltau3posmetlowbwp1 = new TH1F("hptltau3posmetlowbwp1","hptltau3posmetlowbwp1",3,25.,115.);
   TH1F* hptltau3posmetlowbwp2 = new TH1F("hptltau3posmetlowbwp2","hptltau3posmetlowbwp2",3,25.,115.);
   TH1F* hptltau3posmetlowbwp3 = new TH1F("hptltau3posmetlowbwp3","hptltau3posmetlowbwp3",3,25.,115.);
   TH1F* hptltau3posmetlowTruthbwp0 = new TH1F("hptltau3posmetlowTruthbwp0","hptltau3posmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltau3posmetlowTruthbwp1 = new TH1F("hptltau3posmetlowTruthbwp1","hptltau3posmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltau3posmetlowTruthbwp2 = new TH1F("hptltau3posmetlowTruthbwp2","hptltau3posmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltau3posmetlowTruthbwp3 = new TH1F("hptltau3posmetlowTruthbwp3","hptltau3posmetlowTruthbwp3",3,25.,115.);
   //
   TH1F* hptltau1pssmetlow = new TH1F("hptltau1pssmetlow","hptltau1posmetlow",3,25.,115.);
   TH1F* hptltau1pssmetlowTruth = new TH1F("hptltau1pssmetlowTruth","hptltau1posmetlowTruth",3,25.,115.);
   TH1F* hptltau1pssmetlowbwp0 = new TH1F("hptltau1pssmetlowbwp0","hptltau1posmetlowbwp0",3,25.,115.);
   TH1F* hptltau1pssmetlowbwp1 = new TH1F("hptltau1pssmetlowbwp1","hptltau1posmetlowbwp1",3,25.,115.);
   TH1F* hptltau1pssmetlowbwp2 = new TH1F("hptltau1pssmetlowbwp2","hptltau1posmetlowbwp2",3,25.,115.);
   TH1F* hptltau1pssmetlowbwp3 = new TH1F("hptltau1pssmetlowbwp3","hptltau1posmetlowbwp3",3,25.,115.);
   TH1F* hptltau1pssmetlowTruthbwp0 = new TH1F("hptltau1pssmetlowTruthbwp0","hptltau1posmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltau1pssmetlowTruthbwp1 = new TH1F("hptltau1pssmetlowTruthbwp1","hptltau1posmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltau1pssmetlowTruthbwp2 = new TH1F("hptltau1pssmetlowTruthbwp2","hptltau1posmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltau1pssmetlowTruthbwp3 = new TH1F("hptltau1pssmetlowTruthbwp3","hptltau1posmetlowTruthbwp3",3,25.,115.);
   // 
   TH1F* hptltau3pssmetlow = new TH1F("hptltau3pssmetlow","hptltau3pssmetlow",3,25.,115.);
   TH1F* hptltau3pssmetlowTruth = new TH1F("hptltau3pssmetlowTruth","hptltau3pssmetlowTruth",3,25.,115.);
   TH1F* hptltau3pssmetlowbwp0 = new TH1F("hptltau3pssmetlowbwp0","hptltau3pssmetlowbwp0",3,25.,115.);
   TH1F* hptltau3pssmetlowbwp1 = new TH1F("hptltau3pssmetlowbwp1","hptltau3pssmetlowbwp1",3,25.,115.);
   TH1F* hptltau3pssmetlowbwp2 = new TH1F("hptltau3pssmetlowbwp2","hptltau3pssmetlowbwp2",3,25.,115.);
   TH1F* hptltau3pssmetlowbwp3 = new TH1F("hptltau3pssmetlowbwp3","hptltau3pssmetlowbwp3",3,25.,115.);
   TH1F* hptltau3pssmetlowTruthbwp0 = new TH1F("hptltau3pssmetlowTruthbwp0","hptltau3pssmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltau3pssmetlowTruthbwp1 = new TH1F("hptltau3pssmetlowTruthbwp1","hptltau3pssmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltau3pssmetlowTruthbwp2 = new TH1F("hptltau3pssmetlowTruthbwp2","hptltau3pssmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltau3pssmetlowTruthbwp3 = new TH1F("hptltau3pssmetlowTruthbwp3","hptltau3pssmetlowTruthbwp3",3,25.,115.);
   // 5-30 (12*4=48)
   TH1F* hjfmtauemu1B = new TH1F("hjfmtauemu1B","hjfmtauemu1B", 26, -1., 25.);
   TH1F* hjfmtauemu1Bbwp1 = new TH1F("hjfmtauemu1Bbwp1","hjfmtauemu1Bbwp1", 26, -1., 25.);
   TH1F* hptmtauemu1B = new TH1F("hptmtauemu1B","hptmtauemu1B",3,25.,115.);
   TH1F* hptmtauemu1Bbwp0 = new TH1F("hptmtauemu1Bbwp0","hptmtauemu1Bbwp0",3,25.,115.);
   TH1F* hptmtauemu1Bbwp1 = new TH1F("hptmtauemu1Bbwp1","hptmtauemu1Bbwp1",3,25.,115.);
   TH1F* hptmtauemu1Bbwp2 = new TH1F("hptmtauemu1Bbwp2","hptmtauemu1Bbwp2",3,25.,115.);
   TH1F* hptmtauemu1Bbwp3 = new TH1F("hptmtauemu1Bbwp3","hptmtauemu1Bbwp3",3,25.,115.);
   TH1F* hptmtauemu1BTruth = new TH1F("hptmtauemu1BTruth","hptmtauemu1BTruth",3,25.,115.);
   TH1F* hptmtauemu1BTruthbwp0 = new TH1F("hptmtauemu1BTruthbwp0","hptmtauemu1BTruthbwp0",3,25.,115.);
   TH1F* hptmtauemu1BTruthbwp1 = new TH1F("hptmtauemu1BTruthbwp1","hptmtauemu1BTruthbwp1",3,25.,115.);
   TH1F* hptmtauemu1BTruthbwp2 = new TH1F("hptmtauemu1BTruthbwp2","hptmtauemu1BTruthbwp2",3,25.,115.);
   TH1F* hptmtauemu1BTruthbwp3 = new TH1F("hptmtauemu1BTruthbwp3","hptmtauemu1BTruthbwp3",3,25.,115.);
   //
   TH1F* hjftauemu1B = new TH1F("hjftauemu1B","hjftauemu1B", 26, -1., 25.);
   TH1F* hjftauemu1Bbwp1 = new TH1F("hjftauemu1Bbwp1","hjftauemu1Bbwp1", 26, -1., 25.);
   TH1F* hpttauemu1B = new TH1F("hpttauemu1B","hpttauemu1B",3,25.,115.);
   TH1F* hpttauemu1Bbwp0 = new TH1F("hpttauemu1Bbwp0","hpttauemu1Bbwp0",3,25.,115.);
   TH1F* hpttauemu1Bbwp1 = new TH1F("hpttauemu1Bbwp1","hpttauemu1Bbwp1",3,25.,115.);
   TH1F* hpttauemu1Bbwp2 = new TH1F("hpttauemu1Bbwp2","hpttauemu1Bbwp2",3,25.,115.);
   TH1F* hpttauemu1Bbwp3 = new TH1F("hpttauemu1Bbwp3","hpttauemu1Bbwp3",3,25.,115.);
   TH1F* hpttauemu1BTruth = new TH1F("hpttauemu1BTruth","hpttauemu1BTruth",3,25.,115.);
   TH1F* hpttauemu1BTruthbwp0 = new TH1F("hpttauemu1BTruthbwp0","hpttauemu1BTruthbwp0",3,25.,115.);
   TH1F* hpttauemu1BTruthbwp1 = new TH1F("hpttauemu1BTruthbwp1","hpttauemu1BTruthbwp1",3,25.,115.);
   TH1F* hpttauemu1BTruthbwp2 = new TH1F("hpttauemu1BTruthbwp2","hpttauemu1BTruthbwp2",3,25.,115.);
   TH1F* hpttauemu1BTruthbwp3 = new TH1F("hpttauemu1BTruthbwp3","hpttauemu1BTruthbwp3",3,25.,115.);
   // 2B
   TH1F* hjfmtauemu2B = new TH1F("hjfmtauemu2B","hjfmtauemu2B", 26, -1., 25.);
   TH1F* hjfmtauemu2Bbwp1 = new TH1F("hjfmtauemu2Bbwp1","hjfmtauemu2Bbwp1", 26, -1., 25.);
   TH1F* hptmtauemu2B = new TH1F("hptmtauemu2B","hptmtauemu2B",3,25.,115.);
   TH1F* hptmtauemu2Bbwp0 = new TH1F("hptmtauemu2Bbwp0","hptmtauemu2Bbwp0",3,25.,115.);
   TH1F* hptmtauemu2Bbwp1 = new TH1F("hptmtauemu2Bbwp1","hptmtauemu2Bbwp1",3,25.,115.);
   TH1F* hptmtauemu2Bbwp2 = new TH1F("hptmtauemu2Bbwp2","hptmtauemu2Bbwp2",3,25.,115.);
   TH1F* hptmtauemu2Bbwp3 = new TH1F("hptmtauemu2Bbwp3","hptmtauemu2Bbwp3",3,25.,115.);
   TH1F* hptmtauemu2BTruth = new TH1F("hptmtauemu2BTruth","hptmtauemu2BTruth",3,25.,115.);
   TH1F* hptmtauemu2BTruthbwp0 = new TH1F("hptmtauemu2BTruthbwp0","hptmtauemu2BTruthbwp0",3,25.,115.);
   TH1F* hptmtauemu2BTruthbwp1 = new TH1F("hptmtauemu2BTruthbwp1","hptmtauemu2BTruthbwp1",3,25.,115.);
   TH1F* hptmtauemu2BTruthbwp2 = new TH1F("hptmtauemu2BTruthbwp2","hptmtauemu2BTruthbwp2",3,25.,115.);
   TH1F* hptmtauemu2BTruthbwp3 = new TH1F("hptmtauemu2BTruthbwp3","hptmtauemu2BTruthbwp3",3,25.,115.);
   //
   TH1F* hjftauemu2B = new TH1F("hjftauemu2B","hjftauemu2B", 26, -1., 25.);
   TH1F* hjftauemu2Bbwp1 = new TH1F("hjftauemu2Bbwp1","hjftauemu2Bbwp1", 26, -1., 25.);
   TH1F* hpttauemu2B = new TH1F("hpttauemu2B","hpttauemu2B",3,25.,115.);
   TH1F* hpttauemu2Bbwp0 = new TH1F("hpttauemu2Bbwp0","hpttauemu2Bbwp0",3,25.,115.);
   TH1F* hpttauemu2Bbwp1 = new TH1F("hpttauemu2Bbwp1","hpttauemu2Bbwp1",3,25.,115.);
   TH1F* hpttauemu2Bbwp2 = new TH1F("hpttauemu2Bbwp2","hpttauemu2Bbwp2",3,25.,115.);
   TH1F* hpttauemu2Bbwp3 = new TH1F("hpttauemu2Bbwp3","hpttauemu2Bbwp3",3,25.,115.);
   TH1F* hpttauemu2BTruth = new TH1F("hpttauemu2BTruth","hpttauemu2BTruth",3,25.,115.);
   TH1F* hpttauemu2BTruthbwp0 = new TH1F("hpttauemu2BTruthbwp0","hpttauemu2BTruthbwp0",3,25.,115.);
   TH1F* hpttauemu2BTruthbwp1 = new TH1F("hpttauemu2BTruthbwp1","hpttauemu2BTruthbwp1",3,25.,115.);
   TH1F* hpttauemu2BTruthbwp2 = new TH1F("hpttauemu2BTruthbwp2","hpttauemu2BTruthbwp2",3,25.,115.);
   TH1F* hpttauemu2BTruthbwp3 = new TH1F("hpttauemu2BTruthbwp3","hpttauemu2BTruthbwp3",3,25.,115.);
   // 5-31 (20*3)
   TH1F* hptmtauemu1Bbj = new TH1F("hptmtauemu1Bbj","hptmtauemu1Bbj",3,25.,115.);
   TH1F* hptmtauemu1Bbjbwp0 = new TH1F("hptmtauemu1Bbjbwp0","hptmtauemu1Bbjbwp0",3,25.,115.);
   TH1F* hptmtauemu1Bbjbwp1 = new TH1F("hptmtauemu1Bbjbwp1","hptmtauemu1Bbjbwp1",3,25.,115.);
   TH1F* hptmtauemu1Bbjbwp2 = new TH1F("hptmtauemu1Bbjbwp2","hptmtauemu1Bbjbwp2",3,25.,115.);
   TH1F* hptmtauemu1Bbjbwp3 = new TH1F("hptmtauemu1Bbjbwp3","hptmtauemu1Bbjbwp3",3,25.,115.);
   TH1F* hpttauemu1Bbj = new TH1F("hpttauemu1Bbj","hpttauemu1Bbj",3,25.,115.);
   TH1F* hpttauemu1Bbjbwp0 = new TH1F("hpttauemu1Bbjbwp0","hpttauemu1Bbjbwp0",3,25.,115.);
   TH1F* hpttauemu1Bbjbwp1 = new TH1F("hpttauemu1Bbjbwp1","hpttauemu1Bbjbwp1",3,25.,115.);
   TH1F* hpttauemu1Bbjbwp2 = new TH1F("hpttauemu1Bbjbwp2","hpttauemu1Bbjbwp2",3,25.,115.);
   TH1F* hpttauemu1Bbjbwp3 = new TH1F("hpttauemu1Bbjbwp3","hpttauemu1Bbjbwp3",3,25.,115.);
   TH1F* hptmtauemu2Bbj = new TH1F("hptmtauemu2Bbj","hptmtauemu2Bbj",3,25.,115.);
   TH1F* hptmtauemu2Bbjbwp0 = new TH1F("hptmtauemu2Bbjbwp0","hptmtauemu2Bbjbwp0",3,25.,115.);
   TH1F* hptmtauemu2Bbjbwp1 = new TH1F("hptmtauemu2Bbjbwp1","hptmtauemu2Bbjbwp1",3,25.,115.);
   TH1F* hptmtauemu2Bbjbwp2 = new TH1F("hptmtauemu2Bbjbwp2","hptmtauemu2Bbjbwp2",3,25.,115.);
   TH1F* hptmtauemu2Bbjbwp3 = new TH1F("hptmtauemu2Bbjbwp3","hptmtauemu2Bbjbwp3",3,25.,115.);
   TH1F* hpttauemu2Bbj = new TH1F("hpttauemu2Bbj","hpttauemu2Bbj",3,25.,115.);
   TH1F* hpttauemu2Bbjbwp0 = new TH1F("hpttauemu2Bbjbwp0","hpttauemu2Bbjbwp0",3,25.,115.);
   TH1F* hpttauemu2Bbjbwp1 = new TH1F("hpttauemu2Bbjbwp1","hpttauemu2Bbjbwp1",3,25.,115.);
   TH1F* hpttauemu2Bbjbwp2 = new TH1F("hpttauemu2Bbjbwp2","hpttauemu2Bbjbwp2",3,25.,115.);
   TH1F* hpttauemu2Bbjbwp3 = new TH1F("hpttauemu2Bbjbwp3","hpttauemu2Bbjbwp3",3,25.,115.);
   //
   TH1F* hptmtauemu1Bwj = new TH1F("hptmtauemu1Bwj","hptmtauemu1Bwj",3,25.,115.);
   TH1F* hptmtauemu1Bwjbwp0 = new TH1F("hptmtauemu1Bwjbwp0","hptmtauemu1Bwjbwp0",3,25.,115.);
   TH1F* hptmtauemu1Bwjbwp1 = new TH1F("hptmtauemu1Bwjbwp1","hptmtauemu1Bwjbwp1",3,25.,115.);
   TH1F* hptmtauemu1Bwjbwp2 = new TH1F("hptmtauemu1Bwjbwp2","hptmtauemu1Bwjbwp2",3,25.,115.);
   TH1F* hptmtauemu1Bwjbwp3 = new TH1F("hptmtauemu1Bwjbwp3","hptmtauemu1Bwjbwp3",3,25.,115.);
   TH1F* hpttauemu1Bwj = new TH1F("hpttauemu1Bwj","hpttauemu1Bwj",3,25.,115.);
   TH1F* hpttauemu1Bwjbwp0 = new TH1F("hpttauemu1Bwjbwp0","hpttauemu1Bwjbwp0",3,25.,115.);
   TH1F* hpttauemu1Bwjbwp1 = new TH1F("hpttauemu1Bwjbwp1","hpttauemu1Bwjbwp1",3,25.,115.);
   TH1F* hpttauemu1Bwjbwp2 = new TH1F("hpttauemu1Bwjbwp2","hpttauemu1Bwjbwp2",3,25.,115.);
   TH1F* hpttauemu1Bwjbwp3 = new TH1F("hpttauemu1Bwjbwp3","hpttauemu1Bwjbwp3",3,25.,115.);
   TH1F* hptmtauemu2Bwj = new TH1F("hptmtauemu2Bwj","hptmtauemu2Bwj",3,25.,115.);
   TH1F* hptmtauemu2Bwjbwp0 = new TH1F("hptmtauemu2Bwjbwp0","hptmtauemu2Bwjbwp0",3,25.,115.);
   TH1F* hptmtauemu2Bwjbwp1 = new TH1F("hptmtauemu2Bwjbwp1","hptmtauemu2Bwjbwp1",3,25.,115.);
   TH1F* hptmtauemu2Bwjbwp2 = new TH1F("hptmtauemu2Bwjbwp2","hptmtauemu2Bwjbwp2",3,25.,115.);
   TH1F* hptmtauemu2Bwjbwp3 = new TH1F("hptmtauemu2Bwjbwp3","hptmtauemu2Bwjbwp3",3,25.,115.);
   TH1F* hpttauemu2Bwj = new TH1F("hpttauemu2Bwj","hpttauemu2Bwj",3,25.,115.);
   TH1F* hpttauemu2Bwjbwp0 = new TH1F("hpttauemu2Bwjbwp0","hpttauemu2Bwjbwp0",3,25.,115.);
   TH1F* hpttauemu2Bwjbwp1 = new TH1F("hpttauemu2Bwjbwp1","hpttauemu2Bwjbwp1",3,25.,115.);
   TH1F* hpttauemu2Bwjbwp2 = new TH1F("hpttauemu2Bwjbwp2","hpttauemu2Bwjbwp2",3,25.,115.);
   TH1F* hpttauemu2Bwjbwp3 = new TH1F("hpttauemu2Bwjbwp3","hpttauemu2Bwjbwp3",3,25.,115.);
   //
   TH1F* hptmtauemu1Blep = new TH1F("hptmtauemu1Blep","hptmtauemu1Blep",3,25.,115.);
   TH1F* hptmtauemu1Blepbwp0 = new TH1F("hptmtauemu1Blepbwp0","hptmtauemu1Blepbwp0",3,25.,115.);
   TH1F* hptmtauemu1Blepbwp1 = new TH1F("hptmtauemu1Blepbwp1","hptmtauemu1Blepbwp1",3,25.,115.);
   TH1F* hptmtauemu1Blepbwp2 = new TH1F("hptmtauemu1Blepbwp2","hptmtauemu1Blepbwp2",3,25.,115.);
   TH1F* hptmtauemu1Blepbwp3 = new TH1F("hptmtauemu1Blepbwp3","hptmtauemu1Blepbwp3",3,25.,115.);
   TH1F* hpttauemu1Blep = new TH1F("hpttauemu1Blep","hpttauemu1Blep",3,25.,115.);
   TH1F* hpttauemu1Blepbwp0 = new TH1F("hpttauemu1Blepbwp0","hpttauemu1Blepbwp0",3,25.,115.);
   TH1F* hpttauemu1Blepbwp1 = new TH1F("hpttauemu1Blepbwp1","hpttauemu1Blepbwp1",3,25.,115.);
   TH1F* hpttauemu1Blepbwp2 = new TH1F("hpttauemu1Blepbwp2","hpttauemu1Blepbwp2",3,25.,115.);
   TH1F* hpttauemu1Blepbwp3 = new TH1F("hpttauemu1Blepbwp3","hpttauemu1Blepbwp3",3,25.,115.);
   TH1F* hptmtauemu2Blep = new TH1F("hptmtauemu2Blep","hptmtauemu2Blep",3,25.,115.);
   TH1F* hptmtauemu2Blepbwp0 = new TH1F("hptmtauemu2Blepbwp0","hptmtauemu2Blepbwp0",3,25.,115.);
   TH1F* hptmtauemu2Blepbwp1 = new TH1F("hptmtauemu2Blepbwp1","hptmtauemu2Blepbwp1",3,25.,115.);
   TH1F* hptmtauemu2Blepbwp2 = new TH1F("hptmtauemu2Blepbwp2","hptmtauemu2Blepbwp2",3,25.,115.);
   TH1F* hptmtauemu2Blepbwp3 = new TH1F("hptmtauemu2Blepbwp3","hptmtauemu2Blepbwp3",3,25.,115.);
   TH1F* hpttauemu2Blep = new TH1F("hpttauemu2Blep","hpttauemu2Blep",3,25.,115.);
   TH1F* hpttauemu2Blepbwp0 = new TH1F("hpttauemu2Blepbwp0","hpttauemu2Blepbwp0",3,25.,115.);
   TH1F* hpttauemu2Blepbwp1 = new TH1F("hpttauemu2Blepbwp1","hpttauemu2Blepbwp1",3,25.,115.);
   TH1F* hpttauemu2Blepbwp2 = new TH1F("hpttauemu2Blepbwp2","hpttauemu2Blepbwp2",3,25.,115.);
   TH1F* hpttauemu2Blepbwp3 = new TH1F("hpttauemu2Blepbwp3","hpttauemu2Blepbwp3",3,25.,115.);
   // 6-4
   TH1F* hnjetemuosB = new TH1F("hnjetemuosB","hnjetemuosB",5,0.,5.);  
   TH1F* hnjetmmosB = new TH1F("hnjetmmosB","hnjetmmosB",5,0.,5.);
   TH1F* hnjeteeosB = new TH1F("hnjeteeosB","hnjeteeosB",5,0.,5.);
   TH1F* hnjetemussB = new TH1F("hnjetemussB","hnjetemussB",5,0.,5.);
   TH1F* hnjetmmssB = new TH1F("hnjetmmssB","hnjetmmssB",5,0.,5.);
   TH1F* hnjeteessB = new TH1F("hnjeteessB","hnjeteessB",5,0.,5.);
   // 6-8 checking truth tau performances 
   TH1F* hsigtransltauosTruth = new TH1F("hsigtransltauosTruth","hsigtransltauosTruth", 20, 0., 1.); 
   TH1F* hmv2c10ltauosTruth = new TH1F("hmv2c10ltauosTruth","hmv2c10ltauosTruth",20, -1., 1.);
   TH1F* hptmtau1posTruth = new TH1F("hptmtau1posTruth","hptmtau1posTruth", 3, 25., 115.);
   TH1F* hetamtau1posTruth = new TH1F("hetamtau1posTruth","hetamtau1posTruth",5,0.,2.5);
   TH1F* hsigtransmtau1posTruth = new TH1F("hsigtransmtau1posTruth","hsigtransmtau1posTruth", 20, 0., 1.); 
   TH1F* hmv2c10mtau1posTruth = new TH1F("hmv2c10mtau1posTruth","hmv2c10mtau1posTruth",20, -1., 1.);
   TH1F* hptmtau3posTruth = new TH1F("hptmtau3posTruth","hptmtau3posTruth", 3, 25., 115.);
   TH1F* hetamtau3posTruth = new TH1F("hetamtau3posTruth","hetamtau3posTruth",5,0.,2.5);
   TH1F* hsigtransmtau3posTruth = new TH1F("hsigtransmtau3posTruth","hsigtransmtau3posTruth", 20, 0., 1.); 
   TH1F* hmv2c10mtau3posTruth = new TH1F("hmv2c10mtau3posTruth","hmv2c10mtau3posTruth",20, -1., 1.);
   TH1F* hptttau1posTruth = new TH1F("hptttau1posTruth","hptttau1posTruth", 3, 25., 115.);
   TH1F* hetattau1posTruth = new TH1F("hetattau1posTruth","hetattau1posTruth",5,0.,2.5);
   TH1F* hsigtransttau1posTruth = new TH1F("hsigtransttau1posTruth","hsigtransttau1posTruth", 20, 0., 1.); 
   TH1F* hmv2c10ttau1posTruth = new TH1F("hmv2c10ttau1posTruth","hmv2c10ttau1posTruth",20, -1., 1.);
   TH1F* hptttau3posTruth = new TH1F("hptttau3posTruth","hptttau3posTruth", 3, 25., 115.);
   TH1F* hetattau3posTruth = new TH1F("hetattau3posTruth","hetattau3posTruth",5,0.,2.5);
   TH1F* hsigtransttau3posTruth = new TH1F("hsigtransttau3posTruth","hsigtransttau3posTruth", 20, 0., 1.); 
   TH1F* hmv2c10ttau3posTruth = new TH1F("hmv2c10ttau3posTruth","hmv2c10ttau3posTruth",20, -1., 1.);
   // 6-12
   TH1F* hmleptau1pos = new TH1F("hmleptau1pos","hmleptau1pos", 30, 0., 150.); 
   TH1F* hmleptau1posTruth =new TH1F("hmleptau1posTruth","hmleptau1posTruth",30, 0.,150.);
   TH1F* hmleptau3pos =new TH1F("hmleptau3pos","hmleptau3pos",30, 0.,150.);
   TH1F* hmleptau3posTruth =new TH1F("hmleptau3posTruth","hmleptau3posTruth",30, 0.,150.);
   TH1F* hmleptau1poslow =new TH1F("hmleptau1poslow","hmleptau1poslow",30, 0.,150.);
   TH1F* hmleptau1poslowTruth =new TH1F("hmleptau1poslowTruth","hmleptau1poslowTruth",30, 0.,150.);
   TH1F* hmleptau3poslow =new TH1F("hmleptau3poslow","hmleptau3poslow",30, 0.,150.);
   TH1F* hmleptau3poslowTruth =new TH1F("hmleptau3poslowTruth","hmleptau3poslowTruth",30, 0.,150.);
   //
   TH1F* hptltaucharm = new TH1F("hptltaucharm","hptltaucharm", 3, 25., 115.);
   TH1F* hptltaucharmbwp0 = new TH1F("hptltaucharmbwp0","hptltaucharmbwp0", 3, 25., 115.);
   TH1F* hptltaucharmbwp1 = new TH1F("hptltaucharmbwp1","hptltaucharmbwp1", 3, 25., 115.);
   TH1F* hptltaucharmbwp2 = new TH1F("hptltaucharmbwp2","hptltaucharmbwp2", 3, 25., 115.);
   TH1F* hptltaucharmbwp3 = new TH1F("hptltaucharmbwp3","hptltaucharmbwp3", 3, 25., 115.);
   //6-13
   TH1F* hptmtau1posTruthbwp0 = new TH1F("hptmtau1posTruthbwp0","hptmtau1posTruthbwp0",3,25.,115.);
   TH1F* hptmtau1posTruthbwp1 = new TH1F("hptmtau1posTruthbwp1","hptmtau1posTruthbwp1",3,25.,115.);
   TH1F* hptmtau1posTruthbwp2 = new TH1F("hptmtau1posTruthbwp2","hptmtau1posTruthbwp2",3,25.,115.);
   TH1F* hptmtau1posTruthbwp3 = new TH1F("hptmtau1posTruthbwp3","hptmtau1posTruthbwp3",3,25.,115.);
   TH1F* hptmtau3posTruthbwp0 = new TH1F("hptmtau3posTruthbwp0","hptmtau3posTruthbwp0",3,25.,115.);
   TH1F* hptmtau3posTruthbwp1 = new TH1F("hptmtau3posTruthbwp1","hptmtau3posTruthbwp1",3,25.,115.);
   TH1F* hptmtau3posTruthbwp2 = new TH1F("hptmtau3posTruthbwp2","hptmtau3posTruthbwp2",3,25.,115.);
   TH1F* hptmtau3posTruthbwp3 = new TH1F("hptmtau3posTruthbwp3","hptmtau3posTruthbwp3",3,25.,115.);
   TH1F* hptttau1posTruthbwp0 = new TH1F("hptttau1posTruthbwp0","hptttau1posTruthbwp0",3,25.,115.);
   TH1F* hptttau1posTruthbwp1 = new TH1F("hptttau1posTruthbwp1","hptttau1posTruthbwp1",3,25.,115.);
   TH1F* hptttau1posTruthbwp2 = new TH1F("hptttau1posTruthbwp2","hptttau1posTruthbwp2",3,25.,115.);
   TH1F* hptttau1posTruthbwp3 = new TH1F("hptttau1posTruthbwp3","hptttau1posTruthbwp3",3,25.,115.);
   TH1F* hptttau3posTruthbwp0 = new TH1F("hptttau3posTruthbwp0","hptttau3posTruthbwp0",3,25.,115.);
   TH1F* hptttau3posTruthbwp1 = new TH1F("hptttau3posTruthbwp1","hptttau3posTruthbwp1",3,25.,115.);
   TH1F* hptttau3posTruthbwp2 = new TH1F("hptttau3posTruthbwp2","hptttau3posTruthbwp2",3,25.,115.);
   TH1F* hptttau3posTruthbwp3 = new TH1F("hptttau3posTruthbwp3","hptttau3posTruthbwp3",3,25.,115.);
   // 6-15 mu dependents 
   TH1F* hpumtau1posTruth = new TH1F("hpumtau1posTruth","hpumtau1posTruth",4,xbins);
   TH1F* hpumtau3posTruth = new TH1F("hpumtau3posTruth","hpumtau3posTruth",4,xbins);
   TH1F* hputtau1posTruth = new TH1F("hputtau1posTruth","hputtau1posTruth",4,xbins);
   TH1F* hputtau3posTruth = new TH1F("hputtau3posTruth","hputtau3posTruth",4,xbins);
   TH1F* hpumtau1posTruthbwp0 = new TH1F("hpumtau1posTruthbwp0","hpumtau1posTruthbwp0",4,xbins);
   TH1F* hpumtau1posTruthbwp1 = new TH1F("hpumtau1posTruthbwp1","hpumtau1posTruthbwp1",4,xbins);
   TH1F* hpumtau1posTruthbwp2 = new TH1F("hpumtau1posTruthbwp2","hpumtau1posTruthbwp2",4,xbins);
   TH1F* hpumtau1posTruthbwp3 = new TH1F("hpumtau1posTruthbwp3","hpumtau1posTruthbwp3",4,xbins);
   TH1F* hpumtau3posTruthbwp0 = new TH1F("hpumtau3posTruthbwp0","hpumtau3posTruthbwp0",4,xbins);
   TH1F* hpumtau3posTruthbwp1 = new TH1F("hpumtau3posTruthbwp1","hpumtau3posTruthbwp1",4,xbins);
   TH1F* hpumtau3posTruthbwp2 = new TH1F("hpumtau3posTruthbwp2","hpumtau3posTruthbwp2",4,xbins);
   TH1F* hpumtau3posTruthbwp3 = new TH1F("hpumtau3posTruthbwp3","hpumtau3posTruthbwp3",4,xbins);
   TH1F* hputtau1posTruthbwp0 = new TH1F("hputtau1posTruthbwp0","hputtau1posTruthbwp0",4,xbins);
   TH1F* hputtau1posTruthbwp1 = new TH1F("hputtau1posTruthbwp1","hputtau1posTruthbwp1",4,xbins);
   TH1F* hputtau1posTruthbwp2 = new TH1F("hputtau1posTruthbwp2","hputtau1posTruthbwp2",4,xbins);
   TH1F* hputtau1posTruthbwp3 = new TH1F("hputtau1posTruthbwp3","hputtau1posTruthbwp3",4,xbins);
   TH1F* hputtau3posTruthbwp0 = new TH1F("hputtau3posTruthbwp0","hputtau3posTruthbwp0",4,xbins);
   TH1F* hputtau3posTruthbwp1 = new TH1F("hputtau3posTruthbwp1","hputtau3posTruthbwp1",4,xbins);
   TH1F* hputtau3posTruthbwp2 = new TH1F("hputtau3posTruthbwp2","hputtau3posTruthbwp2",4,xbins);
   TH1F* hputtau3posTruthbwp3 = new TH1F("hputtau3posTruthbwp3","hputtau3posTruthbwp3",4,xbins);
   // 6-17
   TH2F* htaubdtsig2d = new TH2F("htaubdtsig2d","htaubdtsig2d",20,0.,1.0,20,-1.,1.);
   TH1F* htaubdtsig =new TH1F("htaubdtsig","htaubdtsig",20,0.,1.0);
   TH1F* htaubdtsigbwp0 =new TH1F("htaubdtsigbwp0","htaubdtsigbwp0",20,0.,1.0);
   TH1F* htaubdtsigbwp1 =new TH1F("htaubdtsigbwp1","htaubdtsigbwp1",20,0.,1.0);
   TH1F* htaubdtsigbwp2 =new TH1F("htaubdtsigbwp2","htaubdtsigbwp2",20,0.,1.0);
   TH1F* htaubdtsigbwp3 =new TH1F("htaubdtsigbwp3","htaubdtsigbwp3",20,0.,1.0);
   // 6-20 
   TH1F* htaubdtsig1p =new TH1F("htaubdtsig1p","htaubdtsig1p",20,0.,1.0);
   TH1F* htaubdtsig1pbwp0 =new TH1F("htaubdtsig1pbwp0","htaubdtsig1pbwp0",20,0.,1.0);
   TH1F* htaubdtsig1pbwp1 =new TH1F("htaubdtsig1pbwp1","htaubdtsig1pbwp1",20,0.,1.0);
   TH1F* htaubdtsig1pbwp2 =new TH1F("htaubdtsig1pbwp2","htaubdtsig1pbwp2",20,0.,1.0);
   TH1F* htaubdtsig1pbwp3 =new TH1F("htaubdtsig1pbwp3","htaubdtsig1pbwp3",20,0.,1.0);
   TH1F* htaubdtsig3p =new TH1F("htaubdtsig3p","htaubdtsig3p",20,0.,1.0);
   TH1F* htaubdtsig3pbwp0 =new TH1F("htaubdtsig3pbwp0","htaubdtsig3pbwp0",20,0.,1.0);
   TH1F* htaubdtsig3pbwp1 =new TH1F("htaubdtsig3pbwp1","htaubdtsig3pbwp1",20,0.,1.0);
   TH1F* htaubdtsig3pbwp2 =new TH1F("htaubdtsig3pbwp2","htaubdtsig3pbwp2",20,0.,1.0);
   TH1F* htaubdtsig3pbwp3 =new TH1F("htaubdtsig3pbwp3","htaubdtsig3pbwp3",20,0.,1.0);

   hptltauosbwp0->Sumw2();
   hptltauosbwp1->Sumw2();
   hptltauosbwp2->Sumw2();
   hptltauosbwp3->Sumw2();
   hptltauosTruthbwp0->Sumw2();
   hptltauosTruthbwp1->Sumw2();
   hptltauosTruthbwp2->Sumw2();
   hptltauosTruthbwp3->Sumw2();
   hptltau1pos->Sumw2();
   hptltau1posTruth->Sumw2();
   hptltau1posbwp0->Sumw2();
   hptltau1posbwp1->Sumw2();
   hptltau1posbwp2->Sumw2();
   hptltau1posbwp3->Sumw2();
   hptltau1posTruthbwp0->Sumw2();
   hptltau1posTruthbwp1->Sumw2();
   hptltau1posTruthbwp2->Sumw2();
   hptltau1posTruthbwp3->Sumw2();
   hptltau3pos->Sumw2();
   hptltau3posTruth->Sumw2();
   hptltau3posbwp0->Sumw2();
   hptltau3posbwp1->Sumw2();
   hptltau3posbwp2->Sumw2();
   hptltau3posbwp3->Sumw2();
   hptltau3posTruthbwp0->Sumw2();
   hptltau3posTruthbwp1->Sumw2();
   hptltau3posTruthbwp2->Sumw2();
   hptltau3posTruthbwp3->Sumw2();
   //ss
   hptltaussbwp0->Sumw2();
   hptltaussbwp1->Sumw2();
   hptltaussbwp2->Sumw2();
   hptltaussbwp3->Sumw2();
   hptltaussTruthbwp0->Sumw2();
   hptltaussTruthbwp1->Sumw2();
   hptltaussTruthbwp2->Sumw2();
   hptltaussTruthbwp3->Sumw2();
   hptltau1pss->Sumw2();
   hptltau1pssTruth->Sumw2();
   hptltau1pssbwp0->Sumw2();
   hptltau1pssbwp1->Sumw2();
   hptltau1pssbwp2->Sumw2();
   hptltau1pssbwp3->Sumw2();
   hptltau1pssTruthbwp0->Sumw2();
   hptltau1pssTruthbwp1->Sumw2();
   hptltau1pssTruthbwp2->Sumw2();
   hptltau1pssTruthbwp3->Sumw2();
   hptltau3pss->Sumw2();
   hptltau3pssTruth->Sumw2();
   hptltau3pssbwp0->Sumw2();
   hptltau3pssbwp1->Sumw2();
   hptltau3pssbwp2->Sumw2();
   hptltau3pssbwp3->Sumw2();
   hptltau3pssTruthbwp0->Sumw2();
   hptltau3pssTruthbwp1->Sumw2();
   hptltau3pssTruthbwp2->Sumw2();
   hptltau3pssTruthbwp3->Sumw2();
   // april 10 added 108 
   // low
   hptltauoslowbwp0->Sumw2();
   hptltauoslowbwp1->Sumw2();
   hptltauoslowbwp2->Sumw2();
   hptltauoslowbwp3->Sumw2();
   hptltauoslowTruthbwp0->Sumw2();
   hptltauoslowTruthbwp1->Sumw2();
   hptltauoslowTruthbwp2->Sumw2();
   hptltauoslowTruthbwp3->Sumw2();
   hptltau1poslow->Sumw2();
   hptltau1poslowTruth->Sumw2();
   hptltau1poslowbwp0->Sumw2();
   hptltau1poslowbwp1->Sumw2();
   hptltau1poslowbwp2->Sumw2();
   hptltau1poslowbwp3->Sumw2();
   hptltau1poslowTruthbwp0->Sumw2();
   hptltau1poslowTruthbwp1->Sumw2();
   hptltau1poslowTruthbwp2->Sumw2();
   hptltau1poslowTruthbwp3->Sumw2();
   hptltau3poslow->Sumw2();
   hptltau3poslowTruth->Sumw2();
   hptltau3poslowbwp0->Sumw2();
   hptltau3poslowbwp1->Sumw2();
   hptltau3poslowbwp2->Sumw2();
   hptltau3poslowbwp3->Sumw2();
   hptltau3poslowTruthbwp0->Sumw2();
   hptltau3poslowTruthbwp1->Sumw2();
   hptltau3poslowTruthbwp2->Sumw2();
   hptltau3poslowTruthbwp3->Sumw2();
   //ss
   hptltausslowbwp0->Sumw2();
   hptltausslowbwp1->Sumw2();
   hptltausslowbwp2->Sumw2();
   hptltausslowbwp3->Sumw2();
   hptltausslowTruthbwp0->Sumw2();
   hptltausslowTruthbwp1->Sumw2();
   hptltausslowTruthbwp2->Sumw2();
   hptltausslowTruthbwp3->Sumw2();
   hptltau1psslow->Sumw2();
   hptltau1psslowTruth->Sumw2();
   hptltau1psslowbwp0->Sumw2();
   hptltau1psslowbwp1->Sumw2();
   hptltau1psslowbwp2->Sumw2();
   hptltau1psslowbwp3->Sumw2();
   hptltau1psslowTruthbwp0->Sumw2();
   hptltau1psslowTruthbwp1->Sumw2();
   hptltau1psslowTruthbwp2->Sumw2();
   hptltau1psslowTruthbwp3->Sumw2();
   hptltau3psslow->Sumw2();
   hptltau3psslowTruth->Sumw2();
   hptltau3psslowbwp0->Sumw2();
   hptltau3psslowbwp1->Sumw2();
   hptltau3psslowbwp2->Sumw2();
   hptltau3psslowbwp3->Sumw2();
   hptltau3psslowTruthbwp0->Sumw2();
   hptltau3psslowTruthbwp1->Sumw2();
   hptltau3psslowTruthbwp2->Sumw2();
   hptltau3psslowTruthbwp3->Sumw2();
   // qcd
   hptltauosqcdbwp0->Sumw2();
   hptltauosqcdbwp1->Sumw2();
   hptltauosqcdbwp2->Sumw2();
   hptltauosqcdbwp3->Sumw2();
   hptltauosqcdTruthbwp0->Sumw2();
   hptltauosqcdTruthbwp1->Sumw2();
   hptltauosqcdTruthbwp2->Sumw2();
   hptltauosqcdTruthbwp3->Sumw2();
   hptltau1posqcd->Sumw2();
   hptltau1posqcdTruth->Sumw2();
   hptltau1posqcdbwp0->Sumw2();
   hptltau1posqcdbwp1->Sumw2();
   hptltau1posqcdbwp2->Sumw2();
   hptltau1posqcdbwp3->Sumw2();
   hptltau1posqcdTruthbwp0->Sumw2();
   hptltau1posqcdTruthbwp1->Sumw2();
   hptltau1posqcdTruthbwp2->Sumw2();
   hptltau1posqcdTruthbwp3->Sumw2();
   hptltau3posqcd->Sumw2();
   hptltau3posqcdTruth->Sumw2();
   hptltau3posqcdbwp0->Sumw2();
   hptltau3posqcdbwp1->Sumw2();
   hptltau3posqcdbwp2->Sumw2();
   hptltau3posqcdbwp3->Sumw2();
   hptltau3posqcdTruthbwp0->Sumw2();
   hptltau3posqcdTruthbwp1->Sumw2();
   hptltau3posqcdTruthbwp2->Sumw2();
   hptltau3posqcdTruthbwp3->Sumw2();
   //ss
   hptltaussqcdbwp0->Sumw2();
   hptltaussqcdbwp1->Sumw2();
   hptltaussqcdbwp2->Sumw2();
   hptltaussqcdbwp3->Sumw2();
   hptltaussqcdTruthbwp0->Sumw2();
   hptltaussqcdTruthbwp1->Sumw2();
   hptltaussqcdTruthbwp2->Sumw2();
   hptltaussqcdTruthbwp3->Sumw2();
   hptltau1pssqcd->Sumw2();
   hptltau1pssqcdTruth->Sumw2();
   hptltau1pssqcdbwp0->Sumw2();
   hptltau1pssqcdbwp1->Sumw2();
   hptltau1pssqcdbwp2->Sumw2();
   hptltau1pssqcdbwp3->Sumw2();
   hptltau1pssqcdTruthbwp0->Sumw2();
   hptltau1pssqcdTruthbwp1->Sumw2();
   hptltau1pssqcdTruthbwp2->Sumw2();
   hptltau1pssqcdTruthbwp3->Sumw2();
   hptltau3pssqcd->Sumw2();
   hptltau3pssqcdTruth->Sumw2();
   hptltau3pssqcdbwp0->Sumw2();
   hptltau3pssqcdbwp1->Sumw2();
   hptltau3pssqcdbwp2->Sumw2();
   hptltau3pssqcdbwp3->Sumw2();
   hptltau3pssqcdTruthbwp0->Sumw2();
   hptltau3pssqcdTruthbwp1->Sumw2();
   hptltau3pssqcdTruthbwp2->Sumw2();
   hptltau3pssqcdTruthbwp3->Sumw2();
   // qcdlow
   hptltauosqcdlowbwp0->Sumw2();
   hptltauosqcdlowbwp1->Sumw2();
   hptltauosqcdlowbwp2->Sumw2();
   hptltauosqcdlowbwp3->Sumw2();
   hptltauosqcdlowTruthbwp0->Sumw2();
   hptltauosqcdlowTruthbwp1->Sumw2();
   hptltauosqcdlowTruthbwp2->Sumw2();
   hptltauosqcdlowTruthbwp3->Sumw2();
   hptltau1posqcdlow->Sumw2();
   hptltau1posqcdlowTruth->Sumw2();
   hptltau1posqcdlowbwp0->Sumw2();
   hptltau1posqcdlowbwp1->Sumw2();
   hptltau1posqcdlowbwp2->Sumw2();
   hptltau1posqcdlowbwp3->Sumw2();
   hptltau1posqcdlowTruthbwp0->Sumw2();
   hptltau1posqcdlowTruthbwp1->Sumw2();
   hptltau1posqcdlowTruthbwp2->Sumw2();
   hptltau1posqcdlowTruthbwp3->Sumw2();
   hptltau3posqcdlow->Sumw2();
   hptltau3posqcdlowTruth->Sumw2();
   hptltau3posqcdlowbwp0->Sumw2();
   hptltau3posqcdlowbwp1->Sumw2();
   hptltau3posqcdlowbwp2->Sumw2();
   hptltau3posqcdlowbwp3->Sumw2();
   hptltau3posqcdlowTruthbwp0->Sumw2();
   hptltau3posqcdlowTruthbwp1->Sumw2();
   hptltau3posqcdlowTruthbwp2->Sumw2();
   hptltau3posqcdlowTruthbwp3->Sumw2();
   //ss
   hptltaussqcdlowbwp0->Sumw2();
   hptltaussqcdlowbwp1->Sumw2();
   hptltaussqcdlowbwp2->Sumw2();
   hptltaussqcdlowbwp3->Sumw2();
   hptltaussqcdlowTruthbwp0->Sumw2();
   hptltaussqcdlowTruthbwp1->Sumw2();
   hptltaussqcdlowTruthbwp2->Sumw2();
   hptltaussqcdlowTruthbwp3->Sumw2();
   hptltau1pssqcdlow->Sumw2();
   hptltau1pssqcdlowTruth->Sumw2();
   hptltau1pssqcdlowbwp0->Sumw2();
   hptltau1pssqcdlowbwp1->Sumw2();
   hptltau1pssqcdlowbwp2->Sumw2();
   hptltau1pssqcdlowbwp3->Sumw2();
   hptltau1pssqcdlowTruthbwp0->Sumw2();
   hptltau1pssqcdlowTruthbwp1->Sumw2();
   hptltau1pssqcdlowTruthbwp2->Sumw2();
   hptltau1pssqcdlowTruthbwp3->Sumw2();
   hptltau3pssqcdlow->Sumw2();
   hptltau3pssqcdlowTruth->Sumw2();
   hptltau3pssqcdlowbwp0->Sumw2();
   hptltau3pssqcdlowbwp1->Sumw2();
   hptltau3pssqcdlowbwp2->Sumw2();
   hptltau3pssqcdlowbwp3->Sumw2();
   hptltau3pssqcdlowTruthbwp0->Sumw2();
   hptltau3pssqcdlowTruthbwp1->Sumw2();
   hptltau3pssqcdlowTruthbwp2->Sumw2();
   hptltau3pssqcdlowTruthbwp3->Sumw2();
   hltaucutflow->Sumw2();
   hltaucutflowct->Sumw2();
   // may 16
   hmwltau1posqcdlow->Sumw2();
   hmwltau1posqcdlowTruth->Sumw2();  
   hmwltau3posqcdlow->Sumw2();  
   hmwltau3posqcdlowTruth->Sumw2();
   hmwltau1pssqcdlow->Sumw2();  
   hmwltau1pssqcdlowTruth->Sumw2();
   hmwltau3pssqcdlow->Sumw2();
   hmwltau3pssqcdlowTruth->Sumw2();
   //
   hmwltau1poslow->Sumw2();
   hmwltau1poslowTruth->Sumw2();
   hmwltau3poslow->Sumw2();
   hmwltau3poslowTruth->Sumw2();
   hmwltau1psslow->Sumw2();
   hmwltau1psslowTruth->Sumw2();
   hmwltau3psslow->Sumw2();
   hmwltau3psslowTruth->Sumw2();
   // 5-22 
   hmwltau1poslowWjj->Sumw2();
   hmwltau1poslowbwp0->Sumw2();
   hmwltau1poslowbwp1->Sumw2();
   hmwltau1poslowbwp2->Sumw2();
   hmwltau1poslowbwp3->Sumw2();
   hmwltau1psslowWjj->Sumw2();
   hmwltau1psslowbwp0->Sumw2();
   hmwltau1psslowbwp1->Sumw2();
   hmwltau1psslowbwp2->Sumw2();
   hmwltau1psslowbwp3->Sumw2();
   hmwltau3poslowWjj->Sumw2();
   hmwltau3poslowbwp0->Sumw2();
   hmwltau3poslowbwp1->Sumw2();
   hmwltau3poslowbwp2->Sumw2();
   hmwltau3poslowbwp3->Sumw2();
   hmwltau3psslowWjj->Sumw2();
   hmwltau3psslowbwp0->Sumw2();
   hmwltau3psslowbwp1->Sumw2();
   hmwltau3psslowbwp2->Sumw2();
   hmwltau3psslowbwp3->Sumw2();
   //
   hnjetltauosqcdlow->Sumw2();
   hnjetltauosqcdlowTruth->Sumw2();
   hnjetltaussqcdlow->Sumw2();
   hnjetltaussqcdlowTruth->Sumw2();
   hnjetltauos->Sumw2();
   hnjetltauosTruth->Sumw2();
   hnjetltauss->Sumw2();
   hnjetltaussTruth->Sumw2();
   // 5-18
   hnjetltautightosqcdlow->Sumw2();
   hnjetltauosqcdlowbwp1->Sumw2();
   hnjetltautightosqcdlowbwp1->Sumw2();
   hnjetltautightosqcdlowTruth->Sumw2();
   hnjetltauosqcdlowTruthbwp1->Sumw2();
   hnjetltautightosqcdlowTruthbwp1->Sumw2();
   //
   hnjetltautightssqcdlow->Sumw2();
   hnjetltaussqcdlowbwp1->Sumw2();
   hnjetltautightssqcdlowbwp1->Sumw2();
   hnjetltautightssqcdlowTruth->Sumw2();
   hnjetltaussqcdlowTruthbwp1->Sumw2();
   hnjetltautightssqcdlowTruthbwp1->Sumw2();
   //
   hnjetltautightos->Sumw2();
   hnjetltauosbwp1->Sumw2();
   hnjetltautightosbwp1->Sumw2();
   hnjetltautightosTruth->Sumw2();
   hnjetltauosTruthbwp1->Sumw2();
   hnjetltautightosTruthbwp1->Sumw2();
   //
   hnjetltautightss->Sumw2();
   hnjetltaussbwp1->Sumw2();
   hnjetltautightssbwp1->Sumw2();
   hnjetltautightssTruth->Sumw2();
   hnjetltaussTruthbwp1->Sumw2();
   hnjetltautightssTruthbwp1->Sumw2();
   // 5-24
   hptltau1posbj->Sumw2();
   hptltau1posbjbwp0->Sumw2();
   hptltau1posbjbwp1->Sumw2();
   hptltau1posbjbwp2->Sumw2();
   hptltau1posbjbwp3->Sumw2();
   hptltau3posbj->Sumw2();
   hptltau3posbjbwp0->Sumw2();
   hptltau3posbjbwp1->Sumw2();
   hptltau3posbjbwp2->Sumw2();
   hptltau3posbjbwp3->Sumw2();
   hptltau1pssbj->Sumw2();
   hptltau1pssbjbwp0->Sumw2();
   hptltau1pssbjbwp1->Sumw2();
   hptltau1pssbjbwp2->Sumw2();
   hptltau1pssbjbwp3->Sumw2();
   hptltau3pssbj->Sumw2();
   hptltau3pssbjbwp0->Sumw2();
   hptltau3pssbjbwp1->Sumw2();
   hptltau3pssbjbwp2->Sumw2();
   hptltau3pssbjbwp3->Sumw2();
   // 5-24 fake tau from lep
   hptltau1poslep->Sumw2();
   hptltau1poslepbwp0->Sumw2();
   hptltau1poslepbwp1->Sumw2();
   hptltau1poslepbwp2->Sumw2();
   hptltau1poslepbwp3->Sumw2();
   hptltau1poslowlep->Sumw2();
   hptltau1poslowlepbwp0->Sumw2();
   hptltau1poslowlepbwp1->Sumw2();
   hptltau1poslowlepbwp2->Sumw2();
   hptltau1poslowlepbwp3->Sumw2();
   hmwltau1poslowlep->Sumw2();
   hptltau3poslep->Sumw2();
   hptltau3poslepbwp0->Sumw2();
   hptltau3poslepbwp1->Sumw2();
   hptltau3poslepbwp2->Sumw2();
   hptltau3poslepbwp3->Sumw2();
   hptltau3poslowlep->Sumw2();
   hptltau3poslowlepbwp0->Sumw2();
   hptltau3poslowlepbwp1->Sumw2();
   hptltau3poslowlepbwp2->Sumw2();
   hptltau3poslowlepbwp3->Sumw2();
   hmwltau3poslowlep->Sumw2();
   hptltau1psslep->Sumw2();
   hptltau1psslepbwp0->Sumw2();
   hptltau1psslepbwp1->Sumw2();
   hptltau1psslepbwp2->Sumw2();
   hptltau1psslepbwp3->Sumw2();
   hptltau1psslowlep->Sumw2();
   hptltau1psslowlepbwp0->Sumw2();
   hptltau1psslowlepbwp1->Sumw2();
   hptltau1psslowlepbwp2->Sumw2();
   hptltau1psslowlepbwp3->Sumw2();
   hmwltau1psslowlep->Sumw2();
   hptltau3psslep->Sumw2();
   hptltau3psslepbwp0->Sumw2();
   hptltau3psslepbwp1->Sumw2();
   hptltau3psslepbwp2->Sumw2();
   hptltau3psslepbwp3->Sumw2();
   hptltau3psslowlep->Sumw2();
   hptltau3psslowlepbwp0->Sumw2();
   hptltau3psslowlepbwp1->Sumw2();
   hptltau3psslowlepbwp2->Sumw2();
   hptltau3psslowlepbwp3->Sumw2();
   hmwltau3psslowlep->Sumw2();
   // 5-25 
   hptltau1poswj->Sumw2();
   hptltau1poswjbwp0->Sumw2();
   hptltau1poswjbwp1->Sumw2();
   hptltau1poswjbwp2->Sumw2();
   hptltau1poswjbwp3->Sumw2();
   hptltau3poswj->Sumw2();
   hptltau3poswjbwp0->Sumw2();
   hptltau3poswjbwp1->Sumw2();
   hptltau3poswjbwp2->Sumw2();
   hptltau3poswjbwp3->Sumw2();
   hptltau1psswj->Sumw2();
   hptltau1psswjbwp0->Sumw2();
   hptltau1psswjbwp1->Sumw2();
   hptltau1psswjbwp2->Sumw2();
   hptltau1psswjbwp3->Sumw2();
   hptltau3psswj->Sumw2();
   hptltau3psswjbwp0->Sumw2();
   hptltau3psswjbwp1->Sumw2();
   hptltau3psswjbwp2->Sumw2();
   hptltau3psswjbwp3->Sumw2();

   hptltau1poslowbj->Sumw2();
   hptltau1poslowbjbwp0->Sumw2();
   hptltau1poslowbjbwp1->Sumw2();
   hptltau1poslowbjbwp2->Sumw2();
   hptltau1poslowbjbwp3->Sumw2();
   hptltau3poslowbj->Sumw2();
   hptltau3poslowbjbwp0->Sumw2();
   hptltau3poslowbjbwp1->Sumw2();
   hptltau3poslowbjbwp2->Sumw2();
   hptltau3poslowbjbwp3->Sumw2();
   hptltau1psslowbj->Sumw2();
   hptltau1psslowbjbwp0->Sumw2();
   hptltau1psslowbjbwp1->Sumw2();
   hptltau1psslowbjbwp2->Sumw2();
   hptltau1psslowbjbwp3->Sumw2();
   hptltau3psslowbj->Sumw2();
   hptltau3psslowbjbwp0->Sumw2();
   hptltau3psslowbjbwp1->Sumw2();
   hptltau3psslowbjbwp2->Sumw2();
   hptltau3psslowbjbwp3->Sumw2();
   //
   hptltau1poslowwj->Sumw2();
   hptltau1poslowwjbwp0->Sumw2();
   hptltau1poslowwjbwp1->Sumw2();
   hptltau1poslowwjbwp2->Sumw2();
   hptltau1poslowwjbwp3->Sumw2();
   hptltau3poslowwj->Sumw2();
   hptltau3poslowwjbwp0->Sumw2();
   hptltau3poslowwjbwp1->Sumw2();
   hptltau3poslowwjbwp2->Sumw2();
   hptltau3poslowwjbwp3->Sumw2();
   hptltau1psslowwj->Sumw2();
   hptltau1psslowwjbwp0->Sumw2();
   hptltau1psslowwjbwp1->Sumw2();
   hptltau1psslowwjbwp2->Sumw2();
   hptltau1psslowwjbwp3->Sumw2();
   hptltau3psslowwj->Sumw2();
   hptltau3psslowwjbwp0->Sumw2();
   hptltau3psslowwjbwp1->Sumw2();
   hptltau3psslowwjbwp2->Sumw2();
   hptltau3psslowwjbwp3->Sumw2();
   //5-26
   hmwltau1poslowbj->Sumw2();
   hmwltau3poslowbj->Sumw2();
   hmwltau1psslowbj->Sumw2();
   hmwltau3psslowbj->Sumw2();
   // 5-29 
   hjfltauos1B->Sumw2(); 
   hmwltauos1Bbj->Sumw2();
   hjfltauss1B->Sumw2();
   hmwltauss1Bbj->Sumw2();
   hmwltau3posqcd->Sumw2();
   hmwltau3posqcdTruth->Sumw2();
   hmwltau3pssqcd->Sumw2();
   hmwltau3pssqcdTruth->Sumw2();
   hmwltau3posmetlow->Sumw2();
   hmwltau3posmetlowTruth->Sumw2();
   hmwltau3pssmetlow->Sumw2();
   hmwltau3pssmetlowTruth->Sumw2();
   //
   hptltau1posmetlow->Sumw2();
   hptltau1posmetlowTruth->Sumw2();
   hptltau1posmetlowbwp0->Sumw2();
   hptltau1posmetlowbwp1->Sumw2();
   hptltau1posmetlowbwp2->Sumw2();
   hptltau1posmetlowbwp3->Sumw2();
   hptltau1posmetlowTruthbwp0->Sumw2();
   hptltau1posmetlowTruthbwp1->Sumw2();
   hptltau1posmetlowTruthbwp2->Sumw2();
   hptltau1posmetlowTruthbwp3->Sumw2();
   hptltau3posmetlow->Sumw2();
   hptltau3posmetlowTruth->Sumw2();
   hptltau3posmetlowbwp0->Sumw2();
   hptltau3posmetlowbwp1->Sumw2();
   hptltau3posmetlowbwp2->Sumw2();
   hptltau3posmetlowbwp3->Sumw2();
   hptltau3posmetlowTruthbwp0->Sumw2();
   hptltau3posmetlowTruthbwp1->Sumw2();
   hptltau3posmetlowTruthbwp2->Sumw2();
   hptltau3posmetlowTruthbwp3->Sumw2();
   hptltau1pssmetlow->Sumw2();
   hptltau1pssmetlowTruth->Sumw2();
   hptltau1pssmetlowbwp0->Sumw2();
   hptltau1pssmetlowbwp1->Sumw2();
   hptltau1pssmetlowbwp2->Sumw2();
   hptltau1pssmetlowbwp3->Sumw2();
   hptltau1pssmetlowTruthbwp0->Sumw2();
   hptltau1pssmetlowTruthbwp1->Sumw2();
   hptltau1pssmetlowTruthbwp2->Sumw2();
   hptltau1pssmetlowTruthbwp3->Sumw2();
   hptltau3pssmetlow->Sumw2();
   hptltau3pssmetlowTruth->Sumw2();
   hptltau3pssmetlowbwp0->Sumw2();
   hptltau3pssmetlowbwp1->Sumw2();
   hptltau3pssmetlowbwp2->Sumw2();
   hptltau3pssmetlowbwp3->Sumw2();
   hptltau3pssmetlowTruthbwp0->Sumw2();
   hptltau3pssmetlowTruthbwp1->Sumw2();
   hptltau3pssmetlowTruthbwp2->Sumw2();
   hptltau3pssmetlowTruthbwp3->Sumw2();
   // 5-30 
   hjfmtauemu1B->Sumw2();
   hjfmtauemu1Bbwp1->Sumw2();
   hptmtauemu1B->Sumw2();
   hptmtauemu1Bbwp0->Sumw2();
   hptmtauemu1Bbwp1->Sumw2();
   hptmtauemu1Bbwp2->Sumw2();
   hptmtauemu1Bbwp3->Sumw2();
   hptmtauemu1BTruth->Sumw2();
   hptmtauemu1BTruthbwp0->Sumw2();
   hptmtauemu1BTruthbwp1->Sumw2();
   hptmtauemu1BTruthbwp2->Sumw2();
   hptmtauemu1BTruthbwp3->Sumw2();
   hjftauemu1B->Sumw2();
   hjftauemu1Bbwp1->Sumw2();
   hpttauemu1B->Sumw2();
   hpttauemu1Bbwp0->Sumw2();
   hpttauemu1Bbwp1->Sumw2();
   hpttauemu1Bbwp2->Sumw2();
   hpttauemu1Bbwp3->Sumw2();
   hpttauemu1BTruth->Sumw2();
   hpttauemu1BTruthbwp0->Sumw2();
   hpttauemu1BTruthbwp1->Sumw2();
   hpttauemu1BTruthbwp2->Sumw2();
   hpttauemu1BTruthbwp3->Sumw2();
   //
   hjfmtauemu2B->Sumw2();
   hjfmtauemu2Bbwp1->Sumw2();
   hptmtauemu2B->Sumw2();
   hptmtauemu2Bbwp0->Sumw2();
   hptmtauemu2Bbwp1->Sumw2();
   hptmtauemu2Bbwp2->Sumw2();
   hptmtauemu2Bbwp3->Sumw2();
   hptmtauemu2BTruth->Sumw2();
   hptmtauemu2BTruthbwp0->Sumw2();
   hptmtauemu2BTruthbwp1->Sumw2();
   hptmtauemu2BTruthbwp2->Sumw2();
   hptmtauemu2BTruthbwp3->Sumw2();
   hjftauemu2B->Sumw2();
   hjftauemu2Bbwp1->Sumw2();
   hpttauemu2B->Sumw2();
   hpttauemu2Bbwp0->Sumw2();
   hpttauemu2Bbwp1->Sumw2();
   hpttauemu2Bbwp2->Sumw2();
   hpttauemu2Bbwp3->Sumw2();
   hpttauemu2BTruth->Sumw2();
   hpttauemu2BTruthbwp0->Sumw2();
   hpttauemu2BTruthbwp1->Sumw2();
   hpttauemu2BTruthbwp2->Sumw2();
   hpttauemu2BTruthbwp3->Sumw2();
   // 5-31
   hptmtauemu1Bbj->Sumw2();
   hptmtauemu1Bbjbwp0->Sumw2();
   hptmtauemu1Bbjbwp1->Sumw2();
   hptmtauemu1Bbjbwp2->Sumw2();
   hptmtauemu1Bbjbwp3->Sumw2();
   hpttauemu1Bbj->Sumw2();
   hpttauemu1Bbjbwp0->Sumw2();
   hpttauemu1Bbjbwp1->Sumw2();
   hpttauemu1Bbjbwp2->Sumw2();
   hpttauemu1Bbjbwp3->Sumw2();
   hptmtauemu2Bbj->Sumw2();
   hptmtauemu2Bbjbwp0->Sumw2();
   hptmtauemu2Bbjbwp1->Sumw2();
   hptmtauemu2Bbjbwp2->Sumw2();
   hptmtauemu2Bbjbwp3->Sumw2();
   hpttauemu2Bbj->Sumw2();
   hpttauemu2Bbjbwp0->Sumw2();
   hpttauemu2Bbjbwp1->Sumw2();
   hpttauemu2Bbjbwp2->Sumw2();
   hpttauemu2Bbjbwp3->Sumw2();
   //
   hptmtauemu1Bwj->Sumw2();
   hptmtauemu1Bwjbwp0->Sumw2();
   hptmtauemu1Bwjbwp1->Sumw2();
   hptmtauemu1Bwjbwp2->Sumw2();
   hptmtauemu1Bwjbwp3->Sumw2();
   hpttauemu1Bwj->Sumw2();
   hpttauemu1Bwjbwp0->Sumw2();
   hpttauemu1Bwjbwp1->Sumw2();
   hpttauemu1Bwjbwp2->Sumw2();
   hpttauemu1Bwjbwp3->Sumw2();
   hptmtauemu2Bwj->Sumw2();
   hptmtauemu2Bwjbwp0->Sumw2();
   hptmtauemu2Bwjbwp1->Sumw2();
   hptmtauemu2Bwjbwp2->Sumw2();
   hptmtauemu2Bwjbwp3->Sumw2();
   hpttauemu2Bwj->Sumw2();
   hpttauemu2Bwjbwp0->Sumw2();
   hpttauemu2Bwjbwp1->Sumw2();
   hpttauemu2Bwjbwp2->Sumw2();
   hpttauemu2Bwjbwp3->Sumw2();
   //
   hptmtauemu1Blep->Sumw2();
   hptmtauemu1Blepbwp0->Sumw2();
   hptmtauemu1Blepbwp1->Sumw2();
   hptmtauemu1Blepbwp2->Sumw2();
   hptmtauemu1Blepbwp3->Sumw2();
   hpttauemu1Blep->Sumw2();
   hpttauemu1Blepbwp0->Sumw2();
   hpttauemu1Blepbwp1->Sumw2();
   hpttauemu1Blepbwp2->Sumw2();
   hpttauemu1Blepbwp3->Sumw2();
   hptmtauemu2Blep->Sumw2();
   hptmtauemu2Blepbwp0->Sumw2();
   hptmtauemu2Blepbwp1->Sumw2();
   hptmtauemu2Blepbwp2->Sumw2();
   hptmtauemu2Blepbwp3->Sumw2();
   hpttauemu2Blep->Sumw2();
   hpttauemu2Blepbwp0->Sumw2();
   hpttauemu2Blepbwp1->Sumw2();
   hpttauemu2Blepbwp2->Sumw2();
   hpttauemu2Blepbwp3->Sumw2();
   // 6-4 
   hnjetemuosB->Sumw2();
   hnjetmmosB->Sumw2();
   hnjeteeosB->Sumw2();
   hnjetemussB->Sumw2();
   hnjetmmosB->Sumw2();
   hnjeteessB->Sumw2();
   // 6-8  Truth tau performances
   hsigtransltauosTruth->Sumw2();
   hmv2c10ltauosTruth->Sumw2();
   hptmtau1posTruth->Sumw2();
   hetamtau1posTruth->Sumw2();
   hsigtransmtau1posTruth->Sumw2();
   hmv2c10mtau1posTruth->Sumw2();
   hptmtau3posTruth->Sumw2();
   hetamtau3posTruth->Sumw2();
   hsigtransmtau3posTruth->Sumw2();
   hmv2c10mtau3posTruth->Sumw2();
   hptttau1posTruth->Sumw2();
   hetattau1posTruth->Sumw2();
   hsigtransttau1posTruth->Sumw2();
   hmv2c10ttau1posTruth->Sumw2();
   hptttau3posTruth->Sumw2();
   hetattau3posTruth->Sumw2();
   hsigtransttau3posTruth->Sumw2();
   hmv2c10ttau3posTruth->Sumw2();
   // 6-12
   hmleptau1pos->Sumw2();
   hmleptau1posTruth->Sumw2();
   hmleptau3pos->Sumw2();
   hmleptau3posTruth->Sumw2();
   hmleptau1poslow->Sumw2();
   hmleptau1poslowTruth->Sumw2();
   hmleptau3poslow->Sumw2();
   hmleptau3poslowTruth->Sumw2();
   // 6-12
   hptltaucharm->Sumw2();
   hptltaucharmbwp0->Sumw2();
   hptltaucharmbwp1->Sumw2();
   hptltaucharmbwp2->Sumw2();
   hptltaucharmbwp3->Sumw2();
   // 6-13 
   hptmtau1posTruthbwp0->Sumw2();
   hptmtau1posTruthbwp1->Sumw2();
   hptmtau1posTruthbwp2->Sumw2();
   hptmtau1posTruthbwp3->Sumw2();
   hptmtau3posTruthbwp0->Sumw2();
   hptmtau3posTruthbwp1->Sumw2();
   hptmtau3posTruthbwp2->Sumw2();
   hptmtau3posTruthbwp3->Sumw2();
   hptttau1posTruthbwp0->Sumw2();
   hptttau1posTruthbwp1->Sumw2();
   hptttau1posTruthbwp2->Sumw2();
   hptttau1posTruthbwp3->Sumw2();
   hptttau3posTruthbwp0->Sumw2();
   hptttau3posTruthbwp1->Sumw2();
   hptttau3posTruthbwp2->Sumw2();
   hptttau3posTruthbwp3->Sumw2();
   // 6-15
   hpumtau1posTruth->Sumw2();
   hpumtau3posTruth->Sumw2();
   hputtau1posTruth->Sumw2();
   hputtau3posTruth->Sumw2();
   hpumtau1posTruthbwp0->Sumw2();
   hpumtau1posTruthbwp1->Sumw2();
   hpumtau1posTruthbwp2->Sumw2();
   hpumtau1posTruthbwp3->Sumw2();
   hpumtau3posTruthbwp0->Sumw2();
   hpumtau3posTruthbwp1->Sumw2();
   hpumtau3posTruthbwp2->Sumw2();
   hpumtau3posTruthbwp3->Sumw2();
   hputtau1posTruthbwp0->Sumw2();
   hputtau1posTruthbwp1->Sumw2();
   hputtau1posTruthbwp2->Sumw2();
   hputtau1posTruthbwp3->Sumw2();
   hputtau3posTruthbwp0->Sumw2();
   hputtau3posTruthbwp1->Sumw2();
   hputtau3posTruthbwp2->Sumw2();
   hputtau3posTruthbwp3->Sumw2();
   // 6-17
   htaubdtsig2d->Sumw2();
   htaubdtsig->Sumw2();
   htaubdtsigbwp0->Sumw2();
   htaubdtsigbwp1->Sumw2();
   htaubdtsigbwp2->Sumw2();
   htaubdtsigbwp3->Sumw2();
   // 6-20 
   htaubdtsig1p->Sumw2();
   htaubdtsig1pbwp0->Sumw2();
   htaubdtsig1pbwp1->Sumw2();
   htaubdtsig1pbwp2->Sumw2();
   htaubdtsig1pbwp3->Sumw2();
   //
   htaubdtsig3p->Sumw2();
   htaubdtsig3pbwp0->Sumw2();
   htaubdtsig3pbwp1->Sumw2();
   htaubdtsig3pbwp2->Sumw2();
   htaubdtsig3pbwp3->Sumw2();

   if (fChain == 0) return;

   Long64_t nentries =GetNevtAna()>-1?GetNevtAna():fChain->GetEntriesFast();
   if(GetNevtAna()>-1)std::cout<<" This is a test run with part of dataset: "<<GetNevtAna()<<std::endl;
   //get xsec and kfact;                                                                                         

   //double lumi(36075.0);
   //double lumi_new(36074.0); // 36075.0, 3209 pb-1
   //                                                                                                            
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(debug||(jentry%10000==0))std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<
       			    RunNumber<<" ismc "<<mc_channel_number<<std::endl;
      bool basic_selection = passEventCleaning;
      // merging tt vs ttgamma; Vjets vs Vgamma; then they can be merged:
      if(_outhist.Contains("ttbargamma"))basic_selection &=m_hasMEphoton_DRgt02_nonhad;
      if(_outhist.Contains("ttbarnohad"))basic_selection &=!m_hasMEphoton_DRgt02_nonhad;
      //if(_outhist.Contains("Vjetsnozb")||_outhist.Contains("zbjets"))basic_selection &=m_MEphoton_pt/GeV<10;
      basic_selection &=((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || 
					     HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
			 (RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || 
								HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 ))||
			 (RunYear==2015&&(HLT_2e12_lhloose_L12EM10VH||HLT_e17_lhloose_mu14||HLT_mu18_mu8noL1))||
			 (RunYear>=2016&&(HLT_2e17_lhvloose_nod0||HLT_e17_lhloose_nod0_mu14||HLT_mu22_mu8noL1))); // assuming triggers for 2017 is same for 2016 
      bool trig_match =(lep_isTrigMatch_0||lep_isTrigMatch_1||lep_isTrigMatch_2||lep_isTrigMatch_3||matchDLTll01||matchDLTll02||matchDLTll12||matchDLTll03||matchDLTll13||matchDLTll23);
      bool SLtrig_match = ((RunYear==2015 && (HLT_mu20_iloose_L1MU15 || HLT_mu50 || HLT_e24_lhmedium_L1EM20VH || 
					     HLT_e60_lhmedium || HLT_e120_lhloose ))|| 
			 (RunYear>=2016 && (HLT_mu26_ivarmedium || HLT_mu50 || HLT_e26_lhtight_nod0_ivarloose || 
					    HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 )))&&lep_isTrigMatch_0;
      // note: lepSFID and lepSFIso needed to be corrected for loose iso cases: so far: all individual SF are zero in v4 ntuples 
      double wt = mc_channel_number>0?mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*JVT_EventWeight*SherpaNJetWeight*
	((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0; // using lepSFObjLoose for 1l2tau
      // *lepSFObjTight*tauSFTight*
      //			 *pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*lepSFObjTight*
      //((!dilep_type||!total_charge)*lepSFTrigTight+(dilep_type&&total_charge)*lepSFTrigLoose)*tauSFTight*
      //JVT_EventWeight*SherpaNJetWeight*((quadlep_type>0)/lep_SFIsoLoose_0/lep_SFIsoLoose_1+(onelep_type>0)/lep_SFObjLoose_0*
      //		  (mc_channel_number>0?(tau_truth_0+tau_truth_1)>1:1)+(!quadlep_type&&!onelep_type));
      //study the conversion data vs mc from Z->mumu gamma trilep_type==2
      if(basic_selection){
	if(trig_match&&trilep_type==2&&!nTaus_OR_Pt25&&abs(total_charge)==1&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&lep_Pt_2>20e3&&lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)){ //met<30 GeV ? ttbar vs z+bb: 
	  if(abs(lep_ID_1)==11&&lep_promptLeptonVeto_TagWeight_2<-0.5&&SelectTLepid(2)){
	    hmet->Fill(MET_RefFinal_et/GeV, wt); 
	    double mt = 2*MET_RefFinal_et*lep_Pt_1*(1-cos(MET_RefFinal_phi-lep_Phi_1)); 
	    mt = mt>0.?sqrt(mt):0.;
	    hmt->Fill(mt/GeV, wt);
	    hnbjets->Fill(nJets_OR_T_MV2c10_70, wt); 
	    hnjets->Fill(nJets_OR_T, wt);
	    if(debug){
	      std::cout<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<
		RunNumber<<" ismc "<<mc_channel_number<<" passing "<<MET_RefFinal_et/GeV<<" "<<lep_Pt_1/GeV<<std::endl;
	      *fout_txt<<" I am here event "<<jentry<<" Event "<<EventNumber<<" Run "<<
                RunNumber<<" ismc "<<mc_channel_number<<" passing "<<MET_RefFinal_et/GeV<<" "<<lep_Pt_1/GeV<<std::endl;
	    }
	    if(MET_RefFinal_et/GeV<50&&mt/GeV<50){ 
	      if(nJets_OR_T_MV2c10_70==0){ 
		hmmumu->Fill(Mll02/GeV, wt); 
		hmmumue->Fill(Mlll012/GeV, wt); 
		if(Mll02/GeV>40&&Mll02/GeV<85&&Mlll012/GeV>80&&Mlll012/GeV<100){ // pure 
		  hconorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt); 
		  hplicon->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hplivcon->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		  hdrlcon->Fill(DRll01<DRll12?DRll01:DRll12, wt);
		  // matching with em jets:
		  int ij(-1); 
		  double drxmin(999.);
		  for(int ix = 0; ix<(int)m_jet_pt->size(); ++ix){ //
		    double drx = fabs(lep_Phi_1 - m_jet_phi->at(ix));
		    if(drx>TMath::Pi())drx = 2*TMath::Pi() - drx; 
		    drx = sqrt(pow(drx,2)+pow((lep_Eta_1 - m_jet_eta->at(ix)),2)); 
		    if(drx<drxmin){ 
		      drxmin = drx; 
		      ij = ix; 
		    }
		  }
		  if(ij>-1){ 
		    hdrej->Fill(drxmin,wt);
		    if(drxmin<0.4){
		      hptratioej->Fill(m_jet_pt->at(ij)/lep_Pt_1, wt); 
		      hemfej->Fill(m_jet_emfrac->at(ij), wt);
		      hntrkej->Fill(m_jet_numTrk->at(ij),wt);
		      hsumptej->Fill(m_jet_sumPtTrk->at(ij)/GeV<100?m_jet_sumPtTrk->at(ij)/GeV:99,wt);
                      hsumptet->Fill(m_jet_sumPtTrk->at(ij)/m_jet_pt->at(ij),wt);
		    }
		  }
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		    hpliconTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		    hplivconTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		  }
		  if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		    if(lep_chargeIDBDTTight_1>0.7){
		      hfconorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		      hptfcon->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      hetafcon->Fill(fabs(lep_Eta_1),wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptfconTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    }
		  }
		  else{
		    hptcon->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    hetacon->Fill(fabs(lep_Eta_1),wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptconTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  }
		}
	      }
	      else if(nJets_OR_T_MV2c10_70){ 
		hmmumuB->Fill(Mll02/GeV, wt); 
		hmmumueB->Fill(Mlll012/GeV, wt); 
		if(Mll02/GeV>40&&Mll02/GeV<85&&Mlll012/GeV>80&&Mlll012/GeV<100){ // pure 
		  hconorigB->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt); 
		  hpliconB->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hplivconB->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		    hpliconTruthB->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		    hplivconTruthB->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		  }
		  if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		    if(lep_chargeIDBDTTight_1>0.7){
		      hfconorigB->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		      hptfconB->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptfconTruthB->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    }
		  }
		  else{
		    hptconB->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptconTruthB->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  }
		}
	      }
	    }
	  }
	  // in case 
	  if(abs(lep_ID_2)==11&&lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)){
	    hmet->Fill(MET_RefFinal_et/GeV, wt); 
	    double mt = 2*MET_RefFinal_et*lep_Pt_2*(1-cos(MET_RefFinal_phi-lep_Phi_2)); 
	    mt = mt>0.?sqrt(mt):0.;
	    hmt->Fill(mt/GeV, wt);
	    hnbjets->Fill(nJets_OR_T_MV2c10_70, wt); 
	    hnjets->Fill(nJets_OR_T, wt);
	    if(MET_RefFinal_et/GeV<50&&mt/GeV<50){ 
	      if(nJets_OR_T_MV2c10_70==0){ 
		hmmumu->Fill(Mll01/GeV, wt); 
		hmmumue->Fill(Mlll012/GeV, wt); 
		if(Mll01/GeV>40&&Mll01/GeV<85&&Mlll012/GeV>80&&Mlll012/GeV<100){ // pure 
		  hconorig->Fill(lep_isTruthMatched_2?lep_truthOrigin_2:-1, wt); 
		  hplicon->Fill(lep_promptLeptonIso_TagWeight_2,wt);
		  hplivcon->Fill(lep_promptLeptonVeto_TagWeight_2,wt);
                  hdrlcon->Fill(DRll02<DRll12?DRll02:DRll12, wt);
                  // matching with em jets:
                  int ij(-1);
                  double drxmin(999.);
                  for(int ix = 0; ix<(int)m_jet_pt->size(); ++ix){ //
                    double drx = fabs(lep_Phi_1 - m_jet_phi->at(ix));
                    if(drx>TMath::Pi())drx = 2*TMath::Pi() - drx;
                    drx = sqrt(pow(drx,2)+pow((lep_Eta_1 - m_jet_eta->at(ix)),2));
                    if(drx<drxmin){
                      drxmin = drx;
                      ij = ix;
                    }
                  }
                  if(ij>-1){
                    hdrej->Fill(drxmin,wt);
                    if(drxmin<0.4){
                      hptratioej->Fill(m_jet_pt->at(ij)/lep_Pt_1, wt);
                      hemfej->Fill(m_jet_emfrac->at(ij), wt);
                      hntrkej->Fill(m_jet_numTrk->at(ij),wt);
                      hsumptej->Fill(m_jet_sumPtTrk->at(ij)/GeV<100?m_jet_sumPtTrk->at(ij)/GeV:99,wt);
                      hsumptet->Fill(m_jet_sumPtTrk->at(ij)/m_jet_pt->at(ij),wt);
                    }
                  }
		  if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0)){
		    hpliconTruth->Fill(lep_promptLeptonIso_TagWeight_2,wt);
		    hplivconTruth->Fill(lep_promptLeptonVeto_TagWeight_2,wt);
		  }
		  if(lep_promptLeptonVeto_TagWeight_2<-0.7&&SelectTLepid(2)){
		    if(lep_chargeIDBDTTight_2>0.7){
		      hfconorig->Fill(lep_isTruthMatched_2?lep_truthOrigin_2:-1, wt);
		      hptfcon->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		      hetafcon->Fill(fabs(lep_Eta_1),wt);
		      if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hptfconTruth->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		    }
		  }
		  else{
		     hptcon->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		     hetacon->Fill(fabs(lep_Eta_2),wt);
		     if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hptconTruth->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		  }
		}
	      }
	      else if(nJets_OR_T_MV2c10_70){ 
		hmmumuB->Fill(Mll02/GeV, wt); 
		hmmumueB->Fill(Mlll012/GeV, wt); 
		if(Mll01/GeV>40&&Mll01/GeV<85&&Mlll012/GeV>80&&Mlll012/GeV<100){ // pure 
		  hconorigB->Fill(lep_isTruthMatched_2?lep_truthOrigin_2:-1, wt); 
		  hpliconB->Fill(lep_promptLeptonIso_TagWeight_2,wt);
		  hplivconB->Fill(lep_promptLeptonVeto_TagWeight_2,wt);
		  if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0)){
		    hpliconTruthB->Fill(lep_promptLeptonIso_TagWeight_2,wt);
		    hplivconTruthB->Fill(lep_promptLeptonVeto_TagWeight_2,wt);
		  }
		  if(lep_promptLeptonVeto_TagWeight_2<-0.7&&SelectTLepid(2)){
		    if(lep_chargeIDBDTTight_2>0.7){
		      hfconorigB->Fill(lep_isTruthMatched_2?lep_truthOrigin_2:-1, wt);
		      hptfconB->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		      if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hptfconTruthB->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		    }
		  }
		  else{
		    hptconB->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		    if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hptconTruthB->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
                  }
		}
	      }
	    }
	  }
	} // mumue
	// look for eee
	if(trig_match&&trilep_type==4&&!nTaus_OR_Pt25&&abs(total_charge)==1&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&lep_Pt_2>20e3&&lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)&&lep_chargeIDBDTTight_0>0.7){ //met<30 GeV ? ttbar vs z+bb: 
	  if(abs(lep_ID_2)==11&&lep_promptLeptonVeto_TagWeight_2<-0.7&&SelectTLepid(2)&&lep_chargeIDBDTTight_2>0.7){
	    double mt = 2*MET_RefFinal_et*lep_Pt_1*(1-cos(MET_RefFinal_phi-lep_Phi_1)); 
	    mt = mt>0.?sqrt(mt):0.;
	    if(MET_RefFinal_et/GeV<50&&mt/GeV<50){ 
	      if(nJets_OR_T_MV2c10_70>=0){ 
		hmee->Fill(Mll02/GeV, wt); 
		hmeee->Fill(Mlll012/GeV, wt); 
		if(Mll02/GeV>40&&Mll02/GeV<85&&Mlll012/GeV>80&&Mlll012/GeV<100){ // pure 
		  hconorig3e->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt); 
		  hplicon3e->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hdrlcon3e->Fill(DRll01<DRll12?DRll01:DRll12, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hpliconTruth3e->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		    if(lep_chargeIDBDTTight_1>0.7){
		      hfconorig3e->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		      hptfcon3e->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      hetafcon3e->Fill(fabs(lep_Eta_1),wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptfconTruth3e->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    }
		  }
		  else{
		    hptcon3e->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    hetacon3e->Fill(fabs(lep_Eta_1),wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptconTruth3e->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
                  } 
		}
	      }
	    }
	  }
	  // in case 
	  if(abs(lep_ID_1)==11&&lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)&&lep_chargeIDBDTTight_1>0.7){
	    double mt = 2*MET_RefFinal_et*lep_Pt_2*(1-cos(MET_RefFinal_phi-lep_Phi_2)); 
	    mt = mt>0.?sqrt(mt):0.;
	    if(MET_RefFinal_et/GeV<50&&mt/GeV<50){ 
	      if(nJets_OR_T_MV2c10_70>=0){ 
		hmee->Fill(Mll01/GeV, wt); 
		hmeee->Fill(Mlll012/GeV, wt); 
		if(Mll01/GeV>40&&Mll01/GeV<85&&Mlll012/GeV>80&&Mlll012/GeV<100){ // pure 
		  hconorig3e->Fill(lep_isTruthMatched_2?lep_truthOrigin_2:-1, wt); 
		  hplicon3e->Fill(lep_promptLeptonIso_TagWeight_2,wt);
                  hdrlcon3e->Fill(DRll02<DRll12?DRll02:DRll12, wt);
		  if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hpliconTruth3e->Fill(lep_promptLeptonIso_TagWeight_2,wt);
		  if(lep_promptLeptonVeto_TagWeight_2<-0.7&&SelectTLepid(2)){
		    if(lep_chargeIDBDTTight_2>0.7){
		      hfconorig3e->Fill(lep_isTruthMatched_2?lep_truthOrigin_2:-1, wt);
		      hptfcon3e->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		      hetafcon3e->Fill(fabs(lep_Eta_1),wt);
		      if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hptfconTruth3e->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		    }
		  }
		  else{
		    hptcon3e->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
		    hetacon3e->Fill(fabs(lep_Eta_2),wt);
		    if((lep_truthOrigin_2>9&&lep_truthOrigin_2<15)||(lep_truthOrigin_2==43||lep_truthOrigin_2==0))hptconTruth3e->Fill(lep_Pt_2/GeV<100?lep_Pt_2/GeV:99.9, wt);
                  }
		}
	      }
	    }
	  }
	} // eee
	// qmis for loose electrons: April 5
        if(trig_match&&dilep_type==3&&!nTaus_OR_Pt25&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&!((lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0))||(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)))){ // anti-tight ele 
          // check the fake rate vs eta (0.,0.9, 1.37, 1.52-2.0, 2.8) and Pt: 20-60-100-140--1000 GeV                                             
          int ieta0(0);
          int ipt0(0);
          int ieta1(0);
          int ipt1(0);
          if(abs(lep_Eta_0)<0.9){
            ieta0 = 0;
          }
          else if(abs(lep_Eta_0)<1.37){
            ieta0 = 1;
          }
          else if(abs(lep_Eta_0)<2.0){
            ieta0 = 2;
          }
          else {
            ieta0 = 3;
          }
          if(abs(lep_Eta_1)<0.9){
            ieta1= 0;
          }
          else if(abs(lep_Eta_1)<1.37){
            ieta1= 1;
          }
          else if(abs(lep_Eta_1)<2.0){
            ieta1= 2;
          }
          else {
            ieta1= 3;
          }
          if(lep_Pt_0/GeV<60){
            ipt0 = 0;
          }
          else if(lep_Pt_0/GeV<100){
            ipt0 = 1;
          }
          else if(lep_Pt_0/GeV<140){
            ipt0 = 2;
          }
          else{
            ipt0 = 3;
          }
          if(lep_Pt_1/GeV<60){
            ipt1 = 0;
          }
          else if(lep_Pt_1/GeV<100){
            ipt1 = 1;
          }
          else if(lep_Pt_1/GeV<140){
            ipt1 = 2;
          }
          else{
            ipt1 = 3;
          }
          if(abs(total_charge)==2){
            hmet2eloosess->Fill(MET_RefFinal_et/GeV, wt);
            hnbjets2eloosess->Fill(nJets_OR_T_MV2c10_70, wt);
            hm2eloosess->Fill(Mll01/GeV, wt);
            hnjets2eloosess->Fill(nJets_OR_T, wt);
            if(MET_RefFinal_et/GeV<50){ // wz cut no cuts: lep_chargeIDBDTTight_0>0.0670415&&lep_chargeIDBDTTight_1>0.0670415                     
              if(nJets_OR_T_MV2c10_70>=0){
                hm2eloosesscut->Fill(Mll01/GeV, wt);
                if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)hm2eloosessctcut->Fill(Mll01/GeV, wt); // 0.0670415 ->0.7 
                hnjets2eloosesscut->Fill(nJets_OR_T, wt);
                // save Eta bins and Pt bins Nss/Nos = si+sj sum of two leptons, which should work.                                               
                if(Mll01/GeV>78.5&&Mll01/GeV<98.5){ // signal region                                                                              
                  heta2eloosess->Fill(fabs(lep_Eta_0), wt);
                  heta2eloosess->Fill(fabs(lep_Eta_1), wt);
                  hpt2eloosess->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2eloosess->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2eloosess->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2eloosessct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt); // 0.0670415 ->0.7
                }
                else if((Mll01/GeV>58.5&&Mll01/GeV<78.5)||(Mll01/GeV>98.5&&Mll01/GeV<118.5)){ // 2-times sideband                                 
                  heta2eloosessb->Fill(fabs(lep_Eta_0), wt);
                  heta2eloosessb->Fill(fabs(lep_Eta_1), wt);
                  hpt2eloosessb->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2eloosessb->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2eloosessb->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2eloosessbct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt); // 0.0670415 ->0.7
                }
              }
            }
          }
          if(abs(total_charge)==0){ // os ee                                                                                                      
            hmet2elooseos->Fill(MET_RefFinal_et/GeV, wt);
            hnbjets2elooseos->Fill(nJets_OR_T_MV2c10_70, wt);
            hm2elooseos->Fill(Mll01/GeV, wt);
            hnjets2elooseos->Fill(nJets_OR_T, wt);
            if(MET_RefFinal_et/GeV<50){ // wz cut no cut: lep_chargeIDBDTTight_0>0.0670415&&lep_chargeIDBDTTight_1>0.0670415                      
              TLorentzVector p4ph[10];
              TLorentzVector p4ele[2];
              TLorentzVector p4phme;
              p4ele[0].SetPtEtaPhiE(lep_Pt_0, lep_Eta_0,lep_Phi_0,lep_E_0);
              p4ele[1].SetPtEtaPhiE(lep_Pt_1, lep_Eta_1,lep_Phi_1,lep_E_1);
              if(nJets_OR_T_MV2c10_70>=0){
                hm2elooseoscut->Fill(Mll01/GeV, wt);
                hnjets2elooseoscut->Fill(nJets_OR_T, wt);
                // os ee + ej or phj like events                                                                                                  
                if(Mll01/GeV>40&&Mll01/GeV<85){
                  if(m_hasMEphoton&&m_MEphoton_pt/GeV>35){
                    p4phme.SetPtEtaPhiM(m_MEphoton_pt, m_MEphoton_eta, m_MEphoton_phi,0);
                    hm2elooseosxg->Fill((p4ele[0]+p4ele[1]+p4phme).M()/GeV, wt);
                  }
                  int nph(0);
                  for(int ix = 0; ix<(int)m_jet_pt->size(); ++ix){ // barrel photon
                    if(m_jet_emfrac->at(ix)>0.95&&m_jet_pt->at(ix)/GeV>35&&nph<10&&fabs(m_jet_eta->at(ix))<1.37&&m_jet_numTrk->at(ix)<7){
                      p4ph[nph].SetPtEtaPhiE(m_jet_pt->at(ix), m_jet_eta->at(ix),m_jet_phi->at(ix),m_jet_E->at(ix));
                      if(p4ele[0].DeltaR(p4ph[nph])>0.4&&p4ele[1].DeltaR(p4ph[nph])>0.4){
                        double rm = (p4ele[0]+p4ele[1]+p4ph[nph]).M()/GeV;
                        if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
                          hm2elooseosgamma->Fill(rm,wt);
                        }
                        else if(m_jet_sumPtTrk->at(ix)/GeV>20){
                          hm2elooseosele->Fill(rm,wt);
                        }
                        if(rm>94&&rm<120){
                          h2eloosephsumpt->Fill(m_jet_sumPtTrk->at(ix)/GeV<100.?m_jet_sumPtTrk->at(ix)/GeV:99,wt);
                          h2eloosephsumptet->Fill(m_jet_sumPtTrk->at(ix)/m_jet_pt->at(ix),wt);
                          if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
                            hphpt2elooseos->Fill(m_jet_pt->at(ix)/GeV, wt);
                            hphdr2elooseos->Fill(p4ph[nph].DeltaR(p4ele[0])<p4ph[nph].DeltaR(p4ele[1])?p4ph[nph].DeltaR(p4ele[0]):p4ph[nph].DeltaR(p4ele[1]), wt);
                          }
                          else if(m_jet_sumPtTrk->at(ix)/GeV>20){
                            hept2elooseos->Fill(m_jet_pt->at(ix)/GeV, wt);
                            hedr2elooseos->Fill(p4ph[nph].DeltaR(p4ele[0])<p4ph[nph].DeltaR(p4ele[1])?p4ph[nph].DeltaR(p4ele[0]):p4ph[nph].DeltaR(p4ele[1]), wt);
			  }
                        }
                        if(m_hasMEphoton&&p4phme.DeltaR(p4ph[nph])<0.4){
                          h2eloosephsumptmatched->Fill(m_jet_sumPtTrk->at(ix)/GeV<100.?m_jet_sumPtTrk->at(ix)/GeV:99,wt);
                          h2eloosephsumptetmatched->Fill(m_jet_sumPtTrk->at(ix)/m_jet_pt->at(ix),wt);
                          if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
                            hm2elooseosgmatched->Fill((p4ele[0]+p4ele[1]+p4ph[nph]).M()/GeV,wt);
                            hphpt2elooseosmatched->Fill(m_jet_pt->at(ix)/GeV, wt);
                          }
                          else if(m_jet_sumPtTrk->at(ix)/GeV>20){
                            hm2elooseosematched->Fill((p4ele[0]+p4ele[1]+p4ph[nph]).M()/GeV,wt);
                            hept2elooseosmatched->Fill(m_jet_pt->at(ix)/GeV, wt);
                          }
                        }
                        ++nph;
                      }
                    }
                  }
                  hnph2elooseos->Fill(nph,wt);
                }
                // ee ej or phj
                if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)hm2elooseosctcut->Fill(Mll01/GeV, wt); // 0.0670415 ->0.7
                // do some sideband subtraction
                // save Eta bins and Pt bins Nss/Nos = si+sj sum of two leptons, which should work.
                if(Mll01/GeV>80&&Mll01/GeV<100){ // signal region
                  heta2elooseos->Fill(fabs(lep_Eta_0), wt);
                  heta2elooseos->Fill(fabs(lep_Eta_1), wt);
                  hpt2elooseos->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2elooseos->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2elooseos->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2elooseosct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt); // 0.0670415 ->0.7
                }
                else if((Mll01/GeV>60&&Mll01/GeV<80)||(Mll01/GeV>100&&Mll01/GeV<120)){ // 2-times sideband
                  heta2elooseosb->Fill(fabs(lep_Eta_0), wt);
                  heta2elooseosb->Fill(fabs(lep_Eta_1), wt);
                  hpt2elooseosb->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2elooseosb->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2elooseosb->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2elooseosbct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt); // 0.0670415 ->0.7
                }
              }
            }
          }
        }
	// study for QmisID for electron with Z->ee: dilep_type=1 for mumu; dilep_type=2 for emu; dilep_type=3 for ee  
	if(trig_match&&dilep_type==3&&!nTaus_OR_Pt25&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&
	   lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)&&lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){ //met>30 GeV ? ttbar vs z+bb:
	  // check the fake rate vs eta (0.,0.9, 1.37, 1.52-2.0, 2.8) and Pt: 20-60-100-140--1000 GeV     
	  int ieta0(0);
	  int ipt0(0);
	  int ieta1(0);
	  int ipt1(0);
	  if(abs(lep_Eta_0)<0.9){
	    ieta0 = 0;
	  }
	  else if(abs(lep_Eta_0)<1.37){
	    ieta0 = 1;
	  }
	  else if(abs(lep_Eta_0)<2.0){
	    ieta0 = 2;
	  }
	  else {
	    ieta0 = 3;
	  }
	  if(abs(lep_Eta_1)<0.9){
	    ieta1= 0;
	  }
	  else if(abs(lep_Eta_1)<1.37){
	    ieta1= 1;
	  }
	  else if(abs(lep_Eta_1)<2.0){
	    ieta1= 2;
	  }
	  else {
	    ieta1= 3;
	  }
	  if(lep_Pt_0/GeV<60){
	    ipt0 = 0;
	  }
	  else if(lep_Pt_0/GeV<100){
	    ipt0 = 1;
	  }
	  else if(lep_Pt_0/GeV<140){
	    ipt0 = 2;
	  }
	  else{
	    ipt0 = 3;
	  }
	  if(lep_Pt_1/GeV<60){
	    ipt1 = 0;
	  }
	  else if(lep_Pt_1/GeV<100){
	    ipt1 = 1;
	  }
	  else if(lep_Pt_1/GeV<140){
	    ipt1 = 2;
	  }
	  else{
	    ipt1 = 3;
	  }
	  if(abs(total_charge)==2){
	    hmet2ess->Fill(MET_RefFinal_et/GeV, wt); 
	    hnbjets2ess->Fill(nJets_OR_T_MV2c10_70, wt); 
	    hm2ess->Fill(Mll01/GeV, wt);
	    hnjets2ess->Fill(nJets_OR_T, wt);
	    if(MET_RefFinal_et/GeV<50){ // wz cut no cuts: lep_chargeIDBDTTight_0>0.0670415&&lep_chargeIDBDTTight_1>0.0670415    
	      if(nJets_OR_T_MV2c10_70>=0){ 
		hm2esscut->Fill(Mll01/GeV, wt);
		if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)hm2essctcut->Fill(Mll01/GeV, wt); // 0.0670415 ->0.7
		hnjets2esscut->Fill(nJets_OR_T, wt);
		// save Eta bins and Pt bins Nss/Nos = si+sj sum of two leptons, which should work. 
		if(Mll01/GeV>78.5&&Mll01/GeV<98.5){ // signal region 
		  heta2ess->Fill(fabs(lep_Eta_0), wt); 
		  heta2ess->Fill(fabs(lep_Eta_1), wt);
		  hpt2ess->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2ess->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
		  h2d2ess->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
		  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2essct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt); // 0.0670415 ->0.7
		}
		else if((Mll01/GeV>58.5&&Mll01/GeV<78.5)||(Mll01/GeV>98.5&&Mll01/GeV<118.5)){ // 2-times sideband
		  heta2essb->Fill(fabs(lep_Eta_0), wt);
                  heta2essb->Fill(fabs(lep_Eta_1), wt);
                  hpt2essb->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2essb->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2essb->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2essbct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);  // 0.0670415 ->0.7
		}
	      }
	    }
	  }
	  if(abs(total_charge)==0){ // os ee
	    hmet2eos->Fill(MET_RefFinal_et/GeV, wt); 
	    hnbjets2eos->Fill(nJets_OR_T_MV2c10_70, wt);
	    hm2eos->Fill(Mll01/GeV, wt);
	    hnjets2eos->Fill(nJets_OR_T, wt); 
	    if(MET_RefFinal_et/GeV<50){ // wz cut no cut: lep_chargeIDBDTTight_0>0.0670415&&lep_chargeIDBDTTight_1>0.0670415
	      TLorentzVector p4ph[10];
	      TLorentzVector p4ele[2];
	      TLorentzVector p4phme;
	      p4ele[0].SetPtEtaPhiE(lep_Pt_0, lep_Eta_0,lep_Phi_0,lep_E_0);
	      p4ele[1].SetPtEtaPhiE(lep_Pt_1, lep_Eta_1,lep_Phi_1,lep_E_1);
	      if(nJets_OR_T_MV2c10_70>=0){ 
		hm2eoscut->Fill(Mll01/GeV, wt);
		hnjets2eoscut->Fill(nJets_OR_T, wt);
		// os ee + ej or phj like events 
		if(Mll01/GeV>40&&Mll01/GeV<85){
		  if(m_hasMEphoton&&m_MEphoton_pt/GeV>35){
		    p4phme.SetPtEtaPhiM(m_MEphoton_pt, m_MEphoton_eta, m_MEphoton_phi,0); 
		    hm2eosxg->Fill((p4ele[0]+p4ele[1]+p4phme).M()/GeV, wt);
		  }
		  int nph(0);
		  for(int ix = 0; ix<(int)m_jet_pt->size(); ++ix){ // barrel photon
		    if(m_jet_emfrac->at(ix)>0.95&&m_jet_pt->at(ix)/GeV>35&&nph<10&&fabs(m_jet_eta->at(ix))<1.37&&m_jet_numTrk->at(ix)<7){ 
		      p4ph[nph].SetPtEtaPhiE(m_jet_pt->at(ix), m_jet_eta->at(ix),m_jet_phi->at(ix),m_jet_E->at(ix));
		      if(p4ele[0].DeltaR(p4ph[nph])>0.4&&p4ele[1].DeltaR(p4ph[nph])>0.4){
			double rm = (p4ele[0]+p4ele[1]+p4ph[nph]).M()/GeV;
			if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
			  hm2eosgamma->Fill(rm,wt);
			}
			else if(m_jet_sumPtTrk->at(ix)/GeV>20){
			  hm2eosele->Fill(rm,wt);
			}
			if(rm>94&&rm<120){
			  h2ephsumpt->Fill(m_jet_sumPtTrk->at(ix)/GeV<100.?m_jet_sumPtTrk->at(ix)/GeV:99,wt);
			  h2ephsumptet->Fill(m_jet_sumPtTrk->at(ix)/m_jet_pt->at(ix),wt);
			  if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
			    hphpt2eos->Fill(m_jet_pt->at(ix)/GeV, wt);
			    hphdr2eos->Fill(p4ph[nph].DeltaR(p4ele[0])<p4ph[nph].DeltaR(p4ele[1])?p4ph[nph].DeltaR(p4ele[0]):p4ph[nph].DeltaR(p4ele[1]), wt);
			  }
			  else if(m_jet_sumPtTrk->at(ix)/GeV>20){
			    hept2eos->Fill(m_jet_pt->at(ix)/GeV, wt);
			    hedr2eos->Fill(p4ph[nph].DeltaR(p4ele[0])<p4ph[nph].DeltaR(p4ele[1])?p4ph[nph].DeltaR(p4ele[0]):p4ph[nph].DeltaR(p4ele[1]), wt);
			  }
			}
			if(m_hasMEphoton&&p4phme.DeltaR(p4ph[nph])<0.4){ 
			  h2ephsumptmatched->Fill(m_jet_sumPtTrk->at(ix)/GeV<100.?m_jet_sumPtTrk->at(ix)/GeV:99,wt);
			  h2ephsumptetmatched->Fill(m_jet_sumPtTrk->at(ix)/m_jet_pt->at(ix),wt);
			  if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
			    hm2eosgmatched->Fill((p4ele[0]+p4ele[1]+p4ph[nph]).M()/GeV,wt);
			    hphpt2eosmatched->Fill(m_jet_pt->at(ix)/GeV, wt);
			  }
			  else if(m_jet_sumPtTrk->at(ix)/GeV>20){
			    hm2eosematched->Fill((p4ele[0]+p4ele[1]+p4ph[nph]).M()/GeV,wt);
			    hept2eosmatched->Fill(m_jet_pt->at(ix)/GeV, wt);
			  }
			}
			++nph;
		      }
		    }
		  }
		  hnph2eos->Fill(nph,wt);
		}
		// ee ej or phj 
		if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)hm2eosctcut->Fill(Mll01/GeV, wt);  // 0.0670415 ->0.7
		// do some sideband subtraction 
                // save Eta bins and Pt bins Nss/Nos = si+sj sum of two leptons, which should work.
                if(Mll01/GeV>80&&Mll01/GeV<100){ // signal region
                  heta2eos->Fill(fabs(lep_Eta_0), wt);
                  heta2eos->Fill(fabs(lep_Eta_1), wt);
                  hpt2eos->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2eos->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2eos->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2eosct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt); // 0.0670415 ->0.7
                }
                else if((Mll01/GeV>60&&Mll01/GeV<80)||(Mll01/GeV>100&&Mll01/GeV<120)){ // 2-times sideband
                  heta2eosb->Fill(fabs(lep_Eta_0), wt);
                  heta2eosb->Fill(fabs(lep_Eta_1), wt);
                  hpt2eosb->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2eosb->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                  h2d2eosb->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);
                  if(lep_chargeIDBDTTight_0>0.7&&lep_chargeIDBDTTight_1>0.7)h2d2eosbct->Fill(ieta0+4*ipt0, ieta1+4*ipt1, wt);  // 0.0670415 ->0.7
                }
              }
	    }
	  }
	}
	// z->mumu 
	if(trig_match&&dilep_type==1&&!nTaus_OR_Pt25&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&
	   lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)&&lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)){ //met>30 GeV ? ttbar vs z+bb:
	  // check the fake rate vs eta (0.,0.7, 1.4, 2.1, 2.8) and Pt: 20-60-100-140 GeV     
	  if(abs(total_charge)==2){
	    hmet2mussq->Fill(MET_RefFinal_et/GeV, wt); 
	    hnbjets2mussq->Fill(nJets_OR_T_MV2c10_70, wt); 
	    hm2mussq->Fill(Mll01/GeV, wt);
	    hnjets2mussq->Fill(nJets_OR_T, wt);
	    if(MET_RefFinal_et/GeV<50){ // wz cut  
	      if(nJets_OR_T_MV2c10_70>=0){ 
		hm2mussqcut->Fill(Mll01/GeV, wt);
		hnjets2mussqcut->Fill(nJets_OR_T, wt);
		// save Eta bins and Pt bins Nss/Nos = si+sj sum of two leptons, which should work. 
		if(Mll01/GeV>80&&Mll01/GeV<100){ // signal region 
		  heta2mussq->Fill(fabs(lep_Eta_0), wt); 
		  heta2mussq->Fill(fabs(lep_Eta_1), wt);
		  hpt2mussq->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2mussq->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
		}
		else if((Mll01/GeV>60&&Mll01/GeV<80)||(Mll01/GeV>100&&Mll01/GeV<120)){ // 2-times sideband
		  heta2mussqb->Fill(fabs(lep_Eta_0), wt);
                  heta2mussqb->Fill(fabs(lep_Eta_1), wt);
                  hpt2mussqb->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2mussqb->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
		}
	      }
	    }
	  }
	  if(abs(total_charge)==0){ // os mumu
	    hmet2muos->Fill(MET_RefFinal_et/GeV, wt); 
	    hnbjets2muos->Fill(nJets_OR_T_MV2c10_70, wt);
	    hm2muos->Fill(Mll01/GeV, wt);
	    hnjets2muos->Fill(nJets_OR_T, wt);
	    hmephpt2muos->Fill(m_MEphoton_pt/GeV, wt);
	    if(MET_RefFinal_et/GeV<50){ // wz cut  
		// search for mumu gamma  from jet collection with leading pt 
		TLorentzVector p4ph[10];
		TLorentzVector p4mu[2];
		TLorentzVector p4phme;
		p4mu[0].SetPtEtaPhiE(lep_Pt_0, lep_Eta_0,lep_Phi_0,lep_E_0);
		p4mu[1].SetPtEtaPhiE(lep_Pt_1, lep_Eta_1,lep_Phi_1,lep_E_1);
		hm2muosx->Fill((p4mu[0]+p4mu[1]).M()/GeV, wt);
		if(Mll01/GeV>40&&Mll01/GeV<85){
		  if(m_hasMEphoton&&m_MEphoton_pt/GeV>35){
		    p4phme.SetPtEtaPhiM(m_MEphoton_pt, m_MEphoton_eta, m_MEphoton_phi,0); 
		    hm2muosxg->Fill((p4mu[0]+p4mu[1]+p4phme).M()/GeV, wt);
		  }
		  int nph(0); 
		  for(int ix = 0; ix<(int)m_jet_pt->size(); ++ix){ // barrel photon 
		    if(m_jet_emfrac->at(ix)>0.95&&m_jet_pt->at(ix)/GeV>35&&nph<10&&fabs(m_jet_eta->at(ix))<1.37&&m_jet_numTrk->at(ix)<7){ 
		      p4ph[nph].SetPtEtaPhiE(m_jet_pt->at(ix), m_jet_eta->at(ix),m_jet_phi->at(ix),m_jet_E->at(ix));
		      double rm = (p4mu[0]+p4mu[1]+p4ph[nph]).M()/GeV;
		      if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
			hm2muosgamma->Fill(rm,wt);
		      }
		      else if(m_jet_sumPtTrk->at(ix)/GeV>20){
			hm2muosele->Fill(rm,wt);
		      }
		      if(rm>94&&rm<120){
			hphsumpt->Fill(m_jet_sumPtTrk->at(ix)/GeV<100.?m_jet_sumPtTrk->at(ix)/GeV:99,wt);
			hphsumptet->Fill(m_jet_sumPtTrk->at(ix)/m_jet_pt->at(ix),wt);
			if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
			  hphpt2muos->Fill(m_jet_pt->at(ix)/GeV, wt);
			  hphdr2muos->Fill(p4ph[nph].DeltaR(p4mu[0])<p4ph[nph].DeltaR(p4mu[1])?p4ph[nph].DeltaR(p4mu[0]):p4ph[nph].DeltaR(p4mu[1]), wt);
			}
			else if(m_jet_sumPtTrk->at(ix)/GeV>20){
                          hept2muos->Fill(m_jet_pt->at(ix)/GeV, wt);
                          hedr2muos->Fill(p4ph[nph].DeltaR(p4mu[0])<p4ph[nph].DeltaR(p4mu[1])?p4ph[nph].DeltaR(p4mu[0]):p4ph[nph].DeltaR(p4mu[1]), wt);
			}
		      }
		      if(m_hasMEphoton&&p4phme.DeltaR(p4ph[nph])<0.4){ 
			hphsumptmatched->Fill(m_jet_sumPtTrk->at(ix)/GeV<100.?m_jet_sumPtTrk->at(ix)/GeV:99,wt);
			hphsumptetmatched->Fill(m_jet_sumPtTrk->at(ix)/m_jet_pt->at(ix),wt);
			if(m_jet_sumPtTrk->at(ix)/GeV<2.0){
			  hm2muosgmatched->Fill((p4mu[0]+p4mu[1]+p4ph[nph]).M()/GeV,wt);
			  hphpt2muosmatched->Fill(m_jet_pt->at(ix)/GeV, wt);
			}
			else if(m_jet_sumPtTrk->at(ix)/GeV>20){
                          hm2muosematched->Fill((p4mu[0]+p4mu[1]+p4ph[nph]).M()/GeV,wt);
                          hept2muosmatched->Fill(m_jet_pt->at(ix)/GeV, wt);
			}
		      }
		      ++nph;
		    }
		  }
		  hnph2muos->Fill(nph,wt);
		}
		if(nJets_OR_T_MV2c10_70>=0){ 
		hm2muoscut->Fill(Mll01/GeV, wt);
		hnjets2muoscut->Fill(nJets_OR_T, wt);
		// do some sideband subtraction 
                // save Eta bins and Pt bins Nss/Nos = si+sj sum of two leptons, which should work.
                if(Mll01/GeV>80&&Mll01/GeV<100){ // signal region
                  heta2muos->Fill(fabs(lep_Eta_0), wt);
                  heta2muos->Fill(fabs(lep_Eta_1), wt);
                  hpt2muos->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2muos->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                }
                else if((Mll01/GeV>60&&Mll01/GeV<80)||(Mll01/GeV>100&&Mll01/GeV<120)){ // 2-times sideband
                  heta2muosb->Fill(fabs(lep_Eta_0), wt);
                  heta2muosb->Fill(fabs(lep_Eta_1), wt);
                  hpt2muosb->Fill(lep_Pt_0/GeV<140?lep_Pt_0/GeV:139.9, wt);
                  hpt2muosb->Fill(lep_Pt_1/GeV<140?lep_Pt_1/GeV:139.9, wt);
                }
              }
	    }
	  }
	}
	// here check the fakes e: conversion+fakes: muon: fakes using prob vs tag: selecting ttbar  
        if(trig_match&&dilep_type==1&&!nTaus_OR_Pt25&&abs(total_charge)==2&&lep_Pt_0>20e3&&lep_Pt_1>20e3){ //met<30 GeV ? ttbar vs z+bb:
          if(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)&&lep_Pt_0>27e3){
            hmet2muss->Fill(MET_RefFinal_et/GeV, wt);
            double mt = 2*MET_RefFinal_et*lep_Pt_0*(1-cos(MET_RefFinal_phi-lep_Phi_0));
            mt = mt>0.?sqrt(mt):0.;
	    if(lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)){
	      hmt2muss->Fill(mt/GeV, wt);
	      hnbjets2muss->Fill(nJets_OR_T_MV2c10_70, wt);
	      hnjets2muss->Fill(nJets_OR_T, wt);
	    }
            if(MET_RefFinal_et/GeV>20&&mt/GeV>50){
              if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T>1&&nJets_OR_T<4){
		TLorentzVector p4jet[10];
		int njets(0);
		for(int i = 0; i<nJets_OR_T; ++i){
		  if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged              
		    p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
					      m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
		    ++njets;
		  }
		}
		if(njets>=0){		  
		  double mhw(0); 
		  if(njets>1){
		    mhw = (p4jet[0]+p4jet[1]).M()/GeV;
		    hmhadw2muss->Fill(mhw,wt);
		  } 
		  if(mhw>=0){ // l+w+b
		    hmuorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		    hplimu->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		    hplivmu->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		      hplimuTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		      hplivmuTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		    }
		    if(lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)){
		      hfmuorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		      hptfmu->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptfmuTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      hdrfmu->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmuTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      if(lep_Pt_1/GeV<50){
			hdrfmulpt->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
			if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmulptTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      }
		      else{
			hdrfmuhpt->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
			if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmuhptTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      }
		    }
		    else{ // anti-tight april-11 
		      hptmu->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptmuTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      hdrmu->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmuTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      if(lep_Pt_1/GeV<50){
			hdrmulpt->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
			if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmulptTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      }
		      else{
			hdrmuhpt->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
			if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmuhptTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		      }		      
		    }
		  }
                }
              }
	      // double btagged 
              if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T>1&&nJets_OR_T<4){
		hmuorigX->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		hplimuX->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		hplivmuX->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		  hplimuXTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hplivmuXTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		}
		if(lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)){
		  hfmuorigX->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		  hptfmuX->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptfmuXTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  hdrfmuX->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmuXTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if(lep_Pt_1/GeV<50){
		    hdrfmulptX->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmulptXTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		  else{
		    hdrfmuhptX->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmuhptXTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		}
		else{ // anti-tight 
		  hptmuX->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptmuXTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  hdrmuX->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmuXTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if(lep_Pt_1/GeV<50){
		    hdrmulptX->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmulptXTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		  else{
		    hdrmuhptX->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmuhptXTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		}
	      }
	      // no tag 
              if(nJets_OR_T_MV2c10_70==0&&nJets_OR_T>1&&nJets_OR_T<4){
		hmuorigN->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		hplimuN->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		hplivmuN->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		  hplimuNTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hplivmuNTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		}
		if(lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)){
		  hfmuorigN->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		  hptfmuN->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptfmuNTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  hdrfmuN->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmuNTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if(lep_Pt_1/GeV<50){
		    hdrfmulptN->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmulptNTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		  else{
		    hdrfmuhptN->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrfmuhptNTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		}
		else{
		  hptmuN->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hptmuNTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  hdrmuN->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmuNTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  if(lep_Pt_1/GeV<50){
		    hdrmulptN->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmulptNTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		  else{
		    hdrmuhptN->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))hdrmuhptNTruth->Fill(lep_jet_deltaR_1<4?lep_jet_deltaR_1:3.9, wt);
		  }
		}
	      }
	    }
	  }
          // second muon
          if(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)&&lep_Pt_1>27e3){
            hmet2muss->Fill(MET_RefFinal_et/GeV, wt);
            double mt = 2*MET_RefFinal_et*lep_Pt_1*(1-cos(MET_RefFinal_phi-lep_Phi_1));
            mt = mt>0.?sqrt(mt):0.;
            if(MET_RefFinal_et/GeV>20&&mt/GeV>50){
              if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T>1&&nJets_OR_T<4){
                TLorentzVector p4jet[10];
                int njets(0);
                for(int i = 0; i<nJets_OR_T; ++i){
                  if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged                                                                
                    p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
                                              m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
                    ++njets;
                  }
                }
                if(njets>=0){
                  double mhw(0);
		  if(njets>1){
		    mhw= (p4jet[0]+p4jet[1]).M()/GeV;
		    hmhadw2muss->Fill(mhw,wt);
		  }
                  if(mhw>=0){ // l+w+b
                    hmuorig->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                    hplimu->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		    hplivmu->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
		      hplimuTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		      hplivmuTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
		    }
                    if(lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)){
		      hfmuorig->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                      hptfmu->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
                      if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hptfmuTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
                      hdrfmu->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                      if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmuTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                      if(lep_Pt_0/GeV<50){
                        hdrfmulpt->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                        if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmulptTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                      }
                      else{
                        hdrfmuhpt->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                        if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmuhptTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                      }
                    }
		    else{
		      hptmu->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		      if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hptmuTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		      hdrmu->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		      if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmuTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		      if(lep_Pt_0/GeV<50){
			hdrmulpt->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
			if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmulptTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		      }
		      else{
			hdrmuhpt->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
			if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmuhptTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		      }
		    }
                  }
                }
              }
              // double btagged
              if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T>1&&nJets_OR_T<4){
                hmuorigX->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                hplimuX->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		hplivmuX->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
                if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
		  hplimuXTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		  hplivmuXTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
		}
                if(lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)){
		  hfmuorigX->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                  hptfmuX->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
                  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hptfmuXTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
                  hdrfmuX->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmuXTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  if(lep_Pt_0/GeV<50){
                    hdrfmulptX->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmulptXTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  }
                  else{
                    hdrfmuhptX->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmuhptXTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  }
		}
		else{
		  hptmuX->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hptmuXTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  hdrmuX->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmuXTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  if(lep_Pt_0/GeV<50){
		    hdrmulptX->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmulptXTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  }
		  else{
		    hdrmuhptX->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmuhptXTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  } 
		}
              }
	      // no tags 
              if(nJets_OR_T_MV2c10_70==0&&nJets_OR_T>1&&nJets_OR_T<4){
                hmuorigN->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                hplimuN->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		hplivmuN->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
                if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
		  hplimuNTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		  hplivmuNTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
		}
                if(lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)){
		  hfmuorigN->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                  hptfmuN->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
                  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hptfmuNTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
                  hdrfmuN->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmuNTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  if(lep_Pt_0/GeV<50){
                    hdrfmulptN->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmulptNTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  }
                  else{
                    hdrfmuhptN->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrfmuhptNTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
                  }
		}
		else{
		  hptmuN->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hptmuNTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  hdrmuN->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmuNTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  if(lep_Pt_0/GeV<50){
		    hdrmulptN->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmulptNTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  }
		  else{
		    hdrmuhptN->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))hdrmuhptNTruth->Fill(lep_jet_deltaR_0<4?lep_jet_deltaR_0:3.9, wt);
		  }
		}
              }
            }
          }
	}
	// qmis electron estimation for fake electron: April 5 added 
        if(trig_match&&dilep_type==2&&!nTaus_OR_Pt25&&abs(total_charge)==0&&lep_Pt_0>20e3&&lep_Pt_1>20e3){ //met<30 GeV ? ttbar vs z+bb:
          if(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)&&lep_Pt_0>27e3){
	    int ieta0(0);
	    int ipt0(0);
	    if(abs(lep_Eta_1)<0.9){
	      ieta0 = 0;
	    }
	    else if(abs(lep_Eta_1)<1.37){
	      ieta0 = 1;
	    }
	    else if(abs(lep_Eta_1)<2.0){
	      ieta0 = 2;
	    }
	    else {
	      ieta0 = 3;
	    }
	    if(lep_Pt_1/GeV<60){
	      ipt0 = 0;
	    }
	    else if(lep_Pt_1/GeV<100){
	      ipt0 = 1;
	    }
	    else if(lep_Pt_1/GeV<140){
	      ipt0 = 2;
	    }
	    else{
	      ipt0 = 3;
	    }
	    int idmc = mc_channel_number>0?1:0; 
	    double wtqmis = qmisRate[idmc*3][ipt0+4*ieta0]; // tight: ct; anti-tight
            double wtqmisct = qmisRate[1+idmc*3][ipt0+4*ieta0];
            double wtqmisl = qmisRate[2+idmc*3][ipt0+4*ieta0];
	    double wtqmisx = lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)?wtqmis:wtqmisl;
	    //double wtqmisct = qmisRate[1+idmc*2][ipi0+4*ieta0];
	    hmetemuos->Fill(MET_RefFinal_et/GeV, wt*wtqmisx);
            double mt = 2*MET_RefFinal_et*lep_Pt_0*(1-cos(MET_RefFinal_phi-lep_Phi_0));
            mt = mt>0.?sqrt(mt):0.;
            if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
	      if(lep_chargeIDBDTTight_1>0.7){
		hmtemuos->Fill(mt/GeV, wt*wtqmisct);
		hnbjetsemuos->Fill(nJets_OR_T_MV2c10_70, wt*wtqmisct);
		hnjetsemuos->Fill(nJets_OR_T, wt*wtqmisct);
	      }
            }
            if(MET_RefFinal_et/GeV>20&&mt/GeV>50){
              if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T>1&&nJets_OR_T<4){
                TLorentzVector p4jet[10];
                int njets(0);
                for(int i = 0; i<nJets_OR_T; ++i){
                  if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged
                    p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
                                              m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
                    ++njets;
                  }
                }
                if(njets>=0){
                  double mhw(0.);
                  if(njets>1){
                    mhw= (p4jet[0]+p4jet[1]).M()/GeV;
                    hmhadwemuos->Fill(mhw,wt*wtqmisx);
                  }
                  if(mhw>=0){ // l+w+b
                    heqorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt*wtqmisx);
                    hplieq->Fill(lep_promptLeptonIso_TagWeight_1,wt*wtqmisx);
                    hpliveq->Fill(lep_promptLeptonVeto_TagWeight_1,wt*wtqmisx);
                    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
                      hplieqTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt*wtqmisx);
                      hpliveqTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt*wtqmisx);
                    }
                    if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		      if(lep_chargeIDBDTTight_1>0.7){
			hptfeq->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisct);
			if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
			  hptfeqTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisct);
		      }
                    }
		    else{
		      hpteq->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisl);
		      if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1)){
			hpteqTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisl);
		      }
		    }
                  }
                }
              }
              // double btagged
              if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T>1&&nJets_OR_T<4){
                heqorigX->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt*wtqmisx);
                hplieqX->Fill(lep_promptLeptonIso_TagWeight_1,wt*wtqmisx);
                hpliveqX->Fill(lep_promptLeptonVeto_TagWeight_1,wt*wtqmisx);
                if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
                  hplieqXTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt*wtqmisx);
                  hpliveqXTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt*wtqmisx);
                }
                if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		  if(lep_chargeIDBDTTight_1>0.7){
		    hptfeqX->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisct);
		    if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		      hptfeqXTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisct);
		  }
                }
		else{
		  hpteqX->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisl);
		  if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		    hpteqXTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisl);
		}
              }
              // no tags
              if(nJets_OR_T_MV2c10_70==0&&nJets_OR_T>1&&nJets_OR_T<4){
                heqorigN->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt*wtqmisx);
                hplieqN->Fill(lep_promptLeptonIso_TagWeight_1,wt*wtqmisx);
                hpliveqN->Fill(lep_promptLeptonVeto_TagWeight_1,wt*wtqmisx);
                if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
                  hplieqNTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt*wtqmisx);
                  hpliveqNTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt*wtqmisx);
                }
                if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		  if(lep_chargeIDBDTTight_1>0.7){
		    hptfeqN->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisct);
		    if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		      hptfeqNTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisct);
		  }
                }
		else{
		  hpteqN->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisl);
		  if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		    hpteqNTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt*wtqmisl);		  
		}
              }
            }
          }
          // second muon
          if(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)&&lep_Pt_1>27e3){
            int ieta0(0);
            int ipt0(0);
            if(abs(lep_Eta_0)<0.9){
              ieta0 = 0;
            }
            else if(abs(lep_Eta_0)<1.37){
              ieta0 = 1;
            }
            else if(abs(lep_Eta_0)<2.0){
              ieta0 = 2;
            }
            else {
              ieta0 = 3;
            }
            if(lep_Pt_0/GeV<60){
              ipt0 = 0;
            }
            else if(lep_Pt_0/GeV<100){
              ipt0 = 1;
            }
            else if(lep_Pt_0/GeV<140){
              ipt0 = 2;
            }
            else{
              ipt0 = 3;
            }
            int idmc = mc_channel_number>0?1:0;
	    double wtqmis = qmisRate[idmc*3][ipt0+4*ieta0]; // tight: ct; anti-tight
            double wtqmisct = qmisRate[1+idmc*3][ipt0+4*ieta0];
            double wtqmisl = qmisRate[2+idmc*3][ipt0+4*ieta0];
	    double wtqmisx = lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)?wtqmis:wtqmisl;
            hmetemuos->Fill(MET_RefFinal_et/GeV, wt*wtqmisx);
            double mt = 2*MET_RefFinal_et*lep_Pt_1*(1-cos(MET_RefFinal_phi-lep_Phi_1));
            mt = mt>0.?sqrt(mt):0.;
            if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
	      if(lep_chargeIDBDTTight_0>0.7){
		hmtemuos->Fill(mt/GeV, wt*wtqmisct);
		hnbjetsemuos->Fill(nJets_OR_T_MV2c10_70, wt*wtqmisct);
		hnjetsemuos->Fill(nJets_OR_T, wt*wtqmisct);
	      }
            }
            if(MET_RefFinal_et/GeV>20&&mt/GeV>50){
              if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T>1&&nJets_OR_T<4){
                TLorentzVector p4jet[10];
                int njets(0);
                for(int i = 0; i<nJets_OR_T; ++i){
                  if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged
                    p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
                                              m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
                    ++njets;
                  }
                }
                if(njets>=0){
                  double mhw(0);
                  if(njets>1){
                    mhw = (p4jet[0]+p4jet[1]).M()/GeV;
                    hmhadwemuos->Fill(mhw,wt*wtqmisx);
                  }
                  if(mhw>=0){ // l+w+b
                    heqorig->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt*wtqmisx);
                    hplieq->Fill(lep_promptLeptonIso_TagWeight_0,wt*wtqmisx);
                    hpliveq->Fill(lep_promptLeptonVeto_TagWeight_0,wt*wtqmisx);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
                      hplieqTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt*wtqmisx);
                      hpliveqTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt*wtqmisx);
                    }
                    if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
		      if(lep_chargeIDBDTTight_0>0.7){
			hptfeq->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisct);
			if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
			  hptfeqTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisct);
		      }
                    }
		    else{
		      hpteq->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisl);
		      if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
			hpteqTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisl);		    
		    }
                  }
                }
              }
              // double btagged
              if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T>1&&nJets_OR_T<4){
                heqorigX->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt*wtqmisx);
                hplieqX->Fill(lep_promptLeptonIso_TagWeight_0,wt*wtqmisx);
                hpliveqX->Fill(lep_promptLeptonVeto_TagWeight_0,wt*wtqmisx);
                if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
                  hplieqXTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt*wtqmisx);
                  hpliveqXTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt*wtqmisx);
                }
                if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
		  if(lep_chargeIDBDTTight_0>0.7){
		    hptfeqX->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisct);
		    if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		      hptfeqXTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisct);
		  }
                }
		else{
		  hpteqX->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisl);
		  if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		    hpteqXTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisl);
		}
              }
              // no tags
              if(nJets_OR_T_MV2c10_70==0&&nJets_OR_T>1&&nJets_OR_T<4){
                heqorigN->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt*wtqmisx);
                hplieqN->Fill(lep_promptLeptonIso_TagWeight_0,wt*wtqmisx);
                hpliveqN->Fill(lep_promptLeptonVeto_TagWeight_0,wt*wtqmisx);
                if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
                  hplieqNTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt*wtqmisx);
                  hpliveqNTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt*wtqmisx);
                }
                if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
		  if(lep_chargeIDBDTTight_0>0.7){
		    hptfeqN->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisct);
		    if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		      hptfeqNTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisct);
		  }
                }
		else{
		  hpteqN->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisl);
		  if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		    hpteqNTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt*wtqmisl);
		}
              }
            }
          }
        } // emuss
	// fake electron
	// I am here using emu dilep_type==2
	if(trig_match&&dilep_type==2&&!nTaus_OR_Pt25&&abs(total_charge)==2&&lep_Pt_0>20e3&&lep_Pt_1>20e3){ //met<30 GeV ? ttbar vs z+bb:
	  //bool Qmiscut=mc_channel_number>0?(lep_isQMisID_1==0):true;//veto qmis April 7 	  
          if(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5&&SelectTLepid(0)&&lep_Pt_0>27e3){
            hmetemuss->Fill(MET_RefFinal_et/GeV, wt);
            double mt = 2*MET_RefFinal_et*lep_Pt_0*(1-cos(MET_RefFinal_phi-lep_Phi_0));
            mt = mt>0.?sqrt(mt):0.;
	    if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
	      if(lep_chargeIDBDTTight_1>0.7){
		hmtemuss->Fill(mt/GeV, wt);
		hnbjetsemuss->Fill(nJets_OR_T_MV2c10_70, wt);
		hnjetsemuss->Fill(nJets_OR_T, wt);
	      }
	    }
            if(MET_RefFinal_et/GeV>20&&mt/GeV>50){
              if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T>1&&nJets_OR_T<4){
		TLorentzVector p4jet[10];
		int njets(0);
		for(int i = 0; i<nJets_OR_T; ++i){
		  if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged              
		    p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
					      m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
		    ++njets;
		  }
		}
		if(njets>=0){
		  double mhw(0.);
		  if(njets>1){
		    mhw= (p4jet[0]+p4jet[1]).M()/GeV;
		    hmhadwemuss->Fill(mhw,wt);
		  } 
		  if(mhw>=0){ // l+w+b
		    heorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		    hplie->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		    hplive->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		    if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		      hplieTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		      hpliveTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		    }
		    if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		      if(lep_chargeIDBDTTight_1>0.7){
			hfeorig->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
			hptfe->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
			if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
			  hptfeTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      }
		    }
		    else{
		      hpte->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1)){
			hpteTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		      }
		    }
		  }
                }
              }
	      // double btagged 
              if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T>1&&nJets_OR_T<4){
		heorigX->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		hplieX->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		hpliveX->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		  hplieXTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hpliveXTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		}
		if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		  if(lep_chargeIDBDTTight_1>0.7){
                    hfeorigX->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		    hptfeX->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		      hptfeXTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  }
		}
		else{
		  hpteX->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		    hpteXTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		}
	      }
	      // no tags 
              if(nJets_OR_T_MV2c10_70==0&&nJets_OR_T>1&&nJets_OR_T<4){
		heorigN->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		hplieN->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		hpliveN->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		if((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0)){
		  hplieNTruth->Fill(lep_promptLeptonIso_TagWeight_1,wt);
		  hpliveNTruth->Fill(lep_promptLeptonVeto_TagWeight_1,wt);
		}
		if(lep_promptLeptonVeto_TagWeight_1<-0.7&&SelectTLepid(1)){
		  if(lep_chargeIDBDTTight_1>0.7){
                    hfeorigN->Fill(lep_isTruthMatched_1?lep_truthOrigin_1:-1, wt);
		    hptfeN->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		    if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		      hptfeNTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  }
		}
		else{
		  hpteN->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		  if(((lep_truthOrigin_1>9&&lep_truthOrigin_1<15)||(lep_truthOrigin_1==43||lep_truthOrigin_1==0))&&(!lep_isQMisID_1))
		    hpteNTruth->Fill(lep_Pt_1/GeV<100?lep_Pt_1/GeV:99.9, wt);
		}
	      }
	    }
	  }
          // second muon
	  //Qmiscut=mc_channel_number>0?(lep_isQMisID_0==0):true;
          if(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5&&SelectTLepid(1)&&lep_Pt_1>27e3){
            hmetemuss->Fill(MET_RefFinal_et/GeV, wt);
            double mt = 2*MET_RefFinal_et*lep_Pt_1*(1-cos(MET_RefFinal_phi-lep_Phi_1));
            mt = mt>0.?sqrt(mt):0.;
            if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
	      if(lep_chargeIDBDTTight_0>0.7){
		hmtemuss->Fill(mt/GeV, wt);
		hnbjetsemuss->Fill(nJets_OR_T_MV2c10_70, wt);
		hnjetsemuss->Fill(nJets_OR_T, wt);
	      }
            }
            if(MET_RefFinal_et/GeV>20&&mt/GeV>50){
              if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T>1&&nJets_OR_T<4){
                TLorentzVector p4jet[10];
                int njets(0);
                for(int i = 0; i<nJets_OR_T; ++i){
                  if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged                                                                
                    p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
                                              m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
                    ++njets;
                  }
                }
                if(njets>=0){
                  double mhw(0);
		  if(njets>1){
		    mhw = (p4jet[0]+p4jet[1]).M()/GeV;
		    hmhadw2muss->Fill(mhw,wt);
		  }
                  if(mhw>=0){ // l+w+b
                    heorig->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                    hplie->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		    hplive->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
                    if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
		      hplieTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		      hpliveTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
		    }
                    if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
		      if(lep_chargeIDBDTTight_0>0.7){
			hfeorig->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
			hptfe->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
			if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
			  hptfeTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		      }
                    }
		    else{
		      hpte->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		      if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
			hpteTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		    }
                  }
                }
              }
              // double btagged
              if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T>1&&nJets_OR_T<4){
                heorigX->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                hplieX->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		hpliveX->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
                if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
		  hplieXTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		  hpliveXTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
		}
                if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
		  if(lep_chargeIDBDTTight_0>0.7){
                    hfeorigX->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
		    hptfeX->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		    if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		      hptfeXTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  }
		}
		else{
		  hpteX->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		    hpteXTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		}
              }
	      // no tags 
              if(nJets_OR_T_MV2c10_70==0&&nJets_OR_T>1&&nJets_OR_T<4){
                heorigN->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
                hplieN->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		hpliveN->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
                if((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0)){
		  hplieNTruth->Fill(lep_promptLeptonIso_TagWeight_0,wt);
		  hpliveNTruth->Fill(lep_promptLeptonVeto_TagWeight_0,wt);
		}
                if(lep_promptLeptonVeto_TagWeight_0<-0.7&&SelectTLepid(0)){
		  if(lep_chargeIDBDTTight_0>0.7){
                    hfeorigN->Fill(lep_isTruthMatched_0?lep_truthOrigin_0:-1, wt);
		    hptfeN->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		    if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		      hptfeNTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  }
		}
		else{
		  hpteN->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		  if(((lep_truthOrigin_0>9&&lep_truthOrigin_0<15)||(lep_truthOrigin_0==43||lep_truthOrigin_0==0))&&(!lep_isQMisID_0))
		    hpteNTruth->Fill(lep_Pt_0/GeV<100?lep_Pt_0/GeV:99.9, wt);
		}
              }
            }
          }
	} // emuss 	
	// check the ltau
	if(trig_match&&dilep_type&&total_charge==0&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&
	   ((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&SelectTLepid(0)&&
	   ((abs(lep_ID_1)==11&&lep_promptLeptonVeto_TagWeight_1<-0.7)||(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5))&&SelectTLepid(1)){ //met>30 GeV ? ttbar vs z+bb:
	  // check tt+VBF
	  if((dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&nJets_OR_T>0&&nTaus_OR_Pt25==0){
	    int nvbfj(0); 
	    TLorentzVector p4vbfj[20];
	    for(int i = 0; i<(int)m_jet_pt->size(); ++i){ 
	      if((fabs(m_jet_eta->at(i))>2.5&&fabs(m_jet_eta->at(i))<4.0)||(fabs(m_jet_eta->at(i))<2.5&&m_jet_passOR->at(i))){ // all jets 
		if(fabs(m_jet_eta->at(i))>2.0&&m_jet_pt->at(i)/GeV>30.0&&nvbfj<20){ 
		  p4vbfj[nvbfj].SetPtEtaPhiE(m_jet_pt->at(i),m_jet_eta->at(i),m_jet_phi->at(i),m_jet_E->at(i)); 
		  ++nvbfj; 
		}
	      }
	    }
	    if(nvbfj>1){ 
	      double mjjmax(0.);
	      for(int i = 0; i<nvbfj; ++i){ 
		for(int j = i+1; j<nvbfj; ++j){ 
		  if(fabs(p4vbfj[i].Eta()-p4vbfj[j].Eta())>3.0){ 
		    double rm = (p4vbfj[i]+p4vbfj[j]).M()/GeV;
		    if(mjjmax<rm)mjjmax = rm; 
		  }
		}
	      }
	      if(mjjmax>0)hmjjmax->Fill(mjjmax,wt); 
	      if(mjjmax>500){
		hvbfnjets->Fill(nJets_OR_T,wt);
		hvbfbjets->Fill(nJets_OR_T_MV2c10_70, wt);
		hvbfht->Fill(HT/GeV,wt);
		if(nJets_OR_T_MV2c10_70>1){
		  hvbfnjets2B->Fill(nJets_OR_T,wt);
		  hvbfht2B->Fill(HT/GeV,wt);
		}
		else if(nJets_OR_T_MV2c10_70==1){
		  hvbfnjets1B->Fill(nJets_OR_T,wt);
		  hvbfht1B->Fill(HT/GeV,wt);
		}
		else{
		  hvbfnjets0B->Fill(nJets_OR_T,wt);
		  hvbfht0B->Fill(HT/GeV,wt);
		}
	      }
	    }
	  }
	  // check the fake rate vs eta (0.,0.7, 1.4, 2.1, 2.8) and Pt: 20-60-100-140 GeV 
	  if((dilep_type==1||dilep_type==3)&&Mll01/GeV>80&&Mll01/GeV<100&&nJets_OR_T>0&&nJets_OR_T_MV2c10_70>0){ //z+jets // tag rate vs et with sumpt>5GeV
	    hnjetz->Fill(nJets_OR_T,wt);
	    for(int i=0; i<(int)m_tau_pt->size(); ++i){ 
	      double pt = m_tau_pt->at(i)/GeV;
	      double eta = m_tau_eta->at(i);
	      int ntk = m_tau_numTrack->at(i);
	      if(pt>25&&abs(m_tau_charge->at(i))==1&&(ntk==1||ntk==3)){
		if(fabs(eta)<2.50&&!(fabs(eta)>1.37&&fabs(eta)<1.52)){
		  if(m_tau_passEleBDT->at(i)&&m_tau_passMuonOLR->at(i)){ // m_tau_fromPV->at(i)
		    double drx =DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_0,lep_Phi_0)<DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_1,lep_Phi_1)?
		      DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_0,lep_Phi_0):DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_1,lep_Phi_1);
		    hdrltauz->Fill(drx,wt);
		    if(m_tau_BDTJetScoreSigTrans->at(i)>0.05&&drx>0.4){
		      hbdtsigtransz->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
		      if(m_tau_JetBDTSigMedium->at(i)){ 
			hptmtauz->Fill(pt<115?pt:114,wt);
                        hetamtauz->Fill(fabs(eta),wt); // new mar 10
                        hntkmtauz->Fill(ntk,wt); // new mar 10			
			htpvmtauz->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			hmv2cmtauz->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			if((mc_channel_number>0)&&(m_tau_truthType->at(i)!=10)){
			  if(m_tau_truthType->at(i)==2){
                            hptmtauzele->Fill(pt<115?pt:114, wt);
                          }
                          else if(m_tau_truthType->at(i)==6){
                            hptmtauzmu->Fill(pt<115?pt:114, wt);
                          }
			  else if(m_tau_truthJetFlavour->at(i)>0&&m_tau_truthJetFlavour->at(i)<4){ 
			    hptmtauzl->Fill(pt<115?pt:114, wt);
                            htruthmtauzl->Fill(m_tau_truthType->at(i),wt);
                            horigmtauzl->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==4){ 
			    hptmtauzc->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==5){ 
			    hptmtauzb->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==21){ 
			    hptmtauzg->Fill(pt<115?pt:114, wt);
			  }
			  else{
			    hptmtauzx->Fill(pt<115?pt:114, wt);
                            htruthmtauzx->Fill(m_tau_truthType->at(i),wt);
                            horigmtauzx->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			}
			//if((m_tau_truthOrigin->at(i)>9&&m_tau_truthOrigin->at(i)<15)||(m_tau_truthOrigin->at(i)==43||m_tau_truthOrigin->at(i)==0)){
			if(m_tau_truthType->at(i)==10){
			  hptmtauzTruth->Fill(pt<115?pt:114,wt);
			  hetamtauzTruth->Fill(fabs(eta),wt); // new mar 10 
			  hntkmtauzTruth->Fill(ntk,wt); // new mar 10
			  htpvmtauzTruth->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			  hmv2cmtauzTruth->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			}
		      }
		      else{
			hptltauz->Fill(pt<115?pt:114,wt);
                        hetaltauz->Fill(fabs(eta),wt); // new mar 10
                        hntkltauz->Fill(ntk,wt); // new mar10
			htpvltauz->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			hmv2cltauz->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			if((mc_channel_number>0)&&(m_tau_truthType->at(i)!=10)){
			  if(m_tau_truthType->at(i)==2){
                            hptltauzele->Fill(pt<115?pt:114, wt);
                          }
                          else if(m_tau_truthType->at(i)==6){
                            hptltauzmu->Fill(pt<115?pt:114, wt);
                          }  
			  else if(m_tau_truthJetFlavour->at(i)>0&&m_tau_truthJetFlavour->at(i)<4){ 
			    hptltauzl->Fill(pt<115?pt:114, wt);
                            htruthltauzl->Fill(m_tau_truthType->at(i),wt);
                            horigltauzl->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==4){ 
			    hptltauzc->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==5){ 
			    hptltauzb->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==21){ 
			    hptltauzg->Fill(pt<115?pt:114, wt);
			  }
			  else{
			    hptltauzx->Fill(pt<115?pt:114, wt);
                            htruthltauzx->Fill(m_tau_truthType->at(i),wt);
                            horigltauzx->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			}
			//if((m_tau_truthOrigin->at(i)>9&&m_tau_truthOrigin->at(i)<15)||(m_tau_truthOrigin->at(i)==43||m_tau_truthOrigin->at(i)==0)){
			if(m_tau_truthType->at(i)==10){
			  hptltauzTruth->Fill(pt<115?pt:114,wt);
                          hetaltauzTruth->Fill(fabs(eta),wt); // new mar 10
                          hntkltauzTruth->Fill(ntk,wt); // new mar 10
			  htpvltauzTruth->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			  hmv2cltauzTruth->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			}
		      }
		    }	
		  }
		}
	      }
	    }
	  }
	  //5-30 emu+b+tau
          if((dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<3&&nTaus_OR_Pt25==1){ // ttbar events
	    if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T==1){
	      hptmtauemu1B->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      if(tau_truthType_0!=10){
		hjfmtauemu1B->Fill(tau_truthJetFlavour_0,wt);
		if(tau_MV2c10_0>btagwpCut[1])hjfmtauemu1Bbwp1->Fill(tau_truthJetFlavour_0,wt);
	      }
	      if(tau_MV2c10_0>btagwpCut[0])hptmtauemu1Bbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      if(tau_MV2c10_0>btagwpCut[1])hptmtauemu1Bbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      if(tau_MV2c10_0>btagwpCut[2])hptmtauemu1Bbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      if(tau_MV2c10_0>btagwpCut[3])hptmtauemu1Bbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      if(tau_truthType_0==10){
		hptmtauemu1BTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[0])hptmtauemu1BTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[1])hptmtauemu1BTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[2])hptmtauemu1BTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[3])hptmtauemu1BTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      } // pt spectrum 5-31
	      else if(tau_truthJetFlavour_0==5){
		hptmtauemu1Bbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[0])hptmtauemu1Bbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[1])hptmtauemu1Bbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[2])hptmtauemu1Bbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[3])hptmtauemu1Bbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      }
	      else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
		hptmtauemu1Blep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[0])hptmtauemu1Blepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[1])hptmtauemu1Blepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[2])hptmtauemu1Blepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[3])hptmtauemu1Blepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      }
	      else{
		hptmtauemu1Bwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[0])hptmtauemu1Bwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[1])hptmtauemu1Bwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[2])hptmtauemu1Bwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[3])hptmtauemu1Bwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
	      }
	      //
	      if(tau_JetBDTSigTight_0){ // tight 
		hpttauemu1B->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_truthType_0!=10){
		  hjftauemu1B->Fill(tau_truthJetFlavour_0,wt);
		  if(tau_MV2c10_0>btagwpCut[1])hjftauemu1Bbwp1->Fill(tau_truthJetFlavour_0,wt);
		}
		if(tau_MV2c10_0>btagwpCut[0])hpttauemu1Bbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[1])hpttauemu1Bbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[2])hpttauemu1Bbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_MV2c10_0>btagwpCut[3])hpttauemu1Bbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		if(tau_truthType_0==10){
		  hpttauemu1BTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu1BTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu1BTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu1BTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu1BTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
		else if(tau_truthJetFlavour_0==5){
		  hpttauemu1Bbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu1Bbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu1Bbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu1Bbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu1Bbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
		else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
		  hpttauemu1Blep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu1Blepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu1Blepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu1Blepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu1Blepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
		else{
		  hpttauemu1Bwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu1Bwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu1Bwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu1Bwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu1Bwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
	      }
	    }
            if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T==2){
              hptmtauemu2B->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              if(tau_truthType_0!=10){
                hjfmtauemu2B->Fill(tau_truthJetFlavour_0,wt);
                if(tau_MV2c10_0>btagwpCut[1])hjfmtauemu2Bbwp1->Fill(tau_truthJetFlavour_0,wt);
              }
              if(tau_MV2c10_0>btagwpCut[0])hptmtauemu2Bbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              if(tau_MV2c10_0>btagwpCut[1])hptmtauemu2Bbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              if(tau_MV2c10_0>btagwpCut[2])hptmtauemu2Bbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              if(tau_MV2c10_0>btagwpCut[3])hptmtauemu2Bbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              if(tau_truthType_0==10){
                hptmtauemu2BTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[0])hptmtauemu2BTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hptmtauemu2BTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hptmtauemu2BTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hptmtauemu2BTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              }
              else if(tau_truthJetFlavour_0==5){
                hptmtauemu2Bbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[0])hptmtauemu2Bbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hptmtauemu2Bbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hptmtauemu2Bbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hptmtauemu2Bbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              }
              else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
                hptmtauemu2Blep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[0])hptmtauemu2Blepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hptmtauemu2Blepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hptmtauemu2Blepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hptmtauemu2Blepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              }
              else{
                hptmtauemu2Bwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[0])hptmtauemu2Bwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hptmtauemu2Bwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hptmtauemu2Bwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hptmtauemu2Bwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
              }
              if(tau_JetBDTSigTight_0){ // tight
                hpttauemu2B->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_truthType_0!=10){
                  hjftauemu2B->Fill(tau_truthJetFlavour_0,wt);
                  if(tau_MV2c10_0>btagwpCut[1])hjftauemu2Bbwp1->Fill(tau_truthJetFlavour_0,wt);
                }
                if(tau_MV2c10_0>btagwpCut[0])hpttauemu2Bbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hpttauemu2Bbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hpttauemu2Bbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hpttauemu2Bbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_truthType_0==10){
                  hpttauemu2BTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[0])hpttauemu2BTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[1])hpttauemu2BTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[2])hpttauemu2BTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[3])hpttauemu2BTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                }
		else if(tau_truthJetFlavour_0==5){
		  hpttauemu2Bbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu2Bbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu2Bbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu2Bbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu2Bbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
		else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
		  hpttauemu2Blep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu2Blepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu2Blepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu2Blepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu2Blepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
		else{
		  hpttauemu2Bwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hpttauemu2Bwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hpttauemu2Bwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hpttauemu2Bwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hpttauemu2Bwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		}
              }
            }	    
	  }
	  // 6-4 check ttbar njets 
	  if(dilep_type==2&&(lep_ID_0*lep_ID_1<0)&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<4)hnjetemuosB->Fill(nJets_OR_T,wt);
	  if(dilep_type==1&&(Mll01/GeV<80||Mll01/GeV>100)&&(lep_ID_0*lep_ID_1<0)&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<4)
	    hnjetmmosB->Fill(nJets_OR_T,wt);
          if(dilep_type==3&&(Mll01/GeV<80||Mll01/GeV>100)&&(lep_ID_0*lep_ID_1<0)&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<4)
            hnjeteeosB->Fill(nJets_OR_T,wt);
	  if(dilep_type==2&&(lep_ID_0*lep_ID_1>0)&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<4)hnjetemussB->Fill(nJets_OR_T,wt);
          if(dilep_type==1&&(Mll01/GeV<80||Mll01/GeV>100)&&(lep_ID_0*lep_ID_1>0)&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<4)
            hnjetmmssB->Fill(nJets_OR_T,wt);
          if(dilep_type==3&&(Mll01/GeV<80||Mll01/GeV>100)&&(lep_ID_0*lep_ID_1>0)&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<4)
            hnjeteessB->Fill(nJets_OR_T,wt);
	  //
	  if((dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&nJets_OR_T_MV2c10_70>0){ // ttbar events inclusive
            for(int i=0; i<(int)m_tau_pt->size(); ++i){
              double pt = m_tau_pt->at(i)/GeV;
              double eta = m_tau_eta->at(i);
              int ntk = m_tau_numTrack->at(i);
              if(pt>25&&abs(m_tau_charge->at(i))==1&&(ntk==1||ntk==3)){
                if(fabs(eta)<2.50&&!(fabs(eta)>1.37&&fabs(eta)<1.52)){
                  if(m_tau_passEleBDT->at(i)&&m_tau_passMuonOLR->at(i)){
		    double drx =DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_0,lep_Phi_0)<DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_1,lep_Phi_1)?
		      DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_0,lep_Phi_0):DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_1,lep_Phi_1);
		    if(drx>0.4&&m_tau_truthType->at(i)==10){
                      double ax = m_tau_MV2c10->at(i);
                      if(ax<=-1.)ax = -0.999;
                      if(ax>=1.)ax=0.999;
                      htaubdtsig2d->Fill(m_tau_BDTJetScoreSigTrans->at(i),ax, wt);
                      htaubdtsig->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
                      if(ax>btagwpCut[0])htaubdtsigbwp0->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
                      if(ax>btagwpCut[1])htaubdtsigbwp1->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
                      if(ax>btagwpCut[2])htaubdtsigbwp2->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
                      if(ax>btagwpCut[3])htaubdtsigbwp3->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
		      if(m_tau_JetBDTSigMedium->at(i)){
			if(ntk==1){
			  htaubdtsig1p->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[0])htaubdtsig1pbwp0->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[1])htaubdtsig1pbwp1->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[2])htaubdtsig1pbwp2->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[3])htaubdtsig1pbwp3->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			}
			else{
			  htaubdtsig3p->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[0])htaubdtsig3pbwp0->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[1])htaubdtsig3pbwp1->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[2])htaubdtsig3pbwp2->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(ax>btagwpCut[3])htaubdtsig3pbwp3->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			}
		      }
                    }
		  }
		}
	      }
	    }
	  }
	  if((dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<3){ // ttbar events control regions 
	    hnjetemuB->Fill(nJets_OR_T,wt);
            for(int i=0; i<(int)m_tau_pt->size(); ++i){
              double pt = m_tau_pt->at(i)/GeV;
              double eta = m_tau_eta->at(i);
              int ntk = m_tau_numTrack->at(i);
              if(pt>25&&abs(m_tau_charge->at(i))==1&&(ntk==1||ntk==3)){
                if(fabs(eta)<2.50&&!(fabs(eta)>1.37&&fabs(eta)<1.52)){
                  if(m_tau_passEleBDT->at(i)&&m_tau_passMuonOLR->at(i)){
		    double drx =DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_0,lep_Phi_0)<DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_1,lep_Phi_1)?
		      DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_0,lep_Phi_0):DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),lep_Eta_1,lep_Phi_1);
		    hdrltauemuB->Fill(drx,wt);
                    if(m_tau_BDTJetScoreSigTrans->at(i)>0.05&&drx>0.4){  
		      hbdtsigtransemuB->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
                      if(m_tau_JetBDTSigMedium->at(i)){
			hptmtauemuB->Fill(pt<115?pt:114,wt);
                        hetamtauemuB->Fill(fabs(eta),wt); // new mar 10
                        hntkmtauemuB->Fill(ntk,wt); // new mar 10
			htpvmtauemuB->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			hmv2cmtauemuB->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			if((mc_channel_number>0)&&(m_tau_truthType->at(i)!=10)){
			  if(m_tau_truthType->at(i)==2){ 
			    hptmtauemuBele->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthType->at(i)==6){
			    hptmtauemuBmu->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)>0&&m_tau_truthJetFlavour->at(i)<4){ 
			    hptmtauemuBl->Fill(pt<115?pt:114, wt);
			    htruthmtauemuBl->Fill(m_tau_truthType->at(i),wt);
			    horigmtauemuBl->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==4){ 
			    hptmtauemuBc->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==5){ 
			    hptmtauemuBb->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==21){ 
			    hptmtauemuBg->Fill(pt<115?pt:114, wt);
			  }
			  else{
			    hptmtauemuBx->Fill(pt<115?pt:114, wt);
                            htruthmtauemuBx->Fill(m_tau_truthType->at(i),wt);
                            horigmtauemuBx->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			}
			//if((m_tau_truthOrigin->at(i)>9&&m_tau_truthOrigin->at(i)<15)||(m_tau_truthOrigin->at(i)==43||m_tau_truthOrigin->at(i)==0)){
			if(m_tau_truthType->at(i)==10){
			  hptmtauemuBTruth->Fill(pt<115?pt:114,wt);
                          hetamtauemuBTruth->Fill(fabs(eta),wt); // new mar 10
                          hntkmtauemuBTruth->Fill(ntk,wt); // new mar 10
			  htpvmtauemuBTruth->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			  hmv2cmtauemuBTruth->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			}
                      }
		      else{
			hptltauemuB->Fill(pt<115?pt:114,wt);
                        hetaltauemuB->Fill(fabs(eta),wt); // new mar 10
                        hntkltauemuB->Fill(ntk,wt); // new mar 10
			htpvltauemuB->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			hmv2cltauemuB->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			if((mc_channel_number>0)&&(m_tau_truthType->at(i)!=10)){
			  if(m_tau_truthType->at(i)==2){
                            hptltauemuBele->Fill(pt<115?pt:114, wt);
                          }
                          else if(m_tau_truthType->at(i)==6){
                            hptltauemuBmu->Fill(pt<115?pt:114, wt);
                          }
			  else if(m_tau_truthJetFlavour->at(i)>0&&m_tau_truthJetFlavour->at(i)<4){ 
			    hptltauemuBl->Fill(pt<115?pt:114, wt);
                            htruthltauemuBl->Fill(m_tau_truthType->at(i),wt);
                            horigltauemuBl->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==4){ 
			    hptltauemuBc->Fill(pt<115?pt:114, wt);
			  }
			  else if(m_tau_truthJetFlavour->at(i)==5){ 
			    hptltauemuBb->Fill(pt<115?pt:114, wt);
			  }
			  else  if(m_tau_truthJetFlavour->at(i)==21){ 
			    hptltauemuBg->Fill(pt<115?pt:114, wt);
			  }
			  else{
			    hptltauemuBx->Fill(pt<115?pt:114, wt);
                            htruthltauemuBx->Fill(m_tau_truthType->at(i),wt);
                            horigltauemuBx->Fill(m_tau_truthOrigin->at(i),wt);
			  }
			}
			//if((m_tau_truthOrigin->at(i)>9&&m_tau_truthOrigin->at(i)<15)||(m_tau_truthOrigin->at(i)==43||m_tau_truthOrigin->at(i)==0)){
			if(m_tau_truthType->at(i)==10){
			  hptltauemuBTruth->Fill(pt<115?pt:114,wt);
                          hetaltauemuBTruth->Fill(fabs(eta),wt); // new mar 10
                          hntkltauemuBTruth->Fill(ntk,wt); // new mar 10
			  htpvltauemuBTruth->Fill(fabs(m_tau_PromptTauVeto->at(i))<1?m_tau_PromptTauVeto->at(i):0.99*m_tau_PromptTauVeto->at(i)/fabs(m_tau_PromptTauVeto->at(i)), wt); // mar 15
			  hmv2cltauemuBTruth->Fill(fabs(m_tau_MV2c10->at(i))<1?m_tau_MV2c10->at(i):0.99*m_tau_MV2c10->at(i)/fabs(m_tau_MV2c10->at(i)), wt); // mar 25
			}
		      }
                    }
                  }
                }
              }
            } 
	  }
	}
	if(onelep_type&&SLtrig_match){
	  bool ptcut = RunYear==2015?((abs(lep_ID_0)==11&&lep_Pt_0/GeV>25)||(abs(lep_ID_0)==13&&lep_Pt_0/GeV>21)):lep_Pt_0/GeV>27;
	  //
	  //check qcd 
          TLorentzVector p4lepx;
	  p4lepx.SetPtEtaPhiE(lep_Pt_0,lep_Eta_0, lep_Phi_0,lep_E_0);
	  TLorentzVector p4jet[10];
	  int njets(0);
	  for(int i = 0; i<nJets_OR_T; ++i){
	    if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))<0.83){ // not b-tagged              
	      p4jet[njets].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)), m_jet_eta->at(selected_jets_T->at(i)),
					m_jet_phi->at(selected_jets_T->at(i)),m_jet_E->at(selected_jets_T->at(i)));
	      ++njets;
	    }
	  }
	  TLorentzVector p4tau[10];
	  if(nTaus_OR_Pt25==1)p4tau[0].SetPtEtaPhiE(tau_pt_0, tau_eta_0,tau_phi_0,tau_E_0);
	  if(nTaus_OR_Pt25==2)p4tau[1].SetPtEtaPhiE(tau_pt_1, tau_eta_1,tau_phi_1,tau_E_1);
	  if(trig_match&&ptcut&&(!((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7&&lep_chargeIDBDTTight_0>0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5)))&&
		SelectTLepid(0)&&nJets_OR_T_MV2c10_70>0&&((nTaus_OR_Pt25==1&&nJets_OR_T<4)||(nTaus_OR_Pt25==2&&nJets_OR_T<3))){
	    if(MET_RefFinal_et/GeV>25.0){
              if(nTaus_OR_Pt25==2){
                // qcd 2tau mar 10                                                                                     
                if(tau_charge_0*tau_charge_1<0){
                  hptl2tauosqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
                  hptsubl2tauosqcd->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt);
                  hleptruthl2tauosqcd->Fill(lep_truthType_0,wt);
                }
                else{
                  hptl2taussqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
                  hptsubl2taussqcd->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt);
                  hleptruthl2taussqcd->Fill(lep_truthType_0,wt);
                }
              }
	      if(nTaus_OR_Pt25==1){
		int ican = FindLooseTau(); 
		if(ican>-1){ 
		  if(tau_charge_0*m_tau_charge->at(ican)<0){ // 
		    hptl2taumlosqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		    hleptruthl2taumlosqcd->Fill(lep_truthType_0,wt); // mar 15
		  }
		  else{
		    hptl2taumlssqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		    hleptruthl2taumlssqcd->Fill(lep_truthType_0,wt); // mar 15		    
		  }
		}
	      }
	      if(nTaus_OR_Pt25==1){
		if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os
		  hptmutauosqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  hetamutauosqcd->Fill(fabs(tau_eta_0), wt); // mar 10
                  hntkmutauosqcd->Fill(tau_numTrack_0, wt); // mar 10
		  if(tau_MV2c10_0>btagwpCut[0])hptltauosqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); //april 10 
		  if(tau_MV2c10_0>btagwpCut[1])hptltauosqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltauosqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltauosqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  //may 29
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    hptltau1posqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hptltau1posqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
		    hmwltau3posqcd->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau3posqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau3posqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau3posqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau3posqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau3posqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hmwltau3posqcdTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau3posqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3posqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau3posqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3posqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3posqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		  if(tau_truthType_0==10){
		    hptmutauosqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutauosqcdTruth->Fill(fabs(tau_eta_0),wt); // mar 10
                    hntkmutauosqcdTruth->Fill(tau_numTrack_0, wt); // mar 10
		    if(tau_MV2c10_0>btagwpCut[0])hptltauosqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); //april 10 
		    if(tau_MV2c10_0>btagwpCut[1])hptltauosqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltauosqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltauosqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  }
		  hleptruthmutauosqcd->Fill(lep_truthType_0,wt);
		}
		else{ // ss
		  hptmutaussqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  hetamutaussqcd->Fill(fabs(tau_eta_0),wt); // mar 10
                  hntkmutaussqcd->Fill(tau_numTrack_0, wt); // mar 10
		  if(tau_MV2c10_0>btagwpCut[0])hptltaussqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hptltaussqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltaussqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltaussqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  //may 29
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    hptltau1pssqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hptltau1pssqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
		    hmwltau3pssqcd->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);    
		    hptltau3pssqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hmwltau3pssqcdTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau3pssqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }		  
		  //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		  if(tau_truthType_0==10){
		    hptmutaussqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutaussqcdTruth->Fill(fabs(tau_eta_0),wt); // mar 10
                    hntkmutaussqcdTruth->Fill(tau_numTrack_0, wt); // mar 10
		    if(tau_MV2c10_0>btagwpCut[0])hptltaussqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltaussqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltaussqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltaussqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  }
		  hleptruthmutaussqcd->Fill(lep_truthType_0,wt);
		}
	      }
	    }
	    else{  // met<25 cuts may-29 
              if(nTaus_OR_Pt25==2){
                // qcd 2tau mar 10                                                                                     
                if(tau_charge_0*tau_charge_1<0){
                  hptl2tauosqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
                  hptsubl2tauosqcdlow->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt);
                  hleptruthl2tauosqcdlow->Fill(lep_truthType_0,wt);
                }
                else{
                  hptl2taussqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
                  hptsubl2taussqcdlow->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt);
                  hleptruthl2taussqcdlow->Fill(lep_truthType_0,wt);
                }
              }
	      if(nTaus_OR_Pt25==1){
		int ican = FindLooseTau(); 
		if(ican>-1){ 
		  if(tau_charge_0*m_tau_charge->at(ican)<0){ // 
		    hptl2taumlosqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		    hleptruthl2taumlosqcdlow->Fill(lep_truthType_0,wt); // mar 15
		  }
		  else{
		    hptl2taumlssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		    hleptruthl2taumlssqcdlow->Fill(lep_truthType_0,wt); // mar 15		    
		  }
		}
	      }
	      if(nTaus_OR_Pt25==1){
                if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os
                  hptmutauosqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  hetamutauosqcdlow->Fill(fabs(tau_eta_0),wt); // mar 10
                  hntkmutauosqcdlow->Fill(tau_numTrack_0, wt); // mar 10
		  if(tau_MV2c10_0>btagwpCut[0])hptltauosqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hptltauosqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltauosqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltauosqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(nJets_OR_T_MV2c10_70>1){
		    hnjetltauosqcdlow->Fill(nJets_OR_T,wt);
		    if(tau_JetBDTSigTight_0)hnjetltautightosqcdlow->Fill(nJets_OR_T,wt);
		    if(tau_MV2c10_0>btagwpCut[1]){
		      hnjetltauosqcdlowbwp1->Fill(nJets_OR_T,wt);
		      if(tau_JetBDTSigTight_0)hnjetltautightosqcdlowbwp1->Fill(nJets_OR_T,wt);
		    }
		  }
		  //may 29
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    //hmwltau1posqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau1posqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      //hmwltau1posqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau1posqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
		    hmwltau3posqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau3posqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau3posqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau3posqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau3posqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau3posqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hmwltau3posqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau3posqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3posqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau3posqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3posqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3posqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
                  //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		  if(tau_truthType_0==10){
		    hptmutauosqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    hetamutauosqcdlowTruth->Fill(fabs(tau_eta_0),wt); // mar 10
                    hntkmutauosqcdlowTruth->Fill(tau_numTrack_0, wt); // mar 10
		    if(nJets_OR_T_MV2c10_70>1){
		      hnjetltauosqcdlowTruth->Fill(nJets_OR_T,wt);
		      if(tau_JetBDTSigTight_0)hnjetltautightosqcdlowTruth->Fill(nJets_OR_T,wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hnjetltauosqcdlowTruthbwp1->Fill(nJets_OR_T,wt);
			if(tau_JetBDTSigTight_0)hnjetltautightosqcdlowTruthbwp1->Fill(nJets_OR_T,wt);
		      }
		    }
		    if(tau_MV2c10_0>btagwpCut[0])hptltauosqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltauosqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltauosqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltauosqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  }
                  hleptruthmutauosqcdlow->Fill(lep_truthType_0,wt);
                }
                else{ // ss
                  hptmutaussqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  hetamutaussqcdlow->Fill(fabs(tau_eta_0),wt); // mar 10
                  hntkmutaussqcdlow->Fill(tau_numTrack_0, wt); // mar 10
		  if(tau_MV2c10_0>btagwpCut[0])hptltaussqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); //april 10 
		  if(tau_MV2c10_0>btagwpCut[1])hptltaussqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltaussqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltaussqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(nJets_OR_T_MV2c10_70>1){
		    hnjetltaussqcdlow->Fill(nJets_OR_T,wt);
                    if(tau_JetBDTSigTight_0)hnjetltautightssqcdlow->Fill(nJets_OR_T,wt);
                    if(tau_MV2c10_0>btagwpCut[1]){
		      hnjetltaussqcdlowbwp1->Fill(nJets_OR_T,wt);
                      if(tau_JetBDTSigTight_0)hnjetltautightssqcdlowbwp1->Fill(nJets_OR_T,wt);
                    }
		  }
		  //may 29
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    //hmwltau1pssqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau1pssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      //hmwltau1pssqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau1pssqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
		    hmwltau3pssqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau3pssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hmwltau3pssqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
		      hptltau3pssqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
                  //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		  if(tau_truthType_0==10){
		    hptmutaussqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutaussqcdlowTruth->Fill(fabs(tau_eta_0),wt); // mar 10
                    hntkmutaussqcdlowTruth->Fill(tau_numTrack_0, wt); // mar 10
		    if(nJets_OR_T_MV2c10_70>1){
		      hnjetltaussqcdlowTruth->Fill(nJets_OR_T,wt);
		      if(tau_JetBDTSigTight_0)hnjetltautightssqcdlowTruth->Fill(nJets_OR_T,wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hnjetltaussqcdlowTruthbwp1->Fill(nJets_OR_T,wt);
			if(tau_JetBDTSigTight_0)hnjetltautightssqcdlowTruthbwp1->Fill(nJets_OR_T,wt);
		      }
		    }
		    if(tau_MV2c10_0>btagwpCut[0])hptltaussqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltaussqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltaussqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltaussqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  }
                  hleptruthmutaussqcdlow->Fill(lep_truthType_0,wt);
                }
              }
	    }
	  }
	  if(trig_match&&ptcut&&((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7&&lep_chargeIDBDTTight_0>0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&
		SelectTLepid(0)&&nJets_OR_T_MV2c10_70>0&&((nTaus_OR_Pt25==1&&nJets_OR_T<4)||(nTaus_OR_Pt25==2&&nJets_OR_T<3))){ // control region 
            hmetltau->Fill(MET_RefFinal_et/GeV, wt);
            double mt = 2*MET_RefFinal_et*lep_Pt_0*(1-cos(MET_RefFinal_phi-lep_Phi_0));
            mt = mt>0.?sqrt(mt):0.;
	    hmtltau->Fill(mt/GeV,wt);
	    nbjetsltau->Fill(nJets_OR_T_MV2c10_70, wt);
	    njetsltau->Fill(nJets_OR_T,wt); 
	    ntausltau->Fill(nTaus_OR_Pt25, wt); 
	    double wt_sftau(1.0);
            if(mc_channel_number>0){
              if(nTaus_OR_Pt25==1){
                if(tau_truthType_0!=10){
                  int ix =(tau_pt_0/GeV-25.)/25.;
                  if(ix<0)ix=0;
                  if(ix>3)ix=3;
                  wt_sftau *=FaketauSF[ix];
                }
              }
              if(nTaus_OR_Pt25==2){
                if(tau_truthType_0!=10){
                  int ix =(tau_pt_0/GeV-25.)/25.;
                  if(ix<0)ix=0;
                  if(ix>3)ix=3;
                  wt_sftau *=FaketauSF[ix];
                }
		if(tau_truthType_1!=10){
                  int ix =(tau_pt_1/GeV-25.)/25.;
                  if(ix<0)ix=0;
                  if(ix>3)ix=3;
                  wt_sftau *=FaketauSF[ix];
                }
              }
            }
	    if(nTaus_OR_Pt25==1){ // ltauss ltauos
	      // look for a loose 
	      if(MET_RefFinal_et/GeV>25.0){
		for(int i=0; i<(int)m_tau_pt->size(); ++i){ 
		  double pt = m_tau_pt->at(i)/GeV;
		  double eta = m_tau_eta->at(i);
		  int ntk = m_tau_numTrack->at(i);
		  if(pt>25&&abs(m_tau_charge->at(i))==1&&(ntk==1||ntk==3)){
		    if(fabs(eta)<2.50&&!(fabs(eta)>1.37&&fabs(eta)<1.52)){
		      if(m_tau_passEleBDT->at(i)&&m_tau_passMuonOLR->at(i)){
			double drx =DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i), lep_Eta_0, lep_Phi_0)<DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i),tau_eta_0,tau_phi_0)?
			  DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i), lep_Eta_0, lep_Phi_0):DrEtaPhi(m_tau_eta->at(i),m_tau_phi->at(i), tau_eta_0, tau_phi_0);
			hdrltauz->Fill(drx,wt);
			if(m_tau_BDTJetScoreSigTrans->at(i)>0.05&&drx>0.4){
			  hbdtsigtransltau->Fill(m_tau_BDTJetScoreSigTrans->at(i), wt);
			  if(tau_charge_0*m_tau_charge->at(i)<0){ 
			    hptltauftauos->Fill(pt<115?pt:114,wt);
			    if((lep_ID_0>0?-1:1)*tau_charge_0<0){
			      hptltauosftauos->Fill(pt<115?pt:114,wt);
			    }
			    else{
			      hptltaussftauos->Fill(pt<115?pt:114,wt);
			    }
			    if((mc_channel_number>0)&&(m_tau_truthType->at(i)!=10)){
			      if(m_tau_truthJetFlavour->at(i)<4){ 
				hptltauftauosl->Fill(pt<115?pt:114, wt);
			      }
			      else if(m_tau_truthJetFlavour->at(i)==4){ 
				hptltauftauosc->Fill(pt<115?pt:114, wt);
			      }
			      else if(m_tau_truthJetFlavour->at(i)==5){ 
				hptltauftauosb->Fill(pt<115?pt:114, wt);
			      }
			      else{ 
				hptltauftauosg->Fill(pt<115?pt:114, wt);
			      }
			    }
			    //if((m_tau_truthOrigin->at(i)>9&&m_tau_truthOrigin->at(i)<15)||(m_tau_truthOrigin->at(i)==43||m_tau_truthOrigin->at(i)==0)){
			    if(m_tau_truthType->at(i)==10){
			      hptltauftauosTruth->Fill(pt<115?pt:114,wt);
			      if((lep_ID_0>0?-1:1)*tau_charge_0<0){
				hptltauosftauosTruth->Fill(pt<115?pt:114,wt);
			      }
			      else{
				hptltaussftauosTruth->Fill(pt<115?pt:114,wt);
			      }
			    }
			  }
			  else{
			    hptltauftauss->Fill(pt<115?pt:114,wt);
			    if((lep_ID_0>0?-1:1)*tau_charge_0<0){
			      hptltauosftauss->Fill(pt<115?pt:114,wt);
			    }
			    else{
			      hptltaussftauss->Fill(pt<115?pt:114,wt);
			    }
			    if((mc_channel_number>0)&&(m_tau_truthType->at(i)!=10)){
			      if(m_tau_truthJetFlavour->at(i)<4){ 
				hptltauftaussl->Fill(pt<115?pt:114, wt);
			      }
			      else if(m_tau_truthJetFlavour->at(i)==4){ 
				hptltauftaussc->Fill(pt<115?pt:114, wt);
			      }
			      else if(m_tau_truthJetFlavour->at(i)==5){ 
				hptltauftaussb->Fill(pt<115?pt:114, wt);
			      }
			      else{ 
				hptltauftaussg->Fill(pt<115?pt:114, wt);
			      }
			    }
			    //if((m_tau_truthOrigin->at(i)>9&&m_tau_truthOrigin->at(i)<15)||(m_tau_truthOrigin->at(i)==43||m_tau_truthOrigin->at(i)==0)){
			    if(m_tau_truthType->at(i)==10){
			      hptltauftaussTruth->Fill(pt<115?pt:114,wt);
			      if((lep_ID_0>0?-1:1)*tau_charge_0<0){
				hptltauosftaussTruth->Fill(pt<115?pt:114,wt);
			      }
			      else{
				hptltaussftaussTruth->Fill(pt<115?pt:114,wt);
			      }			    
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	      //
	      if(MET_RefFinal_et/GeV>25.0){
		if(abs(lep_ID_0)>0){
		  int ican = FindLooseTau(); 
		  if(ican>-1){ 
		    if(tau_charge_0*m_tau_charge->at(ican)<0){ // 
		      hptl2taumlos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		      hleptruthl2taumlos->Fill(lep_truthType_0,wt); // mar 15
		    }
		    else{
		      hptl2taumlss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		      hleptruthl2taumlss->Fill(lep_truthType_0,wt); // mar 15		    
		    }
		  }
		  // check charm eff: and add taulepton mass 6-11  
		  if(tau_truthJetFlavour_0==5){
		    int nBx(0);
		    int indexc(-1);
		    for(int i = 0; i<nJets_OR_T; ++i){
		      if(m_jet_flavor_truth_label->at(selected_jets_T->at(i))==5&&m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))>0.83)++nBx;
		      if(m_jet_flavor_truth_label->at(selected_jets_T->at(i))==4)indexc = i; 
		    }
		    if(nBx>0&&indexc>-1){
		      double apt = m_jet_pt->at(selected_jets_T->at(indexc))/GeV;
		      hptltaucharm->Fill(apt<115?apt:114.,wt);
		      if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(indexc))>btagwpCut[0])hptltaucharmbwp0->Fill(apt<115?apt:114.,wt);
		      if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(indexc))>btagwpCut[1])hptltaucharmbwp1->Fill(apt<115?apt:114.,wt);
		      if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(indexc))>btagwpCut[2])hptltaucharmbwp2->Fill(apt<115?apt:114.,wt);
		      if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(indexc))>btagwpCut[3])hptltaucharmbwp3->Fill(apt<115?apt:114.,wt);
		    }
		  }
		  if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os
		    hptltauos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltauosbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltauosbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltauosbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltauosbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    hptltauoswt->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt*wt_sftau);
		    htpvltauos->Fill(fabs(tau_promptTauVeto_0)<1?tau_promptTauVeto_0:0.99*tau_promptTauVeto_0/fabs(tau_promptTauVeto_0), wt); // mar 15 
		    hmv2cltauos->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
		    if(nJets_OR_T_MV2c10_70>1){
		      hnjetltauos->Fill(nJets_OR_T,wt);
		      if(tau_JetBDTSigTight_0)hnjetltautightos->Fill(nJets_OR_T,wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hnjetltauosbwp1->Fill(nJets_OR_T,wt);
			if(tau_JetBDTSigTight_0)hnjetltautightosbwp1->Fill(nJets_OR_T,wt);
		      }
		    }
		    // may 29 check for bjet mass shape 
		    if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T==2){
		      if(tau_truthType_0!=10){
			hjfltauos1B->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5)hmwltauos1Bbj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		    }
		    //April 6
		    if(nJets_OR_T_MV2c10_70>1&&tau_JetBDTSigTight_0&&nJets_OR_T==2){
		      hleptruth1pos->Fill(lep_truthType_0,wt);
		      hptltau1pos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      hmleptau1pos->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		      if(tau_truthType_0!=10){
			hjfltau1pos->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hptltau1posbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1posbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1posbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1posbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1posbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
			  hptltau1poslep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1poslepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1poslepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1poslepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1poslepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else {
			  hptltau1poswj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1poswjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1poswjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1poswjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1poswjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1posbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau1posbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1posbwp1->Fill(tau_truthJetFlavour_0,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1posbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1posbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hptltau1posTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hmleptau1posTruth->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau1posTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau1posTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau1posTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau1posTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
		    if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		      hleptruth3pos->Fill(lep_truthType_0,wt);
		      hptltau3pos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      hmleptau3pos->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		      if(tau_truthType_0!=10){
			hjfltau3pos->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hptltau3posbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3posbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3posbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3posbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3posbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
			  hptltau3poslep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3poslepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3poslepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3poslepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3poslepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else {
			  hptltau3poswj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3poswjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3poswjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3poswjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3poswjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3posbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau3posbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3posbwp1->Fill(tau_truthJetFlavour_0,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3posbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3posbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hptltau3posTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hmleptau3posTruth->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau3posTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau3posTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau3posTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau3posTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hptltauosTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(nJets_OR_T_MV2c10_70>1){
			hnjetltauosTruth->Fill(nJets_OR_T,wt);
			if(tau_JetBDTSigTight_0)hnjetltautightosTruth->Fill(nJets_OR_T,wt);
			if(tau_MV2c10_0>btagwpCut[1]){
			  hnjetltauosTruthbwp1->Fill(nJets_OR_T,wt);
			  if(tau_JetBDTSigTight_0)hnjetltautightosTruthbwp1->Fill(nJets_OR_T,wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0])hptltauosTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltauosTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltauosTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltauosTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      htpvltauosTruth->Fill(fabs(tau_promptTauVeto_0)<1?tau_promptTauVeto_0:0.99*tau_promptTauVeto_0/fabs(tau_promptTauVeto_0), wt); // mar 15
		      hmv2cltauosTruth->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
		      // tau performances studies: 6-8
		      hsigtransltauosTruth->Fill(tau_BDTJetScoreSigTrans_0, wt); 
		      hmv2c10ltauosTruth->Fill(tau_MV2c10_0, wt);
		      if(tau_numTrack_0==1){ 
			hptmtau1posTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hetamtau1posTruth->Fill(fabs(tau_eta_0),wt); 
			hsigtransmtau1posTruth->Fill(tau_BDTJetScoreSigTrans_0, wt);
			hmv2c10mtau1posTruth->Fill(tau_MV2c10_0, wt);
			hpumtau1posTruth->Fill(mu<60?mu:59., wt);
			//6-13
			if(tau_MV2c10_0>btagwpCut[0]){
			  hptmtau1posTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau1posTruthbwp0->Fill(mu<60?mu:59., wt);
			}
			if(tau_MV2c10_0>btagwpCut[1]){
			  hptmtau1posTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau1posTruthbwp1->Fill(mu<60?mu:59., wt);
			}
			if(tau_MV2c10_0>btagwpCut[2]){
			  hptmtau1posTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau1posTruthbwp2->Fill(mu<60?mu:59., wt);
			}
			if(tau_MV2c10_0>btagwpCut[3]){
			  hptmtau1posTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);	
			  hpumtau1posTruthbwp3->Fill(mu<60?mu:59., wt);
			}
		      }
		      else if(tau_numTrack_0==3){
			hptmtau3posTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hetamtau3posTruth->Fill(fabs(tau_eta_0),wt); 
			hsigtransmtau3posTruth->Fill(tau_BDTJetScoreSigTrans_0, wt);
			hmv2c10mtau3posTruth->Fill(tau_MV2c10_0, wt);
			hpumtau3posTruth->Fill(mu<60?mu:59., wt);
			if(tau_MV2c10_0>btagwpCut[0]){
			  hptmtau3posTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau3posTruthbwp0->Fill(mu<60?mu:59., wt);
			}
			if(tau_MV2c10_0>btagwpCut[1]){
			  hptmtau3posTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau3posTruthbwp1->Fill(mu<60?mu:59., wt);
			}
			if(tau_MV2c10_0>btagwpCut[2]){
			  hptmtau3posTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau3posTruthbwp2->Fill(mu<60?mu:59., wt);
			}
			if(tau_MV2c10_0>btagwpCut[3]){
			  hptmtau3posTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hpumtau3posTruthbwp3->Fill(mu<60?mu:59., wt);
			}
		      }		      
		      if(tau_JetBDTSigTight_0){ 
			if(tau_numTrack_0==1){ 
			  hptttau1posTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hetattau1posTruth->Fill(fabs(tau_eta_0),wt); 
			  hsigtransttau1posTruth->Fill(tau_BDTJetScoreSigTrans_0, wt);
			  hmv2c10ttau1posTruth->Fill(tau_MV2c10_0, wt);
			  hputtau1posTruth->Fill(mu<60?mu:59., wt);
			  if(tau_MV2c10_0>btagwpCut[0]){
			    hptttau1posTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau1posTruthbwp0->Fill(mu<60?mu:59., wt);
			  }
			  if(tau_MV2c10_0>btagwpCut[1]){
			    hptttau1posTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau1posTruthbwp1->Fill(mu<60?mu:59., wt);
			  }
			  if(tau_MV2c10_0>btagwpCut[2]){
			    hptttau1posTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau1posTruthbwp2->Fill(mu<60?mu:59., wt);
			  }
			  if(tau_MV2c10_0>btagwpCut[3]){
			    hptttau1posTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau1posTruthbwp3->Fill(mu<60?mu:59., wt);
			  }						
			}
			else if(tau_numTrack_0==3){
			  hptttau3posTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hetattau3posTruth->Fill(fabs(tau_eta_0),wt); 
			  hsigtransttau3posTruth->Fill(tau_BDTJetScoreSigTrans_0, wt);
			  hmv2c10ttau3posTruth->Fill(tau_MV2c10_0, wt);
			  hputtau3posTruth->Fill(mu<60?mu:59., wt);
			  if(tau_MV2c10_0>btagwpCut[0]){
			    hptttau3posTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau3posTruthbwp0->Fill(mu<60?mu:59., wt);
			  }
			  if(tau_MV2c10_0>btagwpCut[1]){
			    hptttau3posTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau3posTruthbwp1->Fill(mu<60?mu:59., wt);
			  }
			  if(tau_MV2c10_0>btagwpCut[2]){
			    hptttau3posTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau3posTruthbwp2->Fill(mu<60?mu:59., wt);
			  }
			  if(tau_MV2c10_0>btagwpCut[3]){
			    hptttau3posTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			    hputtau3posTruthbwp3->Fill(mu<60?mu:59., wt);
			  }
			}		      
		      }		      
		    }
		    hleptruthltauos->Fill(lep_truthType_0,wt);
		    if(abs(lep_ID_0)>0){
		      hptmutauos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      hptmutauoswt->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt*wt_sftau);
		      hetamutauos->Fill(fabs(tau_eta_0),wt); // mar 10 
		      hntkmutauos->Fill(tau_numTrack_0, wt); // mar 10 
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      // tau performance checks 6/8
		      if(tau_truthType_0==10){
			hptmutauosTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hetamutauosTruth->Fill(fabs(tau_eta_0),wt); // mar 10
			hntkmutauosTruth->Fill(tau_numTrack_0, wt); // mar 10
		      }
		      hleptruthmutauos->Fill(lep_truthType_0,wt);
		    }
		    hetaltauos->Fill(fabs(tau_eta_0),wt); 
		    htightltauos->Fill(tau_JetBDTSigTight_0,wt); 
		    htagltauos->Fill(tau_tagWeightBin_0>=4?1:0,wt);
		    hntkltauos->Fill(tau_numTrack_0, wt);
		    hmorltauos->Fill(tau_passMuonOLR_0,wt);
		    horigltauos->Fill(tau_truthOrigin_0, wt); 
		    htypeltauos->Fill(tau_truthType_0, wt);
		    if(tau_truthType_0!=10)hjfltauos->Fill(tau_truthJetFlavour_0,wt);
		  }
		  else{ // ss
		    hptltauss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltaussbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltaussbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltaussbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltaussbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); 
		    hptltausswt->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt*wt_sftau);
		    htpvltauss->Fill(fabs(tau_promptTauVeto_0)<1?tau_promptTauVeto_0:0.99*tau_promptTauVeto_0/fabs(tau_promptTauVeto_0), wt); // mar 15
		    hmv2cltauss->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
		    if(nJets_OR_T_MV2c10_70>1){
		      hnjetltauss->Fill(nJets_OR_T,wt);
                      if(tau_JetBDTSigTight_0)hnjetltautightss->Fill(nJets_OR_T,wt);
                      if(tau_MV2c10_0>btagwpCut[1]){
                        hnjetltaussbwp1->Fill(nJets_OR_T,wt);
                        if(tau_JetBDTSigTight_0)hnjetltautightssbwp1->Fill(nJets_OR_T,wt);
                      }
		    }
                    if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T==2){
		      if(tau_truthType_0!=10){
			hjfltauss1B->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5)hmwltauss1Bbj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
                    }
		    //April 6
		    if(nJets_OR_T_MV2c10_70>1&&tau_JetBDTSigTight_0&&nJets_OR_T==2){
		      hleptruth1pss->Fill(lep_truthType_0,wt);
		      hptltau1pss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_truthType_0!=10){
			hjfltau1pss->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hptltau1pssbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1pssbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1pssbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1pssbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1pssbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
			  hptltau1psslep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1psslepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1psslepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1psslepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1psslepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else{
			  hptltau1psswj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1psswjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1psswjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1psswjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1psswjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1pssbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau1pssbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1pssbwp1->Fill(tau_truthJetFlavour_0,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1pssbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1pssbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hptltau1pssTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau1pssTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau1pssTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau1pssTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau1pssTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
		    if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		      hleptruth3pss->Fill(lep_truthType_0,wt);
		      hptltau3pss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_truthType_0!=10){
			hjfltau3pss->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hptltau3pssbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3pssbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3pssbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3pssbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3pssbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){
			  hptltau3psslep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3psslepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3psslepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3psslepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3psslepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else{
			  hptltau3psswj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3psswjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3psswjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3psswjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3psswjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3pssbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau3pssbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3pssbwp1->Fill(tau_truthJetFlavour_0,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3pssbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3pssbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hptltau3pssTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau3pssTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau3pssTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau3pssTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau3pssTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
		    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hptltaussTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(nJets_OR_T_MV2c10_70>1){
			hnjetltaussTruth->Fill(nJets_OR_T,wt);
			if(tau_JetBDTSigTight_0)hnjetltautightssTruth->Fill(nJets_OR_T,wt);
			if(tau_MV2c10_0>btagwpCut[1]){
			  hnjetltaussTruthbwp1->Fill(nJets_OR_T,wt);
			  if(tau_JetBDTSigTight_0)hnjetltautightssTruthbwp1->Fill(nJets_OR_T,wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0])hptltaussTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltaussTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltaussTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltaussTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      htpvltaussTruth->Fill(fabs(tau_promptTauVeto_0)<1?tau_promptTauVeto_0:0.99*tau_promptTauVeto_0/fabs(tau_promptTauVeto_0), wt); // mar 15
		      hmv2cltaussTruth->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
		    }
		    hleptruthltauss->Fill(lep_truthType_0,wt);
		    if(abs(lep_ID_0)>0){
		      hptmutauss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      hptmutausswt->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt*wt_sftau);
		      hptmutauss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      hetamutauss->Fill(fabs(tau_eta_0),wt); // mar 10 
		      hntkmutauss->Fill(tau_numTrack_0, wt); // mar 10 
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hptmutaussTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hetamutaussTruth->Fill(fabs(tau_eta_0),wt); // mar 10
			hntkmutaussTruth->Fill(tau_numTrack_0, wt); // mar 10
		      }
		      hleptruthmutauss->Fill(lep_truthType_0,wt);
		    }
		    hetaltauss->Fill(fabs(tau_eta_0),wt); 
		    htightltauss->Fill(tau_JetBDTSigTight_0,wt); 
		    htagltauss->Fill(tau_tagWeightBin_0>=4?1:0,wt);
		    hntkltauss->Fill(tau_numTrack_0, wt);
		    hmorltauss->Fill(tau_passMuonOLR_0,wt);
		    horigltauss->Fill(tau_truthOrigin_0, wt); 
		    htypeltauss->Fill(tau_truthType_0, wt);
		    if(tau_truthType_0!=10)hjfltauss->Fill(tau_truthJetFlavour_0,wt);		
		  }
		}
		// no met cuts for njets==3  
		if(abs(lep_ID_0)>0){		
		  int ican = FindLooseTau(); 
		  if(ican>-1){ 
		    if(tau_charge_0*m_tau_charge->at(ican)<0){ // 
		      hptl2taumloslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		      hleptruthl2taumloslow->Fill(lep_truthType_0,wt); // mar 15
		    }
		    else{
		      hptl2taumlsslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // mar 15
		      hleptruthl2taumlsslow->Fill(lep_truthType_0,wt); // mar 15		    
		    }
		  }
		  if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os 
                    hptmutauoslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutauoslow->Fill(fabs(tau_eta_0),wt); // mar 10
                    hntkmutauoslow->Fill(tau_numTrack_0, wt); // mar 10
		    if(tau_MV2c10_0>btagwpCut[0])hptltauoslowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltauoslowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltauoslowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltauoslowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //April 10
		    if(nJets_OR_T_MV2c10_70>1&&tau_JetBDTSigTight_0&&nJets_OR_T==3&&njets==1){
		      hptltau1poslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      hmwltau1poslow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hmleptau1poslow->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		      if(tau_truthType_0!=10){
			hjfltau1poslow->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hmwltau1poslowbj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau1poslowbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1poslowbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1poslowbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1poslowbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1poslowbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){ 
			  hptltau1poslowlep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1poslowlepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1poslowlepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1poslowlepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1poslowlepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hmwltau1poslowlep->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			}
			else{
			  hmwltau1poslowWjj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau1poslowwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1poslowwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1poslowwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1poslowwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1poslowwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0]){
			hptltau1poslowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1poslowbwp0->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1poslowbwp0->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau1poslowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1poslowbwp1->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1poslowbwp1->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2]){
			hptltau1poslowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1poslowbwp2->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1poslowbwp2->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[3]){
			hptltau1poslowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1poslowbwp3->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1poslowbwp3->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hmwltau1poslowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
			hptltau1poslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hmleptau1poslowTruth->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau1poslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau1poslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau1poslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau1poslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
		    if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
		      hptltau3poslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      hmwltau3poslow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hmleptau3poslow->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		      if(tau_truthType_0!=10){
			hjfltau3poslow->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hmwltau3poslowbj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau3poslowbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3poslowbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3poslowbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3poslowbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3poslowbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){ 
			  hptltau3poslowlep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3poslowlepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3poslowlepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3poslowlepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3poslowlepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hmwltau3poslowlep->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			}
			else{
			  hmwltau3poslowWjj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau3poslowwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3poslowwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3poslowwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3poslowwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3poslowwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0]){
			hptltau3poslowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3poslowbwp0->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3poslowbwp0->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau3poslowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3poslowbwp1->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3poslowbwp1->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2]){
			hptltau3poslowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3poslowbwp2->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3poslowbwp2->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[3]){
			hptltau3poslowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3poslowbwp3->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3poslowbwp3->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hmwltau3poslowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
			hptltau3poslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			hmleptau3poslowTruth->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau3poslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau3poslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau3poslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau3poslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
                    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hptmutauoslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      hetamutauoslowTruth->Fill(fabs(tau_eta_0),wt); // mar 10 
                      hntkmutauoslowTruth->Fill(tau_numTrack_0, wt); // mar 10 
		      if(tau_MV2c10_0>btagwpCut[0])hptltauoslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // april 10
		      if(tau_MV2c10_0>btagwpCut[1])hptltauoslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltauoslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltauoslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
                    hleptruthmutauoslow->Fill(lep_truthType_0,wt);
                  }
		  else{ // ss
                    hptmutausslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutausslow->Fill(fabs(tau_eta_0),wt); // mar 10 
                    hntkmutausslow->Fill(tau_numTrack_0, wt); // mar 10 
		    if(tau_MV2c10_0>btagwpCut[0])hptltausslowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltausslowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltausslowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltausslowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    //April 10
		    if(nJets_OR_T_MV2c10_70>1&&tau_JetBDTSigTight_0&&nJets_OR_T==3&&njets==1){
		      hmwltau1psslow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
		      hptltau1psslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_truthType_0!=10){
			hjfltau1psslow->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hmwltau1psslowbj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau1psslowbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1psslowbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1psslowbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1psslowbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1psslowbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}		
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){ 
			  hptltau1psslowlep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1psslowlepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1psslowlepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1psslowlepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1psslowlepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hmwltau1psslowlep->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			}
			else{
			  hmwltau1psslowWjj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau1psslowwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau1psslowwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau1psslowwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau1psslowwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau1psslowwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }	
		      if(tau_MV2c10_0>btagwpCut[0]){
			hptltau1psslowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1psslowbwp0->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1psslowbwp0->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau1psslowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1psslowbwp1->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1psslowbwp1->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2]){
			hptltau1psslowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1psslowbwp2->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1psslowbwp2->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[3]){
			hptltau1psslowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau1psslowbwp3->Fill(tau_truthJetFlavour_0,wt);
			hmwltau1psslowbwp3->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hmwltau1psslowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
			hptltau1psslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau1psslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau1psslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau1psslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau1psslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
		    if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
		      hmwltau3psslow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
		      hptltau3psslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_truthType_0!=10){
			hjfltau3psslow->Fill(tau_truthJetFlavour_0,wt);
			if(tau_truthJetFlavour_0==5){
			  hmwltau3psslowbj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau3psslowbj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3psslowbjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3psslowbjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3psslowbjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3psslowbjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
			else if(tau_truthJetFlavour_0<0&&(tau_truthType_0==2||tau_truthType_0==6)){ 
			  hptltau3psslowlep->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3psslowlepbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3psslowlepbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3psslowlepbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3psslowlepbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  hmwltau3psslowlep->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			}
			else{
			  hmwltau3psslowWjj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
			  hptltau3psslowwj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[0])hptltau3psslowwjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[1])hptltau3psslowwjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[2])hptltau3psslowwjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			  if(tau_MV2c10_0>btagwpCut[3])hptltau3psslowwjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			}
		      }
		      if(tau_MV2c10_0>btagwpCut[0]){
			hptltau3psslowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3psslowbwp0->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3psslowbwp0->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[1]){
			hptltau3psslowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3psslowbwp1->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3psslowbwp1->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      if(tau_MV2c10_0>btagwpCut[2]){
			hptltau3psslowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3psslowbwp2->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3psslowbwp2->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);			
		      }
		      if(tau_MV2c10_0>btagwpCut[3]){
			hptltau3psslowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_truthType_0!=10)hjfltau3psslowbwp3->Fill(tau_truthJetFlavour_0,wt);
			hmwltau3psslowbwp3->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      }
		      //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		      if(tau_truthType_0==10){
			hmwltau3psslowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
			hptltau3psslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[0])hptltau3psslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[1])hptltau3psslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[2])hptltau3psslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
			if(tau_MV2c10_0>btagwpCut[3])hptltau3psslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      }
		    }
                    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){
		    if(tau_truthType_0==10){
		      hptmutausslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      hetamutausslowTruth->Fill(fabs(tau_eta_0),wt); // mar 10
                      hntkmutausslowTruth->Fill(tau_numTrack_0, wt); // mar 10
		      if(tau_MV2c10_0>btagwpCut[0])hptltausslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); // april 10 
		      if(tau_MV2c10_0>btagwpCut[1])hptltausslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltausslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltausslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
                    hleptruthmutausslow->Fill(lep_truthType_0,wt);
		  }
		}
	      } // met>25 GeV 
	      else{
		//
		if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os  
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    //hmwltau1posmetlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau1posmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1posmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1posmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1posmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1posmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      //hmwltau1pssqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau1posmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1posmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1posmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1posmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1posmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
                    hmwltau3posmetlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltau3posmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltau3posmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltau3posmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltau3posmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltau3posmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltau3posmetlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltau3posmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltau3posmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltau3posmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltau3posmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltau3posmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }		  
		}
		else{ //ss 
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
                    hptltau1pssmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltau1pssmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltau1pssmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltau1pssmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltau1pssmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hptltau1pssmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltau1pssmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltau1pssmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltau1pssmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltau1pssmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){
                    hmwltau3pssmetlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltau3pssmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltau3pssmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltau3pssmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltau3pssmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltau3pssmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltau3pssmetlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltau3pssmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltau3pssmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltau3pssmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltau3pssmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltau3pssmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
		}
		//
	      }
	    }
	    else if(nTaus_OR_Pt25==2){
              if(MET_RefFinal_et/GeV>=0){
		TLorentzVector p4tau[2];
		p4tau[0].SetPtEtaPhiE(tau_pt_0,tau_eta_0, tau_phi_0,tau_E_0);
		p4tau[1].SetPtEtaPhiE(tau_pt_1,tau_eta_1, tau_phi_1,tau_E_1);
		if(tau_charge_0*tau_charge_1<0){ // os 
		  hptl2tauos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
		  hptl2tauoswt->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt*wt_sftau); 
		  hleptruthl2tauos->Fill(lep_truthType_0,wt); 
		  hptsubl2tauos->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt); 
		  hptsubl2tauoswt->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt*wt_sftau); 
		  htightl2tauos->Fill(tau_JetBDTSigTight_0+tau_JetBDTSigTight_1,wt);
		  htagl2tauos->Fill(tau_tagWeightBin_0>=4?1:0+tau_tagWeightBin_1>=4?1:0,wt);
		  hmassl2tauos->Fill((p4tau[0]+p4tau[1]).M()/GeV, wt); 
		  hmassl2tauoswt->Fill((p4tau[0]+p4tau[1]).M()/GeV, wt*wt_sftau); 
		  htpvl2tauos->Fill(fabs(tau_promptTauVeto_0)<1?tau_promptTauVeto_0:0.99*tau_promptTauVeto_0/fabs(tau_promptTauVeto_0), wt); // mar 15
		  htpvsubl2tauos->Fill(fabs(tau_promptTauVeto_1)<1?tau_promptTauVeto_1:0.99*tau_promptTauVeto_1/fabs(tau_promptTauVeto_1), wt); // mar 15
		  hmv2cl2tauos->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
                  hmv2csubl2tauos->Fill(fabs(tau_MV2c10_1)<1?tau_MV2c10_1:0.99*tau_MV2c10_1/fabs(tau_MV2c10_1), wt); // mar 25 
		  int idx = 0; 
		  if((tau_truthType_0==10)&&(tau_truthType_1==10)){ 
		    idx = 3; 
		  }
		  else if((tau_truthType_0==10)&&(tau_truthType_1!=10)){
		    idx = 2; 
		  }
		  else if((tau_truthType_0!=10)&&(tau_truthType_1==10)){
		    idx = 1;
		  }
		  htruthl2tauos->Fill(idx,wt); 
		  if(tau_truthType_0!=10)hjfl2tauos->Fill(tau_truthJetFlavour_0,wt);
		  if(tau_truthType_1!=10)hjfl2tauos->Fill(tau_truthJetFlavour_1,wt);		
		}
		else { // ss 
		  hptl2tauss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt); 
		  hptl2tausswt->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt*wt_sftau);
		  hleptruthl2tauss->Fill(lep_truthType_0,wt);
		  hptsubl2tauss->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt); 
		  hptsubl2tausswt->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt*wt_sftau);
		  htightl2tauss->Fill(tau_JetBDTSigTight_0+tau_JetBDTSigTight_1,wt);
		  htagl2tauss->Fill(tau_tagWeightBin_0>=4?1:0+tau_tagWeightBin_1>=4?1:0,wt);
		  hmassl2tauss->Fill((p4tau[0]+p4tau[1]).M()/GeV, wt);
		  hmassl2tausswt->Fill((p4tau[0]+p4tau[1]).M()/GeV, wt*wt_sftau);
		  htpvl2tauss->Fill(fabs(tau_promptTauVeto_0)<1?tau_promptTauVeto_0:0.99*tau_promptTauVeto_0/fabs(tau_promptTauVeto_0), wt); // mar 15
		  htpvsubl2tauss->Fill(fabs(tau_promptTauVeto_1)<1?tau_promptTauVeto_1:0.99*tau_promptTauVeto_1/fabs(tau_promptTauVeto_1), wt); // mar 15
                  hmv2cl2tauss->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
                  hmv2csubl2tauss->Fill(fabs(tau_MV2c10_1)<1?tau_MV2c10_1:0.99*tau_MV2c10_1/fabs(tau_MV2c10_1), wt); // mar 25
		  hlepchl2tauss->Fill((lep_ID_0>0?-1:1)*tau_charge_0,wt); 
		  int idx = 0; 
		  if((tau_truthType_0==10)&&(tau_truthType_1==10)){ 
		    idx = 3; 
		  }
		  else if((tau_truthType_0==10)&&(tau_truthType_1!=10)){
		    idx = 2; 
		  }
		  else if((tau_truthType_0!=10)&&(tau_truthType_1==10)){
		    idx = 1;
		  }
		  htruthl2tauss->Fill(idx,wt); 
		  if(tau_truthType_0!=10)hjfl2tauss->Fill(tau_truthJetFlavour_0,wt);
		  if(tau_truthType_1!=10)hjfl2tauss->Fill(tau_truthJetFlavour_1,wt);		
		}
	      }
	      if(MET_RefFinal_et/GeV>=0.0){// low met mar 10
                // mar 10 l2tau qcd                                                                                    
                if(tau_charge_0*tau_charge_1<0){
                  hptl2tauoslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
                  hleptruthl2tauoslow->Fill(lep_truthType_0,wt);
                  hptsubl2tauoslow->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt);
                }
                else{
                  hptl2tausslow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114.,wt);
                  hleptruthl2tausslow->Fill(lep_truthType_0,wt);
                  hptsubl2tausslow->Fill(tau_pt_1/GeV<115?tau_pt_1/GeV:114.,wt);
                }
	      }
	    }
	  } // control regions
	  // fill l2tau ntuples here and l1tau+loose tau 
	  //((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))
	  if(ptcut&&SelectTLepid(0)&&(nJets_OR_T_MV2c10_70>0)&&(nTaus_OR_Pt25>0)){
	    TLorentzVector p4lep;
	    p4lep.SetPtEtaPhiE(lep_Pt_0,lep_Eta_0, lep_Phi_0,lep_E_0);
	    tnp_plv = lep_promptLeptonVeto_TagWeight_0; 
	    tnp_lepid = lep_ID_0; 
	    tnp_leptruth = lep_truthType_0 + 100*lep_truthOrigin_0;
            tnp_leptrig = lep_isTrigMatch_0;
	    tnp_lepqmistight = lep_chargeIDBDTTight_0;
	    tnp_lepambiguityType = lep_ambiguityType_0;
            hltaucutflow->Fill(0.,1.); 
            hltaucutflowct->Fill(0.,wt);
	    if(lep_isTrigMatch_0){
	      hltaucutflow->Fill(1.,1.);
	      hltaucutflowct->Fill(1.,wt);
	      if(nTaus_OR_Pt25==2&&(tau_charge_0*tau_charge_1)<0){
		hltaucutflow->Fill(2.,1.);
		hltaucutflowct->Fill(2.,wt);
		if((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7&&lep_chargeIDBDTTight_0>0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5)){
		  hltaucutflow->Fill(3.,1.);
		  hltaucutflowct->Fill(3.,wt);
		}
	      }
	    }
	    if(nTaus_OR_Pt25==2){ 
	      int njetx = nJets_OR_T>7?7:nJets_OR_T;
	      double nbjetx(0);
	      double ljmin(99.);
	      double jjmin(99.);
	      double taujmin(99999.);
	      double drtaujmin(99.);
	      double sumjets(0.);
	      TLorentzVector p4jet[10];
	      for(int i = 0; i<njetx; ++i){
		sumjets +=m_jet_pt->at(selected_jets_T->at(i));
		if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))>0.83){
		  ++nbjetx;
		}
		p4jet[i].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)),m_jet_eta->at(selected_jets_T->at(i)),m_jet_phi->at(selected_jets_T->at(i)),
					    m_jet_E->at(selected_jets_T->at(i)));
		double phi1 = m_jet_phi->at(selected_jets_T->at(i));
		double eta1 = m_jet_eta->at(selected_jets_T->at(i));
		double dr= DrEtaPhi(lep_Eta_0, lep_Phi_0, eta1, phi1); 
		if(dr<ljmin)ljmin = dr;
		//dr= DrEtaPhi(tau_eta_0, tau_phi_0, eta1, phi1)>DrEtaPhi(tau_eta_1, tau_phi_1, eta1, phi1)?DrEtaPhi(tau_eta_1, tau_phi_1, eta1, phi1):DrEtaPhi(tau_eta_0, tau_phi_0, eta1, phi1);
                //if(dr<taujmin)taujmin = dr;
		for(int j =i+1; j<njetx; ++j){
		  dr = DrEtaPhi(eta1, phi1,m_jet_eta->at(selected_jets_T->at(j)),
				       m_jet_phi->at(selected_jets_T->at(j)));
		  if(dr<jjmin)jjmin = dr;
		}
	      }	      
	      TLorentzVector p4tau[2];
	      p4tau[0].SetPtEtaPhiE(tau_pt_0,tau_eta_0, tau_phi_0,tau_E_0);
	      p4tau[1].SetPtEtaPhiE(tau_pt_1,tau_eta_1, tau_phi_1,tau_E_1);
	      for(int i = 0; i<njetx; ++i){ 
		double rm = (p4tau[0]+p4jet[i]).M()/GeV;
		if(rm<taujmin)taujmin = rm; 
		double dr = p4tau[0].DeltaR(p4jet[i]); 
		if(dr<drtaujmin)drtaujmin=dr;
		rm = (p4tau[1]+p4jet[i]).M()/GeV;
                if(rm<taujmin)taujmin = rm;
		dr = p4tau[1].DeltaR(p4jet[i]);
                if(dr<drtaujmin)drtaujmin=dr;
	      }
	      tnp_event =EventNumber;
	      tnp_run = RunNumber;
	      tnp_evtclass = nTaus_OR_Pt25;
	      tnp_weight = wt*(mc_channel_number>0?lepSFObjLoose/lepSFObjTight:1.0); // using lepSFObjLoose for 1l2tau only 
	      tnp_njets =njetx;
	      tnp_nbjets = nbjetx;
	      tnp_met = MET_RefFinal_et/GeV;
	      tnp_lept =lep_Pt_0/GeV*(lep_ID_0>0?-1:1); // signed with charge
	      tnp_htjets =sumjets;
	      tnp_leadtaupt = tau_pt_0/GeV;
	      tnp_subtaupt = tau_pt_1/GeV;
	      tnp_leadtaueta = tau_eta_0; 
	      tnp_subtaueta = tau_eta_1; 
	      tnp_leadtautight =tau_JetBDTSigTight_0; 
	      tnp_subtautight = tau_JetBDTSigTight_1;
	      tnp_leadtauntrk = tau_numTrack_0; 
	      tnp_subtauntrk = tau_numTrack_1; 
	      tnp_leadtaubdtjetscore = tau_BDTJetScoreSigTrans_0;
	      tnp_subtaubdtjetscore = tau_BDTJetScoreSigTrans_1;
	      tnp_mtautau = (p4tau[0]+p4tau[1]).M()/GeV;
	      tnp_ljdr = ljmin;
	      tnp_jjdr = jjmin;
	      tnp_drtautau = p4tau[0].DeltaR(p4tau[1]);
	      tnp_pttautau = (p4tau[0]+p4tau[1]).Pt()/GeV;
	      tnp_drltautau = p4lep.DeltaR(p4tau[0]+p4tau[1]);
	      tnp_leadtaubtag = tau_MV2c10_0; // new
              tnp_subtaubtag = tau_MV2c10_1; // new
	      tnp_leadtaubtagBin = tau_tagWeightBin_0; // new 6-28
              tnp_subtaubtagBin = tau_tagWeightBin_1; // new 6-28 
              tnp_leadtauptv = tau_promptTauVeto_0; // new
	      tnp_subtauptv = tau_promptTauVeto_1; // new
	      tnp_leadtautruth = tau_truthType_0==10?10:tau_truthJetFlavour_0; // new
              tnp_subtautruth = tau_truthType_1==10?10:tau_truthJetFlavour_1; //new
              tnp_leadtauch = tau_charge_0; // new
	      tnp_subtauch = tau_charge_1; // new
              tnp_etamax =fabs(tau_eta_0)>fabs(tau_eta_1)?fabs(tau_eta_0):fabs(tau_eta_1); 
	      tnp_leadfrompv = tau_fromPV_0;
	      tnp_subfrompv = tau_fromPV_1;
	      // BDT
	      tmva1l2tau_njets25 = njetx<6?njetx:5; // cap njets
	      tmva1l2tau_nbjets25 = nbjetx<4?nbjetx:3; // cap nbjets
	      tmva1l2tau_htjets = tnp_htjets;
	      tmva1l2tau_leadtaupt = tnp_leadtaupt;
	      tmva1l2tau_subtaupt= tnp_subtaupt;
	      tmva1l2tau_mtautau = tnp_mtautau;
	      tmva1l2tau_jjdr = tnp_jjdr;
	      double myBDT = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
	      if(fabs(myBDT)>=1.0)myBDT=0.999*myBDT/fabs(myBDT);
	      tnp_bdt = myBDT;
	      tnp_drltau = DrEtaPhi(lep_Eta_0, lep_Phi_0, tau_eta_0, tau_phi_0)>DrEtaPhi(lep_Eta_0, lep_Phi_0, tau_eta_1, tau_phi_1)?DrEtaPhi(lep_Eta_0, lep_Phi_0, tau_eta_1, tau_phi_1):DrEtaPhi(lep_Eta_0, lep_Phi_0, tau_eta_0, tau_phi_0);// which mini ?
	      tnp_drtauj = drtaujmin;
	      tnp_mtauj = taujmin;
	      double dphix = fabs(MET_RefFinal_phi - (p4tau[0]+p4tau[1]).Phi());
	      if(dphix>TMath::Pi())dphix = 2*TMath::Pi()-dphix;
	      tnp_drmetditau = dphix;
	      tnp->Fill();
	    }
	    else if(nTaus_OR_Pt25==1){
	      int ican = FindLooseTau();
	      if(ican>-1){
		int njetmax = nJets_OR_T>7?7:nJets_OR_T;
		int njetx(0);
		double nbjetx(0);
		double ljmin(99.);
		double jjmin(99.);
		double taujmin(99999.);
		double drtaujmin(99.);
		double sumjets(0.);
		TLorentzVector p4jet[10];
		for(int i = 0; i<njetmax; ++i){
		  double phi1 = m_jet_phi->at(selected_jets_T->at(i));
		  double eta1 = m_jet_eta->at(selected_jets_T->at(i));		  
		  if(DrEtaPhi(m_tau_eta->at(ican), m_tau_phi->at(ican), eta1, phi1)>0.4){
		    sumjets +=m_jet_pt->at(selected_jets_T->at(i));
		    if(m_jet_flavor_weight_MV2c10->at(selected_jets_T->at(i))>0.83){
		      ++nbjetx;
		    }
		    p4jet[njetx].SetPtEtaPhiE(m_jet_pt->at(selected_jets_T->at(i)),m_jet_eta->at(selected_jets_T->at(i)),m_jet_phi->at(selected_jets_T->at(i)),
						m_jet_E->at(selected_jets_T->at(i)));
		    double dr= DrEtaPhi(lep_Eta_0, lep_Phi_0, eta1, phi1);
		    if(dr<ljmin)ljmin = dr;
		    //dr= DrEtaPhi(tau_eta_0, tau_phi_0, eta1, phi1)>DrEtaPhi(m_tau_eta->at(ican), m_tau_phi->at(ican), eta1, phi1)?
		    //  DrEtaPhi(m_tau_eta->at(ican), m_tau_phi->at(ican), eta1, phi1):DrEtaPhi(tau_eta_0, tau_phi_0, eta1, phi1);
		    //if(dr<taujmin)taujmin = dr;
		    ++njetx;
		    for(int j =i+1; j<njetmax; ++j){
		      double phi2 = m_jet_phi->at(selected_jets_T->at(j));
		      double eta2 = m_jet_eta->at(selected_jets_T->at(j));
		      if(DrEtaPhi(m_tau_eta->at(ican), m_tau_phi->at(ican),eta2, phi2)>0.4){
			dr = DrEtaPhi(eta1, phi1, eta2, phi2);
			if(dr<jjmin)jjmin = dr;
		      }
		    }
		  }
                }
		TLorentzVector p4tau[2];
		p4tau[0].SetPtEtaPhiE(tau_pt_0,tau_eta_0, tau_phi_0,tau_E_0);
		p4tau[1].SetPtEtaPhiE(m_tau_pt->at(ican),m_tau_eta->at(ican), m_tau_phi->at(ican),m_tau_E->at(ican));
		for(int i = 0; i<njetx; ++i){
		  double rm = (p4tau[0]+p4jet[i]).M()/GeV;
		  if(rm<taujmin)taujmin = rm;
		  double dr = p4tau[0].DeltaR(p4jet[i]);
		  if(dr<drtaujmin)drtaujmin = dr;
		  rm = (p4tau[1]+p4jet[i]).M()/GeV;
		  if(rm<taujmin)taujmin = rm;
		  dr = p4tau[0].DeltaR(p4jet[i]);
                  if(dr<drtaujmin)drtaujmin = dr;
		}
		tnp_event =EventNumber;
		tnp_run = RunNumber;
		tnp_evtclass = nTaus_OR_Pt25;
		tnp_weight = wt*(mc_channel_number>0?lepSFObjLoose/lepSFObjTight:1.0); // using lepSFObjLoose for 1l2tau only
		tnp_njets =njetx;
		tnp_nbjets = nbjetx; 
		tnp_met = MET_RefFinal_et/GeV;
		tnp_lept =lep_Pt_0/GeV*(lep_ID_0>0?-1:1); // signed with charge
		tnp_htjets =sumjets;
		tnp_leadtaupt = tau_pt_0/GeV;
		tnp_subtaupt = m_tau_pt->at(ican)/GeV;
		tnp_leadtaueta = tau_eta_0;
		tnp_subtaueta = m_tau_eta->at(ican);
		tnp_leadtautight =tau_JetBDTSigTight_0;
		tnp_subtautight = m_tau_JetBDTSigTight->at(ican);
		tnp_leadtauntrk = tau_numTrack_0;
		tnp_subtauntrk = m_tau_numTrack->at(ican);
		tnp_leadtaubdtjetscore = tau_BDTJetScoreSigTrans_0;
		tnp_subtaubdtjetscore = m_tau_BDTJetScoreSigTrans->at(ican);
		tnp_mtautau = (p4tau[0]+p4tau[1]).M()/GeV;
		tnp_ljdr = ljmin;
		tnp_jjdr = jjmin;
		tnp_drtautau = p4tau[0].DeltaR(p4tau[1]);
		tnp_pttautau = (p4tau[0]+p4tau[1]).Pt()/GeV;
		tnp_drltautau = p4lep.DeltaR(p4tau[0]+p4tau[1]);
		tnp_leadtaubtag = tau_MV2c10_0; // new
		tnp_subtaubtag = m_tau_MV2c10->at(ican); // new
		tnp_leadtaubtagBin = tau_tagWeightBin_0; // new 6-28
		tnp_subtaubtagBin = m_tau_tagWeightBin->at(ican); // new 6-28
		tnp_leadtauptv = tau_promptTauVeto_0; // new
		tnp_subtauptv = m_tau_PromptTauVeto->at(ican); // new
		tnp_leadtautruth = tau_truthType_0==10?10:tau_truthJetFlavour_0; // new
		tnp_subtautruth = m_tau_truthType->at(ican)==10?10:m_tau_truthJetFlavour->at(ican); //new
		tnp_leadtauch = tau_charge_0; // new
		tnp_subtauch = m_tau_charge->at(ican); // new
		tnp_etamax =fabs(tau_eta_0)>fabs(m_tau_eta->at(ican))?fabs(tau_eta_0):fabs(m_tau_eta->at(ican));
		tnp_leadfrompv = tau_fromPV_0;
		tnp_subfrompv = m_tau_fromPV->at(ican);
		// BDT
		tmva1l2tau_njets25 = njetx<6?njetx:5; // cap njets
		tmva1l2tau_nbjets25 = nbjetx<4?nbjetx:3; // cap nbjets
		tmva1l2tau_htjets = tnp_htjets;
		tmva1l2tau_leadtaupt = tnp_leadtaupt;
		tmva1l2tau_subtaupt= tnp_subtaupt;
		tmva1l2tau_mtautau = tnp_mtautau;
		tmva1l2tau_jjdr = tnp_jjdr;
		double myBDT = reader_tth1l2tau->EvaluateMVA("BDT_tth1l2tau");
		if(fabs(myBDT)>=1.0)myBDT=0.999*myBDT/fabs(myBDT);
		tnp_bdt = myBDT;
		tnp_drltau = DrEtaPhi(lep_Eta_0, lep_Phi_0, tau_eta_0, tau_phi_0)>DrEtaPhi(lep_Eta_0, lep_Phi_0, m_tau_eta->at(ican), m_tau_phi->at(ican))?DrEtaPhi(lep_Eta_0, lep_Phi_0, m_tau_eta->at(ican), m_tau_phi->at(ican)):DrEtaPhi(lep_Eta_0, lep_Phi_0, tau_eta_0, tau_phi_0);// which mini ?
		tnp_drtauj = drtaujmin;
		tnp_mtauj = taujmin;
		double dphix = fabs(MET_RefFinal_et - (p4tau[0]+p4tau[1]).Phi());
		if(dphix>TMath::Pi())dphix = 2*TMath::Pi()-dphix;
		tnp_drmetditau = dphix;
		tnp->Fill();
	      }
	    }
	  } // 
	}
	//
      } // trig
   }// loop over events 
   // end for now.
   //_histf->cd();
   _histf->Write();
   _histf->Close();
}
