#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "Resouces/sqlite3.h"
#include "Options.h"
#include "Menu.h"

using namespace std;

sqlite3* db;

int main() {
	int opt(-1);
	while (opt) {
		mainMenu();
		do {
			cout << "请输入：";
			cin >> opt;
		} while (opt<0 || opt >5);
		if (OpenDatabase(db) == false) {
			exit(EXIT_FAILURE);
		}
		switch (opt)
		{
		case 0:
			cout << "再见！" << endl;
			return 0;
		case 1:
			if(QueryAllInfo(db)==false)	exit(EXIT_FAILURE);
			break;
		case 2:
			if(AddInfo(db)==false) exit(EXIT_FAILURE);
			break;
		case 3:
			if (DeleteInfo(db) == false) exit(EXIT_FAILURE);
			break;
		case 4:
			if (UpdateInfo(db) == false) exit(EXIT_FAILURE);
			break;
		case 5:
			if (Query(db) == false) exit(EXIT_FAILURE);
			break;
		default:
			std::cout << "输入错误！" << endl;
			break;
		}
		system("pause");
	}
}
