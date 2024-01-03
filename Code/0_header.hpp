#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP

#include <iostream>
#include <sys/ioctl.h>
#include <cmath>
#include <unistd.h>
#include <fstream>

#define CLEARSCREEN "\033[2J"
#define WALL_CHAR "H"
#define WALL_BUFFER_SIZE (Win_Width/5)
#define Win_Height size.ws_row
#define Win_Width size.ws_col

struct winsize size;

class Interface {
  public:

  //Draws wall of 'H'
  void drawWall();
  void drawBrick();
  //Gets window size and also terminates program if window is too small
  int windowSizeUpdate();


  unsigned int prevWidth;      //The Preveous Width of the terminal
  unsigned int prevHeight;     //The Preveous Height of the terminal  
};

/* class Ball {
  public:

  double wallAngle;
  double ballAngle;
  double OldBallAngle = 0;
  int pointXY[2];
  int newPointXY[2];

  //Obtains the ball's position
  void ballPosition();

  //Gets ball position
  void ball();

}; */







#endif