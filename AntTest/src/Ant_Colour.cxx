#include "Ant.h"

AntClass::AntClass(TH2* AntsWorld, int startX, int startY, int startD) {
  antsWorld = AntsWorld;
  worldSizeX = antsWorld->GetNbinsX();
  worldSizeY = antsWorld->GetNbinsY();
  X = startX;
  Y = startY;
  checkXY();
  D = startD;
  C = startD;
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
void AntClass::checkXY() {
  if (X < 1) 			X = worldSizeX;
  else if (X > worldSizeX) 	X = 1;

  if (Y < 1) 			Y = worldSizeY;
  else if (Y > worldSizeY) 	Y = 1;
}
void AntClass::flipSquare() {
  if ( antsWorld->GetBinContent( antsWorld->FindBin(X-0.001,Y-0.001) ) == 0 ) {
    antsWorld->SetBinContent( antsWorld->FindBin(X-0.001,Y-0.001) , C );
  } else {
    antsWorld->SetBinContent( antsWorld->FindBin(X-0.001,Y-0.001) , 0 );
  }
}
void AntClass::Move() {
    switch (D) {
      case 1: ++X; break;
      case 2: ++Y; break; 
      case 3: --X; break;
      case 4: --Y; break;
    } 
    checkXY();
    int square = antsWorld->GetBinContent( antsWorld->FindBin(X-0.001,Y-0.001) );
    if (square == 0) FlipR();
    if (square != 0) FlipL(); 
    flipSquare();
}
