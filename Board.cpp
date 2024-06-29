#include "pch.h"
#include "Board.h"
#include "Block.h"

//const char* TILE = "бс";
const char* TILE = "бр";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(ConsoleHelper* console)
{
	_console = console;
	GenerateMap();
}


void Board::Render()
{
	int32 XOffset = 3;
	int32 YOffset = 1;
	COORD coord{0,};
	int32 XAdd = 0;
	DWORD dw = 0;
	char chBuf[256] = { 0, };



	for (int32 y = 0; y < _size_y; y++)
	{
		XAdd = 0;
		for (int32 x = 0; x < _size_x; x++)
		{
			coord.X = XAdd + XOffset;
			coord.Y = y + YOffset;
			
			//_backBuffer << TILE;
			//cout << TILE;

			SetConsoleCursorPosition(_console->hBuffer[_console->_curBufferIdx], coord);
			ConsoleColor color = GetTileColor(Pos(y, x));
			ConsoleHelper::SetConsoleColor(color);
			WriteFile(_console->hBuffer[_console->_curBufferIdx], TILE, strlen(TILE), &dw, NULL);

			++XAdd;
			if (_map[y][x] == TileType::EMPTY)
				++XAdd;
			
		}
		//_backBuffer << endl;
		//cout << endl;
	}

	/*ConsoleHelper::GetKeyBoardInput();*/
	//GoToXY(0, 0);
}

void Board::GenerateMap()
{
	for (int32 y = 0; y < _size_y; y++)
	{
		for (int32 x = 0; x < _size_x; x++)
		{
			if (x == 0 || x == _size_x - 1 || y == 0 || y == _size_y - 1)
				_map[y][x] = TileType::WALL;
			else
				_map[y][x] = TileType::EMPTY;
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size_x) return TileType::NONE;
	if (pos.y < 0 || pos.y >= _size_y) return TileType::NONE;

	return _map[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{	
	TileType tiletype = GetTileType(pos);

	switch (tiletype)
	{
	case TileType::EMPTY:
		return ConsoleColor::BLACK;
	case TileType::WALL:
		return ConsoleColor::WHITE;
	}
}

void Board::Update(float deltaTick)
{
	_sumTick += deltaTick;
	if (_sumTick >= 1)
	{
		_sumTick = _sumTick - 1.f;

		if (_block == nullptr)
		{
			_block = new Block();
		}	
		
		//_block->SetBlockPos(pos.y+1, pos.x);
		Render();
		//_block->Update();
		//_block->Render();
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



