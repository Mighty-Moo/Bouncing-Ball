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

// Forward declaration of runSim (Sim.cpp)
void runSim(int ballStartAngle, int delayBaseUnit);


class Interface {
  public:

  //Gets window size and also terminates program if window is too small
  int windowSizeUpdate();
  void displayGenericMenu(const char* options[], int selectedOption, unsigned int arraySize, Interface &myInterface);

  unsigned int windowWidth;    // The width of the terminal
  unsigned int windowHeight;   // The height of the terminal
  unsigned int prevWidth;      // The previous width of the terminal
  unsigned int prevHeight;     // The previous height of the terminal

};

class SimInterface : public Interface {
  public:

  //Updates map for window resizes and if window is too small after resize, an error is displayed.
  void updateMap();

  private:

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
  double balldelay(int baseDelay);
  void adjustPosition(unsigned int prevWindowWidth, unsigned int prevWindowHeight, unsigned int windowWidth, unsigned int windowHeight);

  private:

  // TODO - is it possible to initlize variables down here?
  //Ball's angle
  double ballAngle;
  double OldBallAngle;
  //The acuumulated values of decimal of the ball's position
  double accumulatedPosY;
  double accumulatedPosX;
  //[0] is X and [1] is y
  int pointXY[2];
  int oldPointXY[2];

};


#endif
