#define _CRT_SECURE_NO_WARNINGS 1
#ifndef UPDATEINFO
#define UPDATEINFO 0x0009

//#include "DatabaseOpt.cpp"
//#include "Student.cpp"
#include <iostream>
#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"
bool UpdateInfo(sqlite3* db) {
	using namespace std;
	cout << "修改信息只支持使用学号！望周知！" << endl
		<< "请输入待修改的学生学号：_";
	string uid;
	cin >> uid;
	cout << "该学生的信息如下：" << endl;
	Student stu(-1, uid, "", "");
	selectOneInfo(db,stu);

	cout << "请问您想修改呢？" << endl;
	cout << "\t 1.序号 \t 2.学号" << endl;
	cout << "\t 3.姓名 \t 4.籍贯" << endl;
	cout << "请输入：_";
	char choice;
	cin >> choice;
	if (choice < '1' || choice > '4') {
		cout << "输入错误！" << endl
			<< "是否继续？【yes/y】：_";
		cin >> choice;
		if (choice == 'y') {
			fflush(stdout);
			UpdateInfo(db);
		}
		return false;
	}

	int id(-1);
	string str;
	Student st;
	cout << "请输入:_";
	if (choice < '2') {
		cin >> id;
		st.id = id;
	}
	else
	{
		cin >> str;
		if (choice < '3')	st.uid = str;
		if (choice < '4') st.name = str;
		else st.address = str;
	}

	if (false == updateInfoByUid(db, st, uid)) {
		cout << "发生了一些错误！" << endl
			<< "是否重新修改？【yes/y】：_";
		cin >> choice;
		if (choice == 'y') {
			fflush(stdout);
			UpdateInfo(db);
		}
		return false;
	}

	return true;
}

#endif // !UPDATEINFO