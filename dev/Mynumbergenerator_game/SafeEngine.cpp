#include "SafeEngine.h"
#include "Input.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

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
	std::cout << "Select Difficulty Level:\n";
	std::cout << "1. Easy Guess a number between 1 - 100 out of 15 chances.\n";
	std::cout << "2. Hard Guess a number between 1 - 150 out of 12 chances.\n";
	
	int levelChoice = Input::GetNumber("Enter game mode (1-2) : ", 1, 2);
	int maxNumber = (levelChoice == 1) ? 100 : 150;
	int chancesLeft = (levelChoice == 1) ? 15 : 12;

	bool crackedSafe = false;

	generate(1, maxNumber);


	std::cout << "\nYOU ARE TRAPPEd!! You must guess the combination to escape.\n";
	std::cout << "Enter a number between 1 and " << maxNumber << ".\n";
	std::cout << "You have " << chancesLeft << "attempts remaining.\n";

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
			std::cout << "\nAmazing!! You have cracked the safe and can escape now!\n";
			crackedSafe = true;
		}

		if (!crackedSafe && chancesLeft > 0)
		{
			std::cout << "Chances remaining: " << chancesLeft << "\n\n";
		}

	}

if (!crackedSafe)
{
	std::cout << "GAMEOVER !! You have run out of guessess. The correct combination was: " << getValue() << "\n";
}
	activePlayer.recordResult(crackedSafe);

	return crackedSafe;
}



