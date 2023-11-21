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


//#include<stdio.h>
//#include<stdlib.h>
//
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    int* arr = (int*)malloc(sizeof(int) * n * m);
//    if (arr == NULL)
//    {
//        printf("开辟失败\n");
//        exit(-1);
//    }
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < m && j < n)
//    {
//        if (nums1[i] <= nums2[j])
//        {
//            arr[k] = nums1[i];
//            i++;
//            k++;
//        }
//        else
//        {
//            arr[k] = nums2[j];
//            j++;
//            k++;
//        }
//    }
//    if (i == m)
//    {
//        while (j < n)
//        {
//            arr[k] = nums2[j];
//            k++;
//            j++;
//        }
//    }
//    else
//    {
//        while (i < m)
//        {
//            arr[k] = nums1[i];
//            i++;
//            k++;
//        }
//    }
//    for (int i = 0; i < m + n; i++)
//    {
//        nums1[i] = arr[i];
//    }
//}
//
//int main()
//{
//	int arr1[6] = { 1,2,3 };
//	int arr2[] = { 2,5,6 };
//    int sz1 = sizeof(arr1) / sizeof(int);
//    int sz2 = sizeof(arr2) / sizeof(int);
//    merge(arr1, sz1, 3, arr2, sz2, sz2);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* BuySListNode(int x)//创建节点
//{
//	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (newnode == NULL)
//	{
//		printf("申请节点失败\n");
//		exit(-1);
//	}
//	newnode->val = x;
//	newnode->next = NULL;
//	return newnode;
//}
//
//void SListPushBack(struct ListNode** phead, int x)//尾部插入
//{
//	struct ListNode* newnode = BuySListNode(x);
//	struct ListNode* tail = *phead;
//	if (tail == NULL)
//	{
//		*phead = newnode;
//	}
//	else
//	{
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;
//	}
//}
//
//void SListPrint(struct ListNode** phead)//输出
//{
//	struct ListNode* cur = *phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return head;
//	}
//	else
//	{
//		struct ListNode* tail = head->next;
//		head->next = NULL;
//		while (tail != NULL)
//		{
//			struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//			newnode->val = tail->val;
//			newnode->next = head;
//			head = newnode;
//			tail = tail->next;
//		}
//	}
//	return head;
//}
//
//int main()
//{
//	struct ListNode* head = NULL;
//	SListPushBack(&head, 1);
//	SListPushBack(&head, 2);
//	SListPushBack(&head, 3);
//	SListPushBack(&head, 4);
//	SListPushBack(&head, 5);
//
//	head = reverseList(head);
//
//	SListPrint(&head);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* list1next;
//    struct ListNode* list2next;
//    struct ListNode* newlist = NULL;
//    struct ListNode* tail = NULL;
//    if (list1 == NULL && list2 == NULL)
//    {
//        return NULL;
//    }
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//    while (list1 != NULL && list2 != NULL)
//    {
//        if ((list1->val) <= (list2->val))
//        {
//            if (newlist == NULL)
//            {
//                list1next = list1->next;
//                list1->next = newlist;
//                newlist = list1;
//                list1 = list1next;
//                tail = newlist;
//                list1 = list2next;
//            }
//            else
//            {
//                list1next = list1->next;
//                list1->next = tail->next;
//                tail->next = list1;
//                tail = tail->next;
//                list1 = list1next;
//            }
//        }
//        else
//        {
//            if (newlist == NULL)
//            {
//                list2next = list2->next;
//                list2->next = newlist;
//                newlist = list2;
//                list2 = list2next;
//                tail = newlist;
//                list2 = list2next;
//            }
//            else
//            {
//                list2next = list2->next;
//                list2->next = tail->next;
//                tail->next = list2;
//                tail = tail->next;
//            }
//        }
//    }
//    if (list1 == NULL)
//    {
//        tail->next = list2;
//    }
//    else
//    {
//        tail->next = list1;
//    }
//    return newlist;
//}
//
//int main()
//{
//	struct ListNode* A = (struct ListNode*)malloc(sizeof(struct ListNode));
//	A->val = 1;
//	struct ListNode* B = (struct ListNode*)malloc(sizeof(struct ListNode));
//	B->val = 2;
//	struct ListNode* C = (struct ListNode*)malloc(sizeof(struct ListNode));
//	C->val = 4;
//
//	A->next = B;
//	B->next = C;
//	C->next = NULL;
//	
//	struct ListNode* E = (struct ListNode*)malloc(sizeof(struct ListNode));
//	E->val = 1;
//	struct ListNode* F = (struct ListNode*)malloc(sizeof(struct ListNode));
//	F->val = 3;
//	struct ListNode* G = (struct ListNode*)malloc(sizeof(struct ListNode));
//	G->val = 4;
//
//	E->next = F;
//	F->next = G;
//	G->next = NULL;
//
//    mergeTwoLists(A, E);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}ListNode;
//
//ListNode* partition(ListNode* pHead, int x)
//{
//    int i = 0;
//    struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));
//    first->next = pHead;
//    pHead = first;
//    struct ListNode* FirstPushBack = first;
//    struct ListNode* tail = pHead;
//    struct ListNode* move = pHead->next;
//    struct ListNode* movenext;
//    while (tail->next != NULL)
//    {
//        tail = tail->next;
//    }
//    while (move != FirstPushBack && move != NULL)
//    {
//        if (move->val >= x)
//        {
//            i++;
//            if (i == 1)
//            {
//                FirstPushBack = move;
//            }
//            movenext = move->next;
//            move->next = tail->next;
//            tail->next = move;
//            tail = tail->next;
//            first->next = movenext;
//            move = movenext;
//        }
//        else
//        {
//            first = first->next;
//            move = move->next;
//        }
//    }
//    return first->next;
//}
//
//ListNode* partition2(ListNode* pHead, int x)
//{
//    ListNode* smalllist = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* biglist = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* smalltail = smalllist;
//    ListNode* bigtail = biglist;
//    smalllist->next = NULL;
//    biglist->next = NULL;
//    ListNode* pHeadnext;
//    while (pHead != NULL)
//    {
//        if (pHead->val < x)
//        {
//            pHeadnext = pHead->next;
//            pHead->next = smalltail->next;
//            smalltail->next = pHead;
//            smalltail = smalltail->next;
//            pHead = pHeadnext;
//        }
//        else
//        {
//            pHeadnext = pHead->next;
//            pHead->next = bigtail->next;
//            bigtail->next = pHead;
//            bigtail = bigtail->next;
//            pHead = pHeadnext;
//        }
//    }
//    smalltail->next = biglist->next;
//    return smalltail;
//}
//
//int main()
//{
//	struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
//	a->val = 3;
//
//	struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
//	b->val = 3;
//
//	struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
//	c->val = 3;
//
//	//struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//d->val = 8;
//
//	//struct ListNode* e = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//e->val = 100;
//
//	//struct ListNode* f = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//f->val = 90;
//
//	//struct ListNode* g = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//g->val = 1;
//
//
//	a->next = b;
//	b->next = c;
//	c->next = NULL;
//	//d->next = e;
//	//e->next = f;
//	//f->next = g;
// //   g->next = NULL;
//
//    partition2(a,3);
//
//    return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<limits.h>
//#define INT_MAX
//
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    struct ListNode* arr[10000];
//    int size = 0;
//    while (head != NULL)
//    {
//        int i = 0;
//        while (i < size)
//        {
//            if (arr[i] == &(*head))
//            {
//                return head;
//            }
//            else
//            {
//                i++;
//            }
//        }
//        arr[size] = &(*head);
//        size++;
//        head = head->next;
//    }
//    return NULL;
//}
//
//int main()
//{
//	struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
//	a->val = 1;
//
//	struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
//	b->val = 2;
//
//	a->next = b;
//	b->next = NULL;
//
//    struct ListNode* ret=detectCycle(a);
//
//	return 0;
//}


//#include<stdio.h>
//#include<limits.h>
//
//int main()
//{
//	printf("%u", UINT_MAX);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//
//
//struct Node
//{
//	int val;
//	struct Node* next;
//	struct Node* random;
//};
//
//struct Node* copyRandomList(struct Node* head)
//{
//    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
//    first->next = NULL;
//
//    struct Node* tailfirst = first;
//    struct Node* tailhead = head;
//    while (tailhead != NULL)
//    {
//        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//        newnode->val = tailhead->val;
//        newnode->next = NULL;
//        tailfirst->next = newnode;
//        tailfirst = tailfirst->next;
//        tailhead = tailhead->next;
//    }
//    tailhead = head;
//    tailfirst = first;
//    while (tailhead != NULL)
//    {
//        struct Node* randomposition = tailhead->random;
//        int size = 1;
//        struct Node* find = head;
//        while (find != randomposition)
//        {
//            find = find->next;
//            size++;
//        }
//        struct Node* findfirst = first;
//        while (size--)
//        {
//            findfirst = findfirst->next;
//        }
//        tailfirst->next->random = findfirst;
//        tailfirst = tailfirst->next;
//        tailhead = tailhead->next;
//    }
//    return first->next;
//}

//int main()
//{
//	struct Node* a = malloc(sizeof(struct Node));
//	a->val = 7;
//	struct Node* b = malloc(sizeof(struct Node));
//	b->val = 13;
//	struct Node* c = malloc(sizeof(struct Node));
//	c->val = 11;
//	struct Node* d = malloc(sizeof(struct Node));
//	d->val = 10;
//	struct Node* e = malloc(sizeof(struct Node));
//	e->val = 1;
//
//	a->next = b;
//	b->next = c;
//	c->next = d;
//	d->next = e;
//	e->next = NULL;
//
//	a->random = NULL;
//	b->random = a;
//	c->random = e;
//	d->random = c;
//	e->random = a;
//
//    struct Node* ret = copyRandomList(a);
//
//
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>	
//
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}Node;
//
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    Node* prev;
//    Node* mid = head;
//    Node* tail = head->next;
//    while (tail != NULL)
//    {
//        if (mid->val != tail->val)
//        {
//            prev = mid;
//            mid = mid->next;
//            tail = tail->next;
//        }
//        else
//        {
//            while ((tail != NULL) && (mid->val == tail->val))
//            {
//                tail = tail->next;
//            }
//            prev->next = tail;
//            mid = prev;
//        }
//    }
//    return head;
//}
//
//int main()
//{
//	Node* a = malloc(sizeof(Node));
//	a->val = 1;
//	Node* b = malloc(sizeof(Node));
//	b->val = 2;
//	Node* c = malloc(sizeof(Node));
//	c->val = 3;
//	Node* d = malloc(sizeof(Node));
//	d->val = 3;
//	Node* e = malloc(sizeof(Node));
//	e->val = 4;
//	Node* f = malloc(sizeof(Node));
//	f->val = 4;
//	Node* g = malloc(sizeof(Node));
//	g->val = 5;
//
//	a->next = b;
//	b->next = c;
//	c->next = d;
//	d->next = e;
//	e->next = f;
//	f->next = g;
//	g->next = NULL;
//
//    Node* ret=deleteDuplicates(a);
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdbool.h>
//
//bool compare(char c1, char c2)
//{
//    if (c1 == '(' && c2 == ')')
//    {
//        return true;
//    }
//    if (c1 == '[' && c2 == ']')
//    {
//        return true;
//    }
//    if (c1 == '{' && c2 == '}')
//    {
//        return true;
//    }
//    return false;
//}
//
//bool isValid(char* s)
//{
//    char arr[10];
//    int i = 0;
//    int j = 1;
//    while (s[i] != '\0')
//    {
//        arr[j] = s[i];
//        i++;
//        j++;
//        if (compare(arr[j-2], arr[j-1]))
//        {
//            j -= 1;
//        }
//    }
//    if (j == 1)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//int main()
//{
//	char s[] = "()";
//    isValid(s);
//	return 0;
//}

#include<stdio.h>

int main()
{
	char a = '0';
	char b = '1';
	printf("%d %d\n", a, b);

	return 0;
}