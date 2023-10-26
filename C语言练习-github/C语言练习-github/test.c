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
	if (n > 1)//n要大于所求进制的小一位，如求二进制，则n>1，求六进制，则n>5
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