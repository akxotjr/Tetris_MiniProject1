#include "pch.h"
#include "Board.h"
#include "Block.h"

Board board;

int main()
{
	::srand(static_cast<uint32>(time(nullptr)));					
	board.Init();

	uint64 lastTick = 0;

	while (true)
	{
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
		board.Update(deltaTick);
		board.Render();
	}
}