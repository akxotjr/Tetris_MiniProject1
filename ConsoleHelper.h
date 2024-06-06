#pragma once

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE
};

class ConsoleHelper
{
public:
	static void GetKeyBoardInput();

	static void SetConsoleColor(ConsoleColor color);

};

