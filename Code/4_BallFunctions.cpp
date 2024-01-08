/* 
#include "0_header.hpp"

  //Gets ball position
void Ball::ballDistance() {

  //Distance from point a to b
  double distance;

  //Pythagorean theorm to find the distance from the ball's current point to it's next point. ((X - NX)^2) + ((Y - NY)^2)
  distance = sqrt(pow((pointXY[0] - newPointXY[0]), 2) + pow((pointXY[1] - newPointXY[1]), 2));

  pointXY[1] = pointXY[1] + distance * cos((ballAngle * (M_PI / 180)));
  pointXY[0] = pointXY[0] + distance * sin((ballAngle * (M_PI / 180)));
}


  void Ball::ball() {

    //Save the ballAngle variable
    OldBallAngle = ballAngle;

    ballAngle = (2 * wallAngle - ballAngle + 360) % 360;


  }
  */
