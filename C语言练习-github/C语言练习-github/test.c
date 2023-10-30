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



//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int N = 50;
//	int a = 1;
//	int* tmp = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < 50; i++)
//	{
//		tmp[i] = a;
//		a += 2;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d ", tmp[i]);
//	}
//
//	printf("\n");
//
//	int check;
//	scanf("%d", &check);
//
//	int l = 0;
//	int r = N - 1;
//
//	while (l<r)
//	{
//		int mid = r / 2;
//		if (check > tmp[mid])
//		{
//			l = mid;
//		}
//		else
//		{
//			r = mid;
//		}
//		if (check == tmp[mid])
//		{
//			printf("找到了\n");
//			break;
//		}
//	}
//	
//
//	return 0;
//}



//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr[20];
//	gets(arr);
//	printf("%d", strlen(arr));
//	return 0;
//}



//#include<stdio.h>
//
//void check(int *a, int sz)
//{
//	int tmp1 = 0;
//	int tmp2 = 0;
//	int ret = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		ret = ret ^ a[i];
//	}
//	int b;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((ret >> i) & 1 == 1)
//		{
//			b = i;
//			break;
//
//		}
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		if ((a[i] >> b) & 1 == 1)
//		{
//			tmp1=tmp1^ a[i];
//		}
//		else
//		{
//			tmp2 = tmp2 ^ a[i];
//		}
//	}
//	printf("%d %d", tmp1, tmp2);
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,1,2,3,4 };
//	int sz = sizeof(arr) / sizeof(int);
//	check(arr, sz);
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//void rotate(int* nums, int numsSize, int k)
//{
//    int* arr = (int*)malloc(sizeof(int) * numsSize);
//    int i = numsSize - k;
//    for (int a = 0; a < numsSize; a++, i++)
//    {
//        if (i == numsSize)
//        {
//            i = 0;
//        }
//        arr[a] = nums[i];
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//}
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7 };
//    int sz = sizeof(arr) / sizeof(int);
//    rotate(arr, sz, 3);
//}



//#include<stdio.h>
//#include<malloc.h>
//void rotate(int* nums, int numsSize, int k)
//{
//    int* a = (int*)malloc(sizeof(int) * numsSize);
//    int i = numsSize - k;
//    for (int j = 0; j < numsSize; j++, i++)
//    {
//        if (i == numsSize)
//        {
//            i = 0;
//        }
//        a[j] = nums[i];
//    }
//    nums = a;
//    for (int i = 0; i < numsSize; i++)
//    {
//        printf("%d ", nums[i]);
//    }
//}
//int main()
//{
//    int nums[7] = { 1,2,3,4,5,6,7 };
//    int k = 3;
//    int sz = sizeof(nums) / sizeof(int);
//    rotate(nums, sz, k);
//
//    return 0;
//}



#include<stdio.h>

int main()
{

	return 0;
}