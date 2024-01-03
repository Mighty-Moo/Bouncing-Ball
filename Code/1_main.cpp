// Project started on Monday, November 27 2023
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall
#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
int main() {
  //Create an instance of the Interface class
  Interface myInterface;
  //Ball myBall;



  //myBall.OldBallAngle = 0;


  //Do this the first time
  myInterface.windowSizeUpdate();
  myInterface.drawWall();
  myInterface.drawBrick();


  for (; ;) {

    //Update window size
    myInterface.windowSizeUpdate();

    if (myInterface.windowHeight != myInterface.prevHeight || myInterface.windowWidth != myInterface.prevWidth) {
    
      myInterface.drawWall();
      myInterface.drawBrick();
      std::cout << "Previous Height: " << myInterface.prevHeight << " Previous Width: " << myInterface.prevWidth << std::endl;
      std::cout << "Window Height: " << myInterface.windowHeight << " Window Width: " << myInterface.windowWidth << std::endl;
    }
  
  }

  
}