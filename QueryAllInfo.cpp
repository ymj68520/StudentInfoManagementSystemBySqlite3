#define _CRT_SECURE_NO_WARNINGS 1
#ifndef QUERYALL
#define QUERYALL 0x0004

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"

bool QueryAllInfo(sqlite3* db) {
	return	selectAllInfo(db);
}

#endif // !QUERYALL