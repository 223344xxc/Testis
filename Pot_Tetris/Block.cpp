#include "Block.h"
#include "Global.h"
#include <stdio.h>

Block::Block()
{
	color = ���;
	Stayte = Blank;

}


Block::~Block()
{
}

void Block::print_block(int x, int y, bool feel)
{
	go(x, y);
	SetColor(color);
	if (feel)
		printf("��");
	else
		printf("��");
	SetColor(���);
	go(0, 100);
}

void Block::SetingPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Block::Copy_Block(Block block)
{
	x = block.x;
	y = block.y;
	color = block.color;
	Stayte = block.Stayte;
}

void Block::Reset_Block()
{
	color = ���;
	Stayte = Blank;
}