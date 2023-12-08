#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "0_header.hpp"

extern unsigned int windowWidth;
extern unsigned int windowHeight;

int windowSizeUpdate() {
  struct winsize size;
  
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

  windowWidth = size.ws_col;
  windowHeight = size.ws_row;

  //Tells player if window is too small
  if(windowHeight < 2 || windowWidth < 25) {
    std::cout << "\033[2J\033[0;0H";
    std::cout << "Literally Unplayable";
    //If window is too small, close program
    return(-1);
  }
  return(1);
}
