#include "fcnc_include.h"
#include "common.h"
#include "makechart.h"
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Please specify the framework\n");
	}
	TString framework = argv[1];
	vector<TString> region_tthML = {
		"all","reg1l1tau1b2j_os","reg1l1tau1b2j_ss","reg1l2tau1bnj_os","reg1l2tau1bnj_ss",
		"reg1l1tau2b2j_os","reg1l1tau2b2j_ss","reg1l2tau2bnj_os","reg1l2tau2bnj_ss"
	};
	vector<TString> region_xTFW = {
		"all","reg2mtau1b2j_os","reg2mtau1b2j_ss",
		"reg2mtau2b2j_os","reg2mtau2b2j_ss"
	};
	vector<TString> region;
	if(framework == "tthML") region = region_tthML;
	else region = region_xTFW;
	float BR = 0.2;
	gSystem->mkdir("cutflow");
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
			TString label = "cutflow_"+region[ireg] + "_" + mc_campaigns[icamp];
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
			chart->print("cutflow/" + chart->label);
			deletepointer(chart);
		}
		sum->label = ("cutflow_" + region[ireg]).Data();
		sum->print("cutflow/" + sum->label);
		deletepointer(sum);
		charts.clear();
	}
}
