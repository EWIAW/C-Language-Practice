#include"game.h"

void Initbroad(char broad[ROW][COL], int row, int col)                         //初始化棋盘
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			broad[i][j] = ' ';
		}
	}
}

void DisPlayBroad(char broad[ROW][COL], int row, int col)                      //打印棋盘
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", broad[i][j]);
			if (j < row - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < row - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void Playerbroad(char broad[ROW][COL], int row, int col)                       //玩家走
{
	printf("玩家走:\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (broad[x-1][y-1]==' ')
			{
				broad[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入：> ");
			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入：> ");
		}
		printf("\n");
	}
}

void Computerbroad(char broad[ROW][COL], int row, int col)                     //电脑走
{
	printf("电脑走:\n");
	while (1)
	{
		int x = rand() % 3;                                                    //产生随机坐标
		int y = rand() % 3;
		if (broad[x][y] == ' ')
		{
			broad[x][y] = '#';
			break;
		}
	}
}

char Judgewin(char broad[ROW][COL], int row, int col)                          //判断输赢
{
	//如果 行 全部相同，则返回
	for (int i = 0; i < row; i++)
	{
		if (broad[i][0] == broad[i][1] && broad[i][1] == broad[i][2] && broad[i][0]!=' ')
		{
			return broad[i][0];
		}
	}
	
	//如果 列 全部相同，则返回
	for (int i = 0; i < col; i++)
	{
		if (broad[0][i] == broad[1][i] && broad[1][i] == broad[2][i] && broad[0][i]!=' ')
		{
			return broad[0][i];
		}
	}

	//如果 对角线 全部相同，则返回
	if (broad[0][0] == broad[1][1] && broad[1][1] == broad[2][2] && broad[1][1] != ' ')
	{
		return broad[1][1];
	}
	if (broad[0][2] == broad[1][1] && broad[1][1] == broad[2][0] && broad[1][1] != ' ')
	{
		return broad[1][1];
	}
	
	//如果棋盘未满，则返回
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
			{
				return 'u';
			}
		}
	}

	//返回棋盘已满
	return 'f';
}