#define _CRT_SECURE_NO_WARNINGS 1
#ifndef ADDINFO
#define ADDINFO 0x0006

#include "DataBaseOpt.h"
#include "Resouces/sqlite3.h"


bool AddInfo(sqlite3* db) {
	using namespace std;
	Student st;
	cout << "������ѧ��ѧ�ţ�";
	cin >> st.uid;
	cout << "������ѧ�������������������ģ���";
	cin >> st.name;
	cout << "������ѧ����ַ�������������ģ���";
	cin >> st.address;
	if (insertIntoDatabase(db, st)) {
		cout << "����ɹ���" << endl;;
		return true;
	}
	else {
		// ������Ϣ�Ѵ�ӡ
		return false;
	}
}
#endif // !ADDINFO