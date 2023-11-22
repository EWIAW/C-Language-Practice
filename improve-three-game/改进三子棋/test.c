#include"game.h"

void menu()//菜单函数
{
	printf("\t\t\t\t\t\t*******************************\n");
	printf("\t\t\t\t\t\t******      三子棋       ******\n");
	printf("\t\t\t\t\t\t******      1.play       ******\n");
	printf("\t\t\t\t\t\t******      2.exit       ******\n");
	printf("\t\t\t\t\t\t*******************************\n");
}

void color(int num)//颜色函数，将'X','O',赋上不同的颜色，以便于观察
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

void game()
{
	char ret;//用于接受“判断输赢函数”的返回值，返回"O"，则玩家获胜，返回"X"，则电脑获胜，返回'f'，则棋盘已满，平局，返回'u’,则继续游戏
	char broad[ROWS][COLS];//二维数组棋盘
	Initbroad(broad, ROWS, COLS);//初始化棋盘
	Displaybroad(broad, ROWS, COLS);//打印棋盘

	while (1)
	{
		Playermove(broad, ROW, COL);//玩家下棋

		system("cls");

		Displaybroad(broad, ROWS, COLS);//打印棋盘

		ret = Jugdewin(broad, ROW, COL);//判断输赢

		if (ret != 'u')//如果Jugdewin不等于'u'，则游戏结束，跳出循环
		{
			break;
		}

		Computermove(broad, ROW, COL);//电脑下棋

		system("cls");

		Displaybroad(broad, ROWS, COLS);//打印棋盘

		ret = Jugdewin(broad, ROW, COL);//判断输赢

		if (ret != 'u')//如果Jugdewin不等于'u'，则游戏结束，跳出循环
		{
			break;
		}
	}
	if (ret == 'O')
	{
		printf("玩家获胜\n");
	}
	else if (ret == 'X')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));//用于随机数的生成
	int input = 0;//用户做出选择，1表示开始游戏，0表示退出游戏
	do
	{
		menu();//菜单函数
		printf("请选择:> ");
		scanf("%d", &input);

		system("cls");//清空屏幕，清除上次留下的信息

		switch (input)
		{
		case 1:
			//输入1，进入游戏
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择 ");
			break;
		}
	} while (input);
	return 0;
}