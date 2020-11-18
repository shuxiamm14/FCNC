#include "common.h"
#include "fcnc_include.h"
#include "LatexChart.h"
#include <iostream>
using namespace std;

void fillChart(LatexChart* chart, string inputfiles_name, TString framework, string output_dir){
	string outputfile_name = inputfiles_name;
	printf("Read list %s\n",inputfiles_name.c_str());
	ifstream input_files(inputfiles_name);
	if(!input_files) {
		printf("file %s connot be opened\n", inputfiles_name.c_str());
	}
	char inputline[50];
	auto vars = getVariables(framework);
	while(!input_files.eof()){
		char file_name[20];
		input_files.getline(inputline,50);
		if(strlen(inputline)==0) continue;
		if(inputline[0]=='#') continue;
		sscanf(inputline,"%s",file_name);
		printf("Read file %s\n", file_name);
		ifstream fn(file_name);
		string region_name = file_name;
		findAndReplaceAll(region_name,"Importance_","");
		findAndReplaceAll(region_name,"_1.txt","");
		findAndReplaceAll(region_name,"_2.txt","");
		findAndReplaceAll(region_name,".txt","");
		translateRegion(region_name);
		if(!fn) {
			printf("file %s connot be opened\n", file_name);
		}
		while(!fn.eof()){
			fn.getline(inputline,50);
			if(strlen(inputline)==0) continue;
			if(inputline[0]=='#') continue;
			char varname[20];
			float importance;
			sscanf(inputline,"%s %f",varname, &importance);
			string rowname = ("$"+vars[varname]->title+"$").Data();
			findAndReplaceAll(rowname,"DeltaR","Delta R");
			findAndReplaceAll(rowname,"-","~");
			findAndReplaceAll(rowname,"#","\\");
			findAndReplaceAll(rowname,"tau","tau ");
			chart->set(rowname,region_name,importance*100);
		}
		findAndReplaceAll(outputfile_name,".tmp","");

		chart->print(output_dir+"/"+outputfile_name);
	}
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("please use script print_importance.sh instead\n");
		return 0;
	}
	vector<LatexChart*> charts;
	string output_dir = TABLE_DIR;
	TString framework = "tthML";
	output_dir+="/Importance/";
	gSystem->mkdir(output_dir.c_str());
	output_dir+= framework.Data();
	gSystem->mkdir(output_dir.c_str());
	for(int i = 1; i< argc; i++){
		LatexChart* tmpchart = new LatexChart("importance");
		tmpchart->maxcolumn = 6;
		fillChart(tmpchart,argv[i],framework,output_dir);
		charts.push_back(tmpchart);
	}
	for(int i = 1; i < argc-1; i++){
		charts[0]->concate(charts[i]);
	}
	string outputfile_name = "Merged";
	charts[0]->print(output_dir+"/"+outputfile_name);
	return 0;
}
