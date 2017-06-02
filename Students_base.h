#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <fstream>


const int size1 = 20;
const int size2 = 5;
const int maxFileStringSize = 55;


struct STUDENT
{
	char name[size1];
	char soname[size1];
	int mark[size2];
	double midMrk;
};

void innit(STUDENT* pJornal, int num);
void show_students(STUDENT* pJornal, int num);
void find_worst(STUDENT* pJornal, int num);
void find_best(STUDENT* pJornal, int num);
void edit_profile(STUDENT* pJornal, int num);
void save_changes(STUDENT* pJornal, int numStud);
void backupFromFile(STUDENT* pJornal, int num);
int checkForBaseFile();
int countStudentsFromBase();
void sort_students_byName(STUDENT* pJornal, int num);
void sort_students_byMark(STUDENT* pJornal, int num);
STUDENT* deleteStudent(STUDENT* pJornal, int *num);
STUDENT* addStudent(STUDENT* pJornal, int *num);
