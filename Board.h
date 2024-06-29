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

constexpr int MAP_WIDTH = 12;
constexpr int MAP_HEIGHT = 22;


class Block;

class Board
{

public:

	Board();
	~Board();

	void Init(ConsoleHelper* console);
	void Render();

	void GenerateMap();
	TileType GetTileType(Pos pos);
	ConsoleColor GetTileColor(Pos pos);
	void Update(float deltaTick);
	bool isInBoundary(vector<Pos>& tetromino, Pos blockPos);

private:
	int32 _size_y = 22;
	int32 _size_x = 12;
	float _sumTick = 0;

	ConsoleHelper* _console = nullptr;
	Block* _block = nullptr;

	TileType _map[MAP_HEIGHT][MAP_WIDTH];
};

