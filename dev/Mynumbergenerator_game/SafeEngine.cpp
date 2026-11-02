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
void Unlock::generate(int min,int max)
{
	num = (std::rand() % (max - min + 1)) + min;
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
bool Unlock::playLevel(int maxNumber, int maxChances)
{
	generate(1, maxNumber);

	int chancesLeft = maxChances;
	bool crackedSafe = false;

	std::cout << "\nYOU ARE TRAPPEd!! You must guess the combination to escape.\n";
	std::cout << "Enter a number between 1 and " << maxNumber << ".\n";
	std::cout << "You have " << maxChances << "attempts remaining.\n";

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
			std::cout << "\nAmazing!! You have crakced the safe and can escape now!\n";
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
	return crackedSafe;
}



