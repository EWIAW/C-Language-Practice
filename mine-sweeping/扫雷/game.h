#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 15//��������
#define COL 15//��������

#define MINE 10//���׸���

#define ROWS ROW+2//��������һȦ
#define COLS COL+2

void Initborad(char borad[ROWS][COLS], int rows, int cols, char ret);//��ʼ������
void Displayborad(char borad[ROWS][COLS], int row, int col);//��ӡ����
void Setborad(char bottom[ROWS][COLS], int row, int col);//������
void Screenborad(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col);//�Ų���