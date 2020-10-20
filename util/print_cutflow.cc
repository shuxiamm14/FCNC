#include "fcnc_include.h"
#include "common.h"
#include "LatexChart.h"
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Please specify the framework\n");
	}
	TString framework = argv[1];
	string outputdir = TABLE_DIR;
	outputdir += "/cutflow/";
	gSystem->mkdir(outputdir.c_str());
	outputdir += framework.Data();
	gSystem->mkdir(outputdir.c_str());
	vector<TString> region_tthML = {
		"reg1l1tau1b2j_os","reg1l1tau1b2j_ss","reg1l1tau1b3j_os","reg1l1tau1b3j_ss","reg1l2tau1bnj_os","reg1l2tau1bnj_ss",
		"reg1l1tau2b2j_os","reg1l1tau2b2j_ss","reg1l1tau2b3j_os","reg1l1tau2b3j_ss","reg1l2tau2bnj_os","reg1l2tau2bnj_ss","all"
		"reg2l1tau1bnj", "reg2l1tau2bnj", "reg2lSS1tau1bnj_os", "reg2lSS1tau1bnj_os_antiiso", "reg2lSS1tau1bnj_os_antiisolead"
	};
        //string  cut_name_dict[]={"","this region","this region","bjet pt>30 eta<2.5","tau b-veto","$m_{\\tau\\tau,vis}>50$","$m_{\\tau\\tau,vis}<130$","$\\Delta R(\\tau,\\tau)<3.4$"}; 
	vector<TString> region_xTFW = {
	          "all","reg2mtau1b2jss","reg2mtau1b3jss","reg2mtau1b2jos","reg2mtau1b3jos","reg2mtau2b2jss","reg2mtau2b3jss","reg2mtau2b2jos",
		  "reg2mtau2b3jos","reg2ltau1b2jss","reg2ltau1b3jss","reg2ltau1b2jos","reg2ltau1b3jos","reg2ltau2b2jss","reg2ltau2b3jss",
		  "reg2ltau2b2jos","reg2ltau2b3jos","reg2ttau1b2jss","reg2ttau1b3jss","reg2ttau1b2jos","reg2ttau1b3jos","reg2mtau2b1jos",
		  "reg2mtau2b1jss","reg1l1mtau1b2jos","reg1l1mtau1b2jss","reg1l1mtau1b3jos","reg1l1mtau1b3jss","reg1l1mtau2b2jos",
		  "reg1l1mtau2b2jss","reg1l1mtau2b3jos","reg1l1mtau2b3jss"
        };
	vector<TString> datayear = {"1516","17","18"};
	vector<TString> region;
	if(framework == "tthML") region = region_tthML;
	else region = region_xTFW;
	float BR = 0.2;
	vector<fcncSample> bkg_samples = getBkgSamples(framework);
	vector<fcncSample> sig_samples = getSigSamples(framework,BR);
	vector<fcncSample> samples = bkg_samples;
	samples.insert(samples.end(),sig_samples.begin(),sig_samples.end());
	samples.emplace_back("data","Data",kBlack);
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
			//if(framework == "tthML" && icamp == 2) continue; //tthML only has 80fb-1
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
						TH1D *cutflowhist = (TH1D*)(inputfile->Get(region[ireg]));
						if(!cutflowhist) continue;
						if(!cutflow_hist) {
							cutflow_hist = (TH1D*)(inputfile->Get(region[ireg])->Clone());
							cutflow_hist->SetDirectory(0);
						}else{
						      //	cutflow_hist->Add((TH1D*)inputfile->Get(region[ireg]));
						        TH1D *tmp_ = (TH1D*)(inputfile->Get(region[ireg]));
					for(int i=1;i<=(tmp_->GetXaxis()->GetNbins()>=cutflow_hist->GetXaxis()->GetNbins()?tmp_->GetXaxis()->GetNbins():cutflow_hist->GetXaxis()->GetNbins());i++){
					   double cutflowcontent_=cutflow_hist->GetBinContent(i);
					   double cutflowerror_=cutflow_hist->GetBinError(i);
					   double tmp_error=tmp_->GetBinError(i);
					   cutflow_hist->SetBinContent(i,cutflowcontent_+tmp_->GetBinContent(i));
					   cutflow_hist->SetBinError(i,sqrt(cutflowerror_*cutflowerror_+tmp_error*tmp_error));
					   if(tmp_->GetXaxis()->GetBinLabel(i)==""&&cutflow_hist->GetXaxis()->GetBinLabel(i)=="") break;
		                           }
                                               }
						deletepointer(inputfile);
					}
				}else{
					if(sample.name == "data"){
						inputfile = new TFile("cutflow_data" + datayear[icamp] + ".root");
					}else{
						inputfile = new TFile(filename + sample.name + ".root");
					}
                                        if(!inputfile->Get(region[ireg])) {
						printf("histogram %s not found in file %s\n",region[ireg].Data(),inputfile->GetName());
						continue;
					}
					cutflow_hist = (TH1D*)( inputfile->Get(region[ireg])->Clone());
					cutflow_hist->SetDirectory(0);
					deletepointer(inputfile);
				}
				if(!cutflow_hist) {
					printf("grab cutflow histogram failed: %s, %s\n", (mc_campaigns[icamp] + "_" + sample.name).Data(),region[ireg].Data());
					continue;
				}
				TAxis *xaxis = cutflow_hist->GetXaxis();
				for (int ibin = 1; ibin <= cutflow_hist->GetNbinsX(); ++ibin)
				{
					TString cut_name = xaxis->GetBinLabel(ibin);
                                 	if(cut_name == "") break;
					if(cutflow_hist->GetBinContent(ibin)) chart->set(cut_name.Data(), sample.title.Data(), cutflow_hist->GetBinContent(ibin), cutflow_hist->GetBinError(ibin));
                                    //    if(cut_name == "")chart->set(cut_name_dict[ibin], sample.title.Data(), 0.0,0.0);
                                }
			}
		}
		LatexChart* sum = 0;
		for(auto &chart : charts) {
			if(!sum) sum = chart->clone();
			else sum->add(chart);
			chart->caption = chart->label;
			translateRegion(chart->caption);
			deletepointer(chart);
		}
		sum->label = ("cutflow_" + region[ireg]).Data();
		sum->caption = sum->label;
		translateRegion(sum->caption);
		sum->print(outputdir + "/" + sum->label);
		deletepointer(sum);
		charts.clear();
	}
}
