#include "pch.h"
#include "Board.h"
#include "Block.h"

ConsoleHelper console;
Board board;
Block block;

int main()
{
	::srand(static_cast<uint32>(time(nullptr)));		

	console.Init();
	board.Init(&console);

	LARGE_INTEGER curTick;
	LARGE_INTEGER freq;

	QueryPerformanceCounter(&curTick);
	QueryPerformanceFrequency(&freq);

	while (true)
	{
		LARGE_INTEGER lastTick;
		QueryPerformanceCounter(&lastTick);

		float deltaTick =
			(lastTick.QuadPart - curTick.QuadPart) / (float)freq.QuadPart;
		curTick = lastTick;

		//board.Update(deltaTick);
		board.Render();
		console.ClearScreen();
		console.BufferFlip();
		Sleep(1);
	}
}