
#include "LatexChart.h"
#include "TFile.h"
#include "TH1D.h"
#include "common.h"
#include "fcnc_include.h"
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{

string file_to_read=argv[1];
LatexChart*  mychart=new  LatexChart();

//std::cout<<"string(PACKAGE_DIR)"<<string(PACKAGE_DIR)+"/thefile.txt"<<std::endl;
std::ifstream infile(string(PACKAGE_DIR)+"/"+file_to_read+".txt");
std::string line;
while (std::getline(infile, line))
{
    printf("%s\n",line.c_str());
    char* tmp_line=const_cast<char*>(line.c_str());

    for ( ; *tmp_line != '\0'; ++tmp_line ){
      if ( *tmp_line == ',' ||*tmp_line == ':' )
      {
         *tmp_line = ' ';
      }
    }
    
    char cut[10],tree[10],score[10];
    int cut_,tree_;
    float score_;
    sscanf(line.c_str(), "%s %i %s %i %s %f ",cut,&cut_,tree,&tree_,score,&score_);
    printf("%s\n",line.c_str());
    std::cout<<cut_<<", "<<tree_<<", "<<score_<<std::endl;
    mychart->set("tree="+std::to_string(tree_),"cut="+std::to_string(cut_),score_/2.,0,0);
}
  mychart->print("BDT_optimise_"+file_to_read);
  return 0;
}

