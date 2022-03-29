#pragma once
#include "Block.h"
#include <vector>
using namespace std;



enum BlockType
{
	//���

	A,/*
	  ��
	  ��
	  ��
	  ��
	  */

	B,/*
	  ����
	  ����
	  */

	C,/*
	  ���
	  ���
	  */

	D,/*
	  ���
	  ���
	  ���
	  */

	E,/*
	  ���
	  ���
	  ���
	  */

	F,/*
	  ���
	  ���
	  ���
	  */

	G,/*
	  ���
	  ���
	  ���
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

