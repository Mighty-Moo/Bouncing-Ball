#include "0_Header.hpp"



void Ball::setPosition(short int hitWallAndTilt, unsigned int windowHeight) {

  double speedX = 2.0;
  double speedY = 2.0;
  double posX = 0;
  double posY = 0;
  int distanceTraveled = 0;
  
  //If the ball hit a wall
  if(hitWallAndTilt != 0) {

    //Save the ballAngle variable
    OldBallAngle = ballAngle;
    ballAngle = fmod(((2.0 * hitWallAndTilt) - ballAngle + 360), 360);

  }


  oldPointXY[0] = pointXY[0];
  oldPointXY[1] = pointXY[1];

  //Calculate the new position after hitting the wall
  posX = pointXY[0] + speedX * cos(ballAngle * (M_PI / 180.0));
  posY = pointXY[1] + speedY * sin(ballAngle * (M_PI / 180.0));

  //Get leftover decimal value for sub-pixel rendering
  accumulatedPosX += posX - static_cast<int>(posX);
  accumulatedPosY += posY - static_cast<int>(posY);

  //Set point X and Y to X and Y positions
  pointXY[0] = static_cast<int>(posX);
  pointXY[1] = static_cast<int>(posY);

  if(pointXY[0] + static_cast<int>(accumulatedPosX) <= windowHeight -1) {

    //Add accumulated numbers to the position
    pointXY[0] += static_cast<int>(accumulatedPosX);
    pointXY[1] += static_cast<int>(accumulatedPosY);

    //Subtract used decimal from accumPos so we only have unused decimal value left over
    accumulatedPosX -= static_cast<int>(accumulatedPosX);
    accumulatedPosY -= static_cast<int>(accumulatedPosY);
  }
  else {
    //If the point is out of bounds set to the point at the wall
    pointXY[0] = windowHeight -1;
  }

  //Conditional compilation
  #ifdef DEBUG
    std::cout << "\033[" << pointXY[0] << ";" << pointXY[1] << "H◯" << std::endl;
  #else
    std::cout << "\033[" << pointXY[0] << ";" << pointXY[1] << "H◯" << "\033[" << oldPointXY[0] << ";" << oldPointXY[1] << "H " << std::endl;
  #endif

}

double Ball::balldelay() {


  //Get distance every step in this sim for acurate delay time 
  double adjustedSpeedX = 2.0 * cos(ballAngle * (M_PI / 180.0));
  double adjustedSpeedY = 2.0 * sin(ballAngle * (M_PI / 180.0));

  // Calculate the actual distance traveled in each cycle
  double currentDistance = sqrt(adjustedSpeedX * adjustedSpeedX + adjustedSpeedY * adjustedSpeedY);

  if (currentDistance == 0.0) {
    return(BASE_DELAY);
  }

  //Derive delay time from the steps info
  double adjustedDelay = BASE_DELAY * (1.0 / currentDistance);

  return(adjustedDelay);

}



short int Ball::wallisHit(unsigned int windowWidth, unsigned int windowHeight) {

  //If a vertical wall was hit, return the angle of a vertical wall
  if(pointXY[1] == (windowWidth / 5) + 2 || pointXY[1] == ((windowWidth / 5) * 4) - 2 ) {

  return(180);
  }
  //If a horizontal wall was hit, return the angle of a horizontal wall
  else if(pointXY[0] == windowHeight -1 || pointXY[0] == 1) {

  return(90);
  }
  //Otherwise no wall was hit so return 0 (while 0 could be an angle, it just will say to the other function that no wall was hit. If the angle 0 is nescacarry, we will use 360)
  else {

  return(0);
  }

}


void Ball::adjustPosition(unsigned int prevWindowWidth, unsigned int prevWindowHeight, unsigned int windowWidth, unsigned int windowHeight) {
    //Calculate scaling factors for X and Y coordinates
    double scaleX = static_cast<double>(windowWidth) / prevWindowWidth;
    double scaleY = static_cast<double>(windowHeight) / prevWindowHeight;
    
    //Update ball's X and Y coordinates based on scaling factors
    pointXY[0] = static_cast<int>(pointXY[0] * scaleX);
    pointXY[1] = static_cast<int>(pointXY[1] * scaleY);

    //check if ball was moved out of bounds and correct accordingly
    if(pointXY[1] < (windowWidth/5) +2) {
      pointXY[1] = (windowWidth/5) +2;
    }
    else if(pointXY[1] > ((windowWidth / 5) * 4) -2) {
      pointXY[1] = ((windowWidth / 5) * 4) -2;
    }
    else if(pointXY[0] == windowWidth -1) {
      pointXY[0] = windowWidth -2;
    }
}