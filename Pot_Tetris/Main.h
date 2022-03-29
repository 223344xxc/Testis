#pragma once
#include <conio.h>
#include <Windows.h>
//#include "Global.h"

//"mode con: cols=%d lines=%d"
void ConsolSize(int xi, int yi)
{
	char x[10];
	char y[10];
	_itoa_s(xi, x, 10);
	_itoa_s(yi, y, 10);
	char size[64] = { "mode con: cols=" };
	char size_line[64] = { " lines=" };
	strncat_s(size, x, 5);
	strncat_s(size_line, y, 5);
	strncat_s(size, size_line, sizeof(size_line));

	system(size);
}
