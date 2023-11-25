#include"game.h"

void menu()
{
	printf("\t\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t\t*******   1.play   *******\n");
	printf("\t\t\t\t\t\t*******   0.exit   *******\n");
	printf("\t\t\t\t\t\t**************************\n");
}

void game()
{
	char bottom[ROWS][COLS];
	char show[ROWS][COLS];

	Initborad(bottom, ROWS, COLS, '0');//初始化底部棋盘
	Initborad(show, ROWS, COLS, '*');//初始化顶部部棋盘
	//Displayborad(bottom, ROW, COL);//打印底部棋盘

	system("cls");

	Displayborad(show, ROW, COL);//打印顶部棋盘

	Setmine(bottom, ROW, COL);//布置雷
	//Displayborad(bottom, ROW, COL);//打印底部棋盘

	Screenmine(bottom, show, ROW, COL);//排查雷
}

void color(int num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}