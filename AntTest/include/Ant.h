#ifndef _Ant_h_
#define _Ant_h_

#include "TH2.h"
#include "TArrow.h"
#include <string>
#include <vector>

class AntClass {
  public:
  std::vector<int> Pattern;
  int D;
  int C;
  int state;
  std::string style;
  int X;
  int Y;
  int worldSizeX;
  int worldSizeY;
  TH2* antsWorld;
  TArrow* Arrow;
  
  AntClass(TH2* _antsWorld, int _startX, int _startY, int _startD, std::string _style, int _startState);
  void FlipR();
  void FlipL();
  void SetState(int _state);
  void checkXY();
  void flipSquare();
  void flipSquareMonotone();
  void Move();
  void SetPattern(std::string _pattern);
  int LocateBin();

  void Ant(unsigned int _squareVal);
  void MonotoneAnt(unsigned int _squareVal);
  void Turmite1(unsigned int _squareVal);
  void Turmite2(unsigned int _squareVal);
  void Turmite3(unsigned int _squareVal);
  void Spiral(unsigned int _squareVal);
  void Fibonacci(unsigned int _squareVal);

};
#endif
