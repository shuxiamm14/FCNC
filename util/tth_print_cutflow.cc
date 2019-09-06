#include "fcnc_include.h"
using namespace std;
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
	TString prefix = TString(PACKAGE_DIR);

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
		for (int j = 0; j < 2; ++j)
		{
			if(runcampaign != 0 && j != runcampaign -1 ) continue;
			count ++;
			if(count == 1) {
				cuts.push_back("n-tuple");
				cuts.push_back("basic selection");
				cuts.push_back("trigger matching, tight lepton, tau EleBDT MuOLR");
				cuts.push_back("weight > 2");
				cuts.push_back("veto b-tagged tau");
				cuts.push_back("M_lb<190GeV");
				cuts.push_back("M_tautau<125GeV");
				cuts.push_back("M_tautau>20GeV");
			}
			ifstream logfile1(prefix + "tthcutflow/reduce1/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt");
			printf("log file: %s\n", (prefix + "tthcutflow/reduce1/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt").Data());
			while(!logfile1.eof()){
				logfile1.getline(inputline,500);
				if(strlen(inputline)==0) continue;
				if(inputline[0]=='#') continue;
				float cutf[3], cutferr[3];
				sscanf(inputline,"%f +/- %f, %f +/- %f, %f +/- %f", &cutf[0], &cutferr[0], &cutf[1], &cutferr[1], &cutf[2], &cutferr[2]);
				for (int i = 0; i < 2; ++i)
				{
					cutflow[sample][cuts[i]] += cutf[i];
					cutflowerr[sample][cuts[i]] = sqrt(pow(cutflowerr[sample][cuts[i]],2) + pow(cutferr[i],2));
				}
			}
			ifstream logfile2(prefix + "tthcutflow/reduce2/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt");
			printf("log file: %s\n", (prefix + "tthcutflow/reduce2/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt").Data());
			while(!logfile2.eof()){
				logfile1.getline(inputline,500);
				if(strlen(inputline)==0) continue;
				if(inputline[0]=='#') continue;
				float cutf[3], cutferr[3];
				sscanf(inputline,"%f +/- %f, %f +/- %f, %f +/- %f", &cutf[0], &cutferr[0], &cutf[1], &cutferr[1], &cutf[2], &cutferr[2]);
				for (int i = 2; i < 5; ++i)
				{
					cutflow[sample][cuts[i]] += cutf[i];
					cutflowerr[sample][cuts[i]] = sqrt(pow(cutflowerr[sample][cuts[i]],2) + pow(cutferr[i],2));
				}
			}
			ifstream logfile3(prefix + "tthcutflow/reduce3/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt");
			printf("log file: %s\n", (prefix + "tthcutflow/reduce3/" + (sample=="data"? campaigndata[j] : campaign[j] + "_" + sample) + ".txt").Data());
			while(!logfile3.eof()){
				logfile1.getline(inputline,500);
				if(strlen(inputline)==0) continue;
				if(inputline[0]=='#') continue;
				float cutf[3], cutferr[3];
				sscanf(inputline,"%f +/- %f, %f +/- %f, %f +/- %f", &cutf[0], &cutferr[0], &cutf[1], &cutferr[1], &cutf[2], &cutferr[2]);
				for (int i = 5; i < 8; ++i)
				{
					cutflow[sample][cuts[i]] += cutf[i];
					cutflowerr[sample][cuts[i]] = sqrt(pow(cutflowerr[sample][cuts[i]],2) + pow(cutferr[i],2));
				}
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