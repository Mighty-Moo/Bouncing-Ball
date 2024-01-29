// Project started on Monday, November 27th 2023
// Ball physics and walls UI completed on Friday, January 26th 2024
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall
#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
int main() {

  //Create an instance of the Interface class
  Interface myInterface;
  Ball myBall(12, myInterface.windowWidth/2, 45);
  bool error;




  //Do this the first time
  myInterface.windowSizeUpdate();
  myInterface.drawWall();
  myInterface.drawBrick();



  //Update window size after variable saves in case the player resized the screen
  myInterface.windowSizeUpdate();
  for (; ;) {
    error = false;

    //Check if window hieght hasnt changed and if so, proceeds to output the ball animation
    while (myInterface.windowSizeUpdate(), myInterface.windowHeight == myInterface.prevHeight && myInterface.windowWidth == myInterface.prevWidth) {

      usleep(100000);

      myBall.setPosition(myBall.wallisHit(myInterface.windowWidth, myInterface.windowHeight));

    }
    

    //Since we already know that the window size changed, we don't need to use an if statement to check if it has changed and if so, updates UI  
    //Tells player if window is too small
    if(myInterface.windowHeight < 10 || myInterface.windowWidth < 40) {
      std::cerr << "\033[2J\033[0;0H" << "Literally Unplayable" << std::endl;
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