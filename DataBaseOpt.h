#pragma once
#include "Resouces/sqlite3.h"
#include <string>
#include <iostream>
#include "Student.h"

bool openDatabase(sqlite3*& db);
int queryNumOfRecords(sqlite3* db);
bool insertIntoDatabase(sqlite3* db, Student& st);
bool deleteFromDatabase(sqlite3* db, Student& st);
bool selectOneInfo(sqlite3* db, Student& st);
bool selectAllInfo(sqlite3* db);
bool updateInfoByUid(sqlite3* db, Student& st, std::string uid);