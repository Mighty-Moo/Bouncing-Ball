// Project started on Monday, November 27th 2023
// Ball physics and walls UI completed on Friday, January 26th 2024
// Make a simulation where a ball bounces off a wall and you control the ball by changing the angle of a wall
#include "0_header.hpp"



//Main is in charge of calling and integrating all of these functions
void runSim(int ballStartAngle) {
  int choice = 0;

  //Create an instance of the Interface and Ball classes
  SimInterface myInterface;

  //Update window size since Ball's constructor relies on it
  myInterface.windowSizeUpdate();

  Ball myBall(myInterface.windowHeight/2, myInterface.windowWidth/2, ballStartAngle);


  //Update window sizes and update map
  myInterface.windowSizeUpdate();
  myInterface.updateMap();

  //Don't wait for input
  nodelay(stdscr, TRUE);

  //While user hasn't pressed enter
  while(choice != 10) {

    choice = getch();


    //Check if window hieght hasnt changed and if so, proceeds to output the ball animation
    while (myInterface.windowSizeUpdate(), myInterface.windowHeight == myInterface.prevHeight && myInterface.windowWidth == myInterface.prevWidth && choice != 10) {
      
      choice = getch();
      //Animation delay

      myBall.setPosition(myBall.wallisHit(myInterface.windowWidth, myInterface.windowHeight), myInterface.windowHeight);
      usleep(myBall.balldelay());

    }

    //Update map and scale ball position in a window size change
    myInterface.updateMap();
    myBall.adjustPosition(myInterface.prevWidth, myInterface.prevHeight, myInterface.windowWidth, myInterface.windowHeight);
    myInterface.windowSizeUpdate();
    //Delay in case window is changed quickly and so we dont have to try to keep up with the impossible
    usleep(100000);

  }

  //Reset wait for input to waiting for input
  nodelay(stdscr, FALSE);

}