#include"game.h"

void test()
{
	char ch;
	do
	{
		Snake snake;//创建蛇结构体

		gamestart(&snake);//游戏开始
		gamerun(&snake);//游戏运行
		gameend(&snake);//游戏结束

		setpos(90, 25);
		printf("是否再来一句:Y/N ");
		scanf("%c", &ch);
		getchar();//吸收掉按Y后的 回车键

	} while (ch == 'Y');
}

int main()
{
	srand(time(NULL));

	test();
	return 0;
}