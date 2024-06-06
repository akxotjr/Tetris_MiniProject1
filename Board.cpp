#include "pch.h"
#include "Board.h"
#include "Block.h"

const char* TILE = "бс";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init()
{
	GenerateMap();
}

void Board::Render()
{
	for (int32 y = 0; y < _size_y; y++)
	{
		for (int32 x = 0; x < _size_x; x++)
		{
			ConsoleColor color = GetTileColor(Pos(y, x));
			ConsoleHelper::SetConsoleColor(color);
			cout << TILE;
		}
		cout << endl;
	}
	ConsoleHelper::GetKeyBoardInput();
}

void Board::GenerateMap()
{
	for (int32 y = 0; y < _size_y; y++)
	{
		for (int32 x = 0; x < _size_x; x++)
		{
			if (x == 0 || x == _size_x - 1 || y == 0 || y == _size_y - 1)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size_x) return TileType::NONE;
	if (pos.y < 0 || pos.y >= _size_y) return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	if (_block != nullptr)
	{
		for (auto it : _block->_tetrimino)
			{
				if (it == pos)
					return ConsoleColor::GREEN;
			}
	}
	
	TileType tiletype = GetTileType(pos);

	switch (tiletype)
	{
	case TileType::EMPTY:
		return ConsoleColor::BLACK;
	case TileType::WALL:
		return ConsoleColor::WHITE;
	}
}

void Board::Update(uint64 deltaTick)
{
	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		if (_block == nullptr)
		{
			_block = new Block();
		}
		
		Pos pos = _block->GetBlockPos();
		if (!isInBoundary(_block->_tetrimino, pos))
		{
			_block->SetBlockPos(1, 5);
			_tile[pos.y][pos.x] = TileType::BLOCK;
			_block->~Block();
		}
		
		_block->UpdateTetrimino();
		_block->SetBlockPos(pos.y+1, pos.x);
	}
}


bool Board::isInBoundary(vector<Pos>& tetromino, Pos blockPos)
{
	for (Pos pos : tetromino)
	{
		if (blockPos.y + pos.y > _size_y - 2 || blockPos.x + pos.x > _size_x - 2)
			return false;
	}
	return true;
}



