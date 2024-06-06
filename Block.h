#pragma once
#include <vector>

enum Tetromino
{
	I_MINO = 0,
	O_MINO,
	Z_MINO,
	S_MINO,
	J_MINO,
	L_MINO,
	T_MINO,
	TERTROMINO_COUNT
};

class Block
{
public:
	Block();
	~Block();

	Pos GetBlockPos();
	void SetBlockPos(int32 y, int32 x);

	void UpdateTetrimino();

private:
	vector<Pos> GenerateBlock();



public:
	vector<Pos> _tetrimino;
	Pos _blockPos = Pos(1, 5);

private:
	vector<Pos> _i_mino = { Pos(0,0), Pos(1,0), Pos(2,0), Pos(3,0) };
	vector<Pos> _o_mino = { Pos(0,0), Pos(0,1), Pos(1,0), Pos(1,1) };
	vector<Pos> _z_mino = { Pos(0,0), Pos(0,1), Pos(1,1), Pos(1,2) };
	vector<Pos> _s_mino = { Pos(0,1), Pos(0,2), Pos(1,0), Pos(1,1) };
	vector<Pos> _j_mino = { Pos(0,1), Pos(1,1), Pos(2,0), Pos(2,1) };
	vector<Pos> _l_mino = { Pos(0,0), Pos(1,0), Pos(2,0), Pos(2,1) };
	vector<Pos> _t_mino = { Pos(0,0), Pos(0,1), Pos(0,2), Pos(1,1) };
};

