#pragma once
#include "stdafx.h"
#include "Backup.h"


void Backup::saveToBackUp(STUDENT* pJornal)
{
	int num = countStudentsFromBase();

	std::ofstream fout("students_base_temp_backup.txt");
	for (int i = 0; i < num; ++i)
	{

		for (int j = 0; j < size2; ++j)
		{
			fout << pJornal[i].mark[j] << ' ';
		}

		fout << '\n';
	}

	std::cout << "Backuped up to temp file was successful\n";
	fout.close();
}

void Backup::getFromBackup(STUDENT* pJornal)
{
	char buff[maxFileStringSize];
	std::ifstream fin("students_base_temp_backup.txt");

	if (!fin.is_open()) // if file is not opened
	{
		std::cout << "File is not open!\n"; // file can not be opened
	}
	else
	{
		int studCounter = countStudentsFromBase();

		for (int i = 0; i < studCounter; ++i)
		{
			//name 
			fin.getline(buff, maxFileStringSize);

			char tempArr[size1] = {};// arr for one word from string 
			int globalCount = -1;
			int localCount = 0;

			while (buff[++globalCount] != ' ')
			{
				tempArr[localCount++] = buff[globalCount];
			}

			strcpy_s(pJornal[i].soname, tempArr);

			//soname
			localCount = 0;

			while (buff[++globalCount] != ' ')
			{
				tempArr[localCount++] = buff[globalCount];
			}

			strcpy_s(pJornal[i].name, tempArr);
			//std::cout << "\nbackup soname " << pJornal[i].soname << std::endl;

			//marks
			localCount = 0;
			static double sum;

			char* temp = new char;

			for (int k = 0; k < 10; ++k)
			{
				if (buff[globalCount] == ' ')
				{
					globalCount++; // to dissmiss ' '
				}
				else
				{
					*temp = buff[globalCount++];

					pJornal[i].mark[localCount] = std::atoi(temp);

					sum += pJornal[i].mark[localCount++];
				}
			}
			delete temp;

			pJornal[i].midMrk = sum / 5;
		}

		fin.close(); // closing file
		system("cls");
		std::cout << "Database recovered succesfuly.\n";
		system("pause");
	}
}

