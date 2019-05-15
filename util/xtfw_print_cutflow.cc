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
	map<TString, map<TString, float>> weightedcutflow; //	sample, cut, event number
	map<TString, float> xsecs;
	map<TString, float> AODevents;
	map<TString, float> DAODevents;
	vector<TString> cuts;
	vector<TString> samples;
	int count = 0;

	float luminosity[3];
	luminosity[0] = 3.219555072 + 32.988125184;
	luminosity[1] = 44.30739456;
	luminosity[2] = 59.93723904;

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

	map<int, float> dsxsecs;

	ifstream xsecfile(TString(PACKAGE_DIR) + "/config/Xsecs.txt");
	while(!xsecfile.eof()){
		xsecfile.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		int dsid;
		float filtereff, xsec, kfactor;
		sscanf(inputline,"%d %f %f %f", &dsid, &filtereff, &xsec, &kfactor);
		dsxsecs[dsid] = filtereff*xsec*1000000*kfactor;
	}

	ifstream AODeventfile(TString(PACKAGE_DIR) + "/config/AODeventnumber.txt");
	while(!AODeventfile.eof()){
		AODeventfile.getline(inputline,500);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		char samplename[200];
		int nAOD,nDAOD;
		sscanf(inputline,"%s %d %d", samplename, &nAOD, &nDAOD);
		AODevents[samplename] = nAOD;
		DAODevents[samplename] = nDAOD;
	}
	
	samples.push_back("data");
	for(auto sample: samples){
		for (int j = 0; j < 3; ++j)
		{
			if(runcampaign != 0 && j != runcampaign -1 ) continue;
			count ++;
			TFile treefile(sample=="data"? prefix + campaigndata[j] + "_tree.root" : prefix + campaign[j] + "_" + TString(sample) + "_tree.root");
			TH1D *hcutflow = (TH1D*) treefile.Get("cutflow_HSM_common");
			for (int i = 1; i <= hcutflow->GetNbinsX(); ++i)
			{
				cutflow[sample][hcutflow->GetXaxis()->GetBinLabel(i)] += hcutflow->GetBinContent(i)/(sample=="data"?1:87);
				if(count == 1) cuts.push_back(hcutflow->GetXaxis()->GetBinLabel(i));
			}
		}
		if(sample=="data") continue;
		ifstream sampledsidfile(datafilesdir + sample + ".txt");
		while(!sampledsidfile.eof()){
			sampledsidfile.getline(inputline,500);
			if(strlen(inputline)==0) continue;
			if(inputline[0]=='#') continue;
			int dsid;
			sscanf(inputline,"%d", &dsid);
			xsecs[sample] += dsxsecs[dsid];
		}
	}

	printf("cut");

	for(auto sample: samples)
		printf("\t%s", sample.Data());
	printf("\n");

	printf("AOD");
	for(auto sample: samples)
		printf("\t%d", int(AODevents[sample]));
	printf("\n");

	printf("DAOD");
	for(auto sample: samples)
		printf("\t%d", int(DAODevents[sample]));
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
			printf("\t%d", int(round(cutflow[sample][iter])));
		printf("\n");
	}

	printf("\n\nWeighted:\n");

	printf("cut");
	for(auto sample: samples)
		printf("\t%s", sample.Data());
	printf("\n");

	printf("weighted total events:");
	for(auto sample: samples)
		printf("\t%ld", long(round(xsecs[sample]*(runcampaign == 0? luminosity[0] + luminosity[1] + luminosity[2] : luminosity[runcampaign-1]))));
	printf("\n");

	printf("DAOD");
	for(auto sample: samples){
		if(sample == "data") continue;
		printf("\t%d", int(DAODevents[sample]/AODevents[sample]*(xsecs[sample]*(runcampaign == 0? luminosity[0] + luminosity[1] + luminosity[2] : luminosity[runcampaign-1]))));
	}
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
		for(auto sample: samples){
			if(sample == "data")
				printf("\t%d", int(cutflow[sample][iter]));
			else
				printf("\t%f", cutflow[sample][iter]/AODevents[sample]*(xsecs[sample]*(runcampaign == 0? luminosity[0] + luminosity[1] + luminosity[2] : luminosity[runcampaign-1])));
		}
		printf("\n");
	}
	return 0;
}