#include "Player.h"
#include "Input.h"
#include <iostream>
#include <string>
#include <vector>




Player::Player(std::string name, std::string CharacterSymbol, int numOfMatches, int matchesWon )
	: name(name), numOfMatches(numOfMatches), matchesWon(matchesWon), CharacterSymbol(CharacterSymbol)
{ 

}

	Player::~Player()
{
}

Player Player::createNewplayer()

{
	std::cout << "※※※※※※※※※※※※※※※※※※ Player Creation ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n";

	std::string nameInput = Input::GetString("Enter your player name please: ");

	std::vector<std::string> characterChoice;
	characterChoice.push_back("¬_¬");
	characterChoice.push_back("^_^");
	characterChoice.push_back("(*_*)");
	characterChoice.push_back("<>_<>");

	
	std::cout << "\nChoose your character: \n";

	for (size_t i = 0; i < characterChoice.size(); ++i)
	{
		std::cout << i + 1 << ". Faces " << characterChoice[i] << "\n";
	}
	int choice = Input::GetNumber("Select choice (1-4): ", 1, static_cast<int>(characterChoice.size()));
	
	std::string selectedSymbol = characterChoice[choice - 1];
	std::cout << "Your player is created! Welcome,  " << nameInput << " " << selectedSymbol << "\n\n";

	return Player(nameInput, selectedSymbol, 0, 0);
}



std::string Player::getName() const
{
	return name;
}

int Player::getMatchesPlayed() const
{
	return numOfMatches;
}

int Player::getMatchesWon() const
{
	return matchesWon;
}

std::string Player::getCharacterSymbol() const
{
	return CharacterSymbol;
}


void Player::recordResult(bool won)
{
	numOfMatches++;
	if (won)
	{
		matchesWon++;
	}
}

void Player::displayHighScore()
{
	std::cout << "\n========================================================== = \n";
	std::cout << "Player Stats: " << name << "Avatar: " << CharacterSymbol << '\n';
	std::cout << "\n========================================================== = \n";

	std::cout << "Games Played: " << numOfMatches << '\n';

	std::cout << "Safes Cracked: " << matchesWon << '\n';
}









/*I know that in the future I would like to give the player a choice as to somesort of symbol to 
represent themselves but for now we will only take the name and list a few game stats like number of games played and  won.
I have decide to store my character selectiion in a vector */

