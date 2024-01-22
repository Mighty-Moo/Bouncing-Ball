#include "0_header.hpp"
    

    //Draws wall of 'H'
    void Interface::drawWall() {

      //Clear screen
      std::cout << CLEARSCREEN;

      //Draw Map
      for(int HeightPos = 0; HeightPos != windowHeight; HeightPos++) {
        std::cout << "\033[" << HeightPos << ";" << WALL_BUFFER_SIZE + 1 /* +1 adds a space for the char*/ << "H" << WALL_CHAR << "\033[" << HeightPos << ";" << (WALL_BUFFER_SIZE * 4) - 1 << "H" << WALL_CHAR;
      }
    }
  


//Draws brick wall of '-'
void Interface::drawBrick() {


  //Sets HeightPosition to 0 since it will be that after the screen is cleared. increments until all rows have been gone through
  for(int HeightPos = 0; HeightPos != windowHeight; HeightPos++) {

    //Prints a '-' char until certain position
    for(int widthPos = 0; widthPos != WALL_BUFFER_SIZE + 1; widthPos++) {
      //sets cursor to row position and the current height position
      std::cout << "\033[" << HeightPos << ";" << widthPos << "H";
      std::cout << '-';
    }
    
    //Clear output stream
    std::cout << std::endl;


    //Prints wall on other side of screen
    for(int i = (WALL_BUFFER_SIZE * 4); i <= windowWidth; i++) {
      std::cout << "\033[" << HeightPos << ";" << i << "H";
      std::cout << "-";
    }

    //Clear output stream
    std::cout << std::endl;

  }

}
  

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
  
