#include "header.h"
#include <iostream>
// Determines the new angle of the ball after it hits the wall
// Access the global variables in main.cpp
extern unsigned int wallAngle;
extern unsigned int ballAngle;
extern unsigned int OldBallAngle;

void ball() {

  // Save the ballAngle variable
  OldBallAngle = ballAngle;

  ballAngle = (2 * wallAngle - ballAngle + 360) % 360;
}
