
#include "0_header.hpp"



  void Ball::ball(double wallTilt) {

    //Save the ballAngle variable
    OldBallAngle = ballAngle;

    ballAngle = fmod(((2.0 * wallTilt) - ballAngle + 360), 360);


  }

void Ball::setPosition() {

  double speedX = 2.0;
  double speedY = 2.0;
  


    oldPointXY[0] = pointXY[0];
    oldPointXY[1] = pointXY[1];

    //Calculate the new position after hitting the wall
    pointXY[0] = round(pointXY[0] + speedX * cos(ballAngle * (M_PI / 180.0)));
    pointXY[1] = round(pointXY[1] + speedY * sin(ballAngle * (M_PI / 180.0)));

    std::cout << "\033[" << pointXY[0] << ";" << pointXY[1] << "H◯" << "\033[" << oldPointXY[0] << ";" << oldPointXY[1] << "H " << std::endl;

}
