#include"game.h"

void Initbroad(char broad[ROW][COL], int row, int col)                         //��ʼ������
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			broad[i][j] = ' ';
		}
	}
}

void DisPlayBroad(char broad[ROW][COL], int row, int col)                      //��ӡ����
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

void Playerbroad(char broad[ROW][COL], int row, int col)                       //�����
{
	printf("�����:\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������> ");
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
				printf("�������ѱ�ռ�ã����������룺> ");
			}
		}
		else
		{
			printf("���������Ƿ������������룺> ");
		}
		printf("\n");
	}
}

void Computerbroad(char broad[ROW][COL], int row, int col)                     //������
{
	printf("������:\n");
	while (1)
	{
		int x = rand() % 3;                                                    //�����������
		int y = rand() % 3;
		if (broad[x][y] == ' ')
		{
			broad[x][y] = '#';
			break;
		}
	}
}

char Judgewin(char broad[ROW][COL], int row, int col)                          //�ж���Ӯ
{
	//��� �� ȫ����ͬ���򷵻�
	for (int i = 0; i < row; i++)
	{
		if (broad[i][0] == broad[i][1] && broad[i][1] == broad[i][2] && broad[i][0]!=' ')
		{
			return broad[i][0];
		}
	}
	
	//��� �� ȫ����ͬ���򷵻�
	for (int i = 0; i < col; i++)
	{
		if (broad[0][i] == broad[1][i] && broad[1][i] == broad[2][i] && broad[0][i]!=' ')
		{
			return broad[0][i];
		}
	}

	//��� �Խ��� ȫ����ͬ���򷵻�
	if (broad[0][0] == broad[1][1] && broad[1][1] == broad[2][2] && broad[1][1] != ' ')
	{
		return broad[1][1];
	}
	if (broad[0][2] == broad[1][1] && broad[1][1] == broad[2][0] && broad[1][1] != ' ')
	{
		return broad[1][1];
	}
	
	//�������δ�����򷵻�
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

	//������������
	return 'f';
}