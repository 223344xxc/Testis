#pragma once
#include "Block.h"
#include <vector>
using namespace std;



enum BlockType
{
	//бсбр

	A,/*
	  бс
	  бс
	  бс
	  бс
	  */

	B,/*
	  брбсбр
	  бсбсбс
	  */

	C,/*
	  бсбс
	  бсбс
	  */

	D,/*
	  бсбр
	  бсбс
	  брбс
	  */

	E,/*
	  брбс
	  бсбс
	  бсбр
	  */

	F,/*
	  бсбс
	  бсбр
	  бсбр
	  */

	G,/*
	  бсбс
	  брбс
	  брбс
	  */
	Z,
};

enum AngleType
{
	a0,
	a90,
	a180,
	a270,
};

class MainMap;
class GameBlock
{
public:
	AngleType Angle;
	BlockType Block_Type;
	vector<Block*> List;
public:
	GameBlock();
	~GameBlock();
	void CreateBlock(BlockType Type = Z);
	void SetingVector(int Count, Color color);
	void TurnBlock(MainMap &map);
};

