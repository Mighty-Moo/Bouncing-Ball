#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP

#include <iostream>
#include <sys/ioctl.h>
#include <cmath>
#include <unistd.h>
#include <fstream>

#define CLEARSCREEN "\033[2J"
#define WALL_CHAR "H"
#define WALL_BUFFER_SIZE (windowWidth/5)
#define Win_Height size.ws_row
#define Win_Width size.ws_col


class Interface {
  public:

  //Draws wall of 'H'
  void drawWall();
  void drawBrick();
  //Gets window size and also terminates program if window is too small
  int windowSizeUpdate();
  //Suposedly reads a file by a specified line
  void fileReadLine(int targetLineNumber);

  unsigned int prevWidth;      //The Preveous Width of the terminal
  unsigned int prevHeight;     //The Preveous Height of the terminal  
};

class Ball {
  double ballAngle;
  double OldBallAngle;
  int pointXY[2];

  //Obtains the ball's position
  void ballPosition();

  //Gets ball position
  void ball();

};







#endif