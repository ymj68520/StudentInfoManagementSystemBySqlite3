#define _CRT_SECURE_NO_WARNINGS 1
#ifndef QUERY
#define QUERY 0x0008

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"

bool Query(sqlite3* db) {
	using namespace std;
	cout << "�����������ʲô��Ϣ��ѯ�أ�" << endl;
	cout << "\t 1.��� \t 2.ѧ��" << endl;
	cout << "\t 3.���� \t 4.����" << endl;
	cout << "\t ��ע�⣺�����ͼ�������ж���������" << endl;
	cout << "�����룺_";
	char choice;
	cin >> choice;
	if (choice < '1' || choice > '4') {
		cout << "�������" << endl
			<< "�Ƿ��������yes/y����_";
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
	cout << "������:_";
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
		cout << "������һЩ����" << endl
			<< "�Ƿ����²�ѯ����yes/y����_";
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