#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

extern unsigned int windowWidth;
extern unsigned int windowHeight;

void windowSizeUpdate() {
  struct winsize size;
  
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

  windowWidth = size.ws_col;
  windowHeight = size.ws_row;
}
