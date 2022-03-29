#pragma once
#include "Block.h"
#include <vector>
using namespace std;

const int Y = 20;
const int X = 15;

class MainMap
{
public:

	Block TempMap[Y][X];
	Block Map[Y][X];
public:
	MainMap();
	~MainMap();
	void Print_Map();
	void Update_Map(bool Trigger = true);
	void CopyMap();
	void CopyBlock(vector<Block*>*List);
	void FreezBlock(vector<Block*>*List);
	void DeleteBlock(vector<Block*>* List, int Focus);
	void Print_Pause();
	void Block_All_Down(int Line);
	void Link_Block(vector<Block*>* List);
};

