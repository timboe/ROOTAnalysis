#ifndef _Ant_Colour_h_
#define _Ant_Colour_h_

#include "TH2.h"
#include <string>

class AntClass_Colour {
  public:
  int D;
  int C;
  int X;
  int Y;
  int worldSizeX;
  int worldSizeY;
  TH2* antsWorld;
  
  AntClass(TH2* AntsWorld, int startX, int startY, int startD);
  void FlipR();
  void FlipL();
  void checkXY();
  void flipSquare();
  void Move();
  void SetPattern(string pattern);
};
#endif
