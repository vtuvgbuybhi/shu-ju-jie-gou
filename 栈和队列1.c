#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//ջ�ĸ���ṹ:  һ����������Խṹ��ֻ����̶���һ�˽��в����ɾ��Ԫ�ز������������ݲ����ɾ����һ�����ǳ�Ϊջ������һ��
//��Ϊջ�ס�
//
//ѹջ: ջ�Ĳ������(��������ջ��)
//��ջ: ջ��ɾ������(������Ҳ��ջ��)
//
//
//ջ��          --��     ջ��
//--------------------------------------------------------
//|                                                      |       ����ջ
//--------------------------------------------------------
//
//
//
//   ջ��----��ջ���������������˫��ѭ��������Ȼβ��ɾ������Ч�ʵף�
//------       --------       --------
//|    | --��  |      |   -�� |      |         ��ʽջ
//------       --------       --------
//
//  ջ��<---ջ�ף�������  ͷ�壩



//����ջ��ʵ��

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



//����

//����  : ֻ������һ�˽��в������ݲ�������һ�˽���ɾ�����ݲ������������Ա����Ƚ��ȳ���

//�����: ���в��������һ�˳�Ϊ��β
//������: ����ɾ�����ݵ�һ�˳�Ϊ��ͷ

            // ����������������������������������������������������������������������������
            //                                        -------    --------
            //  ����       <-------                   |  A  |    |  B   |       <-------���
            //                                        -------    --------
            //������������������������������������������������������������������������������
            //   ��ͷ                                                          ��β


//����ʵ��
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






































