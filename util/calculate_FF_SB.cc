
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
    //auto bkgsample = getBkgSamples("xTFW");
    std::vector<std::string> ztautau_sample_name={"mc16a_ztautau_NOMINAL.root","mc16e_ztautau_NOMINAL.root","mc16d_ztautau_NOMINAL.root"};
    std::vector<std::string> top_sample_name={"mc16a_top_NOMINAL.root","mc16d_top_NOMINAL.root","mc16e_top_NOMINAL.root"};
    std::vector<std::string> data_sample_name={"data17_NOMINAL.root","data18_NOMINAL.root","data1516_NOMINAL.root"};
    std::vector<std::string> wjet_sample_name={"mc16a_wjet_NOMINAL.root","mc16e_wjet_NOMINAL.root","mc16d_wjet_NOMINAL.root"};
    std::vector<std::string> smhiggs_sample_name={"mc16a_smhiggs_NOMINAL.root","mc16e_smhiggs_NOMINAL.root","mc16d_smhiggs_NOMINAL.root"};
    std::vector<std::string> other_sample_name={"mc16a_other_NOMINAL.root","mc16e_other_NOMINAL.root","mc16d_other_NOMINAL.root"};
    std::vector<std::string> diboson_sample_name={"mc16a_diboson_NOMINAL.root","mc16e_diboson_NOMINAL.root","mc16d_diboson_NOMINAL.root"};
    std::vector<std::string> zll_sample_name={"mc16a_zll_NOMINAL.root","mc16e_zll_NOMINAL.root","mc16d_zll_NOMINAL.root"};

    TString  readthefile=TString(PACKAGE_DIR)+"/run/reduce3/NOMINAL/";
    TFile*   histFile =0; 
     

    TH1D *total_1p_numerator=0;
    TH1D *total_3p_numerator=0;
    TH1D *total_1p_denominator=0;
    TH1D *total_3p_denominator=0;
    
    std::vector<std::string> total_1p_numerator_sample_name;
    std::vector<std::string> total_1p_denominator_sample_name;

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
     int category_(*argv[1]-'0');
     std::cout<<"category_: "<<category_<<std::endl;
    if(category_==1){
      total_1p_numerator_sample_name=total_1p_numerator_sample_name_nm;
      total_1p_denominator_sample_name=total_1p_denominator_sample_name_nm;
    }else if(category_==2){
      total_1p_numerator_sample_name=total_1p_numerator_sample_name_nm;// numerator are same between lnm and nm
      total_1p_denominator_sample_name=total_1p_denominator_sample_name_lnm;
    }else{
      std::cout<<"you input a wrong FF category!"<<std::endl;
      exit(0);
    }

    for(int i=0;i<data_sample_name.size();i++){
        
        TString histFileName=readthefile+data_sample_name[i];
        //std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
      
        //std::cout<<"sample:"<<data_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          //std::cout<<"name:"<<"data_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("data_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          //std::cout<<htmp->GetNbinsX()<<std::endl;
          //if(i!=0) std::cout<<"nbins: "<<total_1p_numerator->GetNbinsX()<<",INTEGRAL: "<<total_1p_numerator->Integral()<<std::endl;
          if(total_1p_numerator==0)total_1p_numerator=htmp;
          else total_1p_numerator->Add(htmp);
          if(i==0) total_1p_numerator->SetDirectory(0);
          
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          //std::cout<<"name:"<<"data_"+total_1p_denominator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("data_"+total_1p_denominator_sample_name.at(j)).c_str())->Clone("tmp");
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          //std::cout<<htmp->GetNbinsX()<<std::endl;
          if(i!=0)std::cout<<"nbins: "<<total_1p_denominator->GetNbinsX()<<",INTEGRAL: "<<total_1p_denominator->Integral()<<std::endl;
          if(total_1p_denominator==0)total_1p_denominator=htmp;
          else total_1p_denominator->Add(htmp);
          if(i==0) total_1p_denominator->SetDirectory(0);
        }     
        histFile->Close();
    }
   
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;
  
    for(int i=0;i<top_sample_name.size();i++){
        TString histFileName=readthefile+top_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<top_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"top_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("top_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in top,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("top_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("top_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in top,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }

    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;

    for(int i=0;i<wjet_sample_name.size();i++){
        TString histFileName=readthefile+wjet_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<wjet_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"wjet_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("wjet_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in wjet,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("wjet_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("wjet_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in wjet,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;

    for(int i=0;i<diboson_sample_name.size();i++){
        TString histFileName=readthefile+diboson_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<diboson_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"diboson_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("diboson_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in wjet,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("diboson_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("diboson_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in diboson,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }
   
       std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;
     for(int i=0;i<other_sample_name.size();i++){
        TString histFileName=readthefile+other_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<other_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"other_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("other_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in other,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("other_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("other_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in other,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }

        std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;

     for(int i=0;i<smhiggs_sample_name.size();i++){
        TString histFileName=readthefile+smhiggs_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<smhiggs_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"smhiggs_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("smhiggs_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in smhiggs,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("smhiggs_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("smhiggs_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in smhiggs,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;

      for(int i=0;i<zll_sample_name.size();i++){
        TString histFileName=readthefile+zll_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<zll_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"zll_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("zll_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in zll,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("zll_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("zll_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in zll,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }

    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_denominator->Integral()<<std::endl;
    std::cout<<"==========================,INTEGRAL:================== "<<total_1p_numerator->Integral()<<std::endl;

     for(int i=0;i<ztautau_sample_name.size();i++){
        TString histFileName=readthefile+ztautau_sample_name[i];
        std::cout<<"open file: "<<histFileName<<std::endl;
        histFile=TFile::Open(histFileName.Data(),"READ");
         
        std::cout<<"sample:"<<ztautau_sample_name[i]<<std::endl;
        for(int j=0;j<total_1p_numerator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<"ztautau_real_"+total_1p_numerator_sample_name.at(j)<<std::endl;
          htmp=(TH1D*)histFile->Get(("ztautau_real_"+total_1p_numerator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_numerator==0){
            std::cout<<"total_1p_numerator is zero in ztautau,check!"<<std::endl;
            exit(0);
          }else total_1p_numerator->Add(htmp,-1);
        }

        for(int j=0;j<total_1p_denominator_sample_name.size();j++){
          TH1D* htmp;
          std::cout<<"name:"<<("ztautau_real_"+total_1p_denominator_sample_name.at(j))<<std::endl;
          htmp=(TH1D*)histFile->Get(("ztautau_real_"+total_1p_denominator_sample_name.at(j)).c_str());
          if(htmp) htmp = (TH1D*)htmp->Clone("tmp");
          else continue;
          if(total_1p_denominator==0){
            std::cout<<"total_1p_denominator is zero in ztautau,check!"<<std::endl;
            exit(0);
          }else total_1p_denominator->Add(htmp,-1); 
        }
      histFile->Close();
    }


  TH1D* outhist1p=(TH1D*)total_1p_numerator->Clone("outhist1p");
  outhist1p->Reset();


  
  for(int i=0;i<total_1p_numerator->GetNbinsX();i++){
    std::cout<<"------"<<std::endl;
    observable   numerator(total_1p_numerator->GetBinContent(i+1),total_1p_numerator->GetBinError(i+1));
    observable denominator(total_1p_denominator->GetBinContent(i+1),total_1p_denominator->GetBinError(i+1));
    outhist1p->SetBinContent(i+1,(numerator/denominator).nominal);
    outhist1p->SetBinError(i+1,(numerator/denominator).error);
  }

  TFile *outputfile=new TFile((std::string(PACKAGE_DIR)+"/FF_sideband_"+argv[1]+".root").c_str(),"recreate");
  outputfile->cd();
  outhist1p->Write();
  outputfile->Close();



  return 0;
}