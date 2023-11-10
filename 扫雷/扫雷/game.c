#include"game.h"

void Initborad(char borad[ROWS][COLS], int rows, int cols, char ret)//��ʼ������
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			borad[i][j] = ret;
		}
	}
}

void Displayborad(char borad[ROWS][COLS], int row, int col)//��ӡ����
{
	for (int i = 0; i <= col; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%2c ", borad[i][j]);
		}
		printf("\n");
	}
}

void Setborad(char bottom[ROWS][COLS], int row, int col)//������
{
	int count = MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (bottom[x][y] != '1')
		{
			bottom[x][y] = '1';
			count--;
		}
	}
}

void Screenborad(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col)//�Ų���
{
	int count = ROW * COL - MINE;//�����׵ĸ���
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("��������Ҫ�Ų�������꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (bottom[x][y] == '1')
			{
				printf("���ź����㱻��ը����\n");
				break;
			}
			else
			{
				int ret = get_around_mine(bottom, x, y);
				show[x][y] = ret+'0';
				system("cls");
				Displayborad(show, ROW, COL);//��ӡ��������
				count--;
				if (count == 0)
				{
					break;
				}
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}

	if (count == 0)
	{
		printf("��ϲ�����׳ɹ�\n");
	}
}