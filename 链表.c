#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˳����ȱ��  : 1.�ռ䲻������Ҫ���� ��������Ҫ�������۵�
//
//                  |��>ԭ����--�����ۺܵ�
//���ݣ�realloc��---
//                  |��>��ؿ�--���������ݣ��ͷžɿռ䣬�����¿ռ��ַ  --�����ۺܴ�


//int main()
//{
//	int* p1 = malloc(sizeof(int) * 10);
//	int* p2 = realloc(p1, sizeof(int) * 2000);
//
//	return 0;
//}

//2.����Ƶ�����ݣ��������˻����϶�����2�������ܻᵼ��һ���Ŀռ��˷�
//3.˳���Ҫ�����ݴӿ�ʼλ�������洢����ô���Ǵ�ͷ�������м�λ�ò���ɾ�����ݣ�����ҪŲ�����ݣ�Ч�ʾͲ���



//���˳����ȱ��  ---�� ��������

//������߼�ͼ :��������ģ���ͷѹ�����������ڴ浱�У�


//         -------------   ------------   --------------
//phead--->|  1   |  --|->|  2    |  --|->|  3   | NULL|
//         -------------  --------------   -------------
//	       data  next     data    next     data   next
//
//	//��������һ���ṹ�嵱�е�next��Ϊ��ָ��
//
//
//����ͼ  :  �ڴ�����ʵ�洢
//
//      phead             0x12340000           0x12340010             0x12330000
//   -----------       ---------------     -----------------       ------------------
//   |0x12340000|     | 1 |0x12340010|     |  2 |0x12330000|      |  3  | 0x00000000|
//   -----------      -----------------    -----------------       ------------------




//������ŵ� : ��������ռ䣬�����˾��ͷţ��������ʹ���˿ռ䣩
//ͷ���м�������ݣ�����ҪŲ�����ݣ������ڿռ��˷�
//
//ȱ��:  ÿһ�����ݣ���Ҫ��һ��ָ��ȥ���Ӻ������ݽڵ㣬��֧��������ʣ�˳������ֱ��ͨ���±�ֱ�ӷ��ʵ�i�����ݣ�








//typedef int SLTDataType;
//
//typedef struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;
//}SLTNode;
//
//
////��ӡ
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
//		//�ҵ�β�ڵ�
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


//��ӡ
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


//����β������

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
	//˼·1
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

		////˼·2
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

//�ҵ�ĳ���ݲ����ص�ַ
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

//��posλ��֮ǰ��������
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == NULL)
	{
		printf("posλ�ò�����\n");
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
		printf("Ҫɾ�������ݲ�����\n");
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

















