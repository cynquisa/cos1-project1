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

	std::cout << "\nYOU ARE TRAPPED!! You must enter combinat between 1 and " << maxNumber << ".\n";
	std::cout << "You have " << maxChances << "attempts remaining.\n";

	while (chancesLeft > 0)
	{
		int currentGuess = Input::GetString("Enter your guess: ", 1, maxNumber);
	}
}


bool Unlock::playLevel(int maxNumber, int maxChances)
{
	this->generate(1, maxNumber);
	int attempt = 0;
	bool safeCracked = false;

	std::cout << "\nYOU ARE TRAPPED!! You must find the combination to escape.\n";


}
