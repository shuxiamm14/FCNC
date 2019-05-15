#include "fcnc_include.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("please use the script in script/getCutflow.sh\n");
	}
	int runcampaign = 0;
	TString campaign[3] = {"mc16a","mc16d","mc16e"};
	TString campaigndata[3] = {"data1516","data17","data18"};
	TString prefix = TString(PACKAGE_DIR) + "/data/hadhadreduce1/";
	TString datafilesdir = TString(PACKAGE_DIR) + "/datafiles/xTFW/";
	map<TString, map<TString, float>> cutflow; //	sample, cut, event number
	vector<TString> cuts;
	vector<TString> samples;
	int count = 0;

	ifstream samplesfile(argv[1]);
	char inputline[500];
	while(!samplesfile.eof()){
		samplesfile.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		TString filename = inputline;
		filename.Remove(filename.Sizeof()-5,4);
		samples.push_back(filename);
	}

	samples.push_back("data");
	for(auto sample: samples){
		for (int j = 0; j < 3; ++j)
		{
			if(runcampaign != 0 && j != runcampaign -1 ) continue;
			count ++;
			TFile treefile(sample=="data"? prefix + campaigndata[j] + "_tree.root" : prefix + campaign[j] + "_" + TString(sample) + "_tree.root");
			TH1D *hcutflow = (TH1D*) treefile.Get(argv[2]);
			for (int i = 1; i <= hcutflow->GetNbinsX(); ++i)
			{
				cutflow[sample][hcutflow->GetXaxis()->GetBinLabel(i)] += hcutflow->GetBinContent(i);
				if(count == 1) cuts.push_back(hcutflow->GetXaxis()->GetBinLabel(i));
			}
		}
	}

	printf("cut");

	for(auto sample: samples)
		printf("\t%s", sample.Data());
	printf("\n");

	for(auto iter : cuts){
		if(iter == "Any Trigger") continue;
		if(iter == "Detector Cleaning") continue;
		if(iter == "Jet Cleaning") continue;
		if(iter == "Crazy Muon Veto") continue;
		if(iter == "NTaus cut") continue;
		if(iter == "NLep cut") continue;
		if(iter == "Trigger matching") continue;
		if(iter == "Tau nTracks cut") continue;
		if(iter == "Tau ID cut") continue;
		if(iter == "Veto 0-jet events") continue;
		if(iter == "Leading jet pT") continue;
		if(iter == "Di-tau dR cut") continue;
		if(iter == "Di-tau dEta cut") continue;
		if(iter == "Coll approx cuts") continue;
		printf("%s", iter == "All events" ? "skim" : iter.Data());
		for(auto sample: samples)
			printf("\t%ld", long(round(cutflow[sample][iter])));
		printf("\n");
	}
}