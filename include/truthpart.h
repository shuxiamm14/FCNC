#include "TLorentzVector.h"
#ifndef TRUTHPART
#define TRUTHPART
class truthpart
{
public:
	truthpart(int _pdg, TLorentzVector _p4): pdg(_pdg), p4(_p4) {}
	~truthpart(){}
	truthpart *mother = NULL;
	truthpart *twin = NULL;
	std::vector<truthpart*> children;
	TLorentzVector p4;

	int pdg;
	int barcode;
	int motherbarcode = -1;
	std::vector<int> childrenbarcode;
};
#endif