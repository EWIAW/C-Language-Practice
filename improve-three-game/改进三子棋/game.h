#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ROW 10//��
#define COL 10//��

//�������һ��һ������������֣��Ա���������
#define ROWS ROW+1
#define COLS COL+1

void Initbroad(char broad[ROWS][COLS], int rows, int cols);//��ʼ������
void Displaybroad(char broad[ROWS][COLS], int rows, int cols);//��ӡ����

void Playermove(char broad[ROWS][COLS], int row, int col);//�������
void Computermove(char broad[ROWS][COLS], int row, int col);//��������

char Jugdewin(char broad[ROWS][COLS], int row, int col);//�ж���Ӯ