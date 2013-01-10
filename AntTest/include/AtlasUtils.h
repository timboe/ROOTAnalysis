
#ifndef _AtlasUtils_h_
#define _AtlasUtils_h_

#include "TPave.h"

void ATLAS_LABEL(Double_t x,Double_t y,Color_t color=1);
void myText(Double_t x,Double_t y,Color_t color,const char *text,float tsize=0.05);
void myBoxText(Double_t x, Double_t y,Double_t boxsize,Int_t mcolor,const char *text, Double_t linewidth=2, float tsize=0.05);
void myMarkerText(Double_t x,Double_t y,Int_t color,Int_t mstyle,const char *text, float tsize=0.05);
void myLineText( Double_t x, Double_t y, Double_t boxsize,Int_t mcolor,const char *text, float tsize=0.05);
void myLineTextV(Double_t x, Double_t y, Double_t boxsize,Int_t mcolor,const char *text, int lineStyle = 0,  float tsize=0.05);
void ATLAS_PRELIMINARY_LABEL(Double_t x,Double_t y,int font, Color_t color) ;

#endif
