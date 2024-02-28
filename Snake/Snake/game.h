#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<time.h>

//枚举蛇的方向状态
enum SnakeStatus
{
	UP=1,//上
	DOWN,//下
	LEFT,//左
	RIGHT//右
};

//枚举游戏状态
enum GameStatus
{
	OK=1,//正常运行
	STOP,//暂停
	KILL_BY_WALL,//撞墙死
	KILL_BY_SELF,//撞自己死
	ESC//退出
};

//蛇身结构体
typedef struct SnakeNode
{
	int x;//横坐标
	int y;//纵坐标
	struct SnakeNode* next;
}SnakeNode;

//游戏信息结构体
typedef struct Snake
{
	SnakeNode* SnakeHead;//指向蛇头结点的指针
	SnakeNode* Food;//食物结点
	int score;//游戏分数
	int maxscore;//游戏历史最高分数
	int speed;//游戏速度

	//蛇的方向状态
	enum SnakeStatus snakeStatus;

	//游戏状态
	enum GameStatus gamesStatus;
}Snake;

void gamestart(Snake* psnake);//游戏开始
void gamerun(Snake* psnake);//游戏运行
void gameend(Snake* psnake);//游戏结束

//打印游戏欢迎界面
void gamewelcome();

//打印墙体
void printwall();

//移动光标位置
void setpos(int x, int y);

//初始化蛇
void InitSnake(Snake* psnake);

//打印蛇
void PrintSnake(Snake* psnake);

//创建食物
void CreatFood(Snake* psnake);

//按下暂停按键
void pause();

//蛇运动函数
void SnakeMove(Snake* psnake);

//判断按键是否被按下
int JudgeKey(int x);