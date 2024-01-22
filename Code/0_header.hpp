#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP

#include <iostream>
#include <sys/ioctl.h>
#include <cmath>
#include <unistd.h>
#include <fstream>

//For conditional compilation
#define DEBUG
//Define a clearscreen shortcut
#define CLEARSCREEN "\033[2J"
#define WALL_CHAR "H"
#define WALL_BUFFER_SIZE (windowWidth / 5)




class Interface {
  public:

  //Draws wall of 'H'
  void drawWall();
  void drawBrick();
  //Gets window size and also terminates program if window is too small
  int windowSizeUpdate();

  unsigned int windowWidth;
  unsigned int windowHeight;
  unsigned int prevWidth;      //The Preveous Width of the terminal
  unsigned int prevHeight;     //The Preveous Height of the terminal  
};


class Ball {
  public:
  
  long wallAngle;
  long ballAngle;
  long OldBallAngle;

  //[0] is X and [1] is y
  int pointXY[2];
  int oldPointXY[2];

  //Obtains the ball's position
  void setPosition();

  //Gets ball position
  void ball();

};







#endif