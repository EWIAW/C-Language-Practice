#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//���ڻ�ȡϵͳʱ�䣬��ʵ��������Ļ�ȡ
#include<Windows.h>//����ʵ�����������ɫ���ı����������ɫ���ÿ�һ�㣡

#define ROW 20//��������
#define COL 20//��������

#define ROWS ROW+2
#define COLS COL+2

#define MINE 50//�׵ĸ���


void Initborad(char borad[ROWS][COLS], int rows, int cols, char ret);//��ʼ���ײ�����
void Displayborad(char borad[ROWS][COLS], int row, int col);//��ӡ����

void Setmine(char borad[ROWS][COLS], int row, int col);//������
void Screenmine(char bottom[ROWS][COLS], char show[ROWS][COLS], int row, int col);//�Ų���