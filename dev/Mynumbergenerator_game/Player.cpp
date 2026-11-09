#include "Player.h"
#include "Input.h"
#include <iostream>
#include <string>
#include <vector>
#include "ConsoleColor.h"



Player::Player(std::string name, std::string CharacterSymbol, int numOfMatches, int matchesWon )
	: name(name), CharacterSymbol(CharacterSymbol), numOfMatches(numOfMatches), matchesWon(matchesWon)
{ 

}

	Player::~Player()
{
}

Player Player::createNewPlayer()

{
	ConsoleColor::Print( "※※※※※※※※※※※※※※※※※※ Player Creation ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);


	std::string nameInput = Input::GetString("Enter your player name please: ");

	std::vector<std::string> characterChoice;
	characterChoice.push_back("¬_¬");
	characterChoice.push_back("^_^");
	characterChoice.push_back("(*_*)");
	characterChoice.push_back("<>_<>");

	
	ConsoleColor::Print("\nChoose your character: \n", ConsoleColor::Ink::Yellow);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);

	

	for (size_t i = 0; i < characterChoice.size(); ++i)
	{
		ConsoleColor::Print(std::to_string(i + 1) + ". Faces " + characterChoice[i] + "\n", ConsoleColor::Ink::Cyan);
	}
	

	int choice = Input::GetNumber("Select choice (1-4): ", 1, static_cast<int>(characterChoice.size()));
	
	std::string selectedSymbol = characterChoice[choice - 1];

	ConsoleColor::Print("Your player is created! Welcome,  " + nameInput + " " + selectedSymbol + "\n\n", ConsoleColor::Ink::Green);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	

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

void Player::displayHighScore() const
{
	ConsoleColor::Print("\n========================================================== = \n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("Player Stats: ", ConsoleColor::Ink::Purple);
	ConsoleColor::Print(name, ConsoleColor::Ink::Purple);
	ConsoleColor::Print( " Avatar: ", ConsoleColor::Ink::Purple);
	ConsoleColor::Print((CharacterSymbol + "\n"), ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n========================================================== = \n", ConsoleColor::Ink::Purple);

	std::cout << "Games Played: " << numOfMatches << '\n';

	std::cout << "Safes Cracked: " << matchesWon << '\n';
}









/*I know that in the future I would like to give the player a choice as to somesort of symbol to 
represent themselves but for now we will only take the name and list a few game stats like number of games played and  won.
I have decide to store my character selectiion in a vector */

