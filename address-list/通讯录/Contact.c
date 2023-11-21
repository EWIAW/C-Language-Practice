#include"Contact.h"

//查找
int FindContact(Contact* pp, char name[NAME_MAX],PeoInfo reapeat[NAME_REA])
{
	int count = 0;
	for (int i = 0; i < pp->sz; i++)
	{
		if (strcmp(pp->data[i].name,name)==0)
		{
			strcpy(reapeat[count].name, pp->data[i].name);
			reapeat[count].phonenum = pp->data[i].phonenum;
			count++;
		}
	}
	return count;
}

//检查容量是否为满
void CheckCapacity(Contact* pp)
{
	//扩容
	if (pp->capacity == pp->sz)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pp->data, sizeof(PeoInfo) * (EVERY_SZ+pp->capacity));
		if (tmp == NULL)
		{
			perror("AddContact");
		}
		pp->data = tmp;
		pp->capacity = pp->capacity + 2;
		printf("扩容成功\n");
	}
}

//初始化空间
void InitContact(Contact* p)
{
	PeoInfo* tmp = (PeoInfo*)malloc(sizeof(PeoInfo) * INIT_SZ);
	if (tmp == NULL)
	{
		perror("InitContact");
		printf("开辟失败\n");
		return;
	}
	p->data = tmp;
	p->capacity = INIT_SZ;
	p->sz = 0;

	//打开文件
	FILE* pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("InitContact");
		return;
	}
	
	PeoInfo tmpp = { 0 };
	while (fread(&tmpp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(p);
		p->data[p->sz] = tmpp;
		p->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//添加联系人
void AddContact(Contact* p)
{
	CheckCapacity(p);
	printf("请输入姓名：");
	scanf("%s", &p->data[p->sz].name);
	printf("请输入电话号码：");
	scanf("%d", &p->data[p->sz].phonenum);
	printf("添加成功\n");
	p->sz++;
}

//删除联系人
void DeleContact(Contact* p)
{
	int j;
	int i;
	if (p->sz == 0)
	{
		printf("该通讯录中无联系人，无法删除\n");
		return;
	}
	char dele[NAME_MAX];
	PeoInfo reapeat[NAME_REA];
	printf("请输入删除人的姓名：");
	scanf("%s", &dele);
	int count=FindContact(p, &dele,reapeat);

	printf("%-10s %-20s\n", "姓名", "电话号码");
	for (int i = 0; i < count; i++)
	{
		printf("%-10s %-20d\n", reapeat[i].name, reapeat[i].phonenum);
	}

	printf("请输入要删除第几个人的信息：");
	scanf("%d", &i);

	for (j = 0; j < p->sz; j++)
	{
		if (p->data[j].phonenum == reapeat[i - 1].phonenum)
		{
			break;
		}
	}

	for (j; j < p->sz - 1; j++)
	{
		p->data[j] = p->data[j + 1];
	}
	printf("删除成功\n");
	p->sz--;
}

//修改联系人信息
void ModifyContact(Contact* p)
{
	int j;
	int i;
	char modify[NAME_MAX];
	PeoInfo reapeat[NAME_REA];
	printf("请输入修改人的姓名：");
	scanf("%s", &modify);
	int count = FindContact(p, &modify, reapeat);
	printf("%-10s %-20s\n", "姓名", "电话号码");
	for (int i = 0; i < count; i++)
	{
		printf("%-10s %-20d\n", reapeat[i].name, reapeat[i].phonenum);
	}
	printf("请输入要修改第几个人的信息：");
	scanf("%d", &i);
	for (j = 0; j < p->sz; j++)
	{
		if (p->data[j].phonenum == reapeat[i - 1].phonenum)
		{
			break;
		}
	}
	printf("请输入修改后的姓名：");
	scanf("%s", &p->data[j].name);
	printf("请输入修改后的电话号码：");
	scanf("%d", &p->data[j].phonenum);
	printf("修改成功\n");
}

//查找信息
void CheckContact(Contact* p)
{
	char name[NAME_MAX];
	PeoInfo reapeat[NAME_REA];
	printf("请输入查找人的姓名：");
	scanf("%s", &name);
	int count = FindContact(p, &name, reapeat);
	printf("%-10s %-20s\n", "姓名", "电话号码");
	for (int i = 0; i < count; i++)
	{
		printf("%-10s %-20d\n", reapeat[i].name, reapeat[i].phonenum);
	}
}

//输出通讯录
void PrintContact(Contact* p)
{
	printf("%-10s %-20s\n", "姓名", "电话号码");
	for (int i = 0; i < p->sz; i++)
	{
		printf("%-10s %-20d\n", p->data[i].name, p->data[i].phonenum);
	}
}

//排序
void SortContact(Contact p)
{
	for (int i = 0; i < p.sz; i++)
	{
		for (int j = 0; j < p.sz-1-i; j++)
		{
			if (strcmp(p.data[j].name,p.data[j+1].name)>0)
			{
				PeoInfo tmp;
				tmp = p.data[j];
				p.data[j] = p.data[j + 1];
				p.data[j + 1] = tmp;
			}
		}
	}
	printf("%-10s %-20s\n", "姓名", "电话号码");
	for (int i = 0; i < p.sz; i++)
	{
		printf("%-10s %-20d\n", p.data[i].name, p.data[i].phonenum);
	}
}

//销毁通讯录
void DestoryContact(Contact p)
{
	free(p.data);
	p.data = NULL;
	p.capacity = 0;
	p.sz = 0;
}

//保存通讯录
void SaveContact(Contact p)
{
	FILE* pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}//打开文件
	
	for (int i = 0; i < p.sz; i++)//写文件
	{
		fwrite(&(p.data[i]), sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);//关闭文件
	pf = NULL;
}