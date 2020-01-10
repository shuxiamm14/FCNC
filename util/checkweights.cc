#include "TFile.h"
#include "TAxis.h"
#include "TH1D.h"
int main(int argc, char const *argv[])
{
	if(argc!=2) {
		printf("please give the file name\n");
		exit(0);
	}
	TFile mf(argv[1]);
	TAxis *x = ((TH1D*)(mf.Get("h_metadata_theory_weights")))->GetXaxis();
	for (int i = 1; i <= x->GetNbins(); ++i)
	{
	        printf("%s\n",x->GetBinLabel(i));
	}
	return 0;
}
