
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include "common.h"
#include "observable.h" 
int main(int argc, char const *argv[])
{
  if(argc!=2){
    printf("please feed the file and the tree, branch name\n");
    exit(0);
  }
    
    // FFnm=(2mtau1b2jss+2mtau1b3jss)/(1l1mtau1b2jss+1l1mtau1b3jss)


    TString  readthefile=TString(PACKAGE_DIR)+"/run/reduce3/NOMINAL/";
    auto bkgsample = getBkgSamples("xTFW");
    std::vector<TString> compaign={"mc16a","mc16d","mc16e"};
    TString suffix="_NOMINAL.root"; 

    TFile*   histFile =0; 
    TH1D *total_1p_numerator=0;
    TH1D *total_1p_denominator=0;
    
    std::vector<std::string> total_1p_numerator_sample_name;
    std::vector<std::string> total_1p_denominator_sample_name;
    std::vector<TString> data_sample_name={"data17_NOMINAL.root","data18_NOMINAL.root","data1516_NOMINAL.root"};

    std::vector<std::string> total_1p_numerator_sample_name_nm={"NOMINAL_reg2mtau1b2jos_1prong_vetobtagwp70_highmet_leading_index_bin",
    "NOMINAL_reg2mtau1b2jos_1prong_vetobtagwp70_highmet_subleading_index_bin","NOMINAL_reg2mtau1b3jos_1prong_vetobtagwp70_highmet_leading_index_bin",
    "NOMINAL_reg2mtau1b3jos_1prong_vetobtagwp70_highmet_subleading_index_bin","NOMINAL_reg2mtau1b2jos_3prong_vetobtagwp70_highmet_leading_index_bin",
     "NOMINAL_reg2mtau1b2jos_3prong_vetobtagwp70_highmet_subleading_index_bin","NOMINAL_reg2mtau1b3jos_3prong_vetobtagwp70_highmet_leading_index_bin",
     "NOMINAL_reg2mtau1b3jos_3prong_vetobtagwp70_highmet_subleading_index_bin"};

     std::vector<std::string> total_1p_denominator_sample_name_nm={"NOMINAL_reg1mtau1ltau1b3jos_1prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1ltau1mtau1b3jos_1prong_vetobtagwp70_highmet_leading_index_bin","NOMINAL_reg1mtau1ltau1b3jos_3prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1ltau1mtau1b3jos_3prong_vetobtagwp70_highmet_leading_index_bin","NOMINAL_reg1mtau1ltau1b2jos_1prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1ltau1mtau1b2jos_1prong_vetobtagwp70_highmet_leading_index_bin","NOMINAL_reg1mtau1ltau1b2jos_3prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1ltau1mtau1b2jos_3prong_vetobtagwp70_highmet_leading_index_bin"};
     
      std::vector<std::string> total_1p_denominator_sample_name_lnm={"NOMINAL_reg1mtau1lnmtau1b3jos_1prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1lnmtau1mtau1b3jos_1prong_vetobtagwp70_highmet_leading_index_bin","NOMINAL_reg1mtau1lnmtau1b3jos_3prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1lnmtau1mtau1b3jos_3prong_vetobtagwp70_highmet_leading_index_bin","NOMINAL_reg1mtau1lnmtau1b2jos_1prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1lnmtau1mtau1b2jos_1prong_vetobtagwp70_highmet_leading_index_bin","NOMINAL_reg1mtau1lnmtau1b2jos_3prong_vetobtagwp70_highmet_subleading_index_bin",
     "NOMINAL_reg1lnmtau1mtau1b2jos_3prong_vetobtagwp70_highmet_leading_index_bin"};


    // nm=1 or lnm=2
    int category_(*argv[1]-'0');
    std::cout<<"category_: "<<category_<<std::endl;

    if(category_==1){
      total_1p_numerator_sample_name=total_1p_numerator_sample_name_nm;
      total_1p_denominator_sample_name=total_1p_denominator_sample_name_nm;
    }else if(category_==2){
      total_1p_numerator_sample_name=total_1p_numerator_sample_name_nm;// numerator are same between lnm and nm
      total_1p_denominator_sample_name=total_1p_denominator_sample_name_lnm;
    }else{
      std::cout<<"you input a wrong FF category!please input 1(for nm) or 2(for lnm)"<<std::endl;
      exit(0);
    }
    
    // data part
    for(int i=0;i<data_sample_name.size();i++){

        TString histFileName=readthefile+data_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");

        // numerator
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"data_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("data_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0)total_1p_numerator=htmp;
          else total_1p_numerator->Add(htmp);
          if(i==0) total_1p_numerator->SetDirectory(0);
        }

        // denominator
        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"data_"+total_1p_denominator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("data_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0)total_1p_denominator=htmp;
          else total_1p_denominator->Add(htmp);
          if(i==0) total_1p_denominator->SetDirectory(0);
        }     
        histFile->Close();
    }

    // bkg need to be subtracted
    for(int i=0;i<bkgsample.size();i++){
      for (int icamp = 0; icamp < 3;icamp++)
      {
        TString histFileName=readthefile+compaign[icamp]+"_"+(bkgsample.at(i)).name+suffix;
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");

        // numerator
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<(bkgsample.at(i)).name+"_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(((bkgsample.at(i)).name+"_real_"+total_1p_numerator_sample_name.at(j)).Data());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0)total_1p_numerator=htmp;
          else total_1p_numerator->Add(htmp,-1);
          if(icamp==0) total_1p_numerator->SetDirectory(0);
        }
        // denominator
        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<(bkgsample.at(i)).name+"_real_"+total_1p_denominator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(((bkgsample.at(i)).name+"_real_"+total_1p_denominator_sample_name.at(j)).Data());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0)total_1p_denominator=htmp;
          else total_1p_denominator->Add(htmp,-1);
          if(icamp==0) total_1p_denominator->SetDirectory(0);
        }  
        histFile->Close();
      }// end of compaign
    }

  TH1D* outhist1p=(TH1D*)total_1p_numerator->Clone("outhist1p");
  outhist1p->Reset();

  // fill hist
  for(int i=0;i<total_1p_numerator->GetNbinsX();i++){
    std::cout<<"filling the ouput FF hist"<<std::endl;
    observable   numerator(total_1p_numerator->GetBinContent(i+1),total_1p_numerator->GetBinError(i+1));
    observable denominator(total_1p_denominator->GetBinContent(i+1),total_1p_denominator->GetBinError(i+1));
    outhist1p->SetBinContent(i+1,(numerator/denominator).nominal);
    outhist1p->SetBinError(i+1,(numerator/denominator).error);
  }

  TFile *outputfile=new TFile((std::string(PACKAGE_DIR)+"/FF_sideband_"+(category_==1?"nm":"lnm")+".root").c_str(),"recreate");
  outputfile->cd();
  outhist1p->Write();
  outputfile->Close();

  return 0;
}