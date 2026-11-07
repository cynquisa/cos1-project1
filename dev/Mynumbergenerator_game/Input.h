#pragma once
#include <iostream>
#include <string>
#include <limits>

namespace Input

{
	static int GetNumber(const std::string& prompt, int min, int maxNumber)
	{
		std::string input;
		while (true)
		{
			if (!std::cin)
			{
				std::cin.clear();
			}
			std::cout << prompt;
		
		if (!std::getline(std::cin, input) || input.empty())
		{
			continue;
		}
		try
		{
			int number = std::stoi(input);
			if (number >= min && number <= maxNumber)
			{
				return number;
			}
			std::cout << "[ERROR] That number is not an available choice.\n\n";
		}
		catch (...)
		{
			std::cout << "[ERROR] Invalid input. Please enter a valid number.\n\n";
		}
	}
}


	static std::string GetString(const std::string& prompt)
	{
		while (true)
		{

			std::cout << prompt;

			std::string input;


			if (std::getline(std::cin, input))
			{

			if (!input.empty())
			{
			return input;
			}
			std::cout << " [ERROR] You must ener a valid response.\n";
			}
			else
			{
			std::cin.clear();
			return "";
			}

		}
	}
}