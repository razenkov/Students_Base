#include "stdafx.h"
#include "Students_base.h"
#include <ctime>
//#include <cmath>
//#include <string>


void innit(STUDENT* pJornal, int num)
{
	std::cout << "\ninnit fuction starts here\n";
	//srand((unsigned int)time(NULL));
	for (int i = 0; i < num; ++i)
	{
		double midMark = 0;
		strcpy_s(pJornal[i].name, "student_name");
		strcpy_s(pJornal[i].soname, "student_soname");

		for (int j = 0; j < size2; ++j)
		{
			pJornal[i].mark[j] = rand() % 7;
			midMark = midMark + pJornal[i].mark[j];
		}

		midMark = midMark / size2;
		pJornal[i].midMrk = midMark;
	}
};

void show_students(STUDENT* pJornal, int num)
{
	//std::cout << "\nshow fuction starts here\n";
	//std::cout << "\nshow_students starts here\n";
	system("cls");
	double sum = 0;
	std::cout << "---STUDENTS LIST---\n\n";
	for (int i = 0; i < num; ++i)
	{
		std::cout
			<< i + 1 << '.'
			<< pJornal[i].soname << ' '
			<< pJornal[i].name << ' ';

		for (int j = 0; j < size2; ++j)
		{
			sum = pJornal[i].mark[j] + sum;
		}

		std::cout << sum / size2 << std::endl;
		sum = 0;
	}
	system("pause");
};

void find_worst(STUDENT* pJornal, int num)
{
	//std::cout << "\nworst fuction starts here\n";

	system("cls");
	int worstInd = 0;

	for (int i = 0; i < num; ++i)
	{
		if (pJornal[worstInd].midMrk > pJornal[i].midMrk)
			worstInd = i;
	}

	for (int i = 0; i < num; ++i)
	{
		if (pJornal[worstInd].midMrk == pJornal[i].midMrk)
		{
			std::cout << "The worst student is : " << pJornal[i].name << ' '
				<< pJornal[i].soname << ' '
				<< "his middle mark is "
				<< pJornal[i].midMrk << std::endl;
		}
	}
	system("pause");
	return;
}

void find_best(STUDENT* pJornal, int num)
{
	//std::cout << "\nbest fuction starts here\n";
	system("cls");
	int bestInd = 0;

	for (int i = 0; i < num; ++i)
	{
		if (pJornal[bestInd].midMrk < pJornal[i].midMrk)
			bestInd = i;
	}

	for (int i = 0; i < num; ++i)
	{
		if (pJornal[bestInd].midMrk == pJornal[i].midMrk)
		{
			std::cout << "The best student is : " << pJornal[i].name << ' '
				<< pJornal[i].soname << ' '
				<< "his middle mark is "
				<< pJornal[i].midMrk << std::endl;
		}
	}

	system("pause");
	return;
}

void edit_profile(STUDENT* pJornal, int num)
{
	//std::cout << "\nedit fuction starts here\n";
	int id = 0, choise = -1;
	while (choise != 0)
	{
		system("cls");
		std::cout
			<< "\n\nCHOOSE THE PROFILE YOU WANT TO CHANGE";
		std::cin >> id;
		id = id - 1;
		std::cout
			<< "PRESS 1	TO EDIT soNAME \n"
			<< "PRESS 2 TO EDIT NAME \n"
			<< "PRESS 3 TO EDIT MARKS \n"
			<< "PRESS 0 TO GO BACK TO PREVIOUS MENU \n";

		std::cin >> choise;

		switch (choise)
		{
		case 1: {
			std::cout << "\nEnter new soname: ";
			std::cin >> pJornal[id].soname;
			std::cout << "\nSONAME HAS BEEN CHANGED!\n";
			break; }

		case 2: {
			std::cout << pJornal[id].name << "-do";
			std::cout << "\nEnter new name: ";
			std::cin >> pJornal[id].name;
			std::cout << "\nNAME HAS BEEN CHANGED!\n";
			std::cout << pJornal[id].name << "-posle";
			break; }

		case 3: {
			int count = 1;
			for (int i = 0; i < 5; ++i)
			{
				std::cout << pJornal[id].mark[i] << "-do ";
				std::cout << "\nInput mark " << count++ << ": ";
				std::cin >> pJornal[id].mark[i];
				std::cout << pJornal[id].mark[i] << "-posle";
			}
			break; }

		case 0: break;
		}
	}
}

void save_changes(STUDENT* pJornal, int num)
{


	std::ofstream fout("students_base_backup.txt"); // create new obj ofstream and link it with file
	std::cout << "\n Trying to sAVE " << num << "students \n" << "pJornal[last].soname - " << pJornal[num - 1].soname;
	for (int i = 0; i < num; ++i)
	{

		fout << pJornal[i].soname << ' ';
		fout << pJornal[i].name << ' ';

		for (int j = 0; j < size2; ++j)
		{
			fout << pJornal[i].mark[j] << ' ';
		}

		fout << '\n';
	}

	fout.close(); // close file
}

void backupFromFile(STUDENT* pJornal, int num)
{
	std::cout << "\nsave fuction starts here\n";
	char buff[maxFileStringSize];
	std::ifstream fin("students_base_backup.txt");

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

int checkForBaseFile()
{

	std::ifstream fin("students_base_backup.txt");

	if (!fin.is_open()) // if file is not opened
	{
		std::cout << "File is not opened.\n";
		return 1; // file cant open
	}
	else
	{
		return 0;
	}
	fin.close();
}

int countStudentsFromBase()
{
	int studCounter = -1;//count the number of students start
	char *str = new char[55];
	std::ifstream base("students_base_backup.txt");

	while (!base.eof())
	{
		base.getline(str, 55, '\n');
		studCounter++;
	}

	base.close();
	delete str;//count the number of students end
			   //std::cout << studCounter << " student(s) into base\n";
	return studCounter;
}

void sort_students_byName(STUDENT* pJornal, int num)
{
	std::cout << "\nsort_students_byName fuction starts here\n";

	static STUDENT *temp = new STUDENT;
	int minFlag = 0;
	bool isChanged = false;

	for (int j = 0; j < num; ++j)
	{
		for (int i = j; i < num - j - 1; ++i)
		{
			*temp = pJornal[i];
			if ((int)temp->soname[0] >(int)pJornal[i + 1].soname[0])
			{
				std::cout << "\n****** The " << pJornal[i].soname[0] << '>' << pJornal[i + 1].soname[0] << std::endl;
				minFlag = i + 1;
				std::cout << "The min flag is " << minFlag << std::endl;
				isChanged = true;
			}

		}
		std::cout << "^^^^^^here check for if(isChanged)\n";
		if (isChanged)
		{
			*temp = pJornal[j];
			pJornal[j] = pJornal[minFlag];
			pJornal[minFlag] = *temp;
		}
		std::cout << "\n The " << j << " student is " << pJornal[j].soname << std::endl;
		isChanged = false;
	}

	system("pause");
	std::cout << "\nSorted\n";
	delete temp;
}

void sort_students_byMark(STUDENT* pJornal, int num)
{
	{
		std::cout << "\nsort_students_byMarks fuction starts here\n";

		static STUDENT *temp = new STUDENT;

		for (int i = 0; i < num; ++i)
		{
			for (int j = 0; j < num - 1; ++j)
			{
				if (pJornal[j].midMrk < pJornal[j + 1].midMrk)
				{
					*temp = pJornal[j];
					pJornal[j] = pJornal[j + 1];
					pJornal[j + 1] = *temp;
				}
			}
		}

		system("pause");
		std::cout << "\nSorted\n";
	}
}

STUDENT* deleteStudent(STUDENT* pJornal, int *num)
{
	int choise = 0, count = 0;
	std::cout << "Enter the number of student you want to delete\n" << std::endl;
	std::cin >> choise;
	int newNum = *num - 1;
	*num = newNum;
	STUDENT *newJornal = new STUDENT[newNum];

	for (int i = 0; i < newNum - 1; ++i)
	{
		if (i != choise - 1)
		{
			newJornal[count++] = pJornal[i];
		}
	}

	return newJornal;
	delete newJornal;
	system("pause");
}

STUDENT* addStudent(STUDENT* pJornal, int *num)
{
	{

		int newNum = *num + 1;
		*num = newNum;

		STUDENT *newJornal = new STUDENT[newNum];

		for (int i = 0; i < newNum - 1; ++i)
		{
			newJornal[i] = pJornal[i];

		}

		//show_students(pJornal, newNum);

		double midMark = 0;



		strcpy_s(newJornal[*num - 1].name, "new");
		strcpy_s(newJornal[*num - 1].soname, "new");


		for (int j = 0; j < size2; ++j)
		{
			newJornal[*num - 1].mark[j] = rand() % 7;
			midMark = midMark + newJornal[*num - 1].mark[j];
		}

		//show_students(pJornal, newNum);

		midMark = midMark / size2;
		pJornal[*num - 1].midMrk = midMark;
		//std::cout << pJornal[newNum - 1].soname << std::endl;


		//std::cout << pJornal[newNum - 1].soname << std::endl;
		//std::cout << pJornal[*num - 1].soname << std::endl;


		return newJornal;
		delete newJornal;
		system("pause");
	}
}