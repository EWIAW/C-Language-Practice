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


//#pragma pack(2)
//#include<stdio.h>
//
//struct str1
//{
//    char i;
//    int j;
//    char k;
//};
//struct str2
//{
//    char a;
//    struct str1 s1;
//    double b;
//};
//int main()
//{
//    printf("%d\n", sizeof(struct str1));
//    printf("%d\n", sizeof(struct str2));
//    return 0;
//}


//struct str1
//{
//	int i;
//	int j;
//};
//struct str2
//{
//	char a;
//	struct str1 b;
//	int c;
//};
//int main()
//{
//	printf("%d", sizeof(struct str2));
//	return 0;
//}



//#pragma pack(2)
//#include<stdio.h>
//
//struct str
//{
//	char i;
//	int j;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct str));
//	return 0;
//}



//#include<stdio.h>
//
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include<stdio.h>
//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
////下面输出的结果是什么？
//int main()
//{
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int* p = NULL;
//	*p = 10;
//	return 0;
//}


//#include<stdio.h>
//
//void move(int* nums, int head, int* numsSize)
//{
//    while (head < (*numsSize))
//    {
//        nums[head] = nums[head + 1];
//        head++;
//    }
//    (*numsSize)--;
//}
//
//int removeDuplicates(int* nums, int numsSize)
//{
//    int i = 1;
//    int tmp = nums[0];
//    while (i < numsSize)
//    {
//        while (nums[i] == tmp)
//        {
//            move(nums, i, &numsSize);
//        }
//        tmp = nums[i];
//        i++;
//    }
//    return numsSize;
//}
//
//int main()
//{
//	int arr[] = { 0,0,1,1,1,2,2,3,3,4 };
//	int sz = sizeof(arr) / sizeof(int);
//    int len=removeDuplicates(arr, sz);
//
//    for (int i = 0; i < len; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* arr = (int*)malloc(sizeof(int) * n * m);
    if (arr == NULL)
    {
        printf("开辟失败\n");
        exit(-1);
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            arr[k] = nums1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = nums2[j];
            j++;
            k++;
        }
    }
    if (i == m)
    {
        while (j < n)
        {
            arr[k] = nums2[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i < m)
        {
            arr[k] = nums1[i];
            i++;
            k++;
        }
    }
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = arr[i];
    }
}

int main()
{
	int arr1[6] = { 1,2,3 };
	int arr2[] = { 2,5,6 };
    int sz1 = sizeof(arr1) / sizeof(int);
    int sz2 = sizeof(arr2) / sizeof(int);
    merge(arr1, sz1, 3, arr2, sz2, sz2);
	return 0;
}