
#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
using namespace std;


void setFF(LatexChart *chart, TH1D* ff_, string row, string column, int row_,int column_,bool _1p){ // row:eta1 eta2          column:pt1,pt2,pt3
  
  /*
        pt1      pt2     pt3
  eta1  xxx      xxx     xxx
  eta2  xxx      xxx     xxx
  */

  observable fakefactor;
  if(_1p){
    fakefactor.nominal =ff_->GetBinContent(row_==1?column_:column_+3);
    fakefactor.error   =ff_->GetBinError(row_==1?column_:column_+3);
    //std::cout<<"nominal: "<<fakefactor.nominal<<",error: "<<fakefactor.error<<std::endl;
    chart->set(row,column,fakefactor);
  }else{//3p
    fakefactor.nominal =ff_->GetBinContent(row_==1?column_+6:column_+9);
    fakefactor.error   =ff_->GetBinError(row_==1?column_+6:column_+9);
    //std::cout<<"nominal: "<<fakefactor.nominal<<",error: "<<fakefactor.error<<std::endl;
    chart->set(row,column,fakefactor);
  }
}

int main(int argc, char const *argv[])
{
LatexChart*  chart[9];

TFile*   histFile =0; 
TH1D*    FF[4]; // ss_nm ss_lnm sb_nm sb_lnm

TString  readthefile=TString(PACKAGE_DIR)+"/ff_ss/";

string column_name[4]={"","P_{T}\\in (30,40)","P_{T}\\in (40,60)","P_{T}\\in (60,500)"}; 
string row_name[3]={"","\\lvert \\eta \\rvert \\leq 1.37","\\lvert \\eta \\rvert \\geq 1.52"}; 

// need to consistent
std::vector<TString> ff_name={"","FF_ss_nm.root ","FF_sideband_nm.root","FF_ss_lnm.root ","FF_sideband_lnm.root"};
std::string chart_name[9]={"","FF_ss_nm_1p","FF_sideband_nm_1p","FF_ss_lnm_1p ","FF_sideband_lnm_1p","FF_ss_nm_3p","FF_sideband_nm_3p","FF_ss_lnm_3p ","FF_sideband_lnm_3p"};

for(int item=1;item<9;item++){
   chart[item]  =new  LatexChart(chart_name[item]);
}

for(int item=1;item<ff_name.size();item++){
  
  TH1D *htmp;
  histFile=TFile::Open((readthefile+ff_name.at(item)).Data(),"READ");
  htmp=(TH1D*)histFile->Get("outhist1p");
  if(htmp) FF[item]=(TH1D*)htmp->Clone(Form("ff_%i",item));
  else{
    std::cout<<"hist doesnt exit!"<<std::endl;
  }
  FF[item]->SetDirectory(0);
  histFile->Close();

  //fill table
  for (int i = 1; i < 3; ++i) // row
  {
    for (int j = 1; j < 4; ++j) //column
    {
      setFF(chart[item],FF[item],row_name[i],column_name[j],i,j,1); //1p
      setFF(chart[item+4],FF[item],row_name[i],column_name[j],i,j,0);//3p
    }
  }

  if(item<=2){
    if(item==1){
      chart[item]->caption   ="The nm 1p fake-factors in same sign region derived from hadronic channels.";
      chart[4+item]->caption ="The nm 3p fake-factors in same sign region derived from hadronic channels.";
    }else{
      chart[item]->caption   ="The nm 1p fake-factors in side band region derived from hadronic channels.";
      chart[4+item]->caption ="The nm 3p fake-factors in side band region derived from hadronic channels.";
    }
  }else{
     if(item==3){
      chart[item]->caption   ="The lnm 1p fake-factors in same sign region derived from hadronic channels.";
      chart[4+item]->caption ="The lnm 3p fake-factors in same sign region derived from hadronic channels.";
    }else{
      chart[item]->caption   ="The lnm 1p fake-factors in side band region derived from hadronic channels.";
      chart[4+item]->caption ="The lnm 3p fake-factors in side band region derived from hadronic channels.";
    }
  }
}
for(int index=1;index<9;index++){
  chart[index]->print("ff_"+chart_name[index]);
}
return 0;
}
