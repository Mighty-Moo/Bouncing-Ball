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

//Function to display the menu
void Interface::displayGenericMenu(const char* options[], int selectedOption, unsigned int arraySize, Interface &myInterface) {
  //Clear the screen
  std::cout << CLEARSCREEN;

  //Print the centered menu name bold
  std::cout << "\033[39m\033[1m\033[0;" << (myInterface.windowWidth - strlen(options[0])) / 2 << "H" << options[0] << "\033[22m" << std::endl;

  //Print menu options
  for (int i = 1; i < arraySize; ++i) {
		//If printing the current option
    if (i == selectedOption + 1) {
			//Highlight selected option and souround with un-highlighted '<'
			std::cout << "\033[" << (i * 2) + 6 << ";" << (((myInterface.windowWidth - strlen(options[i])) / 2) - 1) << "H" << "<" << std::endl;
			std::cout << "\033[7m" << std::endl;
			
  	}

    //Print options centered
    std::cout << "\033[" << (i * 2) + 6 /*number added is starting point, the multiplier is gap between each item*/ << ";" << ((myInterface.windowWidth - strlen(options[i])) / 2) << "H" << options[i] << std::endl;

    if (i == selectedOption + 1) {
			//Turn off highlighting
      std::cout << "\033[27m" << std::endl;
			//Souround with '>'
			std::cout << "\033[" << (i * 2) + 6 << ";" << (((myInterface.windowWidth - strlen(options[i])) / 2) + strlen(options[i])) << "H" << ">" << std::endl;
    }
  }
}