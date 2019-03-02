#include "fcnc_include.h"

class applyTF
{
public:
	applyTF(){}
	~applyTF(){}
	TString configfolder = "./";
	map<TString,vector<float>> means;
	map<TString,vector<float>> stddevs;
	vector<vector<float>> predictEvent(TString modelname, vector<float>* data, int nparticle, int ndim, int npool, int nscore);
	void readmeanfile(TString filename);
	vector<float> standardize(vector<float> data, TString modelname);
};
