#include "Main.h"
#include <stdlib.h>
#include "MainMap.h"
#include <conio.h>
#include <stdio.h>
#include "Direction.h"
#include "GameBlock.h"
#include <time.h>
#define debug system("pause");

//_kbhit()
//31,25
void SetColor(int color);
void go(int x, int y);
Direction InputKey(char Ctrl);
void MoveBlock(Direction dir, MainMap &map, GameBlock *Block);
void MainGame();

int x = 34;
int y = 22;

extern bool GameEnd;

void main()
{
	srand((int)time(NULL));
	ConsolSize(x, y);

	MainGame();
}

void MainGame()
{
	int Time = 0;
	char Ctrl;
	MainMap map;
	Block TestBlock;
	map.Print_Map();
	GameBlock Block;
	Block.CreateBlock();
	map.CopyBlock(&Block.List);
	map.Update_Map();
	while (true)
	{
		if (GameEnd)
			return;
		if (_kbhit() != NULL)
		{
			Ctrl = _getch();
			if (Ctrl == -32)
			{
				Ctrl = _getch();
				MoveBlock(InputKey(Ctrl), map, &Block);
			}
		}
		if (Time >= 10000)
		{
			Time = 0;
			MoveBlock(down, map, &Block);
			//map.Print_Pause();
		}
		go(0, 100);
		map.Update_Map();
		Time += 1;
	}
}

void SetColor(int color)//텍스트 색깔 변경
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void go(int x, int y)//커서 위치 이동
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void MoveBlock(Direction dir, MainMap &map, GameBlock *Block)
{
	for (int i = 0; i < Block->List.size(); i++)
	{
		switch (dir)
		{
		case None:
			break;
		case right:
			if (Block->List[i]->x + 1 >= X || map.Map[Block->List[i]->y][Block->List[i]->x + 1].Stayte == Pause)
				return;
			break;
		case left:
			if (Block->List[i]->x - 1 < 0 || map.Map[Block->List[i]->y][Block->List[i]->x - 1].Stayte == Pause)
				return;
			break;
		case up://블럭 회전 조건 바뀜
			Block->TurnBlock(map);
			return;
			break;
		case down:
			if (Block->List[i]->y + 1 >= Y || map.Map[Block->List[i]->y + 1][Block->List[i]->x].Stayte == Pause)
			{
				map.FreezBlock(&Block->List);
				Block->CreateBlock();
				map.CopyBlock(&Block->List);
				return;
			}
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < Block->List.size(); i++)
	{
		map.Map[Block->List[i]->y][Block->List[i]->x].Reset_Block();
		switch (dir)
		{
		case None:
			break;
		case right:
			Block->List[i]->x += 1;
			break;
		case left:
			Block->List[i]->x -= 1;
			break;
		case up://블럭 회전
			debug
			break;
		case down:
			Block->List[i]->y += 1;
			break;
		case space:
		default:
			break;
		}
	}
	for (int i = 0; i < Block->List.size(); i++)
		map.Map[Block->List[i]->y][Block->List[i]->x].Copy_Block(*Block->List[i]);
}

Direction InputKey(char Ctrl)
{
	switch (Ctrl)
	{
	case right:
		return right;
		break;
	case left:
		return left;
		break;
	case up:
		return up;
		break;
	case down:
		return down;
		break;
	default:
		return None;
		break;
	}
	return None;
}
