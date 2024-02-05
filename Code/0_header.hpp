#ifndef _0_HEADER_HPP
#define _0_HEADER_HPP

#include <iostream>
#include <sys/ioctl.h>
#include <cmath>
#include <unistd.h>
#include <ncurses.h>


//For conditional compilation
#define DEBU
//Define a clearscreen shortcut
#define CLEARSCREEN "\033[2J"
#define WALL_CHAR "H"
#define WALL_BUFFER_SIZE (windowWidth / 5)
#define BASE_DELAY 500000

void runSim(int ballStartAngle);



class Interface {
  public:

  //Gets window size and also terminates program if window is too small
  int windowSizeUpdate();
  void displayGenericMenu(const char* options[], int selectedOption, unsigned int arraySize, Interface &myInterface);

  unsigned int windowWidth;    //The Height of the terminal
  unsigned int windowHeight;   //The Width of the terminal
  unsigned int prevWidth;      //The Previous Width of the terminal
  unsigned int prevHeight;     //The Previous Height of the terminal

};

class SimInterface : public Interface {
  public:


  //Updates map for window resizes and if window is too small after resize, an error is displayed.
  void updateMap();

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
    accumulatedPosY = 0;
    accumulatedPosX = 0;
  }
  
  //Obtains the ball's new position and desired angle
  void setPosition(short int hitWallAndTilt, unsigned int windowHeight);
  //Finds if wall was hit and returns 0 if not, and an angle of the wall that was hit if so
  short int wallisHit(unsigned int windowWidth, unsigned int windowHeight);
  //Get ball animation delay
  double balldelay();
  void adjustPosition(unsigned int prevWindowWidth, unsigned int prevWindowHeight, unsigned int windowWidth, unsigned int windowHeight);

  private:

  //Ball's angle
  double ballAngle;
  double OldBallAngle;
  double accumulatedPosY;
  double accumulatedPosX;
  //[0] is X and [1] is y
  int pointXY[2];
  int oldPointXY[2];

};


#endif