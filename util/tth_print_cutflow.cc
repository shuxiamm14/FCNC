#include "fcnc_include.h"
#include "common.h"
#include "makechart.h"
using namespace std;

int main(int argc, char const *argv[])
{
	//if (argc != 2)
	//{
	//	printf("start\n");
	//}
	TString framework = "tthML";
	vector<TString> region = {"all","reg1l1tau1b2j_os","reg1l1tau1b2j_ss"};
	float BR = 0.2;

	vector<sample> bkg_samples = getBkgSamples(framework);
	vector<sample> sig_samples = getSigSamples(framework,BR);
	vector<sample> samples = bkg_samples;
	samples.insert(samples.end(),sig_samples.begin(),sig_samples.end());

	for(auto &sample : samples){
		string samptitle = sample.title.Data();
		findAndReplaceAll(samptitle," ","~");
		if(samptitle.find("#") != string::npos) samptitle = "$"+samptitle+"$";
		findAndReplaceAll(samptitle,"#","\\");
		findAndReplaceAll(samptitle,"%","\\%");
		findAndReplaceAll(samptitle,"rightarrow","to ");
		sample.title = samptitle.c_str();
	}
	for (int ireg = 0; ireg < region.size(); ++ireg)
	{

		vector<LatexChart*> charts;
		for (int icamp = 0; icamp < 3; ++icamp)
		{
			if(framework == "tthML" && icamp == 2) continue; //tthML only has 80fb-1
			TString label = region[ireg]+"_cutflow_"+mc_campaigns[icamp];
			LatexChart* chart = new LatexChart(label.Data());
			charts.push_back(chart);
			for(auto sample : samples){

				TFile *inputfile = 0;
				TH1D *cutflow_hist = 0;
				TString filename = "cutflow_" + mc_campaigns[icamp] + "_";
				if(signalmap.find(sample.name) != signalmap.end()){
					for(auto subsamp : signalmap.at(sample.name)){
						inputfile = new TFile(filename + subsamp + ".root");
						if(!cutflow_hist) {
							cutflow_hist = (TH1D*)(inputfile->Get(region[ireg])->Clone());
							cutflow_hist->SetDirectory(0);
						}else{
							cutflow_hist->Add((TH1D*)inputfile->Get(region[ireg]));
						}
						deletepointer(inputfile);
					}
				}else{
					inputfile = new TFile(filename + sample.name + ".root");
					cutflow_hist = (TH1D*)( inputfile->Get(region[ireg])->Clone());
					cutflow_hist->SetDirectory(0);
					deletepointer(inputfile);
				}
				if(!cutflow_hist) printf("grab cutflow histogram failed: %s, %s\n", (mc_campaigns[icamp] + "_" + sample.name).Data(),region[ireg].Data());
				TAxis *xaxis = cutflow_hist->GetXaxis();
				for (int ibin = 1; ibin <= cutflow_hist->GetNbinsX(); ++ibin)
				{
					TString cut_name = xaxis->GetBinLabel(ibin);
					if(cut_name == "") break;
					chart->set(cut_name.Data(), sample.title.Data(), cutflow_hist->GetBinContent(ibin), cutflow_hist->GetBinError(ibin));
				}
			}
		}
		LatexChart* sum = 0;
		for(auto &chart : charts) {
			if(!sum) sum = chart->clone();
			else sum->add(chart);
			chart->print(chart->label);
			deletepointer(chart);
		}
		sum->label = region[ireg]+"_cutflow_";
		sum->print((region[ireg]+"_cutflow").Data());
		deletepointer(sum);
		charts.clear();
	}
}
