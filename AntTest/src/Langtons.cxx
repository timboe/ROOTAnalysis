#include <iostream>
#include <vector>
#include "TROOT.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TStyle.h"
#include "TH2.h"
#include "TAxis.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TTimeStamp.h"
#include "AtlasStyle.h"
#include "AtlasUtils.h"
#include "Ant.h"

int main(int argc, char** argv) {
  std::cout<<std::endl<<"Hi!"<<std::endl;
  TApplication ta("ROOTAnt",&argc,argv);
  
  SetAtlasStyle();
  gStyle->SetPalette(1);

  
  int SizeX=200;
  int SizeY=SizeX;
  int Skip = 10000;
  
  TH2S* theWorld = new TH2S("theWorld","theWorld", SizeX,0,SizeX, SizeY,0,SizeY);
  theWorld->SetContour(99);
  
  theWorld->SetStats(0);
  theWorld->GetXaxis()->SetTitle("X");
  theWorld->GetYaxis()->SetTitle("Y");
  TCanvas* DrawCanvas = new TCanvas("DrawCanvas","DrawCanvas",SizeX*5,SizeY*5);
  DrawCanvas->SetTitle("Langton's Ant");
  theWorld->Draw("col");
  
  std::vector<AntClass*> ants;
  
  int quarter = SizeX/4;
  ants.push_back( new AntClass(theWorld,quarter*1,	quarter*1,	1, "ant", 1) );
  ants.push_back( new AntClass(theWorld,quarter*1,	quarter*3,	1, "ant", 2) );
  ants.push_back( new AntClass(theWorld,quarter*3,	quarter*1,	1, "ant", 3) );
  ants.push_back( new AntClass(theWorld,quarter*3,	quarter*3,	1, "ant", 4) );
  //ants.push_back( new AntClass(theWorld,quarter*3,	quarter,	4, "ant", 0) );
  //ants.push_back( new AntClass(theWorld,quarter*1,	quarter*3,	3, "fibonacci", 0) );
  //ants.push_back( new AntClass(theWorld,quarter+4,	quarter+4,	2, "ant", 0) );
  //ants.push_back( new AntClass(theWorld,quarter*3,	quarter,	1, "turmite2", 0) );
  //ants.push_back( new AntClass(theWorld,quarter*2,	quarter*2,	1) );
  
  //ants[3]->SetPattern("LRRRRRLLRLRRRRRLLR");
  //ants[2]->SetPattern("RLRRLR");
  //ants[1]->SetPattern("RLR");
  //ants[0]->SetPattern("LRRRRRLLR");

  std::cout<<std::endl<<"Pass to ROOT!"<<std::endl;
  
  while(!gSystem->ProcessEvents()) {
	for (int i=1; i<=Skip; ++i) {
	  for (unsigned int a=0; a < ants.size(); ++a) ants[a]->Move();
	}
	gPad->Modified();
        gPad->Update();
  }

  std::cout<<std::endl<<"Done!"<<std::endl;
}
