#include"game.h"

void test()
{
	Snake snake;//�����߽ṹ��

	gamestart(&snake);//��Ϸ��ʼ
	gamerun(&snake);//��Ϸ����
	gameend(&snake);//��Ϸ����
}

int main()
{
	srand(time(NULL));

	test();
	return 0;
}