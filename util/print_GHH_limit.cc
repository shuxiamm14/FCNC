#include "LatexChart.h"
#include "common.h"
#include "fcnc_include.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
using namespace std;

void setlimit(LatexChart *chart, TString filename, string row, string column){
	TFile thefile(filename);
	if(thefile.IsZombie()) return;
	TTree *thetree = (TTree*) thefile.Get("stats");
	float exp_upperlimit,exp_upperlimit_plus1,exp_upperlimit_minus1;
	//TBranch *b_exp_upperlimit,*b_exp_upperlimit_plus1,*b_exp_upperlimit_minus1;
	thetree->SetBranchAddress("exp_upperlimit",&exp_upperlimit);
	thetree->SetBranchAddress("exp_upperlimit_plus1",&exp_upperlimit_plus1);
	thetree->SetBranchAddress("exp_upperlimit_minus1",&exp_upperlimit_minus1);
	thetree->GetEntry(0);
	observable limit;
	limit.nominal = exp_upperlimit;
	limit.error = exp_upperlimit_plus1-exp_upperlimit;
	limit.errordown = exp_upperlimit-exp_upperlimit_minus1;
	//printf("chart->set(%f,%f,%f)\n", thehist->GetBinContent(2),thehist->GetBinContent(4)-thehist->GetBinContent(2),thehist->GetBinContent(2)-thehist->GetBinContent(5));
	chart->set(row,column,limit);
}

int main(int argc, char const *argv[])
{
	auto signals = getSigSamples("tthML",0.2);
	TString variable = "BDTG_test";
	vector<TString> channels = {"reg1l1tau1b2j_os","reg1l1tau1b3j_os","reg1l2tau1bnj_os"};

	LatexChart *chart = new LatexChart("limit");
	for (int isig = 0; isig < signals.size(); ++isig)
	{
		string signaltitle = signals[isig].title.Data();
		if(signaltitle.find("#") != string::npos) signaltitle = "$" + signaltitle + "$";
		findAndReplaceAll(signaltitle,"#","\\");
		findAndReplaceAll(signaltitle,"rightarrow","to ");
		for (int ichan = 0; ichan < channels.size(); ++ichan)
		{
			TString filename=signals[isig].name + "/" + channels[ichan] + "_" + variable + "/Limits/asymptotics/myLimit_CL95.root";
			string regtitle = channels[ichan].Data();
			translateRegion(regtitle);
			setlimit(chart, filename, signaltitle, regtitle);
		}
		TString filename=signals[isig].name + "/combined_" + variable + "/Limits/asymptotics/myLimit_CL95.root";
		setlimit(chart, filename, signaltitle, "Combined");
	}
	chart->caption="The limits derived from leptonic channels.";
	chart->print("limits");
	return 0;
}
