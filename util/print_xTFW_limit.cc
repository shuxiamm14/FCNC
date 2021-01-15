#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
using namespace std;

void setlimit(LatexChart *chart, TString filename, string row, string column){
	TFile thefile(filename);
	if(thefile.IsZombie()) return;
	TTree *thetree = (TTree*) thefile.Get("stats");
	float exp_upperlimit,exp_upperlimit_plus1,exp_upperlimit_minus1;
	thetree->SetBranchAddress("exp_upperlimit",&exp_upperlimit);
	thetree->SetBranchAddress("exp_upperlimit_plus1",&exp_upperlimit_plus1);
	thetree->SetBranchAddress("exp_upperlimit_minus1",&exp_upperlimit_minus1);
	thetree->GetEntry(0);
	observable limit;
	limit.nominal = exp_upperlimit;
	limit.error = exp_upperlimit_plus1-exp_upperlimit;
	limit.errordown = exp_upperlimit-exp_upperlimit_minus1;
	chart->set(row,column,limit);
}

int main(int argc, char const *argv[])
{
	TString variable = "BDTG_test";
	auto sigsample = getSigSamples("xTFW",0.2);
	vector<TString> channels = {"reg2mtau1b2jos_vetobtagwp70_highmet","reg2mtau1b3jos_vetobtagwp70_highmet"};
	vector<TString> channelstitle = {"STH $\\thadhad$", "TTH $\\thadhad$"};
	string framework = "xTFW";
	LatexChart *chart = new LatexChart("limit");
	for (int isig = 0; isig < sigsample.size(); ++isig)
	{
		string samptitle=sigsample[isig].title.Data();
		if(samptitle.find("#")!=string::npos) samptitle = "$" + samptitle + "$";
		findAndReplaceAll(samptitle,"rightarrow","to ");
		findAndReplaceAll(samptitle,"#","\\");
		for (int ichan = 0; ichan < channels.size(); ++ichan)
		{
			TString jobname = sigsample[isig].name + "/" + channels[ichan] + "_" + variable;
			setlimit(chart, jobname + "/Limits/asymptotics/myLimit_BLIND_CL95.root", samptitle, channelstitle[ichan].Data());
		}
		TString jobname = sigsample[isig].name + "/combined" + "_" + variable;
		setlimit(chart, jobname + "/Limits/asymptotics/myLimit_BLIND_CL95.root", samptitle, "Combined");
	}
	chart->caption="The limits derived from hadronic channels.";
	chart->print(string(TABLE_DIR)+"/" + framework + "/limits");
	return 0;
}