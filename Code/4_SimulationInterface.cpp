#include "0_Header.hpp"



// Draws brick wall of '-' and 'H'
void SimInterface::drawWalls() {


  std::cout << CLEARSCREEN;

  // Sets HeightPosition to 0 since it will be that after the screen is cleared. increments until all rows have been gone through
  for(int HeightPos {1}; HeightPos != windowHeight; HeightPos++) {

    // Clear output stream
    std::cout << std::endl;

    // Prints a '-' char until certain position
    for(int widthPos {0}; widthPos != WALL_BUFFER_SIZE + 1; widthPos++) {
      //sets cursor to row position and the current height position
      std::cout << "\033[" << HeightPos << ";" << widthPos << "H";
      std::cout << '-';
    }

    // Print the outer walls
    std::cout << "H";
    std::cout << "\033[" << HeightPos << ";" << ((WALL_BUFFER_SIZE * 4) - 1) << "H" << "H" << std::endl;


    // Prints wall on other side of screen
    for(int i {(WALL_BUFFER_SIZE * 4)}; i <= windowWidth; i++) {
      std::cout << "\033[" << HeightPos << ";" << i << "H";
      std::cout << "-";
    }

  }

}
  


  
void SimInterface::updateMap() {

  bool error {false};

  //Since we already know that the window size changed, we don't need to use an if statement to check if it has changed and if so, updates UI  
  //Tells player if window is too small
  if (windowHeight < 10 || windowWidth < 40) {
    std::cerr << "\033[2J\033[0;0H" << "Literally Unplayable" << std::endl;
    error = true;
  }

  if(!error) {

    //Update UI
    drawWalls();


    #ifdef DEBUG
      std::cout << "Previous Height: " << prevHeight << " Previous Width: " << prevWidth << std::endl;
      std::cout << "Window Height: " << windowHeight << " Window Width: " << windowWidth << std::endl;
    #endif

  }
}
