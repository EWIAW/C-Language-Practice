#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ROW 10//行
#define COL 10//列

//多出来的一行一列用来存放数字，以便于找坐标
#define ROWS ROW+1
#define COLS COL+1

void Initbroad(char broad[ROWS][COLS], int rows, int cols);//初始化棋盘
void Displaybroad(char broad[ROWS][COLS], int rows, int cols);//打印棋盘

void Playermove(char broad[ROWS][COLS], int row, int col);//玩家下棋
void Computermove(char broad[ROWS][COLS], int row, int col);//电脑下棋

char Jugdewin(char broad[ROWS][COLS], int row, int col);//判断输赢