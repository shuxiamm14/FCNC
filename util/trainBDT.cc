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
  char str[300];
   TMVA::Tools::Instance();
   std::cout << std::endl;
   std::cout << "==> Start TMVARegression" << std::endl;
   TString myMethodList = "BDTG";
   TFile* outputFile = TFile::Open( region+"_out.root", "RECREATE" );
   TMVA::Factory *factory = new TMVA::Factory( region + weightfile, outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );
   TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");

   if(region != "reg1l1tau1b2j") {
      dataloader->AddVariable("t1mass",'F');
      dataloader->AddVariable("wmass",'F');
      dataloader->AddVariable("t1vismass",'F');
      dataloader->AddVariable("tau_subpt",'F');
   }
   dataloader->AddVariable("tautaumass",'F');
   dataloader->AddVariable("ttvismass",'F');
   dataloader->AddVariable("t2mass",'F');
   dataloader->AddVariable("x1fit", 'F');
   dataloader->AddVariable("x2fit", 'F');
   dataloader->AddVariable("t2vismass",'F');
   dataloader->AddVariable("tau_leadpt",'F');
   TChain* signal = new TChain(region);
   TChain* background = new TChain(region);
   TString inputsignames[] = {"fcnc_ch","fcnc_uh"};
   TString inputbkgnames[] = {"Vjets","diboson","ttV","ttbarnohad","other","ttH","ttbargamma"};
   TString prefix = PACKAGE_DIR;
   prefix += "/data/reduce2/";
   for (int i = 0; i < 2; ++i)
      signal->Add(prefix + inputsignames[i]+"_tree.root");
   for (int i = 0; i < 7; ++i)
      background->Add(prefix + inputbkgnames[i]+"_tree.root");
   TCut mycuts = "";
   TCut mycutb = "";
   printf(" >>>> Training signal events: %d\n",(Int_t)signal->GetEntries((const char*)(mycuts && cut)));
   printf(" >>>> Training background events: %d\n",(Int_t)background->GetEntries((const char*)(mycutb && cut)));
   dataloader->AddTree(signal, "Signal", 1.0, mycuts && cut, Types::kTraining);
   dataloader->AddTree(background, "Background", 1.0, mycutb && cut, Types::kTraining);
   dataloader->AddTree(signal, "Signal", 1.0, mycuts && !cut, Types::kTesting);
   dataloader->AddTree(background, "Background", 1.0, mycutb && !cut, Types::kTesting);
   dataloader->SetSignalWeightExpression    ("weight*fakeSF");
   dataloader->SetBackgroundWeightExpression("weight*fakeSF");
   TString tmp_bdt_setting = "!H:!V:NTrees=";
   factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTG",
                           tmp_bdt_setting + ntrees + "::BoostType=Grad:Shrinkage=0.1:UseBaggedBoost=True:BaggedSampleFraction=0.6:nCuts="+ncuts+":MaxDepth=2");
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
   TString catname=argv[1];
   int classnb(*argv[2]-'0');
   TString cutnb = "(EventNumber%";
   cutnb += char(*argv[2]);
   cutnb += ")!=";
   for (int i = 1; i < classnb+1; ++i)
   {
      char stri = i+'0';
      char stri1= stri-1;
      RunMVA(catname,TCut(cutnb+stri1),catname+"TMVAClassification_"+stri,argv[4],argv[5]);
   }
   return 0;
}