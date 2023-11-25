#include"game.h"

void menu()
{
	printf("\t\t\t\t\t\t**************************\n");
	printf("\t\t\t\t\t\t*******   1.play   *******\n");
	printf("\t\t\t\t\t\t*******   0.exit   *******\n");
	printf("\t\t\t\t\t\t**************************\n");
}

void game()
{
	char bottom[ROWS][COLS];
	char show[ROWS][COLS];

	Initborad(bottom, ROWS, COLS, '0');//��ʼ���ײ�����
	Initborad(show, ROWS, COLS, '*');//��ʼ������������
	//Displayborad(bottom, ROW, COL);//��ӡ�ײ�����

	system("cls");

	Displayborad(show, ROW, COL);//��ӡ��������

	Setmine(bottom, ROW, COL);//������
	//Displayborad(bottom, ROW, COL);//��ӡ�ײ�����

	Screenmine(bottom, show, ROW, COL);//�Ų���
}

void color(int num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);

	return 0;
}