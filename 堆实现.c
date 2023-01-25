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

//С�����ϵ���
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



//������ϵ���
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


//С�����µ���
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



//������µ���
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

//TopK������N����������ǰK��
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


//������
//����
void HeapSort(int*a,int n)
{
	//��a������С��
	assert(a);
	//����1-->����С��(Ҳ���Թ������)
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

	//����2--->����С��(Ҳ���Թ������)
//	int fparent = (n - 1 - 1) / 2;
//
//	//����ʱ�临�Ӷ�O(N)
//	for (int i = fparent; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);//��ѽ����������
//	}
//
//	int tmp = n;
//
//	//ʱ�临�Ӷ� O(N*logN)
//	while (tmp>=2)
//	{
//		swap(&a[0], &a[tmp - 1]);
//		tmp--;
//		AdjustDown(a, tmp, 0);
//	}
//}

               
//����  ------->��С�ѵ�����
//1.ѡ����С�����ŵ���һ��λ��
//2.���ѡ����С������  ---> �ӵ�15λ�ÿ�ʼ��ʣ�µĵĻ�����һ���ѣ�����֮ǰ�����õĶѹ�ϵȫ������--->ֻ��ʣ�µ����½��ѣ�ѡ����С����
//���ѵ�ʱ�临�Ӷ�  O��N��
//��ô����С�ѵ�ʱ�临�Ӷ�  --> O(N*N)  ������ôһȦ�����ӿ������������ֱ��ѡ��

//��һ��˼·  ������  -->  �����
//1.����ѣ�ѡ��������
//2.�����������һ��������
//3.���ѡ����С������? �����һ���������������棬�������µ������Ϳ���ѡ����С�������Դ����ƣ����ظ�����Ĺ���


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



//֤�����ѵ�ʱ�临�Ӷ�Ϊʲô��  O��N��  ������O(N*logN)
//
//�������ĸ߶�h
//                  *                   ��һ��  : 2^0���ڵ� ����Ҫ�����ƶ���h-1����
//	        *           *             �ڶ��� : 2 ^ 1���ڵ� ����Ҫ�����ƶ���h - 2����
//	    *      *     *     *          ������ : 2 ^ 2���ڵ� ����Ҫ�����ƶ���h - 3����
//    *      * *   * *   * *   *        ���Ĳ� : 2 ^ 3���ڵ� ����Ҫ�����ƶ���h - 4����
//
//
//���ѵ�ʱ�临�Ӷ�
// T��n��=2^0*(h-1)+2^1*(h-2)+2^2*(h-3)+2^3*(h-4) + ���� +2^(h-3)*2+2^(h-2)*1
//
// 2T(n) =         2^1*(h-1)+2^2*(h-2)+2^3*(h-3)+2^4*(h-4) + ���� +2^(h-2)*2+2^(h-1)*1
//
//
//2T(n) - T(n)    --> ���ô�λ���
//= 1-h   + 2^1 +2^2+2^3+2^4+ ���� + 2^(h-2)+2^(h-1)
//
//=2^0 + 2 ^ 1 + 2 ^ 2 + 2 ^ 3 + 2 ^ 4 + ���� + 2 ^ (h - 2) + 2 ^ (h - 1)   -h
//
//=2^h-1   - h
//
//���ǿ���֪��  n=2^h-1      h=log(n+1)
//
//T(n)=N+log(N+1)   Լ����  O��N��





































































