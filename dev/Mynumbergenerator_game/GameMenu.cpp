#include <iostream>
#include "GameMenu.h"
#include <string>
#include "Input.h"
#include "ConsoleColor.h"

GameMenu::MenuChoice GameMenu::menuChoice ()
{
	
	ConsoleColor::Print("1. Player\n", ConsoleColor::Ink::Yellow);
	ConsoleColor::Print( "2. Select Level\n", ConsoleColor::Ink::Yellow);
	ConsoleColor::Print("3. High Scores\n", ConsoleColor::Ink::Yellow);
	ConsoleColor::Print("4. End\n", ConsoleColor::Ink::Yellow);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);


	int input = Input::GetNumber("Enter your choice: ", 1, 4);

	return  static_cast<GameMenu::MenuChoice>(input);
}









//I am getting the hang of this. I can see my menu comming together. I am not sure where to go next but I will keep researching.





