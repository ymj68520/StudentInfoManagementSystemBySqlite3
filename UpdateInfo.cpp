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
	cout << "�޸���Ϣֻ֧��ʹ��ѧ�ţ�����֪��" << endl
		<< "��������޸ĵ�ѧ��ѧ�ţ�_";
	string uid;
	cin >> uid;
	cout << "��ѧ������Ϣ���£�" << endl;
	Student stu(-1, uid, "", "");
	selectOneInfo(db,stu);

	cout << "���������޸��أ�" << endl;
	cout << "\t 1.��� \t 2.ѧ��" << endl;
	cout << "\t 3.���� \t 4.����" << endl;
	cout << "�����룺_";
	char choice;
	cin >> choice;
	if (choice < '1' || choice > '4') {
		cout << "�������" << endl
			<< "�Ƿ��������yes/y����_";
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

	if (false == updateInfoByUid(db, st, uid)) {
		cout << "������һЩ����" << endl
			<< "�Ƿ������޸ģ���yes/y����_";
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