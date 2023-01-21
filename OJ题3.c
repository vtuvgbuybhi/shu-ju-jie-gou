#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�

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
//			//�����������ţ�����ջ��û�����ݣ�˵��
//			//ǰ��û�������ţ���ƥ��
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
//	//���ջ�в��ǿգ�˵��ջ�л���������δ��
//	//û��ƥ�䣬����false
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}




//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//
//ʵ�� MyStack �ࣺ
//
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false

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


//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false


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

























