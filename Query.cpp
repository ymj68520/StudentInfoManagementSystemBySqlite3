#define _CRT_SECURE_NO_WARNINGS 1
#ifndef QUERY
#define QUERY 0x0008

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"

bool Query(sqlite3* db) {
	using namespace std;
	cout << "请问您想根据什么信息查询呢？" << endl;
	cout << "\t 1.序号 \t 2.学号" << endl;
	cout << "\t 3.姓名 \t 4.籍贯" << endl;
	cout << "\t 【注意：姓名和籍贯可能有多个结果！】" << endl;
	cout << "请输入：_";
	char choice;
	cin >> choice;
	if (choice < '1' || choice > '4') {
		cout << "输入错误！" << endl
			<< "是否继续？【yes/y】：_";
		cin >> choice;
		if (choice == 'y') {
			fflush(stdout);
			Query(db);
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

	if (false == selectOneInfo(db, st)) {
		cout << "发生了一些错误！" << endl
			<< "是否重新查询？【yes/y】：_";
		cin >> choice;
		if (choice == 'y') {
			fflush(stdout);
			Query(db);
		}
		return false;
	}

	return true;
}

#endif // !QUERY