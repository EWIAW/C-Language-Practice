#include"game.h"

void Initbroad(char broad[ROWS][COLS], int rows, int cols)//��ʼ������
{
	//����������ȫ�����Ͽո�' '
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			broad[i][j] = ' ';
		}
	}
	//����һ�и�Ϊ0��1��2��3��4����
	for (int i = 0; i < cols; i++)
	{
		broad[0][i] = i;
	}
	//����һ�и�Ϊ1��2��3��4��5����
	for (int i = 1; i < rows; i++)
	{
		broad[i][0] = i;
	}
}

void Displaybroad(char broad[ROWS][COLS], int rows, int cols)//��ӡ����
{
	//��ӡ��һ�е�����
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
		//��ӡ�ָ���
		for (int i = 0; i < rows; i++)
		{
			printf("----");
			if (i < rows - 1)
			{
				printf("|");
			}
		}

		printf("\n");

		printf(" %2d ", broad[i][0]);//��ӡ��һ�е�����
		for (int j = 1; j < cols; j++)
		{
			printf("|");

			if (broad[i][j] == 'O')//�����⵽�¸���ӡ���ַ�Ϊ'O',��ı�����ַ�����ɫ
			{
				color(2);//�������ɫ��Ϊ��ɫ
				printf(" %2c ", broad[i][j]);
				color(15);//�������ٽ������ɫ��Ϊԭ������ɫ
				continue;//��������ѭ��
			}

			if (broad[i][j] == 'X')//�����⵽�¸���ӡ���ַ�Ϊ'X',��ı�����ַ�����ɫ
			{
				color(6);//�������ɫ��Ϊ��ɫ
				printf(" %2c ", broad[i][j]);
				color(15);//�������ٽ������ɫ��Ϊԭ������ɫ
				continue;//��������ѭ��
			}

			printf(" %2c ", broad[i][j]);

		}
		printf("\n");
	}
}

void Playermove(char broad[ROWS][COLS], int row, int col)//�������
{
	printf("�����\n");
	int x = 0;//������
	int y = 0;//������
	while (1)
	{
		printf("��ѡ���������:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//������������������ڣ������
		{
			if (broad[x][y] == ' ')
			{
				broad[x][y] = 'O';
				break;
			}
			else
			{
				printf("�������ѱ�ռ�ã�������ѡ��\n");
			}
		}
		else
		{
			printf("û�д����꣬����������\n");
		}
	}
}

void Computermove(char broad[ROWS][COLS], int row, int col)//��������
{
	printf("������\n");
	while (1)
	{
		int x = rand() % row + 1;//�������1~row������
		int y = rand() % col + 1;//�������1~col������
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

char Jugdewin(char broad[ROWS][COLS], int row, int col)//�ж���Ӯ
{
	for (int i = 1; i <= row; i++)//����ÿһ�к�ÿһ��
	{
		for (int j = 1; j <= col - 2; j++)
		{
			//�ж����Ƿ����
			if (broad[i][j] == broad[i][j + 1] && broad[i][j + 1] == broad[i][j + 2] && broad[i][j] != ' ')
			{
				return broad[i][j];
			}

			//�ж����Ƿ����
			if (broad[j][i] == broad[j + 1][i] && broad[j + 1][i] == broad[j + 2][i] && broad[j][i] != ' ')
			{
				return broad[j][i];
			}
		}
	}
	//�ж�б���Ƿ����
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
	//��������Ƿ�������������ǣ��򷵻� u
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