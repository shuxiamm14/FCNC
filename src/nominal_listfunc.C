#include "nominal.h"
#include "TH2F.h"

TH2F* nominal::prob_20_40 = 0;
TH2F* nominal::prob_40_60 = 0;
TH2F* nominal::prob_60_80 = 0;
TH2F* nominal::prob_80_100 = 0;
TH2F* nominal::prob_100_120 = 0;
TH2F* nominal::prob_120_140 = 0;
TH2F* nominal::prob_140_160 = 0;
TH2F* nominal::prob_160_200 = 0;
TH2F* nominal::prob_200_300 = 0;
TH2F* nominal::prob_300_400 = 0;
TH2F* nominal::prob_400 = 0;

Float_t nominal::getLepTauProb(Float_t _dR, Float_t _minv, Float_t _p) {
  if(!prob_20_40 ||
     !prob_40_60 ||
     !prob_60_80 ||
     !prob_80_100 ||
     !prob_100_120 ||
     !prob_120_140 ||
     !prob_140_160 ||
     !prob_160_200 ||
     !prob_200_300 ||
     !prob_300_400 ||
     !prob_400) {
    printf("Error: prob_xx_xx empty.\n");
    return 0;
  }
  
  TH2F* prob1(0);
  TH2F* prob2(0);
  Float_t fr1 = 0.5;

  if(_p<35) prob1 = prob2 = prob_20_40;
  else if(_p<45) {
    prob1 = prob_20_40;
    prob2 = prob_40_60;
    fr1 = (45-_p)/(45-35);
  }
  else if(_p<55) prob1 = prob2 = prob_40_60;
  else if(_p<65) {
    prob1 = prob_40_60;
    prob2 = prob_60_80;
    fr1 = (65-_p)/(65-55);
  }
  else if(_p<75) prob1 = prob2 = prob_60_80;
  else if(_p<85) {
    prob1 = prob_60_80;
    prob2 = prob_80_100;
    fr1 = (85-_p)/(85-75);
  }
  else if(_p<95) prob1 = prob2 = prob_80_100;
  else if(_p<105) {
    prob1 = prob_80_100;
    prob2 = prob_100_120;
    fr1 = (105-_p)/(105-95);
  }
  else if(_p<115) prob1 = prob2 = prob_100_120;
  else if(_p<125) {
    prob1 = prob_100_120;
    prob2 = prob_120_140;
    fr1 = (125-_p)/(125-115);
  }
  else if(_p<135) prob1 = prob2 = prob_120_140;
  else if(_p<145) {
    prob1 = prob_120_140;
    prob2 = prob_140_160;
    fr1 = (145-_p)/(145-135);
  }
  else if(_p<155) prob1 = prob2 = prob_140_160;
  else if(_p<165) {
    prob1 = prob_140_160;
    prob2 = prob_160_200;
    fr1 = (165-_p)/(165-155);
  }
  else if(_p<195) prob1 = prob2 = prob_160_200;
  else if(_p<220) {
    prob1 = prob_160_200;
    prob2 = prob_200_300;
    fr1 = (220-_p)/(220-195);
  }
  else if(_p<280) prob1 = prob2 = prob_200_300;
  else if(_p<330) {
    prob1 = prob_200_300;
    prob2 = prob_300_400;
    fr1 = (330-_p)/(330-280);
  }
  else if(_p<380) prob1 = prob2 = prob_300_400;
  else if(_p<430) {
    prob1 = prob_300_400;
    prob2 = prob_400;
    fr1 = (430-_p)/(430-380);
  }
  else prob1 = prob2 = prob_400;

  Float_t val = 0;
  if(_minv<prob2->GetXaxis()->GetXmax() && _dR<prob2->GetYaxis()->GetXmax()) {
    //val = fr1*prob1->GetBinContent(prob1->FindBin(_minv,_dR)) + (1-fr1)*prob2->GetBinContent(prob2->FindBin(_minv,_dR));
    val = fr1*eval(_minv,_dR,prob1) + (1-fr1)*eval(_minv,_dR,prob2);
  }
  else if(_minv<prob1->GetXaxis()->GetXmax() && _dR<prob1->GetYaxis()->GetXmax()) {
    //val = fr1*prob1->GetBinContent(prob1->FindBin(_minv,_dR));
    val = fr1*eval(_minv,_dR,prob1);
  }
  return val;
}

Float_t nominal::eval(const Float_t x, const Float_t y, const TH2F* h) {
  Int_t nx = h->GetNbinsX();
  Int_t ny = h->GetNbinsY();
  Int_t bx = h->GetXaxis()->FindBin(x);
  Int_t by = h->GetYaxis()->FindBin(y);
  if(bx<1 || bx>nx || by<1 || by>ny) return 0;

  std::pair<Float_t,Float_t> c1;
  std::pair<Float_t,Float_t> c2;
  std::pair<Float_t,Float_t> c3;
  std::pair<Float_t,Float_t> c4;
  Float_t z1(0), z2(0), z3(0), z4(0);
  std::pair<Float_t,Float_t> c(h->GetXaxis()->GetBinCenter(bx),h->GetYaxis()->GetBinCenter(by));

  if(x<c.first && y<c.second) {
    c1.first  = h->GetXaxis()->GetBinCenter(bx-1);
    c1.second = h->GetYaxis()->GetBinCenter(by-1);
    z1 = h->GetBinContent(bx-1,by-1);
    c2.first  = h->GetXaxis()->GetBinCenter(bx);
    c2.second = h->GetYaxis()->GetBinCenter(by-1);
    z2 = h->GetBinContent(bx,by-1);
    c3.first  = h->GetXaxis()->GetBinCenter(bx);
    c3.second = h->GetYaxis()->GetBinCenter(by);
    z3 = h->GetBinContent(bx,by);
    c4.first  = h->GetXaxis()->GetBinCenter(bx-1);
    c4.second = h->GetYaxis()->GetBinCenter(by);
    z4 = h->GetBinContent(bx-1,by);
  }
  else if(x>=c.first && y<c.second) {
    c1.first  = h->GetXaxis()->GetBinCenter(bx);
    c1.second = h->GetYaxis()->GetBinCenter(by-1);
    z1 = h->GetBinContent(bx,by-1);
    c2.first  = h->GetXaxis()->GetBinCenter(bx+1);
    c2.second = h->GetYaxis()->GetBinCenter(by-1);
    z2 = h->GetBinContent(bx+1,by-1);
    c3.first  = h->GetXaxis()->GetBinCenter(bx+1);
    c3.second = h->GetYaxis()->GetBinCenter(by);
    z3 = h->GetBinContent(bx+1,by);
    c4.first  = h->GetXaxis()->GetBinCenter(bx);
    c4.second = h->GetYaxis()->GetBinCenter(by);
    z4 = h->GetBinContent(bx,by);
  }
  else if(x<c.first && y>=c.second) {
    c1.first  = h->GetXaxis()->GetBinCenter(bx-1);
    c1.second = h->GetYaxis()->GetBinCenter(by);
    z1 = h->GetBinContent(bx-1,by);
    c2.first  = h->GetXaxis()->GetBinCenter(bx);
    c2.second = h->GetYaxis()->GetBinCenter(by);
    z2 = h->GetBinContent(bx,by);
    c3.first  = h->GetXaxis()->GetBinCenter(bx);
    c3.second = h->GetYaxis()->GetBinCenter(by+1);
    z3 = h->GetBinContent(bx,by+1);
    c4.first  = h->GetXaxis()->GetBinCenter(bx-1);
    c4.second = h->GetYaxis()->GetBinCenter(by+1);
    z4 = h->GetBinContent(bx-1,by+1);
  }
  else if(x>=c.first && y>=c.second) {
    c1.first  = h->GetXaxis()->GetBinCenter(bx);
    c1.second = h->GetYaxis()->GetBinCenter(by);
    z1 = h->GetBinContent(bx,by);
    c2.first  = h->GetXaxis()->GetBinCenter(bx+1);
    c2.second = h->GetYaxis()->GetBinCenter(by);
    z2 = h->GetBinContent(bx+1,by);
    c3.first  = h->GetXaxis()->GetBinCenter(bx+1);
    c3.second = h->GetYaxis()->GetBinCenter(by+1);
    z3 = h->GetBinContent(bx+1,by+1);
    c4.first  = h->GetXaxis()->GetBinCenter(bx);
    c4.second = h->GetYaxis()->GetBinCenter(by+1);
    z4 = h->GetBinContent(bx,by+1);
  }
  Float_t a = (x-c1.first)/(c2.first-c1.first);
  Float_t b = (y-c1.second)/(c4.second-c1.second);
  return (1-a)*(1-b)*z1 + (1-a)*b*z4 + a*(1-b)*z2 + a*b*z3;
}
