#define _CRT_SECURE_NO_WARNINGS 1
#ifndef ADDINFO
#define ADDINFO 0x0006

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"


bool AddInfo(sqlite3* db) {
	using namespace std;
	Student st;
	cout << "请输入学生学号：";
	cin >> st.uid;
	cout << "请输入学生姓名（请勿输入中文）：";
	cin >> st.name;
	cout << "请输入学生地址（请勿输入中文）：";
	cin >> st.address;
	if (insertIntoDatabase(db, st)) {
		cout << "插入成功！" << endl;;
		return true;
	}
	else {
		// 错误信息已打印
		return false;
	}
}
#endif // !ADDINFO