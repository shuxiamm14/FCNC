#include <iostream>
#include <map>
#include <vector>
#include "TString.h"
#include "histSaver.h"
#define FITSTRATEGY 2   //1 merge SS and OS. 2 split SS and OS, single fit. 3 split SS and OS, two fits.
const std::vector<double> fakePtSlices = {25,35,45,125};

const TString SFfilename = TString(PACKAGE_DIR) + "/data/" + "scale_factors";

std::vector<fcncSample> getFakeTauOrigin();

std::vector<fcncSample> getFakeLepOrigin();
#if FITSTRATEGY==1
const std::vector<TString> SForigins = {"wjet-fake","bjet-fake","other-fake"};
#else
const std::vector<TString> SForigins = {"wjet-fake_os","wjet-fake_ss","bjet-fake","other-fake"};
#endif
const std::map<TString,std::vector<double>> XsecErr = {
	{"ztautau",{0.022,-0.029}},
	{"ttbar",{0.023768876,-0.035106281}}
};

const std::vector<TString> mc_campaigns = {"mc16a", "mc16d", "mc16e"};
const std::vector<TString> data_campaigns = {"data1516", "data17", "data18"};
const std::map<TString,std::vector<TString>> signalmap = {
	{"tcH",{"fcnc_ch_lv","fcnc_ch_qq","fcnc_prod_ch"}},
	{"tuH",{"fcnc_uh_lv","fcnc_uh_qq","fcnc_prod_uh"}},
	{"fcnc_ch",{"fcnc_ch_lv","fcnc_ch_qq"}},
	{"fcnc_uh",{"fcnc_uh_lv","fcnc_uh_qq"}},
	{"fcnc_prod_ch",{"fcnc_prod_ch"}},
	{"fcnc_prod_uh",{"fcnc_prod_uh"}},
};

void translateRegion(std::string &regtitle);

TString translateRegion(TString &regtitle);

std::vector<fcncSample> getBkgSamples(TString framework);

std::vector<fcncSample> getSigSamples(TString framework, float BRbenchmark);

std::map<TString,variable*> getVariables(TString framework);