#define _CRT_SECURE_NO_WARNINGS 1
#ifndef DELETEINFO
#define DELETEINFO 0x0007

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"

bool DeleteInfo(sqlite3* db) {
	using namespace std;
	cout << "�����������ʲô��Ϣɾ���أ�" << endl;
	cout << "\t 1.��� \t 2.ѧ��" << endl;
	cout << "\t 3.���� \t 4.����" << endl;
	cout << "\t ��ע�⣺�����ͼ�������ж���������" << endl;
	cout << "\t ��      ����ϸȷ������Ҫɾ�������ݣ���";
	cout << "�����룺_" << endl;
	char choice;
	cin >> choice;
	if (choice < '1' || choice > '4') {
		cout << "�������" << endl
			<< "�Ƿ��������yes/y����_";
		cin >> choice;
		if (choice == 'y') {
			fflush(stdout);
			DeleteInfo(db);
		}
		return false;
	}

	int id(-1);
	string str;
	Student st;
	cout << "�����룺_";
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

	if (false == deleteFromDatabase(db, st)) {
		cout << "������һЩ����" << endl
			<< "�Ƿ���������ɾ�����򣿡�yes/y����_";
		cin >> choice;
		if (choice == 'y') {
			fflush(stdout);
			DeleteInfo(db);
		}
		return false;
	}

	return true;
}

#endif // !DELETEINFO