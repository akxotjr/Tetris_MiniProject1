#include "pch.h"
#include "Block.h"

Block::Block()
{
	_tetrimino = GenerateBlock();
}

Block::~Block()
{
}

Pos Block::GetBlockPos()
{
	return _blockPos;
}

void Block::SetBlockPos(int32 y, int32 x)
{
	_blockPos.y = y;
	_blockPos.x = x;
}

void Block::UpdateTetrimino()
{
	for (Pos& pos : _tetrimino)
	{
		pos += _blockPos;
	}
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


