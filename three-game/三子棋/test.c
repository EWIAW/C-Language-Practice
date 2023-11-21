#include"game.h"

void menu()                                                                    //�˵�����
{
	printf("\t\t\t\t\t**********************************\n");
	printf("\t\t\t\t\t******       1.play        ******\n");
	printf("\t\t\t\t\t******       0.exit        *******\n");
	printf("\t\t\t\t\t**********************************\n");
}

void game()                                                                    //��Ϸʵ��������
{
	char ret;                                                                  //������Ϸ����ķ���ֵ
	char broad[ROW][COL];                                                      //��������
	Initbroad(broad, ROW, COL);                                                //���̳�ʼ�� 
	DisPlayBroad(broad, ROW, COL);                                             //��ӡ����
	while (1)
	{
		Playerbroad(broad, ROW, COL);                                          //�����
		DisPlayBroad(broad, ROW, COL);                                         //��ӡ����
		ret=Judgewin(broad, ROW, COL);                                         //�ж���Ӯ
		if (ret != 'u')                                                        //���ret�ķ���ֵΪ'u'����Ϊ��Ϸû�н�������������
		{
			break;
		}

		Computerbroad(broad, ROW, COL);                                        //������
		DisPlayBroad(broad, ROW, COL);                                         //��ӡ����
		ret=Judgewin(broad, ROW, COL);                                         //�ж���Ӯ 
		if (ret != 'u')                                                        //���ret�ķ���ֵΪ'u'����Ϊ��Ϸû�н�������������
		{
			break;
		}
	}
	//ret
	//Ϊ * �����Ӯ��
	//Ϊ # ������Ӯ��
	//Ϊ f ��ƽ��
	//Ϊ u ����Ϸ��������
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if(ret=='#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	DisPlayBroad(broad, ROW, COL);                                             //��ӡ����
}

int main()
{
	srand((unsigned)time(NULL));                                               //�����������seed���������������
	int input = 0;                                                             //�û���������������ѡ��
	do
	{
		menu();                                                                //��ӡ�������
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();                                                            //��Ϸʵ�ֺ���
			break;
		case 0:                                                                //�˳���Ϸ
			break;
		default:
			printf("ѡ�����������ѡ�� \n");
			break;
		}
	} while (input);
	return 0;
}