#include"game.h"

int get_bottom_mine(char borad[ROWS][COLS], int x, int y)//得到该坐标下，周围一圈雷的总数
{
	return borad[x - 1][y - 1] +
		borad[x - 1][y] +
		borad[x - 1][y + 1] +
		borad[x][y - 1] +
		borad[x][y + 1] +
		borad[x + 1][y - 1] +
		borad[x + 1][y] +
		borad[x + 1][y + 1] - 8 * '0';
}

void recur(char bottom[ROWS][COLS], char show[ROWS][COLS], int x, int y)//递归扩展
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 1 && i <= ROW && j >= 1 && j <= COL)
			{
				if ((get_bottom_mine(bottom, i, j) == 0 ) && (show[i][j] == '*'))
				{
					show[i][j] = ' ';
					recur(bottom, show, i, j);
				}
				else if ((get_bottom_mine(bottom, i, j) != 0) && (show[i][j] == '*'))
				{
					int count = get_bottom_mine(bottom, i, j);
					show[i][j] = count + '0';
				}
			}
		}
	}
}

int Jugdewin(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col)//判断输赢
{
	int count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}