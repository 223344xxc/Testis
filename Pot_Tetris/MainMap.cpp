#include "MainMap.h"
#include <stdio.h>
#include "Global.h"

bool GameEnd = false;

MainMap::MainMap()
{
}


MainMap::~MainMap()
{
}

void MainMap::Link_Block(vector<Block*>* List)
{
	for (int i = 0; i < List->size(); i++)
		Map[(*List)[i]->y][(*List)[i]->x].Copy_Block(*(*List)[i]);
}

//¦®¦¯¦¬¦±¦°¦­¡á¡à
void MainMap::Print_Map()
{
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	for (int y = 0; y < Y; y++)
	{
		printf("¦­");

		for (int x = 0; x < X; x++)
			if (Map[y][x].color == Èò»ö)
			{
				go(x * 2 + 2, y + 1);
				printf("¡à");
			}

		printf("¦­");
		printf("\n");
	}
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
}

void MainMap::Print_Pause()
{
	system("cls");
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	for (int y = 0; y < Y; y++)
	{
		printf("¦­ ");

		for (int x = 0; x < X; x++)
			if (Map[y][x].Stayte == Pause)
				printf("¡á");
			else if (Map[y][x].Stayte == NowCtrl)
				printf("¡Û");
			else
				printf("¡à");
			
		printf("¦­");
		printf("\n");
	}
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	system("pause");
}

void MainMap::Update_Map(bool Trigger)
{
	int Pause_Count = 0;
	for (int y = Y - 1; y >= 0 ; y--)
	{
		Pause_Count = 0;
		for (int x = 0; x < X; x++)
		{
			if (Map[y][x].Stayte == Pause)
				Pause_Count += 1;
			if (Map[y][x].color != TempMap[y][x].color)
			{
				if (Map[y][x].color == Èò»ö)
					Map[y][x].print_block(2 + (x * 2), y + 1, false);
				else
					Map[y][x].print_block(2 + (x * 2), y + 1);
			}
			if (Pause_Count >= X)
			{
				for (int xx = 0; xx < X; xx++)
				{
					Map[y][xx].color = Èò»ö;
					Map[y][xx].Stayte = Blank;
					if (Map[y - 1][xx].Stayte == Blank)
						Map[y][xx].print_block(2 + (xx * 2), y + 1, false);
				}
				Block_All_Down(y);
				Pause_Count = 0;
			}
		}
	}
	for (int x = 0; x < X; x++)
	{
		if (Map[0][x].Stayte == Pause)
		{
			GameEnd = true;
			return;
		}
	}


	CopyMap();
}

void MainMap::Block_All_Down(int Line)
{
	for (int y = Line; y >= 0; y--)
	{
		for (int x = 0; x < X; x++)
		{
			if (y <= 0 && Map[y][x].Stayte != NowCtrl)
				Map[y][x].Reset_Block();
			else if (Map[y - 1][x].Stayte != NowCtrl && Map[y][x].Stayte != NowCtrl)
				Map[y][x].Copy_Block(Map[y - 1][x]);
		}
	}
}

void MainMap::CopyMap()
{
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (Map[y][x].color != TempMap[y][x].color)
				TempMap[y][x].color = Map[y][x].color;
		}
	}
}

void MainMap::CopyBlock(vector<Block*>*List)
{
	for (int i = 0; i < List->size(); i++)
		Map[(*List)[i]->y][(*List)[i]->x].Copy_Block(*(*List)[i]);
}

void MainMap::FreezBlock(vector<Block*>*List)
{
	for (int i = 0; i < List->size(); i++)
	{
		Map[(*List)[i]->y][(*List)[i]->x].Stayte = Pause;
	}
}

void MainMap::DeleteBlock(vector<Block*>* List, int Focus)
{
	for (int i = 0; i < List->size(); i++)
	{
		if (i != Focus)
		{
			Map[(*List)[i]->y][(*List)[i]->x].color = Èò»ö;
		}
		if (Map[(*List)[i]->y][(*List)[i]->x].Stayte != Blank)
			Map[(*List)[i]->y][(*List)[i]->x].print_block(2 + ((*List)[i]->x * 2), (*List)[i]->y + 1);
	}
}

