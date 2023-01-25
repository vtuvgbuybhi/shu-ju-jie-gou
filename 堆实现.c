#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>


typedef int HpDataType;
typedef struct HeapNode
{
	HpDataType* a;
	int size;
	int capacity;
}Hp;

void HeapInit(Hp* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void HeapDestroy(Hp* hp)
{
	assert(hp);
	free(hp->a);
	hp->size = hp->capacity = 0;
}

void swap(HpDataType* px, HpDataType* py)
{
	assert(px && py);
	HpDataType tmp = *px;
	*px = *py;
	*py = tmp;
}

//小堆向上调整
//void AdjustUp(HpDataType* q, int child)
//{
//	assert(q);
//	int parent = (child - 1) / 2;
//	while (child>0)
//	{
//		if (q[child] < q[parent])
//		{
//			swap(&q[child], &q[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}



//大堆向上调整
void AdjustUp(HpDataType* q, int child)
{
	assert(q);
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (q[child] > q[parent])
		{
			swap(&q[child], &q[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(Hp* hp, HpDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : (hp->capacity) * 2;
		HpDataType* tmp = realloc(hp->a, sizeof(HpDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->capacity = newcapacity;
		hp->a = tmp;
	}
	hp->a[hp->size] = x;
	hp->size++;

	AdjustUp(hp->a, hp->size - 1);
}

bool HeapEmpty(Hp* hp)
{
	assert(hp);
	return hp->size == 0;
}

HpDataType HeapTop(Hp* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->a[0];
}

void HeapPrint(Hp* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	int tmp = 0;
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
		tmp = hp->a[i];
	}
	printf("\n");
}


//小堆向下调整
//void AdjustDown(HpDataType* a, int n, int parent)
//{
//	assert(a);
//	int child = parent * 2 + 1;
//	while (child<n)
//	{
//		if (child+1<n && a[child + 1] < a[child])
//		{
//			child++;
//		}
//		if (a[child] < a[parent])
//		{
//			swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}



//大堆向下调整
void AdjustDown(HpDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child+1<n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
		}
		else
		{
			break;
		}
	}
}


void HeapPop(Hp* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a, hp->size,0);
}



//int main()
//{
//	int a[] = { 70,56,30,25,15,10,75,80 };
//	Hp hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	return 0;
//}

//TopK问题求N个数中最大的前K个
//void PrintTopK(int* a, int n, int k)
//{
//	assert(a);
//	Hp hp;
//	HeapInit(&hp);
//	for (int i = 0; i < k; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	for (int i = k; i < n; i++)
//	{
//		if (a[i] > HeapTop(&hp))
//		{
//			HeapPop(&hp);
//			HeapPush(&hp, a[i]);
//		}
//	}
//	HeapPrint(&hp);
//
//	HeapDestroy(&hp);
//}
//
//void TestTopK()
//{
//	int n = 10000;
//	int* a =(int*)malloc(sizeof(int) * n);
//	srand(time(0));
//	for (size_t i = 0; i < n; i++)
//	{
//		a[i] = rand() % 1000000;
//	}
//
//	a[50] = 1000000 + 1;
//	a[10] = 1000000 + 2;
//	a[105] = 1000000 + 3;
//	a[466] = 1000000 + 4;
//	a[485] = 1000000 + 5;
//	a[322] = 1000000 + 6;
//	a[656] = 1000000 + 7;
//	a[444] = 1000000 + 8;
//	a[354] = 1000000 + 9;
//	a[784] = 1000000 + 10;
//
//	PrintTopK(a, n, 10);
//
//}
//
//
//int main()
//{
//	TestTopK();
//
//	return 0;
//}


//堆排序
//升序
void HeapSort(int*a,int n)
{
	//把a构建成小堆
	assert(a);
	//方法1-->构建小堆(也可以构建大堆)
	//for (int i = 1; i < n; i++)
	//{
	//	//int parent = (i - 1) / 2;
	//	//while (a[parent] > a[i])
	//	//{
	//	//	swap(&a[parent], &a[i]);
	//	//	i = parent;
	//	//	parent = (i - 1) / 2;
	//	//}
	// 
	//	AdjustUp(a, i);
	//}

	//方法2--->构建小堆(也可以构建大堆)
//	int fparent = (n - 1 - 1) / 2;
//
//	//建堆时间复杂度O(N)
//	for (int i = fparent; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);//大堆解决升序问题
//	}
//
//	int tmp = n;
//
//	//时间复杂度 O(N*logN)
//	while (tmp>=2)
//	{
//		swap(&a[0], &a[tmp - 1]);
//		tmp--;
//		AdjustDown(a, tmp, 0);
//	}
//}

               
//升序  ------->建小堆的问题
//1.选出最小的数放到第一个位置
//2.如何选出次小的数呢  ---> 从第15位置开始，剩下的的话看作一个堆，不过之前建立好的堆关系全部乱了--->只能剩下的重新建堆，选出次小的数
//建堆的时间复杂度  O（N）
//那么升序建小堆的时间复杂度  --> O(N*N)  搞了这么一圈这样子看来还不如遍历直接选出

//换一种思路  排升序  -->  建大堆
//1.建大堆，选出最大的数
//2.最大的数与最后一个数交换
//3.如何选出次小的数呢? 把最后一个数不看做堆里面，进行向下调整，就可以选出次小的数，以此类推，再重复上面的过程


//int main()
//{
//	int a[] = { 70,56,30,25,15,10,75,33,50,69 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	
//	return 0;
//}



//证明建堆的时间复杂度为什么是  O（N）  而不是O(N*logN)
//
//假设树的高度h
//                  *                   第一层  : 2^0个节点 ，需要向下移动（h-1）层
//	        *           *             第二层 : 2 ^ 1个节点 ，需要向下移动（h - 2）层
//	    *      *     *     *          第三层 : 2 ^ 2个节点 ，需要向下移动（h - 3）层
//    *      * *   * *   * *   *        第四层 : 2 ^ 3个节点 ，需要向下移动（h - 4）层
//
//
//建堆的时间复杂度
// T（n）=2^0*(h-1)+2^1*(h-2)+2^2*(h-3)+2^3*(h-4) + …… +2^(h-3)*2+2^(h-2)*1
//
// 2T(n) =         2^1*(h-1)+2^2*(h-2)+2^3*(h-3)+2^4*(h-4) + …… +2^(h-2)*2+2^(h-1)*1
//
//
//2T(n) - T(n)    --> 采用错位相减
//= 1-h   + 2^1 +2^2+2^3+2^4+ …… + 2^(h-2)+2^(h-1)
//
//=2^0 + 2 ^ 1 + 2 ^ 2 + 2 ^ 3 + 2 ^ 4 + …… + 2 ^ (h - 2) + 2 ^ (h - 1)   -h
//
//=2^h-1   - h
//
//我们可以知道  n=2^h-1      h=log(n+1)
//
//T(n)=N+log(N+1)   约等于  O（N）





































































