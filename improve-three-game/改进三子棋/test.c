#include"game.h"

void menu()//�˵�����
{
	printf("\t\t\t\t\t\t*******************************\n");
	printf("\t\t\t\t\t\t******      ������       ******\n");
	printf("\t\t\t\t\t\t******      1.play       ******\n");
	printf("\t\t\t\t\t\t******      2.exit       ******\n");
	printf("\t\t\t\t\t\t*******************************\n");
}

void color(int num)//��ɫ��������'X','O',���ϲ�ͬ����ɫ���Ա��ڹ۲�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

void game()
{
	char ret;//���ڽ��ܡ��ж���Ӯ�������ķ���ֵ������"O"������һ�ʤ������"X"������Ի�ʤ������'f'��������������ƽ�֣�����'u��,�������Ϸ
	char broad[ROWS][COLS];//��ά��������
	Initbroad(broad, ROWS, COLS);//��ʼ������
	Displaybroad(broad, ROWS, COLS);//��ӡ����

	while (1)
	{
		Playermove(broad, ROW, COL);//�������

		system("cls");

		Displaybroad(broad, ROWS, COLS);//��ӡ����

		ret = Jugdewin(broad, ROW, COL);//�ж���Ӯ

		if (ret != 'u')//���Jugdewin������'u'������Ϸ����������ѭ��
		{
			break;
		}

		Computermove(broad, ROW, COL);//��������

		system("cls");

		Displaybroad(broad, ROWS, COLS);//��ӡ����

		ret = Jugdewin(broad, ROW, COL);//�ж���Ӯ

		if (ret != 'u')//���Jugdewin������'u'������Ϸ����������ѭ��
		{
			break;
		}
	}
	if (ret == 'O')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == 'X')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));//���������������
	int input = 0;//�û�����ѡ��1��ʾ��ʼ��Ϸ��0��ʾ�˳���Ϸ
	do
	{
		menu();//�˵�����
		printf("��ѡ��:> ");
		scanf("%d", &input);

		system("cls");//�����Ļ������ϴ����µ���Ϣ

		switch (input)
		{
		case 1:
			//����1��������Ϸ
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ�� ");
			break;
		}
	} while (input);
	return 0;
}