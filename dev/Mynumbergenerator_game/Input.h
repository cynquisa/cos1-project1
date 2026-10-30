#pragma once
#include <iostream>
#include <string>

namespace Input

{
	inline int GetNumber(const std::string& prompt, int min, int max)
	{
		while (true)

		std::cout << prompt;
		std::string input;

		std::getline(std::cin, input);

		try
		{
			int number = std::stoi(input);
			if (number >= min && number <= max)
			{
				return number;
			}
			std::cout << "[ERROR] That number is not an avilable choice.\n\n";
		}
		catch (...)
		{
			std::cout << "[ERROR] Invalid input. Please enter a valid number.\n\n";
		}

	}


	inline std::string GetString(const std::string& prompt)
	{
		while (true)
		{
			std::cout << prompt;

			std::string input;

			std::getline(std::cin, input);

			if (!input.empty())
			{
				return input;
			}
				std::cout << " [ERROR] You cannot leave empty.\n";
		}
	}
}