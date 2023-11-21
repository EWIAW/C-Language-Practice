#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX 20//姓名的最大长度

#define INIT_SZ 4//通讯录初始化容量
#define EVERY_SZ 2//每次增加的空间

#define NAME_REA 10//重名个数

typedef struct PeoInfo
{
	char name[NAME_MAX];//姓名
	int phonenum;//电话号码
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;//结构体指针
	int sz;//通讯录中存的人的个数
	int capacity;//通讯录的容量
}Contact;

enum
{
	EXIT,//退出
	ADD,//添加
	DELE,//删除
	MODIFY,//修改
	CHECK,//查找
	PRINT,//输出
	SORT//排序
};