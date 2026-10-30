#pragma once
#include <iostream>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // To specify for win32 console - if not use normal console colors

namespace ConsoleColor
{
    enum class Ink
    {
        Purple, Cyan, Green, Yellow, Red, White
    };

    inline void Print(const std::string& message, Ink ink)
    {
#ifdef _WIN32
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO original{};

        if (output != INVALID_HANDLE_VALUE &&
            GetConsoleScreenBufferInfo(output, &original))
        {
            // Purple = Titles cards and mystical flavor
            WORD color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;


            if (ink == Ink::Cyan) // mennu options and information
            {
                color = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            }
            else if (ink == Ink::Green) // success messsages and upright meanings
            {
                color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            }
            else if (ink == Ink::Yellow) // user prompts and keywords
            {
                color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            }
            else if (ink == Ink::Red) // error messages and reversed meanings
            {
                color = FOREGROUND_RED | FOREGROUND_INTENSITY;
            }
            else if (ink == Ink::White) // regular text
            {
                color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            }

            std::cout.flush();
            SetConsoleTextAttribute(output, color);
            std::cout << message;
            std::cout.flush();
            SetConsoleTextAttribute(output, original.wAttributes);

            return;
        }
#endif

        std::cout << message;
    }
}
