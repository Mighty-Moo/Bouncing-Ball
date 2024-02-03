#include "0_header.hpp"



int main() {
	setenv("TERM", "xterm-256color", 1);

	// Define menu options
  const char* Menus[4][5] = {
		{"Bouncing-Ball", "Run", "Options", "About"},
		{"Run Menu", "Run New", "Back"},
		{"Options", "Change Ball's Angle", "Option 2", "Back"},
		{"About", "Back"}
	};

	unsigned int arraySize = 0;
  int selectedOption = 0;
  int choice = 0;
	int currentMenu = 0;
	int prevMenu = 0;
	//Set a default value for the ball's angle
	int desiredBallAngle = 45;

  //Initialize ncurses
  initscr();
	//Enable special keys
  keypad(stdscr, TRUE);
	//Do not display input characters
  noecho();
	refresh();

	Interface myInterface;

	myInterface.windowSizeUpdate();

		
	//Hide cursor
	std::cout << "\033[?25l";

  while (true) {

		//Get the number of elements in the row
		//Unfortunately we have to loop through till we encounter a null pointer because the array points to pointers.
		arraySize = 0;
		while (Menus[currentMenu][arraySize] != nullptr) {
    	arraySize++;
		}

		myInterface.windowSizeUpdate();

    //Display the menu
    myInterface.displayGenericMenu(Menus[currentMenu], selectedOption, arraySize, myInterface);

    //Get user input
    choice = getch();

    //Handle arrow key input
    switch (choice) {
    	case KEY_UP:
				//If the key is up, decrement the selected option and obtain it's remainder when divided by the strings total size to wrap the value back to zero
    		selectedOption = (selectedOption - 1 + (arraySize - 1)) % (arraySize -1);

    	break;
    	case KEY_DOWN:
				//Bassically the oposite of key up
    	  selectedOption = (selectedOption + 1) % (arraySize -1);
    	break;
    	case 10:  //Enter key
      	std::cout << CLEARSCREEN << std::endl;  //Clear the screen before printing the message
				if(currentMenu == 0) {
					//Save that we were here
					prevMenu = currentMenu;
					currentMenu = selectedOption + 1;
					//Set to zero so the cursor is on the first option
					selectedOption = 0;
				}
				//Check if selected option is last in array
				else if(selectedOption + 2 == arraySize) {
					//Go to previous menu
					currentMenu = prevMenu;
				}
				else {
					//Really wish I could use switch case
					//Check if the current menu item is an option that opens more code and if so run that code
					//Strmcp returns 0 if strings match
					if(strcmp(Menus[currentMenu][(selectedOption +1)], "Run New") == 0)	{
						std::cout << "Runing...";
						runSim(desiredBallAngle);
						usleep(500000);
					}
					else if(strcmp(Menus[currentMenu][(selectedOption +1)], "Change Ball's Angle") == 0) {
						char choice;
						std::cout << "\033[39m\033[1m\033[" << (myInterface.windowHeight / 2) << ";" << (myInterface.windowWidth - strlen("Set to: ")) / 2 << "H" << "Set to: " << "\033[22m";
						//Turn on visible input characters so the users can see what is being typed
						echo();
						refresh();
						desiredBallAngle = getch() % 360;
						usleep(400000);
						//Turn off visible input characters so the users can't see what is being typed
						noecho();
						refresh();
					}
					else if(strcmp(Menus[currentMenu][(selectedOption +1)], "Option 2") == 0) {
						std::cout << "Done Option 2";
						refresh();
						usleep(500000);
					}
					else {
						//If somthing is wrong, leave a message and exit the program
						std::cout << "This error should never surface but if it somhow did, I need to do somthing" << std::endl;
						return(0);
					}
				}
			break;

				
			//Move current menu to get make string hold diffrent value to get to value equal to proper menu
			//Wait for user input before returning to the menu
      getch();
    	break;
		}
  }

  //End ncurses
  endwin();

  return 0;
}
