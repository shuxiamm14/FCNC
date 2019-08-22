#include "fcnc_include.h"

int main(int argc, char const *argv[])
{

	if(argc!=5){
		printf("Please feed the file with variation list and the file with sample list, give the path of input files and path of output files\n");
		exit(0);
	}

	TString prefixinput = argv[1];
	TString prefixoutput = argv[2];
	std::vector<TString> samples;
	std::vector<TString> variations;
	std::vector<TString> varup;  //varup[ibin]
	std::vector<TString> vardown; //vardown[ibin]
	varup.push_back("");
	vardown.push_back("");
	std::map<TString, std::map<TString, TH1D*>> histograms;  //histograms[sample][variation]
	std::map<TString, TFile*> inputfiles;
	std::map<TString, TH1D*> stacked_histograms;  //histograms[variation]


//======================= read files ======================

	for(auto sample: samples){
		inputfiles[sample] = new TFile(prefixinput + sample+".root");
		for(auto variation: variations){
			histograms[sample][variation] = (TH1D*)inputfiles[sample]->Get(variation);
			if(stacked_histograms.find(variation) == stacked_histograms.end()) stacked_histograms[variation] = (TH1D*)histograms[sample][variation]->Clone("stacked_" + variation);
			else stacked_histograms[variation]->Add(histograms[sample][variation]);
		}
	}

//======================= find cover ======================
	TH1D *templatehist = (TH1D*)histograms[samples[0]][variations[0]]->Clone("template");

	int nbins = templatehist->GetNbinsX();

	for (int i = 1; i <= nbins; ++i)
	{
		float cover_hi = NAN;
		float cover_low = NAN;
		for(auto variation: variations){
			float content = stacked_histograms[variation]->GetBinContent(i);
			if(cover_hi != cover_hi || cover_hi<content) {
				cover_hi = content;
				varup[i] = variation;
			}
			if(cover_hi != cover_hi || cover_low > content) {
				cover_low = content;
				vardown[i] = variation;
			}
		}
	}
//======================= save cover ======================
	for(auto sample: samples){
		TFile outputfile(prefixoutput+"/" + sample + ".root","update");
		for (int i = 1; i <= nbins; ++i){
			templatehist->SetBinContent(i,histograms[sample][varup[i]]->GetBinContent(i));
			templatehist->SetBinError(i,histograms[sample][varup[i]]->GetBinError(i));
		}
		outputfile.cd();
		templatehist->Write("varup",TObject::kWriteDelete);
		for (int i = 1; i <= nbins; ++i){
			templatehist->SetBinContent(i,histograms[sample][vardown[i]]->GetBinContent(i));
			templatehist->SetBinError(i,histograms[sample][vardown[i]]->GetBinError(i));
		}
		templatehist->Write("vardown",TObject::kWriteDelete);
	}
	return 0;
}