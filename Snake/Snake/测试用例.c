#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>

//调整控制台窗口 大小 和 标题
//int main()
//{
//	system("mode con lines=30 cols=100");
//	system("title 贪吃蛇");
//	system("pause");
//	return 0;
//}

//获取控制台句柄  改变光标
//int main()
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
//
//	CONSOLE_CURSOR_INFO cursor = { 0 };//光标信息结构体变量
//	GetConsoleCursorInfo(handle, &cursor);//获取控制台光标信息
//	cursor.dwSize = 75;
//	cursor.bVisible = false;
//	SetConsoleCursorInfo(handle, &cursor);
//
//	return 0;
//}

//改变光标的位置
//int main()
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
//
//	COORD pos = { 50,50 };//设置光标坐标
//
//	SetConsoleCursorPosition(handle, pos);//设置光标的位置
//
//	printf("hehe\n");
//
//	return 0;
//}

//获取按键情况
//int Judge(int x)
//{
//	if ((GetAsyncKeyState(x) & 1) == 1)//如果按键被按下，则返回1
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	while (1)
//	{
//		if (Judge(0x30) == 1)
//		{
//			printf("0\n");
//		}
//		else if (Judge(0x31) == 1)
//		{
//			printf("1\n");
//		}
//		else if (Judge(0x32) == 1)
//		{
//			printf("2\n");
//		}
//		else if (Judge(0x33) == 1)
//		{
//			printf("3\n");
//		}
//		else if (Judge(0x34) == 1)
//		{
//			printf("4\n");
//		}
//		else if (Judge(0x35) == 1)
//		{
//			printf("5\n");
//		}
//		else if (Judge(0x36) == 1)
//		{
//			printf("6\n");
//		}
//		else if (Judge(0x37) == 1)
//		{
//			printf("7\n");
//		}
//		else if (Judge(0x38) == 1)
//		{
//			printf("8\n");
//		}
//		else if (Judge(0x39) == 1)
//		{
//			printf("9\n");
//		}
//	}
//
//	return 0;
//}