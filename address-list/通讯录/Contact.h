#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX 20//��������󳤶�

#define INIT_SZ 4//ͨѶ¼��ʼ������
#define EVERY_SZ 2//ÿ�����ӵĿռ�

#define NAME_REA 10//��������

typedef struct PeoInfo
{
	char name[NAME_MAX];//����
	int phonenum;//�绰����
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;//�ṹ��ָ��
	int sz;//ͨѶ¼�д���˵ĸ���
	int capacity;//ͨѶ¼������
}Contact;

enum
{
	EXIT,//�˳�
	ADD,//���
	DELE,//ɾ��
	MODIFY,//�޸�
	CHECK,//����
	PRINT,//���
	SORT//����
};