#pragma once
#include<vector>

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE
};

struct stRect
{
	int32 Width;
	int32 Height;
};

class ConsoleHelper
{
public:
	ConsoleHelper() : hConsole(nullptr), hBuffer{ nullptr, }, _curBufferIdx(0) {}
	~ConsoleHelper();

	void Init();
	void Destory();

	void ClearScreen();
	void BufferFlip();

	static void GetKeyBoardInput();
	static void SetConsoleColor(ConsoleColor color);

public:
	int width = 12;
	int height = 30;

	HANDLE hConsole;
	stRect rtConsole;
	HANDLE hBuffer[2];
	int32 _curBufferIdx;
};

