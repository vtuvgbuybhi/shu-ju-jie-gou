#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//顺序表的缺陷  : 1.空间不够了需要增容 ，增容是要付出代价的
//
//                  |—>原地扩--》代价很低
//增容（realloc）---
//                  |—>异地孔--》拷贝数据，释放旧空间，返回新空间地址  --》代价很大


//int main()
//{
//	int* p1 = malloc(sizeof(int) * 10);
//	int* p2 = realloc(p1, sizeof(int) * 2000);
//
//	return 0;
//}

//2.避免频繁扩容，我们满了基本上都是扩2倍，可能会导致一定的空间浪费
//3.顺序表要求数据从开始位置连续存储，那么我们从头部或者中间位置插入删除数据，就需要挪动数据，效率就不高



//针对顺序表的缺陷  ---》 诞生了链

//链表的逻辑图 :想象出来的（箭头压根不存在在内存当中）


//         -------------   ------------   --------------
//phead--->|  1   |  --|->|  2    |  --|->|  3   | NULL|
//         -------------  --------------   -------------
//	       data  next     data    next     data   next
//
//	//链表的最后一个结构体当中的next置为空指针
//
//
//物理图  :  内存中真实存储
//
//      phead             0x12340000           0x12340010             0x12330000
//   -----------       ---------------     -----------------       ------------------
//   |0x12340000|     | 1 |0x12340010|     |  2 |0x12330000|      |  3  | 0x00000000|
//   -----------      -----------------    -----------------       ------------------




//链表的优点 : 按需申请空间，不用了就释放（更合理的使用了空间）
//头部中间插入数据，不需要挪动数据，不存在空间浪费
//
//缺陷:  每一个数据，都要存一个指针去链接后面数据节点，不支持随机访问（顺序表可以直接通过下标直接访问第i个数据）








//typedef int SLTDataType;
//
//typedef struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;
//}SLTNode;
//
//
////打印
//void SListPrint(SLTNode* phead)
//{
//	SLTNode* cur = phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//}
//
//
//void SListPushBack(SLTNode** pphead,SLTDataType x)
//{
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (*pphead == NULL)
//	{
//		*pphead = newnode;
//
//	}
//	else
//	{
//		//找到尾节点
//		SLTNode* tail = *pphead;
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//
//		tail->next = newnode;
//	}
//}
//
//
//void TestSList1()
//{
//	SLTNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 3);
//
//	SListPrint(plist);
//}
//
//
//int main()
//{
//	TestSList1();
//
//	return 0;
//}





typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;


SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


//打印
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//进行尾插数据

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next; 
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;

	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	//思路1
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

		////思路2
		//SLTNode* tail = *pphead;
		//while (tail->next->next)
		//{
		//	tail = tail->next;
		//}
		//free(tail->next);
		//tail->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//找到某数据并返回地址
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* head = phead;
	while (head->data != x)
	{
		head = head->next;
		if (head == NULL)
		{
			return NULL;
		}
	}
	return head;
}

//在pos位置之前插入数据
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == NULL)
	{
		printf("pos位置不存在\n");
	}
	else
	{
		SLTNode* cur = BuyListNode(x);
		if (*pphead == pos)
		{
			cur->next = *pphead;
			*pphead = cur;
		}
		else
		{
			cur->next = pos;
			SLTNode* head = *pphead;
			while (head->next != pos)
			{
				head = head->next;
			}
			head->next = cur;
		}
	}
}


void SListErase(SLTNode** pphead, SLTNode* pos)
{
	SLTNode* cur = *pphead;
	if (pos == NULL)
	{
		printf("要删除的数据不存在\n");
	}
	else if (cur->next==NULL)
	{
		free(cur);
		cur = NULL;
	}
	else if (cur == pos)
	{
		*pphead = cur->next;
		free(cur);
		cur = NULL;
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}



void SListDestroy(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while ((*pphead) != NULL)
	{
		cur = cur->next;
		SLTNode* tail = *pphead;
		free(tail);
		tail = NULL;
		*pphead = cur;
	}
}


void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);

	SListPrint(plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	
	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);

}

void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);
}

void TestSList4()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist,3);
	
	SListPrint(plist);

	SLTNode* cur = SListFind(plist, 1);
	SListInsert(&plist, cur, 4);

	SListPrint(plist);
}


void TestSList5()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);

	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 1);
	SListErase(&plist, pos);

	SListPrint(plist);
}


void TestSList6()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 1);

	SListDestroy(&plist);
}

int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
	//TestSList4();
	//TestSList5();
	//TestSList6();
	
	return 0;
}

















