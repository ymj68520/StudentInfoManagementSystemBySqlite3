#define _CRT_SECURE_NO_WARNINGS 1
#ifndef MAINMENU 
#define MAXMENU 0x0003


#include <io.h>
#include <stdio.h>
#include <stdlib.h>

const int minOptNum = 0;
const int maxOptNum = 7;
void mainMenu()
{
	system("cls");
	printf("\n");
	printf("\t\t\t********************************\n");
	printf("\t\t\t*                              *\n");
	printf("\t\t\t*      ѧ��������Ϣ��¼��      *\n");
	printf("\t\t\t*                              *\n");
	printf("\t\t\t*   [0]   �˳�                 *\n");
	printf("\t\t\t*   [1]   �鿴����ѧ����Ϣ     *\n");
	printf("\t\t\t*   [2]   ����ѧ����¼         *\n");
	printf("\t\t\t*   [3]   ɾ��ѧ����¼         *\n");
	printf("\t\t\t*   [4]   �༭ѧ����¼         *\n");
	printf("\t\t\t*   [5]   ��ѯ                 *\n");
	printf("\t\t\t*                              *\n");
	printf("\t\t\t********************************\n");
	printf("\t\t\t*                              *\n");
}

#endif // !MAINMENU 