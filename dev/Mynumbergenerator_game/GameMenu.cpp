#include <iostream>
#include "GameMenu.h"
#include <string>
#include "Input.h"
#include "ConsoleColor.h"

GameMenu::MenuChoice GameMenu::menuChoice ()
{
	
	ConsoleColor::Print("1. Player\n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print( "2. Select Level\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("3. High Scores\n", ConsoleColor::Ink::Red);
	ConsoleColor::Print("4. End\n", ConsoleColor::Ink::Green);

	int input = Input::GetNumber("Enter your choice: ", 1, 4);

	return  static_cast<GameMenu::MenuChoice>(input);
}









//I am getting the hang of this. I can see my menu comming together. I am not sure where to go next but I will keep researching.





