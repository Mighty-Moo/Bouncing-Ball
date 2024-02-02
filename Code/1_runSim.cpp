// Project started on Monday, November 27th 2023
// Ball physics and walls UI completed on Friday, January 26th 2024
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall
#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
int runSim(int ballStartAngle) {



  //Create an instance of the Interface and Ball classes
  SimInterface myInterface;

  myInterface.windowSizeUpdate();

  Ball myBall(myInterface.windowHeight/2, myInterface.windowWidth/2, ballStartAngle);

  //Update window sizes and update map
  myInterface.windowSizeUpdate();
  myInterface.updateMap();



  //Update window size after variable saves in case the player resized the screen
  myInterface.windowSizeUpdate();

  for (; ;) {


    //Check if window hieght hasnt changed and if so, proceeds to output the ball animation
    while (myInterface.windowSizeUpdate(), myInterface.windowHeight == myInterface.prevHeight && myInterface.windowWidth == myInterface.prevWidth) {

      //Animation delay
      usleep(100000);

      myBall.setPosition(myBall.wallisHit(myInterface.windowWidth, myInterface.windowHeight));

    }

    myInterface.updateMap();
    
  
  }
  
}