//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//	return 0;
//}


#include<stdio.h>

int Two(int n)
{
	if (n > 1)//nҪ����������Ƶ�Сһλ����������ƣ���n>1���������ƣ���n>5
	{
		Two(n / 2);
	}
	printf("%d", n % 2);
}

int main()
{
	int input;
	scanf("%d", &input);
	Two(input);
	return 0;
}