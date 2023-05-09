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
	printf("\t\t\t*      学生籍贯信息记录簿      *\n");
	printf("\t\t\t*                              *\n");
	printf("\t\t\t*   [0]   退出                 *\n");
	printf("\t\t\t*   [1]   查看所有学生信息     *\n");
	printf("\t\t\t*   [2]   输入学生记录         *\n");
	printf("\t\t\t*   [3]   删除学生记录         *\n");
	printf("\t\t\t*   [4]   编辑学生记录         *\n");
	printf("\t\t\t*   [5]   查询                 *\n");
	printf("\t\t\t*                              *\n");
	printf("\t\t\t********************************\n");
	printf("\t\t\t*                              *\n");
}

#endif // !MAINMENU 