
#pragma once
#include "Students_base.h"

class Backup
{
	Backup *m_pBackup;
	bool isExist;

public:
	void saveToBackUp(STUDENT* pJornal);
	void getFromBackup(STUDENT* pJornal);
};