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
////������ϵ���
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
////С�����ϵ���
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
////ɾ���Ѷ�������
////���С�����µ���
//void AdjustDown(HpDataType* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child<n)
//	{
//		//�ҳ���С���ĸ�����
//		if (child+1<n && a[child + 1] < a[child])
//		{
//			child = child + 1;
//		}
//		//���������뺢�ӵ�λ��
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
////��Դ�����µ���
////void AdjustDown(HpDataType* a, int n, int parent)
////{
////	int child = parent * 2 + 1;
////	while (child < n)
////	{
////		//�ҳ��ϴ���ĸ�����
////		if (child + 1 < n && a[child + 1] > a[child])
////		{
////			child = child + 1;
////		}
////		//���������뺢�ӵ�λ��
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
////��N�������ҳ�����ǰk��  or  �ҳ���С��ǰk��
//void  PrintTopK(int*a,int n,int k)
//{
//	assert(a);
//	Hp hp;
//	HeapInit(&hp);
//	//����һ��k������С��
//	for (int i = 0; i < k; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	//ʣ��	N-k������Ѷ����бȽ�
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
////��1000�������ҳ�����10��
//
////��ʽ1: ���Ž���ǰ10���������ġ������㷨����  O��N*logN��
////
////��ʽ2:   N�������β����ѣ�             PopK�Σ�      ÿ��ȡ�Ѷ������ݾ�ǰK��   O(N + K*logN)
////               N                        K*logN 
////
////��ʽ3: ����N�ǳ���N��10���ڣ��ڴ��д治����Щ���������Ǵ����ļ��У�K��100    ����ʽ1�ͷ�ʽ2���������ˣ�
////   
////        ʱ�临�Ӷ�  O��K + ��N-K��*logK��   --�� O��N*logK��
////    1.��ǰk��������һ��k������С��
////	2.ʣ�µ�N-k���������θ��Ѷ������ݽ��бȽϣ�����ȶѶ������ݴ󣬾��滻�Ѷ������ݣ������µ���
////    3.������k��������������k������
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
//	//��ȥ����10����1000000�����
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

























































