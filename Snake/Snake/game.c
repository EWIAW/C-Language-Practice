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
	//����ʳ�������
	int x = rand() % 196 + 2;//���ɺ�����
	if (x % 2 != 0)//�������ʳ��ĺ����� ���� ż�� ����������
	{
		goto again;
	}
	int y = rand() % 40 + 1;

	//�������ʳ��������������غϣ�����������
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

	//����ʳ����
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
	cur = SHead;
	for (int i = 0; i < 5; i++)
	{
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

	//��ȡ��Ϸ��ʷ��߷���
	FILE* pf = fopen("MaxScore.txt", "r");
	if (pf == NULL)
	{
		psnake->maxscore = 0;
	}
	else
	{
		fscanf(pf, "%d\n", &psnake->maxscore);
		fclose(pf);
	}

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

//���˶�����
void SnakeMove(Snake* psnake)
{
	//���ߵ�ǰ�������ϴ���һ���½��
	SnakeNode* newnode = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (newnode == NULL)
	{
		printf("SnakeMove:�������ʧ��\n");
		exit(-1);
	}
	newnode->next = NULL;

	//�жϵ�ǰ�ߵ��˶�״̬ �� ȷ���½���λ��
	switch (psnake->snakeStatus)
	{
	case RIGHT:
		newnode->x = psnake->SnakeHead->x + 2;
		newnode->y = psnake->SnakeHead->y;
		break;
	case LEFT:
		newnode->x = psnake->SnakeHead->x - 2;
		newnode->y = psnake->SnakeHead->y;
		break;
	case UP:
		newnode->x = psnake->SnakeHead->x;
		newnode->y = psnake->SnakeHead->y - 1;
		break;
	case DOWN:
		newnode->x = psnake->SnakeHead->x;
		newnode->y = psnake->SnakeHead->y + 1;
		break;
	}

	//���½�����ӵ���ͷ��ǰ��  ͷ��
	newnode->next = psnake->SnakeHead;
	psnake->SnakeHead = newnode;

	//�ж����Ƿ�Ե��Լ�
	SnakeNode* cur = psnake->SnakeHead->next;
	while (cur != NULL)
	{
		if (psnake->SnakeHead->x == cur->x && psnake->SnakeHead->y == cur->y)
		{
			psnake->gamesStatus = KILL_BY_SELF;
			break;	
		}
		else
		{
			cur = cur->next;
		}
	}

	//���ͷ��� �� ʳ���� �غ� �� ��ʳ�� �������� �ٶȱ�죬��������ʳ��
	if (psnake->SnakeHead->x == psnake->Food->x && psnake->SnakeHead->y == psnake->Food->y)
	{
		free(psnake->Food);//�ͷ�ʳ����
		psnake->score += 10;
		if (psnake->speed > 20)
		{
			psnake->speed -= 20;
		}

		//������ʳ�� �� ��ӡ��ʳ��
		CreatFood(psnake);
		setpos(psnake->Food->x, psnake->Food->y);
		printf("��");

		PrintSnake(psnake);
	}
	else if (psnake->SnakeHead->x == 0 ||
			psnake->SnakeHead->x == 198 ||
			psnake->SnakeHead->y == 0 ||
			psnake->SnakeHead->y == 41)//���ͷ�����ǽ�ϣ��� ��Ϸ����
	{
		psnake->gamesStatus = KILL_BY_WALL;
	}
	else//��������ǣ���������ǰ��
	{
		//�ҵ������ڶ������
		SnakeNode* cur = psnake->SnakeHead;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}

		//���ǵ�β��� ����
		setpos(cur->next->x, cur->next->y);
		printf("  ");

		free(cur->next);
		cur->next = NULL;

		PrintSnake(psnake);
	}

}

//��Ϸ����
void gamerun(Snake* psnake)
{
	do
	{
		setpos(70, 45);
		printf("��ǰ������%d", psnake->score);

		setpos(130, 45);
		printf("��Ϸ��ʷ��߷���:%d", psnake->maxscore);

		//�жϰ���״̬
		if (JudgeKey(VK_LEFT) == 1 && psnake->snakeStatus!=RIGHT)
		{
			psnake->snakeStatus = LEFT;
		}
		else if (JudgeKey(VK_RIGHT) == 1 && psnake->snakeStatus!=LEFT)
		{
			psnake->snakeStatus = RIGHT;
		}
		else if (JudgeKey(VK_UP) == 1 && psnake->snakeStatus != DOWN)
		{
			psnake->snakeStatus = UP;
		}
		else if (JudgeKey(VK_DOWN) == 1 && psnake->snakeStatus != UP)
		{
			psnake->snakeStatus = DOWN;
		}
		else if (JudgeKey(VK_ESCAPE) == 1)//�˳�����
		{
			psnake->gamesStatus = ESC;
		}
		else if (JudgeKey(VK_SPACE) == 1)//��ͣ����
		{
			pause();
		}

		Sleep(psnake->speed);

		SnakeMove(psnake);//���˶�����
	} while (psnake->gamesStatus == OK);

}

//��Ϸ�����ƺ���  �ڴ��ͷ�
void gameend(Snake* psnake)
{
	if (psnake->gamesStatus == KILL_BY_SELF)
	{
		setpos(90, 20);
		printf("��Ե��Լ��ˣ���Ϸ����\n");
	}
	else
	{
		setpos(90, 20);
		printf("��ײ��ǽ�ˣ���Ϸ����\n");
	}

	//�ж���Ϸ��ǰ�����Ƿ񳬹���ʷ��߷���
	if (psnake->score > psnake->maxscore)
	{
		FILE* pf = fopen("MaxScore.txt", "w");
		if (pf == NULL)
		{
			printf("gameend:�ļ���ʧ��\n");
			exit(-1);
		}
		fprintf(pf, "%d\n", psnake->score);

		fclose(pf);
	}
	
	//�ڴ��ͷ�

	free(psnake->Food);//�ͷ�ʳ����
	
	//�ͷ���������
	SnakeNode* cur = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (cur == NULL)
	{
		printf("gameend:�������ʧ��\n");
		exit(-1);
	}
	cur = psnake->SnakeHead;
	SnakeNode* curNext = cur->next;

	while (curNext != NULL)
	{
		free(cur);
		cur = curNext;
		curNext = curNext->next;
	}
	free(cur);
	cur = NULL;
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