#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//
//typedef int LTDataType;
//
//typedef struct ListNode
//{
//	LTDataType data;
//	struct ListNode* prev;
//	struct ListNode* next;
//}SLNode;
//
//SLNode* ListInit()
//{
//	SLNode* phead = (SLNode*)malloc(sizeof(SLNode));
//	if (phead == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	phead->next = phead;
//	phead->prev = phead;
//	return phead;
//}
//
//SLNode* BuyListNode(LTDataType x)
//{
//	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//	newnode->prev = NULL;
//	return newnode;
//}
//
//void ListInsert(SLNode* pos, LTDataType x)
//{
//	assert(pos);
//	SLNode* newnode = BuyListNode(x);
//	SLNode* posprev = pos->prev;
//	
//	posprev->next = newnode;
//	newnode->next = pos;
//	newnode->prev = posprev;
//	pos->prev = newnode;
//}
//
//void ListErase(SLNode* pos)
//{
//	assert(pos);
//	SLNode* posprev = pos->prev;
//	SLNode* posnext = pos->next;
//
//	free(pos);
//
//	posprev->next = posnext;
//	posnext->prev = posprev;
//
//}
//
//
//void ListPushBack(SLNode* ps,LTDataType x)
//{
//	assert(ps);
//	//SLNode* newnode = BuyListNode(x);
//	//SLNode* Backprev = ps->prev;
//	//Backprev->next = newnode;
//
//	//ps->prev = newnode;
//
//	//newnode->prev = Backprev;
//	//newnode->next = ps;
//
//	ListInsert(ps, x);
//}
//
//void ListBackPop(SLNode* ps)
//{
//	assert(ps);
//	assert(ps->next != ps);
//	//SLNode* Pushprev = ps->prev->prev;
//	//free(ps->prev);
//
//	//Pushprev->next = ps;
//	//ps->prev = Pushprev;
//
//	ListErase(ps->prev);
//}
//
//
//void ListPushFront(SLNode* ps, LTDataType x)
//{
//	assert(ps);
//	//SLNode* newnode = BuyListNode(x);
//	//SLNode* Frontnext = ps->next;
//	//
//	//ps->next = newnode;
//	//Frontnext->prev = newnode;
//
//	//newnode->next = Frontnext;
//	//newnode->prev = ps;
//
//	ListInsert(ps->next, x);
//
//}
//
//
//void ListFrontPop(SLNode* ps)
//{
//	assert(ps);
//	assert(ps->next != ps);
//	//SLNode* Frontnext = ps->next->next;
//	//free(ps->next);
//	//
//	//ps->next = Frontnext;
//	//Frontnext->prev = ps;
//
//	ListErase(ps->next);
//
//}
//
//
//
//void ListPrint(SLNode* ps)
//{
//	assert(ps);
//	SLNode* cur = ps->next;
//	while (cur != ps)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}
//
//
//
//SLNode* ListFind(SLNode* ps, LTDataType x)
//{
//	assert(ps);
//	SLNode* cur = ps->next;
//	while (cur != ps)
//	{
//		if (cur->data == x)
//		{
//			return cur;
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}
//
//
//
//void TestListNode1()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPushFront(plist, 4);
//	ListPushFront(plist, 5);
//	ListPushFront(plist, 6);
//
//}
//
//void TestListNode2()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPrint(plist);
//
//	ListPushFront(plist, 4);
//	ListPushFront(plist, 5);
//
//	ListPrint(plist);
//}
//
//
//void TestListNode3()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListBackPop(plist);
//	ListBackPop(plist);
//
//	ListPushFront(plist, 4);
//
//	ListBackPop(plist);
//
//	ListPrint(plist);
//
//}
//
//void TestListNode4()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPrint(plist);
//
//	ListFrontPop(plist);
//	ListFrontPop(plist);
//	ListFrontPop(plist);
//
//	ListPrint(plist);
//}
//
//
//
//void TestListNode5()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPrint(plist);
//
//	SLNode* pos = ListFind(plist, 1);
//	ListInsert(pos, 5);
//
//	ListPrint(plist);
//}
//
//
//void TestListNode6()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPrint(plist);
//
//	ListPushFront(plist, 1);
//	ListPushFront(plist, 2);
//	ListPushFront(plist, 3);
//
//	ListPrint(plist);
//
//}
//
//void TestListNode7()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPrint(plist);
//
//	SLNode* pos = ListFind(plist, 2);
//	ListErase(pos);
//
//
//	ListPrint(plist);
//
//	SLNode* pos1 = ListFind(plist, 3);
//	ListInsert(pos1, 2);
//
//
//	ListPrint(plist);
//}
//
//void TestListNode8()
//{
//	SLNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//
//	ListPrint(plist);
//
//	ListFrontPop(plist);
//	ListFrontPop(plist);
//	ListFrontPop(plist);	
//	ListFrontPop(plist);
//
//
//	ListPrint(plist);
//}
//
//
//int main()
//{
//	//TestListNode1();
//	//TestListNode2();
//	//TestListNode3();
//	//TestListNode4();
//	//TestListNode5();
//	//TestListNode6();
//	//TestListNode7();
//	TestListNode8();
//
//	return 0;
//}































