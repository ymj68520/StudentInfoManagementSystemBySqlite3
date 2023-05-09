#define _CRT_SECURE_NO_WARNINGS 1
#ifndef DATABASEOPT
#define DATABASEOPT 0x0002

#include "Resouces/sqlite3.h"
#include "DataBaseOpt.h"

extern "C";

using namespace std;

string DataBaseFilePath = "StudentInfo.db";

int rerr;
char* ErrMsg = 0;

static int callbackshow(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	return 0;
}
static int callbackvoid(void* NotUsed, int argc, char** argv, char** azColName) {
	printf("OK.....\n");
	return 0;
}
string int2string(int a) {
	string str = "";
	for (;a > 0;a /= 10) {
		str += '0' + (a % 10);
	}
	str.reserve();
	return str;
}

string stu2str(Student& st) {
	string str = "";
	str += "'"+ st.uid + "'" + ",";
	str += "'" + st.name + "'" + ",";
	str +=  "'" + st.address + "'";
	return str;
}

bool showResult() {
	if (rerr != SQLITE_OK) {
		printf("Sql Execute Error: %s\n", ErrMsg);
		sqlite3_free(ErrMsg);
		return false;
	}
	else {
		return true;
	}
}
// 打开数据库
bool openDatabase(sqlite3 *&db) {
	rerr = sqlite3_open(DataBaseFilePath.c_str(), &db);
	if (rerr) {
		printf("Open Database Error!\n");
		return false;
	}
	return true;
}
// 查询总共的条数
int queryNumOfRecords(sqlite3* db) {
	int pnRow(0);
	rerr = sqlite3_get_table(db, "select * from studentinfo", nullptr, &pnRow, nullptr, &ErrMsg);
	showResult();
	return pnRow;
}
// 在数据库中添加数据
bool insertIntoDatabase(sqlite3* db, Student& st) {
	string sql = "insert into studentinfo(uid,name,address) "\
		"values(";
	sql += stu2str(st) + ");";
	rerr = sqlite3_exec(db, sql.c_str(), callbackshow, 0, &ErrMsg);
	return showResult();
}
// 删除
bool deleteFromDatabase(sqlite3* db, Student& st) {
	string sql = "delete from studentinfo where ";
	if (st.id != -1) {
		sql += "id = " + to_string(st.id) + ";";
	}
	else if (st.uid != "") {
		sql += "uid = '" + st.uid + "';";
	}
	else if (st.name != "") {
		sql += "name = '" + st.name + "';";
	}
	else if (st.address != "") {
		sql += "address = '" + st.address + "';";
	}
	else
		return false;
	// sql += to_string(st.id) + ";";
	rerr = sqlite3_exec(db, sql.c_str(), callbackshow,0,&ErrMsg);
	return showResult();
}
// 查找一个
bool selectOneInfo(sqlite3* db, Student& st) {
	string sql = "select * from studentinfo where ";
	if (st.id != -1) {
		sql += "id = " + to_string(st.id) + ";";
	}
	else if (st.uid != "") {
		sql += "uid = '" + st.uid + "';";
	}
	else if (st.name != "") {
		sql += "name = '" + st.name + "';";
	}
	else if (st.address != "") {
		sql += "address = '" + st.address + "';";
	}
	else
		return false;
	// string sql = "select * from studentinfo where id = ";
	// sql += to_string(st.id) + ";";
	rerr = sqlite3_exec(db, sql.c_str(), callbackshow, 0, &ErrMsg);
	return showResult();
}
// 查找所有
bool selectAllInfo(sqlite3* db) {
	string sql = "select * from studentinfo";
	rerr = sqlite3_exec(db, sql.c_str(), callbackshow, 0, &ErrMsg);
	return showResult();
}

bool updateInfoByUid(sqlite3* db, Student& st, string uid) {
	string sql = "update studentinfo set ";
	if (st.id != -1) {
		sql += "id = " + to_string(st.id) + " ";
	}
	else if (st.uid != "") {
		sql += "uid = '" + st.uid + "'";
	}
	else if (st.name != "") {
		sql += "name = '" + st.name + "'";
	}
	else if (st.address != "") {
		sql += "address = '" + st.address + "'";
	}
	else
		return false;
	sql += "where uid = '" + uid + "';";
	rerr = sqlite3_exec(db, sql.c_str(), callbackshow, 0, &ErrMsg);
	return showResult();
}

#endif // !DATABASEOPT 0x0002



