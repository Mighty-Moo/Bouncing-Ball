// Project started on Monday, November 27 2023
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall
#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
int main() {

  //Create an instance of the Interface class
  Interface myInterface;
  // Ball myBall;
  bool error;



  //myBall.OldBallAngle = 0;


  //Do this the first time
  myInterface.windowSizeUpdate();
  myInterface.drawWall();
  myInterface.drawBrick();


 
  for (; ;) {
    error = false;

    //Update window size
    myInterface.windowSizeUpdate();



    //Checks if window size has changed and if so, updates UI
    if (myInterface.windowHeight != myInterface.prevHeight || myInterface.windowWidth != myInterface.prevWidth) {
      
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

  
}