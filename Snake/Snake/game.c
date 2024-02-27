#include"game.h"

//��Ϸ��ʼ
void gamestart(Snake* psnake)
{
	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
	CONSOLE_CURSOR_INFO cursor = { 0 };//�����Ϣ�ṹ�����
	GetConsoleCursorInfo(handle, &cursor);//��ȡ�����Ϣ
	cursor.bVisible = false;//���ع��
	SetConsoleCursorInfo(handle, &cursor);//���ù��

	//���ÿ���̨������Ϣ
	system("mode con lines=50 cols=200");
	system("title ̰����");
	//system("pause");

	//��ӡ��Ϸ��ӭ����
	gamewelcome();

	//��ӡǽ��
	printwall();

	//��ʼ����
	InitSnake(psnake);

	//��ӡ��
	PrintSnake(psnake);

	//����ʳ��
	CreatFood(psnake);

	//��ӡʳ��
	setpos(psnake->Food->x,psnake->Food->y);
	printf("��");
}

//����ʳ��
void CreatFood(Snake* psnake)
{
again:

	int x = rand() % 198 + 1;
	int y = rand() % 40 + 1;

	SnakeNode* cur = psnake->SnakeHead;
	while (cur != NULL)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		else
		{
			cur = cur->next;
		}
	}

	SnakeNode* food = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (food == NULL)
	{
		printf("CreatFood:ʳ���㴴��ʧ��\n");
		exit(-1);
	}
	food->next = NULL;
	food->x = x;
	food->y = y;
	psnake->Food = food;

}

//��ӡ��
void PrintSnake(Snake* psnake)
{
	SnakeNode* cur = psnake->SnakeHead;
	while (cur != NULL)
	{
		setpos(cur->x, cur->y);
		printf("��");
		cur = cur->next;
	}
}

//��ʼ����
void InitSnake(Snake* psnake)
{
	//��ʼ������������

	//������ͷ�ṹ��
	SnakeNode* SHead = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (SHead == NULL)
	{
		printf("InitSnake:��ͷ����ʧ��\n");
		exit(-1);
	}
	SHead->next = NULL;
	SnakeNode* cur = SHead;

	//��������
	for (int i = 0; i < 4; i++)
	{
		SnakeNode* Sbody = (SnakeNode*)malloc(sizeof(SnakeNode));
		if (SHead == NULL)
		{
			printf("InitSnake:������ʧ��\n");
			exit(-1);
		}
		Sbody->next = NULL;
		cur->next = Sbody;
		cur = Sbody;
	}

	//��ÿ���������긳ֵ
	for (int i = 0; i < 5; i++)
	{
		cur = SHead;
		cur->x = 100 - 2 * i;
		cur->y = 20;
		cur = cur->next;
	}

	//��ʼ����Ϸ��Ϣ
	psnake->Food = NULL;
	psnake->gamesStatus = OK;
	psnake->score = 0;
	psnake->SnakeHead = SHead;
	psnake->snakeStatus = RIGHT;
	psnake->speed = 200;

}

//�жϰ����Ƿ񱻰���
int JudgeKey(int x)
{
	if ((GetAsyncKeyState(x) & 1) == 1)
	{
		return 1;//����������
	}
	else
	{
		return 0;//����û������
	}
}

//��ͣ����
void pause()
{
	while (1)
	{
		if (JudgeKey(VK_SPACE) == 1)
		{
			break;
		}
	}
}

void SnakeMove(Snake* psnake)
{

}

//��Ϸ����
void gamerun(Snake* psnake)
{
	setpos(70, 45);
	printf("��ǰ������%d", psnake->score);

	//�ߵ��˶�״̬
	if (JudgeKey(VK_LEFT) == 1)
	{
		psnake->snakeStatus = LEFT;
	}
	else if (JudgeKey(VK_RIGHT) == 1)
	{
		psnake->snakeStatus = RIGHT;
	}
	else if (JudgeKey(VK_UP) == 1)
	{
		psnake->snakeStatus = UP;
	}
	else if (JudgeKey(VK_DOWN) == 1)
	{
		psnake->snakeStatus = DOWN;
	}
	else if (JudgeKey(VK_ESCAPE) == 1)//�˳�����
	{
		;
	}
	else if (JudgeKey(VK_SPACE) == 1)//��ͣ����
	{
		pause();
	}

	sleep(psnake->speed);

	SnakeMove(psnake);

}

void gameend(Snake* psnake)
{

}

//��������
void setpos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
	COORD pos = { x,y };
	SetConsoleCursorPosition(handle, pos);//���ù��λ��
}

//��ӡǽ��
void printwall()
{
	system("cls");//����
	//��ӡ�����ǽ
	setpos(0, 0);
	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	//��ӡ�����ǽ
	setpos(0, 41);
	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	//��ӡ�����ǽ
	int x = 0;
	for (int y = 1; y < 41; y++)
	{
		setpos(x, y);
		printf("��");
	}

	//��ӡ�����ǽ
	x = 198;
	for (int y = 1; y < 41; y++)
	{
		setpos(x, y);
		printf("��");
	}

	setpos(100, 45);
	//system("pause");
}

//��ӡ��Ϸ��ӭ����
void gamewelcome()
{
	setpos(90, 25);
	printf("��ӭ����̰����С��Ϸ\n");
	system("pause");
}