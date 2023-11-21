#include"game.h"

void menu()                                                                    //菜单函数
{
	printf("\t\t\t\t\t**********************************\n");
	printf("\t\t\t\t\t******       1.play        ******\n");
	printf("\t\t\t\t\t******       0.exit        *******\n");
	printf("\t\t\t\t\t**********************************\n");
}

void game()                                                                    //游戏实现主函数
{
	char ret;                                                                  //接受游戏结果的返回值
	char broad[ROW][COL];                                                      //定义棋盘
	Initbroad(broad, ROW, COL);                                                //棋盘初始化 
	DisPlayBroad(broad, ROW, COL);                                             //打印棋盘
	while (1)
	{
		Playerbroad(broad, ROW, COL);                                          //玩家走
		DisPlayBroad(broad, ROW, COL);                                         //打印棋盘
		ret=Judgewin(broad, ROW, COL);                                         //判断输赢
		if (ret != 'u')                                                        //如果ret的返回值为'u'，则为游戏没有结束，继续进行
		{
			break;
		}

		Computerbroad(broad, ROW, COL);                                        //电脑走
		DisPlayBroad(broad, ROW, COL);                                         //打印棋盘
		ret=Judgewin(broad, ROW, COL);                                         //判断输赢 
		if (ret != 'u')                                                        //如果ret的返回值为'u'，则为游戏没有结束，继续进行
		{
			break;
		}
	}
	//ret
	//为 * ，玩家赢了
	//为 # ，电脑赢了
	//为 f ，平局
	//为 u ，游戏继续进行
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if(ret=='#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisPlayBroad(broad, ROW, COL);                                             //打印棋盘
}

int main()
{
	srand((unsigned)time(NULL));                                               //创造随机种子seed，用来生成随机数
	int input = 0;                                                             //用户输入数字来做出选择
	do
	{
		menu();                                                                //打印进入界面
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();                                                            //游戏实现函数
			break;
		case 0:                                                                //退出游戏
			break;
		default:
			printf("选择错误，请重新选择： \n");
			break;
		}
	} while (input);
	return 0;
}