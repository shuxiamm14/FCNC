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
#include "TMVA/MethodBDT.h"
#include "AtlasStyle.h"
#include "AtlasLabels.h"
#include "common.h"
#include "LatexChart.h"
#include <fstream>
#endif
using namespace TMVA;
using namespace std;
namespace TMVA{
   class CrossValidation{
   public:
      CrossValidation(){};
      void changeModelPersistence(TMVA::Factory* fact, bool persist){
         fact->fModelPersistence = persist;
      }
   };
}
void RunMVA( TString region = "", TCut cut = "(eventNumber%2)!=0" , TString weightfile = "", TString ncuts = "", TString ntrees = "", char ipart = '0') 
{
   TString framework = (region.Contains("2mtau") || region.Contains("2ltau") || region.Contains("1mtau1ltau")) ? "xTFW" : "tthML";
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
   //dataloader->AddVariable("tau_pt_1",'F');
   dataloader->AddVariable("etmiss",'F');
   dataloader->AddVariable("ttvismass",'F');
   if(region.Contains("j")) dataloader->AddVariable("drtaujmin",'F');
   if(framework == "tthML") {
      dataloader->AddVariable("drlb",'F');
      dataloader->AddVariable("drltau",'F');
      dataloader->AddVariable("drtaub",'F');
      if(region.Contains("2tau")) dataloader->AddVariable("drtautau",'F');
      dataloader->AddVariable("lep_pt_0",'F');
   }else{
      dataloader->AddVariable("drtautau",'F');
      dataloader->AddVariable("t2mass",'F');
   }
   if(region.Contains("2j") || region.Contains("3j")){
      dataloader->AddVariable("dphitauetmiss",'F');
      dataloader->AddVariable("phicent",'F');
      dataloader->AddVariable("tautaumass",'F');
      dataloader->AddVariable("x1fit",'F');
      dataloader->AddVariable("x2fit",'F');
      dataloader->AddVariable("t1mass",'F');
      if(region.Contains("1l1tau")){
         dataloader->AddVariable("mjjmin",'F');
      }
      if(!region.Contains("1l1tau1b2j")){
         dataloader->AddVariable("wmass",'F');
      }
      if(region.Contains("1l1tau1b3j_os"))  dataloader->AddVariable("chi2",'F');
   }else if(region.Contains("1l2tau1") || region.Contains("2lSS")){
      dataloader->AddVariable("t1vismass",'F');
      dataloader->AddVariable("mtaujmin",'F');
      dataloader->AddVariable("etamax",'F');
      dataloader->AddVariable("mtw",'F');
      dataloader->AddVariable("drlbditau",'F');
      dataloader->AddVariable("tautauvispt",'F');
      dataloader->AddVariable("t2vismass",'F');
   }


   TChain* signal = new TChain(region);
   TChain* background = new TChain(region);

   TChain* datatreess = 0;
   TChain* mctreess =0;
   //bool useSS = framework == "xTFW" || region.Contains("reg1l2tau1bnj");
   bool useSS =region.Contains("reg1l2tau1bnj");
   bool uselowtauID= framework == "xTFW";

   if(useSS){
      TString regionss = region;
      regionss.ReplaceAll("os","ss");
      datatreess = new TChain(regionss);
      mctreess = new TChain(regionss);
   }
   if(uselowtauID){
      TString regionss = region;
      regionss.ReplaceAll("2mtau","1mtau1ltau");
      datatreess = new TChain(regionss);
      mctreess = new TChain(regionss);
   }

   auto inputbkgsamples = getBkgSamples(framework);
   auto inputcHfiles = signalmap.at("tcH");
   auto inputuHfiles = signalmap.at("tuH");
   
   TString nominaltreedir  = framework=="tthML" ? "nominal/" : "NOMINAL/";
   TString version = framework=="tthML"?"5":"3";
   for (int icamp = 0; icamp < 3; ++icamp)
   {
      for (auto &file : inputcHfiles)
      {
         signal->Add(prefix + "/data/v"+version+"/" + framework + "reduce2/" + nominaltreedir + mc_campaigns[icamp] + "_" + file + "_tree.root");
      }
      for (auto &file : inputuHfiles)
      {
         signal->Add(prefix + "/data/v"+version+"/" + framework + "reduce2/" + nominaltreedir + mc_campaigns[icamp] + "_" + file + "_tree.root");
      }
      for (auto &bkgsample : inputbkgsamples)
      {
         if(uselowtauID&&bkgsample.name=="zll")continue;
         background->Add(prefix + "/data/v"+version+"/" + framework + "reduce2/" + nominaltreedir + mc_campaigns[icamp] + "_" + bkgsample.name + "_tree.root");
      }
      if(useSS){
         for (auto &bkgsample : inputbkgsamples)
         {
            mctreess->Add(prefix + "/data/v"+version+"/" + framework + "reduce2/" + nominaltreedir + mc_campaigns[icamp] + "_" + bkgsample.name + "_tree.root");
         }
         datatreess->Add(prefix + "/data/v"+version+"/" + framework + "reduce2/" + nominaltreedir + data_campaigns[icamp] + "_tree.root");
      }
   }
   TCut mycuts = "abs(taus_matched_pdgId[0]) == 15 && abs(taus_matched_pdgId[1]) == 15 && weights[0] >0";

   //double norm = region == "reg2mtau1b2jos"? 4097.810002/2816.409586 : 4331.872451/3191.282355;
   //double norm = region == "reg2mtau1b2jos"? 1.09 : 1.57;
   double norm =0.3;

   if(framework == "tthML") mycuts = region.Contains("2tau") ? "abs(taus_matched_pdgId[0]) == 15 && abs(taus_matched_pdgId[1]) == 15 && weights[0] >0" : "abs(taus_matched_pdgId[0]) == 15 && weights[0] >0";
   TCut mycutb = "weights[0]>0";
   printf(" >>>> Training signal events: %d\n",(Int_t)signal->GetEntries((const char*)(mycuts && cut)));
   printf(" >>>> Training background events: %d\n",(Int_t)background->GetEntries((const char*)(mycutb && cut)));
   dataloader->AddTree(signal, "Signal", 1.0, mycuts && cut, Types::kTraining);
   dataloader->AddTree(signal, "Signal", 1.0, mycuts && !cut, Types::kTesting);
   dataloader->AddTree(background, "Background", 1.0, mycutb && cut, Types::kTraining);
   dataloader->AddTree(background, "Background", 1.0, mycutb && !cut, Types::kTesting);
   if(useSS) {
      dataloader->AddTree(mctreess, "Background", framework == "tthML"? 1:-norm, mycutb && cut, Types::kTraining);
      dataloader->AddTree(mctreess, "Background", framework == "tthML"? 1:-norm, mycutb && !cut, Types::kTesting);
      dataloader->AddTree(datatreess, "Background", framework == "tthML"? 1:norm, mycutb && cut, Types::kTraining);
      dataloader->AddTree(datatreess, "Background", framework == "tthML"? 1:norm, mycutb && !cut, Types::kTesting);
   }

   dataloader->SetSignalWeightExpression    ("weights[0]");
   dataloader->SetBackgroundWeightExpression("weights[0]");
   TString tmp_bdt_setting = "!H:!V:NTrees=";
   TString title = "BDTG";
   factory->BookMethod( dataloader, TMVA::Types::kBDT, title,
                           tmp_bdt_setting + ntrees + ":MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.1:UseBaggedBoost=True:BaggedSampleFraction=0.6:nCuts="+ncuts+":MaxDepth=2");
   CrossValidation myVal;
   myVal.changeModelPersistence(factory,0);
   factory->TrainAllMethods();
   MethodBDT* theBDT = dynamic_cast<MethodBDT*>(factory->GetMethod(dataloader->GetName(),title));
   auto importance = theBDT->GetVariableImportance();
   std::ofstream outputimportance;
   outputimportance.open(("Importance_" + region + "_" + ipart + ".txt").Data());
   int ivar = 0;
   for(auto imp : importance){
      outputimportance<<theBDT->GetInputVar(ivar)<< " " <<imp<<endl;
      ivar++;
   }
   outputimportance.close();
   myVal.changeModelPersistence(factory,1);
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
   if (argc<4)
   {
    printf("please give the setting: region\nand mva splitting: 2 or 5\nnumber of cuts\nnumber of trees\n");
    return 0;
   }
   TString figdir = FIGURE_DIR;
   TString tabdir = TABLE_DIR;
   bool testonly = 0;
   TString catname=argv[1];
   int classnb(*argv[2]-'0');
   TString cutnb = "(eventNumber%";
   cutnb += char(*argv[2]);
   cutnb += ")!=";
   TFile *outputfile[5];

   float optim = 0;
   bool plotROC = 0;
   int ncut,ntree;
   auto train = [&](TString ncuts, TString ntrees){
      for (int i = 1; i < classnb+1; ++i)
      {
         char stri = i+'0';
         char stri1= stri-1;
         TString weightfile = catname+"TMVAClassification_"+stri;
         RunMVA(catname,TCut(cutnb+stri1),weightfile,ncuts,ntrees,stri);
         outputfile[i-1] = new TFile(weightfile+"_out.root");
         if(testonly) break;
      }
   
      if(classnb == 2){
         SetAtlasStyle();
         TH1D* testeven = (TH1D*) outputfile[0]->Get("dataset/Method_BDTG/BDTG/MVA_BDTG_rejBvsS");
         if(!testeven) testeven = (TH1D*) outputfile[0]->Get("dataset/Method_BDT/BDTG/MVA_BDTG_rejBvsS");
         TH1D* testodd = (TH1D*) outputfile[1]->Get("dataset/Method_BDTG/BDTG/MVA_BDTG_rejBvsS");
         if(!testodd) testodd = (TH1D*) outputfile[1]->Get("dataset/Method_BDT/BDTG/MVA_BDTG_rejBvsS");
         if(plotROC){
            testeven->SetNameTitle("Test Even","Test Even");
            testeven->SetLineColor(2);
            testeven->SetMarkerSize(0);
            testodd->SetNameTitle("Test Odd","Test Odd");
            testodd->SetLineColor(4);
            testodd->SetMarkerSize(0);
            TCanvas c1(catname,catname,1000,1000);
            testeven->GetXaxis()->SetRangeUser(0,1);
            testeven->GetYaxis()->SetRangeUser(0,1);
            TLegend l1(0.3,0.55,0.7,0.4);
            l1.AddEntry(testeven,"Test Even");
            l1.AddEntry(testodd,"Test Odd");
            c1.cd();
            gPad->SetGrid();
            testeven->Draw();
            testodd->Draw("same");
            l1.Draw();
            TString framework = (catname.Contains("2mtau") || catname.Contains("2ltau") || catname.Contains("1mtau1ltau")) ? "xTFW" : "tthML";
            c1.SaveAs(figdir + "/" + framework + "/BDT/roc_" + catname + ".pdf");
         }
         float intodd = testodd->Integral()/testodd->GetNbinsX();
         float inteven = testeven->Integral()/testeven->GetNbinsX();
         return (intodd+inteven)*50 - fabs(intodd-inteven)*100;
      }
      return (float)0.;
   };
   if(TString(argv[3]) == "Optim"){
      ncut=5;
      ntree=10;
      optim = train(to_string(ncut).c_str(),to_string(ntree).c_str());
      LatexChart chart(catname.Data());
      chart.maxcolumn=7;
      chart.set("NTrees="+to_string(ntree),"NCuts="+to_string(ncut),optim);
      ofstream debugfile("Optim_debug.txt");
      while(true){
         debugfile << ncut <<" "<< ntree <<" "<<optim<<endl;
         float treestep = train(to_string(ncut).c_str(),to_string(ntree+10).c_str());
         chart.set("NTrees="+to_string(ntree+10),"NCuts="+to_string(ncut),treestep);
         float cutstep = train(to_string(ncut+5).c_str(),to_string(ntree).c_str());
         chart.set("NTrees="+to_string(ntree),"NCuts=" + to_string(ncut+5),cutstep);
         if(optim > cutstep && optim > treestep){
            plotROC = 1;
            train(to_string(ncut).c_str(),to_string(ntree).c_str());
            break;
         }
         else if(treestep > cutstep)
         {
            ntree+=10;
            optim = treestep;
         }else{
            ncut+=5;
            optim = cutstep;
         }
      }
      debugfile.close();
      ofstream file(("OptimResult_" + catname + ".txt").Data());
      file << ncut << endl << ntree << endl;
      file.close();
      chart.print((tabdir+"/BDT/Optim_"+catname).Data());
   }else{
      plotROC = 1;
      train(argv[3],argv[4]);
   }
   return 0;
}
