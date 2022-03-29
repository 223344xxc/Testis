#include "GameBlock.h"
#include "Global.h"
#include "MainMap.h"

GameBlock::GameBlock()
{
}


GameBlock::~GameBlock()
{
}

void GameBlock::CreateBlock(BlockType Type)
{
	Angle = a0;
	List.clear();
	if (Type == Z)
	{
		Type = (BlockType)(rand() % 7);
	}
	Block_Type = Type;
	switch (Type)
	{
	case A:
		SetingVector(4, 연한파란색);
		for (int i = 0; i < List.size(); i++)
		{
			List[i]->SetingPos(5, i);
			//List[i]->x = 5;
			//List[i]->y = i;
		}
		break;
	case B:
		SetingVector(4, 연한빨간색);
		List[0]->SetingPos(5, 0);
		List[1]->SetingPos(4, 1);
		List[2]->SetingPos(5, 1);
		List[3]->SetingPos(6, 1);
		break;
	case C:
		SetingVector(4, 연한옥색);
		List[0]->SetingPos(5, 0);
		List[1]->SetingPos(6, 0);
		List[2]->SetingPos(5, 1);
		List[3]->SetingPos(6, 1);
		break;
	case D:
		SetingVector(4, 연한자주색);
		List[0]->SetingPos(5, 0);
		List[1]->SetingPos(5, 1);
		List[2]->SetingPos(6, 1);
		List[3]->SetingPos(6, 2);
		break;
	case E:
		SetingVector(4, 연한초록색);
		List[0]->SetingPos(6, 0);
		List[1]->SetingPos(5, 1);
		List[2]->SetingPos(6, 1);
		List[3]->SetingPos(5, 2);
		break;
	case F:
		SetingVector(4, 연한노란색);
		List[0]->SetingPos(5, 0);
		List[1]->SetingPos(6, 0);
		List[2]->SetingPos(5, 1);
		List[3]->SetingPos(5, 2);
		break;
	case G:	
		SetingVector(4, 초록색);
		List[0]->SetingPos(5, 0);
		List[1]->SetingPos(6, 0);
		List[2]->SetingPos(6, 1);
		List[3]->SetingPos(6, 2);
		break;
	default:
		break;
	}
}

void GameBlock::SetingVector(int Count, Color color)
{
	for (int i = 0; i < Count; i++)
	{
		List.push_back(new Block);
	}
	for (int i = 0; i < List.size(); i++)
	{
		List[i]->Stayte = NowCtrl;
		List[i]->color = color;
	}
}


void GameBlock::TurnBlock(MainMap &map)
{
	for (int i = 0; i < List.size(); i++)
	{
		map.Map[List[i]->y][List[i]->x].Stayte = Blank;
	}
	switch (Block_Type)
	{
	case A:
		switch (Angle)
		{
		case a0:
			if (map.Map[List[0]->y + 2][List[0]->x + 2].Stayte == Blank && List[0]->y + 2 >= 0 && List[0]->y + 2 <Y && List[0]->x + 2 >= 0 && List[0]->x + 2 < X)
				if (map.Map[List[1]->y + 1][List[1]->x + 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x - 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 2, List[0]->y + 2);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y - 1);
						Angle = a90;
					}

			break;
		case a90:
			if (map.Map[List[0]->y + 2][List[0]->x - 2].Stayte == Blank && List[0]->y + 2 >= 0 && List[0]->y + 2 < Y && List[0]->x - 2 >= 0 && List[0]->x - 2 < X)
				if (map.Map[List[1]->y + 1][List[1]->x - 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x + 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 2, List[0]->y + 2);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y - 1);	
						Angle = a180;
					}

			break;
		case a180:
			if (map.Map[List[0]->y - 2][List[0]->x - 2].Stayte == Blank && List[0]->y - 2 >= 0 && List[0]->y - 2 < Y && List[0]->x - 2 >= 0 && List[0]->x - 2 < X)
				if (map.Map[List[1]->y - 1][List[1]->x - 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x + 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 2, List[0]->y - 2);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y + 1);	
						Angle = a270;
					}

			break;
		case a270:
			if (map.Map[List[0]->y - 2][List[0]->x + 2].Stayte == Blank && List[0]->y - 2 >= 0 && List[0]->y - 2 < Y && List[0]->x + 2 >= 0 && List[0]->x + 2 < X)
				if (map.Map[List[1]->y - 1][List[1]->x + 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x - 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 2, List[0]->y - 2);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y + 1);
						Angle = a0;
					}

			break;
		default:
			break;
		}
		break;
	case B:
		switch (Angle)
		{
		case a0:
			if (map.Map[List[0]->y + 1][List[0]->x + 1].Stayte == Blank && List[0]->y + 1 >= 0 && List[0]->y + 1 < Y && List[0]->x + 1 >= 0 && List[0]->x + 1 < X)
				if (map.Map[List[1]->y - 1][List[1]->x + 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x - 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 1, List[0]->y + 1);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y + 1);	
						Angle = a90;
					}

			break;
		case a90:
			if (map.Map[List[0]->y + 1][List[0]->x - 1].Stayte == Blank && List[0]->y + 1 >= 0 && List[0]->y + 1 < Y && List[0]->x - 1 >= 0 && List[0]->x - 1 < X)
				if (map.Map[List[1]->y + 1][List[1]->x + 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x - 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 1, List[0]->y + 1);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y - 1);	
						Angle = a180;
					}

			break;
		case a180:
			if (map.Map[List[0]->y - 1][List[0]->x - 1].Stayte == Blank && List[0]->y - 1 >= 0 && List[0]->y - 1 < Y && List[0]->x - 1 >= 0 && List[0]->x - 1 < X)
				if (map.Map[List[1]->y + 1][List[1]->x - 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x + 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 1, List[0]->y - 1);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y - 1);
						Angle = a270;
					}

			break;
		case a270:
			if (map.Map[List[0]->y - 1][List[0]->x + 1].Stayte == Blank && List[0]->y - 1 >= 0 && List[0]->y - 1 < Y && List[0]->x + 1 >= 0 && List[0]->x + 1 < X)
				if (map.Map[List[1]->y - 1][List[1]->x - 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x + 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 1, List[0]->y - 1);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y + 1);	
						Angle = a0;
					}

			break;
		default:
			break;
		}
		break;
	case C:
		break;
	case D:
		switch (Angle)
		{
		case a0:
			if (map.Map[List[0]->y][List[0]->x + 2].Stayte == Blank && List[0]->y>= 0 && List[0]->y < Y && List[0]->x + 2 >= 0 && List[0]->x + 2 < X)
				if (map.Map[List[1]->y - 1][List[1]->x + 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x - 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 2, List[0]->y);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y - 1);
						Angle = a270;
					}

			break;
		case a270:
			if (map.Map[List[0]->y][List[0]->x - 2].Stayte == Blank && List[0]->y >= 0 && List[0]->y < Y && List[0]->x - 2 >= 0 && List[0]->x - 2 < X)
				if (map.Map[List[1]->y + 1][List[1]->x - 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x + 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 2, List[0]->y);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y + 1);	
						Angle = a0;
					}

			break;
		default:
			break;
		}
		break;
	case E:
		switch (Angle)
		{
		case a0:
			if (map.Map[List[0]->y + 1][List[0]->x + 1].Stayte == Blank && List[0]->y + 1 >= 0 && List[0]->y + 1 < Y && List[0]->x + 1 >= 0 && List[0]->x + 1 < X)
				if (map.Map[List[1]->y - 1][List[1]->x + 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y - 2][List[3]->x].Stayte == Blank && List[3]->y - 2 >= 0 && List[3]->y - 2 < Y && List[3]->x >= 0 && List[3]->x < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 1, List[0]->y + 1);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x, List[3]->y - 2);
						Angle = a270;
					}

			break;
		case a270:
			if (map.Map[List[0]->y - 1][List[0]->x - 1].Stayte == Blank && List[0]->y - 1 >= 0 && List[0]->y - 1 < Y && List[0]->x - 1 >= 0 && List[0]->x - 1 < X)
				if (map.Map[List[1]->y + 1][List[1]->x - 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y + 2][List[3]->x].Stayte == Blank && List[3]->y + 2 >= 0 && List[3]->y + 2 < Y && List[3]->x >= 0 && List[3]->x < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 1, List[0]->y - 1);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x, List[3]->y + 2);
						Angle = a0;
					}

			break;
		default:
			break;
		}
		break;
	case F:
		switch (Angle)
		{
		case a0:
			if (map.Map[List[0]->y + 1][List[0]->x + 1].Stayte == Blank && List[0]->y + 1 >= 0 && List[0]->y + 1 < Y && List[0]->x + 1 >= 0 && List[0]->x + 1 < X)
				if (map.Map[List[1]->y + 2][List[1]->x].Stayte == Blank && List[1]->y + 2 >= 0 && List[1]->y + 2 < Y && List[1]->x >= 0 && List[1]->x < X)
					if (map.Map[List[3]->y - 1][List[3]->x - 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 1, List[0]->y + 1);
						List[1]->SetingPos(List[1]->x, List[1]->y + 2);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y - 1);
						Angle = a90;
					}

			break;
		case a90:
			if (map.Map[List[0]->y + 1][List[0]->x - 1].Stayte == Blank && List[0]->y + 1 >= 0 && List[0]->y + 1 < Y && List[0]->x - 1 >= 0 && List[0]->x - 1 < X)
				if (map.Map[List[1]->y][List[1]->x - 2].Stayte == Blank && List[1]->y >= 0 && List[1]->y < Y && List[1]->x - 2 >= 0 && List[1]->x - 2 < X)
					if (map.Map[List[3]->y - 1][List[3]->x + 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 1, List[0]->y + 1);
						List[1]->SetingPos(List[1]->x - 2, List[1]->y);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y - 1);	
						Angle = a180;
					}

			break;
		case a180:
			if (map.Map[List[0]->y - 1][List[0]->x - 1].Stayte == Blank && List[0]->y - 1 >= 0 && List[0]->y - 1 < Y && List[0]->x - 1 >= 0 && List[0]->x - 1 < X)
				if (map.Map[List[1]->y - 2][List[1]->x].Stayte == Blank && List[1]->y - 2 >= 0 && List[1]->y - 2 < Y && List[1]->x >= 0 && List[1]->x < X)
					if (map.Map[List[3]->y + 1][List[3]->x + 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 1, List[0]->y - 1);
						List[1]->SetingPos(List[1]->x, List[1]->y - 2);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y + 1);
						Angle = a270;
					}

			break;
		case a270:
			if (map.Map[List[0]->y - 1][List[0]->x + 1].Stayte == Blank && List[0]->y - 1 >= 0 && List[0]->y - 1 < Y && List[0]->x + 1 >= 0 && List[0]->x + 1 < X)
				if (map.Map[List[1]->y][List[1]->x + 2].Stayte == Blank && List[1]->y >= 0 && List[1]->y < Y && List[1]->x + 2 >= 0 && List[1]->x + 2 < X)
					if (map.Map[List[3]->y + 1][List[3]->x - 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 1, List[0]->y - 1);
						List[1]->SetingPos(List[1]->x + 2, List[1]->y);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y + 1);	
						Angle = a0;
					}

			break;
		default:
			break;
		}
		break;
	case G:
		switch (Angle)
		{
		case a0:
			if (map.Map[List[0]->y][List[0]->x + 2].Stayte == Blank && List[0]->y >= 0 && List[0]->y < Y && List[0]->x + 2 >= 0 && List[0]->x + 2 < X)
				if (map.Map[List[1]->y + 1][List[1]->x + 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x - 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x + 2, List[0]->y);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y - 1);
						Angle = a90;
					}

			break;
		case a90:
			if (map.Map[List[0]->y + 2][List[0]->x].Stayte == Blank && List[0]->y + 2 >= 0 && List[0]->y + 2 < Y && List[0]->x >= 0 && List[0]->x < X)
				if (map.Map[List[1]->y + 1][List[1]->x - 1].Stayte == Blank && List[1]->y + 1 >= 0 && List[1]->y + 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y - 1][List[3]->x + 1].Stayte == Blank && List[3]->y - 1 >= 0 && List[3]->y - 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x, List[0]->y + 2);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y + 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y - 1);	
						Angle = a180;
					}

			break;
		case a180:
			if (map.Map[List[0]->y][List[0]->x - 2].Stayte == Blank && List[0]->y >= 0 && List[0]->y < Y && List[0]->x - 2 >= 0 && List[0]->x - 2 < X)
				if (map.Map[List[1]->y - 1][List[1]->x - 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x - 1 >= 0 && List[1]->x - 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x + 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x + 1 >= 0 && List[3]->x + 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x - 2, List[0]->y);
						List[1]->SetingPos(List[1]->x - 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x + 1, List[3]->y + 1);
						Angle = a270;
					}

			break;
		case a270:
			if (map.Map[List[0]->y - 2][List[0]->x].Stayte == Blank && List[0]->y - 2 >= 0 && List[0]->y - 2 < Y && List[0]->x >= 0 && List[0]->x < X)
				if (map.Map[List[1]->y - 1][List[1]->x + 1].Stayte == Blank && List[1]->y - 1 >= 0 && List[1]->y - 1 < Y && List[1]->x + 1 >= 0 && List[1]->x + 1 < X)
					if (map.Map[List[3]->y + 1][List[3]->x - 1].Stayte == Blank && List[3]->y + 1 >= 0 && List[3]->y + 1 < Y && List[3]->x - 1 >= 0 && List[3]->x - 1 < X)
					{
						map.DeleteBlock(&List, 2);
						List[0]->SetingPos(List[0]->x, List[0]->y - 2);
						List[1]->SetingPos(List[1]->x + 1, List[1]->y - 1);
						List[3]->SetingPos(List[3]->x - 1, List[3]->y + 1);
						Angle = a0;
					}

			break;
		default:
			break;
		}
		break;
	case Z:
		system("pause");
		break;
	default:
		break;
	}
	map.CopyBlock(&List);
	map.Update_Map();
}