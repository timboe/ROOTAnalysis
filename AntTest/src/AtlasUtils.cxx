#include "AtlasUtils.h"
#include "TPave.h"
#include "TLine.h"
#include "TMarker.h"
#include "math.h"
#include "TLatex.h"
#include <iostream>

using namespace std;

void ATLAS_LABEL(Double_t x,Double_t y,Color_t color) 
{
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextFont(72);
  l.SetTextColor(color);
  l.DrawLatex(x,y,"");//"ATLAS Preliminary");
}

void myText(Double_t x,Double_t y,Color_t color,const char *text,float tsize) {

  //Double_t tsize=0.05;
  TLatex l; //l.SetTextAlign(12); 
  l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextColor(color);
  l.DrawLatex(x,y,text);
}


void myBoxText(Double_t x, Double_t y,Double_t boxsize,Int_t mcolor,const char *text, Double_t linewidth, float tsize) {

  TLatex l; l.SetTextAlign(12); //l.SetTextSize(tsize); 
  l.SetTextSize(tsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-boxsize;

  int debug = 0;
  if(debug) printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  TPave *mbox= new TPave(x1,y1,x2,y2,0,"NDC");

  mbox->SetFillColor(mcolor);
  mbox->SetFillStyle(1001);
  mbox->Draw();

  if (!linewidth) return;

  TLine mline;
  mline.SetLineWidth((int)linewidth);
  mline.SetLineColor(1);
  mline.SetLineStyle(1);
  y=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y,x2,y);

}

void myMarkerText(Double_t x,Double_t y,Int_t color,Int_t mstyle,const char *text, float tsize) {

  //  printf("**myMarker: text= %s\ m ",text);

  //Double_t tsize=0.06;
  TMarker *marker = new TMarker(x-(0.4*tsize),y,8);
  marker->SetMarkerColor(color);  marker->SetNDC();
  marker->SetMarkerStyle(mstyle);
  marker->SetMarkerSize(1.0);
  marker->Draw();

  TLatex l; 
  l.SetTextAlign(12); 
  l.SetTextSize(tsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);
}


void myLineText(
  Double_t x, Double_t y, Double_t boxsize,Int_t mcolor,const char *text, float tsize) {

//  Double_t tsize=0.06;

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(tsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-0.078;

  bool debug=0;
  if(debug) printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  TLine mline;
  mline.SetLineWidth(4);
  mline.SetLineColor(mcolor);
  mline.SetLineStyle((int)boxsize);
  y=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y,x2,y);

}


void myLineTextV(
		 Double_t x, Double_t y, Double_t boxsize,Int_t mcolor,const char *text, int lineStyle,  float tsize) {

//  Double_t tsize=0.06;

  TLatex l; l.SetTextAlign(12); 
  l.SetTextSize(tsize); 
  l.SetNDC();
  l.DrawLatex(x,y,text);

  Double_t y1=y-0.25*tsize;
  Double_t y2=y+0.25*tsize;
  Double_t x2=x-0.3*tsize;
  Double_t x1=x2-0.078;

  bool debug=0;
  if(debug) printf("x1= %f x2= %f y1= %f y2= %f \n",x1,x2,y1,y2);

  TLine mline;
  mline.SetLineWidth(4);
  mline.SetLineColor(mcolor);
  mline.SetLineStyle(lineStyle);
  y=(y1+y2)/2.;
  mline.DrawLineNDC(x1,y,x2,y);

}

void ATLAS_PRELIMINARY_LABEL(Double_t x,Double_t y,int font, Color_t color) 
{
  int text_font_bold = 73;
  //int text_font = 43;
  int text_size = 25;
  
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextFont(text_font_bold);
  l.SetTextSize(text_size);
  l.SetTextColor(color);
  l.DrawLatex(x,y,"ATLAS Preliminary");
}

