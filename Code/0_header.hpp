#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP

#include <iostream>
#include <sys/ioctl.h>
#include <cmath>
#include <unistd.h>
#include <fstream>

//For conditional compilation
#define DEBU
//Define a clearscreen shortcut
#define CLEARSCREEN "\033[2J"
#define WALL_CHAR "H"
#define WALL_BUFFER_SIZE (windowWidth / 5)




class Interface {
  public:


  //Gets window size and also terminates program if window is too small
  int windowSizeUpdate();
  //Updates map for window resizes and if window is too small after resize, an error is displayed.
  void updateMap();
  
  unsigned int windowWidth;    //The Height of the terminal
  unsigned int windowHeight;   //The Width of the terminal
  unsigned int prevWidth;      //The Previous Width of the terminal
  unsigned int prevHeight;     //The Previous Height of the terminal


  private:

  //Draws walls
  void drawWalls();

};


class Ball {
  public:
  
  //Class constructor
  Ball(int startPointX, int startPointY, double startBallAngle) {
    pointXY[0] = startPointX;
    pointXY[1] = startPointY;
    ballAngle = startBallAngle;
  }
  

  //Obtains the ball's new position and desired angle
  void setPosition(short int hitWallAndTilt);
  //Finds if wall was hit and returns 0 if not, and an angle of the wall that was hit if so
  short int wallisHit(unsigned int windowWidth, unsigned int windowHeight);


  private:

  double ballAngle;
  double OldBallAngle;

  //[0] is X and [1] is y
  int pointXY[2];
  int oldPointXY[2];

};


#endif