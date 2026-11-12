#include <iostream>
#include <cstdlib>
#include "GameMenu.h"
#include <string>
#include "Input.h"
#include "ConsoleColor.h"

GameMenu::MenuChoice GameMenu::menuChoice ()
{
	system("cls");
	ConsoleColor::Print(" =*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("  *                                                         *  \n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print(" =*=             Safe Escape Main Menu                     =*= \n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("  *                                                         *  \n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print(" =*=*=*=*=**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print(" =*=*=*=*=**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);


	ConsoleColor::Print("1. Player\n", ConsoleColor::Ink::White);
	ConsoleColor::Print( "2. Select Level\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("3. High Scores\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("4. End\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);


	int input = Input::GetNumber("Enter your choice: ", 1, 4);

	return  static_cast<GameMenu::MenuChoice>(input);
}









//I am getting the hang of this. I can see my menu comming together. I am not sure where to go next but I will keep researching.





