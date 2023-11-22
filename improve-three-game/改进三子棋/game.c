#include"game.h"

void Initbroad(char broad[ROWS][COLS], int rows, int cols)//初始化棋盘
{
	//将下棋区域全部赋上空格' '
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			broad[i][j] = ' ';
		}
	}
	//将第一行赋为0，1，2，3，4……
	for (int i = 0; i < cols; i++)
	{
		broad[0][i] = i;
	}
	//将第一列赋为1，2，3，4，5……
	for (int i = 1; i < rows; i++)
	{
		broad[i][0] = i;
	}
}

void Displaybroad(char broad[ROWS][COLS], int rows, int cols)//打印棋盘
{
	//打印第一行的数字
	for (int i = 0; i < rows; i++)
	{
		printf(" %2d ", broad[0][i]);
		if (i < rows - 1)
		{
			printf("|");
		}
	}
	printf("\n");
	for (int i = 1; i < rows; i++)
	{
		//打印分隔线
		for (int i = 0; i < rows; i++)
		{
			printf("----");
			if (i < rows - 1)
			{
				printf("|");
			}
		}

		printf("\n");

		printf(" %2d ", broad[i][0]);//打印第一列的数字
		for (int j = 1; j < cols; j++)
		{
			printf("|");

			if (broad[i][j] == 'O')//如果检测到下个打印的字符为'O',则改变输出字符的颜色
			{
				color(2);//将输出颜色变为绿色
				printf(" %2c ", broad[i][j]);
				color(15);//输出完后，再将输出颜色变为原来的颜色
				continue;//跳出本次循环
			}

			if (broad[i][j] == 'X')//如果检测到下个打印的字符为'X',则改变输出字符的颜色
			{
				color(6);//将输出颜色变为黄色
				printf(" %2c ", broad[i][j]);
				color(15);//输出完后，再将输出颜色变为原来的颜色
				continue;//跳出本次循环
			}

			printf(" %2c ", broad[i][j]);

		}
		printf("\n");
	}
}

void Playermove(char broad[ROWS][COLS], int row, int col)//玩家下棋
{
	printf("玩家走\n");
	int x = 0;//行坐标
	int y = 0;//列坐标
	while (1)
	{
		printf("请选择你的坐标:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//如果输入坐标在棋盘内，则成立
		{
			if (broad[x][y] == ' ')
			{
				broad[x][y] = 'O';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新选择\n");
			}
		}
		else
		{
			printf("没有此坐标，请重新输入\n");
		}
	}
}

void Computermove(char broad[ROWS][COLS], int row, int col)//电脑下棋
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % row + 1;//随机生成1~row的数字
		int y = rand() % col + 1;//随机生成1~col的数字
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (broad[x][y] == ' ')
			{
				broad[x][y] = 'X';
				break;
			}
		}
	}
}

char Jugdewin(char broad[ROWS][COLS], int row, int col)//判断输赢
{
	for (int i = 1; i <= row; i++)//控制每一行和每一列
	{
		for (int j = 1; j <= col - 2; j++)
		{
			//判断行是否符合
			if (broad[i][j] == broad[i][j + 1] && broad[i][j + 1] == broad[i][j + 2] && broad[i][j] != ' ')
			{
				return broad[i][j];
			}

			//判断列是否符合
			if (broad[j][i] == broad[j + 1][i] && broad[j + 1][i] == broad[j + 2][i] && broad[j][i] != ' ')
			{
				return broad[j][i];
			}
		}
	}
	//判断斜向是否符合
	for (int i = 1; i <= row - 2; i++)
	{
		for (int j = 1; j <= col - 2; j++)
		{
			if (broad[i][j] == broad[i + 1][j + 1] && broad[i + 1][j + 1] == broad[i + 2][j + 2] && broad[i + 1][j + 1] != ' ')
			{
				return broad[i + 1][j + 1];
			}

			if (broad[i][row - j + 1] == broad[i + 1][row - j] && broad[i + 1][row - j] == broad[i + 2][row - j - 1] && broad[i + 1][row - j] != ' ')
			{
				return broad[i + 1][row - j];
			}
		}
	}
	//检查棋盘是否已满，如果不是，则返回 u
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= row; j++)
		{
			if (broad[i][j] == ' ')
			{
				return 'u';
			}
		}
	}

	return 'f';
}