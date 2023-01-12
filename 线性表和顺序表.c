#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//线性表  : 是n个具有相同特性的数据元素的有限序列
//常见的线性表: 顺序表、链表、栈、队列、字符串……

//                   | --》静态
//顺序表  --》 数组--
//                   | --》动态
//
//数组当中我们是没有要求的，顺序表当中我们要求数据必须连续存储、必须从头开始存

//顺序表  : 是用一段物理地址的连续存储单元依次存储数据元素的线性结构，一般情况下采用数组存储


//#define N 1000
/*typedef int SLDataType;*/     //重定义一个名称出来--》想存char类型  直接将int改char  


//静态顺序表
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;//表示数组中存储了多少个数据
//}SL;

//顺序表接口（接口函数）----函数的命名风格是跟着STL的c++的一个库函数
//void SeqListInit(SL* ps)//初始化顺序表
//{
//
//
//}
//
////静态特点: 如果满了就不让插入
//void SeqListPushBack(SL* ps, SLDataType x)//尾插数据
//void SeqListPopBack(SL* ps, SLDataType x)//尾删
//void SeqListPushFront(SL* ps, SLDataType x)//头插
//void SeqListPopFront(SL* ps, SLDataType x)//头删









//动态顺序表

//typedef int SLDataType;
//
//typedef struct SeqList
//{
//	SLDataType* a;
//	int size;      //表示数组中存储了多少个数据
//	int capacity;  //数组实际能存数据空间容量是多大
//}SL;
//
//
//void SeqListInit(SL* ps)//初始化顺序表
//{
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
//
//void SeqListCheckCapacity(SL* ps)
//{
//	if (ps->size == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//
//		//realloc有一个特点: 当你对原来的空间扩容，但原来的空间是空，那么就和malloc的功能是一样的
//		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//}
//

//void SeqListPushBack(SL* ps, SLDataType x)//尾插数据
////1.整个顺序表没有空间
////2.空间不够  --> 扩容
////3.空间足够，直接插入数据即可
//{
//	//如果没有空间，或者空间不足我们就扩容
//	SeqListCheckCapacity(ps);
//
//	//足够的空间，直接插入
//	ps->a[ps->size] = x;
//	ps->size++;
//}
//void SeqListPopBack(SL* ps)//尾删
//{
//	//方法1
//	//if (ps->size > 0)
//	//{
//	//	//ps->a[ps->size - 1] = 0;   //这步多余了
//	//	ps->size--;
//	//}
//	
//	//方法2
//	assert(ps->size > 0);
//	ps->size--;
//
//}
//
//void SeqListPushFront(SL* ps, SLDataType x)//头插
//{
//	SeqListCheckCapacity(ps);
//	//挪动数据
//	int end = ps->size - 1;
//	while (end >= 0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}
//
//void SeqListPopFront(SL* ps)//头删
//{
//	assert(ps->size > 0);
//	int begin = 1;
//	while (begin < ps->size)
//	{
//		ps->a[begin - 1] = ps->a[begin];
//		begin++;
//	}
//	ps->size--;
//}
//
//
//void SeqListPrint(SL* ps)//打印
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
//
////销毁
//void SeqListDestory(SL* ps)
//{
//	free(ps->a);
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
//
////找到了返回x位置下标，没有找到返回-1
//void SeqListSearch(SL* ps, SLDataType x);
////指定pos下标位置插入
//void SeqListInsert(SL* ps, int pos, SLDataType x);
////删除pos位置的数据
//void SeqListErase(SL* ps, int pos);
//
//
//
//void TestSeqList1()
//{
//	SL s1;
//	SeqListInit(&s1);//传结构体的地址，函数实参传给形参实际是值的拷贝
//	//尾插  1 2 3 4 5  5个数据
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 3);
//	SeqListPushBack(&s1, 4);
//	SeqListPushBack(&s1, 5);
//
//
//	SeqListPrint(&s1);
//
//
//	SeqListDestory(&s1);
//}
//
//void TestSeqList2()
//{
//	SL s1;
//	SeqListInit(&s1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 2);
//	SeqListPushBack(&s1, 5);
//
//	SeqListPrint(&s1);
//
//	SeqListPushFront(&s1, 10);
//	SeqListPushFront(&s1, 20);
//	SeqListPushFront(&s1, 30);
//	SeqListPushFront(&s1, 40);
//
//	SeqListPrint(&s1);
//
//	SeqListPopFront(&s1);
//
//	SeqListDestory(&s1);
//}
//
//int main()
//{ 
////	TestSeqList1();
////	TestSeqList2();
//
//	return 0;
//}















