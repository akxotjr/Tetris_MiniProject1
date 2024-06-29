#include "pch.h"
#include "Block.h"
#include "ConsoleHelper.h"

Block::Block()
{
	_tetrimino = GenerateBlock();
}

Block::~Block()
{
}

void Block::Update()
{
	if (_blockPos.y > 20)
		_blockPos.y = 1;
	_blockPos += Pos(1, 0);
}

void Block::Render()
{
	for (Pos pos : _tetrimino)
	{
		pos += GetBlockPos();
		//ConsoleHelper::SetConsoleColor(ConsoleColor::GREEN);
		//GoToXY(pos.x, pos.y);
		//cout << "бс";

	}
	//GoToXY(0, 0);
}

vector<Pos> Block::GenerateBlock()
{
	const int32 randValue = ::rand() % Tetromino::TERTROMINO_COUNT;
	Tetromino tetromino = static_cast<Tetromino>(randValue);
	
	switch (tetromino)
	{
	case I_MINO:
		return _i_mino;
	case O_MINO:
		return _o_mino;
	case Z_MINO:
		return _z_mino;
	case S_MINO:
		return _s_mino;
	case J_MINO:
		return _j_mino;
	case L_MINO:
		return _l_mino;
	case T_MINO:
		return _t_mino;
	}
}


