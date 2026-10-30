#pragma once
#include <string>
#include <iostream>

class Player
{
private:
	std::string name;
	std::string CharacterSymbol;

	int numOfMatches;
	int matchesWon;
public:

	Player(std::string name, std::string CharacterSymbol, int numOfMatches, int matchesWon);

	~Player();
	static Player createNewplayer();

	std::string getName() const;

	std::string getCharacterSymbol() const;

	int getMatchesPlayed() const;

	int getMatchesWon() const;



	void recordResult(bool won);
	void displayHighScore();

};
