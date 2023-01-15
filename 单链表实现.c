#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//
//typedef int SLTDataType;
//
//
//typedef struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;
//}SListNode;
//
//
////��ӡ����
//void SListPrint(SListNode* phead)
//{
//	SListNode* cur = phead;
//	while (cur)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL");
//	printf("\n");
//}
//
//
//SListNode* BuySListNode(SLTDataType x)
//{
//	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
//	if (newNode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newNode->data = x;
//	newNode->next = NULL;
//	return newNode;
//}
//
//
////β��
//void SListPushBack(SListNode** pphead, SLTDataType x)
//{
//	SListNode* newNode = BuySListNode(x);
//	SListNode* cur = *pphead;
//	if (*pphead != NULL)
//	{
//		while (cur->next != NULL)
//		{
//			cur = cur->next;
//		}
//		cur->next = newNode;
//	}
//	else
//	{
//		*pphead = newNode;
//	}
//}
//
//
////ͷ������
//void SListPushFront(SListNode** pphead, SLTDataType x)
//{
//	SListNode* newNode = BuySListNode(x);
//	newNode->next = (*pphead);
//	*pphead = newNode;
//}
//
////βɾ
//void SListPopBack(SListNode** pphead)
//{
//	assert(*pphead);
//	SListNode* cur = *pphead;
//	SListNode* curr = NULL;
//	if ((*pphead)->next == NULL)
//	{
//		free(*pphead);
//		*pphead = NULL;
//	}
//	else
//	{
//		while (cur->next != NULL)
//		{
//			curr = cur;
//			cur = cur->next;
//		}
//		curr->next = NULL;
//		free(cur);
//		cur = NULL;
//	}
//}
//
////ͷɾ
//void SListPopFront(SListNode** pphead)
//{
//	assert(*pphead);
//	SListNode* cur = *pphead;
//	*pphead = (*pphead)->next;
//	free(cur);
//	cur = NULL;
//}
//
////�ҵ�x������x���±�
//SListNode* SListFind(SListNode* phead,SLTDataType x)
//{
//	SListNode* tail = phead;
//	if (phead == NULL)
//	{
//		return;
//	}
//	else
//	{
//		while (tail->data != x)
//		{
//			tail = tail->next;
//			if (tail == NULL)
//			{
//				return NULL;
//			}
//		}
//		return tail;
//	}
//}
//
////��xλ��֮ǰ����y
//void SListInsertFront(SListNode** pphead, SLTDataType x,SLTDataType y)
//{
//	SListNode* newnode = BuySListNode(y);
//	SListNode* head = *pphead;
//	SListNode* pos = SListFind(*pphead, x);
//	if (pos == NULL)
//	{
//		printf("�����λ�ò�����\n");
//	}
//	else
//	{
//		if (pos == head)
//		{
//			newnode->next = *pphead;
//			*pphead = newnode;
//		}
//		else
//		{
//			while (head->next != pos)
//			{
//				head = head->next;
//			}
//			newnode->next = head->next;
//			head->next = newnode;
//		}
//	}
//}
//
////��xλ��֮�����y
//void SListInsertBack(SListNode** pphead, SLTDataType x, SLTDataType y)
//{
//	SListNode* newnode = BuySListNode(y);
//	SListNode* pos = SListFind(*pphead, x);
//	if (pos == NULL)
//	{
//		printf("Ҫ�����λ�ò�����\n");
//	}
//	else
//	{
//		if (pos->next == NULL)
//		{
//			pos->next = newnode;
//			newnode->next = NULL;
//		}
//		else
//		{
//			newnode->next = pos->next;
//			pos->next = newnode;
//		}
//	}
//}
//
////ɾ��xλ��
//void SListErase(SListNode** pphead, SLTDataType x)
//{
//	assert(*pphead);
//	SListNode* pos = SListFind(*pphead, x);
//	SListNode* head = *pphead;
//	if (pos == NULL)
//	{
//		printf("xλ�ò�����\n");
//	}
//	else
//	{
//		if (pos == head)
//		{
//			*pphead = head->next;
//			free(head);
//		}
//		else
//		{
//			while (head->next!= pos)
//			{
//				head = head->next;
//			}
//			SListNode* hhead = head->next->next;
//			free(head->next);
//			head->next=NULL;
//			head->next = hhead;
//		}
//	}
//}
//
//void SListDestroy(SListNode** pphead)
//{
//	assert(*pphead);
//	SListNode* head = pphead;
//	while (head != NULL)
//	{
//		head = (*pphead)->next;
//		free(*pphead);
//		*pphead = NULL;
//		*pphead = head;
//	}
//}
//
//
//void TestSList1()
//{
//	SListNode* plist = NULL;
//	SListPrint(plist);
//
//	SListPopFront(&plist);
//
//	SListPrint(plist);
//
//}
//
//void TestSList2()
//{
//	SListNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//
//
//	SListNode* pos = SListFind(plist,2);
//	int i = 1;
//	while (pos)
//	{
//		printf("��%d��pos  %p->%d \n", i++, pos, pos->data);
//		pos = SListFind(pos->next, 2);
//	}
//}
//
//void TestSList3()
//{
//	SListNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 3);
//
//	SListPrint(plist);
//
//	SListInsertFront(&plist,3,5);
//	SListInsertBack(&plist,3,5);
//
//	SListPrint(plist);
//}
//
//void TestSList4()
//{
//	SListNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 1);
//
//	SListPrint(plist);
//
//	//SListErase(&plist, 1);
//	//SListErase(&plist, 1);
//	//SListErase(&plist, 1);
//
//	//SListPrint(plist);
//	SListDestroy(&plist);
//}
//
//int main()
//{
//	//TestSList1();
//	//TestSList2();
//	//TestSList3();
//	TestSList4();
//
//	return 0;
//}













