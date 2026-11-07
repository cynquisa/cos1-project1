// Mynumbergenerator_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameMenu.h"
#include "SafeEngine.h"
#include "Player.h"
#include "Input.h"
#include <string>
#include <vector>
#include <Windows.h>


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Unlock safeGame;

	GameMenu gameMenu;

	Player* activePlayer = nullptr;

	bool isRunning = true;

	std::cout << " =*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n";
	std::cout << "  *                                                         *  \n";
	std::cout << " =*=              Welcome To Safe Escape                   =*= \n";
	std::cout << "  *                                                         *  \n";
	std::cout << " =*=*=*=*=**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n";
	std::cout << " =*=*=*=*=**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n";
	std::cout << " ⌈—————————————————————————————————————————————————————————⌉ \n";
	std::cout << " | ⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄ | \n";
	std::cout << " | ⇊                                                      ⇊ | \n";
	std::cout << " | ⇊                                                      ⇊ | \n";
	std::cout << " | ⇊	    ========================================      ⇊ | \n";
	std::cout << " | ⇊      |                                         |     ⇊ | \n";
	std::cout << " | ⇊      |                                         |     ⇊ | \n";
	std::cout << " | ⇊      |       ( 7 )  ( 8 )  ( 9 )               |     ⇊ | \n";
	std::cout << " | ⇊      |       ( 4 )  ( 5 )  ( 6 )       _       |     ⇊ | \n";
	std::cout << " | ⇊      |       ( 1 )  ( 2 )  ( 3 )     /   /     |     ⇊ | \n";
	std::cout << " | ⇊      |                               |   |     |     ⇊ | \n";
	std::cout << " | ⇊      |                               |   |     |     ⇊ | \n";
	std::cout << " | ⇊      |                               |   |     |     ⇊ | \n";
	std::cout << " | ⇊      |         _ _ _ _ _ _ _ _       | _ |     |     ⇊ | \n";
	std::cout << " | ⇊      |       {                 }               |     ⇊ | \n";
	std::cout << " | ⇊      |       {  L O C K E D    }               |     ⇊ | \n";
	std::cout << " | ⇊      |       { _ _ _ _ _ _ _ _ }               |     ⇊ | \n";
	std::cout << " | ⇊      |                                         |     ⇊ | \n";
	std::cout << " | ⇊	    ========================================      ⇊ | \n";
	std::cout << " | ⇊                                                      ⇊ | \n";
	std::cout << " |  ⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄⇄ | \n";
	std::cout << " ⌊———————————————————————————————————————————————————————— ⌋ \n";

	while (isRunning)
	{
		std::cin.clear();

		GameMenu::MenuChoice choice = gameMenu.menuChoice();

		switch (choice)
		{
		case GameMenu::MenuChoice::Player:
		{
			if (activePlayer != nullptr)
			{
				delete activePlayer;
			}

			Player createdPlayer = Player::createNewPlayer();
			activePlayer = new Player(createdPlayer);
			break;
		}
		case GameMenu::MenuChoice::Level:
		{
			if (activePlayer == nullptr)
			{
				std::cout << "\n[!] You must create your player first, please choose option 1.\n";
			}
			else
			{
				safeGame.playLevel(*activePlayer);
			}
			break;
		}
		case GameMenu::MenuChoice::HighScores:
		{
			if (activePlayer != nullptr) activePlayer->displayHighScore();

			else std::cout << "\nNo players have been recorded.\n";

			break;
		}
		case GameMenu::MenuChoice::End:
		{
			std::cout << "GAMEOVER  X_X\n";
			isRunning = false;
			break;
		}
		}
		std::cout << " =*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n";
	

		}
		if (activePlayer != nullptr) delete activePlayer;
		return 0;
	}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
