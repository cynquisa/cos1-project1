#include "SafeEngine.h"
#include "Input.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include "ConsoleColor.h"


Unlock::Unlock() : num(1)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}
Unlock::~Unlock()
{

}
void Unlock::generate(int min,int maxNumber)
{
	num = (std::rand() % (maxNumber - min + 1)) + min;
}
int Unlock::getValue() const
{
	return num;
}
GuessResult Unlock::evaluateGuess(int userGuess) const
{
	if (userGuess > num)
	{
		return GuessResult::TooHigh;
	}
	else if (userGuess < num)
	{
		return GuessResult::TooLow;
	}
	return GuessResult::Correct;
}
bool Unlock::playLevel(Player& activePlayer)
{
	system("cls");
	ConsoleColor::Print("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("           Select Your Difficulty Level:\n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);


	ConsoleColor::Print("1. Easy  (Guess a number between 1 - 100 out of 15 chances.)\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("2. Hard  (Guess a number between 1 - 150 out of 12 chances.)\n", ConsoleColor::Ink::White);
	
	int levelChoice = Input::GetNumber("Enter game mode (1-2) : ", 1, 2);
	int maxNumber = (levelChoice == 1) ? 100 : 150;
	int chancesLeft = (levelChoice == 1) ? 15 : 12;
	system("cls");

	bool crackedSafe = false;

	generate(1, maxNumber);

	std::cout << "\033[5;31m" << R"(	        ___
    .-"`   `"-.
  .'    .-.    '.
 /     (/^\)     \             __________________________ 
/  #   (\ /)      \          |                           |
| #    .-'-.      |          |  ( 7 ) ( 8 ) ( 9 )   __   |
|     /(_I_)\     |          |  ( 4 ) ( 5 ) ( 6 )  |  |  |
;     \\) (//     ;          |  ( 1 ) ( 2 ) ( 3 )  |  |  |
 ;     / Y \     ;           |     _____________   |  |  |
  \    \ | /    /            |    |    LOCKED   |   \_|  |
   \    \|/    /             |     ¯¯¯¯¯¯¯¯¯¯¯¯¯         |
    \   /|\   /              |___________________________|
     |  \|/  |
     |__/Y\__|
)" << "\033[0m";
	std::cout << "\033[90m" << R"(
     {=======}
     }======={             You look around, no winows,and one door.
     {=======}                   You must find the code esacpe.  
     }======={
  jgs{=======}
      `""u""` )" << "\033[0m\n";


	ConsoleColor::Print("\nYOU ARE TRAPPEd!! You must guess the combination to escape.\n", ConsoleColor::Ink::Red);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);

	std::cout << "Enter a number between 1 and " << maxNumber << ".\n";
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);

	ConsoleColor::Print("You have " + std::to_string (chancesLeft) + "attempts remaining.\n", ConsoleColor::Ink::Red);

	while (chancesLeft > 0 && !crackedSafe)
	{
		int currentGuess = Input::GetNumber("Enter your guess: ", 1, maxNumber);
		GuessResult result = evaluateGuess(currentGuess);

		if (result == GuessResult::TooHigh)
		{
			std::cout << "Too high! Try a lower number.\n";
			chancesLeft--;
		}
		else if (result == GuessResult::TooLow)
		{
			std::cout << "Too low! Enter a higher number.\n";
			chancesLeft--;
		}
		else if (result == GuessResult::Correct)
		{
			ConsoleColor::Print(" ⌈—————————————————————————————————————————————————————————⌉ \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄|       | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊                                                      ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊                                                      ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊	    ========================================       ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |                                         | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |                                         | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |       ( 7 )  ( 8 )  ( 9 )               | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |       ( 4 )  ( 5 )  ( 6 )       _       | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |       ( 1 )  ( 2 )  ( 3 )     /   /     | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |                               |   |     | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |                               |   |     | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |                               |   |     | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |         _ _ _ _ _ _ _ _       | _ |     | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |       {                 }               | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |       {    O P E N      }               | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |       { _ _ _ _ _ _ _ _ }               | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊      |                                         | ⟩    ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊	    ========================================       ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇊                                                      ⇊ | \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" | ⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄| \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print(" ⌊———————————————————————————————————————————————————————— ⌋ \n", ConsoleColor::Ink::Green);
			ConsoleColor::Print("\n", ConsoleColor::Ink::White);
			ConsoleColor::Print("\n", ConsoleColor::Ink::White);
			ConsoleColor::Print("\n", ConsoleColor::Ink::White);

			ConsoleColor::Print("\nAmazing!! You have cracked the safe and now you can escape now!\n", ConsoleColor::Ink::Green);
			crackedSafe = true;
		}

		if (!crackedSafe && chancesLeft > 0)
		{
			ConsoleColor::Print( "Chances remaining: " + std::to_string( chancesLeft) + "\n\n", ConsoleColor::Ink::Red);
			crackedSafe = false;

		}

	}

if (!crackedSafe)
{


	ConsoleColor::Print("GAMEOVER !! You have run out of guessess. The correct combination was: " + std::to_string(getValue()) + "\n", ConsoleColor::Ink::Red);
}
	activePlayer.recordResult(crackedSafe);

	Input::Pause("\nPress Enter to return to the main menu...");
	return crackedSafe;
}



