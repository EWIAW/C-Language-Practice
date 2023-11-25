#include"game.h"

void Initborad(char borad[ROWS][COLS], int rows, int cols, char ret)//��ʼ���ײ�����
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
	color(2);
	for (int i = 0; i <= col; i++)
	{
		printf(" %2d", i);
	}
	color(15);

	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		color(2);
		printf(" %2d", i);
		color(15);

		for (int j = 1; j <= col; j++)
		{
			if (borad[i][j] != '*')
			{
				color(9);
				printf(" %2c", borad[i][j]);
				color(15);
				continue;
			}
			printf(" %2c", borad[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char borad[ROWS][COLS], int row, int col)//������
{
	int count = MINE;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;

		if (borad[x][y] == '0')
		{
			borad[x][y] = '1';
			count--;
		}
	}
}

void Screenmine(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col)//�Ų���
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("�������Ų������: ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (show[x][y] == '*')
			{
				if (bottom[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					break;
				}
				else
				{
					int num = get_bottom_mine(bottom, x, y);
					if (num == 0)
					{
						show[x][y] = ' ';
						recur(bottom, show, x, y);
					}
					else
					{
						show[x][y] = num + '0';

					}
					system("cls");
					Displayborad(show, ROW, COL);//��ӡ��������
				}
			}
			else
			{
				printf("�������ѱ�ɨ��������������\n");
			}

		}
		else
		{
			printf("��������Ƿ�������������\n");
		}

		if (Jugdewin(bottom, show, row, col) == MINE)
		{
			printf("��ϲ�㣬ɨ�׳ɹ�\n");
			break;
		}
	}

}