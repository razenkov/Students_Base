#pragma once
#include "stdafx.h"


void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}




//int main()
//{
//
//	for (int i = 0; i < 15; ++i)
//	{
//		SetColor(i);
//		std::cout << i << "\nChangeConsoleToColors\n";
//		Sleep(1000);
//	}
//	return 0;
//}