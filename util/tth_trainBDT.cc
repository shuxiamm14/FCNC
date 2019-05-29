#include <cstdlib>
#include <iostream> 
#include <map>
#include <string>
#include "stdio.h"
#include "stdlib.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMVA/TMVAGui.h"
#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#endif
using namespace TMVA;
void RunMVA( TString region = "", TCut cut = "(EventNumber%2)!=0" , TString weightfile = "", TString ncuts = "", TString ntrees = "") 
{
   TString prefix = PACKAGE_DIR;
   TMVA::Tools::Instance();
   std::cout << std::endl;
   std::cout << "==> Start TMVARegression" << std::endl;
   TString myMethodList = "BDTG";
   TFile* outputFile = TFile::Open(weightfile+"_out.root", "RECREATE" );
   TMVA::Factory *factory = new TMVA::Factory(weightfile, outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );
   TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");
   dataloader->AddVariable("tau_pt_0",'F');
   dataloader->AddVariable("tau_pt_1",'F');
   if(region == "reg2mtau1b3jos" || region == "reg2mtau1b2jos" || region == "reg1l1tau1b3j" ||  region == "reg1l1tau1b2j"){
      dataloader->AddVariable("etmiss",'F');
      dataloader->AddVariable("dphitauetmiss",'F');
      dataloader->AddVariable("drtautau",'F');
      dataloader->AddVariable("phicent",'F');
      dataloader->AddVariable("tautaumass",'F');
      if(region != "reg1l1tau1b2j"){
         dataloader->AddVariable("wmass",'F');
         dataloader->AddVariable("t1mass",'F');
      }
      dataloader->AddVariable("t2mass",'F');
      dataloader->AddVariable("x1fit",'F');
      dataloader->AddVariable("x2fit",'F');
   }else if(region == "reg1l2tau1bnj_os"){
      //dataloader->AddVariable("t1mass",'F');
      //dataloader->AddVariable("wmass",'F');
      //dataloader->AddVariable("tautaumass",'F');
      //dataloader->AddVariable("t2mass",'F');
      //dataloader->AddVariable("x1fit", 'F');
      //dataloader->AddVariable("x2fit", 'F');
      dataloader->AddVariable("t1vismass",'F');
      dataloader->AddVariable("mtaujmin",'F');
      dataloader->AddVariable("drltau",'F');
      dataloader->AddVariable("drtautau",'F');
      dataloader->AddVariable("etamax",'F');
      dataloader->AddVariable("mtw",'F');
      dataloader->AddVariable("drlbditau",'F');
      dataloader->AddVariable("tautauvispt",'F');
      dataloader->AddVariable("t2vismass",'F');
   }

   dataloader->AddVariable("ttvismass",'F');
   dataloader->AddVariable("drtaujmin",'F');


   TChain* signal = new TChain(region);
   TChain* background = new TChain(region);

   TChain* datatreess;
   TChain* mctreess;

   if(region.Contains("2mtau")){
      TString inputdatanameshad[] = {"data1516","data17","data18"};
      TString inputsignameshad[] = {"mc16a_fcnc_ch_qq","mc16d_fcnc_ch_qq","mc16e_fcnc_ch_qq",
                                    "mc16a_fcnc_uh_qq","mc16d_fcnc_uh_qq","mc16e_fcnc_uh_qq",
                                    "mc16a_fcnc_ch_lv","mc16d_fcnc_ch_lv","mc16e_fcnc_ch_lv",
                                    "mc16a_fcnc_uh_lv","mc16d_fcnc_uh_lv","mc16e_fcnc_uh_lv",
                                    "mc16a_fcnc_prod_ch","mc16d_fcnc_prod_ch","mc16e_fcnc_prod_ch",
                                    "mc16a_fcnc_prod_uh","mc16d_fcnc_prod_uh","mc16e_fcnc_prod_uh"};
      TString inputbkgnameshad[] = {"mc16a_wjet","mc16d_wjet","mc16e_wjet","mc16a_zll","mc16d_zll","mc16e_zll","mc16a_smhiggs","mc16a_ztautau","mc16d_smhiggs","mc16d_ztautau","mc16e_smhiggs","mc16e_ztautau","mc16a_diboson","mc16a_top","mc16d_diboson","mc16d_top","mc16e_diboson","mc16e_top"};
   
      double norm = region == "reg2mtau1b2jos"? 4097.810002/2816.409586 : 4331.872451/3191.282355;
   
   
      for (int i = 0; i < sizeof(inputsignameshad)/sizeof(TString); ++i)
      {
         signal->Add(prefix + "/data/hadhadreduce2/" + inputsignameshad[i] + "_tree.root");
      }
      for (int i = 0; i < sizeof(inputbkgnameshad)/sizeof(TString); ++i)
      {
         background->Add(prefix + "/data/hadhadreduce2/" + inputbkgnameshad[i] + "_tree.root");
      }
      if(region == "reg2mtau1b2jos") {
         datatreess = new TChain("reg2mtau1b2jss");
         mctreess = new TChain("reg2mtau1b2jss");
      } else {
         datatreess = new TChain("reg2mtau1b3jss");
         mctreess = new TChain("reg2mtau1b3jss");
      }
      for (int i = 0; i < sizeof(inputbkgnameshad)/sizeof(TString); ++i)
      {
         mctreess->Add(prefix + "/data/hadhadreduce2/" + inputbkgnameshad[i] + "_tree.root");
      }
      for (int i = 0; i < sizeof(inputdatanameshad)/sizeof(TString); ++i)
      {
         datatreess->Add(prefix + "/data/hadhadreduce2/" + inputdatanameshad[i] + "_tree.root");
      }
      TCut mycuts = "tauabspdg == 15";
   
      dataloader->AddTree(signal, "Signal", 1.0, cut, Types::kTraining);
      dataloader->AddTree(background, "Background", 1, cut && mycuts, Types::kTraining);
      dataloader->AddTree(datatreess, "Background", norm, cut, Types::kTraining); 
      dataloader->AddTree(mctreess, "Background", -norm, cut && mycuts, Types::kTraining);
   
      dataloader->AddTree(signal, "Signal", 1.0, !cut, Types::kTesting);
      dataloader->AddTree(background, "Background", 1, !cut && mycuts, Types::kTesting);
      dataloader->AddTree(datatreess, "Background", norm, !cut, Types::kTesting); 
      dataloader->AddTree(mctreess, "Background", -norm, !cut && mycuts, Types::kTesting);
      dataloader->SetSignalWeightExpression    ("weights[0]");
      dataloader->SetBackgroundWeightExpression("weights[0]");
   }else{
      TString inputdatanamestth[] = {"data1516","data17"};
      TString inputsignamestth[] = {"fcnc_ch","fcnc_uh"};//,"fcnc_prod_uh","fcnc_prod_ch"};
      TString inputbkgnamestth[] = {"Vjets","diboson","ttV","ttbarnohad","other","ttH","ttbargamma","sherpattbar"};

      if(region.Contains("reg1l2tau1bnj")) {
         datatreess = new TChain("reg1l2tau1bnj_ss");
         mctreess = new TChain("reg1l2tau1bnj_ss");
      }

      prefix += "/data/reduce2/";
      for (int i = 0; i < 2; ++i){
         signal->Add(prefix + inputsignamestth[i]+"a_tree.root");
         signal->Add(prefix + inputsignamestth[i]+"d_tree.root");
      }
   //   for (int i = 0; i < 7; ++i)
   //      background->Add(prefix + inputbkgnames[i]+"_tree.root");

      if(region.Contains("reg1l2tau1bnj")) {
         datatreess -> Add(prefix + inputdatanamestth[0]+"_tree.root");
         datatreess -> Add(prefix + inputdatanamestth[1]+"_tree.root");
         mctreess->Add(prefix + inputbkgnamestth[3]+"a_tree.root");
         mctreess->Add(prefix + inputbkgnamestth[6]+"a_tree.root");
         mctreess->Add(prefix + inputbkgnamestth[3]+"d_tree.root");
         mctreess->Add(prefix + inputbkgnamestth[6]+"d_tree.root");
      }
      background->Add(prefix + inputbkgnamestth[3]+"a_tree.root");
      background->Add(prefix + inputbkgnamestth[6]+"a_tree.root");
      //background->Add(prefix + inputbkgnamestth[7]+"a_tree.root");
      background->Add(prefix + inputbkgnamestth[3]+"d_tree.root");
      background->Add(prefix + inputbkgnamestth[6]+"d_tree.root");
      //background->Add(prefix + inputbkgnamestth[7]+"d_tree.root");
      //background->Add(prefix + "data_tree.root");


      TCut mycuts = region.Contains("reg1l2tau1bnj") ? "tau_truthType_0 == 10 && tau_truthType_1 == 10 && weights[0] >0" : "tau_truthType_0 == 10 && weights[0] >0";
      TCut mycutb = "weights[0]>0";
      printf(" >>>> Training signal events: %d\n",(Int_t)signal->GetEntries((const char*)(mycuts && cut)));
      printf(" >>>> Training background events: %d\n",(Int_t)background->GetEntries((const char*)(mycutb && cut)));
      dataloader->AddTree(signal, "Signal", 1.0, mycuts && cut, Types::kTraining);
      dataloader->AddTree(background, "Background", 1.0, mycutb && cut, Types::kTraining);
      if(region.Contains("reg1l2tau1bnj")) dataloader->AddTree(mctreess, "Background", 1.0, mycutb && cut, Types::kTraining);
      if(region.Contains("reg1l2tau1bnj")) dataloader->AddTree(datatreess, "Background", 1.0, mycutb && cut, Types::kTraining);
      dataloader->AddTree(signal, "Signal", 1.0, mycuts && !cut, Types::kTesting);
      dataloader->AddTree(background, "Background", 1.0, mycutb && !cut, Types::kTesting);
   //   dataloader->SetSignalWeightExpression    ("weights[0]*fakeSF");
   //   dataloader->SetBackgroundWeightExpression("weights[0]*fakeSF");
      dataloader->SetSignalWeightExpression    ("weights[0]");
      dataloader->SetBackgroundWeightExpression("weights[0]");
   }
   TString tmp_bdt_setting = "!H:!V:NTrees=";
   factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTG",
                           tmp_bdt_setting + ntrees + ":MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.1:UseBaggedBoost=True:BaggedSampleFraction=0.6:nCuts="+ncuts+":MaxDepth=2");
   factory->TrainAllMethods();
   factory->TestAllMethods();
   factory->EvaluateAllMethods();    
   outputFile->Close();
   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;      
   delete factory;
   if (!gROOT->IsBatch()) TMVAGui( outputFile->GetName() );
}
int main(int argc, char const *argv[])
{
   if (argc!=5)
   {
    printf("please give the setting: region\nand mva splitting: 2 or 5\nnumber of cuts\nnumber of trees\n");
    return 0;
   }
   bool testonly = 0;
   TString catname=argv[1];
   int classnb(*argv[2]-'0');
   TString cutnb = "(eventNumber%";
   cutnb += char(*argv[2]);
   cutnb += ")!=";
   for (int i = 1; i < classnb+1; ++i)
   {
      char stri = i+'0';
      char stri1= stri-1;
      RunMVA(catname,TCut(cutnb+stri1),catname+"TMVAClassification_"+stri,argv[3],argv[4]);
      if(testonly) break;
   }
   return 0;
}