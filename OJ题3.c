#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。

//typedef char SLTDataType;
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
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackPush(ST* ps, SLTDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = realloc(ps->a, sizeof(ST) * newcapacity);
//		if (tmp == 0)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//SLTDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//bool isValid(char* s)
//{
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, s);
//			s++;
//		}
//		else
//		{
//			//遇到了右括号，但是栈中没有数据，说明
//			//前面没有左括号，不匹配
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			SLTDataType top = StackTop(&st);
//			if ((*s == ']' && top != '[') || (*s == ')' && top != '(') || (*s == '}' && top != '{'))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				s++;
//			}
//		}
//	}
//	//如果栈中不是空，说明栈中还有左括号未出
//	//没有匹配，返回false
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}




//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false

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
//typedef struct 
//{
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() 
//{
//    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&st->q1);
//    QueueInit(&st->q2);
//
//    return st;
//}
//
//void myStackPush(MyStack* obj, int x) 
//{
//    if (!QueueEmpty(&obj->q1))
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
//int myStackPop(MyStack* obj) 
//{
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (!QueueEmpty(&obj->q1))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    while (QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty, QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//    
//    int top = QueueFront(nonempty);
//    QueuePop(nonempty);
//    return top;
//}
//
//int myStackTop(MyStack* obj) 
//{
//    if (!QueueEmpty(&obj->q1))
//    {
//        return QueueBack(&obj->q1);
//    }
//    else
//    {
//        return QueueBack(&obj->q2);
//    }
//}
//
//bool myStackEmpty(MyStack* obj) 
//{
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) 
//{
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);
//}




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
//void QueueInit(Queue* pq)
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
//
//typedef struct 
//{
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() 
//{
//    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&st->q1);
//    QueueInit(&st->q2);
//    return st;
//}
//
//void myStackPush(MyStack* obj, int x) 
//{
//    if (!QueueEmpty(&obj->q1))
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
//int myStackPop(MyStack* obj) 
//{
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (!QueueEmpty(&obj->q1))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    while (QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty, QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//
//    int top = QueueFront(nonempty);
//    QueuePop(nonempty);
//    return top;
//}
//
//int myStackTop(MyStack* obj) 
//{
//    if (!QueueEmpty(&obj->q1))
//    {
//        return QueueBack(&obj->q1);
//    }
//    else
//    {
//        return QueueBack(&obj->q2);
//    }
//}
//
//bool myStackEmpty(MyStack* obj) 
//{
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) 
//{
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);
//}


//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false


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
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackPush(ST* ps, SLTDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLTDataType* tmp = realloc(ps->a, sizeof(ST) * newcapacity);
//		if (tmp == 0)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
//SLTDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
//int Stacksize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//typedef struct 
//{
//	ST PushST;
//	ST PopST;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() 
//{
//	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&q->PushST);
//	StackInit(&q->PopST);
//	return q;
//}
//
//void myQueuePush(MyQueue* obj, int x) 
//{
//	StackPush(&obj->PushST, x);
//}
//
//int myQueuePop(MyQueue* obj) 
//{
//	if (StackEmpty(&obj->PopST))
//	{
//		while (!StackEmpty(&obj->PushST))
//		{
//			StackPush(&obj->PopST, StackTop(&obj->PushST));
//			StackPop(&obj->PushST);
//		}
//	}
//
//	int Front = StackTop(&obj->PopST);
//	StackPop(&obj->PopST);
//	return Front;
//}
//
//int myQueuePeek(MyQueue* obj) 
//{
//	if (StackEmpty(&obj->PopST))
//	{
//		while (!StackEmpty(&obj->PushST))
//		{
//			StackPush(&obj->PopST, StackTop(&obj->PushST));
//			StackPop(&obj->PushST);
//		}
//	}
//	return StackTop(&obj->PopST);
//}
//
//bool myQueueEmpty(MyQueue* obj) 
//{
//	return StackEmpty(&obj->PushST) && StackEmpty(&obj->PopST);
//}
//
//void myQueueFree(MyQueue* obj) 
//{
//	StackDestroy(&obj->PushST);
//	StackDestroy(&obj->PopST);
//	free(obj);
//}

























