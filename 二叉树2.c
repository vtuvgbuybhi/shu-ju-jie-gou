#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//
//typedef int HpDataType;
//
//typedef struct Heap
//{
//	HpDataType* a;
//	int size;
//	int capacity;
//}Hp;
//
//void HeapInit(Hp* ph)
//{
//	assert(ph);
//	ph->a = NULL;
//	ph->size = ph->capacity = 0;
//}
//
//void HeapDestroy(Hp* ph)
//{
//	assert(ph);
//	free(ph->a);
//	ph->size = ph->capacity = 0;
//}
//
//void swap(HpDataType* px, HpDataType* py)
//{
//	assert(px && py);
//	HpDataType tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
////大堆向上调整
////void AdjustUp(HpDataType* a, int child)
////{
////	assert(a);
////	int parent = (child - 1) / 2;
////	while (child > 0)
////	{
////		if (a[child] > a[parent])
////		{
////			swap(&a[child], &a[parent]);
////
////			child = parent;
////			parent = (child - 1) / 2;
////		}
////		else
////		{
////			break;
////		}
////	}
////}
//
////小堆向上调整
//void AdjustUp(HpDataType* a, int child)
//{
//	assert(a);
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] < a[parent])
//		{
//			swap(&a[child], &a[parent]);
//
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//
//
//void HeapPush(Hp* ph,HpDataType x)
//{
//	assert(ph);
//	if (ph->size == ph->capacity)
//	{
//		int newcapacity = ph->capacity == 0 ? 4 : (ph->capacity) * 2;
//		HpDataType* tmp = realloc(ph->a, sizeof(HpDataType) * newcapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ph->capacity = newcapacity;
//		ph->a = tmp;
//	}
//	ph->a[ph->size] = x;
//	ph->size++;
//
//	AdjustUp(ph->a,ph->size-1);
//}
//
//bool HeapEmpty(Hp* hp)
//{
//	assert(hp);
//	return hp->size == 0;
//}
//
//int HeapSize(Hp* hp)
//{
//	assert(hp);
//	return hp->size;
//}
//
////删除堆顶的数据
////针对小堆向下调整
//void AdjustDown(HpDataType* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child<n)
//	{
//		//找出较小的哪个孩子
//		if (child+1<n && a[child + 1] < a[child])
//		{
//			child = child + 1;
//		}
//		//交换父亲与孩子的位置
//		if (a[child] < a[parent])
//		{
//			swap(&a[child], &a[parent]);
//
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
////针对大堆向下调整
////void AdjustDown(HpDataType* a, int n, int parent)
////{
////	int child = parent * 2 + 1;
////	while (child < n)
////	{
////		//找出较大的哪个孩子
////		if (child + 1 < n && a[child + 1] > a[child])
////		{
////			child = child + 1;
////		}
////		//交换父亲与孩子的位置
////		if (a[child] > a[parent])
////		{
////			swap(&a[child], &a[parent]);
////
////			parent = child;
////			child = parent * 2 + 1;
////		}
////		else
////		{
////			break;
////		}
////	}
////}
//
//void HeapPop(Hp* hp)
//{
//	assert(hp);
//	assert(!HeapEmpty(hp));
//
//	swap(&hp->a[0], &hp->a[hp->size - 1]);
//	hp->size--;
//
//	AdjustDown(hp->a, hp->size, 0);
//}
//
//void HeapPrint(Hp* hp)
//{
//	assert(hp);
//	for (int i = 0; i < hp->size; i++)
//	{
//		printf("%d ", hp->a[i]);
//	}
//	printf("\n");
//}
//
//int HeapTop(Hp* hp)
//{
//	assert(hp);
//	assert(!HeapEmpty(hp));
//	return hp->a[0];
//}
//
////在N个数中找出最大的前k个  or  找出最小的前k个
//void  PrintTopK(int*a,int n,int k)
//{
//	assert(a);
//	Hp hp;
//	HeapInit(&hp);
//	//创建一个k个数的小堆
//	for (int i = 0; i < k; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	//剩下	N-k个数与堆顶进行比较
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
//
////在1000个数中找出最大的10个
//
////方式1: 先排降序，前10个就是最大的。排序算法最快的  O（N*logN）
////
////方式2:   N个数依次插入大堆，             PopK次，      每次取堆顶的数据就前K个   O(N + K*logN)
////               N                        K*logN 
////
////方式3: 假设N非常大，N是10个亿，内存中存不下这些整数，他们存在文件中，K是100    （方式1和方式2都不能用了）
////   
////        时间复杂度  O（K + （N-K）*logK）   --》 O（N*logK）
////    1.用前k个数建立一个k个数的小堆
////	2.剩下的N-k个数，依次跟堆顶的数据进行比较，如果比堆顶的数据大，就替换堆顶的数据，再向下调整
////    3.最后堆里k个数，就是最大的k个数了
//
////int main()
////{
////	int a[] = { 70,56,30,25,15,10,75 };
////	Hp hp;
////	HeapInit(&hp);
////	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
////	{
////		HeapPush(&hp, a[i]);
////	}
////	HeapPrint(&hp);
////
////	HeapPop(&hp);
////	HeapPrint(&hp);
////
////	return 0;
////}
//#include<time.h>
//
//void TestTopk()
//{
//	int n = 10000;
//	int* a = (int*)malloc(sizeof(int) * n);
//	srand(time(0));
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 1000000;
//	}
//	//再去设置10个比1000000大的数
//	a[5] = 1000000 + 1;
//	a[100] = 1000000 + 2;
//	a[105] = 1000000 + 3;
//	a[466] = 1000000 + 4;
//	a[4895] = 1000000 + 5;
//	a[3252] = 1000000 + 6;
//	a[656] = 1000000 + 7;
//	a[444] = 1000000 + 8;
//	a[3654] = 1000000 + 9;
//	a[7854] = 1000000 + 10;
//
//	PrintTopK(a, n, 10);
//}
//
//
//int main()
//{
//	TestTopk();
//
//	return 0;
//}

























































