#include "common.h"
#include "fcnc_include.h"
#include <sstream>

std::vector<sample> getBkgSamples(TString framework){
	std::vector<sample> samples;
	samples.emplace_back("smhiggs","SM Higgs",kViolet);
	samples.emplace_back("wjet","W+jets",kOrange);
	samples.emplace_back("diboson","Diboson",(enum EColor)7);
	samples.emplace_back("zll","Z#rightarrowll",kBlue);
	samples.emplace_back("ztautau","Z#rightarrow#tau#tau",kGreen);
	if(framework=="tthML"){
		//samples.push_back(sample("top","Top rare",kWhite));
		samples.emplace_back("others","Rare",kMagenta);
		samples.emplace_back("ttbar","t#bar{t}",kYellow);
		samples.emplace_back("ttV","t#bar{t}V",(enum EColor)((kAzure)+1));
	}else{
		samples.emplace_back("top","Top production",kYellow);
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
	samples.emplace_back("fcnc_ch","#bar{t}t#rightarrowbWcH"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_prod_ch","cg#rightarrowtH"+tmp,kRed,signorm);
	samples.emplace_back("tcH","tcH merged signal"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_uh","#bar{t}t#rightarrowbWuH"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_prod_uh","ug#rightarrowtH"+tmp,kRed,signorm);
	samples.emplace_back("tuH","tuH merged signal"+tmp,kRed,signorm);
	return samples;
}
void translateRegion(std::string &regtitle){
	findAndReplaceAll(regtitle,"reg1l1tau1b3j_","TTH~$\\tlhad$~");
	findAndReplaceAll(regtitle,"reg1l1tau1b2j_","STH~$\\tlhad$~");
	findAndReplaceAll(regtitle,"reg1l1tau2b3j_","TTH~$\\tlhad$~2b~");
	findAndReplaceAll(regtitle,"reg1l1tau2b2j_","STH~$\\tlhad$~2b~");
	findAndReplaceAll(regtitle,"reg1l2tau1bnj_","$l\\thadhad$~");
	findAndReplaceAll(regtitle,"reg1l2tau2bnj_","$l\\thadhad$~2b~");
	findAndReplaceAll(regtitle,"_","~");
}