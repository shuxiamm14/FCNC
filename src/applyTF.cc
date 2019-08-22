// main.cpp
#include <regex> 
#include <fdeep/fdeep.hpp>
#include "applyTF.h"
using namespace std;
map<TString, fdeep::model*> models;

vector<vector<float>> applyTF::predictEvent(TString modelname, vector<float> data[], int nparticle, int ndim, int npool, int nscore)
{
    if(models.find(modelname) == models.end())
        models[modelname] = new fdeep::model(fdeep::load_model((configfolder + "/" + modelname + ".json").Data()));
    if(means.find(modelname) == means.end()){
        printf("ERROR: applyTF::predictEvent cannot find mean of the model %s\n", modelname.Data());
        exit(0);
    }
    if(stddevs.find(modelname) == stddevs.end()){
        printf("ERROR: applyTF::predictEvent cannot find stddev of the model %s\n", modelname.Data());
        exit(0);
    }
    vector<fdeep::tensor5> particles;
    for (int i = 0; i < nparticle; ++i)
    {
        vector<float> standardizeddata = standardize(data[i],modelname,ndim);
    	const fdeep::shared_float_vec sv(fplus::make_shared_ref<fdeep::float_vec>(standardizeddata));
    	particles.push_back(fdeep::tensor5(fdeep::shape5(1, 1, 1, 1,ndim), sv));
    }
    const auto result = models[modelname]->predict(particles);
    vector<vector<float>> output;
    vector<float> outputtmp;
    for (int ipool = 0; ipool < npool; ++ipool)
    {
    	for (int iscore = 0; iscore < nscore; ++iscore)
    	{
    		outputtmp.push_back((*(result[ipool].as_vector()))[iscore]);
    	}
    	output.push_back(outputtmp);
    	outputtmp.clear();
    }
    return output;
}

vector<float> applyTF::standardize(vector<float> data, TString modelname, int ndim){
    if(ndim!=means[modelname].size()){
        printf("applyTF::standardize() ERROR: data dimention is not consistent with means provided\n");
        exit(1);
    }
    vector<float> standardizeddata;
    for (int i = 0; i < ndim; ++i)
    {
        standardizeddata.push_back((data[i]-means[modelname][i])/stddevs[modelname][i]);
    }
    return standardizeddata;
}

void applyTF::readmeanfile(TString filename){
    ifstream fn(configfolder + "/" + filename);
    char inputline[100];
    char modelname[20];
    char meanorstddev[10];
    char numbers[100];
    TString smeanorstddev;
    string snumbers;
    while(!fn.eof()){
        fn.getline(inputline,200);
        if(strlen(inputline)==0) continue;
        sscanf(inputline,"%s %s",modelname,meanorstddev);
        smeanorstddev = meanorstddev;
        regex r("\\[.*\\]");
        smatch m;
        string sinputline = inputline;
        regex_search(sinputline, m, r);
        snumbers = m.str();
        snumbers.erase(remove(snumbers.begin(), snumbers.end(), ','), snumbers.end());
        snumbers.erase(remove(snumbers.begin(), snumbers.end(), '['), snumbers.end());
        snumbers.erase(remove(snumbers.begin(), snumbers.end(), ']'), snumbers.end());
        istringstream iss(snumbers);
        if(smeanorstddev.Contains("mean")){
            copy(istream_iterator<float>(iss),istream_iterator<float>(),back_inserter(means[modelname]));
        }else{
            copy(istream_iterator<float>(iss),istream_iterator<float>(),back_inserter(stddevs[modelname]));
        }
    }
}