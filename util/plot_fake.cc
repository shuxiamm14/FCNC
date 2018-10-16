#include "nominal.h"

int main(int argc, char const *argv[])
{
   nominal *analysis = new nominal();
   ifstream fn(argv[1]);
   if(!fn) {
     fprintf(stderr,"Error: can't open file: %s\n",argv[1]);
     return 1;
   }
   char inputline[100];
   while(!fn.eof()){
      fn.getline(inputline,200);
      if(strlen(inputline)==0) continue;
      if(inputline[0]=='#') continue;
      char filename[100];
      char cate[100];
      sscanf(inputline,"%s %s",&filename,&cate);
      printf("reading file: %s in %s\n", filename, cate);
      analysis->Loop( (TTree*)TFile::Open(filename)->Get("nominal"), cate);
   }
   analysis->plot();
   return 0;
}