#include"game.h"

void test()
{
	char ch;
	do
	{
		Snake snake;//�����߽ṹ��

		gamestart(&snake);//��Ϸ��ʼ
		gamerun(&snake);//��Ϸ����
		gameend(&snake);//��Ϸ����

		setpos(90, 25);
		printf("�Ƿ�����һ��:Y/N ");
		scanf("%c", &ch);
		getchar();//���յ���Y��� �س���

	} while (ch == 'Y');
}

int main()
{
	srand(time(NULL));

	test();
	return 0;
}