#include"game.h"

void test()
{
	Snake snake;//创建蛇结构体

	gamestart(&snake);//游戏开始
	gamerun(&snake);//游戏运行
	gameend(&snake);//游戏结束
}

int main()
{
	srand(time(NULL));

	test();
	return 0;
}