#include "0_header.hpp"

//Gets window size and terminates program if window is too small
int Interface::windowSizeUpdate() {
  struct winsize size;

  prevHeight = windowHeight;
  prevWidth = windowWidth;

  //Get window size
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  
  //Set window size variables
  windowHeight = size.ws_row;
  windowWidth = size.ws_col;


  return(0);
}
