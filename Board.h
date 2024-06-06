#pragma once

#include "ConsoleHelper.h"
#include <vector>

enum
{
	MAX_BOARD_SIZE = 25,
	MOVE_TICK = 1000
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	BLOCK,
	WALL
};

class Block;

class Board
{

public:

	Board();
	~Board();

	void Init();
	void Render();

	void GenerateMap();
	TileType GetTileType(Pos pos);
	ConsoleColor GetTileColor(Pos pos);
	void Update(uint64 deltaTick);
	bool isInBoundary(vector<Pos>& tetromino, Pos blockPos);

private:
	int32 _size_y = 22;
	int32 _size_x = 12;
	uint64 _sumTick = 0;

	Block* _block = nullptr;

	TileType _tile[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
};

