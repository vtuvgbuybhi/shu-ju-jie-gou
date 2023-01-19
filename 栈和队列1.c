#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//栈的概念及结构:  一种特殊的线性结构，只允许固定的一端进行插入和删除元素操作，进行数据插入和删除的一端我们称为栈顶，另一端
//称为栈底。
//
//压栈: 栈的插入操作(入数据在栈顶)
//出栈: 栈的删除操作(出数据也在栈顶)
//
//
//栈底          --》     栈顶
//--------------------------------------------------------
//|                                                      |       数组栈
//--------------------------------------------------------
//
//
//
//   栈底----》栈顶（这种情况得是双向循环链表，不然尾上删除数据效率底）
//------       --------       --------
//|    | --》  |      |   -》 |      |         链式栈
//------       --------       --------
//
//  栈顶<---栈底（单链表  头插）



//数组栈的实现

//typedef int SLTDataType;
//
//typedef struct Stack
//{
//	SLTDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//
//void StackInit(ST* ps)
//{
//	assert(ps);
//
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//
//void StackDestory(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->capacity = 0;
//	ps->top = 0;
//}
//
//void StackPush(ST* ps, SLTDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int Newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = (SLTDataType*)realloc(ps->a, sizeof(SLTDataType) * Newcapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = Newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	ps->top--;
//}
//
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//
//
//SLTDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//
//
//void StackTest1()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//
//	StackDestory(&st);
//}
//
//
//void StackTest2()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//
//	StackDestory(&st);
//}
//
//int main()
//{
//	//StackTest1();
//	StackTest2();
//
//	return 0;
//}



//队列

//概念  : 只允许在一端进行插入数据操作，另一端进行删除数据操作的特殊线性表，（先进先出）

//入队列: 进行插入操作的一端称为队尾
//出队列: 进行删除数据的一端称为对头

            // ——————————————————————————————————————
            //                                        -------    --------
            //  出队       <-------                   |  A  |    |  B   |       <-------入队
            //                                        -------    --------
            //———————————————————————————————————————
            //   对头                                                          队尾


//队列实现
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//    QDataType data;
//    struct QueueNode* next;
//}QueueNode;
//
//typedef struct Queue
//{
//    QueueNode* head;
//    QueueNode* tail;
//}Queue;
//
//void QueueInit(Queue*pq)
//{
//    assert(pq);
//    pq->head = NULL;
//    pq->tail = NULL;
//}
//
//void QueueDestroy(Queue* pq)
//{
//    assert(pq);
//    QueueNode* cur = pq->head;
//    while (cur != NULL)
//    {
//        QueueNode* next = cur->next;
//        free(cur);
//        cur = next;
//    }
//    pq->head = pq->tail = NULL;
//}
//
//void QueuePush(Queue* pq, QDataType x)
//{
//    assert(pq);
//    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//    if (newNode == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    newNode->next = NULL;
//    newNode->data = x;
//    if (pq->head == NULL)
//    {
//        pq->head = pq->tail = newNode;
//    }
//    else
//    {
//        pq->tail->next = newNode;
//        pq->tail = newNode;
//    }
//}
//
//bool QueueEmpty(Queue* pq)
//{
//    assert(pq);
//    return pq->head == NULL;
//}
//
//void QueuePop(Queue* pq)
//{
//    assert(pq);
//    assert(!QueueEmpty(pq));
//    QueueNode* next = pq->head->next;
//    free(pq->head);
//    pq->head = next;
//    if (next == NULL)
//    {
//        pq->tail = NULL;
//    }
//}
//
//QDataType QueueFront(Queue* pq)
//{
//    assert(pq);
//    assert(!QueueEmpty(pq));
//    return pq->head->data;
//}
//
//QDataType QueueBack(Queue* pq)
//{
//    assert(pq);
//    assert(!QueueEmpty(pq));
//    return pq->tail->data;
//}
//
//int QueueSize(Queue* pq)
//{
//    assert(pq);
//    int n = 0;
//    QueueNode* cur = pq->head;
//    while (cur)
//    {
//        n++;
//        cur = cur->next;
//    }
//    return n;
//}
//
//void TestQueue1()
//{
//    Queue q;
//    QueueInit(&q);
//    QueuePush(&q, 1);
//    QueuePush(&q, 2);
//    QueuePush(&q, 3);
//
//    while (!QueueEmpty(&q))
//    {
//        printf("%d ", QueueFront(&q));
//        QueuePop(&q);
//    }
//
//    QueueDestroy(&q);
//}
//
//int main()
//{
//    TestQueue1();
//
//    return 0; 
//}






































