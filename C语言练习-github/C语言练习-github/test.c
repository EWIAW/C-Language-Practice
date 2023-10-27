//#include<stdio.h>
//
//int main()
//{
//	printf("hello world\n");
//	return 0;
//}


//#include<stdio.h>
//
//int Two(int n)
//{
//	if (n > 1)//n要大于所求进制的小一位，如求二进制，则n>1，求六进制，则n>5
//	{
//		Two(n / 2);
//	}
//	printf("%d", n % 2);
//}
//
//int main()
//{
//	int input;
//	scanf("%d", &input);
//	Two(input);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a[10], i, t, j;
//	printf("请输入十个整数");
//	for (i = 1; i <= 10; i++)
//		scanf("%d", &a[i]);
//	printf("\n");
//	for (j = 1; j < 10; j++)
//		for (i = 1; i < 11 - j; i++)
//			if (a[i] > a[i + 1])
//			{
//				t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
//			}
//	printf("排序后为");
//	for (i = 1; i <= 10; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//	return 0;
//}



#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N = 50;
	int a = 1;
	int* tmp = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < 50; i++)
	{
		tmp[i] = a;
		a += 2;
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", tmp[i]);
	}

	printf("\n");

	int check;
	scanf("%d", &check);

	int l = 0;
	int r = N - 1;

	while (l<r)
	{
		int mid = r / 2;
		if (check > tmp[mid])
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
		if (check == tmp[mid])
		{
			printf("找到了\n");
			break;
		}
	}
	

	return 0;
}