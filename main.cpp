#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "Students_base.h"
#include "Backup.h"

int main()
{
	//std::cout << "+++++++++++++++++++++++++++++++++";
	Backup backup;
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	if ((checkForBaseFile()) == 0)
	{
		std::cout << "Do you want to recover your student's list or you you want to innit new list? ";
	}
	//std::cout << "+++++++++++++++++++++++++++++++++";
	char startAnswer;
	std::cin >> startAnswer;

	static int numStud;
	STUDENT * pJornal;

	if (startAnswer == 'y')//restoring students from base
	{
		numStud = countStudentsFromBase();
		pJornal = new STUDENT[numStud];


		backupFromFile(pJornal, numStud);

	}
	else
	{
		std::cout << "\nEnter the number of students you want to innit: ";//innitiating new list
		std::cin >> numStud;
		pJornal = new STUDENT[numStud];
		innit(pJornal, numStud);
	}

	std::cout << "\n";

	int choise = -1;
	while (choise != 0)
	{
		system("cls");
		std::cout << "---MENU---\n"
			"SERCH THE BEST        PRESS 1\n"
			"SERCH THE WORST       PRESS 2\n"
			"SHOW ALL STUDENTS     PRESS 3\n"
			"SORT YOUR STUDENTS    PRESS 4\n"
			"EDIT STUDENT PROFILES PRESS 5\n"
			"ADD/DELETE STUDENT    PRESS 6\n"
			"TO FINISH             PRESS 0\n\n";


		std::cin >> choise;
		std::cout << "\n";

		while (choise < 0 || choise > 6)
		{
			std::cout << "Enter correct choise :";
			std::cin >> choise;
		}

		switch (choise)
		{
		case 1: find_best(pJornal, numStud);
			break;
		case 2: find_worst(pJornal, numStud);
			break;
		case 3: show_students(pJornal, numStud);
			break;
		case 4:
			std::cout << "\nTo sort by name press 1\n" << "To sort by marks press 2\n";
			std::cin >> choise;
			if (choise == 1)
			{
				sort_students_byName(pJornal, numStud);
			}
			else if (choise == 2)
			{
				sort_students_byMark(pJornal, numStud);
			}
			break;
		case 5:edit_profile(pJornal, numStud);
			break;
		case 6:
			std::cout << "\nTo add 1\n" << "To delete press 2\n";
			std::cin >> choise;
			if (choise == 1)
			{
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "\np11111111Jornal before - " << pJornal;
				std::cout << "\np11111111numStud before - " << numStud;
				SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

				pJornal = addStudent(pJornal, &numStud);

				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "\np1111111Jornal after - " << pJornal;
				std::cout << "\np11111111numStud after - " << numStud;
				SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else if (choise == 2)
			{
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				pJornal = deleteStudent(pJornal, &numStud);
				SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			break;
		case 0:
			system("cls");
			std::cout << "DO YOU WANT TO SAVE THE CHANGES?";
			char answer;
			std::cin >> answer;
			if (answer == 'y')
			{
				save_changes(pJornal, numStud);
				std::cout << "ALL YOUR DATA IS SAVED.\n";
				system("pause");
				exit(0);
			}
			else
			{
				std::cout << "ALL YOUR DATA IS NOT SAVED.\n\n";
				exit(0);
			}
			break;
		}
		save_changes(pJornal, numStud);
		backup.saveToBackUp(pJornal);
		system("pause");
	}

	delete[] pJornal;

	if (_CrtDumpMemoryLeaks())
		std::cout << "Memory Leak!\n";
	return 0;
}