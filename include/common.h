#include <iostream>
#include <map>
#include <vector>
#include "TString.h"
#include "histSaver.h"
const std::vector<double> fakePtSlices = {25,35,45,125};

const TString SFfilename = TString(PACKAGE_DIR) + "/data/" + "scale_factors.root";

const std::vector<TString> SForigins = {"wjet-fake","bjet-fake","other-fake"};

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

class fcncSample
{
public:
	fcncSample(TString _name, TString _title, enum EColor _color, double _norm = 1): name(_name), title(_title), color(_color), norm(_norm) {};
	~fcncSample(){};
	TString name;
	TString title;
	double norm;
	enum EColor color;
};

std::vector<fcncSample> getBkgSamples(TString framework);

std::vector<fcncSample> getSigSamples(TString framework, float BRbenchmark);

std::map<TString,variable*> getVariables(TString framework);