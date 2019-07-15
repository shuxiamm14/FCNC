#include "TTree.h"
#include "TFile.h"

int main(int argc, char const *argv[])
{
	if(argc!=4){
		printf("please feed the file and the tree, branch name\n");
		exit(0);
	}
	TFile readthefile(argv[1]);
	TTree *readtree = (TTree*)readthefile.Get(argv[2]);
	ULong64_t var;
	readtree->SetBranchAddress(argv[3],&var);
	long entries = readtree->GetEntries();
	for (int i = 0; i < entries; ++i)
	{
		readtree->GetEntry(i);
		printf("%s = %llu\n", argv[3], var);
	}
	return 0;
}