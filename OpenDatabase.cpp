#define _CRT_SECURE_NO_WARNINGS 1
#ifndef OPENDATABASE
#define OPENDATABASE 0x0005

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"
#include <iostream>

bool OpenDatabase(sqlite3*& db) {
	openDatabase(db);
	if (db == nullptr) {
		std::cout << "�����ݿ�ʧ�ܣ�" << std::endl;
		return false;
	}
	return true;
}

#endif