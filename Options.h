#pragma once
#include "Resouces/sqlite3.h"
#include "Student.h"

bool UpdateInfo(sqlite3* db);
bool Query(sqlite3* db);
bool DeleteInfo(sqlite3* db);
bool AddInfo(sqlite3* db);
bool OpenDatabase(sqlite3*& db);
bool QueryAllInfo(sqlite3* db);