#include"Contact.h"

void menu()
{
	printf("  1.���  2.ɾ��  \n");
	printf("  3.�޸�  4.����  \n");
	printf("  5.��ʾ  6.����  \n");
	printf("      0.�˳�      \n");
}

int main()
{
	Contact con;
	InitContact(&con);//��ʼ���ռ�
	int input;
	do
	{
		menu();
		printf("��ѡ����Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//�����ϵ��
			break;
		case DELE:
			DeleContact(&con);//ɾ����ϵ��
			break;
		case MODIFY:
			ModifyContact(&con);//�޸���ϵ��
			break;
		case CHECK:
			CheckContact(&con);//������ϵ��
			break;
		case PRINT:
			PrintContact(&con);//��ʾͨѶ¼
			break;
		case SORT:
			SortContact(con);//����ͨѶ¼
			break;
		case EXIT:
			SaveContact(&con);//����ͨѶ¼
			DestoryContact(&con);//����ͨѶ¼
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}