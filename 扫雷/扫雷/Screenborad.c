#include"game.h"

int get_around_mine(char bottom[ROWS][COLS],int x,int y)
{
	return bottom[x - 1][y - 1] +
		bottom[x - 1][y] +
		bottom[x - 1][y + 1] +
		bottom[x][y - 1] +
		bottom[x][y + 1] +
		bottom[x + 1][y - 1] +
		bottom[x + 1][y] +
		bottom[x + 1][y + 1] - 8 * '0';
}