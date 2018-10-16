#define MytthAnaFakeSys_cxx
#include "MytthAnaFakeSys.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TH1F.h"
#include "BDTcalculation.h"
const double btagwpCut[4]={0.94,0.83,0.64,0.11}; // 60, 70, 77, 85 % (0.8244273); // 0.645925 77% for MV2c10; 70% 0.8244273   
// tight muon: &&((abs(lep_ID_0)==13 && lep_isolationFixedCutLoose_0 && lep_promptLeptonVeto_TagWeight_0<-0.5)
// tight electron: (abs(lep_ID_0)==11 && lep_isolationFixedCutLoose_0 && lep_isTightLH_0 && lep_chargeIDBDTTight_0>0.7 && lep_ambiguityType_0 == 0 
//                 && lep_promptLeptonVeto_TagWeight_0<-0.7)) 

void MytthAnaFakeSys::Loop()
{
   int GeV(1000);
   bool debug(false);
   debug = _debug>0;
   if(_subdir){
     _histf->mkdir(_subdir); 
     _histf->cd(_subdir);
   }
   else{
     _histf->cd();
   }
   std::ofstream* fout_txt(0);
   if(debug)fout_txt = new std::ofstream(_outhist+".txt");
   TString BDT_tth1l2tau = "/global/projecta/projectdirs/atlas/weiming/testareaSL5/AxAODsData/tthAnaTop/makingPlots/MakingMini/TMVAClassification_BDTG.weightsv2901var7taupt25Triglept27tauTMnobtag_capnjets5nbjets3.xml";
   std::cout<<" which BDT ? "<<BDT_tth1l2tau<<std::endl;
   initialiseTMVA_tth1l2tau(BDT_tth1l2tau);
   // Booking here: 
   //TH1F*
   //ltau rate 
   TH1F* hmetltau = new TH1F("hmetltau","hmetltau",40,0., 200.);
   TH1F* hmtltau = new TH1F("hmtltau","hmtltau",40,0., 200.);
   TH1F* nbjetsltau = new TH1F("nbjetsltau","nbjetsltau", 5, 0., 5.);
   TH1F* njetsltau = new TH1F("njetsltau","njetsltau", 10, 0., 10.);
   TH1F* ntausltau = new TH1F("ntausltau","ntausltau", 5, 0., 5.);
   TH1F* hptltauos = new TH1F("hptltauos","hptltauos", 3,25.,115.);
   TH1F* hptltauosTruth = new TH1F("hptltauosTruth","hptltauosTruth", 3,25.,115.);
   TH1F* hleptruthltauos = new TH1F("hleptruthltauos","hleptruthltauos",25,0.,25.); // mar 3
   //8-4
   //ltau ss
   TH1F* hptltauss = new TH1F("hptltauss","hptltauss", 3,25.,115.);
   TH1F* hptltaussTruth = new TH1F("hptltaussTruth","hptltaussTruth", 3,25.,115.);
   TH1F* hleptruthltauss = new TH1F("hleptruthltauss","hleptruthltauss",25,0.,25.); // mar 3
   // 8/4 QCD studies 
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
   //os 8/4
   TH1F* hetamutauosqcd = new TH1F("hetamutauosqcd","hetamutauosqcd",5, 0., 2.5);
   TH1F* hntkmutauosqcd = new TH1F("hntkmutauosqcd","hntkmutauosqcd",5, 0., 5.0);
   TH1F* hetamutauosqcdTruth = new TH1F("hetamutauosqcdTruth","hetamutauosqcdTruth",5,0., 2.5);
   TH1F* hntkmutauosqcdTruth = new TH1F("hntkmutauosqcdTruth","hntkmutauosqcdTruth",5,0., 5.0);
   TH1F* hetamutauosqcdlow = new TH1F("hetamutauosqcdlow","hetamutauosqcdlow",5,0., 2.5);
   TH1F* hntkmutauosqcdlow = new TH1F("hntkmutauosqcdlow","hntkmutauosqcdlow",5,0., 5.0);
   TH1F* hetamutauosqcdlowTruth = new TH1F("hetamutauosqcdlowTruth","hetamutauosqcdlowTruth",5,0., 2.5);
   TH1F* hntkmutauosqcdlowTruth = new TH1F("hntkmutauosqcdlowTruth","hntkmutauosqcdlowTruth",5,0., 5.0);
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
   TH1F* hetamutausslow = new TH1F("hetamutausslow","hetamutausslow",5,0., 2.5);
   TH1F* hntkmutausslow = new TH1F("hntkmutausslow","hntkmutausslow",5,0., 5.0);
   TH1F* hetamutausslowTruth = new TH1F("hetamutausslowTruth","hetamutausslowTruth",5,0., 2.5);
   TH1F* hntkmutausslowTruth = new TH1F("hntkmutausslowTruth","hntkmutausslowTruth",5,0., 5.0);
   // 8-4
   TH1F* hmv2cltauos = new TH1F("hmv2cltauos","hmv2cltauos",20, -1., 1.);
   TH1F* hmv2cltauosTruth = new TH1F("hmv2cltauosTruth","hmv2cltauosTruth",20, -1., 1.);
   TH1F* hmv2cltauss = new TH1F("hmv2cltauss","hmv2cltauss",20, -1., 1.);
   TH1F* hmv2cltaussTruth = new TH1F("hmv2cltaussTruth","hmv2cltaussTruth",20, -1., 1.);
   // 8-4 
   TH1F* hjfltau1pos = new TH1F("hjfltau1pos","hjfltau1pos", 26, -1., 25.);
   TH1F* hleptruth1pos = new TH1F("hleptruth1pos","hleptruth1pos",25,0.,25.);
   TH1F* hjfltau3pos = new TH1F("hjfltau3pos","hjfltau3pos", 26, -1., 25.);
   TH1F* hleptruth3pos = new TH1F("hleptruth3pos","hleptruth3pos",25,0.,25.);
   TH1F* hjfltau1pss = new TH1F("hjfltau1pss","hjfltau1pss", 26, -1., 25.);
   TH1F* hleptruth1pss = new TH1F("hleptruth1pss","hleptruth1pss",25,0.,25.);
   TH1F* hjfltau3pss = new TH1F("hjfltau3pss","hjfltau3pss", 26, -1., 25.);
   TH1F* hleptruth3pss = new TH1F("hleptruth3pss","hleptruth3pss",25,0.,25.);
   //8-4
   TH1F* hjfltau1posbwp1 = new TH1F("hjfltau1posbwp1","hjfltau1posbwp1", 26, -1., 25.);
   TH1F* hjfltau3posbwp1 = new TH1F("hjfltau3posbwp1","hjfltau3posbwp1", 26, -1., 25.);
   TH1F* hjfltau1pssbwp1 = new TH1F("hjfltau1pssbwp1","hjfltau1pssbwp1", 26, -1., 25.);
   TH1F* hjfltau3pssbwp1 = new TH1F("hjfltau3pssbwp1","hjfltau3pssbwp1", 26, -1., 25.);
   //8-4
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
   // ltau
   hmetltau->Sumw2();
   hmtltau->Sumw2();
   nbjetsltau->Sumw2();
   njetsltau->Sumw2();
   ntausltau->Sumw2();
   // 1ltau os 
   hptltauos->Sumw2();
   hptltauosTruth->Sumw2();
   hleptruthltauos->Sumw2();
   //1ltau ss
   hptltauss->Sumw2();
   hptltaussTruth->Sumw2();
   hleptruthltauss->Sumw2();
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
   //
   hetamutauosqcd->Sumw2();
   hntkmutauosqcd->Sumw2();
   hetamutauosqcdTruth->Sumw2();
   hntkmutauosqcdTruth->Sumw2();
   hetamutauosqcdlow->Sumw2();
   hntkmutauosqcdlow->Sumw2();
   hetamutauosqcdlowTruth->Sumw2();
   hntkmutauosqcdlowTruth->Sumw2();
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
   hetamutausslow->Sumw2();
   hntkmutausslow->Sumw2();
   hetamutausslowTruth->Sumw2();
   hntkmutausslowTruth->Sumw2();
   //
   hmv2cltauos->Sumw2();
   hmv2cltauosTruth->Sumw2();
   hmv2cltauss->Sumw2();
   hmv2cltaussTruth->Sumw2();
   //os 8/4
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
   //ss 8/4
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
   //os 8/4
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
   //os 8/4
   TH1F* hptltauosqcdbwp0 = new TH1F("hptltauosqcdbwp0","hptltauosqcdbwp0",3,25.,115.);
   TH1F* hptltauosqcdbwp1 = new TH1F("hptltauosqcdbwp1","hptltauosqcdbwp1",3,25.,115.);
   TH1F* hptltauosqcdbwp2 = new TH1F("hptltauosqcdbwp2","hptltauosqcdbwp2",3,25.,115.);
   TH1F* hptltauosqcdbwp3 = new TH1F("hptltauosqcdbwp3","hptltauosqcdbwp3",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp0 = new TH1F("hptltauosqcdTruthbwp0","hptltauosqcdTruthbwp0",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp1 = new TH1F("hptltauosqcdTruthbwp1","hptltauosqcdTruthbwp1",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp2 = new TH1F("hptltauosqcdTruthbwp2","hptltauosqcdTruthbwp2",3,25.,115.);
   TH1F* hptltauosqcdTruthbwp3 = new TH1F("hptltauosqcdTruthbwp3","hptltauosqcdTruthbwp3",3,25.,115.);
   //
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
   TH1F* hmwltau3posqcd = new TH1F("hmwltau3posqcd","hmwltau3posqcd",30, 0., 150.);
   TH1F* hmwltau3posqcdTruth = new TH1F("hmwltau3posqcdTruth","hmwltau3posqcdTruth",30, 0., 150.);
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
   // tight 
   TH1F* hptltautight1posqcd = new TH1F("hptltautight1posqcd","hptltautight1posqcd",3,25.,115.);
   TH1F* hptltautight1posqcdTruth = new TH1F("hptltautight1posqcdTruth","hptltautight1posqcdTruth",3,25.,115.);
   TH1F* hptltautight1posqcdbwp0 = new TH1F("hptltautight1posqcdbwp0","hptltautight1posqcdbwp0",3,25.,115.);
   TH1F* hptltautight1posqcdbwp1 = new TH1F("hptltautight1posqcdbwp1","hptltautight1posqcdbwp1",3,25.,115.);
   TH1F* hptltautight1posqcdbwp2 = new TH1F("hptltautight1posqcdbwp2","hptltautight1posqcdbwp2",3,25.,115.);
   TH1F* hptltautight1posqcdbwp3 = new TH1F("hptltautight1posqcdbwp3","hptltautight1posqcdbwp3",3,25.,115.);
   TH1F* hptltautight1posqcdTruthbwp0 = new TH1F("hptltautight1posqcdTruthbwp0","hptltautight1posqcdTruthbwp0",3,25.,115.);
   TH1F* hptltautight1posqcdTruthbwp1 = new TH1F("hptltautight1posqcdTruthbwp1","hptltautight1posqcdTruthbwp1",3,25.,115.);
   TH1F* hptltautight1posqcdTruthbwp2 = new TH1F("hptltautight1posqcdTruthbwp2","hptltautight1posqcdTruthbwp2",3,25.,115.);
   TH1F* hptltautight1posqcdTruthbwp3 = new TH1F("hptltautight1posqcdTruthbwp3","hptltautight1posqcdTruthbwp3",3,25.,115.);
   TH1F* hmwltautight3posqcd = new TH1F("hmwltautight3posqcd","hmwltautight3posqcd",30, 0., 150.);
   TH1F* hmwltautight3posqcdTruth = new TH1F("hmwltautight3posqcdTruth","hmwltautight3posqcdTruth",30, 0., 150.);
   TH1F* hptltautight3posqcd = new TH1F("hptltautight3posqcd","hptltautight3posqcd",3,25.,115.);
   TH1F* hptltautight3posqcdTruth = new TH1F("hptltautight3posqcdTruth","hptltautight3posqcdTruth",3,25.,115.);
   TH1F* hptltautight3posqcdbwp0 = new TH1F("hptltautight3posqcdbwp0","hptltautight3posqcdbwp0",3,25.,115.);
   TH1F* hptltautight3posqcdbwp1 = new TH1F("hptltautight3posqcdbwp1","hptltautight3posqcdbwp1",3,25.,115.);
   TH1F* hptltautight3posqcdbwp2 = new TH1F("hptltautight3posqcdbwp2","hptltautight3posqcdbwp2",3,25.,115.);
   TH1F* hptltautight3posqcdbwp3 = new TH1F("hptltautight3posqcdbwp3","hptltautight3posqcdbwp3",3,25.,115.);
   TH1F* hptltautight3posqcdTruthbwp0 = new TH1F("hptltautight3posqcdTruthbwp0","hptltautight3posqcdTruthbwp0",3,25.,115.);
   TH1F* hptltautight3posqcdTruthbwp1 = new TH1F("hptltautight3posqcdTruthbwp1","hptltautight3posqcdTruthbwp1",3,25.,115.);
   TH1F* hptltautight3posqcdTruthbwp2 = new TH1F("hptltautight3posqcdTruthbwp2","hptltautight3posqcdTruthbwp2",3,25.,115.);
   TH1F* hptltautight3posqcdTruthbwp3 = new TH1F("hptltautight3posqcdTruthbwp3","hptltautight3posqcdTruthbwp3",3,25.,115.);
   //ss 8/4
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
   //
   TH1F* hmwltau3pssqcd = new TH1F("hmwltau3pssqcd","hmwltau3pssqcd",30, 0., 150.);
   TH1F* hmwltau3pssqcdTruth = new TH1F("hmwltau3pssqcdTruth","hmwltau3pssqcdTruth",30, 0., 150.);
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
   // qcd tight 
   TH1F* hptltautight1pssqcd = new TH1F("hptltautight1pssqcd","hptltautight1pssqcd",3,25.,115.);
   TH1F* hptltautight1pssqcdTruth = new TH1F("hptltautight1pssqcdTruth","hptltautight1pssqcdTruth",3,25.,115.);
   TH1F* hptltautight1pssqcdbwp0 = new TH1F("hptltautight1pssqcdbwp0","hptltautight1pssqcdbwp0",3,25.,115.);
   TH1F* hptltautight1pssqcdbwp1 = new TH1F("hptltautight1pssqcdbwp1","hptltautight1pssqcdbwp1",3,25.,115.);
   TH1F* hptltautight1pssqcdbwp2 = new TH1F("hptltautight1pssqcdbwp2","hptltautight1pssqcdbwp2",3,25.,115.);
   TH1F* hptltautight1pssqcdbwp3 = new TH1F("hptltautight1pssqcdbwp3","hptltautight1pssqcdbwp3",3,25.,115.);
   TH1F* hptltautight1pssqcdTruthbwp0 = new TH1F("hptltautight1pssqcdTruthbwp0","hptltautight1pssqcdTruthbwp0",3,25.,115.);
   TH1F* hptltautight1pssqcdTruthbwp1 = new TH1F("hptltautight1pssqcdTruthbwp1","hptltautight1pssqcdTruthbwp1",3,25.,115.);
   TH1F* hptltautight1pssqcdTruthbwp2 = new TH1F("hptltautight1pssqcdTruthbwp2","hptltautight1pssqcdTruthbwp2",3,25.,115.);
   TH1F* hptltautight1pssqcdTruthbwp3 = new TH1F("hptltautight1pssqcdTruthbwp3","hptltautight1pssqcdTruthbwp3",3,25.,115.);
   TH1F* hmwltautight3pssqcd = new TH1F("hmwltautight3pssqcd","hmwltautight3pssqcd",30, 0., 150.);
   TH1F* hmwltautight3pssqcdTruth = new TH1F("hmwltautight3pssqcdTruth","hmwltautight3pssqcdTruth",30, 0., 150.);
   TH1F* hptltautight3pssqcd = new TH1F("hptltautight3pssqcd","hptltautight3pssqcd",3,25.,115.);
   TH1F* hptltautight3pssqcdTruth = new TH1F("hptltautight3pssqcdTruth","hptltautight3pssqcdTruth",3,25.,115.);
   TH1F* hptltautight3pssqcdbwp0 = new TH1F("hptltautight3pssqcdbwp0","hptltautight3pssqcdbwp0",3,25.,115.);
   TH1F* hptltautight3pssqcdbwp1 = new TH1F("hptltautight3pssqcdbwp1","hptltautight3pssqcdbwp1",3,25.,115.);
   TH1F* hptltautight3pssqcdbwp2 = new TH1F("hptltautight3pssqcdbwp2","hptltautight3pssqcdbwp2",3,25.,115.);
   TH1F* hptltautight3pssqcdbwp3 = new TH1F("hptltautight3pssqcdbwp3","hptltautight3pssqcdbwp3",3,25.,115.);
   TH1F* hptltautight3pssqcdTruthbwp0 = new TH1F("hptltautight3pssqcdTruthbwp0","hptltautight3pssqcdTruthbwp0",3,25.,115.);
   TH1F* hptltautight3pssqcdTruthbwp1 = new TH1F("hptltautight3pssqcdTruthbwp1","hptltautight3pssqcdTruthbwp1",3,25.,115.);
   TH1F* hptltautight3pssqcdTruthbwp2 = new TH1F("hptltautight3pssqcdTruthbwp2","hptltautight3pssqcdTruthbwp2",3,25.,115.);
   TH1F* hptltautight3pssqcdTruthbwp3 = new TH1F("hptltautight3pssqcdTruthbwp3","hptltautight3pssqcdTruthbwp3",3,25.,115.);
   //qcdlow 
   //os 8/4
   TH1F* hptltauosqcdlowbwp0 = new TH1F("hptltauosqcdlowbwp0","hptltauosqcdlowbwp0",3,25.,115.);
   TH1F* hptltauosqcdlowbwp1 = new TH1F("hptltauosqcdlowbwp1","hptltauosqcdlowbwp1",3,25.,115.);
   TH1F* hptltauosqcdlowbwp2 = new TH1F("hptltauosqcdlowbwp2","hptltauosqcdlowbwp2",3,25.,115.);
   TH1F* hptltauosqcdlowbwp3 = new TH1F("hptltauosqcdlowbwp3","hptltauosqcdlowbwp3",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp0 = new TH1F("hptltauosqcdlowTruthbwp0","hptltauosqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp1 = new TH1F("hptltauosqcdlowTruthbwp1","hptltauosqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp2 = new TH1F("hptltauosqcdlowTruthbwp2","hptltauosqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltauosqcdlowTruthbwp3 = new TH1F("hptltauosqcdlowTruthbwp3","hptltauosqcdlowTruthbwp3",3,25.,115.);
   // medium 
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
   TH1F* hmwltau3posqcdlow = new TH1F("hmwltau3posqcdlow","hmwltau3posqcdlow",30, 0., 150.);
   TH1F* hmwltau3posqcdlowTruth = new TH1F("hmwltau3posqcdlowTruth","hmwltau3posqcdlowTruth",30, 0., 150.);
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
   // tight 
   TH1F* hptltautight1posqcdlow = new TH1F("hptltautight1posqcdlow","hptltautight1posqcdlow",3,25.,115.);
   TH1F* hptltautight1posqcdlowTruth = new TH1F("hptltautight1posqcdlowTruth","hptltautight1posqcdlowTruth",3,25.,115.);
   TH1F* hptltautight1posqcdlowbwp0 = new TH1F("hptltautight1posqcdlowbwp0","hptltautight1posqcdlowbwp0",3,25.,115.);
   TH1F* hptltautight1posqcdlowbwp1 = new TH1F("hptltautight1posqcdlowbwp1","hptltautight1posqcdlowbwp1",3,25.,115.);
   TH1F* hptltautight1posqcdlowbwp2 = new TH1F("hptltautight1posqcdlowbwp2","hptltautight1posqcdlowbwp2",3,25.,115.);
   TH1F* hptltautight1posqcdlowbwp3 = new TH1F("hptltautight1posqcdlowbwp3","hptltautight1posqcdlowbwp3",3,25.,115.);
   TH1F* hptltautight1posqcdlowTruthbwp0 = new TH1F("hptltautight1posqcdlowTruthbwp0","hptltautight1posqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight1posqcdlowTruthbwp1 = new TH1F("hptltautight1posqcdlowTruthbwp1","hptltautight1posqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight1posqcdlowTruthbwp2 = new TH1F("hptltautight1posqcdlowTruthbwp2","hptltautight1posqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight1posqcdlowTruthbwp3 = new TH1F("hptltautight1posqcdlowTruthbwp3","hptltautight1posqcdlowTruthbwp3",3,25.,115.);
   TH1F* hmwltautight3posqcdlow = new TH1F("hmwltautight3posqcdlow","hmwltautight3posqcdlow",30, 0., 150.);
   TH1F* hmwltautight3posqcdlowTruth = new TH1F("hmwltautight3posqcdlowTruth","hmwltautight3posqcdlowTruth",30, 0., 150.);
   TH1F* hptltautight3posqcdlow = new TH1F("hptltautight3posqcdlow","hptltautight3posqcdlow",3,25.,115.);
   TH1F* hptltautight3posqcdlowTruth = new TH1F("hptltautight3posqcdlowTruth","hptltautight3posqcdlowTruth",3,25.,115.);
   TH1F* hptltautight3posqcdlowbwp0 = new TH1F("hptltautight3posqcdlowbwp0","hptltautight3posqcdlowbwp0",3,25.,115.);
   TH1F* hptltautight3posqcdlowbwp1 = new TH1F("hptltautight3posqcdlowbwp1","hptltautight3posqcdlowbwp1",3,25.,115.);
   TH1F* hptltautight3posqcdlowbwp2 = new TH1F("hptltautight3posqcdlowbwp2","hptltautight3posqcdlowbwp2",3,25.,115.);
   TH1F* hptltautight3posqcdlowbwp3 = new TH1F("hptltautight3posqcdlowbwp3","hptltautight3posqcdlowbwp3",3,25.,115.);
   TH1F* hptltautight3posqcdlowTruthbwp0 = new TH1F("hptltautight3posqcdlowTruthbwp0","hptltautight3posqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight3posqcdlowTruthbwp1 = new TH1F("hptltautight3posqcdlowTruthbwp1","hptltautight3posqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight3posqcdlowTruthbwp2 = new TH1F("hptltautight3posqcdlowTruthbwp2","hptltautight3posqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight3posqcdlowTruthbwp3 = new TH1F("hptltautight3posqcdlowTruthbwp3","hptltautight3posqcdlowTruthbwp3",3,25.,115.);
   //ss 8/4
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
   TH1F* hmwltau3pssqcdlow = new TH1F("hmwltau3pssqcdlow","hmwltau3pssqcdlow",30, 0., 150.);
   TH1F* hmwltau3pssqcdlowTruth = new TH1F("hmwltau3pssqcdlowTruth","hmwltau3pssqcdlowTruth",30, 0., 150.);
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
   // 8/4 tight 
   TH1F* hptltautight1pssqcdlow = new TH1F("hptltautight1pssqcdlow","hptltautight1pssqcdlow",3,25.,115.);
   TH1F* hptltautight1pssqcdlowTruth = new TH1F("hptltautight1pssqcdlowTruth","hptltautight1pssqcdlowTruth",3,25.,115.);
   TH1F* hptltautight1pssqcdlowbwp0 = new TH1F("hptltautight1pssqcdlowbwp0","hptltautight1pssqcdlowbwp0",3,25.,115.);
   TH1F* hptltautight1pssqcdlowbwp1 = new TH1F("hptltautight1pssqcdlowbwp1","hptltautight1pssqcdlowbwp1",3,25.,115.);
   TH1F* hptltautight1pssqcdlowbwp2 = new TH1F("hptltautight1pssqcdlowbwp2","hptltautight1pssqcdlowbwp2",3,25.,115.);
   TH1F* hptltautight1pssqcdlowbwp3 = new TH1F("hptltautight1pssqcdlowbwp3","hptltautight1pssqcdlowbwp3",3,25.,115.);
   TH1F* hptltautight1pssqcdlowTruthbwp0 = new TH1F("hptltautight1pssqcdlowTruthbwp0","hptltautight1pssqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight1pssqcdlowTruthbwp1 = new TH1F("hptltautight1pssqcdlowTruthbwp1","hptltautight1pssqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight1pssqcdlowTruthbwp2 = new TH1F("hptltautight1pssqcdlowTruthbwp2","hptltautight1pssqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight1pssqcdlowTruthbwp3 = new TH1F("hptltautight1pssqcdlowTruthbwp3","hptltautight1pssqcdlowTruthbwp3",3,25.,115.);
   TH1F* hmwltautight3pssqcdlow = new TH1F("hmwltautight3pssqcdlow","hmwltautight3pssqcdlow",30, 0., 150.);
   TH1F* hmwltautight3pssqcdlowTruth = new TH1F("hmwltautight3pssqcdlowTruth","hmwltautight3pssqcdlowTruth",30, 0., 150.);
   TH1F* hptltautight3pssqcdlow = new TH1F("hptltautight3pssqcdlow","hptltautight3pssqcdlow",3,25.,115.);
   TH1F* hptltautight3pssqcdlowTruth = new TH1F("hptltautight3pssqcdlowTruth","hptltautight3pssqcdlowTruth",3,25.,115.);
   TH1F* hptltautight3pssqcdlowbwp0 = new TH1F("hptltautight3pssqcdlowbwp0","hptltautight3pssqcdlowbwp0",3,25.,115.);
   TH1F* hptltautight3pssqcdlowbwp1 = new TH1F("hptltautight3pssqcdlowbwp1","hptltautight3pssqcdlowbwp1",3,25.,115.);
   TH1F* hptltautight3pssqcdlowbwp2 = new TH1F("hptltautight3pssqcdlowbwp2","hptltautight3pssqcdlowbwp2",3,25.,115.);
   TH1F* hptltautight3pssqcdlowbwp3 = new TH1F("hptltautight3pssqcdlowbwp3","hptltautight3pssqcdlowbwp3",3,25.,115.);
   TH1F* hptltautight3pssqcdlowTruthbwp0 = new TH1F("hptltautight3pssqcdlowTruthbwp0","hptltautight3pssqcdlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight3pssqcdlowTruthbwp1 = new TH1F("hptltautight3pssqcdlowTruthbwp1","hptltautight3pssqcdlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight3pssqcdlowTruthbwp2 = new TH1F("hptltautight3pssqcdlowTruthbwp2","hptltautight3pssqcdlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight3pssqcdlowTruthbwp3 = new TH1F("hptltautight3pssqcdlowTruthbwp3","hptltautight3pssqcdlowTruthbwp3",3,25.,115.);
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
   // 8/4
   TH1F* hnjetltauosqcdlow = new TH1F("hnjetltauosqcdlow","hnjetltauosqcdlow",4,0.,4.);
   TH1F* hnjetltauosqcdlowTruth = new TH1F("hnjetltauosqcdlowTruth","hnjetltauosqcdlowTruth",4,0.,4.);
   TH1F* hnjetltaussqcdlow = new TH1F("hnjetltaussqcdlow","hnjetltaussqcdlow",4,0.,4.);
   TH1F* hnjetltaussqcdlowTruth = new TH1F("hnjetltaussqcdlowTruth","hnjetltaussqcdlowTruth",4,0.,4.);
   TH1F* hnjetltauos = new TH1F("hnjetltauos","hnjetltauos",4,0.,4.);
   TH1F* hnjetltauosTruth = new TH1F("hnjetltauosTruth","hnjetltauosTruth",4,0.,4.);
   TH1F* hnjetltauss = new TH1F("hnjetltauss","hnjetltauss",4,0.,4.);
   TH1F* hnjetltaussTruth = new TH1F("hnjetltaussTruth","hnjetltaussTruth",4,0.,4.);
   // 8/4
   TH1F* hnjetltautightosqcdlow = new TH1F("hnjetltautightosqcdlow","hnjetltautightosqcdlow",4,0.,4.);
   TH1F* hnjetltauosqcdlowbwp1 = new TH1F("hnjetltauosqcdlowbwp1","hnjetltauosqcdlowbwp1",4,0.,4.);
   TH1F* hnjetltautightosqcdlowbwp1 = new TH1F("hnjetltautightosqcdlowbwp1","hnjetltautightosqcdlowbwp1",4,0.,4.);
   TH1F* hnjetltautightosqcdlowTruth = new TH1F("hnjetltautightosqcdlowTruth","hnjetltautightosqcdlowTruth",4,0.,4.);
   TH1F* hnjetltauosqcdlowTruthbwp1 = new TH1F("hnjetltauosqcdlowTruthbwp1","hnjetltauosqcdlowTruthbwp1",4,0.,4.);
   TH1F* hnjetltautightosqcdlowTruthbwp1 = new TH1F("hnjetltautightosqcdlowTruthbwp1","hnjetltautightosqcdlowTruthbwp1",4,0.,4.);
   // 8/4
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
   // 8-4 
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
   // oct 1 2018 
   TH1F* hptltau1posgj = new TH1F("hptltau1posgj","hptltau1posgj",3,25.,115.);
   TH1F* hptltau1posgjbwp0 = new TH1F("hptltau1posgjbwp0","hptltau1posgjbwp0",3,25.,115.);
   TH1F* hptltau1posgjbwp1 = new TH1F("hptltau1posgjbwp1","hptltau1posgjbwp1",3,25.,115.);
   TH1F* hptltau1posgjbwp2 = new TH1F("hptltau1posgjbwp2","hptltau1posgjbwp2",3,25.,115.);
   TH1F* hptltau1posgjbwp3 = new TH1F("hptltau1posgjbwp3","hptltau1posgjbwp3",3,25.,115.);
   TH1F* hptltau3posgj = new TH1F("hptltau3posgj","hptltau3posgj",3,25.,115.);
   TH1F* hptltau3posgjbwp0 = new TH1F("hptltau3posgjbwp0","hptltau3posgjbwp0",3,25.,115.);
   TH1F* hptltau3posgjbwp1 = new TH1F("hptltau3posgjbwp1","hptltau3posgjbwp1",3,25.,115.);
   TH1F* hptltau3posgjbwp2 = new TH1F("hptltau3posgjbwp2","hptltau3posgjbwp2",3,25.,115.);
   TH1F* hptltau3posgjbwp3 = new TH1F("hptltau3posgjbwp3","hptltau3posgjbwp3",3,25.,115.);
   TH1F* hptltau1pssgj = new TH1F("hptltau1pssgj","hptltau1pssgj",3,25.,115.);
   TH1F* hptltau1pssgjbwp0 = new TH1F("hptltau1pssgjbwp0","hptltau1pssgjbwp0",3,25.,115.);
   TH1F* hptltau1pssgjbwp1 = new TH1F("hptltau1pssgjbwp1","hptltau1pssgjbwp1",3,25.,115.);
   TH1F* hptltau1pssgjbwp2 = new TH1F("hptltau1pssgjbwp2","hptltau1pssgjbwp2",3,25.,115.);
   TH1F* hptltau1pssgjbwp3 = new TH1F("hptltau1pssgjbwp3","hptltau1pssgjbwp3",3,25.,115.);
   TH1F* hptltau3pssgj = new TH1F("hptltau3pssgj","hptltau3pssgj",3,25.,115.);
   TH1F* hptltau3pssgjbwp0 = new TH1F("hptltau3pssgjbwp0","hptltau3pssgjbwp0",3,25.,115.);
   TH1F* hptltau3pssgjbwp1 = new TH1F("hptltau3pssgjbwp1","hptltau3pssgjbwp1",3,25.,115.);
   TH1F* hptltau3pssgjbwp2 = new TH1F("hptltau3pssgjbwp2","hptltau3pssgjbwp2",3,25.,115.);
   TH1F* hptltau3pssgjbwp3 = new TH1F("hptltau3pssgjbwp3","hptltau3pssgjbwp3",3,25.,115.);
   // 8-4
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
   //8-4 
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
   // 8-4
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
   // 8-4
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
   // 8-4
   TH1F* hmwltau1poslowbj = new TH1F("hmwltau1poslowbj","hmwltau1poslowbj",30, 0., 150.);
   TH1F* hmwltau3poslowbj = new TH1F("hmwltau3poslowbj","hmwltau3poslowbj",30, 0., 150.);
   TH1F* hmwltau1psslowbj = new TH1F("hmwltau1psslowbj","hmwltau1psslowbj",30, 0., 150.);
   TH1F* hmwltau3psslowbj = new TH1F("hmwltau3psslowbj","hmwltau3psslowbj",30, 0., 150.);
   // oct 1 2018 
   TH1F* hmwltau1poslowgj = new TH1F("hmwltau1poslowgj","hmwltau1poslowgj",30, 0., 150.);
   TH1F* hptltau1poslowgj = new TH1F("hptltau1poslowgj","hptltau1poslowgj",3,25.,115.);
   TH1F* hptltau1poslowgjbwp0 = new TH1F("hptltau1poslowgjbwp0","hptltau1poslowgjbwp0",3,25.,115.);
   TH1F* hptltau1poslowgjbwp1 = new TH1F("hptltau1poslowgjbwp1","hptltau1poslowgjbwp1",3,25.,115.);
   TH1F* hptltau1poslowgjbwp2 = new TH1F("hptltau1poslowgjbwp2","hptltau1poslowgjbwp2",3,25.,115.);
   TH1F* hptltau1poslowgjbwp3 = new TH1F("hptltau1poslowgjbwp3","hptltau1poslowgjbwp3",3,25.,115.);
   TH1F* hmwltau3poslowgj = new TH1F("hmwltau3poslowgj","hmwltau3poslowgj",30, 0., 150.);
   TH1F* hptltau3poslowgj = new TH1F("hptltau3poslowgj","hptltau3poslowgj",3,25.,115.);
   TH1F* hptltau3poslowgjbwp0 = new TH1F("hptltau3poslowgjbwp0","hptltau3poslowgjbwp0",3,25.,115.);
   TH1F* hptltau3poslowgjbwp1 = new TH1F("hptltau3poslowgjbwp1","hptltau3poslowgjbwp1",3,25.,115.);
   TH1F* hptltau3poslowgjbwp2 = new TH1F("hptltau3poslowgjbwp2","hptltau3poslowgjbwp2",3,25.,115.);
   TH1F* hptltau3poslowgjbwp3 = new TH1F("hptltau3poslowgjbwp3","hptltau3poslowgjbwp3",3,25.,115.);
   TH1F* hmwltau1psslowgj = new TH1F("hmwltau1psslowgj","hmwltau1psslowgj",30, 0., 150.);
   TH1F* hptltau1psslowgj = new TH1F("hptltau1psslowgj","hptltau1psslowgj",3,25.,115.);
   TH1F* hptltau1psslowgjbwp0 = new TH1F("hptltau1psslowgjbwp0","hptltau1psslowgjbwp0",3,25.,115.);
   TH1F* hptltau1psslowgjbwp1 = new TH1F("hptltau1psslowgjbwp1","hptltau1psslowgjbwp1",3,25.,115.);
   TH1F* hptltau1psslowgjbwp2 = new TH1F("hptltau1psslowgjbwp2","hptltau1psslowgjbwp2",3,25.,115.);
   TH1F* hptltau1psslowgjbwp3 = new TH1F("hptltau1psslowgjbwp3","hptltau1psslowgjbwp3",3,25.,115.);
   TH1F* hmwltau3psslowgj = new TH1F("hmwltau3psslowgj","hmwltau3psslowgj",30, 0., 150.);
   TH1F* hptltau3psslowgj = new TH1F("hptltau3psslowgj","hptltau3psslowgj",3,25.,115.);
   TH1F* hptltau3psslowgjbwp0 = new TH1F("hptltau3psslowgjbwp0","hptltau3psslowgjbwp0",3,25.,115.);
   TH1F* hptltau3psslowgjbwp1 = new TH1F("hptltau3psslowgjbwp1","hptltau3psslowgjbwp1",3,25.,115.);
   TH1F* hptltau3psslowgjbwp2 = new TH1F("hptltau3psslowgjbwp2","hptltau3psslowgjbwp2",3,25.,115.);
   TH1F* hptltau3psslowgjbwp3 = new TH1F("hptltau3psslowgjbwp3","hptltau3psslowgjbwp3",3,25.,115.);
   // 8/4 saved 
   TH1F* hjfltauos1B = new TH1F("hjfltauos1B","hjfltauos1B", 26, -1., 25.);
   TH1F* hmwltauos1Bbj = new TH1F("hmwltauos1Bbj","hmwltauos1Bbj",30, 0., 150.);
   TH1F* hjfltauss1B = new TH1F("hjfltauss1B","hjfltauss1B", 26, -1., 25.);
   TH1F* hmwltauss1Bbj = new TH1F("hmwltauss1Bbj","hmwltauss1Bbj",30, 0., 150.);
   // 8-4 tight met low os medium 
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
   TH1F* hmwltau3posmetlow = new TH1F("hmwltau3posmetlow","hmwltau3posmetlow",30, 0., 150.);
   TH1F* hmwltau3posmetlowTruth = new TH1F("hmwltau3posmetlowTruth","hmwltau3posmetlowTruth",30, 0., 150.);
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
   // tight 
   TH1F* hptltautight1posmetlow = new TH1F("hptltautight1posmetlow","hptltautight1posmetlow",3,25.,115.);
   TH1F* hptltautight1posmetlowTruth = new TH1F("hptltautight1posmetlowTruth","hptltautight1posmetlowTruth",3,25.,115.);
   TH1F* hptltautight1posmetlowbwp0 = new TH1F("hptltautight1posmetlowbwp0","hptltautight1posmetlowbwp0",3,25.,115.);
   TH1F* hptltautight1posmetlowbwp1 = new TH1F("hptltautight1posmetlowbwp1","hptltautight1posmetlowbwp1",3,25.,115.);
   TH1F* hptltautight1posmetlowbwp2 = new TH1F("hptltautight1posmetlowbwp2","hptltautight1posmetlowbwp2",3,25.,115.);
   TH1F* hptltautight1posmetlowbwp3 = new TH1F("hptltautight1posmetlowbwp3","hptltautight1posmetlowbwp3",3,25.,115.);
   TH1F* hptltautight1posmetlowTruthbwp0 = new TH1F("hptltautight1posmetlowTruthbwp0","hptltautight1posmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight1posmetlowTruthbwp1 = new TH1F("hptltautight1posmetlowTruthbwp1","hptltautight1posmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight1posmetlowTruthbwp2 = new TH1F("hptltautight1posmetlowTruthbwp2","hptltautight1posmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight1posmetlowTruthbwp3 = new TH1F("hptltautight1posmetlowTruthbwp3","hptltautight1posmetlowTruthbwp3",3,25.,115.);
   //
   TH1F* hmwltautight3posmetlow = new TH1F("hmwltautight3posmetlow","hmwltautight3posmetlow",30, 0., 150.);
   TH1F* hmwltautight3posmetlowTruth = new TH1F("hmwltautight3posmetlowTruth","hmwltautight3posmetlowTruth",30, 0., 150.);
   TH1F* hptltautight3posmetlow = new TH1F("hptltautight3posmetlow","hptltautight3posmetlow",3,25.,115.);
   TH1F* hptltautight3posmetlowTruth = new TH1F("hptltautight3posmetlowTruth","hptltautight3posmetlowTruth",3,25.,115.);
   TH1F* hptltautight3posmetlowbwp0 = new TH1F("hptltautight3posmetlowbwp0","hptltautight3posmetlowbwp0",3,25.,115.);
   TH1F* hptltautight3posmetlowbwp1 = new TH1F("hptltautight3posmetlowbwp1","hptltautight3posmetlowbwp1",3,25.,115.);
   TH1F* hptltautight3posmetlowbwp2 = new TH1F("hptltautight3posmetlowbwp2","hptltautight3posmetlowbwp2",3,25.,115.);
   TH1F* hptltautight3posmetlowbwp3 = new TH1F("hptltautight3posmetlowbwp3","hptltautight3posmetlowbwp3",3,25.,115.);
   TH1F* hptltautight3posmetlowTruthbwp0 = new TH1F("hptltautight3posmetlowTruthbwp0","hptltautight3posmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight3posmetlowTruthbwp1 = new TH1F("hptltautight3posmetlowTruthbwp1","hptltautight3posmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight3posmetlowTruthbwp2 = new TH1F("hptltautight3posmetlowTruthbwp2","hptltautight3posmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight3posmetlowTruthbwp3 = new TH1F("hptltautight3posmetlowTruthbwp3","hptltautight3posmetlowTruthbwp3",3,25.,115.);
   // 8-4  tight met low ss medium 
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
   TH1F* hmwltau3pssmetlow = new TH1F("hmwltau3pssmetlow","hmwltau3pssmetlow",30, 0., 150.);
   TH1F* hmwltau3pssmetlowTruth = new TH1F("hmwltau3pssmetlowTruth","hmwltau3pssmetlowTruth",30, 0., 150.);
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
   // tight 
   TH1F* hptltautight1pssmetlow = new TH1F("hptltautight1pssmetlow","hptltautight1posmetlow",3,25.,115.);
   TH1F* hptltautight1pssmetlowTruth = new TH1F("hptltautight1pssmetlowTruth","hptltautight1posmetlowTruth",3,25.,115.);
   TH1F* hptltautight1pssmetlowbwp0 = new TH1F("hptltautight1pssmetlowbwp0","hptltautight1posmetlowbwp0",3,25.,115.);
   TH1F* hptltautight1pssmetlowbwp1 = new TH1F("hptltautight1pssmetlowbwp1","hptltautight1posmetlowbwp1",3,25.,115.);
   TH1F* hptltautight1pssmetlowbwp2 = new TH1F("hptltautight1pssmetlowbwp2","hptltautight1posmetlowbwp2",3,25.,115.);
   TH1F* hptltautight1pssmetlowbwp3 = new TH1F("hptltautight1pssmetlowbwp3","hptltautight1posmetlowbwp3",3,25.,115.);
   TH1F* hptltautight1pssmetlowTruthbwp0 = new TH1F("hptltautight1pssmetlowTruthbwp0","hptltautight1pssmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight1pssmetlowTruthbwp1 = new TH1F("hptltautight1pssmetlowTruthbwp1","hptltautight1pssmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight1pssmetlowTruthbwp2 = new TH1F("hptltautight1pssmetlowTruthbwp2","hptltautight1pssmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight1pssmetlowTruthbwp3 = new TH1F("hptltautight1pssmetlowTruthbwp3","hptltautight1pssmetlowTruthbwp3",3,25.,115.);
   //
   TH1F* hmwltautight3pssmetlow = new TH1F("hmwltautight3pssmetlow","hmwltautight3pssmetlow",30, 0., 150.);
   TH1F* hmwltautight3pssmetlowTruth = new TH1F("hmwltautight3pssmetlowTruth","hmwltautight3pssmetlowTruth",30, 0., 150.);
   TH1F* hptltautight3pssmetlow = new TH1F("hptltautight3pssmetlow","hptltautight3pssmetlow",3,25.,115.);
   TH1F* hptltautight3pssmetlowTruth = new TH1F("hptltautight3pssmetlowTruth","hptltautight3pssmetlowTruth",3,25.,115.);
   TH1F* hptltautight3pssmetlowbwp0 = new TH1F("hptltautight3pssmetlowbwp0","hptltautight3pssmetlowbwp0",3,25.,115.);
   TH1F* hptltautight3pssmetlowbwp1 = new TH1F("hptltautight3pssmetlowbwp1","hptltautight3pssmetlowbwp1",3,25.,115.);
   TH1F* hptltautight3pssmetlowbwp2 = new TH1F("hptltautight3pssmetlowbwp2","hptltautight3pssmetlowbwp2",3,25.,115.);
   TH1F* hptltautight3pssmetlowbwp3 = new TH1F("hptltautight3pssmetlowbwp3","hptltautight3pssmetlowbwp3",3,25.,115.);
   TH1F* hptltautight3pssmetlowTruthbwp0 = new TH1F("hptltautight3pssmetlowTruthbwp0","hptltautight3pssmetlowTruthbwp0",3,25.,115.);
   TH1F* hptltautight3pssmetlowTruthbwp1 = new TH1F("hptltautight3pssmetlowTruthbwp1","hptltautight3pssmetlowTruthbwp1",3,25.,115.);
   TH1F* hptltautight3pssmetlowTruthbwp2 = new TH1F("hptltautight3pssmetlowTruthbwp2","hptltautight3pssmetlowTruthbwp2",3,25.,115.);
   TH1F* hptltautight3pssmetlowTruthbwp3 = new TH1F("hptltautight3pssmetlowTruthbwp3","hptltautight3pssmetlowTruthbwp3",3,25.,115.);
   // 8/4 saved (12*4=48)
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
   // 8/4
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
   // 2B 8/4
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
   // 8/4
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
   // 8/4
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
   // oct 1 2018 
   TH1F* hptmtauemu1Bgj = new TH1F("hptmtauemu1Bgj","hptmtauemu1Bgj",3,25.,115.);
   TH1F* hptmtauemu1Bgjbwp0 = new TH1F("hptmtauemu1Bgjbwp0","hptmtauemu1Bgjbwp0",3,25.,115.);
   TH1F* hptmtauemu1Bgjbwp1 = new TH1F("hptmtauemu1Bgjbwp1","hptmtauemu1Bgjbwp1",3,25.,115.);
   TH1F* hptmtauemu1Bgjbwp2 = new TH1F("hptmtauemu1Bgjbwp2","hptmtauemu1Bgjbwp2",3,25.,115.);
   TH1F* hptmtauemu1Bgjbwp3 = new TH1F("hptmtauemu1Bgjbwp3","hptmtauemu1Bgjbwp3",3,25.,115.);
   TH1F* hpttauemu1Bgj = new TH1F("hpttauemu1Bgj","hpttauemu1Bgj",3,25.,115.);
   TH1F* hpttauemu1Bgjbwp0 = new TH1F("hpttauemu1Bgjbwp0","hpttauemu1Bgjbwp0",3,25.,115.);
   TH1F* hpttauemu1Bgjbwp1 = new TH1F("hpttauemu1Bgjbwp1","hpttauemu1Bgjbwp1",3,25.,115.);
   TH1F* hpttauemu1Bgjbwp2 = new TH1F("hpttauemu1Bgjbwp2","hpttauemu1Bgjbwp2",3,25.,115.);
   TH1F* hpttauemu1Bgjbwp3 = new TH1F("hpttauemu1Bgjbwp3","hpttauemu1Bgjbwp3",3,25.,115.);
   TH1F* hptmtauemu2Bgj = new TH1F("hptmtauemu2Bgj","hptmtauemu2Bgj",3,25.,115.);
   TH1F* hptmtauemu2Bgjbwp0 = new TH1F("hptmtauemu2Bgjbwp0","hptmtauemu2Bgjbwp0",3,25.,115.);
   TH1F* hptmtauemu2Bgjbwp1 = new TH1F("hptmtauemu2Bgjbwp1","hptmtauemu2Bgjbwp1",3,25.,115.);
   TH1F* hptmtauemu2Bgjbwp2 = new TH1F("hptmtauemu2Bgjbwp2","hptmtauemu2Bgjbwp2",3,25.,115.);
   TH1F* hptmtauemu2Bgjbwp3 = new TH1F("hptmtauemu2Bgjbwp3","hptmtauemu2Bgjbwp3",3,25.,115.);
   TH1F* hpttauemu2Bgj = new TH1F("hpttauemu2Bgj","hpttauemu2Bgj",3,25.,115.);
   TH1F* hpttauemu2Bgjbwp0 = new TH1F("hpttauemu2Bgjbwp0","hpttauemu2Bgjbwp0",3,25.,115.);
   TH1F* hpttauemu2Bgjbwp1 = new TH1F("hpttauemu2Bgjbwp1","hpttauemu2Bgjbwp1",3,25.,115.);
   TH1F* hpttauemu2Bgjbwp2 = new TH1F("hpttauemu2Bgjbwp2","hpttauemu2Bgjbwp2",3,25.,115.);
   TH1F* hpttauemu2Bgjbwp3 = new TH1F("hpttauemu2Bgjbwp3","hpttauemu2Bgjbwp3",3,25.,115.);
   // 8/4
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
   // 8/4
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
   // 8-4
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
   //8-8
   TH1F* hmzll = new TH1F("hmzll","hmzll",50, 0., 150.);
   TH1F* hmzmm = new TH1F("hmzmm","hmzmm",50, 0., 150.);
   TH1F* hmzee = new TH1F("hmzee","hmzee",50, 0., 150.);
   TH1F* hmzleptau = new TH1F("hmzleptau","hmzleptau",50, 0., 150.);
   TH1F* hmzleptaubwp0 = new TH1F("hmzleptaubwp0","hmzleptaubwp0",50, 0., 150.);
   TH1F* hmzleptaubwp1 = new TH1F("hmzleptaubwp1","hmzleptaubwp1",50, 0., 150.);
   TH1F* hmzleptaubwp2 = new TH1F("hmzleptaubwp2","hmzleptaubwp2",50, 0., 150.);
   TH1F* hmzleptaubwp3 = new TH1F("hmzleptaubwp3","hmzleptaubwp3",50, 0., 150.);
   TH1F* hmzleptautight = new TH1F("hmzleptautight","hmzleptautight",50, 0., 150.);
   TH1F* hmzleptautightbwp0 = new TH1F("hmzleptautightbwp0","hmzleptautightbwp0",50, 0., 150.);
   TH1F* hmzleptautightbwp1 = new TH1F("hmzleptautightbwp1","hmzleptautightbwp1",50, 0., 150.);
   TH1F* hmzleptautightbwp2 = new TH1F("hmzleptautightbwp2","hmzleptautightbwp2",50, 0., 150.);
   TH1F* hmzleptautightbwp3 = new TH1F("hmzleptautightbwp3","hmzleptautightbwp3",50, 0., 150.);
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
   // medium
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
   hmwltau3posqcd->Sumw2();
   hmwltau3posqcdTruth->Sumw2();
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
   // tight 
   hptltautight1posqcd->Sumw2();
   hptltautight1posqcdTruth->Sumw2();
   hptltautight1posqcdbwp0->Sumw2();
   hptltautight1posqcdbwp1->Sumw2();
   hptltautight1posqcdbwp2->Sumw2();
   hptltautight1posqcdbwp3->Sumw2();
   hptltautight1posqcdTruthbwp0->Sumw2();
   hptltautight1posqcdTruthbwp1->Sumw2();
   hptltautight1posqcdTruthbwp2->Sumw2();
   hptltautight1posqcdTruthbwp3->Sumw2();
   hmwltautight3posqcd->Sumw2();
   hmwltautight3posqcdTruth->Sumw2();
   hptltautight3posqcd->Sumw2();
   hptltautight3posqcdTruth->Sumw2();
   hptltautight3posqcdbwp0->Sumw2();
   hptltautight3posqcdbwp1->Sumw2();
   hptltautight3posqcdbwp2->Sumw2();
   hptltautight3posqcdbwp3->Sumw2();
   hptltautight3posqcdTruthbwp0->Sumw2();
   hptltautight3posqcdTruthbwp1->Sumw2();
   hptltautight3posqcdTruthbwp2->Sumw2();
   hptltautight3posqcdTruthbwp3->Sumw2();
   //ss
   hptltaussqcdbwp0->Sumw2();
   hptltaussqcdbwp1->Sumw2();
   hptltaussqcdbwp2->Sumw2();
   hptltaussqcdbwp3->Sumw2();
   hptltaussqcdTruthbwp0->Sumw2();
   hptltaussqcdTruthbwp1->Sumw2();
   hptltaussqcdTruthbwp2->Sumw2();
   hptltaussqcdTruthbwp3->Sumw2();
   // medium
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
   hmwltau3pssqcd->Sumw2();
   hmwltau3pssqcdTruth->Sumw2();
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
   // tight 
   hptltautight1pssqcd->Sumw2();
   hptltautight1pssqcdTruth->Sumw2();
   hptltautight1pssqcdbwp0->Sumw2();
   hptltautight1pssqcdbwp1->Sumw2();
   hptltautight1pssqcdbwp2->Sumw2();
   hptltautight1pssqcdbwp3->Sumw2();
   hptltautight1pssqcdTruthbwp0->Sumw2();
   hptltautight1pssqcdTruthbwp1->Sumw2();
   hptltautight1pssqcdTruthbwp2->Sumw2();
   hptltautight1pssqcdTruthbwp3->Sumw2();
   hmwltautight3pssqcd->Sumw2();
   hmwltautight3pssqcdTruth->Sumw2();
   hptltautight3pssqcd->Sumw2();
   hptltautight3pssqcdTruth->Sumw2();
   hptltautight3pssqcdbwp0->Sumw2();
   hptltautight3pssqcdbwp1->Sumw2();
   hptltautight3pssqcdbwp2->Sumw2();
   hptltautight3pssqcdbwp3->Sumw2();
   hptltautight3pssqcdTruthbwp0->Sumw2();
   hptltautight3pssqcdTruthbwp1->Sumw2();
   hptltautight3pssqcdTruthbwp2->Sumw2();
   hptltautight3pssqcdTruthbwp3->Sumw2();
   // qcdlow
   hptltauosqcdlowbwp0->Sumw2();
   hptltauosqcdlowbwp1->Sumw2();
   hptltauosqcdlowbwp2->Sumw2();
   hptltauosqcdlowbwp3->Sumw2();
   hptltauosqcdlowTruthbwp0->Sumw2();
   hptltauosqcdlowTruthbwp1->Sumw2();
   hptltauosqcdlowTruthbwp2->Sumw2();
   hptltauosqcdlowTruthbwp3->Sumw2();
   // medium
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
   hmwltau3posqcdlow->Sumw2();
   hmwltau3posqcdlowTruth->Sumw2();
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
   // tight 
   hptltautight1posqcdlow->Sumw2();
   hptltautight1posqcdlowTruth->Sumw2();
   hptltautight1posqcdlowbwp0->Sumw2();
   hptltautight1posqcdlowbwp1->Sumw2();
   hptltautight1posqcdlowbwp2->Sumw2();
   hptltautight1posqcdlowbwp3->Sumw2();
   hptltautight1posqcdlowTruthbwp0->Sumw2();
   hptltautight1posqcdlowTruthbwp1->Sumw2();
   hptltautight1posqcdlowTruthbwp2->Sumw2();
   hptltautight1posqcdlowTruthbwp3->Sumw2();
   hmwltautight3posqcdlow->Sumw2();
   hmwltautight3posqcdlowTruth->Sumw2();
   hptltautight3posqcdlow->Sumw2();
   hptltautight3posqcdlowTruth->Sumw2();
   hptltautight3posqcdlowbwp0->Sumw2();
   hptltautight3posqcdlowbwp1->Sumw2();
   hptltautight3posqcdlowbwp2->Sumw2();
   hptltautight3posqcdlowbwp3->Sumw2();
   hptltautight3posqcdlowTruthbwp0->Sumw2();
   hptltautight3posqcdlowTruthbwp1->Sumw2();
   hptltautight3posqcdlowTruthbwp2->Sumw2();
   hptltautight3posqcdlowTruthbwp3->Sumw2();
   //ss
   hptltaussqcdlowbwp0->Sumw2();
   hptltaussqcdlowbwp1->Sumw2();
   hptltaussqcdlowbwp2->Sumw2();
   hptltaussqcdlowbwp3->Sumw2();
   hptltaussqcdlowTruthbwp0->Sumw2();
   hptltaussqcdlowTruthbwp1->Sumw2();
   hptltaussqcdlowTruthbwp2->Sumw2();
   hptltaussqcdlowTruthbwp3->Sumw2();
   // medium
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
   hmwltau3pssqcdlow->Sumw2();
   hmwltau3pssqcdlowTruth->Sumw2();
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
   // tight 
   hptltautight1pssqcdlow->Sumw2();
   hptltautight1pssqcdlowTruth->Sumw2();
   hptltautight1pssqcdlowbwp0->Sumw2();
   hptltautight1pssqcdlowbwp1->Sumw2();
   hptltautight1pssqcdlowbwp2->Sumw2();
   hptltautight1pssqcdlowbwp3->Sumw2();
   hptltautight1pssqcdlowTruthbwp0->Sumw2();
   hptltautight1pssqcdlowTruthbwp1->Sumw2();
   hptltautight1pssqcdlowTruthbwp2->Sumw2();
   hptltautight1pssqcdlowTruthbwp3->Sumw2();
   hmwltautight3pssqcdlow->Sumw2();
   hmwltautight3pssqcdlowTruth->Sumw2();
   hptltautight3pssqcdlow->Sumw2();
   hptltautight3pssqcdlowTruth->Sumw2();
   hptltautight3pssqcdlowbwp0->Sumw2();
   hptltautight3pssqcdlowbwp1->Sumw2();
   hptltautight3pssqcdlowbwp2->Sumw2();
   hptltautight3pssqcdlowbwp3->Sumw2();
   hptltautight3pssqcdlowTruthbwp0->Sumw2();
   hptltautight3pssqcdlowTruthbwp1->Sumw2();
   hptltautight3pssqcdlowTruthbwp2->Sumw2();
   hptltautight3pssqcdlowTruthbwp3->Sumw2();
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
   // oct 1 2018 
   hptltau1posgj->Sumw2();
   hptltau1posgjbwp0->Sumw2();
   hptltau1posgjbwp1->Sumw2();
   hptltau1posgjbwp2->Sumw2();
   hptltau1posgjbwp3->Sumw2();
   hptltau3posgj->Sumw2();
   hptltau3posgjbwp0->Sumw2();
   hptltau3posgjbwp1->Sumw2();
   hptltau3posgjbwp2->Sumw2();
   hptltau3posgjbwp3->Sumw2();
   hptltau1pssgj->Sumw2();
   hptltau1pssgjbwp0->Sumw2();
   hptltau1pssgjbwp1->Sumw2();
   hptltau1pssgjbwp2->Sumw2();
   hptltau1pssgjbwp3->Sumw2();
   hptltau3pssgj->Sumw2();
   hptltau3pssgjbwp0->Sumw2();
   hptltau3pssgjbwp1->Sumw2();
   hptltau3pssgjbwp2->Sumw2();
   hptltau3pssgjbwp3->Sumw2();
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
   // oct 1 2018 
   hmwltau1poslowgj->Sumw2();
   hptltau1poslowgj->Sumw2();
   hptltau1poslowgjbwp0->Sumw2();
   hptltau1poslowgjbwp1->Sumw2();
   hptltau1poslowgjbwp2->Sumw2();
   hptltau1poslowgjbwp3->Sumw2();
   hmwltau3poslowgj->Sumw2();
   hptltau3poslowgj->Sumw2();
   hptltau3poslowgjbwp0->Sumw2();
   hptltau3poslowgjbwp1->Sumw2();
   hptltau3poslowgjbwp2->Sumw2();
   hptltau3poslowgjbwp3->Sumw2();
   hmwltau1psslowgj->Sumw2();
   hptltau1psslowgj->Sumw2();
   hptltau1psslowgjbwp0->Sumw2();
   hptltau1psslowgjbwp1->Sumw2();
   hptltau1psslowgjbwp2->Sumw2();
   hptltau1psslowgjbwp3->Sumw2();
   hmwltau3psslowgj->Sumw2();
   hptltau3psslowgj->Sumw2();
   hptltau3psslowgjbwp0->Sumw2();
   hptltau3psslowgjbwp1->Sumw2();
   hptltau3psslowgjbwp2->Sumw2();
   hptltau3psslowgjbwp3->Sumw2();
   // 5-29 
   hjfltauos1B->Sumw2(); 
   hmwltauos1Bbj->Sumw2();
   hjfltauss1B->Sumw2();
   hmwltauss1Bbj->Sumw2();
   hmwltau3posqcd->Sumw2();
   hmwltau3posqcdTruth->Sumw2();
   hmwltau3pssqcd->Sumw2();
   hmwltau3pssqcdTruth->Sumw2();
   // 8-4 metlow medium os 
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
   hmwltau3posmetlow->Sumw2();
   hmwltau3posmetlowTruth->Sumw2();
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
   // tight 
   hptltautight1posmetlow->Sumw2();
   hptltautight1posmetlowTruth->Sumw2();
   hptltautight1posmetlowbwp0->Sumw2();
   hptltautight1posmetlowbwp1->Sumw2();
   hptltautight1posmetlowbwp2->Sumw2();
   hptltautight1posmetlowbwp3->Sumw2();
   hptltautight1posmetlowTruthbwp0->Sumw2();
   hptltautight1posmetlowTruthbwp1->Sumw2();
   hptltautight1posmetlowTruthbwp2->Sumw2();
   hptltautight1posmetlowTruthbwp3->Sumw2();
   hmwltautight3posmetlow->Sumw2();
   hmwltautight3posmetlowTruth->Sumw2();
   hptltautight3posmetlow->Sumw2();
   hptltautight3posmetlowTruth->Sumw2();
   hptltautight3posmetlowbwp0->Sumw2();
   hptltautight3posmetlowbwp1->Sumw2();
   hptltautight3posmetlowbwp2->Sumw2();
   hptltautight3posmetlowbwp3->Sumw2();
   hptltautight3posmetlowTruthbwp0->Sumw2();
   hptltautight3posmetlowTruthbwp1->Sumw2();
   hptltautight3posmetlowTruthbwp2->Sumw2();
   hptltautight3posmetlowTruthbwp3->Sumw2();
   // 8-4 lowmet ss medium
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
   hmwltau3pssmetlow->Sumw2();
   hmwltau3pssmetlowTruth->Sumw2();
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
   // tight 
   hptltautight1pssmetlow->Sumw2();
   hptltautight1pssmetlowTruth->Sumw2();
   hptltautight1pssmetlowbwp0->Sumw2();
   hptltautight1pssmetlowbwp1->Sumw2();
   hptltautight1pssmetlowbwp2->Sumw2();
   hptltautight1pssmetlowbwp3->Sumw2();
   hptltautight1pssmetlowTruthbwp0->Sumw2();
   hptltautight1pssmetlowTruthbwp1->Sumw2();
   hptltautight1pssmetlowTruthbwp2->Sumw2();
   hptltautight1pssmetlowTruthbwp3->Sumw2();
   hmwltautight3pssmetlow->Sumw2();
   hmwltautight3pssmetlowTruth->Sumw2();
   hptltautight3pssmetlow->Sumw2();
   hptltautight3pssmetlowTruth->Sumw2();
   hptltautight3pssmetlowbwp0->Sumw2();
   hptltautight3pssmetlowbwp1->Sumw2();
   hptltautight3pssmetlowbwp2->Sumw2();
   hptltautight3pssmetlowbwp3->Sumw2();
   hptltautight3pssmetlowTruthbwp0->Sumw2();
   hptltautight3pssmetlowTruthbwp1->Sumw2();
   hptltautight3pssmetlowTruthbwp2->Sumw2();
   hptltautight3pssmetlowTruthbwp3->Sumw2();
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
   // oct 1 2018 
   hptmtauemu1Bgj->Sumw2();
   hptmtauemu1Bgjbwp0->Sumw2();
   hptmtauemu1Bgjbwp1->Sumw2();
   hptmtauemu1Bgjbwp2->Sumw2();
   hptmtauemu1Bgjbwp3->Sumw2();
   hpttauemu1Bgj->Sumw2();
   hpttauemu1Bgjbwp0->Sumw2();
   hpttauemu1Bgjbwp1->Sumw2();
   hpttauemu1Bgjbwp2->Sumw2();
   hpttauemu1Bgjbwp3->Sumw2();
   hptmtauemu2Bgj->Sumw2();
   hptmtauemu2Bgjbwp0->Sumw2();
   hptmtauemu2Bgjbwp1->Sumw2();
   hptmtauemu2Bgjbwp2->Sumw2();
   hptmtauemu2Bgjbwp3->Sumw2();
   hpttauemu2Bgj->Sumw2();
   hpttauemu2Bgjbwp0->Sumw2();
   hpttauemu2Bgjbwp1->Sumw2();
   hpttauemu2Bgjbwp2->Sumw2();
   hpttauemu2Bgjbwp3->Sumw2();
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
   // 8-8 
   hmzll->Sumw2();
   hmzmm->Sumw2();
   hmzee->Sumw2();
   hmzleptau->Sumw2();
   hmzleptaubwp0->Sumw2();
   hmzleptaubwp1->Sumw2();
   hmzleptaubwp2->Sumw2();
   hmzleptaubwp3->Sumw2();
   hmzleptautight->Sumw2();
   hmzleptautightbwp0->Sumw2();
   hmzleptautightbwp1->Sumw2();
   hmzleptautightbwp2->Sumw2();
   hmzleptautightbwp3->Sumw2();
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
      double wt = mc_channel_number>0?_lum/43.814*mc_norm*mcWeightOrg*pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*JVT_EventWeight*
	SherpaNJetWeight*((dilep_type||trilep_type)*lepSFObjTight+(onelep_type||quadlep_type)*lepSFObjTight)*(nTaus_OR_Pt25>0?tauSFTight:1.0):1.0; // using lepSFObjLoose for 1l2tau
      // *lepSFObjTight*tauSFTight*
      //			 *pileupEventWeight_090*bTagSF_weight_MV2c10_Continuous*lepSFObjTight*
      //((!dilep_type||!total_charge)*lepSFTrigTight+(dilep_type&&total_charge)*lepSFTrigLoose)*tauSFTight*
      //JVT_EventWeight*SherpaNJetWeight*((quadlep_type>0)/lep_SFIsoLoose_0/lep_SFIsoLoose_1+(onelep_type>0)/lep_SFObjLoose_0*
      //		  (mc_channel_number>0?(tau_truth_0+tau_truth_1)>1:1)+(!quadlep_type&&!onelep_type));
      //study the conversion data vs mc from Z->mumu gamma trilep_type==2
      if(basic_selection){
	// check the ltau
	if(trig_match&&dilep_type&&total_charge==0&&lep_Pt_0>20e3&&lep_Pt_1>20e3&&
	   ((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&SelectTLepid(0)&&
	   ((abs(lep_ID_1)==11&&lep_promptLeptonVeto_TagWeight_1<-0.7)||(abs(lep_ID_1)==13&&lep_promptLeptonVeto_TagWeight_1<-0.5))&&SelectTLepid(1)){ //met>30 GeV ? ttbar vs z+bb:
	  //5-30 emu+b+tau
	  // check z->ll here 
	  if(nJets_OR_T>0&&(dilep_type==1||dilep_type==3)){
	    hmzll->Fill(Mll01/1000.<150.?Mll01/1000.:149.,wt);
	    if(dilep_type==1)hmzmm->Fill(Mll01/1000.<150.?Mll01/1000.:149.,wt);
	    if(dilep_type==3)hmzee->Fill(Mll01/1000.<150.?Mll01/1000.:149.,wt);
	  } 
          if((dilep_type==2||((dilep_type==1||dilep_type==3)&&(Mll01/GeV<80||Mll01/GeV>100)))&&total_charge==0&&nJets_OR_T_MV2c10_70>0&&nJets_OR_T<3&&nTaus_OR_Pt25==1){ // ttbar events
	    if(nJets_OR_T_MV2c10_70==1&&nJets_OR_T==1){ //ll+1b+tau // medium
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
              else if(tau_truthJetFlavour_0==21){ //oct 1 2018
		hptmtauemu1Bgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[0])hptmtauemu1Bgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hptmtauemu1Bgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hptmtauemu1Bgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hptmtauemu1Bgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
                else if(tau_truthJetFlavour_0==21){// oct 1 2018
                  hpttauemu1Bgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[0])hpttauemu1Bgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[1])hpttauemu1Bgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[2])hpttauemu1Bgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[3])hpttauemu1Bgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
            if(nJets_OR_T_MV2c10_70==2&&nJets_OR_T==2){// ll+2b+tau light->tau // medium
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
              else if(tau_truthJetFlavour_0==21){ // oct 1 2018
                hptmtauemu2Bgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[0])hptmtauemu2Bgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[1])hptmtauemu2Bgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[2])hptmtauemu2Bgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                if(tau_MV2c10_0>btagwpCut[3])hptmtauemu2Bgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
                else if(tau_truthJetFlavour_0==21){// oct 1 2018
                  hpttauemu2Bgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[0])hpttauemu2Bgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[1])hpttauemu2Bgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[2])hpttauemu2Bgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_MV2c10_0>btagwpCut[3])hpttauemu2Bgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
	}
	if(onelep_type&&SLtrig_match){
	  bool ptcut = RunYear==2015?((abs(lep_ID_0)==11&&lep_Pt_0/GeV>25)||(abs(lep_ID_0)==13&&lep_Pt_0/GeV>21)):lep_Pt_0/GeV>27;
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
	  if(trig_match&&ptcut&&(!( (abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5)))
	     &&SelectTLepid(0)&&nJets_OR_T_MV2c10_70>0&&((nTaus_OR_Pt25==1&&nJets_OR_T<4)||(nTaus_OR_Pt25==2&&nJets_OR_T<3))){
	    if(MET_RefFinal_et/GeV>25.0){
	      if(nTaus_OR_Pt25==1){
		if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os 
		  // qcdtau+2B+0,1j
		  hptmutauosqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  hetamutauosqcd->Fill(fabs(tau_eta_0), wt); // mar 10
                  hntkmutauosqcd->Fill(tau_numTrack_0, wt); // mar 10
		  if(tau_MV2c10_0>btagwpCut[0])hptltauosqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); //april 10 
		  if(tau_MV2c10_0>btagwpCut[1])hptltauosqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltauosqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltauosqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  if(tau_truthType_0==10){
                    hptmutauosqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutauosqcdTruth->Fill(fabs(tau_eta_0),wt);
                    hntkmutauosqcdTruth->Fill(tau_numTrack_0, wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltauosqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); //april 10
                    if(tau_MV2c10_0>btagwpCut[1])hptltauosqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltauosqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltauosqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  }
                  hleptruthmutauosqcd->Fill(lep_truthType_0,wt);
		  // qcdtau+2B + Tight 
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2&&tau_JetBDTSigTight_0){
                    hptltautight1posqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight1posqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight1posqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight1posqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight1posqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    //if((tau_truthOrigin_0>9&&tau_truthOrigin_0<15)||(tau_truthOrigin_0==43||tau_truthOrigin_0==0)){                                      
                    if(tau_truthType_0==10){
                      hptltautight1posqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight1posqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight1posqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight1posqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight1posqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1&&tau_JetBDTSigTight_0){ 
                    hmwltautight3posqcd->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltautight3posqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight3posqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight3posqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight3posqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight3posqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltautight3posqcdTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltautight3posqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight3posqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight3posqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight3posqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight3posqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
		  //qcdtau+2B medium
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    hptltau1posqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      hptltau1posqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){ // qcdtau+2B+j
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
		}
		else{ // ss
		  hptmutaussqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                  hetamutaussqcd->Fill(fabs(tau_eta_0),wt); // mar 10
                  hntkmutaussqcd->Fill(tau_numTrack_0, wt); // mar 10
		  if(tau_MV2c10_0>btagwpCut[0])hptltaussqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hptltaussqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltaussqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltaussqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_truthType_0==10){
		    hmwltau3pssqcdTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau3pssqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  }
                  hleptruthmutaussqcd->Fill(lep_truthType_0,wt);
		  // qcdtauss + 2B + tight
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2&&tau_JetBDTSigTight_0){
                    hptltautight1pssqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight1pssqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight1pssqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight1pssqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight1pssqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hptltautight1pssqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight1pssqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight1pssqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight1pssqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight1pssqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1&&tau_JetBDTSigTight_0){
                    hmwltautight3pssqcd->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltautight3pssqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight3pssqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight3pssqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight3pssqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight3pssqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltautight3pssqcdTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltautight3pssqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight3pssqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight3pssqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight3pssqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight3pssqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
		  //qcdtauss + 2B medium 
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){ 
		    hptltau1pssqcd->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      hptltau1pssqcdTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){ // qcdtau+2B+j
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
		}
	      }
	    }
	    else{  // met<25 cuts may-29 
	      if(nTaus_OR_Pt25==1){
                if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os
		  // qcdtau+2b+0,1j
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
                  if(tau_truthType_0==10){
                    hptmutauosqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutauosqcdlowTruth->Fill(fabs(tau_eta_0),wt);
                    hntkmutauosqcdlowTruth->Fill(tau_numTrack_0, wt);
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
		  //qcdlow+tau +2B tight 
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2&&tau_JetBDTSigTight_0){
                    hptltautight1posqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight1posqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight1posqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight1posqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight1posqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hptltautight1posqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight1posqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight1posqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight1posqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight1posqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1&&tau_JetBDTSigTight_0){
                    hmwltautight3posqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltautight3posqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight3posqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight3posqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight3posqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight3posqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltautight3posqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltautight3posqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight3posqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight3posqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight3posqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight3posqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
		  // qcdlow+2B medium 
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    hptltau1posqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      hptltau1posqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1posqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1posqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1posqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1posqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){ // qcdtau+2b+j
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
                }
                else{ // ss
		  // qcdtau+2b+0,1j
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
                  if(tau_truthType_0==10){
                    hptmutaussqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    hetamutaussqcdlowTruth->Fill(fabs(tau_eta_0),wt);
                    hntkmutaussqcdlowTruth->Fill(tau_numTrack_0, wt);
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
		  // ss qcdlow_tau+2B tight
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2&&tau_JetBDTSigTight_0){ 
                    hptltautight1pssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight1pssqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight1pssqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight1pssqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight1pssqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hptltautight1pssqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight1pssqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight1pssqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight1pssqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight1pssqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1&&tau_JetBDTSigTight_0){
                    hmwltautight3pssqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltautight3pssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight3pssqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight3pssqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight3pssqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight3pssqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltautight3pssqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltautight3pssqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight3pssqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight3pssqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight3pssqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight3pssqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
		  } 
		  // ss qcdlow + tau + 2B medium 
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){
		    hptltau1pssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      hptltau1pssqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1pssqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1pssqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1pssqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1pssqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1){ // ss qcd+tau+2B+j
		    hmwltau3pssqcdlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltau3pssqcdlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      hmwltau3pssqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt); 
		      hptltau3pssqcdlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3pssqcdlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau3pssqcdlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3pssqcdlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3pssqcdlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
                } // charge
              }
	    } // met 
	  }
	  // save z->ltau for lepton->tau calibration 
          if(trig_match&&ptcut&&((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&
	     SelectTLepid(0)&&(nTaus_OR_Pt25==1&&nJets_OR_T>0)){
	    if(((lep_ID_0>0?-1:1)*tau_charge_0)<0){
	      hmzleptau->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
	      if(tau_MV2c10_0>btagwpCut[0])hmzleptaubwp0->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
              if(tau_MV2c10_0>btagwpCut[1])hmzleptaubwp1->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
              if(tau_MV2c10_0>btagwpCut[2])hmzleptaubwp2->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
              if(tau_MV2c10_0>btagwpCut[3])hmzleptaubwp3->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
	      if(tau_JetBDTSigTight_0){ 
		hmzleptautight->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		if(tau_MV2c10_0>btagwpCut[0])hmzleptautightbwp0->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		if(tau_MV2c10_0>btagwpCut[1])hmzleptautightbwp1->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		if(tau_MV2c10_0>btagwpCut[2])hmzleptautightbwp2->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
		if(tau_MV2c10_0>btagwpCut[3])hmzleptautightbwp3->Fill((p4lepx+p4tau[0]).M()/1000.<150.?(p4lepx+p4tau[0]).M()/1000.:149.,wt);
	      }
	    }
	  }
	  if(trig_match&&ptcut&&((abs(lep_ID_0)==11&&lep_promptLeptonVeto_TagWeight_0<-0.7)||(abs(lep_ID_0)==13&&lep_promptLeptonVeto_TagWeight_0<-0.5))&&
		SelectTLepid(0)&&nJets_OR_T_MV2c10_70>0&&((nTaus_OR_Pt25==1&&nJets_OR_T<4)||(nTaus_OR_Pt25==2&&nJets_OR_T<3))){ // control region 
            hmetltau->Fill(MET_RefFinal_et/GeV, wt);
            double mt = 2*MET_RefFinal_et*lep_Pt_0*(1-cos(MET_RefFinal_phi-lep_Phi_0));
            mt = mt>0.?sqrt(mt):0.;
	    hmtltau->Fill(mt/GeV,wt);
	    nbjetsltau->Fill(nJets_OR_T_MV2c10_70, wt);
	    njetsltau->Fill(nJets_OR_T,wt); 
	    ntausltau->Fill(nTaus_OR_Pt25, wt); 
	    if(nTaus_OR_Pt25==1){ // ltauss ltauos
	      if(MET_RefFinal_et/GeV>25.0){
		if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os
		  hptltauos->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hptltauosbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hptltauosbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltauosbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltauosbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
                  if(tau_truthType_0==10){ // check truth tau
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
                    hmv2cltauosTruth->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt);
                    hsigtransltauosTruth->Fill(tau_BDTJetScoreSigTrans_0, wt);
                    hmv2c10ltauosTruth->Fill(tau_MV2c10_0, wt);
                  }
                  hleptruthltauos->Fill(lep_truthType_0,wt);
		  // ltau + 2B tight 
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
                      else if(tau_truthJetFlavour_0==21){ // oct 1 2018
                        hptltau1posgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau1posgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau1posgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau1posgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau1posgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2){ // ltau+2B medium
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
                      else if(tau_truthJetFlavour_0==21){ // oct 1 2018
                        hptltau3posgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau3posgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau3posgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau3posgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau3posgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		  // ltau +2B + j tight 
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
                      else if(tau_truthJetFlavour_0==21){ // oct 1 2018
                        hmwltau1poslowgj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                        hptltau1poslowgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau1poslowgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau1poslowgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau1poslowgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau1poslowgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		  // ltau+2B+j medium
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
                      else if(tau_truthJetFlavour_0==21){ // oct 1 2018
                        hmwltau3poslowgj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                        hptltau3poslowgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau3poslowgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau3poslowgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau3poslowgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau3poslowgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		}
		else{ // ss
		  hptltauss->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[0])hptltaussbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[1])hptltaussbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[2])hptltaussbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		  if(tau_MV2c10_0>btagwpCut[3])hptltaussbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt); 
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
                    hmv2cltaussTruth->Fill(fabs(tau_MV2c10_0)<1?tau_MV2c10_0:0.99*tau_MV2c10_0/fabs(tau_MV2c10_0), wt); // mar 25
                  }
                  hleptruthltauss->Fill(lep_truthType_0,wt);
		  // ltau+2B + tight 
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
                      else if(tau_truthJetFlavour_0==21){// oct 1 2018
                        hptltau1pssgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau1pssgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau1pssgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau1pssgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau1pssgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		  // ltau+2B medium
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
                      else if(tau_truthJetFlavour_0==21){// oct 1 2018
                        hptltau3pssgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau3pssgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau3pssgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau3pssgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau3pssgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		  // ltau+2B+j tight 
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
                      else if(tau_truthJetFlavour_0==21){// oct 1 2018
                        hmwltau1psslowgj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                        hptltau1psslowgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau1psslowgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau1psslowgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau1psslowgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau1psslowgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		    if(tau_truthType_0==10){
		      hmwltau1psslowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau1psslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau1psslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau1psslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau1psslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau1psslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		  // ltau +2B+j medium
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
                      else if(tau_truthJetFlavour_0==21){ // oct 1 2018
                        hmwltau3psslowgj->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                        hptltau3psslowgj->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[0])hptltau3psslowgjbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[1])hptltau3psslowgjbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[2])hptltau3psslowgjbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                        if(tau_MV2c10_0>btagwpCut[3])hptltau3psslowgjbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
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
		    if(tau_truthType_0==10){
		      hmwltau3psslowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltau3psslowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltau3psslowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltau3psslowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltau3psslowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltau3psslowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
		}
	      } // met>25 GeV 
	      else{ // met < 25 GeV
		if((lep_ID_0>0?-1:1)*tau_charge_0<0){ // os only medium tau:    
		  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2&&tau_JetBDTSigTight_0){
		    //hmwltau1posmetlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		    hptltautight1posmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[0])hptltautight1posmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[1])hptltautight1posmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[2])hptltautight1posmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_MV2c10_0>btagwpCut[3])hptltautight1posmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    if(tau_truthType_0==10){
		      //hmwltau1pssqcdlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
		      hptltautight1posmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[0])hptltautight1posmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[1])hptltautight1posmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[2])hptltautight1posmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		      if(tau_MV2c10_0>btagwpCut[3])hptltautight1posmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
		    }
		  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1&&tau_JetBDTSigTight_0){
                    hmwltautight3posmetlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltautight3posmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight3posmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight3posmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight3posmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight3posmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltautight3posmetlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltautight3posmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight3posmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight3posmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight3posmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight3posmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
		  // medium 
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
		  //		  
		}
		else{ //ss  // tight 
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==2&&tau_JetBDTSigTight_0){
                    hptltautight1pssmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight1pssmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight1pssmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight1pssmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight1pssmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hptltautight1pssmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight1pssmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight1pssmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight1pssmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight1pssmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
                  if(nJets_OR_T_MV2c10_70>1&&nJets_OR_T==3&&njets==1&&tau_JetBDTSigTight_0){
                    hmwltautight3pssmetlow->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                    hptltautight3pssmetlow->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[0])hptltautight3pssmetlowbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[1])hptltautight3pssmetlowbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[2])hptltautight3pssmetlowbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_MV2c10_0>btagwpCut[3])hptltautight3pssmetlowbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    if(tau_truthType_0==10){
                      hmwltautight3pssmetlowTruth->Fill((p4jet[0]+p4tau[0]).M()/1000.<150.?(p4jet[0]+p4tau[0]).M()/1000.:149.,wt);
                      hptltautight3pssmetlowTruth->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[0])hptltautight3pssmetlowTruthbwp0->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[1])hptltautight3pssmetlowTruthbwp1->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[2])hptltautight3pssmetlowTruthbwp2->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                      if(tau_MV2c10_0>btagwpCut[3])hptltautight3pssmetlowTruthbwp3->Fill(tau_pt_0/GeV<115?tau_pt_0/GeV:114., wt);
                    }
                  }
		  // medium 
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
		  //
		}
		//
	      }
	    }
	  }    // control regions 
	}
	//
      } // trig
   }// loop over events 
   // end for now.
   //_histf->cd();
   _histf->Write();
   _histf->Close();
}
