#include "TString.h"
#include <map>
class applyTF
{
public:
	applyTF(){}
	~applyTF(){}
	TString configfolder = "./";
	std::map<TString,std::vector<float>> means;
	std::map<TString,std::vector<float>> stddevs;
	std::vector<std::vector<float>> predictEvent(TString modelname, std::vector<float>* data, int nparticle, int ndim, int npool, int nscore);
	void readmeanfile(TString filename);
	std::vector<float> standardize(std::vector<float> data, TString modelname, int ndim);
};
