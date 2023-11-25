#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//用于获取系统时间，来实现随机数的获取
#include<Windows.h>//用于实现输出字体颜色，改变输出字体颜色，好看一点！

#define ROW 20//棋盘行数
#define COL 20//棋盘列数

#define ROWS ROW+2
#define COLS COL+2

#define MINE 50//雷的个数


void Initborad(char borad[ROWS][COLS], int rows, int cols, char ret);//初始化底部棋盘
void Displayborad(char borad[ROWS][COLS], int row, int col);//打印棋盘

void Setmine(char borad[ROWS][COLS], int row, int col);//布置雷
void Screenmine(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷