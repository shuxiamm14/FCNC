#include "MytthAnaFakeSys.h"
#include "TKey.h"

int main(int argc, char *argv[])
{

  if(argc < 2)
  {
    cout << " Usage: " << " input_file or list; and number of events to analysis" << endl;
    cout << " input_file - input file in ROOT format tree," << endl;
    return 1;
  }


  TString inputFile(argv[1]);
  std::cout<<"inputfile "<<inputFile<<std::endl;
  int myevt = -1; 
  int debug = 0;
  //bool isout(false);
  if(argc>2)myevt=atoi(argv[2]);
  if(argc>3)debug=atoi(argv[3]);
  bool listok = inputFile.Contains(".list");

  string filename =(string)inputFile;
  int n = filename.find("/");
  bool ismc =((int)(filename.find("Data"))>-1?0:1)||((int)(filename.find("data"))>-1?0:1); // check is mc or not
  bool isys = ((int)filename.find("SkimSysV6"))>-1?1:0; 
  double lum(80.); // 2015+2016 mc16a
  if(!isys){
    lum=43.814; // normalized back 
  }
  int nameid(0);
  while(n>-1){
    filename =filename.substr(n+1);
    n = filename.find("/");
  }
  if(listok){ 
    n = filename.find(".list"); // remove anything after .root or .list
    filename = filename.substr(0,n);
  }
  else{
    n = filename.find(".root"); // remove anything after .root or .list 
    filename = filename.substr(0,n);
  }
  TString output(filename); // output 
  TChain *chain = new TChain("nominal");
  bool lfst(true);
  TFile* filex;
  int mmx(0);
  if(listok){ // this is a list containing multiple files
    ifstream source(inputFile);
    if(!source){
      std::cout<<" Couldn't open "<<inputFile<<" . Aborting "<<std::endl;
      return 1;
    }
    TString line;
    int ith(0);
    while(!source.eof()){     //getline(source,line)){
      source>>line;
      std::cout<<" file added ith"<<ith<<" "<<line<<std::endl;
      if(line==""){
	continue;
      }
      if(lfst){

	filex = TFile::Open(line,"READ"); 
	//filex->Close();
	lfst = false;
      }
      else{
	filex = TFile::Open(line,"READ");
	//filex->Close();
      }
      chain->Add(line);
      
      std::cout<<" file added ith"<<ith<<" "<<line<<" "<<chain->GetEntries()<<" added events "<<chain->GetEntries()-mmx<<std::endl;
      mmx = chain->GetEntries();
      ++ith;
    }
  }
  else{
    filex = TFile::Open(inputFile,"READ");
    chain->Add(inputFile);
  }
  // analysis for lists data only  
  int nx = chain->GetEntries();
  std::cout<<"Inputfile"<< inputFile<<" name "<<filename<<" Containing events in chain "<<nx<<std::endl;
  TString outputx("../../Hist/25ns_R21SkimSysV6/FakeMini/");
  outputx +=output;
  if(myevt>-1){
    outputx +="_testwithEvt_";
    outputx +=myevt;
  }
  TFile* histf = new TFile(outputx+".root", "RECREATE");
  if(filex){
    TIter nextkey(filex->GetListOfKeys());
    TKey *key;
    int nkey(0);
    while ( (key = (TKey*)nextkey())) {
      TObject *obj = key->ReadObj();
      if ( obj->IsA()->InheritsFrom( TTree::Class() ) ) {
	TString obj_name= obj->GetName();
	if(nkey>0)histf = new TFile(outputx+".root", "UPDATE");
	std::cout<<"Process TTree "<<nkey<<" "<<obj_name<<std::endl;
	chain = new TChain(obj_name);
	int ith(0);
	if(listok){
	  ifstream source(inputFile);
	  TString line;
	  while(!source.eof()){
	    source>>line;
	    if(line==""){
	      continue;
	    }
	    chain->Add(line);
	    std::cout<<"Tree name "<<obj_name<<" file added ith"<<ith<<" "<<line<<" "<<chain->GetEntries()<<std::endl;
	    ++ith;
	  }
	}
	else{
	  chain->Add(inputFile);
	  ++ith;
	}
	std::cout<<"Tree Name "<<obj_name <<" nfiles added "<<ith<< " Containing events in chain "<<chain->GetEntries()<<std::endl;
	MytthAnaFakeSys* t = new MytthAnaFakeSys(chain);
	t->SetOutHistFile(outputx);
	t->SetOutHistFile(histf);
	t->SetNevtAna(myevt);
	t->SetSampleid(nameid);
	t->SetIsmc(ismc);
	t->SetDebug(debug);
	t->SetLum(lum);
	t->SetSubdir(obj_name);
	t->Loop();
	++nkey;
	delete t;
	if(histf)histf->Close();
      }
    }
  }
  else {
    std::cout<<" File not exist Aborting "<<std::endl;
    return 1;
  }
}


