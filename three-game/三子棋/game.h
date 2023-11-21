#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void Initbroad(char broad[ROW][COL], int row, int col);                        //初始化棋盘
void DisPlayBroad(char broad[ROW][COL], int row, int col);                     //打印棋盘

void Playerbroad(char broad[ROW][COL], int row, int col);                      //玩家走
void Computerbroad(char broad[ROW][COL], int row, int col);                    //电脑走

char Judgewin(char broad[ROW][COL], int row, int col);                         //判断输赢