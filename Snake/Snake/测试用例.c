#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>

//��������̨���� ��С �� ����
//int main()
//{
//	system("mode con lines=30 cols=100");
//	system("title ̰����");
//	system("pause");
//	return 0;
//}

//��ȡ����̨���  �ı���
//int main()
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
//
//	CONSOLE_CURSOR_INFO cursor = { 0 };//�����Ϣ�ṹ�����
//	GetConsoleCursorInfo(handle, &cursor);//��ȡ����̨�����Ϣ
//	cursor.dwSize = 75;
//	cursor.bVisible = false;
//	SetConsoleCursorInfo(handle, &cursor);
//
//	return 0;
//}

//�ı����λ��
//int main()
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
//
//	COORD pos = { 50,50 };//���ù������
//
//	SetConsoleCursorPosition(handle, pos);//���ù���λ��
//
//	printf("hehe\n");
//
//	return 0;
//}

//��ȡ�������
//int Judge(int x)
//{
//	if ((GetAsyncKeyState(x) & 1) == 1)//������������£��򷵻�1
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