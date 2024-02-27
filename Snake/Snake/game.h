#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<time.h>

//ö���ߵķ���״̬
enum SnakeStatus
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};

//ö����Ϸ״̬
enum GameStatus
{
	OK=1,
	STOP,
	KILL_BY_WALL,
	KILL_BY_SELF
};

//����ṹ��
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode;

//��Ϸ��Ϣ�ṹ��
typedef struct Snake
{
	SnakeNode* SnakeHead;//ָ����ͷ����ָ��
	SnakeNode* Food;//ʳ����
	int score;//��Ϸ����
	int speed;//��Ϸ�ٶ�

	//�ߵķ���״̬
	enum SnakeStatus snakeStatus;

	//��Ϸ״̬
	enum GameStatus gamesStatus;
}Snake;

void gamestart(Snake* psnake);//��Ϸ��ʼ
void gamerun(Snake* psnake);//��Ϸ����
void gameend(Snake* psnake);//��Ϸ����

//��ӡǽ��
void printwall();

//��������
void setpos(int x, int y);

//��ӡ��Ϸ��ӭ����
void gamewelcome();

//��ʼ����
void InitSnake(Snake* psnake);

//��ӡ��
void PrintSnake(Snake* psnake);

//����ʳ��
void CreatFood(Snake* psnake);