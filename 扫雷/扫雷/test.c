#include"game.h"

void menu()
{
	printf("\t\t\t\t\t\t******************************\n");
	printf("\t\t\t\t\t\t******      1.play     *******\n");
	printf("\t\t\t\t\t\t******      0.exit     *******\n");
	printf("\t\t\t\t\t\t******************************\n");
}

void game()
{
	char bottom[ROWS][COLS];//�ײ����̣�����׵���Ϣ
	char show[ROWS][COLS];//�������̣���ӡ��Χ�׵ĸ���

	Initborad(bottom, ROWS, COLS,'0');//��ʼ���ײ�����
	Initborad(show, ROWS, COLS,'*');//��ʼ����������

	system("cls");

	//Displayborad(bottom, ROW, COL);//��ӡ�ײ�����
	Displayborad(show, ROW, COL);//��ӡ��������

	Setborad(bottom, ROW, COL);//������
	//Displayborad(bottom, ROW, COL);//��ӡ�ײ�����

	Screenborad(bottom, show, ROW, COL);//�Ų���
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
			printf("�����������������\n");
			break;
		}
	} while (input);

	return 0;
}