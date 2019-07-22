#include "tthmltree.h"

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		printf("please input reduce scheme, sample.txt, sysname\nFor example: >$tth_reduce2_run 2 fcnc_prod_chd.txt nominal");
	}

	TString prefix = PACKAGE_DIR;
	ifstream fn(argv[2]);
	if(!fn) {
	  fprintf(stderr,"Error: can't open file: %s\n",argv[2]);
	  return 1;
	}
	bool doplot = 0;
	char inputline[100];
	bool dofake = 0;

	vector<TString> regions,regions1;
	if(dofake){
		regions.push_back("reg1e1mu1tau1b");
		regions.push_back("reg1e1mu1tau2b");
		regions.push_back("reg1l1tau2b1j_os");
		regions.push_back("reg1l1tau2b1j_ss");

		regions1.push_back("reg1e1mu2b");
		regions1.push_back("reg1e1mu2bnj");
		regions1.push_back("reg1l2b2j");
	}else{
		regions.push_back("reg1l2tau1bnj_os");
		regions.push_back("reg1l2tau1bnj_ss");
		regions.push_back("reg1l1tau1b2j_os");
		regions.push_back("reg1l1tau1b2j_ss");
		regions.push_back("reg1l1tau1b3j_os");
		regions.push_back("reg1l1tau1b3j_ss");
		regions.push_back("reg1l2tau2bnj_os");
		regions.push_back("reg1l2tau2bnj_ss");
		regions.push_back("reg1l1tau2b2j_os_85");
		regions.push_back("reg1l1tau2b2j_ss_85");
		regions.push_back("reg1l1tau2b3j_os_85");
		regions.push_back("reg1l1tau2b3j_ss_85");
	}
	tthmltree *analysis = new tthmltree();
	analysis->dumpeventnumber = 1;

	analysis->tthcutflow.trackevent(100014948);
	analysis->tthcutflow.trackevent(100029789);
	analysis->tthcutflow.trackevent(100031531);
	analysis->tthcutflow.trackevent(100047871);
	analysis->tthcutflow.trackevent(100116996);
	analysis->tthcutflow.trackevent(100154687);
	analysis->tthcutflow.trackevent(10018238);
	analysis->tthcutflow.trackevent(10019907);
	analysis->tthcutflow.trackevent(100218491);
	analysis->tthcutflow.trackevent(100236226);
	analysis->tthcutflow.trackevent(100243268);
	analysis->tthcutflow.trackevent(100266038);
	analysis->tthcutflow.trackevent(100287328);
	analysis->tthcutflow.trackevent(100321108);
	analysis->tthcutflow.trackevent(100331291);
	analysis->tthcutflow.trackevent(100370965);
	analysis->tthcutflow.trackevent(10037521);
	analysis->tthcutflow.trackevent(100385144);
	analysis->tthcutflow.trackevent(100394007);
	analysis->tthcutflow.trackevent(100428457);
	analysis->tthcutflow.trackevent(100475254);

	if(!dofake) {
		analysis->dovetobwp["btagwp70"] = 1;
		analysis->fcnc_regions = regions;
	}
	else {
		analysis->dovetobwp["btagwp70"] = 1;
		analysis->dobwp["btagwp70"] = 1;
		analysis->dobwp["btagwp85"] = 1;
		analysis->fake_regions = regions;
		analysis->fake_regions_notau = regions1;
	}
	regions.insert(regions.end(),regions1.begin(),regions1.end());
	analysis->plotNPs.push_back(0);
	analysis->plotNPs.push_back(1);
	analysis->plotNPs.push_back(2);
	analysis->plotNPs.push_back(3);
	analysis->plotNPs.push_back(4);
	analysis->plotNPs.push_back(5);
	analysis->plotNPs.push_back(6);
	analysis->plotNPs.push_back(7);
	analysis->plotNPs.push_back(8);
	//if(!dofake) analysis->plotNPs.push_back(1);
	analysis->SystematicsName = argv[3];
	analysis->debug = 0;
	analysis->writetree = 1;
	analysis->fcnc = 1;
	analysis->reduce = *argv[1]-'0';
	analysis->dumptruth = 1;
	//analysis->readTFmeanstd("meanstddevs.txt");

	fn.getline(inputline,200);
	char cate[100];
	char title[100];
	int version;
	sscanf(inputline,"%d %s %s",&version,cate,title);
	if(analysis->reduce == 3 || dofake ) {
		analysis->writetree = 0;
		doplot = 1;
	}

	if(doplot) {
		if(TString(cate).Contains("data")){
			analysis->plotNPs.clear();
			analysis->plotNPs.push_back(0);
		}
	}
	if(doplot) analysis->init_hist(cate);
	analysis->version = version;
	analysis->init_sample(cate, title);
	TString rootfilename = prefix + "/data/tthmlreduce" + char(analysis->reduce - 1 + '0') + "/" + argv[3] + "/" + cate + "_tree.root";
	printf("reading Root file: %s\n", rootfilename.Data());
	TFile inputfile(rootfilename);
	for (auto i : regions)
	{
		printf("region: %s\n", i.Data());
		if(!(TTree*)inputfile.Get(i.Data())) {
			printf("TTree name not found: %s\n", i.Data());
			exit(1);
		}
		analysis->Loop( (TTree*)inputfile.Get(i.Data()), cate);
		printf("finish loop on region: %s\n", i.Data());
	}
	analysis->finalise_sample();
	inputfile.Close();
	return 0;
}
