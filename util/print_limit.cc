#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
using namespace std;

void setlimit(LatexChart *chart, TString filename, string row, string column){
	TFile thefile(filename);
	if(thefile.IsZombie()) return;
	TH1D *thehist = (TH1D*) thefile.Get("limit");
	printf("chart->set(%f,%f,%f)\n", thehist->GetBinContent(2),thehist->GetBinContent(4)-thehist->GetBinContent(2),thehist->GetBinContent(2)-thehist->GetBinContent(5));
	chart->set(row,column,thehist->GetBinContent(2),thehist->GetBinContent(4)-thehist->GetBinContent(2),thehist->GetBinContent(2)-thehist->GetBinContent(5));
}

int main(int argc, char const *argv[])
{
	TString variable = "BDTG_test";
	vector<TString> signals = {"uH","cH"};
	vector<TString> signalstitle = {"tuH","tcH"};
	vector<TString> channels = {"2j","3j","2tau"};
	vector<TString> channelstitle = {"STH $\\tlhad$", "TTH $\\tlhad$", "$l\\thadhad$"};
	LatexChart *chart = new LatexChart("limit");
	for (int isig = 0; isig < signals.size(); ++isig)
	{
		for (int ichan = 0; ichan < channels.size(); ++ichan)
		{
			TString jobname = variable + "_" + signals[isig] + "_" + channels[ichan];
			setlimit(chart, jobname + "/Limits/" + jobname + ".root", signalstitle[isig].Data(), channelstitle[ichan].Data());
		}
		TString jobname = variable + "_" + signals[isig];
		setlimit(chart, jobname + "/Limits/" + jobname + ".root", signalstitle[isig].Data(), "Combined");
	}
	chart->caption="The limits derived from leptonic channels.";
	chart->print("limits");
	return 0;
}