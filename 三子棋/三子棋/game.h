#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void Initbroad(char broad[ROW][COL], int row, int col);                        //��ʼ������
void DisPlayBroad(char broad[ROW][COL], int row, int col);                     //��ӡ����

void Playerbroad(char broad[ROW][COL], int row, int col);                      //�����
void Computerbroad(char broad[ROW][COL], int row, int col);                    //������

char Judgewin(char broad[ROW][COL], int row, int col);                         //�ж���Ӯ