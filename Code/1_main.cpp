// Project started on Monday, November 27 2023
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall

#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
int main() {

  //Create an instance of the Interface class
  Interface myInterface;
  //Ball myBall;

  myInterface.prevWidth = 0;
  myInterface.prevHeight = 0;

  //myBall.OldBallAngle = 0;


  //Do this the first time
  myInterface.windowSizeUpdate();
  myInterface.drawWall();
  myInterface.drawBrick();


  for (; ;) {

    //Update window size
    myInterface.windowSizeUpdate();

    if (Win_Height != myInterface.prevHeight || Win_Width != myInterface.prevWidth) {
      myInterface.drawWall();
      myInterface.drawBrick();
    }
  
  }

  
}