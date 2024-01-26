// Project started on Monday, November 27 2023
// Ball physics and walls UI now complete
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall
#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
int main() {

  //Create an instance of the Interface class
  Interface myInterface;
  Ball myBall;
  bool error;


  myBall.wallAngle = 180;
  myBall.OldBallAngle = 0;
  myBall.ballAngle = 45;


  //Do this the first time
  myInterface.windowSizeUpdate();
  myInterface.drawWall();
  myInterface.drawBrick();

  myBall.pointXY[0] = 12;
  myBall.pointXY[1] = myInterface.windowWidth/2;


  //Update window size after variable saves in case the player resized the screen
  myInterface.windowSizeUpdate();
  for (; ;) {
    error = false;


    while (myInterface.windowSizeUpdate(), myInterface.windowHeight == myInterface.prevHeight && myInterface.windowWidth == myInterface.prevWidth) {
      usleep(100000);

      //Checks if the ball hit a wall and if so, calculates the balls new angle
      if(myBall.pointXY[1] == (myInterface.windowWidth / 5) + 2 || myBall.pointXY[1] == ((myInterface.windowWidth / 5) * 4) - 2 ) {

        myBall.ball(180);
        
      }
      else if(myBall.pointXY[0] == myInterface.windowHeight -1 || myBall.pointXY[0] == 1) {
        myBall.ball(90);

      }
      
      myBall.setPosition(); //Make private and access through ball




    }
    

    //Since we already know that the window size changed, we don't need to use an if statement to check if it has changed and if so, updates UI  
    //Tells player if window is too small
    if(myInterface.windowHeight < 10 || myInterface.windowWidth < 40) {
      std::cout << "\033[2J\033[0;0H";
      std::cerr << "Literally Unplayable" << std::endl;
      error = true;
    }

    if(error == false) {

      //Update UI
      myInterface.drawWall();
      myInterface.drawBrick();

      #ifdef DEBUG
        std::cout << "Previous Height: " << myInterface.prevHeight << " Previous Width: " << myInterface.prevWidth << std::endl;
        std::cout << "Window Height: " << myInterface.windowHeight << " Window Width: " << myInterface.windowWidth << std::endl;
      #endif

    }
  
  }

  
}