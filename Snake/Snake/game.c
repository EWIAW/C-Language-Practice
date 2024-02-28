#include"game.h"

//游戏开始
void gamestart(Snake* psnake)
{
	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
	CONSOLE_CURSOR_INFO cursor = { 0 };//光标信息结构体变量
	GetConsoleCursorInfo(handle, &cursor);//获取光标信息
	cursor.bVisible = false;//隐藏光标
	SetConsoleCursorInfo(handle, &cursor);//设置光标

	//设置控制台窗口信息
	system("mode con lines=50 cols=200");
	system("title 贪吃蛇");
	//system("pause");

	//打印游戏欢迎界面
	gamewelcome();

	//打印墙体
	printwall();

	//初始化蛇
	InitSnake(psnake);

	//打印蛇
	PrintSnake(psnake);

	//创建食物
	CreatFood(psnake);

	//打印食物
	setpos(psnake->Food->x,psnake->Food->y);
	printf("★");
}

//创建食物
void CreatFood(Snake* psnake)
{
again:
	//生成食物的坐标
	int x = rand() % 196 + 2;//生成横坐标
	if (x % 2 != 0)//如果生成食物的横坐标 不是 偶数 则重新生成
	{
		goto again;
	}
	int y = rand() % 40 + 1;

	//如果生成食物的坐标与蛇身重合，则重新生成
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

	//创建食物结点
	SnakeNode* food = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (food == NULL)
	{
		printf("CreatFood:食物结点创建失败\n");
		exit(-1);
	}
	food->next = NULL;
	food->x = x;
	food->y = y;
	psnake->Food = food;

}

//打印蛇
void PrintSnake(Snake* psnake)
{
	SnakeNode* cur = psnake->SnakeHead;
	while (cur != NULL)
	{
		setpos(cur->x, cur->y);
		printf("□");
		cur = cur->next;
	}
}

//初始化蛇
void InitSnake(Snake* psnake)
{
	//初始化五个蛇身的蛇

	//创建蛇头结构体
	SnakeNode* SHead = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (SHead == NULL)
	{
		printf("InitSnake:蛇头创建失败\n");
		exit(-1);
	}
	SHead->next = NULL;
	SnakeNode* cur = SHead;

	//创建蛇身
	for (int i = 0; i < 4; i++)
	{
		SnakeNode* Sbody = (SnakeNode*)malloc(sizeof(SnakeNode));
		if (SHead == NULL)
		{
			printf("InitSnake:蛇身创建失败\n");
			exit(-1);
		}
		Sbody->next = NULL;
		cur->next = Sbody;
		cur = Sbody;
	}

	//给每个蛇身坐标赋值
	cur = SHead;
	for (int i = 0; i < 5; i++)
	{
		cur->x = 100 - 2 * i;
		cur->y = 20;
		cur = cur->next;
	}

	//初始化游戏信息
	psnake->Food = NULL;
	psnake->gamesStatus = OK;
	psnake->score = 0;
	psnake->SnakeHead = SHead;
	psnake->snakeStatus = RIGHT;
	psnake->speed = 200;

	//读取游戏历史最高分数
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

//判断按键是否被按下
int JudgeKey(int x)
{
	if ((GetAsyncKeyState(x) & 1) == 1)
	{
		return 1;//按键被按下
	}
	else
	{
		return 0;//按键没被按下
	}
}

//暂停按键
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

//蛇运动函数
void SnakeMove(Snake* psnake)
{
	//在蛇的前进方向上创建一个新结点
	SnakeNode* newnode = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (newnode == NULL)
	{
		printf("SnakeMove:创建结点失败\n");
		exit(-1);
	}
	newnode->next = NULL;

	//判断当前蛇的运动状态 并 确定新结点的位置
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

	//将新结点链接到蛇头的前面  头插
	newnode->next = psnake->SnakeHead;
	psnake->SnakeHead = newnode;

	//判断蛇是否吃到自己
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

	//如果头结点 与 食物结点 重合 则 吃食物 分数增加 速度变快，并创建新食物
	if (psnake->SnakeHead->x == psnake->Food->x && psnake->SnakeHead->y == psnake->Food->y)
	{
		free(psnake->Food);//释放食物结点
		psnake->score += 10;
		if (psnake->speed > 20)
		{
			psnake->speed -= 20;
		}

		//创建新食物 并 打印新食物
		CreatFood(psnake);
		setpos(psnake->Food->x, psnake->Food->y);
		printf("★");

		PrintSnake(psnake);
	}
	else if (psnake->SnakeHead->x == 0 ||
			psnake->SnakeHead->x == 198 ||
			psnake->SnakeHead->y == 0 ||
			psnake->SnakeHead->y == 41)//如果头结点在墙上，则 游戏结束
	{
		psnake->gamesStatus = KILL_BY_WALL;
	}
	else//如果都不是，则蛇正常前进
	{
		//找到倒数第二个结点
		SnakeNode* cur = psnake->SnakeHead;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}

		//覆盖掉尾结点 方块
		setpos(cur->next->x, cur->next->y);
		printf("  ");

		free(cur->next);
		cur->next = NULL;

		PrintSnake(psnake);
	}

}

//游戏运行
void gamerun(Snake* psnake)
{
	do
	{
		setpos(70, 45);
		printf("当前分数：%d", psnake->score);

		setpos(130, 45);
		printf("游戏历史最高分数:%d", psnake->maxscore);

		//判断按键状态
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
		else if (JudgeKey(VK_ESCAPE) == 1)//退出按键
		{
			psnake->gamesStatus = ESC;
		}
		else if (JudgeKey(VK_SPACE) == 1)//暂停按键
		{
			pause();
		}

		Sleep(psnake->speed);

		SnakeMove(psnake);//蛇运动函数
	} while (psnake->gamesStatus == OK);

}

//游戏结束善后工作  内存释放
void gameend(Snake* psnake)
{
	if (psnake->gamesStatus == KILL_BY_SELF)
	{
		setpos(90, 20);
		printf("你吃到自己了，游戏结束\n");
	}
	else
	{
		setpos(90, 20);
		printf("你撞到墙了，游戏结束\n");
	}

	//判断游戏当前分数是否超过历史最高分数
	if (psnake->score > psnake->maxscore)
	{
		FILE* pf = fopen("MaxScore.txt", "w");
		if (pf == NULL)
		{
			printf("gameend:文件打开失败\n");
			exit(-1);
		}
		fprintf(pf, "%d\n", psnake->score);

		fclose(pf);
	}
	
	//内存释放

	free(psnake->Food);//释放食物结点
	
	//释放蛇身链表
	SnakeNode* cur = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (cur == NULL)
	{
		printf("gameend:创建结点失败\n");
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

//设置坐标
void setpos(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
	COORD pos = { x,y };
	SetConsoleCursorPosition(handle, pos);//设置光标位置
}

//打印墙体
void printwall()
{
	system("cls");//清屏
	//打印上面的墙
	setpos(0, 0);
	for (int i = 0; i < 100; i++)
	{
		printf("■");
	}

	//打印下面的墙
	setpos(0, 41);
	for (int i = 0; i < 100; i++)
	{
		printf("■");
	}

	//打印左面的墙
	int x = 0;
	for (int y = 1; y < 41; y++)
	{
		setpos(x, y);
		printf("■");
	}

	//打印右面的墙
	x = 198;
	for (int y = 1; y < 41; y++)
	{
		setpos(x, y);
		printf("■");
	}

	setpos(100, 45);
	//system("pause");
}

//打印游戏欢迎界面
void gamewelcome()
{
	setpos(90, 25);
	printf("欢迎来到贪吃蛇小游戏\n");
	system("pause");
}