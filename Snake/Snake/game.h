#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<time.h>

//枚举蛇的方向状态
enum SnakeStatus
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};

//枚举游戏状态
enum GameStatus
{
	OK=1,
	STOP,
	KILL_BY_WALL,
	KILL_BY_SELF
};

//蛇身结构体
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode;

//游戏信息结构体
typedef struct Snake
{
	SnakeNode* SnakeHead;//指向蛇头结点的指针
	SnakeNode* Food;//食物结点
	int score;//游戏分数
	int speed;//游戏速度

	//蛇的方向状态
	enum SnakeStatus snakeStatus;

	//游戏状态
	enum GameStatus gamesStatus;
}Snake;

void gamestart(Snake* psnake);//游戏开始
void gamerun(Snake* psnake);//游戏运行
void gameend(Snake* psnake);//游戏结束

//打印墙体
void printwall();

//设置坐标
void setpos(int x, int y);

//打印游戏欢迎界面
void gamewelcome();

//初始化蛇
void InitSnake(Snake* psnake);

//打印蛇
void PrintSnake(Snake* psnake);

//创建食物
void CreatFood(Snake* psnake);