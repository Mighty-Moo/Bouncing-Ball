#include <iostream>
#include <ncurses.h>
#include <cstring>
#include "0_header.hpp"

//Function to display the menu
void displayMenu(const char* options[], int selectedOption, unsigned int arraySize, Interface &myInterface) {
  //Clear the screen
  std::cout << CLEARSCREEN;

  //Print the centered menu name
  std::cout << "\033[0;" << (myInterface.windowWidth - strlen(options[0])) / 2 << "H" << options[0] << std::endl;

  //Print menu options
  for (int i = 1; i < arraySize; ++i) {
    if (i == selectedOption + 1) {
			std::cout << "\033[" << (i * 2) + 6 << ";" << (((myInterface.windowWidth - strlen(options[i])) / 2) - 1) << "H" << "<" << std::endl;
			std::cout << "\033[7m" << std::endl;
			
  	}

    //Print options centered
    std::cout << "\033[" << (i * 2) + 6/*number added is starting point, the multiplier is gap between each item*/ << ";" << ((myInterface.windowWidth - strlen(options[i])) / 2) << "H" << options[i] << std::endl;

    if (i == selectedOption + 1) {
      std::cout << "\033[27m" << std::endl;  //Turn off highlighting
			std::cout << "\033[" << (i * 2) + 6 << ";" << (((myInterface.windowWidth - strlen(options[i])) / 2) + strlen(options[i])) << "H" << ">" << std::endl;
    }
  }
}

int main() {
	// Define menu options
  const char* mainMenu[] = {"My Menu Name", "Run", "Options", "About"};
	unsigned int arraySize = sizeof(mainMenu) / sizeof(mainMenu[0]);
  int selectedOption = 0;
  int choice;

  //Initialize ncurses
  initscr();
	//Enable special keys
  keypad(stdscr, TRUE);
	//Do not display input characters
  noecho();

	Interface myInterface;

	myInterface.windowSizeUpdate();

		
	//Hide cursor
	std::cout << "\e[?25l";

  while (true) {
		myInterface.windowSizeUpdate();
    //Display the menu
    displayMenu(mainMenu, selectedOption, arraySize, myInterface);

    //Get user input
    choice = getch();

    //Handle arrow key input
    switch (choice) {
    	case KEY_UP:
    		selectedOption = (selectedOption - 1 + 3) % 3;
    	break;
    	case KEY_DOWN:
    	  selectedOption = (selectedOption + 1) % 3;
    	break;
    	case 10:  //Enter key
      	std::cout << CLEARSCREEN << std::endl;  //Clear the screen before printing the message
				std::cout << "\033[" << (myInterface.windowHeight / 2) << ";" << ((myInterface.windowWidth - strlen("Option   selected.")) / 2) << "H" << "Option " << selectedOption + 1 << " selected" << std::endl;
      	getch();    //Wait for user input before returning to the menu
    	break;
		}
  }

  //End ncurses
  endwin();

  return 0;
}
