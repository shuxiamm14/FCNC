#include "common.h"
#include <sstream>

std::vector<sample> getBkgSamples(TString framework){
	std::vector<sample> samples;
	samples.push_back(sample("smhiggs","SM Higgs",kViolet));
	samples.push_back(sample("wjet","W+jets",kOrange));
	samples.push_back(sample("diboson","Diboson",(enum EColor)7));
	samples.push_back(sample("zll","Z#rightarrowll",kBlue));
	samples.push_back(sample("ztautau","Z#rightarrow#tau#tau",kGreen));
	if(framework=="tthML"){
		//samples.push_back(sample("top","Top rare",kWhite));
		samples.push_back(sample("others","Rare",kMagenta));
		samples.push_back(sample("ttbar","t#bar{t}",kYellow));
		samples.push_back(sample("ttV","t#bar{t}V",kAzure));
	}else{
		samples.push_back(sample("top","Top production",kYellow));
	}
	//samples.push_back(sample("othertop","Top rare",kWhite));
	//samples.push_back(sample("others","Rare",kTeal));
	//samples.push_back(sample("ttbar","t#bar{t}",kYellow));
	//samples.push_back(sample("ttV","t#bar{t}V",kAzure));
	return samples;
}

std::vector<sample> getSigSamples(TString framework, float BRbenchmark){
	std::vector<sample> samples;
	std::stringstream ss;
	ss<<"(BR=" << BRbenchmark << "%)";
	TString tmp;
	ss>>tmp;
	double signorm = BRbenchmark*(framework == "xTFW"? 1:5);
	samples.push_back(sample("fcnc_ch","#bar{t}t#rightarrowbWcH"+tmp,kRed,signorm));
	samples.push_back(sample("fcnc_prod_ch","cg#rightarrowtH"+tmp,kRed,signorm));
	samples.push_back(sample("tcH","tcH merged signal"+tmp,kRed,signorm));
	samples.push_back(sample("fcnc_uh","#bar{t}t#rightarrowbWuH"+tmp,kRed,signorm));
	samples.push_back(sample("fcnc_prod_uh","ug#rightarrowtH"+tmp,kRed,signorm));
	samples.push_back(sample("tuH","tuH merged signal"+tmp,kRed,signorm));
	return samples;
}