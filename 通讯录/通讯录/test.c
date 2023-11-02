#include"Contact.h"

void menu()
{
	printf("  1.添加  2.删除  \n");
	printf("  3.修改  4.查找  \n");
	printf("  5.显示  6.排序  \n");
	printf("      0.退出      \n");
}

int main()
{
	Contact con;
	InitContact(&con);//初始化空间
	int input;
	do
	{
		menu();
		printf("请选择你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//添加联系人
			break;
		case DELE:
			DeleContact(&con);//删除联系人
			break;
		case MODIFY:
			ModifyContact(&con);//修改联系人
			break;
		case CHECK:
			CheckContact(&con);//查找联系人
			break;
		case PRINT:
			PrintContact(&con);//显示通讯录
			break;
		case SORT:
			SortContact(con);//排序通讯录
			break;
		case EXIT:
			SaveContact(&con);//保存通讯录
			DestoryContact(&con);//销毁通讯录
			printf("退出程序\n");
			break;
		default:
			printf("选择错误请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}