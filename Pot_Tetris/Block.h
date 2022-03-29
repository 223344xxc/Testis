#pragma once
#include "Text_Color.h"

enum BlockStayte
{
	Blank,
	NowCtrl,
	Pause,
};

class Block
{
public:
	int x = 0;
	int y = 0;
	BlockStayte Stayte = Blank;
	Color color;

public:
	Block();
	~Block();
	void SetingPos(int x, int y);
	void print_block(int x, int y, bool feel = true);
	void Copy_Block(Block block);
	void Reset_Block();
};

