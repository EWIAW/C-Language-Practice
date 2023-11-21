#include"Contact.h"

//����
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

//��������Ƿ�Ϊ��
void CheckCapacity(Contact* pp)
{
	//����
	if (pp->capacity == pp->sz)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pp->data, sizeof(PeoInfo) * (EVERY_SZ+pp->capacity));
		if (tmp == NULL)
		{
			perror("AddContact");
		}
		pp->data = tmp;
		pp->capacity = pp->capacity + 2;
		printf("���ݳɹ�\n");
	}
}

//��ʼ���ռ�
void InitContact(Contact* p)
{
	PeoInfo* tmp = (PeoInfo*)malloc(sizeof(PeoInfo) * INIT_SZ);
	if (tmp == NULL)
	{
		perror("InitContact");
		printf("����ʧ��\n");
		return;
	}
	p->data = tmp;
	p->capacity = INIT_SZ;
	p->sz = 0;

	//���ļ�
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

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//�����ϵ��
void AddContact(Contact* p)
{
	CheckCapacity(p);
	printf("������������");
	scanf("%s", &p->data[p->sz].name);
	printf("������绰���룺");
	scanf("%d", &p->data[p->sz].phonenum);
	printf("��ӳɹ�\n");
	p->sz++;
}

//ɾ����ϵ��
void DeleContact(Contact* p)
{
	int j;
	int i;
	if (p->sz == 0)
	{
		printf("��ͨѶ¼������ϵ�ˣ��޷�ɾ��\n");
		return;
	}
	char dele[NAME_MAX];
	PeoInfo reapeat[NAME_REA];
	printf("������ɾ���˵�������");
	scanf("%s", &dele);
	int count=FindContact(p, &dele,reapeat);

	printf("%-10s %-20s\n", "����", "�绰����");
	for (int i = 0; i < count; i++)
	{
		printf("%-10s %-20d\n", reapeat[i].name, reapeat[i].phonenum);
	}

	printf("������Ҫɾ���ڼ����˵���Ϣ��");
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
	printf("ɾ���ɹ�\n");
	p->sz--;
}

//�޸���ϵ����Ϣ
void ModifyContact(Contact* p)
{
	int j;
	int i;
	char modify[NAME_MAX];
	PeoInfo reapeat[NAME_REA];
	printf("�������޸��˵�������");
	scanf("%s", &modify);
	int count = FindContact(p, &modify, reapeat);
	printf("%-10s %-20s\n", "����", "�绰����");
	for (int i = 0; i < count; i++)
	{
		printf("%-10s %-20d\n", reapeat[i].name, reapeat[i].phonenum);
	}
	printf("������Ҫ�޸ĵڼ����˵���Ϣ��");
	scanf("%d", &i);
	for (j = 0; j < p->sz; j++)
	{
		if (p->data[j].phonenum == reapeat[i - 1].phonenum)
		{
			break;
		}
	}
	printf("�������޸ĺ��������");
	scanf("%s", &p->data[j].name);
	printf("�������޸ĺ�ĵ绰���룺");
	scanf("%d", &p->data[j].phonenum);
	printf("�޸ĳɹ�\n");
}

//������Ϣ
void CheckContact(Contact* p)
{
	char name[NAME_MAX];
	PeoInfo reapeat[NAME_REA];
	printf("����������˵�������");
	scanf("%s", &name);
	int count = FindContact(p, &name, reapeat);
	printf("%-10s %-20s\n", "����", "�绰����");
	for (int i = 0; i < count; i++)
	{
		printf("%-10s %-20d\n", reapeat[i].name, reapeat[i].phonenum);
	}
}

//���ͨѶ¼
void PrintContact(Contact* p)
{
	printf("%-10s %-20s\n", "����", "�绰����");
	for (int i = 0; i < p->sz; i++)
	{
		printf("%-10s %-20d\n", p->data[i].name, p->data[i].phonenum);
	}
}

//����
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
	printf("%-10s %-20s\n", "����", "�绰����");
	for (int i = 0; i < p.sz; i++)
	{
		printf("%-10s %-20d\n", p.data[i].name, p.data[i].phonenum);
	}
}

//����ͨѶ¼
void DestoryContact(Contact p)
{
	free(p.data);
	p.data = NULL;
	p.capacity = 0;
	p.sz = 0;
}

//����ͨѶ¼
void SaveContact(Contact p)
{
	FILE* pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}//���ļ�
	
	for (int i = 0; i < p.sz; i++)//д�ļ�
	{
		fwrite(&(p.data[i]), sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);//�ر��ļ�
	pf = NULL;
}