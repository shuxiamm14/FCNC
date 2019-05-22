#include "fcnc_include.h"

int countDigit(float n) 
{ 
    int count = 0; 
    while (n >= 10) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

std::string ReplaceString(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("please use the script in script/getCutflow.sh\n");
	}
	int runcampaign = 1;
	TString campaign[3] = {"mc16a","mc16d","mc16e"};
	TString campaigndata[3] = {"data1516","data17","data18"};
	TString prefix = TString(PACKAGE_DIR) + "/data/hadhadreduce1/";
	TString datafilesdir = TString(PACKAGE_DIR) + "/datafiles/xTFW/";

	map<TString, map<TString, float>> cutflow; //	sample, cut, event number
	map<TString, map<TString, float>> cutflowerr; //	sample, cut, event number
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
			TFile treefile(sample=="data"? prefix + campaigndata[j] + "_tree.root" : prefix + campaign[j] + "_" + sample + "_tree.root");
			TH1D *hcutflow = (TH1D*) treefile.Get(sample=="data"? "cutflow_HSM_common_raw" : argv[2]);
			for (int i = 1; i <= hcutflow->GetNbinsX(); ++i)
			{
				cutflow[sample][hcutflow->GetXaxis()->GetBinLabel(i)] += hcutflow->GetBinContent(i);
				cutflowerr[sample][hcutflow->GetXaxis()->GetBinLabel(i)] += hcutflow->GetBinError(i);
				if(count == 1) cuts.push_back(hcutflow->GetXaxis()->GetBinLabel(i));
			}
			if(count == 1) {
				cuts.push_back("n-tuple");
				cuts.push_back("trigger matching");
				cuts.push_back("n tracks = 1,3");
			
				cuts.push_back("2 medium OS tau");
				cuts.push_back("true taus");
				cuts.push_back("jet pt cut");
				cuts.push_back("bjet pt eta cut");
				cuts.push_back("tautau vis mass > 50");
				cuts.push_back("tautau vis mass < 130");
				cuts.push_back("drtautau > 3.4");
			}
			ifstream logfile1(prefix + "../../reduce1log/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt");
			printf("log file: %s\n", (prefix + "../../reduce1log/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt").Data());
			while(!logfile1.eof()){
				logfile1.getline(inputline,500);
				if(strlen(inputline)==0) continue;
				if(inputline[0]=='#') continue;
				float cutf[3], cutferr[3];
				sscanf(inputline,"%f +/- %f, %f +/- %f, %f +/- %f", &cutf[0], &cutferr[0], &cutf[1], &cutferr[1], &cutf[2], &cutferr[2]);
				cutflow[sample]["n-tuple"] += cutf[0];
				cutflowerr[sample]["n-tuple"] = sqrt(pow(cutflowerr[sample]["n-tuple"],2) + pow(cutferr[0],2));
				cutflow[sample]["trigger matching"] += cutf[1];
				cutflowerr[sample]["trigger matching"] = sqrt(pow(cutflowerr[sample]["trigger matching"],2) + pow(cutferr[1],2));
				cutflow[sample]["n tracks = 1,3"] += cutf[2];
				cutflowerr[sample]["n tracks = 1,3"] = sqrt(pow(cutflowerr[sample]["n tracks = 1,3"],2) + pow(cutferr[2],2));
			}
			ifstream logfile2(prefix + "../../reduce22jlog/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt");
			printf("log file: %s\n", (prefix + "../../reduce22jlog/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt").Data());
			while(!logfile2.eof()){
				logfile2.getline(inputline,500);
				if(strlen(inputline)==0) continue;
				if(inputline[0]=='#') continue;
				float cutf[7], cutferr[7];
				sscanf(inputline,"%f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f, %f +/- %f", &cutf[0], &cutferr[0], &cutf[1], &cutferr[1], &cutf[2], &cutferr[2], &cutf[3], &cutferr[3], &cutf[4], &cutferr[4], &cutf[5], &cutferr[5], &cutf[6], &cutferr[6]);
				cutflow[sample]["2 medium OS tau"] += cutf[0];
				cutflowerr[sample]["2 medium OS tau"] = sqrt(pow(cutflowerr[sample]["2 medium OS tau"],2) + pow(cutferr[0],2));
				cutflow[sample]["true taus"] += cutf[1];
				cutflowerr[sample]["true taus"] = sqrt(pow(cutflowerr[sample]["true taus"],2) + pow(cutferr[1],2));
				cutflow[sample]["jet pt cut"] += cutf[2];
				cutflowerr[sample]["jet pt cut"] = sqrt(pow(cutflowerr[sample]["jet pt cut"],2) + pow(cutferr[2],2));
				cutflow[sample]["bjet pt eta cut"] += cutf[3];
				cutflowerr[sample]["bjet pt eta cut"] = sqrt(pow(cutflowerr[sample]["bjet pt eta cut"],2) + pow(cutferr[3],2));
				cutflow[sample]["tautau vis mass > 50"] += cutf[4];
				cutflowerr[sample]["tautau vis mass > 50"] = sqrt(pow(cutflowerr[sample]["tautau vis mass > 50"],2) + pow(cutferr[4],2));
				cutflow[sample]["tautau vis mass < 130"] += cutf[5];
				cutflowerr[sample]["tautau vis mass < 130"] = sqrt(pow(cutflowerr[sample]["tautau vis mass < 130"],2) + pow(cutferr[5],2));
				cutflow[sample]["drtautau > 3.4"] += cutf[6];
				cutflowerr[sample]["drtautau > 3.4"] = sqrt(pow(cutflowerr[sample]["drtautau > 3.4"],2) + pow(cutferr[6],2));
			}
		}
	}

	for (int isep = 0; isep < 3; ++isep)
	{
		printf("\\hline\ncut");
		int isample = -1;
		for(auto sample: samples){
			isample++;
			if(isample % 3 != isep) continue;
			printf(" & %s", ReplaceString(string(sample),"_"," ").c_str());
		}
		printf("\\\\ \\hline\n");
		
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
			isample = -1;
			for(auto sample: samples){
				isample++;
				if(isample % 3 != isep) continue;
				int ndigit = countDigit(cutflow[sample][iter]);
				if(ndigit > 4) printf(" & $( %4.2f \\pm %4.2f ) \\times 10^{%d}$", cutflow[sample][iter]/pow(10,ndigit), cutflowerr[sample][iter]/pow(10,ndigit), ndigit);
				else printf(" & $%4.2f \\pm %4.2f$", cutflow[sample][iter], cutflowerr[sample][iter]);
			}
			printf("\\\\ \\hline\n");
		}
	}
}