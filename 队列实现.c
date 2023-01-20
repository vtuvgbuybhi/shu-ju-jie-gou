#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdlib.h>
//
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QueueNode;
//
//typedef struct Queue
//{
//	QueueNode* head;
//	QueueNode* tail;
//}Queue;
//
//void QueueInit(Queue*pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//
//void QueuePush(Queue* pq,QDataType x)
//{
//	assert(pq);
//	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//	if (newNode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newNode->next = NULL;
//	newNode->data = x;
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newNode;
//	}
//	else
//	{
//		pq->tail->next = newNode;
//		pq->tail = newNode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* cur = pq->head->next;
//	free(pq->head);
//	pq->head = cur;
//	if (pq->head == NULL)
//	{
//		pq->tail = NULL;
//	}
//}
//
//QDataType QueueFront(Queue*pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//
//
//void TestQueue1()
//{
//	Queue st;
//	QueueInit(&st);
//	QueuePush(&st, 1);
//	QueuePush(&st, 2);
//	QueuePush(&st, 3);
//	QueuePush(&st, 4);
//
//	while (!QueueEmpty(&st))
//	{
//		printf("%d ", QueueFront(&st));
//		QueuePop(&st);
//	}
//
//	QueueDestroy(&st);
//
//}
//
//
//int main()
//{
//	TestQueue1();
//	return 0;
//}



































































































