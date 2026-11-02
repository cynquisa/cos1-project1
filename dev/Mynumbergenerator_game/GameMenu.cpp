#include <iostream>
#include "GameMenu.h"
#include <string>
#include "Input.h"

MenuChoice menuChoice ()
{
	
	std::cout << "1. Player\n";
	std::cout << "2. Select Level\n";
	std::cout << "3. High Scores\n";
	std::cout << "4. End\n";

	int input = Input::GetNumber("Enter your choice: ", 1, 4);

	return  static_cast<MenuChoice>(input);
}




















/*I am getting the hang of this. I can see my menu comming together. I am not sure where to go next but I will keep researching.


	int input = 0;
	std::cout << "1. player\n2. Select Level\n3. High Scores\n4. Exit\n";
	std::cout << "Enter your choice: ";
	std::cin >> input;

	MenuChoice choice = static_cast<MenuChoice>(input);
	menuChoice;
	return 0;
	this how I couud test the menu in the main.*/




