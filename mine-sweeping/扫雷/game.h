#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 15//棋盘行数
#define COL 15//棋盘列数

#define MINE 10//地雷个数

#define ROWS ROW+2//棋盘外扩一圈
#define COLS COL+2

void Initborad(char borad[ROWS][COLS], int rows, int cols, char ret);//初始化棋盘
void Displayborad(char borad[ROWS][COLS], int row, int col);//打印棋盘
void Setborad(char bottom[ROWS][COLS], int row, int col);//布置雷
void Screenborad(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷