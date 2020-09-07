#include "LatexChart.h"
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
	vector<TString> signals = {
		"GHH300X",
		"GHH300Y",
		"GHH3f600f0",
		"GHH3fm600f0",
		"GHH3f350f2100",
		"GHH3fm350f2100",
		"GHH3fm350fm2100",
		"GHH3f350fm2100",
		"GHH3f0f3000",
		"GHH3f0fm3000",
		"GHH600X",
		"GHH600Y",
		"GHH6f650f0",
		"GHH6fm650f0",
		"GHH6f400f2400",
		"GHH6fm400f2400",
		"GHH6fm400fm2400",
		"GHH6f400fm2400",
		"GHH6f0f3500",
		"GHH6f0fm3500",
		"GHH900X",
		"GHH9f800f0",
		"GHH9fm800f0",
		"GHH9f600f3600",
		"GHH9fm600f3600",
		"GHH9fm600fm3600",
		"GHH9f600fm3600",
		"GHH9f0f5000",
		"GHH9f0fm5000"
	};
	vector<TString> signalstitle = signals;
	vector<TString> channels = {"3l","ss2l"};
	vector<TString> channelstitle = {"3l","ss2l"};
	vector<TString> channelsjob = {"3l_Reg3lMhh", "ss2l_Meff"};
	LatexChart *chart = new LatexChart("limit");
	for (int isig = 0; isig < signals.size(); ++isig)
	{
		for (int ichan = 0; ichan < channels.size(); ++ichan)
		{
			TString filename=signals[isig] + "/Fit" + channelsjob[ichan] + "/Limits/asymptotics/myLimit_BLIND_CL95.root";
			setlimit(chart, filename, signalstitle[isig].Data(), channelstitle[ichan].Data());
		}
		TString filename=signals[isig] + "/combined/Limits/asymptotics/myLimit_CL95.root";
		setlimit(chart, filename, signalstitle[isig].Data(), "Combined");
	}
	chart->caption="The limits derived from leptonic channels.";
	chart->print("limits");
	return 0;
}
