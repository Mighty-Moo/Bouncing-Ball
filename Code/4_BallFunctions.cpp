
#include "0_header.hpp"



  void Ball::ball() {

    //Save the ballAngle variable
    OldBallAngle = ballAngle;

    ballAngle = ((2 * wallAngle) - ballAngle + 360) % 360;


  }

void Ball::setPosition() {

  //Speed of the ball
  double speed = 2.0;


  oldPointXY[0] = pointXY[0];
  oldPointXY[1] = pointXY[1];

  //Calculate the new position after hitting the wall
  pointXY[0] = pointXY[0] + speed * cos(ballAngle * (M_PI / 180.0));
  pointXY[1] = pointXY[1] + speed * sin(ballAngle * (M_PI / 180.0));

  std::cout << "\033[" << pointXY[0] << ";" << pointXY[1] << "H◯" << "\033[" << oldPointXY[0] << ";" << oldPointXY[1] << "H " << std::endl;

}
