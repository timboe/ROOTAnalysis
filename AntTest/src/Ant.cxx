#include "Ant.h"
#include <iostream>


AntClass::AntClass(TH2* _antsWorld, int _startX, int _startY, int _startD, std::string _style, int _startState) {
  antsWorld = _antsWorld;
  worldSizeX = antsWorld->GetNbinsX();
  worldSizeY = antsWorld->GetNbinsY();
  X = _startX;
  Y = _startY;
  checkXY();
  D = _startD;
  C = _startD;
  state = _startState;
  SetPattern("LR");
  Arrow = 0;
  style = _style;
}
void AntClass::FlipR() {
  switch (D) {
    case 1: D=2; return;
    case 2: D=3; return;  
    case 3: D=4; return;
    case 4: D=1; return;
  }
}
void AntClass::FlipL() {
  switch (D) {
    case 1: D=4; return;
    case 2: D=1; return;  
    case 3: D=2; return;
    case 4: D=3; return;
  }   
}
void AntClass::SetState(int _state) {
  state = _state;
}
void AntClass::checkXY() {
  if (X < 1) 			X = worldSizeX;
  else if (X > worldSizeX) 	X = 1;

  if (Y < 1) 			Y = worldSizeY;
  else if (Y > worldSizeY) 	Y = 1;
}
void AntClass::flipSquare() {
  unsigned int newSquareVal = antsWorld->GetBinContent( LocateBin() ) + 1;
  if (newSquareVal >= Pattern.size()) newSquareVal = 0;
  antsWorld->SetBinContent( LocateBin() , newSquareVal );
}

void AntClass::flipSquareMonotone() {
  unsigned int SquareVal = antsWorld->GetBinContent( LocateBin() );
  if (SquareVal) antsWorld->SetBinContent( LocateBin() , 0 );
  else antsWorld->SetBinContent( LocateBin() , C ); 
}


void AntClass::Move() {
    switch (D) {
      case 1: ++X; break;
      case 2: ++Y; break; 
      case 3: --X; break;
      case 4: --Y; break;
    } 
    checkXY();
    if (Arrow) delete Arrow;
    Arrow = new TArrow(X-2,Y-2,X,Y);
    Arrow->SetLineWidth(4);
    Arrow->Draw();
    unsigned int squareVal = antsWorld->GetBinContent( LocateBin() );
    if (squareVal >= Pattern.size()) squareVal = 0;
    if (style == "ant") {
      Ant(squareVal);
    }
   else  if (style == "monotoneAnt") {
      MonotoneAnt(squareVal);
    }
    else if (style == "turmite1") {
      Turmite1(squareVal);
    }
    else if (style == "turmite2") {
      Turmite2(squareVal);
    }
    else if (style == "turmite3") {
      Turmite3(squareVal);
    }
    else if (style == "spiral") {
      Spiral(squareVal);
    }
    else if (style == "fibonacci") {
      Fibonacci(squareVal);
    }
    else {
      std::cout<<"UNKNOWN TYPE "<<style<<"!"<<std::endl;
    }

}
void AntClass::SetPattern(std::string _pattern) {
  Pattern.clear();
  for(unsigned int POS = 0; POS < _pattern.length(); ++POS) {
    if      (_pattern.substr(POS,1) == "L" || _pattern.substr(POS,1) == "l") Pattern.push_back(0);
    else if (_pattern.substr(POS,1) == "R" || _pattern.substr(POS,1) == "r") Pattern.push_back(1);
    else std::cout<<"ERROR: Please supply only `L` or `R` in pattern"<<std::endl;
  }
}
int AntClass::LocateBin() {
  return antsWorld->FindBin(X-0.001,Y-0.001);
}

void AntClass::Ant(unsigned int _squareVal) {
  if (Pattern.at(_squareVal) == 0) FlipL();
  if (Pattern.at(_squareVal) == 1) FlipR();
  flipSquare();
}

void AntClass::MonotoneAnt(unsigned int _squareVal) {
  if (_squareVal == 0) FlipL();
  else FlipR();
  flipSquareMonotone();
}

void AntClass::Turmite1(unsigned int _squareVal) {
  if (Pattern.at(_squareVal) == 0) {
    if(state == 0) {
      SetState(1);
      FlipR();
      flipSquare();
    }
    else if(state == 1) {
      SetState(0);
      flipSquare();
    }
  }
  else if (Pattern.at(_squareVal) == 1) {
    if(state == 0) {
      SetState(1);
      FlipL();
      flipSquare();
    }
    else if(state == 1) {
      SetState(0);
      flipSquare();
    }
  }
}

void AntClass::Turmite2(unsigned int _squareVal) {
  if (Pattern.at(_squareVal) == 0) {
    if(state == 0) {
      SetState(1);
      FlipL();
      flipSquare();
    }
    else if(state == 1) {
      FlipR();
      flipSquare();
    }
  }
  else if (Pattern.at(_squareVal) == 1) {
    if(state == 0) {
      SetState(1);
      FlipL();
      flipSquare();
    }
    else if(state == 1) {
      SetState(0);
      FlipL();
      flipSquare();
    }
  }
}

void AntClass::Turmite3(unsigned int _squareVal) {
  if (Pattern.at(_squareVal) == 0) {
    if(state == 0) {
      SetState(1);
      FlipR();
      flipSquare();
    }
    else if(state == 1) {
      SetState(0);
      flipSquare();
    }
  }
  else if (Pattern.at(_squareVal) == 1) {
    if(state == 0) {
      SetState(1);
      FlipR();
      flipSquare();
    }
  }
}

void AntClass::Spiral(unsigned int _squareVal) {
  if (Pattern.at(_squareVal) == 0) {
    if(state == 0) {
      SetState(1);
      flipSquare();
    }
    else if(state == 1) {
      FlipR();
      flipSquare();
    }
  }
  else if (Pattern.at(_squareVal) == 1) {
    if(state == 0) {
      FlipL();
    }
    else if(state == 1) {
      SetState(0);
      flipSquare();
    }
  }
}

void AntClass::Fibonacci(unsigned int _squareVal) {
  if (Pattern.at(_squareVal) == 0) {
    if(state == 0) {
      SetState(1);
      FlipL();
      flipSquare();
    }
    else if(state == 1) {
      FlipR();
      flipSquare();
    }
  }
  else if (Pattern.at(_squareVal) == 1) {
    if(state == 0) {
      SetState(1);
      FlipL();
    }
    else if(state == 1) {
      SetState(0);
      flipSquare();
    }
  }
}





