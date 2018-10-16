// For TMVA

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#endif
using namespace TMVA;

//
// ** Variables for hh4w BDT **
// 
TMVA::Reader *reader_tthssltau;
TMVA::Reader *reader_tth1l2tau;
// fcnc                                                                                                                     
TMVA::Reader *reader_thq2lss35j;
TMVA::Reader *reader_thq2lss4xj;
TMVA::Reader *reader_thq2lss2j;
TMVA::Reader *reader_thq2lss2xj;
TMVA::Reader *reader_thq3l24j;
// thq vs ttV                                                                                                               
TMVA::Reader *reader_thqvsttV2lss35j;
TMVA::Reader *reader_thqvsttV2lss2j;
TMVA::Reader *reader_thqvsttV3l24j;

Float_t tmva_njt;
Float_t tmva_leppt;
Float_t tmva_taupt;
Float_t tmva_met;
Float_t tmva_taueta;
Float_t tmva_ltaudr;
Float_t tmva_bdtjsc;
Float_t tmva_jtaudr;
Float_t tmva_ljdr;
Float_t tmva_jjdr;
Float_t tmva_sumet;
Float_t tmva_nbtags;
//
Float_t tmva1l2tau_njets25;
Float_t tmva1l2tau_nbjets25;
Float_t tmva1l2tau_htjets;
Float_t tmva1l2tau_leadtaupt;
Float_t tmva1l2tau_subtaupt;
Float_t tmva1l2tau_mtautau;
Float_t tmva1l2tau_jjdr;
// top fcnc                                                                                                                 
Float_t tmvafcnc_chimin;
Float_t tmvafcnc_drlepww;
Float_t tmvafcnc_mlepww;
Float_t tmvafcnc_mfcnc;
Float_t tmvafcnc_drqw;
Float_t tmvafcnc_ptw1;
Float_t tmvafcnc_ptw2;;
Float_t tmvafcnc_ptq;
Float_t tmvafcnc_wiso;
Float_t tmvafcnc_lepiso;


void initialiseTMVA_tthssltau( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT
#endif
  
  //---------------------------------------------------------------
  
  // This loads the library
  TMVA::Tools::Instance();
  
  // Default MVA methods to be trained + tested
  std::map<std::string,int> Use;
  
  std::cout << std::endl;
  std::cout << "==> Start TMVAClassificationApplication for combinatorial background" << std::endl;
  
  // Select methods (don't look at this code - not of interest)
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;
    
    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);
      
      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod 
		  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
	for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
	}
	std::cout << std::endl;
	return;
      }
      Use[regMethod] = 1;
    }
  }

  // ---------------------------------------------------------------------------------

  // --- Create the Reader object

  std::cout << "--- Create the Reader object" << endl;

  reader_tthssltau= new TMVA::Reader( "!Color:!Silent" );  

  reader_tthssltau->AddVariable( "NJet25" ,&tmva_njt ); 
  reader_tthssltau->AddVariable( "Leppt25"  ,&tmva_leppt );
  reader_tthssltau->AddVariable( "Taupt25"  ,&tmva_taupt );
  reader_tthssltau->AddVariable( "Met25"    ,&tmva_met );
  reader_tthssltau->AddVariable( "Taueta"   ,&tmva_taueta );
  reader_tthssltau->AddVariable( "LtaudR"   ,&tmva_ltaudr );
  reader_tthssltau->AddVariable( "Bdtjsc"   ,&tmva_bdtjsc );
  reader_tthssltau->AddVariable( "JtaudR"   ,&tmva_jtaudr );
  reader_tthssltau->AddVariable( "LjdR"     ,&tmva_ljdr );
  reader_tthssltau->AddVariable( "JjdR"     ,&tmva_jjdr );
  reader_tthssltau->AddVariable( "Sumet25"  ,&tmva_sumet );
  reader_tthssltau->AddVariable( "Nbtags"   ,&tmva_nbtags );

  reader_tthssltau->BookMVA("BDT_tthssltau", weights);
  
}


void initialiseTMVA_tth1l2tau( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT 
#endif

  //---------------------------------------------------------------

  // This loads the library
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested
  std::map<std::string,int> Use;

  std::cout << std::endl;
  std::cout << "==> Start TMVAClassificationApplication for combinatorial background" << std::endl;

  // Select methods (don't look at this code - not of interest)
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }

  // ---------------------------------------------------------------------------------

  // --- Create the Reader object

  std::cout << "--- Create the Reader object" << endl;

  reader_tth1l2tau= new TMVA::Reader( "!Color:!Silent" );

  reader_tth1l2tau->AddVariable( "Njets25<6?Njets25:5" ,&tmva1l2tau_njets25 );
  reader_tth1l2tau->AddVariable( "Nbjets25<4?Nbjets25:3" ,&tmva1l2tau_nbjets25 );
  reader_tth1l2tau->AddVariable( "Htjets"  ,&tmva1l2tau_htjets );
  reader_tth1l2tau->AddVariable( "Leadtaupt"  ,&tmva1l2tau_leadtaupt );
  reader_tth1l2tau->AddVariable( "Subtaupt"    ,&tmva1l2tau_subtaupt );
  reader_tth1l2tau->AddVariable( "Mtautau"   ,&tmva1l2tau_mtautau );
  reader_tth1l2tau->AddVariable( "Jjdr"   ,&tmva1l2tau_jjdr );
  reader_tth1l2tau->BookMVA("BDT_tth1l2tau", weights);

}

// 2lss35j                                                                                                                  
void initialiseTMVA_thq2lss35j( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library                                                                                                 
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested                                                                             
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)                                                             
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------                                      
  // --- Create the Reader object                                                                                           
  std::cout << "--- Create the Reader object thq2lss35j" << endl;

  reader_thq2lss35j= new TMVA::Reader( "!Color:!Silent" );
  //reader_thq2lss35j->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );                                             
  reader_thq2lss35j->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );
  reader_thq2lss35j->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  reader_thq2lss35j->AddVariable( "Mfcnc<250?Mfcnc:250"  ,&tmvafcnc_mfcnc );
  //reader_thq2lss35j->AddVariable( "Drqw"    ,&tmvafcnc_drqw );                                                            
  //reader_thq2lss35j->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );                                                 
  //reader_thq2lss35j->AddVariable( "Ptq<150?Ptq:150"    ,&tmvafcnc_ptq );                                                  
  reader_thq2lss35j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );
  reader_thq2lss35j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );
  reader_thq2lss35j->BookMVA("BDT_thq2lss35j", weights);
}

//2lss4xj 
void initialiseTMVA_thq2lss4xj( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library                                                                                                 
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested                                                                             
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)                                                             
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------                                      
  // --- Create the Reader object                                                                                           
  std::cout << "--- Create the Reader object thq2lss4xj" << endl;

  reader_thq2lss4xj= new TMVA::Reader( "!Color:!Silent" );
  reader_thq2lss4xj->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  reader_thq2lss4xj->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );
  reader_thq2lss4xj->AddVariable( "Mlepww<150?Mlepww:150"  ,&tmvafcnc_mlepww );
  reader_thq2lss4xj->AddVariable( "Mfcnc<250?Mfcnc:250"  ,&tmvafcnc_mfcnc );
  reader_thq2lss4xj->AddVariable( "Ptq<150?Ptq:150"    ,&tmvafcnc_ptq );
  reader_thq2lss4xj->AddVariable( "Ptw1<100?Ptw1:100."  ,&tmvafcnc_ptw1 );
  reader_thq2lss4xj->BookMVA("BDT_thq2lss4xj", weights);
}

// 2lss35j                                                                                                                  
void initialiseTMVA_thqvsttV2lss35j( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library                                                                                                 
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested                                                                             
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)                                                             
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------                                      
  // --- Create the Reader object                                                                                           
  std::cout << "--- Create the Reader object thqvsttV2lss35j" << endl;
  reader_thqvsttV2lss35j= new TMVA::Reader( "!Color:!Silent" );
  reader_thqvsttV2lss35j->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  reader_thqvsttV2lss35j->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );
  reader_thqvsttV2lss35j->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  reader_thqvsttV2lss35j->AddVariable( "Mfcnc<250?Mfcnc:250"  ,&tmvafcnc_mfcnc );
  //reader_thqvsttV2lss35j->AddVariable( "Drqw"    ,&tmvafcnc_drqw );                                                       
  reader_thqvsttV2lss35j->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );
  //reader_thqvsttV2lss35j->AddVariable( "Ptw2<100?Ptw2:100."  ,&tmvafcnc_ptw2 );                                           
  reader_thqvsttV2lss35j->AddVariable( "Ptq<150?Ptq:150"    ,&tmvafcnc_ptq );
  //reader_thqvsttV2lss35j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );                                             
  //reader_thqvsttV2lss35j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );                                       
  reader_thqvsttV2lss35j->BookMVA("BDT_thqvsttV2lss35j", weights);
}

// 2lss2j                                                                                                                   
void initialiseTMVA_thq2lss2j( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library                                                                                                 
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested                                                                             
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)                                                             
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }

  // ---------------------------------------------------------------------------------                                      
  // --- Create the Reader object                                                                                           
  std::cout << "--- Create the Reader object thq2lss2j" << endl;

  reader_thq2lss2j= new TMVA::Reader( "!Color:!Silent" );
  reader_thq2lss2j->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  //reader_thq2lss2j->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );                                          
  reader_thq2lss2j->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  //reader_thq2lss2j->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );                                                  
  //reader_thq2lss2j->AddVariable( "Ptw2<100?Ptw2:100."  ,&tmvafcnc_ptw2 );                                                 
  reader_thq2lss2j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );
  reader_thq2lss2j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );
  reader_thq2lss2j->BookMVA("BDT_thq2lss2j", weights);
}
// 2lss2xj no isoltion 
void initialiseTMVA_thq2lss2xj( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT
#endif
  // This loads the library
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------
  // --- Create the Reader object
  std::cout << "--- Create the Reader object thq2lss2xj" << endl;

  reader_thq2lss2xj= new TMVA::Reader( "!Color:!Silent" );
  reader_thq2lss2xj->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  reader_thq2lss2xj->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );                                                      
  reader_thq2lss2xj->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  reader_thq2lss2xj->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );                                                              
  //reader_thq2lss2j->AddVariable( "Ptw2<100?Ptw2:100."  ,&tmvafcnc_ptw2 );
  //reader_thq2lss2j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );
  //reader_thq2lss2j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );
  reader_thq2lss2xj->BookMVA("BDT_thq2lss2xj", weights);
}

//thq vs ttV                                                                                                                
// 2lss2j                                                                                                                   
void initialiseTMVA_thqvsttV2lss2j( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library                                                                                                 
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested                                                                             
  std::map<std::string,int> Use;
  // Select methods (don't look at this code - not of interest)                                                             
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------                                      
  // --- Create the Reader object                                                                                           
  std::cout << "--- Create the Reader object thqvsttV2lss2j" << endl;

  reader_thqvsttV2lss2j= new TMVA::Reader( "!Color:!Silent" );
  reader_thqvsttV2lss2j->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  reader_thqvsttV2lss2j->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );
  reader_thqvsttV2lss2j->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  reader_thqvsttV2lss2j->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );
  reader_thqvsttV2lss2j->AddVariable( "Ptw2<100?Ptw2:100."  ,&tmvafcnc_ptw2 );
  //reader_thqvsttV2lss2j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );                                              
  //reader_thqvsttV2lss2j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );                                        
  reader_thqvsttV2lss2j->BookMVA("BDT_thqvsttV2lss2j", weights);
}


// 3l24j                                                                                                                    
void initialiseTMVA_thq3l24j( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library                                                                                                 
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested                                                                             
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)                                                             
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------
  // --- Create the Reader object
  std::cout << "--- Create the Reader object thq3l24j" << endl;

  reader_thq3l24j= new TMVA::Reader( "!Color:!Silent" );
  reader_thq3l24j->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  reader_thq3l24j->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );
  reader_thq3l24j->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  reader_thq3l24j->AddVariable( "Mfcnc<250?Mfcnc:250"  ,&tmvafcnc_mfcnc );
  //reader_thq3l24j->AddVariable( "Drqw"    ,&tmvafcnc_drqw );
  //reader_thq3l24j->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );
  //reader_thq3l24j->AddVariable( "Ptw2<100?Ptw2:100."  ,&tmvafcnc_ptw2 );
  //reader_thq3l24j->AddVariable( "Ptq<150?Ptq:150"    ,&tmvafcnc_ptq );
  reader_thq3l24j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );
  reader_thq3l24j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );
  reader_thq3l24j->BookMVA("BDT_thq3l24j", weights);
}


// thq vs ttV                                                                                                               
// 3l24j                                                                                                                    
void initialiseTMVA_thqvsttV3l24j( TString weights, TString myMethodList = "" )
{
#ifdef __CINT__
  gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT                                                             
#endif
  // This loads the library
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested
  std::map<std::string,int> Use;

  // Select methods (don't look at this code - not of interest)
  if (myMethodList != "") {
    for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

    std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
    for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
	std::cout << "Method \"" << regMethod
                  << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
	  std::cout << it->first << " ";
        }
	std::cout << std::endl;
        return;
      }
      Use[regMethod] = 1;
    }
  }
  // ---------------------------------------------------------------------------------                                      
  // --- Create the Reader object                                                                                           
  std::cout << "--- Create the Reader object thqvsttV3l24j" << endl;

  reader_thqvsttV3l24j= new TMVA::Reader( "!Color:!Silent" );
  reader_thqvsttV3l24j->AddVariable( "Chimin<10?Chimin:10." ,&tmvafcnc_chimin );
  reader_thqvsttV3l24j->AddVariable( "Drlepww<3.5?Drlepww:3.5" ,&tmvafcnc_drlepww );
  reader_thqvsttV3l24j->AddVariable( "Mlepww<100?Mlepww:100"  ,&tmvafcnc_mlepww );
  reader_thqvsttV3l24j->AddVariable( "Mfcnc<250?Mfcnc:250"  ,&tmvafcnc_mfcnc );
  //reader_thqvsttV3l24j->AddVariable( "Drqw"    ,&tmvafcnc_drqw );                                                         
  reader_thqvsttV3l24j->AddVariable( "Ptw1<100?Ptw1:100"  ,&tmvafcnc_ptw1 );
  reader_thqvsttV3l24j->AddVariable( "Ptw2<100?Ptw2:100."  ,&tmvafcnc_ptw2 );
  //reader_thqvsttV3l24j->AddVariable( "Ptq<150?Ptq:150"    ,&tmvafcnc_ptq );                                               
  //reader_thqvsttV3l24j->AddVariable( "Wiso>-1?Wiso:-1"   ,&tmvafcnc_wiso );                                               
  //reader_thqvsttV3l24j->AddVariable( "Lepiso>-1?Lepiso:-1"   ,&tmvafcnc_lepiso );                                         
  reader_thqvsttV3l24j->BookMVA("BDT_thqvsttV3l24j", weights);
}
