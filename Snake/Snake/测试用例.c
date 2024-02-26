//#include<stdio.h>
//#include<stdlib.h>
//#include<Windows.h>
//#include<stdbool.h>
//
//int Judge(short x)
//{
//	if ((GetAsyncKeyState(x) & 1) == 1)
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
//	//system("mode con lines=30 cols=100");
//	//system("title 贪吃蛇");
//	//system("pause");
//
//	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//CONSOLE_CURSOR_INFO CurInfo;
//
//	//GetConsoleCursorInfo(handle, &CurInfo);
//
//	//CurInfo.dwSize = 25;
//
//	//CurInfo.bVisible = false;
//
//	//SetConsoleCursorInfo(handle, &CurInfo);
//
//	//COORD pos = { 50,50 };
//
//	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	//SetConsoleCursorPosition(handle, pos);
//
//	//printf("hehe\n");
//
//
//	//GetAsyncKeyState	//获取一个按键的状态  判断一个键是否被按过
//
//	while (1)
//	{
//		if (Judge(0x30))
//		{
//			printf("0\n");
//		}
//		else if (Judge(0x31))
//		{
//			printf("1\n");
//		}
//		else if (Judge(0x32))
//		{
//			printf("2\n");
//		}
//		else if (Judge(0x33))
//		{
//			printf("3\n");
//		}
//		else if (Judge(0x34))
//		{
//			printf("4\n");
//		}
//		else if (Judge(0x35))
//		{
//			printf("5\n");
//		}
//		else if (Judge(0x36))
//		{
//			printf("6\n");
//		}
//		else if (Judge(0x37))
//		{
//			printf("7\n");
//		}
//		else if (Judge(0x38))
//		{
//			printf("8\n");
//		}
//		else if (Judge(0x39))
//		{
//			printf("9\n");
//		}
//	}
//
//	return 0;
//}