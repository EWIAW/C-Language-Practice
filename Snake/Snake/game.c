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
	for (int i = 0; i < 5; i++)
	{
		cur = SHead;
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

void SnakeMove(Snake* psnake)
{

}

//游戏运行
void gamerun(Snake* psnake)
{
	setpos(70, 45);
	printf("当前分数：%d", psnake->score);

	//蛇的运动状态
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
	else if (JudgeKey(VK_ESCAPE) == 1)//退出按键
	{
		;
	}
	else if (JudgeKey(VK_SPACE) == 1)//暂停按键
	{
		pause();
	}

	sleep(psnake->speed);

	SnakeMove(psnake);

}

void gameend(Snake* psnake)
{

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