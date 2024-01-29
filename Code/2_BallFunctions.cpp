#include "0_header.hpp"



void Ball::setPosition(short int hitWallAndTilt) {

  double speedX = 2.0;
  double speedY = 2.0;
  
  if(hitWallAndTilt =! 0) {
    //Save the ballAngle variable
    OldBallAngle = ballAngle;

    ballAngle = fmod(((2.0 * hitWallAndTilt) - ballAngle + 360), 360);
  }


  oldPointXY[0] = pointXY[0];
  oldPointXY[1] = pointXY[1];

  //Calculate the new position after hitting the wall
  pointXY[0] = round(pointXY[0] + speedX * cos(ballAngle * (M_PI / 180.0)));
  pointXY[1] = round(pointXY[1] + speedY * sin(ballAngle * (M_PI / 180.0)));

  std::cout << "\033[" << pointXY[0] << ";" << pointXY[1] << "H◯" << "\033[" << oldPointXY[0] << ";" << oldPointXY[1] << "H " << std::endl;

}

short int wallisHit(unsigned int windowWidth, unsigned int windowHeight) {

  if(pointXY[1] == (windowWidth / 5) + 2 || pointXY[1] == ((windowWidth / 5) * 4) - 2 ) {

  return(180);
  }
  else if(pointXY[0] == windowHeight -1 || pointXY[0] == 1) {

  return(90);
  }
  else {

  return(0);
  }

}
